#include <bits/stdc++.h>
using namespace std;
void towerOfHanoi( int n , char start , char end , char middle )
{
	if ( n == 1 )
	{
		cout << "MOVING THE DISC FROM " << start << " " << " TO " << end << endl;
		return ;
	}
	towerOfHanoi ( n - 1 , start , middle , end ) ;
	cout << "MOVING THE DISC FROM " << start << " " << " TO " << end << endl;
	towerOfHanoi ( n - 1 , middle , end , start ) ;

}
int main() {

	int n ;
	cin >> n ;
	towerOfHanoi ( n , 'A' , 'C' , 'B' ) ;
	return 0;
}
