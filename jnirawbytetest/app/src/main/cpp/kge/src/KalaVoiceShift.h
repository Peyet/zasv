/*
 * JNI Header file generated by annotation JNI helper
 * written by landerlyoung@gmail.com
 */

/* C/C++ header file for class com.young.jennysampleapp.ComputeIntensiveClass */
#pragma once

#include <jni.h>

namespace  KalaVoiceShift {

static constexpr const jint KALA_VOICE_SHIFT_NO_EFFECT = 0;
static constexpr const jint KALA_VOICE_SHIFT_SOPRANO = 1;
static constexpr const jint KALA_VOICE_SHIFT_BASSO = 2;
static constexpr const jint KALA_VOICE_SHIFT_BABY = 3;
static constexpr const jint KALA_VOICE_SHIFT_AUTOTUNE = 4;
static constexpr const jint KALA_VOICE_SHIFT_METAL = 5;
static constexpr const jint KALA_VOICE_SHIFT_CHORUS = 6;


/*
 * Class:     com_young_jnirawbytetest_audiotest_KalaVoiceShift
 * Method:    private static long create(int sampleRate, int channel)
 * Signature: (II)J
 */
jlong create(JNIEnv *env, jclass clazz, jint sampleRate, jint channel);


/*
 * Class:     com_young_jnirawbytetest_audiotest_KalaVoiceShift
 * Method:    private static int process(long nativeHandel, byte[] inBuffer, int inSize, byte[] outBuffer, int outBufferSize)
 * Signature: (J[BI[BI)I
 */
jint process(JNIEnv *env, jclass clazz, jlong nativeHandel, jbyteArray inBuffer, jint inSize, jbyteArray outBuffer, jint outBufferSize);


/*
 * Class:     com_young_jnirawbytetest_audiotest_KalaVoiceShift
 * Method:    private static int getIdRange(long nativeHandel, int[] outMaxIdAndMinId)
 * Signature: (J[I)I
 */
jint getIdRange(JNIEnv *env, jclass clazz, jlong nativeHandel, jintArray outMaxIdAndMinId);


/*
 * Class:     com_young_jnirawbytetest_audiotest_KalaVoiceShift
 * Method:    private static int getIdDefault(long nativeHandel)
 * Signature: (J)I
 */
jint getIdDefault(JNIEnv *env, jclass clazz, jlong nativeHandel);


/*
 * Class:     com_young_jnirawbytetest_audiotest_KalaVoiceShift
 * Method:    private static int setTypeId(long nativeHandel, int typeId)
 * Signature: (JI)I
 */
jint setTypeId(JNIEnv *env, jclass clazz, jlong nativeHandel, jint typeId);


/*
 * Class:     com_young_jnirawbytetest_audiotest_KalaVoiceShift
 * Method:    private static int getTypeId(long nativeHandel)
 * Signature: (J)I
 */
jint getTypeId(JNIEnv *env, jclass clazz, jlong nativeHandel);


/*
 * Class:     com_young_jnirawbytetest_audiotest_KalaVoiceShift
 * Method:    private static java.lang.String getNameById(long nativeHandel, int typeId)
 * Signature: (JI)Ljava/lang/String;
 */
jstring getNameById(JNIEnv *env, jclass clazz, jlong nativeHandel, jint typeId);


/*
 * Class:     com_young_jnirawbytetest_audiotest_KalaVoiceShift
 * Method:    private static void release(long nativeHandel)
 * Signature: (J)V
 */
void release(JNIEnv *env, jclass clazz, jlong nativeHandel);




/*
 * register Native functions
 */
void registerNativeFunctions(JNIEnv *env);

} //endof namespace KalaVoiceShift