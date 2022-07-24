#include <iostream>
#include <vector>
#define ll long long

using namespace std;

bool works(const vector<ll>& have, const vector<pair<ll, pair<ll,ll>>>& rsv, ll mid, ll n) {
   bool pass = true;
   vector<ll> need(n);
   for (ll i = 0; i <= mid; i++) {
       need[rsv[i].second.first] += rsv[i].first;
       if (rsv[i].second.second + 1 < n) need[rsv[i].second.second + 1] -= rsv[i].first;
   }
   ll sum = 0;
   for (ll i = 0; i < n; i++) {
       sum += need[i];
       if (sum > have[i]) pass = false;
   }
   return pass;
}

int main() {
   ll n, m;
   cin >> n >> m;
   vector<pair<ll, pair<ll, ll>>> rsv(m);
   vector<ll> have(n);
   for (auto &e: have) cin >> e;
   for (auto &e: rsv) {
       cin >> e.first >> e.second.first >> e.second.second;
       e.second.first--;
       e.second.second--;
   }
   if (works(have, rsv, m - 1, n)) {
       cout << 0 << endl;
       return 0;
   }
   ll l = 0, r = m - 1;
   while (l < r) {
       ll mid = (l + r) / 2;
       if (works(have, rsv, mid, n)) l = mid + 1;
       else r = mid;
   }
   cout << -1 << endl << l + 1 << endl;
}
