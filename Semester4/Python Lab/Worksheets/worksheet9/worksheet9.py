for i in range(65, 91):
    f = open(f'./{chr(i)}.txt', 'w')
    f.write(f"This is the file named {chr(i)}.")
    f.close()

