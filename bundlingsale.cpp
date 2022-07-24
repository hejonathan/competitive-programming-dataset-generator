#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int n, m, w;

int find_root(vector<int>& root, int a){
    if(root[a] == a) return a;
    return root[a] = find_root(root, root[a]);
}

int main(){
    cin>>n>>m>>w;
    vector<int> price(n+1), value(n+1);
    for(int i=1;i<=n;i++)
        cin>>price[i]>>value[i];

    vector<int> root(n+1);
    for(int i=1;i<=n;i++)
        root[i] = i;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        root[find_root(root, b)] = find_root(root, a);
    }
    for(int i=1;i<=n;i++){
        if(find_root(root, i) == i) continue;
        price[find_root(root, i)] += price[i];
        value[find_root(root, i)] += value[i];
        price[i] = 0;
        value[i] = 0;
    }
    vector<int> dp(w+1, 0);
    for(int i=1;i<=n;i++)
        for(int money = w; money>=price[i]; money--)
            dp[money] = max(dp[money], dp[money - price[i]] + value[i]);

    cout << dp[w];
}
