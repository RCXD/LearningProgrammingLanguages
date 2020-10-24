#연결큐
class Node:
    def __init__(self, data):
        self.data=data
        self.next=None #next가 들어가면 이중연결인거임.
        #Qx. 리스트와 Queue의 차이가 뭘까?

class LinkedQueue:
    def __init__(self):
        self.front=None
        self.rear=None
    def is_empty(self):
        return self.front==None

    #def is_full(self): #굳이 필요 없다..!
    #    pass

    def enQueue(self, data):
        #추가할 데이터로 Node객체 만들기
        newNode=Node(data)
        print('insert data: ', data)
        #첫 추가이면 
        if self.is_empty(): #첫추가일땐 rear, front를 newNode로 해두면 됨
            #front도 추가하는 node로 바꿔 준다
            self.front=newNode
        #첫 추가가 아니면
        else:
            #현재 rear의 next를 추가하는 node로 바꿔서 연결을 해준다.
            self.rear.next=newNode #두번째부터 연결을 해주고 나서
        #현재 rear를 새로 추가한 node로 변경
        self.rear=newNode   #새 노드를 추가해준다.

    def deQueue(self):
        if not self.is_empty():
            #front 위치에 있는 데이터를 data 변수에 넣어주고
            data=self.front.data
            #출력
            print('delete data: ', data)
            #front 위치를 다음으로 변경
            self.front=self.front.next #python에서는 front, rear를 모두 같이 옮겨버리면, 가리키지 않는 공간은 알아서 삭제된다고?
                #과연 그럴까? 맞을까? C는 하나하나 다 삭제해줘야한다고 함
            #변경위치가 비어있다면 큐가 비어있다는 뜻임. 
            if self.front is None:
                #아직 값이 남아있는 rear를 None으로 변경(??)
                self.rear = None
    #front부터 다음노드로 이동하면서 하나씩 출력
    def show(self):
        curr=self.front
        while curr.next != None:
            print(curr.data, end=' ') #헤드가 없으니 curr부터가 데이터임.
            curr=curr.next
        print(curr.data) #논리 보정

#자료구조는 자료를 만들어내는게... 중요하다나 뭐라나
#테트리스 소스파일도 찾아보라나?

li = LinkedQueue()
li.enQueue('A')
li.enQueue('B')
li.enQueue('C')
li.enQueue('D')
li.show()
li.deQueue()
li.show()