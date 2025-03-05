LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS := -std=c++14 -std=gnu++1z
LOCAL_CPPFLAGS := -fexceptions -frtti

LOCAL_MODULE_OWNER := orange
LOCAL_MODULE := libvaas_jni
LOCAL_ODM_MODULE := true
LOCAL_MODULE_TAGS := optional

subdir_makefiles=$(call first-makefiles-under,$(LOCAL_PATH))
  $(foreach mk,$(subdir_makefiles),$(info including $(mk) ...)$(eval include $(mk)))
include $(BUILD_SHARED_LIBRARY)
