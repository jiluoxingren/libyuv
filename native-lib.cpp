#include <jni.h>
#include <string>
#include <libyuv/convert.h>

extern "C" JNIEXPORT int JNICALL
Java_android_media_libyuv_Libyuv_ARGBToI420(JNIEnv* env,
                                            jobject /* this */,
                                            const jbyteArray src_argb,
                                            int src_stride_argb,
                                            jbyteArray dst_y,
                                            int dst_stride_y,
                                            jbyteArray dst_u,
                                            int dst_stride_u,
                                            jbyteArray dst_v,
                                            int dst_stride_v,
                                            int width,
                                            int height) {

    jbyte *srcArgb = env->GetByteArrayElements(src_argb, NULL);
    jbyte *destY = env->GetByteArrayElements(dst_y, NULL);
    jbyte *destU = env->GetByteArrayElements(dst_u, NULL);
    jbyte *destV = env->GetByteArrayElements(dst_v, NULL);

    int nRet = libyuv::ARGBToI420((const uint8_t*)srcArgb,
                      src_stride_argb,
                      (uint8_t*)destY,
                      dst_stride_y,
                      (uint8_t*)destU,
                      dst_stride_u,
                      (uint8_t*)destV,
                      dst_stride_v,
                      width,
                      height);

    env->ReleaseByteArrayElements(src_argb, srcArgb, 0);
    env->ReleaseByteArrayElements(dst_y, destY, 0);
    env->ReleaseByteArrayElements(dst_u, destU, 0);
    env->ReleaseByteArrayElements(dst_v, destV, 0);

    return nRet;
}

extern "C" JNIEXPORT int JNICALL
Java_android_media_libyuv_Libyuv_I420Blend(JNIEnv* env,
                                           jobject /* this */,
                                           const jbyteArray src_y0,
                                           int src_stride_y0,
                                           const jbyteArray src_u0,
                                           int src_stride_u0,
                                           const jbyteArray src_v0,
                                           int src_stride_v0,
                                           const jbyteArray src_y1,
                                           int src_stride_y1,
                                           const jbyteArray src_u1,
                                           int src_stride_u1,
                                           const jbyteArray src_v1,
                                           int src_stride_v1,
                                           const jbyteArray alpha,
                                           int alpha_stride,
                                           jbyteArray dst_y,
                                           int dst_stride_y,
                                           jbyteArray dst_u,
                                           int dst_stride_u,
                                           jbyteArray dst_v,
                                           int dst_stride_v,
                                           int width,
                                           int height) {

    jbyte *srcY0 = env->GetByteArrayElements(src_y0, NULL);
    jbyte *srcU0 = env->GetByteArrayElements(src_u0, NULL);
    jbyte *srcV0 = env->GetByteArrayElements(src_v0, NULL);

    jbyte *srcY1 = env->GetByteArrayElements(src_y1, NULL);
    jbyte *srcU1 = env->GetByteArrayElements(src_u1, NULL);
    jbyte *srcV1 = env->GetByteArrayElements(src_v1, NULL);

    jbyte *alpha0 = env->GetByteArrayElements(alpha, NULL);

    jbyte *destY = env->GetByteArrayElements(dst_y, NULL);
    jbyte *destU = env->GetByteArrayElements(dst_u, NULL);
    jbyte *destV = env->GetByteArrayElements(dst_v, NULL);

    int nRet = libyuv::I420Blend((const uint8_t*)srcY0,
                                 src_stride_y0,
                                 (const uint8_t*)srcU0,
                                 src_stride_u0,
                                 (const uint8_t*)srcV0,
                                 src_stride_v0,
                                 (const uint8_t*)srcY1,
                                 src_stride_y1,
                                 (const uint8_t*)srcU1,
                                 src_stride_u1,
                                 (const uint8_t*)srcV1,
                                 src_stride_v1,
                                 (const uint8_t*)alpha0,
                                 alpha_stride,
                                 (uint8_t*)destY,
                                 dst_stride_y,
                                 (uint8_t*)destU,
                                 dst_stride_u,
                                 (uint8_t*)destV,
                                 dst_stride_v,
                                 width,
                                 height);

    env->ReleaseByteArrayElements(src_y0, srcY0, 0);
    env->ReleaseByteArrayElements(src_u0, srcU0, 0);
    env->ReleaseByteArrayElements(src_v0, srcV0, 0);

    env->ReleaseByteArrayElements(src_y1, srcY1, 0);
    env->ReleaseByteArrayElements(src_u1, srcU1, 0);
    env->ReleaseByteArrayElements(src_v1, srcV1, 0);

    env->ReleaseByteArrayElements(alpha, alpha0, 0);

    env->ReleaseByteArrayElements(dst_y, destY, 0);
    env->ReleaseByteArrayElements(dst_u, destU, 0);
    env->ReleaseByteArrayElements(dst_v, destV, 0);

    return nRet;
}
