//solving painter's problem using DYNAMIC PROGRAMMING
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll sum [ 10000 ] ;
ll dp [ 1000][ 1000 ] ;
ll partition ( ll n , ll k )
{
	// when k = 1 ;
	for ( ll i = 1 ;i <= n ; i ++ )
		dp [ 1 ] [ i ] = sum[ i - 1 ] ;

	// when n = 1 ;
	for ( ll i = 1 ;i<= k ; i ++ )
		dp [ i ] [ 1 ] = sum [ 0 ] ;

	for ( ll i = 2 ; i <= k ; i ++ ) // patition
	{
		for ( ll j = 1 ; j <= n ; j ++ ) // elements
		{
			ll best = INT_MAX;
			for ( ll p = 1 ; p<= j ; p++ )
			best = min ( best , max ( dp [ i - 1 ] [ p ] , sum [ j - 1 ] - sum [ p - 1] ) ) ;
			dp [ i ] [ j  ] = best ;
		}
	}
	return dp [ k ] [ n ] ;
}
int main() {
	ll n , k , a ;
	cin >> n >> k;
	cin>> sum[ 0 ] ;

	for ( ll i = 1 ; i < n ; i ++ )
	 {
	 	cin >> a;
	 	sum [ i ] = sum [ i - 1 ] + a ;
	 }
	 cout << partition ( n , k ) ;
	// your code goes here
	return 0;
}
