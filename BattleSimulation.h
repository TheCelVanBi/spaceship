typedef struct BattleSimulation_struct *BattleSimulation;
struct BattleSimulation_struct {
	int id, ship_hp, enemy_hp, rounds_lasted, rounds_max;
	char *winner;
} BattleSimulation_struct;

int init_battlesim(BattleSimulation sim);
void main_battle(char ship[], char enemy[], BattleSimulation sim);
void free_sim(BattleSimulation self);
