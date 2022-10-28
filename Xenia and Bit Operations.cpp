#include<bits/stdc++.h>

using namespace std;
struct segmenttree {
	int n;
	vector<int> st;

	void init(int _n) {
		this->n = _n;
		st.resize(4 * n, 0);
	}
	
	void print()
	{
		for(auto a : st) cout<<a<<' ';
	}
	
	void build(int start, int ending, int node, vector<int> &v, int flag) {
		if (start == ending) {
			st[node] = v[start];
			return;
		}

		int mid = (start + ending) / 2;
		build(start, mid, 2 * node + 1, v, (flag + 1)%2);
		build(mid + 1, ending, 2 * node + 2, v, (flag + 1)%2);

		if(flag == 1)st[node] = (st[node * 2 + 1] | st[node * 2 + 2]);
		else if (flag == 0) st[node] = (st[node * 2 + 1]^st[node * 2 + 2]);
	}

	int query(int start, int ending, int l, int r, int node) {
		return st[node];
	}

	void update(int start, int ending, int node, int index, int value, int flag) {
		// base case
		if (start == ending) {
			st[node] = value;
			return;
		}

		int mid = (start + ending) / 2;
		if (index <= mid) {
			// left subtree
			update(start, mid, 2 * node + 1, index, value, (flag + 1)%2);
		}
		else {
			// right
			update(mid + 1, ending, 2 * node + 2, index, value, (flag + 1)%2);
		}
		
		if(flag == 1)st[node] = (st[node * 2 + 1] | st[node * 2 + 2]);
		else if (flag == 0) st[node] = (st[node * 2 + 1] ^ st[node * 2 + 2]);

		//st[node] = st[node * 2 + 1] + st[node * 2 + 2];

		return;
	}

	void build(vector<int> &v) {
		int a = log2(n + 1);
		if(a%2 == 0) build(0, n - 1, 0, v,0);
		else build(0, n - 1, 0, v,1);
	}

	int query() {
		return query(0, n - 1, 0, n - 1, 0);
	}

	void update(int x, int y) {
		int a = log2(n + 1);
		if(a%2 == 0) update(0, n - 1, 0, x, y,0);
		else update(0, n - 1, 0, x, y,1);
	}
};

int main()
{
	int n, m, a,x, y;
	vector<int> v;
	cin>>n>>m;
	n = pow(2,n);
	
	for(int i = 0; i < n; i++)
	{
		cin>>a;
		v.push_back(a);
	}
	segmenttree tree;
	tree.init(v.size());
	tree.build(v);
	
	for(int i =0;i < m; i++)
	{
		cin>>x>>y;
		tree.update(x - 1, y);
		cout << tree.query() << '\n';
		
	}

	/*vector<int> v = {1, 6, 3, 5};
	segmenttree tree;

	tree.init(v.size());
	tree.build(v);
	cout << tree.query() << '\n';
	tree.print();
	cout<<'\n';

	tree.update(0, 4);
	cout << tree.query() << '\n';
	tree.print();
	cout<<'\n';

	
	tree.update(2, 4);
	cout << tree.query() << '\n';
	tree.print();
	cout<<'\n';

	
	tree.update(0, 2);
	cout << tree.query() << '\n';
	tree.print();
	cout<<'\n';

	
	tree.update(0, 2);
	cout << tree.query() << '\n';
	tree.print();
	cout<<'\n';*/

	
	return 0;
}