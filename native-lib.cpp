#include <jni.h>
#include <string>
#include <libyuv/convert.h>

static uint8_t* GetDirectBufferAddress(JNIEnv* env, jobject byteBuffer)
{
    jclass cls = env->GetObjectClass(byteBuffer);
    jfieldID fid = env->GetFieldID(cls, "data","Ljava/nio/ByteBuffer;");
    jobject bar = env->GetObjectField(byteBuffer, fid);
    return (uint8_t*)env->GetDirectBufferAddress(bar);
}

extern "C" JNIEXPORT int JNICALL
Java_android_media_libyuv_Libyuv_ARGBToI420(JNIEnv* env,
                                            jobject /* this */,
                                            const jobject src_argb,
                                            int src_stride_argb,
                                            jobject dst_y,
                                            int dst_stride_y,
                                            jobject dst_u,
                                            int dst_stride_u,
                                            jobject dst_v,
                                            int dst_stride_v,
                                            int width,
                                            int height)
{
    uint8_t *srcArgb = GetDirectBufferAddress(env, src_argb);
    uint8_t *destY = GetDirectBufferAddress(env, dst_y);
    uint8_t *destU = GetDirectBufferAddress(env, dst_u);
    uint8_t *destV = GetDirectBufferAddress(env, dst_v);

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

    return nRet;
}

extern "C" JNIEXPORT int JNICALL
Java_android_media_libyuv_Libyuv_I420Blend(JNIEnv* env,
                                           jobject /* this */,
                                           const jobject src_y0,
                                           int src_stride_y0,
                                           const jobject src_u0,
                                           int src_stride_u0,
                                           const jobject src_v0,
                                           int src_stride_v0,
                                           const jobject src_y1,
                                           int src_stride_y1,
                                           const jobject src_u1,
                                           int src_stride_u1,
                                           const jobject src_v1,
                                           int src_stride_v1,
                                           const jobject alpha,
                                           int alpha_stride,
                                           jobject dst_y,
                                           int dst_stride_y,
                                           jobject dst_u,
                                           int dst_stride_u,
                                           jobject dst_v,
                                           int dst_stride_v,
                                           int width,
                                           int height)
{
    uint8_t *srcY0 = GetDirectBufferAddress(env, src_y0);
    uint8_t *srcU0 = GetDirectBufferAddress(env, src_u0);
    uint8_t *srcV0 = GetDirectBufferAddress(env, src_v0);

    uint8_t *srcY1 = GetDirectBufferAddress(env, src_y1);
    uint8_t *srcU1 = GetDirectBufferAddress(env, src_u1);
    uint8_t *srcV1 = GetDirectBufferAddress(env, src_v1);

    uint8_t *alpha0 = GetDirectBufferAddress(env, alpha);

    uint8_t *destY = GetDirectBufferAddress(env, dst_y);
    uint8_t *destU = GetDirectBufferAddress(env, dst_u);
    uint8_t *destV = GetDirectBufferAddress(env, dst_v);

    return libyuv::I420Blend((const uint8_t*)srcY0,
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
}
