MAX_SIZE = 5
class Node:
    def __init__(self,data):
        self.data=data

class LinearQueue:
    def __init__(self):
        self.ql=[]
        self.front=0
        self.rear=0
        self.count=0

    def is_empty(self):
        return self.front==self.rear
    
    def is_full(self):
        return self.rear==MAX_SIZE
    
    def enQueue(self,data):
        if not self.is_full():
            print("insert data :",data)
            newNode=Node(data)
            #rear 위치에 데이터 추가
            self.ql.insert(self.rear,newNode)
            self.rear+=1

    def deQueue(self):
        if not self.is_empty():
            data=self.ql[self.front].data
            print("delete data :",data)
            #front 위치의 데이터 삭제
            self.ql[self.front]=''
            self.front+=1

    def show(self):
        if not self.is_empty():
            for i in range(self.front,self.rear):
                print(self.ql[i].data)

lq = LinearQueue()
lq.enQueue('A')
lq.enQueue('B')
lq.enQueue('C')
lq.enQueue('D')
lq.deQueue()
lq.deQueue()
lq.deQueue()










    
