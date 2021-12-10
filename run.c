#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
//hello
char fileContent[10000];

unsigned int xorbuf(int* buffer, int size) {
    unsigned int result = 0;
    for (int i = 0; i < size; i++) {
        result ^= buffer[i];
    }
    return result;
}

int readFile(int fd, int block_size, int block_count) {
  int n;
  int *buf;
  int total_read = 0;
  int n_read;
  int size = block_size * block_count;
  buf = (int*)malloc(size*sizeof(int));

  // for(int i = 0 ; i < block_count; i++) {
  //   n = read(fd, buf, block_size);
  //   if (n < 0) {
  //     printf("read: read error\n");
  //     return;
  //   }
  // }

  // printf("xor: %08x\n", xorbuf(buf, SIZE));

  // while ((n = read(fd, buf, size)) > 0) {
  //   if (n < 0) {
  //     printf("read: read error\n");
  //     return;
  //   }
  //   size += n;
  // }

  // printf("xor: %08x\n", xorbuf(buf, block_size * block_count));

  // free(buf);
  // buf = NULL;

  // return;

    
  while ((n_read = read(fd, buf + total_read, size - total_read)) > 0) {
    total_read += n_read;
  }  
	
  printf("xor: %08x\n", xorbuf(buf, total_read));
  return ((n_read <0) ? n_read : total_read);
}

int writeFile(int fd, int block_size, int block_count) {
  if (fd < 0) {
    printf("Error in opening the file for writing\n");
    return 1;
  }
      
  int result = lseek(fd, block_size * block_count, SEEK_SET);
  if (result < 0) {
    printf("Error1\n");
    close(fd);
    return 1;
  }
  result = write(fd, "a", 1);
  if (result < 0) {
    printf("Error2\n");
    close(fd);
    return 1;
   }
}

double now() {
    struct timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec / 1000000.0;
}

int main(int argc, char *argv[]) {
  int fd, i, n;
  double startr, endr;
  double startw, endw;

  if (argc != 5) {
    printf("Incorrect number of arguments, exiting.\n");
    printf("Sample usage: \n./run <filename> [-r|-w] <block_size> <block_count>\n");
    return 0;
  }

  int block_size = atoi(argv[3]);
  int block_count = atoi(argv[4]);


  if (argv[2][1] == 'w') {
      startw = now();
      fd = open(argv[1], O_RDWR|O_CREAT, (mode_t)0600);
      writeFile(fd, block_size, block_count);
      endw = now();
      printf("[final_proj.c] writing completed in %f seconds\n", endw - startw);
  }
  else if (argv[2][1] == 'r') {
    if ((fd = open(argv[1], O_RDWR|O_CREAT)) > 0) {
      startr = now();
      readFile(fd, block_size, block_count);
      endr = now();
      printf("[final_proj.c] reading completed in %f seconds\n", endr - startr);
    }
  }

  close(fd);

  return 0;
}
