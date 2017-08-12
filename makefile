all: output1 output2 output3 output4
output1: wave.o hydrogen.o
	gcc hydrogen.o wave.o -o output1 -lm
output2: wave.o helium.o
	gcc helium.o wave.o -o output2 -lm
output3: wave.o lithium.o
	gcc wave.o lithium.o -o output3 -lm
output4: wave.o beryllium.o
	gcc wave.o beryllium.o -o output4 -lm
wave.o: wave.c
	gcc -c wave.c -lm
hydrogen.o: hydrogen.c
	gcc -c hydrogen.c
helium.o: helium.c
	gcc -c helium.c
lithium.o: lithium.c
	gcc -c lithium.c
beryllium.o: beryllium.c
	gcc -c beryllium.c

clean:
	rm *.o output1 output2 output3 output4
