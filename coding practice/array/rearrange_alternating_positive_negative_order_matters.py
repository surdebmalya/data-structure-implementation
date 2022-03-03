"""
Question:
https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

Medium
"""
def rearrange(arr, length):
    numberP = 0
    numberN = 0
    for i in arr:
        if i>=0:
            numberP+=1
        elif i<0:
            numberN+=1
    if numberP>numberN:
        # first element is negative
        for index in range(length):
            if numberN==0:
                return
            if index%2==0: # this index must be negative
                if arr[index]>=0:
                    ptrN = -1
                    for i in range(index, length):
                        if arr[i]<0:
                            ptrN=i
                            break
                    else:
                        return
                    temp = arr[index]
                    arr[index]=arr[ptrN]
                    for i in range(ptrN, index+1, -1):
                        arr[i] = arr[i-1]
                    arr[index+1] = temp
                    numberN-=1
            elif index%2!=0: # this index must be positive
                if arr[index]<0:
                    ptrP = -1
                    for i in range(index, length):
                        if arr[i]>=0:
                            ptrP=i
                            break
                    else:
                        return
                    temp = arr[index]
                    arr[index]=arr[ptrP]
                    for i in range(ptrP, index+1, -1):
                        arr[i] = arr[i-1]
                    arr[index+1] = temp
    elif numberP<numberN:
        # first element is positive
        for index in range(length):
            if numberP==0:
                return
            if index%2!=0: # this index must be negative
                if arr[index]>=0:
                    ptrN = -1
                    for i in range(index, length):
                        if arr[i]<0:
                            ptrN=i
                            break
                    else:
                        return
                    temp = arr[index]
                    arr[index]=arr[ptrN]
                    for i in range(ptrN, index+1, -1):
                        arr[i] = arr[i-1]
                    arr[index+1] = temp
            elif index%2==0: # this index must be positive
                if arr[index]<0:
                    ptrP = -1
                    for i in range(index, length):
                        if arr[i]>=0:
                            ptrP=i
                            break
                    else:
                        return
                    temp = arr[index]
                    arr[index]=arr[ptrP]
                    for i in range(ptrP, index+1, -1):
                        arr[i] = arr[i-1]
                    arr[index+1] = temp
                    numberP-=1
    else:
        if arr[i]<0:
            # first element is negative
            for index in range(length):
                if numberN==0:
                    return
                if index%2==0: # this index must be negative
                    if arr[index]>=0:
                        ptrN = -1
                        for i in range(index, length):
                            if arr[i]<0:
                                ptrN=i
                                break
                        else:
                            return
                        temp = arr[index]
                        arr[index]=arr[ptrN]
                        for i in range(ptrN, index+1, -1):
                            arr[i] = arr[i-1]
                        arr[index+1] = temp
                        numberN-=1
                elif index%2!=0: # this index must be positive
                    if arr[index]<0:
                        ptrP = -1
                        for i in range(index, length):
                            if arr[i]>=0:
                                ptrP=i
                                break
                        else:
                            return
                        temp = arr[index]
                        arr[index]=arr[ptrP]
                        for i in range(ptrP, index+1, -1):
                            arr[i] = arr[i-1]
                        arr[index+1] = temp
        else:
            # first element is positive
            for index in range(length):
                if numberP==0:
                    return
                if index%2!=0: # this index must be negative
                    if arr[index]>=0:
                        ptrN = -1
                        for i in range(index, length):
                            if arr[i]<0:
                                ptrN=i
                                break
                        else:
                            return
                        temp = arr[index]
                        arr[index]=arr[ptrN]
                        for i in range(ptrN, index+1, -1):
                            arr[i] = arr[i-1]
                        arr[index+1] = temp
                elif index%2==0: # this index must be positive
                    if arr[index]<0:
                        ptrP = -1
                        for i in range(index, length):
                            if arr[i]>=0:
                                ptrP=i
                                break
                        else:
                            return
                        temp = arr[index]
                        arr[index]=arr[ptrP]
                        for i in range(ptrP, index+1, -1):
                            arr[i] = arr[i-1]
                        arr[index+1] = temp
                        numberP-=1

if __name__ == "__main__":
    arr = [1, 2, 3, -4, -1, 4]
    rearrange(arr, len(arr))
    for i in arr:
        print(i, end=" ")