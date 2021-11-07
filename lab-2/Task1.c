#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encode(const char *original, char *encoded)
{
	if(original == NULL || encoded == NULL)
	{
	    printf("null pointer.");
	}
	else{
		
		char ele[1];
		ele[0] = *original;  //store the element
		int count = 0; //count the number of the same element
		//int i = 0;  //the input string pointer
		int n = 0;  //the output string pointer
		char int2str[10];  //store the int transformed string
		
		while(*original != '\0')
		{
			
		//find the number of the same elements
			while(*original == ele[0])  
			{
				count++;
				original++;
			}
		
			//add the number in the output string
			if(count > 1)
			{
				sprintf(int2str, "%d", count);  //type transform
				strcat(encoded, int2str);
			}
			
			//add the char in the output string
			strncat(encoded, ele, 1);
		    
			
			//count the new different char element
			ele[0] = *original;
		    count = 0;
		}
}
}

void decode(const char *encoded, char *decoded)
{
	//
	if(decoded == NULL || encoded == NULL)
	{
	    printf("null pointer.");
	}
	else
	{
		char int2str[10];
	
		int n,place;
		char x;
		int i=0;
	
		while(*encoded != '\0')
	
    //printf("%c\n",*new_encode++);
			
		{
			//first situation: degit+char
			if(isdigit(*encoded))
			{
				sscanf(encoded,"%d",&n);  //sscanf() will scan from the pointer of new_encode
			
				//need to judge the digit place
				sprintf(int2str,"%d",n);  //sprintf() will rewrite the string
				place = strlen(int2str);
				for(i=0;i<place;i++){
					encoded++;
				}
		
				sscanf(encoded,"%c",&x);
				encoded++;
				for(i=0;i<n;i++){
					//printf("%c",x);
					*decoded = x;
					decoded++;
				}
				//printf("%c",*new_encode);
			}
			
			//second situation:char
			else
			{
			//	printf("%c",*new_encode);
				*decoded = *encoded;
				decoded++;
				encoded++;
			}
		
		}
		
	}
}

	
void main(void){
	
	const char original[100] =
	"wwwwwWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB";
	
	char encoded[100] = {0};
	
	char decoded[100] = {0};
	
	printf("original:%s\n", original);
	
	encode(original, encoded);
	printf("Encoded: %s\n", encoded);
	
	decode(encoded, decoded);
	printf("Decoded: %s\n", decoded);
	
}