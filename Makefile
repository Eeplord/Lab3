CC = g++
CFLAGS = -Wall
LDFLAGS = -lm

all : patient

patient : patientCharge.o
	$(CC) $(CFLAGS) patientCharge.o $(LDFLAGS) -o patient

patientCharge.o : patientCharge.cpp
	$(CC) $(CFLAGS) -c patientCharge.cpp

clean :
	rm patient patientCharge.o