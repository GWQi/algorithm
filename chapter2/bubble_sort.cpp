#include <vector>
#include <limits>
#include <initializer_list>
#include <iostream>
#include <algorithm>

void bubble_sort(std::vector<int>& nums)
{
  int i, j;
  for (i = 0; i < nums.size()-1; ++i)
    for (j = nums.size()-1; j > i; --j)
      if (nums[j] < nums[j-1])
        std::swap(nums[j], nums[j-1]);
}
int main()
{
  std::vector<int> nums = {2, 4, 5, 7, 1, 2, 3, 6};
  bubble_sort(nums);
  for (int i = 0; i < nums.size(); ++i) std::cout << nums[i] << " ";
}
