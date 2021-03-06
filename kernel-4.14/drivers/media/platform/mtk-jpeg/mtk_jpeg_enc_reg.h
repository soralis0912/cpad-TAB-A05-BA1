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

#ifndef _MTK_JPEG_ENC_REG_H
#define _MTK_JPEG_ENC_REG_H
#define MTK_JPEG_COMP_MAX		3


#define JPEG_DRV_ENC_INT_STATUS_DONE			0x01
#define JPEG_DRV_ENC_INT_STATUS_STALL			0x02
#define JPEG_DRV_ENC_INT_STATUS_VCODEC_IRQ		0x10
#define JPEG_DRV_ENC_INT_STATUS_MASK_ALLIRQ		0x13

#define JPGENC_RSTB				0x100
#define JPGENC_CTRL				0x104
#define JPGENC_QUALITY				0x108
#define JPGENC_BLK_NUM				0x10C
#define JPGENC_BLK_CNT				0x110
#define JPGENC_INT_STS				0x11C
#define JPGENC_DST_ADDR0			0x120
#define JPGENC_DMA_ADDR0			0x124
#define JPGENC_STALL_ADDR0			0x128
#define JPGENC_OFFSET_ADDR			0x138
#define JPGENC_RST_MCU_NUM			0x150
#define JPGENC_IMG_SIZE				0x154
#define JPGENC_DEBUG_INFO0			0x160
#define JPGENC_DEBUG_INFO1			0x164
#define JPGENC_TOTAL_CYCLE			0x168
#define JPGENC_BYTE_OFFSET_MASK			0x16C
#define JPGENC_SRC_LUMA_ADDR			0x170
#define JPGENC_SRC_CHROMA_ADDR			0x174
#define JPGENC_STRIDE				0x178
#define JPGENC_IMG_STRIDE			0x17C
//mt8168
#define JPGENC_RDMA_CHKSUM			0x200
#define JPGENC_BSDMA_CHKSUM			0x204
#define JPGENC_RDMA_OUTPUT_CHKSUM	0x20C
#define JPGENC_RDMA_OUTPUT_CHKSUM	0x20C
#define JPGENC_LATENCY_THRES        0x31C
#define JPGENC_CCDE_SETTING         0x320
#define JPGENC_PAUSE_CTRL            0x324
#define JPGENC_PAUSE_CTRL            0x324

//end
#define JPGENC_DCM_CTRL				0x300
#define JPGENC_CODEC_SEL			0x314//NO need in mt8168
#define JPGENC_ULTRA_THRES			0x318

#endif /* _MTK_JPEG_REG_H */
