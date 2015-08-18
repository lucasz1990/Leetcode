#include <iostream>
#include <map>
//#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size == 0 ) return 0;
        
        int i;
        int max = 1;

        map<char, int> myMap;
        map<char, int>::iterator it;


        myMap[s[0]] = 0;
        int counts[size];

        for (i = 0; i < size; i++) {
             counts[i] = size - i;
        }
        
        for (i = 1; i < size; i++) {
            it = myMap.find(s[i]);
            
            if (it != myMap.end()) {
                int previous_index = it->second;

                cout << "previous_index = " <<  previous_index << "\n";
                cout << "i = " <<  i << "\n";
                counts[previous_index] = i - previous_index;
                myMap.erase(it);
            }
            myMap[s[i]] = i;
        }
        
        for (i=0; i < size; i++) {
            max = counts[i] > max ? counts[i] : max;

        }


        return max; 
    }
};

int main() {
    
    string a("abaa");

    Solution sb;

    cout << sb.lengthOfLongestSubstring(a)<<"\n";

    return 0;
}

