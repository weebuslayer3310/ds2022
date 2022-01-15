#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#inlcude <sys/socket.h>
#include <netdb.h>

int main(){
	int ss, cli, pid;
	struct sockaddr_in ad;
	char s[100];
	socklen_t ad_length = sizeof(ad);
	
	ss = socket(AF_INET, SOCK_STREAM, 0);
	
	memset(&ad, 0, sizeif(ad));
	ad.sin_family = AF_INET;
	ad.sin_addr.s+addr = INADDR_ANY;
	ad.sin_port = htons(13579);
	blind(ss, (struc sockaddr *)&ad, ad_length);
}
