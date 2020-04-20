#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char * argv[] )
{
    int option = atoi(argv[1]);
    int i;

    if(option == 1)
    {
      printf(2, "Before calling fork(): \n");   
      info(option);
      int pid = fork();
      if(pid == 0)
      {
	 printf(2,"info() while child process is running.\n");
	 info(option);
      }
      else
      {
         wait();
         printf(2,"After child process finished.\n");
         info(option);
      }
    }
    else if(option == 2)
    {
      info(option);
      printf(2,"12");
      info(option);
      printf(2,"1st line ^ shows output of info() at process start (should be just 1 info() call)\n");
      printf(2,"2nd line ^ shows output after printing 12 (1 info() + 2 write() + 1 info() )\n");
      info(option);
      printf(2,"Next output is after printing all of those chars above ( many write()'s + 3 info() )\n");
    }
    else if(option  == 3)
    {
      printf(2,"Calling info() at beginning of process...\n");
      info(option);
      for(i = 0; i < 12; i++)
      {
	printf(2,"----------------------------------------------\n");
        printf(2,"Now allocating additional page of memory.\n");
        int *p = (int*) malloc(4096);
        if(p == 0)
          printf(2,"  no memory available, malloc() failed!\n");
        else
	  printf(2,"  malloc(4096) successful!\n");
        printf(2, "  Calling info() again to see change.\n");
        info(option);
      }
    }
    printf(2,"\n");
    exit();
}
