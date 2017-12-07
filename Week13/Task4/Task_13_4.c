#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct card{
	// symbol = 1 = Hearts, 2 = Diamond, 3 = Clubs, 4 = Spades
	// number = 2 ~ 14 (11=J 12=Q 13=K, 14=Ace)
	int symbol; int number;
} Card;

typedef struct player {
	int budget;
	int value;
	int call;
	int bet;
} Player;

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
		if (player->budget < num)
			printf("NOT ENOUGH MONEY\n");
		else
			player->budget -= num;
	}
	else if (strcmp(cmd, "VALUE") == 0)
	{
		num = atoi(strtok(NULL, " "));
		player->value = num;
	}
	else if (strcmp(cmd, "SHOW") == 0)
		printf("%d\n", player->budget);
	else if (strcmp(cmd, "START") == 0)
	{
		if (player->budget < 100 || opponent->budget < 100){
			printf("NOT ENOUGH MONEY\n");
			return 1;
		}
			
		else {
			player->bet = 100;
			opponent->bet = 100;
		}
	}
	else if (strcmp(cmd, "RAISE") == 0)
	{
		if (player->budget < opponent->bet * 2)
			printf("NOT ENOUGH MONEY\n");
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

