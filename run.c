#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>


unsigned int xorbuf(unsigned int* buffer, int size) {
    unsigned int result = 0;
    for (int i = 0; i < size; i++) {
        result ^= buffer[i];
    }
    return result;
}


void readFile(int fd, int block_size, int block_count) {
    int n;
    unsigned int *buf = (unsigned int*)malloc(block_size*sizeof(unsigned int));
    unsigned int xor;

    while (n=read(fd, buf, block_size)) {
  	  xor ^= xorbuf(buf, n);
  	}
  	
    printf("xor: %08x\n", xor);
    close(fd);
}

void writeFile(int fd, int block_size, int block_count) {
  if (fd < 0) {
    printf("Error in opening the file for writing\n");
  }
      
  int result = lseek(fd, block_size * block_count, SEEK_SET);
  if (result < 0) {
    printf("Error1\n");
    close(fd);
  }
  result = write(fd, "a", 1);
  if (result < 0) {
    printf("Error2\n");
    close(fd);
   }
   close(fd);
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
      printf("[run.c] writing completed in %f seconds\n", endw - startw);
      close(fd);
  }
  else if (argv[2][1] == 'r') {
    if ((fd = open(argv[1], O_RDWR|O_CREAT)) > 0) {
      startr = now();
      readFile(fd, block_size, block_count);
      endr = now();
      printf("[run.c] reading completed in %f seconds\n", endr - startr);
    }
  }

  return 0;
}
