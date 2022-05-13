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

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
  const char* f = "./text1";
	if(stat(f, &stat1)) {
		printf("Text1 Does Not Exist\n");	
	}

}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
	const char* f = "./text2";
	if(stat(f, &stat2)) {
		printf("Text2 Does Not Exist\n");	
	}
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
  static struct tm t1;
	t1 = *(localtime(&stat1.st_mtime));
	time1 = &t1;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
  static struct tm t2;
	t2 = *(localtime(&stat2.st_mtime));
	time2 = &t2;
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
   const char* t1="./text1";
      const char* t2="./text2";

      int size1=stat1.st_size;
      int size2=stat2.st_size;
   
      printf("size compare\n");
      if(size1>size2)
            printf("text1 is bigger\n\n");
      else if (size1<size2)
            printf("text2 is bigger\n\n");
      else
            printf("size are equal\n\n");

    
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
        const char* t1="./text1";
      const char* t2="./text2";

      int block1=stat1.st_blksize;
      int block2=stat2.st_blksize;

      printf("block compare\n");
      if(block1>block2)
            printf("text1 is bigger\n\n");
      else if (block1<block2)
            printf("text2 is bigger\n\n");
      else
           printf("size are equal\n\n");

}
//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
	printf("date compare\n");
	if(time1->tm_mon>time2->tm_mon) printf("text1 is early\n\n");
	else if(time1->tm_mon<time2->tm_mon) printf("text2 is early\n\n");
	else if(time1->tm_mon==time2->tm_mon) {
		if(time1->tm_mday<time2->tm_mday) printf("text1 is early\n\n");
		else if(time1->tm_mday>time2->tm_mday) printf("text2 is early\n\n");
		else if(time1->tm_mday==time2->tm_mday) printf("same date\n\n");
	}
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
	printf("time compare\n");
	if(time1->tm_hour>time2->tm_hour) printf("text1 is early\n");
	else if(time1->tm_hour<time2->tm_hour) printf("text2 is early\n");
	else if(time1->tm_hour==time2->tm_hour) {
		if(time1->tm_min<time2->tm_min) printf("text1 is early\n");
		else if(time1->tm_min>time2->tm_min) printf("text2 is early\n");
		else if(time1->tm_min==time2->tm_min) printf("same date\n");
	}
}