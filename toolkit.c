#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Register function
void registerUser(){

    char name[20];
    int pin;

    printf("\nREGISTRATION\n");
    printf("Welcome to Safaricom\n");
    printf("Enter your name: ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // flushes the leftover newline
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Input your PIN number: ");
    scanf("%d", &pin);

    FILE *file;
    file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "\nUser: %s %d|", name, pin);
    // fprintf(file, "---------------------------------------------------------");
    fclose(file);

    printf("\n\nWelcome %s, you have successfully registered with Safaricom", name);
}

//login function
int loginUser(){
    char name[20];
    int pin, file_pin;
    char file_username[50];
    int verified = 0;

    for(int i=1; i<=3; i++){
        printf("\nLOGIN FORM");
            printf("\nPlease enter your credentials");
            printf("\nEnter your name: ");
            scanf("%s", name);
    
            printf("Enter your PIN: ");
            scanf("%d", &pin);
    
            FILE *fp;
    
            fp = fopen("users.txt", "r");
            if (fp == NULL) {
                perror("Error opening file");
                return 1;
            }
    
            // Read through the file line by line
            while (fscanf(fp, "%s %d", file_username, &file_pin) != EOF) {
                if (strcmp(name, file_username) == 0 && pin == file_pin) {
                    verified = 1;
                    break;
                }
            }
    
            fclose(fp);
    
            if (verified) {
                printf("Verification successful.\n");
                return 0;
            } else {
                printf("Verification failed. Invalid username or password.\n");
            }

    }
    printf("SIM blocked. Too many attempts");
    exit(0);

    
}

void sendMoney(){
    int amount, phone, pin;
    printf("\nSEND MONEY SERVICES\n");
    printf("Enter the phone number: ");
    scanf("%d", &phone);

    printf("Enter the amount: ");
    scanf("%d", &amount);

    printf("Enter your PIN: ");
    scanf("%d", &pin);

    printf("You have sent Ksh %d to +254%d\n", amount, phone);
}

void withdrawCash(){
    int amount;
    printf("\nWITHDRAWAL SERVICES\n");
    printf("Enter the amount: ");
    scanf("%d", &amount);

    printf("You have withdrawn Ksh %d\n", amount);
}

void buyAirtime(){
    int amount;
    printf("\nAIRTIME SERVICES\n");
    printf("Enter the amount: ");
    scanf("%d", &amount);

    printf("You have bought Ksh %d airtime\n", amount);
}

void loansAndSavings(){
    int amount;
    printf("\nLOANS AND SERVICES\n");
    printf("Enter the amount: ");
    scanf("%d", &amount);

    printf("You have saved Ksh %d\n", amount);
}

void lipaNaMpesa(){
    int amount;
    printf("\nLIPA NA MPESA\n");
    printf("Enter the amount: ");
    scanf("%d", &amount);

    printf("You have paid Ksh %d\n", amount);
}

void myAccount(){
    int amount;
    printf("\nMY ACCOUNT\n");
    printf("Enter the amount: ");
    scanf("%d", &amount);

    printf("You have Ksh %d in your account\n", amount);
}

//Mpesa function
void Mpesa(){
    int choice;
    printf("\nWELCOME HOME\n");
    printf("1. Send Money\n");
    printf("2. Withdraw Cash\n");
    printf("3. Buy Airtime\n");
    printf("4. Loans and Savings\n");
    printf("5. Lipa na MPESA\n");
    printf("6. My Account\n");
    printf("Select an option: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            sendMoney();
            break;
        case 2:
            withdrawCash();
            break;
        case 3:
            buyAirtime();
            break;
        case 4:
            loansAndSavings();
            break;
        case 5:
            lipaNaMpesa();
            break;
        case 6:
            myAccount();
            break;
        default:
            printf("Invalid option\n");
    }
}



int main(){
    int option, choice;
    printf("\n");
    printf("WELCOME TO SAFARICOM TOOLKIT\n");
    printf("1.Register\n");
    printf("2.Login\n");
    printf("Enter Choice:");
    scanf("%d", &choice);

    if(choice == 1){
        registerUser();
        Mpesa();
    }
    else if(choice == 2){
        loginUser();
        Mpesa();
    }
    else{
        printf("Invalid input");
        exit(0);
    }
    printf("\n");
    
    // do{
    //     printf("\t\t\t\t\t\t\t\tHOME\n");
        
    //     printf("1. Go back to Home\n");
    //     printf("2. Exit\n");
    //     printf("Select an option: ");
    //     scanf("%d", &option);
    // }while(option == 1);    
    
    
    return 0;
}