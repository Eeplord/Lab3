// CIS22B
// Lab3
// Cameron March
// CarInstrumentSimulator.cpp

#include <iostream>

// FuelGauge class trakcs the size of the cars tank and how much fuel is in it.
// It can add fuel to the maximum tank size and remove fuel to 0.
class FuelGauge
{
public:

	// Constructor
	FuelGauge(int tankSize)
	{
		amount_ = 0;
		tankSize_ = tankSize;
	}

	// Default constructor
	FuelGauge()
	{
		amount_ = 0;
		tankSize_ = 15;
	}

	// Returns amount of fuel in tank
	int getAmount()
	{
		return amount_;
	}

	// Returns maximum tank size
	int getTankSize()
	{
		return tankSize_;
	}

	// Add 1 gallon to the amount of fuel, but won't surpass maximum tank size
	void fill()
	{
		if(amount_ < tankSize_)
		{
			amount_++;
		}
	}

	// Removes 1 gallon from the amount of fuel, but won't go below 0
	void empty()
	{
		if(amount_ > 0)
		{
			amount_--;
		}
	}

private:

	int amount_;
	int tankSize_;
};

// Odometer class tracks the amount of miles driven. It can also subtract 1
// gallon from a FuelGauge object and add the car's miles per gallons to
// its travel distance.
class Odometer
{
public:

	// Constructor
	Odometer(int mileage)
	{
		mileage_ = mileage;
	}

	// Default constructor
	Odometer()
	{
		mileage_ = 0;
	}

	// Returns total number of miles travelled
	int getMileage()
	{
		return mileage_;
	}

	// Increases total number of miles travelled by the given parameter.
	// If mileage goes over 1,000,000, the counter rolls over and continues
	// from zero.
	void increment(int miles)
	{
		mileage_ += miles;

		if(mileage_ >= 1000000)
		{
			mileage_ -= 1000000;
		}
	}

	// Removes 1 gallon from the FuelGauge object and travels one unit
	// of the car's miles per gallon.
	void drive(FuelGauge *fuel, int mpg)
	{
		fuel->empty();
		this->increment(mpg);
	}

private:

	int mileage_;
};

int main()
{
	// Instantiating variables
	int mpg, tankSize;
	char input;
	bool quit = false;

	// Introduction and collecting data on car
	std::cout << "Welcome to Car Instrument Simulator." << std::endl;
	std::cout << "What is your car's mpg? ";
	std::cin >> mpg;
	std::cout << "What is the size of your car's gas tank? ";
	std::cin >> tankSize;

	// Creating the FuelGauge and Odometer objects
	FuelGauge gauge(tankSize);
	Odometer odometer(0);

	// Main menu loop
	while(!quit)
	{
		// Tell the user their current distance travelled and ask what they
		// want to do next.
		std::cout << "\nYou have travelled " << odometer.getMileage() <<
			" miles." << std::endl;
		std::cout << "[1] Fill up and drive\n[2] Take a break" << std::endl;
		std::cin >> input;

		switch(input)
		{
			// Fill the gas tank to maximum capacity and drive the car until
			// empty, showing what distance was travelled per gallon.
			case '1':
				std::cout << "Filling tank..." << std::endl;

				// Fill car to maximum tank size
				for(int i = 0; i < tankSize; i++)
				{
					gauge.fill();
				}

				std::cout << "Driving..." << std::endl;

				// Drive until empty
				while(gauge.getAmount() > 0)
				{
					odometer.drive(&gauge, mpg);

					// Show user distance after each gallon
					std::cout << "\n\tOdometer: " << odometer.getMileage() <<
						" mi Gas Tank: " << gauge.getAmount() << " gallons" <<
						std::endl;
				}

				break;

			// Quit the program
			case '2':
				quit = true;
				break;

			// Catch unused inputs
			default:
				std::cout << "I don't recognize that command." << std::endl;
				break;
		}
	}

	return 0;
}
