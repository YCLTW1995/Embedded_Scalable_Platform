/* Copyright 2019 Columbia University, SLD Group */

#include "system.hpp"

system_t *tb_system = NULL;

// Default image if argv[] is not set
//std::string image_path = "cat.bin";

//std::string model_path = "../../models/dwarf7.mojo";

extern void esc_elaborate()
{
    // Creating the whole system
    // Original 
        //tb_system = new system_t("tb_system", model_path, image_path);
    // My version
    tb_system = new system_t("tb_system") ;
}

extern void esc_cleanup()
{
    // Deleting the system
    delete tb_system;
}

int sc_main(int argc, char *argv[])
{
    // Kills various SystemC warnings
    sc_report_handler::set_actions(SC_WARNING, SC_DO_NOTHING);

    //if (argc >= 2)
    //{ image_path = std::string(argv[1]) + ".bin"; }

    esc_initialize(argc, argv);
    esc_elaborate();

    sc_clock clk("clk", CLOCK_PERIOD, SC_NS);
    sc_signal<bool> rst("rst");

    tb_system->clk(clk);
    tb_system->rst(rst);

    rst.write(false);

    sc_start(RESET_PERIOD, SC_NS);

    rst.write(true);

    sc_start();

    esc_log_pass();

    return 0;
}