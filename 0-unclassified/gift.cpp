#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int n, dua = 0, satu = 0;

int main(void)
{
	sf("%d", &n);
	int i;
	FORS(i,n) {
		int x; sf("%d", &x);
		if(x == 100) satu++;
		else dua++;
	}
	
	if((satu + dua*2)%2) { puts("NO"); return 0; }
	if((dua%2 && !satu) || (dua%2 && satu%2)) { puts("NO"); return 0; }
	puts("YES");
	
	return 0;
}
