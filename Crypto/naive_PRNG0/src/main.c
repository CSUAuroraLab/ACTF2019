#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char flag[32];
char banner[] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x5F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x0A, 0x7C, 0x5C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2F, 0x7C, 0x28, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x5C, 0x28, 0x20, 0x5C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x28, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x5C, 0x28, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x29, 0x28, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x29, 0x28, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x5C, 0x20, 0x20, 0x5C, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x2F, 0x28, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x29, 0x0A, 0x7C, 0x20, 0x29, 0x20, 0x20, 0x20, 0x28, 0x20, 0x7C, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x20, 0x5C, 0x2F, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x20, 0x5C, 0x2F, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x29, 0x20, 0x7C, 0x7C, 0x20, 0x28, 0x29, 0x20, 0x28, 0x29, 0x20, 0x7C, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x20, 0x5C, 0x2F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x29, 0x20, 0x28, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x29, 0x20, 0x7C, 0x0A, 0x7C, 0x20, 0x7C, 0x20, 0x5F, 0x20, 0x7C, 0x20, 0x7C, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x7C, 0x20, 0x7C, 0x7C, 0x20, 0x7C, 0x7C, 0x20, 0x7C, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x0A, 0x7C, 0x20, 0x7C, 0x28, 0x20, 0x29, 0x7C, 0x20, 0x7C, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x29, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x7C, 0x20, 0x7C, 0x28, 0x5F, 0x29, 0x7C, 0x20, 0x7C, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x29, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x0A, 0x7C, 0x20, 0x7C, 0x7C, 0x20, 0x7C, 0x7C, 0x20, 0x7C, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x0A, 0x7C, 0x20, 0x28, 0x29, 0x20, 0x28, 0x29, 0x20, 0x7C, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x2F, 0x5C, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x2F, 0x5C, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x2F, 0x5C, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x5F, 0x29, 0x20, 0x7C, 0x7C, 0x20, 0x29, 0x20, 0x20, 0x20, 0x28, 0x20, 0x7C, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x2F, 0x5C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x5F, 0x29, 0x20, 0x7C, 0x0A, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x29, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x2F, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x2F, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x2F, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x29, 0x7C, 0x2F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5C, 0x7C, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x2F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x29, 0x5F, 0x28, 0x20, 0x20, 0x20, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x29, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x5F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x28, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x20, 0x5C, 0x20, 0x28, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x29, 0x28, 0x20, 0x20, 0x5F, 0x5F, 0x20, 0x20, 0x5C, 0x20, 0x20, 0x20, 0x28, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x29, 0x28, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x29, 0x28, 0x20, 0x28, 0x20, 0x20, 0x20, 0x20, 0x2F, 0x7C, 0x28, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x5C, 0x20, 0x20, 0x28, 0x20, 0x20, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x29, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x29, 0x20, 0x29, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x29, 0x20, 0x7C, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x5C, 0x20, 0x20, 0x29, 0x20, 0x20, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x20, 0x29, 0x7C, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x20, 0x29, 0x7C, 0x7C, 0x20, 0x20, 0x5C, 0x20, 0x20, 0x28, 0x20, 0x7C, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x20, 0x5C, 0x2F, 0x20, 0x20, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x29, 0x20, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x2F, 0x20, 0x2F, 0x20, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x5F, 0x29, 0x20, 0x7C, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x29, 0x20, 0x7C, 0x20, 0x20, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x29, 0x7C, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x29, 0x7C, 0x7C, 0x20, 0x20, 0x20, 0x5C, 0x20, 0x7C, 0x20, 0x7C, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x2F, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x20, 0x28, 0x20, 0x20, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x7C, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x29, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x29, 0x7C, 0x20, 0x28, 0x5C, 0x20, 0x5C, 0x29, 0x20, 0x7C, 0x7C, 0x20, 0x7C, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x28, 0x2F, 0x20, 0x2F, 0x29, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x5C, 0x20, 0x5C, 0x20, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x29, 0x20, 0x7C, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x29, 0x20, 0x7C, 0x20, 0x20, 0x7C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x28, 0x5C, 0x20, 0x28, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x5C, 0x20, 0x20, 0x20, 0x7C, 0x7C, 0x20, 0x7C, 0x20, 0x5C, 0x5F, 0x20, 0x20, 0x29, 0x20, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x2F, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x7C, 0x20, 0x29, 0x5F, 0x5F, 0x5F, 0x29, 0x20, 0x29, 0x7C, 0x20, 0x29, 0x20, 0x20, 0x20, 0x28, 0x20, 0x7C, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x2F, 0x20, 0x20, 0x29, 0x20, 0x20, 0x7C, 0x20, 0x29, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x29, 0x20, 0x5C, 0x20, 0x5C, 0x5F, 0x5F, 0x7C, 0x20, 0x29, 0x20, 0x20, 0x5C, 0x20, 0x20, 0x7C, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x20, 0x7C, 0x20, 0x20, 0x28, 0x5F, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x7C, 0x2F, 0x20, 0x5C, 0x5F, 0x5F, 0x5F, 0x2F, 0x20, 0x7C, 0x2F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5C, 0x7C, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x2F, 0x20, 0x20, 0x20, 0x7C, 0x2F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x2F, 0x20, 0x20, 0x20, 0x5C, 0x5F, 0x5F, 0x2F, 0x7C, 0x2F, 0x20, 0x20, 0x20, 0x20, 0x29, 0x5F, 0x29, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x29, 0x20, 0x20, 0x28, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x29, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};

int main()
{
  int fd = open("flag", O_RDONLY);
  if (fd < 0)
  {
    puts("Something goes wrong, tell admin...");
    exit(1);
  }
  else
  {
    ssize_t result = read(fd, flag, 31);
    if (result < 0)
    {
      puts("Something goes wrong, tell admin...");
      exit(1);
    }
  }
  puts(banner);
  while (1)
  {
    int option, tmp1, tmp2;
    puts("What you want to do?\n"
         "1) Check next 10 random number\n"
         "2) Guess next random number\n"
         "3) Read the source code\n"
         "4) Exit\n"
         "> ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      for (int i = 0; i < 10; ++i)
      {
        printf("%d ", rand());
      }
      puts("");
      break;
    case 2:
      printf("So next random number is: ");
      scanf("%d", &tmp1);
      tmp2 = rand();
      if (tmp1 == tmp2)
      {
        puts("WELL DONE!");
        puts(flag);
      }
      else
      {
        printf("Ops, right answer is %d\n", tmp2);
      }
      break;
    case 3:
      system("cat main.c");
      break;
    case 4:
      exit(0);
    default:
      printf("What's your mean by %d?\n", option);
      break;
    }
  }
  return 0;
}
