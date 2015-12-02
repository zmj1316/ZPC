/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000002383065040_2195151378_init();
    work_m_00000000002383065040_3957750027_init();
    work_m_00000000002544221707_0204903951_init();
    work_m_00000000004175839661_3508565487_init();
    work_m_00000000002699631795_0303914935_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000002699631795_0303914935");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
