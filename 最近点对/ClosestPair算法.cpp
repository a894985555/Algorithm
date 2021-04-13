#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int n,m,k;

struct point {
    double x,y;
}e[N];

int cmpX(point p1,point p2) {
    return p1.x < p2.x;
}

int cmpY(point p1,point p2) {
    return p1.y < p2.y;
}


double dis(point p1,point p2) {
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double getMinDistance(point e[],int l,int r) {
    //如果刚好有两个点
    if (r-l==1) {
        return dis(e[l],e[r]);
    }

    //如果刚好有三个点
    if (r-l==2) {
        return min(dis(e[l],e[l+1]),min(dis(e[l],e[r]),dis(e[l+1],e[r])));
    }

    //如果多于三个点需要分治
    //先根据一维的x坐标进行排序和分治，根据中位数分成左右两部分点
    int mid = l+r>>1;
    
    //得到左右集合最小的距离
    double d = min(getMinDistance(e,l,mid),getMinDistance(e,mid+1,r));

    //有可能两个最短点对分别在左右两个集合还需要进一步讨论
    point p[r-l+1];
    int cnt=0;

    //将中位数旁边[x-d,x+d]范围之内的点都容纳进来
    for (int i=l;i<=r;i++) {
        if (fabs(e[i].x-e[mid].x)<d) {
            p[++cnt] = e[i];
        }
    }
    
    //根据y坐标进行升序排序
    sort(p+1,p+cnt+1,cmpY);

    for (int i=1;i<=cnt;i++) {
        for (int j=i+1;j<=cnt;j++) {
            
            //由于是升序排序,如果当前的点对y坐标差距比d还要大
            //说明接下来的点的距离都要大于d,故break
            if (p[j].y - p[i].y >= d) break;

            //否则可能是最小点对,需要更新一下最小点对距离
            d = min(d,dis(p[i],p[j]));
        }
    }
    return d;
}


void run() {
    while (scanf("%d",&n),n) {
        for (int i=1;i<=n;i++) {
            scanf("%lf %lf",&e[i].x,&e[i].y);
        }
        sort(e+1,e+n+1,cmpX);
        printf("The minimum distance of point pair is = %lf",getMinDistance(e,1,n));
    }
}

int main() {
    run();
    return 0;
}