#include <fcntl.h>    // open()
#include <unistd.h>   // close()
#include <stdio.h>    // printf()
#include <stdlib.h>   // free()

char *get_next_line(int fd);  // get_next_line 함수 선언

int main(void)
{
    int fd = open("test.txt", O_RDONLY);  // 파일 열기
    if (fd == -1)
    {
        perror("파일 열기 실패");
        return 1;
    }

    char *line = get_next_line(fd);  // 첫 줄만 읽기
    if (line)
    {
        printf("firstLine: %s", line);  // 줄 출력
        free(line);                // 메모리 해제
    }
    // char *line2 = get_next_line(fd);  // 첫 줄만 읽기
    // if (line2)
    // {
    //     printf("firstLine: %s", line2);  // 줄 출력
    //     free(line);                // 메모리 해제
    // }

    close(fd);  // 파일 닫기
    return 0;
}
