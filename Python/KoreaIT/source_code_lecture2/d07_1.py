# 이진탐색트리는 순서가 아닌 기준에 따라 저장하는 개념
class Node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None

class BST:
    def __init__(self):
        self.level=1
        self.root=None
        self.count=1
        self.queue=[Node('none')]

    def insertNode(self,data):
        newNode=Node(data)
        if self.count==1:
            self.root=newNode
        else:
            if self.count==2**self.level:
                self.level+=1
            if self.root.left is None:
                self.root.left=newNode
            elif self.root.right is None:
                self.root.right=newNode
            else:
                if self.queue[self.count//2].left is None:
                    self.queue[self.count//2].left=newNode
                elif self.queue[self.count//2].right is None:
                    self.queue[self.count//2].right=newNode
        self.count+=1
        self.queue.append(newNode)
    
    def cinsertNode(self,data,node):
        if node is None: #첫 추가일때 진입
            node=Node(data)
            self.queue.append(node)
            self.count+=1
            if self.root is None: #루트가 비어있는지 확인
                self.root=node
        else:
            if node.data>data:
                node.left=self.cinsertNode(data,node.left)
            else:
                node.right=self.cinsertNode(data,node.right)
        return node #첫추가때는 리턴받아 쓰지는 않음

    #이건 뭐에 속하나? print위치가 조금 다른데?
    #def order(self,node):
    #    if node is not None:
    #        self.order(node.left)
    #        self.order(node.right)
    #        print(node.data,end=' ')
    
    ###전위순회 방식 구현
    def preOrder(self,node):
        if node is not None: #첫노드. 시작노드!
            #들어온 노드의 데이터 출력
            print(node.data, end=' ')#시작노드가 None이 아니면 출력
            #왼쪽 노드를 넘겨준 채 다시 호출
            self.preOrder(node.left) #재귀호하면 타겟노드 출력(None이 아니면)
            #오른쪽 노드를 넘겨주며 다시 호출
            self.preOrder(node.right) #left가 없으면 자동적으로 right가 출력될듯.
    
    #중위순회방식 구현
    def inOrder(self,node):
        if node is not None:
            #들어온 노드의 왼쪽 노드를 넘겨주며 호출
            self.inOrder(node.left) #left 호출
            #들어온 노드의 데이터 출력 #왼쪽이 없어야 출력 가능함.
            #left호출이 끝나고 돌아오면, 서브트리의 루트가 출력됨.
            print(node.data, end=' ')
            #그리고 왼쪽이 없다면(출력없이 리턴됨) 오른쪽이 출력 가능.
            self.inOrder(node.right) #right 호출
    
    #후위순회방식 구현
    #잎을 가장 먼저 출력!
    def postOrder(self,node):
        if node is not None:
            self.postOrder(node.left)
            self.postOrder(node.right)
            print(node.data, end=' ')

    #탐색 구현 
    def searchNode(self,data,node):
        if node is None:
            return None
        if node.data==data:
            return node #노드 자체를 리턴! 이후 액세스 가능
        elif node.data>data: 
            return self.searchNode(data, node.left)
        else: #왼쪽 뒤져서 없으면 우측으로.
            return self.searchNode(data, node.right)

bst=BST()
for data in [21,7,38,61,15,17,42,81,100,1]:
    bst.cinsertNode(data,bst.root)
#bst.order(bst.root)
bst.preOrder(bst.root); print()
bst.inOrder(bst.root);print()
bst.postOrder(bst.root);print()


findNode = bst.searchNode(61, bst.root)
print(findNode.data)
