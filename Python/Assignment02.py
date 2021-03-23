"""
Write a Python class that allows us to track how much a customer spends at 20 different shops and determines his/her eligibility for a discount. The class should allow 1) check total amount purchases in different store, and 2) check discount eligibility if he/she has purchased over $100 in 3 different stores.
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
        self.purchase.update({item:Shop.items.get(item)})
        self.total+=Shop.items.get(item)
    def checkTotalPurchase(self):
        print(f'The total purchase is {self.total:,} $.')
    def checkDiscntEligib(self):
        print(f'{self.name} will get discount' if eligibility else f'{self.name} is not eligible for discount')



