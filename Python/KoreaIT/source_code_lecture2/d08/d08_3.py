#버블정렬

dataList = []
size = int(input('값 개수: '))

for i in range(size):
    dataList.append(int(input(str(i+1)+'번재 값: '))) #input 안에는 문자열 하나만 보내야함!! ,를 쓰지 말것. 잦은 실수

print("정렬 전:", dataList)
print('=======================================')

for i in range(size):
    for j in range(size-1):
        if dataList[j]>dataList[j+1]:
            dataList[j], dataList[j+1] = dataList[j+1], dataList[j]

#출력
print("정렬 후:", dataList)

#매우 단순? 동작원리는? 한번 작성해보자