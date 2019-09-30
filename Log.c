#include "BattleSimulation.h"
#include "Record.h"
#include "Log.h"
#include <stdio.h>
#include <stdlib.h>

int init_log(Log self){
	self->ctr=0;
	printf("sizeof Log: %lu\n",sizeof(Log_struct));
//	printf("sizeof Ctr: %lu\n",sizeof(self->ctr));
//	printf("sizeof a Record: %lu\n",sizeof(Record_struct));
	printf("sizeof records array: %lu\n",sizeof(self->records_array));
	//printf("sizeof ctr: %lu\n",sizeof(self->ctr));
	return 0;
}

int update_log(Log self, Record rec) {
	unsigned short t  = self->ctr;
	self->records_array[t] = (Record) malloc(sizeof(Record_struct));
	self->records_array[t]->ship_hp = rec->ship_hp;
	self->records_array[t]->enemy_hp = rec->enemy_hp;
	self->records_array[t]->winner = rec->winner;
	self->records_array[t]->rounds_lasted = rec->rounds_lasted;
	self->ctr = self->ctr+sizeof(Record);
	printf("log update. Got from rec {%d, %d, %s, %d} \n",self->records_array[t]->ship_hp,
	self->records_array[t]->enemy_hp, self->records_array[t]->winner,self->records_array[t]
	->rounds_lasted);
	return 0;
}
void print_log(Log self){
	int ctr = self->ctr;
	for (int i=0;i<ctr;i=i+8){
		printf("---SIMULATION RESULTS---\n");
		printf("Initial Ship's HP: %d || Initial Enemy's HP: %d\n",
		self->records_array[i]->ship_hp,self->records_array[i]->enemy_hp);
		printf("Rounds Lasted: %d || Winner: %s\n",self->records_array[i]->rounds_lasted,
		self->records_array[i]->winner);
//		printf("Winner for this record %s",rec->winner);
	}
}

void free_log(Log self){
int ctr = self->ctr;
for (int i=0;i<ctr;i=i+8){
	free(self->records_array[i]);
	}
free(self);
}
