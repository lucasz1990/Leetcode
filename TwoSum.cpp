class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        int i;
        int match;
        vector<int> Result(2);

        std::map<int, int> ValueIndex;
        std::map<int, int>::iterator it; 

        //build the map
        
        ValueIndex[nums[0]] = 0;
        

        //for (it = ValueIndex.begin(); it != ValueIndex.end(); it++ ) {
        //    std::cout << it->first << " => " << it->second << '\n';            
        //}
        for (i = 1; i < size; i++) {

            match = target - nums[i];
            
            //cout<<match<<"\n";

            it = ValueIndex.find(match);
            //cout << "i = "<< i << "\n";
            //cout << "match = "<< match << "\n";

            //cout << "DEBUG: < key pair > = < " << it->first << " " << it->second<< " > \n";
            if (it != ValueIndex.end()) {
                Result[0] = it->second + 1;
                Result[1] = i + 1;
                return Result;
            }
            
            else {
                ValueIndex[nums[i]] = i;
            
            }            
        }

    }
};

