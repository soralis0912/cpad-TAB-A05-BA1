/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __M4U_PORT_H__
#define __M4U_PORT_H__

/* ==================================== */
/* about portid */
/* ==================================== */

enum {
	/*larb0-MMSYS-10*/
	M4U_PORT_DISP_OVL0,
	M4U_PORT_DISP_2L_OVL0_LARB0,
	M4U_PORT_DISP_2L_OVL1_LARB0,
	M4U_PORT_DISP_RDMA0,
	M4U_PORT_DISP_RDMA1,
	M4U_PORT_DISP_WDMA0,
	M4U_PORT_MDP_RDMA0,
	M4U_PORT_MDP_WROT0,
	M4U_PORT_MDP_WDMA0,
	M4U_PORT_DISP_FAKE0,
	/*larb1-VDEC-7*/
	M4U_PORT_HW_VDEC_MC_EXT,
	M4U_PORT_HW_VDEC_PP_EXT,
	M4U_PORT_HW_VDEC_VLD_EXT,
	M4U_PORT_HW_VDEC_AVC_MV_EXT,
	M4U_PORT_HW_VDEC_PRED_RD_EXT,
	M4U_PORT_HW_VDEC_PRED_WR_EXT,
	M4U_PORT_HW_VDEC_PPWRAP_EXT,
	/*larb2-IMG-3*/
	M4U_PORT_IMG_IPUO,
	M4U_PORT_IMG_IPU3O,
	M4U_PORT_IMG_IPUI,
	/*larb3-CAM-5*/
	M4U_PORT_CAM_IPUO,
	M4U_PORT_CAM_IPU2O,
	M4U_PORT_CAM_IPU3O,
	M4U_PORT_CAM_IPUI,
	M4U_PORT_CAM_IPU2I,
	/*larb4-VENC-11*/
	M4U_PORT_VENC_RCPU,
	M4U_PORT_VENC_REC,
	M4U_PORT_VENC_BSDMA,
	M4U_PORT_VENC_SV_COMV,
	M4U_PORT_VENC_RD_COMV,
	M4U_PORT_JPGENC_RDMA,
	M4U_PORT_JPGENC_BSDMA,
	M4U_PORT_VENC_CUR_LUMA,
	M4U_PORT_VENC_CUR_CHROMA,
	M4U_PORT_VENC_REF_LUMA,
	M4U_PORT_VENC_REF_CHROMA,
	/*larb5-IMGSYS-25*/
	M4U_PORT_CAM_IMGI,
	M4U_PORT_CAM_IMG2O,
	M4U_PORT_CAM_IMG3O,
	M4U_PORT_CAM_VIPI,
	M4U_PORT_CAM_LCEI,
	M4U_PORT_CAM_SMXI,
	M4U_PORT_CAM_SMXO,
	M4U_PORT_CAM_WPE0_RDMA1,
	M4U_PORT_CAM_WPE0_RDMA0,
	M4U_PORT_CAM_WPE0_WDMA,

	M4U_PORT_CAM_FDVT_RP,
	M4U_PORT_CAM_FDVT_WR,
	M4U_PORT_CAM_FDVT_RB,
	M4U_PORT_CAM_WPE1_RDMA0,
	M4U_PORT_CAM_WPE1_RDMA1,
	M4U_PORT_CAM_WPE1_WDMA,
	M4U_PORT_CAM_DPE_RDMA,
	M4U_PORT_CAM_DPE_WDMA,
	M4U_PORT_CAM_MFB_RDMA0,
	M4U_PORT_CAM_MFB_RDMA1,

	M4U_PORT_CAM_MFB_WDMA,
	M4U_PORT_CAM_RSC_RDMA0,
	M4U_PORT_CAM_RSC_WDMA,
	M4U_PORT_CAM_OWE_RDMA,
	M4U_PORT_CAM_OWE_WDMA,
	/*larb6-CAM-31*/
	M4U_PORT_CAM_IMGO,
	M4U_PORT_CAM_RRZO,
	M4U_PORT_CAM_AAO,
	M4U_PORT_CAM_AFO,
	M4U_PORT_CAM_LSCI0,
	M4U_PORT_CAM_LSCI1,
	M4U_PORT_CAM_PDO,
	M4U_PORT_CAM_BPCI,
	M4U_PORT_CAM_LCSO,
	M4U_PORT_CAM_CAM_RSSO_A,

	M4U_PORT_CAM_UFEO,
	M4U_PORT_CAM_SOCO,
	M4U_PORT_CAM_SOC1,
	M4U_PORT_CAM_SOC2,
	M4U_PORT_CAM_CCUI,
	M4U_PORT_CAM_CCUO,
	M4U_PORT_CAM_RAWI_A,
	M4U_PORT_CAM_CCUG,
	M4U_PORT_CAM_PSO,
	M4U_PORT_CAM_AFO_1,

	M4U_PORT_CAM_LSCI_2,
	M4U_PORT_CAM_PDI,
	M4U_PORT_CAM_FLKO,
	M4U_PORT_CAM_LMVO,
	M4U_PORT_CAM_UFGO,
	M4U_PORT_CAM_SPARE,
	M4U_PORT_CAM_SPARE_2,
	M4U_PORT_CAM_SPARE_3,
	M4U_PORT_CAM_SPARE_4,
	M4U_PORT_CAM_SPARE_5,
	M4U_PORT_CAM_SPARE_6,

	/*VPU*/
	M4U_PORT_VPU,
	M4U_PORT_VPU1,

	M4U_PORT_CCU0,
	M4U_PORT_CCU1,
	M4U_PORT_UNKNOWN

};
#define M4U_PORT_NR M4U_PORT_UNKNOWN

#endif
