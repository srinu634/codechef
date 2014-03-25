arr =[]
index = [0]*1005
bcount = [0]*1005
bpow = [0]*1005
str1 = "test"

def main():
    global arr,index,bcount,bpow,str1
    t = int(input())
    
    while(t>0):
        t = t -1
        index = [0]*n ;dpsum = [0]*n; bcount = [0]*n;  bpow = [0]*1007
        n = int(input())
        arr = map(int, raw_input().split())
        a,b,c = map(int, raw_input().split())
        str1 = raw_input()
    
        fillindex(n)
        arr = countsort(n)
        dpvalues(a,b,c,n)
        
        print ' '.join(map(str,arr))
        
def dpvalues(a,b,c,n):
    global arr,index,dpsum,bcount,bpow,str1

    #1: count b's
    if(str1[0]=='M'):
        bcount[0] = 1
    else:
        bcount[0] = 0
    for i in range(1,n):
        if(str1[i]=='M'):
            bcount[i] = 1 + bcount[i-1]
        else:
            bcount[i] = bcount[i-1]
    
    #2: DP b powers % c
    bpow[0] = 1
    for i in range(1,1005):    #Powers of b
        bpow[i] = (b*bpow[i-1])%c
     
    #3: THE FINAL RESULT
    sum = 0
    for i in range(0,n):
        if(str1[i]=='A'):
            sum = (sum+a)%c
        elif(str1[i]=='M'):
            sum  = (sum*b)%c
        arr[i] = ( (arr[i]*bpow[bcount[i]])%c + sum  )%c
        
def countsort(n):
    global index,arr
    t=[0]*n
    for i in range(0,n):
        t[ index[i] ] = arr[ i ]
    return t
    
def fillindex(n):
    global index,arr,str1
    revflag = 0;   left = 0;  right = n - 1
    for i in range(0,n):
        if(str1[i]=='R'):
            revflag = revflag ^ 1
        if(revflag==0):
            index[left] = i;     left = left + 1
        else:
            index[right] = i;    right = right -1
    
main()
