#선형큐

MAX_SIZE = 5
class Node:
    def __init__(self, data):
        self.data=data

class LinearQueue:
    def __init__(self):
        self.ql = [] #queue list
        self.front=0
        self.rear=0
        self.count=0

    def is_empty(self):
        return self.front==self.rear
    def is_full(self):
        return self.rear==MAX_SIZE #삽입은 rear에서 한다! 혼란 주의
    def enQueue(self, data):
        if not self.is_full():
            print('insert data:', data)
            newNode=Node(data)
            #rear 위치에 데이터 추가
            self.ql.insert(self.rear, newNode) #rear 위치에 데이터 추가해야 한다
            #Qx. 이 ql은 정리가 잘 될까?
            self.rear+=1
    def deQueue(self):
        if not self.is_empty():
            data=self.ql[self.front].data
            print('delete data:', data)
            #front 위치의 데이터 삭제
            self.ql[self.front]='' #del, pop을 쓰는건 적절하지 않다고 함. 빈거를 넣어주는 이유는??
            self.front+=1
    def show(self):
        if not self.is_empty():
            for i in range(self.front, self.rear):
                print(self.ql[i].data, end=' ')

lq=LinearQueue()
lq.enQueue('A')
lq.enQueue('B')
lq.enQueue('C')
lq.enQueue('D')
lq.show()
lq.ql
lq.deQueue()
