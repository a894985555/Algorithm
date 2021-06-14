#include<bits/stdc++.h>
const int N = 1e3+10;
using namespace std;

int n,m,k;
int w[N];
int dp[N],pre[N][N];


/**
 * 打印装载方案
 */
void print() {
	cout<<"\nthe max box num is: "<<dp[m]<<endl;
	cout<<"\nand the choice is following(the id of box):"<<endl;
	int now = m;
	int i = n;
	while (now && i) {
		if (pre[i][now]) {
			cout<<pre[i][now]<<endl;
		} else {
			i--;
			continue;
		}
		now -= w[pre[i][now]];
		i--;
	}
}


/**
 * 装载问题01背包
 */
void run() {
	puts("Input the number of box and loading weight:");
	cin>>n>>m;
	puts("Input the each weight of box");
	for (int i=1;i<=n;i++) {
		cin>>w[i];
	}

	for (int i=1;i<=n;i++) {
		for (int j=m;j>=w[i];j--) {
			if (dp[j-w[i]]+1>dp[j]) {
				dp[j] = dp[j-w[i]]+1;
				pre[i][j] = i;
			}
		}
	}
	print();
}

int main() {
	run();
	return 0;
}