#include<stdio.h>
#include<algorithm>
using namespace std;

int D, S, N;

struct segy {
    int v[2048], tag[2048];
    
    void change(int p, int l, int r, int ll, int rr, int d) {
        v[p] = max(v[p], d);
        if (ll <= l && r <= rr) {
            tag[p] = max(tag[p], d);
            return;
        }
        int mid = (l+r)/2;
        if (ll < mid) change(p<<1, l, mid, ll, rr, d);
        if (rr > mid) change(p<<1|1, mid, r, ll, rr, d);
    }
    
    int query(int p, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return v[p];
        }
        int mid = (l+r)>>1, ans = tag[p];
        if (ll < mid) ans = max(ans, query(p<<1, l, mid, ll, rr));
        if (rr > mid) ans = max(ans, query(p<<1|1, mid, r, ll, rr));
        return ans;
    }
};

struct segx {
    segy v[2048], tag[2048];
    
    void change(int p, int l, int r, int ll, int rr, int y1, int y2, int d) {
        v[p].change(1, 1, S, y1, y2, d);
        if (ll <= l && r <= rr) {
            tag[p].change(1, 1, S, y1, y2, d);
            return;
        }
        int mid = (l+r)/2;
        if (ll < mid) change(p<<1, l, mid, ll, rr, y1, y2, d);
        if (rr > mid) change(p<<1|1, mid, r, ll, rr, y1, y2, d);
    }
    
    int query(int p, int l, int r, int ll, int rr, int y1, int y2) {
        if (ll <= l && r <= rr) {
            return v[p].query(1, 1, S, y1, y2);
        }
        int mid = (l+r)>>1, ans = tag[p].query(1, 1, S, y1, y2);
        if (ll < mid) ans = max(ans, query(p<<1, l, mid, ll, rr, y1, y2));
        if (rr > mid) ans = max(ans, query(p<<1|1, mid, r, ll, rr, y1, y2));
        return ans;
    }
} T;

int main() {
    scanf("%d%d%d", &D, &S, &N);
    for (int i = 1, d, s, w, x, y, now; i <= N; ++i) {
        scanf("%d%d%d%d%d", &d, &s, &w, &x, &y);
        int t = T.query(1, 0, D, x, x+d, y, y+s);
        T.change(1, 0, D, x, x+d, y, y+s, t+w);
    }
    printf("%d\n", T.query(1, 0, D, 0, D, 0, S));
    return 0;
}
