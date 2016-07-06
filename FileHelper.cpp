#include "FileHelper.hpp"

void FileHelper::myPrintHelloMake(void) {
    
    printf("Hello makefiles!\n");
    
    return;
}

void FileHelper::initTextFile(const char* filename, string initText)
{
    ofstream outfile;
    outfile.open(filename);
    outfile << initText << endl;
    outfile.close();
    cout << "Text File is created.\n";
}

int FileHelper::appendTextToTextFile(const char* filename, string appendText)
{
    cout << "in append mode...\n";
    
    ofstream fout(filename,ios::app);
    if (!fout)
    {
        cout << "Unable to open for appending.\n";
        return (1);
    }
    fout << appendText << "\n";
    fout.close();
    cout << "Append mode finish.\n";
    return (0);
}

int FileHelper::coutTextFile(const char* filename)
{
    
    ifstream fin(filename);
    if (!fin)
    {
        cout << "Unable to open for reading.\n";
        return (1);
    }
    
    char ch;
    while (fin.get(ch))
    {
        cout << ch;
    }
    
    fin.close();
    
    return (0);
}

#define NUM_LETTERS 26
struct Letter_Stats {
public:
    int index;
    int count;
    char letter;
    bool operator< (const Letter_Stats &other) const {
        return index < other.index;
    }
};

int FileHelper::coutLowLetterStatsFromTextFile(const char* filename)
{
    ifstream fin(filename);
    if (!fin)
    {
        cout << "Unable to open for reading.\n";
        return (1);
    }
    
    Letter_Stats stats[NUM_LETTERS];
    
    int i;
    int index;
    for (i=0;i<NUM_LETTERS;i++)
        
    {
        stats[i].index=0;
        stats[i].count=0;
        stats[i].letter=('a' + i);
    }
    
    char ch;
    
    while (fin.get(ch))
    {
        if('a' <= ch && ch <= 'z')
        {
            if(stats[ch - 'a'].count==0)
            {
                stats[ch - 'a'].index=index++;
            }
            stats[ch - 'a'].count++;
        }
    }
    
    sort( stats, stats+NUM_LETTERS);//average case linearithmic (n log n) time complexity n=26
    
    for(i=0;i<NUM_LETTERS;i++)
    {
        if(stats[i].count==0)
        {
            continue;
        }
        cout << stats[i].letter<<":"<<stats[i].count<<endl;
    }
    //uncomment to see memory usage.
    //    cout << "memory usage:" <<sizeof(stats)<<endl;
    
    fin.close();
    
    return 0;
}

