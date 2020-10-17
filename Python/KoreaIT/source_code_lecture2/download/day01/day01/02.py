class Car:
    brand=''
    color=''
    price=0

    def __init__(self,brand='',color='',price=0):
        self.brand=brand
        self.color=color
        self.price=price

    def start(self):
        print(self.brand,'시동 켜기')

    def stop(self):
        print(self.brand,'시동 끄기')

myCar=Car()#기본생성자
#myCar=Car("Benz","White",35000)

myCar.brand='Benz'
myCar.color='White'
myCar.price=35000
myCar.start()
myCar.stop()

momCar=Car()

momCar.brand='Ferrari'
momCar.color="Red"
momCar.price=50000











