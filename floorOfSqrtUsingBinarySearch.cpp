// floor of square root of a number

#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll sqrt ( ll n )
{
	ll s = 0 , e = n ;

	while ( (e-s)> 1){

		ll mid = ( s+ e ) / 2 ;
		if ( mid * mid == n ) return mid ;
		if ( mid * mid < n )
			s = mid ;
		else  e = mid ;

	}
	return s ;

}
int main() {
	ll n ;
	cin >> n ;
	cout << sqrt( n ) ;
	return 0;
}
