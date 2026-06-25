#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char currency[20], name[20];
    int choice;
    float amount, result;

    float INR_USD = 0.012f;
    float INR_EUR = 0.011f;
    float INR_GBP = 0.0095f;
    float INR_JPY = 1.80f;

    float USD_INR = 83.10f;
    float EUR_INR = 90.50f;
    float GBP_INR = 105.20f;
    float JPY_INR = 0.55f;


    printf("\n===============================\n");
    printf("       CURRENCY CONVERTER\n");
    printf("===============================\n");


    printf("\nEnter your currency country (India/USA/Germany/UK/Japan): ");

    if(scanf("%19s", currency) != 1)
    {
        printf("Invalid input.\n");
        return 0;
    }


    for(int i = 0; currency[i] != '\0'; i++)
    {
        name[i] = tolower(currency[i]);
        name[i + 1] = '\0';
    }


    if(strcmp(name,"india") != 0 &&
       strcmp(name,"usa") != 0 &&
       strcmp(name,"germany") != 0 &&
       strcmp(name,"uk") != 0 &&
       strcmp(name,"japan") != 0)
    {
        printf("Country not supported.\n");
        return 0;
    }


    printf("Enter amount: ");

    if(scanf("%f",&amount) != 1 || amount <= 0)
    {
        printf("Invalid amount.\n");
        return 0;
    }


    printf("\nConvert to:\n");
    printf("1. India (INR)\n");
    printf("2. USA (USD)\n");
    printf("3. Germany (EUR)\n");
    printf("4. UK (GBP)\n");
    printf("5. Japan (JPY)\n");

    printf("Choose option: ");

    if(scanf("%d",&choice) != 1 || choice < 1 || choice > 5)
    {
        printf("Invalid choice.\n");
        return 0;
    }


    if((strcmp(name,"india")==0 && choice==1) ||
       (strcmp(name,"usa")==0 && choice==2) ||
       (strcmp(name,"germany")==0 && choice==3) ||
       (strcmp(name,"uk")==0 && choice==4) ||
       (strcmp(name,"japan")==0 && choice==5))
    {
        printf("Same currency conversion is not allowed.\n");
        return 0;
    }


    if(strcmp(name,"india")==0)
    {
        if(choice==2)
            result = amount * INR_USD;
        else if(choice==3)
            result = amount * INR_EUR;
        else if(choice==4)
            result = amount * INR_GBP;
        else
            result = amount * INR_JPY;
    }

    else if(strcmp(name,"usa")==0)
    {
        result = amount * USD_INR;
    }

    else if(strcmp(name,"germany")==0)
    {
        result = amount * EUR_INR;
    }

    else if(strcmp(name,"uk")==0)
    {
        result = amount * GBP_INR;
    }

    else
    {
        result = amount * JPY_INR;
    }


    printf("\nConverted amount: %.2f\n", result);

    printf("\nThank you for using Currency Converter!\n");


    return 0;
}
