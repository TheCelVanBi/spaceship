#include "BattleSimulation.h"
#include "Record.h"
#include "Log.h"
#include <stdio.h>
#include <stdlib.h>

int init_log(Log self){
self->ctr=0;
printf("sizeof Log: %lu\n",sizeof(self));
printf("sizeof records array: %lu\n",sizeof(self->records_array));
//printf("sizeof ctr: %lu\n",sizeof(self->ctr));
return 0;
}

int update_log(Log self, Record rec) {
	//todo refactor to match requirements. need to assign spaceship references to battlesimulation instead
	self->records_array[self->ctr] = rec;
	self->ctr++;
//	int i = self->ctr;
	printf("log update, winner: %s\n",rec->winner);
	return 0;
}
void print_log(Log self){
	for (int i=0;i<(self->ctr);i++){
		printf("Record number %d\n",i+1);
//		printf("%s\n",self->records_array[self->ctr]->winner);
	}
}
