#include <stdio.h>
#include <stdlib.h>
#include "Record.h"
#include "BattleSimulation.h"
#include "Spaceship.h"
#include "Record.h"
int init_log(Log self){
self->ctr=0;
return 0;
}
int log_session(Log self, Record rec) {
	//todo refactor to match requirements. need to assign spaceship references to battlesimulation instead
	self->records_array[ctr] = rec;
	self->ctr++;
	return 0;
}
