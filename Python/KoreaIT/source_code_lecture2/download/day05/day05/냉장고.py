#(나는 지금 편돌이)

#안녕하세요 GS25 입니다
#1. 냉동식품
    #1. 냉동식품 추가하기
    #2. 폐기물 빼기
    #3. 뒤로가기
#2. 음료수
    #1. 음료수 추가하기
    #2. 음료수 빼기
    #3. 뒤로가기
#3. 나가기
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class LinkedQueue:
    def __init__(self):
        self.front=None
        self.rear=None

    def is_empty(self):
        return self.front==None

    def enQueue(self,data):
        newNode=Node(data)
        print(data,"추가완료")
        if self.is_empty():
            self.front = newNode
        else:
            self.rear.next=newNode
        self.rear=newNode
            
    def deQueue(self):
        if not self.is_empty():
            data = self.front.data
            print(data,"폐기완료")
            self.front=self.front.next
            if self.front is None:
                self.rear = None

    def show(self):
        curr=self.front
        while curr.next!=None:
            print(curr.data)
            curr=curr.next
        print(curr.data)

#각 냉장고별로 상품을 따로 보관해야하므로(햄버거는 냉동식품에, 사이다는 음료수에)
#큐를 두개 만들어준다
food = LinkedQueue()
drink = LinkedQueue()
while True:
    print("안녕하세요 GS25 입니다\n1. 냉동식품\n2. 음료수\n3. 전체 냉장고 보기\n4. 나가기")
    choice=int(input())
    if choice==1:
        # 냉동식품
        while True:
            print("1. 냉동식품 추가하기\n2. 폐기물 빼기\n3. 뒤로가기")
            choice=int(input())
            if choice==1:
                #냉동식품 추가
                food.enQueue(input("추가할 상품 : "))
            elif choice==2:
                #폐기물 빼기
                food.deQueue()
            elif choice==3:
                break
            
    elif choice==2:
        #음료수
        while True:
            print("1. 음료수 추가하기\n2. 폐기물 빼기\n3. 뒤로가기")
            choice=int(input())
            if choice==1:
                #음료수 추가
                drink.enQueue(input("추가할 상품 : "))
            elif choice==2:
                #폐기물 빼기
                drink.deQueue()
            elif choice==3:
                break
    elif choice==3:
        print("냉동식품 냉장고")
        if not food.is_empty():
            print("================")
            food.show()
            print("================")
        else:
            print("상품없음")

        print("음료수 냉장고")
        if not drink.is_empty():
            print("================")
            drink.show()
            print("================")
        else:
            print("상품없음")
    elif choice==4:
        print("빠이")
        break
    else:
        print("다시 입력해주세요")














    
