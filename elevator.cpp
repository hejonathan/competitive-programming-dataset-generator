#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
   int n, a, b;
   cin >> n >> a >> b;
   a--;
   b--;
   vector<int> dist(n);
   for (auto &e: dist) cin >> e;
   vector<bool> visited(n, false);
   queue<pair<int, int>> q;
   q.push({a, 0});
   while (!q.empty()) {
       int temp = q.front().first, level = q.front().second;
       q.pop();
       if (temp < 0 or temp >= n) continue;
       if (temp == b) {
           cout << level << endl;
           return 0;
       }
       visited[temp] = true;
       int top = temp + dist[temp], bot = temp - dist[temp];
       if (top < n && !visited[top]) q.push({top, level + 1});
       if (bot >= 0 && !visited[bot]) q.push({bot, level + 1});
   }
   cout << -1 << endl;
   return 0;
}
