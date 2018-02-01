#include<stdio.h>
int main()
{
    int c=getchar(),last;int x=0;int z=1;
	while(c!=EOF)
    {
      if(z==1)
      {
        z=0;
        last=c;
    	c=getchar();
        continue;
      }
      printf("Abhi\n");
      if(((last>='a' && last<='z') || (last>='A' && last<='Z'))&&!((c>='a' && c<='z') || (c>='A' && c<='Z')))
        x++;
    c=getchar();
	}
	printf("%d",x);
	return 0;
}


/*#include <iostream>
using namespace std;
class Complex {
    public: double *re, *im;
    
    Complex(double r,double m) {
  
       re = new double(r); 
       im = new double(m);   
       cout<<"Constructor called";
    }
     Complex(Complex &t){
        re = new double; im = new double; 
       *re =*t.re;  *im=*t.im; 
   }
    
}; 
int main() {

    double x, y, z;
    
    cin >> x >> y  >> z;
    Complex n1(x,y);
    cout << *n1.re << "+" << *n1.im << "i ";
    Complex n2 = n1;
    cout << *n2.re << "+" << *n2.im << "i ";
    *n1.im = z;
    cout << *n2.re << "+" << *n2.im << "i ";
    cout << *n1.re << "+" << *n1.im << "i ";
    return 0;
}*/
