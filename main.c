/**
* @author Panos Patros
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Spaceship.h"
#include "BattleSimulation.h"
#include "Record.h"
int
main(){
	srand(time(NULL));
	BattleSimulation b;
	b = (BattleSimulation) malloc(sizeof(BattleSimulation_struct));
	init_battlesim(b);
	Record r;
	r = (Record) malloc(sizeof(Record_struct));
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
	record_battle(b,r);
	free_sim(b);
	free_record(r);
	return 0;
}
