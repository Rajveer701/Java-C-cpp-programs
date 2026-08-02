////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Header Files inclusion
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdbool.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// User Defined Macros
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MAXINODE 10
#define MAXFILESIZE 50
#define MAXOPENFILES 10

#define READ 1
#define WRITE 2
#define EXECUTE 4

#define START 0
#define CURRENT 1
#define END 2

#define EXECUTE_SUCCESS 0

#define REGULARFILE 1
#define SPECIALFILE 2

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// User Defined Macros for Error Handling
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define ERR_INVALID_PARAMETER -1

#define ERR_NO_INODES -2

#define ERR_FILE_ALREADY_EXIST -3
#define ERR_FILE_NOT_EXIST -4

#define ERR_PERMISSION_DENIED -5

#define ERR_INSUFFICENT_SPACE -6
#define ERR_INSUFFICIENT_DATA -7

#define ERR_MAX_FILES_OPENED -8

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Stucture Name : BootBlock
// Description : It holds the infomation to 
//               boot(start) the Operating System 
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct BootBlock{
    char Information[100];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Stucture Name : SuperBlock
// Description : It holds the info of 
//               complete file system
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct SuperBlock{
    int TotalInodes;
    int FreeInodes;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Stucture Name : Inode
// Description : It holds infomation of file
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

struct Inode{
    char FileName[20];
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int FileType;
    int RefernceCount;          //no. of instances currently accessing the file
    int Permission;
    char *Buffer;
    struct Inode *next;
};

typedef struct Inode INODE;     //I --> indexed
typedef struct Inode* PINODE;
typedef struct Inode** PPINODE;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Stucture Name : FileTable
// Description : It holds the information of  
//               opened files
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

struct FileTable{
    int ReadOffset;
    int WriteOffset;
    int Mode;
    PINODE ptrInode;
};

typedef struct FileTable FILETABLE;
typedef struct FileTable* PFILETABLE;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Stucture Name : UAREA
// Description : It holds the information of process 
//               
////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct UAREA{
    char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Global Variables used in the project
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct BootBlock bootobj;
struct SuperBlock superobj;
struct UAREA uareaobj;

PINODE head = NULL;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :      IntialiseUAREA()
// Description :        It is used to intialise UREA
// Author :             Rajveer Rajput
// Date :               31/07/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InitialiseUREA(){
    int i = 0;

    strcpy(uareaobj.ProcessName,"Myexe");

    for(i=0;i<MAXOPENFILES;i++){
        uareaobj.UFDT[i] = NULL;
    }

    printf("Marvellous CVFS : UAREA gets intialised successfully\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :      IntialiseSuperBlock()
// Description :        It is used to intialise Super Block
// Author :             Rajveer Rajput
// Date :               31/07/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void IntialiseSuperBlock(){
    superobj.TotalInodes = MAXINODE;
    superobj.FreeInodes = MAXINODE;

    printf("Marvellous CVFS : SuperBlock gets intialised successfully\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :      CreateDILB()
// Description :        It is used to create linked list of Inodes
// Author :             Rajveer Rajput
// Date :               31/07/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CreateDILB(){
    int i = 0;
    PINODE temp = NULL;
    PINODE newn = NULL;

    temp = head;

    for(i=1;i<=MAXINODE;i++){
        newn = (PINODE)malloc(sizeof(INODE));

        newn->InodeNumber = i;
        strcpy(newn->FileName,"\0");
        newn->FileSize = 0;
        newn->ActualFileSize = 0;
        newn->FileType = 0;
        newn->Permission = 0;
        newn->RefernceCount = 0;
        newn->Buffer = NULL;
        newn->next = NULL;

        if(temp == NULL){
            head = newn;
            temp = head;
        }
        else{
            temp->next = newn;
            temp = temp->next;
        }
    }

    printf("Marvellous CVFS : DILB created successfully\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :      StartAuxillaryDataInitialisation()
// Description :        It is used to call all such func 
//                      which are used to initialise auxillary data
// Author :             Rajveer Rajput
// Date :               31/07/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void StartAuxillaryDataInitialisation(){
    strcpy(bootobj.Information,"Booting process of Marvellous CVFS is completed");

    printf("%s\n",bootobj.Information);
    InitialiseUREA();

    IntialiseSuperBlock();

    CreateDILB();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :      DisplayHelp()
// Description :        It is used to display help 
//                      to the user of project
// Author :             Rajveer Rajput
// Date :               1/08/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DisplayHelp(){
    printf("----------------------------------------------\n");
    printf("--------- Marvellous CVFS Help Page  ---------\n");
    printf("----------------------------------------------\n");

    printf("man : It is used to display the manual page\n");
    printf("clear : It is used to clear the terminal screen\n");
    printf("creat : It is used to create new regular file\n");
    printf("open : It is used to open regular file\n");
    printf("close : It is used to close regular file\n");
    printf("write : It is used to write the data into the file\n");
    printf("read : It is used to read the data from the file\n");
    printf("stat : It is used to display statistical information of the file\n");    
    printf("unlink : It is used to delete the file\n");    
    printf("exit : It is used to terminate Marvellous CVFS\n");    


    printf("----------------------------------------------\n");

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :      ManPageDisplay()
// Description :        It is used to display man page
//                      of specific command
// Input :              Name of Command
// Author :             Rajveer Rajput
// Date :               1/08/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManPageDisplay(char Name[]){
    if(strcmp(Name,"exit") == 0){
        printf("About : It is used to terminate the project\n");
        printf("Usage : exit\n");
    }
    else if(strcmp(Name,"ls") == 0){
        printf("About : It is used to list all files from current directory\n");
        printf("Usage : ls\n");
    }
    else if(strcmp(Name,"clear") == 0){
        printf("About : It is used to clear the terminal\n");
        printf("Usage : clear\n");
    }
    else{
        printf("No manual entry found for %s\n",Name);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Entry point function of CVFS project
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    char str[80] = {'\0'};
    char Command[5][20] = {{'\0'}};

    int iRet = 0,iCount = 0;

    StartAuxillaryDataInitialisation();

    printf("----------------------------------------------\n");
    printf("---- Marvellous CVFS started successfully ----\n");
    printf("----------------------------------------------\n");

    //Infinite Listening Shell

    while(1){
        fflush(stdin);

        strcpy(str,"");
        
        printf("\nMarvellous CVFS : > ");
        fgets(str,sizeof(str),stdin);

        iCount = sscanf(str,"%s %s %s %s %s",Command[0],Command[1],Command[2],Command[3],Command[4]);

        fflush(stdin);

        if(iCount == 1){
            if(strcmp(Command[0],"exit") == 0){
                printf("Thank you for using Marvellous CVFS\n");
                printf("Deallocationg all resources of Marvellous CVFS\n");
                break;
            }
            else if(strcmp(Command[0],"help") == 0){
                DisplayHelp();
            }
            else if(strcmp(Command[0],"clear") == 0){
                #ifdef _WIN32
                    system("cls")
                #else 
                    system("clear");
                #endif
            }
            else{
                printf("Command not found\n");
                printf("Please refer help option to get more information\n");
                printf("Please refer manual page of command using man\n");
            }
        }
        else if(iCount == 2){
            if(strcmp(Command[0],"man") == 0){
                ManPageDisplay(Command[1]);
            }
            else{
                printf("Command not found\n");
                printf("Please refer help option to get more information\n");
                printf("Please refer manual page of command using man\n");
            }
        }
        else if(iCount == 3){
            
        }
        else if(iCount == 4){
            
        }
        else{
            printf("Command not found\n");
            printf("Please refer help option to get more information\n");
            printf("Please refer manual page of command using man\n");
        }
    } //end of while

    return 0;
} //end of main