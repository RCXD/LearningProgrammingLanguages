class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class LinkedQueue:
    def __init__(self):
        self.front=None
        self.rear=None

    def is_empty(self):
        return self.front==None

    def enQueue(self,data):
        #추가할 데이터로 Node 객체 만들기
        newNode=Node(data)
        print("insert data :",data)
        #첫 추가이면
        if self.is_empty():
            #front도 추가하는 node로 바꾸어 준다
            self.front = newNode
        #첫추가가 아니면
        else:
            #현재 rear의 next를 추가하는 node로 바꾸어서 연결을 해준다
            self.rear.next=newNode
        #현재 rear를 새로 추가한 node로 변경
        self.rear=newNode
            
    def deQueue(self):
        if not self.is_empty():
            #front 위치에 있는 데이터를 data 변수에 넣어주고
            data = self.front.data
            #출력
            print("delete data :",data)
            #front 위치를 다음 노드로 변경
            self.front=self.front.next
            #변경했더니 비어있다면 큐가 비어있다는 뜻이므로
            if self.front is None:
                #아직 값이 남아있는 rear를 None으로 변경해준다
                self.rear = None

    #front부터 다음노드로 이동하면서 하나씩 출력
    def show(self):
        curr=self.front
        while curr.next!=None:
            print(curr.data)
            curr=curr.next
        print(curr.data)

lq = LinkedQueue()
lq.enQueue('A')
lq.deQueue()









