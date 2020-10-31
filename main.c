#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "construction.h"

//Structs for players in a game
int main(){
	srand(time(NULL));

	printf("\nWelcome to the game!\n");

	//linked list of all players in the game
	struct player *player_list = NULL;

	//Creating new players and randomizing certain parts, inserting at front of list
	printf("\nInserting new players...\n");
	struct player *player1 = insert_front(player_list, rand()%500, rand()/100, "Potatocat");
	struct player *player2 = insert_front(player1, rand()%500, rand()/100, "Pandamouse");
	struct player *player3 = insert_front(player2, rand()%500, rand()/100, "Iceduck");
	struct player *player4 = insert_front(player3, rand()%500, rand()/100, "Firepup");
	print_list(player4); //printing out the entire list of players

	//Removing a player
	printf("\nRemoving player Potatocat...\n");
	player4=remove_player(player4, player1->level, player1->num_collected,"Potatocat");
	print_list(player4);

	//Removing a player
	printf("\nRemoving player Iceduck...\n");
	player4=remove_player(player4, player3->level, player3->num_collected,"Iceduck");
	print_list(player4);

	//Freeing the nodes
	printf("\nFreeing nodes...\n");
	player4=free_list(player4);

	print_list(player4); //empty list

	return 0;
}