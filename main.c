#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int time1_tm_mon;
int time1_tm_mday;
int time1_tm_hour;
int time1_tm_min;

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
   // sizecmp();
   // blockcmp();
   // datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
    stat("text1", &stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    stat("text2", &stat2);	
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
	if((time1 = localtime(&stat1.st_mtime)) == NULL)
		printf("getting text1's time info fail\n\n");
	else
	{
		time1_tm_mon = time1->tm_mon;
		time1_tm_mday = time1->tm_mday;
		time1_tm_hour = time1->tm_hour;
		time1_tm_min = time1->tm_min;
	}
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
  	if((time2 = localtime(&stat2.st_mtime)) == NULL)
		printf("getting text2's time info fail\n\n");

}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    printf("size compare\n");
    int file1 = (int)stat1.st_size;
    int file2 = (int)stat2.st_size;
    
    if(file1 > file2) printf("text1 is bigger.\n");
    else if(file1 < file2) printf("text2 is bigger.\n");
    else printf("sizes are equal.\n");
    printf("\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    printf("block compare\n");
    int file1 = (int)stat1.st_blocks;
    int file2 = (int)stat2.st_blocks;

    if(file1 > file2) printf("text1 is bigger.\n");
    else if(file1 < file2) printf("text2 is bigger.\n");
    else printf("sizes are equal.\n");
    printf("\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
   printf("time compare\n");
   
   if( (time1_tm_hour) != (time2->tm_hour) ) {	// hour compare
   	if( (time1_tm_hour) > (time2->tm_hour) )
		printf("text2 is early\n\n");
	else
		printf("text1 is early\n\n");
   }
   else						// minute compare
   {
	   if( (time1_tm_min) > (time2->tm_min) )
		   printf("text2 is early\n\n");
	   else if( (time1_tm_min) < (time2->tm_min) )
		   printf("text1 is early\n\n");
	   else
		   printf("same time\n\n");
   }
}
