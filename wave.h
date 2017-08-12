

#ifndef wave_h
#define wave_h

int hydrogen_wave(double E, double wave[], int size, double dx);

int helium_wave(double E, double wave[], int size, double dx);

int lithium_wave(double E, double wave[], int size, double dx, double subshell);

int beryllium_wave(double E, double wave[], int size, double dx, double subshell);

int norm(double wave[], int size);

#endif
