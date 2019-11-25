#include <stdio.h>
#include <string.h>
int n, m, i, j, k, a, b, x, y, ans, u[200005];
int h[100005], f[100005], v[100005], zhi[100005], ji[100005];
struct AB{
	int a, b, n;
} d[200005];
void charu(int i, int a, int b){
	d[i].a = a, d[i].b = b;
	d[i].n = h[a], h[a] = i;
}
int find(int x){
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}
void dfs(int a, int p){
	int b, i, fa=a;
	//printf("(%d): ", a);
	for(i=h[a]; i; i=d[i].n){
		if(u[i] == 0) u[i] = u[i^1] = 1;
		else continue; //Ë«Ïò 
		b = d[i].b;
		if(b == p) continue; //ÖØ±ß 
		//printf("(%d %d) ", a, b);
		if(v[b] == 0){
			ji[b] = v[b] = v[a] + 1;
			zhi[a]++;
			dfs(b, a);
			if(ji[b] < v[a]){
				if(ji[b] < ji[a]) ji[a] = ji[b];
				//if(a == 13) printf("<<<13-->>>");
				zhi[a]--;
			}
		}
		else if(v[b] < ji[a]) ji[a] = v[b];
	}
	v[a] = -v[a];
	//printf("==> %d %d\n", a, find(a));
	//printf("a=%d du=%d\n", a, zhi[a]);
}
int main(){
	//freopen("suodian.txt", "r", stdin);
	//freopen("suodianout.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d%d", &a, &b);
		if(a == b) continue; //ÎÞ±ß 
		charu(i*2, a, b);
		charu(i*2+1, b, a);
	}
	for(i=1; i<=n; i++) f[i] = i;
	memset(ji, 1, sizeof(ji));
	for(i=1; i<=n; i++){
		if(v[i] == 0){
			v[i] = 1;
			dfs(i, 0);
		}
	}
	for(i=1; i<=n; i++) find(i);
	//printf("==%d %d ==\n", son[5], p[5], );
	//for(i=1; i<=n; i++) c[find(i)]++;
	for(i=1; i<=n; i++){
		if(zhi[i] > 1) ans++;
		else if(zhi[i] == 1 && v[i]!=-1) ans++;
		//else if(zhi[i]==1 && v[i]!=-1 && f[son[i]]!=f[p[i]]) ans++;
		//printf("(%d %d %d)\n", i, zhi[i], h[i]);
	}
	printf("%d\n", ans);
	for(i=1; i<=n; i++){
		if(zhi[i] > 1) printf("%d ", i);
		else if(zhi[i] == 1 && v[i]!=-1) printf("%d ", i);
	}
	return 0;
}
