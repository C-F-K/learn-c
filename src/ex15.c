#include <stdio.h>

void fucking_blat() {
    // create two arrays we care about
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // first way using indexing
    // rewritten to be pointers
    // and backwards
    int *age = ages;
    char **name = names;

    for(i = (count - 1); i >= 0; i--) {
        printf("%s has %d years alive.\n",
               *(name + i), *(age + i));
    }

    printf("---\n");

    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;

    // second way using pointers
    // rewritten to be arrays
    for(i = 0; i < count; i++) {
        printf("%s is %d years old.\n",
                cur_name[i], cur_age[i]);
    }

    printf("---\n");

    // third way, pointers are just arrays
    // also rewritten to be arrays
    for(i = 0; i < count; i++) {
        printf("%s is %d years old again.\n",
                names[i], ages[i]);
    }

    printf("---\n");

    // fourth way with pointers in a stupid complex way
    for(cur_name = names, cur_age = ages;
            (cur_age - ages) < count;
            cur_name++, cur_age++) 
    {
        printf("%s lived %d years so far.\n",
                *cur_name, *cur_age);
    }

}

void print_args(int *carg, char *varg[]) {
    // we know the args here are pointers
    int i = 0;
    // deref the count, it is an int now
    for (i = 0; i < *carg; i++) {
        // deref the array by indexing into it pointy-style (ie. by offset)
        printf("%s\n",*(varg + i));
        // now deref it again for chars pls
        int j = 0;
        for (j = 0; j < sizeof(*(varg + i)); j++) {
            printf("%c\n",*(*(varg + i) + j));
        }
    }
}

int main(int argc, char *argv[])
{
    // argc is an int
    int *carg = &argc;
    // now carg's a pointer TO THE ADDRESS OF argc and 'int' says 'gimme 4 bytes after that'

    // argv is already a pointer to (the first element in) an array; that is, an address
    char **varg = argv;
    // now varg's a pointer to a pointer to that address 
    
    // pass in the pointers themselves
    print_args(carg,varg);

    return 0;
}

// how pointers work: 
// they're like references in perl, in that they point to some data in memory;
// but where in perl you manipulate the ref as though it were the data
// (so incrementing a scalar ref means incrementing the variable it actually points to) 
// in C you manipulate ~the ref itself~, that is, you alter the specific bit of memory to which it points
// (so incrementing an int pointer still means incrementing that int, but incrementing an array pointer means incrementing the index to which the pointer points)
// this means there is still some magic happening as the compiler has to decide to handle that intelligently, it's just different magic
// IMPORTANT PARALLELISM:
// to get the value of a ref in perl, you add a (type-specific) symbol, and if you're passing around the ref it's always $calar;
// to get the value of a pointer in C, you add a * that's type-agnostic because you should have already typed the variable itself, and if you're passing around the pointer you just use the bareword
// IMPORTANT DIFFERENCE: 
// when you're making a pointer to something, you also have to fuck with the rvalue: you need to make sure you're referencing the ADDRESS of that thing. arrays do this by default, since ' = array' means 'set to the address of the first element which is also the address of the whole array and therefore what we mean by the bareword'. for ints (and presumably chars) you have to prefix the rvalue with & because you don't want the value, you want the address of the value 
