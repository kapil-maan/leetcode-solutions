//medium (tough for me)


class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            array<int, 4> di = { 0, 0, 1, -1}, dj = {-1, 1, 0, 0};
            int n = moveTime.size(), m = moveTime[0].size();
            vector<vector<int>> d(n, vector<int>(m, -1));
            set<array<int, 3>> dist;
            d[0][0] = 0;
            dist.insert({0, 0, 0});
            int lastTime = 0;
            while (!dist.empty()) {
                auto fr = *dist.begin();
                dist.erase(dist.begin());
                if (fr[0] > lastTime) {
                    lastTime = fr[0];
                }
                for (int i = 0; i < 4; i++) {
                    int ii = fr[1] + di[i], jj = fr[2] + dj[i];
                    if (!(ii >= 0 && ii < n && jj >= 0 && jj < m)) {
                        continue;
                    }
                    if (d[ii][jj] != -1) {
                        continue;
                    }
                    
                    int time = max(moveTime[ii][jj] + 1, lastTime + 1);
                    d[ii][jj] = time;
                    dist.insert({time, ii, jj});
                }
            }
            return d[n - 1][m - 1];
        }
    };