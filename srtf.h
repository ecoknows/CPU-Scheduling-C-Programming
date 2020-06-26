#ifndef SRTF_H
#define SRTF_H
#include "declaration.h"
#include "dataentry.h"
#include "fcfs.h"
#define MIN 10000

void SRTF(){
    system("cls");
    SetColor("Yellow");
    printf(" %c%c%c%c%c%c%c%c%c%c%c",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    SetColor("Aqua");
    printf(" Shortest Remaining Time First Scheduling");
    SetColor("Yellow");
    printf(" %c%c%c%c%c%c%c%c%c%c%c\n\n",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    EnterDataWithCopy(1);
    processSRTF();
}

void SRTFToFCFS(){
    system("cls");
    SetColor("Yellow");
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    SetColor("Aqua");
    printf(" SRTF and FCFS");
    SetColor("Yellow");
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);

    EnterDataWithCopy(1);
    SetColor("Yellow");
    printf("\n\n %c%c%c%c%c%c%c%c%c%c%c%c%c",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    SetColor("Aqua");
    printf(" Shortest Remaining Time First Scheduling");
    SetColor("Yellow");
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    processSRTF();
    EnterData(0);
    SetColor("Yellow");
    printf("\n\n %c%c%c%c%c%c%c%c%c%c%c%c%c",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    SetColor("Aqua");
    printf(" First Come First Serve Scheduling");
    SetColor("Yellow");
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    processFCFS();
}

void processSRTF(){

    process->S[process->currentProcess] = process->AT[process->currentProcess];
    process->E[process->currentProcess] = process->AT[process->currentProcess];
    process->isFirst[process->currentProcess] = 0;
    int currentEnding = 0;
    int doneCnt = 0;
    int gant[50];
    int gantEnding[50];
    int gantSize = 0;
    int gantEndingSize = 0;
    gant[0] = process->currentProcess;
    gantEnding[0] = process->E[process->currentProcess];
    gantSize++;
    gantEndingSize++;

    while(1){
        int current = process->currentProcess;

        int minPos = 0;
        int minScore = 1000;

        for(int i = 0; i < process->size; i++){

            if(process->E[current] >= process->AT[i] && !process->isProcess[i] && current != i){

                if(processCPY->BT[current] > processCPY->BT[i] || processCPY->BT[current] == 0){

                    if(processCPY->BT[i] < minScore){
                        minScore = processCPY->BT[i];
                        minPos = i;
                    }

                }

            }
        }

        if(minScore != 1000){
            int pos = minPos;
            process->currentProcess = pos;
            if(process->isFirst[pos]){
                process->S[pos] = process->E[current];
                process->E[pos] = process->S[pos];
                process->isFirst[pos] = 0;
            }else{
                process->E[pos] = process->E[current];
            }


        }


        if(gant[gantSize-1] != current){
            gant[gantSize] = current;
            gantSize++;

            gantEnding[gantEndingSize] = process->E[current];
            gantEndingSize++;
        }

        if(doneCnt == process->size){
            gantEnding[gantEndingSize] = process->E[current];
            gantEndingSize++;
            break;
        }

        if(current == process->currentProcess){
            process->E[current]++;
            processCPY->BT[current]--;
            if(processCPY->BT[current] == 0){
                process->isProcess[current] = 1;
                doneCnt++;
            }

        }


    }



    float aWT = 0;
    float aRT = 0;
    float aTAT = 0;
    SetColor("Yellow");
    printf("\n\n %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    SetColor("Light Red");
    printf("\n\n NAME \t AT \t BT \t S \t E \t WT \t RT \t TAT\n\n");
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
               ,process->E[i],process->WT[i],process->RT[i],process->TAT[i]);
    }
    SetColor("Yellow");
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    printf("   \t   \t   \t   \t   \t %.2f \t %.2f \t %.2f \n\n", aWT/=(process->size) , aRT/=(process->size) ,aTAT/=(process->size) );



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

#endif // SRTF_H
