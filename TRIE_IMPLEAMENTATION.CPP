#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
struct node {

	node * parent ;
	node *children [ 26 ] ;
	vector < ll > occurence ;
} ;
void construct ( node * root , string s , ll ind )
{
	ll i (0) ;
	node * temp = root ;
	while ( s [ i ] != '\0')
	{
		if ( temp -> children [ s [ i ] -'a' ] == NULL )
		{
			node * child = new node ;
			child ->parent = temp ;
			temp -> children [ s [ i ] - 'a' ] = child ;
			temp = child ;
		}
		else temp = temp->children [ s [ i ] -'a' ] ;
		i ++ ;
	}
	temp -> occurence.push_back ( ind ) ;
}
void laxographic ( node *  root , vector < char > v )
{

	for ( ll i = 0 ; i < 26 ; i ++ )
	{
		if ( root -> children [ i ] == NULL ) continue ;
		else
		{
			v.push_back ( 'a' + i );
			laxographic ( root-> children [ i ] , v ) ;
			v.pop_back () ;
			//cout << endl ;
		}
	}

	if  ( root -> occurence .size() != 0 )
		for ( ll i = 0 ; i < v.size() ; i ++ ) cout << v [ i ] ;
    cout<< endl ;
	v.pop_back () ;
}

node * search ( node * root , string s )
{
	ll i (0) ;
	node * temp = root ;
	while ( s [ i ] != '\0' )
	{
		if ( temp ->children [ s [ i ] - 'a' ] == NULL ) break ;
		else
			temp = temp -> children [ s[ i ] - 'a'] ;
		i ++ ;
	}
	if ( s [ i ] == '\0' and temp ->occurence  .size() != 0 ) return temp ;
	else return NULL ;
}
void remove ( node * root , string s )
{
	node * temp = search ( root , s ) ;
	if  ( temp == NULL ) return ;
	temp->occurence .pop_back () ;
	ll child(0) ;
    for ( ll i =0 ; i < 26 ; i ++ )
	     if ( temp ->children [ i ] != NULL ) child++ ;

    if ( child != 0 ) return;
    node * parent ;
    	while ( temp -> occurence.size() == 0 and child == 0 and temp->parent != NULL )
    	{
    		child = 0 ;
    		parent = temp -> parent ;
    		for ( ll i =0 ; i < 26 ; i ++ )
    		{
    			if ( temp ->children [ i ] == temp  )
    			{
    				parent -> children [ i ] == NULL;
    				free ( temp ) ;
    				temp = parent ;
    			}
    			else child ++ ;
    		}
    	}

}
int main() {
	ll n ;
	cin >> n ;
	string s ;
	node * root = new node ;
	for ( ll i = 0 ; i< n ; i ++ )
	{
		cin >> s ;
		construct ( root , s  , i + 1 ) ;
	}
	vector < char > v ;
	laxographic ( root  , v ) ;
	cout << endl ;
	cin >> s ;
	remove (  root , s ) ;
	laxographic ( root  , v ) ;
	cout << endl ;
	return 0;
}
