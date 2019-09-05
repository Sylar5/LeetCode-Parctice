/**
*****************************************************************************************
567. Permutation in String
Medium

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
********************************************************************************************
**/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())  return false;
        vector<int> f1(26, 0), f2(26, 0);
        for(int i = 0; i < s1.size(); ++i) {
            ++f1[s1[i] - 'a'];
            ++f2[s2[i] - 'a'];
        }
        int count = 0;
        for(int i = 0; i < 26; ++i) {
            if(f1[i] == f2[i]) ++count;
        }
        if(count == 26)  return true;
        for(int i = 0; i < s2.size() - s1.size(); ++i) {
            int left = s2[i] - 'a', right = s2[i + s1.size()] - 'a';
            --f2[left];
            if(f2[left] == f1[left]) 
                ++count;
            else if(f2[left] == f1[left] - 1)  
                --count;
            ++f2[right];
            if(f2[right] == f1[right]) 
                ++count;
            else if(f2[right] == f1[right] + 1)  
                --count;
            if(count == 26)  return true;
        }
        return count == 26;
    }

};
