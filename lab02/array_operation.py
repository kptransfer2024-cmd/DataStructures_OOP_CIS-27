

def linearSearch(arr, target):
    is_found = False
    for i in range(len(arr)):
        if arr[i] == target:
            print(f"Value {target} found at index: {i}")
            is_found = True
    if not is_found:
        print(f"Value {target} not found in the array.")

def highestValue(arr):
    highest = arr[0]
    for i in range(len(arr)):
        if arr[i] > highest:
            highest = arr[i]
    print(f"The highest valueis: {highest}")

def middleValue(arr):
    print(f"The middle index is: {len(arr)//2}")

def bubbleSort(arr):
    for i in range(len(arr)):
        for j in range(len(arr)-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    print(f"The sorted array is: {arr}")

def meanAverage(arr):
    sum = 0
    for i in range(len(arr)):
        sum += arr[i]
    print(f"The mean average is: {sum / len(arr)}")

def medianAverage(arr):
    bubbleSort(arr)
    if len(arr) % 2 == 1:
        median = arr[len(arr) // 2]
    else:
        median = (arr[len(arr) // 2] + arr[len(arr) // 2 - 1]) / 2
    print(f"The median average is: {median}")

array1 = [11, 22, 33, 44, 55, 66, 55, 44, 99, 100]
medianAverage(array1)