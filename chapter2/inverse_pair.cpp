#include <vector>
#include <limits>
#include <initializer_list>
#include <iostream>

void merge_with_guard(std::vector<int>& nums, int p, int q, int r)
{
  int leftsize = q - p + 1, rightsize = r - q;
  int i, j;
  std::vector<int> left(leftsize + 1, 0);
  std::vector<int> right(rightsize + 1, 0);
  for (i = 0; i < leftsize; ++i) left[i] = nums[p+i];
  for (i = 0; i < rightsize; ++i) right[i] = nums[q+1+i];
  left[leftsize] = std::numeric_limits<int>::max();
  right[rightsize] = std::numeric_limits<int>::max();
  i = 0;
  j = 0;
  for (int k = p; k <= r; ++k)
  {
    if (left[i] <= right[j]) nums[k] = left[i++];
    else nums[k] = right[j++];
  }
  return;
}

void merge_without_guard(std::vector<int>& nums, int p, int q, int r)
{
  int leftsize = q - p + 1, rightsize = r - q;
  int i, j, k;
  std::vector<int> left(leftsize, 0);
  std::vector<int> right(rightsize, 0);
  for (i = 0; i < leftsize; ++i) left[i] = nums[p+i];
  for (i = 0; i < rightsize; ++i) right[i] = nums[q+1+i];
  i = 0;
  j = 0;
  k = p;
  while (i < leftsize && j < rightsize)
  {
    if (left[i] < right[j]) nums[k++] = left[i++];
    else nums[k++] = right[j++];
  }
  if (i < leftsize)
    for (; i < leftsize; ++i)
      nums[k++] = left[i];
  if (j < rightsize)
    for (; j < rightsize; ++j)
      nums[k++] = right[j];
  return;
}

void _merge_sort(std::vector<int>& nums, int p, int r)
{
  if (p < r)
  {
    int q = (p + r) / 2;
    _merge_sort(nums, p, q);
    _merge_sort(nums, q + 1, r);
    merge_without_guard(nums, p, q, r);
  }
  return;
}
void merge_sort(std::vector<int>& nums)
{
  _merge_sort(nums, 0, nums.size() - 1);
  return;
}

int main()
{
  std::vector<int> nums = {2, 4, 5, 7, 1, 2, 3, 6};
  merge_sort(nums);
  for (int i = 0; i < nums.size(); ++i) std::cout << nums[i] << " ";
}
