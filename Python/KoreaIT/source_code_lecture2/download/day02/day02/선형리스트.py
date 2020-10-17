#데이터를 저장할 단순 저장공간
#n1 = []로 구현시 0번방, 1번방 n1[0],n1[1]
#n1 = Node() 구현시 n1.data, n1.idx
class Node:
    data=0
    idx=0

    def __init__(self,data):
        self.idx=Node.idx
        Node.idx+=1
        self.data=data

#기능이 구현되어 있는 선형리스트
#추가, 삭제, 수정, 조회 등
class LinearList:
    dataList=[]
    count=0
    def __init__(self):
        self.dataList=[]
        self.count=0

    #추가(맨 뒤에 추가하기 때문에 data만 알려주면 된다)
    def append(self,data):
        #노드로 가공한다고 생각하기
        newNode=Node(data)
        print("append :",data)
        self.dataList.append(newNode)
        self.count+=1

    #삽입(어디에 추가할지와, data 두개의 값이 필요하다)
    def insert(self,idx,data):
        newNode=Node(data)
        print('insert :',data)
        newNode.idx=idx
        for i in range(idx,self.count):
            self.dataList[i].idx+=1
        self.dataList.insert(idx,newNode)
        self.count+=1

    #삭제
    def delete(self,idx):
        print('delete :',idx)
        for i in range(idx,self.count):
            self.dataList[i].idx-=1
        del self.dataList[idx]
        self.count-=1
        Node.idx-=1

    #수정
    def update(self,idx,data):
        self.dataList[idx].data=data

    #조회
    def get(self,idx):
        print('get')
        print(self.dataList[idx].idx,":",self.dataList[idx].data)
    #목록
    def show(self):
        print('show')
        for i in range(self.count):
            print('%d : %s'%(self.dataList[i].idx,self.dataList[i].data))


li=LinearList()
li.append('A')
li.append('B')
li.show()



        
