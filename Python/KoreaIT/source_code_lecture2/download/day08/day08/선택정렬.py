dataList = []
size = int(input('값 개수 : '))

for i in range(size):
    dataList.append(int(input(str(i+1)+'번째 값 : ')))

print("정렬 전 :",dataList)
print('==================================')
for i in range(size-1):
    min = i
    for j in range(i+1,size):
        if dataList[min] >= dataList[j]:
            min=j
    dataList[i],dataList[min]=dataList[min],dataList[i]

print("정렬 후 :",dataList)
