#이진탐색트리: 이진탐색 알고리즘에 트리구조를 접목한 구조.
#입력할때는 마찬가지로 넣으나, 탐색방법이 다르게.

class Node:
    def __init__(self, data):
        self.data=data
        self.left=None
        self.right=None

class BST:
    def __init__(self):
        self.level=1
        self.root=None
        self.count=1 #insert할때 비교할기 편해지는 듯? 좀더 고민... 분석...
        self.queue=[Node('none')] #queue에 비어있는 None 하나 추가
        #queue는 리스트로, 트리가 커질때마다...

    def insertNode(self, data):
        newNode=Node(data)
        if self.count==1:
            self.root = newNode
        else:
            if self.count==2**self.level:
                self.level+=1
            #루트의 좌/우 비교하는건 없어도 되는 부분이라고 함. 없애고 수정해볼 필요도 있겠음.
            if self.root.left is None: #루트의 왼쪽 자식이 비어있다면
                self.root.left=newNode
            elif self.root.right is None: #루트의 오른쪽 자식이 비어있다면
                self.root.right=newNode
            else: #루트추가 끝냄
                #2로 나누면 타겟의 부모(가 될 노드)를 찾을 수 있음.
                if self.queue[self.count//2].left is None: #타겟 부모의 좌측이 비어있다면
                    self.queue[self.count//2].left=newNode
                elif self.queue[self.count//2].right is None: #타겟 부모의 우측이 비어있다면
                    self.queue[self.count//2].right=newNode
        self.count+=1
        self.queue.append(newNode)

    #def findNode(self, Node): #Notice: get같은 함수는 미리 만들어놓는게 나중이 편하다
    
    #정렬하면서 추가하기.. 비교하면서.
    def cinsertNode(self, data, node):  #재귀함수... 인자에 self는 무시해야한다는걸
        #                                주의하자... 보는눈이 바뀌어야하거나 연습이 많이 필요함.
        if node is None: #첫 추가시
            node = Node(data)
            self.queue.append(node)
            self.count+=1
            if self.root is None:
                self.root=node
        else:
            if node.data>data: #비교! node.data는 원래 있던...
                node.left=self.cinsertNode(data, node.left) #재귀호출
                #처음에, 재귀호출한 함수의 node.left가 비어있으면 None이 넘어감.
                #비어있으면 그 자리에 저장하게 됨.
            else:
                node.right=self.cinsertNode(data, node.right)
        return node
    #이번엔 delete를 만들지 않는다고 함. 만들어보기!!
    #재귀 예제?? 잘 이해가 안가고... node=None으로 초기화인게 어떤 의미인지도..
    #재귀적인 생각은 어떻게 할 수 있을까?
    #많은 재귀 예제를 풀어봐야하겠는데

    def order(self, node): #순서대로 출력하기
        if node is not None:
            self.order(node.left)
            self.order(node.right)
            print(node.data, end=' ')

bst=BST()
for data in [21, 7, 38, 61, 15, 17, 42, 81, 100, 1]:
    bst.cinsertNode(data, bst.root) #굳이 루트를 넘기지 않고도 할 수 있는 방법이 있을건데.

bst.order(bst.root)


#문제의 조건을 다시 정리하고, 논리를 정리해서, 구현해보는 부분을 다시 곱씹어보자.

#다음주 일정: 이진탐색 알고리즘 3가지 구현

#파일도 싹 정리해봐야함.