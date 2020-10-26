#포화이진트리

class Node:
    def __init__(self, data):
        self.data=data


class BTree:
    def __init__(self):
        #실제 노드들이 저장될 리스트
        self.blist=[''] #0번 노드 비우기

    def insertNode(self, data):
        newNode=Node(data)
        self.blist.append(newNode)

    #출력 form을 트리모양으로 만들어줌
    def printNode(self):
        num = 1
        #인덱스가 2의 제곱수인 경우에 Enter 한번 해 주고 출력 시작
        for i in range(1, len(self.blist)):
            if i%(2**num)==0:
                print()
                num+=1
            print(self.blist[i].data, end=" ")
    #전 이진트리의 첫번째 노드의 번호는 2^n승이다.
    def deleteNode(self, data):
        #blist에 있는 모든 노들을 스캔
        for i in range(1, len(self.blist)):
            #같은 데이터를 갖고 있는 데이터가 있다면 그 노드가 삭제할 노드임.
            if self.blist[i].data==data:
                #삭제할 노드를 임시 저장
                node=self.blist[i]
                #노드가 남겨있으므로 데이터를 넘겨서 지울 수 없음
                #리스트에서 삭제
                self.blist.remove(self.blist[i]) 
                #임시 저장했던 그 노드 리턴
                return node #pop처럼 지운거 알려주기
        #for문에서 return을 못만났으면 삭제할 값이 없다는 뜻
        print('삭제할 값이 없습니다.')
        
    def searchParentNode(self,data): #본인 위치부터 찾아야 한다
        for i in range(1, len(self.blist)):
            if self.blist[i].data==data: #자기자신 찾기
                #그 인덱스가 1인 경우는 Root Node임
                if i==1:
                    print('Root Node') #첫번째는 루트노드이므로 부모가 없다.
                    return True #True는 Root node임을 알 수 있음
                else:
                    #자기 자신의 인덱스의 2로 나눈 몫이 부모노드의 인덱스임.
                    print('Parent Node: ',self.blist[i//2].data)
                    return self.blist[i//2]
                    #실제 웹페이지의 구조는 트리구조로 되어 있다.
                    #자식, 부모노드를 찾는 함수도 구현되어 있다.
        print('찾는 값이 없습니다.') #존재하지 않는 데이터
        return False #파이썬은 리턴타입이 뭐든 상관이 없는것이 장점.
        #False는 찾는 노드가 없는 것

    def searchChildNode(self, data):
        #childNode는 한 개 이상이므로 리스트 형태로 리턴!
        cl=[]
        #자신부터 찾는다.
        for i in range(1, len(self.blist)):
            if self.blist[i].data==data:
                if i*2<len(self.blist):
                    #말단노드에서 자식찾기를 피해야 한다.
                    print('Left Child Node: ', self.blist[i*2].data)
                    cl.append(self.blist[i*2])
                    #Right Node는 없을 수도 있다.
                    if i*2+1<len(self.blist): #길이와 같을때의 조건은 빼는게 맞다고.
                        print('Right Child Node: ', self.blist[i*2+1].data)
                        cl.append(self.blist[i*2+1])
                    else:
                        print('Right Child Node: not exist')
                    return cl #두 자식을 찾아 리스트로 반환
                else:
                    print('Leaf Node')
                    return True
        print('찾는 값이 없습니다.')
        return False
            
#중간에 확인 못함. 녹화파일 확인바람 10.25 11:10


t = BTree()
for i in range(1,17):
    t.insertNode(i)

t.printNode()

t.deleteNode(14) #14가 지워지고 16이 당겨지는걸 확인할 수 있다.
#포화이진트리여서 당겨지는 것이다.
t.printNode()