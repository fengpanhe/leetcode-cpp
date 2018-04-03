#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  void sortColors(vector<int> &nums) {
    int num_count[3] = {0, 0, 0};
    for (auto num : nums) {
      num_count[num]++;
    }
    int index = 0;
    while (num_count[0] > 0) {
      nums[index++] = 0;
      num_count[0]--;
    }
    while (num_count[1] > 0) {
      nums[index++] = 1;
      num_count[1]--;
    }
    while (num_count[2] > 0) {
      nums[index++] = 2;
      num_count[2]--;
    }
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}