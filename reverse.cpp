#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int reverse(int x) {
        bool negative = 0;
        if (x < 0) {
            negative = 1;
        }
        cout << "negative? " << negative <<"\n";
        int num = negative ? x*(-1) : x;
        
        cout << "num = " << num <<"\n";
        int i = 10;
        vector<int> digits;
        int digitToPush;
        int iTen;
        while(num/i > 0) {
            iTen = i/10;
            digitToPush = (num % i)/iTen;
            digits.push_back(digitToPush);
            
            i *= 10;
            cout << i <<"\n";
        }
        
        digits.push_back((num%i)/(i/10));

        int size = digits.size();
        int result = 0;
        int j;
        int k = 1;

        cout << digits[0] << "\n";
        cout << size << "\n";
        if (size >= 10 && digits[0] >= 2) {
            return 0;
        }

        for (j = size - 1; j >= 0 ; j--){
            cout << "j = " <<j<<"\n";
            result += digits[j]*k;
            k *= 10;
        }

        result = negative ? (-1) * result : result;
        return result;
    }
};

int main() {
    Solution sb;

    cout << "return "<<sb.reverse(1463847412)<<"\n";

    return 0;
}
