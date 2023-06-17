*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
Full Name  : 
Student ID#: 
Email      : 
Section    : 
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define Max_income 400000.00
#define Min_income 500.00
#define Min_price 100.00

#include <stdio.h>

int main()
{
    int maxItem = 10, endLoop, numbOfItems, priority[maxItem],i, userChoice, Years, Months = 0;
    double netIncome, itemCost[maxItem], totalCost, amount,remainder;
    char finOption[maxItem];



    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n"); 

    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &netIncome);
        if (netIncome < Min_income)
            {
                printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", Min_income);
            }
        else if (netIncome > Max_income)
            {
                printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", Max_income);
            } 
        else 
            {
                endLoop = 1;
            }
        printf("\n");
        
    } while (endLoop != 1);

    do
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &numbOfItems);
        if (numbOfItems < 1 || numbOfItems > maxItem)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
            endLoop = 0;
        } else 
        {
            endLoop = 1;
        }
        printf("\n");

    } while (endLoop != 1);

    for ( i = 1; i  <= numbOfItems; i++)
    {
        printf("Item-%d Details:\n",i);
        do 
        {
        
        printf("   Item cost: $");
        scanf("%lf", &itemCost[i]);
            if (itemCost[i] < Min_price)
            {
            printf("      ERROR: Cost must be at least $100.00\n");
            endLoop = 0;
            } else 
            {
                endLoop = 1;
            }
        }while(endLoop != 1);

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);

            if (priority[i] < 1 || priority[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
                endLoop = 0;
            }else 
            {
                endLoop = 1;
            }
            

        } while (endLoop != 1);


        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finOption[i]);
            if (finOption[i] != 'n' && finOption[i] != 'y')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                endLoop = 0;
            } else
            {
                endLoop = 1;
            }
        } while (endLoop != 1);
        printf("\n");
    }
    
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 1; i <= numbOfItems;i++)
    {
    printf("%3d  %5d    %5c    %11.2lf\n",i, priority[i], finOption[i],itemCost[i]);
    totalCost += itemCost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);
    
    

    do
    {
       printf("How do you want to forecast your wish list?\n");
       printf(" 1. All items (no filter)\n");
       printf(" 2. By priority\n");
       printf(" 0. Quit/Exit\n");
       printf("Selection: ");
       scanf("%d", &userChoice);
       if (userChoice > 2 || userChoice < 0)
       {
            printf("\nERROR: Invalid menu selection.\n\n");
            i = 0;
       } else if (userChoice == 0)
       {
            i = 1;
       }
       switch (userChoice)
       {
       case 1:
        printf("====================================================\n");
        printf("Filter:   All items\n");
        printf("Amount:   $%1.2lf\n", totalCost);
        Years = totalCost / netIncome / 12;  
        remainder = (totalCost / netIncome/12 - Years) * 12;
        do
        {
            remainder--;
            Months++;
        } while (remainder > 0);
        printf("Forecast: %d years, %d months\n", Years,Months);
        
        for (i = 0; i < numbOfItems; i++)
        {
            if (finOption[i] == 'y')
            {
            printf("NOTE: Financing options are available on some items.\n");
            printf("      You can likely reduce the estimated months.\n");
            printf("====================================================\n\n");
            i = numbOfItems;
            }
        }
        break;
        case 2: 
        printf("\nWhat priority do you want to filter by? [1-3]: ");
        scanf("%d", &userChoice);
        for (i = 1; i <= numbOfItems; i++)
        {
            if (priority[i] == userChoice)
            {
                amount += itemCost[i];
            }
        }
        printf("====================================================\n");
        printf("Filter:   by priority (%d)\n",userChoice);
        printf("Amount:   $%1.2lf\n", amount);
        Years = amount / netIncome / 12;  
        remainder = (amount / netIncome/ 12 - Years) * 12;
        do
        {
            remainder--;
            Months++;
        } while (remainder > 0);
        
        
        printf("Forecast: %d years, %d months\n", Years,Months);
        if (finOption[userChoice] == 'y')
        {
            printf("NOTE: Financing options are available on some items.\n");
            printf("      You can likely reduce the estimated months.\n");
            printf("====================================================\n\n");
        }
       default:
        break;
       }
       amount = 0.0;
       Months = 0;
    } while (i !=1);
    
    printf("\nBest of luck in all your future endeavours!\n\n");




    return 0;
}
