//
//  fileinfo.c
//  FirstC
//
//  Created by jyrnan on 2022/12/1.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>

void show_stat_info(char *fname, struct stat *buf);

int main(int argc, char *argv[]) {
    
    struct stat info;
    
    if (argc > 1)
        if (stat(argv[1], &info) != -1) {
            
            show_stat_info(argv[1], &info);
            return 0;
        }
        else
            perror(argv[1]);
    return 1;
    
}

void show_stat_info(char * fname, struct stat *buf) {
    printf("    mode: %o\n", buf->st_mode);
    printf("    lnks: %d\n", buf->st_nlink);
    printf("    name: %s\n", fname);
    
    if (S_ISDIR(buf->st_mode))
        printf("this is a directory");
    
   
}

char * uid_to_name(uid_t uid) {
    return getpwuid(uid)->pw_name;
}
