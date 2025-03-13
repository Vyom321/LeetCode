#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int max_Subarray(vector<int>&nums){
    int current_Sum = 0;
    int max_Sum = INT_MIN;
    for(int num : nums){
        current_Sum = max(current_Sum+num , num);
        max_Sum = max(max_Sum , current_Sum);
    }
    return max_Sum;
}
};
int main(){
Solution sol;
int n ;
cout<<"Enter the size of the array"<<endl;
cin>>n;
vector<int>nums(n);
cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int result = sol.max_Subarray(nums);
    
    cout << "Maximum subarray sum: " << result << endl;
    
    return 0;
}