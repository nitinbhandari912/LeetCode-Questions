class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        cnt=0
        for wd in patterns :
            if wd in word :
                cnt+=1
        return cnt