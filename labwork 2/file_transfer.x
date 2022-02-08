const MAXLEN = 262144;
const REQUEST_VALUE = 1000;
const RESPONSE_VALUE = 1000;
const GET = 1;
const PUT = 2;
const ERROR = 0;

typedef opaque filebytes[MAXLEN];

struct file {
	char name[MAXLEN];
	filebytes data;
	int nbytes;
};

struct send_{
	char value[REQUEST_VALUE];
	char name[REQUEST_VALUE];
	struct file data;
	int request_type ;
	int total;
};
typedef struct send_ put_req;

struct request_{
	char value[REQUEST_VALUE];
	char name[REQUEST_VALUE];
	int request_type;
	int recieved;
	int start;
};
typedef struct request_ get_request;

struct response{
	char value[REQUEST_VALUE];
	char name[REQUEST_VALUE];
	struct file data;
	int response_type ;
};

typedef struct response response;


program FILE_TRANSFER {
	version FILE_TRANSFER_1 {
		int TRANSF(put_req) = 1;
		response TRANSF2(get_request) = 2;
	} = 1;
} = 0x31230000;
