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
	}

	friend std::ostream &operator<<(std::ostream &output,
		const ParkingTicket &ticket)
	{
		output << "\nCAR" << std::endl;
		output << "\tMake: " << ticket.make_ << std::endl;
		output << "\tModel: " << ticket.model_ << std::endl;
		output << "\tColor: " << ticket.color_ << std::endl;
		output << "\tLicense Plate: " << ticket.licensePlate_ << std::endl;
		output << "\tMinutes Parked: " << ticket.minutesParked_ << std::endl;

		output << "\nMETER" << std::endl;
		output << "\tMinutes Paid For: " << ticket.parkingTime_ << std::endl;

		output << "\nOFFICER" << std::endl;
		output << "\tName: " << ticket.officerName_ << std::endl;
		output << "\tBadge Number: " << ticket.officerBadgeNumber_ << std::endl;

		output << "\nFINE: " << std::endl;

		return output;
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

int main()
{

	ParkedCar car("Honda", "Accord", "White", "8LHS035", 90);
	ParkingMeter meter(30);
	PoliceOfficer officer("Jones", 1337);

	if(!officer.examineParking(car, meter))
	{
		ParkingTicket ticket = officer.issueTicket(&car, &meter);
		std::cout << ticket;
	}
	else
	{

	}

	return 0;
}