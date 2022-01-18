all: main.cpp ./src/global.cpp ./src/hospital.cpp ./src/address.cpp ./src/person.cpp ./src/doctor.cpp ./src/patient.cpp ./src/appointment.cpp ./src/nurse.cpp ./src/driver.cpp ./src/ambulance.cpp
	g++ -o "./build/expense-manager" main.cpp ./src/global.cpp ./src/hospital.cpp ./src/address.cpp ./src/person.cpp ./src/doctor.cpp ./src/patient.cpp ./src/appointment.cpp ./src/nurse.cpp ./src/driver.cpp ./src/ambulance.cpp
run:
	./bin/expense-manager
clean:
	rm -f ./bin/*
clean(win):
	del /f bin\*