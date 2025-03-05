#include <dlfcn.h>
#include <string>
#include "VAASNative.h"
#include "VAASJNIUtils.h"

namespace vaas_jni {

VAASNative VAASNative::mInstance = VAASNative();

VAASNative::VAASNative() {
    mHandle = dlopen("libvaas_core.so", RTLD_LAZY);

    if (!mHandle) {
        ALOGE(TAG, "Can't open library: %s", dlerror());
        clear();
        return;
    } else {
        ALOGI(TAG, "dlopen library success");

        mVAASInit = (vaasInit_t) dlsym(mHandle, "vaasInit");
        if (mVAASInit == nullptr) {
            ALOGI(TAG, "mVAASInit is nullptr: %p", mVAASInit);
            clear();
            return;
        }

        mVAASProcess = (vaasProcess_t) dlsym(mHandle, "vaasProcess");
        if (mVAASProcess == nullptr) {
            ALOGI(TAG, "mVAASProcess is nullptr: %p", mVAASProcess);
            clear();
            return;
        }

        mVAASDeinit = (vaasDeinit_t) dlsym(mHandle, "vaasDeinit");
        if (mVAASDeinit == nullptr) {
            ALOGI(TAG, "mVAASDeinit is nullptr: %p", mVAASDeinit);
            clear();
            return;
        }
    }
}

VAASNative::~VAASNative() {
    clear();
}

void VAASNative::init() {
    if (mVAASInit != nullptr) mVAASInit();
}

void VAASNative::process(unsigned char *pData, unsigned int width, unsigned int height, unsigned int rotation90) {
    if (mVAASProcess != nullptr) mVAASProcess(pData, width, height, rotation90);
}

void VAASNative::deinit() {
    if (mVAASDeinit != nullptr) mVAASDeinit();
}

VAASNative* VAASNative::getInstance() {
    return &mInstance;
}

void VAASNative::clear() {
    mVAASInit = nullptr;
    mVAASProcess = nullptr;
    mVAASDeinit = nullptr;
    dlclose(mHandle);
    mHandle = nullptr;
}

}