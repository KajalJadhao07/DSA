class Solution:
    def frequencySort(self, s: str) -> str:
        freq = {}

        for ch in s:
            if(ch in freq):
                freq[ch] += 1
            else:
                freq[ch] = 1

        res = ""
        sorted_dict = dict(sorted(freq.items(), key=lambda x: (x[1], x[0]), reverse = True))

        for key, value in sorted_dict.items():
            res += key * value

        return res