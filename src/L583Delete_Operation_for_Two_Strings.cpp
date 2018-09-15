#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {

    int w1_len = word1.size(), w2_len = word2.size();
    if (w1_len == 0)
      return w2_len;
    if (w2_len == 0)
      return w1_len;
    int dp[500][500] = {0};
    if (word1.at(0) == word2.at(0))
      dp[0][0] = 1;
    for (int i = 1; i < w2_len; i++) {
      if (word1.at(0) == word2.at(i)) {
        dp[0][i] = 1;
      } else {
        dp[0][i] = dp[0][i - 1];
      }
    }

    for (int i = 1; i < w1_len; i++) {
      if (word1.at(i) == word2.at(0)) {
        dp[i][0] = 1;
      } else {
        dp[i][0] = dp[i - 1][0];
      }
      for (int j = 1; j < w2_len; j++) {
        if (word1.at(i) == word2.at(j)) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return w1_len + w2_len - 2 * dp[w1_len - 1][w2_len - 1];
  }
};

int main() {
  Solution solution;
  printf("num: %d\n", solution.minDistance("a", "b"));
}