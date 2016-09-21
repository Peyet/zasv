/**
 * File generated by Jenny -- https://github.com/LanderlYoung/Jenny
 *
 * DO NOT EDIT THIS FILE WITHOUT COPYING TO YOUR SRC DIRECTORY.
 *
 * For bug report, please refer to github issue tracker https://github.com/LanderlYoung/Jenny/issues,
 * or contact author landerlyoung@gmail.com.
 */
#include "SuperSoundWrapper.h"

extern "C" {
#include "supersound_api.h"
#include "supersound_err.h"
#include "supersound_types.h"
}

#ifdef DEBUG

#include <android/log.h>

#define LOGV(...)   __android_log_print((int)ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define LOGD(...)   __android_log_print((int)ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...)   __android_log_print((int)ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGW(...)   __android_log_print((int)ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGE(...)   __android_log_print((int)ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#else
#define LOGV(...)
#define LOGD(...)
#define LOGI(...)
#define LOGW(...)
#define LOGE(...)
#endif


//change to whatever you like
static constexpr auto LOG_TAG = "SuperSoundWrapper";

namespace SuperSoundWrapper {

constexpr auto jbool2str(jboolean jbool)
{
    return jbool == JNI_TRUE ? "true" : "false";
}

/*
 * Class:     com_young_jnirawbytetest_supersound_SuperSoundWrapper
 * Method:    private static boolean nativeInit()
 * Signature: ()Z
 */
jboolean nativeInit(JNIEnv *env, jclass clazz)
{
    return static_cast<jboolean>(supersound_init() == ERROR_SUPERSOUND_SUCCESS);
}


/*
 * Class:     com_young_jnirawbytetest_supersound_SuperSoundWrapper
 * Method:    private static boolean nativeUninit()
 * Signature: ()Z
 */
jboolean nativeUninit(JNIEnv *env, jclass clazz)
{
    supersound_uninit();
    return JNI_TRUE;
}


/*
 * Class:     com_young_jnirawbytetest_supersound_SuperSoundWrapper
 * Method:    private static long nativeCreateIns(int sampleRate, int channelCound)
 * Signature: (II)J
 */
jlong nativeCreateIns(JNIEnv *env, jclass clazz, jint sampleRate, jint channelCount)
{
    SUPERSOUND_INST ins;
    supersound_create_inst(&ins, sampleRate, channelCount);

    LOGV("%s sampleRate:%d channelCount:%d", __FUNCTION__, sampleRate, channelCount);

    return reinterpret_cast<jlong>(ins);
}


/*
 * Class:     com_young_jnirawbytetest_supersound_SuperSoundWrapper
 * Method:    private static boolean nativeSetIntensity(long nativeHandel, int effectType, float intensity)
 * Signature: (JIF)Z
 */
jboolean nativeSetIntensity(JNIEnv *env, jclass clazz, jlong nativeHandel, jint effectType,
                            jfloat intensity)
{
    SUPERSOUND_INST ins = reinterpret_cast<SUPERSOUND_INST>(nativeHandel);

    return static_cast<jboolean>(
            supersound_set_intensity(ins, static_cast<SUPERSOUND_EFFECT_TYPE>(effectType),
                                     intensity)
            == ERROR_SUPERSOUND_SUCCESS);
}


/*
 * Class:     com_young_jnirawbytetest_supersound_SuperSoundWrapper
 * Method:    private static int getLookAhead(long nativeHandel)
 * Signature: (J)I
 */
jint getLookAhead(JNIEnv *env, jclass clazz, jlong nativeHandel)
{
    SUPERSOUND_INST ins = reinterpret_cast<SUPERSOUND_INST>(nativeHandel);
    return supersound_get_lookahead(ins);
}


/*
 * Class:     com_young_jnirawbytetest_supersound_SuperSoundWrapper
 * Method:    private static boolean process(long nativeHandel, byte[] data, int sampleNum)
 * Signature: (J[BI)Z
 */
jboolean process(JNIEnv *env, jclass clazz, jlong nativeHandel, jbyteArray data, jint sampleNum)
{
    jboolean isCopy;
    jbyte *bytes = env->GetByteArrayElements(data, &isCopy);

    SUPERSOUND_INST ins = reinterpret_cast<SUPERSOUND_INST>(nativeHandel);
    int retVal = supersound_process(ins, reinterpret_cast<short *>(bytes), sampleNum);

    LOGV("%s isCopy=%s sampleNum=%d retVal=%d", __FUNCTION__, jbool2str(isCopy), sampleNum, retVal);

    env->ReleaseByteArrayElements(data, bytes, 0);

    return static_cast<jboolean>(retVal == ERROR_SUPERSOUND_SUCCESS);
}


/*
 * Class:     com_young_jnirawbytetest_supersound_SuperSoundWrapper
 * Method:    private static boolean nativeDestroyIns(long nativeHandel)
 * Signature: (J)Z
 */
jboolean nativeDestroyIns(JNIEnv *env, jclass clazz, jlong nativeHandel)
{
    SUPERSOUND_INST ins = reinterpret_cast<SUPERSOUND_INST>(nativeHandel);
    supersound_destory_inst(&ins);
    return JNI_TRUE;
}


static const JNINativeMethod gsNativeMethods[] = {
        {
                /* method name      */ const_cast<char *>("nativeInit"),
                /* method signature */ const_cast<char *>("()Z"),
                /* function pointer */ reinterpret_cast<void *>(nativeInit)
        },
        {
                /* method name      */ const_cast<char *>("nativeUninit"),
                /* method signature */ const_cast<char *>("()Z"),
                /* function pointer */ reinterpret_cast<void *>(nativeUninit)
        },
        {
                /* method name      */ const_cast<char *>("nativeCreateIns"),
                /* method signature */ const_cast<char *>("(II)J"),
                /* function pointer */ reinterpret_cast<void *>(nativeCreateIns)
        },
        {
                /* method name      */ const_cast<char *>("nativeSetIntensity"),
                /* method signature */ const_cast<char *>("(JIF)Z"),
                /* function pointer */ reinterpret_cast<void *>(nativeSetIntensity)
        },
        {
                /* method name      */ const_cast<char *>("getLookAhead"),
                /* method signature */ const_cast<char *>("(J)I"),
                /* function pointer */ reinterpret_cast<void *>(getLookAhead)
        },
        {
                /* method name      */ const_cast<char *>("process"),
                /* method signature */ const_cast<char *>("(J[BI)Z"),
                /* function pointer */ reinterpret_cast<void *>(process)
        },
        {
                /* method name      */ const_cast<char *>("nativeDestroyIns"),
                /* method signature */ const_cast<char *>("(J)Z"),
                /* function pointer */ reinterpret_cast<void *>(nativeDestroyIns)
        }
};
static const int gsMethodCount =
        sizeof(gsNativeMethods) / sizeof(JNINativeMethod);

/**
 * register Native functions
 * @returns success or not
 */
bool registerNativeFunctions(JNIEnv *env)
{
    jclass clazz = env->FindClass(FULL_CLASS_NAME);
    return clazz != nullptr
           && 0 == env->RegisterNatives(clazz, gsNativeMethods, gsMethodCount);
}


} //endof namespace SuperSoundWrapper


JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env),
                   JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    SuperSoundWrapper::registerNativeFunctions(env);
    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved)
{

}