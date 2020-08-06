#ifndef NPP_H
#define NPP_H
#include "declaration.h"
#include "dataentry.h"
#define MIN 10000

void NPP(){
    system("cls");
    SetColor("Yellow");
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    SetColor("Aqua");
    printf(" Non-Preemptive Priorirty Scheduling");
    SetColor("Yellow");
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    char c = 'N';
    printf("Does have an I/O burst [Y/N] ? ");
    scanf("%s", &c);
    if(c == 'Y' || c == 'y'){
        EnterDataPriority_IOBurst();
        processNPP_IOBurst();
    }else{
        EnterDataPriority(1);
        processNPP();
    }
}

void processNPP(){

    process->S[process->currentProcess] = process->AT[process->currentProcess];
    process->E[process->currentProcess] = process->BT[process->currentProcess];
    process->isProcess[process->currentProcess] = 1;


    int gant[50];
    int gantEnding[50];
    int gantSize = 0;
    int gantEndingSize = 0;
    gantEnding[0] = process->AT[process->currentProcess];
    gantEndingSize++;

    while(1){
        int current = process->currentProcess;
        int currentEnding = process->E[current];

        int isProcess = 1;
        int minPos = -1;
        int isIdle = 0;
        int minP = MIN;
        int minAT = MIN;


        for(int i = 0; i < process->size; i++){
            if(process->E[current] >= process->AT[i] && i != current && !process->isProcess[i]){
                if(process->P[i] < minP){
                    minP = process->P[i];
                    minPos = i;
                }
            }


            if(!process->isProcess[i]){
                isProcess = 0;
            }

        }


        if(!isProcess && minPos == -1){
            for(int i = 0; i < process->size; i++){
                if(minAT > process->AT[i] && i != current && !process->isProcess[i] ){
                    minAT = process->AT[i];
                    minPos = i;
                }
            }

            /*
            printf("minPos : %i, minP : %i", minPos , minBT);
            char c;
            scanf("%s",&c);*/
            currentEnding = minAT;
            isIdle = 1;
        }

        if(isProcess){
            gant[gantSize] = current;
            gantSize++;

            gantEnding[gantEndingSize] = process->E[current];
            gantEndingSize++;
            /*
            for(int i = 0; i < gantEndingSize; i++){
                printf("gant : %i , gantEnding : %i \n", gant[i], gantEnding[i]);
            }*/
            break;
        }

        process->S[minPos] = currentEnding;
        process->E[minPos] = currentEnding +  process->BT[minPos];
        process->isProcess[minPos] = 1;
        process->currentProcess = minPos;



        gant[gantSize] = current;
        gantSize++;

        gantEnding[gantEndingSize] = process->E[current];
        gantEndingSize++;

        if(isIdle){
            gant[gantSize] = -1;
            gantSize++;
            gantEnding[gantEndingSize] = minAT;
            gantEndingSize++;
        }

    }


    float aWT = 0;
    float aRT = 0;
    float aTAT = 0;
    SetColor("Yellow");
    printf("\n\n %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    SetColor("Light Red");
    printf("\n\n NAME \t AT \t BT \t P \t S \t E \t WT \t RT \t TAT\n\n");
    SetColor("Bright White");
    for(int i = 0; i < process->size; i++){

        process->WT[i] = process->S[i] - process->AT[i];
        process->RT[i] = process->S[i] - process->AT[i];
        process->TAT[i] = process->E[i] - process->AT[i];
        aWT += (float) process->WT[i];
        aRT += (float) process->RT[i];
        aTAT += (float) process->TAT[i];


        printf(" %s \t %i \t %i \t %i \t %i \t %i \t %i \t %i \t %i \n",
               process->name[i], process->AT[i], process->BT[i],process->P[i], process->S[i]
               ,process->E[i],process->WT[i],process->RT[i],process->TAT[i]);
    }
    SetColor("Yellow");
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    printf("   \t   \t   \t  \t  \t   \t %.2f \t %.2f \t %.2f \n\n", aWT/=(process->size) , aRT/=(process->size) ,aTAT/=(process->size) );



    for(int i = 0; i < gantSize; i++){

        SetColor("Light Red");

        if(i != gantSize-1){
           int space = gantEnding[i+1] - gantEnding[i];
           int adj_space = strlen(process->name[gant[i]]) + 1 + space;
           int space_start = adj_space/2;

           for(int x = 0; x < space_start; x++){
             printf(" ");
           }

           if(gant[i] == -1)
             printf("?");
           else
             printf("%s",process->name[gant[i]]);

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

void processNPP_IOBurst(){
    process->S[process->currentProcess] = process->AT[process->currentProcess];
    process->E[process->currentProcess] = process->AT[process->currentProcess] + process->CPU_1[process->currentProcess];
    processCPY->AT[process->currentProcess] = process->E[process->currentProcess] + process->IO[process->currentProcess];
    process->isIODone[process->currentProcess] = 1;

    int gant[50];
    int gantEnding[50];
    int gantSize = 0;
    int gantEndingSize = 0;
    gantEnding[0] = process->AT[process->currentProcess];
    gantEndingSize++;

   while(1){
        int current = process->currentProcess;
        int currentEnding = process->E[current];

        int isProcess = 1;
        int minPos = -1;
        int minP = MIN;
        int isIdle = 0;

        for(int i = 0; i < process->size; i++){

        /*
            printf("i : %i, current : %i , Ending : %i , AT : %i , Process : %i \n",i, current, process->E[current], processCPY->AT[i], process->isProcess[i]);
            char c;
            scanf("%s",&c);*/

            if(process->E[current] >= processCPY->AT[i] && i != current && !process->isProcess[i]){
                if(process->P[i] < minP){
                    minP = process->P[i];
                    minPos = i;

                    printf("minPossss : %i \n", minPos);
                }
            }

            if(!process->isProcess[i]){
                isProcess = 0;
            }

        }
        int minAt = 10000;

        if(!isProcess && minPos == -1){
            for(int i = 0; i < process->size; i++){
                if(processCPY->AT[i] < minAt && !process->isProcess[i]){
                    minAt = processCPY->AT[i];
                    minPos = i;
                }
            }

            /*
            printf("minPos : %i, minP : %i", minPos , minP);
            char c;
            scanf("%s",&c);*/
            currentEnding = minAt;
            isIdle = 1;
        }


        if(isProcess){
            gant[gantSize] = current;
            gantSize++;

            gantEnding[gantEndingSize] = process->E[current];
            gantEndingSize++;
            /*
            for(int i = 0; i < gantEndingSize; i++){
                printf("gant : %i , gantEnding : %i \n", gant[i], gantEnding[i]);
            }*/
            break;
        }

        if(!process->isIODone[minPos]){
            process->S[minPos] = currentEnding;
            process->E[minPos] = currentEnding +  process->CPU_1[minPos];
            processCPY->AT[minPos] = process->E[minPos] + process->IO[minPos];
            process->isIODone[minPos] = 1;
            process->currentProcess = minPos;
            //printf("XName: %s, S = %i, E = %i\n", process->name[minPos],process->S[minPos],process->E[minPos]);
        }else{
            process->E[minPos] = currentEnding + process->CPU_2[minPos];
            process->isProcess[minPos] = 1;
            process->currentProcess = minPos;
           // printf("YName: %s, S = %i, E = %i\n", process->name[minPos],process->S[minPos],process->E[minPos]);
        }


        gant[gantSize] = current;
        gantSize++;

        gantEnding[gantEndingSize] = process->E[current];
        gantEndingSize++;

        if(isIdle){
            gant[gantSize] = -1;
            gantSize++;
            printf("minEnd = %i \n", process->E[current]);
            printf("minAt = %i \n", minAt);
            gantEnding[gantEndingSize] = minAt;
            gantEndingSize++;
        }

        /*
        printf("min = %i \n", minPos);
        for(int i = 0; i < process->size; i++){

            printf("P%i = %i\n",i+1 , process->isProcess[i]);
        }
        char c;
        scanf("%s",&c);*/


    }


    float aWT = 0;
    float aRT = 0;
    float aTAT = 0;
    SetColor("Yellow");
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    SetColor("Light Red");
    printf("\n\n NAME \t AT \t CPU,I/O,CPU \t P \t S \t E \t WT \t RT \t TAT\n\n");
    SetColor("Bright White");
    for(int i = 0; i < process->size; i++){

        process->RT[i] = process->S[i] - process->AT[i];
        process->TAT[i] = process->E[i] - process->AT[i];
        process->WT[i] = process->TAT[i] - ( process->CPU_1[i] + process->IO[i] + process->CPU_2[i] );
        aWT += (float) process->WT[i];
        aRT += (float) process->RT[i];
        aTAT += (float) process->TAT[i];


        printf(" %s \t %i \t %i,%i,%i  \t %i \t %i \t %i \t %i \t %i \t %i \n",
               process->name[i], process->AT[i], process->CPU_1[i],process->IO[i],process->CPU_2[i],process->P[i],process->S[i]
               ,process->E[i],process->WT[i],process->RT[i],process->TAT[i]);
    }
    SetColor("Yellow");
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2);
    printf("   \t   \t      \t\t  \t  \t   \t %.2f \t %.2f \t %.2f \n\n", aWT/=(process->size) , aRT/=(process->size) ,aTAT/=(process->size) );



    for(int i = 0; i < gantSize; i++){

        SetColor("Light Red");

        if(i != gantSize-1){
           int space = gantEnding[i+1] - gantEnding[i];
           int adj_space = 5 + space;
           int space_start = adj_space/2;

           if(gant[i] != -1){
            adj_space = strlen(process->name[gant[i]]) + 1 + space;
            space_start = adj_space/2;
           }

           for(int x = 0; x < space_start; x++){
             printf(" ");
           }

           if(gant[i] == -1)
             printf("?");
           else
             printf("%s",process->name[gant[i]]);

           for(int x = 0; x < adj_space-space_start-1; x++){
             printf(" ");
           }
        }else{
           int space = gantEnding[i] - gantEnding[i-1];
           int adj_space =  5 + space;
           int space_start = adj_space/2;

           if(gant[i] != -1){
            adj_space = strlen(process->name[gant[i]]) + 1 + space;
            space_start = adj_space/2;
           }

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
            int length = 3 + space;
            if(gant[i] != -1)
             length = strlen(process->name[gant[i]]) + 1 + space;

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

#endif // NPP_H
