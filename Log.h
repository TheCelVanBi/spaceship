typedef struct Log_struct *Log;
struct Log_struct {
	Record records_array[100];
	u_int8_t ctr;
} Log_struct;

int log_session(Log self, Record rec);
