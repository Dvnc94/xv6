#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char * argv[] )
{
    printf(2, ",x,v,vxvx\n");
    info(atoi(argv[1]));
    int i;

    for(i = 0; i < 4; i++)
    {
      int *p = (int*) malloc(4096);
      if(p == 0)
        printf(2,"no memory available, malloc() failed.\n");
      info(atoi(argv[1]));
    }
    exit();
}
