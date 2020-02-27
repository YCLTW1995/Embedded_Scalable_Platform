/* Copyright 2019 Columbia University SLD Group */

#include "utils.hpp"

#include "memory.hpp"

// -- Functions (read)

void memory_t::reset_multi_read()
{
    // Nothing to do
}

bool memory_t::do_read(dma_target_t::data_t &val, unsigned index)
{
    // TODO: copy the value from data to val
    unsigned b_index = index/4 ;
    val.range(31,0) = data[b_index].to_uint() ;
    return true;
}

void memory_t::multi_read(dma_target_t::archan_t &archan,
                          dma_target_t::rchan_t &rchan,
                          bool &burst_done)
{
    bool ret = do_read(rchan.data, archan.addr);

    if (!ret)
    {
        rchan.resp = axi4::AXI_SLVERR_RESPONSE;
    }

    if (archan.len == 0)
    {
        burst_done = true;
    }

    archan.addr += 4;
    archan.len -= 1;
}

bool memory_t::can_multi_read() const
{
    return true;
}

// -- Functions (write)

void memory_t::reset_multi_write()
{
    // Nothing to do
}

bool memory_t::do_write(dma_target_t::data_t val, unsigned index)
{
    unsigned b_index = index / 4;

    // TODO: copy the value from val to data
    data[b_index] = val.range(31, 0).to_uint();
    
    return true;
}

void memory_t::multi_write(dma_target_t::awchan_t &awchan,
                           const dma_target_t::wchan_t &wchan,
                           dma_target_t::bchan_t &bchan,
                           bool &burst_done)
{
    if (!do_write(wchan.data, awchan.addr))
    {
        bchan.resp = axi4::AXI_SLVERR_RESPONSE;
    }

    if (awchan.len == 0)
    {
        burst_done = true;
    }

    awchan.addr += 4;
    awchan.len -= 1;
}

bool memory_t::can_multi_write() const
{
    return true;
}