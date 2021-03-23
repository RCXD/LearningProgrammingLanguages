# Question: If I have n disks, move disks into designated peg.
# Rule 01: Larger disk cannot be on top of the smaller disk
# Rule 02: Should move the disk on top first, one by one

'''
    peg i           peg j           peg k
    A  
    B
    C
    D
    E
'''

# Attempt 01: Stack
class Node:
    def __init__(self, data):
        self.data=data

class Stack:
    def __init__(self, name):
        self.name=name
        self.stackList=[]
        self.top=0
        #self.tempTop=0
        print('created peg', self.name)

    def push(self, data):
        #if not self.isFull():
            newNode=Node(data)
            #self.stackList.insert(self.tempTop, newNode)
            self.stackList.insert(self.top, newNode)
            self.top += 1
            #self.tempTop += 1
            #print('pushed '+data)
        # else:
        #     print('stack overflow')

    def pop(self):
        if not self.isEmpty():
            #print(self.stackList[self.tempTop-1].data)
            #result = self.stackList[self.tempTop-1]
            result = self.stackList[self.top-1]
            #self.tempTop -= 1
            self.top -= 1
            return result.data
        else:
            #print('stack empty')
            return '-1'

    def isEmpty(self):
        #return self.tempTop == 0
        return self.top==0

    # def isFull(self):
    #     return self.top==MAX_SIZE

def directMove(origin, dest):
    #origin.Stack()
    #dest.Stack()
    target = origin.pop()
    dest.push(target) #works!
    #print('moved', str(target), 'from', origin.name, 'to', dest.name)

def move(n, i, j, k):
    if n==1:
        directMove(i,k)
    else:
        move(n-1, i, k, j)
        directMove(i,k)
        move(n-1, j, i, k) 

#Setting up
import time

ii=Stack('i')
jj=Stack('j')
kk=Stack('k')
num=int(input('Insert how many disks you have\n'))
for i in range(0,num):
    #ii.push(chr(ord('E')-i))
    ii.push(' '*i+'-'*(2*(num-i)-1))
    #print('pushed '+chr(ord('E')-i)+' in peg '+ii.name)    
    print('pushed '+' '*i+'-'*(2*(num-i)-1)+' in peg '+ii.name) 
#Setup check(direct access to List)
print(ii.name, jj.name, kk.name, sep='\t')
for i in range(len(ii.stackList)):
    print(ii.stackList[len(ii.stackList)-i-1].data)

#Solve problem
begin=time.time()
move(num, ii, jj, kk)
end=time.time()

#Show Status
print(ii.name, jj.name, kk.name, sep='\t')
for i in range(num):
    print(ii.pop(), jj.pop(), kk.pop(), sep='\t')
print(f"Total runtime of the movement is {end - begin}")

# Other References
# Python recurrsion: https://lucete1230-cyberpolice.tistory.com/222
# Python ASCII: https://www.programiz.com/python-programming/examples/ascii-character
# Python time module: https://www.geeksforgeeks.org/python-measure-time-taken-by-program-to-execute/
# Python time complexity: https://wiki.python.org/moin/TimeComplexity