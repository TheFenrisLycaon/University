ROOT = 0.5

flag = 1

while flag:
    try:
        num = input("Enter the number you want the square root for ::\t")
        num_float = float(num)
        flag = 0
    except:
        print("Please enter a numeric value...")

num_root = num_float**ROOT

print("The square root of {} is {}".format(round(num_float,2), round(num_root,3)))
