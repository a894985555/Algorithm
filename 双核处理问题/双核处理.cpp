#include<bits/stdc++.h>
const int N = 1e4+10;
using namespace std;

int n;				//n个任务
int t[N];			//加工时间ti
int tot;			//Σti
int dp[N];			//dp矩阵
int choose[N][N];	//记录某个dp状态选择了哪项任务
int id[N];			//标记第一台机器选择的任务ID


/**
 * 输出任务方案过程：
 */
void print() {
	int i = n;
	int now = tot/2;

	//由于直接输出时任务ID是倒叙的,所以用vector存储,方便排序
	vector<int>v;

	//从dp矩阵自底向上递推回初始状态,得到任务方案
	while (now && i) {
		if (!choose[i][now]) {
			i--;
			continue;
		}
		v.push_back(choose[i][now]);
		id[choose[i][now]] = 1;
		now -= t[i];
		i--;
	}

	cout<<"The first machine choose: ";
	sort(v.begin(),v.end());
	for (auto i:v) {
		cout<<"t"<<i<<" ";
	}
	cout<<", time = "<<dp[tot/2]<<endl;
	cout<<"The second machine choose: ";
	for (int i=1;i<=n;i++) {
		if (id[i]) continue;
		cout<<"t"<<i<<" ";
	}
	cout<<", time = "<<(tot-dp[tot/2])<<endl;

	cout<<"Therefore the total process time = "<<max(dp[tot/2],tot-dp[tot/2])<<endl;
}

void run() {
	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>t[i];
		tot += t[i];
	}

	//01背包过程,这里使用滚动数组压缩了dp维数

	//枚举可选任务
	for (int i=1;i<=n;i++) {

		//枚举背包容量,最大背包空间为Σti的一半
		for (int j=tot/2;j>=t[i];j--) {

			//如果当前取的状态优于不取的状态，则取这个任务，并记录任务id
			if (dp[j-t[i]]+t[i]>dp[j]) {
				dp[j] = dp[j-t[i]]+t[i];
				choose[i][j] = i;
			}
		}
	}
	
	print();
}

int main() {
	run();
	return 0;
}

/*
INPUT:
5
1 5 2 10 3
*/