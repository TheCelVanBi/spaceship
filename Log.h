typedef struct Log_struct *Log;
struct Log_struct {
	short ctr;
	Record records_array[1000];
} Log_struct;
int init_log(Log self);
int update_log(Log self, Record rec);
void print_log(Log self);
