// segment tree


#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll arr [ 10000 ] , seg_arr [ 100000 ] ;
void construct ( ll node , ll q_s , ll q_e )
{
	if ( q_s == q_e )
	{
		seg_arr [ node ] = arr [ q_s ] ;
		return ;
	}
	ll mid = ( q_s + q_e) / 2 ;
	construct ( 2 * node + 1  , q_s , mid ) ;
	construct ( 2 * node + 2  , mid+ 1 , q_e ) ;
	seg_arr [ node ] = seg_arr [ 2 * node + 1 ] +seg_arr [ 2 * node + 2 ] ;
}
void update ( ll node , ll q_s , ll q_e  , ll val , ll ind )
{
	if ( ind < q_s and ind > q_e )
		return ;
	seg_arr [ node ] += val ;
	if ( q_s !=q_e )
	{
	ll mid = ( q_s + q_e) / 2 ;
	update ( 2 * node + 1  , q_s , mid , val , ind ) ;
	update ( 2 * node + 2  , mid+ 1 , q_e , val , ind ) ;
	}
}

ll  query ( ll node , ll q_s , ll q_e  ,ll l , ll r )
{
	if ( q_s >= l and q_e <= r ) return seg_arr [ node ] ;
	if ( q_e < l or q_s > r ) return 0 ;

	ll mid = ( q_s + q_e) / 2 ;
	return ( query ( 2 * node + 1  , q_s , mid , l , r )+
								query( 2 * node + 2  , mid + 1 , q_e , l  , r ) );
}
int main() {
	ll n , q , x ;
	cin >> n >> q ;
	for ( ll i = 0 ; i < n ; i ++ ) cin >> arr [ i ] ;
	construct ( 0  , 0  , n - 1  ) ;
    //for ( ll i = 0 ; i <2 * n - 1  ; i++ ) cout << seg_arr [ i ] << " " ;
    //cout << endl ;
	while (  q-- )
	{
		ll x;
		cin >> x;
		if ( x  ) //update
		{
			ll ind , val ;
			cin >> ind >> val ;
			ll diff  = val - arr [ ind ] ;
			arr [ ind ] = val ;
			update ( 0 , 0 , n - 1  , diff  ,  ind ) ;
		}
		else  // range query
		{
			ll l , r ;
			cin >> l >> r ;
			cout << query ( 0  , 0  , n - 1 ,  l ,  r ) << endl ;
		}

	}
	// your code goes here
	return 0;
}
