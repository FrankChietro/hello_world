//Program takes your age and the amount you make each day and estimates how much money you will have at age 65

#include <stdio.h>
#include <math.h>

int main(){

//Defining Variables
    double amountperday, currentage, newage, yourmoney, initialsavings;

//User input for age
    printf("Please enter your age: ");
    scanf("%lf", &currentage);

//User input for initial savings
    printf("Please enter savings as of today: ");
    scanf("%lf", &initialsavings);

//User input for money earned each day
    printf("Please enter money saved each day: ");
    scanf("%lf", &amountperday);


//Age and money calculation
    newage= 65- currentage;


    yourmoney= initialsavings + ((amountperday*365)*newage);



//Main calculation
    if(yourmoney >= 1000000){

        printf("You are a millionaire!! You saved %.2lf at age 65",yourmoney);

}
    else if(yourmoney < 1000000){

        printf("Not there yet, keep saving! You saved %.2lf at age 65",yourmoney);

    }

    return 0;

}
