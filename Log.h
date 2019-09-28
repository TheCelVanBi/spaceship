typedef struct Log_struct *Log;
struct Log_struct {
	Record records_array[100];
} Log_struct;

int log_session();
