#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> merged;
        int size1 = nums1.size();
        int size2 = nums2.size();
        
        int i = 0;
        int j = 0;
        
        while (i < size1 || j < size2) {
            
            //case 1, both two arrays not emptied
            if (i < size1 && j < size2) {
                
                if(nums1[i] < nums2[j]) {
                    merged.push_back(nums1[i]);
                    i++;
                }
                else {
                    merged.push_back(nums2[j]);
                    j++;
                }

            }
            
            // num2 empty
            else if (i < size1) {
                merged.push_back(nums1[i]);
                i++;
            }
            
            //num1 empty
            else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        
        
        if ((size1 + size2)%2){
            return merged[(size1+size2)/2];
        }
        else {
            return (merged[(size1+size2)/2-1]+merged[(size1+size2)/2])/2.0; 
        }
        
    }


};

int main() {
    
    int myinput1[] = {1, 3, 5, 7, 9};
    int myinput2[] = {2, 4, 6, 8, 10};
    
    vector<int> input1(myinput1, myinput1 + sizeof(myinput1) / sizeof(int));
    vector<int> input2(myinput2, myinput2 + sizeof(myinput2) / sizeof(int));

    Solution sb;

    cout<<"result = " <<sb.findMedianSortedArrays(input1, input2)<<"\n";

    return 0;
}


