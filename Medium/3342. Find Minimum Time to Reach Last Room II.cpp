//medium

#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;

        // (time, x, y, parity)
        pq.emplace(0, 0, 0, 0);
        dist[0][0][0] = 0;

        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!pq.empty()) {
            auto [time, x, y, parity] = pq.top(); pq.pop();
            if (x == n - 1 && y == m - 1) return time;

            if (time > dist[x][y][parity]) continue;

            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                int moveCost = (parity == 0 ? 1 : 2);
                int startTime = max(time, moveTime[nx][ny]);
                int arrivalTime = startTime + moveCost;

                if (arrivalTime < dist[nx][ny][parity ^ 1]) {
                    dist[nx][ny][parity ^ 1] = arrivalTime;
                    pq.emplace(arrivalTime, nx, ny, parity ^ 1);
                }
            }
        }
        return -1; // unreachable
    }
};
