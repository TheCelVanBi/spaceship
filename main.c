/**
* @author Panos Patros
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BattleSimulation.h"
#include "Record.h"
#include "Log.h"
int
main(){
	srand(time(NULL));
	/*
	//test epic battle
	init_battlesim(b,100,1);
	printf("Conducting battle\n");
	main_battle("USS Enterprise","Borg Drone",b);
/*
	attack_spaceship(s1,s2);
	attack_spaceship(s2,s1);
	//Print info post-battle
	print_spaceship(s1);
	print_spaceship(s2);
	//Free both
	free_spaceship(s1);
	free_spaceship(s2);
*/
	Log log;
	log = (Log) malloc(sizeof(Log_struct));
	init_log(log);
	for(int i=0;i<10;i++) {
		//printf("Iteration %d\n",i+1);
		BattleSimulation sim;
		sim = (BattleSimulation) malloc(sizeof(BattleSimulation_struct));
		init_battlesim(sim);
		Record rec;
		rec = (Record) malloc(sizeof(Record_struct));
		record_battle(sim,rec);
		update_log(log,rec);
		free_sim(sim);
		free_record(rec);
	}
	print_log(log);
	free_log(log);
	return 0;
}
