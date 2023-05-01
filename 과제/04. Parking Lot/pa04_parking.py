k, n = map(int, input().split())
cnt=0
first=k
car=[]
tmp=[]
rmove=[0]
def carIn(x):
    if 0 in car:
        loc=car.index(0)
        del car[loc]
        car.insert(loc,x)
    else:
        car.append(x)
def carOut(x):
    y=car.index(-x)
    car[y]=0
for i in range(n):
    tmp.append(int(input()))
    if tmp[i]>0:
        cnt+=1
        carIn(tmp[i])
    else:
        if -tmp[i] not in tmp:
            tmp[i]=0
        else:    
            cnt-=1
            carOut(tmp[i])
    if cnt>k:
        k*=2
    if cnt/k<=1/3 and k>first:          
        k=int(k/2)
        car=[j for j in car if j not in rmove]

for i in range(len(car)):
    if car[i]:
        print(i+1,car[i])