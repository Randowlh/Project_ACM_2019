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
        while t!=None:
            print(str(t.element)," ")
            t=t.pointer
        print("");
    def recursive_count(self,node):
        if node.pointer==None:
            return 1;
        return self.recursive_count(node.pointer)+1;
a=link_list();
n=int(input("Enter the number of list"));
# lst = [int(x) for x in input().split()]
for i in range(n):
    a.insert(random.randint(1,1000));
print("ans="+str(a.recursive_count(a.head)));
    