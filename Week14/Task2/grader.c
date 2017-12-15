#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct player {
	int budget;
	int value;
	int call;
	int bet;
} Player;

typedef struct card{
	// symbol = 1 = Hearts, 2 = Diamond, 3 = Clubs, 4 = Spades
	// number = 2 ~ 14 (11=J 12=Q 13=K, 14=Ace)
	int symbol; int number;
} Card;

int call_command_grader(Player* human, Player* computer, char* command){
	
	char *name;
	char *cmd;
	int num;
	
	name = strtok(command, " ");
	Player *player;
	Player *opponent;
	
	if(!strcmp("HUMAN", name)){
		player = human;
		opponent = computer;
	} else if(!strcmp("COMPUTER", name)){
		player = computer;
		opponent = human;
	}
	
	cmd = strtok(NULL, " ");
	if (strcmp(cmd, "CALL") == 0)
	{
		player->call = 1;
		if (player->call && opponent->call)
		{
			
			if (player->value > opponent->value)
			{
				player->budget += opponent->bet;
				opponent->budget -= opponent->bet;
			}
			else if(player->value < opponent->value)
			{
				player->budget -= opponent->bet;
				opponent->budget += opponent->bet;
			}
			
			player->call = 0;
			opponent->call = 0;
			return 1;
		}
		
		player->bet = opponent->bet;
	}
	else{
		player->call = 0;
		opponent->call = 0;
	}

	if (strcmp(cmd, "ADD") == 0)
	{
		num = atoi(strtok(NULL, " "));
		player->budget += num;
	}
	else if (strcmp(cmd, "MINUS") == 0)
	{
		num = atoi(strtok(NULL, " "));
		if (player->budget < num){
			//printf("NOT ENOUGH MONEY\n");
			return -1;
		}
			
		else
			player->budget -= num;
	}
	else if (strcmp(cmd, "VALUE") == 0)
	{
		num = atoi(strtok(NULL, " "));
		player->value = num;
	}
	else if (strcmp(cmd, "SHOW") == 0){
		// printf("%d\n", player->budget);
		return player->budget;
	}
		
	else if (strcmp(cmd, "START") == 0)
	{
		if (player->budget < 100 || opponent->budget < 100){
			//printf("NOT ENOUGH MONEY\n");
			return -1;
		}
			
		else {
			player->bet = 100;
			opponent->bet = 100;
		}
	}
	else if (strcmp(cmd, "RAISE") == 0)
	{
		if (player->budget < opponent->bet * 2){
			//printf("NOT ENOUGH MONEY\n");
			return -1;
		}
			
		else {
			if (opponent->budget < opponent->bet * 2)
			{
				opponent->budget -= opponent->bet;
				player->budget += opponent->bet;
				return 1;
			}
			else
			{
				player->bet = opponent->bet * 2;
			}
		}
	}
	else if (strcmp(cmd, "FOLD") == 0)
	{
		opponent->budget += player->bet;
		player->budget -= player->bet;
		return 1;
	}
	
	return 0;
}

int choose_command_grader(char computer_cards[3][4], char human_cards[5][4], Player* human, Player* computer){
	
	// return value : call = 0, raise = 1, fold = 2
	const int CALL = 0;
	const int RAISE = 1;
	const int FOLD = 2;
	
	if(computer->bet * 2 >= human->budget){
		return CALL;
	}
	
	// 2% prob
	int r = rand() % 1000;
	if(r < 20) 
		return CALL;

	int val = determine_hand(human_cards);

	switch(val){
		
		case 0: // no pair
			if(human->bet == 100){
				return RAISE;
			}
			else if(human->bet < 1600){
				return rand()%2;
			}
			else if(human-> bet < 12800){
				return CALL;
			}
			else{
				return rand()%2+1;
			}
			
			break;
		case 1:	// one pair
			if(human->bet < 800){
				return RAISE;
			}
			else if(human->bet < 3200){
				return rand()%2;
			}
			else if(human->bet < 51200){
				return CALL;
			}
			else {
				return rand()%2+1;
			}
			break;
			
		case 2:
			if(human->bet < 6400){
				return RAISE;
			}
			else if(human->bet < 25600){
				return rand()%2;
			}
			else if(human->bet < 102400){
				return CALL;
			}
			else{
				return rand()%2+1;
			}
			
			break;
		case 3:
			if(human->bet < 25600){
				return RAISE;
			}
			else if(human->bet < 102400){
				return rand()%2;
			}
			else if(human->bet < 409600){
				return CALL;
			}
			else{
				return rand()%2+1;
			}
			break;
		case 4:
			if(human->bet < 51200){
				return RAISE;
			}
			else if(human->bet < 409600){
				return rand()%2;
			}
			else{
				return CALL;
			}
			break;
		case 5:
			if(human->bet < 102400){
				return RAISE;
			}
			else if(human->bet < 409600){
				return rand()%2;
			}
			else{
				return CALL;
			}
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			if(human->bet < 204800){
				return RAISE;
			}
			else if(human->bet < 409600){
				return rand()%2;
			}
			else{
				return CALL;
			}
			break;
	}
}

int *pick_rand_nums(int max_num, int n){
	int *nums = (int *)malloc(sizeof(int) * n);
	int cnt = 0;
	int r;
	
	while(cnt < n){
		r = rand()%max_num;
		
		int chk = 1;
		for(int i = 0; i < cnt; i++){
			if(nums[i] == r){
				chk = 0;
				break;
			}
		}
		
		if(chk){
			nums[cnt++] = r;
		}
	}
	
	return nums;
}

char cards[52][4] = {"DA","D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK",
						"HA","H2","H3","H4","H5","H6","H7","H8","H9","H10","HJ","HQ","HK",
						"SA","S2","S3","S4","S5","S6","S7","S8","S9","S10","SJ","SQ","SK",
						"CA","C2","C3","C4","C5","C6","C7","C8","C9","C10","CJ","CQ","CK"};

// comment out below this line when submitting!

char commands[2][3][15] = {
	"COMPUTER CALL", "COMPUTER RAISE", "COMPUTER FOLD",
	"HUMAN CALL", "HUMAN RAISE", "HUMAN FOLD"
};

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
	
	srand(time(NULL));
	
	int n_tests;
    int n_games; // # of games
    int win_goal; // if win count >= win goal, you win
    
    scanf("%d %d %d", &n_tests, &n_games, &win_goal);
    
    int human_initial_money = 1000000000;
    int computer_initial_money = 100000000;
    int win_condition = 100000; // if player earns more than this, player wins;
    int win_count = 0;
    
    char human_cards[5][4];
    char computer_cards[5][4];
    
    char command[50];
    
    // show intro message and rules
//    printf("%s\n", intro);
//    printf(explanation, n_games);
    
	for(int t = 0; t < n_tests; t++){
		// start the game
        Player human = {0,0,0,0};
	    Player human_grader = {0,0,0,0};
	    Player computer = {0,0,0,0};
	    Player computer_grader = {0,0,0,0};
	    
	    // set default budget of HUMAN and COMPUTER
	    sprintf(command, "HUMAN ADD %d", human_initial_money); // cmd "HUMAN ADD 2000"
	    call_command_grader(&human_grader, &computer_grader, command);
	    sprintf(command, "HUMAN ADD %d", human_initial_money);
	    call_command(&human, &computer, command);
	    sprintf(command, "COMPUTER ADD %d", computer_initial_money); // cmd = "COMPUTER ADD 2000"
	    call_command_grader(&human_grader, &computer_grader, command);
	    sprintf(command, "COMPUTER ADD %d", computer_initial_money);
	    call_command(&human, &computer, command);
	    
	    for(int i = 0; i < n_games; i++){
	    	
//	    	printf("\n***** ROUND %3d *****\n", i+1);
	    	
	    	int* random_numbers = pick_rand_nums(52, 10);
	    	for(int j = 0; j < 5; j++){
	    		strcpy(human_cards[j], cards[random_numbers[j]]);
				strcpy(computer_cards[j], cards[random_numbers[j+5]]); 
			}
			free(random_numbers);
			
	    	int human_score = determine_hand(human_cards);
	    	int computer_score = determine_hand(computer_cards);
	    	
//	    	printf("\n# HUMAN CARDS\n\n");
//	    	printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", human_cards[0], human_cards[1], human_cards[2],
//										human_cards[3], human_cards[4], score_to_name[human_score]);
			
			/*
			printf("\n-- COMPUTER CARDS --\n\n");
	   		printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", computer_cards[0], computer_cards[1], computer_cards[2],
										computer_cards[3], computer_cards[4], score_to_name[computer_score]);
			*/
			
//			printf("\n*********************\n\n");
			
	        // set value
			sprintf(command, "HUMAN VALUE %d", human_score);
			call_command_grader(&human_grader, &computer_grader, command);
			sprintf(command, "HUMAN VALUE %d", human_score);
			call_command(&human, &computer, command);
			sprintf(command, "COMPUTER VALUE %d", computer_score);
			call_command_grader(&human_grader, &computer_grader, command);
			sprintf(command, "COMPUTER VALUE %d", computer_score);
			call_command(&human, &computer, command);
			
	        // start betting
	        int human_turn = ((i+1) % 2 == 1);
	        int fail;
	        
			if(human_turn){
				strcpy(command, "HUMAN START");
//				printf("%s\n", command);
				fail = call_command_grader(&human_grader, &computer_grader, command);
				strcpy(command, "HUMAN START");
				call_command(&human, &computer, command);
			} else{
				strcpy(command, "COMPUTER START");
//				printf("%s\n", command);
				fail = call_command_grader(&human_grader, &computer_grader, command);
				strcpy(command, "COMPUTER START");
				call_command(&human, &computer, command);
			}
			
			if(fail == -1)
				break;
				
	        // loop until bet ends
			while(1){
				
				int pick;
				int result=-1;
				
				// loop while command returns -1 (NOT ENOUGH MONEY)
				while(result==-1){
					
					int human_val = human.value;
					human.value = -1;
					
					if(human_turn){
		            	//fgets(command, sizeof(command), stdin);
		            	//command[strcspn(command, "\r\n")] = '\0';
		            	pick = choose_command_grader(computer_cards+2, human_cards, &human_grader, &computer_grader);
					}
					else{
						pick = choose_command(human_cards+2, computer_cards, &human, &computer);
					}
					
					human.value = human_val;
		            
		            strcpy(command, commands[human_turn][pick]);
		            
//		            printf("%s\n", command);
					result = call_command_grader(&human_grader, &computer_grader, command);
					
					if(result == -1) // NOT ENOUGH MONEY
						continue;
					
					strcpy(command, commands[human_turn][pick]);
					call_command(&human, &computer, command);
				}
				
	            // bet ended
				if(result == 1){
	                
	                // show results
//			    	printf("\n-- HUMAN CARDS --\n\n");
//			    	printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", human_cards[0], human_cards[1], human_cards[2],
//												human_cards[3], human_cards[4], score_to_name[human_score]);
//					
//					
//					printf("\n-- COMPUTER CARDS --\n\n");
//			   		printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", computer_cards[0], computer_cards[1], computer_cards[2],
//												computer_cards[3], computer_cards[4], score_to_name[computer_score]);
//				
//					printf("\n");
					strcpy(command, "HUMAN SHOW");
//					printf("# HUMAN BUDGET    ==> %d\n", call_command_grader(&human_grader, &computer_grader, command));
					//call_command(&human, &computer, command);
					strcpy(command, "COMPUTER SHOW");
//					printf("# COMPUTER BUDGET ==> %d\n", call_command_grader(&human_grader, &computer_grader, command));
					//call_command(&human, &computer, command);
					break;	
				}
				
				human_turn = 1 - human_turn;
			}
			
//			printf("\n----- FINAL RESULT -----\n");
			strcpy(command, "HUMAN SHOW");
//			printf("# HUMAN     ==> %d\n", call_command_grader(&human_grader, &computer_grader, command));
			//call_command(&human, &computer, command);
			strcpy(command, "COMPUTER SHOW");
//			printf("# COMPUTER  ==> %d\n", call_command_grader(&human_grader, &computer_grader, command));
			//call_command(&human, &computer, command);
		}
		
		int human_final_budget;
		int computer_final_budget;
		
		strcpy(command, "HUMAN SHOW");
		human_final_budget = call_command_grader(&human_grader, &computer_grader, command);
		strcpy(command, "COMPUTER SHOW");
		computer_final_budget = call_command_grader(&human_grader, &computer_grader, command);
		
		if(computer_final_budget - computer_initial_money >= win_condition)
			win_count++;
	}
	
	printf("%d\n", win_count >= win_goal);
}
