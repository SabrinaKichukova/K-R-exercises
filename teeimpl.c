#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){

char buff[BUFSIZ];
size_t bytes;


int fd2 = open("file6.txt", O_CREAT | O_WRONLY | O_APPEND);

while((bytes = read(STDIN_FILENO,buff,BUFSIZ))> 0 ){
    write(STDOUT_FILENO,buff,bytes);
    write(fd2,buff,bytes);
}

close(fd2);

return 0;
}
    