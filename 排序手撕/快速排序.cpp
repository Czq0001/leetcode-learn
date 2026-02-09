#include <iostream>
#include <utility>
#include <vector>
using namespace std;
void quickSort(vector<int> &nums, int l, int r) {
  if (l >= r) {
    return;
  }
  int pivot = nums[l];
  int i = l, j = r;
  while (i < j) {
    while (i < j && nums[j] > pivot) {
      j--;
    }
    while (i < j && nums[i] <= pivot) {
      i++;
    }
    swap(nums[i], nums[j]);
  }
  swap(nums[i], nums[l]);
  quickSort(nums, l, i - 1);
  quickSort(nums, i + 1, r);
}
int main() {
  vector<int> nums = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  quickSort(nums, 0, nums.size() - 1);
  for (auto n : nums) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}