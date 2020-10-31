class Node:
    idx=1
    def __init__(self,data):
        self.data=data
        self.next=None
        self.idx=Node.idx
        Node.idx+=1

class LinkedBTree:
    def __init__(self):
        self.root=None
        self.count=0

    def insertNode(self,data):
        newNode=Node(data)
        if self.root is None:
            self.root=newNode
        else:
            curr=self.root
            for i in range(self.count-1):
                curr=curr.next
            curr.next=newNode
        self.count+=1

    def printNode(self):
        curr=self.root
        num=1
        for i in range(self.count):
            if curr.idx%(2**num)==0:
                print()
                num+=1
            print(curr.data,end=' ')
            curr=curr.next
        print()
    def deleteNode(self,data):
        curr=self.root
        deleteNode=self.root
        preNode=None
        for i in range(self.count-1):
            if curr.next.data==data:
                deleteNode=curr.next
                preNode=curr
                break
            curr=curr.next
        curr=deleteNode
        while curr.next is not None:
            curr.idx-=1
            curr=curr.next
            
        if preNode is None:
            self.root=self.root.next
        else:
            preNode.next=preNode.next.next
        print("delete :",data)
        self.count-=1
        Node.idx-=1
        return deleteNode

t=LinkedBTree()
for i in range(1,21):
    t.insertNode(i)
t.printNode()
t.deleteNode(18)
t.printNode()







