# KMP (Knuth-Morris-Pratt) String Matching Algorithm

def compute_lps(pattern):
    m = len(pattern)
    lps = [0] * m
    
    length = 0  # length of the previous longest prefix suffix
    i = 1
    
    while i < m:
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
                
    return lps


def kmp_search(text, pattern):
    n = len(text)
    m = len(pattern)
    
    # Edge case
    if m == 0:
        return []
    
    lps = compute_lps(pattern)
    
    i = 0  # index for text
    j = 0  # index for pattern
    
    result = []
    
    while i < n:
        if text[i] == pattern[j]:
            i += 1
            j += 1
        
        if j == m:
            result.append(i - j)
            j = lps[j - 1]
        
        elif i < n and text[i] != pattern[j]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
                
    return result


# -------- Main Program --------
if __name__ == "__main__":
    text = input("Enter text: ")
    pattern = input("Enter pattern: ")
    
    matches = kmp_search(text, pattern)
    
    if matches:
        print("Pattern found at indices:", matches)
    else:
        print("Pattern not found")