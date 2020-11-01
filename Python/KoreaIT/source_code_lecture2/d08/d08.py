#선택 정렬

dataList = []
size = int(input('값 개수: '))

for i in range(size):
    dataList.append(int(input(str(i+1)+'번재 값: '))) #input 안에는 문자열 하나만 보내야함!! ,를 쓰지 말것. 잦은 실수

print("정렬 전:", dataList)
print('=======================================')
for i in range(size-1):
    min=i #실수 주의
    for j in range(i+1, size):
        if dataList[min] >= dataList[j]:   #min자리보다 더 작은게 있다면
            min = j #최소값을 j로 바꿈
    dataList[i], dataList[min] = dataList[min], dataList[i] #tuple로 실제 값 자리바꾸기

print("정렬 후:", dataList)

#가장 빠르고, 쉽다.