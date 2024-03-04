#ifndef __SYSCON_INIT_H__
#define __SYSCON_INIT_H__

#define SCU_INIT_ERR_SUCCESS	0
#define SCU_INIT_ERR_FAILED	1

bootstage_t scu_otpstrap_init_f(void);
bootstage_t scu_otpstrap_init_r(void);
bootstage_t scu_pinmux_init(void);
bootstage_t scu_dbgctrl_init(void);
bootstage_t scu_rstlog_init(void);

#endif
