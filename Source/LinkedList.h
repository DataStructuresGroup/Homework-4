#ifndef __LinkedList__
#define __LinkedList__
// This merely holds the LinkedList struct.  The related functions can be located at:
//  LinkedList.cpp.


#pragma region Inclusions
// This is a temporary solution for now, this inclusion must be resolved before final submission!
//TODO Fix inclusion at header; std::string.  LinkList.h >> LinkList.cpp
	#include <string>
#pragma endregion


// Node Methodology:
// ======================
// |     DATA FIELDS    |
// | ------------------ |
// |     Next Node -->  |
// ======================


struct Node
{
	// Data within the node
	std::string nameFirst;		// Holds the passenger's first name
	std::string nameLast;		// Holds the passenger's last name
	int passengerID;			// Retains the passenger's ID
	int reservationNum;			// Retains the passenger's reservation number
	int telephoneNum;			// Holds the passenger's preferred phone number.
	int seatNum;				// Holds the passenger's seat number
	std::string mealType;		// What meal does the passenger want during the flight?
	bool checkedIn;				// Whether or not the passenger has checked in for the flight.

	//----

	// Next node
	Node* next;					// Point to the next node
};


// ================================
// --------------------------------
// ================================


struct Reservation
{
	Node* head;
	
	Reservation();
	
	void MainMenu();					// Displays a list of functionalities available to the end-user.
	void Instructions();				// Provides instructions to the end-user.
	char PromptUser_MainMenu();			// Fetch the STDIN from the end-user [keyboard or emulated keystrokes only]
	void EvaluateAndRun(char);	// Inspect the user's input and try to run the request
	void ClearBuffer();					// Thrash the terminal buffer.	
	
	
	void Print_Passenger_List(Node*, bool);
	void InsertNode(Node*);
	void CreateNewNode(std::string, std::string, int, int, int, int, std::string);
	int Autofill_List_Numbers(int);
	std::string Autofill_List_MealChoice();
	int GetSeatAvailable(int);
	void Autofill_List();
	std::string UserInput_String(bool);
	int UserInput_Number(bool);
	bool UserInput_Bool(bool);
	std::string ManualCustomerAdd_MealChoice();
	void ManualCustomerAdd();
	bool Search(Node**, Node**, int, std::string, int);
	void FindPrintPassenger();
	bool delete_node();
	void UpdatePassengerInformation();
	void CheckInPassenger();
	void Print_CheckIn_List();
	void Print_Meal_List();
	void Sort();
	bool Alphebetize(std::string, std::string);
};
#endif // !__LinkedList__
