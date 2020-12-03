# GoogLenet 调研报告

## 1.Googlenet简介

是2014年Christian Szegedy提出的一种全新的深度学习结构，在这之前的AlexNet、VGG等结构都是通过增大网络的深度（层数）来获得更好的训练效果，但层数的增加会带来很多负作用，比如**overfit、梯度消失、梯度爆炸**等。Googlenet的提出则从另一种角度来提升训练结果：能更高效的利用计算资源，在相同的计算量下能提取到更多的特征，从而提升训练结果。其核心思想为整个Googlenet结构就是由多个这样的inception模块串联起来的。提高深度网络模型性能的常用方法就是提高网络模型大小，网络模型大小包括网络深度与网络宽度。在有足够的有标签数据的前提下，这是简单和保险的训练高性能模型的方法，但这会加大网络模型参数，加大了模型过拟合的风险。同时这也大大降低的训练周期，带来了大量的计算开销，尤其是在全连接层。**解决上述两个问题的可行方式就是利用稀疏连接来代替全连接层。**inception结构的主要贡献有两个：一是使用1x1的卷积来进行升降维；二是在多个尺寸上同时进行卷积再聚合。

## 2.两大创新

### 	（1）1x1卷积

​	作用1：在相同尺寸的感受野中叠加更多的卷积，能提取到更丰富的特征。先进行一次普通的卷积（比如3x3），紧跟再进行一次1x1的卷积，对于某个像素点来说1x1卷积等效于该像素点在所有特征上进行一次全连接的计算，所以右侧图的1x1卷积画成了全连接层的形式，需要注意的是NIN结构中无论是第一个3x3卷积还是新增的1x1卷积，后面都紧跟着激活函数（比如relu）。将两个卷积串联，就能组合出更多的非线性特征。举个例子，假设第1个3x3卷积＋激活函数近似于f1(x)=ax2+bx+c，第二个1x1卷积＋激活函数近似于f2(x)=mx2+nx+q，那f1(x)和f2(f1(x))比哪个非线性更强，更能模拟非线性的特征？答案是显而易见的。NIN的结构和传统的神经网络中多层的结构有些类似，后者的多层是跨越了不同尺寸的感受野（通过层与层中间加pool层），从而在更高尺度上提取出特征；NIN结构是在同一个尺度上的多层（中间没有pool层），从而在相同的感受野范围能提取更强的非线性。

​	作用2：使用1x1卷积进行降维，降低了计算复杂度。图2中间3x3卷积和5x5卷积前的1x1卷积都起到了这个作用。当某个卷积层输入的特征数较多，对这个输入进行卷积运算将产生巨大的计算量；如果对输入先进行降维，减少特征数后再做卷积计算量就会显著减少。下图是优化前后两种方案的乘法次数比较，同样是输入一组有192个特征、32x32大小，输出256组特征的数据，第一张图直接用3x3卷积实现，需要192x256x3x3x32x32=452984832次乘法；第二张图先用1x1的卷积降到96个特征，再用3x3卷积恢复出256组特征，需要192x96x1x1x32x32+96x256x3x3x32x32=245366784次乘法，使用1x1卷积降维的方法节省了一半的计算量。有人会问，用1x1卷积降到96个特征后特征数不就减少了么，会影响最后训练的效果么？答案是否定的，只要最后输出的特征数不变（256组），中间的降维类似于压缩的效果，并不影响最终训练的结果。

	### 	（2）意义多个尺寸上进行卷积再聚合的意义

​	作用1：在直观感觉上在多个尺度上同时进行卷积，能提取到不同尺度的特征。特征更为丰富也意味着最后分类判断时更加准确。

​	作用2：利用稀疏矩阵分解成密集矩阵计算的原理来加快收敛速度。举个例子下图左侧是个稀疏矩阵（很多元素都为0，不均匀分布在矩阵中），和一个2x2的矩阵进行卷积，需要对稀疏矩阵中的每一个元素进行计算；如果像右图那样把稀疏矩阵分解成2个子密集矩阵，再和2x2矩阵进行卷积，稀疏矩阵中0较多的区域就可以不用计算，计算量就大大降低。**这个原理应用到inception上就是要在特征维度上进行分解！**传统的卷积层的输入数据只和一种尺度（比如3x3）的卷积核进行卷积，输出固定维度（比如256个特征）的数据，所有256个输出特征基本上是均匀分布在3x3尺度范围上，这可以理解成输出了一个稀疏分布的特征集；而inception模块在多个尺度上提取特征（比如1x1，3x3，5x5），输出的256个特征就不再是均匀分布，而是相关性强的特征聚集在一起（比如1x1的的96个特征聚集在一起，3x3的96个特征聚集在一起，5x5的64个特征聚集在一起），这可以理解成多个密集分布的子特征集。这样的特征集中因为相关性较强的特征聚集在了一起，不相关的非关键特征就被弱化，同样是输出256个特征，inception方法输出的特征“冗余”的信息较少。用这样的“纯”的特征集层层传递最后作为反向计算的输入，自然收敛的速度更快。

​	作用3：再聚和就是要把相关性强的特征汇聚到一起。这有点类似上面的解释2，把1x1，3x3，5x5的特征分开。因为训练收敛的最终目的就是要提取出独立的特征，所以预先把相关性强的特征汇聚，就能起到加速收敛的作用。

## 3.项目源码

以下是Google TensorFlow项目组2016年开源的Googlenet源码

``` python
# Copyright 2016 The TensorFlow Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==============================================================================
"""Contains the definition for inception v1 classification network."""

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import tensorflow.compat.v1 as tf
import tf_slim as slim

from nets import inception_utils

# pylint: disable=g-long-lambda
trunc_normal = lambda stddev: tf.truncated_normal_initializer(
    0.0, stddev)


def inception_v1_base(inputs,
                      final_endpoint='Mixed_5c',
                      include_root_block=True,
                      scope='InceptionV1'):
  """Defines the Inception V1 base architecture.

  This architecture is defined in:
    Going deeper with convolutions
    Christian Szegedy, Wei Liu, Yangqing Jia, Pierre Sermanet, Scott Reed,
    Dragomir Anguelov, Dumitru Erhan, Vincent Vanhoucke, Andrew Rabinovich.
    http://arxiv.org/pdf/1409.4842v1.pdf.

  Args:
    inputs: a tensor of size [batch_size, height, width, channels].
    final_endpoint: specifies the endpoint to construct the network up to. It
      can be one of ['Conv2d_1a_7x7', 'MaxPool_2a_3x3', 'Conv2d_2b_1x1',
      'Conv2d_2c_3x3', 'MaxPool_3a_3x3', 'Mixed_3b', 'Mixed_3c',
      'MaxPool_4a_3x3', 'Mixed_4b', 'Mixed_4c', 'Mixed_4d', 'Mixed_4e',
      'Mixed_4f', 'MaxPool_5a_2x2', 'Mixed_5b', 'Mixed_5c']. If
      include_root_block is False, ['Conv2d_1a_7x7', 'MaxPool_2a_3x3',
      'Conv2d_2b_1x1', 'Conv2d_2c_3x3', 'MaxPool_3a_3x3'] will not be available.
    include_root_block: If True, include the convolution and max-pooling layers
      before the inception modules. If False, excludes those layers.
    scope: Optional variable_scope.

  Returns:
    A dictionary from components of the network to the corresponding activation.

  Raises:
    ValueError: if final_endpoint is not set to one of the predefined values.
  """
  end_points = {}
  with tf.variable_scope(scope, 'InceptionV1', [inputs]):
    with slim.arg_scope(
        [slim.conv2d, slim.fully_connected],
        weights_initializer=trunc_normal(0.01)):
      with slim.arg_scope([slim.conv2d, slim.max_pool2d],
                          stride=1, padding='SAME'):
        net = inputs
        if include_root_block:
          end_point = 'Conv2d_1a_7x7'
          net = slim.conv2d(inputs, 64, [7, 7], stride=2, scope=end_point)
          end_points[end_point] = net
          if final_endpoint == end_point:
            return net, end_points
          end_point = 'MaxPool_2a_3x3'
          net = slim.max_pool2d(net, [3, 3], stride=2, scope=end_point)
          end_points[end_point] = net
          if final_endpoint == end_point:
            return net, end_points
          end_point = 'Conv2d_2b_1x1'
          net = slim.conv2d(net, 64, [1, 1], scope=end_point)
          end_points[end_point] = net
          if final_endpoint == end_point:
            return net, end_points
          end_point = 'Conv2d_2c_3x3'
          net = slim.conv2d(net, 192, [3, 3], scope=end_point)
          end_points[end_point] = net
          if final_endpoint == end_point:
            return net, end_points
          end_point = 'MaxPool_3a_3x3'
          net = slim.max_pool2d(net, [3, 3], stride=2, scope=end_point)
          end_points[end_point] = net
          if final_endpoint == end_point:
            return net, end_points

        end_point = 'Mixed_3b'
        with tf.variable_scope(end_point):
          with tf.variable_scope('Branch_0'):
            branch_0 = slim.conv2d(net, 64, [1, 1], scope='Conv2d_0a_1x1')
          with tf.variable_scope('Branch_1'):
            branch_1 = slim.conv2d(net, 96, [1, 1], scope='Conv2d_0a_1x1')
            branch_1 = slim.conv2d(branch_1, 128, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_2'):
            branch_2 = slim.conv2d(net, 16, [1, 1], scope='Conv2d_0a_1x1')
            branch_2 = slim.conv2d(branch_2, 32, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_3'):
            branch_3 = slim.max_pool2d(net, [3, 3], scope='MaxPool_0a_3x3')
            branch_3 = slim.conv2d(branch_3, 32, [1, 1], scope='Conv2d_0b_1x1')
          net = tf.concat(
              axis=3, values=[branch_0, branch_1, branch_2, branch_3])
        end_points[end_point] = net
        if final_endpoint == end_point: return net, end_points

        end_point = 'Mixed_3c'
        with tf.variable_scope(end_point):
          with tf.variable_scope('Branch_0'):
            branch_0 = slim.conv2d(net, 128, [1, 1], scope='Conv2d_0a_1x1')
          with tf.variable_scope('Branch_1'):
            branch_1 = slim.conv2d(net, 128, [1, 1], scope='Conv2d_0a_1x1')
            branch_1 = slim.conv2d(branch_1, 192, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_2'):
            branch_2 = slim.conv2d(net, 32, [1, 1], scope='Conv2d_0a_1x1')
            branch_2 = slim.conv2d(branch_2, 96, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_3'):
            branch_3 = slim.max_pool2d(net, [3, 3], scope='MaxPool_0a_3x3')
            branch_3 = slim.conv2d(branch_3, 64, [1, 1], scope='Conv2d_0b_1x1')
          net = tf.concat(
              axis=3, values=[branch_0, branch_1, branch_2, branch_3])
        end_points[end_point] = net
        if final_endpoint == end_point: return net, end_points

        end_point = 'MaxPool_4a_3x3'
        net = slim.max_pool2d(net, [3, 3], stride=2, scope=end_point)
        end_points[end_point] = net
        if final_endpoint == end_point: return net, end_points

        end_point = 'Mixed_4b'
        with tf.variable_scope(end_point):
          with tf.variable_scope('Branch_0'):
            branch_0 = slim.conv2d(net, 192, [1, 1], scope='Conv2d_0a_1x1')
          with tf.variable_scope('Branch_1'):
            branch_1 = slim.conv2d(net, 96, [1, 1], scope='Conv2d_0a_1x1')
            branch_1 = slim.conv2d(branch_1, 208, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_2'):
            branch_2 = slim.conv2d(net, 16, [1, 1], scope='Conv2d_0a_1x1')
            branch_2 = slim.conv2d(branch_2, 48, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_3'):
            branch_3 = slim.max_pool2d(net, [3, 3], scope='MaxPool_0a_3x3')
            branch_3 = slim.conv2d(branch_3, 64, [1, 1], scope='Conv2d_0b_1x1')
          net = tf.concat(
              axis=3, values=[branch_0, branch_1, branch_2, branch_3])
        end_points[end_point] = net
        if final_endpoint == end_point: return net, end_points

        end_point = 'Mixed_4c'
        with tf.variable_scope(end_point):
          with tf.variable_scope('Branch_0'):
            branch_0 = slim.conv2d(net, 160, [1, 1], scope='Conv2d_0a_1x1')
          with tf.variable_scope('Branch_1'):
            branch_1 = slim.conv2d(net, 112, [1, 1], scope='Conv2d_0a_1x1')
            branch_1 = slim.conv2d(branch_1, 224, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_2'):
            branch_2 = slim.conv2d(net, 24, [1, 1], scope='Conv2d_0a_1x1')
            branch_2 = slim.conv2d(branch_2, 64, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_3'):
            branch_3 = slim.max_pool2d(net, [3, 3], scope='MaxPool_0a_3x3')
            branch_3 = slim.conv2d(branch_3, 64, [1, 1], scope='Conv2d_0b_1x1')
          net = tf.concat(
              axis=3, values=[branch_0, branch_1, branch_2, branch_3])
        end_points[end_point] = net
        if final_endpoint == end_point: return net, end_points

        end_point = 'Mixed_4d'
        with tf.variable_scope(end_point):
          with tf.variable_scope('Branch_0'):
            branch_0 = slim.conv2d(net, 128, [1, 1], scope='Conv2d_0a_1x1')
          with tf.variable_scope('Branch_1'):
            branch_1 = slim.conv2d(net, 128, [1, 1], scope='Conv2d_0a_1x1')
            branch_1 = slim.conv2d(branch_1, 256, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_2'):
            branch_2 = slim.conv2d(net, 24, [1, 1], scope='Conv2d_0a_1x1')
            branch_2 = slim.conv2d(branch_2, 64, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_3'):
            branch_3 = slim.max_pool2d(net, [3, 3], scope='MaxPool_0a_3x3')
            branch_3 = slim.conv2d(branch_3, 64, [1, 1], scope='Conv2d_0b_1x1')
          net = tf.concat(
              axis=3, values=[branch_0, branch_1, branch_2, branch_3])
        end_points[end_point] = net
        if final_endpoint == end_point: return net, end_points

        end_point = 'Mixed_4e'
        with tf.variable_scope(end_point):
          with tf.variable_scope('Branch_0'):
            branch_0 = slim.conv2d(net, 112, [1, 1], scope='Conv2d_0a_1x1')
          with tf.variable_scope('Branch_1'):
            branch_1 = slim.conv2d(net, 144, [1, 1], scope='Conv2d_0a_1x1')
            branch_1 = slim.conv2d(branch_1, 288, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_2'):
            branch_2 = slim.conv2d(net, 32, [1, 1], scope='Conv2d_0a_1x1')
            branch_2 = slim.conv2d(branch_2, 64, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_3'):
            branch_3 = slim.max_pool2d(net, [3, 3], scope='MaxPool_0a_3x3')
            branch_3 = slim.conv2d(branch_3, 64, [1, 1], scope='Conv2d_0b_1x1')
          net = tf.concat(
              axis=3, values=[branch_0, branch_1, branch_2, branch_3])
        end_points[end_point] = net
        if final_endpoint == end_point: return net, end_points

        end_point = 'Mixed_4f'
        with tf.variable_scope(end_point):
          with tf.variable_scope('Branch_0'):
            branch_0 = slim.conv2d(net, 256, [1, 1], scope='Conv2d_0a_1x1')
          with tf.variable_scope('Branch_1'):
            branch_1 = slim.conv2d(net, 160, [1, 1], scope='Conv2d_0a_1x1')
            branch_1 = slim.conv2d(branch_1, 320, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_2'):
            branch_2 = slim.conv2d(net, 32, [1, 1], scope='Conv2d_0a_1x1')
            branch_2 = slim.conv2d(branch_2, 128, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_3'):
            branch_3 = slim.max_pool2d(net, [3, 3], scope='MaxPool_0a_3x3')
            branch_3 = slim.conv2d(branch_3, 128, [1, 1], scope='Conv2d_0b_1x1')
          net = tf.concat(
              axis=3, values=[branch_0, branch_1, branch_2, branch_3])
        end_points[end_point] = net
        if final_endpoint == end_point: return net, end_points

        end_point = 'MaxPool_5a_2x2'
        net = slim.max_pool2d(net, [2, 2], stride=2, scope=end_point)
        end_points[end_point] = net
        if final_endpoint == end_point: return net, end_points

        end_point = 'Mixed_5b'
        with tf.variable_scope(end_point):
          with tf.variable_scope('Branch_0'):
            branch_0 = slim.conv2d(net, 256, [1, 1], scope='Conv2d_0a_1x1')
          with tf.variable_scope('Branch_1'):
            branch_1 = slim.conv2d(net, 160, [1, 1], scope='Conv2d_0a_1x1')
            branch_1 = slim.conv2d(branch_1, 320, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_2'):
            branch_2 = slim.conv2d(net, 32, [1, 1], scope='Conv2d_0a_1x1')
            branch_2 = slim.conv2d(branch_2, 128, [3, 3], scope='Conv2d_0a_3x3')
          with tf.variable_scope('Branch_3'):
            branch_3 = slim.max_pool2d(net, [3, 3], scope='MaxPool_0a_3x3')
            branch_3 = slim.conv2d(branch_3, 128, [1, 1], scope='Conv2d_0b_1x1')
          net = tf.concat(
              axis=3, values=[branch_0, branch_1, branch_2, branch_3])
        end_points[end_point] = net
        if final_endpoint == end_point: return net, end_points

        end_point = 'Mixed_5c'
        with tf.variable_scope(end_point):
          with tf.variable_scope('Branch_0'):
            branch_0 = slim.conv2d(net, 384, [1, 1], scope='Conv2d_0a_1x1')
          with tf.variable_scope('Branch_1'):
            branch_1 = slim.conv2d(net, 192, [1, 1], scope='Conv2d_0a_1x1')
            branch_1 = slim.conv2d(branch_1, 384, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_2'):
            branch_2 = slim.conv2d(net, 48, [1, 1], scope='Conv2d_0a_1x1')
            branch_2 = slim.conv2d(branch_2, 128, [3, 3], scope='Conv2d_0b_3x3')
          with tf.variable_scope('Branch_3'):
            branch_3 = slim.max_pool2d(net, [3, 3], scope='MaxPool_0a_3x3')
            branch_3 = slim.conv2d(branch_3, 128, [1, 1], scope='Conv2d_0b_1x1')
          net = tf.concat(
              axis=3, values=[branch_0, branch_1, branch_2, branch_3])
        end_points[end_point] = net
        if final_endpoint == end_point: return net, end_points
    raise ValueError('Unknown final endpoint %s' % final_endpoint)


def inception_v1(inputs,
                 num_classes=1000,
                 is_training=True,
                 dropout_keep_prob=0.8,
                 prediction_fn=slim.softmax,
                 spatial_squeeze=True,
                 reuse=None,
                 scope='InceptionV1',
                 global_pool=False):
  """Defines the Inception V1 architecture.

  This architecture is defined in:

    Going deeper with convolutions
    Christian Szegedy, Wei Liu, Yangqing Jia, Pierre Sermanet, Scott Reed,
    Dragomir Anguelov, Dumitru Erhan, Vincent Vanhoucke, Andrew Rabinovich.
    http://arxiv.org/pdf/1409.4842v1.pdf.

  The default image size used to train this network is 224x224.

  Args:
    inputs: a tensor of size [batch_size, height, width, channels].
    num_classes: number of predicted classes. If 0 or None, the logits layer
      is omitted and the input features to the logits layer (before dropout)
      are returned instead.
    is_training: whether is training or not.
    dropout_keep_prob: the percentage of activation values that are retained.
    prediction_fn: a function to get predictions out of logits.
    spatial_squeeze: if True, logits is of shape [B, C], if false logits is of
        shape [B, 1, 1, C], where B is batch_size and C is number of classes.
    reuse: whether or not the network and its variables should be reused. To be
      able to reuse 'scope' must be given.
    scope: Optional variable_scope.
    global_pool: Optional boolean flag to control the avgpooling before the
      logits layer. If false or unset, pooling is done with a fixed window
      that reduces default-sized inputs to 1x1, while larger inputs lead to
      larger outputs. If true, any input size is pooled down to 1x1.

  Returns:
    net: a Tensor with the logits (pre-softmax activations) if num_classes
      is a non-zero integer, or the non-dropped-out input to the logits layer
      if num_classes is 0 or None.
    end_points: a dictionary from components of the network to the corresponding
      activation.
  """
  # Final pooling and prediction
  with tf.variable_scope(
      scope, 'InceptionV1', [inputs], reuse=reuse) as scope:
    with slim.arg_scope([slim.batch_norm, slim.dropout],
                        is_training=is_training):
      net, end_points = inception_v1_base(inputs, scope=scope)
      with tf.variable_scope('Logits'):
        if global_pool:
          # Global average pooling.
          net = tf.reduce_mean(
              input_tensor=net, axis=[1, 2], keepdims=True, name='global_pool')
          end_points['global_pool'] = net
        else:
          # Pooling with a fixed kernel size.
          net = slim.avg_pool2d(net, [7, 7], stride=1, scope='AvgPool_0a_7x7')
          end_points['AvgPool_0a_7x7'] = net
        if not num_classes:
          return net, end_points
        net = slim.dropout(net, dropout_keep_prob, scope='Dropout_0b')
        logits = slim.conv2d(net, num_classes, [1, 1], activation_fn=None,
                             normalizer_fn=None, scope='Conv2d_0c_1x1')
        if spatial_squeeze:
          logits = tf.squeeze(logits, [1, 2], name='SpatialSqueeze')

        end_points['Logits'] = logits
        end_points['Predictions'] = prediction_fn(logits, scope='Predictions')
  return logits, end_points
inception_v1.default_image_size = 224

inception_v1_arg_scope = inception_utils.inception_arg_scope
```

其大致流程为下图

![img](https://img-blog.csdnimg.cn/20200326233448621.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzMwMDkxOTQ1,size_16,color_FFFFFF,t_70#pic_center)

##  4.几大版本的发展

### Inception v1

![img](https://img-blog.csdnimg.cn/2020042921105099.png)
从Inception v1首先可以介绍一下分治的思想。可以看到，同样是一层，但有四种处理方法，最后将它们合并起来。
![img](https://img-blog.csdnimg.cn/20200429211132562.png)
而一层中的某一个分支还可以串联多个层。这里涉及一个概念叫做bottle neck，即先用1 × 1卷积然后再用3 × 3卷积等等操作。1 × 1卷积的作用是为了降低通道数，而后的面层进行卷积，例如从256个通道数通过“瓶颈”到64，然后3 × 3的卷积层，从64到64，相当于把通道数改变与卷积分开了。这样做的好处是可以大大降低参数量，但效果并没有受到很大的影响，这也是Inception降低参数量的重要方法。其实bottle neck也有因式分解的思想。
![img](https://img-blog.csdnimg.cn/20200429215950468.png)
基于Inception的GoogLeNet有22层，里面有多个Inception结构，为了防止梯度消失还额外增加了两个辅助的softmax。还有就是使用了平均池化替代全连接层，思想来自于NIN（Network in Network）。

### Inception v2

![img](https://img-blog.csdnimg.cn/20200429211307889.png)
因式分解比如类似于VGG中介绍的，5 × 5分解为两个3 × 3，最终效果基本一致，但参数量可以减小，计算复杂性可以降低。
![img](https://img-blog.csdnimg.cn/20200429212637614.png)
这里还要提一点，为了降低特征图大小，如果先池化再Inception卷积会出现特征缺失，反之计算量又很大，最终将两者并行。
![img](https://img-blog.csdnimg.cn/20200429220325685.png)
基于Inception v2，有了改进版的GoogLeNet，效果也有了较大的提升：
![img](https://img-blog.csdnimg.cn/20200429220354985.png)

### Inception v3

![img](https://img-blog.csdnimg.cn/20200429211334897.png)
这种因式分解的思想可以更进一步，3 × 3可以用一个1 × 3和3 × 1去近似，参数量缩小为2 / 3。即 n × n可以近似为1 × n和n × 1。比如5 × 5可以用1 × 3 + 3 × 1 + 1 × 3 + 3 × 1。如果对效果影响不大，完全可以用来缩小计算量。
![img](https://img-blog.csdnimg.cn/20200429212721584.png)

### Inception v4

![img](https://img-blog.csdnimg.cn/20200429211413301.png)
![img](https://img-blog.csdnimg.cn/2020042921142763.png)
Inception v4研究了Inception模块与残差连接的结合。ResNet结构大大地加深了网络深度，还极大地提升了训练速度，同时性能也有提升。
![img](https://img-blog.csdnimg.cn/20200429220610418.png)
v4提供了很多标准模块，将分治和因式分解合并起来，综合各项技术。因为模块的设计经过了大量的尝试，所以很多应用可以直接使用，当然也可以借鉴其中的思想设计自己的模块。