#include <func.h>

void dfs_print(char* dir, int width);

int dirs = 0, files = 0;
int main(int argc, char *argv[]){
    // ./mytree dir
    ARGS_CHECK(argc, 2);
    puts(argv[1]);
    dfs_print(argv[1], 4);
    puts("\n");

    printf("%d directories, %d files\n", dirs, files);
    return 0;
}

void dfs_print(char* dir, int width){
    DIR* pdir = opendir(dir);
    ERROR_CHECK(pdir, NULL, "opendir");
    struct dirent* pdirent;
    while((pdirent = readdir(pdir)) != NULL){
        if(pdirent->d_name[0] == '.')
            continue;
        for(int i = 0; i < width; i++){
            printf(" ");
        }
        puts(pdirent->d_name);

        if(pdirent->d_type == DT_DIR){
            dirs++;
            char subpath[300];
            // dir/pdirent->d_name
            sprintf(subpath, "%s/%s", dir, pdirent->d_name);

            dfs_print(subpath, width + 4);
        }else{
            files++;
        }
    }
}

