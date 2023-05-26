#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 30

 
void printArray(char a[], int length){
    for (int i=0; i<length; i++) {
    if (i==0&&a[i]!='\0') printf("[%c", a[i]);
    else if (i==0&&a[i]=='\0') printf("[\\0");
    else if (a[i]=='\0') printf(",\\0");
    else printf(",%c", a[i]);
    }
printf("]\n"); 
}
void readLine(char str[], int length){
    int i=0;
    char aChar;
    
    do {
        aChar = getchar();
        if (i<LENGTH){
            str[i] = aChar;
        }
        i++;
            
    } while (aChar != '\n');
    
    if (i<LENGTH){
        str[i-1] = '\0';
    }
    else{
        str[LENGTH-1] = '\0';
    }
}

void printString(char a[], int length){
    printf("\"");
    int i = 0;
    while (a[i] != '\0'){
        putchar(a[i]);
        i++;
    }
    printf("\"\n");
}

int findFirstOccurence(char a[], char achar){
   for (int i = 0; i < strlen(a); i++) {
      if (a[i] == achar) return i;
      if (a[i] == '\0') return -1;
    }
    return -1;
}



void insertChar(char a[], char aChar, int index){
    int n;
    int i;
    n = strlen(a);
 
 for (i = n-1; i >= index; i--) {
     a[i+1] = a[i];
 }
 a[index] = aChar;
}

int readInt(char a[], int length){
    if (a[0]<'0'|| a[0]>'9'){
        return -1;
    }
    int i = 0;
    int result = 0;
    while (a[i] != '\0'){
        if (a[i] >= '0' && a[i] <= '9'){
            result = result * 10 + (a[i] - '0');
        }
        else {
            return result;
        }
        i++;
    }
    return result;
}

int replaceChar(char a[], char fromString[], char toChar){
    int i, j, c=0;
   for (i = 0; i<strlen(a); i++){
       for(j=0; j<strlen(a); j++){
         if(a[j]==toChar)
         continue;
         if(fromString[i]==a[j]){
             a[j]=toChar;
             c++;
       }
    }
}
return c;
}

void stringReorder(char a[], int index1, int index2){
    int i, j;
    
 for (i = 0; i<index1; i++){
     a[i] = a[strlen(a)-i];
   }
 for(j=strlen(a); j>index2; j--){
         a[j] = a[strlen(a)-j];
         
       }
     
}

int main (void){
    char inputString[LENGTH] = "";
    char currString[LENGTH] = {'\0'};
    char occ;
    char ins;
    int h = 0;
    int f;
    char re[LENGTH] = "";
    char newC;
    int index1;
    int index2;
  
     
    do {
        printf("Command?");
        printf(" ");
        readLine(inputString, LENGTH);
        switch (inputString[0]){
            
             case 'a':
            printf("The current array is: ");
            printArray(currString, LENGTH);
            break;
            
            case 'p':
            printf("The current string is: ");
            printString(currString, LENGTH);
            break;
            
            case 's':
            printf("Please enter a string? ");
            readLine(currString, LENGTH);
            break;
            
            case 'o':
            printf("Find first occurrence of which character? ");
            readLine(inputString, LENGTH);
            occ = inputString[0];
            f = findFirstOccurence(currString, occ);
            printf("The first occurrence of \'%c\' is at index %d\n", occ, f);
            break;
            
            case 'i':
            printf("Insert which character? ");
            readLine(inputString, LENGTH);
            ins = inputString[0];
            printf("At what index? ");
            readLine(inputString, LENGTH);
            h = readInt(inputString, LENGTH);
            insertChar(currString, ins, h);
            break;
            
            case 'r':
            printf("Replace which characters? ");
            readLine(re, LENGTH);
            printf("with which character? ");
            readLine(inputString, LENGTH);
            newC=inputString[0]; 
            replaceChar(currString, re, newC);
            break;
            
            case 'R':
            printf("Please enter index 1? ");
            readLine(inputString, LENGTH);
            index1 = inputString[0];
            printf("Please enter index 2? ");
            readLine(inputString, LENGTH);
            index2 = inputString[0];
            stringReorder(currString, index1, index2);
            
            
            case 'q':
            printf("Bye!\n");
            break;
            default:
            printf("Unknown command '%c'\n", inputString[0]);
            break;
        }
    }while (inputString[0] != 'q');    
}
 