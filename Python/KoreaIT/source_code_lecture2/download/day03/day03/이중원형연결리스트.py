class Node:
    def __init__(self,data):
        self.data=data
        self.prev=None
        self.next=None
'''
class DoubleCircleLinkedList:
    def __init__(self):
        self.head=Node('head')
        self.tail=Node('tail')
        self.head.prev=self.tail
        self.head.next=self.tail
        self.tail.next=self.head
        self.tail.prev=self.head
        self.count=0

    #첫번째 노드의 idx : 0    
    def insert(self,idx,data):
        if idx>self.count and idx<0:
            return
        newNode=Node(data)
        curr=None
        if idx<=self.count/2:
            curr=self.head
            for i in range(idx):
                curr=curr.next
        else:
            curr=self.tail
            for i in range(self.count-idx+1):
                curr=curr.prev
        
        newNode.prev=curr
        newNode.next=curr.next
        curr.next.prev=newNode
        curr.next=newNode
        self.count+=1

    def show(self):
        curr=self.head
        for i in range(self.count):
            print(curr.data)
            curr=curr.next
        print(curr.data)
'''
class DoubleCircleLinkedList:
    def __init__(self):
        self.cri=Node('cri')
        self.cri.next=self.cri
        self.cri.prev=self.cri
        self.count=0

    #첫번째 노드의 idx : 0    
    def insert(self,idx,data):
        if idx>self.count and idx<0:
            return
        newNode=Node(data)
        curr=self.cri
        if idx<=self.count/2:
            for i in range(idx):
                curr=curr.next
        else:
            for i in range(self.count-idx+1):
                curr=curr.prev
                
        newNode.prev=curr
        newNode.next=curr.next
        curr.next.prev=newNode
        curr.next=newNode
        self.count+=1
        
    def show(self,flag=True):
        curr=self.cri
        if flag:
            for i in range(self.count):
                print(curr.data,end='⇢')
                curr=curr.next
            print(curr.data)
        else:
            for i in range(self.count):
                print(curr.data,end='⇢')
                curr=curr.prev
            print(curr.data)

li = DoubleCircleLinkedList()
li.insert(0,'A')
li.insert(0,'B')
li.insert(1,'C')
li.show()
