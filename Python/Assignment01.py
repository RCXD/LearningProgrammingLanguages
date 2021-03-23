"""
Write a Python class that allows us to track car fuel consumption. 
The class should allow 1) add gas, and 2) check amount of gas tank 
based on distance travel and car fuel economy. 
Submit a class file and an invoking file to test your python class.
"""
    
class Car:
    def __init__(self, owner, carName, distTravel, fuelEco):
        self.owner=owner
        self.carName=carName
        self.gas=0
        self.distTravel=distTravel
        self.fuelEco=fuelEco
        self.tank=distTravel/fuelEco

    def addGas(self, gas):
        print(f'{gas:,} galons added in the gas tank of {self.owner}\'s {self.carName}.')
        self.gas+=gas
        if self.gas>self.tank: #detect overflow
            overflow=self.gas-self.tank
            self.gas=self.tank
            print(f'{overflow:,} galons of gas overflowed')
        print(f'Remaining gas is {self.gas:,}.')
            
    def checkGasTank(self):
        print(f'The amount of gas tank of {self.owner}\'s {self.carName} is {self.tank:,} galons.')
        print(f'And the remaining gas is {self.gas:,} galons.')


"""
Fuel economy: distanceTravel per galon
The amount of gas tank: distance travel / fuel economy
"""
mycar = Car('A', 'Lamborghini', 100000, 2.0)
mycar.addGas(1000)
mycar.addGas(5000)
mycar.addGas(100000)
mycar.checkGasTank()