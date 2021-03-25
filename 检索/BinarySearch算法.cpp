#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;

int n,m,k;

int binarySearch(int a[],int len,int x) {
    int l = 1, r = len, mid;
    while (l<=r) {
        int mid = l+r>>1;
        if (x == a[mid]) {
            return mid;
        }
        if (x<a[mid]) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return 0;
}


int main() {
    scanf("%d",&n);
    int a[N] = {0};
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    printf("%d\n",binarySearch(a,n,m));
}