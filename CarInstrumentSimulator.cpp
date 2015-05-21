// CIS22B
// Lab3
// Cameron March
// CarInstrumentSimulator.cpp

#include <iostream>

class FuelGauge
{
public:

	FuelGauge(int tankSize)
	{
		amount_ = 0;
		tankSize_ = tankSize;
	}

	FuelGauge()
	{
		amount_ = 0;
		tankSize_ = 15;
	}

	int getAmount()
	{
		return amount_;
	}

	int getTankSize()
	{
		return tankSize_;
	}

	void fill()
	{
		if(amount_ < tankSize_)
		{
			amount_++;
		}
	}

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

class Odometer
{
public:

	Odometer(int mileage)
	{
		mileage_ = mileage;
	}

	Odometer()
	{
		mileage_ = 0;
	}

	int getMileage()
	{
		return mileage_;
	}

	void increment(int miles)
	{
		mileage_ += miles;

		if(mileage_ >= 1000000)
		{
			mileage_ -= 1000000;
		}
	}

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
	int mpg, tankSize;
	char input;
	bool quit = false;

	std::cout << "Welcome to Car Instrument Simulator." << std::endl;
	std::cout << "What is your car's mpg? ";
	std::cin >> mpg;
	std::cout << "What is the size of your car's gas tank? ";
	std::cin >> tankSize;

	FuelGauge gauge(tankSize);
	Odometer odometer(0);

	while(!quit)
	{
		std::cout << "\nYou have travelled " << odometer.getMileage() <<
			" miles." << std::endl;
		std::cout << "[1] Fill up and drive\n[2] Take a break" << std::endl;
		std::cin >> input;

		switch(input)
		{
			case '1':
				std::cout << "Filling tank..." << std::endl;
				for(int i = 0; i < tankSize; i++)
				{
					gauge.fill();
				}

				std::cout << "Driving..." << std::endl;

				while(gauge.getAmount() > 0)
				{
					odometer.drive(&gauge, mpg);
					std::cout << "\n\tOdometer: " << odometer.getMileage() <<
						" mi Gas Tank: " << gauge.getAmount() << " gallons" <<
						std::endl;
				}

				break;

			case '2':
				quit = true;
				break;

			default:
				std::cout << "I don't recognize that command." << std::endl;
				break;
		}
	}

	return 0;
}
