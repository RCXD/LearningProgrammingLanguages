MAX_SIZE=4
class Node:
    def __init__(self,data):
        self.data=data

class CircularQueue:
    def __init__(self):
        self.front=0
        self.rear=0
        self.ql=[]
        #ql에 비어있는 데이터를 추가함으로서 일단 ql의 크기를 MAX_SIZE로 맞춰준다
        for i in range(MAX_SIZE):
            self.ql.append('')

    def is_full(self):
        #rear와 front가 같고, front 위치에 ''가 아닌 노드가 담겨있다면 꽉차있는 상태
        return self.rear==self.front and self.ql[self.front]!=''
    
    def is_empty(self):
        #반대로 rear와 front가 같고, front 위치에 노드 대신 ''가 있다면 비어있는 상태
        return self.rear==self.front and self.ql[self.front]==''

    def enQueue(self,data):
        if not self.is_full():
            newNode = Node(data)
            print("insert :",data)
            #rear 위치에 새로운 노드 추가
            self.ql[self.rear]=newNode
            #rear 1 증가
            self.rear+=1
            #만약 rear가 MAX_SIZE가 됐다면, rear를 0으로 옮겨주어야 하므로
            #MAX_SIZE로 나눈 나머지로 바꾸어 준다.
            #만약 MAX_SIZE보다 작은 숫자였다면 나눈 나머지는 그대로이다 (ex : 4->0 / 3->3)
            self.rear=self.rear%MAX_SIZE
            
    def deQueue(self):
        if not self.is_empty():
            #front 위치에 있는 데이터 출력
            data = self.ql[self.front].data
            print("delete :",data)
            #front 위치에 노드 대신 ''를 넣어준다(비어있다는 의미로)
            self.ql[self.front]=''
            #front 1 증가
            self.front+=1
            #위와같은 이유로 최대크기로 나눈 나머지로 바꾸어준다
            self.front%=MAX_SIZE

    #front부터 시작해서 한바퀴 돌면서 데이터가 있는것들만 출력해준다
    def show(self):
        if not self.is_empty():
            currIdx = self.front
            while True:
                print(self.ql[currIdx].data)
                currIdx+=1
                #currIdx가 MAX_SIZE를 넘어가지 않게 위와같이 나눈 나머지로 바꾸어준다
                currIdx%=MAX_SIZE
                #만약 옮기다가 다시 front와 currIdx가 같은경우가 온다면 한바퀴 돌았다는
                #뜻이므로 탈출해준다. 또한 currIdx 위치에 ''가 들어있다면 데이터가 없다는
                #뜻이므로 그때도 탈출이 필요하다. 따라서 두 조건을 or로 연산해준다
                if(self.ql[currIdx]=='' or currIdx==self.front):
                    break













