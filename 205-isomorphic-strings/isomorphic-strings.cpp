class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        char mapST[256] = {0};
        char mapTS[256] = {0};
        
        for (int i = 0; i < s.length(); ++i) {
            char charS = s[i];
            char charT = t[i];
            
            if (mapST[charS] != 0 && mapST[charS] != charT) {
                return false;
            }
            if (mapTS[charT] != 0 && mapTS[charT] != charS) {
                return false;
            }
            
            mapST[charS] = charT;
            mapTS[charT] = charS;
        }
        
        return true;
    }
};