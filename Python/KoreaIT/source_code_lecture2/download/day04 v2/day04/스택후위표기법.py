from 연결스택 import *

def getPriority(op):
    if op=='+' or op=='-':
        return 1
    elif op=='*' or op=='/':
        return 2

def doing(eq):
    for i in range(len(eq)):
        if eq[i].isdigit():
            print(eq[i],end='')
        else:
            if s.is_empty():
                s.push(eq[i])
            else:
                while (getPriority(s.top.data)>=getPriority(eq[i])):
                    s.pop()
                    if s.is_empty():
                        break
                s.push(eq[i])
    while not s.is_empty():
        s.pop()

s = LinkedStack()
while True:
    eq = input('수식 입력 : ')
    doing(eq)
    print()
