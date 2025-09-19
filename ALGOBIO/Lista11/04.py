def binary_search(input: list, val: int):
    if (len(input)==0): return -1
    mid = len(input)//2

    if (val==input[mid]): return mid
    elif (val>input[mid]): 
        ret = binary_search(input[mid+1:],val) 
        if ret != -1:
            return ret + mid+1
    elif (val<input[mid]): 
        ret = binary_search(input[:mid],val)
        if ret != -1:
            return ret
    return -1
print(binary_search([0,1,2,3,4,5,77],77))