// ============================================================================================
// --------------------------------------------------------------------------------------------
// ============================================================================================
// Team:			4
// Programmer:		Jim, Nicholas, Ben, Kyle
// Class:			CS 3003; S/T: Topics in Data Structures
// Assignment #:	4
// Due Date:		10.April.2017
// Instructor:		Dr. Zhao
// Description:		Simulation of Airline Reservation System
//					<MORE DETAILS HERE>
//
// Notes:		Visual Basic 2015 [.NET] and MinGW
// Exit Codes:
//		0 = Successful operation
//		!0 = Errors; check Operating System ExitCode definitions
// ============================================================================================
// --------------------------------------------------------------------------------------------
// ============================================================================================


#pragma region Inclusions
#include <iostream>			// Used for Input and Output
#include "LinkedList.h"		// Link List header; containing the link list methodology.
#include "LinkedList.cpp"	// Implementations for emulating the Link List behaviors and procedures.
#pragma endregion


#pragma region Prototypes
void MainMenu();					// Displays a list of functionalities available to the end-user.
void Instructions();				// Provides instructions to the end-user.
char PromptUser_MainMenu();			// Fetch the STDIN from the end-user [keyboard or emulated keystrokes only]
void EvaluateAndRun(char, Node**);	// Inspect the user's input and try to run the request
void ClearBuffer();					// Thrash the terminal buffer.
#pragma endregion


// Main [Entry Point]
// ===============================================
// Documentation:
//	The main entry point for this program.
// ===============================================
int main()
{
	// Create a new instance of the link list; this is our primary list!
	Node* head;
	head = NULL;

	char userInput;				// This will be used for selected from the main menu.

	Instructions();				// Provide instructions to the user via terminal buffer.
	do // Main program
	{
		MainMenu();							// Provide the main menu to the end-user
		userInput = PromptUser_MainMenu();	// Capture the user's input
		std::cout << std::endl;				// Add a new line for readability
		EvaluateAndRun(userInput, &head);	// Try to execute the request
	} while (tolower(userInput) != 'x');	// Exit?

	return 0;					// Terminate
} // main()



// Instructions
// ===============================================
// Documentation:
//	Provide instructions to the user as to what this program is doing and how to use it.
// ===============================================
void Instructions()
{
	std::cout << "WELCOME TO BLUE-SKY AIRLINES!" << std::endl
		<< "Where we are dedicated to suckering you out of your money!" << std::endl
		<< "---------------------------------------------" << std::endl
		<< "This is a simulation program that provides some flexibility with" << std::endl
		<< "adjusting the link list and minor management tools.  With this program," << std::endl
		<< "it is possible to generate a reasonable size customer list and perform" << std::endl
		<< "maintenance as needed.  Such maintenance could be removing a customer," << std::endl
		<< "updating the customer's information, update reservations, change seats," << std::endl
		<< "and even revise customer's inflight meals!  Use the menu to navigate" << std::endl
		<< "through this program and try to crash it!  I dare you!" << std::endl
		<< "Looks like I picked the wrong week to quit sniffing glue. -Steve McCroskey"  // reference: https://youtu.be/VmW-ScmGRMA
		<< std::endl << std::endl;
} // Instructions()



// Main Menu
// ===============================================
// Documentation:
//	This function will provide a list of functionality that is available to the end-user.
// ===============================================
void MainMenu()
{
	// The border for the main menu screen
	std::cout << "Select an option:" << std::endl
		<< "====================" << std::endl;

	// Main menu options
	std::cout << "[1] - Automatically Generate a Customer List" << std::endl
		<< "[2] - Manually add a new customer" << std::endl
		<< "[3] - Print all customer information" << std::endl
		<< "[4] - Search for a passenger" << std::endl
		<< "[X] - Exit" << std::endl << std::endl;
} // MainMenu()



// Evaluate and Run
// ===============================================
// Documentation:
//	This will allow the user to perform the requested action, if STDIN is legal.
// -----------------------------------------------
// Parameters:
//	STDIN [char]
//		User's requested action
//	head [Node**]
//		Primary list that contains user info
// ===============================================
void EvaluateAndRun(char STDIN, Node** head)
{
	switch (STDIN)
	{
	case '1':	// Automatically generate customer list
		Autofill_List(head);
		break;
	case '2':	// Manually input customer
		ManualCustomerAdd(head);
		break;
	case '3':	// Print all customers [primary pointer]
		Print_Passenger_List(*head);
		break;
	case '4':
		FindPrintPassenger(*head);
		break;
	case 'X':	// Quietly pass through; exit
		break;
	case 'x':	// Quietly pass through; exit
		break;
	default:	// Bad Input
		std::cout << "Incorrect option!" << std::endl << std::endl;
		break;
	} // switch

	ClearBuffer();	// Provide spacing after evaluation
} // EvaluateAndRun()



// Prompt User [Main Menu]
// ===============================================
// Documentation:
//  Capture user input and return it as an integer.  By convention, use a python'ish input prompt.
//  From personal experience, this is more clear that the program is 'wanting' something from the user.
// -----------------------------------------------
// Output:
//  STDIN [Char]
//		Return the STDIN from the end-user.
// ===============================================
char PromptUser_MainMenu()
{
	char inputCapture = '-';		// If incase - to avoid bugs, use a default value.
	std::cout << ">>>>> ";			// The python'ish prompt
	std::cin >> inputCapture;		// Capture the input

	return inputCapture;			// Return the value.
} // PromptUser_MainMenu()



// Clear Buffer
// ===============================================
// This function, despite minimal, will try to make the buffer easier to read for the end user.
// ===============================================
void ClearBuffer()
{
	std::cout << std::endl
		<< std::endl
		<< std::endl
		<< std::endl
		<< std::endl
		<< std::endl;
} // ClearBuffer()