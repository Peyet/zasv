/**
 * File generated by Jenny -- https://github.com/LanderlYoung/Jenny
 *
 * DO NOT EDIT THIS FILE WITHOUT COPYING TO YOUR SRC DIRECTORY.
 *
 * For bug report, please refer to github issue tracker https://github.com/LanderlYoung/Jenny/issues,
 * or contact author landerlyoung@gmail.com.
 */

/* C++ header file for class com.young.jnirawbytetest.supersound.SuperSoundWrapper */
#pragma once

#include <jni.h>

namespace  SuperSoundWrapper {

//DO NOT modify
static constexpr auto FULL_CLASS_NAME = "com/young/jnirawbytetest/supersound/SuperSoundWrapper";

static constexpr jfloat SUPERSOUND_SURROUND_PARAM_MIN = 0.0;
static constexpr jfloat SUPERSOUND_SURROUND_PARAM_DEFAUT = 1.3;
static constexpr jfloat SUPERSOUND_SURROUND_PARAM_MAX = 3.0;
static constexpr jfloat SUPERSOUND_BASS_PARAM_MIN = 0.0;
static constexpr jfloat SUPERSOUND_BASS_PARAM_DEFAUT = 1.5;
static constexpr jfloat SUPERSOUND_BASS_PARAM_MAX = 3.0;
static constexpr jfloat SUPERSOUND_VOCAL_PARAM_MIN = 0.0;
static constexpr jfloat SUPERSOUND_VOCAL_PARAM_DEFAUT = 0.1;
static constexpr jfloat SUPERSOUND_VOCAL_PARAM_MAX = 1.5;
static constexpr jfloat SUPERSOUND_STUDIO_PARAM_MIN = 1.0;
static constexpr jfloat SUPERSOUND_STUDIO_PARAM_DEFAUT = 1.5;
static constexpr jfloat SUPERSOUND_STUDIO_PARAM_MAX = 2.0;


/*
 * Class:     com_young_jnirawbytetest_supersound_SuperSoundWrapper
 * Method:    private static boolean nativeInit()
 * Signature: ()Z
 */
jboolean nativeInit(JNIEnv *env, jclass clazz);


/*
 * Class:     com_young_jnirawbytetest_supersound_SuperSoundWrapper
 * Method:    private static boolean nativeUninit()
 * Signature: ()Z
 */
jboolean nativeUninit(JNIEnv *env, jclass clazz);


/*
 * Class:     com_young_jnirawbytetest_supersound_SuperSoundWrapper
 * Method:    private static long nativeCreateIns(int sampleRate, int channelCound)
 * Signature: (II)J
 */
jlong nativeCreateIns(JNIEnv *env, jclass clazz, jint sampleRate, jint channelCound);


/*
 * Class:     com_young_jnirawbytetest_supersound_SuperSoundWrapper
 * Method:    private static boolean nativeSetIntensity(long nativeHandel, int effectType, float intensity)
 * Signature: (JIF)Z
 */
jboolean nativeSetIntensity(JNIEnv *env, jclass clazz, jlong nativeHandel, jint effectType, jfloat intensity);


/*
 * Class:     com_young_jnirawbytetest_supersound_SuperSoundWrapper
 * Method:    private static int getLookAhead(long nativeHandel)
 * Signature: (J)I
 */
jint getLookAhead(JNIEnv *env, jclass clazz, jlong nativeHandel);


/*
 * Class:     com_young_jnirawbytetest_supersound_SuperSoundWrapper
 * Method:    private static boolean processF(long nativeHandel, float[] data, int sampleNum)
 * Signature: (J[FI)Z
 */
jboolean processF(JNIEnv *env, jclass clazz, jlong nativeHandel, jfloatArray data, jint sampleNum);


/*
 * Class:     com_young_jnirawbytetest_supersound_SuperSoundWrapper
 * Method:    private static boolean process(long nativeHandel, byte[] data, int sampleNum)
 * Signature: (J[BI)Z
 */
jboolean process(JNIEnv *env, jclass clazz, jlong nativeHandel, jbyteArray data, jint sampleNum);


/*
 * Class:     com_young_jnirawbytetest_supersound_SuperSoundWrapper
 * Method:    private static boolean nativeDestroyIns(long nativeHandel)
 * Signature: (J)Z
 */
jboolean nativeDestroyIns(JNIEnv *env, jclass clazz, jlong nativeHandel);




/**
 * register Native functions
 * @returns success or not
 */
bool registerNativeFunctions(JNIEnv *env);

} //endof namespace SuperSoundWrapper
