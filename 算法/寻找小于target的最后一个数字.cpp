#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums = {1,2,3,4,5,6,6,7};
    int target = 6;
    int l = 0,r = nums.size()-1;
    int ans = -1;
    while (l <= r) {
        int mid = l + (r-l)/2;
        if(nums[mid] <= target){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout << ans << endl;
    return 0;
}