num = int(input())
ans=1
n=1
while True:
    if ans%num==0:
        print(ans//num,n)
        break
    else:
        ans=ans*10+1
        n+=1