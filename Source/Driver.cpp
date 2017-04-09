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
#include <stdlib.h>			// Used for the rand() function
#include <time.h>			// Used for the srand() funtion
#include "LinkedList.h"		// Link List header; containing the link list methodology.

// DEPRECATED [VS LNK2005 <!>]
 #include "LinkedList.cpp"	// Implementations for emulating the Link List behaviors and procedures.
								// I have commented this out as I am hitting LNK2005 issues with this statement.
								//  It seems with the OOP merge, the LNK behavior has changed.  With that
								//  I have commented this out so I can compile this project.  If anyone else
								//  depends on this one call, please let me know and I'll try to work around
								//  the issue.
// ----
#pragma endregion



// Main [Entry Point]
// ===============================================
// Documentation:
//	The main entry point for this program.
// ===============================================
int main()
{
	// Because we want serious randomness in this lousy program!
	srand(time(NULL));

	// Create a new instance of the link list; this is our primary list!
	Reservation BSA;
	
	
	if(BSA.Alphebetize("peadtb", "peadta")){std::cout << "WEEEEEEE!" << std::endl;}
	
	
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
