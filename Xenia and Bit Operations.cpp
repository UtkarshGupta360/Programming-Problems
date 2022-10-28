//Problem Link: https://codeforces.com/problemset/problem/339/D

/*
Xenia the beginner programmer has a sequence a, consisting of 2n non-negative integers: a1, a2, ..., a2n. Xenia is currently studying bit operations. 
To better understand how they work, Xenia decided to calculate some value v for a.

Namely, it takes several iterations to calculate value v. At the first iteration, Xenia writes a new sequence a1 or a2, a3 or a4, ..., a2n - 1 or a2n, 
consisting of 2n - 1 elements. In other words, she writes down the bit-wise OR of adjacent elements of sequence a. 
At the second iteration, Xenia writes the bitwise exclusive OR of adjacent elements of the sequence obtained after the first iteration. 
At the third iteration Xenia writes the bitwise OR of the adjacent elements of the sequence obtained after the second iteration. 
And so on; the operations of bitwise exclusive OR and bitwise OR alternate. In the end, she obtains a sequence consisting of one element, and that element is v.

Let's consider an example. Suppose that sequence a = (1, 2, 3, 4). 
Then let's write down all the transformations (1, 2, 3, 4)  →  (1 or 2 = 3, 3 or 4 = 7)  →  (3 xor 7 = 4). The result is v = 4.

You are given Xenia's initial sequence. But to calculate value v for a given sequence would be too easy, so you are given additional m queries. 
Each query is a pair of integers p, b. Query p, b means that you need to perform the assignment ap = b. After each query, you need to print the new value v for the new sequence a.

Input
The first line contains two integers n and m (1 ≤ n ≤ 17, 1 ≤ m ≤ 105). The next line contains 2n integers a1, a2, ..., a2n (0 ≤ ai < 230). 
Each of the next m lines contains queries. The i-th line contains integers pi, bi (1 ≤ pi ≤ 2n, 0 ≤ bi < 230) — the i-th query.

Output
Print m integers — the i-th integer denotes value v for sequence a after the i-th query.

Examples
input
2 4
1 6 3 5
1 4
3 4
1 2
1 2
output
1
3
3
3

*/

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
