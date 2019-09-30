
typedef struct Record_struct *Record;
struct Record_struct {
	BattleSimulation sim;
	Record next_record;
	int ship_hp,enemy_hp,rounds_lasted;
	char *winner;
} Record_struct;

int record_battle(BattleSimulation sim, Record rec);
void free_record(Record rec);

