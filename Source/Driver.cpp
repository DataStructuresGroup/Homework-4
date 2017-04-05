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



// Main
// ================
// The main entry point for this program.
int main()
{
	// OOP: Uncomment when these instructions are ready for invoktion.
	// Reservation bluesky;
	// bluesky.start();

	Node* head;
	head = NULL;

	Autofill_List(&head); // Autofill
	Print_Passenger_List(head); // provide a list
	system("PAUSE"); // stop the terminal from closing immediately
	return 0;
} // main()