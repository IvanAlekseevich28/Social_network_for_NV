#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define areal 5

typedef struct userInfo
{
    char nickname[32];
    unsigned age;
    char town[16];
} userInfo;

typedef struct user
{
    userInfo inf;
    struct user* friends[areal - 1];
} user;

void printUserInfo(user *obj);
unsigned getNumberOfFriends(user* obj);
void setUser(user *obj);
void showList(user* list);
void autoSetUsers (user *arr, unsigned size, char** nameArr, unsigned width, unsigned sizeNames);
void makeFriend(user* arr, user* you);

int main()
{
    srand(time(NULL));


//    FILE *f;
//   //
//    char Array[1000];
//    f = fopen("C:\\Users\\Ivan\\Desktop\\NameList.txt", "r" );
//    if(f == NULL)
//    {
//        printf("Problrms");
//    }
//     while (fgets(Array, 1000, f)!=NULL)
//     {
//         printf("%s", Array);
//     }
//    fclose(f);

    char nameArr[10][10] =
    {"Liam",
     "Noah",
     "William",
     "James",
     "Logan",
     "Benjamin",
     "Mason",
     "Elijah",
     "Oliver",
     "Jacob"};

    user arr[areal];
    for (unsigned i = 0; i < areal; i++)
        setUser(&arr[i]);
       // autoSetUsers(&arr[i], areal, nameArr, 10, 10);


    makeFriend(arr, &arr[0]);
    printUserInfo(&arr[0]);
    printf("You friends:/n");
    for (unsigned i = 0; i < getNumberOfFriends(&arr[0]); i++)
    printUserInfo(arr[0].friends[i]);
    return 0;
}



void printUserInfo(user *obj)
{
    printf("User info:\n");
    printf("Full name:\t");
    printf("%s", obj->inf.nickname);
    printf("\nAge: ");
    printf("%u", obj->inf.age);
    printf("\nTown:\t");
    printf("%s", obj->inf.town);
    printf("\nFriends: ");
    printf("%u", getNumberOfFriends(obj));
    printf("\n\n");
}

unsigned getNumberOfFriends(user* obj)
{
    unsigned count = 0;
    for (unsigned i = 0; i < areal - 1; i++)
        if (obj->friends[i] != NULL) count++;

    return count;
}

void setUser(user *obj)
{
    printf("Enter your full name: ");
    scanf("%s", obj->inf.nickname);
    printf("Enter your age: ");
    scanf("%u", &obj->inf.age);
    printf("Enter your town: ");
    scanf("%s", obj->inf.town);
    printf("\n\n");

    for (unsigned i = 0; i < areal; i++)
        obj->friends[i] = NULL;
}

void showList(user* list)
{
    for (unsigned i = 0; i < areal; i++)
    {
        printf("#%u\t", i);
        printf("%s", list[i].inf.nickname);
        printf("\n");
    }

}

void autoSetUsers (user *arr, unsigned size, char** nameArr, unsigned width, unsigned sizeNames)
{
    for (unsigned i = 0; i < size; i++)
    {
//        for (unsigned j = 0; j < width; j++)
//        arr[i].inf.nickname[j] = nameArr[rand() % sizeNames][j];
        strcpy(arr[i].inf.nickname, nameArr[rand() % sizeNames]);
        arr[i].inf.age = rand() % 50 + 12;
        strcpy(arr[i].inf.town, "BOT");

    }

}

void makeFriend(user* arr, user* you)
{
    while (1){
        showList(arr);
        unsigned chose;
        printf("Choose a person number: ");
        scanf("%u", &chose);
        if (&arr[chose] == you)
        {
            printf("NO! You can't setect yourself!\n");
            continue;
        }else if (chose < areal)
        {
            you->friends[getNumberOfFriends(you)] = &arr[chose];
            arr[chose].friends[getNumberOfFriends(&arr[chose])] = you;
        } else
        {
            printf("Uncorrect number!\n");
            continue;
        }
        printf("Do you want to chose someone else? (y/n)");
        char answer_for_repeat;
        answer_for_repeat = getch();
        if (answer_for_repeat != 'y') break;
    }
}
