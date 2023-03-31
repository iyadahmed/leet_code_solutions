// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    enum Direction {
        RIGHT = 0,
        LEFT = 1,
        UP = 2,
        DOWN = 3
    };

    struct Vec {
        int x, y;
    };

    static Vec directionToVec(Direction d) {
        switch (d) {
            case Direction::RIGHT:
                return {0, 1};
            case Direction::DOWN:
                return {1, 0};
            case Direction::LEFT:
                return {0, -1};
            case Direction::UP:
                return {-1, 0};
        }
    }

    static Direction rotate_right(Direction d) {
        switch (d) {
            case Direction::RIGHT:
                return Direction::DOWN;
            case Direction::DOWN:
                return Direction::LEFT;
            case Direction::LEFT:
                return Direction::UP;
            case Direction::UP:
                return Direction::RIGHT;
        }
    }

    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        size_t m = matrix.size();
        size_t n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        size_t num_visited = 0;
        int x = 0, y = 0;
        Direction d = Direction::RIGHT;
        while (num_visited < (m * n)) {
            result.push_back(matrix[x][y]);
            visited[x][y] = true;
            num_visited++;

            {
                auto [dx, dy] = directionToVec(d);

                int next_x = x + dx;
                int next_y = y + dy;

                if (isBorder(next_x, next_y, m, n)) {
                    d = rotate_right(d);
                } else {
                    if (visited[next_x][next_y]) {
                        d = rotate_right(d);
                    }
                }
            }

            auto [dx, dy] = directionToVec(d);
            x = x + dx;
            y = y + dy;
        }

        return result;
    }

    static bool isBorder(int x, int y, int m, int n) {
        return x < 0 || x >= m || y < 0 || y >= n;
    }
};