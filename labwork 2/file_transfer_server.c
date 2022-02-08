
#include "file_transfer.h"

int *transf_1_svc(put_req *argp, struct svc_req *rqstp)
{
	char opened_file[MAXLEN];
	FILE *ofile;
	long long int total = 0;
	long long int chunk = 0;
	static int result = 1;
	total += argp->data.nbytes + argp->total;
	chunk += total/MAXLEN;

	if (strcmp(opened_file, "") == 0 && ofile == NULL)
	{
		printf("Sending new file %s.\n", argp->data.name);

		strcpy(opened_file, argp->data.name);
		ofile = fopen(argp->data.name, "ab+");
	}
	if (strcmp(opened_file, argp->data.name) == 0)
	{
		printf("\rChunk %lld ,%lld bytes of file %s were received.", chunk, total, argp->name);
		fflush(stdout);

		fwrite(argp->data.data, 1, argp->data.nbytes, ofile);
		result = 0;

		if (argp->data.nbytes < MAXLEN)
		{
			printf("\nFinished receiving %s.\n", argp->name);
			total = 0;
			chunk = 0;
			fclose(ofile);
			ofile = NULL;
			strcpy(opened_file, "");
		}
	}
	return &result;
}

response *transf2_1_svc(get_request *argp, struct svc_req *rqstp)
{
	static response result;
	FILE *ofile;
	ofile = fopen(argp->name, "rb");
	long long int total = 0;
	long long int chunk = 0;

	if (ofile == NULL)
	{
		printf("File not found.\n");
		exit(1);
	}

	printf("Sending file %s.\n", argp->name);
	strcpy(result.name,argp->name);
	result.response_type = PUT;
	fseek (ofile, argp->start, SEEK_SET);
    result.data.nbytes = fread(result.data.data, 1, MAXLEN, ofile);
    total += argp->start + result.data.nbytes;
	chunk = total/MAXLEN;

	printf("\rChunk %lld and Total %lld bytes of %s sent to Client.",chunk, total, argp->name);
	fflush(stdout);
	fclose(ofile);
	return &result;
}
