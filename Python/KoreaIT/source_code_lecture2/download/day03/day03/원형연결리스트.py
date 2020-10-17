class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class CircleLinkedList:
    def __init__(self):
        self.head=Node('head')
        self.count=0
    #추가
    def append(self,data):
        newNode=Node(data)
        curr=self.head
        for i in range(self.count):
            curr=curr.next
        curr.next=newNode
        newNode.next = self.head
        self.count+=1
        
    #삽입
    def insert(self,idx,data):
        if (idx<=self.count):
            newNode=Node(data)
            curr=self.head
            for i in range(idx-1):
                curr=curr.next
            newNode.next=curr.next
            curr.next=newNode
            self.count+=1
            
    #수정
    def update(self,idx,newData):
        if (idx<=self.count):
            curr=self.head
            for i in range(idx):
                curr=curr.next
            curr.data=newData
    #삭제
    def delete(self,idx):
        if(idx<=self.count):
            curr=self.head
            for i in range(idx-1):
                curr=curr.next
            curr.next=curr.next.next
            self.count-=1
    #조회
    def get(self,idx):
        if(idx>self.count):
            pass
        else:
            curr=self.head
            for i in range(idx):
                curr=curr.next
            print(curr.data)
    #목록
    def show(self):
        curr=self.head
        for i in range(self.count):
            print(curr.data,end="»")
            curr=curr.next
        print(curr.data)

cll=CircleLinkedList()
cll.append('A')
cll.append('B')
cll.append('C')
cll.show()#head>>A>>B>>C
cll.insert(2,'D')
cll.show()#head>>A>>D>>B>>C
cll.delete(3)
cll.show()#head>>A>>D>>C
cll.update(1,'E')
cll.show()










