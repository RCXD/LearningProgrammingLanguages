"""
Write a Python class that allows us to track how much a customer spends at 20 different shops 
and determines his/her eligibility for a discount. The class should allow 1) 
check total amount purchases in different store, and 2) 
check discount eligibility if he/she has purchased over $100 in 3 different stores.
"""
class Shops:
    def __init__(self):
        self.shopList=list()
    def addShop(self, name):
        MyShop=Shop(name)
        self.shopList.append(MyShop)
        
class Shop:
    def __init__(self, name):
        self.name=name
        self.items=dict()
    def addItems(self, item, price):
        self.items.update({item:price})
class Customer:
    def __init__(self, name):
        self.name=name
        self.visitList=list()
        self.purchase=dict()
        self.total=0
        self.eligibility=False
    def addPurchase(self, Shop, item):
        self.visitList.append(Shop.name)
        self.purchase.update({item:Shop.items.get(item)})
        self.total+=Shop.items.get(item)
        if self.total >= 100 and len(self.purchase) >= 3:
            self.eligibility=True
        else:
            self.eligibility=False
    def checkTotalPurchase(self):
        print(f'The total purchase is {self.total:,} $.')
    def checkDiscntEligib(self):
        print(f'{self.name} will get discount' if self.eligibility else f'{self.name} is not eligible for discount')


MyShops=Shops()
for i in range(20):
    MyShops.addShop(f'Shop{i+1}')
for i in range(len(MyShops.shopList)):
    print(MyShops.shopList[i].name)
MyShops.shopList[0].addItems('apple', 10)
MyShops.shopList[0].addItems('peach', 15)
MyShops.shopList[0].addItems('pear', 20)

MyShops.shopList[1].addItems('apple', 11)
MyShops.shopList[1].addItems('peach', 12)
MyShops.shopList[1].addItems('pear', 18)

MyShops.shopList[2].addItems('gummy bear', 30)
MyShops.shopList[2].addItems('bubble gum', 20)
MyShops.shopList[2].addItems('candy', 15)

A=Customer('Andrew')
B=Customer('Benton')
C=Customer('Charls')

A.addPurchase(MyShops.shopList[0],'apple')
A.checkTotalPurchase()
A.checkDiscntEligib()

A.addPurchase(MyShops.shopList[2],'gummy bear')
A.addPurchase(MyShops.shopList[2],'candy')
A.addPurchase(MyShops.shopList[1],'pear')
A.addPurchase(MyShops.shopList[1],'apple')
A.addPurchase(MyShops.shopList[2],'gummy bear')
A.addPurchase(MyShops.shopList[2],'candy')
A.checkTotalPurchase()
A.checkDiscntEligib()