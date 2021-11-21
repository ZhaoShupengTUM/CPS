#include <stdio.h>

#define FILTER_ORDER 3

int main(void){
	
	float A[FILTER_ORDER+1] = {1.0000, -2.3812, 1.9397, -0.5360};
	float B[FILTER_ORDER+1] = {0.0028,  0.0084, 0.0084, 0.0028 };
	
	//open the file
	FILE *inputSignal= fopen("noisy signal.csv","r");
	
	 if(inputSignal == NULL){
        printf("Cant't find the inputSignal file!\n");
        return 1;
    }
	
	//write the signal into a .csv file
	FILE *outSignal = fopen("filtered signal.csv","w");
	
	//read the signal
	float oSignal[1000] = {0};
	
	//the order of the Filter is 3, so first 3 samples should be 0, means oSignal[3] is
	//the first sampled signal
	int i = 3; //the counter
	
	while(!feof(inputSignal))
	{
		fscanf(inputSignal, "%f\n", &oSignal[i]);
		i++;
	}
	
	printf("%f\n",oSignal[4]);
	
	//calculate the filtered signal using the digital filter
	float fSignal[1000] = {0};
	
	for(i=3; i<1000; i++) 
	{
		fSignal[i] = B[0]*oSignal[i] + B[1]*oSignal[i-1] + B[2]*oSignal[i-2] + B[3]*oSignal[i-3] 
		- A[1]*fSignal[i-1] - A[2]*fSignal[i-2] - A[3]*fSignal[i-3];
		
		fprintf(outSignal, "%f\n", fSignal[i]);
	}
	
	printf("%f", fSignal[5]);
	
	fclose(inputSignal);
	fclose(outSignal);
	
	return 0;
}