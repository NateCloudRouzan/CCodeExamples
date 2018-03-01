// -------------------------------------------------------------------------------------
// filename: CurencyConverterLab1.c
//
//Description:This program works as a currency converter for Dollars and yen.
//			It takes input from the user then converts between the currencies
//			It then gives the user an idea of the value of that much currency by
//			Providing the user with some examples of what that much money can buy in the native country
//
//Author: Nate Cloud-Rouzan
// -------------------------------------------------------------------------------------

//  preprocessor directive to support printing to the display
#include <stdio.h>

//  the main program
int main(void)
{
	//These Constants have been taken from google and will be used throughout the module
    float DOLLARSTOYEN = 113.13;
    float YENTODOLLARS = 0.0088;

	//  declare, define, and initialize some working variables
    float yen;
    float dollars;

	//  This chunk of code gives a description to the user of what the will do
	//It also gives the current exchange rate of dollars to yen and also yen to dollars
	printf("This program will use the exchange rate between dollars and yen. \n");
	printf("It will also give you examples of things you will be able to buy in exchanged country...\n");
	printf("The exchange rate from Yen to Dollars is %2.2f\n", DOLLARSTOYEN);
	printf("The exchange rate from Yen to dollars is  %2.2f\n", YENTODOLLARS);
	printf("\n");

	//ask the user then number of dollars the user would like to exchange
	//the data will be a floating point number: %f
	//stored in the variable 'dollars'
	printf("please enter your money to be exchanged in dollars $");
	scanf("%f", &dollars);

	//Exchange dollars inputed to yen
	yen = DOLLARSTOYEN * dollars;

	//Tells user what they inputed in dollars
	//Then displays the exchanged Yen
	printf("\n");//Newline
	printf("The amount of dollars you entered is $%2.2f\n ", dollars);
	printf("The equivalent yen you would have is Y%2.2f\n ", yen);
    printf("\n");//NewLine

	//This is an IF branch that will display what the user can buy with the equivalent Yen
    printf("With that much yen you could buy... \n");
     if ( yen > 500.0 ) printf( "a beer in japan (500 Yen) \n");
     if ( yen > 1000.0 ) printf( "a meal at an average restaurant (1,000 Yen) \n" );
     if ( yen > 200000.0 ) printf( "an average sized house in Japan (200,000 Yen) \n" );
	printf("\n");//Newline

	//ask the user then number of Yen the user would like to exchange
	//the data will be a floating point number: %f
	//stored in the variable 'yen'
	printf("please enter your Money you would like exchanged in Yen ");
	scanf("%f", &yen);

	//Exchange yen inputed to dollars
	dollars = yen * YENTODOLLARS;

	//Tells user what they inputed in Yen
	//Then displays the exchanged Dollars
	printf("The amount of Yen you entered is Y%2.2f\n", yen);
	printf("The equivalent Dollars you would have is $ %2.2f\n ", dollars);
	printf("\n"); //Line Break

	//This is an IF branch that will display what the user can buy with the equivalent dollars
	printf("With that much money you could buy... \n");
    if ( dollars > 5.0 )printf( "a beer in the US ($5) \n");
    if ( dollars > 10974.0 )printf( "a years tuition at UW ($10,974) \n" );
    if ( dollars > 35000.0 )printf( "a Tesla Model 3 ($35,000) \n" );
	
	return 0;
}
