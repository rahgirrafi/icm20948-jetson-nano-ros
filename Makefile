imu:main.o icm20948.o
	gcc -Wall -o imu main.o icm20948.o -lm -std=gnu99
main.o: main.cpp ICM20948.h
	gcc -Wall -c main.cpp -lm -std=gnu99
icm20948.o: icm20948.cpp ICM20948.h
	gcc -Wall -c icm20948.cpp -lm -std=gnu99	
clean:
	rm main.o icm20948.o imu