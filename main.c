#include <stdio.h>
#include <dirent.h>
#include <string.h>

void render(const char *name,int is_dir,int indent){
    if (indent)
        printf("%*c",indent *2,' ');
    if (is_dir){
        printf("\e[1;34m%s\e[1;0m\n",name);
    }else{
        printf("%s\n",name);
    }
}

int traverse(const char *path,int indent){
    DIR *dir = opendir(path);
    if (!dir){
        perror("Cannot open path");
        return 1;
    }
    struct dirent *dp;
    while ((dp = readdir(dir)) != NULL){
        const char *name = dp->d_name;
        if (strcmp(name, ".") == 0 || strcmp(name,"..") == 0){
            continue;
        }
        if (dp->d_type == DT_DIR){
            render(name, 1,indent);
            //continue traversing
            size_t len = strlen(path) + strlen(name) + 2;
            char sub_path[len];
            //printf("Value of sub_path is %s",sub_path);
            snprintf(sub_path,len,"%s/%s",path,name); // Writes the path to the sub_path buffer
            traverse(sub_path,indent + 1);

        }else{
            render(name,0,indent);
        }
        //printf("%s\n",name);
        // closedir(dir);
        // return 0;
        // printf("Check out this inode ");
        // printf("Check this out %s",dp->d_name);
    }
    closedir(dir);
    return 0;
}

int main(int argc, char **argv){
    const char *path = "." ;// Default root

    if (argc > 1){
        path = argv[1];
    }

    int err = traverse(path,0);
    //printf("path %s\n",path);
    return 0;

}
