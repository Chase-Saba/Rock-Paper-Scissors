#include "ColtonHeader.h"

char Colton_Alg::Algorithm1(char wtl[], char opp_array[], int rounds){
	//goal of this algorithm was to create something that was still random but used weighted percentages based on wtl ratio
	
	char play; //return value/RPS move
	int i; //iterator
	int arrlen=0;
	float r=0; //rock percentage
	float p=0; //paper percentage
	float s=0; //scissors percentage
	float high=0; //highest %
	float mid=0; //middle %
	float low=0; //low %
	float chance; // used to determine which percentage I would choose
	
	//get array length
	for(i=0;i<100;i++){
		if(opp_array[i]=='r' || opp_array[i]=='p' || opp_array[i]=='s' ){
			++arrlen;
		}
	}
	
	//random number generator, ensures an improved level of variation between values when compared to functions like rand and srand
	random_device rd;
	mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100); //random number generation between 1->100

	
	//first ten moves are random to ensure enough results for the function to be initialized
	if(arrlen<=10){
		
  int num = rand() % 3 + 1;
    if(num == 1){
        play = 'r';
    }
    else if (num == 2){
        play = 'p';
    }
    else{
        play = 's';
    }
  
    return play;
}

//actual algorithm
else{
	for(i=0;i<arrlen;i++){
		if(wtl[i]=='w'){
			//encourage specific move percentages if it wins by incrementing
			if(opp_array[i]=='r'){
				++p;
			}
			if(opp_array[i]=='p'){
				++s;
			}
			if(opp_array[i]=='s'){
				++r;
			}
		}
		
		if(wtl[i]=='t'){
			//encourage specific move percentages if it ties
			if(opp_array[i]=='r'){
				++r;
			}
			if(opp_array[i]=='p'){
				++p;
			}
			if(opp_array[i]=='s'){
				++s;
			}
		}
	  if(wtl[i]=='l'){
		  //encourage opposite move percentages if loss
			if(opp_array[i]=='r'){
				++p;
			}
			if(opp_array[i]=='p'){
				++s;
			}
			if(opp_array[i]=='s'){
				++r;
			}
	
		}
	}
	//these three equations create decimal percentages for my algorithm
	r=(r/arrlen);
	
	p=(p/arrlen);
	
	s=(s/arrlen);
	
	//assigns a random number to chance
	chance=dis(gen);
	chance=chance/100;
	
	//these next six if statments ensures that the program determines which of the three(r,p, or s) have the highest chance, middle, and lowest chance of occuring
	//using all possibilites of combinations to determine
	if(r<=p && p<=s){
		low=r;
		mid=p;
		high=s;
	}
	if(r<=s && s<=p){
		low=r;
		mid=s;
		high=p;
	}
	if(s<=r && r<=p){
		low=s;
		mid=r;
		high=p;
	}
	if(s<=p && p<=r){
		low=s;
		mid=p;
		high=r;
	}
	if(p<=s && s<=r){
		low=p;
		mid=s;
		high=r;
	}
	if(p<=r && r<=s){
		low=p;
		mid=r;
		high=s;
	}
	cout<<"Rock-"<<r<<" Scissors-"<<s<<" Paper-"<<p<<" Chance-"<<chance<<endl; //used to test output
	cout<<"Low-"<<low<<" Mid-"<<mid<<" High-"<<high<<endl; //used to test output
	
	/*the next few if statements are designed to simulate/recreate how percentages are chosen at random based on larger numerical values
	idea is that the larger percentage will be chosen most often but there is still a chance to choose either the middle or lower percentage if
	the algorithm is "lucky".
	
	This is done through a few equations, the idea is that the random number generator provided by C++ provides a random 1/100 chance to land on any number from 1 to 100
	With this, you can calculate different percentages. For example, if you want to have a 75% chance of something, then any time you get a number from the random number generator
	under 75 then you have hit that percentage, if higher, then you missed it.
	*/
	
	if(chance<high){ //checks if chance is within range of highest percentage
//if so, it rechecks which value was highest and uses it as its play
		if(high==r){
			play='r';
				return play;
		}
		if(high==s){
			play='s';
				return play;
		}
		if(high==p){
			play='p';
				return play;
		}
	}
	else{ //if it did not end up being within range of the first percentage, then you subtract the chance from the percentage and check to see if it hits the middle percentage
		chance=chance-high;
	}
	if(chance<mid){
		if(mid==r){
			play='r';
				return play;
		}
		if(mid==s){
			play='s';
				return play;
		}
		if(mid==p){
			play='p';
				return play;
		}
	}
	else{  //same process repeated, if it is wihtin middle chance then it plays, if not, proceeds to lowest chance and then plays
		chance=chance-mid;
	}
	if(chance<=low){
		if(low==r){
			play='r';
			return play;
		}
		if(low==s){
			play='s';
			return play;
		}
		if(low==p){
			play='p';
			return play;
		}
	}
	else{ //ensures that if percentages fall to around zero and chances still land on low percent, it will use the low percent
		if(low==r){
			play='r';
			return play;
		}
		if(low==s){
			play='s';
			return play;
		}
		if(low==p){
			play='p';
			return play;
		}
}
}
return 0;
}	
	
	
	
char Colton_Alg::BigBadEvilCode(char wtl[], char opp_array[], int rounds){
	//initial algorithm I created, goal was to make a simple but effective predictive algorithm that I could build off of to create my probability algorithm
    int i;
    int arrlen=0;
	char play;
	
	//get array length
	for(i=0;i<100;i++){
		if(opp_array[i]=='r' || opp_array[i]=='p' || opp_array[i]=='s' ){
			++arrlen;
		}
	}

	
	if(arrlen<=10){ //plays random for the first ten for data collection
		
  int num = rand() % 3 + 1;
    if(num == 1){
        play = 'r';
    }
    else if (num == 2){
        play = 'p';
    }
    else{
        play = 's';
    }
  
    return play;
}


 if(wtl[arrlen-1]=='l' || wtl[arrlen-1]=='t'){ //if the previous round was a loss or tie, then it will play the move that would have beaten opponents previous play
		
			if(opp_array[arrlen-1]=='r'){
				play='p';
			}
			if(opp_array[arrlen-1]=='p'){
				play='s';
			}
			if(opp_array[arrlen-1]=='s'){
				play='r';
			}
 }
 
			
 if(wtl[arrlen-1]=='w'){// if the previous round was a win, then it will play the opposite move that would have lost to opponent in previous round
		//idea is this will catch algorithms that want to change their strategy after losing a round, should ensure either a win or a tie as long as opponents algorithm
		//does not replay losing move, which I cannot guarentee, but it is a common tactic 
			if(opp_array[arrlen-1]=='r'){
				play='s';
			}
			if(opp_array[arrlen-1]=='p'){
				play='r';
			}
			if(opp_array[arrlen-1]=='s'){
				play='p';
			}
 }

   
    return play;
}

	
