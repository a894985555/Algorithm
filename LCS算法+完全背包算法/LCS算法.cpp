#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e3+10;

char a[N],b[N];
int dp[N][N];


//输出LCS方案
void print(int l,int r) {
    if (l<=0 || r<=0) return;
    if (a[l] == b[r]) {
        print(l-1,r-1);
        cout<<a[l];
    } else if (dp[l-1][r]>dp[l][r-1]) {
        print(l-1,r);
    } else {
        print(l,r-1);
    }
}

void run() {
	cin>>a+1>>b+1;
	int lena = strlen(a+1);
	int lenb = strlen(b+1);
	for (int i=1;i<=lena;i++) {
		for (int j=1;j<=lenb;j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[lena][lenb]<<endl;
    print(lena,lenb);
}

int main() {
	run();
	return 0;
}
