MAX_SIZE = 5

class Node:
    def __init__(self,data):
        self.data=data

class Stack:
    #메소드의 이름에 is, has가 있다면 보통 리턴이 Bool타입(True,False)
    def __init__(self):
        self.stackList=[]
        self.top=0
        self.tempTop=0

    #push(추가) : is_full?
    def push(self,data):
        if not self.is_full():
            newNode=Node(data)
            self.stackList.insert(self.tempTop,newNode)
            self.top+=1
            self.tempTop+=1
        else:
            print("stack overflow")
            
    #pop(제거) : is_empty?
    def pop(self):
        if not self.is_empty():
            print(self.stackList[self.tempTop-1].data)
            self.tempTop-=1
    
    #is_empty(비어있는 여부)
    def is_empty(self):
        return self.tempTop==0
    #is_full(꽉차있는 여부)
    def is_full(self):
        return self.top==MAX_SIZE

sl = Stack()
sl.push('A')
sl.push('B')
sl.push('C')
sl.push('D')
sl.push('E')
sl.pop()
sl.pop()
