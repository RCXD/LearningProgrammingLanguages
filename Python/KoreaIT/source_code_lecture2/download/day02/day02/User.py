from 연결리스트 import *
class User:
    def __init__(self,userid,userpw,username):
        self.userid=userid
        self.userpw=userpw
        self.username=username

print('==============UMS==============')
userList=LinkedList()
while True:
    print('1. 회원가입\n2. 로그인\n3. 나가기')
    choice=int(input())
    if(choice==1):
        print("회원가입입니다")
        userid=input("아이디 : ")
        userpw=input("패스워드 : ")
        username=input("이름 : ")
        user=User(userid,userpw,username)
        userList.append(user)
    elif(choice==2):
        print("로그인입니다")
        userid=input("아이디 : ")
        userpw=input("패스워드 : ")
        for i in range(userList.count):
            if(userList.get(i).data.userid==userid):
                if(userList.get(i).data.userpw==userpw):
                    print(userid+"님 로그인 성공!")
                    
    elif(choice==3):
        print("안녕히 가세요")
        break
    else:
        print("잘못 입력했습니다.")



