#원형큐
MAX_SIZE = 4

class Node:
    def __init__(self, data):
        self.data = data

class CircularQueue:
    def __init__(self):
        self.front=0
        self.rear=0
        self.ql=[]
        for i in range(MAX_SIZE):
            self.ql.append('')
    
    def is_full(self):
        #self.ql[self.front]
        return self.rear==self.front and self.ql[self.front]!=''
    def is_empty(self):
        return self.rear==self.front and self.ql[self.front]==''
    def enQueue(self, data):
        if not self.is_full():
            newNode = Node(data)
            print('insert: ', data)
            self.ql[self.rear]=newNode
            self.rear+=1
            self.rear=self.rear%MAX_SIZE

    def deQueue(self):
        if not self.is_empty():
            data = self.ql[self.front].data
            print('delete :', data)
            self.ql[self.front]=''
            self.front+=1
            self.front%=MAX_SIZE
    def show(self):
        if not self.is_empty():
            currIdx = self.front
            cnt = 0
            while True:
                print(self.ql[currIdx].data)
                currIdx+=1
                currIdx%=MAX_SIZE
                if(self.ql[currIdx]==''or cnt==MAX_SIZE):
                    break
    

#이 자료구조 수업은 선행학습 없이는 살아남을 수가 없는 것 같다.
        

ql=CircularQueue()
ql.enQueue('A')
ql.enQueue('B')
ql.enQueue('C')
ql.enQueue('D')
ql.enQueue('E')
ql.show()

ql.deQueue()
ql.deQueue()
ql.show()