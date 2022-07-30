#include <func.h>

int main()
{
    FILE* fp = popen("echoall", "r");
    ERROR_CHECK(fp, NULL, "popen");

    char buf[1024] = {0};
    while(fgets(buf, 1024, fp) != NULL){
        puts(buf);
        memset(buf, 0, 1024);
    }

    return 0;     
}
