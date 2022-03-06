#3 Longest Substring Without Repeating Characters

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        characterToIndex = {}
        startIndex = 0
        maxLength = 0
        for i in range(len(s)):
            character = s[i]
            if character in characterToIndex and characterToIndex[character] >= startIndex:
                if maxLength < i - startIndex:
                    maxLength = i - startIndex
                startIndex = characterToIndex[character] + 1
                
                if len(s) - startIndex < maxLength:
                    break
            
            characterToIndex[character] = i
        
        if len(s) - startIndex > maxLength:
            maxLength = len(s) - startIndex
        
        return maxLength
            
test = {}

test[" "] = 'test'

print(test)
