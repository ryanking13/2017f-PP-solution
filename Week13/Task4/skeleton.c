#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// do not modify this struct!!!!
typedef struct player {
	int budget;
	int value;
	int call;
	int bet;
} Player;

int determine_hand(char c[5][4]){
    return 0;
	// TODO: Implement your own function!
}

int call_command(Player* human, Player* computer, char* command){
    return 1;
    // TODO: Implement your own function!
}

// comment out line below this when submitting!

char *intro = "\
*************************\n\
|     W E L C O M E     |\n\
|          T O          |\n\
|         T H E         |\n\
|   P O K E R G A M E   |\n\
*************************\
";

char *explanation = "\n\
********* RULES *********\n\
1. [The Poker Game] consists of %d rounds.\n\
2. On each round, HUMAN and COMPUTER takes 5 cards.\n\
3. If round number is odd, HUMAN starts betting first, if not, COMPUTER starts first.\n\
*************************\n\
";

char score_to_name[10][25] = {
	"No Pair",
	"One Pair",
	"Two Pair",
	"Three Card",
	"Straight",
	"Flush",
	"Full House",
	"Four Card",
	"Straight Flush",
	"Royal Straight Flush",
};

int main(){
	
    int n_games = 10; // # of games
    int human_initial_money = 2000;
    int computer_initial_money = 2000;
    
    // these cards must be changed to random in the final game!
    char human_cards[10][5][4] = {
		"C9","H4","CQ","HK","SQ",
		"DK","D5","DJ","DQ","H4",
		"HJ","DK","D2","CQ","C6",
		"D6","H3","S10","SJ","H7",
		"D7","S2","H10","SJ","DQ",
		"D7","S4","CA","D9","D10",
		"S2","H3","HJ","H10","C3",
		"DK","DJ","C8","HK","C7",
		"C9","C8","H4","DQ","SQ",
		"CQ","C7","C3","SA","D4"
    };
    char computer_cards[10][5][4] = {
		"SJ","CJ","S10","DK","D7",
		"H9","S3","C4","C2","D7",
		"S9","H10","HQ","SJ","CK",
		"D2","C3","S5","S3","C6",
		"SA","DK","H4","C9","HK",
		"C3","S5","HJ","DJ","H10",
		"S5","SQ","D10","C4","CK",
		"D3","S7","H3","CA","DA",
		"H9","HA","H5","CQ","C4",
		"HK","H4","C5","C2","C8"
    };
    
    static Player human;
    static Player computer;
    
    char command[50];
    
    // show intro message and rules
    printf("%s\n", intro);
    printf(explanation, n_games);
    
    // start the game
    
    // set default budget of HUMAN and COMPUTER
    sprintf(command, "HUMAN ADD %d", human_initial_money); // cmd "HUMAN ADD 2000"
    call_command(&human, &computer, command);
    sprintf(command, "COMPUTER ADD %d", computer_initial_money); // cmd = "COMPUTER ADD 2000"
    call_command(&human, &computer, command);
    
    for(int i = 0; i < n_games; i++){
    	printf("\n***** ROUND %3d *****\n", i+1);
    	
    	int human_score = determine_hand(human_cards[i]);
    	int computer_score = determine_hand(computer_cards[i]);
    	
    	printf("\n# HUMAN CARDS\n\n");
    	printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", human_cards[i][0], human_cards[i][1], human_cards[i][2],
									human_cards[i][3], human_cards[i][4], score_to_name[human_score]);
		
		/*
		printf("\n-- COMPUTER CARDS --\n\n");
   		printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", computer_cards[i][0], computer_cards[i][1], computer_cards[i][2],
									computer_cards[i][3], computer_cards[i][4], score_to_name[computer_score]);
		*/
		
		printf("\n*********************\n\n");
		
        // set value
		sprintf(command, "HUMAN VALUE %d", human_score);
		call_command(&human, &computer, command);
		sprintf(command, "COMPUTER VALUE %d", computer_score);
		call_command(&human, &computer, command);
		
        // start betting
		if((i+1) % 2 == 1)
			strcpy(command, "HUMAN START");
		else
			strcpy(command, "COMPUTER START");		
	
		printf("%s\n", command);
		call_command(&human, &computer, command);
		
        // loop until bet ends
		while(1){
            
            if(!fgets(command, sizeof(command), stdin) && feof(stdin)) break;
            command[strcspn(command, "\r\n")] = '\0';
            
			int result = call_command(&human, &computer, command);
			
            // bet ended
			if(result != 0){
                
                // show results
		    	printf("\n-- HUMAN CARDS --\n\n");
		    	printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", human_cards[i][0], human_cards[i][1], human_cards[i][2],
											human_cards[i][3], human_cards[i][4], score_to_name[human_score]);
				
				
				printf("\n-- COMPUTER CARDS --\n\n");
		   		printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", computer_cards[i][0], computer_cards[i][1], computer_cards[i][2],
											computer_cards[i][3], computer_cards[i][4], score_to_name[computer_score]);
			
				printf("\n");
				printf("# HUMAN BUDGET    ==> ");
				strcpy(command, "HUMAN SHOW");
				call_command(&human, &computer, command);
				printf("# COMPUTER BUDGET ==> ");
				strcpy(command, "COMPUTER SHOW");
				call_command(&human, &computer, command);
				break;	
			}
		}
	}
}
