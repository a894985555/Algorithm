#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;

int n,m,k;
int mp[110][110];


/**
 * 存单向边
 */
void add(int u,int v,int w) {
    mp[u][v] = min(mp[u][v],w);
}


/**
 * floyd算法的本质是dp状态转移，设三维数组mp[k][i][j]
 * k代表可以经过[1,k]区间中的某几个顶点(可以经过也可以不经过其中某个点)
 * i和j分别代表起点和终点，mp[k][i][j]代表能够经过[1,k]区间结点的i结点到j结点的最短距离
 * 对于从i结点到j结点,我们可以选择不经过k结点，也可以选择经过k结点
 * 那么状态转移方程如下：
 * mp[k][i][j] = min(mp[k-1][i][j],mp[k-1][i][k]+mp[k-1][k][j]); 
 * 
 * k循环必须放在最外围，因为k也代表了当前状态的层数
 * 如果k循环放在最里面一层，无法确保状态转移的正确性
 * 例如我们必须先递推完（k=1,mp[k][i][j]）的情况
 * 我们才能通过k=1这层状态,转移到（k=2,mp[k][i][j]）这层状态上
 * 
 * for (int k=1;k<=n;k++) {
 *     for (int i=1;i<=n;i++) {
 *         for (int j=1;j<=n;j++) {
 *             mp[k][i][j] = min(mp[k-1][i][j],mp[k-1][i][k]+mp[k-1][k][j]); 
 *         }
 *     }
 * }
 * 通过滚动数组对第一维进行压缩，就可以得到如下二维的dp数组
 */
void floyd() {
    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                mp[i][j] = min(mp[i][j],mp[i][k]+mp[k][j]);
            }
        }
    }
}
void run() {
	scanf("%d %d",&n,&m);
    int u,v,w;
    memset(mp,0x3f3f3f3f,sizeof mp);
    for (int i=1;i<=m;i++) {
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
    }
	floyd();
    puts("the distance matrix is:");
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            printf("%d ",i==j?0:mp[i][j]);
        }
        puts("");
    }
}

int main() {
    run();
    return 0;
}

/*
4 8
4 1 5
1 4 4
4 3 12
3 4 1
3 1 7
1 3 6
1 2 2
2 3 3
*/
