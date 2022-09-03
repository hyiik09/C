#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 50

float a[MAX], b[MAX], sumX = 0, sumPowX = 0, sumY = 0, sumXY = 0, m, c;

int getInput()
{
    int n, i;
    /* to get the User Input */
    printf("How many data points > ");
    scanf("%d", &n);
    printf("Enter data:\n");
    printf("============\n");
    
    //saving user input into the array
    for (i = 1; i <= n; i++)
    {
        printf("\n(Point %d)\n",i);
        printf("x[%d]=", i);
        scanf("%f", &a[i]);
        printf("y[%d]=", i);
        scanf("%f", &b[i]);
    }
    
    
    return n;
}

void linear_cal(float x[MAX],float y[MAX], int n)
{
    /* Calculating Required Sum */
    for (int i = 1; i <= n; i++)
    {
        sumX = sumX + x[i];
        sumPowX = sumPowX + pow(x[i],2);
        sumY = sumY + y[i];
        sumXY = sumXY + x[i] * y[i];
    }
    
    /* Calculating m and c */
    m = (n * sumXY - sumX * sumY) / (n * sumPowX - pow(sumX,2));
    c = (sumY - m * sumX) / n;
}

float set2Des(float a)
{
    int b = a*100;
    float c =b;
    float d = c/100;
    return d;
}

bool test()
{
    float x[]={0,0,2,5,7};
    float y[]={0,-1,5,12,20};
    int n = 4;
    float expect_m = 2.89, expect_c = -1.13;
    linear_cal(x,y,n);
    float actual_m = set2Des(m);
    float actual_c = set2Des(c);
    
    if(expect_m == actual_m && expect_c == actual_c)
        return true;
    else
        return false;
    
}

int main()
{
    int n = getInput();
    linear_cal(a,b,n);
    /* Displaying value of m and c */
    printf("Values are: a=%0.2f and b = %0.2f", c, m);
    if (c < 0)
    {
        c = c*-1;
        printf("\nEquation of best fit is: y = %0.2fx - %0.2f", m, c);
    }else if (c>0)
    {
        printf("\nEquation of best fit is: y = %0.2fx + %0.2f", m, c);
    }else
    {
        printf("\nEquation of best fit is: y = %0.2fx", m);
    }   
    return (0);
}
