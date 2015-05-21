CC = g++
CFLAGS = -Wall
LDFLAGS = -lm

all : patient parking car

patient : PatientCharge.o
	$(CC) $(CFLAGS) PatientCharge.o $(LDFLAGS) -o patient

PatientCharge.o : PatientCharge.cpp
	$(CC) $(CFLAGS) -c PatientCharge.cpp

parking : ParkingTicketSimulator.o
	$(CC) $(CFLAGS) ParkingTicketSimulator.o $(LDFLAGS) -o parking

ParkingTicketSimulator.o : ParkingTicketSimulator.cpp
	$(CC) $(CFLAGS) -c ParkingTicketSimulator.cpp

car : CarInstrumentSimulator.o
	$(CC) $(CFLAGS) CarInstrumentSimulator.o $(LDFLAGS) -o car

CarInstrumentSimulator.o : CarInstrumentSimulator.cpp
	$(CC) $(CFLAGS) -c CarInstrumentSimulator.cpp

clean :
	rm patient PatientCharge.o parking ParkingTicketSimulator.o car CarInstrumentSimulator.o