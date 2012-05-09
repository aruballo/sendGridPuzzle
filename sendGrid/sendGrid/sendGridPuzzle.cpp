#include <stdio.h>
#include <Windows.h>

//Antonio Ruballos
//aruballo@uci.edu
//Solution to SendGrid Trivia Puzzle

int main(){
	
	int x = 0;
	int y = 0;
	int interations = 0;
	int requiredQuartz = 0;
	int maxX = 0;
	int maxY = 0;
	int iterations = 0;
	int i = 0;

	printf("Please indicate the required quartz for the soup: (Integers only please!) \n");
	scanf("%d", &requiredQuartz);
	
	printf("Please indicate the quartz of the first pot: \n");
	scanf("%d", &maxX);

	printf("Please indicate the quartz of the second pot: \n");
	scanf("%d", &maxY);

	//If we do not have a pot larger than the required quartz, we can't move on.
	//I say larger, because if both are less than the required amount, then
	//obviously we can't hold the amount needed and if we have one the exact size
	//there's no reason to move on. 
	if((!(maxX>requiredQuartz) && !(maxY>requiredQuartz)) || ((maxX == requiredQuartz) || (maxY == requiredQuartz))){
		printf("Error: Either both pots are too small or you have a pot of the size needed already. \n");
		printf("Please rerun program with correct inputs. Now exiting. \n");
		Sleep(1000);
		return 0;
	}
		
	//After working out arbitrary numbers of the given problem, I found that
	//my solution for the 4 5 3 numbers works for any given numbers so long as
	//the difference between the bigger pot and the smaller pot is a multiple 
	//of the required quarts. Dividing the required quartz by the multiple then
	//gave me the number of iterations of my algorithm that I have to go through.
	//If the pots are equal, there is no way to use one as a reference of measurement
	//for the other, so there is an error. If the larger pot minus the smaller pot 
	//is equal to the required quartz, then there is also no reason to run the 
	//algorithm. 
	//I'm assuming that for this problem, the size of the pots will adhere to my given algorithm.
	//So I'm assuming the inputs it will receive are of the same nature as the ridddle.
	//Otherwise, I throw an error.

	if(maxX > maxY){
			if((maxX - maxY) == requiredQuartz){
				printf("You can subtract the smaller pot from the larger pot to get your required quartz. \n");
				Sleep(3000);
				return 0;
			}
			
			if(requiredQuartz%(maxX - maxY) == 0){
				iterations = requiredQuartz / (maxX - maxY);
			}
			else{
				//The pots don't adhere to the original riddles rules. So I throw an error.
				printf("The pot sizes do not follow the original riddles pattern.");
				Sleep(3000);
				return 0;
			}
		}
	else if(maxX < maxY){
		if((maxY - maxX) == requiredQuartz){
			printf("You can subtract the smaller pot from the larger pot to get your required quartz.");
			Sleep(1000);
			return 0;
		}
		if(requiredQuartz%(maxX - maxY) == 0){
			iterations = requiredQuartz / (maxY - maxX);
		}
		else{
			//The pots don't adhere to the original riddles rules. So I throw an error.
			printf("The pot sizes do not follow the original riddles pattern.");
			Sleep(3000);
			return 0;
		}
	}
	else{
		printf("Your pots are equal in size. I do not believe there is a way to solve your dilemma.");
		Sleep(1000);
		return 0;
	}

			for(i = 0; i < iterations; i++){
			if(maxX > maxY){
				
				printf("We fill the larger pot with:\n ");
				x = maxX;
				printf("%d", x);
				printf(" quartz.\n");
				printf("We begin to top off the smaller pot by pouring some of the big pot. We have:\n");
				x = maxX - (maxY - y);
				printf("%d", x);
				printf(" quartz remaining in the big pot.\n");
				
				if(x == requiredQuartz){
					printf("This is the required amount of quartz we needed.\n");
					printf("Enjoy the soup! (program will close in about 30 seconds) \n");
					Sleep(30000);
					return 0;
				}
				printf("We empy out the full small pot. \n");
				printf("We empty out the bigger pot into the smaller pot. \n");
				printf("The smaller pot has : \n");
				y = x;
				printf("%d", y);
				printf(" quartz. \n");
			}
			
			else if(maxX < maxY){
				
				printf("We fill the larger pot with:\n");
				y = maxY;
				printf("%d", y);
				printf(" quartz. \n");
				printf("We begin to top off the smaller pot by pouring some of the big pot. We have:\n ");
				y = maxY - (maxX - x);
				printf("%d" , y);
			    printf(" quartz remaining in the big pot.\n");
				
				if(y == requiredQuartz){
					printf("This is the required amount of quartz we needed.\n");
					printf("Enjoy the soup! (program will close in about 30 seconds) \n");
					Sleep(30000);
					return 0;
				}
				printf("We dump out the water in the smaller pot.\n");
				printf("We empty out the bigger pot into the smaller pot.\n");
				printf("The smaller pot has : \n");
				x = y;
				printf("%d", x);
				printf(" quartz. \n");
			}
		}	

	
	
	return 0;
}