#include <vector>
#include <iostream>
#include <limits>
#include <initializer_list>

struct Res
{
 public:
  int low;
  int high;
  int sum;
  Res(int low_, int high_, int sum_):low(low_), high(high_), sum(sum_) {}

};

Res max_crossing_array(const std::vector<int>& nums, int p, int q, int r)
{
  int tmp, left_sum, right_sum, a, low, high;
  left_sum = std::numeric_limits<int>::min();
  tmp = 0;
  for (a = q; a >= p; --a)
  {
    tmp += nums[a];
    if (tmp > left_sum)
    {
      left_sum = tmp;
      low = a;
    }
  }
  tmp = 0;
  right_sum = std::numeric_limits<int>::min();
  for (a =  q + 1; a <= r; ++a) 
  {
    tmp += nums[a];
    if (tmp > right_sum) 
    {
      right_sum = tmp;
      high = a;
    }
  }

  return Res(low, high, left_sum+right_sum);
}

Res max_subarray(const std::vector<int>& nums, int p, int r)
{
  if (p == r)
    return Res(p, r, nums[p]);
  int q = (p + r) / 2;
  struct Res left = max_subarray(nums, p, q);
  struct Res right = max_subarray(nums, q+1, r);
  struct Res cross = max_crossing_array(nums, p, q, r);
  if (left.sum >= right.sum && left.sum >= cross.sum)
    return left;
  else if (right.sum > left.sum && right.sum >= cross.sum)
    return right;
  else
    return cross;
}

Res max_subarray_liner(const std::vector<int>& nums)
{
  int low, high, a, low_tmp = 0;
  int tmp_sum = 0, sum = std::numeric_limits<int>::min();
  for (a = 0; a < nums.size(); ++a)
  {
    tmp_sum += nums[a];
    if (tmp_sum > sum)
    {
      low = low_tmp;
      high = a;
      sum = tmp_sum;
    }
    if (tmp_sum <= 0)
    {
      low_tmp = a + 1;
      tmp_sum = 0;
    }
  }
  return Res(low, high, sum);
}



int main()
{
  std::vector<int> nums = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
  Res res = max_subarray_liner(nums);
  std::cout << res.low << ' ' << res.high << ' ' << res.sum << std::endl;
}
