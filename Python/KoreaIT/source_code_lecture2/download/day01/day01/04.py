#Student 클래스 / 학생이름, 학생반, 학생번호, [국어,영어,수학점수]

#1. 점수 기입하기
#2. 점수 조회하기
#3. 나가기

class Student:
    stuName=''
    stuClass=0
    stuNum=0
    stuScore=[]

    def __init__(self,name,c,n):
        self.stuName=name
        self.stuClass=c
        self.stuNum=n
        self.stuScore=list()

#학생들 객체가 담길 리스트
stuList=[]
while True:
    print("1. 점수 기입하기\n2. 점수 조회하기\n3. 나가기")
    choice = int(input())
    if(choice==1):
        name=input("이름 : ")
        c=int(input("반 : "))
        n=int(input("번호 : "))
        #입력받은 값들로 Student객체 하나 생성하기
        stu=Student(name,c,n)
        #전체 학생 목록에 그 주소값 추가
        stuList.append(stu)
        kor = int(input("국어점수 : "))
        eng = int(input("영어점수 : "))
        mat = int(input("수학점수 : "))
        stu.stuScore.append(kor)
        stu.stuScore.append(eng)
        stu.stuScore.append(mat)
        print(stu.stuName+" 학생 점수 기입 완료")
    
    elif(choice==2):
        #반, 번호 입력받아서 찾기
        c=int(input("반 : "))
        n=int(input("번호 : "))
        #전체 학생 목록에서 객체 하나씩 가져오면서 for문 반복
        for stu in stuList:
            #그 객체의 반이 입력한 반과 같다면
            if(stu.stuClass==c):
                #그 객체의 번호 비교
                if(stu.stuNum==n):
                    #찾는 객체이므로 점수 출력
                    print("국어점수 :",stu.stuScore[0])
                    print("영어점수 :",stu.stuScore[1])
                    print("수학점수 :",stu.stuScore[2])
                    
    elif(choice==3):
        print("안녕히가세요")
        break










        
