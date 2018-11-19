#include "../system.h"

void insertion_sort(std::vector<int>& nums)
{
  if (nums.size() <= 1)
    return;
  int length = nums.size();
  int i, j, key;
  for (i = 1; i < length; ++i)
  {
    key = nums[i];
    j = i-1;
    while (j >= 0 && nums[j] > key)
    {
      nums[j+1] = nums[j];
      --j;
    }
    nums[j+1] = key;
  }
}
void insertion_sort_reverse(std::vector<int>& nums)
{
  if (nums.size() <= 1)
    return;
  int i, j, key;
  for (j = 1; j < nums.size(); ++j)
  {
    key = nums[j];
    i = j - 1;
    while (i >= 0 && nums[i] < key)
    {
      nums[i+1] = nums[i];
      ++i;
    }
    nums[i+1] = key;
  }
}
