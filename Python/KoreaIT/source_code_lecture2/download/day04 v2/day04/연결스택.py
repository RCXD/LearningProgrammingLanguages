class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class LinkedStack:
    def __init__(self):
        self.head=Node('head')
        self.top=None
    def push(self,data):
        newNode=Node(data)
        curr=self.head
        while (curr.next is not None):
            curr=curr.next
        curr.next=newNode
        self.top=newNode
    def pop(self):
        if not self.is_empty():
            curr=self.head
            while (curr.next.next is not None):
                curr=curr.next
            print(curr.next.data,end='')
            curr.next=None
            self.top=curr
        else:
            print("stack is empty!")
            
    def is_empty(self):
        return self.head.next==None

    def selectAll(self):
        curr = self.head
        while (curr.next is not None):
            print(curr.data,end='⇨')
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

