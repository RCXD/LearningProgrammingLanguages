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
            curr=curr.next #왼쪽 current는 공간의미, 오른쪽 current는 값의 의미...! 
            #등호 왼쪽이냐 오른쪽이냐 차이
        curr.next=newNode
        newNode.next=self.head
        self.count+=1
        
    #삽입
    def insert(self,idx,data):
        if(idx <= self.count):
            newNode=Node(data)
            curr=self.head #head로 이동
            for i in range(idx-1):
                curr=curr.next #다음으로 이동
            newNode.next = curr.next #개념적으로, 이걸 먼저 실행해줘야한다.
            #처리순서가 중요함. 
            #A, B 사이에 끼워넣는 경우 B는 A.next이지만 new.next는 B가 아니다.
            curr.next = newNode

    #파이썬은 동시에 바꾸는게 가능은 하다고 함. 확인바람!
    """
    data1 = 10
    data2 = 20
    data2.data1 = data1.data2 #???
    """
            
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
            self.count -= 1 #삭제 후 개수 맞춰주기
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
cll.insert(2, 'D')
cll.show()#head>>A>>D>>B>>C
cll.delete(3)
cll.show()#head>>A>>D>>C
cll.update(1, 'E')
cll.show()#head>>E>>D

#마지막 리스트를 헤드랑만 연결해주면 그게 원형연결리스트라고 함.
#복습하자...