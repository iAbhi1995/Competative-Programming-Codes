#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string a[4];
std::string operator+( int b,std::string const &a) {
  std::ostringstream oss;
  oss << a << b;
  return oss.str();
}
void input()
{
	string s;
	cin>>s;int k=0,j=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='.')
		{
			a[j++]=s.substr(k,i);
			k=i+1;
		}
	}
	a[j]=s.substr(k);
}
char check(int n)
{
	char ch;
	if(n>=1&&n<=127)
	ch='A';
	else if(n>=128&&n<=191)
	ch='B';
	else if(n>=192&&n<=223)
	ch='C';
	else if(n>=224&&n<=239)
	ch='D';
	else if(n>=240&&n<=255)
	ch='E';
	else
	{cout<<"Wrong input\n";return ' ';}
	return ch;
}
void Decimal()
{
	for(int i=0;i<4;i++)
	{
		int n=stoi(a[i]);
		if(i==0)
		cout<<"Class is : "<<check(n)<<"\n";
		char b[8];
		for(int k=0;k<8;k++)
		b[k]='0';
		int k=0;
		while(n>0)
		{
			b[k++]=(char)(n%2+48);
			n=n/2;
		}
		for(int j=7;j>=0;j--)
		cout<<b[j];
		if(i<3)
		cout<<".";
	}
}
void Binary()
{
	int n=0;
	for(int i=0;i<4;i++)
	{
		for(int j=7;j>=0;j--)
		{
			n=n+(a[i][j]-48)*(int)pow(2,7-j);
		}
		if(i==0)
		cout<<"Class is : "<<check(n)<<"\n";
		cout<<n;
		if(i<3)
		cout<<".";
		
		n=0;		
	}
	cout<<endl;
}
int main()
{
	int n;
	cout<<"Enter 1.Deimal form input \n2.Binary form input\n";
	cin>>n;
	input();
	if(n==1)
	Decimal();
	else if(n==2)
	Binary();
	else
	cout<<"Invalid choice\n";
	return 0;
}
