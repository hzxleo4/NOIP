#include<stdio.h>
#include<iostream>
using namespace std;

struct AB {
	int d, i;
	
	bool operator < (const AB &A) const {
		if (d != A.d) return d < A.d;
		return i < A.i;
	}
};

struct tree {
	int l, r, d;
	AB k;
} t[100000+10];

int n, m, p[100000+10], del[100000+10];

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

int merge(int x, int y) {
	if (!x) return y;
	if (!y) return x;
	if (t[y].k < t[x].k) swap(x, y);
	t[x].r = merge(t[x].r, y);
	if (t[t[x].r].d > t[t[x].l].d) swap(t[x].l, t[x].r);
	t[x].d = t[x].r ? t[t[x].r].d+1 : 0;
	return x;
}

int remove(int x) {
	return merge(t[x].l, t[x].r);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t[i].k.d);
		p[i] = t[i].k.i = i;
	}
	for (int i = 1, o, x, y, id; i <= m; ++i) {
		scanf("%d%d", &o, &x);
		if (o == 1) {
			scanf("%d", &y);
			if (del[x] || del[y]) continue;
			x = find(x);
			y = find(y);
			if (x == y) continue;
			id = merge(x, y);
			p[id] = p[x] = p[y] = id;
		} else {
			if (del[x]) {
				printf("-1\n");
				continue;
			}
			x = find(x);
			printf("%d\n", t[x].k.d);
			id = remove(x);
			p[id] = p[x] = id;
			del[x] = 1;
		}
	}
	return 0;
}
