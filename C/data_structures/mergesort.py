def mergesort(array, begin=0, end=None):
    if end == None:
        end = len(array)
    if end - begin > 1:
        mid = (begin + end)/2

        mergesort(array, begin, mid)
        mergesort(array, mid, end)
        
        merge(array, begin, mid, end)

def merge(array, begin, mid, end):

    left_array = array[begin:mid]
    right_array = array[mid:end]

    print("Left array: ")
    print(left_array)
    print("Right array: ")
    print(right_array)

    left_top = 0
    right_top = 0

    for i in range(begin, end):
        if left_top >= len(left_array):
            array[i] = right_array[right_top]
            right_top += 1
        elif right_top >= len(right_array):
            array[i] = left_array[left_top]
            left_top += 1
        elif left_array[left_top] < right_array[right_top]:
            array[i] = left_array[left_top]
            left_top += 1
        elif right_array[right_top] < left_array[left_top]:
            array[i] = right_array[right_top]
            right_top += 1


array = [9, 8, 7, 6, 5, 4, 3, 2, 1]
print(array)
mergesort(array)
print(array)