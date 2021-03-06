#include <stdio.h>
// get assert() here which aborts on fail
#include <assert.h>
// get malloc() and NULL here 
#include <stdlib.h>
// get strdup here
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void Person_destroy(struct Person *who)
{
    assert(who != NULL);

    free(who->name);
    free(who);
}

void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

void fucking_blat() {
    // make two people structures
    struct Person *joe = Person_create(
            "Joe Alex", 32, 64, 140);

    struct Person *frank = Person_create(
            "Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);
}

void noptr_print(struct Person fuck) {
    printf("Name: %s\n",fuck.name);
    printf("\tAge: %d\n",fuck.age);
    printf("\tHeight: %d\n",fuck.height);
    printf("\tWeight: %d\n",fuck.weight);
}

int main(int argc, char *argv[])
{
    struct Person joe = { .name="Joe Alex", .age=32, .height=64, .weight=140 };
    struct Person frank = { .name="Frank Blank", .age=20, .height=72, .weight=180 };

    noptr_print(joe);
    noptr_print(frank);
    
    joe.age += 20;
    joe.height -= 2;
    joe.weight += 40;

    frank.age += 20;
    frank.weight += 20;

    noptr_print(joe);
    noptr_print(frank);

    return 0;
}
