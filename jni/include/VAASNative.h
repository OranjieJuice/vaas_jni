#ifndef VAAS_NATIVE_H
#define VAAS_NATIVE_H

namespace vaas_jni {

typedef void (*vaasInit_t)();
typedef void (*vaasProcess_t)(unsigned char* pData, unsigned int width, unsigned int height, unsigned int rotate90);
typedef int (*vaasDeinit_t)();

class VAASNative {
public:
    VAASNative();
    ~VAASNative();
    void init();
    void process(unsigned char* pData, unsigned int width, unsigned int height, unsigned int rotation90);
    void deinit();
    static VAASNative* getInstance();
private:
    void clear();
    vaasInit_t mVAASInit;
    vaasProcess_t  mVAASProcess;
    vaasDeinit_t mVAASDeinit;
    void* mHandle;
    static VAASNative mInstance;
};

}

#endif // VAAS_NATIVE_H
