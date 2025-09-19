def merge_sort(input: list):
    i = j = 0
    if len(input) > 1:
        mid = len(input) // 2
        listA = merge_sort(input[:mid])
        listB = merge_sort(input[mid:])
        while i < len(listA) and j < len(listB):
            if listA[i] < listB[j]:
                input[j+i] = listA[i]
                i += 1
            else:
                input[j+i] = listB[j]
                j += 1
        while i < len(listA):
            input[j+i] = listA[i]
            i += 1
        while j < len(listB):
            input[j+i] = listB[j]
            j += 1
    return input
        

print(merge_sort([1,5,4,6,4,8]))