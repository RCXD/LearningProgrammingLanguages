class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircleLinkedList:
    def __init__(self):
        self.head=Node('head')
        self.count = 0

#자료구조의 6가지 기본 기능
    #추가
    def append(self, data):
        newNode=Node(data)
        curr=self.head #어디있는지 알려주기 위함...
        for i in range(self.count):
            curr=curr.next
        curr.next=newNode
        newNode.next=self.head
        self.count+=1
    #삽입
    def insert(self, idx, data):
        #추가와 반대?
    #수정
    def update(self, idx, data):
        if (idx <= self.count):
            curr = self.head
            for i in range(idx):
                curr=curr.next
            curr.data = newData
    #삭제
    def delete(self, idx):
        if(idx<=self.count):
            cur=self.head
            for i in range(idx-1):
                curr=curr.next
            curr.next = curr.next.next
    #조회
    def get(self, idx): #idx를 0부터 할지, 1부터 할지도 결정할 수 있다
        if(idx>self.count):
            pass
        else:
            curr=self.head 
            for i in range(idx):
                curr = curr.next
            print(curr.data) #편한 방법
            #return curr.data #리턴을 할 경우 호출해서 함. 실제로는 리턴을 많이 사용
    #목록
    def show(self):
        curr=self.head
        for i in range(self.count):
            print(curr.data.end='😊') #win + . #뭐가 문제???
            curr = curr.next
        print(curr.data)

cll=CircleLinkedList()
cll.append('A')
cll.append('B')
cll.append('C')
cll.show()


#근데 왜 자료구조를 만들고있지?
#만들어진게 있겠지만 이해를 위해 만드나?