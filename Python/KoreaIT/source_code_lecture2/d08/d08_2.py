#삽입 정렬
#5 1 2 4 3 -> 1 5 2 4 3 -> 1 2 5 4 3 -> 1 2 4 3 5 

#데이터 입력 및 준비 기본 Form
dataList = []
size = int(input('값 개수: '))

for i in range(size):
    dataList.append(int(input(str(i+1)+'번재 값: '))) #input 안에는 문자열 하나만 보내야함!! ,를 쓰지 말것. 잦은 실수

print("정렬 전:", dataList)
print('=======================================')
'''
for i in range(1, size):
    tmp=i
    j = i-1 #j는 하나 작은 인덱스부터 시작
    while j>=0:
        if dataList[tmp] < dataList[j]:
            dataList[tmp],dataList[j] = dataList[j],dataList[tmp]
            print("sort", dataList)
            tmp=j
        else:
            j-=1
'''

#도전과제 : j 없이 변수 하나로 구현하기... 가능할 것인가?
for i in range(1, size):
    tmp=dataList[i]
    idx = -1 #j는 하나 작은 인덱스부터 시작
    for j in range(i-1, -1, -1):
        if tmp < dataList[j]:
            dataList[j+1] = dataList[j]
        else:
            idx = j
            break
    dataList[idx+1]=tmp

#출력
print("정렬 후:", dataList)

#어짜피 for문 변수를 쓰든 while을 쓰든 그게 그거 아닌가?
'''
8 1 2 5 6 7 4 3
1 2 4 5 6 7 8 3 
#뒤에서부터 스캔해서 임시저장한거보다 크다면 하나씩 덮어씌우고, 조건 탈출하면(else) 대체해버림(dataList[idx+1]=tmp)
'''