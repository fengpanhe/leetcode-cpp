#include <list>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    if (path.empty())
      return "/";
    char *c_path = new char[strlen(path.c_str()) + 1];
    c_path[strlen(path.c_str())] = '\0';
    strcpy(c_path, path.c_str());

    vector<string> v_res;

    char *temp = strtok(c_path, "/");
    while (temp != NULL) {
      if (strlen(temp) == 1 && temp[0] == '.') {

      } else if (strlen(temp) == 2 && temp[0] == '.' && temp[1] == '.') {
        if (v_res.size() != 0) {
          v_res.pop_back();
        }
      } else {
        v_res.push_back(string(temp));
      }
      temp = strtok(NULL, "/");
    }
    delete[] c_path;

    string res = "/";
    for (int i = 0; i < v_res.size(); i++) {
      res += v_res.at(i);
      if (i != v_res.size() - 1)
        res += "/";
    }
    return res;
  }
};

int main() {
  Solution solution;
  printf("%s\n", solution.simplifyPath("/").c_str());
}