#ifndef __ICUBE_IOCTL__H__

#define __ICUBE_IOCTL__H__



#include <linux/ioctl.h>

#include <linux/types.h>

#include <stdint.h>

#include <linux/kernel.h>

#include <linux/sched.h>

#include <drm/drm.h>

#if !defined(__KERNEL__)

#define __user

#endif


enum mem_type{
	mem_dump = 0,
	reg_dump ,
	no_dump
};

struct drm_icubegpu_dump_mem {
	unsigned long long data_addr;
	unsigned int data_size;
	void  *user_addr;
	enum mem_type type;
};





#define DRM_ICUBEGPU_DUMP_MEM  0x0a



#define DRM_IOCTL_ICUBEGPU_DUMP_MEM  DRM_IOWR(DRM_COMMAND_BASE + DRM_ICUBEGPU_DUMP_MEM, struct drm_icubegpu_dump_mem)

#endif

