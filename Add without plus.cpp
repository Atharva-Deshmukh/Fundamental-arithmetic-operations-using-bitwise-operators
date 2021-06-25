/*

Perform addition without using + operator 

Logic is taken from the book

Issue:
Modify it for floating numbers later on

*/

#include<iostream>

using namespace std;

void AddWithoutPlus(int M,int N)
{	
//Addition => (Sum without carry + carry<<1)

	//taking all the corner cases one by one
	if(M==0 && N!=0)
	{
		cout<<"\n"<<N;
	}
	else if(N==0 && M!=0)
	{
		cout<<"\n"<<M;
	}
	else if(M>0 && N>0)
	{
		while(N!=0)
		{
			int sum=(M^N); //getting sum without carry
			int carry=(M&N)<<1;
			M=sum;
			N=carry;
		}
		cout<<"\n"<<M;
	}
	else if(M<0 || N<0)
	{
		cout<<"\nPlz Enter positive numbers ONLY as bitwise operators are usless on negative numbers";
	} 
	//else nhi diya to bhi chalega
}

int main()
{
	//Assuming M and N are 32 bits
	
	int M,N;
	
	cout<<"\nEnter first number M"<<" ";
	cin>>M;
	
	cout<<"\nEnter second number N"<<" ";
	cin>>N;
		
	cout<<"\n\n (M + N) without '+'=> \n";
	
	//calling our function
	AddWithoutPlus(M,N);
		
return 0;	
}
