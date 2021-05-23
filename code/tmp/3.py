import random
class Node:
    def __init__(self,element,pointer):
        self.element = element
        self.pointer = pointer
class link_list:
    def __init__(self):
        self.head=None
    def insert(self,data):
        new_node=Node(data,self.head)
        self.head=new_node
    def isEmpty(self):
        return self.head==None
    def output(self):
        t=self.head
        ans=""
        while t!=None:
            print(t.element,end=' ')
            t=t.pointer
        print("");
    def recursive_count(self,node):
        if node.pointer==None:
            return 1;
        return self.recursive_count(node.pointer)+1;
    def quick_part(self,head,tail):
        if head==tail or head.pointer==tail:
            return 
        pivot=head.element;
        left=head;
        cur=head.pointer;
        while cur != tail:
            if cur.element < pivot:
                left = left.pointer;
                left.element, cur.element=cur.element,left.element;
            cur = cur.pointer;
        head.element,left.element=left.element,head.element;
        self.quick_part(head,left);
        self.quick_part(left.pointer,tail);
    def quick_sort(self,node):
        self.quick_part(node,None);
n=int(input("please input the size of the array"))
a=link_list();
for i in range(n):
    a.insert(random.randint(0,10000));
print("before sort:");
a.output();
a.quick_sort(a.head);
print("after sort");
a.output();
