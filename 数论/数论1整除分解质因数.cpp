#include<cstdio>
using namespace std;
int n,k,e[10005],d[10005],c,b,a;
int main(){
    scanf("%d %d",&n,&k);
    //整除到e[]数组中 
    for(int i=2;i<=n/i;++i)
        if(n % i == 0)		e[++c] = i;
    if(e[c] * e[c] == n);
    else	e[c+1] = n/e[c];
    for(int i=c-1;i>=1;--i)
        e[2*c-i] = n / e[i];
    //分解质因数到e[]数组中 
    for(int i=2;i<=n/i;++i){
        if(n % i == 0)
            e[++c] = i;//质数 
            while(n % i == 0){
                d[c]++;//质数的个数 
                n /= i;
            }
    }
    if(n > 1)	e[++c] = n;	d[c] = 1;
    return 0;
}
