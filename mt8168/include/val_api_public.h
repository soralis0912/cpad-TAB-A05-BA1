#ifndef _VAL_API_PUBLIC_H_
#define _VAL_API_PUBLIC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "val_types_public.h"

/**
 * @par Function
 *   eVideoInitMVA
 * @par Description
 *   Alloc the handle for MVA usage
 * @param
 *   a_pvHandle         [IN] The handle for MVA usage
 * @par Returns
 *   VAL_UINT32_T       [OUT] Non-Used
 */
VAL_UINT32_T eVideoInitMVA(VAL_VOID_T **a_pvHandle);


/**
 * @par Function
 *   eVideoAllocMVA
 * @par Description
 *   Use the given va and size, to get the MVA
 * @param
 *   a_pvHandle         [IN] The handle for MVA usage
 * @param
 *   a_u4Va             [IN] The given va used to get MVA
 * @param
 *   ap_u4Pa            [OUT] The MVA
 * @param
 *   a_u4Size           [IN] The given size used to get MVA
 * @param
 *   a_pvM4uConfig      [IN] The MVA config info
 * @par Returns
 *   VAL_UINT32_T       [OUT] Non-Used
 */
VAL_UINT32_T eVideoAllocMVA(
	VAL_VOID_T *a_pvHandle,
	VAL_UINT32_T a_u4Va,
	VAL_UINT32_T *ap_u4Pa,
	VAL_UINT32_T a_u4Size,
	VAL_VCODEC_M4U_BUFFER_CONFIG_T * a_pvM4uConfig
);

/**
 * @par Function
 *   eVideoFreeMVA
 * @par Description
 *   Use the given va, MVA and size, to free the MVA
 * @param
 *   a_pvHandle         [IN] The handle for MVA usage
 * @param
 *   a_u4Va             [IN] The given va used to free MVA
 * @param
 *   a_u4Pa             [IN] The given MVA used to free MVA
 * @param
 *   a_u4Size           [IN] The given size used to get MVA
 * @param
 *   a_pvM4uConfig      [IN] The MVA config info
 * @par Returns
 *   VAL_UINT32_T       [OUT] Non-Used
 */
VAL_UINT32_T eVideoFreeMVA(
	VAL_VOID_T *a_pvHandle,
	VAL_UINT32_T a_u4Va,
	VAL_UINT32_T a_u4Pa,
	VAL_UINT32_T a_u4Size,
	VAL_VCODEC_M4U_BUFFER_CONFIG_T * a_pvM4uConfig
);


/**
 * @par Function
 *   eVideoDeInitMVA
 * @par Description
 *   Free the handle for MVA usage
 * @param
 *   a_pvHandle         [IN] The handle for MVA usage
 * @par Returns
 *   VAL_UINT32_T       [OUT] Non-Used
 */
VAL_UINT32_T eVideoDeInitMVA(VAL_VOID_T *a_pvHandle);


/**
 * @par Function
 *   eVideoGetM4UModuleID
 * @par Description
 *   Get the M4U module port ID
 * @param
 *   u4MemType          [IN] The memory usage for VENC or VDEC
 * @par Returns
 *   VAL_UINT32_T       [OUT] The M4U module port ID for VENC or VDEC
 */
VAL_INT32_T eVideoGetM4UModuleID(VAL_UINT32_T u4MemType);


/**
 * @par Function
 *   eVideoAtoi
 * @par Description
 *   The abstraction layer for atoi() function
 * @param
 *   a_prParam          [IN] The structure contains used info for atoi()
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_PARAMETER for fail
 */
VAL_RESULT_T eVideoAtoi(VAL_ATOI_T *a_prParam, VAL_UINT32_T a_u4ParamSize);


/**
 * @par Function
 *   eVideoStrStr
 * @par Description
 *   The abstraction layer for strstr() function
 * @param
 *   a_prParam          [IN] The structure contains used info for strstr()
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_PARAMETER for fail
 */
VAL_RESULT_T eVideoStrStr(VAL_STRSTR_T *a_prParam, VAL_UINT32_T a_u4ParamSize);

/**
 * @par Function
 *   eVideoOpenIonDevFd
 * @par Description
 *   The open ion dev fd function
 * @par Returns
 *   VAL_UINT32_T       [OUT] The opened Ion Device Fd
 */
VAL_UINT32_T eVideoOpenIonDevFd();

/**
 * @par Function
 *   eVideoCloseIonDevFd
 * @par Description
 *   The close ion dev fd function
 * @param
 *   u4IonDevFd         [IN] The synced ion dev fd for check
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_PARAMETER for fail
 */
VAL_RESULT_T eVideoCloseIonDevFd(VAL_UINT32_T u4IonDevFd);

/**
 * @par Function
 *   eVideoFlushCache
 * @par Description
 *   The flush cache usage function
 * @param
 *   a_prParam          [IN] The structure contains used info for flush cache
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @param
 *   optype             [IN] 0 for flush all, 1 for flush by page
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_MEMORY for fail
 */
VAL_RESULT_T eVideoFlushCache(VAL_MEMORY_T *a_prParam, VAL_UINT32_T a_u4ParamSize, VAL_UINT32_T optype);

/**
 * @par Function
 *   eVideoFlushCacheRange
 * @par Description
 *   The flush cache range usage function
 * @param
 *   a_prParam          [IN] The structure contains used info for flush cache
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_MEMORY for fail
 */
VAL_RESULT_T eVideoFlushCacheRange(VAL_MEMORY_T *a_prParam, VAL_UINT32_T a_u4ParamSize);

/**
 * @par Function
 *   eVideoFlushCache
 * @par Description
 *   The flush cache usage function
 * @param
 *   a_prParam          [IN] The structure contains used info for flush cache
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @param
 *   optype             [IN] 0 for flush all, 1 for flush by page
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_MEMORY for fail
 */
VAL_RESULT_T eVideoFlushCache_OAL(VAL_MEMORY_T *a_prParam, VAL_UINT32_T a_u4ParamSize, VAL_UINT32_T optype);

/**
 * @par Function
 *   eVideoInvalidateCache
 * @par Description
 *   The invalidate cache usage function
 * @param
 *   a_prParam          [IN] The structure contains used info for invalidate cache
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @param
 *   optype             [IN] 0 for flush all, 1 for invalidate by page
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_MEMORY for fail
 */
VAL_RESULT_T eVideoInvalidateCache(VAL_MEMORY_T *a_prParam, VAL_UINT32_T a_u4ParamSize, VAL_UINT32_T optype);

/**
 * @par Function
 *   eVideoInvalidateCacheRange
 * @par Description
 *   The invalidate cache usage function
 * @param
 *   a_prParam          [IN] The structure contains used info for invalidate cache
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_MEMORY for fail
 */
VAL_RESULT_T eVideoInvalidateCacheRange(VAL_MEMORY_T *a_prParam, VAL_UINT32_T a_u4ParamSize);

/**
 * @par Function
 *   eVideoFlushCache
 * @par Description
 *   The flush cache usage function
 * @param
 *   a_prParam          [IN] The structure contains used info for flush cache
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @param
 *   optype             [IN] 0 for flush all, 1 for flush by page
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_MEMORY for fail
 */
VAL_RESULT_T eVideoFlushCache_ex(VAL_MEMORY_T *a_prParam, VAL_UINT32_T a_u4ParamSize, VAL_UINT32_T optype);

/**
 * @par Function
 *   eVideoInvalidateCache
 * @par Description
 *   The invalidate cache usage function
 * @param
 *   a_prParam          [IN] The structure contains used info for invalidate cache
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @param
 *   optype             [IN] 0 for flush all, 1 for invalidate by page
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_MEMORY for fail
 */
VAL_RESULT_T eVideoInvalidateCache_ex(VAL_MEMORY_T *a_prParam, VAL_UINT32_T a_u4ParamSize, VAL_UINT32_T optype);

/**
 * @par Function
 *   eVideoInvalidateCache
 * @par Description
 *   The invalidate cache usage function
 * @param
 *   a_prParam          [IN] The structure contains used info for invalidate cache
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @param
 *   optype             [IN] 0 for flush all, 1 for invalidate by page
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_MEMORY for fail
 */
VAL_RESULT_T eVideoInvalidateCache_OAL(VAL_MEMORY_T *a_prParam, VAL_UINT32_T a_u4ParamSize, VAL_UINT32_T optype);

/**
 * @par Function
 *   eVideoMemAlloc
 * @par Description
 *   The memory allocate usage function
 * @param
 *   a_prParam          [IN] The structure contains used info for allocate memory
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @par Returns
 *   VAL_RESULT_T       [OUT]
 *   VAL_RESULT_NO_ERROR for success,
 *   VAL_RESULT_INVALID_MEMORY or VAL_RESULT_INVALID_PARAMETER for fail
 */
VAL_RESULT_T eVideoMemAlloc(VAL_MEMORY_T *a_prParam, VAL_UINT32_T a_u4ParamSize);

/**
 * @par Function
 *   eVideoMemAlloc_OAL
 * @par Description
 *   The memory allocate usage function
 * @param
 *   a_prParam          [IN] The structure contains used info for allocate memory
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @par Returns
 *   VAL_RESULT_T       [OUT]
 *   VAL_RESULT_NO_ERROR for success,
 *   VAL_RESULT_INVALID_MEMORY or VAL_RESULT_INVALID_PARAMETER for fail
 */
VAL_RESULT_T eVideoMemAlloc_OAL(VAL_MEMORY_T *a_prParam, VAL_UINT32_T a_u4ParamSize);

/**
 * @par Function
 *   eVideoMemFree
 * @par Description
 *   The memory free usage function
 * @param
 *   a_prParam          [IN] The structure contains used info for free memory
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_PARAMETER for fail
 */
VAL_RESULT_T eVideoMemFree(VAL_MEMORY_T *a_prParam, VAL_UINT32_T a_u4ParamSize);

/**
 * @par Function
 *   eVideoMemFree_OAL
 * @par Description
 *   The memory free usage function
 * @param
 *   a_prParam          [IN] The structure contains used info for free memory
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_PARAMETER for fail
 */
VAL_RESULT_T eVideoMemFree_OAL(VAL_MEMORY_T *a_prParam, VAL_UINT32_T a_u4ParamSize);


VAL_VOID_T *eVideoMemMAP(VAL_UINT64_T a_u8Base, VAL_UINT32_T a_u4Size);

VAL_RESULT_T eVideoMemUnMAP(VAL_VOID_T *a_prVa, VAL_UINT32_T a_u4Size);

/**
 * @par Function
 *   eVideoMemSet
 * @par Description
 *   The memory set usage function
 * @param
 *   a_prParam          [IN] The structure contains used info for set memory
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @param
 *   a_u4Value          [IN] The value for set to memory
 * @param
 *   a_u4Size           [IN] The size of "memory" want to be set
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_PARAMETER for fail
 */
VAL_RESULT_T eVideoMemSet(
	VAL_MEMORY_T *a_prParam,
	VAL_UINT32_T a_u4ParamSize,
	VAL_INT32_T a_u4Value,
	VAL_UINT32_T a_u4Size
);


/**
 * @par Function
 *   eVideoMemCpy
 * @par Description
 *   The memory copy usage function
 * @param
 *   a_prParamDst       [IN] The structure contains destination memory info for copy memory
 * @param
 *   a_u4ParamDstSize   [IN] The size of a_prParamDst structure
 * @param
 *   a_prParamSrc       [IN] The structure contains source memory info for copy memory
 * @param
 *   a_u4ParamSrcSize   [IN] The size of a_prParamSrc structure
 * @param
 *   a_u4Size           [IN] The size of "source memory" and "destination memory" want to be copied
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_PARAMETER for fail
 */
VAL_RESULT_T eVideoMemCpy(
	VAL_MEMORY_T *a_prParamDst,
	VAL_UINT32_T a_u4ParamDstSize,
	VAL_MEMORY_T *a_prParamSrc,
	VAL_UINT32_T a_u4ParamSrcSize,
	VAL_UINT32_T a_u4Size
);


/**
 * @par Function
 *   eVideoMemCmp
 * @par Description
 *   The memory compare usage function
 * @param
 *   a_prParamSrc1      [IN] The structure contains memory 1 info for compare memory
 * @param
 *   a_u4ParamSrc1Size  [IN] The size of a_prParamSrc1 structure
 * @param
 *   a_prParamSrc2      [IN] The structure contains memory 2 info for compare memory
 * @param
 *   a_u4ParamSrc2Size  [IN] The size of a_prParamSrc2 structure
 * @param
 *   a_u4Size           [IN] The size of "memory 1" and "memory 2" want to be compared
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_INVALID_PARAMETER for fail
 */
VAL_RESULT_T eVideoMemCmp(
	VAL_MEMORY_T *a_prParamSrc1,
	VAL_UINT32_T a_u4ParamSrc1Size,
	VAL_MEMORY_T *a_prParamSrc2,
	VAL_UINT32_T a_u4ParamSrc2Size,
	VAL_UINT32_T a_u4Size
);


/**
 * @par Function
 *   eVideoGCEInit
 * @par Description
 *   The GCE cammand buffer queue init function
 * @param
 *   a_prGceHandle      [OUT] The handle contains internal structure for user
 * @param
 *   bIsDecoder      [IN] Is decoder or encoder, GCE use different thread
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, others for fail
 */
VAL_RESULT_T eVideoGCEInit(
    VAL_ULONG_T  *a_prGceHandle,
    VAL_UINT32_T u4IsDecoder
);

/**
 * @par Function
 *   eVideoGCESetWaitDoneCB
 * @par Description
 *   Set GCE wait done callback function
 * @param
 *   a_ulGceHandle      [IN] The handle contains internal structure allocated by eVideoGCEInit
 * @param
 *   rWaitDoneCB      [IN] pfnWaitDoneProc invoked before sem_post eVideoSetGCECmdFlush & pUserInstHandle
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, others for fail
 */
VAL_RESULT_T eVideoGCESetWaitDoneCB(
    VAL_ULONG_T  a_ulGceHandle,
    GCE_CMDQ_CB_T rWaitDoneCB
);

/**
 * @par Function
 *   eVideoGCEAddCmdRead
 * @par Description
 *   Add GCE cammand buffer init function - read register
 * @param
 *   a_pCmdQ_buff      [IN/OUT] The cammand queue buffer which to be wirtten
 * @param
 *   a_u4Addr      [IN] The read address of register
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, others for fail
 */
VAL_RESULT_T eVideoGCEAddCmdRead(
    VCODEC_DRV_GCE_CMDQ_T *a_pCmdQ_buff,
    VAL_UINT32_T a_u4Addr
);

/**
 * @par Function
 *   eVideoGCEAddCmdWrite
 * @par Description
 *   Add GCE cammand buffer init function - write register
 * @param
 *   a_pCmdQ_buff      [IN/OUT] The cammand queue buffer which to be wirtten
 * @param
 *   a_u4Addr      [IN] The write address of register
  * @param
 *   a_u4Val      [IN] The write value
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, others for fail
 */
VAL_RESULT_T eVideoGCEAddCmdWrite(
    VCODEC_DRV_GCE_CMDQ_T *a_pCmdQ_buff,
    VAL_UINT32_T a_u4Addr, VAL_UINT32_T a_u4Val, VAL_UINT32_T a_u4Mask
);

/**
 * @par Function
 *   eVideoGCEAddCmdPollReg
 * @par Description
 *   Add GCE cammand buffer init function - poll register
 * @param
 *   a_pCmdQ_buff      [IN/OUT] The cammand queue buffer which to be wirtten
 * @param
 *   a_u4Addr      [IN] The read address of register
  * @param
 *   a_u4Val      [IN] The cmd will poll register until this value
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, others for fail
 */
VAL_RESULT_T eVideoGCEAddCmdPollReg(
    VCODEC_DRV_GCE_CMDQ_T *a_pCmdQ_buff,
     VAL_UINT32_T a_u4Addr, VAL_UINT32_T a_u4Val, VAL_UINT32_T a_u4Mask
);

/**
 * @par Function
 *   eVideoGCEAddCmdWaitEvent
 * @par Description
 *   Add GCE cammand buffer init function - wait event
 * @param
 *   a_pCmdQ_buff      [IN/OUT] The cammand queue buffer which to be wirtten
  * @param
 *   event_id      [IN] The cmd will wait this event ID & clear event
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, others for fail
 */
VAL_RESULT_T eVideoGCEAddCmdWaitEvent(
    VCODEC_DRV_GCE_CMDQ_T *a_pCmdQ_buff,
    VCODEC_DRV_GCE_EVENT_ID_T event_id
);

/**
 * @par Function
 *   eVideoGCEAddCmdMemMove
 * @par Description
 *   Add GCE cammand buffer init function - mv memory
 * @param
 *   a_pCmdQ_buff      [IN/OUT] The cammand queue buffer which to be wirtten
 * @param
 *   a_u4Addr_src      [IN] The cmd read source address (physical addr)
  * @param
 *   a_u4Addr_dst      [IN] The cmd write destination address (physical addr)
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, others for fail
 */
VAL_RESULT_T eVideoGCEAddCmdMemMove(
    VCODEC_DRV_GCE_CMDQ_T *a_pCmdQ_buff,
    VAL_UINT64_T a_u4Addr_src, VAL_UINT64_T a_u4Addr_dst
);

/**
 * @par Function
 *   eVideoSetGCECmdFlush
 * @par Description
 *   ioctl to VCU & trigger GCE HW flush this cmdq buffer,
 *   once over GCE_CMD_BUFFQ_SIZE waiting for callback
 *   this function will block & wait by semaphore
 * @param
 *   a_ulGceHandle      [IN] The handle contains internal structure allocated by eVideoGCEInit
 * @param
 *   a_pCmdQ_buff      [IN] The cammand queue buffer wait for GCE HW flush
 */
VAL_RESULT_T eVideoSetGCECmdFlush(
    VAL_ULONG_T  a_ulGceHandle,
    VCODEC_DRV_GCE_CMDQ_T *a_pCmdQ_buff
);

/**
 * @par Function
 *   eVideoWaitGCECallBack
 * @par Description
 *   ioctl to VCU & wait GCE flush done callback cmdq buffer,
 *   once ioctl returned will post semaphore & push back cmd buffer Q
 * @param
 *   a_ulGceHandle      [IN] The handle contains internal structure allocated by eVideoGCEInit
 * @param
 *   a_ppCmdQ_buff      [IN] The cammand queue buffer which is flushed
 */
VAL_RESULT_T eVideoWaitGCECallBack(
    VAL_ULONG_T  a_ulGceHandle,
    VCODEC_DRV_GCE_CMDQ_T **a_ppCmdQ_buff
);

/**
 * @par Function
 *   eVideoGCEDeinit
 * @par Description
 *   The GCE cammand buffer queue deinit function
 * @param
 *   a_ulGceHandle      [IN] The handle contains internal structure to be freed
 */
VAL_RESULT_T eVideoGCEDeinit(
    VAL_ULONG_T  a_ulGceHandle
);


/**
 * @par Function
 *   eVideoGcePutBuf2List
 * @par Description
 *
 * @param
 *
 */
VAL_RESULT_T eVideoGcePutBuf2List(
    VCODEC_DRV_GCE_BUF_LIST_T  *pGceBufList,
    VCODEC_DRV_GCE_INFO_T *pGceInfo
);

/**
 * @par Function
 *   eVideoGceAquireBuf
 * @par Description
 *
 * @param
 *
 */
VAL_UINT32_T eVideoGceAquireBuf(
    VCODEC_DRV_GCE_BUF_LIST_T  *pGceBufList
);

/**
 * @par Function
 *   eVideoGceReleaseBuf
 * @par Description
 *
 * @param
 *
 */
VAL_RESULT_T eVideoGceReleaseBuf(
    VCODEC_DRV_GCE_BUF_LIST_T  *pGceBufList,
    P_VCODEC_DRV_GCE_INFO_T pGceInfo
);

/**
 * @par Function
 *   eVideoGceResetCmdBuf
 * @par Description
 *
 * @param
 *
 */

VAL_RESULT_T eVideoGceResetCmdBuf(
    P_VCODEC_DRV_GCE_INFO_T pGceInfo
);


/**
 * @par Function
 *   WaitISR
 * @par Description
 *   The ISR usage related function, whene trigger HW, we will use to wait HW complete
 * @param
 *   a_prParam          [IN] The structure contains used info for ISR usage
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_ISR_TIMEOUT for fail
 */
VAL_RESULT_T WaitISR(VAL_ISR_T *a_prParam, VAL_UINT32_T a_u4ParamSize);


/**
 * @par Function
 *   eVideoLockHW
 * @par Description
 *   The single/multiple instance usage function, to allow using HW
 * @param
 *   a_prParam          [IN] The structure contains used info for Lock HW
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_UNKNOWN_ERROR for fail
 */
VAL_RESULT_T eVideoLockHW(VAL_HW_LOCK_T *a_prParam, VAL_UINT32_T  a_u4ParamSize);


/**
 * @par Function
 *   eVideoLockHW
 * @par Description
 *   The single/multiple instance usage function, to release HW for another instance
 * @param
 *   a_prParam          [IN] The structure contains used info for unLock HW
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_UNKNOWN_ERROR for fail
 */
VAL_RESULT_T eVideoUnLockHW(VAL_HW_LOCK_T *a_prParam, VAL_UINT32_T  a_u4ParamSize);

/**
 * @par Function
 *   eVideoIncLogCount
 * @par Description
 *   The single/multiple instance usage function, to increase or decrease kernel log detect count
 * @param
 *   a_prParam          [IN] Indicate to increase or decrease kernel log detect count
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success, VAL_RESULT_UNKNOWN_ERROR for fail
 */
VAL_RESULT_T eVideoIncLogCount( VAL_BOOL_T *a_prParam);


/**
 * @par Function
 *   eVideoGetTimeOfDay
 * @par Description
 *   The timing usage function, used to performance profiling
 * @param
 *   a_prParam          [IN] The structure contains used info for timing usage
 * @param
 *   a_u4ParamSize      [IN] The size of a_prParam structure
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success
 */
VAL_RESULT_T eVideoGetTimeOfDay(VAL_TIME_T *a_prParam, VAL_UINT32_T a_u4ParamSize);


/**
 * @par Function
 *   eHalEMICtrlForRecordSize
 * @par Description
 *   The recording info function, to get the record size for setting to EMI controller
 * @param
 *   a_prDrvRecordSize  [IN] The structure contains used info for recording size
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success
 */
VAL_RESULT_T eHalEMICtrlForRecordSize(VAL_RECORD_SIZE_T *a_prDrvRecordSize);


/**
 * @par Function
 *   eVideoVcodecSetThreadID
 * @par Description
 *   The thread info function, to set thread ID for used to lock/unlock HW and priority adjustment
 * @param
 *   a_prThreadID       [IN] The structure contains used info for thread info
 * @par Returns
 *   VAL_RESULT_T       [OUT] VAL_RESULT_NO_ERROR for success
 */
VAL_RESULT_T eVideoVcodecSetThreadID(VAL_VCODEC_THREAD_ID_T *a_prThreadID);


/**
 * @par Function
 *   eVideoGetParam
 * @par Description
 *   The parameter info function, to get val parameter
 * @param
 *   a_eType        [IN]    The VAL_GET_TYPE_T enum
 * @param
 *   a_pvInParam    [IN]    The input parameter
 * @param
 *   a_pvOutParam   [OUT]   The output parameter
 * @par Returns
 *   VAL_RESULT_T   [OUT]   VAL_RESULT_NO_ERROR for success
 */
VAL_RESULT_T eVideoGetParam(VAL_GET_TYPE_T a_eType, VAL_VOID_T *a_pvInParam, VAL_VOID_T *a_pvOutParam);

/**
 * @par Function
 *   eVideoSetParam
 * @par Description
 *   The parameter info function, to set val parameter
 * @param
 *   a_eType        [IN]    The VAL_SET_TYPE_T enum
 * @param
 *   a_pvInParam    [IN]    The input parameter
 * @param
 *   a_pvOutParam   [OUT]   The output parameter
 * @par Returns
 *   VAL_RESULT_T   [OUT]   VAL_RESULT_NO_ERROR for success
 */
VAL_RESULT_T eVideoSetParam(VAL_SET_TYPE_T a_eType, VAL_VOID_T *a_pvInParam, VAL_VOID_T *a_pvOutParam);

VAL_RESULT_T eVideoE3TCMPowerON(VAL_UINT32_T a_u4E3TCMClk);
VAL_RESULT_T eVideoE3TCMPowerOFF(VAL_UINT32_T a_u4E3TCMClk);
#ifdef __ANDROID__
pid_t gettid();
#endif

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _VAL_API_PUBLIC_H_ */
