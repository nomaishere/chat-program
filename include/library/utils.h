#ifndef UTILS
#define UTILS

#include <stdio.h>
#include <string.h>

#include "../data/model.h"

void itoa(int i, char *st);

void set_heartbeat_packet(char heartbeat_packet[], USER profile);

#endif