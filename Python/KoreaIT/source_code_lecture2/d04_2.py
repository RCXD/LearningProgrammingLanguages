#Teacher Solution

from WebStack import *
wl=LinkedStack() #WebList
history = LinkedStack() #history

def go(self, url):
    wl.push(url)
def forward(self):
    wl.push(history.pop()) #얘 왜 에러남?
def back(self):
    #history.push(wl.pop())
    page = wl
def history(self):
    temp = wl.selectAll()
    cnt= 1
    for web in temp:
        print(cnt, '. 들렸던 페이지 : ', web, sep='')
        cnt += 1

#이것이 MVC model 1이다.
#Reference : Modeing
# MVC model 1, 2
# https://www.javatpoint.com/model-1-and-model-2-mvc-architecture