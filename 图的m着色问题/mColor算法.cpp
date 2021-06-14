#include<bits/stdc++.h>
const int N = 1e3+10;
using namespace std;

int n,m,k;
int mp[N][N],col[N];
int tot;

int check(int u) {
	for (int i=1;i<=n;i++) {
		if (!mp[u][i]) continue;
		if (col[i] == col[u]) return 0;
	}
	return 1;
}

void mColor(int cur) {
	if (cur>n) {
		tot++;
		for (int i=1;i<=n;i++) {
			cout<<col[i]<<" ";
		}
		cout<<endl;
		return;
	}
	//枚举颜色
	for (int i=1;i<=m;i++) {
		col[cur] = i;
		if (check(cur)) {
			mColor(cur+1);
		}
		col[cur] = 0;
	}
}

void run() {
	cin>>n>>m;
	int a,b;
	while (cin>>a>>b) {
		if (!a && !b) break;
		mp[a][b]=mp[b][a]=1;
	}
	mColor(1);
	if (tot) {
		cout<<"total = "<<tot<<endl;
	} else {
		cout<<"NO"<<endl;
	}
}

int main() {
	run();
	return 0;
}

/*
5 4
1 3
1 2
1 4
2 3
2 4
2 5
3 4
4 5
0 0
*/