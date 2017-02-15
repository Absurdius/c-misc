// Sieve of erastofanes
#include <string>
#include <iostream>
#include <istream>

using namespace std; 

int main()
{
	cout << "welcome to Eristophanes sieve. \nEnter an integer to begin.\n";
	//get number from keyboard
	int length; 
	cin >> length;
	// create string
	string primes (length + 1, 'p') ;
	// loop string 
	int p = 2; // current prime
	do{
		for (int i = p+1; i < length; ++i)
		{
			//cout << (i%p);
			if((i%p) == 0)
			{
				primes[i] = 'c'; 
			}
		}
		//find next prime
		p++;
		while (primes[p] != 'p')
		{
			p++;
			if(p > length){break;}
		}
		// prints primes :D cout << p << "\n";
	} while (p < length) ;
	
	// output numbers
	// by looping string and printing 
	cout << "primes are... \n" ; 
	for (int i = 0; i < length; ++i)
		{
			//cout << primes[i];
			//if (i % 20 == 0){cout << "\n";}
			
			
			if(primes[i] == 'p')
			{
				cout << i << "\n"; 
			}
			
		}
}