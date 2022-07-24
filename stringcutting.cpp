#include <iostream>
#include <vector>
using namespace std;
bool check(int mid, int k, const vector<int>& lengths) {
   int tot = 0;
   for (auto e: lengths)
       tot += int(e / mid);
   return tot >= k;
}
int main() {
   int n, k;
   cin >> n >> k;
   vector<int> lengths(n);
   for (auto &e: lengths) cin >> e;
   int left = 0, right = 1e9;
   while (left < right) {
       int mid = left + (right - left + 1) / 2;
       if (check(mid, k, lengths)) left = mid;
       else right = mid - 1;
   }
   cout << left << endl;
}