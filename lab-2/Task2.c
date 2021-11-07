#include <stdio.h>

int main(void){
	
	//define a structure to store the content
	struct person{
		char lname[20];
		char fname[20];
		int g1;
		int g2;
		int g3;
		int g4;
		char email[30];
	}p1;
	
	int sum;
	float note;
	
	//open the file
	FILE *inputGrade= fopen("grading.txt","r");
	
	FILE *outGrade = fopen("finalNote.txt","w");
	
	if (!inputGrade) {
		printf("fopen .txt to read error !\n");  //check if read succeds		
		//exit(1);
	}
	
	else if(!outGrade){
		printf("fopen .txt to write error !\n");
	}
	
	else{
		
			while(!feof(inputGrade))
			{
			
				//read the file
				fscanf(inputGrade,"%20s,,%20s,,%d,%d,%d,%d,%40s\n",p1.lname,p1.fname,&p1.g1,&p1.g2,&p1.g3,&p1.g4,p1.email);
				//cauculate the note
				sum = p1.g1+p1.g2+p1.g3+p1.g4;
				
				//printf("%d\n",sum);
				
				if(0<=sum && 50>sum){
				note = 5.0;
				}
				else if(50<=sum && 55.5>sum){
				note = 4.0;
				}
				else if(55.5<=sum && 60.5>sum){
					note = 3.7;
				}
				else if(60.5<=sum && 65.5>sum){
				note =3.3;	
				}
				else if(65.5<=sum && 70.5>sum){
					note = 3.0;
				}
				else if(70.5<=sum && 75.5>sum){
					note = 2.7;
				}
				else if(75.5<=sum && 81>sum){
				note = 2.3;
				}
				else if(81<=sum && 86>sum){
					note = 2.0;
				}
				else if(86<=sum && 91>sum){
					note = 1.7;
				}
				else if(91<=sum && 96>sum){
				note = 1.3;
				}
				else if(96<=sum){
				note = 1.0;
				}
					
				//printf("%2.1f\n",note);
				
				//terminal output
				printf("%s %s <%s>: %2.1f\n",p1.lname,p1.fname,p1.email,note);
			
				//write the file	
				fprintf(outGrade, "%s %s <%s>: %2.1f\n", p1.lname,p1.fname,p1.email,note);
				
				//fscanf(inputGrade,"%s,,%s,,%d,%d,%d,%d,%s\n",p1.lname,p1.fname,&p1.g1,&p1.g2,&p1.g3,&p1.g4,p1.email);
			
			}		
				
				fclose(inputGrade);
				fclose(outGrade);
		
	}
	
	return 0;
}