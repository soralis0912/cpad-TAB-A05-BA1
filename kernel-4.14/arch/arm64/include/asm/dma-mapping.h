/*
 * Copyright (C) 2012 ARM Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __ASM_DMA_MAPPING_H
#define __ASM_DMA_MAPPING_H

#ifdef __KERNEL__

#include <linux/types.h>
#include <linux/vmalloc.h>

#include <xen/xen.h>
#include <asm/xen/hypervisor.h>


#ifdef CONFIG_MTK_BOUNCING_CHECK
#include <mt-plat/aee.h>
#endif
extern const struct dma_map_ops dummy_dma_ops;

static inline const struct dma_map_ops *get_arch_dma_ops(struct bus_type *bus)
{
	/*
	 * We expect no ISA devices, and all other DMA masters are expected to
	 * have someone call arch_setup_dma_ops at device creation time.
	 */
	return &dummy_dma_ops;
}

void arch_setup_dma_ops(struct device *dev, u64 dma_base, u64 size,
			const struct iommu_ops *iommu, bool coherent);
#define arch_setup_dma_ops	arch_setup_dma_ops

#ifdef CONFIG_IOMMU_DMA
void arch_teardown_dma_ops(struct device *dev);
#define arch_teardown_dma_ops	arch_teardown_dma_ops
int dma_map_sg_within_reserved_iova(struct device *dev, struct scatterlist *sg,
				    int nents, int prot, dma_addr_t dma_addr);
void dma_unmap_sg_within_reserved_iova(struct device *dev,
				       struct scatterlist *sg, int nents,
				       int prot, size_t size);
void *dma_alloc_coherent_fix_iova(struct device *dev, dma_addr_t dma_addr,
				  size_t size, gfp_t flag);
void dma_free_coherent_fix_iova(struct device *dev, void *cpu_addr,
				dma_addr_t dma_addr, size_t size);

#endif

/* do not use this function in a driver */
static inline bool is_device_dma_coherent(struct device *dev)
{
	return dev->archdata.dma_coherent;
}

static inline dma_addr_t phys_to_dma(struct device *dev, phys_addr_t paddr)
{
	dma_addr_t dev_addr = (dma_addr_t)paddr;

	return dev_addr - ((dma_addr_t)dev->dma_pfn_offset << PAGE_SHIFT);
}

static inline phys_addr_t dma_to_phys(struct device *dev, dma_addr_t dev_addr)
{
	phys_addr_t paddr = (phys_addr_t)dev_addr;

	return paddr + ((phys_addr_t)dev->dma_pfn_offset << PAGE_SHIFT);
}

static inline bool dma_capable(struct device *dev, dma_addr_t addr, size_t size)
{
#ifdef CONFIG_MTK_BOUNCING_CHECK
	bool ret;

	if (!dev->dma_mask) {
		aee_kernel_warning("Bounce Buffering", "NULL dma_mask");
		return false;
	}

	ret = addr + size - 1 <= *dev->dma_mask;
	if (!ret)
		aee_kernel_warning("Bounce Buffering",
				"Incorrect dma_mask(%llx), addr+size-1(%llx)",
				*dev->dma_mask, addr + size - 1);

	return ret;
#else
	if (!dev->dma_mask)
		return false;

	return addr + size - 1 <= *dev->dma_mask;
#endif
}

static inline void dma_mark_clean(void *addr, size_t size)
{
}

/* Override for dma_max_pfn() */
static inline unsigned long dma_max_pfn(struct device *dev)
{
	dma_addr_t dma_max = (dma_addr_t)*dev->dma_mask;

	return (ulong)dma_to_phys(dev, dma_max) >> PAGE_SHIFT;
}
#define dma_max_pfn(dev) dma_max_pfn(dev)

#endif	/* __KERNEL__ */
#endif	/* __ASM_DMA_MAPPING_H */
