MAX_SIZE = 5



class Node:
    def __init__(self,data):
        self.data=data

class Stack:
    #메소드의 이름에 is, has가 있다면 보통 리턴이 Bool타입(True,False)
    def __init__(self):
        self.stackList=[]
        self.top=0
        self.bottom=0

    #push(추가) : is_full?
    def push(self,data):
        if not self.is_full():
            newNode=Node(data)
            self.stackList.insert(self.top,newNode)
            self.top+=1
    #pop(제거) : is_empty?

    
    #is_empty(비어있는 여부)
    def is_empty(self):
        return self.top==self.bottom
    #is_full(꽉차있는 여부)
    def is_full(self):
        return self.top==MAX_SIZE
