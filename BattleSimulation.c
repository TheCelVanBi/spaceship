#include "Spaceship.h"
#include "BattleSimulation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init_battlesim(BattleSimulation sim){
	//dunno when to config rounds; will set to rand for now
	sim->rounds_max = rand()%100+1;
	sim->id = rand()%1000;
	sim->rounds_lasted = 0;
}

void main_battle(char *ship, char *enemy, BattleSimulation sim){

	Spaceship s1, s2;
	s1 = (Spaceship) malloc(sizeof(Spaceship_struct));
        if(s1 == NULL){
                printf("Malloc failed for s1!\n");
        }
        s2 = (Spaceship) malloc(sizeof(Spaceship_struct));
        if(s2 == NULL){
	                printf("Malloc failed for s2!\n");
        }
	init_spaceship(s1,ship);
	init_spaceship(s2,enemy);
	sim->ship_hp = s1->health_points;
	sim->enemy_hp = s2->health_points;
//	print_spaceship(s1);
//	print_spaceship(s2);
        while(s1->health_points>0 && s2->health_points>0 && sim->rounds_max>=sim->rounds_lasted){
                attack_spaceship(s1,s2);
                if(s2->health_points > 0){
                	attack_spaceship(s2,s1);
                }
                sim->rounds_lasted++;
	}
	if (s1->health_points>0 && s2->health_points<=0){
		int len_s1_name = strlen(s1->name);
		sim->winner = malloc(len_s1_name+1);
		strncpy(sim->winner,s1->name,len_s1_name+1);
	}
	if (s2->health_points>0 && s1->health_points<=0){
		int len_s2_name = strlen(s2->name);
		sim->winner = malloc(len_s2_name+1);
		strncpy(sim->winner,s2->name,len_s2_name+1);
	}
	if (s2->health_points>0 && s1->health_points>0) {
		char winner_default[4] = "Both";
		int winlen = strlen(winner_default);
		sim->winner = malloc(winlen+1);
		strncpy(sim->winner,winner_default,winlen+1);

	}
	free_spaceship(s1);
	free_spaceship(s2);
}

void free_sim(BattleSimulation self){
	free(self->winner);
	free(self);
}
