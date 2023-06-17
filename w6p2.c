/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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

int main(void)
{
    int maxItem = 10, endLoop, numbOfItems, priority[maxItem],i;
    double netIncome, itemCost[maxItem], totalCost;
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
    
    
    printf("Best of luck in all your future endeavours!\n\n");
    return 0;
}
