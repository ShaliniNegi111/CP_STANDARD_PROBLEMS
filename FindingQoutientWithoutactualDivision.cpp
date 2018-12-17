// Divide two integers without using multiplication, division and mod operator
// general method

#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;

int main() {
	ll m , n , c(0) , flag (0);
	cin >> m >> n ;
	if ( m < 0 and  n < 0 ) m = abs(m) ,n = abs(n) ;
	if ( m < 0 or n <0 )
	{
		flag = 1 ;
		m = abs(m) ;
		n = abs(n) ;

	}
	while ( m >= n )
	{
		c ++ ;
		m -= n ;
	}
	if ( flag == 0 )
	cout << c;
	else cout << - c ;
	// your code goes here
	return 0;
}
