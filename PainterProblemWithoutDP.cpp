#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll arr [ 100000 ] ;
ll sum ( ll start , ll end )
{
	ll s(0) ;
	for ( ll i = start ; i <= end ; i ++ )
		s += arr [ i ] ;
	return s ;
}
ll partition ( ll n , ll k )
{
	if ( n == 1 ) return arr [ 0 ] ; // base case ;
	if ( k == 1 ) return sum ( 0 , n-1 ) ; // base case 2 ;
	ll best = INT_MAX ;
	for ( ll i = 1 ; i <= n ; i ++ )
	best= min ( best , max ( partition( i , k - 1 ) , sum ( i , n-1  ) ) ) ;
	return best;
}
int main() {
	ll n , k ;
	cin >> n >> k ;
	for ( ll i = 0 ; i <n ; i ++ )	cin >> arr [ i ] ;
	cout << partition ( n ,k ) ;
	return 0;
}
