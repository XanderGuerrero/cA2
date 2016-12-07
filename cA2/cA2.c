//FileName: cA2.c
//ProjectName: cA2
//Author: Alex Guerrero
//Date: October 15, 2013
//Description:  This program calculates powers of user inputted bases and exponents through the
//              use of a powerCalc() function.  The user inputs values through the direction of a menu. 
//              The program also checks the values entered by the user with a range checking function called rangeCheck().



#include<stdio.h>



//disables a warning to allow the use of the getNum()
#pragma warning(disable: 4996)



//function prototypes
int getNum(void);
int powerCalc(int base, int exponent);
int rangeCheck(int value, int minValue, int maxValue);



int main(void)
{
    //variables used in program, initialized
    int base = 1;
    int exponent = 1;
    int userInput = 0;
    int result = 0;
    int rangeResult = 0;
    int value = 0;
    int previousBaseValue = 1;
    int previousExponentValue = 1;

    //continuous loop to reprompt user after every menu/value entry
    while( 1 )
    {
        //menu display for user
        printf("Power Menu:\n\n    1. Change Base\n    2. Change Exponent\n    3. Display base raised to exponent\n    4. Exit program\n\nOption?\n\n");

        //calls getNum function
        userInput = getNum();
        printf("\n");
       
        //if user enters 1
        if( userInput == 1 )
        {
            //following code prompts user to enter a value for base
            //then calls the getNum function to get user input
            //the base value is copied into another variable to restore its previous value if
            //the value entered is out of range
            printf("please enter a base\n\n");
            base = getNum();
            if( base >= 1 && base <= 25)
			{
				previousBaseValue = base;
			}
            //informs user of data entered
            printf("\nYou entered %d for a base value\n\n", base);
            rangeResult = rangeCheck(base, 1, 25);
            if( rangeResult == 0 )
            {
                base = previousBaseValue;
            }
        }

        //if user enters 2
        if( userInput == 2 )
        {
            //following code prompts user to enter a value for an exponent
            //then calls the getNum function to get user input,
            //the exponent value is copied into another variable to restore its previous value if
            //the value entered is out of range
            printf("please enter an exponent\n\n");
            exponent = getNum();
			if( exponent >= 1 && exponent <= 5)
			{
				previousExponentValue = exponent;
			}
            //informs user of data entered
            printf("\nYou entered %d for an exponent value\n\n", exponent);
            rangeResult = rangeCheck(exponent, 1, 5);
            if( rangeResult == 0 )
            {
                exponent = previousExponentValue;
            }
        }

        //if user enters 3
        if( userInput == 3 )
        {
            //the following code calculates the result of raising of one number
            //to the power of another through the use of the power function
            //the information is then displayed to the user
            result = powerCalc(base, exponent);
            printf("The value calculated is %d\n\n", result);
        }

        //if user enters 4
        if( userInput == 4 )
        {
            //break out of the loop
            break;
        }
    }

    //informs the user the program is quitting
    printf("Goodbye\n\n");

    return 0;
}



//FunctionName: rangeCheck
//Description: checks the user inputted data for the correct range. 1-25 for bases, 1-5 for exponents
//Parameters: int value, int minValue, int maxValue
//Return Values: valueOfRange

int rangeCheck(int value, int minValue, int maxValue)
{
    //varialbe used for return value
    int valueOfRange = 0;

    //if the user inputted data is out of range return 0, if data is in range return 1
    //if data is out of range, user is informed with a printf statement
    if( value < minValue || value > maxValue )
    {
        printf("ERROR: The value entered is out of range\n\nValues must be between 1 and 25 for the base values\n");
        printf("and between 1 and 5 for the exponent values\n\n");
        valueOfRange = 0;
    }
    else
    {
        valueOfRange = 1;
    }

    return valueOfRange;
}



//FunctionName: powerCalc
//Description: raises one number to the power of another
//Parameters: int base, int exponent
//Return Values: answer

int powerCalc(int base, int exponent)
{
    //variables used in for loop and return statement
    int count = 0;
    int answer = 1;

    //for loop uses a running total to calculate raising one number
    //to the power of another
    for( count = 1; count <= exponent; count++ )
    {
        answer = answer * base;
    }

    return answer;
}



//FunctionName: getNum
//Description:  gets user inputted numbers from the keyboard
//Parameters: void
//Return Values: number

int getNum(void)
{
    //array is 121 bytes in size and variable record stores the string
    char record[121] = {0};
    int number = 0;

    //fgets() is used to get a string from the keyboard
    fgets(record, 121, stdin);

    //extract a number from the string; sscanf() returns a number
    //corresponding with the number of items found in the string
    //if the user did not enter a number recognizable by the system,
    //set number to -1
    if( sscanf(record, "%d", &number ) != 1 )
    {
        number = -1;
    }
    return number;
}