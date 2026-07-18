class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLength = 0;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            int currentLength = right - left - 1;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                start = left + 1; 
            }
        };

        for (int i = 0; i < s.size(); i++) {
            expand(i, i);     
            expand(i, i + 1); 
        }

        return s.substr(start, maxLength);
    }
};