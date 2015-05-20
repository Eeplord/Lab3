// CIS22B
// Lab3
// Cameron March
// PatientCharge.cpp

#include <iostream>

// Overloaded function prototype for in-patient
double calculateCharges(double days, double rate, double servicesCharge,
	double medicationCharge);

// Overloaded function prototype for out-patient
double calculateCharges(double servicesCharge, double medicationCharge);

// Checks for negative input
bool checkInput(double input);

// Overloaded function that assigns user input to in-patient variables
void getPatientInput(double *days, double *rates, double *servicesCharge,
	double *medicationCharge);

// Overloaded function that assigns user input to out-patient variables
void getPatientInput(double *servicesCharge, double *medicationCharge);

// Main menu logic
int main()
{
	// Initializing variables
	char input;
	double days, rates, servicesCharge, medicationCharge, totalCharges;
	bool quit = false;

	// Introduction
	std::cout << "Welcome to Patient Payment Handler." <<
		" Enter (q) to quit." << std::endl;	

	// Loop until user quits or finishes data entry
	while(!quit)
	{
		// Ask if user is an in-patient or an out-patient
		std::cout << "Are you an in-patient (i) or an out-patient (o)? ";
		std::cin >> input;

		// Selection handling
		switch(input)
		{
			// Handling of the in-patient case
			case 'i':

				getPatientInput(&days, &rates, &servicesCharge,
					&medicationCharge);

				// Calculating charges using overloaded function
				totalCharges = calculateCharges(days, rates, servicesCharge,
					medicationCharge);

				// Display charges to user
				std::cout << "\nYour charges are: $" << totalCharges <<
					"\n" << std::endl;

				// Quitting the program
				quit = true;
				break;

			// Handling of the out-patient case
			case 'o':

				// Pass addresses to assign inputs to charges
				getPatientInput(&servicesCharge, &medicationCharge);

				// Calculating charges using overloaded function
				totalCharges = calculateCharges(servicesCharge,
					medicationCharge);

				// Display charges to user
				std::cout << "\nYour charges are: $" << totalCharges <<
					"\n" << std::endl;

				// Quitting the program
				quit = true;
				break;

			// Option to quit without entering information
			case 'q':

				quit = true;
				break;

			// Handling invalid input
			default:
				std::cout << "Not a valid input." << std::endl;
				break;
		}
	}

	return 0;
}

// Calculates charges for in-patients
double calculateCharges(double days, double rate, double servicesCharge,
	double medicationCharge)
{
	return (days * rate) + calculateCharges(servicesCharge, medicationCharge);
}

// Calculates charges for out-patients
double calculateCharges(double servicesCharge, double medicationCharge)
{
	return servicesCharge + medicationCharge;
}

// Checks that if an input is negative and sends a message.
// Returns true if input is negative and false if it is positive.
bool checkInput(double input)
{
	if(input < 0.0)
	{
		std::cout << "Input cannot be negative." << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

// Uses pointers to let user assign valid inputs for in-patient charges
void getPatientInput(double *days, double *rate, double *servicesCharge,
	double *medicationCharge)
{
	bool negativeInput = true;

	// Looping until we get a non-negative number of days
	while(negativeInput)
	{
		std::cout << "How many days did you stay? ";
		std::cin >> *days;
		negativeInput = checkInput(*days);
	}

	negativeInput = true;

	// Looping until we get a non-negative rate
	while(negativeInput)
	{
		std::cout << "What is the daily rate? ";
		std::cin >> *rate;
		negativeInput = checkInput(*rate);
	}

	// Using overloaded out-patient function to assign
	// values to the services and medication charges
	getPatientInput(servicesCharge, medicationCharge);
}

// Uses pointers to let user assign valid inputs for out-patient charges
void getPatientInput(double *servicesCharge, double *medicationCharge)
{
	bool negativeInput = true;				

	// Looping until we get a non-negative hospital charge
	while(negativeInput)
	{
		std::cout << "What are the hospital service charges? ";
		std::cin >> *servicesCharge;
		negativeInput = checkInput(*servicesCharge);
	}

	negativeInput = true;	

	// Looping until we get a non-negative medication charge
	while(negativeInput)
	{
		std::cout << "What are the medication charges? ";
		std::cin >> *medicationCharge;
		negativeInput = checkInput(*medicationCharge);
	}
}