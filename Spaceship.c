/**
* @author Panos Patros
**/

#include "Spaceship.h"
#include <stdio.h> /*printf*/
#include <stdlib.h> /*rand*/
#include <string.h> /*strncpy, strlen*/

int
init_spaceship(Spaceship self, char *name){
	int name_length = strlen(name);
	self->name = malloc(name_length + 1);
	if(self->name == NULL){
		/*Malloc failed*/
		return -1;
	}
	strncpy(self->name, name, name_length);
	self->health_points = rand()%21 + 80;
	self->defense_points = rand()%6 + 5;
	self->attack_points = rand()%11 + 10;
	return 0;
}

int
calculate_attack_power_spaceship(Spaceship self){
       //Write up
	int attack_point_mult = rand()%2+1;
	return attack_point_mult;
}


void
attack_spaceship(Spaceship self, Spaceship underAttack){
	/*Write up*/
	int mult = calculate_attack_power_spaceship(self);
	int damage =((self->attack_points*mult)/2) - underAttack->defense_points;
	if (damage >= 0)
	{
		underAttack->health_points = underAttack->health_points - damage;
		//printf("%s attacked %s! %d damage dealt.\n",self->name,underAttack->name,damage);
	}
	else{
		//printf("%s attacked %s but %s's shield blocks all damage.\n",self->name, underAttack->name,underAttack->name);
	}     

}

int
is_destroyed_spaceship(Spaceship self){
       /*Write up*/
	if (self->health_points<=0){ printf("Spaceship %s is destroyed.\n",self->name);}
	else{
	printf("Spaceship %s is still operational.\n",self->name);
	}
 	return 0;
}

void
print_spaceship(Spaceship self){
	printf("%s: %d (HP), %d (AP), %d (DP)\n", self->name, self->health_points, self->attack_points, self->defense_points);
}

void
free_spaceship(Spaceship self){
	free(self->name);
	free(self);
}
