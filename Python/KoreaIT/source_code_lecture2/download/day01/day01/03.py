#User클래스 회원번호, 회원 아이디, 회원 비밀번호, 회원 이름
#첫번째 가입(객체생성)한 사람부터 회원번호 1번
#그 이후 회원번호 하나씩 증가 / 외부변수 사용X

class User:
    userNum=1
    userId=''
    userPw=''
    userName=''

    def __init__(self,userId,userPw,userName):
        self.userNum=User.userNum
        User.userNum+=1
        self.userId=userId
        self.userPw=userPw
        self.userName=userName

    #return한 문자열이 객체명을 출력했을때 나온다(__str__)
    def __repr__(self):
        return str(self.userNum)+"번 회원 : "+self.userId+"/"+self.userName


user1=User('apple','1234','사과')
user2=User('melon','1234','메론')


print(user1)
print(user2)







