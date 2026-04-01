class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
         vector<int> ans;
    if(words.empty()) return ans;

    int wordLen = words[0].length();
    int wordCount = words.size();
    int totalLen = wordLen * wordCount;

    unordered_map<string,int> target;
    for(string w : words)
        target[w]++;

    for(int i = 0; i < wordLen; i++)
    {
        int left = i, count = 0;
        unordered_map<string,int> window;

        for(int j = i; j + wordLen <= s.length(); j += wordLen)
        {
            string word = s.substr(j, wordLen);

            if(target.find(word) != target.end())
            {
                window[word]++;
                count++;

                while(window[word] > target[word])
                {
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }

                if(count == wordCount)
                    ans.push_back(left);
            }
            else
            {
                window.clear();
                count = 0;
                left = j + wordLen;
            }
        }
    }

    return ans;
    }
};