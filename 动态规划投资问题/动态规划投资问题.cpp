#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;

int n,m,x;
int f[N][N],F[N][N];

void run() {
	cin>>n>>m;
	for (int j=0;j<=m;j++) {
		for (int i=1;i<=n;i++) {
			cin>>f[i][j];
		}
	}
    //枚举投资
	for (int i=1;i<=n;i++) {
        //枚举前i个共分配j元
		for (int j=0;j<=m;j++) {
            //枚举第i个投资投资k元
			for (int k=0;k<=j;k++) {
				F[i][j] = max(F[i][j],F[i-1][j-k] + f[i][k]);
			}
		}
	}
	printf("mx = %d\n",F[n][m]);
}

int main() {
	run();
	return 0;
}

/*
4 5
0 0 0 0 
11 0 2 20
12 5 10 21
13 10 30 22
14 15 32 23
15 20 40 24


*/