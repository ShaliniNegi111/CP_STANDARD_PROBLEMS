#include<bits/stdc++.h>
using namespace std ;
stack < char > s ;
void Insert ( char x )
{
      if ( s.size() == 0 )
      s.push (  x ) ;
      else
      {
            char c = s.top() ;
            s.pop() ;
            Insert( x ) ;
            s.push ( c ) ;
      }
}
void Reverse ()
{
      if( s.size() > 0 )
      {
            char c = s.top() ;
            s.pop() ;
            Reverse () ;
            Insert ( c ) ;
      }

}
int main()
{

      int n ;
      char x ;
      cout << "ENTER THE NO OF ELEMENT THAT YOU WANT TO INSERT \n";
      cin >> n ;

      for ( int i = 0 ; i < n ; i ++ )
      {
            cout << "ENTER  THE ELEMENT \n" ;
            cin >> x ;
            s.push ( x ) ;
      }
      Reverse ();
      string ans ;
      while ( !s.empty() )
      {
            ans += s.top() ;
            s.pop() ;
      }
      cout << ans ;
}
