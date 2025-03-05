LOCAL_C_INCLUDES += \
        $(LOCAL_PATH)/jni/include \
        libnativehelper/include_jni

LOCAL_SRC_FILES += \
        jni/VAASNative.cpp \
        jni/VAASJNI.cpp

LOCAL_LDLIBS += \
        -ldl

LOCAL_SHARED_LIBRARIES += \
        libvaas_core