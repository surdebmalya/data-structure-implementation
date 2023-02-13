# Pollard rho method

def find_function(x):
    return pow(x, 2) + 1
    
def GCD(a, b):
    if(b == 0):
        return abs(a)
    else:
        return GCD(b, a % b)

if __name__=="__main__":
    n = int(input("Enter N: "))
    if(n<0):
        print("ERROR")
    else:
        k = 15
        x = 2
        y = 2
        c = 1
        gcd = 1
        while(gcd == 1 and k>0):
            x = find_function(x) % n
            y = find_function(find_function(y)) % n
            gcd = GCD(max(abs(x - y), n), min(abs(x-y), n))
            print(f"x = {x}, y = {y}, gcd = {gcd}")
            k = k-1
        if(gcd!=1):
            print("COMPOSITE")
        else:
            print("PRIME")