#include <sys/ioctl.h>

#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>

#include <fcntl.h> //open

#include <unistd.h> //close

#include "dump_mem.h"

#define DEVICE_DIR "/dev/dri/renderD128"

#define DATA_SIZE 4096


int main(int argc, char **argv)

{

	int ret = 0;
        int i=0;
	struct drm_icubegpu_dump_mem args;
        unsigned int data[DATA_SIZE] = {0};

    int fd = open(DEVICE_DIR, O_RDWR);

    if(fd < 0){

        printf("open device: /dev/dri/renderD128  failed!\n");

		return -1;

    }
        printf("%s\n", argv[1]); 
        args.data_addr = strtol(argv[1], NULL, 16);
        args.data_size = DATA_SIZE;
        args.user_addr = data;
        args.type = atoi(argv[2]);

        printf("args.data_addr = 0x%llx\n", args.data_addr);
        printf("args.data_size = %d\n", args.data_size);
        printf("args.user_addr = %p\n", args.user_addr);
        printf("args.type = %d\n", args.type);
	ret = ioctl(fd, DRM_IOCTL_ICUBEGPU_DUMP_MEM, &args);
	
	 if(ret < 0){
	
		printf("%s, %d, dump mem failed!\n", __FUNCTION__, __LINE__);
	
		return -1;
	
	 }

    close(fd);
    printf("-------------------------------------------\n"); 
    for(i=0; i<16; i++){
        if(i % 4 == 0){
           printf("\n");
        }
        printf("0x%8x ", data[i]);
    }

    return 0;

}

