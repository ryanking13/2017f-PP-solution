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

int determine_hand(char c[5][4]){
	Card hand[5];
	
	for(int i=0;i<5;i++){
		if( c[i][0] == 'H' ) hand[i].symbol = 1;
		if( c[i][0] == 'D' ) hand[i].symbol = 2;
		if( c[i][0] == 'C' ) hand[i].symbol = 3;
		if( c[i][0] == 'S' ) hand[i].symbol = 4;

		if( c[i][1] == 'A' ) hand[i].number = 14;
		else if( c[i][1] == 'J' ) hand[i].number = 11;
		else if( c[i][1] == 'Q' ) hand[i].number = 12;
		else if( c[i][1] == 'K' ) hand[i].number = 13;
		else hand[i].number = atoi(c[i]+1);
	}
	
	int symbol_cnt[5], number_cnt[15];
		for(int i=1;i<=4;i++) symbol_cnt[i] = 0;
		for(int i=2;i<=14;i++) number_cnt[i] = 0;
	
		for(int n=0;n<5;n++){
			symbol_cnt[hand[n].symbol]++;
			number_cnt[hand[n].number]++;
		}
	
		int two_cnt = 0 , three_cnt = 0, four_cnt = 0;
		int unique_symbol = 0;
		for(int i=2;i<=14;i++){
			if( number_cnt[i] == 2 ) two_cnt++;
			if( number_cnt[i] == 3 ) three_cnt++;
			if( number_cnt[i] == 4 ) four_cnt++;
		}
		for(int i=1;i<=4;i++){
			if( symbol_cnt[i] == 5 ) unique_symbol = 1;
		}
	
		// Find straight
		// A2345 = X / JQKA2 = X / 10JQKA = OK 
		// back straight is not considered (A2345)
		int straight = 0;	
		for(int i=2;i<=10;i++){
			int found = 1;
			for(int j=0;j<5;j++){
				if( number_cnt[i+j] != 1 ){
					found = 0;
					break;
				}
			}
			if( found == 1 ){
				straight = 1;
				break;
			}
		}
		
		// royal straight flush (9)
		if( unique_symbol == 1 ){
			int ok = 1;
			for(int i=0;i<5;i++){
				if( number_cnt[10+i] != 1 ) ok = 0;
			}
			if( ok == 1 ) return 9; 
		}
	
		// straight flush (8)
		if( unique_symbol == 1 && straight == 1 ) return 8;
		
		// four card (7)
		if( four_cnt == 1 ) return 7;
	
		// full house (6)
		if( two_cnt == 1 && three_cnt == 1 ) return 6;
	
		// flush (5)
		if( unique_symbol == 1 ) return 5;
	
		// straight (4)
		if( straight == 1 ) return 4;
	
		// three card (3)
		if( three_cnt == 1 ) return 3;
	
		// two pair (2)
		if( two_cnt == 2 ) return 2;
	
		// one pair (1)
		if( two_cnt == 1 ) return 1;
	
		// no pair (0)
		return 0;
}

int call_command(Player* human, Player* computer, char* command){
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

int choose_command(char human_cards[3][4], char computer_cards[5][4], Player* human, Player* computer){
	// return value : call = 0, raise = 1, fold = 2
	int val = determine_hand(computer_cards);
	
	if(human->bet * 2 >= computer->budget){
		return 0;
	}
	
	int ab = (human_cards[0][1] == human_cards[1][1]);
	int bc = (human_cards[1][1] == human_cards[2][1]);
	int ca = (human_cards[2][1] == human_cards[0][1]);
	
	if(val == 0){
		return 2;
	}
	else{
		if(val == 1){
			if(ab || bc || ca){
				return 2;
			}
			else if(human->bet < 200000){
				return 1;
			}
			else{
				return 0;
			}
		}
		else if(val == 2){
			if(ab && bc){
				return 2;
			}
			else if(human->bet < 400000){
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			return 1;
		}
	}
}

/*************
	comment out below this line when submitting!
	comment out below this line when submitting!
*************/
/*
// select n random numbers in [0, max_num)
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

// poker cards
char cards[52][4] = {"DA","D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK",
						"HA","H2","H3","H4","H5","H6","H7","H8","H9","H10","HJ","HQ","HK",
						"SA","S2","S3","S4","S5","S6","S7","S8","S9","S10","SJ","SQ","SK",
						"CA","C2","C3","C4","C5","C6","C7","C8","C9","C10","CJ","CQ","CK"};

// possible bet commands
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

    int n_games = 30; // # of games
    int human_initial_money = 100000000;
    int computer_initial_money = 10000000;
    int win_condition = computer_initial_money / 50; // if player earns more than this, player wins;
    int win_count = 0;
    
    char human_cards[5][4];
    char computer_cards[5][4];
    
    char command[50];
    
    // show intro message and rules
    printf("%s\n", intro);
    printf(explanation, n_games);
    
	// start the game
    Player human = {0,0,0,0};
    Player computer = {0,0,0,0};
    
    // set default budget of HUMAN and COMPUTER
    sprintf(command, "HUMAN ADD %d", human_initial_money);
    call_command(&human, &computer, command);
    sprintf(command, "COMPUTER ADD %d", computer_initial_money);
    call_command(&human, &computer, command);
    
    for(int i = 0; i < n_games; i++){
    	
    	printf("\n***** ROUND %3d *****\n", i+1);
    	
    	// select 10 random cards
    	int* random_numbers = pick_rand_nums(52, 10);
    
    	// set human, computer hand
    	for(int j = 0; j < 5; j++){
    		strcpy(human_cards[j], cards[random_numbers[j]]);
			strcpy(computer_cards[j], cards[random_numbers[j+5]]); 
		}
		
		free(random_numbers);
		
    	int human_score = determine_hand(human_cards);
    	int computer_score = determine_hand(computer_cards);
    	
    	printf("\n# HUMAN CARDS\n\n");
    	printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", human_cards[0], human_cards[1], human_cards[2],
									human_cards[3], human_cards[4], score_to_name[human_score]);
		
		
		// printf("\n-- COMPUTER CARDS --\n\n");
   		// printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", computer_cards[0], computer_cards[1], computer_cards[2],
		//							computer_cards[3], computer_cards[4], score_to_name[computer_score]);
		
		
		printf("\n*********************\n\n");
		
        // set value
		sprintf(command, "HUMAN VALUE %d", human_score);
		call_command(&human, &computer, command);
		sprintf(command, "COMPUTER VALUE %d", computer_score);
		call_command(&human, &computer, command);
		
        // start betting
        int human_turn = ((i+1) % 2 == 1);
        int fail;
        
		if(human_turn){
			strcpy(command, "HUMAN START");
			printf("%s\n", command);
			fail = call_command(&human, &computer, command);
		} else{
			strcpy(command, "COMPUTER START");
			printf("%s\n", command);
			fail = call_command(&human, &computer, command);
		}
		
		// NOT ENOUGH MONEY --> game end 
		if(fail == -1)
			break;
			
        // loop until bet ends
		while(1){
			
			int pick;
			int result = -1;
			
			// loop while command returns -1 (NOT ENOUGH MONEY)
			while(result == -1){
				
				// if it is human's turn, you give a command
				if(human_turn){
	            	fgets(command, sizeof(command), stdin);
	            	command[strcspn(command, "\r\n")] = '\0';
	            	result = call_command(&human, &computer, command);
				}
				// if it is computer's turn, AI will give a command
				else{
					pick = choose_command(human_cards+(4*2), computer_cards, &human, &computer);
					strcpy(command, commands[human_turn][pick]);
					printf("%s\n", command);
					result = call_command(&human, &computer, command);
				}
				
				if(result == -1) // NOT ENOUGH MONEY
					continue;
			}
			
            // bet ended
			if(result == 1){
                
                // show results
		    	printf("\n-- HUMAN CARDS --\n\n");
		    	printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", human_cards[0], human_cards[1], human_cards[2],
											human_cards[3], human_cards[4], score_to_name[human_score]);
				
				
				printf("\n-- COMPUTER CARDS --\n\n");
		   		printf("| %3s %3s %3s %3s %3s | ==> [ %s ]\n", computer_cards[0], computer_cards[1], computer_cards[2],
											computer_cards[3], computer_cards[4], score_to_name[computer_score]);
			
				printf("\n");
				printf("# HUMAN BUDGET    ==> ");
				strcpy(command, "HUMAN SHOW");
				call_command(&human, &computer, command);
				printf("# COMPUTER BUDGET ==> ");
				strcpy(command, "COMPUTER SHOW");
				call_command(&human, &computer, command);
				break;	
			}
			
			// change order
			human_turn = 1 - human_turn;
		}
	}
	
	printf("\n----- FINAL RESULT -----\n");
	strcpy(command, "HUMAN SHOW");
	printf("# HUMAN     ==> ");
	call_command(&human, &computer, command);
	strcpy(command, "COMPUTER SHOW");
	printf("# COMPUTER  ==> ");
	call_command(&human, &computer, command);
}
*/
