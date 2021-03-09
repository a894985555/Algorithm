#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;


/**
 * 存无向图的边 + 按边权升序排序
 */
struct node {
	int u,v,w;
	bool friend operator<(const node &x, const node &y) {
		return x.w < y.w;
	}
}e[N];

int n,m,k;
int fa[N];
vector<node>res;

/**
 * 并查集
 * 用于判断两个点是否存在一个集合中
 */
int get(int x) {
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}

void Kruskal() {
	int sum = 0;
	int tot = 0;
    for (int i=1;i<=m;i++) {
		int u = e[i].u;
		int v = e[i].v;
		int w = e[i].w;

		/**
		 * 判断两个点是否已经处于一个集合中
		 * 如果相同,则跳过当前这条边,防止出现环
		 */
		int x = get(u);
		int y = get(v);
		if (x == y) continue;


		/**
		 * 如果两个点不在一个集合中
		 * 则将它们合并成一个集合,并选取当前这条边
		 */
		fa[x] = y;
		tot += w;
		sum++;
		res.push_back({u,v,w});
		if (sum == n-1) break;
	}
	if (sum != n-1) {
		puts("MST is not existed");
		return;
	}

	printf("MST is existed and total weight = %d\n",tot);
	puts("follwing the edges:");
	for (auto g:res) {
		printf("V%d->V%d Weight = %d\n",g.u,g.v,g.w);
	}
}

void run() {
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) {
		fa[i] = i;
	}
	for (int i=1;i<=m;i++) {
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+m+1);
	Kruskal();
}

int main() {
    run();
    return 0;
}