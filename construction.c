#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "construction.h"

//prints the items in the struct
void display_stats(struct player *p){
	printf("Player Name: %s\t\tLevel: %d\t Total items collected: %d\n", p->name, p->level, p->num_collected);
}

//creates new player with name, level, and number of items collected
struct player *new_player(int i, int nc, char *n){

	struct player *np;

	//dynamic heap memory
	np = malloc(sizeof(struct player));

	strncpy(np->name, n, sizeof(np->name)-1);
	np->level=i;
	np->num_collected=nc;

	return np;
}

//changing information in the struct
void change_info(struct player *p, char *n, int i, int nc){
	strncpy(p->name, n, sizeof(p->name)-1);
	p->level=i;
	p->num_collected=nc;
}

//prints all players of the linked list
void print_list(struct player *p){
	while (p){
		display_stats(p); //print out the player in the linked list
		p=p->next; //increment to next player
	}
}

//inserts a new player at the front of the linked list with data provided
struct player * insert_front(struct player *first, int level, int nc, char name[]){
	struct player *p = new_player(level, nc, name); //new player
	p->next=first; //insert to the front of list
	return p; //return pointer to new beginning of list
}

//frees all memory of nodes
struct player * free_list(struct player *p){
	int i=1; //counter for the nth node being freed
	struct player *q; //keep track of the next player
	while (p){
		printf("Freeing node: %d\n", i++);
		q=p->next; //keeping track of the next player
		free(p);
		p=q; //going to next player 
	}
	return NULL;
}

//removes a player with the same data as provided
struct player * remove_player(struct player *p, int level, int nc, char name[]){
	struct player *first = p;	//first node in the list
	struct player *previous = NULL;	//keeping track of position in linked list 
	while (p){ 
		if (p->level==level && p->num_collected==nc && strcmp(name,p->name)==0){ //if data matches
			if (previous){ //if the player is not the first in the list
				previous->next=p->next; //connect previous to next
				free(p);
				return first; //return the pointer to the beginning of the list
			}
			return p->next; //if player is first in list, return the next player
		}
		previous=p; //increment position 
		p=p->next; //increment position
	}
	return first;
}
