/*
 * Scheduling of process and threads
 * 
 * Copyright 2018 Guilherme Silva
 */

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio_ext.h>

// Defines
#ifdef linux
	#define OS "linux"
#endif
#ifdef _WIN32
	#define OS "windows"
#endif

#define MIN_NUMBER_OF_PROCESSES 2
#define MAX_NUMBER_OF_PROCESSES 3

// Type definitions
typedef struct Process
{
	int i_start;
	int i_duration;
}Process;
	

// Declaration of functions 
void start();
char menu();
void schedule(char c_option);
int getNumberOfProcesses();
void getValuesOfProcesses(Process *Processes, int i_numOfProcesses);
char FIFO();
char LIFO();
char SJF();
void clearScreen();
void flushBuffer();
char clearMemory();
void showProcesses();
void exitProgram();

int main(int argc, char **argv)
{
	start();
	return 0;
}

// Definition of functions
void start()
{
	schedule(menu());
}

// Show the menu and return the option that has choosed
char menu()
{
	char c_input = 0;
	
	puts("Scheduling of process and threads");
	puts("---------------------------------");
	puts("Choose one of the options bellow:");
	do
	{
		puts("[1] FIFO");
		puts("[2] LIFO");
		puts("[3] SJF");
		puts("[4] Clear memory");
		puts("[5] Show processes/threads list");
		puts("[0] Exit");
		scanf("%s", &c_input);
	}while(c_input < '0' || c_input > '5');
	clearScreen();
	return c_input;
}

// Receive the menu option and start the schedule 
void schedule(char c_option)
{
	int i_numOfProcesses = getNumberOfProcesses();
    Process *Processes = malloc(sizeof(Process) * i_numOfProcesses);
	
	getValuesOfProcesses(Processes, i_numOfProcesses);
	
	
	switch(c_option)
	{
		case '1':
			//FIFO();
			break;
		case '2':
			//LIFO();
			break;
		case '3':
			//SJF();
			break;
		case '4':
			//clearMemory();
			break;
		case '5':
			//showProcesses();
			break;
		case '0':
			exitProgram();
			break;
	}
}

// Get and return the number of processes to a pointer
int getNumberOfProcesses()
{
	int i_input = 0;
	do
	{
		puts("\nPlease, enter the number of processes/threads: ");
		printf("The number must be between %d and %d.\n",MIN_NUMBER_OF_PROCESSES, MAX_NUMBER_OF_PROCESSES); 
		scanf("%d", &i_input);
	}while(i_input < MIN_NUMBER_OF_PROCESSES || i_input > MAX_NUMBER_OF_PROCESSES); 
	return i_input;
}	

// Get the value of the proccesses
void getValuesOfProcesses(Process *Processes, int i_numOfProcesses)
{
	unsigned char uc_count = 0;
	puts("Insert the data of the processes/threads correctly: ");
	while(uc_count < i_numOfProcesses)
	{
		puts("---------------------");
		printf("Process/Thread %d:\n", uc_count+1);
		printf("\tStart: ");
		scanf("%d", Processes[uc_count]->i_start);
		printf("\tDuration: ");
		scanf("%d", Processes[uc_count++].i_duration);
	}
	
}	
// Clear the prompt according with the OS
void clearScreen()
{
	if(strcmp(OS, "linux") == 0)
	{
		system("clear");
	}
	else if(strcmp(OS, "windows") == 0)
	{
		system("cls");
	}
}

// Flush the buffer according with the OS
// This function can flush input and ouput buffer
void flushBuffer(char *c_typeBuffer)
{
	/// It is not working
	if(strcmp(OS, "linux") == 0)
	{
		if(strcmp(c_typeBuffer, "stdin") == 0)
		{
			__fpurge(stdin);		
		}
		else if(strcmp(c_typeBuffer, "stdout"))
		{
			
			__fpurge(stdout);
			
		}
	}
	else if(strcmp(OS, "windows") == 0)
	{
		if(strcmp(c_typeBuffer, "stdin") == 0)
		{
			fflush(stdin);
		}
		else if(strcmp(c_typeBuffer, "stdout"))
		{
			fflush(stdout);
		}
	}

}



// Exit the program
void exitProgram()
{
	puts("Exiting...");
	system("exit");
}


