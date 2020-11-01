M=7

#comprehension
#dataList=['' for i in range(M)]
dataList= []
for i in range(M):
    dataList.append('')

#해시 함수
def h(data):
    return data%M

def search(data):
    return dataList[h(data)]

for i in range(3):
    saveData=int(input("저장할 값 : "))
    dataList[h(saveData)]=saveData

for i in range(M):
    print(i,':',dataList[i])

findData = int(input("찾을 값 : "))
#기존방식
'''
for i in range(M):
    if dataList[i]==findData:
        print(findData,"는",i,"번째에 있습니다.")
        break
'''
print(findData,"는",h(findData),"번째에 있습니다.")
    
