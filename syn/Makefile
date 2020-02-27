# Copyright 2018 Columbia University, SLD Group

# Disable timing checks
BDW_VLOGSIM_ARGS = -NOTIMINGCHECKS -UNBUFFERED

# Extra flags for mojo
BDW_EXTRA_CCFLAGS = $(CXXFLAGS)
BDW_EXTRA_HLFLAGS = $(CXXFLAGS)

# Uncomment for Insight
BDW_DEBUG = 1

saySimPassed:
	@bdw_sim_pass

-include Makefile.prj

Makefile.prj: project.tcl
	@bdw_makegen

clean: clean_all clean_libs
	@rm -f Makefile.prj
	@rm -f *~ *.bak *.BAK *.log *.jou
	@rm -f .failed_resolve.cc
	@rm -f .syn_asic.qws
	@rm -f irun.key
	@rm -rf waves.shm
	@rm -rf .simvision
	@rm -f .project.*
	@rm -f .stack*
	@rm -f .stratus*
	@rm -f .syn.qws
	@rm -rf .Xil

distclean: clean

distclean-all: distclean
	@rm -rf cachelib

.PHONY: generate_plm distclean distclean-all clean
