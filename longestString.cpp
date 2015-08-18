#include <iostream>
#include <map>
//#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        
//        if (size == 0 ) return 0;
        
        int i;
        int max = 0;
        
        for (i = 0; i < size; i++) {
            int localMax;

            map<char, int> myMap;
            myMap[s[i]] = i;
            int count = 1;
            int j;
            
            for (j = i + 1; myMap.find(s[j]) == myMap.end() && j< size; j++) {
                
                myMap[s[j]] = count;
                count ++; 
            }

            localMax = count;

            max = localMax > max ? localMax : max;
        } 
        
        
        
        return max; 
    }
};

int main() {
    
    string a("abcdeafghi");

    Solution sb;

    cout << sb.lengthOfLongestSubstring(a)<<"\n";

    return 0;
}

