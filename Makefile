CC = g++
CFLAGS = -Wall
LDFLAGS = -lm

all : patient parking

patient : PatientCharge.o
	$(CC) $(CFLAGS) PatientCharge.o $(LDFLAGS) -o patient

PatientCharge.o : PatientCharge.cpp
	$(CC) $(CFLAGS) -c PatientCharge.cpp

parking : ParkingTicketSimulator.o
	$(CC) $(CFLAGS) ParkingTicketSimulator.o $(LDFLAGS) -o parking

ParkingTicketSimulator.o : ParkingTicketSimulator.cpp
	$(CC) $(CFLAGS) -c ParkingTicketSimulator.cpp

clean :
	rm patient PatientCharge.o parking ParkingTicketSimulator.o