#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    string longestPalindrome(string s) {
        int size = s.length();
        int i;
        int odd_max_center = 0;
        int odd_max_radius = 0;
        int even_max_low_center = 0;
        int even_max_radius = 0;
        bool odd = 0;
        bool even = 0;
        
        if (size == 0 || size == 1) {
            return s;
        }
        
        for (i = 0; i < size; i++) {
            int j = 0;
            //found the odd_max radius for each "i"
            while ( j <= i) {
                if(s[i-j] == s[i+j]) {
                    odd = 1;
                    j++;
                }
                else
                    break;
            }
            if (odd_max_radius < j - 1) {
                odd_max_center = i;
                odd_max_radius = j -1;
            }

            
            //find the even max
            int k = 0;
            bool local_even = 0;
            while ( k <= i) {
                cout << "i = " << i<<" k= "<<k<<"\ns[i-k] = "<<s[i-k]<<" s[i+k+1] = "<<s[i+k+1]<<"\n";
                if(s[i-k] == s[i+k+1]){
                    even = 1;
                    local_even = 1;
                    k++;
                }
                else
                    break;
            }
            cout << "i = " << i << " k = "<<j<<" \nlocal_even = "<<local_even<<"\n";
            if(local_even) {
                if(even_max_radius <= k - 1){
                    even_max_low_center = i;
                    even_max_radius = k - 1;
                }
            }
        }

        //then do a final compare for the old max and even max!
        
        int begin, end;
        cout << "even = " << even << "\n";
        if (even){
            int odd_length = 2 * odd_max_radius + 1;
            int even_length = 2 * (even_max_radius + 1);
            
            if (odd_length > even_length) {
                begin = odd_max_center - odd_max_radius;
                end = odd_max_center + odd_max_radius;
            }
            else{
                begin = even_max_low_center - even_max_radius;
                end = even_max_low_center + 1 + even_max_radius;
                cout << "begin = " << begin << "end = " << end << "\n"; 
            }
        }
        else {
            begin = odd_max_center - odd_max_radius;
            end = odd_max_center + odd_max_radius;
        }
    

        string result (s.begin() + begin, s.begin() + end + 1);
        return result;
    }
};


int main() {
    
    string input = "abb";
    Solution sb;

    cout <<sb.longestPalindrome(input)<<"\n";

    return 0;
}

