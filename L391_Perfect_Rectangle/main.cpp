#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Position {
    int x = 0;
    int y = 0;
    int num = 0;
    Position(int x, int y) {
        this->x = x;
        this->y = y;
        this->num += 1;
    }
    bool equal(int x, int y){
        if (this->x == x && this->y == y){
            num += 1;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.empty())
            return false;

        int left = 0;
        int right = 0;
        int top = 0;
        int bottom = 0;

        int area = 0;

        int tmpWide = 0;
        int tmpHigh = 0;
        vector<Position> positions;
        for (int i = 0; i < rectangles.size(); i++){
            left = rectangles[i][0];
            right = rectangles[i][2];
            bottom = rectangles[i][1];
            top = rectangles[i][3];

            bool flag1 = true;
            bool flag2 = true;
            bool flag3 = true;
            bool flag4 = true;
            for (int j = 0; j < positions.size(); ++j) {
                if (positions[j].equal(left, bottom))
                    flag1 = false;
                if (positions[j].equal(left, top))
                    flag2 = false;
                if (positions[j].equal(right, bottom))
                    flag3 = false;
                if (positions[j].equal(right, top))
                    flag4 = false;
            }
            if (flag1)
                positions.push_back(Position(left, bottom));
            if (flag2)
                positions.push_back(Position(left, top));
            if (flag3)
                positions.push_back(Position(right, bottom));
            if (flag4)
                positions.push_back(Position(right, top));

            area += (right - left) * (top - bottom);
        }

        vector<Position> Apos;
        for (int i = 0; i < positions.size(); ++i) {
            if (positions[i].num % 2 != 0)
                Apos.push_back(positions[i]);
        }

        if (Apos.size() != 4)
            return false;

        left = Apos[0].x;
        right = Apos[0].x;
        bottom = Apos[0].y;
        top = Apos[0].y;

        for (int k = 1; k < Apos.size(); ++k) {
            int x = Apos[k].x;
            int y = Apos[k].y;
            if (left > x)
                left = x;
            if (right < x)
                right = x;
            if (bottom > y)
                bottom = y;
            if (top < y)
                top = y;
        }

        if (area == (right - left) * (top - bottom))
            return true;
        else return false;
    }
};

class Solution1 {
    struct hash_pair{
        template <typename T, typename U>
        size_t operator()(const pair<T, U> &p) const {
            size_t l = hash<T>()(p.first), r = hash<U>()(p.second);
            return l + 0x9e3779b9 + (r << 6) + (r >> 2);
        }
    };

public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int left  = INT_MAX, right = INT_MIN, bottom = INT_MAX, top = INT_MIN;
        unordered_map<pair<int, int>, int, hash_pair> points;
        int area = 0;
        vector<pair<int, int>> local = {{0, 1}, {2, 3}, {0, 3}, {2, 1}};
        for (auto r:rectangles) {
            for (auto l:local) {
                if (++points[make_pair(r[l.first], r[l.second])] > 4) return false;
            }
            left = min(left, r[0]);
            right = max(right, r[2]);
            bottom = min(bottom, r[1]);
            top = max(top, r[3]);
            area += (r[2] - r[0]) * (r[3] - r[1]);
        }
        if (area != (right - left) * (top - bottom)) return false;

        unordered_set<pair<int, int>, hash_pair> s = {{left, bottom}, {left, top}, {right, bottom}, {right, top}};
        for (auto it = points.begin(); it != points.end(); it++){
            if (it->second % 2 != 0){
                if (s.count(it->first) > 0){
                    s.erase(it->first);
                } else {
                    return false;
                }
            }
        }

        return s.empty();
    }
};
int main() {
    vector<vector<int>> rectangles = {{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
    std::cout << "Hello, World!" << std::endl;
    Solution1 solution1;
    cout << solution1.isRectangleCover(rectangles) << endl;
    return 0;
}