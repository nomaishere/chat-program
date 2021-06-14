#ifndef USERS
#define USERS

#define USER_ADDED 300
#define USER_UPDATED 301
#define USER_DELETED 302

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../data/model.h"
#include "error.h"

int updateUserList(USER *user, USER_FULLDATA *userList, int userIndex[], int max_user);

void checkDeactiveUser(USER_FULLDATA *userList, int userIndex[], int max_user);

// TODO add_user와 update_user, delete_user 함수도 만들기(지금은 그냥 한번에 구현되있음)

#endif