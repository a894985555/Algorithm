#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e3+10;

int n,m,x;
vector<int>p;
int dp[N][N],sep[N][N];

//矩阵链乘法
void matrixChain() {
	//枚举区间长度
	for (int d=1;d<=n;d++) {
		//枚举区间左端点
		for (int i=1;i<=n-d;i++) {
			//区间右端点
			int j=i+d;
			//枚举区间分割点
			for (int k=i;k<j;k++) {
				//p[i-1]代表Ai的行数,p[k]代表Ak的的列数，p[j]代表Aj的列数
				int temp = dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
				if (dp[i][j] > temp) {
					dp[i][j] = temp;
					sep[i][j] = k;
				}
			}
		}
	}
	cout<<dp[1][n]<<endl;
}

//输出矩阵链乘法的方案
void printChain(int l,int r) {
	if (l==r) {
		cout<<"A"<<l;
		return;
	}
	cout<<"(";
	printChain(l,sep[l][r]);
	printChain(sep[l][r]+1,r);
	cout<<")";
}

void run() {
	memset(dp,inf,sizeof dp);
	cin>>n;
	for (int i=0;i<=n;i++) {
		cin>>m;
		p.push_back(m);
		dp[i][i] = 0;
	}
	matrixChain();
	printChain(1,n);
}

int main() {
	run();
	return 0;
}

/*
6
30 35 15 5 10 20 25
*/