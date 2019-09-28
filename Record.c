#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BattleSimulation.h"
#include "Record.h"

int record_battle(BattleSimulation sim, Record rec){
	rec->sim = sim;
	rec->next_record = rec+1;
	//debugging purposes. sizeof Record_struct: 40 (36 + 4 padding bytes)	
	printf("Sizeof int: %lu\n",sizeof(rec->ship_hp));
	printf("Sizeof winner: %lu\n",sizeof(rec->winner));
	printf("Sizeof sim: %lu\n",sizeof(rec->sim));
	printf("current record at: %p\n",rec);
	printf("next record at: %p\n",rec->next_record);
	main_battle("USS Enterprise","Borg Drone", sim);
	rec->ship_hp = sim->ship_hp;
	rec->enemy_hp = sim->enemy_hp;
	rec->winner = sim->winner;
	rec->rounds_lasted = sim->rounds_lasted;
	printf("--> Initial values: \nOur ship HP: %d\n",rec->ship_hp);
	printf("Enemy ship HP: %d\n",rec->enemy_hp);
	printf("--> Final Results:\nRounds lasted: %d\n",rec->rounds_lasted);
	printf("%s survived the round.\n",rec->winner);
	return 0;
}

void free_record(Record rec){
	free(rec);
}


