def romanToInt(s: str) -> int:
    a = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000 }
    

    s = s.replace("CM", "DCD")
    s = s.replace("CD", "CCCC")    
    s = s.replace("XC", "LXL")
    s = s.replace("XL", "XXXX")    
    s = s.replace("IX", "VIV")
    s = s.replace("IV", "IIII")

    result = 0
    for el in s:
        result += a[el]
    return result
