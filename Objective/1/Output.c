
// Guess the Output 


    #include<stdio.h>
    #define CUBE(x) (x*x*x)
    int main()
    {
        int a, b=4;
        a = CUBE(b++);
        printf("%d, %d\n", a, b);
    }

// Answer is  :  120, 7
// 
//  when the variable is passed , it is b=4 at initail
//  then on increment it becomes b=5 and then again b=6
//  so we get a=4*5*6=120
//  then we have b++ --> b=7
