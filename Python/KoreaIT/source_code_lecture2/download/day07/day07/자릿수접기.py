#자릿수접기.py
M=7
dataList = ['' for i in range(M)]

#해시함수
def h(x):
    return x%M

def digitFolding(s):
    tot=0
    for ch in s:
        tot+=ord(ch)
    return tot

while True:
    s=input('저장할 문자열 : ')
    saveIdx = h(digitFolding(s))
    dataList[saveIdx]=s

    for i in range(M):
        print(i,":",dataList[i])

'''
'bye'
98+121+101 = 320
320%7==5
bye : 5

'hello'
104+101+108+108+111 = 532
532%7==0
hello : 0
'''
