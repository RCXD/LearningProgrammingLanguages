class Node:
    def __init__(self,data):
        self.data=data

class BTree:
    def __init__(self):
        #실제 노드들이 저장될 리스트
        self.blist=['']#0번 노드 비우기

    def insertNode(self,data):
        newNode=Node(data)
        self.blist.append(newNode)

    #출력 form을 트리 모양으로 만들어 준다
    def printNode(self):
        num=1

        #인덱스가 2의 제곱수인 경우에 enter 한번 해 주고 출력 시작
        for i in range(1,len(self.blist)):
            if i%(2**num) == 0:
                print()
                num+=1
            print(self.blist[i].data,end=" ")
        print()

    def deleteNode(self,data):
        #blist에 있는 모든 노드들을 훑으면서
        for i in range(1,len(self.blist)):
            #같은 데이터를 갖고 있는 노드가 있다면 그 노드가 삭제할 노드이다
            if self.blist[i].data==data:
                #삭제할 노드를 임시 저장한 후
                node=self.blist[i]
                #리스트에서는 삭제
                self.blist.remove(self.blist[i])
                #임시 저장했던 그 노드 return
                return node
        #for문에서 return을 못만났으므로, 삭제할 값이 없다는 뜻이다.
        print("삭제할 값이 없습니다.")

    def searchParentNode(self,data):
        for i in range(1,len(self.blist)):
            #자기 자신을 먼저 찾고
            if self.blist[i].data==data:
                #그 인덱스가 1인 경우에는 Root Node이기 때문에
                if i==1:
                    print("Root Node")
                    #사용하는 곳에서 True값이 리턴됐다면, Root Node임을 알 수 있다.
                    return True
                else:
                    #자기 자신의 인덱스의 2로 나눈 몫이 부모노드의 인덱스이다
                    print("Parent Node :",self.blist[i//2].data)
                    return self.blist[i//2]
        print("찾는값이 없습니다.")
        #False가 리턴됐다면, 찾는 노드가 없었다는 것을 알 수 있다.
        return False

    def searchChildNode(self,data):
        #childNode는 한개 이상이므로 리스트 형태로 리턴해준다.
        cl=[]
        for i in range(1,len(self.blist)):
            if self.blist[i].data==data:
                #주어진 노드의 인덱스*2가 길이보다 작을 때가 Leaf Node가 아닐 때이다(자식노드가 있다)
                if i*2<len(self.blist):
                    #left 부터 채워지기 때문에 왼쪽 자식노드를 cl에 추가해준다.
                    print("Left Child Node :",self.blist[i*2].data)
                    cl.append(self.blist[i*2])
                    #인덱스*2+1이 길이보다 작다는것은 오른쪽 자식노드도 있다는 뜻이므로
                    if i*2+1<len(self.blist):
                        #오른쪽 자식노드를 cl에 추가해준다.
                        print("Right Child Node :",self.blist[i*2+1].data)
                        cl.append(self.blist[i*2+1])
                    else:
                        #오른쪽 자식노드가 없다는 뜻
                        print("Right Child Node : X")
                    return cl
                #그 외에는 Leaf Node이므로 True를 리턴해준다.
                else:
                    print("Leaf Node")
                    return True
        print("찾는값이 없습니다.")
        return False

t = BTree()
for i in range(1,17):
    t.insertNode(i)
t.printNode()
t.deleteNode(11)
t.searchParentNode(5)
t.searchChildNode(6)








