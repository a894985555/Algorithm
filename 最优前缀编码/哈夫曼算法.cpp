#include<bits/stdc++.h>
const int N = 1e3+10;
using namespace std;



struct node {
	int val,id;
	bool friend operator<(const node &x,const node &y) {
		//按照键值降序排序
		if (x.val!=y.val) return x.val>y.val;
		return x.id>y.id;
	}
};

struct tree {
	int l,r,val;
}t[N];

string s;
priority_queue<node>q;
int n,m,k;
int fa[N];
string HafCode[N];

/**
 * 从叶子节点开始跳到祖先节点
 */
void getHafCode() {
	for (int i=1;i<=n;i++) {
		string c;
		int j = i;
		while (fa[j]) {
			c = (j==t[fa[j]].l?'0':'1')+c;
			j = fa[j];
		}
		HafCode[i] = c;
	}
}

void Haf() {
	/**
	 * 哈夫曼算法最多执行n-1次
	 */
	for (int i=1;i<n;i++) {
		//每次从堆中取出2个值最小的节点
		node a = q.top();
		q.pop();
		node b = q.top();
		q.pop();

		int id = i+n;
		int val = a.val+b.val;

		//建立树结构
		t[id].l = a.id;
		t[id].r = b.id;
		t[id].val = val;
		fa[a.id] = id;
		fa[b.id] = id;
		q.push({val,id});
	}
	getHafCode();
}

void run() {
	cin>>s;
	n = s.length();
	for (int i=1;i<=n;i++) {
		int val;
		cin>>val;
		q.push({val,i});
	}
	Haf();
	for (int i=1;i<=n;i++) {
		cout<<s[i-1]<<":";
		cout<<HafCode[i]<<endl;
	}
}

int main() {
	run();
	return 0;
}