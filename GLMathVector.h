#ifndef GL_MATH_VEC_H
#define GL_MATH_VEC_H

#include "GLMathTypes.h"
#import <Accelerate/Accelerate.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma mark - Prototypes

// Vector math functions
static __inline__ vec2_t vec2_add(const vec2_t v1, const vec2_t v2);
static __inline__ vec2_t vec2_sub(const vec2_t v1, const vec2_t v2);
static __inline__ vec2_t vec2_mul(const vec2_t v1, const vec2_t v2);
static __inline__ float vec2_dot(const vec2_t v1, const vec2_t v2);
static __inline__ float vec2_magSquared(const vec2_t v);
static __inline__ float vec2_mag(const vec2_t v);
static __inline__ vec2_t vec2_normalize(const vec2_t v);
static __inline__ float vec2_dist(const vec2_t v1, const vec2_t v2);
static __inline__ vec2_t vec2_scalarMul(const vec2_t v, float s);
static __inline__ vec2_t vec2_scalarDiv(const vec2_t v, float s);
static __inline__ vec2_t vec2_negate(const vec2_t v);

static __inline__ vec3_t vec3_add(const vec3_t v1, const vec3_t v2);
static __inline__ vec3_t vec3_sub(const vec3_t v1, const vec3_t v2);
static __inline__ vec3_t vec3_mul(const vec3_t v1, const vec3_t v2);
static __inline__ float vec3_dot(const vec3_t v1, const vec3_t v2);
static __inline__ float vec3_magSquared(const vec3_t v);
static __inline__ float vec3_mag(const vec3_t v);
static __inline__ vec3_t vec3_normalize(const vec3_t v);
static __inline__ float vec3_dist(const vec3_t v1, const vec3_t v2);
static __inline__ vec3_t vec3_scalarMul(const vec3_t v, float s);
static __inline__ vec3_t vec3_scalarDiv(const vec3_t v, float s);
static __inline__ vec3_t vec3_cross(const vec3_t v1, const vec3_t v2);
static __inline__ vec3_t vec3_negate(const vec3_t v);

static __inline__ vec4_t vec4_add(const vec4_t v1, const vec4_t v2);
static __inline__ vec4_t vec4_sub(const vec4_t v1, const vec4_t v2);
static __inline__ vec4_t vec4_mul(const vec4_t v1, const vec4_t v2);
static __inline__ float vec4_dot(const vec4_t v1, const vec4_t v2);
static __inline__ float vec4_magSquared(const vec4_t v);
static __inline__ float vec4_mag(const vec4_t v);
static __inline__ float vec4_dist(const vec4_t v1, const vec4_t v2);
static __inline__ vec4_t vec4_scalarMul(const vec4_t v, float s);
static __inline__ vec4_t vec4_scalarDiv(const vec4_t v, float s);
static __inline__ vec4_t vec4_cross(const vec4_t v1, const vec4_t v2);
static __inline__ vec4_t vec4_negate(const vec4_t v);

#pragma mark Implementations

#pragma mark - ~ Vectors(2)
static __inline__ vec2_t vec2_add(const vec2_t v1, const vec2_t v2) {
	vec2_t out;
	vDSP_vadd(v1.f, 1, v2.f, 1, out.f, 1, 2);
	return out;
}
static __inline__ vec2_t vec2_sub(const vec2_t v1, const vec2_t v2) {
	vec2_t out;
	vDSP_vsub(v1.f, 1, v2.f, 1, out.f, 1, 2);
	return out;
}
static __inline__ vec2_t vec2_mul(const vec2_t v1, const vec2_t v2) {
	vec2_t out;
	vDSP_vmul(v1.f, 1, v2.f, 1, out.f, 1, 2);
	return out;
}
static __inline__ float vec2_dot(const vec2_t v1, const vec2_t v2) {
	float out;
	vDSP_dotpr(v1.f, 1, v2.f, 1, &out, 2);
	return out;
}
static __inline__ float vec2_magSquared(const vec2_t v) {
	float magnitudes[2];
	vDSP_vsq(v.f, 1, magnitudes, 1, 2);
	return magnitudes[0] + magnitudes[1];
}
static __inline__ float vec2_mag(const vec2_t v) {
	return sqrtf(vec2_magSquared(v));
}
static __inline__ vec2_t vec2_normalize(const vec2_t v) {
	return vec2_scalarDiv(v, vec2_mag(v));
}
static __inline__ float vec2_dist(const vec2_t v1, const vec2_t v2) {
	float magnitudes[2];
	vDSP_vdist((float*)v1.f, 1, (float*)v2.f, 1, magnitudes, 1, 2);
	return magnitudes[0] + magnitudes[1];
}
static __inline__ vec2_t vec2_scalarMul(const vec2_t v, float s) {
	vec2_t out;
	vDSP_vsmul(v.f, 1, &s, out.f, 1, 2);
	return out;
}
static __inline__ vec2_t vec2_scalarDiv(const vec2_t v, float s) {
	vec2_t out;
	vDSP_vsdiv((float*)v.f, 1, &s, out.f, 1, 2);
	return out;
}
static __inline__ vec2_t vec2_negate(const vec2_t v) {
	vec2_t out;
	vDSP_vneg ((float*)v.f, 1, out.f, 1, 2);
	return out;
}

#pragma mark - ~ Vectors(3)
static __inline__ vec3_t vec3_add(const vec3_t v1, const vec3_t v2) {
	vec3_t out;
	vDSP_vadd(v1.f, 1, v2.f, 1, out.f, 1, 3);
	return out;
}
static __inline__ vec3_t vec3_sub(const vec3_t v1, const vec3_t v2) {
	vec3_t out;
	vDSP_vsub(v2.f, 1, v1.f, 1, out.f, 1, 3);
	return out;
}
static __inline__ vec3_t vec3_mul(const vec3_t v1, const vec3_t v2) {
	vec3_t out;
	vDSP_vmul(v1.f, 1, v2.f, 1, out.f, 1, 3);
	return out;
}
static __inline__ float vec3_dot(const vec3_t v1, const vec3_t v2) {
	float out;
	vDSP_dotpr(v1.f, 1, v2.f, 1, &out, 3);
	return out;
}
static __inline__ float vec3_magSquared(const vec3_t v) {
	float magnitudes[3];
	vDSP_vsq(v.f, 1, magnitudes, 1, 3);
	return magnitudes[0] + magnitudes[1] + magnitudes[2];
}
static __inline__ float vec3_mag(const vec3_t v) {
	return sqrtf(vec3_magSquared(v));
}
static __inline__ vec3_t vec3_normalize(const vec3_t v) {
	return vec3_scalarDiv(v, vec3_mag(v));
}
static __inline__ float vec3_dist(const vec3_t v1, const vec3_t v2) {
	float magnitudes[3];
	vDSP_vdist((float*)v1.f, 1, (float*)v2.f, 1, magnitudes, 1, 3);
	return magnitudes[0] + magnitudes[1] + magnitudes[2];
}
static __inline__ vec3_t vec3_scalarMul(const vec3_t v, float s) {
	vec3_t out;
	vDSP_vsmul(v.f, 1, &s, out.f, 1, 3);
	return out;
}
static __inline__ vec3_t vec3_scalarDiv(const vec3_t v, float s) {
	vec3_t out;
	vDSP_vsdiv((float*)v.f, 1, &s, out.f, 1, 3);
	return out;
}

static __inline__ vec3_t vec3_cross(const vec3_t v1, const vec3_t v2) {
    return (vec3_t){ v1.y * v2.z - v1.z * v2.y,
                     v1.z * v2.x - v1.x * v2.z,
                     v1.x * v2.y - v1.y * v2.x };
}
static __inline__ vec3_t vec3_negate(const vec3_t v) {
	vec3_t out;
	vDSP_vneg ((float*)v.f, 1, out.f, 1, 3);
	return out;
}

#pragma mark - ~ Vectors(4)
static __inline__ vec4_t vec4_add(const vec4_t v1, const vec4_t v2) {
	vec4_t out;
	vDSP_vadd(v1.f, 1, v2.f, 1, out.f, 1, 4);
	return out;
}
static __inline__ vec4_t vec4_sub(const vec4_t v1, const vec4_t v2) {
	vec4_t out;
	vDSP_vsub(v1.f, 1, v2.f, 1, out.f, 1, 4);
	return out;
}
static __inline__ vec4_t vec4_mul(const vec4_t v1, const vec4_t v2) {
	vec4_t out;
	vDSP_vmul(v1.f, 1, v2.f, 1, out.f, 1, 4);
	return out;
}
static __inline__ float vec4_dot(const vec4_t v1, const vec4_t v2) {
	float out;
	vDSP_dotpr(v1.f, 1, v2.f, 1, &out, 4);
	return out;
}
static __inline__ float vec4_magSquared(const vec4_t v) {
	float magnitudes[4];
	vDSP_vsq(v.f, 1, magnitudes, 1, 4);
	return magnitudes[0] + magnitudes[1] + magnitudes[2] + magnitudes[3];
}
static __inline__ float vec4_mag(const vec4_t v) {
	return sqrtf(vec4_magSquared(v));
}
static __inline__ vec4_t vec4_normalize(const vec4_t v) {
	return vec4_scalarDiv(v, vec4_mag(v));
}
static __inline__ float vec4_dist(const vec4_t v1, const vec4_t v2) {
	float magnitudes[4];
	vDSP_vdist((float*)v1.f, 1, (float*)v2.f, 1, magnitudes, 1, 4);
	return magnitudes[0] + magnitudes[1] + magnitudes[2] + magnitudes[3];
}
static __inline__ vec4_t vec4_scalarMul(const vec4_t v, float s) {
	vec4_t out;
	vDSP_vsmul((float*)v.f, 1, &s, out.f, 1, 4);
	return out;
}
static __inline__ vec4_t vec4_scalarDiv(const vec4_t v, float s) {
	vec4_t out;
	vDSP_vsdiv((float*)v.f, 1, &s, out.f, 1, 4);
	return out;
}
static __inline__ vec4_t vec4_cross(const vec4_t v1, const vec4_t v2) {
    return (vec4_t){ v1.y * v2.z - v1.z * v2.y,
                     v1.z * v2.x - v1.x * v2.z,
                     v1.x * v2.y - v1.y * v2.x,
					 0.0 };
}
static __inline__ vec4_t vec4_negate(const vec4_t v) {
	vec4_t out;
	vDSP_vneg ((float*)v.f, 1, out.f, 1, 4);
	return out;
}

#ifdef __cplusplus
}
#endif
#endif