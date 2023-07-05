#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct User {
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];

int user_count = 0;

int find_user_by_username(char *username) {
  for (int i = 0; i < user_count; i++) {
    if (strcmp(users[i].username, username) == 0) {
      return i;
    }
  }
  return -1;
}

void signup(char *username, char *password) {
  int index = find_user_by_username(username);
  if (index != -1) {
    printf("this username already exists!\n");
    return;
  }

  strcpy(users[user_count].username, username);
  strcpy(users[user_count].password, password);
  user_count++;
  printf("Signup successfull!\n\nWELCOME, Let's Play!\n");
}

void login(char *username, char *password) {
  int index = find_user_by_username(username);
  if (index == -1) {
    printf("username not found!\n");

  }
  if (strcmp(users[index].password, password) != 0) {
    printf("password incorrect!\n");
    return;
  }
   
  printf("login successfull!\n\nWELCOME, Let's Play!\n");
}

void guest(){
        printf("WELCOME, Let's Play!\n");
}

void logout(){
        printf("you are in the Login Menu now\n");
}

/*void start(int *size){
        if(size<3){
                printf("invalid size,size must be bigger than 2!\n");
        }
}*/

int main() {
  char input[100];
  char command[10];
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
  int size=0;

  FILE *file = fopen("users.txt", "r");
  if (file != NULL) {
    while (fscanf(file, "%s %s", users[user_count].username, users[user_count].password) == 2) {
      user_count++;
    }
    fclose(file);
  }

  while (1) {
    printf("> ");
    fgets(input, 100, stdin);
    sscanf(input, "%s %s %s", command, username, password);
    if (strcmp(command, "signup") == 0) {
      signup(username, password);
    } else if (strcmp(command, "login") == 0) {
      login(username, password);
    } else if(strcmp(command, "guest") == 0) {
      guest();
    } else if(strcmp(command, "logout") == 0) {
      logout();
     /* } else if(strcmp(command, "start") == 0) {
      start(size);*/

    } else if (strcmp(command, "exit") == 0) {

      file = fopen("users.txt", "w");
      for (int i = 0; i < user_count; i++) {
        fprintf(file, "%s %s\n", users[i].username, users[i].password);
      }
      fclose(file);
      printf("program closed successfully!\n");
      exit(0);
    } else {
      printf("invalid command!\n");
    }
  }

  return 0;
}

                                     
