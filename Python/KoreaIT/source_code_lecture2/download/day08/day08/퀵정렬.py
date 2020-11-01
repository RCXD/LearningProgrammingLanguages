def partition(ar,left,right):
    pivot=ar[right]     #제일 오른쪽 위치를 pivot
    i=left-1#           가장 왼쪽 요소의 -1
    for j in range(left,right):#처음부터 끝까지 반복
        if ar[j]<=pivot:    #j위치의 값이 작다면, i를 증가시킨 후 swap
            i+=1
            ar[i],ar[j]=ar[j],ar[i]
            print('SWAP :',ar)
    ar[i+1],ar[right]=ar[right],ar[i+1] #ar[right]
    return i+1

def QuickSort(ar,left,right):
    if left<right:
        q=partition(ar,left,right)
        QuickSort(ar,left,q-1)
        QuickSort(ar,q+1,right)
        


dataList = [6,2,7,9,4,1,8,5,3]
size=9
#size = int(input('값 개수 : '))

#for i in range(size):
#    dataList.append(int(input(str(i+1)+'번째 값 : ')))
    
print("정렬 전 :",dataList)
print('==================================')
QuickSort(dataList,0,size-1)


print("정렬 후 :",dataList)
