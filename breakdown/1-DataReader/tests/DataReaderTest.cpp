#include <iostream>
#include "DataReader.h"

using namespace std;

void testScan()
{
    const char* filePath="../../tests/tmp.proto";
    FILE* fp=fopen(filePath,"rb");
    ncnn::DataReaderFromStdio dr(fp);
    int ret=0;
    while(1)
    {
        char layerType[256];
        ret=dr.scan("%s",&layerType);
        if(ret==-1) break;
        int layerId;
        ret=dr.scan("%d",&layerId);
        if(ret==-1) break;
        cout<<layerType<<" "<<layerId<<endl;

    }
}

void testRead()
{
    const char* filePath="../../tests/tmp.model";
    FILE* fp=fopen(filePath,"rb");
    ncnn::DataReaderFromStdio dr(fp);
    int ret=0;
    while(1)
    {
        char* ch=new char(4);
        ret=dr.read(ch,sizeof(char)*4);
        if(ret==0) break;
        cout<<ch<<endl;
    }
}

int main()
{
    //testScan();
    testRead();
    printf("ok\n");
    return 0;
}