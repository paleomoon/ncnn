#ifndef DATAREADER_H
#define DATAREADER_H

#include <stdio.h>

namespace ncnn {
    class DataReader
    {
    public:
        virtual ~DataReader(); //如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码,所以要使用虚析构
        virtual int scan(const char* format, void* p) const;
        virtual size_t read(void* buf, size_t size) const;
    };

    class DataReaderFromStdio : public DataReader //继承方式与父类成员访问符取范围小的
    {
    public:
        DataReaderFromStdio(FILE* fp);
        virtual int scan(const char* format, void* p) const;
        virtual size_t read(void* buf, size_t size) const;

    private:
        FILE* fp;
    };
    
}

#endif