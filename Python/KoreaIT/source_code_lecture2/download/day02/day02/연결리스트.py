class Node:
    def __init__(self,data):
        self.data=data
        self.next=None #모든 타입의 초기값

class LinkedList:
    def __init__(self):
        self.head=Node('head')
        self.count=0

    #추가
    def append(self,data):  ㅜ  
        newNode = Node(data)
        curr=self.head
        for i in range(self.count):
            curr=curr.next
        curr.next=newNode
        self.count+=1
    #삽입
    def insert(self,idx,data):
        if(idx<0 or idx>self.count):
            print("해당 위치 삽입 불가")
            return
        newNode = Node(data)
        curr=self.head
        for i in range(idx):
            curr=curr.next
        if(curr.next is not None):
            temp=curr.next
            curr.next=newNode
            newNode.next=temp
        else:
            curr.next=newNode
        self.count+=1
    #수정
    def update(self,idx,data):
        curr=self.head
        for i in range(idx+1):
            curr=curr.next
        curr.data=data
    #삭제
    def delete(self,idx):
        if(idx<0 or idx>=self.count):
            print("존재하지 않는 인덱스")
            return
        curr=self.head
        for i in range(idx):
            curr=curr.next
        #print(idx,':',curr.next.data)
        temp=curr.next
        if(curr.next.next is not None):
            curr.next=curr.next.next
        else:
            curr.next=None
        del temp
        self.count-=1
    #조회
    def get(self,idx):
        if(idx<0 or idx>=self.count):
            print("존재하지 않는 인덱스")
            return
        curr=self.head
        for i in range(idx+1):
            curr=curr.next
        #print(idx,':',curr.data)
        return curr
    #목록
    def selectAll(self):
        curr=self.head
        while curr.next is not None:
            print(curr.data,end='->')
            curr=curr.next
        print(curr.data)
'''
li=LinkedList()
li.append('A')
li.append('B')
li.append('C')
li.insert(1,'D')
#head->A->D->B->C
li.selectAll()
#head->A->E->B->C
li.update(1,'E')
li.get(2)
li.delete(2)
#head->A->E->C
li.selectAll()
li2=LinkedList()
li2.append(1)
'''
