#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char * argv[] )
{
    printf(2, ",x,v,vxvx\n");
    info(atoi(argv[1]));
    exit();
}