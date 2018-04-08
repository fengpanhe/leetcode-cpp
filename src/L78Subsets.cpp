#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> indexFlag;  //作为当前子集最后一个元素在nums中的位置

        ans.push_back(vector<int>(0));
        indexFlag.push_back(0);

        int nums_size = nums.size();
        for(int i = 0; i < nums_size; i++){
            vector<int> v;
            v.push_back(nums.at(i));
            ans.push_back(v);
            indexFlag.push_back(i);
        }
        int start = 1, end = ans.size();
        int ss_size = 2;
        for(; ss_size <= nums_size; ss_size++){
            while(start < end){
                for(int i = indexFlag.at(start) + 1; i < nums_size; i++){
                    vector<int> v(ans.at(start));
                    v.push_back(nums.at(i));
                    ans.push_back(v);
                    indexFlag.push_back(i);
                }
                start++;
            }
            end = ans.size();
        }
        return ans;
    }
};


int main(){
    Solution s;
    vector<int> a;
    printf("%d\n", a.size());
}
