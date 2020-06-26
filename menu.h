#ifndef MENU_H
#define MENU_H
#include "fcfs.h"
#include "sjf.h"
#include "srtf.h"
#include "pp.h"
#include "npp.h"
#include "rr.h"
#include "comperative.h"

int displayMenu(){
    int x = 0;
    char *Text = "Aqua";
    char *Border = "Yellow";

    SetColor(Border);
    printf(" %c%c%c%c%c%c%c%c%c%c%c",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    SetColor(Text);
    SetColor("Bright White");
    printf(" CPU");
    SetColor("Light Yellow");
    printf(" Scheduling");
    SetColor("Light Red");
    printf(" Algorithm");
    SetColor(Border);
    printf(" %c%c%c%c%c%c%c%c%c%c%c\n",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    printf(" 0");
    SetColor("Bright White");
    printf(".");
    SetColor(Text);
    printf(" Comperative Analysis\n");
    SetColor(Border);
    printf(" 1");
    SetColor("Bright White");
    printf(".");
    SetColor(Text);
    printf(" First Come First Serve\n");
    SetColor(Border);
    printf(" 2");
    SetColor("Bright White");
    printf(".");
    SetColor(Text);
    printf(" Shortest Jump First\n");
    SetColor(Border);
    printf(" 3");
    SetColor("Bright White");
    printf(".");
    SetColor(Text);
    printf(" Shortest Remaining Time\n");
    SetColor(Border);
    printf(" 4");
    SetColor("Bright White");
    printf(".");
    SetColor(Text);
    printf(" Preemptive Priority Scheduling Analysis\n");
    SetColor(Border);
    printf(" 5");
    SetColor("Bright White");
    printf(".");
    SetColor(Text);
    printf(" Non-Preemptive Priority Scheduling Analysis\n");
    SetColor(Border);
    printf(" 6");
    SetColor("Bright White");
    printf(".");
    SetColor(Text);
    printf(" Round Robin Scheduling \n");
    SetColor(Border);
    printf(" 7");
    SetColor("Bright White");
    printf(".");
    SetColor(Text);
    printf(" Exit\n");
    SetColor(Border);
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    printf(" Choice : ");
    SetColor(Text);
    scanf("%i",&x);

    switch(x){
        case 0: Compare();break;
        case 1: FCFS();
        printf("\n---- press enter ----");
        getch();
        break;
        case 2: SJF();
        printf("\n---- press enter ----");
        getch();
        break;
        case 3: SRTF();
        printf("\n---- press enter ----");
        getch();
        break;
        case 4: PP();
        printf("\n---- press enter ----");
        getch();
        break;
        case 5: NPP();
        printf("\n---- press enter ----");
        getch();
        break;
        case 6: RR();
        printf("\n---- press enter ----");
        getch();
        break;
        case 7: return 0;
    }

    return 1;

}





#endif // MENU_H
