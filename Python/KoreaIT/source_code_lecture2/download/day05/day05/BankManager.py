from BankModule import *
bw1=LinkedQueue("입출금 관련업무")
bw2=LinkedQueue("예금상담 개인대출")
class BankManager:
    bwNum=1
    def numIssue(self,num):
        if num==1:
            #입출금
            bw1.enQueue(self.bwNum)
            print(self.bwNum,"번 손님 ",bw1.task," 창구에 대기등록 되었습니다.",sep='')
            self.bwNum+=1
        elif num==2:
            #예금, 대출
            bw2.enQueue(self.bwNum)
            print(self.bwNum,"번 손님 ",bw2.task," 창구에 대기등록 되었습니다.",sep='')
            self.bwNum+=1

    def numFind(self,num):
        curr=bw1.front
        cnt=0
        while curr is not None:
            cnt+=1
            if(curr.data==num):
                print(bw1.task," 창구이며 대기순서는 ",cnt,"번째 입니다.",sep='')
                break
            curr=curr.next
        curr=bw2.front
        cnt=0
        while curr is not None:
            cnt+=1
            if(curr.data==num):
                print(bw2.task," 창구이며 대기순서는 ",cnt,"번째 입니다.",sep='')
                break
            curr=curr.next
    def callNum(self,choice):
        if choice==1:
            #입출금
            num = bw1.deQueue()
            print(num, "번 손님 1번 창구로 와주세요", sep="")
        elif choice==2:
            #예금, 대출상담
            num=bw1.deQueue()
            print(num,"번 손님 2번 창구로 와주세요",sep="")

#뭔가 빠졌음. 적응안되네
#요구조건, 문제가 없으니 중구난방
