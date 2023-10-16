#include "ColtonHeader.h"

int main() {
  
    //declare variables
    //the reason the array length is 100 is because instead of the program passing
    //arrays that are over 1000 size, it will provide the most recent 100 plays.
    char arr_alg1[100] = "";
    char arr_alg2[100] = "";
    char wtl1[100] = "";
    char wtl2[100] = "";
    int win_alg1 = 0;
    int ties = 0;
    int loss_alg1 = 0;
    Colton_Alg alg1;
    Colton_Alg alg2; 
  
    //get number of rounds
  
    int rounds;
    cout << "Enter how many rounds to play: ";
  
    cin >> rounds;
  
    //loop battles
  
    for (int i = 0; i < rounds; i++){
      //get first algorithms move
        char play1 = alg1.Algorithm1(wtl1, arr_alg1, i);
      //get second algorithms move
        char play2 = alg2.BigBadEvilCode(wtl2, arr_alg2, i);
      //for testing you can use these lines to make sure algorithms are providing correct throw
        //cout << "Player 1 throws >> " << play1 << endl;
        //cout << "Player 2 throws >> " << play2 << endl;
        arr_alg1[i%100] = play2;
        arr_alg2[i%100] = play1;
      
        if(play2 == play1){ // tie condition
            ties++;
            wtl1[i%100] = 't';
            wtl2[i%100] = 't';
        }
        else if( (play1 == 'p' && play2 == 'r') || (play1 == 'r' && play2 == 's') || (play1 == 's' && play2 == 'p')){ //win condition
            win_alg1++;
            wtl1[i%100] = 'w';
            wtl2[i%100] = 'l';
        }
        else{ //lose condition
            loss_alg1++;
            wtl1[i%100] = 'l';
            wtl2[i%100] = 'w';
        }

        //output round info
        cout << "Round#" << i+1 << endl;
        cout << "Win:" << win_alg1 << " Percentage: " << static_cast<int>((static_cast<double>(win_alg1) / (i+1)) *100) << "%" << endl;
        cout << "Tied: " << ties << " Percentage: " << static_cast<int>((static_cast<double>(ties) / (i+1)) * 100) << "%" << endl;
        cout << "Loss: " << loss_alg1 << " Percentage: " <<  static_cast<int>((static_cast<double>(loss_alg1) / (i+1)) * 100) << "%" << endl << endl;
    }
  cout << endl;
    //final output
  //determines if they tied or who won and then outputs accordingly
    if(win_alg1 == loss_alg1){
      cout << "Algorithm's Resulted in a tie" << endl;
        cout << "Win Percentage: " << static_cast<int>((static_cast<double>(win_alg1) / (rounds)) * 100) << "%" << endl; 
        cout << "Tie Percentage: " << static_cast<int>((static_cast<double>(ties) / (rounds)) * 100) << "%" << endl;
    }
  else if (win_alg1 > loss_alg1){
    cout << "Winning Algorithm: Algorithm 1" << endl;
        cout << "Win Percentage: " << static_cast<int>((static_cast<double>(win_alg1) / (rounds)) * 100) << "%" << endl; 
        cout << "Tie Percentage: " << static_cast<int>((static_cast<double>(ties) / (rounds)) * 100) << "%" << endl << endl;

    cout << "Losing Algorithm: Algorithm 2" << endl;
        cout << "Win Percentage: " << static_cast<int>((static_cast<double>(loss_alg1) / (rounds)) * 100) << "%" << endl; 
        cout << "Tie Percentage: " << static_cast<int>((static_cast<double>(ties) / (rounds)) * 100) << "%" << endl;
  }
   else{
     cout << "Winning Algorithm: Algorithm 2" << endl;
        cout << "Win Percentage: " << static_cast<int>((static_cast<double>(loss_alg1) / (rounds)) * 100) << "%" <<  endl; 
        cout << "Tie Percentage: " << static_cast<int>((static_cast<double>(ties) / (rounds)) * 100) << "%" << endl << endl;

    cout << "Losing Algorithm: Algorithm 1" << endl;
        cout << "Win Percentage: " << static_cast<int>((static_cast<double>(win_alg1) / (rounds)) * 100) << "%" << endl; 
        cout << "Tie Percentage: " << static_cast<int>((static_cast<double>(ties) / (rounds)) * 100) << "%" <<endl;
   }
    return 0;
}
