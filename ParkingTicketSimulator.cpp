// CIS22B
// Lab3
// Cameron March
// ParkingTicketSimulator.cpp

#include <iostream>
#include <string>

class ParkedCar
{
public:

	ParkedCar(std::string make, std::string model, std::string color,
		std::string licensePlate, int minutesParked)
	{
		make_ = make;
		model_ = model;
		color_ = color;
		licensePlate_ = licensePlate;
		minutesParked_ = minutesParked;
	}

	std::string getMake()
	{
		return make_;
	}

	std::string getModel()
	{
		return model_;
	}

	std::string getColor()
	{
		return color_;
	}

	std::string getLicensePlate()
	{
		return licensePlate_;
	}

	int getMinutesParked()
	{
		return minutesParked_;
	}

private:

	std::string make_;
	std::string model_;
	std::string color_;
	std::string licensePlate_;
	int minutesParked_;
};


class ParkingMeter
{
public:

	ParkingMeter(int parkingTime)
	{
		parkingTime_ = parkingTime;
	}

	int getParkingTime()
	{
		return parkingTime_;
	}

private:

	int parkingTime_;
};

class ParkingTicket
{
public:

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

class PoliceOfficer
{
public:

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

	ParkingTicket issueTicket(ParkedCar *car, ParkingMeter *meter)
	{
		ParkingTicket ticket(car, meter, name_, badgeNumber_);
		return ticket;
	}

private:

	std::string name_;
	int badgeNumber_;
};

void issueTicket(ParkedCar *car, ParkingMeter *meter, PoliceOfficer *officer);
void runSample();
void runCustom();

int main()
{
	char input;

	std::cout << "Welcome to Parking Ticket Simulator.\n" << std::endl;
	
	do
	{
		std::cout << "[1] Sample\n" << "[2] Custom\n" << "[q] Quit" <<
			std::endl; 

		std::cin >> input;

		switch(input)
		{
			case '1':
				runSample();
				break;

			case '2':
				runCustom();
				break;

			case 'q':
				std::cout << "Quitting..." << std::endl;
				break;

			default:
				std::cout << input << " is not a recognized command." <<
					std::endl;
				break;
		}
	}while(input != 'q');

	return 0;
}

void issueTicket(ParkedCar *car, ParkingMeter *meter, PoliceOfficer *officer)
{
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

	ParkedCar car(make, model, color, plate, minutesParked);
	ParkingMeter meter(minutesPaid);
	PoliceOfficer officer(name, badge);

	issueTicket(&car, &meter, &officer);
}