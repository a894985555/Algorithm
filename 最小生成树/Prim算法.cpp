#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3+10;

struct node {
	int u,v,w;
};

int n,m,k;
int mp[N][N];
int dis[N];
pair<int,int>fa[N];
int sum;
vector<node>res;

/**
 * 建图
 */
void add(int u,int v,int w) {
	mp[u][v] = mp[v][u] = min(mp[u][v],w);
}

/**
 * 松弛操作是为了在稠密图的情况下降低时间复杂度
 * 如果为了找出边权最小的边而直接遍历
 * 当前集合中的点连接所有的边,总时间复杂度会是O(n*(n+m))
 * 所以我们要在寻找最小边权的同时处理dis数组
 * 总时间复杂度就会变成O(n*(n+n));
 * dis[i]数组代表当前集合中的某点到i点的最短距离
 */
void slack(int u) {
	for (int v=1;v<=n;v++) {
		int w = mp[u][v];
		if (dis[v] == -1) continue;
		if (w < dis[v]) {
			dis[v] = w;
			fa[v] = {u,w};
		}
	}
}


/**
 * 遍历集合中的点
 * 找出集合中点的边权最小的边连接的那个点加入集合
 * 如果这条边连接的点已经是集合中的点则跳过
 */
void Prim() {
	dis[1] = 0;
	for (int i=1;i<=n;i++) {
		int idx,mi = 1e9;
		for (int j=1;j<=n;j++) {
			if (dis[j] == -1) continue;
			if (dis[j] < mi) {
				idx = j;
				mi = dis[j];
			}
		}
		if (mi==1e9) {
			puts("MST is not existed");
			return;
		}
		sum += mi;
		dis[idx] = -1;
		slack(idx);
	}

	printf("MST is existed and total weight = %d\n",sum);
	puts("follwing the edges:");
	for (int i=1;i<=n;i++) {
		if (fa[i].first==i) continue;
		printf("V%d->V%d Weight = %d\n",fa[i].first,i,fa[i].second);
	}
}

void run() {
	scanf("%d %d",&n,&m);
	int u,v,w;

    /**
     * 预处理数据
     */
	for (int i=1;i<=n;i++) {
		dis[i] = 1e9;
		fa[i].first = i;
		for (int j=i;j<=n;j++) {
			mp[i][j] = mp[j][i] = 1e9;
		}
	}
	for (int i=1;i<=m;i++) {
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
	}
	Prim();
}

int main() {
    run();
    return 0;
}