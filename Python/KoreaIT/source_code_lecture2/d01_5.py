#Student 클래스 학생번호, 학생

class Student:
    studName = ''
    studClass = 0
    studNum = 0
    studScore=[]

    def __init__(self, studName, studClass, studNum):
        self.studName = studName
        self.studClass = studClass
        self.studNum = studNum
        self.studScore=list()

        #self.studNum = Student.studNum
        #Student.studNum += 1

#학생들 객체가 담길 리스트
studList=[]
while True:
    print('1. 점수 기입하기\n2. 점수 조회하기\n3. 나가기')
    choice = int(input())
    if choice ==1:
        studName = input('이름 : ')
        studClass = int(input('반 : '))
        studNum = int(input('번호 : '))
        #입력받은걸로 객체 하나 생성
        #아래처럼 하면 원래의 stu 객체는 없어지나?
        stu = Student(studName, studClass, studNum)
        #전체 학생목록에 그 주소값 추가 
        studList.append(stu)
        print(studList)
        #kor, eng, mat = map(int, input())
        kor = input('국어 점수: ')
        eng = input('영어 점수: ')
        mat = input('수학 점수: ')
        #stu.studScore.append(kor).append(eng).append(mat) #한번에 안된다...ㅠ
        stu.studScore.append(kor)
        stu.studScore.append(eng)
        stu.studScore.append(mat)
        print(stu.studName + '기입 완료')

    elif choice==2:
        #반, 번호 입력받아서 찾기
        c = int(input('반: '))
        n = int(input('번호: '))
        for stu in studList:
            #print(stu.studClass, stu.studNum)
            if(stu.studClass==c):
                if(stu.studNum==n):
                    print('국어점수: ', stu.studScore[0])
                    print('영어점수: ', stu.studScore[1])
                    print('수학점수: ', stu.studScore[2])
    elif choice==3:
        print('안녕히가세요')
        break

#주피터로 따라가야하나?? 복습 필수겠네

