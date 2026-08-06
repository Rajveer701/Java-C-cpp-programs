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

#define MAXINODE 5
#define MAXFILESIZE 50
#define MAXOPENFILES 5

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
    //Marvellous CVFS : > man exit
    if(strcmp(Name,"exit") == 0){
        printf("About : It is used to terminate the project\n");
        printf("Usage : exit\n");
    }
    //Marvellous CVFS : > man ls
    else if(strcmp(Name,"ls") == 0){
        printf("About : It is used to list all files from current directory\n");
        printf("Usage : ls\n");
    }
    //Marvellous CVFS : > man clear
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
// Function Name :      IsFileExist()
// Description :        It is used to check whether the
//                      file is present or not      
// Input :              Name of File
// Output :             True if present
//                      False if not present
// Author :             Rajveer Rajput
// Date :               1/08/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool IsFileExist(
        char name[]        //name of file
    )
{
    PINODE temp = head;
    bool bFlag = false;

    while(temp!=NULL){
        if(strcmp(temp->FileName,name) == 0){
            bFlag = true;
            break;
        }
        temp = temp->next;
    }

    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :      CreateFile()
// Description :        It is used to create a new file      
// Input :              Name of File & Permissions
// Output :             File Descriptor
// Author :             Rajveer Rajput
// Date :               1/08/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CreateFile(
        char name[],        //name of file
        int permission      // File Permission
    )
{   
    int i = 0;
    PINODE temp = head;

    if(superobj.FreeInodes == 0){
        return ERR_NO_INODES;
    }
    
    // If permission value is wrong
    // Permission = 1 -> READ
    // Permission = 2 -> WRITE
    // Permission = 3 -> READ + WRITE
    if(permission < 1 || permission > 3){
        return ERR_INVALID_PARAMETER;
    }

    if(IsFileExist(name) == true){
        return ERR_FILE_ALREADY_EXIST;
    }

    // Search for empty Inode
    while(temp != NULL){
        if(temp->FileType == 0){
            break;
        }

        temp = temp->next;
    }
    
    // Rare case
    if(temp == NULL){
        return ERR_NO_INODES; 
    }

    // Search empty UFDT entry
    // Reserve first 3 FDs
    for(i = 3;i<MAXINODE;i++){
        if(uareaobj.UFDT[i] == NULL){
            break;
        }
    }

    if(i == MAXOPENFILES){
        return ERR_MAX_FILES_OPENED;
    }

    // Allocate memory for file table

    uareaobj.UFDT[i] = (PFILETABLE)malloc(sizeof(FILETABLE));

    // Intialise File Table
    uareaobj.UFDT[i]->ReadOffset = 0;
    uareaobj.UFDT[i]->WriteOffset = 0;
    uareaobj.UFDT[i]->Mode = permission;
    
    // Connect File Table with Inode
    uareaobj.UFDT[i]->ptrInode = temp;


    // Initialise all members of Inode
    strcpy(uareaobj.UFDT[i]->ptrInode->FileName,name);

    uareaobj.UFDT[i]->ptrInode->FileSize = MAXFILESIZE;
    
    uareaobj.UFDT[i]->ptrInode->ActualFileSize = 0;

    uareaobj.UFDT[i]->ptrInode->FileType = REGULARFILE;

    uareaobj.UFDT[i]->ptrInode->RefernceCount = 1;

    uareaobj.UFDT[i]->ptrInode->Permission = permission;

    // Allocate menory for Files Data(Data Block)

    uareaobj.UFDT[i]->ptrInode->Buffer = (char *)malloc(MAXFILESIZE);

    superobj.FreeInodes--;

    return i;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :      LsFile()
// Description :        It is used to display names 
//                      of all files
// Input :              None
// Output :             None
// Author :             Rajveer Rajput
// Date :               1/08/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LsFile(){
    PINODE temp = head;

    printf("----------------------------------------------\n");
    printf("---- Marvellous CVFS Files Information ----\n");
    printf("----------------------------------------------\n");

    while(temp!=NULL){
        if(temp->FileType != 0){
            printf("%s\n",temp->FileName);
        }

        temp = temp->next;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :      LsFile_All()
// Description :        It is used to display all 
//                      details of all files
// Input :              None
// Output :             None
// Author :             Rajveer Rajput
// Date :               2/08/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LsFile_All(){
    PINODE temp = head;

    printf("----------------------------------------------\n");
    printf("---- Marvellous CVFS Files Information ----\n");
    printf("----------------------------------------------\n");

    printf("FileName    InodeNumber    FileSize\n");
    while(temp!=NULL){
        if(temp->FileType != 0){
            printf("%s\t %d\t %d\t\n",temp->FileName,temp->InodeNumber,temp->ActualFileSize);
        }

        temp = temp->next;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :      stat_File()
// Description :        It is used to display  
//                      all details of specific file
// Input :              File Name
// Output :             Exit status of the function
// Author :             Rajveer Rajput
// Date :               2/08/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int stat_file(char name[]){
    PINODE temp = NULL;
    int Permission = 0;
    int Type = 0;

    if(IsFileExist(name) == false){
        return ERR_FILE_NOT_EXIST;
    }

    temp = head;

    while(temp!=NULL){
        if(strcmp(temp->FileName,name) == 0){
            printf("----------------------------------------------\n");
            printf("------- Statistical Information of File ------\n");
            printf("----------------------------------------------\n");

            //Logic
            printf("File Name : %s\n",temp->FileName);

            printf("Inode number : %d\n",temp->InodeNumber);

            printf("File Size : %d\n",temp->FileSize);

            printf("Actual File Size : %d\n",temp->ActualFileSize);

            printf("Refernce Count : %d\n",temp->RefernceCount);

            Permission = temp->Permission;

            if(Permission == READ){
                printf("File Permission : Read Only \n");
            }
            else if(Permission == WRITE){
                printf("File Permission : Write Only \n");
            }
            else if(Permission == READ + WRITE){
                printf("File Permission : Read + Write \n");
            }

            Type = temp->FileType;

            if(Type == REGULARFILE){
                printf("File Type : Regular File \n");
            }
            else if(Type == SPECIALFILE){
                printf("File Type : Special File \n");
            }

            printf("----------------------------------------------\n");
            
            break;
        }
        temp = temp->next;
    }
    return EXECUTE_SUCCESS;
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
            //Marvellous CVFS : > exit
            if(strcmp(Command[0],"exit") == 0){
                printf("Thank you for using Marvellous CVFS\n");
                printf("Deallocationg all resources of Marvellous CVFS\n");
                break;
            }
            //Marvellous CVFS : > help
            else if(strcmp(Command[0],"help") == 0){
                DisplayHelp();
            }
            //Marvellous CVFS : > clear
            else if(strcmp(Command[0],"clear") == 0){
                #ifdef _WIN32
                    system("cls")
                #else 
                    system("clear");
                #endif
            }
            //Marvellous CVFS : > ls
            else if(strcmp(Command[0],"ls") == 0){
                LsFile();
            }
            else{
                printf("Command not found\n");
                printf("Please refer help option to get more information\n");
                printf("Please refer manual page of command using man\n");
            }
        }
        else if(iCount == 2){
            //Marvellous CVFS : > man open
            if(strcmp(Command[0],"man") == 0){
                ManPageDisplay(Command[1]);
            }
            //Marvellous CVFS : > ls -a
            else if((strcmp(Command[0],"ls") == 0) && (strcmp(Command[1],"-a") == 0)){
                LsFile_All();
            }
            //Marvellous CVFS : > stat filename(stat Ganesh.txt)
            else if(strcmp(Command[0],"stat") == 0){
                iRet = stat_file(Command[1]);
                if(iRet == ERR_FILE_NOT_EXIST){
                    printf("Error : File does not exist\n");
                }
            }
            else{
                printf("Command not found\n");
                printf("Please refer help option to get more information\n");
                printf("Please refer manual page of command using man\n");
            }
        }
        else if(iCount == 3){
            //Marvellous CVFS : > creat Ganesh.txt 3
            if(strcmp(Command[0],"creat") == 0){
                iRet = CreateFile(Command[1],atoi(Command[2]));

                if(iRet == ERR_NO_INODES){
                    printf("Error : Unable to create new file\n");
                    printf("Because there is no free Inode\n");
                }
                else if(iRet == ERR_INVALID_PARAMETER){
                    printf("Error : Unable to create new file\n");
                    printf("Because parameters of command are invalid\n");
                    printf("Please use man page to get actual parameters\n");
                }
                else if(iRet == ERR_FILE_ALREADY_EXIST){
                    printf("Error : Unable to create new file\n");
                    printf("Because the file name is already present\n");
                    printf("Please use ls command to check names of all files\n");
                }
                else if(iRet == ERR_MAX_FILES_OPENED){
                    printf("Error : Unable to create new file\n");
                    printf("Because the UFDT is full\n");
                    printf("Please close some opened files\n");
                }
                else{
                    printf("File succesfully created with FD : %d\n",iRet);
                }
            }
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