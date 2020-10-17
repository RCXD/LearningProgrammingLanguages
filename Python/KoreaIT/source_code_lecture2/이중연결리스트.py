class Node:
    def __init__(self, data): #기본 틀!
        self.data=data
        self.prev=None #초기화
        self.next=None #초기화

class DoubleLinkedList:
    def __init__(self):
        #헤드 노드
        self.head=Node('head')
        #테일 노드
        self.tail=Node('tail') #이중연결은 tail이 필요하다! 노드가 2개부터 시작하는 거임.
        #head의 next에 tail 연결
        self.head.next = self.tail #미리 head와 tail을 연결하고 시작
        #tail의 prev에 head 연결
        self.tail.prev = self.head #미리 head와 tail을 연결하고 시작
        self.count=0 #노드가 두개여도 head와 tail은 데이터가 아니다. 개수와 무관
        #head는 prev이 필요없고 tail은 next가 필요없다.

    #추가(무조건 뒤에.. tail에..)
    def append(self, data):
        newNode=Node(data)
        #self.tail.prev.next = newNode #이건 무엇?
        #추가하려는 노드의 next는 무조건 tail일 수밖에 없다.
        #newNode의 next에 self.tail의 주소값 넣기
        newNode.next=self.tail #새거의 다음이 tail을 가리키게함
        #newNode의 prev은 현재 tail의 prev노드로 넣어주어야 한다.
        newNode.prev=self.tail.prev #새거의 전은 원래 tail의 이전꺼를 가리게 하여 
            #tail의 이전꺼와 tail 사이에 새거를 끼워넣음
        self.tail.prev.next = newNode
        self.tail.prev=newNode
        self.count+=1
        """ 필요없는 구조. tail이 있기 때문
        curr=self.head
        for i in range(self.count):
            curr = curr.next
        curr.next = newNode
        newNode.prev = curr
        tail.prev=newNode
        """
    
    #삽입
    def insert(self, idx, data):
        if idx > self.count: #인덱스 초과
            print("index 초과")
            return #종료의 의미
        newNode=Node(data)
        #idx가 머리에 가까운 위치
        if idx<= self.count/2: #head와 가까운지, tail에 가까운지 판단하는 과정
            #head부터 next로 접근하기
            curr = self.head #head의 속성을 가져온다. next도 쓸 수 있다니...
            #추가하려는 위치 전까지 이동하기 위해 idx-1만큼 for문 반복
            for i in range(idx-1): #헤드부터 한번 이동하는 효과라고...?
                curr = curr.next #이게 무슨 의미더라? 다음꺼의 주소 가져오는거 맞나?
            #현재 curr: 추가하려는 위치 전 노드
            #newNode의 prev과 next를 세팅하기
            newNode.prev=curr
            newNode.next = curr.next
            #temp에 현재 current에 연결되어 있는 다음 노드를 임시 저장
            temp = curr.next #임시로 보관
            #current에 있는 next를 추가하는 노드로 변경
            curr.next = newNode
            #임시저장한 temp(원래 curr의 next로 연결되어 있던 node)의 prev을
            #추가하는 노드로 변경
            temp.prev = newNode
        else: #idx가 꼬리에 가까운 위치
            ''' #최적화 코딩
            #tail부터 prev로 접근하기
            curr=self.tail
            #for i in range(idx-1):
            for i in range(self.count - idx+2): #전체 개수에서 인덱스만큼 전진, 두번 후진
                #좀더 생각해보자... 인덱싱...
                curr = curr.prev
            # 전 노드로 이동했으면 아래는 동일
            newNode.prev = curr
            newNode.next = curr.next
            temp=curr.next
            curr.next=newNode
            temp.prev=newNode
            '''
            #학술적 수준 접근
            curr=self.tail
            for i in range(self.count-idx+1):
                curr=curr.prev
            newNode.prev=curr.prev
            newNode.next=curr

            curr.prev.next=newNode
            curr.prev = newNode

        self.count+=1


    #수정
    def update(self, idx, newData):
        if idx>self.count:
            return "wrong index"
        if idx <= self.count/2:
            curr=self.head
            for i in range(idx):
                curr=curr.next
        else:
            curr=self.tail
            for i in range(self.count-idx+1): #tail node가 있기 때문에 가중치 1
                curr=curr.prev
        curr.data=newData
    #조회
    def get(self,idx):
        if idx>self.count:
            return "wrong index"
        curr=None
        if idx <= self.count/2:
            curr=self.head
            for i in range(idx):
                curr=curr.next
        else:
            curr=self.tail
            for i in range(self.count-idx+1): #tail node가 있기 때문에 가중치 1
                curr=curr.prev
        print(curr.data)

    #삭제
    def delete(self, idx):
        if idx>self.count:
            return "wrong index"
        curr=None
        if idx <= self.count/2:
            #get메소드를 먼저 구현해놓을 시 return을 통해
            #해당하는 인덱스의 Node를 반환받기 때문에 훨씬
            #편하게 사용할 수 있다.
            #아래의 for문을 통해 이동하는 코드를 쓸 필요가 없다
            #curr=self.get(idx-1) #이걸 쓰면 수정에서 if-else도 삭제해버릴 수 있다나?
            curr=self.head
            for i in range(idx):
                curr=curr.next
            #현재 curr : 삭제하려는 위치 전 노드

            #삭제하려는 위치 다음노드의 prev을 curr로 변경
            curr.next=curr.next.next 
            #curr.next는 원래 삭제할 대상을 가리킴
            #curr.next.next는 삭제대상 다음의 데이터임
            #curr의 next를 삭제하려는 위치 다음노드로 변경
            curr.next.next.prev=curr
            #삭제할 데이터 양쪽의 연결을 끊어야한다.
            #순서바꿔도 무관할듯?
            #curr.next.next.prev=curr
            #curr.next=curr.next.next
        else: #반대로 돌기
            curr=self.tail
            #curr=self.get(idx+1)
            for i in range(self.count-idx+1): #tail node가 있기 때문에 가중치 1
                curr=curr.prev
            curr.prev.prev.next = curr
            curr.prev=curr.prev.prev
        self.count -= 1

    #목록 한번에
    def show(self, flag=True): #기본값 오름차순
        if flag :
            self.ascShow() #내부함수니까 self!
        else:
            self.descShow()
    #목록1.. idx 오름차순
    def ascShow(self): #ascending : 오름차순
        curr = self.head
        for i in range(self.count):
            print(curr.data, end="→ ") #이상한 이모지 쓰니까 깨지네
            curr=curr.next
        print(curr.data) #마지막에 화살표를 표시하기 않기 위해 최종 데이터 출력

    #목록2.. idx 내림차순
    def descShow(self):
        curr=self.tail
        for i in range(self.count):
            print(curr.data, end="↠ ")
        print(curr.data)
    #... 정렬되어 있다면 처리속도가 매우 빨라진다고 함.
    #... 정렬도 할 줄 알아야 한다고 함.

dll=DoubleLinkedList() #무엇? 왜안됨?
dll.append('A')
dll.append('B')
dll.append('C')
dll.show() #ABC
dll.show(False) #tail>C>B>A #뭔가 코딩 잘못함. 수정바람
dll.insert(2, 'D')
dll.show() #ADBC
dll.update(3, 'E')
dll.show() #ADEC
dll.delete(2) #2번위치면 D가 지워져야하는데 E가 지워졌다. 오류 수정바람
dll.show() #AEC
dll.get(3) #C가 나와야 한다는데...?

#get때문에 빠르고 편한거라나??


#여기서 말하는 Node가 Node.js에서 말하는 Node인가?