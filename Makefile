imu:main.o icm20948.o
	g++ -Wall -o imu main.o icm20948.o -std=c++17
main.o: main.cpp ICM20948.h
	g++ -Wall -c main.cpp -std=c++17
icm20948.o: icm20948.cpp ICM20948.h
	g++ -Wall -c icm20948.cpp -std=c++17
clean:
	rm main.o icm20948.o imu