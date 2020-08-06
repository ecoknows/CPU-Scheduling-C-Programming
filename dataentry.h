#ifndef DATAENTRY_H
#define DATAENTRY_H
#include "declaration.h"

Process* process;
Process *processCPY;

char *Text = "Yellow";
char *inp = "Aqua";

void InstantiateProcess(){
    process = new_Process();
    processCPY = new_Process();
}
void EnterData(int x){
    if(x){
        SetColor("Yellow");
        printf(" how many process? > ");
        SetColor(inp);
        scanf("%i", &process->size);

        SetColor("Yellow");
        printf("\n\n (");
        SetColor("Bright White");
        printf("example input");
        SetColor("Yellow");
        printf(")");
        inputText();
        printf("P1 0 10\n\n\n");


    }
    int minAt = 10000;

    for(int i = 0; i < process->size; i++){
        if(x){
            inputText();
            scanf("%s%i%i",&process->name[i],&process->AT[i],&process->BT[i]);
        }
        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }

        process->isProcess[i] = 0;
    }
}

void EnterDataSJF(int x){

    if(x){
        SetColor("Yellow");
        printf(" how many process? > ");
        SetColor(inp);
        scanf("%i", &process->size);

        SetColor("Yellow");
        printf("\n\n (");
        SetColor("Bright White");
        printf("example input");
        SetColor("Yellow");
        printf(")");
        inputText();
        printf("P1 0 10\n\n\n");
    }

    int minAt = 10000;

    for(int i = 0; i < process->size; i++){
        if(x){
            inputText();
            scanf("%s%i%i",&process->name[i],&process->AT[i],&process->BT[i]);
        }

        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }else if (process->AT[i] == minAt){
            if(process->BT[i] < process->BT[process->currentProcess]){
                minAt = process->AT[i];
                process->currentProcess = i;
            }
        }

        process->isProcess[i] = 0;
    }
}

void EnterDataPriority(int x){
    if(x){
        SetColor("Yellow");
        printf(" how many process? > ");
        SetColor(inp);
        scanf("%i", &process->size);

        SetColor("Yellow");
        printf("\n\n (");
        SetColor("Bright White");
        printf("example input");
        SetColor("Yellow");
        printf(")");
        inputTextPriority();
        printf("P1 0 10 3\n\n\n");
    }
    int minAt = 10000;

    for(int i = 0; i < process->size; i++){
        if(x){
            inputTextPriority();
            scanf("%s%i%i%i",&process->name[i],&process->AT[i],&process->BT[i], &process->P[i]);
        }
        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }else if (process->AT[i] == minAt){
            if(process->BT[i] < process->BT[process->currentProcess]){
                minAt = process->AT[i];
                process->currentProcess = i;
            }
        }

        process->isProcess[i] = 0;
    }
}

void EnterDataWithCopy(int x){
    if(x){
        SetColor("Yellow");
        printf(" how many process? > ");
        SetColor(inp);
        scanf("%i", &process->size);

        SetColor("Yellow");
        printf("\n\n (");
        SetColor("Bright White");
        printf("example input");
        SetColor("Yellow");
        printf(")");
        inputText();
        printf("P1 0 10\n\n\n");
    }
    int minAt = 10000;

    for(int i = 0; i < process->size; i++){
        if(x){
            inputText();
            scanf("%s%i%i",&process->name[i],&process->AT[i],&process->BT[i]);
        }
        processCPY->BT[i] = process->BT[i];

        process->isProcess[i] = 0;
        process->isFirst[i] = 1;

        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }else if (process->AT[i] == minAt){
            if(process->BT[i] < process->BT[process->currentProcess]){
                minAt = process->AT[i];
                process->currentProcess = i;
            }
        }

        process->isProcess[i] = 0;
    }
}


void EnterDataWithCopyPriority(){
    SetColor("Yellow");
    printf(" how many process? > ");
    SetColor(inp);
    scanf("%i", &process->size);

    SetColor("Yellow");
    printf("\n\n (");
    SetColor("Bright White");
    printf("example input");
    SetColor("Yellow");
    printf(")");
    inputTextPriority();
    printf("P1 0 10 3\n\n\n");

    int minAt = 10000;

    for(int i = 0; i < process->size; i++){
        inputTextPriority();
        scanf("%s%i%i%i",&process->name[i],&process->AT[i],&process->BT[i],&process->P[i]);
        processCPY->BT[i] = process->BT[i];

        process->isProcess[i] = 0;
        process->isFirst[i] = 1;

        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }else if (process->AT[i] == minAt){
            if(process->BT[i] < process->BT[process->currentProcess]){
                minAt = process->AT[i];
                process->currentProcess = i;
            }
        }

        process->isProcess[i] = 0;
    }
}


void EnterDataWithCopyRR(){
    SetColor("Yellow");
    printf(" how many process? > ");
    SetColor(inp);
    scanf("%i", &process->size);
    SetColor("Yellow");
    printf(" time quantumn? > ");
    SetColor("Aqua");
    scanf("%i", &process->TQ);
    SetColor("Yellow");
    printf("\n\n (");
    SetColor("Bright White");
    printf("example input");
    SetColor("Yellow");
    printf(")");
    inputText();
    printf("P1 0 10\n\n\n");

    int minAt = 10000;

    for(int i = 0; i < process->size; i++){
        inputText();
        scanf("%s%i%i",&process->name[i],&process->AT[i],&process->BT[i]);
        processCPY->BT[i] = process->BT[i];
        processCPY->AT[i] = process->AT[i];

        process->isProcess[i] = 0;
        process->isFirst[i] = 1;

        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }else if (process->AT[i] == minAt){
            if(process->BT[i] < process->BT[process->currentProcess]){
                minAt = process->AT[i];
                process->currentProcess = i;
            }
        }

        process->isProcess[i] = 0;
    }
}

/*
    WITH I/O Burst
*/


void EnterDataIOBurst(){
    SetColor("Yellow");
    printf(" how many process? > ");
    SetColor(inp);
    scanf("%i", &process->size);

    SetColor("Yellow");
    printf("\n\n (");
    SetColor("Bright White");
    printf("example input");
    SetColor("Yellow");
    printf(")");
    inputTextIOBurst();
    printf("P1 0 10 5 6 7\n\n\n");

    int minAt = 10000;

    for(int i = 0; i < process->size; i++){
        inputTextIOBurst();
        scanf("%s%i%i%i%i",&process->name[i],&process->AT[i],&process->CPU_1[i], &process->IO[i], &process->CPU_2[i]);


        processCPY->AT[i] = process->AT[i];

        process->isFirst[i] = 1;
        process->isIODone[i] = 0;


        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }

        process->isProcess[i] = 0;
    }
}

void EnterDataIOBurstSJF(int x){
    if(x){
        SetColor("Yellow");
        printf(" how many process? > ");
        SetColor(inp);
        scanf("%i", &process->size);

        SetColor("Yellow");
        printf("\n\n (");
        SetColor("Bright White");
        printf("example input");
        SetColor("Yellow");
        printf(")");
        inputTextIOBurst();
        printf("P1 0 10 5 6 7\n\n\n");
    }

    int minAt = 10000;

    for(int i = 0; i < process->size; i++){
        if(x){
            inputTextIOBurst();
            scanf("%s%i%i%i%i",&process->name[i],&process->AT[i],&process->CPU_1[i], &process->IO[i], &process->CPU_2[i]);
        }

        processCPY->AT[i] = process->AT[i];

        process->isFirst[i] = 1;
        process->isIODone[i] = 0;


        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }else if (process->AT[i] == minAt){
            if(process->CPU_1[i] < process->CPU_1[process->currentProcess]){
                minAt = process->AT[i];
                process->currentProcess = i;
            }
        }

        process->isProcess[i] = 0;
    }
}

void EnterDataPriority_IOBurst(){
    SetColor("Yellow");
    printf(" how many process? > ");
    SetColor(inp);
    scanf("%i", &process->size);

    SetColor("Yellow");
    printf("\n\n (");
    SetColor("Bright White");
    printf("example input");
    SetColor("Yellow");
    printf(")");
    inputTextIOBurstPriority();
    printf("P1 0 10 5 6 7 3\n\n\n");

    int minAt = 10000;

    for(int i = 0; i < process->size; i++){
        inputTextIOBurstPriority();
        scanf("%s%i%i%i%i%i",&process->name[i],&process->AT[i],&process->CPU_1[i],&process->IO[i],&process->CPU_2[i], &process->P[i]);


        processCPY->AT[i] = process->AT[i];

        process->isFirst[i] = 1;
        process->isIODone[i] = 0;

        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }else if (process->AT[i] == minAt){
            if(process->BT[i] < process->BT[process->currentProcess]){
                minAt = process->AT[i];
                process->currentProcess = i;
            }
        }

        process->isProcess[i] = 0;
    }
}

void inputText(){
        SetColor("Yellow");
        printf("\n Input");
        printf(" (");
        SetColor("Light Aqua");
        printf(" Process Name");
        SetColor("Bright White");
        printf(",");
        SetColor("Light Red");
        printf(" AT");
        SetColor("Bright White");
        printf(",");
        SetColor("Light Green");
        printf(" BT");
        SetColor("Yellow");
        printf(" )\n");
        printf(" > ");
        SetColor("Aqua");
}

void inputTextPriority(){
        SetColor("Yellow");
        printf("\n Input");
        printf(" (");
        SetColor("Light Aqua");
        printf(" Process Name");
        SetColor("Bright White");
        printf(",");
        SetColor("Light Red");
        printf(" AT");
        SetColor("Bright White");
        printf(",");
        SetColor("Light Green");
        printf(" BT");
        SetColor("Bright White");
        printf(",");
        SetColor("White");
        printf(" P");
        SetColor("Yellow");
        printf(" )\n");
        printf(" > ");
        SetColor("Aqua");
}


void inputTextIOBurstPriority(){
        SetColor("Yellow");
        printf("\n Input");
        printf(" (");
        SetColor("Light Aqua");
        printf(" Process Name");
        SetColor("Bright White");
        printf(",");
        SetColor("Light Red");
        printf(" AT");
        SetColor("Bright White");
        printf(",");
        SetColor("Light Green");
        printf(" CPU");
        SetColor("Bright White");
        printf(",");
        SetColor("Light Yellow");
        printf(" IO");
        SetColor("Bright White");
        printf(",");
        SetColor("Light Green");
        printf(" CPU");
        SetColor("Bright White");
        printf(",");
        SetColor("White");
        printf(" P");
        SetColor("Yellow");
        printf(" )\n");
        printf(" > ");
        SetColor("Aqua");
}

void inputTextIOBurst(){
        SetColor("Yellow");
        printf("\n Input");
        printf(" (");
        SetColor("Light Aqua");
        printf(" Process Name");
        SetColor("Bright White");
        printf(",");
        SetColor("Light Red");
        printf(" AT");
        SetColor("Bright White");
        printf(",");
        SetColor("Light Green");
        printf(" CPU");
        SetColor("Bright White");
        printf(",");
        SetColor("Light Yellow");
        printf(" IO");
        SetColor("Bright White");
        printf(",");
        SetColor("Light Green");
        printf(" CPU");
        SetColor("Yellow");
        printf(" )\n");
        printf(" > ");
        SetColor("Aqua");
}



#endif // DATAENTRY_H
