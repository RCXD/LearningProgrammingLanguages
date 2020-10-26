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

    def order(self,node):
        if node is not None:
            self.order(node.left)
            self.order(node.right)
            print(node.data,end=' ')

bst=BST()
for data in [21,7,38,61,15,17,42,81,100,1]:
    bst.cinsertNode(data,bst.root)

bst.order(bst.root)





