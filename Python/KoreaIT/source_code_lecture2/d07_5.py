#제곱탐색법
#충돌시 제곱만큼 건너뛴 주소에 데이터를 삽입
#예) 100주소에 삽입시 데이터가 있으면 101로 이동해서 삽입
#101에도 있으면 104에
#104에도 있으면 109로 이동

M=7
#move = 1
dataList = ['' for i in range(M)]
#'''
#def Move():
#    temp = move #왜 무브가 없다는거?
#    move = move+1
#    return temp**2
#'''

def h(x):
    return x%M

def digitFolding(s):
    tot=0
    for ch in s:
        tot+= ord(ch)
    return tot
move = 1
cnt = 0
def insertData(s):
    global move #전역변수 생성하기..
    global cnt
    #이거 안하면 함수내에 move가 생성된다고 함. 그래도 상관없다나???
    #파이썬 변수개념 이해좀. 전역, 지역변수
    idx = h(digitFolding(s))
    temp=idx ##
    while True:
        print("INSERT: ", idx,"-",s)
        if(cnt==10):
            print("INSERT FAILED")
            cnt==0
            break
        if dataList[temp]=='':
            dataList[temp]=s
            move = 1 #성공했을대도 초기화해야 함.
            cnt = 0
            break
        else: #이미 무언가 데이터가 있을 때
            cnt+=1#무한반복 check
            temp=(temp+move**2)%M #move만큼 이동한다. 범위 벗어나지 않게 나머지로 컷
            move+=1
            #왜 move가 없다는거?
def printData():
    for i in range(M):
        print(i, ":", dataList[i])

def searchData(s):
    global move
    global cnt
    idx = h(digitFolding(s))
    temp = idx
    while True: #이동된것일 수도 있음.
        if(cnt==10):
            print("No DATA")
            cnt==0
            break
        if s==dataList[temp]:
            print("SEARCH IDX: ", temp)
            move = 1
            cnt = 0
            break
        else: 
            cnt+=1#무한반복 check
            temp=(temp+move**2)%M #이동된걸 찾을때까지 이동
            move+=1

def findData(s):
    global move
    global cnt
    idx = h(digitFoilding(s))
    #.... adal;skdjlkas
    #수업코드보고 복구좀...

#왜 똑바로 안되는거지?... 수정/보완, 원인분석좀
#move문제...? -> 전역, 지역변수 또는 파이썬 버전 문제인듯? 3.8.6버전과 비교바람
#공간이 비어있는데도 우연히 무한반복될 수 있다.
#무한반복 방지코드도 제대로 안되는데?
#cnt는 왜 지역변수인상태에서 제대로 안돌지?

insertData('apple')
insertData('banna')
insertData('cherry')
insertData('durian')
insertData('test')
insertData('hello')
printData()
searchData('hello')


