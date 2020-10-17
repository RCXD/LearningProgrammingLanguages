#User 클래스 / 회원번호, 회원아이디, 회원비밀번호, 회원이름
#Product 클래스 / 상품번호, 상품이름, 상품가격, 상품재고
class User:
    userNum=1
    userId=''
    userPw=''
    userName=''

    def __init__(self,userId,userPw,userName):
        self.userNum=User.userNum
        self.userId=userId
        self.userPw=userPw
        self.userName=userName
        User.userNum+=1

class Product:
    prodNum=1
    prodName=''
    prodPrice=0
    prodCnt=0

    def __init__(self,prodName,prodPrice,prodCnt):
        self.prodNum=Product.prodNum
        self.prodName=prodName
        self.prodPrice=prodPrice
        self.prodCnt=prodCnt
        Product.prodNum+=1

#로그인 성공시 호출할 함수
#매개값 : 로그인 성공한 그 객체의 주소값
def loginMenu(user):
    prodList=userList[user]
    while True:
        choice=int(input("1. 상품 올리기\n2. 상품 수정하기\n3. 상품 삭제하기\n4. 내 상품보기\n5. 로그아웃\n"))
        if(choice==1):
            prodName=input("상품 이름 : ")
            prodPrice=int(input("상품 가격 : "))
            prodCnt=int(input("상품 재고 : "))
            product = Product(prodName,prodPrice,prodCnt)
            #딕셔너리이름[키값] >> 키에 연결된 value
            #user에는 로그인 성공한 그 회원의 주소가 담겨있기 때문에
            #userList[user] 그회원의 상품 리스트([])를 가져오게 된다
            #추가한 상품을 그 리스트에 append
            userList[user].append(product)
            print(product.prodName+" 상품 추가")
            
        elif(choice==2):
            #수정하기
            #for 변수 in range(초기값,끝값,증감량)
            #range(초기값,끝값) --> 증감량 1
            #range(끝값) --> 초기값=0, 증감량=1
            for i in range(len(prodList)):
                print(i+1,"번 ",prodList[i].prodName+" : "+str(prodList[i].prodPrice)+"원 / "+str(prodList[i].prodCnt)+"개")
            pChoice=int(input("번호 선택 : "))
            prodList[pChoice-1].prodPrice=int(input("새로운 가격 : "))
            
        elif(choice==3):
            #삭제하기
            for i in range(len(prodList)):
                print(i+1,"번 ",prodList[i].prodName+" : "+str(prodList[i].prodPrice)+"원 / "+str(prodList[i].prodCnt)+"개")
            pChoice=int(input("번호 선택 : "))
            del prodList[pChoice-1]
            
        elif(choice==4):
            #           여전히 로그인 성공한 그 객체와 연결된 리스트[]
            for prod in userList[user]:
                print(prod.prodName+" : "+str(prod.prodPrice)+"원 / "+str(prod.prodCnt)+"개")
        elif(choice==5):
            #회원탈퇴
            pass
        
        elif(choice==6):
            print("로그아웃")
            break

#외부변수 전체회원 딕셔너리 {회원:올린상품리스트}
#1. 회원가입하기
#2. 로그인하기
#3. 나가기
userList=dict()
while True:
    choice=int(input("1. 회원가입\n2. 로그인\n3. 회원탈퇴\n4. 나가기\n"))
    if(choice==1):
        #회원가입
        print("회원가입 입니다.")
        userId=input("아이디 : ")
        userPw=input("비밀번호 : ")
        userName=input("이름 : ")
        user=User(userId,userPw,userName)
        #딕셔너리는 기존 키값이 아닌곳에 접근하면 원소가 새로 만들어진다
        #새로 생성한 user 객체의 주소값을 key값으로, 빈 리스트를 value로 연결하며 원소 생성
        userList[user]=list()
        print(user.userName+"님 회원가입 완료!")
    elif(choice==2):
        #로그인
        print("로그인 입니다.")
        userId=input("아이디 : ")
        userPw=input("비밀번호 : ")
        #user는 딕셔너리의 key를 하나씩 가져오며 for문 반복
        for user in userList:
            #아이디와 비밀번호 비교
            if(user.userId==userId and user.userPw==userPw):
                print(user.userName+"님 로그인 성공!")
                #함수호출/ 넘겨주는 값은 로그인 성공한 그 user 주소값
                loginMenu(user)
    elif(choice==3):
        print("안녕히가세요")
        break

#회원가입 메뉴
#아이디 :
#비밀번호 :
#이름 :

#로그인 성공시 메뉴
#1. 상품 올리기
#2. 상품 수정하기
#3. 상품 삭제하기
#4. 내 상품 보기
#5. 회원탈퇴
#6. 로그아웃




        
