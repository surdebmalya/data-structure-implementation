# Muller rabin test

def get_m_and_k(num):
    actual_num = num
    count=0
    while(num%2==0):
        count = count +1
        num = num/2
    k = count
    m = actual_num / pow(2, count)
    return m, k
    
def algo(n):
    actual_num = n
    num = n-1
    m, k = get_m_and_k(num)
    print(f"m = {m}")
    print(f"k = {k}")
    
    # first step
    t = pow(2, m) % n
    print(f"T = {t}")
    if(t==1 or t == num):
        return "PRIME"
    if(k==1): 
        if(t==1 or t == -1):
            return "PRIME"
        else:
            return "COMPOSITE"
    while(k-1>=0):
        t = pow(t, 2) % actual_num
        k = k-1
        if(t==1):
            return "COMPOSITE"
        if((t==-1 or t == num)):
            return "PRIME"
    return "COMPOSITE"

if __name__=="__main__":
    numChar = int(input("One or Two digit? : "))
    if numChar==1:
        n = int(input("Enter N: "))
    else:
        x = int(input("Enter X: "))
        p = int(input("Enter P: "))
        n = pow(x, p)
    if(n<0):
        print("ERROR")
    else:
        print(f"{n} is " + algo(n))