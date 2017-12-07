#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// comment out below this line when submitting!

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

typedef struct player {
	int budget;
	int value;
	int call;
	int bet;
} Player;

int main(){
	
    int n_games = 5; // # of games
    int human_initial_money = 100000000;
    int computer_initial_money = 100000000;
    
    // these cards must be changed to random in the final game!
    char human_cards[40][5][4] = {
		"H4","C4","D4","SK","S3",
		"H4","C4","D4","SK","S3",
		"HA","HK","HJ","HQ","H10",
		"DA","HA","SA","CA","HK",
		"D8","D9","D10","DJ","DQ",
		"D8","D9","D10","DJ","DQ",
		"D2","D3","D5","D10","DA",
		"D8","D9","D10","DJ","DQ",
		"D2","H2","S2","DK","HK",
		"D2","H2","S2","DK","HK",
		"H4","C4","DK","S10","S3",
		"HA","HK","HJ","HQ","H10",
		"H4","C4","D4","SK","S3",
		"H4","C4","D4","SK","S3",
		"H4","C7","DK","S10","S3",
		"H2","H3","D5","D4","S6",
		"H4","C7","DK","S10","S3",
		"H4","C4","DK","SK","S3",
		"DA","HA","SA","CA","HK",
		"H4","C7","DK","S10","S3",
		"H2","H3","D5","D4","S6",
		"D2","H2","S2","DK","HK",
		"H4","C4","DK","S10","S3",
		"H4","C4","DK","S10","S3",
		"H2","H3","D5","D4","S6",
		"D2","H2","S2","DK","HK",
		"D2","H2","S2","DK","HK",
		"H4","C4","DK","SK","S3",
		"DA","HA","SA","CA","HK",
		"H4","C4","DK","S10","S3",
		"H4","C7","DK","S10","S3",
		"D2","D3","D5","D10","DA",
		"D8","D9","D10","DJ","DQ",
		"H4","C7","DK","S10","S3",
		"H4","C7","DK","S10","S3",
		"D8","D9","D10","DJ","DQ",
		"H4","C7","DK","S10","S3",
		"D2","H2","S2","DK","HK",
		"DA","HA","SA","CA","HK",
		"DA","HA","SA","CA","HK"
    };
    char computer_cards[40][5][4] = {
		"H4","C4","DK","S10","S3",
		"H4","C4","DK","S10","S3",
		"H4","C4","DK","S10","S3",
		"HA","HK","HJ","HQ","H10",
		"HA","HK","HJ","HQ","H10",
		"H4","C7","DK","S10","S3",
		"D8","D9","D10","DJ","DQ",
		"D8","D9","D10","DJ","DQ",
		"HA","HK","HJ","HQ","H10",
		"D2","H2","S2","DK","HK",
		"D2","H2","S2","DK","HK",
		"H4","C7","DK","S10","S3",
		"H4","C7","DK","S10","S3",
		"D8","D9","D10","DJ","DQ",
		"DA","HA","SA","CA","HK",
		"DA","HA","SA","CA","HK",
		"H4","C7","DK","S10","S3",
		"H2","H3","D5","D4","S6",
		"D2","H2","S2","DK","HK",
		"H4","C4","DK","SK","S3",
		"DA","HA","SA","CA","HK",
		"HA","HK","HJ","HQ","H10",
		"DA","HA","SA","CA","HK",
		"H2","H3","D5","D4","S6",
		"H4","C4","D4","SK","S3",
		"HA","HK","HJ","HQ","H10",
		"HA","HK","HJ","HQ","H10",
		"D2","H2","S2","DK","HK",
		"H4","C7","DK","S10","S3",
		"H4","C4","D4","SK","S3",
		"H4","C4","DK","SK","S3",
		"D2","H2","S2","DK","HK",
		"HA","HK","HJ","HQ","H10",
		"D2","H2","S2","DK","HK",
		"D2","D3","D5","D10","DA",
		"H4","C4","DK","SK","S3",
		"H4","C7","DK","S10","S3",
		"H4","C7","DK","S10","S3",
		"D8","D9","D10","DJ","DQ",
		"DA","HA","SA","CA","HK"
    };
    
    static Player human;
	static Player computer;
    
    char command[50];
    
    int idx;
    scanf("%d\n", &idx);
    
    // show intro message and rules
    /*
    printf("%s\n", intro);
    printf(explanation, n_games);
    */
    
    // start the game
    
    // set default budget of HUMAN and COMPUTER
    sprintf(command, "HUMAN ADD %d", human_initial_money); // cmd "HUMAN ADD 2000"
    call_command(&human, &computer, command);
    sprintf(command, "COMPUTER ADD %d", computer_initial_money); // cmd = "COMPUTER ADD 2000"
    call_command(&human, &computer, command);
    
    for(int i = 0; i < n_games; i++){
    	//printf("\n***** ROUND %3d *****\n", i+1);
    	
    	int human_score = determine_hand(human_cards[idx+i]);
    	int computer_score = determine_hand(computer_cards[idx+i]);
    	
    	/*
    	printf("\n# HUMAN CARDS\n\n");
    	printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", human_cards[i][0], human_cards[i][1], human_cards[i][2],
									human_cards[i][3], human_cards[i][4], score_to_name[human_score]);
		*/
		
		/*
		printf("\n-- COMPUTER CARDS --\n\n");
   		printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", computer_cards[i][0], computer_cards[i][1], computer_cards[i][2],
									computer_cards[i][3], computer_cards[i][4], score_to_name[computer_score]);
		*/
		
		//printf("\n*********************\n\n");
		
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
	
		// printf("%s\n", command);
		call_command(&human, &computer, command);
		
        // loop until bet ends
		while(1){
            
            if(!fgets(command, sizeof(command), stdin) && feof(stdin)) break;
            command[strcspn(command, "\r\n")] = '\0';
            
			int result = call_command(&human, &computer, command);
			
            // bet ended
			if(result != 0){
                
                // show results
                /*
		    	printf("\n-- HUMAN CARDS --\n\n");
		    	printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", human_cards[i][0], human_cards[i][1], human_cards[i][2],
											human_cards[i][3], human_cards[i][4], score_to_name[human_score]);
				
				
				printf("\n-- COMPUTER CARDS --\n\n");
		   		printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", computer_cards[i][0], computer_cards[i][1], computer_cards[i][2],
											computer_cards[i][3], computer_cards[i][4], score_to_name[computer_score]);
			
				printf("\n");
				printf("# HUMAN BUDGET    ==> ");
				*/
				strcpy(command, "HUMAN SHOW");
				call_command(&human, &computer, command);
				//printf("# COMPUTER BUDGET ==> ");
				strcpy(command, "COMPUTER SHOW");
				call_command(&human, &computer, command);
				break;	
			}
		}
	}
}
