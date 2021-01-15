## 数据读取类DataReader

DataReader的作用主要有两个：

- 读取深度模型网络结构

    ```
    int DataReaderFromStdio::scan(const char* format, void* p) const
    {
        return fscanf(fp, format, p); //适合读取网络结构文件.param
    }
    ```
    封装[fscanf() ](https://www.runoob.com/cprogramming/c-function-fscanf.html): `int fscanf(FILE *stream, const char *format, ...)`


- 读取深度模型的权重信息

    ```
    size_t DataReaderFromStdio::read(void* buf, size_t size) const
    {
        return fread(buf, 1, size, fp); //适合读取权重文件.bin
    }
    ```
    封装[ fread()](https://www.runoob.com/cprogramming/c-function-fread.html): `size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)`
