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

/* int readFile(int fd, int block_size, int block_count) {
  int n;
  int *buf = (unsigned int*)malloc(block_size*sizeof(unsigned int));
  unsigned int xor;
  
  for (int i = 0; i < block_count; i++) {
  	n = read(fd, buf, block_size);
  	xor = xorbuf(buf, n);
  }
  
  printf("xor: %08x\n", xor);
  free(buf);
  buf = NULL;
  close(fd);
  return 0;
}
 */

void readFile(int fd, int block_size) {
    int n;
    unsigned int *buf = (unsigned int*)malloc(block_size*sizeof(unsigned int));
    unsigned int xor;

    while ((n=read(fd, buf, block_size * sizeof(unsigned int))) > 0) {
        n = (int)(n/sizeof(unsigned int));
        xor ^= xorbuf(buf, n);
    }
    printf("xor: %08x\n", xor);
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

  if (argc != 2) {
    printf("Incorrect number of arguments, exiting.\n");
    printf("Sample usage: \n./fast <filename>\n");
    return 0;
  } else {
      if ((fd = open(argv[1], O_RDWR|O_CREAT)) > 0) {
        startr = now();
        readFile(fd,4096);
        endr = now();
        printf("[run.c] reading completed in %f seconds\n", endr - startr);
      }
  }
  return 0;
}
