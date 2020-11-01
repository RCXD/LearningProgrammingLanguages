class Car: #클래스는 가급적 첫글자를 대문자로.
    #brand = ''
    #color = ''
    #price = 0

    def __init(self, brand='', color='', price=0):
        self.brand = brand
        self.color=color
        self.price=price
        #이렇게 하면, 필드에 별도 변수를 만들 필요가 없다.
        #기본값까지 정할 수 있음.

    def start(self):
        print(self.brand, '시동 켜기')
    
    def stop(self):
        print(self.brand, '시동 끄기')

myCar = Car()

myCar.brand = 'benz'
myCar.color = 'White'
myCar.price = 35000
myCar.start()
myCar.stop()

momCar = Car()

momCar.brand='Ferrari'
momCar.color="Red"
momCar.price=50000
#python에서는 객체를 만들 때 데이터를 저장하기위한 메모리(필드)가 먼저 생성
#객체의 주소는 클래스명이 가지고 있음.

