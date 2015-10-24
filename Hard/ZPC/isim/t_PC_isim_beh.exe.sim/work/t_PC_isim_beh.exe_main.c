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
    work_m_00000000002383065040_2207681426_init();
    work_m_00000000002544221707_0204903951_init();
    work_m_00000000003212594970_3508565487_init();
    xilinxcorelib_ver_m_00000000001358910285_1290601285_init();
    xilinxcorelib_ver_m_00000000001687936702_0135474683_init();
    xilinxcorelib_ver_m_00000000002621774987_3467082781_init();
    xilinxcorelib_ver_m_00000000001603977570_0301627302_init();
    work_m_00000000000403262735_1756065721_init();
    work_m_00000000000000996807_1368203981_init();
    work_m_00000000004265130494_4217414517_init();
    work_m_00000000004173762286_0365506110_init();
    work_m_00000000000596992369_1106866723_init();
    work_m_00000000003319913314_3887546801_init();
    xilinxcorelib_ver_m_00000000001358910285_2212199708_init();
    xilinxcorelib_ver_m_00000000001687936702_0020666995_init();
    xilinxcorelib_ver_m_00000000000277421008_3303619959_init();
    xilinxcorelib_ver_m_00000000001603977570_0713773647_init();
    work_m_00000000003617559063_3602556285_init();
    xilinxcorelib_ver_m_00000000001358910285_3299116533_init();
    xilinxcorelib_ver_m_00000000001687936702_2735655753_init();
    xilinxcorelib_ver_m_00000000000277421008_4021089419_init();
    xilinxcorelib_ver_m_00000000001603977570_3418879223_init();
    work_m_00000000002489990758_3775873897_init();
    work_m_00000000000544065368_0584589268_init();
    work_m_00000000000866552629_3566486687_init();
    work_m_00000000000525373135_1733832700_init();
    work_m_00000000003880331323_1504805999_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000003880331323_1504805999");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
