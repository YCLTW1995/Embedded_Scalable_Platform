# Copyright 2018 Columbia University, SLD Group

#
# Technology Libraries
#

set_attr fpga_use_dsp off
set_attr fpga_tool "vivado"
set_attr fpga_part "xczu9eg-ffvb1156-2-e"

#
# Global synthesis attributes
#

set_attr message_detail           2
set_attr default_input_delay      0.1
set_attr default_protocol         false
set_attr inline_partial_constants true
set_attr output_style_reset_all   true
set_attr lsb_trimming             true

set_attr sharing_effort_regs      low
set_attr sharing_effort_parts     low

#
# Global project includes
#


set INCLUDES "-I../src"

#
# High-Level Synthesis Options
#

set_attr hls_cc_options "$INCLUDES"

#
# Compiler and Simulator Options
#

set_systemc_options -gcc 4.1
set_attr cc_options "$INCLUDES"

use_systemc_simulator incisive
set_attr end_of_sim_command "make saySimPassed"


#
# DSE configurations
#

# AXI4 - Bit width of identifiers

set ID_WIDTH "6"

# AXI4 - Bit width for the addresses (assuming no less than 32)

set ADDR_WIDTH "32"

# AXI4 - Bit width for the data values (assuming no less than 32)

set DATA_WIDTH ""
append DATA_WIDTH "32"


# Size of the local memory - (max number of samples)

set MAX_SAMPLES 32

# Testbench configuration parameters

set NSAMPLES 16
set NITERS 4


#
# Set the library for the memories
#

#use_hls_lib "./memlib"

#
# Set the target clock and reset period
#

set CLOCK_PERIOD 10.0; # 100 MHz frequency
set RESET_PERIOD [expr $CLOCK_PERIOD * 30]

#
# Set common options for all configurations
#

set PRINT on
set SCHED_ASAP on
set COMMON_HLS_FLAGS "--clock_period=$CLOCK_PERIOD --prints=$PRINT --sched_asap=$SCHED_ASAP"
set COMMON_CFG_FLAGS "-DCLOCK_PERIOD=$CLOCK_PERIOD -DRESET_PERIOD=$RESET_PERIOD"

#
# Testbench or system level modules
#

define_system_module tb ../tb/driver.cpp \
                        ../tb/memory.cpp \
                        ../tb/system.cpp \
                        ../tb/sc_main.cpp

#
# System level modules to be synthesized
#

define_hls_module sha ../src/sha.cpp

#
# Setting the synthesis options
#

set BASIC_OPTIONS "$COMMON_HLS_FLAGS"

# Split all the multipliers larger than 16 bits

# set_attr split_multiply 16

# Flatten all the arrays except the PLMs

# set_attr flatten_arrays on

#
# Generating sim/system configs
#

foreach dw $DATA_WIDTH {

    define_io_config * IOCFG_$dw \
	-DID_WIDTH=$ID_WIDTH -DADDR_WIDTH=$ADDR_WIDTH \
	-DDATA_WIDTH=$dw $COMMON_CFG_FLAGS \
	-DMAX_SAMPLES=$MAX_SAMPLES \
	-DNSAMPLES=$NSAMPLES \
	-DNITERS=$NITERS \
        -DDEBUG

    # Define the testbench

    define_system_config tb TESTBENCH_$dw -io_config IOCFG_$dw

    # Define the HLS configs

    define_hls_config sha BASIC -io_config IOCFG_$dw $COMMON_HLS_FLAGS

    # Behavioral simulation
    define_sim_config "BEHAV_$dw" "sha BEH" \
	"tb TESTBENCH_$dw" -io_config IOCFG_$dw

    # RTL simulation
    define_sim_config "BASIC_${dw}_V" "sha RTL_V BASIC" \
	"tb TESTBENCH_$dw" -io_config IOCFG_$dw

}; # foreach DATA_WIDTH


