#include <iostream>
#include <time.h>
#include "FileHelper.hpp"

int main(int argc, const char * argv[]) {
    clock_t start,end;
    start = clock();
    FileHelper::coutLowLetterStatsFromTextFile("input.txt");
    end = clock();
    printf("Took : %f\n",(float)(end - start)/(float)CLOCKS_PER_SEC);
    
    return(0);
}