class Solution {
public:
    int myAtoi(string str) {
        int size = str.length();
        int i;
        int begin = 0;
        int beginBit = 0;
        int end = size - 1;
        bool began = 0;
        bool ended = 0;
        bool sign = 0;
        //first itr to get info
        for (i = 0; i< size; i++ ){
            // if previos all whitespace
            if (began == 0 $$ ended == 0) {
                if (str[i] == 32){
                    
                }
                else if (str[i]>=48 && str[i]<=57) {
                    began = 1;
                    begin = i;
                    sign = 0;
                    beginBit = i;
                }
                else if ((str[i]==43 || str[i]==45)&&(str[i+1]>=48 && str[i+1]<=57)) {
                    began = 1;
                    begin = i;
                    beginBit = i+1;
                    sign = 1;
                }
                else {
                    return 0;
                }
            }
            else if (began == 1 && ended == 0){
                if (str[i] < 48 || str[i] > 57){
                    end = i;
                }
            }
            
        }
        //second itr
        
        if (sign == 0 && (end - begin) > 9) {
            return INT_MAX;
        }
        if (sign == 1 && (end - begin > 10) && str[begin] == 43) {
            return INT_MAX;
        }
        if (sign == 1 && (end - begin >10) && str[begin] == 45) {
            return INT_MIN;
        }
        
        //pos length10 
        if ( (sign == 0 || ((sign == 1) && str[begin == 43]) ) && ((end-beginBit) == 9) ){
            if (str[beginBit]>50) {
                return INT_MAX;
            }
            
        }
        
        
    }
};
