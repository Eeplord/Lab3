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

	ParkingTicket(const ParkedCar *car, const ParkingMeter *meter,
		std::string officerName, int officerBadgeNumber)
	{
		car_ = car;
		meter_ = meter;
		officerName_ = officerName;
		officerBadgeNumber_ = officerBadgeNumber;
	}

	ParkedCar getCar()
	{
		return car_;
	}

	ParkingMeter getMeter()
	{
		return meter_;
	}

	friend std::ostream &operator<<(std::ostream &output,
		const ParkingTicket &ticket)
	{
		output << "Car - " << std::endl;
		output << "\tMake: " << ticket.getCar()->getMake();
		output << "\tModel: " << ticket.getCar()->getModel();
		output << "\tColor: " << ticket.getCar()->getColor();
		output << "\tLicense Plate: " << ticket.getCar()->getLicensePlate() << std::endl;
	}

private:

	const ParkedCar *car_;
	const ParkingMeter *meter_;
	std::string officerName_;
	int officerBadgeNumber_;
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

	return 0;
}