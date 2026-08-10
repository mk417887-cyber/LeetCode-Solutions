class Solution {
public:
    int maximumValue(vector<string>& strs) {
    int ans = 0 ;

    for ( string s : strs){
        bool isnumber = true;
        for(char ch : s){
            if( !isdigit(ch)){
                isnumber = false;
                break;
            }
        }
        if(isnumber){
            ans = max(ans , stoi(s));
        }
        else{
            ans = max(ans , (int)s.length());
            
        }
    }      
    return ans;
    }
};