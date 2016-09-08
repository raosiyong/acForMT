#include <stdio.h>
#include <stdlib.h>
#include "cstruct.h"

struct p1{
    int id;
    char name[20];
    char priv[0];
};
struct p2{
    int id;
    char name[20];
    char priv[0];
};

struct s1{
    struct p1 * pp1;
    char version[20];
    char priv[0];
};
struct ss1{
    struct s1 * ps1;
    int stat;
};


#define contain_of
#define offset_of

 

int main(int argc,char ** argv){
    printf("Hello world!\r\n");
    struct s1 *is1 =(struct s1 *) malloc(sizeof(struct s1));
    printf("S1 offset:%p priv:%p %p\r\n",is1,is1->priv,&is1->priv);
    free(is1);
    printf("cstruct end\r\n");
    testBacklog();
    testUtils();
    testNetTools();
    return 0;
}

