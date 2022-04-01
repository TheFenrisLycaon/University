def BinarySearch(arr, low, high, key):
    mid = (low + high - 1) // 2

    if key >= arr[high]:
        return "Element not found !"

    if high >= low:

        if arr[mid] == key:
            return f"Element Found At {mid+1}"

        elif key > arr[mid]:
            return BinarySearch(arr, mid + 1, high, key)

        else:
            return BinarySearch(arr, low, mid - 1, key)

    else:
        return "Element not found"


print(BinarySearch([1, 2, 3, 4, 5, 6, 7, 8, 9], 0, 8, 1))
