#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char from[20];
    char lower[20];
    int to;
    float amount = 0.0f, converted = 0.0f;

    // Fixed example conversion rates (editable)
    float INR_to_USD = 0.012f;
    float INR_to_EUR = 0.011f;
    float INR_to_GBP = 0.0095f;
    float INR_to_JPY = 1.80f;

    float USD_to_INR = 83.10f;
    float EUR_to_INR = 90.50f;
    float GBP_to_INR = 105.20f;
    float JPY_to_INR = 0.55f;

    printf("\n=====================================\n");
    printf("           CURRENCY CONVERTER        \n");
    printf("=====================================\n\n");

    // Ask user for base currency
    printf("Enter your currency country (India / USA / Germany / UK / Japan): ");
    if (scanf("%19s", from) != 1) {
        printf("\nInput error. Please run the program again.\n");
        return 0;
    }

    // make lowercase copy for case-insensitive compare
    for (int i = 0; from[i] != '\0' && i < 19; ++i) {
        lower[i] = (char)tolower((unsigned char)from[i]);
        lower[i+1] = '\0';
    }

    // Validate country input (case-insensitive)
    if (strcmp(lower, "india") != 0 &&
        strcmp(lower, "usa") != 0 &&
        strcmp(lower, "germany") != 0 &&
        strcmp(lower, "uk") != 0 &&
        strcmp(lower, "japan") != 0) {
        printf("\nInvalid country '%s'. Accepted names: India, USA, Germany, UK, Japan\n", from);
        return 0;
    }

    // Enter amount
    printf("Enter amount: ");
    if (scanf("%f", &amount) != 1) {
        printf("\nInvalid amount input. Please enter a numeric value (e.g., 1234.56).\n");
        return 0;
    }

    if(amount==0){
        printf("Invaild amount Input. You entered : %.0f\n",amount);
        return 0;
    }
    if (amount <= 0.0f ) {
        printf("\n Amount must be greater than zero . You entered: %.2f\n", amount);
        return 0;
    }

    // Choose target country
    printf("\nConvert to:\n");
    printf("1. India (INR)\n");
    printf("2. USA (USD)\n");
    printf("3. Germany (EUR)\n");
    printf("4. UK (GBP)\n");
    printf("5. Japan (JPY)\n");
    printf("Enter your choice (1-5): ");
    if (scanf("%d", &to) != 1) {
        printf("\nInvalid choice input. Enter an integer between 1 and 5.\n");
        return 0;
    }

    // Validate target input
    if (to < 1 || to > 5) {
        printf("\n Invalid choice '%d'. Choice must be between 1 and 5.\n", to);
        return 0;
    }

    // Prevent converting into same country (compare using lowercase)
    if ((strcmp(lower, "india") == 0 && to == 1) ||
        (strcmp(lower, "usa") == 0 && to == 2) ||
        (strcmp(lower, "germany") == 0 && to == 3) ||
        (strcmp(lower, "uk") == 0 && to == 4) ||
        (strcmp(lower, "japan") == 0 && to == 5)) {
        printf("\nCannot convert to the same currency (%s). Please choose a different target.\n", from);
        return 0;
    }

    printf("\n-------------------------------------\n");

    // Conversion logic (source identified by lowercase)
    if (strcmp(lower, "india") == 0) {
        switch (to) {
            case 2: converted = amount * INR_to_USD; printf("Converted Amount: %.2f USD\n", converted); break;
            case 3: converted = amount * INR_to_EUR; printf("Converted Amount: %.2f EUR\n", converted); break;
            case 4: converted = amount * INR_to_GBP; printf("Converted Amount: %.2f GBP\n", converted); break;
            case 5: converted = amount * INR_to_JPY; printf("Converted Amount: %.2f JPY\n", converted); break;
        }
    }
    else if (strcmp(lower, "usa") == 0) {
        if (to == 1) converted = amount * USD_to_INR;
        printf("Converted Amount: %.2f INR\n", converted);
    }
    else if (strcmp(lower, "germany") == 0) {
        if (to == 1) converted = amount * EUR_to_INR;
        printf("Converted Amount: %.2f INR\n", converted);
    }
    else if (strcmp(lower, "uk") == 0) {
        if (to == 1) converted = amount * GBP_to_INR;
        printf("Converted Amount: %.2f INR\n", converted);
    }
    else if (strcmp(lower, "japan") == 0) {
        if (to == 1) converted = amount * JPY_to_INR;
        printf("Converted Amount: %.2f INR\n", converted);
    }

    printf("-------------------------------------\n");

    return 0;
}
