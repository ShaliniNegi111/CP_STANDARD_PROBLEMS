/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	static int min ( int x , int y , int z )
	{
		return Math.min ( Math.min ( x , y ) , z ) ;
	}

	public static int edit ( String s1 , String s2 , int n  , int m  )
	{


		int dp [ ] [  ]  = new int [ 1001 ] [ 1001 ];
		for ( int i = 0 ; i <= n   ; i ++ )
		{

			for ( int j = 0 ; j <= m   ; j ++  )
			{
				    if ( i == 0 )
				    	dp [ i ] [ j ] = j  ;
				    else if ( j == 0 )
				    	dp [ i ] [ j ] = i ;
					else if ( s1.charAt ( i - 1 ) == s2.charAt ( j - 1 ) )
						dp [ i ] [ j ] = dp [ i - 1 ] [ j - 1 ] ;
					else
					dp [ i ] [ j ] =1 +  min ( dp [ i - 1 ] [ j ] , dp [ i ] [ j -1 ] , dp [ i - 1 ] [ j -1 ] ) ;


			}
		}

		return dp [ n ] [ m ] ;
	}
	public static void main (String[] args) throws java.lang.Exception
	{

		String s1 , s2 ;
		Scanner in = new Scanner ( System.in ) ;
		s1 = in.next() ;
		s2 = in.next() ;;
		System.out.println ( edit ( s1 , s2 , s1.length() , s2.length() )) ;
	}
}
