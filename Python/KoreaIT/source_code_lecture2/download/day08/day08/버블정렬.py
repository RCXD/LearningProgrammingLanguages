dataList = []
size = int(input('값 개수 : '))

for i in range(size):
    dataList.append(int(input(str(i+1)+'번째 값 : ')))
    
print("정렬 전 :",dataList)
print('==================================')

for i in range(size):
    for j in range(size-1):
        if dataList[j]>dataList[j+1]:
            dataList[j],dataList[j+1]=dataList[j+1],dataList[j]




print("정렬 후 :",dataList)
