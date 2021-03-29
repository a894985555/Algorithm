#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;

//有序表归并
void merge(int a[],int b[],int l,int r) {
    int mid = l+r>>1;
    int L = l,R = mid+1,st=l;
    while (L<=mid && R<=r) {
        if (a[L]<=a[R]) {
            b[st++] = a[L++];
        } else {
            b[st++] = a[R++];
        }
    }
    while (L<=mid) b[st++] = a[L++];
    while (R<=r) b[st++] = a[R++];
    for (int i=l;i<=r;i++) {
        a[i] = b[i];
    }
}

//分治
void sort(int a[],int b[],int l,int r) {
    int mid = l+r>>1;
    if (l>=r) return;
    sort(a,b,l,mid);
    sort(a,b,mid+1,r);
    merge(a,b,l,r);
}

//归并排序接口
void MergeSort(int a[],int len) {
    int b[N]; 
    sort(a,b,1,len);
}


int main() {
    int n,a[N];
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    MergeSort(a,n);
    for (int i=1;i<=n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
