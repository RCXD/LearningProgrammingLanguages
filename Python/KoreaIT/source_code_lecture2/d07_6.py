#이중 해싱
M=7
c=13 #서로소를 쓰는것이 통계적으로 클러스터확률이 낮아짐
j=1 #약수
dataList=['' for i in range(M)]

def h(x):
    return x%M
def d(x):
    return x%c+1

#idx h(x)*d(x)%M+j

def digitFolding(s):
    tot=0
    for ch in s:
        tot+=ord(ch)
    return tot

def insertData(s):
    global j
    idx=h(digitFolding(s))
    while True:
        if dataList[idx%M]=='': #복잡하니까 여기서 %M해준다나?
            dataList[idx%M]=s
            print("INSERT: ",idx%M, "-",s)
            j=1
            break
        else:
            idx = h(digitFolding(s))*d(digitFolding(s))%M+j
            j+=1 #j마저도 하나씩 증가시킴

def printData():
    for i in range(M):
        print(i,":",dataList[i])


insertData('apple')
insertData('banna')
insertData('cherry')
insertData('durian')
insertData('test')
insertData('hello')
printData()
insertData('hello')
printData()
#선형탐색, 제곱탐색법보다 성능이 좋았다는걸 알 수 있음