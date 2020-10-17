class Node:
    def __init__(self,data):
        self.data=data
        self.prev=None
        self.next=None

class DoubleLinkedList:
    def __init__(self):
        #헤드노드
        self.head=Node('head')
        #테일노드
        self.tail=Node('tail')
        #head의 next에 tail연결
        self.head.next=self.tail
        #tail의 prev에 head연결
        self.tail.prev=self.head
        self.count=0
    #추가
    def append(self,data):
        newNode=Node(data)
        #추가하려는 노드의 next는 무조건 tail일 수밖에 없다.
        #newNode의 next에 self.tail의 주소값 넣기
        newNode.next=self.tail
        #newNode의 prev은 현재 tail의 prev노드로 넣어주어야 한다.
        newNode.prev=self.tail.prev
        #tail의 prev은 이제 newNode로 새로 연결
        #tail의 기존 prev노드의 next는 newNode로 연결
        self.tail.prev.next=newNode
        self.tail.prev=newNode
        self.count+=1
        
    #삽입
    def insert(self,idx,data):
        if idx>self.count:
            return
        newNode=Node(data)
        #idx가 머리에 가까운 위치
        if idx <= self.count/2:
            #head부터 next로 접근하기
            curr=self.head
            #추가하려는 위치 전 까지 이동하기 위해 idx-1만큼 for문 반복
            for i in range(idx-1):
                curr=curr.next
                
            #현재 curr : 추가하는위치 전 노드
            #newNode의 prev과 next를 셋팅하기
            newNode.prev=curr
            newNode.next=curr.next

            #temp에 현재 curr에 연결되어있는 다음 노드를 임시저장
            temp=curr.next
            #curr에 있는 next를 추가하는 노드로 변경
            curr.next=newNode
            #임시저장한 temp(원래 curr의 next로 연결되어있던 노드)의 prev을
            #추가하는 노드로 변경
            temp.prev=newNode
            
        #idx가 꼬리에 가까운 위치
        else:
            #tail부터 prev으로 접근하기
            '''
            curr=self.tail
            for i in range(self.count-idx+2):
                curr=curr.prev

            newNode.prev=curr
            newNode.next=curr.next
            temp=curr.next
            curr.next=newNode
            temp.prev=newNode
            '''
            curr=self.tail
            for i in range(self.count-idx+1):
                curr=curr.prev

            newNode.prev=curr.prev
            newNode.next=curr

            curr.prev.next=newNode
            curr.prev=newNode
            
                
        self.count+=1
    #수정
    def update(self,idx,newData):
        if idx>self.count:
            return
        curr=None
        if idx <= self.count/2:
            curr=self.head
            for i in range(idx):
                curr=curr.next
        else:
            curr=self.tail
            for i in range(self.count-idx+1):
                curr=curr.prev
        curr.data=newData
            
    #삭제
    def delete(self,idx):
        if idx>self.count:
            return
        curr=None

        if idx <= self.count/2:
            #get 메소드를 먼저 선언해 놓을 시 return을 통해 해당하는 인덱스의
            #Node를 반환받기 때문에 훨씬 편하게 사용할 수 있다.
            #아래의 for문을 통해 이동하는 코드를 쓸 필요가 없다.
            #curr=self.get(idx-1)

            curr=self.head
            for i in range(idx-1):
                curr=curr.next
            #현재 curr : 삭제하려는 위치 전 노드

            #삭제하려는 위치 다음노드의 prev을 curr로 변경
            curr.next.next.prev=curr
            #curr의 next를 삭제하려는 위치 다음노드로 변경
            curr.next=curr.next.next
                      
        else:
            curr=self.tail
            #curr=self.get(idx+1)
            for i in range(self.count-idx):
                curr=curr.prev
            curr.prev.prev.next=curr
            curr.prev=curr.prev.prev
        self.count-=1

    #조회
    def get(self,idx):
        if idx>self.count:
            return
        curr=None
        if idx <= self.count/2:
            curr=self.head
            for i in range(idx):
                curr=curr.next
        else:
            curr=self.tail
            for i in range(self.count-idx+1):
                curr=curr.prev
        print(curr.data)
        return curr
    #목록(인덱스 오름차순)
    def ascShow(self):
        curr=self.head
        for i in range(self.count):
            print(curr.data,end="→")
            curr=curr.next
        print(curr.data)
    #목록(인덱스 내림차순)
    def descShow(self):
        curr=self.tail
        for i in range(self.count):
            print(curr.data,end="→")
            curr=curr.prev
        print(curr.data)
    def show(self,flag=True):
        if flag:
            self.ascShow()
        else:
            self.descShow()

dll=DoubleLinkedList()
dll.append('A')
dll.append('B')
dll.append('C')
dll.show()#오름차순
dll.show(False)#내림차순
dll.insert(2,'D')
dll.show()
dll.update(3,'E')
dll.show()
dll.delete(2)
dll.show()
dll.get(3)

