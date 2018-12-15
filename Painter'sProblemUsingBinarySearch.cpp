//painter's problem using binary search ;

#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll arr [ 10000 ] ;
ll n , k ;
bool IsValid ( ll mid  )
{
	ll student = 1 ;
	ll pages = 0 ;
	for( ll i = 0 ; i < n ; i ++ )
	{
		if ( pages + arr [ i ] > mid )
		{
			student ++ ;
			pages = arr [i ] ;
			if ( student > k ) return 0 ;
		}
		else
		{
			pages += arr [ i  ] ;
		}
	}
	return 1 ;

}
ll binary_search ( ll l , ll h )
{
	ll ans = l ;
	while ( l <= h )
	{
		ll mid = l + ( h - l )/ 2 ;
		if ( IsValid ( mid ) )
		{
			ans = mid ;
			h = mid -1 ;
		}
		else	l = mid + 1 ;
	}
	return ans ;
}
int main() {
    ll sum(0) ;
	cin >> n >> k ;
	for ( ll i = 0 ; i < n ; i ++ )
	{
		cin >> arr [ i ] ;
		sum += arr [ i ] ;
	}
	cout << binary_search ( arr [ n -1  ] , sum  ) ;
	return 0;
}
