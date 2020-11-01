dataList = []
size = int(input('값 개수 : '))

for i in range(size):
    dataList.append(int(input(str(i+1)+'번째 값 : ')))
    
print("정렬 전 :",dataList)
print('==================================')

for i in range(1,size):
    tmp=dataList[i]
    idx=-1
    for j in range(i-1,-1,-1):
        if tmp<dataList[j]:
            dataList[j+1]=dataList[j]
        else:
            idx=j
            break
    dataList[idx+1]=tmp
    

print("정렬 후 :",dataList)
