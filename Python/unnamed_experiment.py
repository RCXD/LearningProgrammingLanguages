class Myclass:
    def __init__(self):
        self.a = 1
    def swap(self):
        b=self.a
        return b

if __name__== "__main__":
    c=Myclass()
    b=c.swap()
    print(c.a)
    print(b)
    
