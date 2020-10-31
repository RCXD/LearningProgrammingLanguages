#선형탐색법

M=7
move = 2 #move는 반드시 M의 약수가 아니어야 한다고 함.
#고정폭으로 이동
#1은 상관 없을 듯?
dataList = ['' for i in range(M)]

def h(x):
    return x%M

def digitFolding(s):
    tot=0
    for ch in s:
        tot+= ord(ch)
    return tot

def insertData(s):
    idx = h(digitFolding(s))
    while True:
        print("INSERT: ", idx,"-",s)
        if dataList[idx]=='':
            dataList[idx]=s
            break
        else: #이미 무언가 데이터가 있을 때
            idx=(idx+move)%M #move만큼 이동한다. 범위 벗어나지 않게 나머지로 컷

def printData():
    for i in range(M):
        print(i, ":", dataList[i])

def searchData(s):
    idx = h(digitFolding(s))
    while True: #이동된것일 수도 있음.
        if s==dataList[idx]:
            print("SEARCH IDX: ", idx)
            break
        else: 
            idx = (idx+move)%M #이동된걸 찾을때까지 이동

#이 알고리즘도 결국 오류가 있다. 왠지, 무한루프에 빠지는것이 예상된다.
#왜 난 수업코드랑 결과가 다르지? 확인바람... 비교해봐야함!


insertData('apple')
insertData('banna')
insertData('cherry')
insertData('durian')
insertData('test')
insertData('hello')
printData()
searchData('hello')