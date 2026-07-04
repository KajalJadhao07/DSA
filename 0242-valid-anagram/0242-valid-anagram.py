class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s) == len(t)):
            s1 = set(s)
            for ch in s1:
                if s.count(ch) != t.count(ch):
                    return False

            return True
        else:
            return False