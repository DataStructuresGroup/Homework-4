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



// Main [Entry Point]
// ===============================================
// Documentation:
//	The main entry point for this program.
// ===============================================
int main()
{
	// Create a new instance of the link list; this is our primary list!
	Reservation BSA;

	char userInput;				// This will be used for selected from the main menu.

	BSA.Instructions();				// Provide instructions to the user via terminal buffer.
	do // Main program
	{
		BSA.MainMenu();							// Provide the main menu to the end-user
		userInput = BSA.PromptUser_MainMenu();	// Capture the user's input
		std::cout << std::endl;				// Add a new line for readability
		BSA.EvaluateAndRun(userInput);	// Try to execute the request
	} while (tolower(userInput) != 'x');	// Exit?

	return 0;					// Terminate
} // main()