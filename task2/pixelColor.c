#include "pixelColor.h"
unsigned char stepsToRed(int steps){
	return sqrt(steps+1);
}
unsigned char stepsToBlue(int steps){
	return steps+5;
}
unsigned char stepsToGreen(int steps){
	return steps+5;
}
