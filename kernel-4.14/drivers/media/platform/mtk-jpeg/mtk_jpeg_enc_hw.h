/*
 * Copyright (c) 2019 MediaTek Inc.
 * Author: Xia Jiang <xia.jiang@mediatek.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */


#ifndef _MTK_JPEG_HW_H
#define _MTK_JPEG_HW_H

#include <media/videobuf2-core.h>

#include "mtk_jpeg_enc_core.h"
#include "mtk_jpeg_enc_reg.h"
#define JPEG_ENC_DST_ADDR_OFFSET_MASK 0x0f
#define JPEG_ENC_CTRL_YUV_BIT 0x18
#define JPEG_ENC_CTRL_RESTART_EN_BIT            0x400
#define JPEG_ENC_CTRL_FILE_FORMAT_BIT           0x20
#define JPEG_ENC_EN_JFIF_EXIF                   (1 << 5)
#define JPEG_ENC_CTRL_INT_EN_BIT                0x04
#define JPEG_ENC_CTRL_ENABLE_BIT                0x01

enum {
	MTK_JPEG_ENC_RESULT_DONE		= 0,
	MTK_JPEG_ENC_RESULT_STALL		= 1,
	MTK_JPEG_ENC_RESULT_VCODEC_IRQ		= 2,
	MTK_JPEG_ENC_RESULT_ERROR_UNKNOWN	= 3
};

static inline u32 mtk_jpeg_align(u32 val, u32 align)
{
	return (val + align - 1) & ~(align - 1);
}

struct mtk_jpeg_bs {
	dma_addr_t	dma_addr;
	size_t		size;
	u32			dma_addr_offset;
	u32			dma_addr_offsetmask;
};
struct mtk_jpeg_mem {
	dma_addr_t	dma_addr;
	size_t		size;
};
struct mtk_jpeg_fb {
	struct mtk_jpeg_mem	fb_addr[MTK_JPEG_COMP_MAX];
	u32			num_planes;
};
void mtk_jpeg_enc_reset(void __iomem *base);
u32 mtk_jpeg_enc_get_int_status(void __iomem *base);
u32 mtk_jpeg_enc_get_file_size(void __iomem *base);
u32 mtk_jpeg_enc_enum_result(void __iomem *base, u32 irq_status, u32 *fileSize);
void mtk_jpeg_enc_start(void __iomem *enc_reg_base);
void mtk_jpeg_enc_set_config(void __iomem *base,
				  struct mtk_jpeg_enc_param *config,
				  struct mtk_jpeg_bs *bs,
				  struct mtk_jpeg_fb *fb);
#endif /* _MTK_JPEG_HW_H */
