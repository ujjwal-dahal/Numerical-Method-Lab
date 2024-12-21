#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) x*sin(x)-1
#define df(x) (1+log(x))/log(10)
void main(){
    float x0,f0,df0,x1,f1,e;
    int Iteration =1,N;
    printf("\n C Program for NR Method created by Ujjwal Dahal on 2081/8/24");
    printf("\n Enter value of initial guess x0:");
    scanf("%f",&x0);
    printf("\n Enter the value of max no of initial N:");
    scanf("%d",&N);
    printf("\n Enter the value of predefined error:");
    scanf("%f",&e);
    printf("\n______________________________________________________________________________\n");
    printf("\n Iteration\tx0\t\tf(x0)\t\tx1\t\tf(x1)");
    printf("\n______________________________________________________________________________\n");
    do{
    	f0=f(x0);
    	df0=df(x0);
    	if (df0==0.0){
    		printf("NR Method fails i.e Math error");
    		exit(0);
		}
		x1=x0-f0/df0;
		x0=x1;
		f1=f(x1);
		printf("\n%d\t\t%f\t%f\t%f\t%f\n",Iteration,x0,f0,x1,f1);
		Iteration=Iteration+1;
		if (Iteration>N){
			printf("The solution doesnot converge");
			exit(0);
		}
	}while (fabs(f1)>e);
    printf("\n______________________________________________________________________________\n");
	printf("\n The required approxiamate root is %0.8f",x1);
}