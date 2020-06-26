#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "menu.h"
#include "dataentry.h"

int main()
{
    SetColor("Purple");
    InstantiateProcess();

    while(displayMenu()){
        system("cls");
    }

    return 0;
}

int SetColor(char *color){
    if(strcmp(color,"Black") == 0){
       colorCons(0);
    }else if (strcmp(color,"Blue") == 0){
       colorCons(1);
    }else if (strcmp(color,"Green") == 0){
       colorCons(2);
    }else if (strcmp(color,"Aqua") == 0){
       colorCons(3);
    }else if (strcmp(color,"Red") == 0){
       colorCons(4);
    }else if (strcmp(color,"Purple") == 0){
       colorCons(5);
    }else if (strcmp(color,"Yellow") == 0){
       colorCons(6);
    }else if (strcmp(color,"White") == 0){
       colorCons(7);
    }else if (strcmp(color,"Gray") == 0){
        colorCons(8);
    }else if (strcmp(color,"Light Blue") == 0){
        colorCons(9);
    }else if (strcmp(color,"Light Green") == 0){
        colorCons(10);
    }else if (strcmp(color,"Light Aqua") == 0){
        colorCons(11);
    }else if (strcmp(color,"Light Red") == 0){
        colorCons(12);
    }else if (strcmp(color,"Light Purple") == 0){
        colorCons(13);
    }else if (strcmp(color,"Light Yellow") == 0){
        colorCons(14);
    }else if (strcmp(color,"Bright White") == 0){
        colorCons(15);
    }
}

void colorCons(int ForgC)
 {
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                 //Mask out all but the background attribute, and add in the forgournd     color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }

