This is a c program on windows showing a example of buffer overflow.
# Knowledge backgroud
When a function is called,the parameters of it and a address will be pushed in to the stack.This address(let us call it RET)  points to a instruction which will be executed next after the function call.Then internal variables of the called function will be pushed into the stack.

The later some data is pushed to the stack,the lower the logic address of the data in the memory will be.So the internal variable has lower address than RET.If we set the the value of the internal variable intentionally to make the size of the internal variable longer that it should be,we can override the value of the RET.Then the program will execute the instruction pointed by the RET,which is modified by us.

<!-- more -->

# Explanations on this c program
```c
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
```

The function main() will call the function overflow(),then return to main().In normal circumstances,the function fun() will not be executed.But using the knowledge above we can let the function fun() be executed.


![Paste_Image.png](http://7xt4f4.com1.z0.glb.clouddn.com/16-4-19/23038487.jpg)

function fun() is executed!

# How to run this c program
On windows OS,you'd better use mingw to compile it(the c compiler of visual studio may not allow buffer-overflow to happen).Click [here](https://raw.githubusercontent.com/VincentSeven/buffer_overflow/master/mingw-get-inst-20120426.exe) to download a setup program of mingw.
