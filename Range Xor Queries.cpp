#include<bits/stdc++.h>

using namespace std;

// summation
struct segmenttree {
	int n;
	vector<int> st;

	void init(int _n) {
		this->n = _n;
		st.resize(4 * n, -1);
	}

	void build(int start, int ending, int node, vector<int> &v) {
		// leaf node base case
		if (start == ending) 
		{
			st[node] = v[start];
			return;
		}

		int mid = (start + ending) / 2;
		build(start, mid, 2 * node + 1, v);
		build(mid + 1, ending, 2 * node + 2, v);

		if(st[node * 2 + 1] != -1 && st[node * 2 + 2] != -1) st[node] = st[node * 2 + 2]^st[node * 2 + 1];
		else if (st[node * 2 + 1] == -1 && st[node * 2 + 2] != -1) st[node] = st[node * 2 + 2];
		else st[node] = st[node * 2 + 1];
	}

	int query(int start, int ending, int l, int r, int node) {
		if (start > r || ending < l) {
			return -1;
		}
		if (start >= l && ending <= r) 
		{
			return st[node];
		}
		int mid = (start + ending) / 2;
		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, ending, l, r, 2 * node + 2);
		
		if(q1 != -1 && q2 != -1) return (q2^q1);
		else if (q1 == -1 && q2 != -1) return q2;
		else return q1;
	}
	void build(vector<int> &v) 
	{
		build(0, n - 1, 0, v);
	}

	int query(int l, int r) 
	{
		return query(0, n - 1, l, r, 0);
	}
};

int main()
{
	segmenttree tree;
	int n, q;
	vector<int>v;
	cin>>n>>q;
	while(n)
	{
		int a;
		cin>>a;
		v.push_back(a);
		n--;
	}
	tree.init(v.size());
	tree.build(v);
	while(q)
	{
		int a,b;
		cin>>a>>b;
		cout << tree.query(a - 1, b - 1) << '\n';
		q--;
	}
	return 0;
}