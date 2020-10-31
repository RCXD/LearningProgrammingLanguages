#자리수 접기

M=7
dataList=['' for i in range(M)] #comprehension

# "Hello" > ASCII code로 바꿔 각 값 합함
# (72+101+108+108+111)%M -> 주소값으로 활용

#해시 함수
def h(x):
    return x%M

def digitFolding(s):
    tot=0
    for ch in s:
        tot+=ord(ch) #문자를 ASCII로 바꿔줌
    return tot

while True:
    s=input('저장할 문자열: ')
    saveIdx = h(digitFolding(s))
    dataList[saveIdx]=s

    for i in range(M):
        print(i, ":",dataList[i])
        