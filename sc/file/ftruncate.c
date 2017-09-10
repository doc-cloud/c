#include <stdio.h>  
#include <string.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <fcntl.h>  
  
int main(void)  
{  
    int fd;  
  
    const char *s1 = "0123456789";  
    const char *s2 = "abcde";  
  
    fd = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);  
    /* if error */  
  
    write(fd, s1, strlen(s1));  
  
    ftruncate(fd, 0);  
    // lseek(fd, 0, SEEK_SET);  
      
    write(fd, s2, strlen(s2));  
  
    close(fd);  
  
    return 0;  
}  
