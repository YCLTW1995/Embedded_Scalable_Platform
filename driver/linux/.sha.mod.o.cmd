cmd_/home/esp2020/yl4337/esp/soft/leon3/drivers/sha/linux/sha.mod.o := sparc-linux-gcc -Wp,-MD,/home/esp2020/yl4337/esp/soft/leon3/drivers/sha/linux/.sha.mod.o.d  -nostdinc -isystem /opt/leon/lib/gcc/sparc-leon3-linux-uclibc/5.5.0/include -I/home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include -I./arch/sparc/include/generated/uapi -I./arch/sparc/include/generated  -I/home/esp2020/yl4337/esp/soft/leon3/linux/include -I./include -I/home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/uapi -I/home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi -I./include/generated/uapi -include /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/kconfig.h -I/home/esp2020/yl4337/esp/soft/leon3/linux//home/esp2020/yl4337/esp/soft/leon3/drivers/sha/linux -I/home/esp2020/yl4337/esp/soft/leon3/drivers/sha/linux -D__KERNEL__ -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -m32 -mcpu=leon3 -pipe -mno-fpu -fcall-used-g5 -fcall-used-g7 -Wa,-Av8 -fno-delete-null-pointer-checks -O2 --param=allow-store-data-races=0 -DCC_HAVE_ASM_GOTO -Wframe-larger-than=1024 -fno-stack-protector -Wno-unused-but-set-variable -fomit-frame-pointer -fno-var-tracking-assignments -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types  -I/home/esp2020/yl4337/esp/soft/leon3/drivers/sha/linux/../../include  -DKBUILD_BASENAME='"sha.mod"'  -DKBUILD_MODNAME='"sha"' -DMODULE  -c -o /home/esp2020/yl4337/esp/soft/leon3/drivers/sha/linux/sha.mod.o /home/esp2020/yl4337/esp/soft/leon3/drivers/sha/linux/sha.mod.c

source_/home/esp2020/yl4337/esp/soft/leon3/drivers/sha/linux/sha.mod.o := /home/esp2020/yl4337/esp/soft/leon3/drivers/sha/linux/sha.mod.c

deps_/home/esp2020/yl4337/esp/soft/leon3/drivers/sha/linux/sha.mod.o := \
    $(wildcard include/config/module/unload.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/module.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/sysfs.h) \
    $(wildcard include/config/modules/tree/lookup.h) \
    $(wildcard include/config/livepatch.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/module/sig.h) \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/debug/set/module/ronx.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/types.h \
  arch/sparc/include/generated/asm/types.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/asm-generic/types.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/int-ll64.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/asm-generic/int-ll64.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/uapi/asm/bitsperlong.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitsperlong.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/asm-generic/bitsperlong.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/posix_types.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/stddef.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/stddef.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/kasan.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
    $(wildcard include/config/kprobes.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
    $(wildcard include/config/gcov/kernel.h) \
    $(wildcard include/config/stack/validation.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/uapi/asm/posix_types.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/asm-generic/posix_types.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
    $(wildcard include/config/page/poisoning/zero.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/const.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/panic/timeout.h) \
  /opt/leon/lib/gcc/sparc-leon3-linux-uclibc/5.5.0/include/stdarg.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/linkage.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/stringify.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/export.h \
    $(wildcard include/config/have/underscore/symbol/prefix.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/trim/unused/ksyms.h) \
  arch/sparc/include/generated/asm/linkage.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/linkage.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/bitops.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/bitops.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/bitops_32.h \
    $(wildcard include/config/sparc/leon/cas.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/uapi/asm/byteorder.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/byteorder/big_endian.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/byteorder/big_endian.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/swab.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/swab.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/uapi/asm/swab.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/uapi/asm/asi.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/byteorder/generic.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitops/non-atomic.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitops/ffz.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitops/__ffs.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitops/sched.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitops/ffs.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitops/fls.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitops/__fls.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitops/fls64.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitops/hweight.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitops/arch_hweight.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitops/const_hweight.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitops/lock.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitops/le.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bitops/ext2-atomic.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/typecheck.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/printk.h \
    $(wildcard include/config/message/loglevel/default.h) \
    $(wildcard include/config/early/printk.h) \
    $(wildcard include/config/printk/nmi.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/init.h \
    $(wildcard include/config/debug/rodata.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/kern_levels.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/kernel.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/sysinfo.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/cache.h \
    $(wildcard include/config/sparc32.h) \
  arch/sparc/include/generated/asm/div64.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/div64.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/stat.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/uapi/asm/stat.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/stat.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/seqlock.h \
    $(wildcard include/config/debug/lock/alloc.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/preempt.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/preempt.h \
    $(wildcard include/config/preempt/count.h) \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  arch/sparc/include/generated/asm/preempt.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/preempt.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/thread_info.h \
    $(wildcard include/config/thread/info/in/task.h) \
    $(wildcard include/config/compat.h) \
    $(wildcard include/config/debug/stack/usage.h) \
    $(wildcard include/config/have/arch/within/stack/frames.h) \
    $(wildcard include/config/hardened/usercopy.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/bug.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/thread_info.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/thread_info_32.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/ptrace.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/uapi/asm/ptrace.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/psr.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/uapi/asm/psr.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/switch_to.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/switch_to_32.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/smp.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/smp_32.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/head.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/head_32.h \
    $(wildcard include/config/kgdb.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/bitmap.h \
    $(wildcard include/config/s390.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/string.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/string.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/string_32.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/page.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/page_32.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/memory_model.h \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/pfn.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/getorder.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/irqflags.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/irqflags_32.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/bottom_half.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/barrier.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/barrier_32.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/barrier.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/spinlock_types.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/spinlock_types_up.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/rwlock_types.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/spinlock_up.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/processor.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/processor_32.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/signal.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/personality.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/personality.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/uapi/asm/signal.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/sigcontext.h \
    $(wildcard include/config/sparc64.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/uapi/asm/sigcontext.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/asm-generic/signal-defs.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/rwlock.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/spinlock_api_up.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/atomic.h \
    $(wildcard include/config/generic/atomic64.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/atomic.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/atomic_32.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/cmpxchg.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/cmpxchg_32.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/cmpxchg-local.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/atomic64.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/atomic-long.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/math64.h \
    $(wildcard include/config/arch/supports/int128.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/time64.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/time.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/uidgid.h \
    $(wildcard include/config/multiuser.h) \
    $(wildcard include/config/user/ns.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/highuid.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/kmod.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/gfp.h \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/zone/device.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/memory/isolation.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/cma.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/mmdebug.h \
    $(wildcard include/config/debug/vm.h) \
    $(wildcard include/config/debug/virtual.h) \
    $(wildcard include/config/debug/vm/pgflags.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/zsmalloc.h) \
    $(wildcard include/config/memcg.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/page/extension.h) \
    $(wildcard include/config/no/bootmem.h) \
    $(wildcard include/config/numa/balancing.h) \
    $(wildcard include/config/deferred/struct/page/init.h) \
    $(wildcard include/config/transparent/hugepage.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/have/memblock/node/map.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/wait.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/current.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/wait.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/nodemask.h \
    $(wildcard include/config/movable/node.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/page-flags-layout.h \
  include/generated/bounds.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/memory_hotplug.h \
    $(wildcard include/config/memory/hotremove.h) \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
    $(wildcard include/config/have/bootmem/info/node.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/notifier.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/errno.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/errno.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/uapi/asm/errno.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/asm-generic/errno-base.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
    $(wildcard include/config/mutex/spin/on/owner.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/osq_lock.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/rwsem.h \
    $(wildcard include/config/rwsem/spin/on/owner.h) \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/err.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/rwsem-spinlock.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/srcu.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/rcupdate.h \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/rcu/trace.h) \
    $(wildcard include/config/rcu/stall/common.h) \
    $(wildcard include/config/no/hz/full.h) \
    $(wildcard include/config/rcu/nocb/cpu.h) \
    $(wildcard include/config/tasks/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/prove/rcu.h) \
    $(wildcard include/config/rcu/boost.h) \
    $(wildcard include/config/rcu/nocb/cpu/all.h) \
    $(wildcard include/config/no/hz/full/sysidle.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/completion.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/ktime.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/jiffies.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/timex.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/timex.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/param.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/uapi/asm/param.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/param.h \
    $(wildcard include/config/hz.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/asm-generic/param.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/timex.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/timex_32.h \
  include/generated/timeconst.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/timekeeping.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/rcutiny.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
    $(wildcard include/config/wq/watchdog.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/timer.h \
    $(wildcard include/config/timer/stats.h) \
    $(wildcard include/config/debug/objects/timers.h) \
    $(wildcard include/config/no/hz/common.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/topology.h \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
    $(wildcard include/config/sched/smt.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/smp.h \
    $(wildcard include/config/up/late/init.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/llist.h \
    $(wildcard include/config/arch/have/nmi/safe/cmpxchg.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/percpu.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/percpu_32.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/percpu.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/percpu-defs.h \
    $(wildcard include/config/page/table/isolation.h) \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/topology.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/topology_32.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/topology.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/sysctl.h \
    $(wildcard include/config/sysctl.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/rbtree.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/sysctl.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/elf.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/elf.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/elf_32.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/mbus.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/ross.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/viking.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/mxcc.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/arch/sparc/include/asm/pgtsrmmu.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/elf.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/uapi/linux/elf-em.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/kobject.h \
    $(wildcard include/config/uevent/helper.h) \
    $(wildcard include/config/debug/kobject/release.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/sysfs.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/kernfs.h \
    $(wildcard include/config/kernfs.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/idr.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/kobject_ns.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/kref.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/jump_label.h \
    $(wildcard include/config/jump/label.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/extable.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/rbtree_latch.h \
  arch/sparc/include/generated/asm/module.h \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/asm-generic/module.h \
    $(wildcard include/config/have/mod/arch/specific.h) \
    $(wildcard include/config/modules/use/elf/rel.h) \
    $(wildcard include/config/modules/use/elf/rela.h) \
  /home/esp2020/yl4337/esp/soft/leon3/linux/include/linux/vermagic.h \
  include/generated/utsrelease.h \

/home/esp2020/yl4337/esp/soft/leon3/drivers/sha/linux/sha.mod.o: $(deps_/home/esp2020/yl4337/esp/soft/leon3/drivers/sha/linux/sha.mod.o)

$(deps_/home/esp2020/yl4337/esp/soft/leon3/drivers/sha/linux/sha.mod.o):
