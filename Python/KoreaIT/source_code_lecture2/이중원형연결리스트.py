#head와 tail을 연결해야 함.
#tail.next는 head,
#head.prev는 tail

#Mission : 삽입까지 구현

class Node:
    def __init__(self, data):
        self.data=data
        self.next=None
        self.prev=None
"""
class DoubleCircleLinkedList:
    def __init__(self):
        self.head = Node('head')
        self.tail = Node('tail')
        #이중원형은 기준(criteria)를 만듦
        self.head.prev = self.tail
        self.head.next = self.tail #
        self.tail.prev = self.head #
        self.tail.next = self.head
        self.count = 0

    #첫번째 node의 idx = 0으로
    def insert(self, idx, data):
        if idx > self.count and idx < 0: #idx가... 0, 1은 통과된다고?
            return
        newNode = Node(data)
        if idx <= self.count/2: #이것도 논리가 맞나? 그림이 안그려지는데
            curr = self.head
            for i in range(idx): #삽입위치 전까지 이동
            #for i in range(idx-1): #이거는 첫 index가 1일 때
                curr = curr.next
        else:
            curr = self.tail
            for i in range(self.count - idx + 1):
                curr = curr.prev

        newNode.prev = curr
        newNode.next = curr.next
        curr.next = newNode
        curr.next.prev = newNode
            
        self.count+=1

    def show(self):

        curr = self.head
        for i in range(self.count):
            print(curr.data, end = '>')
            curr=curr.next
        print(curr.data)
"""

class DoubleCircleLinkedList:
    def __init__(self):
        self.cri=Node('cri')
        self.cri.next=self.cri
        self.cri.prev=self.cri
        self.count=0

    def insert(self, idx, data):
        if idx>self.count and idx < 0:
            return
        newNode = Node(data)
        curr=self.cri
        if idx<=self.count/2:
            for i in range(idx):
                curr=curr.next
        else:
            for i in range(self.count-idx+1):
                curr=curr.prev

        newNode.prev = curr
        newNode.next = curr.next
        curr.next.prev = newNode
        curr.next = newNode
        self.count += 1

    def show(self, flag=True):
        curr=self.cri
        if flag:
            for i in range(self.count):
                print(curr.data, end='>')
                curr= curr.next
            print(curr.data)
        else:
            for i in range(self.count):
                print(curr.data, end='>')
                curr=curr.prev
            print(curr.data)

ll = DoubleCircleLinkedList()
ll.insert(0, 'A')
ll.insert(0, 'B')
ll.insert(1, 'C')
#ll.insert(3, 'D') #BCAD... 안되네? 문제 해결좀
ll.show()
ll.show(False)
#코드업에서 천문제는 풀어야 늘 수 있다!!

##자료구조
#리스트
#연결리스트
#스택
#큐
#트리
#덱(생략?)

##기술
#정렬
#해싱

#따라가려면 선행학습을 해야겠다..
#보충계획 - 조교 : 선형리스트, 연결리스트