#include <jni.h>
#include "VAASNative.h"

namespace vaas_jni {

extern "C"
JNIEXPORT void JNICALL
Java_com_android_camera_vaas_VAASNative_vaasInit(JNIEnv *env, jobject thiz) {
    VAASNative::getInstance()->init();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_android_camera_vaas_VAASNative_vaasProcess(
        JNIEnv *env, jobject thiz,
        jint width, jint height,
        jobject yBuf, jint yPStride, jint yRStride,
        jobject cbBuf, jint cbPStride, jint cbRStride,
        jobject crBuf, jint crPStride, jint crRStride,
        jint cropLeft, jint cropTop, jint cropRight, jint cropBottom,
        jint rot90) {
    jbyte* y = (jbyte*)env->GetDirectBufferAddress(yBuf);
    jbyte* cb = (jbyte*)env->GetDirectBufferAddress(cbBuf);
    jbyte* cr = (jbyte*)env->GetDirectBufferAddress(crBuf);
    VAASNative::getInstance()->process((unsigned char*) y, width, height, rot90);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_android_camera_vaas_VAASNative_vaasDeinit(JNIEnv *env, jobject thiz) {
    VAASNative().getInstance()->deinit();
}

}