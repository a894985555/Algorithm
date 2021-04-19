#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int n,m,k;

//找出第k小，就是说有k-1个元素比它小
int FindKthMin(int a[],int l,int r,int k) {
	if (l==r) return a[l];
	int i = l, j = r;

	//选取开头元素取出来然后右左分别插空
	int x = a[i];
	while (i < j) {
		while (i<j && a[j]>=x)j--;
		a[i] = a[j];
		while (i<j && a[i]<=x)i++;
		a[j] = a[i];
	}

	//i作为分割点,i左边元素均比a[i]小,右边元素均比a[i]大
	a[i] = x;

	//计算左区间有多少个
	int num = i-l+1;

	//如果左区间个数少于k个,那么第k小必然在右区间
	if (num < k) return FindKthMin(a,i+1,r,k-num);

	//如果左区间个数大于等于k个,那么第k小必然在左区间
	return FindKthMin(a,l,i,k);
}


void run() {
	cin>>n>>k;
	int a[1000];
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	cout<<FindKthMin(a,1,n,k)<<endl;
}


int main() {
	run();
	return 0;
}