#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Data{
	int sign;
	int number;
	double number2;
	char string[100];
};

int check(char c[], struct Data *data);
void printer(struct Data data);
float convert(char c[]);

int main(){
	struct Data *datac,data;
	datac=&data;
	char c[100];
	printf("your input : ");
	scanf("%s",c);
	check(c,datac);
	printer(data);
	return 0;
}
void printer(struct Data data){
	int sign=data.sign;
	if (sign==3){//string
		printf("it is a string %s",data.string);
		}
	else if (sign==1 || sign==-1){
		printf("<int> %d*2 = %d",data.number,data.number*2);
		}
	else if(sign==-2 || sign==2){
		printf("<float> %f/2 = %f",data.number2,data.number2/2);
	}
}
int check(char c[],struct Data *data){
	int length=strlen(c);
	int key=0;
	int neg=0;
	int decPoint=0;
	int index=0;
	for(index=0;index!=length;index++){
		if (c[index]==48 || (c[index]>48 && c[index]<58)){
			if (decPoint){
				if (neg) key=-2; //negetive float
				else key=2;}	 //positive float
			else {
				if (neg)key=-1; //negetive integer
				else key=1;}  //positive integer
		}
		else if(c[index]==46){
			if (decPoint==0){ //ensuring c[] contain only one decimal point
				decPoint=index;}
			else{
				key=3; //string, if multiple point
				break;}
		}
		else if(c[index]==45 && index==0){
			neg=1; //checking if "-" sign at the begining
		}
		else{
			key=3;   //string
			break;}
	}
	if (key==3)strcpy((*data).string,c);
	else if(key==1||key==-1) (*data).number=atoi(c);
	else if(key==2||key==-2) (*data).number2=atof(c);
	(*data).sign=key;
	return key;
}
