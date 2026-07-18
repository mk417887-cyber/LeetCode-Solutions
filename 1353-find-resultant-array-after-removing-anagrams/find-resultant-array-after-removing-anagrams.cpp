class Solution {
    private:
    bool isAnagram(const string& s, const string& t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }
        for (char c : t) {
            count[c - 'a']--;
        }
        
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        result.push_back(words[0]);
        
        for (int i = 1; i < words.size(); ++i) {
            if (!isAnagram(result.back(), words[i])) {
                result.push_back(words[i]);
            }
        }
        
        return result;
    }


};