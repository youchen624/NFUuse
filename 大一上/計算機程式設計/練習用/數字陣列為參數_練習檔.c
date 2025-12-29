#include <stdio.h>
#include <stdlib.h>

double total(double a[],int n);
double average(double a[],int n);
double maximal(double a[],int n);
void copy1(double b[],double a[],int n);

void reverse (double a[],int n);
int main()
{double array[8]={1.1,3.3,5.5,7.7,8.8,6.6,2.2,4.4};
  int i;
double array2[8];

 printf("陣列值和為%.2lf:\n",total(array,8));
 printf("陣列值平均為%.2lf\n",average(array,8));
 printf("陣列最大值為%.2lf\n",maximal(array,8));
 
 copy1(array2,array,8);
 printf("array2陣列內值為:");
  for(i=0;i<8;i++)
   printf("%.2lf ",array2[i]);  
 
 reverse(array2,8);
printf("\n經倒轉後, array2陣列內值為:");
  for(i=0;i<8;i++)
   printf("%.2lf ",array2[i]); 
  printf("\n ");
  system("pause");
  return 0;
}

double total(double a[],int n)
{  
	int i;
	double sum=0;
  for(i=0;i<n;i++)
     sum+=a[i];
  return sum;
}
double average(double a[],int n)
{ 
	return 0;

}
double maximal(double a[],int n)
{ 
	return 0;


}
void copy1(double b[],double a[],int n)
{   



}

void reverse (double a[],int n)
{ 


}
