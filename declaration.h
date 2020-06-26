#ifndef DECLARATION_H
#define DECLARATION_H
#define SIZE 50

typedef struct PROCESS{
    char name[SIZE][SIZE];
    int AT[SIZE];
    int BT[SIZE];
    int P[SIZE];
    int S[SIZE];
    int E[SIZE];
    int WT[SIZE];
    int RT[SIZE];
    int TAT[SIZE];
    int isProcess[SIZE];
    int isFirst[SIZE];

    int CPU_1[SIZE];
    int IO[SIZE];
    int CPU_2[SIZE];
    int isIODone[SIZE];

    int TQ;
    int size;
    int currentProcess;
}Process;


Process* new_Process(){
    Process *process = (Process*) malloc(sizeof(Process));
    return process;
}


#endif // DECLARATION_H
