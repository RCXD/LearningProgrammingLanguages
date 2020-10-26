#연결트리
#인덱스로 찾는다.

class Node:
    idx=1
    def __init__(self, data):
        self.data=data
        self.next=None #Notice: 아직은 선형구조임. 1:1
        self.idx=Node.idx #노드 클래스 자체의 인덱스를 넣어준다.
        Node.idx += 1 #하나씩 증가시켜준다.
        #OOP를 좀 배워야할거같다. 인강을 꼭 들어야 할 듯

class LinkedBTree:
    def __init__(self):
        self.root=None
        self.count=0

    def insertNode(self, data): #Notice: 선형구조를 트리처럼 쓰고 있는 상황임!
        newNode=Node(data)
        if self.root is None: #루트가 없는 경우
            self.root=newNode #루트에 뉴노드를 만들어넣는것
        else: #루트가 있는 경우
            curr=self.root #루트를 현재노드로 잡고
            for i in range(self.count-1): #0부터 개수-1까지, 맨 끝까지 이동. count-1번 점프한다.
                #간선의 개수 = 이동 횟수
                curr=curr.next #현재노드는 루트를 가리키고있으니 next는 루트의 next부터 순서대로 이동함.
                #루트를 이동시키는게 아니라 curr를 이동시켜야 타겟을 잡으니까.
                #원래 가리키는 관계를 훼손하지 않으니 이동 효과가 나는 것.
            curr.next=newNode #잡은 적절한 타겟에 newNode를 저장
            #원래 맨끝의 next는 None이므로, newNode를 저장하면 연결하는 효과가 남.
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
        #싹다 스캔
        for i in range(self.count):
            if curr.next.data==data: #삭제할 노드 전까지 이동
                #이래야 이전노드 찾는 행동을 한번 더 하지 않을 수 있다.
                deleteNode=curr.next #삭제할 노드는 data가 일치하는 노드
                preNode=curr #삭제할 노드의 전 노드
                break
            curr=curr.next
        curr=deleteNode
        while curr.next is not None:
            curr.idx -= 1
            curr=curr.next
        #여기까지가 인덱스 이동
        #연결 귾어주기
        preNode.next=preNode.next.next
        if preNode is None:
            self.root=self.root.next
        else:
            preNode.next=preNode.next.next는
        print('delete: ', data)
        self.count-=1
        Node.idx-=1
        return deleteNode

        #Mission: 부모노드, 자식노드 찾기

#왜 에러나냐 ㅡㅡ


t=LinkedBTree()
for i in range(1, 21):
    t.insertNode(i)
t.printNode()

t.deleteNode(18)
t.printNode()