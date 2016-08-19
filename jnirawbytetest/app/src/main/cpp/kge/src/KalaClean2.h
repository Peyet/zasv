/*
 * JNI Header file generated by annotation JNI helper
 * written by landerlyoung@gmail.com
 */

/* C/C++ header file for class com.young.jennysampleapp.ComputeIntensiveClass */
#pragma once

#include <jni.h>

namespace  KalaClean2 {



/*
 * Class:     com_young_jnirawbytetest_audiotest_KalaClean2
 * Method:    private static long createClean2(int sampleRate, int channel)
 * Signature: (II)J
 */
jlong createClean2(JNIEnv *env, jclass clazz, jint sampleRate, jint channel);


/*
 * Class:     com_young_jnirawbytetest_audiotest_KalaClean2
 * Method:    private static int clean2Process(long handel, byte[] inBuffer, int size)
 * Signature: (J[BI)I
 */
jint clean2Process(JNIEnv *env, jclass clazz, jlong handel, jbyteArray inBuffer, jint size);


/*
 * Class:     com_young_jnirawbytetest_audiotest_KalaClean2
 * Method:    private void destroyClean2(long handel)
 * Signature: (J)V
 */
void destroyClean2(JNIEnv *env, jobject thiz, jlong handel);




/*
 * register Native functions
 */
void registerNativeFunctions(JNIEnv *env);

} //endof namespace KalaClean2
