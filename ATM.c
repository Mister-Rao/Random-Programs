#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>
#include<unistd.h>

//DATABASE
int PIN[6] = {1010,2020,3030,4040,5050,6060};
int CARD[6] = {111111,112211,113311,114411,115511,116611};
int AMOUNT[6] = {10000,50000,15000,7000,9000,10000};
int ACCTYP[6] = {1,1,1,2,3,1};
int WRONGLIMIT[6] = {0,0,0,0,0,0};
int AMOUNTLIMIT[6] = {0,0,0,0,0,0};
int ATM_CASH_AVAILABLE = 70000;


//GLOBAL VARIABLES
int pin, cardNo, ID;
jmp_buf buf;

//GLOBAL CONSTANTS
#define WRONG_PIN_LIMIT 3
#define DAY_LIMIT 40000

//FUNCTION PROTOTYPES
int Authen(int);
void Choices(int);
void withdraw(int,int);
void Menu();

//MAIN
int main(){
    int i, token;

    //HANDLING
    if(setjmp(buf)){
        sleep(3);
        system("clear");
        goto top;
    }
    top:
        while(ATM_CASH_AVAILABLE == 0){
            printf("ATM OFFLINE\n");
            printf("NO CASH IN ATM\n");
        }
        
        printf("\n\n\n\n");
        printf("\t\t\tATM ONLINE\n");
        printf("\n\nInsert Card:\t");
        scanf("%d",&cardNo);
        for(i=0;i<6;i++)
            if(CARD[i] == cardNo){
                ID = i;
                //WRONG PIN LIMIT EXCEEDED
                if(WRONGLIMIT[ID] == WRONG_PIN_LIMIT){
                    printf("Incorrect PIN entered 3 times\n");
                    sleep(3);
                    system("clear");
                    goto top;
                }
                token = Authen(ID);
                break;
            }
            else if(i==5 && CARD[i] != cardNo){
                //INVALID CARD
                printf("Invalid Card\n");
                sleep(3);
                system("clear");
                goto top;
            }

        //CARD AND PIN VALIDATED
        if(token == 1)
            Choices(ID);
        else{
            printf("Invalid Pin\nTry Again\n");
            //WRONG PIN LIMIT
            WRONGLIMIT[ID]++;
            sleep(3);
            system("clear");
            goto top;
        }
}//end main



//*********************************************************************************************//


//FUNCTIONS
//FUNCTION AUTHENTICATE
int Authen(int index){
    printf("Enter pin:\t");
    scanf("%d",&pin);
    if(PIN[index] == pin)
        return 1;
    else
        return -1;
}

//FUNCTION CHOICES
void Choices(int ID){
    int ch;

LANGUAGE_SELECT:
    printf("Select Language\n");
    printf("1.English\t2.Kannada\t3.Hindi\n");
    scanf("%d",&ch);

    switch (ch)
    {
        case 1:
            Menu();
            break;
        
        case 2:
            printf("Your selected language('Kannada') is not yet available.\nPlease select a different language\n");
            sleep(2);
            system("clear");
            goto LANGUAGE_SELECT;

        case 3:
            printf("Your selected language('Hindi') is not yet available.\nPlease select a different language\n");
            sleep(2);
            system("clear");
            goto LANGUAGE_SELECT;
            
        default:
            printf("\n\nInvalid Selection\n\n");
            longjmp(buf,1);
    }
}

//FUNCTION WITHDRAW
void withdraw(int Acctyp, int ID){
    int withAmount;


    if(ACCTYP[ID] != Acctyp){
        printf("Invalid Account Type\n");
        longjmp(buf,1);
    }

    printf("Enter Amount to be withdraw\n");
    scanf("%d",&withAmount);

    //CHECKING LIMIT
    AMOUNTLIMIT[ID] += withAmount;
    if(withAmount > DAY_LIMIT || AMOUNTLIMIT[ID] > DAY_LIMIT){
        if(AMOUNTLIMIT[ID] > DAY_LIMIT)
            AMOUNTLIMIT[ID] -= withAmount;
        printf("Daily Withdrawal Limit Reached\n");
        longjmp(buf,1);
    }

    //CHECKING AVAILABLE BALANCE
    if(withAmount > AMOUNT[ID]){
        printf("insufficient Balance\n");
        printf("\nAVAILABLE BALANCE:\t");
        printf("%d\n",AMOUNT[ID]);
        longjmp(buf,1);
    }

    //CHECKING AVAILABLE ATM CASH
    if(withAmount > ATM_CASH_AVAILABLE){
        ATM_CASH_AVAILABLE -= withAmount;
        printf("NO CASH IN ATM\n");
        printf("AVAILABLE CASH:\t %d\n",ATM_CASH_AVAILABLE);
        longjmp(buf,1);
    }

    //UPDATING DATABASE BALANCE
    AMOUNT[ID] -= withAmount;
    printf("\nAMOUNT SUCCESSFULLY WITHDRAWN:\t");
    printf("%d\n",withAmount);
    printf("\nAVAILABLE BALANCE:\t");
    printf("%d\n",AMOUNT[ID]);
    
    longjmp(buf,1);
}

//FUNCTION MENU
void Menu(){
    int ch, Acctyp, cPIN;
    int nPIN, confPIN;
    system("clear");
    printf("SELECT YOUR CHOICE\n");
    printf("\t1.WITHDRAW\n\t2.BALANCE\n\t3.CHANGE PIN\n\t4.EXIT\n");
    printf("\nSELECT:\t\n");
    scanf("%d",&ch);

    switch (ch)
    {
        case 1:
            printf("Select Account Type\n");
            printf("\n1.Savings\t\t2.Credit\t\t3.Current\n");
            scanf("%d",&Acctyp);
            withdraw(Acctyp, ID);
            break;

        case 2:
            printf("\n\nBALANCE:\t %d\n\n",AMOUNT[ID]);
            longjmp(buf,1);
            break;

        case 3:
            printf("Enter current PIN:\t");
            scanf("%d",&cPIN);
            if(PIN[ID] == cPIN){
                printf("Enter New PIN:\t");
                scanf("%d",&nPIN);
                printf("Enter New PIN again:\t");
                scanf("%d",&confPIN);
                if(nPIN == confPIN){
                    PIN[ID] = nPIN;
                    printf("PIN changed successfully\n");
                    longjmp(buf,1);
                }
            }
            break;

        case 4:
            printf("Thank You for using ATM\n");
            longjmp(buf,1);
            break;

        default:
            printf("IINVALID SELECTION\n");
            longjmp(buf,1);
            
    }
}