// CIS22B
// Lab3
// Cameron March
// ParkingTicketSimulator.cpp

#include <iostream>
#include <string>

// Class to simulate a park car. Stores all the information needed
class ParkedCar
{
public:

	// Constructor
	ParkedCar(std::string make, std::string model, std::string color,
		std::string licensePlate, int minutesParked)
	{
		make_ = make;
		model_ = model;
		color_ = color;
		licensePlate_ = licensePlate;
		minutesParked_ = minutesParked;
	}

	// Returns make
	std::string getMake()
	{
		return make_;
	}

	// Returns model
	std::string getModel()
	{
		return model_;
	}

	// Returns color
	std::string getColor()
	{
		return color_;
	}

	// Returns license plate
	std::string getLicensePlate()
	{
		return licensePlate_;
	}

	// Returns minutes parked
	int getMinutesParked()
	{
		return minutesParked_;
	}

private:

	// Private stored variables
	std::string make_;
	std::string model_;
	std::string color_;
	std::string licensePlate_;
	int minutesParked_;
};

// Class simulates a parking meter and stores minutes paid for
class ParkingMeter
{
public:

	// Constructor
	ParkingMeter(int parkingTime)
	{
		parkingTime_ = parkingTime;
	}

	// Returns time paid for
	int getParkingTime()
	{
		return parkingTime_;
	}

private:

	// Private stored variable
	int parkingTime_;
};

// Simulates a parking ticket. Stores information on car, meter and officer.
// Has a method that prints the ticket.
class ParkingTicket
{
public:

	// Constructor takes pointers to car, meter, and officer objects
	ParkingTicket(ParkedCar *car, ParkingMeter *meter,
		std::string officerName, int officerBadgeNumber)
	{
		make_ = car->getMake();
		model_ = car->getModel();
		color_ = car->getColor();
		licensePlate_ = car->getLicensePlate();
		minutesParked_ = car->getMinutesParked();
		parkingTime_ = meter->getParkingTime();
		officerName_ = officerName;
		officerBadgeNumber_ = officerBadgeNumber;

		int timeOver = minutesParked_ - parkingTime_;
		int hours = 0;

		if(timeOver % 60 > 0)
		{
			hours = 1;
		}

		hours += (timeOver / 60) - 1;
		charge_ = 25 + 10 * hours;
	}

	// Prints the ticket out in a human-readable format
	void display()
	{
		std::cout << "\nCAR" << std::endl;
		std::cout << "\tMake: " << make_ << std::endl;
		std::cout << "\tModel: " << model_ << std::endl;
		std::cout << "\tColor: " << color_ << std::endl;
		std::cout << "\tLicense Plate: " << licensePlate_ << std::endl;
		std::cout << "\tMinutes Parked: " << minutesParked_ << std::endl;

		std::cout << "\nMETER" << std::endl;
		std::cout << "\tMinutes Paid For: " << parkingTime_ << std::endl;

		std::cout << "\nOFFICER" << std::endl;
		std::cout << "\tName: " << officerName_ << std::endl;
		std::cout << "\tBadge Number: " << officerBadgeNumber_ << std::endl;

		std::cout << "\nFINE: $" << charge_ << "\n" << std::endl;
	}

private:

	// Private stored variables
	std::string make_;
	std::string model_;
	std::string color_;
	std::string licensePlate_;
	std::string officerName_;
	int officerBadgeNumber_;
	int minutesParked_;
	int parkingTime_;
	int charge_;
};

// Simulates a police officer. Stores name and badge number.
class PoliceOfficer
{
public:

	// Constructor
	PoliceOfficer(std::string name, int badgeNumber)
	{
		name_ = name;
		badgeNumber_ = badgeNumber;
	}

	// Returns true if parked legally and false if parked illegally
	bool examineParking(ParkedCar car, ParkingMeter meter)
	{
		if(car.getMinutesParked() > meter.getParkingTime())
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	// Writes a parking ticket and returns it
	ParkingTicket issueTicket(ParkedCar *car, ParkingMeter *meter)
	{
		ParkingTicket ticket(car, meter, name_, badgeNumber_);
		return ticket;
	}

private:

	// Private stored variables
	std::string name_;
	int badgeNumber_;
};

// Function prototypes
void issueTicket(ParkedCar *car, ParkingMeter *meter, PoliceOfficer *officer);
void runSample();
void runCustom();

// Main menu logic
int main()
{
	// Input variable
	char input;

	std::cout << "Welcome to Parking Ticket Simulator.\n" << std::endl;
	
	// Menu loop
	do
	{
		std::cout << "[1] Sample\n" << "[2] Custom\n" << "[q] Quit" <<
			std::endl; 

		std::cin >> input;

		switch(input)
		{
			// Prints out a premade example of the program in action
			case '1':
				runSample();
				break;

			// Allows the user to enter their own variables and
			// view the results.
			case '2':
				runCustom();
				break;

			// Quits the program
			case 'q':
				std::cout << "Quitting..." << std::endl;
				break;

			// Catches unrecognized inputs
			default:
				std::cout << input << " is not a recognized command." <<
					std::endl;
				break;
		}
	}while(input != 'q');

	return 0;
}

// Logic for issuing a ticket. If the car is parked illegaly it runs the 
// ticket.display() function. Otherwise it prints 'no ticket issued'.
void issueTicket(ParkedCar *car, ParkingMeter *meter, PoliceOfficer *officer)
{
	// Checking if a ticket needs to  be written
	if(!officer->examineParking(*car, *meter))
	{
		std::cout << "Ticket Issued" << std::endl;
		ParkingTicket ticket = officer->issueTicket(car, meter);
		ticket.display();
	}
	else
	{
		std::cout << "No Ticket Issued" <<std::endl;
	}
}

// Prints a premade example of the program in action
void runSample()
{
	std::cout << "Officer Jones spots a white Honda Accord at a parking" <<
		" meter flashing the words 'Time Expired'. Checking his notes, he" <<
		" sees the car has been parked for 130 minutes. The policeman takes" <<
		" out his notebook and pen.\n" << std::endl; 

	ParkedCar car1("Honda", "Accord", "White", "8LHS035", 130);
	ParkingMeter meter1(30);
	PoliceOfficer officer1("Jones", 1337);

	issueTicket(&car1, &meter1, &officer1);

	std::cout << "On the other side of town, a black Bugati Veyron" <<
		" catches the eyes of Officer Martin. Checking the parking" <<
		" meter, he sees there are still 20 minutes remaining, and" <<
		" his notes tell him the car has been parked for 70 minutes." <<
		" Officer Martin keeps his ticket pad in his pocket as he" <<
		" admires the car.\n" << std::endl;

	ParkedCar car2("Bugati", "Veyron", "Black", "2FST4ME", 50);
	ParkingMeter meter2(70);
	PoliceOfficer officer2("Martin", 4201);

	issueTicket(&car2, &meter2, &officer2);
}

// Asks user for input then writes a ticket if needed
void runCustom()
{
	std::string make;
	std::string model;
	std::string color;
	std::string plate;
	int minutesParked;

	int minutesPaid;

	std::string name;
	int badge;

	std::cout << "Car's Make: ";
	std::cin >> make;
	std::cout << "Car's Model: ";
	std::cin >> model;
	std::cout << "Car's Color: ";
	std::cin >> color;
	std::cout << "Plate Number: ";
	std::cin >> plate;
	std::cout << "Minutes Parked: ";
	std::cin >> minutesParked;

	std::cout << "Minutes Paid For: ";
	std::cin >> minutesPaid;

	std::cout << "Officer's Name: ";
	std::cin >> name;
	std::cout << "Badge Number: ";
	std::cin >> badge;

	// Creating the objects based on user input
	ParkedCar car(make, model, color, plate, minutesParked);
	ParkingMeter meter(minutesPaid);
	PoliceOfficer officer(name, badge);

	// Issueing a ticket if necessary
	issueTicket(&car, &meter, &officer);
}