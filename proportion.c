#include <stdio.h>
#include <string.h>

double addTotal(int numberOfInput, double itemValue[]);
void itemProportion(double total, int numberOfInput, double itemValue[], double propList[]);
void scale(int numberOfInput, int itemRef, double propList[], double itemRefNewVal, double newItemValue[]);

int main (void){
    //prompt and program instructions
    printf("\nThis program will help you in scaling your proportions.\n");
    printf("Note: Don't use the space key.\n");
    printf("Note: type 0 to the Name to exit the loop.\n");
    char itemName[100][20];
    double itemValue[100];
    int numberOfInput = 0;
    printf("Note: You can only name an item with 20 characters.\n");
    printf("Note: You can only add 100 items.\n\n");    
    for (int i = 0; i < 100; i++){
        printf("Name: ");
        scanf("%s", &itemName[i]);
        if (strcmp(itemName[i], "0") == 0){
            break;
        }
        printf("Value: ");
        scanf("%lf", &itemValue[i]);
        
        numberOfInput++;
    }     

    double total = addTotal(numberOfInput, itemValue);

    //display user options for the second list
    int itemRef = 0;
    double itemRefNewVal = 0.0; 
    printf("\n=================================================\n\nItem Index:\n\n");
    for (int i = 0; i < numberOfInput; i++){
        printf("%d - %s\n", i, itemName[i]);
    } 
    printf("\nWhich item would you like to be the reference for scaling? ");
    scanf("%d", &itemRef);
    printf("What is the new value of this item? ");
    scanf("%lf", &itemRefNewVal);

    //function call for proportion computation
    double propList[100];
    itemProportion(total, numberOfInput, itemValue, propList);

    //using itemRef, scale the list 
    double newItemValue[100];
    scale(numberOfInput, itemRef, propList, itemRefNewVal, newItemValue);

    //print the results
    printf("\nInitially:\n");
    for (int i = 0; i < numberOfInput; i++){
        printf("%s - %.2lf\n", itemName[i], itemValue[i]);
    }
    printf("\n=================================================");
    printf("\n\nScaled: \n");
    for (int i = 0; i < numberOfInput; i++){
        printf("%s - ", itemName[i]);
        printf("%.2lf\n", newItemValue[i]);
    }
    printf("\n");

    return 0; 
}
double addTotal(int numberOfInput, double itemValue[]){
    double total = 0;
    for (int i = 0; i < numberOfInput; i++){
        total += itemValue[i];
    }
    return total;
}

void itemProportion(double total, int numberOfInput, double itemValue[], double propList[]){
    for (int i = 0; i < numberOfInput; i++){
        propList[i] = itemValue[i]/total;
    }
}

void scale(int numberOfInput, int itemRef, double propList[], double itemRefNewVal, double newItemValue[]){
    double itemRefProp = propList[itemRef];
    double itemRefPropPrime = 1.0 - itemRefProp;    
    double newItemValMis = (itemRefNewVal * itemRefPropPrime) / itemRefProp; 
    double newItemValSum = newItemValMis + itemRefNewVal;
    for (int i = 0; i < numberOfInput; i++){
        newItemValue[i] = propList[i] * newItemValSum;
    }
}   