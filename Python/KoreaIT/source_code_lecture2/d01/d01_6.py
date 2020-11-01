'''
문제: 
User 클래스 / 회원번호, 회원아이디, 비밀번호, 이름
Product 클래스 / 상품번호, 상품이름, 상품가격, 상품재고
 -> 상품리스트에 클래스를 올림
외부변수 : 전체회원 딕셔너리{회원:올린 상품 리스트}
1. 회원가입하기
2. 로그인하기
3. 나가기

회원가입 메뉴
1. 아이디 : 
2. 비밀번호 :
3. 이름 :

로그인 성공시 메뉴
1. 상품 올리기
2. 상품 수정하기
3. 상품 삭제하기
4. 내 상품 보기
5. 회원 탈퇴
6. 로그아웃
'''

class User:
    userNum = 0
    userId = ''
    userPw = ''
    userName = ''

    def __init__(self, userId, userPw, userName):
        self.userNum = User.userNum
        self.userId=userId
        self.userPw = userPw
        self.userName= userName
        User.userNum+=1

class Product:
    prodNum = 1
    prodName = ''
    prodPrice = 0
    prodCnt = 0

    def __init__(self, prodName, prodPrice, prodCnt):
        self.prodNum=Product.prodNum
        self.prodName = prodName
        self.prodPrice = prodPrice
        self.prodCnt = prodCnt
        Product.prodNum += 1

#로그인 성공시 호출할 함수
#매개값 : 로그인 성공한 그 객체의 주소값
def loginMenu(user):
    prodList = userData[user] #밸류값은 리스트인가?
    #리스트값으로 넣었던가? 확인바람...
    while 1:
        choice = int(input('1. 상품 올리기\n2. 상품 수정하기\n3. 상품 삭제하기\n4. 내 상품 보기\n5. 회원탈퇴\n6. 로그아웃\n'))
        if choice==1:
            prodName= input('상품이름: ')
            prodPrice= int(input('상품가격: '))
            prodCnt= int(input('상품 재고: '))
            product= Product(prodName, prodPrice, prodCnt)
            #딕셔너리이름[키값] -> 키에 연결된 value
            #user에는 로그인 성공한 그 회원의 주소가 담겨있기 때문에
            #userData[user]: 그 회원(user)의 상품 리스트([])를 가져오게 됨.
            #추가한 상품을 리스트에 append
            userData[user].append(product)
            print(product.prodName+" 상품 추가")

        elif choice==2:
            #수정하기 : 인덱싱...!
            for i in range(len(prodList)):
                print(i+1, '번 ', prodList[i].prodName+' : '+str(prodList[i].prodPrice)+'원 / '+str(prodList[i].prodCnt))
            pChoice=int(input('번호 선택: ')) #??
            prodList[pChoice-1].prodPrice=int(input('새로운 가격: '))

        elif choice==3:
            #삭제하기 : del을 쓰면 되려나? 또 지우는방법이 있던데
            #dict.remove(value)...는 번거로울수 있다고. value를 넘겨줘야하기 때문
            #del은 너무 강력해서 잘 안쓴다고??
            #remove는 너무 복잡하다고.
            for i in range(len(prodList)):
                #range(초기값=0, 끝값, 증감량=1) or (초기값, 끝값) or (끝값)
                print(i+1, '번 ', prodList[i].prodName+' : '+str(prodList[i].prodPrice)+'원 / '+str(prodList[i].prodCnt))
            pChoice=int(input('번호 선택: '))
            del prodList[pChoice-1]
            pass
        elif choice==4:
            #내 상품  보기
            for prod in userData[user]:
                print(prod.prodName+' : '+str(prod.prodPrice)+'원 / '+str(prod.prodCnt)+'개')
        elif choice ==3:
            #회원 탈퇴... 쌍으로 삭제를 해야? 그냥 삭제하면 오류가 날 것이다?
            #숙제! 코드 올리기. 웹하드 폴더에...(어디?)
            pass
        elif choice==5:
            print('로그아웃')
            break


userData = dict()
while 1:
    choice = int(input('1. 회원가입하기\n2. 로그인\n3. 나가기\n'))
    if choice ==1:
        #회원가입
        print('회원가입 입니다.')
        userId = input('아이디:')
        userPw = input('비밀번호: ')
        userName = input('이름: ')
        user=User(userId, userPw, userName)
        #딕셔너리는 기존 키값이 아닌 곳에 접근하면 원소가 새로 만들어짐!
        #새로 생성한 user 객체의 주소값을 key값으로, 빈 리스트를 value로 연결하며 원소 생성
        #객체를 같은 이름으로 만들어도 원래 필드는 제거되지 않음
        #단, 그 필드를 가리키던 객체명은 어디에 저장하지 않으면 훼손되는 개념일지도?
        userData[user] = list()
        #user라는 키값에 빈 리스트 생성
        #객체 자체를 키로 사용하게 된다고 함.
        print(user.userName+'님 회원가입 완료!')
        print(userData)
        pass
    elif choice ==2:
        #로그인
        print('로그인 입니다.')
        userId = input('아이디:')
        userPw = input('비밀번호: ')
        #user는 딕셔너리의 key를 하나씩 가져오며 for문 반복
        for user in userData:
            #아이디와 비밀번호 비교
            if(user.userId == userId and user.userPw==userPw):
                print(user.userName+'님 로그인 성공')
                #함수 호출/넘겨주는 값은 로그인 성공한 그 user의 주소값.
                #로그인 성공시 화면 구성 필요. 복잡하니까 함수로.
                loginMenu(user) #밑에다 정의하니까 정의되지 않았다나??
        pass

    elif choice ==3:
        print('안녕히 가세요')
        break

#숙제 : 회원탈퇴! 딕셔너리에서 값 지우기...