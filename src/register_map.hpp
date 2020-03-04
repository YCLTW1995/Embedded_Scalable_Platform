/* Copyright 2018 Columbia University SLD Group */

#ifndef __REGISTER_MAP_HPP__
#define __REGISTER_MAP_HPP__

// -- Status and command registers

#define CMD_REG                  0x00

// -- Command encoding

#define ACCELERATOR_CMD_CLEARIRQ 0x00
#define ACCELERATOR_CMD_GO       0x01

// -- Pointers to memory

#define IN_DATA_BASE_ADDR_REG    0x04
//#define IN_COEFF_BASE_ADDR_REG   0x08
//#define OUT_DATA_BASE_ADDR_REG   0x0c

// -- Configuration parameters

///#define NSAMPLES_REG             0x10
//#define NITERS_REG               0x14


#endif /* __REGISTER_MAP_HPP__ */