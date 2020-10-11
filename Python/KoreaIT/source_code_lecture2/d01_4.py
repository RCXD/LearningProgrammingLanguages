#User 클래스- 회원번호, 회원아이디, 회원 비밀번호, 회원 이름
#첫번째 가입(객체생성)한 사람부터 회원번호 1번
#그 이후 회원번호 하나씩 증가

class User:
    id = ''
    pw = ''
    name = ''
    num = 1

    def __init__(self, id, pw, name):
        print('생성되었습니다.')
        self.num = User.num
        User.num += 1
        #원 클래스의 필드의 데이터도 가져올 수 있다...
        self.id = id
        self.pw = pw
        self.name = name
    
    #객체를 출력하면 그 객체에 대한 설명(주소값 포함)이 출력됨.
    #__repr__을 이용하면 설명내용을 바꿀 수 있다고 함.
    #__str__과 거의 기능이 같다. 컴퓨터 입장에서 약간의 차이가 있긴 하다고 함.
    def __repr__(self): #repr : representation
        return str(self.num)+'번 회원 : '+self.id+"/"+self.name


user1 = User('abc','abc1','ABC')
user2 = User('bcd','bcd2','BCD')

#print(user1.num)
#print(user2.num)
print(user1)
print(user2)


#??? 보충 : __str__ vs __repr__