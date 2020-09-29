# To add a new cell, type '# %%'
# To add a new markdown cell, type '# %% [markdown]'

#어떻게 해야 내보내지나??
#이게 잘 된건지도 잘 모르겠는데?


def isLeapYear(year):
    return True if year%4 == 0 and year%100 != 0 or year%400 == 0 else False

def lastDay(year, month):
    lst = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    if isLeapYear(year):
        lst[1] = 29
    return lst[month-1]

def lastDay_test(year, month):
    #1월 ~ 7월 : 홀수가 31일, 8월~12월 : 짝수가 31일
    if month == 2:
        return 29 if isLeapYear(year) else 28
    elif 0 < month < 8 and month%2==1:
        return 31
    elif 7 < month < 13 and month%2==0:
        return 31
    else:
        return 30

#My own solution
def totalDay(year, month, day):
    #1년 : 365일
    #각 월별 최대 일자: lst[]
    #2020년 : 1년부터 2019년 흐름. 2019*365, 윤일도 합쳐야함.isLeapYear
    #1월 1일 ~ 1월 31일 : 31-1일
    #1월 1일 ~ m월 d일 : lst[0]+lst[1]+...+lst[m-1]+(d-1) or d
    #첫째날을 0일로 치면 (d-1)까지 세고, 1일로 치면 d까지 세야 맞다.
    
    #1년~2년1월1일까지 : 365일
    #윤년이 있으면 366일해서 합하는 함수
    days = 0
    for i in range(1, year): #year-1까지 합
        days += 366 if isLeapYear(i) else 365
    for i in range(1, month): #1월부터 month-1까지
        days += lastDay(year, i) #1월부터 전달까지의 lastDay 합
    days += day #잔여 day 합
    return days
    #위의 1을 기준일로 만들면 D-day가 될 듯.

def weekDay(year, month, day):
    return totalDay(year, month, day)%7



if __name__== '__main__':
    print(isLeapYear(2020))
    print(lastDay(2020,9))
    print(totalDay(2020,9,28))
    print(weekDay(2020,9,28))
    wd = weekDay(2020, 9, 30)
    wdStr = '월' if wd==1 else '화' if wd==2 else '수' if wd==3 else '목' if wd==4 else '금' if wd==5 else '토'
    print('오늘은 '+wdStr+'요일 입니다.')