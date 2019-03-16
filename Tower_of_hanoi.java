import java.util.*;

import java.lang.*;

import java.io.*;


class GFG 
{
    
    
	public static void Tower_of_Hanoi ( int n , char start , char end  , char middle  ) 
  
 	 {
        
		if ( n == 1 )
    
    		{
            
				System.out.println ( "move disk " + n + " from rod " +  start + " to rod " + end );
           
 				return ;
       
	                  }
  
      		Tower_of_Hanoi ( n - 1 , start , middle , end ) ;
 
		System.out.println ( "move disk " + n + " from rod " +  start +  " to rod " +  end );
       
 		Tower_of_Hanoi ( n - 1 , middle , end , start ) ;
        
    
	}
	
		public static void main (String[] args) 
		{
	    
	    
	    
			int t  ; // t = no of test case  
	    
			Scanner in = new Scanner ( System.in ) ;
	   
			 t = in.nextInt() ; 
	    
		 	while ( t --  > 0 )
	    
			{
	       
				 int n ;// n = no of disc

	       			 n = in.nextInt() ; 
	       
 				Tower_of_Hanoi ( n , '1' , '3' , '2' ) ;
	        
				System.out.println ( ( int) Math.pow ( 2 ,  n ) - 1 )  ;
	   
 			}
		
	
		}

	
}