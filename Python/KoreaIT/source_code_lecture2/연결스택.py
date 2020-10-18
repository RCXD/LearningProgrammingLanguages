class Node:
    def __init__(self, data):
        self.data=data
        self.next=None

#up-down으로 구성하면 더 쉬웠을지도.
#RAM의 스택영역은 실제로 스택구조로 만들어져있다고 함. 넘치면 stack overflow 에러 발생

class LinkedStack:
    def __init__(self):
        self.head = Node('head')
        #self.head = None #이렇게도 어떻게 가능하다고 함.

    def push(self, data):
        newNode=Node(data)
        curr = self.head

        #푸시할 위치를 찾는다. 맨 끝을 찾으면 됨.
        while curr.next is not None: #for문을 쓰기에는 크기를 모른다. count값이 없기 때문에 맨 끝이 어딘지 모름.
            curr=curr.next
        curr.next = newNode
        self.top = newNode #
            
    def pop(self):
        if not self.is_empty():
            curr = self.head
            while curr.next.next is not None: #원하는 위치의 조건
                curr=curr.next #원하는 위치까지 옮기기
            curr.next=None
            self.top=curr 
        else:
            print('stack is empty')
    def is_empty(self):
        return self.head.next == None

    def selectAll(self):
        curr = self.head
        while curr.next is not None:
            print(curr.data, end='⇒ ') #두칸짜리 문자인듯
            curr=curr.next
        print(curr.data)


'''
ls = LinkedStack()

ls.push('A')
ls.push('B')
ls.push('C')
ls.push('D')
ls.selectAll()
'''