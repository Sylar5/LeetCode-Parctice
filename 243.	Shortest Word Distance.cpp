/**
**************************************************************************************
243. 最短单词距离

给定一个单词列表和两个单词 word1 和 word2，返回列表中这两个单词之间的最短距离。

示例:
假设 words = ["practice", "makes", "perfect", "coding", "makes"]

输入: word1 = “coding”, word2 = “practice”
输出: 3
输入: word1 = "makes", word2 = "coding"
输出: 1
注意:
你可以假设 word1 不等于 word2, 并且 word1 和 word2 都在列表里。
***************************************************************************************
**/
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        if(words.size() < 2)  return 0;
        int l1 = -1, l2 = -1;
        int res = words.size() + 1;
        for(int i = 0; i < words.size(); ++i) {
            if(words[i] == word1) {
                l1 = i;
                if(l2 != -1 && l1 - l2 < res)  res = l1 - l2;
            }
            else if(words[i] == word2) {
                l2 = i;
                if(l1 != -1 && l2 - l1 < res)  res = l2 - l1;
            }
        }
        return res == words.size() + 1 ? 0 : res;
    }
};
