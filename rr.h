#ifndef RR_H
#define RR_H
#include "declaration.h"
#include "dataentry.h"
#define MIN 10000

void RR(){
    system("cls");
    SetColor("Yellow");
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    SetColor("Aqua");
    printf(" Round Robin Scheduling");
    SetColor("Yellow");
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    EnterDataWithCopyRR();
    processRR();
}

void processRR(){
int burst = (process->TQ <= processCPY->BT[process->currentProcess]) ? process->TQ : processCPY->BT[process->currentProcess];
    process->S[process->currentProcess] = process->AT[process->currentProcess];
    process->E[process->currentProcess] = process->AT[process->currentProcess] + burst;
    processCPY->AT[process->currentProcess] = process->E[process->currentProcess];
    processCPY->BT[process->currentProcess]-= burst;
    process->isFirst[process->currentProcess] = 0;

      //  printf("FIRST Current = %i, S = %i , E = %i, AT = %i, BT = %i, \n",process->currentProcess, process->S[process->currentProcess]
    //,process->E[process->currentProcess], processCPY->AT[process->currentProcess],processCPY->BT[process->currentProcess] );

    int gant[50];
    int gantEnding[50];
    int gantSize = 0;
    int gantEndingSize = 0;
    gant[0] = process->currentProcess;
    gantSize++;
    gantEnding[0] = process->S[process->currentProcess];
    gantEndingSize++;
    gantEnding[1] = process->E[process->currentProcess];
    gantEndingSize++;


    int doneCnt = 0;

    while(1){
        int current = process->currentProcess;



        int minPos = 0;
        int minScore = 1000;

        for(int i = 0; i < process->size; i++){

                  //  printf("hey = %i, e = %i, at = %i size = %i \n",i,process->E[current],processCPY->AT[i], process->size);
            if(process->E[current] >= processCPY->AT[i] && current != i){
                  //  printf("hey = %i, e = %i, at = %i size = %i \n",i,process->E[current],processCPY->AT[i], process->size);
                if(processCPY->AT[i] < minScore && processCPY->BT[i] != 0){
                    minScore = processCPY->AT[i];
                    minPos = i;
                }
            }
        }



        if(minScore != 1000){
            int pos = minPos;

            int bet = (process->TQ <= processCPY->BT[pos]) ?process->TQ : processCPY->BT[pos];
           // printf("%i bet= %i\n", pos, bet);
            if(process->isFirst[pos]){
                process->S[pos] = process->E[current];
                process->isFirst[pos] = 0;
            }
            process->E[pos] = process->E[current] + bet;
            processCPY->AT[pos] = process->E[pos];
            processCPY->BT[pos] -= bet;
            process->currentProcess = pos;

        }


        if(processCPY->BT[current] == 0){
            doneCnt++;
        }


        if(gant[gantSize-1] != current){
            gant[gantSize] = current;
            gantSize++;

            gantEnding[gantEndingSize] = process->E[current];
            gantEndingSize++;
        }


        if(doneCnt == process->size){
            break;
        }


        /*
        int c = ' ';
        printf("Current = %i, S = %i , E = %i, AT = %i, BT = %i, minPos = %i ",current, process->S[current]
               ,process->E[current], process->AT[current],processCPY->BT[current], minPos);
        scanf("%s",&c);*/

    }


    SetColor("Yellow");
    printf("\n\n TIME QUANTUM ");
    SetColor("Bright White");
    printf(" > ");
    SetColor("Aqua");
    printf("%i",process->TQ);

    float aWT = 0;
    float aRT = 0;
    float aTAT = 0;
    SetColor("Yellow");
    printf("\n\n %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    SetColor("Light Red");
    printf("\n\n NAME \t AT \t BT \t S \t E \t RT \t WT \t TAT\n\n");
    SetColor("Bright White");
    for(int i = 0; i < process->size; i++){

        process->RT[i] = process->S[i] - process->AT[i];
        process->TAT[i] = process->E[i] - process->AT[i];
        process->WT[i] = process->TAT[i] - process->BT[i];
        aWT += (float) process->WT[i];
        aRT += (float) process->RT[i];
        aTAT += (float) process->TAT[i];


        printf(" %s \t %i \t %i \t %i \t %i \t %i \t %i \t %i \n",
               process->name[i], process->AT[i], process->BT[i], process->S[i]
               ,process->E[i],process->RT[i],process->WT[i],process->TAT[i]);
    }
    SetColor("Yellow");
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    printf("   \t   \t   \t   \t   \t %.2f \t %.2f \t %.2f \n\n",aRT/=(process->size),aWT/=(process->size) ,aTAT/=(process->size) );


    for(int i = 0; i < gantSize; i++){

        SetColor("Light Red");

        if(i != gantSize-1){
           int space = gantEnding[i+1] - gantEnding[i];
           int adj_space = strlen(process->name[gant[i]]) + 1 + space;
           int space_start = adj_space/2;

           for(int x = 0; x < space_start; x++){
             printf(" ");
           }

           printf("%s", process->name[gant[i]]);

           for(int x = 0; x < adj_space-space_start-1; x++){
             printf(" ");
           }
        }else{
           int space = gantEnding[i] - gantEnding[i-1];
           int adj_space = strlen(process->name[gant[i]]) + 1 + space;
           int space_start = adj_space/2;

           for(int x = 0; x < space_start; x++){
             printf(" ");
           }

           printf("%s", process->name[gant[i]]);
        }



    }

    printf("\n");

    for(int i = 0; i < gantEndingSize; i++){

        if(i != gantEndingSize-1){
            SetColor("Yellow");
            int space = gantEnding[i+1] - gantEnding[i];
            printf("%i",gantEnding[i]);
            if(gantEnding[i] > 9)
                space--;
            int length = strlen(process->name[gant[i]]) + 1 + space;
            SetColor("Bright White");
            for(int x = 0; x < length; x++){
                printf("-");
            }
        }else{
            SetColor("Yellow");
            printf("%i",gantEnding[i]);
        }

    }

    printf("\n");

}


#endif // RR_H
