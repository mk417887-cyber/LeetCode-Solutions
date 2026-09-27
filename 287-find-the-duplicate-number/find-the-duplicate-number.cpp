class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
            unordered_map<int , int> hash;

    for( int i = 0 ; i < nums.size() ; i++){
        hash[nums[i]]++;
    }
    for(int j = 0 ; j < nums.size() ; j++){
        if(hash[nums[j]] > 1){
            return nums[j];
        }
    }
    return -1;
    }
};