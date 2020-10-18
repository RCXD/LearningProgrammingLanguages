MAX_SIZE = 5 #억지? 라고함. Python의 List는 동적이어서...

class Node:
    def __init__(self, data):
        self.data=data

class Stack:
    #메소드의 이름에 is, has가 있다면 보통 리턴이 bool타입(True, False)
    
    

    def __init__(self):
        self.stackList=[]
        self.top=0 #top은 보통 -1부터 시작한다고 한다. 의미상... 참고자료 필요!
        self.tempTop=0 #push하면 tempTop과 top이 같이 올라가지만, pop하면 tempTop만 내릴거라고 함.
        #원래는 tempTop은 필요 없는 변수라고 함. top만 있으면 된다고.
        #self.bottom=0 #bottom은 공간이 한정될 때 한꺼번에 옮길때 쓴다? 나중에 확인바람
        #bottom은 queue 구조에서 쓰는 변수라고 함.

    #push(추가) : is full?
    def push(self, data):
        if not self.isFull():
            newNode=Node(data)
            self.stackList.insert(self.tempTop, newNode) #insert는 리스트 메소드임
            self.top += 1
            self.tempTop += 1
        else:
            print('stack overflow')
    #pop(제거) : 항상 is empty?
    def pop(self): #이미 List의 메소드에 pop이 있긴 하다.
        if not self.isEmpty():
            print(self.stackList[self.tempTop-1].data) #제거가 아닌거같은데?
            self.tempTop -= 1

    #isEmpty(비어있는지 여부) : top = bottom
    def isEmpty(self):
        return self.tempTop == 0

    #isFull(꽉 차있는지 여부) : top = max size
    def isFull(self):
        return self.top==MAX_SIZE #비어있어도 한번 채우면 더이상 넣지 않을 예정(억지로 만든거다?)
        #억지로 tempTop을 만드는 이유는 무엇이려나?

sl=Stack()
sl.push('A')
sl.push('B')
sl.push('C')
sl.push('D')
sl.push('E')
sl.pop() #E
sl.pop() #D