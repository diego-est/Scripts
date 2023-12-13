def suma(a, b, c):
    possible = False
    if a + b == c:
        possible == True
    elif a + c == b:
        possible == True
    elif b + c == a:
        possible == True
    return possible

def popCount(a) -> int:
    accumulator = 0
    while a > 0:
        accumulator = a % 2
        a = a / 2
    return accumulator


from collections import Counter 
def checksum(strings) -> int:
    twos = 0
    threes = 0
    for string in strings:
        freqs = Counter(string)
        for freq in freqs:
            if freqs[freq] == 2:
                twos += 1
            elif freqs[freq] == 3:
                threes += 1

    print(twos * threes)


test = ["abcdef", "bababc", "abcdee", "aaa", "bb"]

checksum(test)



