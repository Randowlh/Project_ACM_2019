#!/usr/bin/env python
#coding=utf-8
import pyttsx3
import os
import thread
from darkflow.net.build import TFNet
import cv2
from io import BytesIO
import time
import numpy as np
import glob
from PIL import Image, ImageDraw,ImageFont
import requests
import Tkinter
import tkMessageBox
import numpy as np
import picamera
from picamera.array import PiRGBArray
edd=1
cnt=0
spk=pyttsx3.init()
camera = picamera.PiCamera()
opt = {"model": "/home/pi/darkflow-master/cfg/tiny-yolo-voc.cfg", "load": "/bin/tiny-yolo-voc.weights", "threshold": 0.15}   
tfnet = TFNet(opt)
camera.framerate = 1
camera.resolution = (800, 600)
ffont = ImageFont.truetype("ARIAL.TTF",10)
# import cv2
def show(tt):
    global cnt
    rawCapture = PiRGBArray(camera, size=(800, 600))
    for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
        # if(cnt%4!=tt):
        #     continue
        cnt=cnt+1
        image = frame.array
        img1 =Image.fromarray(image)
        # # show the frame
        img2 = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
        result = tfnet.return_predict(img2)
        # img1 =image.copy()
        draw = ImageDraw.Draw(img1)
        # result = tfnet.return_predict(img2)
        ma=0
        mix='hello'
        for det in result:
            print(det['label'])
            # print((det['bottomright']['x']-det['topleft']['x'])*(det['bottomright']['y']-det['topleft']['y']));
            if(ma<(det['bottomright']['x']-det['topleft']['x'])*(det['bottomright']['y']-det['topleft']['y'])):
                ma=(det['bottomright']['x']-det['topleft']['x'])*(det['bottomright']['y']-det['topleft']['y'])
                mix=det['label']
            draw.rectangle([det['topleft']['x'], det['topleft']['y'],det['bottomright']['x'], det['bottomright']['y']],outline=(255, 0, 0),width=4)
            draw.text((det['topleft']['x'], det['topleft']['y'] -40), det['label'],font =ffont , fill=(255, 0, 0))
        spk.say(mix)
        spk.runAndWait()
        cv2.imshow("Frame", np.array(img1))
        key = cv2.waitKey(1) & 0xFF
        rawCapture.truncate(0)
        if key == ord("q"):
            break
    # camera.start_preview()
    # global edd
    # cap = cv2.VideoCapture(0)
    # cap.set(3,640) # set width
    # cap.set(4,480) # set height
    # while(edd==1):
    #     ret, frame = cap.read()
    #     # frame = cv2.flip(frame, -1) # flip camera vertically
    #     gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    #     cv2.imshow('frame',frame)
    #     #cv2.imshow('gray',gray)

    #     k = cv2.waitKey(30) & 0xff
    #     if k == 27: # press 'ESC' to quit
    #         break
    # cap.release()
top = Tkinter.Tk()
thread.start_new_thread( show, (0,) )
# thread.start_new_thread( show, (1,) )
# thread.start_new_thread( show, (2,) )
# thread.start_new_thread( show, (3,) )
def prss():
    number = 1
    for filename in glob.glob('Pictures/*.jpg'):
        img1 = Image.open(filename).convert('RGB')
        img2 = cv2.cvtColor(np.array(img1), cv2.COLOR_RGB2BGR)
        result = tfnet.return_predict(img2)
        print(result)
        draw = ImageDraw.Draw(img1)
        for det in result:
            draw.rectangle([det['topleft']['x'], det['topleft']['y'], det['bottomright']['x'], det['bottomright']['y']],outline=(255, 0, 0),width=2)
            draw.text((det['topleft']['x'], det['topleft']['y'] -40), det['label'],font =ffont , fill=(255, 0, 0))
        img1.save(filename)
        number += 1
    print("识别后的图片已保存")
ff=0
def takephoto():
    camera.capture('Pictures/image.jpg')
    prss()
def exx():
    top.destroy();
    edd=0
while(edd==1):
        # top.destroy()
    B = Tkinter.Button(top, text ="点我拍照", command = takephoto) 
    C = Tkinter.Button(top, text ="点我退出", command = exx) 
    B.pack()
    C.pack()
    top.mainloop()
