#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e3+10;

int n,m,k;
int weight[N];
int val[N];
int dp[N];

void run() {
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>weight[i]>>val[i];
	}
	for (int i=1;i<=n;i++) {
		for (int j=weight[i];j<=m;j++) {
			dp[j] = max(dp[j],dp[j-weight[i]]+val[i]);
		}
	}
	cout<<dp[m]<<endl;
}

int main() {
	run();
	return 0;
}
