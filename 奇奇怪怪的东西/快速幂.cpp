#include<cstdio>
using namespace std;
long long b,p,k;
//������ö��1��λ�ã�ֱ�ӳ�2��x�η� 
void poww(long long b,long long p,long long k){
    long long t = 1,base = b,pp = p;
    while(p){
        if(p&1)
            t *= base,t %= k;
        p >>=1;
        base *= base;
        base %= k;
    }
    printf("%lld^%lld mod %lld=%lld",b,pp,k,t);
}
int main(){
    scanf("%lld%lld%lld",&b,&p,&k);//b^p mod k
    poww(b,p,k);
    return 0;
}
