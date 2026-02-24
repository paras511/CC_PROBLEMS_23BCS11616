import sys
input = sys.stdin.readline

k = int(input().strip())
s = input().strip()

count = 0
prefix = 0
freq = {0: 1}  

for ch in s:
    if ch == '1':
        prefix += 1
    
    if prefix - k in freq:
        count += freq[prefix - k]
    
    freq[prefix] = freq.get(prefix, 0) + 1

print(count)