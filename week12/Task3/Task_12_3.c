#include <stdio.h> 
#include <stdlib.h>
typedef struct card{
	// symbol = 1 = Hearts, 2 = Diamond, 3 = Clubs, 4 = Spades
	// number = 2 ~ 14 (11=J 12=Q 13=K, 14=Ace)
	int symbol; int number;
} Card;


// Based on : http://7poker.dreamx.com/game/7poker/7poker_help_01.asp
int determine(Card hand[5]){
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

char types[11][30] = {"No Pair", "One Pair", "Two Pair", "Three Card", 
						"Straight", "Flush" , "Full House","Four Card",
						"Straight Flush", "Royal Straight Flush"};
int main(void){
	int tc; scanf("%d",&tc);
	while(tc--){
		char input[5][10];
		for(int i=0;i<5;i++) scanf("%s",input[i]);
		
		// symbol : 1 = Hearts(H), 2 = Diamond(D), 3 = Clubs(C), 4 = Spades(S)
		// number : 2 ~ 14 (11=J 12=Q 13=K, 14=Ace)
		Card hand[5];
		for(int i=0;i<5;i++){
			if( input[i][0] == 'H' ) hand[i].symbol = 1;
			if( input[i][0] == 'D' ) hand[i].symbol = 2;
			if( input[i][0] == 'C' ) hand[i].symbol = 3;
			if( input[i][0] == 'S' ) hand[i].symbol = 4;

			if( input[i][1] == 'A' ) hand[i].number = 14;
			else if( input[i][1] == 'J' ) hand[i].number = 11;
			else if( input[i][1] == 'Q' ) hand[i].number = 12;
			else if( input[i][1] == 'K' ) hand[i].number = 13;
			else hand[i].number = atoi(input[i]+1);
		}
		
		int type = determine(hand);
		printf("%s\n",types[type]);

	}
}

/* Sample input
5
D4 H4 S4 C4 C5
D10 HA S3 C2 CA
DA H10 SJ CQ CK
DA DK DQ DJ D10
S2 S3 H2 H3 D10
*/