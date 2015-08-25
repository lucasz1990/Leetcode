#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int reverse(int x) {
        bool negative = 0;

        if (x == -2147483648)
            return 0;
        if (x == 0) return 0;

        if (x < 0) {
            negative = 1;
        }
        cout << "negative? " << negative <<"\n";
        int num = negative ? x*(-1) : x;
        
        cout << "num = " << num <<"\n";
        vector<int> digits;
        int digitToPush;
        int iTen;

        while(num/10 > 0) {
            cout << "num =" << num <<"\n";
            digitToPush = (num % 10);
            digits.push_back(digitToPush);
            
            num = num/10;
        }
        digits.push_back(num%10);


        int size = digits.size();
        int result = 0;
        int j;
        int k = 1;

        cout << digits[0] << "\n";
        cout << size << "\n";
        
        if (size == 10) {
            if (digits[0] >=3)  return 0;
            else if (digits[0] == 2) {
                int sum = 0;
                int m;
                int n = 1;
                for (m = 9; m >=1; m--){
                    sum += digits[m]*n;
                    n *= 10;
                }
                if (sum > 147483647)    return 0;

            }
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

    cout << "return "<<sb.reverse(1)<<"\n";

    return 0;
}
