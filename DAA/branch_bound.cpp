#include <bits/stdc++.h>
using namespace std;

struct Item
{
	float weight;
	int value;
};


struct Node
{
	int level, profit, bound;
	float weight;
};


bool comparison(Item a, Item b)
{
	double r1 = (double)a.value / a.weight;
	double r2 = (double)b.value / b.weight;
	return r1 > r2;
}


int bound(Node u, int n, int W, Item arr[])
{
	if (u.weight >= W)
	{
       return 0;
	}
	int pro_bound = u.profit;

	int j = u.level + 1;
	int totweight = u.weight;

	while ((j < n) && (totweight + arr[j].weight <= W))
	{
		totweight += arr[j].weight;
		pro_bound += arr[j].value;
		j++;
	}

	if (j < n)
	{
       	pro_bound += (W - totweight) * arr[j].value /
						arr[j].weight;
	}
	return pro_bound;
}


int main()
{
	int W=10;
	Item arr[] = {{1, 50}, {4, 60}, {3, 120}, {6, 90}, {4, 80}};
	int n = sizeof(arr) / sizeof(arr[0]);
    
	sort(arr, arr + n, comparison);
    
	queue<Node> Q;
	Node u, v;
    
	u.level = -1;
	u.profit = u.weight = 0;
	Q.push(u);
    
	int max_pro = 0;
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();

		if (u.level == -1)
			v.level = 0;

		if (u.level == n - 1)
			continue;

		v.level = u.level + 1;

		v.weight = u.weight + arr[v.level].weight;
		v.profit = u.profit + arr[v.level].value;

		if (v.weight <= W && v.profit > max_pro)
			max_pro = v.profit;

		v.bound = bound(v, n, W, arr);

		if (v.bound > max_pro)
			Q.push(v);

		v.weight = u.weight;
		v.profit = u.profit;
		v.bound = bound(v, n, W, arr);
		if (v.bound > max_pro)
			Q.push(v);
	}
	cout << "Maximum possible profit possible = "<< max_pro;

	return 0;
}