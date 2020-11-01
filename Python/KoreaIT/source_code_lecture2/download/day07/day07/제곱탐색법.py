#충돌시 제곱만큼 건너뛴 주소에 데이터를 삽입
#ex) 100주소에 삽입시 데이터가 있으면 > 101로 이동해서 삽입
#   101에도 있으면 > 104로 이동해서 삽입
#   104에도 있으면 > 109로 이동해서 삽입

M=7
move = 1
dataList = ['' for i in range(M)]
cnt=0
def h(x):
    return x%M

def digitFolding(s):
    tot = 0
    for ch in s:
        tot+=ord(ch)
    return tot

def insertData(s):
    #move=1
    global move
    global cnt
    idx = h(digitFolding(s))
    temp=idx
    while True:
        if(cnt==10):
            print("INSERT FAILED")
            cnt=0
            break
        print("INSERT :",temp,"-",s)
        if dataList[temp]=='':
            dataList[temp]=s
            move=1
            cnt=0
            break
        else:
            cnt+=1
            temp=(idx+move**2)%M
            move+=1

def findData(s):
    global move
    global cnt
    idx = h(digitFolding(s))
    temp=idx
    while True:
        if(cnt==10):
            print("NO DATA")
            cnt=0
            break
        print("INSERT :",temp,"-",s)
        if dataList[temp]==s:
            print("SEARCH IDX :",temp)
            move=1
            cnt=0
            break
        else:
            cnt+=1
            temp=(idx+move**2)%M
            move+=1


def printData():
    for i in range(M):
        print(i,":",dataList[i])

insertData("banana")
insertData("test")
insertData("cherry")
insertData("durian")
insertData("hello")
printData()
insertData("hello")
