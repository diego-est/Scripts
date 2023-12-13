#include <bits/stdc++.h>
using namespace std;
typedef size_t sz;
typedef uint64_t Int;
typedef vector<Int> vi;
typedef pair<Int, Int> ii;
typedef vector<pair<Int, Int>> vii;
typedef vector<vector<Int>> vvi;

Int pow_mod(Int a, Int p, Int n)
{
    if (p == 0)
        return 1;
    Int ans = pow_mod(a, p / 2, n);
    ans = (ans * ans) % n;
    if (p % 2 == 1)
        ans = (ans * a) % n;
    return ans;
}

void fastscan(Int &number)
{
    number = 0;
    bool negative = false;
    register int c;
    c = getchar();

    if (c=='-')
        negative = true, c = getchar();

    for (; c>47 && c<58; c=getchar())
        number = number * 10 + c - 48;

    if (negative)
        number *= -1;
}


int main()
{
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/

	/* solution */
	Int num;
	sz ctr = 79465933;
	while (ctr --> 0) {
		fastscan(num);
		printf("%lu\n", num);
	}

	return 0;
}
