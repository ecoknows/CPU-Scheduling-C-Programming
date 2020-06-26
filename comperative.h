#ifndef COMPERATIVE_H
#define COMPERATIVE_H
#include "fcfs.h"
#include "srtf.h"
#include "sjf.h"
#include "pp.h"

void Compare(){
    system("cls");
    int x = 0;
    char *Text = "Aqua";
    char *Border = "Yellow";

    SetColor(Border);
    printf(" %c%c%c%c%c%c%c%c%c%c%c",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    SetColor(Text);
    SetColor("Light Yellow");
    printf(" Comperative");
    SetColor("Bright White");
    printf(" Analysis");
    SetColor(Border);
    printf(" %c%c%c%c%c%c%c%c%c%c%c\n",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    SetColor(Border);
    printf(" 1");
    SetColor(Text);
    SetColor("Light Yellow");
    printf(". FCFS");
    SetColor("Light Red");
    printf(" and");
    SetColor("Bright White");
    printf(" SJF\n");
    SetColor(Border);
    printf(" 2");
    SetColor(Text);
    SetColor("Light Yellow");
    printf(". SRTF");
    SetColor("Light Red");
    printf(" and");
    SetColor("Bright White");
    printf(" FCFS\n");
    SetColor(Border);
    printf(" 3");
    SetColor(Text);
    SetColor("Light Yellow");
    printf(". SJF");
    SetColor("Light Red");
    printf(" and");
    SetColor("Bright White");
    printf(" SRTF\n");
    SetColor(Border);
    printf(" 4");
    SetColor(Text);
    SetColor("Light Yellow");
    printf(". PP");
    SetColor("Light Red");
    printf(" and");
    SetColor("Bright White");
    printf(" NPP\n");
    SetColor(Border);
    printf(" 5");
    SetColor("Light Yellow");
    printf(". Back\n");
    SetColor(Border);
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    printf(" Choice : ");
    SetColor(Text);
    scanf("%i",&x);

    switch(x){
        case 1: FCFStoSJF();
        printf("\n---- press enter ----");
        getch();
        break;
        case 2: SRTFToFCFS();
        printf("\n---- press enter ----");
        getch();
        break;
        case 3: SJFToSRTF();
        printf("\n---- press enter ----");
        getch();
        break;
        case 4: PPToNPP();
        printf("\n---- press enter ----");
        getch();
        break;
        case 5: break;
    }
}


#endif // COMPERATIVE_H
