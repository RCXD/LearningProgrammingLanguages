from 연결스택 import *

def getPriority(op):
    if op=='+' or op=='-':
        return 1
    elif op=='*' or op== '/':
        return 2

def doing(eq): #equation
    for i in range(len(eq)):
        if eq[i].isdigit(): #string method
            print(eq[i], end= '')
        else:
            if s.is_empty(): #스택이 비어있으면
                s.push(eq[i]) #스택에 집어넣는다.
            else:
                while getPriority(s.top.data)>=getPriority(eq[i]): #top에 있는것의 우선순위보다 낮으면 팝
                    s.pop() #*가 들어있는데 +가 들어가려한다면 *가 팝됨
                    if s.is_empty(): #다 비웠으면 탈출. top==None일때.
                        break
                s.push(eq[i]) #우선순위가 높은것들을 비운 뒤 낮은 것(eq[i])을 푸시
    while not s.is_empty():
        s.pop()

s = LinkedStack()
while True:
    eq = input('수식 입력: ')
    doing(eq)
    print()

#왜 연산자가 출력이 안되니? 찾아라 어딘가 출력할 적절한 장소를..