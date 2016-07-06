#include <string>
#include <iostream>
#include <fstream>

using namespace std;
#ifndef FileHelper_hpp
#define FileHelper_hpp

class FileHelper {
public:
    static void myPrintHelloMake(void);
    static void initTextFile(const char* filename, string initText);
    static int appendTextToTextFile(const char* filename, string appendText);
    static int coutTextFile(const char* filename);
    static int coutLowLetterStatsFromTextFile(const char* filename);
};



#endif /* FileHelper_hpp */