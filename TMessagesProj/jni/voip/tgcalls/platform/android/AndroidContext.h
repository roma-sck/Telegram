#ifndef TGCALLS_ANDROID_CONTEXT_H
#define TGCALLS_ANDROID_CONTEXT_H

#include "PlatformContext.h"

#include <jni.h>
#include <voip/tgcalls/group/GroupInstanceImpl.h>

namespace tgcalls {

class AndroidContext final : public PlatformContext {
public:
    AndroidContext(JNIEnv *env, jobject instance);
    ~AndroidContext() override;

    jobject getJavaCapturer();
    jobject getJavaInstance();
    jclass getJavaCapturerClass();

    void setJavaInstance(JNIEnv *env, jobject instance);

    std::shared_ptr<BroadcastPartTask> streamTask;

private:
    jclass VideoCameraCapturerClass = nullptr;
    jobject javaCapturer = nullptr;
    jobject javaInstance = nullptr;

};

} // namespace tgcalls

#endif
