//
//  file.c
//  laba3
//
//  Created by Sergei Waribrus on 08/12/14.
//  Copyright (c) 2014 Sergei Waribrus. All rights reserved.
//

#include "file.h"

short int getRand(void)
{
    short int min = -20000;
    short int max = 32000;
    return (short int) min + (rand() % (int)(max - min + 1));
}

static void write_random_file(const char * name, int count) {
    FILE *fd = fopen(name, "w+");
    if(fd) {
        for(int i = 0; i < count; i++) {
            fprintf(fd, "%hd\n", getRand());
        }
        fclose(fd);
    }
}

static void read_file(const char * name, short int *array, int count) {
    FILE *fp = fopen(name, "r");
    if(fp) {
        short int buf = 0;
        for (int i = 0; i < count; i++) {
            fscanf(fp, "%hd", &buf);
            if (buf < -20000 || buf > 32000) {
                exit(0);
            }
            array[i] = buf;
        }
        fclose(fp);
    }
}

namespace_file const file = {write_random_file, read_file};