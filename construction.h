#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

struct player{
	int level;
	int num_collected;
	char name[256];
	struct player *next;
};

void print_stats(struct player p);
struct player * new_player(int i, int nc, char *n);
void change_info(struct player *p, char *n, int i, int nc);
void print_list(struct player *p);
struct player * insert_front(struct player *first, int level, int nc, char name[]);
struct player * free_list(struct player *p);
struct player * remove_player(struct player *first, int level, int nc, char name[]);

#endif