/* The LibVMI Library is an introspection library that simplifies access to
 * memory in a target virtual machine or in a file containing a dump of
 * a system's physical memory.  LibVMI is based on the XenAccess Library.
 *
 * This file is part of LibVMI.
 *
 * LibVMI is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * LibVMI is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with LibVMI.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OS_LINUX_H_
#define OS_LINUX_H_

#include "libvmi.h"
#include "config/config_parser.h"
#include <stdlib.h>

struct linux_instance {
    char *sysmap;           /**< system map file for domain's running kernel */

    uint64_t kernel_boundary; /**< the VA where the kernel is mapped */

    uint64_t tasks_offset; /**< task_struct->tasks */

    uint64_t mm_offset; /**< task_struct->mm */

    uint64_t pid_offset; /**< task_struct->pid */

    uint64_t pgd_offset; /**< mm_struct->pgd */

    uint64_t name_offset; /**< task_struct->comm */
};
typedef struct linux_instance *linux_instance_t;

status_t linux_init(vmi_instance_t instance);

uint64_t linux_get_offset(vmi_instance_t vmi, const char* offset_name);

status_t linux_system_map_symbol_to_address(vmi_instance_t instance,
        const char *symbol, addr_t *kernel_base_vaddr, addr_t *address);

addr_t linux_pid_to_pgd(vmi_instance_t vmi, vmi_pid_t pid);

vmi_pid_t linux_pgd_to_pid(vmi_instance_t vmi, addr_t pgd);

status_t linux_teardown(vmi_instance_t vmi);

#endif /* OS_LINUX_H_ */
