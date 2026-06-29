class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        s=""
        for st in licensePlate :
            if (st >='a' and st<='z') or (st>='A' and st<='Z') :
                s+=st
        s=s.lower()
        plate_counts = Counter(s)
        shortest_word=None
        for word in words:
            word_counts = Counter(word)
            if (plate_counts & word_counts) == plate_counts:
                if shortest_word is None or len(word) < len(shortest_word):
                    shortest_word = word
        return shortest_word