#include<stdio.h>
#include<algorithm>
#define MAXN 2050
using namespace std;

struct segY {
	
	struct node {
		int l, r, lc, rc, val, cov;
	} t[MAXN];
	
	int tot;
	
	void build(int p, int l, int r) {
		t[p].l = l;
		t[p].r = r;
		t[p].cov = t[p].val = 0;
		if (l+1 == r){
			t[p].lc = t[p].rc = 0;
			return;
		}
		int mid = (l+r)>>1;
		t[p].lc = ++tot;
		build(t[p].lc, l, mid);
		t[p].rc = ++tot;
		build(t[p].rc, mid, r);
	}
	
	void init(int l, int r) {
		tot = 0;
		build(++tot, l, r);
	}
	
	void modify(int p, int l, int r, int d) {
		t[p].val = max(t[p].val, d);
		if (l <= t[p].l && t[p].r <= r) {
			t[p].cov = max(t[p].cov, d);
			return;
		}
		int mid = (t[p].l+t[p].r)>>1;
		if (l < mid) modify(t[p].lc, l, r, d);
		if (r > mid) modify(t[p].rc, l, r, d);
	}
	
	int query(int p, int l, int r) {
		if (l <= t[p].l && t[p].r <= r) return t[p].val;
		int ans = t[p].cov, mid = (t[p].l+t[p].r)>>1;
		if (l < mid) ans = max(ans, query(t[p].lc, l, r));
		if (r > mid) ans = max(ans, query(t[p].rc, l, r));
		return ans;
	}
	
};

struct segX {
	
	struct node {
		int l, r, lc, rc;
		segY val, cov;
	} t[MAXN];
	
	int tot;
	
	void build(int p, int l, int r, int y) {
		t[p].l = l;
		t[p].r = r;
		t[p].val.init(0, y);
		t[p].cov.init(0, y);
		if (l+1 == r) {
			t[p].lc = t[p].rc = 0;
			return;
		}
		int mid = (l+r)>>1;
		t[p].lc = ++tot;
		build(t[p].lc, l, mid, y);
		t[p].rc = ++tot;
		build(t[p].rc, mid, r, y);
	}
	
	void init(int l, int r, int y) {
		tot = 0;
		build(++tot, l, r, y);
	}
	
	void modify(int p, int l, int r, int y1, int y2, int d) {
		t[p].val.modify(1, y1, y2, d);
		if (l <= t[p].l && t[p].r <= r) {
			t[p].cov.modify(1, y1, y2, d);
			return;
		}
		int mid = (t[p].l+t[p].r)>>1;
		if (l < mid) modify(t[p].lc, l, r, y1, y2, d);
		if (r > mid) modify(t[p].rc, l, r, y1, y2, d);
	}
	
	int query(int p, int l, int r, int y1, int y2) {
		if (l <= t[p].l && t[p].r <= r) return t[p].val.query(1, y1, y2);
		int ans = t[p].cov.query(1, y1, y2), mid = (t[p].l+t[p].r)>>1;
		if (l < mid) ans = max(ans, query(t[p].lc, l, r, y1, y2));
		if (r > mid) ans = max(ans, query(t[p].rc, l, r, y1, y2));
		return ans;
	}
	
} T;
int D, S, N;
int main() {
	scanf("%d%d%d", &D, &S, &N);
	T.init(0, D, S);
	for (int i = 1, d, s, w, x, y; i <= N; ++i) {
		scanf("%d%d%d%d%d", &d, &s, &w, &x, &y);
		int k = T.query(1, x, x+d, y, y+s);
		T.modify(1, x, x+d, y, y+s, k+w);
	}
	printf("%d\n", T.query(1, 0, D, 0, S));
	return 0;
}
