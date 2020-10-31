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
        if node is None:
            node=Node(data)
            self.queue.append(node)
            self.count+=1
            if self.root is None:
                self.root=node
        else:
            if node.data>data:
                node.left=self.cinsertNode(data,node.left)
            else:
                node.right=self.cinsertNode(data,node.right)
        return node

    def searchNode(self,data,node):
        if node is None:
            return None
        if node.data==data:
            return node
        elif node.data>data:
            return self.searchNode(data,node.left)
        else:
            return self.searchNode(data,node.right)

    def preOrder(self,node):
        if node is not None:
            #들어온 노드의 데이터 출력
            print(node.data,end=' ')
            #왼쪽 노드를 넘겨준 채 다시 호출
            self.preOrder(node.left)
            #오른쪽 노드를 넘겨주며 다시 호출
            self.preOrder(node.right)
        

    def inOrder(self,node):
        if node is not None:
            #들어온 노드의 왼쪽 노드를 넘겨주며 호출
            self.inOrder(node.left)
            #들어온 노드의 데이터 출력
            print(node.data,end=' ')
            #들어온 노드의 오른쪽 노드를 넘겨주며 호출
            self.inOrder(node.right)

    def postOrder(self,node):
        if node is not None:
            self.postOrder(node.left)
            self.postOrder(node.right)
            print(node.data,end=" ")
            

bst=BST()
for data in [21,7,38,61,15,17,42,81,100,1]:
    bst.cinsertNode(data,bst.root)

bst.preOrder(bst.root)
print()
bst.inOrder(bst.root)
print()
bst.postOrder(bst.root)
print()
findNode = bst.searchNode(61,bst.root)
print(findNode.data)




