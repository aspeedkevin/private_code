// SPDX-License-Identifier: GPL-2.0+
// [dwc_ddrphy_phyinit_main] Start of dwc_ddrphy_phyinit_main()
// [dwc_ddrphy_phyinit_sequence] Start of dwc_ddrphy_phyinit_sequence()
// [dwc_ddrphy_phyinit_initStruct] Start of dwc_ddrphy_phyinit_initStruct()
// [dwc_ddrphy_phyinit_initStruct] End of dwc_ddrphy_phyinit_initStruct()
// [dwc_ddrphy_phyinit_setDefault] Start of dwc_ddrphy_phyinit_setDefault()
// [dwc_ddrphy_phyinit_setDefault] End of dwc_ddrphy_phyinit_setDefault()

////##############################################################
//
//// dwc_ddrphy_phyinit_userCustom_overrideUserInput is a user-editable function.  User can edit this function according to their needs.
////
//// The purpose of dwc_ddrphy_phyinit_userCustom_overrideUserInput() is to override any
//// any field in Phyinit data structure set by dwc_ddrphy_phyinit_setDefault()
//// User should only override values in userInputBasic and userInputAdvanced.
//// IMPORTANT: in this function, user shall not override any values in the
//// messageblock directly on the data structue as the might be overwritten by
//// dwc_ddrphy_phyinit_calcMb().  Use dwc_ddrphy_phyinit_setMb() to set
//// messageblock parameters for override values to remain pervasive if
//// desired
//
////##############################################################

dwc_ddrphy_phyinit_userCustom_overrideUserInput();
//
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'DramType' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'DimmType' to 0x4
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'NumDbyte' to 0x2
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'NumActiveDbyteDfi0' to 0x2
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'NumAnib' to 0xa
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'NumRank_dfi0' to 0x1
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'DramDataWidth[0]' to 0x10
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'DramDataWidth[1]' to 0x10
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'DramDataWidth[2]' to 0x10
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'DramDataWidth[3]' to 0x10
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'NumPStates' to 0x1
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'Frequency[0]' to 0x640
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'PllBypass[0]' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'DfiFreqRatio[0]' to 0x1
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'Dfi1Exists' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'D4RxPreambleLength[0]' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'D4TxPreambleLength[0]' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'ExtCalResVal' to 0xf0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'Is2Ttiming[0]' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'ODTImpedance[0]' to 0x78
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'TxImpedance[0]' to 0x3c
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'MemAlertEn' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'MtestPUImp' to 0xf0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'DisDynAdrTri[0]' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'PhyMstrTrainInterval[0]' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'PhyMstrMaxReqToAck[0]' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'PhyMstrCtrlMode[0]' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'WDQSExt' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'CalInterval' to 0x9
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'CalOnce' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'RxEnBackOff' to 0x1
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'TrainSequenceCtrl' to 0x31f
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'SnpsUmctlOpt' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'SnpsUmctlF0RC5x[0]' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'TxSlewRiseDQ[0]' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'TxSlewFallDQ[0]' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'TxSlewRiseAC' to 0x45
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'TxSlewFallAC' to 0xa
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'IsHighVDD' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'TxSlewRiseCK' to 0x52
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'TxSlewFallCK' to 0x12
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'DisablePmuEcc' to 0x1
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'EnableMAlertAsync' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'Apb32BitMode' to 0x1
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'tDQS2DQ' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'tDQSCK' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'tCASL_override' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'tCASL_add[0][0]' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'tCASL_add[0][1]' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'tCASL_add[0][2]' to 0x0
//// [dwc_ddrphy_phyinit_setUserInput] Setting PHYINIT field 'tCASL_add[0][3]' to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].MsgMisc to 0x7
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].Pstate to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].PllBypassEn to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].DRAMFreq to 0xc80
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].PhyVref to 0x40
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].DramType to 0x2
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].DisabledDbyte to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].EnabledDQs to 0x10
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].CsPresent to 0x1
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].CsPresentD0 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].CsPresentD1 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].AddrMirror to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].PhyCfg to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].SequenceCtrl to 0x31f
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].HdtCtrl to 0xc8
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].PhyConfigOverride to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].DFIMRLMargin to 0x2
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].MR0 to 0x2150
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].MR1 to 0x101
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].MR2 to 0x228
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].MR3 to 0x400
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].MR4 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].MR5 to 0x500
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].MR6 to 0x104f
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].X16Present to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].CsSetupGDDec to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].AcsmOdtCtrl0 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].AcsmOdtCtrl1 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].AcsmOdtCtrl2 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].AcsmOdtCtrl3 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].AcsmOdtCtrl4 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].AcsmOdtCtrl5 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].AcsmOdtCtrl6 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].AcsmOdtCtrl7 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib0 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib1 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib2 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib3 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib4 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib5 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib6 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib7 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib8 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib9 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib10 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib11 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib12 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib13 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib14 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib15 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib16 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib17 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib18 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR0Nib19 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib0 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib1 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib2 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib3 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib4 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib5 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib6 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib7 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib8 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib9 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib10 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib11 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib12 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib13 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib14 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib15 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib16 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib17 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib18 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR1Nib19 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib0 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib1 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib2 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib3 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib4 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib5 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib6 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib7 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib8 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib9 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib10 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib11 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib12 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib13 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib14 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib15 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib16 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib17 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib18 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR2Nib19 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib0 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib1 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib2 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib3 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib4 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib5 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib6 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib7 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib8 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib9 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib10 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib11 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib12 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib13 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib14 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib15 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib16 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib17 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib18 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].VrefDqR3Nib19 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].ALT_CAS_L to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].ALT_WCAS_L to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].D4Misc to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].ExtTrainOpt to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_1D[0].NVDIMM to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].MsgMisc to 0x7
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].Pstate to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].PllBypassEn to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].DRAMFreq to 0xc80
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].PhyVref to 0x40
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].DramType to 0x2
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].DisabledDbyte to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].EnabledDQs to 0x10
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].CsPresent to 0x1
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].CsPresentD0 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].CsPresentD1 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].AddrMirror to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].PhyCfg to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].SequenceCtrl to 0x31f
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].HdtCtrl to 0xc8
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].PhyConfigOverride to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].DFIMRLMargin to 0x2
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].MR0 to 0x2150
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].MR1 to 0x101
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].MR2 to 0x228
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].MR3 to 0x400
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].MR4 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].MR5 to 0x500
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].MR6 to 0x104f
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].X16Present to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].CsSetupGDDec to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].AcsmOdtCtrl0 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].AcsmOdtCtrl1 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].AcsmOdtCtrl2 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].AcsmOdtCtrl3 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].AcsmOdtCtrl4 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].AcsmOdtCtrl5 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].AcsmOdtCtrl6 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].AcsmOdtCtrl7 to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib0 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib1 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib2 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib3 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib4 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib5 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib6 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib7 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib8 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib9 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib10 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib11 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib12 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib13 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib14 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib15 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib16 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib17 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib18 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR0Nib19 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib0 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib1 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib2 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib3 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib4 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib5 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib6 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib7 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib8 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib9 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib10 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib11 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib12 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib13 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib14 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib15 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib16 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib17 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib18 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR1Nib19 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib0 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib1 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib2 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib3 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib4 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib5 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib6 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib7 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib8 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib9 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib10 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib11 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib12 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib13 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib14 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib15 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib16 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib17 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib18 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR2Nib19 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib0 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib1 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib2 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib3 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib4 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib5 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib6 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib7 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib8 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib9 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib10 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib11 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib12 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib13 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib14 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib15 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib16 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib17 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib18 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].VrefDqR3Nib19 to 0xf
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].ALT_CAS_L to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].ALT_WCAS_L to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].D4Misc to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].ExtTrainOpt to 0x0
// [dwc_ddrphy_phyinit_setMb] Setting mb_DDR4U_2D[0].NVDIMM to 0x0
// [dwc_ddrphy_phyinit_userCustom_overrideUserInput] End of dwc_ddrphy_phyinit_userCustom_overrideUserInput()
//[dwc_ddrphy_phyinit_calcMb] Start of dwc_ddrphy_phyinit_calcMb()
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_1D[0].DramType override to 0x2
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_1D[0].Pstate override to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_1D[0].DRAMFreq override to 0xc80
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_1D[0].PllBypassEn override to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_1D[0].EnabledDQs override to 0x10
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_1D[0].PhyCfg override to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_1D[0].DisabledDbyte override to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_1D[0].X16Present override to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[1].DramType to 0x2
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[1].Pstate to 0x1
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[1].DRAMFreq to 0x856
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[1].PllBypassEn to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[1].EnabledDQs to 0x10
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[1].PhyCfg to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[1].DisabledDbyte to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[1].X16Present to 0x1
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[2].DramType to 0x2
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[2].Pstate to 0x2
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[2].DRAMFreq to 0x74a
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[2].PllBypassEn to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[2].EnabledDQs to 0x10
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[2].PhyCfg to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[2].DisabledDbyte to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[2].X16Present to 0x1
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[3].DramType to 0x2
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[3].Pstate to 0x3
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[3].DRAMFreq to 0x640
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[3].PllBypassEn to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[3].EnabledDQs to 0x10
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[3].PhyCfg to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[3].DisabledDbyte to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] Setting mb_DDR4U_1D[3].X16Present to 0x1
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_2D[0].DramType override to 0x2
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_2D[0].Pstate override to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_2D[0].DRAMFreq override to 0xc80
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_2D[0].PllBypassEn override to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_2D[0].EnabledDQs override to 0x10
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_2D[0].PhyCfg override to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_2D[0].DisabledDbyte override to 0x0
//// [dwc_ddrphy_phyinit_softSetMb] mb_DDR4U_2D[0].X16Present override to 0x0
////[dwc_ddrphy_phyinit_calcMb] TG_active[0] = 1
////[dwc_ddrphy_phyinit_calcMb] TG_active[1] = 0
////[dwc_ddrphy_phyinit_calcMb] TG_active[2] = 0
////[dwc_ddrphy_phyinit_calcMb] TG_active[3] = 0
////[dwc_ddrphy_phyinit_calcMb] tDIMM_CK [pstate=0][tg=0] = 0 ps
////[dwc_ddrphy_phyinit_calcMb] tDIMM_DQ [pstate=0][tg=0] = 0 ps
////[dwc_ddrphy_phyinit_calcMb] userInputSim.tCASL_add[pstate=0][tg=0] = 0 ps
////[dwc_ddrphy_phyinit_calcMb] tDIMM_CK [pstate=0][tg=1] = 0 ps
////[dwc_ddrphy_phyinit_calcMb] tDIMM_DQ [pstate=0][tg=1] = 0 ps
////[dwc_ddrphy_phyinit_calcMb] userInputSim.tCASL_add[pstate=0][tg=1] = 0 ps
////[dwc_ddrphy_phyinit_calcMb] tDIMM_CK [pstate=0][tg=2] = 0 ps
////[dwc_ddrphy_phyinit_calcMb] tDIMM_DQ [pstate=0][tg=2] = 0 ps
////[dwc_ddrphy_phyinit_calcMb] userInputSim.tCASL_add[pstate=0][tg=2] = 0 ps
////[dwc_ddrphy_phyinit_calcMb] tDIMM_CK [pstate=0][tg=3] = 0 ps
////[dwc_ddrphy_phyinit_calcMb] tDIMM_DQ [pstate=0][tg=3] = 0 ps
////[dwc_ddrphy_phyinit_calcMb] userInputSim.tCASL_add[pstate=0][tg=3] = 0 ps
//[dwc_ddrphy_phyinit_calcMb] End of dwc_ddrphy_phyinit_calcMb()
//// [phyinit_print_dat] // ####################################################
//// [phyinit_print_dat] //
//// [phyinit_print_dat] // Printing values in user input structure
//// [phyinit_print_dat] //
//// [phyinit_print_dat] // ####################################################
//// [phyinit_print_dat] pUserInputBasic->Frequency[0] = 1600
//// [phyinit_print_dat] pUserInputBasic->Frequency[1] = 1067
//// [phyinit_print_dat] pUserInputBasic->Frequency[2] = 933
//// [phyinit_print_dat] pUserInputBasic->Frequency[3] = 800
//// [phyinit_print_dat] pUserInputBasic->NumAnib = 10
//// [phyinit_print_dat] pUserInputBasic->DramType = 0
//// [phyinit_print_dat] pUserInputBasic->ARdPtrInitValOvr = 0
//// [phyinit_print_dat] pUserInputBasic->ARdPtrInitVal[0] = 3
//// [phyinit_print_dat] pUserInputBasic->ARdPtrInitVal[1] = 3
//// [phyinit_print_dat] pUserInputBasic->ARdPtrInitVal[2] = 3
//// [phyinit_print_dat] pUserInputBasic->ARdPtrInitVal[3] = 3
//// [phyinit_print_dat] pUserInputBasic->DfiFreqRatio[0] = 1
//// [phyinit_print_dat] pUserInputBasic->DfiFreqRatio[1] = 1
//// [phyinit_print_dat] pUserInputBasic->DfiFreqRatio[2] = 1
//// [phyinit_print_dat] pUserInputBasic->DfiFreqRatio[3] = 1
//// [phyinit_print_dat] pUserInputBasic->NumActiveDbyteDfi0 = 2
//// [phyinit_print_dat] pUserInputBasic->DisPtrInitClrTxTracking[0] = 0
//// [phyinit_print_dat] pUserInputBasic->DisPtrInitClrTxTracking[1] = 0
//// [phyinit_print_dat] pUserInputBasic->DisPtrInitClrTxTracking[2] = 0
//// [phyinit_print_dat] pUserInputBasic->DisPtrInitClrTxTracking[3] = 0
//// [phyinit_print_dat] pUserInputBasic->DramDataWidth[0] = 16
//// [phyinit_print_dat] pUserInputBasic->DramDataWidth[1] = 16
//// [phyinit_print_dat] pUserInputBasic->DramDataWidth[2] = 16
//// [phyinit_print_dat] pUserInputBasic->DramDataWidth[3] = 16
//// [phyinit_print_dat] pUserInputBasic->PllBypass[0] = 0
//// [phyinit_print_dat] pUserInputBasic->PllBypass[1] = 0
//// [phyinit_print_dat] pUserInputBasic->PllBypass[2] = 0
//// [phyinit_print_dat] pUserInputBasic->PllBypass[3] = 0
//// [phyinit_print_dat] pUserInputBasic->Dfi1Exists = 0
//// [phyinit_print_dat] pUserInputBasic->Train2D = 0
//// [phyinit_print_dat] pUserInputBasic->NumRank_dfi0 = 1
//// [phyinit_print_dat] pUserInputBasic->DimmType = 4
//// [phyinit_print_dat] pUserInputBasic->NumPStates = 1
//// [phyinit_print_dat] pUserInputBasic->NumDbyte = 2
//// [phyinit_print_dat] pUserInputAdvanced->DisablePmuEcc = 1
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvEn[0] = 1
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvEn[1] = 1
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvEn[2] = 1
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvEn[3] = 1
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvEn[4] = 0
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvEn[5] = 0
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvEn[6] = 0
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvEn[7] = 0
//// [phyinit_print_dat] pUserInputAdvanced->SnpsUmctlOpt = 0
//// [phyinit_print_dat] pUserInputAdvanced->TxImpedanceCtrl1[0] = 25
//// [phyinit_print_dat] pUserInputAdvanced->TxImpedanceCtrl1[1] = 25
//// [phyinit_print_dat] pUserInputAdvanced->TxImpedanceCtrl1[2] = 25
//// [phyinit_print_dat] pUserInputAdvanced->TxImpedanceCtrl1[3] = 25
//// [phyinit_print_dat] pUserInputAdvanced->TxSlewFallAC = 10
//// [phyinit_print_dat] pUserInputAdvanced->CalOnce = 0
//// [phyinit_print_dat] pUserInputAdvanced->ExtCalResVal = 240
//// [phyinit_print_dat] pUserInputAdvanced->D4TxPreambleLength[0] = 0
//// [phyinit_print_dat] pUserInputAdvanced->D4TxPreambleLength[1] = 0
//// [phyinit_print_dat] pUserInputAdvanced->D4TxPreambleLength[2] = 0
//// [phyinit_print_dat] pUserInputAdvanced->D4TxPreambleLength[3] = 0
//// [phyinit_print_dat] pUserInputAdvanced->DramByteSwap[0] = 0
//// [phyinit_print_dat] pUserInputAdvanced->DramByteSwap[1] = 0
//// [phyinit_print_dat] pUserInputAdvanced->DramByteSwap[2] = 0
//// [phyinit_print_dat] pUserInputAdvanced->DramByteSwap[3] = 0
//// [phyinit_print_dat] pUserInputAdvanced->NvAnibRcvSel[0] = 0
//// [phyinit_print_dat] pUserInputAdvanced->NvAnibRcvSel[1] = 0
//// [phyinit_print_dat] pUserInputAdvanced->NvAnibRcvSel[2] = 11
//// [phyinit_print_dat] pUserInputAdvanced->NvAnibRcvSel[3] = 11
//// [phyinit_print_dat] pUserInputAdvanced->NvAnibRcvSel[4] = 0
//// [phyinit_print_dat] pUserInputAdvanced->NvAnibRcvSel[5] = 0
//// [phyinit_print_dat] pUserInputAdvanced->NvAnibRcvSel[6] = 0
//// [phyinit_print_dat] pUserInputAdvanced->NvAnibRcvSel[7] = 0
//// [phyinit_print_dat] pUserInputAdvanced->CalInterval = 9
//// [phyinit_print_dat] pUserInputAdvanced->IsHighVDD = 0
//// [phyinit_print_dat] pUserInputAdvanced->TxSlewRiseAC = 69
//// [phyinit_print_dat] pUserInputAdvanced->TxSlewRiseCK = 82
//// [phyinit_print_dat] pUserInputAdvanced->RedundantCs_en = 0
//// [phyinit_print_dat] pUserInputAdvanced->TrainSequenceCtrl = 799
//// [phyinit_print_dat] pUserInputAdvanced->PhyMstrCtrlMode[0] = 0
//// [phyinit_print_dat] pUserInputAdvanced->PhyMstrCtrlMode[1] = 0
//// [phyinit_print_dat] pUserInputAdvanced->PhyMstrCtrlMode[2] = 0
//// [phyinit_print_dat] pUserInputAdvanced->PhyMstrCtrlMode[3] = 0
//// [phyinit_print_dat] pUserInputAdvanced->TxSlewFallDQ[0] = 0
//// [phyinit_print_dat] pUserInputAdvanced->TxSlewFallDQ[1] = 0
//// [phyinit_print_dat] pUserInputAdvanced->TxSlewFallDQ[2] = 0
//// [phyinit_print_dat] pUserInputAdvanced->TxSlewFallDQ[3] = 0
//// [phyinit_print_dat] pUserInputAdvanced->MtestPUImp = 240
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvLaneSel[0] = 1
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvLaneSel[1] = 3
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvLaneSel[2] = 1
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvLaneSel[3] = 3
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvLaneSel[4] = 0
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvLaneSel[5] = 0
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvLaneSel[6] = 0
//// [phyinit_print_dat] pUserInputAdvanced->AnibRcvLaneSel[7] = 0
//// [phyinit_print_dat] pUserInputAdvanced->AlertRecoveryEnable = 0
//// [phyinit_print_dat] pUserInputAdvanced->DisDynAdrTri[0] = 0
//// [phyinit_print_dat] pUserInputAdvanced->DisDynAdrTri[1] = 0
//// [phyinit_print_dat] pUserInputAdvanced->DisDynAdrTri[2] = 0
//// [phyinit_print_dat] pUserInputAdvanced->DisDynAdrTri[3] = 0
//// [phyinit_print_dat] pUserInputAdvanced->VREGCtrl_LP2_PwrSavings_En = 0
//// [phyinit_print_dat] pUserInputAdvanced->SnpsUmctlF0RC5x[0] = 0
//// [phyinit_print_dat] pUserInputAdvanced->SnpsUmctlF0RC5x[1] = 0
//// [phyinit_print_dat] pUserInputAdvanced->SnpsUmctlF0RC5x[2] = 0
//// [phyinit_print_dat] pUserInputAdvanced->SnpsUmctlF0RC5x[3] = 0
//// [phyinit_print_dat] pUserInputAdvanced->D4RxPreambleLength[0] = 0
//// [phyinit_print_dat] pUserInputAdvanced->D4RxPreambleLength[1] = 1
//// [phyinit_print_dat] pUserInputAdvanced->D4RxPreambleLength[2] = 1
//// [phyinit_print_dat] pUserInputAdvanced->D4RxPreambleLength[3] = 1
//// [phyinit_print_dat] pUserInputAdvanced->PhyMstrMaxReqToAck[0] = 0
//// [phyinit_print_dat] pUserInputAdvanced->PhyMstrMaxReqToAck[1] = 0
//// [phyinit_print_dat] pUserInputAdvanced->PhyMstrMaxReqToAck[2] = 0
//// [phyinit_print_dat] pUserInputAdvanced->PhyMstrMaxReqToAck[3] = 0
//// [phyinit_print_dat] pUserInputAdvanced->TxSlewRiseDQ[0] = 0
//// [phyinit_print_dat] pUserInputAdvanced->TxSlewRiseDQ[1] = 0
//// [phyinit_print_dat] pUserInputAdvanced->TxSlewRiseDQ[2] = 0
//// [phyinit_print_dat] pUserInputAdvanced->TxSlewRiseDQ[3] = 0
//// [phyinit_print_dat] pUserInputAdvanced->TxSlewFallCK = 18
//// [phyinit_print_dat] pUserInputAdvanced->TxImpedance[0] = 60
//// [phyinit_print_dat] pUserInputAdvanced->TxImpedance[1] = 25
//// [phyinit_print_dat] pUserInputAdvanced->TxImpedance[2] = 25
//// [phyinit_print_dat] pUserInputAdvanced->TxImpedance[3] = 25
//// [phyinit_print_dat] pUserInputAdvanced->en_16LogicalRanks_3DS = 0
//// [phyinit_print_dat] pUserInputAdvanced->RstRxTrkState = 0
//// [phyinit_print_dat] pUserInputAdvanced->Is2Ttiming[0] = 0
//// [phyinit_print_dat] pUserInputAdvanced->Is2Ttiming[1] = 0
//// [phyinit_print_dat] pUserInputAdvanced->Is2Ttiming[2] = 0
//// [phyinit_print_dat] pUserInputAdvanced->Is2Ttiming[3] = 0
//// [phyinit_print_dat] pUserInputAdvanced->MemAlertEn = 0
//// [phyinit_print_dat] pUserInputAdvanced->rtt_term_en = 0
//// [phyinit_print_dat] pUserInputAdvanced->PhyMstrTrainInterval[0] = 0
//// [phyinit_print_dat] pUserInputAdvanced->PhyMstrTrainInterval[1] = 0
//// [phyinit_print_dat] pUserInputAdvanced->PhyMstrTrainInterval[2] = 0
//// [phyinit_print_dat] pUserInputAdvanced->PhyMstrTrainInterval[3] = 0
//// [phyinit_print_dat] pUserInputAdvanced->WDQSExt = 0
//// [phyinit_print_dat] pUserInputAdvanced->en_3DS = 0
//// [phyinit_print_dat] pUserInputAdvanced->TxImpedanceCtrl2[0] = 0
//// [phyinit_print_dat] pUserInputAdvanced->TxImpedanceCtrl2[1] = 0
//// [phyinit_print_dat] pUserInputAdvanced->TxImpedanceCtrl2[2] = 0
//// [phyinit_print_dat] pUserInputAdvanced->TxImpedanceCtrl2[3] = 0
//// [phyinit_print_dat] pUserInputAdvanced->ODTImpedance[0] = 120
//// [phyinit_print_dat] pUserInputAdvanced->ODTImpedance[1] = 60
//// [phyinit_print_dat] pUserInputAdvanced->ODTImpedance[2] = 60
//// [phyinit_print_dat] pUserInputAdvanced->ODTImpedance[3] = 60
//// [phyinit_print_dat] pUserInputAdvanced->EnableMAlertAsync = 0
//// [phyinit_print_dat] pUserInputAdvanced->Apb32BitMode = 1
//// [phyinit_print_dat] pUserInputAdvanced->Nibble_ECC = 15
//// [phyinit_print_dat] pUserInputAdvanced->RxEnBackOff = 1
//// [phyinit_print_dat] pUserInputAdvanced->ATxImpedance = 53247
//// [phyinit_print_dat] pUserInputSim->tDQS2DQ    = 0
//// [phyinit_print_dat] pUserInputSim->tDQSCK	   = 0
//// [phyinit_print_dat] pUserInputSim->tSTAOFF[0] = 0
//// [phyinit_print_dat] pUserInputSim->tSTAOFF[1] = 0
//// [phyinit_print_dat] pUserInputSim->tSTAOFF[2] = 0
//// [phyinit_print_dat] pUserInputSim->tSTAOFF[3] = 0
//// [phyinit_print_dat] // ####################################################
//// [phyinit_print_dat] //
//// [phyinit_print_dat] // Printing values of 1D message block input/inout fields, PState=0
//// [phyinit_print_dat] //
//// [phyinit_print_dat] // ####################################################
//// [phyinit_print_dat] mb_DDR4U_1D[0].AdvTrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].MsgMisc = 0x7
//// [phyinit_print_dat] mb_DDR4U_1D[0].Pstate = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].PllBypassEn = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].DRAMFreq = 0xc80
//// [phyinit_print_dat] mb_DDR4U_1D[0].PhyVref = 0x40
//// [phyinit_print_dat] mb_DDR4U_1D[0].DramType = 0x2
//// [phyinit_print_dat] mb_DDR4U_1D[0].DisabledDbyte = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].EnabledDQs = 0x10
//// [phyinit_print_dat] mb_DDR4U_1D[0].CsPresent = 0x1
//// [phyinit_print_dat] mb_DDR4U_1D[0].CsPresentD0 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].CsPresentD1 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AddrMirror = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].PhyCfg = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].SequenceCtrl = 0x31f
//// [phyinit_print_dat] mb_DDR4U_1D[0].HdtCtrl = 0xc8
//// [phyinit_print_dat] mb_DDR4U_1D[0].Rx2D_CmdSpacing = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].MREP_MIN_PULSE = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].DWL_MIN_PULSE = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].PhyConfigOverride = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].DFIMRLMargin = 0x2
//// [phyinit_print_dat] mb_DDR4U_1D[0].DDR4_RXEN_OFFSET = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].MR0 = 0x2150
//// [phyinit_print_dat] mb_DDR4U_1D[0].MR1 = 0x101
//// [phyinit_print_dat] mb_DDR4U_1D[0].MR2 = 0x228
//// [phyinit_print_dat] mb_DDR4U_1D[0].MR3 = 0x400
//// [phyinit_print_dat] mb_DDR4U_1D[0].MR4 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].MR5 = 0x500
//// [phyinit_print_dat] mb_DDR4U_1D[0].MR6 = 0x104f
//// [phyinit_print_dat] mb_DDR4U_1D[0].X16Present = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].CsSetupGDDec = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK0 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK1 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK2 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK3 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK4 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK5 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK6 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK7 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl0 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl1 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl2 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl3 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl4 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl5 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl6 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl7 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].ALT_CAS_L = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].ALT_WCAS_L = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].D4Misc = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].ExtTrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].NVDIMM = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AdvTrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].MsgMisc = 0x7
//// [phyinit_print_dat] mb_DDR4U_1D[0].Pstate = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].PllBypassEn = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].DRAMFreq = 0xc80
//// [phyinit_print_dat] mb_DDR4U_1D[0].PhyVref = 0x40
//// [phyinit_print_dat] mb_DDR4U_1D[0].DramType = 0x2
//// [phyinit_print_dat] mb_DDR4U_1D[0].DisabledDbyte = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].EnabledDQs = 0x10
//// [phyinit_print_dat] mb_DDR4U_1D[0].CsPresent = 0x1
//// [phyinit_print_dat] mb_DDR4U_1D[0].CsPresentD0 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].CsPresentD1 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AddrMirror = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].PhyCfg = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].SequenceCtrl = 0x31f
//// [phyinit_print_dat] mb_DDR4U_1D[0].HdtCtrl = 0xc8
//// [phyinit_print_dat] mb_DDR4U_1D[0].Rx2D_CmdSpacing = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].MREP_MIN_PULSE = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].DWL_MIN_PULSE = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].PhyConfigOverride = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].DFIMRLMargin = 0x2
//// [phyinit_print_dat] mb_DDR4U_1D[0].DDR4_RXEN_OFFSET = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].MR0 = 0x2150
//// [phyinit_print_dat] mb_DDR4U_1D[0].MR1 = 0x101
//// [phyinit_print_dat] mb_DDR4U_1D[0].MR2 = 0x228
//// [phyinit_print_dat] mb_DDR4U_1D[0].MR3 = 0x400
//// [phyinit_print_dat] mb_DDR4U_1D[0].MR4 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].MR5 = 0x500
//// [phyinit_print_dat] mb_DDR4U_1D[0].MR6 = 0x104f
//// [phyinit_print_dat] mb_DDR4U_1D[0].X16Present = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].CsSetupGDDec = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK0 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK1 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK2 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK3 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK4 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK5 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK6 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].RTT_NOM_WR_PARK7 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl0 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl1 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl2 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl3 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl4 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl5 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl6 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].AcsmOdtCtrl7 = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR0Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR1Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR2Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].VrefDqR3Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_1D[0].ALT_CAS_L = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].ALT_WCAS_L = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].D4Misc = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].ExtTrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_1D[0].NVDIMM = 0x0
//// [phyinit_print_dat] // ####################################################
//// [phyinit_print_dat] //
//// [phyinit_print_dat] // Printing values of 2D message block input/inout fields, PState=0
//// [phyinit_print_dat] //
//// [phyinit_print_dat] // ####################################################
//// [phyinit_print_dat] mb_DDR4U_2D[0].AdvTrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].MsgMisc = 0x7
//// [phyinit_print_dat] mb_DDR4U_2D[0].Pstate = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].PllBypassEn = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].DRAMFreq = 0xc80
//// [phyinit_print_dat] mb_DDR4U_2D[0].PhyVref = 0x40
//// [phyinit_print_dat] mb_DDR4U_2D[0].DramType = 0x2
//// [phyinit_print_dat] mb_DDR4U_2D[0].DisabledDbyte = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].EnabledDQs = 0x10
//// [phyinit_print_dat] mb_DDR4U_2D[0].CsPresent = 0x1
//// [phyinit_print_dat] mb_DDR4U_2D[0].CsPresentD0 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].CsPresentD1 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AddrMirror = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].PhyCfg = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].SequenceCtrl = 0x31f
//// [phyinit_print_dat] mb_DDR4U_2D[0].HdtCtrl = 0xc8
//// [phyinit_print_dat] mb_DDR4U_2D[0].RX2D_TrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].TX2D_TrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].Share2DVrefResult = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].Delay_Weight2D = 0x20
//// [phyinit_print_dat] mb_DDR4U_2D[0].Voltage_Weight2D = 0x80
//// [phyinit_print_dat] mb_DDR4U_2D[0].Rx2D_CmdSpacing = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].MREP_MIN_PULSE = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].DWL_MIN_PULSE = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].PhyConfigOverride = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].DFIMRLMargin = 0x2
//// [phyinit_print_dat] mb_DDR4U_2D[0].VoltageRange2D = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR1_EQU_TrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].advSearch_rd2D = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].advSearch_wr2D = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].moreDebug2D = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR6_EQU_TrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].TX2D_DB_DFE_TrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].CsWriteNoise = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AdvTrainOpt2D = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].Misc2D = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR0 = 0x2150
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR1 = 0x101
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR2 = 0x228
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR3 = 0x400
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR4 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR5 = 0x500
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR6 = 0x104f
//// [phyinit_print_dat] mb_DDR4U_2D[0].X16Present = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].CsSetupGDDec = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK0 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK1 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK2 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK3 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK4 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK5 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK6 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK7 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl0 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl1 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl2 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl3 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl4 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl5 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl6 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl7 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].ALT_CAS_L = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].ALT_WCAS_L = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].D4Misc = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].ExtTrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].NVDIMM = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AdvTrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].MsgMisc = 0x7
//// [phyinit_print_dat] mb_DDR4U_2D[0].Pstate = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].PllBypassEn = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].DRAMFreq = 0xc80
//// [phyinit_print_dat] mb_DDR4U_2D[0].PhyVref = 0x40
//// [phyinit_print_dat] mb_DDR4U_2D[0].DramType = 0x2
//// [phyinit_print_dat] mb_DDR4U_2D[0].DisabledDbyte = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].EnabledDQs = 0x10
//// [phyinit_print_dat] mb_DDR4U_2D[0].CsPresent = 0x1
//// [phyinit_print_dat] mb_DDR4U_2D[0].CsPresentD0 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].CsPresentD1 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AddrMirror = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].PhyCfg = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].SequenceCtrl = 0x31f
//// [phyinit_print_dat] mb_DDR4U_2D[0].HdtCtrl = 0xc8
//// [phyinit_print_dat] mb_DDR4U_2D[0].RX2D_TrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].TX2D_TrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].Share2DVrefResult = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].Delay_Weight2D = 0x20
//// [phyinit_print_dat] mb_DDR4U_2D[0].Voltage_Weight2D = 0x80
//// [phyinit_print_dat] mb_DDR4U_2D[0].Rx2D_CmdSpacing = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].MREP_MIN_PULSE = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].DWL_MIN_PULSE = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].PhyConfigOverride = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].DFIMRLMargin = 0x2
//// [phyinit_print_dat] mb_DDR4U_2D[0].VoltageRange2D = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR1_EQU_TrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].advSearch_rd2D = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].advSearch_wr2D = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].moreDebug2D = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR6_EQU_TrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].TX2D_DB_DFE_TrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].CsWriteNoise = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AdvTrainOpt2D = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].Misc2D = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR0 = 0x2150
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR1 = 0x101
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR2 = 0x228
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR3 = 0x400
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR4 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR5 = 0x500
//// [phyinit_print_dat] mb_DDR4U_2D[0].MR6 = 0x104f
//// [phyinit_print_dat] mb_DDR4U_2D[0].X16Present = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].CsSetupGDDec = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK0 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK1 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK2 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK3 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK4 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK5 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK6 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].RTT_NOM_WR_PARK7 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl0 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl1 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl2 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl3 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl4 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl5 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl6 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].AcsmOdtCtrl7 = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR0Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR1Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR2Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib0 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib1 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib2 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib3 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib4 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib5 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib6 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib7 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib8 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib9 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib10 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib11 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib12 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib13 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib14 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib15 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib16 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib17 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib18 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].VrefDqR3Nib19 = 0xf
//// [phyinit_print_dat] mb_DDR4U_2D[0].ALT_CAS_L = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].ALT_WCAS_L = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].D4Misc = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].ExtTrainOpt = 0x0
//// [phyinit_print_dat] mb_DDR4U_2D[0].NVDIMM = 0x0

////##############################################################
////
//// Step (A) : Bring up VDD, VDDQ, and VAA
////
//// The power supplies can come up and stabilize in any order.
//// While the power supplies are coming up, all outputs will be unknown and
//// the values of the inputs are don't cares.
////
////##############################################################

dwc_ddrphy_phyinit_userCustom_A_bringupPower();

//[dwc_ddrphy_phyinit_userCustom_A_bringupPower] End of dwc_ddrphy_phyinit_userCustom_A_bringupPower()
//
//
////##############################################################
////
//// 4.3.2(B) Start Clocks and Reset the PHY
////
//// Following is one possbile sequence to reset the PHY. Other sequences are also possible.
//// See section 5.2.2 of the PUB for other possible reset sequences.
////
//// 1. Drive PwrOkIn to 0. Note: Reset, DfiClk, and APBCLK can be X.
//// 2. Start DfiClk and APBCLK
//// 3. Drive Reset to 1 and PRESETn_APB to 0.
////	Note: The combination of PwrOkIn=0 and Reset=1 signals a cold reset to the PHY.
//// 4. Wait a minimum of 8 cycles.
//// 5. Drive PwrOkIn to 1. Once the PwrOkIn is asserted (and Reset is still asserted),
////	DfiClk synchronously switches to any legal input frequency.
//// 6. Wait a minimum of 64 cycles. Note: This is the reset period for the PHY.
//// 7. Drive Reset to 0. Note: All DFI and APB inputs must be driven at valid reset states before the deassertion of Reset.
//// 8. Wait a minimum of 1 Cycle.
//// 9. Drive PRESETn_APB to 1 to de-assert reset on the ABP bus.
////10. The PHY is now in the reset state and is ready to accept APB transactions.
////
////##############################################################
//
//
dwc_ddrphy_phyinit_userCustom_B_startClockResetPhy();

//// [dwc_ddrphy_phyinit_userCustom_B_startClockResetPhy] End of dwc_ddrphy_phyinit_userCustom_B_startClockResetPhy()
//

////##############################################################
////
//// Step (C) Initialize PHY Configuration
////
//// Load the required PHY configuration registers for the appropriate mode and memory configuration
////
////##############################################################
//

//// [phyinit_C_initPhyConfig] Start of dwc_ddrphy_phyinit_C_initPhyConfig()
//// [phyinit_C_initPhyConfig] Programming ForceClkGaterEnables::ForcePubDxClkEnLow to 0x1
dwc_ddrphy_apb_wr(0x200a6, 0x2); // DWC_DDRPHYA_MASTER0_base0_ForceClkGaterEnables
// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming VREGCtrl3::VshCtrlUpdate to 0x0 for MASTER
dwc_ddrphy_apb_wr(0x20066, 0x0); // DWC_DDRPHYA_MASTER0_base0_VREGCtrl3
// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming VREGCtrl3::VshCtrlUpdate to 0x0 for all DBYTEs
dwc_ddrphy_apb_wr(0x10066, 0x0); // DWC_DDRPHYA_DBYTE0_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x11066, 0x0); // DWC_DDRPHYA_DBYTE1_base0_VREGCtrl3
// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming VREGCtrl3::VshCtrlUpdate to 0x0 for all ANIBs
dwc_ddrphy_apb_wr(0x66, 0x0); // DWC_DDRPHYA_ANIB0_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x1066, 0x0); // DWC_DDRPHYA_ANIB1_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x2066, 0x0); // DWC_DDRPHYA_ANIB2_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x3066, 0x0); // DWC_DDRPHYA_ANIB3_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x4066, 0x0); // DWC_DDRPHYA_ANIB4_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x5066, 0x0); // DWC_DDRPHYA_ANIB5_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x6066, 0x0); // DWC_DDRPHYA_ANIB6_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x7066, 0x0); // DWC_DDRPHYA_ANIB7_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x8066, 0x0); // DWC_DDRPHYA_ANIB8_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x9066, 0x0); // DWC_DDRPHYA_ANIB9_base0_VREGCtrl3
// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming VREGCtrl1::VshDAC to 0x31 for MASTER
dwc_ddrphy_apb_wr(0x20029, 0xc4); // DWC_DDRPHYA_MASTER0_base0_VREGCtrl1_p0
// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming VREGCtrl1::VshDAC to 0x31 for all DBYTEs
dwc_ddrphy_apb_wr(0x10029, 0xc4); // DWC_DDRPHYA_DBYTE0_base0_VREGCtrl1_p0
dwc_ddrphy_apb_wr(0x11029, 0xc4); // DWC_DDRPHYA_DBYTE1_base0_VREGCtrl1_p0
// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming VREGCtrl1::VshDAC to 0x31 for all ANIBs
dwc_ddrphy_apb_wr(0x29, 0xc4); // DWC_DDRPHYA_ANIB0_base0_VREGCtrl1_p0
dwc_ddrphy_apb_wr(0x1029, 0xc4); // DWC_DDRPHYA_ANIB1_base0_VREGCtrl1_p0
dwc_ddrphy_apb_wr(0x2029, 0xc4); // DWC_DDRPHYA_ANIB2_base0_VREGCtrl1_p0
dwc_ddrphy_apb_wr(0x3029, 0xc4); // DWC_DDRPHYA_ANIB3_base0_VREGCtrl1_p0
dwc_ddrphy_apb_wr(0x4029, 0xc4); // DWC_DDRPHYA_ANIB4_base0_VREGCtrl1_p0
dwc_ddrphy_apb_wr(0x5029, 0xc4); // DWC_DDRPHYA_ANIB5_base0_VREGCtrl1_p0
dwc_ddrphy_apb_wr(0x6029, 0xc4); // DWC_DDRPHYA_ANIB6_base0_VREGCtrl1_p0
dwc_ddrphy_apb_wr(0x7029, 0xc4); // DWC_DDRPHYA_ANIB7_base0_VREGCtrl1_p0
dwc_ddrphy_apb_wr(0x8029, 0xc4); // DWC_DDRPHYA_ANIB8_base0_VREGCtrl1_p0
dwc_ddrphy_apb_wr(0x9029, 0xc4); // DWC_DDRPHYA_ANIB9_base0_VREGCtrl1_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming TxSlewRate::CsrTxSrc to 0x0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming TxSlewRate::TxPreDrvMode to 0x0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming TxSlewRate to 0x0
//// [phyinit_C_initPhyConfig] ### NOTE ### Optimal setting for TxSlewRate::CsrTxSrc are technology specific.
//// [phyinit_C_initPhyConfig] ### NOTE ### Please consult the "Output Slew Rate" section of HSpice Model App Note in specific technology for recommended settings

dwc_ddrphy_apb_wr(0x1005f, 0x0); // DWC_DDRPHYA_DBYTE0_base0_TxSlewRate_b0_p0
dwc_ddrphy_apb_wr(0x1015f, 0x0); // DWC_DDRPHYA_DBYTE0_base0_TxSlewRate_b1_p0
dwc_ddrphy_apb_wr(0x1105f, 0x0); // DWC_DDRPHYA_DBYTE1_base0_TxSlewRate_b0_p0
dwc_ddrphy_apb_wr(0x1115f, 0x0); // DWC_DDRPHYA_DBYTE1_base0_TxSlewRate_b1_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate::ATxPreDrvMode to 0x0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate::CsrATxSrc ANIB 0 to 0x11e
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate ANIB 0 to 0x11e
dwc_ddrphy_apb_wr(0x55, 0x11e); // DWC_DDRPHYA_ANIB0_base0_ATxSlewRate_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate::CsrATxSrc ANIB 1 to 0x11e
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate ANIB 1 to 0x11e
dwc_ddrphy_apb_wr(0x1055, 0x11e); // DWC_DDRPHYA_ANIB1_base0_ATxSlewRate_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate::CsrATxSrc ANIB 2 to 0x11e
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate ANIB 2 to 0x11e
dwc_ddrphy_apb_wr(0x2055, 0x11e); // DWC_DDRPHYA_ANIB2_base0_ATxSlewRate_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate::CsrATxSrc ANIB 3 to 0x11e
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate ANIB 3 to 0x11e
dwc_ddrphy_apb_wr(0x3055, 0x11e); // DWC_DDRPHYA_ANIB3_base0_ATxSlewRate_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate::CsrATxSrc ANIB 4 to 0x11e
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate ANIB 4 to 0x11e
dwc_ddrphy_apb_wr(0x4055, 0x11e); // DWC_DDRPHYA_ANIB4_base0_ATxSlewRate_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate::CsrATxSrc ANIB 5 to 0x15a
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate ANIB 5 to 0x15a
dwc_ddrphy_apb_wr(0x5055, 0x15a); // DWC_DDRPHYA_ANIB5_base0_ATxSlewRate_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate::CsrATxSrc ANIB 6 to 0x11e
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate ANIB 6 to 0x11e
dwc_ddrphy_apb_wr(0x6055, 0x11e); // DWC_DDRPHYA_ANIB6_base0_ATxSlewRate_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate::CsrATxSrc ANIB 7 to 0x11e
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate ANIB 7 to 0x11e
dwc_ddrphy_apb_wr(0x7055, 0x11e); // DWC_DDRPHYA_ANIB7_base0_ATxSlewRate_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate::CsrATxSrc ANIB 8 to 0x11e
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate ANIB 8 to 0x11e
dwc_ddrphy_apb_wr(0x8055, 0x11e); // DWC_DDRPHYA_ANIB8_base0_ATxSlewRate_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate::CsrATxSrc ANIB 9 to 0x11e
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxSlewRate ANIB 9 to 0x11e
dwc_ddrphy_apb_wr(0x9055, 0x11e); // DWC_DDRPHYA_ANIB9_base0_ATxSlewRate_p0
//// [phyinit_C_initPhyConfig] ### NOTE ### Optimal setting for ATxSlewRate::CsrATxSrc are technology specific.
//// [phyinit_C_initPhyConfig] ### NOTE ### Please consult the "Output Slew Rate" section of HSpice Model App Note in specific technology for recommended settings

//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming CalPreDriverOverride::CsrTxOvSrc to 0x172
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming CalPreDriverOverride::TxCalBaseN to 0x1
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming CalPreDriverOverride::TxCalBaseP to 0x1
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming CalPreDriverOverride to 0x372
//// [phyinit_C_initPhyConfig] ### NOTE ### Optimal setting for CalPreDriverOverride::CsrTxOvSrc are technology specific.
//// [phyinit_C_initPhyConfig] ### NOTE ### Please consult the "Output Slew Rate" section of HSpice Model App Note in specific technology for recommended settings

dwc_ddrphy_apb_wr(0x2008c, 0x372); // DWC_DDRPHYA_MASTER0_base0_CalPreDriverOverride
//// [phyinit_C_initPhyConfig] PUB revision is 0x0350.
//// [phyinit_C_initPhyConfig] Pstate=0,  Memclk=1600MHz, Programming PllCtrl2::PllFreqSel to 0x19 based on DfiClk frequency = 800.
dwc_ddrphy_apb_wr(0x200c5, 0x19); // DWC_DDRPHYA_MASTER0_base0_PllCtrl2_p0
//// [phyinit_C_initPhyConfig] Pstate=0,  Memclk=1600MHz, Programming PllCtrl1::PllCpPropCtrl to 0x3 based on DfiClk frequency = 800.
//// [phyinit_C_initPhyConfig] Pstate=0,  Memclk=1600MHz, Programming PllCtrl1::PllCpIntCtrl to 0x1 based on DfiClk frequency = 800.
//// [phyinit_C_initPhyConfig] Pstate=0,  Memclk=1600MHz, Programming PllCtrl1 to 0x61 based on DfiClk frequency = 800.
dwc_ddrphy_apb_wr(0x200c7, 0x61); // DWC_DDRPHYA_MASTER0_base0_PllCtrl1_p0
//// [phyinit_C_initPhyConfig] Pstate=0,  Memclk=1600MHz, Programming PllTestMode to 0x400f based on DfiClk frequency = 800.
dwc_ddrphy_apb_wr(0x200ca, 0x400f); // DWC_DDRPHYA_MASTER0_base0_PllTestMode_p0
//// [phyinit_C_initPhyConfig] Pstate=0,  Memclk=1600MHz, Programming PllCtrl4::PllCpPropGsCtrl to 0x6 based on DfiClk frequency = 800.
//// [phyinit_C_initPhyConfig] Pstate=0,  Memclk=1600MHz, Programming PllCtrl4::PllCpIntGsCtrl to 0x12 based on DfiClk frequency = 800.
//// [phyinit_C_initPhyConfig] Pstate=0,  Memclk=1600MHz, Programming PllCtrl4 to 0xd2 based on DfiClk frequency = 800.
dwc_ddrphy_apb_wr(0x200cc, 0xd2); // DWC_DDRPHYA_MASTER0_base0_PllCtrl4_p0
//// [phyinit_C_initPhyConfig] ### NOTE ### Optimal setting for PllCtrl1 and PllTestMode are technology specific.
//// [phyinit_C_initPhyConfig] ### NOTE ### Please consult technology specific PHY Databook for recommended settings

//
////##############################################################
////
//// Program ARdPtrInitVal based on Frequency and PLL Bypass inputs
//// The values programmed here assume ideal properties of DfiClk
//// and Pclk including:
//// - DfiClk skew
//// - DfiClk jitter
//// - DfiClk PVT variations
//// - Pclk skew
//// - Pclk jitter
////
//// PLL Bypassed mode:
////	 For MemClk frequency > 933MHz, the valid range of ARdPtrInitVal_p0[3:0] is: 2-5
////	 For MemClk frequency < 933MHz, the valid range of ARdPtrInitVal_p0[3:0] is: 1-5
////
//// PLL Enabled mode:
////	 For MemClk frequency > 933MHz, the valid range of ARdPtrInitVal_p0[3:0] is: 1-5
////	 For MemClk frequency < 933MHz, the valid range of ARdPtrInitVal_p0[3:0] is: 0-5
////
////##############################################################
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ARdPtrInitVal to 0x1
dwc_ddrphy_apb_wr(0x2002e, 0x1); // DWC_DDRPHYA_MASTER0_base0_ARdPtrInitVal_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming DisPtrInitClrTxTracking to 0x0
dwc_ddrphy_apb_wr(0x20051, 0x0); // DWC_DDRPHYA_MASTER0_base0_PtrInitTrackingModeCntrl_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming DqsPreambleControl::TwoTckRxDqsPre  to 0x0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming DqsPreambleControl::TwoTckTxDqsPre  to 0x0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming DqsPreambleControl::PositionDfeInit to 0x2
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming DqsPreambleControl::DDR5RxPreamble  to 0x0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming DqsPreambleControl::DDR5RxPostamble to 0x0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming DqsPreambleControl					 to 0x8
dwc_ddrphy_apb_wr(0x20024, 0x8); // DWC_DDRPHYA_MASTER0_base0_DqsPreambleControl_p0
//// [phyinit_C_initPhyConfig] Programming DbyteDllModeCntrl::DllRxPreambleMode to 0x1
//// [phyinit_C_initPhyConfig] Programming DbyteDllModeCntrl::DllRxBurstLengthMode to 0x0
//// [phyinit_C_initPhyConfig] Programming DbyteDllModeCntrl to 0x2
dwc_ddrphy_apb_wr(0x2003a, 0x2); // DWC_DDRPHYA_MASTER0_base0_DbyteDllModeCntrl
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming TxOdtDrvStren::TxOdtStrenPu to 0x4
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming TxOdtDrvStren::TxOdtStrenPd to 0x0
dwc_ddrphy_apb_wr(0x1004d, 0x4); // DWC_DDRPHYA_DBYTE0_base0_TxOdtDrvStren_b0_p0
dwc_ddrphy_apb_wr(0x1014d, 0x4); // DWC_DDRPHYA_DBYTE0_base0_TxOdtDrvStren_b1_p0
dwc_ddrphy_apb_wr(0x1104d, 0x4); // DWC_DDRPHYA_DBYTE1_base0_TxOdtDrvStren_b0_p0
dwc_ddrphy_apb_wr(0x1114d, 0x4); // DWC_DDRPHYA_DBYTE1_base0_TxOdtDrvStren_b1_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxImpedance::ADrvStrenP to 0x3f
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxImpedance::ADrvStrenN to 0x3f
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxImpedance::ATxReserved13x12 to 0x0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxImpedance::ATxCalBaseN to 0x1
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming ATxImpedance::ATxCalBaseP to 0x1
dwc_ddrphy_apb_wr(0x43, 0xcfff); // DWC_DDRPHYA_ANIB0_base0_ATxImpedance
dwc_ddrphy_apb_wr(0x1043, 0xcfff); // DWC_DDRPHYA_ANIB1_base0_ATxImpedance
dwc_ddrphy_apb_wr(0x2043, 0xcfff); // DWC_DDRPHYA_ANIB2_base0_ATxImpedance
dwc_ddrphy_apb_wr(0x3043, 0xcfff); // DWC_DDRPHYA_ANIB3_base0_ATxImpedance
dwc_ddrphy_apb_wr(0x4043, 0xcfff); // DWC_DDRPHYA_ANIB4_base0_ATxImpedance
dwc_ddrphy_apb_wr(0x5043, 0xcfff); // DWC_DDRPHYA_ANIB5_base0_ATxImpedance
dwc_ddrphy_apb_wr(0x6043, 0xcfff); // DWC_DDRPHYA_ANIB6_base0_ATxImpedance
dwc_ddrphy_apb_wr(0x7043, 0xcfff); // DWC_DDRPHYA_ANIB7_base0_ATxImpedance
dwc_ddrphy_apb_wr(0x8043, 0xcfff); // DWC_DDRPHYA_ANIB8_base0_ATxImpedance
dwc_ddrphy_apb_wr(0x9043, 0xcfff); // DWC_DDRPHYA_ANIB9_base0_ATxImpedance
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming TxImpedanceCtrl0::TxStrenEqHiPu to 0xc
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming TxImpedanceCtrl0::TxStrenEqLoPd to 0xc
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming TxImpedanceCtrl1::TxStrenPu to 0x3f
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming TxImpedanceCtrl1::TxStrenPd to 0x3f
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming TxImpedanceCtrl2::TxStrenEqLoPu to 0x0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming TxImpedanceCtrl2::TxStrenEqHiPd to 0x0
dwc_ddrphy_apb_wr(0x10041, 0x30c); // DWC_DDRPHYA_DBYTE0_base0_TxImpedanceCtrl0_b0_p0
dwc_ddrphy_apb_wr(0x10049, 0xfff); // DWC_DDRPHYA_DBYTE0_base0_TxImpedanceCtrl1_b0_p0
dwc_ddrphy_apb_wr(0x1004b, 0x0); // DWC_DDRPHYA_DBYTE0_base0_TxImpedanceCtrl2_b0_p0
dwc_ddrphy_apb_wr(0x10141, 0x30c); // DWC_DDRPHYA_DBYTE0_base0_TxImpedanceCtrl0_b1_p0
dwc_ddrphy_apb_wr(0x10149, 0xfff); // DWC_DDRPHYA_DBYTE0_base0_TxImpedanceCtrl1_b1_p0
dwc_ddrphy_apb_wr(0x1014b, 0x0); // DWC_DDRPHYA_DBYTE0_base0_TxImpedanceCtrl2_b1_p0
dwc_ddrphy_apb_wr(0x11041, 0x30c); // DWC_DDRPHYA_DBYTE1_base0_TxImpedanceCtrl0_b0_p0
dwc_ddrphy_apb_wr(0x11049, 0xfff); // DWC_DDRPHYA_DBYTE1_base0_TxImpedanceCtrl1_b0_p0
dwc_ddrphy_apb_wr(0x1104b, 0x0); // DWC_DDRPHYA_DBYTE1_base0_TxImpedanceCtrl2_b0_p0
dwc_ddrphy_apb_wr(0x11141, 0x30c); // DWC_DDRPHYA_DBYTE1_base0_TxImpedanceCtrl0_b1_p0
dwc_ddrphy_apb_wr(0x11149, 0xfff); // DWC_DDRPHYA_DBYTE1_base0_TxImpedanceCtrl1_b1_p0
dwc_ddrphy_apb_wr(0x1114b, 0x0); // DWC_DDRPHYA_DBYTE1_base0_TxImpedanceCtrl2_b1_p0
//// [phyinit_C_initPhyConfig] Programming DfiMode to 0x1
dwc_ddrphy_apb_wr(0x20018, 0x1); // DWC_DDRPHYA_MASTER0_base0_DfiMode
//// [phyinit_C_initPhyConfig] Programming DfiCAMode to 0x2
dwc_ddrphy_apb_wr(0x20075, 0x2); // DWC_DDRPHYA_MASTER0_base0_DfiCAMode
//// [phyinit_C_initPhyConfig] Programming CalDrvStr0::CalDrvStrPd50 to 0x2
//// [phyinit_C_initPhyConfig] Programming CalDrvStr0::CalDrvStrPu50 to 0x2
dwc_ddrphy_apb_wr(0x20050, 0x82); // DWC_DDRPHYA_MASTER0_base0_CalDrvStr0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming CalUclkInfo::CalUClkTicksPer1uS to 0x320
dwc_ddrphy_apb_wr(0x20008, 0x320); // DWC_DDRPHYA_MASTER0_base0_CalUclkInfo_p0
//// [phyinit_C_initPhyConfig] Programming CalRate::CalInterval to 0x9
//// [phyinit_C_initPhyConfig] Programming CalRate::CalOnce to 0x0
dwc_ddrphy_apb_wr(0x20088, 0x9); // DWC_DDRPHYA_MASTER0_base0_CalRate
//// [phyinit_C_initPhyConfig] Pstate=0, Programming VrefInGlobal::GlobalVrefInSel to 0x0
//// [phyinit_C_initPhyConfig] Pstate=0, Programming VrefInGlobal::GlobalVrefInDAC to 0x1f
//// [phyinit_C_initPhyConfig] Pstate=0, Programming VrefInGlobal to 0xf8
dwc_ddrphy_apb_wr(0x200b2, 0xf8); // DWC_DDRPHYA_MASTER0_base0_VrefInGlobal_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Programming DqDqsRcvCntrl (Byte=0, Upper/Lower=0) to 0x2500
dwc_ddrphy_apb_wr(0x10043, 0x2500); // DWC_DDRPHYA_DBYTE0_base0_DqDqsRcvCntrl_b0_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Programming DqDqsRcvCntrl (Byte=0, Upper/Lower=1) to 0x2500
dwc_ddrphy_apb_wr(0x10143, 0x2500); // DWC_DDRPHYA_DBYTE0_base0_DqDqsRcvCntrl_b1_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Programming DqDqsRcvCntrl (Byte=1, Upper/Lower=0) to 0x2500
dwc_ddrphy_apb_wr(0x11043, 0x2500); // DWC_DDRPHYA_DBYTE1_base0_DqDqsRcvCntrl_b0_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Programming DqDqsRcvCntrl (Byte=1, Upper/Lower=1) to 0x2500
dwc_ddrphy_apb_wr(0x11143, 0x2500); // DWC_DDRPHYA_DBYTE1_base0_DqDqsRcvCntrl_b1_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Programming DqDqsRcvCntrl2 to 0x1c
dwc_ddrphy_apb_wr(0x1004c, 0x1c); // DWC_DDRPHYA_DBYTE0_base0_DqDqsRcvCntrl2_p0
dwc_ddrphy_apb_wr(0x1104c, 0x1c); // DWC_DDRPHYA_DBYTE1_base0_DqDqsRcvCntrl2_p0
//// [phyinit_C_initPhyConfig] Programming ATxOdtDrvStren of ANIB_0 to 0x0
dwc_ddrphy_apb_wr(0x42, 0x0); // DWC_DDRPHYA_ANIB0_base0_ATxOdtDrvStren
//// [phyinit_C_initPhyConfig] Programming ATxOdtDrvStren of ANIB_0 to 0x0
dwc_ddrphy_apb_wr(0x42, 0x0); // DWC_DDRPHYA_ANIB0_base0_ATxOdtDrvStren
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming TristateModeCA::DisDynAdrTri_p0 to 0x0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming TristateModeCA::DDR2TMode_p0 to 0x0
dwc_ddrphy_apb_wr(0x20019, 0x4); // DWC_DDRPHYA_MASTER0_base0_TristateModeCA_p0
//// [phyinit_C_initPhyConfig] Programming DfiFreqXlat*
dwc_ddrphy_apb_wr(0x200f0, 0x5555); // DWC_DDRPHYA_MASTER0_base0_DfiFreqXlat0
dwc_ddrphy_apb_wr(0x200f1, 0x5555); // DWC_DDRPHYA_MASTER0_base0_DfiFreqXlat1
dwc_ddrphy_apb_wr(0x200f2, 0x5555); // DWC_DDRPHYA_MASTER0_base0_DfiFreqXlat2
dwc_ddrphy_apb_wr(0x200f3, 0x5555); // DWC_DDRPHYA_MASTER0_base0_DfiFreqXlat3
dwc_ddrphy_apb_wr(0x200f4, 0x5555); // DWC_DDRPHYA_MASTER0_base0_DfiFreqXlat4
dwc_ddrphy_apb_wr(0x200f5, 0x5555); // DWC_DDRPHYA_MASTER0_base0_DfiFreqXlat5
dwc_ddrphy_apb_wr(0x200f6, 0x5555); // DWC_DDRPHYA_MASTER0_base0_DfiFreqXlat6
dwc_ddrphy_apb_wr(0x200f7, 0xf000); // DWC_DDRPHYA_MASTER0_base0_DfiFreqXlat7
//// [phyinit_C_initPhyConfig] Pstate=0,  Memclk=1600MHz, Programming Seq0BDLY0 to 0x64
dwc_ddrphy_apb_wr(0x2000b, 0x64); // DWC_DDRPHYA_MASTER0_base0_Seq0BDLY0_p0
//// [phyinit_C_initPhyConfig] Pstate=0,  Memclk=1600MHz, Programming Seq0BDLY1 to 0xc8
dwc_ddrphy_apb_wr(0x2000c, 0xc8); // DWC_DDRPHYA_MASTER0_base0_Seq0BDLY1_p0
//// [phyinit_C_initPhyConfig] Pstate=0,  Memclk=1600MHz, Programming Seq0BDLY2 to 0x2bc
dwc_ddrphy_apb_wr(0x2000d, 0x2bc); // DWC_DDRPHYA_MASTER0_base0_Seq0BDLY2_p0
//// [phyinit_C_initPhyConfig] Pstate=0,  Memclk=1600MHz, Programming Seq0BDLY3 to 0x2c
dwc_ddrphy_apb_wr(0x2000e, 0x2c); // DWC_DDRPHYA_MASTER0_base0_Seq0BDLY3_p0
//// [phyinit_C_initPhyConfig] Disabling DBYTE 0 Lane 8 (DBI) Receiver to save power.
dwc_ddrphy_apb_wr(0x1004a, 0x500); // DWC_DDRPHYA_DBYTE0_base0_DqDqsRcvCntrl1
//// [phyinit_C_initPhyConfig] Disabling DBYTE 1 Lane 8 (DBI) Receiver to save power.
dwc_ddrphy_apb_wr(0x1104a, 0x500); // DWC_DDRPHYA_DBYTE1_base0_DqDqsRcvCntrl1
//// [phyinit_C_initPhyConfig] Programming MasterX4Config::X4TG to 0x0
dwc_ddrphy_apb_wr(0x20025, 0x0); // DWC_DDRPHYA_MASTER0_base0_MasterX4Config
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming GPR7(csrAlertRecovery) to 0x0
dwc_ddrphy_apb_wr(0x90307, 0x0); // DWC_DDRPHYA_INITENG0_base0_Seq0BGPR7_p0
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming DMIPinPresent::RdDbiEnabled to 0x0
dwc_ddrphy_apb_wr(0x2002d, 0x0); // DWC_DDRPHYA_MASTER0_base0_DMIPinPresent_p0
// [phyinit_C_initPhyConfig] Programming TimingModeCntrl::Dly64Prec to 0x0
dwc_ddrphy_apb_wr(0x20040, 0x0); // DWC_DDRPHYA_MASTER0_base0_TimingModeCntrl
// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming VREGCtrl3::VshCtrlUpdate to 0x1 for MASTER
dwc_ddrphy_apb_wr(0x20066, 0x1); // DWC_DDRPHYA_MASTER0_base0_VREGCtrl3
// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming VREGCtrl3::VshCtrlUpdate to 0x1 for all DBYTEs
dwc_ddrphy_apb_wr(0x10066, 0x1); // DWC_DDRPHYA_DBYTE0_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x11066, 0x1); // DWC_DDRPHYA_DBYTE1_base0_VREGCtrl3
// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming VREGCtrl3::VshCtrlUpdate to 0x1 for all ANIBs
dwc_ddrphy_apb_wr(0x66, 0x1); // DWC_DDRPHYA_ANIB0_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x1066, 0x1); // DWC_DDRPHYA_ANIB1_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x2066, 0x1); // DWC_DDRPHYA_ANIB2_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x3066, 0x1); // DWC_DDRPHYA_ANIB3_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x4066, 0x1); // DWC_DDRPHYA_ANIB4_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x5066, 0x1); // DWC_DDRPHYA_ANIB5_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x6066, 0x1); // DWC_DDRPHYA_ANIB6_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x7066, 0x1); // DWC_DDRPHYA_ANIB7_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x8066, 0x1); // DWC_DDRPHYA_ANIB8_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x9066, 0x1); // DWC_DDRPHYA_ANIB9_base0_VREGCtrl3
// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming AcClkDLLControl to 0x1080
dwc_ddrphy_apb_wr(0x200ea, 0x1080); // DWC_DDRPHYA_MASTER0_base0_AcClkDLLControl_p0
// [phyinit_C_initPhyConfig] Programming ArcPmuEccCtl to 0x1
dwc_ddrphy_apb_wr(0xc0086, 0x1); // DWC_DDRPHYA_DRTUB0_ArcPmuEccCtl
// [phyinit_C_initPhyConfig] Programming VREGCtrl2 to 0x9820 for MASTER
dwc_ddrphy_apb_wr(0x2002b, 0x9820); // DWC_DDRPHYA_MASTER0_base0_VREGCtrl2
// [phyinit_C_initPhyConfig] Programming VREGCtrl2 to 0x8020 for all DBYTEs
dwc_ddrphy_apb_wr(0x1002b, 0x8020); // DWC_DDRPHYA_DBYTE0_base0_VREGCtrl2
dwc_ddrphy_apb_wr(0x1102b, 0x8020); // DWC_DDRPHYA_DBYTE1_base0_VREGCtrl2
// [phyinit_C_initPhyConfig] Programming VREGCtrl2 to 0x8020 for all ANIBs
dwc_ddrphy_apb_wr(0x2b, 0x8020); // DWC_DDRPHYA_ANIB0_base0_VREGCtrl2
dwc_ddrphy_apb_wr(0x102b, 0x8020); // DWC_DDRPHYA_ANIB1_base0_VREGCtrl2
dwc_ddrphy_apb_wr(0x202b, 0x8020); // DWC_DDRPHYA_ANIB2_base0_VREGCtrl2
dwc_ddrphy_apb_wr(0x302b, 0x8020); // DWC_DDRPHYA_ANIB3_base0_VREGCtrl2
dwc_ddrphy_apb_wr(0x402b, 0x8020); // DWC_DDRPHYA_ANIB4_base0_VREGCtrl2
dwc_ddrphy_apb_wr(0x502b, 0x8020); // DWC_DDRPHYA_ANIB5_base0_VREGCtrl2
dwc_ddrphy_apb_wr(0x602b, 0x8020); // DWC_DDRPHYA_ANIB6_base0_VREGCtrl2
dwc_ddrphy_apb_wr(0x702b, 0x8020); // DWC_DDRPHYA_ANIB7_base0_VREGCtrl2
dwc_ddrphy_apb_wr(0x802b, 0x8020); // DWC_DDRPHYA_ANIB8_base0_VREGCtrl2
dwc_ddrphy_apb_wr(0x902b, 0x8020); // DWC_DDRPHYA_ANIB9_base0_VREGCtrl2
// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming VREGCtrl3::VshCtrlUpdate to 0x0 for MASTER
dwc_ddrphy_apb_wr(0x20066, 0x0); // DWC_DDRPHYA_MASTER0_base0_VREGCtrl3
// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming VREGCtrl3::VshCtrlUpdate to 0x0 for all DBYTEs
dwc_ddrphy_apb_wr(0x10066, 0x0); // DWC_DDRPHYA_DBYTE0_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x11066, 0x0); // DWC_DDRPHYA_DBYTE1_base0_VREGCtrl3
// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming VREGCtrl3::VshCtrlUpdate to 0x0 for all ANIBs
dwc_ddrphy_apb_wr(0x66, 0x0); // DWC_DDRPHYA_ANIB0_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x1066, 0x0); // DWC_DDRPHYA_ANIB1_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x2066, 0x0); // DWC_DDRPHYA_ANIB2_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x3066, 0x0); // DWC_DDRPHYA_ANIB3_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x4066, 0x0); // DWC_DDRPHYA_ANIB4_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x5066, 0x0); // DWC_DDRPHYA_ANIB5_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x6066, 0x0); // DWC_DDRPHYA_ANIB6_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x7066, 0x0); // DWC_DDRPHYA_ANIB7_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x8066, 0x0); // DWC_DDRPHYA_ANIB8_base0_VREGCtrl3
dwc_ddrphy_apb_wr(0x9066, 0x0); // DWC_DDRPHYA_ANIB9_base0_VREGCtrl3
// [phyinit_C_initPhyConfig] Programming VrefDAC0 to 0x3f for all DBYTEs and lanes
// [phyinit_C_initPhyConfig] Programming VrefDAC1 to 0x3f for all DBYTEs and lanes
// [phyinit_C_initPhyConfig] Programming VrefDAC2 to 0x3f for all DBYTEs and lanes
// [phyinit_C_initPhyConfig] Programming VrefDAC3 to 0x3f for all DBYTEs and lanes
dwc_ddrphy_apb_wr(0x10040, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC0_r0_p0
dwc_ddrphy_apb_wr(0x10030, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC1_r0
dwc_ddrphy_apb_wr(0x10050, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC2_r0
dwc_ddrphy_apb_wr(0x10060, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC3_r0
dwc_ddrphy_apb_wr(0x10140, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC0_r1_p0
dwc_ddrphy_apb_wr(0x10130, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC1_r1
dwc_ddrphy_apb_wr(0x10150, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC2_r1
dwc_ddrphy_apb_wr(0x10160, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC3_r1
dwc_ddrphy_apb_wr(0x10240, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC0_r2_p0
dwc_ddrphy_apb_wr(0x10230, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC1_r2
dwc_ddrphy_apb_wr(0x10250, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC2_r2
dwc_ddrphy_apb_wr(0x10260, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC3_r2
dwc_ddrphy_apb_wr(0x10340, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC0_r3_p0
dwc_ddrphy_apb_wr(0x10330, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC1_r3
dwc_ddrphy_apb_wr(0x10350, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC2_r3
dwc_ddrphy_apb_wr(0x10360, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC3_r3
dwc_ddrphy_apb_wr(0x10440, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC0_r4_p0
dwc_ddrphy_apb_wr(0x10430, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC1_r4
dwc_ddrphy_apb_wr(0x10450, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC2_r4
dwc_ddrphy_apb_wr(0x10460, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC3_r4
dwc_ddrphy_apb_wr(0x10540, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC0_r5_p0
dwc_ddrphy_apb_wr(0x10530, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC1_r5
dwc_ddrphy_apb_wr(0x10550, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC2_r5
dwc_ddrphy_apb_wr(0x10560, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC3_r5
dwc_ddrphy_apb_wr(0x10640, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC0_r6_p0
dwc_ddrphy_apb_wr(0x10630, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC1_r6
dwc_ddrphy_apb_wr(0x10650, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC2_r6
dwc_ddrphy_apb_wr(0x10660, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC3_r6
dwc_ddrphy_apb_wr(0x10740, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC0_r7_p0
dwc_ddrphy_apb_wr(0x10730, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC1_r7
dwc_ddrphy_apb_wr(0x10750, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC2_r7
dwc_ddrphy_apb_wr(0x10760, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC3_r7
dwc_ddrphy_apb_wr(0x10840, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC0_r8_p0
dwc_ddrphy_apb_wr(0x10830, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC1_r8
dwc_ddrphy_apb_wr(0x10850, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC2_r8
dwc_ddrphy_apb_wr(0x10860, 0x3f); // DWC_DDRPHYA_DBYTE0_base0_VrefDAC3_r8
dwc_ddrphy_apb_wr(0x11040, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC0_r0_p0
dwc_ddrphy_apb_wr(0x11030, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC1_r0
dwc_ddrphy_apb_wr(0x11050, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC2_r0
dwc_ddrphy_apb_wr(0x11060, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC3_r0
dwc_ddrphy_apb_wr(0x11140, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC0_r1_p0
dwc_ddrphy_apb_wr(0x11130, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC1_r1
dwc_ddrphy_apb_wr(0x11150, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC2_r1
dwc_ddrphy_apb_wr(0x11160, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC3_r1
dwc_ddrphy_apb_wr(0x11240, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC0_r2_p0
dwc_ddrphy_apb_wr(0x11230, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC1_r2
dwc_ddrphy_apb_wr(0x11250, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC2_r2
dwc_ddrphy_apb_wr(0x11260, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC3_r2
dwc_ddrphy_apb_wr(0x11340, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC0_r3_p0
dwc_ddrphy_apb_wr(0x11330, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC1_r3
dwc_ddrphy_apb_wr(0x11350, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC2_r3
dwc_ddrphy_apb_wr(0x11360, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC3_r3
dwc_ddrphy_apb_wr(0x11440, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC0_r4_p0
dwc_ddrphy_apb_wr(0x11430, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC1_r4
dwc_ddrphy_apb_wr(0x11450, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC2_r4
dwc_ddrphy_apb_wr(0x11460, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC3_r4
dwc_ddrphy_apb_wr(0x11540, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC0_r5_p0
dwc_ddrphy_apb_wr(0x11530, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC1_r5
dwc_ddrphy_apb_wr(0x11550, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC2_r5
dwc_ddrphy_apb_wr(0x11560, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC3_r5
dwc_ddrphy_apb_wr(0x11640, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC0_r6_p0
dwc_ddrphy_apb_wr(0x11630, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC1_r6
dwc_ddrphy_apb_wr(0x11650, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC2_r6
dwc_ddrphy_apb_wr(0x11660, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC3_r6
dwc_ddrphy_apb_wr(0x11740, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC0_r7_p0
dwc_ddrphy_apb_wr(0x11730, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC1_r7
dwc_ddrphy_apb_wr(0x11750, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC2_r7
dwc_ddrphy_apb_wr(0x11760, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC3_r7
dwc_ddrphy_apb_wr(0x11840, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC0_r8_p0
dwc_ddrphy_apb_wr(0x11830, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC1_r8
dwc_ddrphy_apb_wr(0x11850, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC2_r8
dwc_ddrphy_apb_wr(0x11860, 0x3f); // DWC_DDRPHYA_DBYTE1_base0_VrefDAC3_r8
//// [phyinit_C_initPhyConfig] Pstate=0, Memclk=1600MHz, Programming DfiFreqRatio_p0 to 0x1
dwc_ddrphy_apb_wr(0x200fa, 0x1); // DWC_DDRPHYA_MASTER0_base0_DfiFreqRatio_p0
//// [phyinit_C_initPhyConfig] Programming ForceClkGaterEnables::ForcePubDxClkEnLow to 0x0
dwc_ddrphy_apb_wr(0x200a6, 0x0); // DWC_DDRPHYA_MASTER0_base0_ForceClkGaterEnables
//// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=0) to 0xc
dwc_ddrphy_apb_wr(0x28, 0xc); // DWC_DDRPHYA_ANIB0_base0_AForceTriCont
//// [phyinit_C_initPhyConfig] End of dwc_ddrphy_phyinit_C_initPhyConfig()
//
//
////##############################################################
////
//// dwc_ddrphy_phyinit_userCustom_customPreTrain is a user-editable function.
////
//// The purpose of dwc_ddrphy_phyinit_userCustom_customPreTrain() is to override any
//// any message block fields calculated by Phyinit in dwc_ddrphy_phyinit_calcMb() or to
//// override any CSR values programmed by Phyinit in dwc_ddrphy_phyinit_C_initPhyConfig().
//// This function is executed before training and thus any override here might affect
//// training result.
////
//// IMPORTANT: in this function, user shall not override any values in userInputBasic and
//// userInputAdvanced data structures. Use dwc_ddrphy_phyinit_userCustom_overrideUserInput()
//// to modify values in those data structures.
////
////##############################################################
//
//// [phyinit_userCustom_customPreTrain] Start of dwc_ddrphy_phyinit_userCustom_customPreTrain()
//// [phyinit_userCustom_customPreTrain] End of dwc_ddrphy_phyinit_userCustom_customPreTrain()
//// [dwc_ddrphy_phyinit_D_loadIMEM, 1D] Start of dwc_ddrphy_phyinit_D_loadIMEM (Train2D=0)
//
//
////##############################################################
////
//// (D) Load the 1D IMEM image
////
//// This function loads the training firmware IMEM image into the SRAM.
//// See PhyInit App Note for detailed description and function usage
////
////##############################################################
//
//
//// [dwc_ddrphy_phyinit_D_loadIMEM, 1D] Programming MemResetL to 0x2
dwc_ddrphy_apb_wr(0x20060, 0x2); // DWC_DDRPHYA_MASTER0_base0_MemResetL
// [dwc_ddrphy_phyinit_storeIncvFile] Reading input file: /home/jerry_ku/Project/Development/ast2700dev/ddr45phy_tsmc12/coreConsultant/config3_3.50a/2022-12-12-16-52-55/firmware/Latest/training/ddr4/ddr4_pmu_train_imem.incv

//// 1.	Enable access to the internal CSRs by setting the MicroContMuxSel CSR to 0.
////	   This allows the memory controller unrestricted access to the configuration CSRs.
dwc_ddrphy_apb_wr(0xd0000, 0x0); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
//// [dwc_ddrphy_phyinit_WriteOutMem] STARTING 32bit write. offset 0x50000 size 0x8000
//#ifdef TRAIN_LOADBIN
#if defined(CONFIG_DDR_PHY_TRAINING)
dwc_ddrphy_phyinit_userCustom_D_loadIMEM(0);
#else
dwc_ddrphy_apb_wr_32b(0x50000, 0x98);
dwc_ddrphy_apb_wr_32b(0x50002, 0x50);
dwc_ddrphy_apb_wr_32b(0x50004, 0x50);
dwc_ddrphy_apb_wr_32b(0x50006, 0x50);
dwc_ddrphy_apb_wr_32b(0x50008, 0x50);
dwc_ddrphy_apb_wr_32b(0x5000a, 0x50);
dwc_ddrphy_apb_wr_32b(0x5000c, 0x50);
dwc_ddrphy_apb_wr_32b(0x5000e, 0x50);
dwc_ddrphy_apb_wr_32b(0x50010, 0x50);
dwc_ddrphy_apb_wr_32b(0x50012, 0x50);
dwc_ddrphy_apb_wr_32b(0x50014, 0x50);
dwc_ddrphy_apb_wr_32b(0x50016, 0x50);
dwc_ddrphy_apb_wr_32b(0x50018, 0x50);
dwc_ddrphy_apb_wr_32b(0x5001a, 0x50);
dwc_ddrphy_apb_wr_32b(0x5001c, 0x50);
dwc_ddrphy_apb_wr_32b(0x5001e, 0x50);
dwc_ddrphy_apb_wr_32b(0x50020, 0x50);
dwc_ddrphy_apb_wr_32b(0x50022, 0x50);
dwc_ddrphy_apb_wr_32b(0x50024, 0x50);
dwc_ddrphy_apb_wr_32b(0x50026, 0x50);
dwc_ddrphy_apb_wr_32b(0x50028, 0x402069);
dwc_ddrphy_apb_wr_32b(0x5002a, 0x7000264a);
dwc_ddrphy_apb_wr_32b(0x5002c, 0x7000264a);
dwc_ddrphy_apb_wr_32b(0x5002e, 0x7000264a);
dwc_ddrphy_apb_wr_32b(0x50030, 0x0);
dwc_ddrphy_apb_wr_32b(0x50032, 0x0);
dwc_ddrphy_apb_wr_32b(0x50034, 0x0);
dwc_ddrphy_apb_wr_32b(0x50036, 0x0);
dwc_ddrphy_apb_wr_32b(0x50038, 0x0);
dwc_ddrphy_apb_wr_32b(0x5003a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5003c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5003e, 0x0);
dwc_ddrphy_apb_wr_32b(0x50040, 0x7ce07054);
dwc_ddrphy_apb_wr_32b(0x50042, 0x230a);
dwc_ddrphy_apb_wr_32b(0x50044, 0x48c1101);
dwc_ddrphy_apb_wr_32b(0x50046, 0x80422242);
dwc_ddrphy_apb_wr_32b(0x50048, 0x3121b01);
dwc_ddrphy_apb_wr_32b(0x5004a, 0x7ee0f5fa);
dwc_ddrphy_apb_wr_32b(0x5004c, 0x702c700c);
dwc_ddrphy_apb_wr_32b(0x5004e, 0x706c704c);
dwc_ddrphy_apb_wr_32b(0x50050, 0x706d704d);
dwc_ddrphy_apb_wr_32b(0x50052, 0x70ad708d);
dwc_ddrphy_apb_wr_32b(0x50054, 0x70ed70cd);
dwc_ddrphy_apb_wr_32b(0x50056, 0x706f704f);
dwc_ddrphy_apb_wr_32b(0x50058, 0x254a708f);
dwc_ddrphy_apb_wr_32b(0x5005a, 0x264a3000);
dwc_ddrphy_apb_wr_32b(0x5005c, 0x70ef3000);
dwc_ddrphy_apb_wr_32b(0x5005e, 0x280206a);
dwc_ddrphy_apb_wr_32b(0x50060, 0x2029b88d);
dwc_ddrphy_apb_wr_32b(0x50062, 0x44db8000);
dwc_ddrphy_apb_wr_32b(0x50064, 0x8001);
dwc_ddrphy_apb_wr_32b(0x50066, 0x800042db);
dwc_ddrphy_apb_wr_32b(0x50068, 0x706f0400);
dwc_ddrphy_apb_wr_32b(0x5006a, 0xf802022);
dwc_ddrphy_apb_wr_32b(0x5006c, 0x22c00000);
dwc_ddrphy_apb_wr_32b(0x5006e, 0x402069);
dwc_ddrphy_apb_wr_32b(0x50070, 0xf1fe78e0);
dwc_ddrphy_apb_wr_32b(0x50072, 0xc2e1c3e1);
dwc_ddrphy_apb_wr_32b(0x50074, 0xc0e1c1e1);
dwc_ddrphy_apb_wr_32b(0x50076, 0xb7c81cf8);
dwc_ddrphy_apb_wr_32b(0x50078, 0x1408e805);
dwc_ddrphy_apb_wr_32b(0x5007a, 0x7fe0341f);
dwc_ddrphy_apb_wr_32b(0x5007c, 0x40c3c0a4);
dwc_ddrphy_apb_wr_32b(0x5007e, 0x9888000);
dwc_ddrphy_apb_wr_32b(0x50080, 0x80f8000);
dwc_ddrphy_apb_wr_32b(0x50082, 0x714c0233);
dwc_ddrphy_apb_wr_32b(0x50084, 0x2a00);
dwc_ddrphy_apb_wr_32b(0x50086, 0x1600f005);
dwc_ddrphy_apb_wr_32b(0x50088, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x5008a, 0x226f0010);
dwc_ddrphy_apb_wr_32b(0x5008c, 0xaa000a43);
dwc_ddrphy_apb_wr_32b(0x5008e, 0x208c8a04);
dwc_ddrphy_apb_wr_32b(0x50090, 0xf20d8fc3);
dwc_ddrphy_apb_wr_32b(0x50092, 0xc041c084);
dwc_ddrphy_apb_wr_32b(0x50094, 0xb9a4020);
dwc_ddrphy_apb_wr_32b(0x50096, 0xc18402a0);
dwc_ddrphy_apb_wr_32b(0x50098, 0xd8ff702c);
dwc_ddrphy_apb_wr_32b(0x5009a, 0xa00da2);
dwc_ddrphy_apb_wr_32b(0x5009c, 0xb2ab99a);
dwc_ddrphy_apb_wr_32b(0x5009e, 0xd8ff02a0);
dwc_ddrphy_apb_wr_32b(0x500a0, 0x20ab700c);
dwc_ddrphy_apb_wr_32b(0x500a2, 0x7fff00c4);
dwc_ddrphy_apb_wr_32b(0x500a4, 0x78e0f1ff);
dwc_ddrphy_apb_wr_32b(0x500a6, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x500a8, 0x2482b6c8);
dwc_ddrphy_apb_wr_32b(0x500aa, 0x16003e03);
dwc_ddrphy_apb_wr_32b(0x500ac, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x500ae, 0xc0530004);
dwc_ddrphy_apb_wr_32b(0x500b0, 0x710d1600);
dwc_ddrphy_apb_wr_32b(0x500b2, 0x809004);
dwc_ddrphy_apb_wr_32b(0x500b4, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x500b6, 0x3fe8000);
dwc_ddrphy_apb_wr_32b(0x500b8, 0xb16c05b);
dwc_ddrphy_apb_wr_32b(0x500ba, 0x760c0120);
dwc_ddrphy_apb_wr_32b(0x500bc, 0xb0e4608);
dwc_ddrphy_apb_wr_32b(0x500be, 0xd80f0120);
dwc_ddrphy_apb_wr_32b(0x500c0, 0x71011600);
dwc_ddrphy_apb_wr_32b(0x500c2, 0x3fe9004);
dwc_ddrphy_apb_wr_32b(0x500c4, 0x30401c90);
dwc_ddrphy_apb_wr_32b(0x500c6, 0x71011600);
dwc_ddrphy_apb_wr_32b(0x500c8, 0xe1d29009);
dwc_ddrphy_apb_wr_32b(0x500ca, 0x30401c9c);
dwc_ddrphy_apb_wr_32b(0x500cc, 0xc1216c);
dwc_ddrphy_apb_wr_32b(0x500ce, 0x1e00c15c);
dwc_ddrphy_apb_wr_32b(0x500d0, 0x90097044);
dwc_ddrphy_apb_wr_32b(0x500d2, 0x1600e1d2);
dwc_ddrphy_apb_wr_32b(0x500d4, 0x90047101);
dwc_ddrphy_apb_wr_32b(0x500d6, 0x1c9800f4);
dwc_ddrphy_apb_wr_32b(0x500d8, 0xb98c3040);
dwc_ddrphy_apb_wr_32b(0x500da, 0x70441e00);
dwc_ddrphy_apb_wr_32b(0x500dc, 0xf49004);
dwc_ddrphy_apb_wr_32b(0x500de, 0x71011600);
dwc_ddrphy_apb_wr_32b(0x500e0, 0xfc9004);
dwc_ddrphy_apb_wr_32b(0x500e2, 0x120ec14e);
dwc_ddrphy_apb_wr_32b(0x500e4, 0x218c3701);
dwc_ddrphy_apb_wr_32b(0x500e6, 0xf421800c);
dwc_ddrphy_apb_wr_32b(0x500e8, 0x3701120d);
dwc_ddrphy_apb_wr_32b(0x500ea, 0x101216c);
dwc_ddrphy_apb_wr_32b(0x500ec, 0x8110937);
dwc_ddrphy_apb_wr_32b(0x500ee, 0x71011600);
dwc_ddrphy_apb_wr_32b(0x500f0, 0x1009004);
dwc_ddrphy_apb_wr_32b(0x500f2, 0x3e092b);
dwc_ddrphy_apb_wr_32b(0x500f4, 0x41c3da24);
dwc_ddrphy_apb_wr_32b(0x500f6, 0x4908000);
dwc_ddrphy_apb_wr_32b(0x500f8, 0xda22a150);
dwc_ddrphy_apb_wr_32b(0x500fa, 0xda23a14f);
dwc_ddrphy_apb_wr_32b(0x500fc, 0xda20a14e);
dwc_ddrphy_apb_wr_32b(0x500fe, 0xda21a14a);
dwc_ddrphy_apb_wr_32b(0x50100, 0x7011958);
dwc_ddrphy_apb_wr_32b(0x50102, 0x7c11954);
dwc_ddrphy_apb_wr_32b(0x50104, 0x7811934);
dwc_ddrphy_apb_wr_32b(0x50106, 0xc11ba140);
dwc_ddrphy_apb_wr_32b(0x50108, 0x1600661e);
dwc_ddrphy_apb_wr_32b(0x5010a, 0x80007102);
dwc_ddrphy_apb_wr_32b(0x5010c, 0x16000006);
dwc_ddrphy_apb_wr_32b(0x5010e, 0x80007100);
dwc_ddrphy_apb_wr_32b(0x50110, 0x216d089e);
dwc_ddrphy_apb_wr_32b(0x50112, 0x206c0901);
dwc_ddrphy_apb_wr_32b(0x50114, 0x716f0080);
dwc_ddrphy_apb_wr_32b(0x50116, 0xf840a11);
dwc_ddrphy_apb_wr_32b(0x50118, 0xb750000);
dwc_ddrphy_apb_wr_32b(0x5011a, 0xc02045);
dwc_ddrphy_apb_wr_32b(0x5011c, 0xf00c7a10);
dwc_ddrphy_apb_wr_32b(0x5011e, 0xa117810);
dwc_ddrphy_apb_wr_32b(0x50120, 0xf84);
dwc_ddrphy_apb_wr_32b(0x50122, 0x204f0960);
dwc_ddrphy_apb_wr_32b(0x50124, 0xf0040042);
dwc_ddrphy_apb_wr_32b(0x50126, 0x2204f);
dwc_ddrphy_apb_wr_32b(0x50128, 0xb88c700c);
dwc_ddrphy_apb_wr_32b(0x5012a, 0x2b00c050);
dwc_ddrphy_apb_wr_32b(0x5012c, 0xc04c3040);
dwc_ddrphy_apb_wr_32b(0x5012e, 0x18402655);
dwc_ddrphy_apb_wr_32b(0x50130, 0x2544c05f);
dwc_ddrphy_apb_wr_32b(0x50132, 0xc0451040);
dwc_ddrphy_apb_wr_32b(0x50134, 0x70adc013);
dwc_ddrphy_apb_wr_32b(0x50136, 0x24e224f);
dwc_ddrphy_apb_wr_32b(0x50138, 0xc049b814);
dwc_ddrphy_apb_wr_32b(0x5013a, 0x70051e00);
dwc_ddrphy_apb_wr_32b(0x5013c, 0x3fe9004);
dwc_ddrphy_apb_wr_32b(0x5013e, 0x11350d35);
dwc_ddrphy_apb_wr_32b(0x50140, 0x334f2b00);
dwc_ddrphy_apb_wr_32b(0x50142, 0xba27aef);
dwc_ddrphy_apb_wr_32b(0x50144, 0x40400260);
dwc_ddrphy_apb_wr_32b(0x50146, 0x40c1e890);
dwc_ddrphy_apb_wr_32b(0x50148, 0x2600802);
dwc_ddrphy_apb_wr_32b(0x5014a, 0x16004140);
dwc_ddrphy_apb_wr_32b(0x5014c, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x5014e, 0x8110001);
dwc_ddrphy_apb_wr_32b(0x50150, 0x78fb01be);
dwc_ddrphy_apb_wr_32b(0x50152, 0xfee790f);
dwc_ddrphy_apb_wr_32b(0x50154, 0x40c10220);
dwc_ddrphy_apb_wr_32b(0x50156, 0xf1e871a5);
dwc_ddrphy_apb_wr_32b(0x50158, 0xc04dc009);
dwc_ddrphy_apb_wr_32b(0x5015a, 0x1422085);
dwc_ddrphy_apb_wr_32b(0x5015c, 0xe009b2);
dwc_ddrphy_apb_wr_32b(0x5015e, 0xc051c04d);
dwc_ddrphy_apb_wr_32b(0x50160, 0xa01209a);
dwc_ddrphy_apb_wr_32b(0x50162, 0x70c370cd);
dwc_ddrphy_apb_wr_32b(0x50164, 0x4288000);
dwc_ddrphy_apb_wr_32b(0x50166, 0x2a44804f);
dwc_ddrphy_apb_wr_32b(0x50168, 0xc05a0100);
dwc_ddrphy_apb_wr_32b(0x5016a, 0xc00dc11a);
dwc_ddrphy_apb_wr_32b(0x5016c, 0x7825b90c);
dwc_ddrphy_apb_wr_32b(0x5016e, 0xb89c781b);
dwc_ddrphy_apb_wr_32b(0x50170, 0xc05db89f);
dwc_ddrphy_apb_wr_32b(0x50172, 0x1ca09000);
dwc_ddrphy_apb_wr_32b(0x50174, 0x22443000);
dwc_ddrphy_apb_wr_32b(0x50176, 0x1c948080);
dwc_ddrphy_apb_wr_32b(0x50178, 0xd8803000);
dwc_ddrphy_apb_wr_32b(0x5017a, 0xc046da7f);
dwc_ddrphy_apb_wr_32b(0x5017c, 0x122ca);
dwc_ddrphy_apb_wr_32b(0x5017e, 0x7825c009);
dwc_ddrphy_apb_wr_32b(0x50180, 0x785b7a05);
dwc_ddrphy_apb_wr_32b(0x50182, 0xb89fb89c);
dwc_ddrphy_apb_wr_32b(0x50184, 0x9000c056);
dwc_ddrphy_apb_wr_32b(0x50186, 0x1ca4702c);
dwc_ddrphy_apb_wr_32b(0x50188, 0x95f3000);
dwc_ddrphy_apb_wr_32b(0x5018a, 0xc0110115);
dwc_ddrphy_apb_wr_32b(0x5018c, 0x2015b804);
dwc_ddrphy_apb_wr_32b(0x5018e, 0x40c30042);
dwc_ddrphy_apb_wr_32b(0x50190, 0x56c8000);
dwc_ddrphy_apb_wr_32b(0x50192, 0xa476202);
dwc_ddrphy_apb_wr_32b(0x50194, 0x2a400032);
dwc_ddrphy_apb_wr_32b(0x50196, 0x206c0280);
dwc_ddrphy_apb_wr_32b(0x50198, 0xc00d02c3);
dwc_ddrphy_apb_wr_32b(0x5019a, 0x3e8c2455);
dwc_ddrphy_apb_wr_32b(0x5019c, 0x78657c34);
dwc_ddrphy_apb_wr_32b(0x5019e, 0xb89c781b);
dwc_ddrphy_apb_wr_32b(0x501a0, 0x90a0b89f);
dwc_ddrphy_apb_wr_32b(0x501a2, 0xda7fbae1);
dwc_ddrphy_apb_wr_32b(0x501a4, 0x1800b4a0);
dwc_ddrphy_apb_wr_32b(0x501a6, 0xd8800085);
dwc_ddrphy_apb_wr_32b(0x501a8, 0x122ca);
dwc_ddrphy_apb_wr_32b(0x501aa, 0x7865c009);
dwc_ddrphy_apb_wr_32b(0x501ac, 0x781b7845);
dwc_ddrphy_apb_wr_32b(0x501ae, 0xb89fb89c);
dwc_ddrphy_apb_wr_32b(0x501b0, 0x24559040);
dwc_ddrphy_apb_wr_32b(0x501b2, 0x78343f00);
dwc_ddrphy_apb_wr_32b(0x501b4, 0x7124b040);
dwc_ddrphy_apb_wr_32b(0x501b6, 0x702cf1d3);
dwc_ddrphy_apb_wr_32b(0x501b8, 0x735091d);
dwc_ddrphy_apb_wr_32b(0x501ba, 0x42c3700c);
dwc_ddrphy_apb_wr_32b(0x501bc, 0x86c8000);
dwc_ddrphy_apb_wr_32b(0x501be, 0xb88c7a35);
dwc_ddrphy_apb_wr_32b(0x501c0, 0x7813a20e);
dwc_ddrphy_apb_wr_32b(0x501c2, 0x1aa8);
dwc_ddrphy_apb_wr_32b(0x501c4, 0xf1f47124);
dwc_ddrphy_apb_wr_32b(0x501c6, 0xc106c005);
dwc_ddrphy_apb_wr_32b(0x501c8, 0xd8407014);
dwc_ddrphy_apb_wr_32b(0x501ca, 0x121ca);
dwc_ddrphy_apb_wr_32b(0x501cc, 0xc006c146);
dwc_ddrphy_apb_wr_32b(0x501ce, 0xc0205f);
dwc_ddrphy_apb_wr_32b(0x501d0, 0x30001cb4);
dwc_ddrphy_apb_wr_32b(0x501d2, 0x781bc006);
dwc_ddrphy_apb_wr_32b(0x501d4, 0x30001c8c);
dwc_ddrphy_apb_wr_32b(0x501d6, 0xc0527704);
dwc_ddrphy_apb_wr_32b(0x501d8, 0xc055700c);
dwc_ddrphy_apb_wr_32b(0x501da, 0x52ae69a);
dwc_ddrphy_apb_wr_32b(0x501dc, 0x70ed0026);
dwc_ddrphy_apb_wr_32b(0x501de, 0x40c3c111);
dwc_ddrphy_apb_wr_32b(0x501e0, 0x4288000);
dwc_ddrphy_apb_wr_32b(0x501e2, 0xa01219a);
dwc_ddrphy_apb_wr_32b(0x501e4, 0x610179d5);
dwc_ddrphy_apb_wr_32b(0x501e6, 0x2944c00d);
dwc_ddrphy_apb_wr_32b(0x501e8, 0xb9e10102);
dwc_ddrphy_apb_wr_32b(0x501ea, 0xba0cd97f);
dwc_ddrphy_apb_wr_32b(0x501ec, 0x781b7845);
dwc_ddrphy_apb_wr_32b(0x501ee, 0xb89fb89c);
dwc_ddrphy_apb_wr_32b(0x501f0, 0x9000c05e);
dwc_ddrphy_apb_wr_32b(0x501f2, 0x30001ca8);
dwc_ddrphy_apb_wr_32b(0x501f4, 0x1800c01e);
dwc_ddrphy_apb_wr_32b(0x501f6, 0xd8800085);
dwc_ddrphy_apb_wr_32b(0x501f8, 0x121ca);
dwc_ddrphy_apb_wr_32b(0x501fa, 0xe68dc009);
dwc_ddrphy_apb_wr_32b(0x501fc, 0x78257845);
dwc_ddrphy_apb_wr_32b(0x501fe, 0xb89c781b);
dwc_ddrphy_apb_wr_32b(0x50200, 0xc059b89f);
dwc_ddrphy_apb_wr_32b(0x50202, 0x1cac9000);
dwc_ddrphy_apb_wr_32b(0x50204, 0xd80f3000);
dwc_ddrphy_apb_wr_32b(0x50206, 0x2d040c);
dwc_ddrphy_apb_wr_32b(0x50208, 0x30001c80);
dwc_ddrphy_apb_wr_32b(0x5020a, 0x78d8710c);
dwc_ddrphy_apb_wr_32b(0x5020c, 0x750cc054);
dwc_ddrphy_apb_wr_32b(0x5020e, 0x706fc048);
dwc_ddrphy_apb_wr_32b(0x50210, 0x4527377);
dwc_ddrphy_apb_wr_32b(0x50212, 0x710c002d);
dwc_ddrphy_apb_wr_32b(0x50214, 0x6c32800);
dwc_ddrphy_apb_wr_32b(0x50216, 0x9c3206f);
dwc_ddrphy_apb_wr_32b(0x50218, 0x10598820);
dwc_ddrphy_apb_wr_32b(0x5021a, 0xc64f008d);
dwc_ddrphy_apb_wr_32b(0x5021c, 0xf213796b);
dwc_ddrphy_apb_wr_32b(0x5021e, 0x8236e0b);
dwc_ddrphy_apb_wr_32b(0x50220, 0xc64f05b5);
dwc_ddrphy_apb_wr_32b(0x50222, 0x70012e01);
dwc_ddrphy_apb_wr_32b(0x50224, 0x53f003c);
dwc_ddrphy_apb_wr_32b(0x50226, 0x3e0913);
dwc_ddrphy_apb_wr_32b(0x50228, 0x41c3c64f);
dwc_ddrphy_apb_wr_32b(0x5022a, 0x56c8000);
dwc_ddrphy_apb_wr_32b(0x5022c, 0x810c7915);
dwc_ddrphy_apb_wr_32b(0x5022e, 0x7f6fc04f);
dwc_ddrphy_apb_wr_32b(0x50230, 0x26009c6);
dwc_ddrphy_apb_wr_32b(0x50232, 0x701440e1);
dwc_ddrphy_apb_wr_32b(0x50234, 0x2203aa);
dwc_ddrphy_apb_wr_32b(0x50236, 0x3b802455);
dwc_ddrphy_apb_wr_32b(0x50238, 0x8e6702c);
dwc_ddrphy_apb_wr_32b(0x5023a, 0xda300160);
dwc_ddrphy_apb_wr_32b(0x5023c, 0xf2087bab);
dwc_ddrphy_apb_wr_32b(0x5023e, 0x396e698);
dwc_ddrphy_apb_wr_32b(0x50240, 0xc00e0001);
dwc_ddrphy_apb_wr_32b(0x50242, 0xf007b88c);
dwc_ddrphy_apb_wr_32b(0x50244, 0x2004c00e);
dwc_ddrphy_apb_wr_32b(0x50246, 0xf80);
dwc_ddrphy_apb_wr_32b(0x50248, 0x1e00efff);
dwc_ddrphy_apb_wr_32b(0x5024a, 0x90047004);
dwc_ddrphy_apb_wr_32b(0x5024c, 0x700c00fc);
dwc_ddrphy_apb_wr_32b(0x5024e, 0x996d9ff);
dwc_ddrphy_apb_wr_32b(0x50250, 0x70ad0060);
dwc_ddrphy_apb_wr_32b(0x50252, 0x30831200);
dwc_ddrphy_apb_wr_32b(0x50254, 0x40084a);
dwc_ddrphy_apb_wr_32b(0x50256, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x50258, 0x33c11c04);
dwc_ddrphy_apb_wr_32b(0x5025a, 0x600a56);
dwc_ddrphy_apb_wr_32b(0x5025c, 0xd8ffc540);
dwc_ddrphy_apb_wr_32b(0x5025e, 0x754c702c);
dwc_ddrphy_apb_wr_32b(0x50260, 0x1c0c726c);
dwc_ddrphy_apb_wr_32b(0x50262, 0xc54231c1);
dwc_ddrphy_apb_wr_32b(0x50264, 0x33c11c04);
dwc_ddrphy_apb_wr_32b(0x50266, 0x600a3e);
dwc_ddrphy_apb_wr_32b(0x50268, 0x1480c540);
dwc_ddrphy_apb_wr_32b(0x5026a, 0xc2083000);
dwc_ddrphy_apb_wr_32b(0x5026c, 0xc014790f);
dwc_ddrphy_apb_wr_32b(0x5026e, 0x710a17);
dwc_ddrphy_apb_wr_32b(0x50270, 0xc5437810);
dwc_ddrphy_apb_wr_32b(0x50272, 0xc141c742);
dwc_ddrphy_apb_wr_32b(0x50274, 0xd8ffc040);
dwc_ddrphy_apb_wr_32b(0x50276, 0x714cd90c);
dwc_ddrphy_apb_wr_32b(0x50278, 0xc208f008);
dwc_ddrphy_apb_wr_32b(0x5027a, 0xc040c141);
dwc_ddrphy_apb_wr_32b(0x5027c, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x5027e, 0xc742c543);
dwc_ddrphy_apb_wr_32b(0x50280, 0x600a0a);
dwc_ddrphy_apb_wr_32b(0x50282, 0x700c726c);
dwc_ddrphy_apb_wr_32b(0x50284, 0x30001c88);
dwc_ddrphy_apb_wr_32b(0x50286, 0xc040c042);
dwc_ddrphy_apb_wr_32b(0x50288, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x5028a, 0x726c754c);
dwc_ddrphy_apb_wr_32b(0x5028c, 0x31c11c0c);
dwc_ddrphy_apb_wr_32b(0x5028e, 0x6009ee);
dwc_ddrphy_apb_wr_32b(0x50290, 0x33c11c04);
dwc_ddrphy_apb_wr_32b(0x50292, 0x70adc01f);
dwc_ddrphy_apb_wr_32b(0x50294, 0x7b0fd980);
dwc_ddrphy_apb_wr_32b(0x50296, 0x754cd8ff);
dwc_ddrphy_apb_wr_32b(0x50298, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x5029a, 0x33c11c04);
dwc_ddrphy_apb_wr_32b(0x5029c, 0x6009d2);
dwc_ddrphy_apb_wr_32b(0x5029e, 0x2455c540);
dwc_ddrphy_apb_wr_32b(0x502a0, 0x20f43f00);
dwc_ddrphy_apb_wr_32b(0x502a2, 0x8da06c0);
dwc_ddrphy_apb_wr_32b(0x502a4, 0xc10500a0);
dwc_ddrphy_apb_wr_32b(0x502a6, 0x708b1600);
dwc_ddrphy_apb_wr_32b(0x502a8, 0x18000);
dwc_ddrphy_apb_wr_32b(0x502aa, 0x23514200);
dwc_ddrphy_apb_wr_32b(0x502ac, 0xd8ffb000);
dwc_ddrphy_apb_wr_32b(0x502ae, 0x6120ca);
dwc_ddrphy_apb_wr_32b(0x502b0, 0x23847063);
dwc_ddrphy_apb_wr_32b(0x502b2, 0xdb809001);
dwc_ddrphy_apb_wr_32b(0x502b4, 0xf20cc057);
dwc_ddrphy_apb_wr_32b(0x502b6, 0x790fc017);
dwc_ddrphy_apb_wr_32b(0x502b8, 0x3f002455);
dwc_ddrphy_apb_wr_32b(0x502ba, 0x4020f4);
dwc_ddrphy_apb_wr_32b(0x502bc, 0xa008a6);
dwc_ddrphy_apb_wr_32b(0x502be, 0x4508c105);
dwc_ddrphy_apb_wr_32b(0x502c0, 0x2208c012);
dwc_ddrphy_apb_wr_32b(0x502c2, 0x78220341);
dwc_ddrphy_apb_wr_32b(0x502c4, 0xc006c044);
dwc_ddrphy_apb_wr_32b(0x502c6, 0x148c6119);
dwc_ddrphy_apb_wr_32b(0x502c8, 0x71103000);
dwc_ddrphy_apb_wr_32b(0x502ca, 0xc004c106);
dwc_ddrphy_apb_wr_32b(0x502cc, 0x4520ca);
dwc_ddrphy_apb_wr_32b(0x502ce, 0x621ac105);
dwc_ddrphy_apb_wr_32b(0x502d0, 0xdd2c044);
dwc_ddrphy_apb_wr_32b(0x502d2, 0x78500060);
dwc_ddrphy_apb_wr_32b(0x502d4, 0x6994c111);
dwc_ddrphy_apb_wr_32b(0x502d6, 0x16c22415);
dwc_ddrphy_apb_wr_32b(0x502d8, 0x800041c3);
dwc_ddrphy_apb_wr_32b(0x502da, 0x6221056c);
dwc_ddrphy_apb_wr_32b(0x502dc, 0x10f2944);
dwc_ddrphy_apb_wr_32b(0x502de, 0xd97fb9e1);
dwc_ddrphy_apb_wr_32b(0x502e0, 0xc121ca);
dwc_ddrphy_apb_wr_32b(0x502e2, 0xbf0dc309);
dwc_ddrphy_apb_wr_32b(0x502e4, 0x793b7965);
dwc_ddrphy_apb_wr_32b(0x502e6, 0x27057f25);
dwc_ddrphy_apb_wr_32b(0x502e8, 0x90001f81);
dwc_ddrphy_apb_wr_32b(0x502ea, 0x1cb00000);
dwc_ddrphy_apb_wr_32b(0x502ec, 0xb1003040);
dwc_ddrphy_apb_wr_32b(0x502ee, 0xb4b700c);
dwc_ddrphy_apb_wr_32b(0x502f0, 0x1c841030);
dwc_ddrphy_apb_wr_32b(0x502f2, 0xc0173000);
dwc_ddrphy_apb_wr_32b(0x502f4, 0x780fda7f);
dwc_ddrphy_apb_wr_32b(0x502f6, 0x40c37c15);
dwc_ddrphy_apb_wr_32b(0x502f8, 0x56c8000);
dwc_ddrphy_apb_wr_32b(0x502fa, 0xd8806403);
dwc_ddrphy_apb_wr_32b(0x502fc, 0x2b44bbe1);
dwc_ddrphy_apb_wr_32b(0x502fe, 0x22ca0101);
dwc_ddrphy_apb_wr_32b(0x50300, 0xc0090001);
dwc_ddrphy_apb_wr_32b(0x50302, 0x7b1b7845);
dwc_ddrphy_apb_wr_32b(0x50304, 0x1c88c004);
dwc_ddrphy_apb_wr_32b(0x50306, 0xb90d3040);
dwc_ddrphy_apb_wr_32b(0x50308, 0xc1057b25);
dwc_ddrphy_apb_wr_32b(0x5030a, 0xbb9c651d);
dwc_ddrphy_apb_wr_32b(0x5030c, 0xd5a78b0);
dwc_ddrphy_apb_wr_32b(0x5030e, 0xbb9f0060);
dwc_ddrphy_apb_wr_32b(0x50310, 0x1c84b300);
dwc_ddrphy_apb_wr_32b(0x50312, 0xe0d3080);
dwc_ddrphy_apb_wr_32b(0x50314, 0xc0161411);
dwc_ddrphy_apb_wr_32b(0x50316, 0x51800);
dwc_ddrphy_apb_wr_32b(0x50318, 0x7913c006);
dwc_ddrphy_apb_wr_32b(0x5031a, 0x7f13c004);
dwc_ddrphy_apb_wr_32b(0x5031c, 0x3e30925);
dwc_ddrphy_apb_wr_32b(0x5031e, 0xc006db1f);
dwc_ddrphy_apb_wr_32b(0x50320, 0x7b46611a);
dwc_ddrphy_apb_wr_32b(0x50322, 0x226cba23);
dwc_ddrphy_apb_wr_32b(0x50324, 0x24550040);
dwc_ddrphy_apb_wr_32b(0x50326, 0x621a3b82);
dwc_ddrphy_apb_wr_32b(0x50328, 0x71248200);
dwc_ddrphy_apb_wr_32b(0x5032a, 0xc0200f);
dwc_ddrphy_apb_wr_32b(0x5032c, 0xf1eea200);
dwc_ddrphy_apb_wr_32b(0x5032e, 0x10208a);
dwc_ddrphy_apb_wr_32b(0x50330, 0x700cc04a);
dwc_ddrphy_apb_wr_32b(0x50332, 0x1030258a);
dwc_ddrphy_apb_wr_32b(0x50334, 0xc058c047);
dwc_ddrphy_apb_wr_32b(0x50336, 0x10208a);
dwc_ddrphy_apb_wr_32b(0x50338, 0x148cc04b);
dwc_ddrphy_apb_wr_32b(0x5033a, 0x77103000);
dwc_ddrphy_apb_wr_32b(0x5033c, 0x2a00f8);
dwc_ddrphy_apb_wr_32b(0x5033e, 0x1e00700c);
dwc_ddrphy_apb_wr_32b(0x50340, 0x90047004);
dwc_ddrphy_apb_wr_32b(0x50342, 0x1e0003fe);
dwc_ddrphy_apb_wr_32b(0x50344, 0x90047045);
dwc_ddrphy_apb_wr_32b(0x50346, 0xf6303fe);
dwc_ddrphy_apb_wr_32b(0x50348, 0x78f01032);
dwc_ddrphy_apb_wr_32b(0x5034a, 0x600cde);
dwc_ddrphy_apb_wr_32b(0x5034c, 0xc119c105);
dwc_ddrphy_apb_wr_32b(0x5034e, 0x2455b100);
dwc_ddrphy_apb_wr_32b(0x50350, 0x20f43f00);
dwc_ddrphy_apb_wr_32b(0x50352, 0x14b006c1);
dwc_ddrphy_apb_wr_32b(0x50354, 0xb0203000);
dwc_ddrphy_apb_wr_32b(0x50356, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x50358, 0x18000);
dwc_ddrphy_apb_wr_32b(0x5035a, 0x19e0829);
dwc_ddrphy_apb_wr_32b(0x5035c, 0xc209c017);
dwc_ddrphy_apb_wr_32b(0x5035e, 0x2455790f);
dwc_ddrphy_apb_wr_32b(0x50360, 0x20f43f00);
dwc_ddrphy_apb_wr_32b(0x50362, 0x14840041);
dwc_ddrphy_apb_wr_32b(0x50364, 0x78453000);
dwc_ddrphy_apb_wr_32b(0x50366, 0x14887a1b);
dwc_ddrphy_apb_wr_32b(0x50368, 0xb80d3000);
dwc_ddrphy_apb_wr_32b(0x5036a, 0xb89c7845);
dwc_ddrphy_apb_wr_32b(0x5036c, 0xb020b89f);
dwc_ddrphy_apb_wr_32b(0x5036e, 0x14110e23);
dwc_ddrphy_apb_wr_32b(0x50370, 0xc105c015);
dwc_ddrphy_apb_wr_32b(0x50372, 0x600c8e);
dwc_ddrphy_apb_wr_32b(0x50374, 0xc1167810);
dwc_ddrphy_apb_wr_32b(0x50376, 0xc004f008);
dwc_ddrphy_apb_wr_32b(0x50378, 0x60f8c105);
dwc_ddrphy_apb_wr_32b(0x5037a, 0x600c7e);
dwc_ddrphy_apb_wr_32b(0x5037c, 0xc1197810);
dwc_ddrphy_apb_wr_32b(0x5037e, 0xafeb100);
dwc_ddrphy_apb_wr_32b(0x50380, 0xd0a0080);
dwc_ddrphy_apb_wr_32b(0x50382, 0x16000000);
dwc_ddrphy_apb_wr_32b(0x50384, 0x90047100);
dwc_ddrphy_apb_wr_32b(0x50386, 0xe80c03fc);
dwc_ddrphy_apb_wr_32b(0x50388, 0xc10cc007);
dwc_ddrphy_apb_wr_32b(0x5038a, 0xc00b7014);
dwc_ddrphy_apb_wr_32b(0x5038c, 0x3c120ca);
dwc_ddrphy_apb_wr_32b(0x5038e, 0xc007c04b);
dwc_ddrphy_apb_wr_32b(0x50390, 0xf0246038);
dwc_ddrphy_apb_wr_32b(0x50392, 0x64fcc406);
dwc_ddrphy_apb_wr_32b(0x50394, 0xc00c4381);
dwc_ddrphy_apb_wr_32b(0x50396, 0xb216098);
dwc_ddrphy_apb_wr_32b(0x50398, 0x24550023);
dwc_ddrphy_apb_wr_32b(0x5039a, 0x2b443b80);
dwc_ddrphy_apb_wr_32b(0x5039c, 0xda1f0801);
dwc_ddrphy_apb_wr_32b(0x5039e, 0x71647a66);
dwc_ddrphy_apb_wr_32b(0x503a0, 0x80207835);
dwc_ddrphy_apb_wr_32b(0x503a2, 0x81210f);
dwc_ddrphy_apb_wr_32b(0x503a4, 0xf1f1a020);
dwc_ddrphy_apb_wr_32b(0x503a6, 0xc018c107);
dwc_ddrphy_apb_wr_32b(0x503a8, 0x80002108);
dwc_ddrphy_apb_wr_32b(0x503aa, 0xc00ac058);
dwc_ddrphy_apb_wr_32b(0x503ac, 0x20cac10b);
dwc_ddrphy_apb_wr_32b(0x503ae, 0xc04a0049);
dwc_ddrphy_apb_wr_32b(0x503b0, 0x25ca6f09);
dwc_ddrphy_apb_wr_32b(0x503b2, 0x700c1009);
dwc_ddrphy_apb_wr_32b(0x503b4, 0xc00cc047);
dwc_ddrphy_apb_wr_32b(0x503b6, 0xf183671f);
dwc_ddrphy_apb_wr_32b(0x503b8, 0xc018c107);
dwc_ddrphy_apb_wr_32b(0x503ba, 0xc0127110);
dwc_ddrphy_apb_wr_32b(0x503bc, 0x25cac10b);
dwc_ddrphy_apb_wr_32b(0x503be, 0xc00a1009);
dwc_ddrphy_apb_wr_32b(0x503c0, 0x4920ca);
dwc_ddrphy_apb_wr_32b(0x503c2, 0xa00ce6);
dwc_ddrphy_apb_wr_32b(0x503c4, 0x209ac04a);
dwc_ddrphy_apb_wr_32b(0x503c6, 0x20150a01);
dwc_ddrphy_apb_wr_32b(0x503c8, 0x40c30381);
dwc_ddrphy_apb_wr_32b(0x503ca, 0x4288000);
dwc_ddrphy_apb_wr_32b(0x503cc, 0x783d6101);
dwc_ddrphy_apb_wr_32b(0x503ce, 0x422044);
dwc_ddrphy_apb_wr_32b(0x503d0, 0x1002944);
dwc_ddrphy_apb_wr_32b(0x503d2, 0x800041c3);
dwc_ddrphy_apb_wr_32b(0x503d4, 0x7a14086c);
dwc_ddrphy_apb_wr_32b(0x503d6, 0x11a87955);
dwc_ddrphy_apb_wr_32b(0x503d8, 0xc00a0002);
dwc_ddrphy_apb_wr_32b(0x503da, 0x30a0b);
dwc_ddrphy_apb_wr_32b(0x503dc, 0x19a8c00a);
dwc_ddrphy_apb_wr_32b(0x503de, 0x810e0000);
dwc_ddrphy_apb_wr_32b(0x503e0, 0x10030d07);
dwc_ddrphy_apb_wr_32b(0x503e2, 0xc20fa1ae);
dwc_ddrphy_apb_wr_32b(0x503e4, 0x740c722c);
dwc_ddrphy_apb_wr_32b(0x503e6, 0xf0ab990);
dwc_ddrphy_apb_wr_32b(0x503e8, 0x43630060);
dwc_ddrphy_apb_wr_32b(0x503ea, 0x14b470ed);
dwc_ddrphy_apb_wr_32b(0x503ec, 0xb8253000);
dwc_ddrphy_apb_wr_32b(0x503ee, 0x10250f19);
dwc_ddrphy_apb_wr_32b(0x503f0, 0x3b802455);
dwc_ddrphy_apb_wr_32b(0x503f2, 0x712c48e2);
dwc_ddrphy_apb_wr_32b(0x503f4, 0xeee740c);
dwc_ddrphy_apb_wr_32b(0x503f6, 0xb9910060);
dwc_ddrphy_apb_wr_32b(0x503f8, 0xf1f371e5);
dwc_ddrphy_apb_wr_32b(0x503fa, 0x740c732c);
dwc_ddrphy_apb_wr_32b(0x503fc, 0x600ede);
dwc_ddrphy_apb_wr_32b(0x503fe, 0xc00ab910);
dwc_ddrphy_apb_wr_32b(0x50400, 0x742cc20f);
dwc_ddrphy_apb_wr_32b(0x50402, 0x740cc040);
dwc_ddrphy_apb_wr_32b(0x50404, 0x4363b992);
dwc_ddrphy_apb_wr_32b(0x50406, 0x600eca);
dwc_ddrphy_apb_wr_32b(0x50408, 0x411c541);
dwc_ddrphy_apb_wr_32b(0x5040a, 0x7167ffef);
dwc_ddrphy_apb_wr_32b(0x5040c, 0xe68e700c);
dwc_ddrphy_apb_wr_32b(0x5040e, 0xd807c054);
dwc_ddrphy_apb_wr_32b(0x50410, 0xffe103fe);
dwc_ddrphy_apb_wr_32b(0x50412, 0xe4fc048);
dwc_ddrphy_apb_wr_32b(0x50414, 0xe0f1450);
dwc_ddrphy_apb_wr_32b(0x50416, 0xe431410);
dwc_ddrphy_apb_wr_32b(0x50418, 0x710c13f1);
dwc_ddrphy_apb_wr_32b(0x5041a, 0xc01bf053);
dwc_ddrphy_apb_wr_32b(0x5041c, 0x19f083b);
dwc_ddrphy_apb_wr_32b(0x5041e, 0x42c3c01d);
dwc_ddrphy_apb_wr_32b(0x50420, 0x86c8000);
dwc_ddrphy_apb_wr_32b(0x50422, 0x851800);
dwc_ddrphy_apb_wr_32b(0x50424, 0x30001494);
dwc_ddrphy_apb_wr_32b(0x50426, 0xc01a791d);
dwc_ddrphy_apb_wr_32b(0x50428, 0x7a357914);
dwc_ddrphy_apb_wr_32b(0x5042a, 0xc012822e);
dwc_ddrphy_apb_wr_32b(0x5042c, 0x12a84831);
dwc_ddrphy_apb_wr_32b(0x5042e, 0x70300000);
dwc_ddrphy_apb_wr_32b(0x50430, 0xc115c012);
dwc_ddrphy_apb_wr_32b(0x50432, 0xb21ca);
dwc_ddrphy_apb_wr_32b(0x50434, 0xd808c155);
dwc_ddrphy_apb_wr_32b(0x50436, 0xe43f037);
dwc_ddrphy_apb_wr_32b(0x50438, 0xc1191555);
dwc_ddrphy_apb_wr_32b(0x5043a, 0x300014ac);
dwc_ddrphy_apb_wr_32b(0x5043c, 0x14a8b100);
dwc_ddrphy_apb_wr_32b(0x5043e, 0xc11e3000);
dwc_ddrphy_apb_wr_32b(0x50440, 0x14310e17);
dwc_ddrphy_apb_wr_32b(0x50442, 0xc116b100);
dwc_ddrphy_apb_wr_32b(0x50444, 0x300014a4);
dwc_ddrphy_apb_wr_32b(0x50446, 0x14a0b100);
dwc_ddrphy_apb_wr_32b(0x50448, 0xc11d3000);
dwc_ddrphy_apb_wr_32b(0x5044a, 0x966b100);
dwc_ddrphy_apb_wr_32b(0x5044c, 0xe110080);
dwc_ddrphy_apb_wr_32b(0x5044e, 0xc01c1651);
dwc_ddrphy_apb_wr_32b(0x50450, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x50452, 0xe1d29009);
dwc_ddrphy_apb_wr_32b(0x50454, 0xffef030d);
dwc_ddrphy_apb_wr_32b(0x50456, 0xe1b71c5);
dwc_ddrphy_apb_wr_32b(0x50458, 0x26421675);
dwc_ddrphy_apb_wr_32b(0x5045a, 0x710c1541);
dwc_ddrphy_apb_wr_32b(0x5045c, 0x20477838);
dwc_ddrphy_apb_wr_32b(0x5045e, 0x35f03c0);
dwc_ddrphy_apb_wr_32b(0x50460, 0x1c80ffef);
dwc_ddrphy_apb_wr_32b(0x50462, 0xc01c3000);
dwc_ddrphy_apb_wr_32b(0x50464, 0x1e00b880);
dwc_ddrphy_apb_wr_32b(0x50466, 0x90097004);
dwc_ddrphy_apb_wr_32b(0x50468, 0x730ce1d2);
dwc_ddrphy_apb_wr_32b(0x5046a, 0xc054b80e);
dwc_ddrphy_apb_wr_32b(0x5046c, 0x345700c);
dwc_ddrphy_apb_wr_32b(0x5046e, 0x45cbffcf);
dwc_ddrphy_apb_wr_32b(0x50470, 0xf000ffff);
dwc_ddrphy_apb_wr_32b(0x50472, 0xa25704c);
dwc_ddrphy_apb_wr_32b(0x50474, 0x41c30715);
dwc_ddrphy_apb_wr_32b(0x50476, 0x86c8000);
dwc_ddrphy_apb_wr_32b(0x50478, 0x816e7955);
dwc_ddrphy_apb_wr_32b(0x5047a, 0x7144c010);
dwc_ddrphy_apb_wr_32b(0x5047c, 0xc02009);
dwc_ddrphy_apb_wr_32b(0x5047e, 0x11a8c050);
dwc_ddrphy_apb_wr_32b(0x50480, 0x25080000);
dwc_ddrphy_apb_wr_32b(0x50482, 0xf1f1100d);
dwc_ddrphy_apb_wr_32b(0x50484, 0x702cc010);
dwc_ddrphy_apb_wr_32b(0x50486, 0xffaf0fda);
dwc_ddrphy_apb_wr_32b(0x50488, 0x1000253a);
dwc_ddrphy_apb_wr_32b(0x5048a, 0x70cdc010);
dwc_ddrphy_apb_wr_32b(0x5048c, 0x60b8be8c);
dwc_ddrphy_apb_wr_32b(0x5048e, 0xc144791d);
dwc_ddrphy_apb_wr_32b(0x50490, 0xc0047114);
dwc_ddrphy_apb_wr_32b(0x50492, 0x2c20ca);
dwc_ddrphy_apb_wr_32b(0x50494, 0xe78ec044);
dwc_ddrphy_apb_wr_32b(0x50496, 0x260160);
dwc_ddrphy_apb_wr_32b(0x50498, 0x45cb42e1);
dwc_ddrphy_apb_wr_32b(0x5049a, 0x86c8000);
dwc_ddrphy_apb_wr_32b(0x5049c, 0x852e7df6);
dwc_ddrphy_apb_wr_32b(0x5049e, 0x100015a8);
dwc_ddrphy_apb_wr_32b(0x504a0, 0x40203a);
dwc_ddrphy_apb_wr_32b(0x504a2, 0x541c3);
dwc_ddrphy_apb_wr_32b(0x504a4, 0xf9e0001);
dwc_ddrphy_apb_wr_32b(0x504a6, 0x15a8ff8f);
dwc_ddrphy_apb_wr_32b(0x504a8, 0x854e1001);
dwc_ddrphy_apb_wr_32b(0x504aa, 0x62387dfb);
dwc_ddrphy_apb_wr_32b(0x504ac, 0x3002232f);
dwc_ddrphy_apb_wr_32b(0x504ae, 0x78d37114);
dwc_ddrphy_apb_wr_32b(0x504b0, 0x3832239);
dwc_ddrphy_apb_wr_32b(0x504b2, 0x2039c04c);
dwc_ddrphy_apb_wr_32b(0x504b4, 0x78650040);
dwc_ddrphy_apb_wr_32b(0x504b6, 0xc00cc04b);
dwc_ddrphy_apb_wr_32b(0x504b8, 0x302c23ca);
dwc_ddrphy_apb_wr_32b(0x504ba, 0x22cc7110);
dwc_ddrphy_apb_wr_32b(0x504bc, 0xf40f8381);
dwc_ddrphy_apb_wr_32b(0x504be, 0xc5240e1);
dwc_ddrphy_apb_wr_32b(0x504c0, 0x712c0220);
dwc_ddrphy_apb_wr_32b(0x504c2, 0x750ce812);
dwc_ddrphy_apb_wr_32b(0x504c4, 0x741c3);
dwc_ddrphy_apb_wr_32b(0x504c6, 0xd4a0001);
dwc_ddrphy_apb_wr_32b(0x504c8, 0x42e10060);
dwc_ddrphy_apb_wr_32b(0x504ca, 0x750cf015);
dwc_ddrphy_apb_wr_32b(0x504cc, 0x641c3);
dwc_ddrphy_apb_wr_32b(0x504ce, 0x42e10002);
dwc_ddrphy_apb_wr_32b(0x504d0, 0x600d36);
dwc_ddrphy_apb_wr_32b(0x504d2, 0xf00d4363);
dwc_ddrphy_apb_wr_32b(0x504d4, 0x710cc304);
dwc_ddrphy_apb_wr_32b(0x504d6, 0xc04b722c);
dwc_ddrphy_apb_wr_32b(0x504d8, 0xb993750c);
dwc_ddrphy_apb_wr_32b(0x504da, 0x600d22);
dwc_ddrphy_apb_wr_32b(0x504dc, 0x141042e1);
dwc_ddrphy_apb_wr_32b(0x504de, 0x40c3301b);
dwc_ddrphy_apb_wr_32b(0x504e0, 0x86c8000);
dwc_ddrphy_apb_wr_32b(0x504e2, 0x34d2015);
dwc_ddrphy_apb_wr_32b(0x504e4, 0x15ac852f);
dwc_ddrphy_apb_wr_32b(0x504e6, 0x203a1000);
dwc_ddrphy_apb_wr_32b(0x504e8, 0x41c30040);
dwc_ddrphy_apb_wr_32b(0x504ea, 0x10009);
dwc_ddrphy_apb_wr_32b(0x504ec, 0xffaf0f0e);
dwc_ddrphy_apb_wr_32b(0x504ee, 0x15ac42e1);
dwc_ddrphy_apb_wr_32b(0x504f0, 0x854f1001);
dwc_ddrphy_apb_wr_32b(0x504f2, 0x7d1d6238);
dwc_ddrphy_apb_wr_32b(0x504f4, 0xc00c7114);
dwc_ddrphy_apb_wr_32b(0x504f6, 0x3832239);
dwc_ddrphy_apb_wr_32b(0x504f8, 0x102c25ca);
dwc_ddrphy_apb_wr_32b(0x504fa, 0x402039);
dwc_ddrphy_apb_wr_32b(0x504fc, 0xc0477865);
dwc_ddrphy_apb_wr_32b(0x504fe, 0x7110c00c);
dwc_ddrphy_apb_wr_32b(0x50500, 0x838122cc);
dwc_ddrphy_apb_wr_32b(0x50502, 0x40e1f40e);
dwc_ddrphy_apb_wr_32b(0x50504, 0x2200bc6);
dwc_ddrphy_apb_wr_32b(0x50506, 0xe813702c);
dwc_ddrphy_apb_wr_32b(0x50508, 0x41c3750c);
dwc_ddrphy_apb_wr_32b(0x5050a, 0x1000b);
dwc_ddrphy_apb_wr_32b(0x5050c, 0x600cbe);
dwc_ddrphy_apb_wr_32b(0x5050e, 0xf01642e1);
dwc_ddrphy_apb_wr_32b(0x50510, 0x41c3750c);
dwc_ddrphy_apb_wr_32b(0x50512, 0x2000a);
dwc_ddrphy_apb_wr_32b(0x50514, 0xcae42e1);
dwc_ddrphy_apb_wr_32b(0x50516, 0x43a10060);
dwc_ddrphy_apb_wr_32b(0x50518, 0xc304f00c);
dwc_ddrphy_apb_wr_32b(0x5051a, 0x41c3750c);
dwc_ddrphy_apb_wr_32b(0x5051c, 0x2000c);
dwc_ddrphy_apb_wr_32b(0x5051e, 0x600c9a);
dwc_ddrphy_apb_wr_32b(0x50520, 0xc50442e1);
dwc_ddrphy_apb_wr_32b(0x50522, 0xc047710c);
dwc_ddrphy_apb_wr_32b(0x50524, 0xe810c00b);
dwc_ddrphy_apb_wr_32b(0x50526, 0x926c105);
dwc_ddrphy_apb_wr_32b(0x50528, 0x202f0060);
dwc_ddrphy_apb_wr_32b(0x5052a, 0xc11306c8);
dwc_ddrphy_apb_wr_32b(0x5052c, 0x13422f40);
dwc_ddrphy_apb_wr_32b(0x5052e, 0x7945b915);
dwc_ddrphy_apb_wr_32b(0x50530, 0xb99cb988);
dwc_ddrphy_apb_wr_32b(0x50532, 0xb100b99f);
dwc_ddrphy_apb_wr_32b(0x50534, 0xe810c007);
dwc_ddrphy_apb_wr_32b(0x50536, 0x906c105);
dwc_ddrphy_apb_wr_32b(0x50538, 0x78b00060);
dwc_ddrphy_apb_wr_32b(0x5053a, 0x2f40c113);
dwc_ddrphy_apb_wr_32b(0x5053c, 0xb9151342);
dwc_ddrphy_apb_wr_32b(0x5053e, 0x21057945);
dwc_ddrphy_apb_wr_32b(0x50540, 0x90000f81);
dwc_ddrphy_apb_wr_32b(0x50542, 0xb10000fe);
dwc_ddrphy_apb_wr_32b(0x50544, 0xf15171e5);
dwc_ddrphy_apb_wr_32b(0x50546, 0x704c706f);
dwc_ddrphy_apb_wr_32b(0x50548, 0x1150a3b);
dwc_ddrphy_apb_wr_32b(0x5054a, 0xb804c011);
dwc_ddrphy_apb_wr_32b(0x5054c, 0x812015);
dwc_ddrphy_apb_wr_32b(0x5054e, 0x800040c3);
dwc_ddrphy_apb_wr_32b(0x50550, 0x6101056c);
dwc_ddrphy_apb_wr_32b(0x50552, 0x320923);
dwc_ddrphy_apb_wr_32b(0x50554, 0x3e802455);
dwc_ddrphy_apb_wr_32b(0x50556, 0x8320f4);
dwc_ddrphy_apb_wr_32b(0x50558, 0xb90bc00d);
dwc_ddrphy_apb_wr_32b(0x5055a, 0xf812104);
dwc_ddrphy_apb_wr_32b(0x5055c, 0xe0006fff);
dwc_ddrphy_apb_wr_32b(0x5055e, 0x7825781b);
dwc_ddrphy_apb_wr_32b(0x50560, 0xb89fb89c);
dwc_ddrphy_apb_wr_32b(0x50562, 0x7144b060);
dwc_ddrphy_apb_wr_32b(0x50564, 0xf32f1e4);
dwc_ddrphy_apb_wr_32b(0x50566, 0x70ad0040);
dwc_ddrphy_apb_wr_32b(0x50568, 0x76c41e00);
dwc_ddrphy_apb_wr_32b(0x5056a, 0x3fe9004);
dwc_ddrphy_apb_wr_32b(0x5056c, 0x31350b99);
dwc_ddrphy_apb_wr_32b(0x5056e, 0x2800710c);
dwc_ddrphy_apb_wr_32b(0x50570, 0x7e0f06c0);
dwc_ddrphy_apb_wr_32b(0x50572, 0x2200b42);
dwc_ddrphy_apb_wr_32b(0x50574, 0x88540c1);
dwc_ddrphy_apb_wr_32b(0x50576, 0x700c0031);
dwc_ddrphy_apb_wr_32b(0x50578, 0x200b42);
dwc_ddrphy_apb_wr_32b(0x5057a, 0x1200d9ff);
dwc_ddrphy_apb_wr_32b(0x5057c, 0x9fa3083);
dwc_ddrphy_apb_wr_32b(0x5057e, 0xc5430000);
dwc_ddrphy_apb_wr_32b(0x50580, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x50582, 0x200c06);
dwc_ddrphy_apb_wr_32b(0x50584, 0x1600c540);
dwc_ddrphy_apb_wr_32b(0x50586, 0x80007100);
dwc_ddrphy_apb_wr_32b(0x50588, 0x702c089e);
dwc_ddrphy_apb_wr_32b(0x5058a, 0xc040734c);
dwc_ddrphy_apb_wr_32b(0x5058c, 0xdb18d8ff);
dwc_ddrphy_apb_wr_32b(0x5058e, 0xc642c543);
dwc_ddrphy_apb_wr_32b(0x50590, 0x200dd6);
dwc_ddrphy_apb_wr_32b(0x50592, 0x31411c04);
dwc_ddrphy_apb_wr_32b(0x50594, 0xd980c01f);
dwc_ddrphy_apb_wr_32b(0x50596, 0x7b0f754c);
dwc_ddrphy_apb_wr_32b(0x50598, 0xc543d8ff);
dwc_ddrphy_apb_wr_32b(0x5059a, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x5059c, 0x200bd2);
dwc_ddrphy_apb_wr_32b(0x5059e, 0xc00ec540);
dwc_ddrphy_apb_wr_32b(0x505a0, 0x2004712c);
dwc_ddrphy_apb_wr_32b(0x505a2, 0xf80);
dwc_ddrphy_apb_wr_32b(0x505a4, 0x1e00efff);
dwc_ddrphy_apb_wr_32b(0x505a6, 0x90047004);
dwc_ddrphy_apb_wr_32b(0x505a8, 0xb8a00fc);
dwc_ddrphy_apb_wr_32b(0x505aa, 0x700c0020);
dwc_ddrphy_apb_wr_32b(0x505ac, 0x712cc00e);
dwc_ddrphy_apb_wr_32b(0x505ae, 0x1e00b88c);
dwc_ddrphy_apb_wr_32b(0x505b0, 0x90047004);
dwc_ddrphy_apb_wr_32b(0x505b2, 0xb7600fc);
dwc_ddrphy_apb_wr_32b(0x505b4, 0x700c0020);
dwc_ddrphy_apb_wr_32b(0x505b6, 0xf1b67167);
dwc_ddrphy_apb_wr_32b(0x505b8, 0x3000149c);
dwc_ddrphy_apb_wr_32b(0x505ba, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x505bc, 0xe1d29009);
dwc_ddrphy_apb_wr_32b(0x505be, 0x30001498);
dwc_ddrphy_apb_wr_32b(0x505c0, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x505c2, 0xf49004);
dwc_ddrphy_apb_wr_32b(0x505c4, 0x1e00c00e);
dwc_ddrphy_apb_wr_32b(0x505c6, 0x90047004);
dwc_ddrphy_apb_wr_32b(0x505c8, 0x149000fc);
dwc_ddrphy_apb_wr_32b(0x505ca, 0x1e003000);
dwc_ddrphy_apb_wr_32b(0x505cc, 0x90047004);
dwc_ddrphy_apb_wr_32b(0x505ce, 0x248003fe);
dwc_ddrphy_apb_wr_32b(0x505d0, 0x14043e03);
dwc_ddrphy_apb_wr_32b(0x505d2, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x505d4, 0xc12841);
dwc_ddrphy_apb_wr_32b(0x505d6, 0x3822144);
dwc_ddrphy_apb_wr_32b(0x505d8, 0x81206d);
dwc_ddrphy_apb_wr_32b(0x505da, 0x7945b828);
dwc_ddrphy_apb_wr_32b(0x505dc, 0x4002044);
dwc_ddrphy_apb_wr_32b(0x505de, 0x81f7825);
dwc_ddrphy_apb_wr_32b(0x505e0, 0xd9170330);
dwc_ddrphy_apb_wr_32b(0x505e2, 0x6012044);
dwc_ddrphy_apb_wr_32b(0x505e4, 0x2310913);
dwc_ddrphy_apb_wr_32b(0x505e6, 0x80b4899);
dwc_ddrphy_apb_wr_32b(0x505e8, 0xd9f70374);
dwc_ddrphy_apb_wr_32b(0x505ea, 0x722cf002);
dwc_ddrphy_apb_wr_32b(0x505ec, 0x7fe07914);
dwc_ddrphy_apb_wr_32b(0x505ee, 0x78e0782f);
dwc_ddrphy_apb_wr_32b(0x505f0, 0x8c0206d);
dwc_ddrphy_apb_wr_32b(0x505f2, 0x70147902);
dwc_ddrphy_apb_wr_32b(0x505f4, 0x2121ca);
dwc_ddrphy_apb_wr_32b(0x505f6, 0x782f7fe0);
dwc_ddrphy_apb_wr_32b(0x505f8, 0xc120ad);
dwc_ddrphy_apb_wr_32b(0x505fa, 0x48994200);
dwc_ddrphy_apb_wr_32b(0x505fc, 0xf432280);
dwc_ddrphy_apb_wr_32b(0x505fe, 0x20c0e18c);
dwc_ddrphy_apb_wr_32b(0x50600, 0xe009008d);
dwc_ddrphy_apb_wr_32b(0x50602, 0x780f7fe0);
dwc_ddrphy_apb_wr_32b(0x50604, 0x700cc0f1);
dwc_ddrphy_apb_wr_32b(0x50606, 0x200ace);
dwc_ddrphy_apb_wr_32b(0x50608, 0xc0d1712c);
dwc_ddrphy_apb_wr_32b(0x5060a, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x5060c, 0x700cc0f1);
dwc_ddrphy_apb_wr_32b(0x5060e, 0x200abe);
dwc_ddrphy_apb_wr_32b(0x50610, 0xc0d1712c);
dwc_ddrphy_apb_wr_32b(0x50612, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x50614, 0xd980d8ff);
dwc_ddrphy_apb_wr_32b(0x50616, 0x746c754c);
dwc_ddrphy_apb_wr_32b(0x50618, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x5061a, 0xd980d8ff);
dwc_ddrphy_apb_wr_32b(0x5061c, 0x746c754c);
dwc_ddrphy_apb_wr_32b(0x5061e, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x50620, 0x2c02940);
dwc_ddrphy_apb_wr_32b(0x50622, 0xf822004);
dwc_ddrphy_apb_wr_32b(0x50624, 0x8000000);
dwc_ddrphy_apb_wr_32b(0x50626, 0x3002940);
dwc_ddrphy_apb_wr_32b(0x50628, 0xf802004);
dwc_ddrphy_apb_wr_32b(0x5062a, 0xe0006ffd);
dwc_ddrphy_apb_wr_32b(0x5062c, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x5062e, 0x1e89712c);
dwc_ddrphy_apb_wr_32b(0x50630, 0x1e88135c);
dwc_ddrphy_apb_wr_32b(0x50632, 0x1ec0135c);
dwc_ddrphy_apb_wr_32b(0x50634, 0x1ecc96c4);
dwc_ddrphy_apb_wr_32b(0x50636, 0x1ebe9044);
dwc_ddrphy_apb_wr_32b(0x50638, 0x7ee09044);
dwc_ddrphy_apb_wr_32b(0x5063a, 0xf802005);
dwc_ddrphy_apb_wr_32b(0x5063c, 0x1669002);
dwc_ddrphy_apb_wr_32b(0x5063e, 0x7ee09000);
dwc_ddrphy_apb_wr_32b(0x50640, 0x20057845);
dwc_ddrphy_apb_wr_32b(0x50642, 0x90020f80);
dwc_ddrphy_apb_wr_32b(0x50644, 0x7ee00166);
dwc_ddrphy_apb_wr_32b(0x50646, 0x2402940);
dwc_ddrphy_apb_wr_32b(0x50648, 0x20057a38);
dwc_ddrphy_apb_wr_32b(0x5064a, 0x90030f80);
dwc_ddrphy_apb_wr_32b(0x5064c, 0xb040e0c4);
dwc_ddrphy_apb_wr_32b(0x5064e, 0x7ee07124);
dwc_ddrphy_apb_wr_32b(0x50650, 0x941d1f58);
dwc_ddrphy_apb_wr_32b(0x50652, 0x901c1f5e);
dwc_ddrphy_apb_wr_32b(0x50654, 0x844208a);
dwc_ddrphy_apb_wr_32b(0x50656, 0x901c1f57);
dwc_ddrphy_apb_wr_32b(0x50658, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x5065a, 0x40c3c0f1);
dwc_ddrphy_apb_wr_32b(0x5065c, 0x8948000);
dwc_ddrphy_apb_wr_32b(0x5065e, 0xb98a9025);
dwc_ddrphy_apb_wr_32b(0x50660, 0xcaab025);
dwc_ddrphy_apb_wr_32b(0x50662, 0x712c02e0);
dwc_ddrphy_apb_wr_32b(0x50664, 0x7ee0c0d1);
dwc_ddrphy_apb_wr_32b(0x50666, 0xd80fc0f1);
dwc_ddrphy_apb_wr_32b(0x50668, 0x6008f6);
dwc_ddrphy_apb_wr_32b(0x5066a, 0xc0d1d90f);
dwc_ddrphy_apb_wr_32b(0x5066c, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x5066e, 0x800041c3);
dwc_ddrphy_apb_wr_32b(0x50670, 0x89200562);
dwc_ddrphy_apb_wr_32b(0x50672, 0x8fc3208c);
dwc_ddrphy_apb_wr_32b(0x50674, 0x4120ca);
dwc_ddrphy_apb_wr_32b(0x50676, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x50678, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x5067a, 0x7ee0754c);
dwc_ddrphy_apb_wr_32b(0x5067c, 0x30831200);
dwc_ddrphy_apb_wr_32b(0x5067e, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x50680, 0x7ee0754c);
dwc_ddrphy_apb_wr_32b(0x50682, 0x30831200);
dwc_ddrphy_apb_wr_32b(0x50684, 0xd8ff702c);
dwc_ddrphy_apb_wr_32b(0x50686, 0x4528754c);
dwc_ddrphy_apb_wr_32b(0x50688, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x5068a, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x5068c, 0x7ee0754c);
dwc_ddrphy_apb_wr_32b(0x5068e, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x50690, 0xdb10754c);
dwc_ddrphy_apb_wr_32b(0x50692, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x50694, 0x754cd8ff);
dwc_ddrphy_apb_wr_32b(0x50696, 0x7ee0726c);
dwc_ddrphy_apb_wr_32b(0x50698, 0x702cc0f1);
dwc_ddrphy_apb_wr_32b(0x5069a, 0x1200822);
dwc_ddrphy_apb_wr_32b(0x5069c, 0xc0d1dab4);
dwc_ddrphy_apb_wr_32b(0x5069e, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x506a0, 0x700cc0f1);
dwc_ddrphy_apb_wr_32b(0x506a2, 0x2008ee);
dwc_ddrphy_apb_wr_32b(0x506a4, 0x1200d9ff);
dwc_ddrphy_apb_wr_32b(0x506a6, 0xc0d13083);
dwc_ddrphy_apb_wr_32b(0x506a8, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x506aa, 0x13432c40);
dwc_ddrphy_apb_wr_32b(0x506ac, 0x3000262f);
dwc_ddrphy_apb_wr_32b(0x506ae, 0x30de2605);
dwc_ddrphy_apb_wr_32b(0x506b0, 0x12432f40);
dwc_ddrphy_apb_wr_32b(0x506b2, 0x7832305);
dwc_ddrphy_apb_wr_32b(0x506b4, 0xbb9cbb91);
dwc_ddrphy_apb_wr_32b(0x506b6, 0x7ee0bb9f);
dwc_ddrphy_apb_wr_32b(0x506b8, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x506ba, 0xc1b4b6c8);
dwc_ddrphy_apb_wr_32b(0x506bc, 0x4528c253);
dwc_ddrphy_apb_wr_32b(0x506be, 0x41c34200);
dwc_ddrphy_apb_wr_32b(0x506c0, 0x10189);
dwc_ddrphy_apb_wr_32b(0x506c2, 0x600952);
dwc_ddrphy_apb_wr_32b(0x506c4, 0x70cd750c);
dwc_ddrphy_apb_wr_32b(0x506c6, 0x13650e73);
dwc_ddrphy_apb_wr_32b(0x506c8, 0x702c42c1);
dwc_ddrphy_apb_wr_32b(0x506ca, 0x2950917);
dwc_ddrphy_apb_wr_32b(0x506cc, 0x20f4c013);
dwc_ddrphy_apb_wr_32b(0x506ce, 0xc08e0083);
dwc_ddrphy_apb_wr_32b(0x506d0, 0xb0607834);
dwc_ddrphy_apb_wr_32b(0x506d2, 0x712462ba);
dwc_ddrphy_apb_wr_32b(0x506d4, 0x1438f1f6);
dwc_ddrphy_apb_wr_32b(0x506d6, 0x1440310b);
dwc_ddrphy_apb_wr_32b(0x506d8, 0x14463103);
dwc_ddrphy_apb_wr_32b(0x506da, 0x14483102);
dwc_ddrphy_apb_wr_32b(0x506dc, 0x144a3101);
dwc_ddrphy_apb_wr_32b(0x506de, 0x143a3100);
dwc_ddrphy_apb_wr_32b(0x506e0, 0x143c311b);
dwc_ddrphy_apb_wr_32b(0x506e2, 0x143e311f);
dwc_ddrphy_apb_wr_32b(0x506e4, 0x1442311e);
dwc_ddrphy_apb_wr_32b(0x506e6, 0x1444310f);
dwc_ddrphy_apb_wr_32b(0x506e8, 0xc048310c);
dwc_ddrphy_apb_wr_32b(0x506ea, 0xc246c147);
dwc_ddrphy_apb_wr_32b(0x506ec, 0x750cc343);
dwc_ddrphy_apb_wr_32b(0x506ee, 0x18a41c3);
dwc_ddrphy_apb_wr_32b(0x506f0, 0x42c1000b);
dwc_ddrphy_apb_wr_32b(0x506f2, 0xc4454361);
dwc_ddrphy_apb_wr_32b(0x506f4, 0x1c08c744);
dwc_ddrphy_apb_wr_32b(0x506f6, 0x1c043780);
dwc_ddrphy_apb_wr_32b(0x506f8, 0x8e637c0);
dwc_ddrphy_apb_wr_32b(0x506fa, 0x1c000060);
dwc_ddrphy_apb_wr_32b(0x506fc, 0x71c536c0);
dwc_ddrphy_apb_wr_32b(0x506fe, 0xc0b4f1c8);
dwc_ddrphy_apb_wr_32b(0x50700, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x50702, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x50704, 0x2432845);
dwc_ddrphy_apb_wr_32b(0x50706, 0x41604220);
dwc_ddrphy_apb_wr_32b(0x50708, 0xdff219e);
dwc_ddrphy_apb_wr_32b(0x5070a, 0x792f6119);
dwc_ddrphy_apb_wr_32b(0x5070c, 0x1e000ad);
dwc_ddrphy_apb_wr_32b(0x5070e, 0x78e04060);
dwc_ddrphy_apb_wr_32b(0x50710, 0x800040c3);
dwc_ddrphy_apb_wr_32b(0x50712, 0x18030562);
dwc_ddrphy_apb_wr_32b(0x50714, 0x7fe00003);
dwc_ddrphy_apb_wr_32b(0x50716, 0x31802);
dwc_ddrphy_apb_wr_32b(0x50718, 0x266fc2e6);
dwc_ddrphy_apb_wr_32b(0x5071a, 0x8ee01243);
dwc_ddrphy_apb_wr_32b(0x5071c, 0x700c4300);
dwc_ddrphy_apb_wr_32b(0x5071e, 0x200bc6);
dwc_ddrphy_apb_wr_32b(0x50720, 0xb3a4220);
dwc_ddrphy_apb_wr_32b(0x50722, 0x700c0020);
dwc_ddrphy_apb_wr_32b(0x50724, 0x200b06);
dwc_ddrphy_apb_wr_32b(0x50726, 0x8e11700c);
dwc_ddrphy_apb_wr_32b(0x50728, 0x800045cb);
dwc_ddrphy_apb_wr_32b(0x5072a, 0x8290562);
dwc_ddrphy_apb_wr_32b(0x5072c, 0x8d02001f);
dwc_ddrphy_apb_wr_32b(0x5072e, 0x8d03e80b);
dwc_ddrphy_apb_wr_32b(0x50730, 0x26854668);
dwc_ddrphy_apb_wr_32b(0x50732, 0xe80e1018);
dwc_ddrphy_apb_wr_32b(0x50734, 0xf8e2305);
dwc_ddrphy_apb_wr_32b(0x50736, 0xe000000);
dwc_ddrphy_apb_wr_32b(0x50738, 0x1660f008);
dwc_ddrphy_apb_wr_32b(0x5073a, 0x80d1080);
dwc_ddrphy_apb_wr_32b(0x5073c, 0x466800fe);
dwc_ddrphy_apb_wr_32b(0x5073e, 0x18e234f);
dwc_ddrphy_apb_wr_32b(0x50740, 0x228cbf15);
dwc_ddrphy_apb_wr_32b(0x50742, 0xe7c8fc3);
dwc_ddrphy_apb_wr_32b(0x50744, 0x404001e2);
dwc_ddrphy_apb_wr_32b(0x50746, 0x1f802705);
dwc_ddrphy_apb_wr_32b(0x50748, 0x1e09008);
dwc_ddrphy_apb_wr_32b(0x5074a, 0x208ab0c0);
dwc_ddrphy_apb_wr_32b(0x5074c, 0x41c3021a);
dwc_ddrphy_apb_wr_32b(0x5074e, 0x2a900e);
dwc_ddrphy_apb_wr_32b(0x50750, 0x40c3b100);
dwc_ddrphy_apb_wr_32b(0x50752, 0xfac0000);
dwc_ddrphy_apb_wr_32b(0x50754, 0x10051d00);
dwc_ddrphy_apb_wr_32b(0x50756, 0x700cb101);
dwc_ddrphy_apb_wr_32b(0x50758, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x5075a, 0x700c4300);
dwc_ddrphy_apb_wr_32b(0x5075c, 0x917702c);
dwc_ddrphy_apb_wr_32b(0x5075e, 0x160000c3);
dwc_ddrphy_apb_wr_32b(0x50760, 0x90087102);
dwc_ddrphy_apb_wr_32b(0x50762, 0xaf701d6);
dwc_ddrphy_apb_wr_32b(0x50764, 0x7124803e);
dwc_ddrphy_apb_wr_32b(0x50766, 0x41c3710c);
dwc_ddrphy_apb_wr_32b(0x50768, 0x40f);
dwc_ddrphy_apb_wr_32b(0x5076a, 0xff8f0211);
dwc_ddrphy_apb_wr_32b(0x5076c, 0x1e00c2e2);
dwc_ddrphy_apb_wr_32b(0x5076e, 0x90087004);
dwc_ddrphy_apb_wr_32b(0x50770, 0x760c01e2);
dwc_ddrphy_apb_wr_32b(0x50772, 0xe009ee);
dwc_ddrphy_apb_wr_32b(0x50774, 0x45cb4328);
dwc_ddrphy_apb_wr_32b(0x50776, 0x1029004);
dwc_ddrphy_apb_wr_32b(0x50778, 0x10300b17);
dwc_ddrphy_apb_wr_32b(0x5077a, 0x10451d00);
dwc_ddrphy_apb_wr_32b(0x5077c, 0x340c3);
dwc_ddrphy_apb_wr_32b(0x5077e, 0xfbad090);
dwc_ddrphy_apb_wr_32b(0x50780, 0x1d00ffcf);
dwc_ddrphy_apb_wr_32b(0x50782, 0xc6c21005);
dwc_ddrphy_apb_wr_32b(0x50784, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x50786, 0xc1a4b6c8);
dwc_ddrphy_apb_wr_32b(0x50788, 0xc0094318);
dwc_ddrphy_apb_wr_32b(0x5078a, 0xbfc3238c);
dwc_ddrphy_apb_wr_32b(0x5078c, 0x1c0e456b);
dwc_ddrphy_apb_wr_32b(0x5078e, 0x16003004);
dwc_ddrphy_apb_wr_32b(0x50790, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x50792, 0x260a0562);
dwc_ddrphy_apb_wr_32b(0x50794, 0xc10a3040);
dwc_ddrphy_apb_wr_32b(0x50796, 0x100125ca);
dwc_ddrphy_apb_wr_32b(0x50798, 0x70c01600);
dwc_ddrphy_apb_wr_32b(0x5079a, 0x3f98000);
dwc_ddrphy_apb_wr_32b(0x5079c, 0xc3414648);
dwc_ddrphy_apb_wr_32b(0x5079e, 0x330825);
dwc_ddrphy_apb_wr_32b(0x507a0, 0x30421c03);
dwc_ddrphy_apb_wr_32b(0x507a2, 0x7a3b4020);
dwc_ddrphy_apb_wr_32b(0x507a4, 0xcc32084);
dwc_ddrphy_apb_wr_32b(0x507a6, 0x2022244);
dwc_ddrphy_apb_wr_32b(0x507a8, 0x783d7a05);
dwc_ddrphy_apb_wr_32b(0x507aa, 0x1002044);
dwc_ddrphy_apb_wr_32b(0x507ac, 0x41407a05);
dwc_ddrphy_apb_wr_32b(0x507ae, 0x30821c03);
dwc_ddrphy_apb_wr_32b(0x507b0, 0x10f10e17);
dwc_ddrphy_apb_wr_32b(0x507b2, 0x935c70b);
dwc_ddrphy_apb_wr_32b(0x507b4, 0x160001d0);
dwc_ddrphy_apb_wr_32b(0x507b6, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x507b8, 0xe88d0013);
dwc_ddrphy_apb_wr_32b(0x507ba, 0xe17f012);
dwc_ddrphy_apb_wr_32b(0x507bc, 0xe211590);
dwc_ddrphy_apb_wr_32b(0x507be, 0x16001551);
dwc_ddrphy_apb_wr_32b(0x507c0, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x507c2, 0x8150001);
dwc_ddrphy_apb_wr_32b(0x507c4, 0x40e1019f);
dwc_ddrphy_apb_wr_32b(0x507c6, 0x30c12440);
dwc_ddrphy_apb_wr_32b(0x507c8, 0xa00b3e);
dwc_ddrphy_apb_wr_32b(0x507ca, 0x33822440);
dwc_ddrphy_apb_wr_32b(0x507cc, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x507ce, 0x18000);
dwc_ddrphy_apb_wr_32b(0x507d0, 0x19e0811);
dwc_ddrphy_apb_wr_32b(0x507d2, 0x10d00e0d);
dwc_ddrphy_apb_wr_32b(0x507d4, 0x15b00e09);
dwc_ddrphy_apb_wr_32b(0x507d6, 0x7f0578fb);
dwc_ddrphy_apb_wr_32b(0x507d8, 0x41c3c00c);
dwc_ddrphy_apb_wr_32b(0x507da, 0x1040a);
dwc_ddrphy_apb_wr_32b(0x507dc, 0xc04242a1);
dwc_ddrphy_apb_wr_32b(0x507de, 0xffaf092a);
dwc_ddrphy_apb_wr_32b(0x507e0, 0x1800257c);
dwc_ddrphy_apb_wr_32b(0x507e2, 0xb4002651);
dwc_ddrphy_apb_wr_32b(0x507e4, 0x10cb2679);
dwc_ddrphy_apb_wr_32b(0x507e6, 0x106123c5);
dwc_ddrphy_apb_wr_32b(0x507e8, 0xe2f7075);
dwc_ddrphy_apb_wr_32b(0x507ea, 0x26d01375);
dwc_ddrphy_apb_wr_32b(0x507ec, 0x700c3421);
dwc_ddrphy_apb_wr_32b(0x507ee, 0x3802025);
dwc_ddrphy_apb_wr_32b(0x507f0, 0xf015f00d);
dwc_ddrphy_apb_wr_32b(0x507f2, 0xf015f011);
dwc_ddrphy_apb_wr_32b(0x507f4, 0xf019f016);
dwc_ddrphy_apb_wr_32b(0x507f6, 0xf011f016);
dwc_ddrphy_apb_wr_32b(0x507f8, 0xf00ff00f);
dwc_ddrphy_apb_wr_32b(0x507fa, 0xf00df00d);
dwc_ddrphy_apb_wr_32b(0x507fc, 0x740cf00e);
dwc_ddrphy_apb_wr_32b(0x507fe, 0xe0ff00f);
dwc_ddrphy_apb_wr_32b(0x50800, 0xe0f1550);
dwc_ddrphy_apb_wr_32b(0x50802, 0x730c1591);
dwc_ddrphy_apb_wr_32b(0x50804, 0x720cf009);
dwc_ddrphy_apb_wr_32b(0x50806, 0xeadf007);
dwc_ddrphy_apb_wr_32b(0x50808, 0x6e2f10f1);
dwc_ddrphy_apb_wr_32b(0x5080a, 0xf003d807);
dwc_ddrphy_apb_wr_32b(0x5080c, 0x232f750c);
dwc_ddrphy_apb_wr_32b(0x5080e, 0x23440782);
dwc_ddrphy_apb_wr_32b(0x50810, 0x264b0e02);
dwc_ddrphy_apb_wr_32b(0x50812, 0x210abc00);
dwc_ddrphy_apb_wr_32b(0x50814, 0x22cf0780);
dwc_ddrphy_apb_wr_32b(0x50816, 0x218401e2);
dwc_ddrphy_apb_wr_32b(0x50818, 0x23840601);
dwc_ddrphy_apb_wr_32b(0x5081a, 0x79450001);
dwc_ddrphy_apb_wr_32b(0x5081c, 0x78257865);
dwc_ddrphy_apb_wr_32b(0x5081e, 0x2032840);
dwc_ddrphy_apb_wr_32b(0x50820, 0x30c02e41);
dwc_ddrphy_apb_wr_32b(0x50822, 0xf812004);
dwc_ddrphy_apb_wr_32b(0x50824, 0x20000000);
dwc_ddrphy_apb_wr_32b(0x50826, 0x7abbc001);
dwc_ddrphy_apb_wr_32b(0x50828, 0x90002351);
dwc_ddrphy_apb_wr_32b(0x5082a, 0x7b057825);
dwc_ddrphy_apb_wr_32b(0x5082c, 0xf802205);
dwc_ddrphy_apb_wr_32b(0x5082e, 0x9008);
dwc_ddrphy_apb_wr_32b(0x50830, 0x3101140e);
dwc_ddrphy_apb_wr_32b(0x50832, 0x2e40b060);
dwc_ddrphy_apb_wr_32b(0x50834, 0x20043200);
dwc_ddrphy_apb_wr_32b(0x50836, 0xf83);
dwc_ddrphy_apb_wr_32b(0x50838, 0x14030f00);
dwc_ddrphy_apb_wr_32b(0x5083a, 0xbfc33080);
dwc_ddrphy_apb_wr_32b(0x5083c, 0x3c223c5);
dwc_ddrphy_apb_wr_32b(0x5083e, 0x7865b80c);
dwc_ddrphy_apb_wr_32b(0x50840, 0x900872c3);
dwc_ddrphy_apb_wr_32b(0x50842, 0xb2000040);
dwc_ddrphy_apb_wr_32b(0x50844, 0x441a40);
dwc_ddrphy_apb_wr_32b(0x50846, 0x2604c002);
dwc_ddrphy_apb_wr_32b(0x50848, 0x3f81);
dwc_ddrphy_apb_wr_32b(0x5084a, 0x238cff00);
dwc_ddrphy_apb_wr_32b(0x5084c, 0x7825bfc3);
dwc_ddrphy_apb_wr_32b(0x5084e, 0x41a80);
dwc_ddrphy_apb_wr_32b(0x50850, 0xf4076d01);
dwc_ddrphy_apb_wr_32b(0x50852, 0x1e00790f);
dwc_ddrphy_apb_wr_32b(0x50854, 0x80007044);
dwc_ddrphy_apb_wr_32b(0x50856, 0x780f0562);
dwc_ddrphy_apb_wr_32b(0x50858, 0x1404c0a4);
dwc_ddrphy_apb_wr_32b(0x5085a, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x5085c, 0x1f50929);
dwc_ddrphy_apb_wr_32b(0x5085e, 0x2025710c);
dwc_ddrphy_apb_wr_32b(0x50860, 0xf1ad0040);
dwc_ddrphy_apb_wr_32b(0x50862, 0xf008f006);
dwc_ddrphy_apb_wr_32b(0x50864, 0xf00af008);
dwc_ddrphy_apb_wr_32b(0x50866, 0xf002f00a);
dwc_ddrphy_apb_wr_32b(0x50868, 0xf1a5760c);
dwc_ddrphy_apb_wr_32b(0x5086a, 0xf1a3d816);
dwc_ddrphy_apb_wr_32b(0x5086c, 0xf1a1d808);
dwc_ddrphy_apb_wr_32b(0x5086e, 0xf19fd820);
dwc_ddrphy_apb_wr_32b(0x50870, 0x41c3700c);
dwc_ddrphy_apb_wr_32b(0x50872, 0x1040b);
dwc_ddrphy_apb_wr_32b(0x50874, 0xff6f0ffe);
dwc_ddrphy_apb_wr_32b(0x50876, 0x700c42c1);
dwc_ddrphy_apb_wr_32b(0x50878, 0x78e0f195);
dwc_ddrphy_apb_wr_32b(0x5087a, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x5087c, 0xc1a8b6c8);
dwc_ddrphy_apb_wr_32b(0x5087e, 0xc60fc510);
dwc_ddrphy_apb_wr_32b(0x50880, 0x1434c70e);
dwc_ddrphy_apb_wr_32b(0x50882, 0xc347301b);
dwc_ddrphy_apb_wr_32b(0x50884, 0xc145c246);
dwc_ddrphy_apb_wr_32b(0x50886, 0xc543c044);
dwc_ddrphy_apb_wr_32b(0x50888, 0xc741c642);
dwc_ddrphy_apb_wr_32b(0x5088a, 0xffef0df6);
dwc_ddrphy_apb_wr_32b(0x5088c, 0x36c01c00);
dwc_ddrphy_apb_wr_32b(0x5088e, 0x70811600);
dwc_ddrphy_apb_wr_32b(0x50890, 0x18000);
dwc_ddrphy_apb_wr_32b(0x50892, 0x19e091f);
dwc_ddrphy_apb_wr_32b(0x50894, 0x780f78db);
dwc_ddrphy_apb_wr_32b(0x50896, 0xc004c042);
dwc_ddrphy_apb_wr_32b(0x50898, 0xc206c105);
dwc_ddrphy_apb_wr_32b(0x5089a, 0xc543c307);
dwc_ddrphy_apb_wr_32b(0x5089c, 0xdd2c741);
dwc_ddrphy_apb_wr_32b(0x5089e, 0x1c00ffef);
dwc_ddrphy_apb_wr_32b(0x508a0, 0xc0a836c0);
dwc_ddrphy_apb_wr_32b(0x508a2, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x508a4, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x508a6, 0xb92c0f1);
dwc_ddrphy_apb_wr_32b(0x508a8, 0xc0d1ffcf);
dwc_ddrphy_apb_wr_32b(0x508aa, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x508ac, 0x1e89008);
dwc_ddrphy_apb_wr_32b(0x508ae, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x508b0, 0x800040c3);
dwc_ddrphy_apb_wr_32b(0x508b2, 0x7fe00564);
dwc_ddrphy_apb_wr_32b(0x508b4, 0x431800);
dwc_ddrphy_apb_wr_32b(0x508b6, 0x800040c3);
dwc_ddrphy_apb_wr_32b(0x508b8, 0x7fe00565);
dwc_ddrphy_apb_wr_32b(0x508ba, 0x431800);
dwc_ddrphy_apb_wr_32b(0x508bc, 0xb66c0f1);
dwc_ddrphy_apb_wr_32b(0x508be, 0xc0d1ffcf);
dwc_ddrphy_apb_wr_32b(0x508c0, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x508c2, 0x1e69008);
dwc_ddrphy_apb_wr_32b(0x508c4, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x508c6, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x508c8, 0xc1a6b6c8);
dwc_ddrphy_apb_wr_32b(0x508ca, 0xbe8c70cd);
dwc_ddrphy_apb_wr_32b(0x508cc, 0xc144c245);
dwc_ddrphy_apb_wr_32b(0x508ce, 0xc0424708);
dwc_ddrphy_apb_wr_32b(0x508d0, 0x6e3470ad);
dwc_ddrphy_apb_wr_32b(0x508d2, 0x724cd8ff);
dwc_ddrphy_apb_wr_32b(0x508d4, 0x1c0c746c);
dwc_ddrphy_apb_wr_32b(0x508d6, 0xc5413441);
dwc_ddrphy_apb_wr_32b(0x508d8, 0xd5ac640);
dwc_ddrphy_apb_wr_32b(0x508da, 0x4338ffef);
dwc_ddrphy_apb_wr_32b(0x508dc, 0x4163d8ff);
dwc_ddrphy_apb_wr_32b(0x508de, 0x726c724c);
dwc_ddrphy_apb_wr_32b(0x508e0, 0xc742c543);
dwc_ddrphy_apb_wr_32b(0x508e2, 0xd46c541);
dwc_ddrphy_apb_wr_32b(0x508e4, 0xc640ffef);
dwc_ddrphy_apb_wr_32b(0x508e6, 0x702cc004);
dwc_ddrphy_apb_wr_32b(0x508e8, 0xc041734c);
dwc_ddrphy_apb_wr_32b(0x508ea, 0x726cc005);
dwc_ddrphy_apb_wr_32b(0x508ec, 0xc040c543);
dwc_ddrphy_apb_wr_32b(0x508ee, 0xd2ed8ff);
dwc_ddrphy_apb_wr_32b(0x508f0, 0xc742ffef);
dwc_ddrphy_apb_wr_32b(0x508f2, 0xffcf0b32);
dwc_ddrphy_apb_wr_32b(0x508f4, 0xc543db40);
dwc_ddrphy_apb_wr_32b(0x508f6, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x508f8, 0xffef0d1a);
dwc_ddrphy_apb_wr_32b(0x508fa, 0xc0a6c540);
dwc_ddrphy_apb_wr_32b(0x508fc, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x508fe, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x50900, 0xadec0f1);
dwc_ddrphy_apb_wr_32b(0x50902, 0xc0d1ffcf);
dwc_ddrphy_apb_wr_32b(0x50904, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x50906, 0x1e49008);
dwc_ddrphy_apb_wr_32b(0x50908, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x5090a, 0x46cbc0e6);
dwc_ddrphy_apb_wr_32b(0x5090c, 0x9948000);
dwc_ddrphy_apb_wr_32b(0x5090e, 0x7fbb86a0);
dwc_ddrphy_apb_wr_32b(0x50910, 0xb2f8661);
dwc_ddrphy_apb_wr_32b(0x50912, 0x708d0362);
dwc_ddrphy_apb_wr_32b(0x50914, 0x11750c23);
dwc_ddrphy_apb_wr_32b(0x50916, 0x3cb2014);
dwc_ddrphy_apb_wr_32b(0x50918, 0x3c320f4);
dwc_ddrphy_apb_wr_32b(0x5091a, 0x633b7485);
dwc_ddrphy_apb_wr_32b(0x5091c, 0x23487b6e);
dwc_ddrphy_apb_wr_32b(0x5091e, 0x23090003);
dwc_ddrphy_apb_wr_32b(0x50920, 0x1b000083);
dwc_ddrphy_apb_wr_32b(0x50922, 0x71e510c4);
dwc_ddrphy_apb_wr_32b(0x50924, 0x71a5f1f0);
dwc_ddrphy_apb_wr_32b(0x50926, 0xc4c6f1ea);
dwc_ddrphy_apb_wr_32b(0x50928, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x5092a, 0xc1a7b6c8);
dwc_ddrphy_apb_wr_32b(0x5092c, 0xca0ac041);
dwc_ddrphy_apb_wr_32b(0x5092e, 0x800047cb);
dwc_ddrphy_apb_wr_32b(0x50930, 0x87c0098c);
dwc_ddrphy_apb_wr_32b(0x50932, 0xe01fb805);
dwc_ddrphy_apb_wr_32b(0x50934, 0xca09c046);
dwc_ddrphy_apb_wr_32b(0x50936, 0xc143c240);
dwc_ddrphy_apb_wr_32b(0x50938, 0xe01fb805);
dwc_ddrphy_apb_wr_32b(0x5093a, 0x8702c042);
dwc_ddrphy_apb_wr_32b(0x5093c, 0xb2016);
dwc_ddrphy_apb_wr_32b(0x5093e, 0x8958701);
dwc_ddrphy_apb_wr_32b(0x50940, 0xc3010382);
dwc_ddrphy_apb_wr_32b(0x50942, 0xc827bd4);
dwc_ddrphy_apb_wr_32b(0x50944, 0x93000020);
dwc_ddrphy_apb_wr_32b(0x50946, 0x264ac100);
dwc_ddrphy_apb_wr_32b(0x50948, 0x61193000);
dwc_ddrphy_apb_wr_32b(0x5094a, 0x2148792e);
dwc_ddrphy_apb_wr_32b(0x5094c, 0xc102000d);
dwc_ddrphy_apb_wr_32b(0x5094e, 0x8002844);
dwc_ddrphy_apb_wr_32b(0x50950, 0x71507ab0);
dwc_ddrphy_apb_wr_32b(0x50952, 0x104525ca);
dwc_ddrphy_apb_wr_32b(0x50954, 0x11022553);
dwc_ddrphy_apb_wr_32b(0x50956, 0x114525ad);
dwc_ddrphy_apb_wr_32b(0x50958, 0x6d36780e);
dwc_ddrphy_apb_wr_32b(0x5095a, 0x2644c044);
dwc_ddrphy_apb_wr_32b(0x5095c, 0x79451040);
dwc_ddrphy_apb_wr_32b(0x5095e, 0xb320b882);
dwc_ddrphy_apb_wr_32b(0x50960, 0xc005c045);
dwc_ddrphy_apb_wr_32b(0x50962, 0x30050e49);
dwc_ddrphy_apb_wr_32b(0x50964, 0x301b140c);
dwc_ddrphy_apb_wr_32b(0x50966, 0x32c32314);
dwc_ddrphy_apb_wr_32b(0x50968, 0x200c36);
dwc_ddrphy_apb_wr_32b(0x5096a, 0xc1049300);
dwc_ddrphy_apb_wr_32b(0x5096c, 0x305e2640);
dwc_ddrphy_apb_wr_32b(0x5096e, 0x69557165);
dwc_ddrphy_apb_wr_32b(0x50970, 0x623ac100);
dwc_ddrphy_apb_wr_32b(0x50972, 0x4a316d35);
dwc_ddrphy_apb_wr_32b(0x50974, 0x780e6038);
dwc_ddrphy_apb_wr_32b(0x50976, 0x2048c106);
dwc_ddrphy_apb_wr_32b(0x50978, 0x7a100000);
dwc_ddrphy_apb_wr_32b(0x5097a, 0x20ca7150);
dwc_ddrphy_apb_wr_32b(0x5097c, 0x791b0045);
dwc_ddrphy_apb_wr_32b(0x5097e, 0xf812104);
dwc_ddrphy_apb_wr_32b(0x50980, 0xffc00000);
dwc_ddrphy_apb_wr_32b(0x50982, 0x7825b8c4);
dwc_ddrphy_apb_wr_32b(0x50984, 0xf1ddb300);
dwc_ddrphy_apb_wr_32b(0x50986, 0xf1b871c5);
dwc_ddrphy_apb_wr_32b(0x50988, 0x1404c0a7);
dwc_ddrphy_apb_wr_32b(0x5098a, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x5098c, 0x900e42c3);
dwc_ddrphy_apb_wr_32b(0x5098e, 0x9280004c);
dwc_ddrphy_apb_wr_32b(0x50990, 0x2b409261);
dwc_ddrphy_apb_wr_32b(0x50992, 0x79850401);
dwc_ddrphy_apb_wr_32b(0x50994, 0x2c40e805);
dwc_ddrphy_apb_wr_32b(0x50996, 0x793d17c3);
dwc_ddrphy_apb_wr_32b(0x50998, 0xbb2ff003);
dwc_ddrphy_apb_wr_32b(0x5099a, 0xba8c793b);
dwc_ddrphy_apb_wr_32b(0x5099c, 0x92419280);
dwc_ddrphy_apb_wr_32b(0x5099e, 0x2a407b25);
dwc_ddrphy_apb_wr_32b(0x509a0, 0x79850401);
dwc_ddrphy_apb_wr_32b(0x509a2, 0x2c40e805);
dwc_ddrphy_apb_wr_32b(0x509a4, 0x783d17c2);
dwc_ddrphy_apb_wr_32b(0x509a6, 0xba2ff003);
dwc_ddrphy_apb_wr_32b(0x509a8, 0x41c3783b);
dwc_ddrphy_apb_wr_32b(0x509aa, 0xfe4c900f);
dwc_ddrphy_apb_wr_32b(0x509ac, 0xb1607a05);
dwc_ddrphy_apb_wr_32b(0x509ae, 0x40c3bb30);
dwc_ddrphy_apb_wr_32b(0x509b0, 0xf04c900f);
dwc_ddrphy_apb_wr_32b(0x509b2, 0xb040b161);
dwc_ddrphy_apb_wr_32b(0x509b4, 0x7fe0ba30);
dwc_ddrphy_apb_wr_32b(0x509b6, 0x78e0b041);
dwc_ddrphy_apb_wr_32b(0x509b8, 0x7de07034);
dwc_ddrphy_apb_wr_32b(0x509ba, 0x2104791b);
dwc_ddrphy_apb_wr_32b(0x509bc, 0xf81);
dwc_ddrphy_apb_wr_32b(0x509be, 0xb8c4ffc0);
dwc_ddrphy_apb_wr_32b(0x509c0, 0x78257fe0);
dwc_ddrphy_apb_wr_32b(0x509c2, 0xc1a4c0f1);
dwc_ddrphy_apb_wr_32b(0x509c4, 0xaaa700c);
dwc_ddrphy_apb_wr_32b(0x509c6, 0xd9ffffef);
dwc_ddrphy_apb_wr_32b(0x509c8, 0xc043700c);
dwc_ddrphy_apb_wr_32b(0x509ca, 0xc041c042);
dwc_ddrphy_apb_wr_32b(0x509cc, 0xc040d85a);
dwc_ddrphy_apb_wr_32b(0x509ce, 0xd980d8ff);
dwc_ddrphy_apb_wr_32b(0x509d0, 0xb6ada0a);
dwc_ddrphy_apb_wr_32b(0x509d2, 0xdb20ffef);
dwc_ddrphy_apb_wr_32b(0x509d4, 0xffcf0872);
dwc_ddrphy_apb_wr_32b(0x509d6, 0xc0d1c0a4);
dwc_ddrphy_apb_wr_32b(0x509d8, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x509da, 0x20c07014);
dwc_ddrphy_apb_wr_32b(0x509dc, 0x7fe00fe9);
dwc_ddrphy_apb_wr_32b(0x509de, 0x12884);
dwc_ddrphy_apb_wr_32b(0x509e0, 0x70831600);
dwc_ddrphy_apb_wr_32b(0x509e2, 0x3f88000);
dwc_ddrphy_apb_wr_32b(0x509e4, 0x7ce0bbe0);
dwc_ddrphy_apb_wr_32b(0x509e6, 0x18007b5);
dwc_ddrphy_apb_wr_32b(0x509e8, 0x4340c0f1);
dwc_ddrphy_apb_wr_32b(0x509ea, 0x70821600);
dwc_ddrphy_apb_wr_32b(0x509ec, 0x3f88000);
dwc_ddrphy_apb_wr_32b(0x509ee, 0x3e0a1d);
dwc_ddrphy_apb_wr_32b(0x509f0, 0xc042c1a4);
dwc_ddrphy_apb_wr_32b(0x509f2, 0xd8ffc140);
dwc_ddrphy_apb_wr_32b(0x509f4, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x509f6, 0x30011c0c);
dwc_ddrphy_apb_wr_32b(0x509f8, 0xffef0d06);
dwc_ddrphy_apb_wr_32b(0x509fa, 0x30811c04);
dwc_ddrphy_apb_wr_32b(0x509fc, 0xc0d1c0a4);
dwc_ddrphy_apb_wr_32b(0x509fe, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x50a00, 0x70831600);
dwc_ddrphy_apb_wr_32b(0x50a02, 0x3f88000);
dwc_ddrphy_apb_wr_32b(0x50a04, 0x7ce0bbe0);
dwc_ddrphy_apb_wr_32b(0x50a06, 0xe022246);
dwc_ddrphy_apb_wr_32b(0x50a08, 0xe032344);
dwc_ddrphy_apb_wr_32b(0x50a0a, 0x1a0076d);
dwc_ddrphy_apb_wr_32b(0x50a0c, 0x78e07a65);
dwc_ddrphy_apb_wr_32b(0x50a0e, 0x4340c0f1);
dwc_ddrphy_apb_wr_32b(0x50a10, 0x70821600);
dwc_ddrphy_apb_wr_32b(0x50a12, 0x3f88000);
dwc_ddrphy_apb_wr_32b(0x50a14, 0x3e0a27);
dwc_ddrphy_apb_wr_32b(0x50a16, 0xc042c1a4);
dwc_ddrphy_apb_wr_32b(0x50a18, 0xe012146);
dwc_ddrphy_apb_wr_32b(0x50a1a, 0xe002244);
dwc_ddrphy_apb_wr_32b(0x50a1c, 0xc0407825);
dwc_ddrphy_apb_wr_32b(0x50a1e, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x50a20, 0x1c0c734c);
dwc_ddrphy_apb_wr_32b(0x50a22, 0xcb23001);
dwc_ddrphy_apb_wr_32b(0x50a24, 0x1c04ffef);
dwc_ddrphy_apb_wr_32b(0x50a26, 0xc0a43081);
dwc_ddrphy_apb_wr_32b(0x50a28, 0x7ee0c0d1);
dwc_ddrphy_apb_wr_32b(0x50a2a, 0x1cfcc2e2);
dwc_ddrphy_apb_wr_32b(0x50a2c, 0x4318b6c8);
dwc_ddrphy_apb_wr_32b(0x50a2e, 0x600822);
dwc_ddrphy_apb_wr_32b(0x50a30, 0x863740c);
dwc_ddrphy_apb_wr_32b(0x50a32, 0x45cb031e);
dwc_ddrphy_apb_wr_32b(0x50a34, 0x8948000);
dwc_ddrphy_apb_wr_32b(0x50a36, 0x30100b0f);
dwc_ddrphy_apb_wr_32b(0x50a38, 0x1a139504);
dwc_ddrphy_apb_wr_32b(0x50a3a, 0xb8ac301c);
dwc_ddrphy_apb_wr_32b(0x50a3c, 0xcc13f002);
dwc_ddrphy_apb_wr_32b(0x50a3e, 0x70811600);
dwc_ddrphy_apb_wr_32b(0x50a40, 0x3f88000);
dwc_ddrphy_apb_wr_32b(0x50a42, 0x3e0921);
dwc_ddrphy_apb_wr_32b(0x50a44, 0xb19b504);
dwc_ddrphy_apb_wr_32b(0x50a46, 0x95023010);
dwc_ddrphy_apb_wr_32b(0x50a48, 0x301c1a12);
dwc_ddrphy_apb_wr_32b(0x50a4a, 0xe022046);
dwc_ddrphy_apb_wr_32b(0x50a4c, 0xe002144);
dwc_ddrphy_apb_wr_32b(0x50a4e, 0xf0037845);
dwc_ddrphy_apb_wr_32b(0x50a50, 0xb502cc12);
dwc_ddrphy_apb_wr_32b(0x50a52, 0x702c40a1);
dwc_ddrphy_apb_wr_32b(0x50a54, 0x2a00cc2);
dwc_ddrphy_apb_wr_32b(0x50a56, 0x9542daeb);
dwc_ddrphy_apb_wr_32b(0x50a58, 0xb0f9521);
dwc_ddrphy_apb_wr_32b(0x50a5a, 0x95003030);
dwc_ddrphy_apb_wr_32b(0x50a5c, 0xffcf0f4a);
dwc_ddrphy_apb_wr_32b(0x50a5e, 0xf06f003);
dwc_ddrphy_apb_wr_32b(0x50a60, 0x1404ffcf);
dwc_ddrphy_apb_wr_32b(0x50a62, 0xc6c2341b);
dwc_ddrphy_apb_wr_32b(0x50a64, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x50a66, 0x4528b6c8);
dwc_ddrphy_apb_wr_32b(0x50a68, 0x2008ae);
dwc_ddrphy_apb_wr_32b(0x50a6a, 0x8a14318);
dwc_ddrphy_apb_wr_32b(0x50a6c, 0x710c0030);
dwc_ddrphy_apb_wr_32b(0x50a6e, 0x800046cb);
dwc_ddrphy_apb_wr_32b(0x50a70, 0x28000894);
dwc_ddrphy_apb_wr_32b(0x50a72, 0x960506cf);
dwc_ddrphy_apb_wr_32b(0x50a74, 0x800041c3);
dwc_ddrphy_apb_wr_32b(0x50a76, 0xed1803f6);
dwc_ddrphy_apb_wr_32b(0x50a78, 0xf802004);
dwc_ddrphy_apb_wr_32b(0x50a7a, 0xefff0000);
dwc_ddrphy_apb_wr_32b(0x50a7c, 0x8900b605);
dwc_ddrphy_apb_wr_32b(0x50a7e, 0x1e082f);
dwc_ddrphy_apb_wr_32b(0x50a80, 0x1a119600);
dwc_ddrphy_apb_wr_32b(0x50a82, 0x2004301c);
dwc_ddrphy_apb_wr_32b(0x50a84, 0xf82);
dwc_ddrphy_apb_wr_32b(0x50a86, 0x9100ef8b);
dwc_ddrphy_apb_wr_32b(0x50a88, 0xf802004);
dwc_ddrphy_apb_wr_32b(0x50a8a, 0x10740000);
dwc_ddrphy_apb_wr_32b(0x50a8c, 0xf0087845);
dwc_ddrphy_apb_wr_32b(0x50a8e, 0xb605b88c);
dwc_ddrphy_apb_wr_32b(0x50a90, 0x80b8900);
dwc_ddrphy_apb_wr_32b(0x50a92, 0xcc11001e);
dwc_ddrphy_apb_wr_32b(0x50a94, 0x40c1b600);
dwc_ddrphy_apb_wr_32b(0x50a96, 0x1e00ece);
dwc_ddrphy_apb_wr_32b(0x50a98, 0x78ef4163);
dwc_ddrphy_apb_wr_32b(0x50a9a, 0x714c41c1);
dwc_ddrphy_apb_wr_32b(0x50a9c, 0x2600e66);
dwc_ddrphy_apb_wr_32b(0x50a9e, 0x1600db40);
dwc_ddrphy_apb_wr_32b(0x50aa0, 0x80007100);
dwc_ddrphy_apb_wr_32b(0x50aa2, 0xed1103f6);
dwc_ddrphy_apb_wr_32b(0x50aa4, 0x1e082d);
dwc_ddrphy_apb_wr_32b(0x50aa6, 0x20049620);
dwc_ddrphy_apb_wr_32b(0x50aa8, 0xf80);
dwc_ddrphy_apb_wr_32b(0x50aaa, 0x96421074);
dwc_ddrphy_apb_wr_32b(0x50aac, 0xf812104);
dwc_ddrphy_apb_wr_32b(0x50aae, 0xef8b0000);
dwc_ddrphy_apb_wr_32b(0x50ab0, 0x96217825);
dwc_ddrphy_apb_wr_32b(0x50ab2, 0x811f006);
dwc_ddrphy_apb_wr_32b(0x50ab4, 0x9642001e);
dwc_ddrphy_apb_wr_32b(0x50ab6, 0x96009621);
dwc_ddrphy_apb_wr_32b(0x50ab8, 0x1800e12);
dwc_ddrphy_apb_wr_32b(0x50aba, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x50abc, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x50abe, 0xf02c0f1);
dwc_ddrphy_apb_wr_32b(0x50ac0, 0x710c0020);
dwc_ddrphy_apb_wr_32b(0x50ac2, 0x2ff0811);
dwc_ddrphy_apb_wr_32b(0x50ac4, 0xef6702c);
dwc_ddrphy_apb_wr_32b(0x50ac6, 0x750c0020);
dwc_ddrphy_apb_wr_32b(0x50ac8, 0x301206d);
dwc_ddrphy_apb_wr_32b(0x50aca, 0x7fe0c0d1);
dwc_ddrphy_apb_wr_32b(0x50acc, 0x78e04020);
dwc_ddrphy_apb_wr_32b(0x50ace, 0xee2c2e2);
dwc_ddrphy_apb_wr_32b(0x50ad0, 0x710c0020);
dwc_ddrphy_apb_wr_32b(0x50ad2, 0x2ff081d);
dwc_ddrphy_apb_wr_32b(0x50ad4, 0x750c70ad);
dwc_ddrphy_apb_wr_32b(0x50ad6, 0x200ed2);
dwc_ddrphy_apb_wr_32b(0x50ad8, 0x81171ad);
dwc_ddrphy_apb_wr_32b(0x50ada, 0x750c02ff);
dwc_ddrphy_apb_wr_32b(0x50adc, 0xec6);
dwc_ddrphy_apb_wr_32b(0x50ade, 0x28d206d);
dwc_ddrphy_apb_wr_32b(0x50ae0, 0xc6c240a1);
dwc_ddrphy_apb_wr_32b(0x50ae2, 0x714cb80d);
dwc_ddrphy_apb_wr_32b(0x50ae4, 0xf832005);
dwc_ddrphy_apb_wr_32b(0x50ae6, 0x16a9002);
dwc_ddrphy_apb_wr_32b(0x50ae8, 0xe18f7a38);
dwc_ddrphy_apb_wr_32b(0x50aea, 0xfc7208a);
dwc_ddrphy_apb_wr_32b(0x50aec, 0x122ca);
dwc_ddrphy_apb_wr_32b(0x50aee, 0x240224f);
dwc_ddrphy_apb_wr_32b(0x50af0, 0x51b00);
dwc_ddrphy_apb_wr_32b(0x50af2, 0xb300b340);
dwc_ddrphy_apb_wr_32b(0x50af4, 0x7fe0b340);
dwc_ddrphy_apb_wr_32b(0x50af6, 0x51b00);
dwc_ddrphy_apb_wr_32b(0x50af8, 0x70144100);
dwc_ddrphy_apb_wr_32b(0x50afa, 0x20e0700c);
dwc_ddrphy_apb_wr_32b(0x50afc, 0x783007cc);
dwc_ddrphy_apb_wr_32b(0x50afe, 0x7fe0e03f);
dwc_ddrphy_apb_wr_32b(0x50b00, 0x78e0b826);
dwc_ddrphy_apb_wr_32b(0x50b02, 0x4200c0f1);
dwc_ddrphy_apb_wr_32b(0x50b04, 0x200d5a);
dwc_ddrphy_apb_wr_32b(0x50b06, 0x795b4020);
dwc_ddrphy_apb_wr_32b(0x50b08, 0x1812144);
dwc_ddrphy_apb_wr_32b(0x50b0a, 0xc0d17839);
dwc_ddrphy_apb_wr_32b(0x50b0c, 0xb8c17fe0);
dwc_ddrphy_apb_wr_32b(0x50b0e, 0x7de07034);
dwc_ddrphy_apb_wr_32b(0x50b10, 0x216c791d);
dwc_ddrphy_apb_wr_32b(0x50b12, 0xb8c40101);
dwc_ddrphy_apb_wr_32b(0x50b14, 0x78257fe0);
dwc_ddrphy_apb_wr_32b(0x50b16, 0xf72c0f1);
dwc_ddrphy_apb_wr_32b(0x50b18, 0xe809ffcf);
dwc_ddrphy_apb_wr_32b(0x50b1a, 0x800040c3);
dwc_ddrphy_apb_wr_32b(0x50b1c, 0x712c0894);
dwc_ddrphy_apb_wr_32b(0x50b1e, 0x2a00b2e);
dwc_ddrphy_apb_wr_32b(0x50b20, 0x1e00da40);
dwc_ddrphy_apb_wr_32b(0x50b22, 0x900f7205);
dwc_ddrphy_apb_wr_32b(0x50b24, 0xc0d1e022);
dwc_ddrphy_apb_wr_32b(0x50b26, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x50b28, 0xc1a4c3e4);
dwc_ddrphy_apb_wr_32b(0x50b2a, 0xffef0f2a);
dwc_ddrphy_apb_wr_32b(0x50b2c, 0x20794608);
dwc_ddrphy_apb_wr_32b(0x50b2e, 0x68b20000);
dwc_ddrphy_apb_wr_32b(0x50b30, 0xffef0f3e);
dwc_ddrphy_apb_wr_32b(0x50b32, 0xeea9e508);
dwc_ddrphy_apb_wr_32b(0x50b34, 0x1600e827);
dwc_ddrphy_apb_wr_32b(0x50b36, 0x80007100);
dwc_ddrphy_apb_wr_32b(0x50b38, 0x70cd0068);
dwc_ddrphy_apb_wr_32b(0x50b3a, 0x800041c3);
dwc_ddrphy_apb_wr_32b(0x50b3c, 0xb8eb0894);
dwc_ddrphy_apb_wr_32b(0x50b3e, 0x14a225c5);
dwc_ddrphy_apb_wr_32b(0x50b40, 0xda0ec080);
dwc_ddrphy_apb_wr_32b(0x50b42, 0x73441e00);
dwc_ddrphy_apb_wr_32b(0x50b44, 0xe022900f);
dwc_ddrphy_apb_wr_32b(0x50b46, 0xa00eb6);
dwc_ddrphy_apb_wr_32b(0x50b48, 0xdeebe8b);
dwc_ddrphy_apb_wr_32b(0x50b4a, 0x750c0020);
dwc_ddrphy_apb_wr_32b(0x50b4c, 0x208ab8eb);
dwc_ddrphy_apb_wr_32b(0x50b4e, 0x26ca0010);
dwc_ddrphy_apb_wr_32b(0x50b50, 0x43831001);
dwc_ddrphy_apb_wr_32b(0x50b52, 0x712c9305);
dwc_ddrphy_apb_wr_32b(0x50b54, 0x7e05da40);
dwc_ddrphy_apb_wr_32b(0x50b56, 0xabec080);
dwc_ddrphy_apb_wr_32b(0x50b58, 0xb3c502a0);
dwc_ddrphy_apb_wr_32b(0x50b5a, 0x1e00c7c4);
dwc_ddrphy_apb_wr_32b(0x50b5c, 0x900f7344);
dwc_ddrphy_apb_wr_32b(0x50b5e, 0xc7c4e022);
dwc_ddrphy_apb_wr_32b(0x50b60, 0x281215f);
dwc_ddrphy_apb_wr_32b(0x50b62, 0x20326038);
dwc_ddrphy_apb_wr_32b(0x50b64, 0x80000f80);
dwc_ddrphy_apb_wr_32b(0x50b66, 0x7fe0086c);
dwc_ddrphy_apb_wr_32b(0x50b68, 0x2078);
dwc_ddrphy_apb_wr_32b(0x50b6a, 0xc2e1c3e1);
dwc_ddrphy_apb_wr_32b(0x50b6c, 0xc0e1c1e1);
dwc_ddrphy_apb_wr_32b(0x50b6e, 0xb7c81cf8);
dwc_ddrphy_apb_wr_32b(0x50b70, 0xc1844220);
dwc_ddrphy_apb_wr_32b(0x50b72, 0x1600c141);
dwc_ddrphy_apb_wr_32b(0x50b74, 0x80007081);
dwc_ddrphy_apb_wr_32b(0x50b76, 0x80f0018);
dwc_ddrphy_apb_wr_32b(0x50b78, 0x40400064);
dwc_ddrphy_apb_wr_32b(0x50b7a, 0x1e00dce);
dwc_ddrphy_apb_wr_32b(0x50b7c, 0x1408c101);
dwc_ddrphy_apb_wr_32b(0x50b7e, 0x7fe0341f);
dwc_ddrphy_apb_wr_32b(0x50b80, 0x78e0c0a4);
dwc_ddrphy_apb_wr_32b(0x50b82, 0x1822841);
dwc_ddrphy_apb_wr_32b(0x50b84, 0x141206c);
dwc_ddrphy_apb_wr_32b(0x50b86, 0x6a357822);
dwc_ddrphy_apb_wr_32b(0x50b88, 0x7fe06038);
dwc_ddrphy_apb_wr_32b(0x50b8a, 0x78e0780e);
dwc_ddrphy_apb_wr_32b(0x50b8c, 0x93ac2e4);
dwc_ddrphy_apb_wr_32b(0x50b8e, 0x46cb0080);
dwc_ddrphy_apb_wr_32b(0x50b90, 0xc09004);
dwc_ddrphy_apb_wr_32b(0x50b92, 0x10851e00);
dwc_ddrphy_apb_wr_32b(0x50b94, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x50b96, 0x18000);
dwc_ddrphy_apb_wr_32b(0x50b98, 0x341c3);
dwc_ddrphy_apb_wr_32b(0x50b9a, 0x20440d40);
dwc_ddrphy_apb_wr_32b(0x50b9c, 0x208a808d);
dwc_ddrphy_apb_wr_32b(0x50b9e, 0xd4a041f);
dwc_ddrphy_apb_wr_32b(0x50ba0, 0x20ca0060);
dwc_ddrphy_apb_wr_32b(0x50ba2, 0x98e0041);
dwc_ddrphy_apb_wr_32b(0x50ba4, 0x781d00a0);
dwc_ddrphy_apb_wr_32b(0x50ba6, 0x41c370b5);
dwc_ddrphy_apb_wr_32b(0x50ba8, 0xa1200007);
dwc_ddrphy_apb_wr_32b(0x50baa, 0x40c3);
dwc_ddrphy_apb_wr_32b(0x50bac, 0x20ca1388);
dwc_ddrphy_apb_wr_32b(0x50bae, 0xd2a0041);
dwc_ddrphy_apb_wr_32b(0x50bb0, 0x1e000060);
dwc_ddrphy_apb_wr_32b(0x50bb2, 0x96e10c5);
dwc_ddrphy_apb_wr_32b(0x50bb4, 0x781d00a0);
dwc_ddrphy_apb_wr_32b(0x50bb6, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x50bb8, 0x3f98000);
dwc_ddrphy_apb_wr_32b(0x50bba, 0x1f0809);
dwc_ddrphy_apb_wr_32b(0x50bbc, 0x10451e00);
dwc_ddrphy_apb_wr_32b(0x50bbe, 0x78e0c6c4);
dwc_ddrphy_apb_wr_32b(0x50bc0, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x50bc2, 0x2482b6c8);
dwc_ddrphy_apb_wr_32b(0x50bc4, 0x47483d02);
dwc_ddrphy_apb_wr_32b(0x50bc6, 0x43084338);
dwc_ddrphy_apb_wr_32b(0x50bc8, 0xda2c080);
dwc_ddrphy_apb_wr_32b(0x50bca, 0xb25ff8f);
dwc_ddrphy_apb_wr_32b(0x50bcc, 0x750c10b1);
dwc_ddrphy_apb_wr_32b(0x50bce, 0x18d41c3);
dwc_ddrphy_apb_wr_32b(0x50bd0, 0xf360001);
dwc_ddrphy_apb_wr_32b(0x50bd2, 0x4260ffef);
dwc_ddrphy_apb_wr_32b(0x50bd4, 0x702cc080);
dwc_ddrphy_apb_wr_32b(0x50bd6, 0x1600e66);
dwc_ddrphy_apb_wr_32b(0x50bd8, 0x700c714c);
dwc_ddrphy_apb_wr_32b(0x50bda, 0xf032d909);
dwc_ddrphy_apb_wr_32b(0x50bdc, 0x351b2b40);
dwc_ddrphy_apb_wr_32b(0x50bde, 0x10300b1b);
dwc_ddrphy_apb_wr_32b(0x50be0, 0x41c3750c);
dwc_ddrphy_apb_wr_32b(0x50be2, 0x1018f);
dwc_ddrphy_apb_wr_32b(0x50be4, 0xffef0f0e);
dwc_ddrphy_apb_wr_32b(0x50be6, 0xdd094260);
dwc_ddrphy_apb_wr_32b(0x50be8, 0xd8d0dec0);
dwc_ddrphy_apb_wr_32b(0x50bea, 0x41c3f00a);
dwc_ddrphy_apb_wr_32b(0x50bec, 0x1018e);
dwc_ddrphy_apb_wr_32b(0x50bee, 0xffef0efa);
dwc_ddrphy_apb_wr_32b(0x50bf0, 0x72ad4260);
dwc_ddrphy_apb_wr_32b(0x50bf2, 0xd880de8c);
dwc_ddrphy_apb_wr_32b(0x50bf4, 0x200560f8);
dwc_ddrphy_apb_wr_32b(0x50bf6, 0xc18006c0);
dwc_ddrphy_apb_wr_32b(0x50bf8, 0x1600de6);
dwc_ddrphy_apb_wr_32b(0x50bfa, 0x700c724c);
dwc_ddrphy_apb_wr_32b(0x50bfc, 0xd7a722c);
dwc_ddrphy_apb_wr_32b(0x50bfe, 0xc280ffaf);
dwc_ddrphy_apb_wr_32b(0x50c00, 0xd32c080);
dwc_ddrphy_apb_wr_32b(0x50c02, 0x66feff8f);
dwc_ddrphy_apb_wr_32b(0x50c04, 0x33802305);
dwc_ddrphy_apb_wr_32b(0x50c06, 0xdcac180);
dwc_ddrphy_apb_wr_32b(0x50c08, 0x42a10160);
dwc_ddrphy_apb_wr_32b(0x50c0a, 0x41a1710c);
dwc_ddrphy_apb_wr_32b(0x50c0c, 0xffaf0d5a);
dwc_ddrphy_apb_wr_32b(0x50c0e, 0x2480c280);
dwc_ddrphy_apb_wr_32b(0x50c10, 0x14043d02);
dwc_ddrphy_apb_wr_32b(0x50c12, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x50c14, 0x2482c3e2);
dwc_ddrphy_apb_wr_32b(0x50c16, 0x45283d02);
dwc_ddrphy_apb_wr_32b(0x50c18, 0xc0804300);
dwc_ddrphy_apb_wr_32b(0x50c1a, 0xff8f0cfe);
dwc_ddrphy_apb_wr_32b(0x50c1c, 0xd002354);
dwc_ddrphy_apb_wr_32b(0x50c1e, 0xd9ac180);
dwc_ddrphy_apb_wr_32b(0x50c20, 0xda090160);
dwc_ddrphy_apb_wr_32b(0x50c22, 0x41c3750c);
dwc_ddrphy_apb_wr_32b(0x50c24, 0x10190);
dwc_ddrphy_apb_wr_32b(0x50c26, 0xffef0e8a);
dwc_ddrphy_apb_wr_32b(0x50c28, 0x700c42a1);
dwc_ddrphy_apb_wr_32b(0x50c2a, 0xd1ed909);
dwc_ddrphy_apb_wr_32b(0x50c2c, 0xc280ffaf);
dwc_ddrphy_apb_wr_32b(0x50c2e, 0x78e0c7c2);
dwc_ddrphy_apb_wr_32b(0x50c30, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x50c32, 0x18000);
dwc_ddrphy_apb_wr_32b(0x50c34, 0x7ce0b8e0);
dwc_ddrphy_apb_wr_32b(0x50c36, 0x42c3702c);
dwc_ddrphy_apb_wr_32b(0x50c38, 0xe0369005);
dwc_ddrphy_apb_wr_32b(0x50c3a, 0x900340c3);
dwc_ddrphy_apb_wr_32b(0x50c3c, 0xb220e034);
dwc_ddrphy_apb_wr_32b(0x50c3e, 0xb8b1b020);
dwc_ddrphy_apb_wr_32b(0x50c40, 0xd823b020);
dwc_ddrphy_apb_wr_32b(0x50c42, 0x80041afe);
dwc_ddrphy_apb_wr_32b(0x50c44, 0x900440c3);
dwc_ddrphy_apb_wr_32b(0x50c46, 0x90200014);
dwc_ddrphy_apb_wr_32b(0x50c48, 0x7fe0b982);
dwc_ddrphy_apb_wr_32b(0x50c4a, 0x78e0b020);
dwc_ddrphy_apb_wr_32b(0x50c4c, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x50c4e, 0x1600b6c8);
dwc_ddrphy_apb_wr_32b(0x50c50, 0x90047101);
dwc_ddrphy_apb_wr_32b(0x50c52, 0x160001e0);
dwc_ddrphy_apb_wr_32b(0x50c54, 0x8000709b);
dwc_ddrphy_apb_wr_32b(0x50c56, 0x2b400004);
dwc_ddrphy_apb_wr_32b(0x50c58, 0x29013080);
dwc_ddrphy_apb_wr_32b(0x50c5a, 0xb8c30000);
dwc_ddrphy_apb_wr_32b(0x50c5c, 0x70080d);
dwc_ddrphy_apb_wr_32b(0x50c5e, 0x80970ad);
dwc_ddrphy_apb_wr_32b(0x50c60, 0x71ad0190);
dwc_ddrphy_apb_wr_32b(0x50c62, 0xa0080e);
dwc_ddrphy_apb_wr_32b(0x50c64, 0x71edd820);
dwc_ddrphy_apb_wr_32b(0x50c66, 0x900540c3);
dwc_ddrphy_apb_wr_32b(0x50c68, 0xb0e0e112);
dwc_ddrphy_apb_wr_32b(0x50c6a, 0x3c418de);
dwc_ddrphy_apb_wr_32b(0x50c6c, 0x710e1600);
dwc_ddrphy_apb_wr_32b(0x50c6e, 0x1969004);
dwc_ddrphy_apb_wr_32b(0x50c70, 0x10100d83);
dwc_ddrphy_apb_wr_32b(0x50c72, 0x13bf0e7f);
dwc_ddrphy_apb_wr_32b(0x50c74, 0x1c072684);
dwc_ddrphy_apb_wr_32b(0x50c76, 0x13c0264f);
dwc_ddrphy_apb_wr_32b(0x50c78, 0x900545cb);
dwc_ddrphy_apb_wr_32b(0x50c7a, 0xb500e196);
dwc_ddrphy_apb_wr_32b(0x50c7c, 0x2b40d80e);
dwc_ddrphy_apb_wr_32b(0x50c7e, 0xfd6355b);
dwc_ddrphy_apb_wr_32b(0x50c80, 0x1df60060);
dwc_ddrphy_apb_wr_32b(0x50c82, 0x208a9205);
dwc_ddrphy_apb_wr_32b(0x50c84, 0xb7e0a0f);
dwc_ddrphy_apb_wr_32b(0x50c86, 0x1df60060);
dwc_ddrphy_apb_wr_32b(0x50c88, 0xfc29245);
dwc_ddrphy_apb_wr_32b(0x50c8a, 0x781d0060);
dwc_ddrphy_apb_wr_32b(0x50c8c, 0x71001600);
dwc_ddrphy_apb_wr_32b(0x50c8e, 0x19e9004);
dwc_ddrphy_apb_wr_32b(0x50c90, 0x90451df0);
dwc_ddrphy_apb_wr_32b(0x50c92, 0x92051df6);
dwc_ddrphy_apb_wr_32b(0x50c94, 0x2004b809);
dwc_ddrphy_apb_wr_32b(0x50c96, 0xf80);
dwc_ddrphy_apb_wr_32b(0x50c98, 0x7e053e00);
dwc_ddrphy_apb_wr_32b(0x50c9a, 0x1380264f);
dwc_ddrphy_apb_wr_32b(0x50c9c, 0xcc0cb500);
dwc_ddrphy_apb_wr_32b(0x50c9e, 0x1f832605);
dwc_ddrphy_apb_wr_32b(0x50ca0, 0xc0000000);
dwc_ddrphy_apb_wr_32b(0x50ca2, 0x198218a);
dwc_ddrphy_apb_wr_32b(0x50ca4, 0x87d0208c);
dwc_ddrphy_apb_wr_32b(0x50ca6, 0x208cf715);
dwc_ddrphy_apb_wr_32b(0x50ca8, 0xf71183d0);
dwc_ddrphy_apb_wr_32b(0x50caa, 0x190228a);
dwc_ddrphy_apb_wr_32b(0x50cac, 0x840d208c);
dwc_ddrphy_apb_wr_32b(0x50cae, 0x8521ca);
dwc_ddrphy_apb_wr_32b(0x50cb0, 0x40c3f00b);
dwc_ddrphy_apb_wr_32b(0x50cb2, 0xe18c9005);
dwc_ddrphy_apb_wr_32b(0x50cb4, 0x2051800);
dwc_ddrphy_apb_wr_32b(0x50cb6, 0x83c418fa);
dwc_ddrphy_apb_wr_32b(0x50cb8, 0x218af00a);
dwc_ddrphy_apb_wr_32b(0x50cba, 0x23050190);
dwc_ddrphy_apb_wr_32b(0x50cbc, 0x2305305b);
dwc_ddrphy_apb_wr_32b(0x50cbe, 0x90123f80);
dwc_ddrphy_apb_wr_32b(0x50cc0, 0xb0600000);
dwc_ddrphy_apb_wr_32b(0x50cc2, 0x73c41e00);
dwc_ddrphy_apb_wr_32b(0x50cc4, 0xe0509013);
dwc_ddrphy_apb_wr_32b(0x50cc6, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x50cc8, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x50cca, 0xc1a4c2e4);
dwc_ddrphy_apb_wr_32b(0x50ccc, 0x702c4608);
dwc_ddrphy_apb_wr_32b(0x50cce, 0x754cd8ff);
dwc_ddrphy_apb_wr_32b(0x50cd0, 0x4528db08);
dwc_ddrphy_apb_wr_32b(0x50cd2, 0xc142c143);
dwc_ddrphy_apb_wr_32b(0x50cd4, 0xd62c141);
dwc_ddrphy_apb_wr_32b(0x50cd6, 0xc140ffaf);
dwc_ddrphy_apb_wr_32b(0x50cd8, 0xb88c700c);
dwc_ddrphy_apb_wr_32b(0x50cda, 0xc040d90c);
dwc_ddrphy_apb_wr_32b(0x50cdc, 0xb990d8ff);
dwc_ddrphy_apb_wr_32b(0x50cde, 0x746c714c);
dwc_ddrphy_apb_wr_32b(0x50ce0, 0xc642c543);
dwc_ddrphy_apb_wr_32b(0x50ce2, 0xffaf0d46);
dwc_ddrphy_apb_wr_32b(0x50ce4, 0xc0a4c541);
dwc_ddrphy_apb_wr_32b(0x50ce6, 0x78e0c6c4);
dwc_ddrphy_apb_wr_32b(0x50ce8, 0xc1a4c0f1);
dwc_ddrphy_apb_wr_32b(0x50cea, 0x700cc042);
dwc_ddrphy_apb_wr_32b(0x50cec, 0xb88cdb0c);
dwc_ddrphy_apb_wr_32b(0x50cee, 0xc0404160);
dwc_ddrphy_apb_wr_32b(0x50cf0, 0xb990d8ff);
dwc_ddrphy_apb_wr_32b(0x50cf2, 0x1c0c714c);
dwc_ddrphy_apb_wr_32b(0x50cf4, 0xd223001);
dwc_ddrphy_apb_wr_32b(0x50cf6, 0x1c04ffaf);
dwc_ddrphy_apb_wr_32b(0x50cf8, 0xc0a43001);
dwc_ddrphy_apb_wr_32b(0x50cfa, 0x7ee0c0d1);
dwc_ddrphy_apb_wr_32b(0x50cfc, 0x45cbc2e4);
dwc_ddrphy_apb_wr_32b(0x50cfe, 0x10a9004);
dwc_ddrphy_apb_wr_32b(0x50d00, 0x264f95c0);
dwc_ddrphy_apb_wr_32b(0x50d02, 0xb5001180);
dwc_ddrphy_apb_wr_32b(0x50d04, 0x600eca);
dwc_ddrphy_apb_wr_32b(0x50d06, 0xd820d810);
dwc_ddrphy_apb_wr_32b(0x50d08, 0x600ec2);
dwc_ddrphy_apb_wr_32b(0x50d0a, 0x905d1d7e);
dwc_ddrphy_apb_wr_32b(0x50d0c, 0xebad810);
dwc_ddrphy_apb_wr_32b(0x50d0e, 0x1d7e0060);
dwc_ddrphy_apb_wr_32b(0x50d10, 0xd810901d);
dwc_ddrphy_apb_wr_32b(0x50d12, 0x600eae);
dwc_ddrphy_apb_wr_32b(0x50d14, 0xc6c4b5c0);
dwc_ddrphy_apb_wr_32b(0x50d16, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x50d18, 0xbf2b6c8);
dwc_ddrphy_apb_wr_32b(0x50d1a, 0xc1a4ffaf);
dwc_ddrphy_apb_wr_32b(0x50d1c, 0xbfa700c);
dwc_ddrphy_apb_wr_32b(0x50d1e, 0xd9ffffaf);
dwc_ddrphy_apb_wr_32b(0x50d20, 0xab270ad);
dwc_ddrphy_apb_wr_32b(0x50d22, 0xdb07ff8f);
dwc_ddrphy_apb_wr_32b(0x50d24, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x50d26, 0xcbec541);
dwc_ddrphy_apb_wr_32b(0x50d28, 0xc540ffaf);
dwc_ddrphy_apb_wr_32b(0x50d2a, 0x736f70cd);
dwc_ddrphy_apb_wr_32b(0x50d2c, 0x11350d8f);
dwc_ddrphy_apb_wr_32b(0x50d2e, 0x1600700c);
dwc_ddrphy_apb_wr_32b(0x50d30, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x50d32, 0x87f0010);
dwc_ddrphy_apb_wr_32b(0x50d34, 0x710c036e);
dwc_ddrphy_apb_wr_32b(0x50d36, 0x71011600);
dwc_ddrphy_apb_wr_32b(0x50d38, 0x89a8000);
dwc_ddrphy_apb_wr_32b(0x50d3a, 0xc14078b8);
dwc_ddrphy_apb_wr_32b(0x50d3c, 0x7f0f702c);
dwc_ddrphy_apb_wr_32b(0x50d3e, 0xb990d8ff);
dwc_ddrphy_apb_wr_32b(0x50d40, 0x726c734c);
dwc_ddrphy_apb_wr_32b(0x50d42, 0xc742c643);
dwc_ddrphy_apb_wr_32b(0x50d44, 0xffaf0e6e);
dwc_ddrphy_apb_wr_32b(0x50d46, 0x36c01c04);
dwc_ddrphy_apb_wr_32b(0x50d48, 0x71001600);
dwc_ddrphy_apb_wr_32b(0x50d4a, 0x89a8000);
dwc_ddrphy_apb_wr_32b(0x50d4c, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x50d4e, 0xd8ffc040);
dwc_ddrphy_apb_wr_32b(0x50d50, 0xc643726c);
dwc_ddrphy_apb_wr_32b(0x50d52, 0xe52c742);
dwc_ddrphy_apb_wr_32b(0x50d54, 0x1c04ffaf);
dwc_ddrphy_apb_wr_32b(0x50d56, 0x160036c0);
dwc_ddrphy_apb_wr_32b(0x50d58, 0x80007100);
dwc_ddrphy_apb_wr_32b(0x50d5a, 0x702c089a);
dwc_ddrphy_apb_wr_32b(0x50d5c, 0xc040b990);
dwc_ddrphy_apb_wr_32b(0x50d5e, 0x734cd8ff);
dwc_ddrphy_apb_wr_32b(0x50d60, 0xc643db28);
dwc_ddrphy_apb_wr_32b(0x50d62, 0xe32c742);
dwc_ddrphy_apb_wr_32b(0x50d64, 0x1c04ffaf);
dwc_ddrphy_apb_wr_32b(0x50d66, 0xa2636c0);
dwc_ddrphy_apb_wr_32b(0x50d68, 0xdb28ff8f);
dwc_ddrphy_apb_wr_32b(0x50d6a, 0xc742c643);
dwc_ddrphy_apb_wr_32b(0x50d6c, 0x33c11c04);
dwc_ddrphy_apb_wr_32b(0x50d6e, 0xffaf0c2e);
dwc_ddrphy_apb_wr_32b(0x50d70, 0x71a5c640);
dwc_ddrphy_apb_wr_32b(0x50d72, 0xc043f1ba);
dwc_ddrphy_apb_wr_32b(0x50d74, 0xc041c042);
dwc_ddrphy_apb_wr_32b(0x50d76, 0xd8ffc040);
dwc_ddrphy_apb_wr_32b(0x50d78, 0x754cd980);
dwc_ddrphy_apb_wr_32b(0x50d7a, 0xffaf0c16);
dwc_ddrphy_apb_wr_32b(0x50d7c, 0x912746c);
dwc_ddrphy_apb_wr_32b(0x50d7e, 0xe66ff8f);
dwc_ddrphy_apb_wr_32b(0x50d80, 0xe6eff8f);
dwc_ddrphy_apb_wr_32b(0x50d82, 0x700cff8f);
dwc_ddrphy_apb_wr_32b(0x50d84, 0xffaf0b2a);
dwc_ddrphy_apb_wr_32b(0x50d86, 0x89ed9ff);
dwc_ddrphy_apb_wr_32b(0x50d88, 0x710c01a0);
dwc_ddrphy_apb_wr_32b(0x50d8a, 0x1404c0a4);
dwc_ddrphy_apb_wr_32b(0x50d8c, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x50d8e, 0x88ec0f1);
dwc_ddrphy_apb_wr_32b(0x50d90, 0x4320ffaf);
dwc_ddrphy_apb_wr_32b(0x50d92, 0x40604200);
dwc_ddrphy_apb_wr_32b(0x50d94, 0xffaf08ba);
dwc_ddrphy_apb_wr_32b(0x50d96, 0x60584140);
dwc_ddrphy_apb_wr_32b(0x50d98, 0x7fe0c0d1);
dwc_ddrphy_apb_wr_32b(0x50d9a, 0x78e0780f);
dwc_ddrphy_apb_wr_32b(0x50d9c, 0x4308c0f1);
dwc_ddrphy_apb_wr_32b(0x50d9e, 0x8b64040);
dwc_ddrphy_apb_wr_32b(0x50da0, 0x260affaf);
dwc_ddrphy_apb_wr_32b(0x50da2, 0x43003040);
dwc_ddrphy_apb_wr_32b(0x50da4, 0xffaf0862);
dwc_ddrphy_apb_wr_32b(0x50da6, 0x41004061);
dwc_ddrphy_apb_wr_32b(0x50da8, 0xffaf0892);
dwc_ddrphy_apb_wr_32b(0x50daa, 0x780200a);
dwc_ddrphy_apb_wr_32b(0x50dac, 0xc0d16078);
dwc_ddrphy_apb_wr_32b(0x50dae, 0x780f7fe0);
dwc_ddrphy_apb_wr_32b(0x50db0, 0x16007014);
dwc_ddrphy_apb_wr_32b(0x50db2, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x50db4, 0x41c30004);
dwc_ddrphy_apb_wr_32b(0x50db6, 0x1689004);
dwc_ddrphy_apb_wr_32b(0x50db8, 0x22221c2);
dwc_ddrphy_apb_wr_32b(0x50dba, 0x7905b815);
dwc_ddrphy_apb_wr_32b(0x50dbc, 0x91007fe0);
dwc_ddrphy_apb_wr_32b(0x50dbe, 0x1600c2e6);
dwc_ddrphy_apb_wr_32b(0x50dc0, 0x9004710d);
dwc_ddrphy_apb_wr_32b(0x50dc2, 0x47cb01c6);
dwc_ddrphy_apb_wr_32b(0x50dc4, 0xe1c69005);
dwc_ddrphy_apb_wr_32b(0x50dc6, 0xbdc9d80a);
dwc_ddrphy_apb_wr_32b(0x50dc8, 0x12ce254f);
dwc_ddrphy_apb_wr_32b(0x50dca, 0x600d3e);
dwc_ddrphy_apb_wr_32b(0x50dcc, 0x2505b7c0);
dwc_ddrphy_apb_wr_32b(0x50dce, 0x1f80);
dwc_ddrphy_apb_wr_32b(0x50dd0, 0xb7000c00);
dwc_ddrphy_apb_wr_32b(0x50dd2, 0x600d2e);
dwc_ddrphy_apb_wr_32b(0x50dd4, 0xd80ad80a);
dwc_ddrphy_apb_wr_32b(0x50dd6, 0x600d26);
dwc_ddrphy_apb_wr_32b(0x50dd8, 0x1600b7c0);
dwc_ddrphy_apb_wr_32b(0x50dda, 0x90027100);
dwc_ddrphy_apb_wr_32b(0x50ddc, 0xb7a001c8);
dwc_ddrphy_apb_wr_32b(0x50dde, 0xc6c6b8c9);
dwc_ddrphy_apb_wr_32b(0x50de0, 0xb99fd922);
dwc_ddrphy_apb_wr_32b(0x50de2, 0x70149100);
dwc_ddrphy_apb_wr_32b(0x50de4, 0x16007de0);
dwc_ddrphy_apb_wr_32b(0x50de6, 0x90047100);
dwc_ddrphy_apb_wr_32b(0x50de8, 0x7fe00008);
dwc_ddrphy_apb_wr_32b(0x50dea, 0x78e0b100);
dwc_ddrphy_apb_wr_32b(0x50dec, 0x43c3c2e6);
dwc_ddrphy_apb_wr_32b(0x50dee, 0x9888000);
dwc_ddrphy_apb_wr_32b(0x50df0, 0xa268300);
dwc_ddrphy_apb_wr_32b(0x50df2, 0x712cffef);
dwc_ddrphy_apb_wr_32b(0x50df4, 0x160083c1);
dwc_ddrphy_apb_wr_32b(0x50df6, 0x8000709e);
dwc_ddrphy_apb_wr_32b(0x50df8, 0x45080004);
dwc_ddrphy_apb_wr_32b(0x50dfa, 0x8302776d);
dwc_ddrphy_apb_wr_32b(0x50dfc, 0x3a2083f);
dwc_ddrphy_apb_wr_32b(0x50dfe, 0x12012b42);
dwc_ddrphy_apb_wr_32b(0x50e00, 0x26447fdc);
dwc_ddrphy_apb_wr_32b(0x50e02, 0x7aaf1041);
dwc_ddrphy_apb_wr_32b(0x50e04, 0x600862);
dwc_ddrphy_apb_wr_32b(0x50e06, 0xe81378ef);
dwc_ddrphy_apb_wr_32b(0x50e08, 0x2e4078bb);
dwc_ddrphy_apb_wr_32b(0x50e0a, 0x2056354c);
dwc_ddrphy_apb_wr_32b(0x50e0c, 0x7a850802);
dwc_ddrphy_apb_wr_32b(0x50e0e, 0x7ae5bf0d);
dwc_ddrphy_apb_wr_32b(0x50e10, 0x2402940);
dwc_ddrphy_apb_wr_32b(0x50e12, 0xb8917845);
dwc_ddrphy_apb_wr_32b(0x50e14, 0xb89fb89c);
dwc_ddrphy_apb_wr_32b(0x50e16, 0x23089000);
dwc_ddrphy_apb_wr_32b(0x50e18, 0x71c5100b);
dwc_ddrphy_apb_wr_32b(0x50e1a, 0x262ff1e1);
dwc_ddrphy_apb_wr_32b(0x50e1c, 0x21c0f2c7);
dwc_ddrphy_apb_wr_32b(0x50e1e, 0x69020062);
dwc_ddrphy_apb_wr_32b(0x50e20, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x50e22, 0xb89fd860);
dwc_ddrphy_apb_wr_32b(0x50e24, 0x6d59020);
dwc_ddrphy_apb_wr_32b(0x50e26, 0x10feffef);
dwc_ddrphy_apb_wr_32b(0x50e28, 0x78e08100);
dwc_ddrphy_apb_wr_32b(0x50e2a, 0xb89fd862);
dwc_ddrphy_apb_wr_32b(0x50e2c, 0x10fe9040);
dwc_ddrphy_apb_wr_32b(0x50e2e, 0x6dd8101);
dwc_ddrphy_apb_wr_32b(0x50e30, 0x10fcffef);
dwc_ddrphy_apb_wr_32b(0x50e32, 0x78e08100);
dwc_ddrphy_apb_wr_32b(0x50e34, 0x2078ca03);
dwc_ddrphy_apb_wr_32b(0x50e36, 0x793b0381);
dwc_ddrphy_apb_wr_32b(0x50e38, 0x21cae08c);
dwc_ddrphy_apb_wr_32b(0x50e3a, 0x7fe00061);
dwc_ddrphy_apb_wr_32b(0x50e3c, 0x78e04020);
dwc_ddrphy_apb_wr_32b(0x50e3e, 0x700026f4);
dwc_ddrphy_apb_wr_32b(0x50e40, 0x5e8000);
dwc_ddrphy_apb_wr_32b(0x50e42, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x50e44, 0x800042c3);
dwc_ddrphy_apb_wr_32b(0x50e46, 0xa2000988);
dwc_ddrphy_apb_wr_32b(0x50e48, 0x704026f4);
dwc_ddrphy_apb_wr_32b(0x50e4a, 0x5e8000);
dwc_ddrphy_apb_wr_32b(0x50e4c, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x50e4e, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x50e50, 0xc1a6b6c8);
dwc_ddrphy_apb_wr_32b(0x50e52, 0x40c3c044);
dwc_ddrphy_apb_wr_32b(0x50e54, 0x89a8000);
dwc_ddrphy_apb_wr_32b(0x50e56, 0x90204528);
dwc_ddrphy_apb_wr_32b(0x50e58, 0x700c90c1);
dwc_ddrphy_apb_wr_32b(0x50e5a, 0x97ec145);
dwc_ddrphy_apb_wr_32b(0x50e5c, 0xd9ffffaf);
dwc_ddrphy_apb_wr_32b(0x50e5e, 0x30831200);
dwc_ddrphy_apb_wr_32b(0x50e60, 0x83270ed);
dwc_ddrphy_apb_wr_32b(0x50e62, 0xc743ff8f);
dwc_ddrphy_apb_wr_32b(0x50e64, 0xc741c742);
dwc_ddrphy_apb_wr_32b(0x50e66, 0xffaf0a3e);
dwc_ddrphy_apb_wr_32b(0x50e68, 0xc005c740);
dwc_ddrphy_apb_wr_32b(0x50e6a, 0x26cf70b5);
dwc_ddrphy_apb_wr_32b(0x50e6c, 0x200412a1);
dwc_ddrphy_apb_wr_32b(0x50e6e, 0xffff0f9b);
dwc_ddrphy_apb_wr_32b(0x50e70, 0x234fe7f8);
dwc_ddrphy_apb_wr_32b(0x50e72, 0x72b5309b);
dwc_ddrphy_apb_wr_32b(0x50e74, 0x300123ca);
dwc_ddrphy_apb_wr_32b(0x50e76, 0xc004ed19);
dwc_ddrphy_apb_wr_32b(0x50e78, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x50e7a, 0xd8ffc042);
dwc_ddrphy_apb_wr_32b(0x50e7c, 0xc743db10);
dwc_ddrphy_apb_wr_32b(0x50e7e, 0x31011c04);
dwc_ddrphy_apb_wr_32b(0x50e80, 0xffaf0bf6);
dwc_ddrphy_apb_wr_32b(0x50e82, 0xc004c640);
dwc_ddrphy_apb_wr_32b(0x50e84, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x50e86, 0xd8ffc042);
dwc_ddrphy_apb_wr_32b(0x50e88, 0xc743db20);
dwc_ddrphy_apb_wr_32b(0x50e8a, 0x30c11c04);
dwc_ddrphy_apb_wr_32b(0x50e8c, 0x36c01c00);
dwc_ddrphy_apb_wr_32b(0x50e8e, 0xc004f018);
dwc_ddrphy_apb_wr_32b(0x50e90, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x50e92, 0xd8ffc042);
dwc_ddrphy_apb_wr_32b(0x50e94, 0xc743db20);
dwc_ddrphy_apb_wr_32b(0x50e96, 0x30c11c04);
dwc_ddrphy_apb_wr_32b(0x50e98, 0xffaf0bc6);
dwc_ddrphy_apb_wr_32b(0x50e9a, 0x36c01c00);
dwc_ddrphy_apb_wr_32b(0x50e9c, 0xc743c004);
dwc_ddrphy_apb_wr_32b(0x50e9e, 0x31011c04);
dwc_ddrphy_apb_wr_32b(0x50ea0, 0xc640c042);
dwc_ddrphy_apb_wr_32b(0x50ea2, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x50ea4, 0xdb10734c);
dwc_ddrphy_apb_wr_32b(0x50ea6, 0xff8f0baa);
dwc_ddrphy_apb_wr_32b(0x50ea8, 0xd8ff702c);
dwc_ddrphy_apb_wr_32b(0x50eaa, 0xdb32754c);
dwc_ddrphy_apb_wr_32b(0x50eac, 0x34011c0c);
dwc_ddrphy_apb_wr_32b(0x50eae, 0xc1424528);
dwc_ddrphy_apb_wr_32b(0x50eb0, 0x9aac141);
dwc_ddrphy_apb_wr_32b(0x50eb2, 0xc140ffaf);
dwc_ddrphy_apb_wr_32b(0x50eb4, 0xff4f0ec2);
dwc_ddrphy_apb_wr_32b(0x50eb6, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x50eb8, 0x99ac541);
dwc_ddrphy_apb_wr_32b(0x50eba, 0xc540ffaf);
dwc_ddrphy_apb_wr_32b(0x50ebc, 0xff4f0e92);
dwc_ddrphy_apb_wr_32b(0x50ebe, 0x1404c0a6);
dwc_ddrphy_apb_wr_32b(0x50ec0, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x50ec2, 0x2840c0e4);
dwc_ddrphy_apb_wr_32b(0x50ec4, 0x44cb024d);
dwc_ddrphy_apb_wr_32b(0x50ec6, 0x48900e);
dwc_ddrphy_apb_wr_32b(0x50ec8, 0x134e2405);
dwc_ddrphy_apb_wr_32b(0x50eca, 0x6c22b620);
dwc_ddrphy_apb_wr_32b(0x50ecc, 0x34c2105);
dwc_ddrphy_apb_wr_32b(0x50ece, 0xb4407224);
dwc_ddrphy_apb_wr_32b(0x50ed0, 0x3422105);
dwc_ddrphy_apb_wr_32b(0x50ed2, 0x6962b260);
dwc_ddrphy_apb_wr_32b(0x50ed4, 0x7d65c102);
dwc_ddrphy_apb_wr_32b(0x50ed6, 0x3f1080d);
dwc_ddrphy_apb_wr_32b(0x50ed8, 0x208ab520);
dwc_ddrphy_apb_wr_32b(0x50eda, 0xf0060fc7);
dwc_ddrphy_apb_wr_32b(0x50edc, 0x101137c);
dwc_ddrphy_apb_wr_32b(0x50ede, 0x210f);
dwc_ddrphy_apb_wr_32b(0x50ee0, 0x41b7c);
dwc_ddrphy_apb_wr_32b(0x50ee2, 0x78e0c4c4);
dwc_ddrphy_apb_wr_32b(0x50ee4, 0x900e44cb);
dwc_ddrphy_apb_wr_32b(0x50ee6, 0x1c0200c2);
dwc_ddrphy_apb_wr_32b(0x50ee8, 0xb4201014);
dwc_ddrphy_apb_wr_32b(0x50eea, 0x7fe0b441);
dwc_ddrphy_apb_wr_32b(0x50eec, 0x78e0b462);
dwc_ddrphy_apb_wr_32b(0x50eee, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x50ef0, 0x4508b6c8);
dwc_ddrphy_apb_wr_32b(0x50ef2, 0x4358ca0b);
dwc_ddrphy_apb_wr_32b(0x50ef4, 0x7a16da08);
dwc_ddrphy_apb_wr_32b(0x50ef6, 0x900340c3);
dwc_ddrphy_apb_wr_32b(0x50ef8, 0xb040e024);
dwc_ddrphy_apb_wr_32b(0x50efa, 0xfc7228a);
dwc_ddrphy_apb_wr_32b(0x50efc, 0x45180c);
dwc_ddrphy_apb_wr_32b(0x50efe, 0x808418fe);
dwc_ddrphy_apb_wr_32b(0x50f00, 0x800042c3);
dwc_ddrphy_apb_wr_32b(0x50f02, 0x82600994);
dwc_ddrphy_apb_wr_32b(0x50f04, 0x8458201);
dwc_ddrphy_apb_wr_32b(0x50f06, 0x2b4000e2);
dwc_ddrphy_apb_wr_32b(0x50f08, 0x21f4034c);
dwc_ddrphy_apb_wr_32b(0x50f0a, 0x240500ce);
dwc_ddrphy_apb_wr_32b(0x50f0c, 0x90021f80);
dwc_ddrphy_apb_wr_32b(0x50f0e, 0xb0c01064);
dwc_ddrphy_apb_wr_32b(0x50f10, 0x1f8c2405);
dwc_ddrphy_apb_wr_32b(0x50f12, 0x49002);
dwc_ddrphy_apb_wr_32b(0x50f14, 0x30300b15);
dwc_ddrphy_apb_wr_32b(0x50f16, 0xc021f4);
dwc_ddrphy_apb_wr_32b(0x50f18, 0xf840813);
dwc_ddrphy_apb_wr_32b(0x50f1a, 0xfc000000);
dwc_ddrphy_apb_wr_32b(0x50f1c, 0xf007d820);
dwc_ddrphy_apb_wr_32b(0x50f1e, 0x8010208c);
dwc_ddrphy_apb_wr_32b(0x50f20, 0x208af7bc);
dwc_ddrphy_apb_wr_32b(0x50f22, 0xb4000808);
dwc_ddrphy_apb_wr_32b(0x50f24, 0xf1e07164);
dwc_ddrphy_apb_wr_32b(0x50f26, 0x800c4e);
dwc_ddrphy_apb_wr_32b(0x50f28, 0x30300b0b);
dwc_ddrphy_apb_wr_32b(0x50f2a, 0x730c8529);
dwc_ddrphy_apb_wr_32b(0x50f2c, 0x710cf002);
dwc_ddrphy_apb_wr_32b(0x50f2e, 0x1400eca);
dwc_ddrphy_apb_wr_32b(0x50f30, 0x46cb70ed);
dwc_ddrphy_apb_wr_32b(0x50f32, 0xe1749003);
dwc_ddrphy_apb_wr_32b(0x50f34, 0xb6e1b6e0);
dwc_ddrphy_apb_wr_32b(0x50f36, 0xf1e8500);
dwc_ddrphy_apb_wr_32b(0x50f38, 0x120b01e0);
dwc_ddrphy_apb_wr_32b(0x50f3a, 0x85073081);
dwc_ddrphy_apb_wr_32b(0x50f3c, 0x10030f0d);
dwc_ddrphy_apb_wr_32b(0x50f3e, 0x20008be);
dwc_ddrphy_apb_wr_32b(0x50f40, 0xf1fb71e5);
dwc_ddrphy_apb_wr_32b(0x50f42, 0x30300b0d);
dwc_ddrphy_apb_wr_32b(0x50f44, 0xfc7208a);
dwc_ddrphy_apb_wr_32b(0x50f46, 0xf003b600);
dwc_ddrphy_apb_wr_32b(0x50f48, 0x8500b601);
dwc_ddrphy_apb_wr_32b(0x50f4a, 0x1e00ef6);
dwc_ddrphy_apb_wr_32b(0x50f4c, 0x3081120b);
dwc_ddrphy_apb_wr_32b(0x50f4e, 0x850570cd);
dwc_ddrphy_apb_wr_32b(0x50f50, 0x382080d);
dwc_ddrphy_apb_wr_32b(0x50f52, 0x2000896);
dwc_ddrphy_apb_wr_32b(0x50f54, 0xf1fb71c5);
dwc_ddrphy_apb_wr_32b(0x50f56, 0x30300b0b);
dwc_ddrphy_apb_wr_32b(0x50f58, 0x85028d58);
dwc_ddrphy_apb_wr_32b(0x50f5a, 0x8501f002);
dwc_ddrphy_apb_wr_32b(0x50f5c, 0x1200f5a);
dwc_ddrphy_apb_wr_32b(0x50f5e, 0x1404712c);
dwc_ddrphy_apb_wr_32b(0x50f60, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x50f62, 0xb90a781b);
dwc_ddrphy_apb_wr_32b(0x50f64, 0xf802005);
dwc_ddrphy_apb_wr_32b(0x50f66, 0xe0649003);
dwc_ddrphy_apb_wr_32b(0x50f68, 0x3c9e11f);
dwc_ddrphy_apb_wr_32b(0x50f6a, 0xb02000a0);
dwc_ddrphy_apb_wr_32b(0x50f6c, 0xa13704c);
dwc_ddrphy_apb_wr_32b(0x50f6e, 0x201401f5);
dwc_ddrphy_apb_wr_32b(0x50f70, 0x19000081);
dwc_ddrphy_apb_wr_32b(0x50f72, 0x71440005);
dwc_ddrphy_apb_wr_32b(0x50f74, 0xda5ef1f9);
dwc_ddrphy_apb_wr_32b(0x50f76, 0x1202ba9f);
dwc_ddrphy_apb_wr_32b(0x50f78, 0xb0200501);
dwc_ddrphy_apb_wr_32b(0x50f7a, 0x5011202);
dwc_ddrphy_apb_wr_32b(0x50f7c, 0x1202b021);
dwc_ddrphy_apb_wr_32b(0x50f7e, 0xb0220501);
dwc_ddrphy_apb_wr_32b(0x50f80, 0x5011202);
dwc_ddrphy_apb_wr_32b(0x50f82, 0x9220b023);
dwc_ddrphy_apb_wr_32b(0x50f84, 0x9221b024);
dwc_ddrphy_apb_wr_32b(0x50f86, 0x9222b025);
dwc_ddrphy_apb_wr_32b(0x50f88, 0xb0267fe0);
dwc_ddrphy_apb_wr_32b(0x50f8a, 0xc1abc3e2);
dwc_ddrphy_apb_wr_32b(0x50f8c, 0x41c3c080);
dwc_ddrphy_apb_wr_32b(0x50f8e, 0x83f8000);
dwc_ddrphy_apb_wr_32b(0x50f90, 0xff2f0962);
dwc_ddrphy_apb_wr_32b(0x50f92, 0xc080da2a);
dwc_ddrphy_apb_wr_32b(0x50f94, 0x2600a96);
dwc_ddrphy_apb_wr_32b(0x50f96, 0xd1ad92a);
dwc_ddrphy_apb_wr_32b(0x50f98, 0xd26ffcf);
dwc_ddrphy_apb_wr_32b(0x50f9a, 0x4508ffef);
dwc_ddrphy_apb_wr_32b(0x50f9c, 0xbe24100);
dwc_ddrphy_apb_wr_32b(0x50f9e, 0x40a10160);
dwc_ddrphy_apb_wr_32b(0x50fa0, 0xffcf0c82);
dwc_ddrphy_apb_wr_32b(0x50fa2, 0xc12053);
dwc_ddrphy_apb_wr_32b(0x50fa4, 0x30421a01);
dwc_ddrphy_apb_wr_32b(0x50fa6, 0xa01206d);
dwc_ddrphy_apb_wr_32b(0x50fa8, 0x90120ad);
dwc_ddrphy_apb_wr_32b(0x50faa, 0x30421a06);
dwc_ddrphy_apb_wr_32b(0x50fac, 0x1a02702c);
dwc_ddrphy_apb_wr_32b(0x50fae, 0xca023002);
dwc_ddrphy_apb_wr_32b(0x50fb0, 0x25091d);
dwc_ddrphy_apb_wr_32b(0x50fb2, 0x3402940);
dwc_ddrphy_apb_wr_32b(0x50fb4, 0xf802005);
dwc_ddrphy_apb_wr_32b(0x50fb6, 0x1549002);
dwc_ddrphy_apb_wr_32b(0x50fb8, 0x71249040);
dwc_ddrphy_apb_wr_32b(0x50fba, 0xc032284);
dwc_ddrphy_apb_wr_32b(0x50fbc, 0xf1f3b040);
dwc_ddrphy_apb_wr_32b(0x50fbe, 0x70451e00);
dwc_ddrphy_apb_wr_32b(0x50fc0, 0xff689003);
dwc_ddrphy_apb_wr_32b(0x50fc2, 0x9de);
dwc_ddrphy_apb_wr_32b(0x50fc4, 0x1400a5e);
dwc_ddrphy_apb_wr_32b(0x50fc6, 0x1400eaa);
dwc_ddrphy_apb_wr_32b(0x50fc8, 0x78e0c7c2);
dwc_ddrphy_apb_wr_32b(0x50fca, 0xc1bbc3e2);
dwc_ddrphy_apb_wr_32b(0x50fcc, 0xc0804508);
dwc_ddrphy_apb_wr_32b(0x50fce, 0x800041c3);
dwc_ddrphy_apb_wr_32b(0x50fd0, 0x8e206c8);
dwc_ddrphy_apb_wr_32b(0x50fd2, 0xda6cff2f);
dwc_ddrphy_apb_wr_32b(0x50fd4, 0xa16c080);
dwc_ddrphy_apb_wr_32b(0x50fd6, 0xd96c0260);
dwc_ddrphy_apb_wr_32b(0x50fd8, 0x208aed07);
dwc_ddrphy_apb_wr_32b(0x50fda, 0x1e000c07);
dwc_ddrphy_apb_wr_32b(0x50fdc, 0x90037004);
dwc_ddrphy_apb_wr_32b(0x50fde, 0xc7c2e8c4);
dwc_ddrphy_apb_wr_32b(0x50fe0, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x50fe2, 0xc1a7b6c8);
dwc_ddrphy_apb_wr_32b(0x50fe4, 0xffef0c8e);
dwc_ddrphy_apb_wr_32b(0x50fe6, 0xc7a4708);
dwc_ddrphy_apb_wr_32b(0x50fe8, 0xc044ffef);
dwc_ddrphy_apb_wr_32b(0x50fea, 0x308d1207);
dwc_ddrphy_apb_wr_32b(0x50fec, 0xffef0c02);
dwc_ddrphy_apb_wr_32b(0x50fee, 0xc046c045);
dwc_ddrphy_apb_wr_32b(0x50ff0, 0xe52700c);
dwc_ddrphy_apb_wr_32b(0x50ff2, 0x41a1ff6f);
dwc_ddrphy_apb_wr_32b(0x50ff4, 0x702cca00);
dwc_ddrphy_apb_wr_32b(0x50ff6, 0x760470ad);
dwc_ddrphy_apb_wr_32b(0x50ff8, 0xd8ff7b0f);
dwc_ddrphy_apb_wr_32b(0x50ffa, 0x754cb98e);
dwc_ddrphy_apb_wr_32b(0x50ffc, 0xc742c543);
dwc_ddrphy_apb_wr_32b(0x50ffe, 0xf0ec541);
dwc_ddrphy_apb_wr_32b(0x51000, 0xc540ff6f);
dwc_ddrphy_apb_wr_32b(0x51002, 0x716fd911);
dwc_ddrphy_apb_wr_32b(0x51004, 0xb90ad8ff);
dwc_ddrphy_apb_wr_32b(0x51006, 0xdb7c704c);
dwc_ddrphy_apb_wr_32b(0x51008, 0x36c01c0c);
dwc_ddrphy_apb_wr_32b(0x5100a, 0xc541c742);
dwc_ddrphy_apb_wr_32b(0x5100c, 0xff6f0ef2);
dwc_ddrphy_apb_wr_32b(0x5100e, 0x95ec540);
dwc_ddrphy_apb_wr_32b(0x51010, 0xd8ffffaf);
dwc_ddrphy_apb_wr_32b(0x51012, 0x702c70cd);
dwc_ddrphy_apb_wr_32b(0x51014, 0xd8ffbe8c);
dwc_ddrphy_apb_wr_32b(0x51016, 0x724cb990);
dwc_ddrphy_apb_wr_32b(0x51018, 0x1c0c746c);
dwc_ddrphy_apb_wr_32b(0x5101a, 0xc74230c1);
dwc_ddrphy_apb_wr_32b(0x5101c, 0x36c01c04);
dwc_ddrphy_apb_wr_32b(0x5101e, 0xff6f0ece);
dwc_ddrphy_apb_wr_32b(0x51020, 0xd911c640);
dwc_ddrphy_apb_wr_32b(0x51022, 0xb90ad8ff);
dwc_ddrphy_apb_wr_32b(0x51024, 0x746c724c);
dwc_ddrphy_apb_wr_32b(0x51026, 0xc742c543);
dwc_ddrphy_apb_wr_32b(0x51028, 0xebac541);
dwc_ddrphy_apb_wr_32b(0x5102a, 0xc640ff6f);
dwc_ddrphy_apb_wr_32b(0x5102c, 0xd8ffd911);
dwc_ddrphy_apb_wr_32b(0x5102e, 0x724cb90a);
dwc_ddrphy_apb_wr_32b(0x51030, 0xc543746c);
dwc_ddrphy_apb_wr_32b(0x51032, 0x1c04c742);
dwc_ddrphy_apb_wr_32b(0x51034, 0xea236c0);
dwc_ddrphy_apb_wr_32b(0x51036, 0xc640ff6f);
dwc_ddrphy_apb_wr_32b(0x51038, 0xd8ff702c);
dwc_ddrphy_apb_wr_32b(0x5103a, 0x724cb990);
dwc_ddrphy_apb_wr_32b(0x5103c, 0x1c0c746c);
dwc_ddrphy_apb_wr_32b(0x5103e, 0xc7423141);
dwc_ddrphy_apb_wr_32b(0x51040, 0x36c01c04);
dwc_ddrphy_apb_wr_32b(0x51042, 0xff6f0e86);
dwc_ddrphy_apb_wr_32b(0x51044, 0xc004c640);
dwc_ddrphy_apb_wr_32b(0x51046, 0xc543754c);
dwc_ddrphy_apb_wr_32b(0x51048, 0x2044e020);
dwc_ddrphy_apb_wr_32b(0x5104a, 0xc0040041);
dwc_ddrphy_apb_wr_32b(0x5104c, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x5104e, 0xe0206038);
dwc_ddrphy_apb_wr_32b(0x51050, 0xd8ff7b0f);
dwc_ddrphy_apb_wr_32b(0x51052, 0xe66702c);
dwc_ddrphy_apb_wr_32b(0x51054, 0xc540ff6f);
dwc_ddrphy_apb_wr_32b(0x51056, 0xffef0926);
dwc_ddrphy_apb_wr_32b(0x51058, 0xd91140e1);
dwc_ddrphy_apb_wr_32b(0x5105a, 0xb90ad8ff);
dwc_ddrphy_apb_wr_32b(0x5105c, 0x746c714c);
dwc_ddrphy_apb_wr_32b(0x5105e, 0xc742c543);
dwc_ddrphy_apb_wr_32b(0x51060, 0xe4ac541);
dwc_ddrphy_apb_wr_32b(0x51062, 0xc640ff6f);
dwc_ddrphy_apb_wr_32b(0x51064, 0xd8ffd911);
dwc_ddrphy_apb_wr_32b(0x51066, 0x714cb90a);
dwc_ddrphy_apb_wr_32b(0x51068, 0xc543746c);
dwc_ddrphy_apb_wr_32b(0x5106a, 0x1c04c742);
dwc_ddrphy_apb_wr_32b(0x5106c, 0xe3236c0);
dwc_ddrphy_apb_wr_32b(0x5106e, 0xc640ff6f);
dwc_ddrphy_apb_wr_32b(0x51070, 0xffef08b6);
dwc_ddrphy_apb_wr_32b(0x51072, 0xc10640e1);
dwc_ddrphy_apb_wr_32b(0x51074, 0x754cc005);
dwc_ddrphy_apb_wr_32b(0x51076, 0x2014c543);
dwc_ddrphy_apb_wr_32b(0x51078, 0x21540041);
dwc_ddrphy_apb_wr_32b(0x5107a, 0xb8c00c80);
dwc_ddrphy_apb_wr_32b(0x5107c, 0x20546038);
dwc_ddrphy_apb_wr_32b(0x5107e, 0x7b0f0c80);
dwc_ddrphy_apb_wr_32b(0x51080, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x51082, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x51084, 0xff6f0e02);
dwc_ddrphy_apb_wr_32b(0x51086, 0x700cc540);
dwc_ddrphy_apb_wr_32b(0x51088, 0x791bb88e);
dwc_ddrphy_apb_wr_32b(0x5108a, 0xff4f0c16);
dwc_ddrphy_apb_wr_32b(0x5108c, 0x30c11c0c);
dwc_ddrphy_apb_wr_32b(0x5108e, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x51090, 0xff6f0dea);
dwc_ddrphy_apb_wr_32b(0x51092, 0xbcec540);
dwc_ddrphy_apb_wr_32b(0x51094, 0xdb40ff4f);
dwc_ddrphy_apb_wr_32b(0x51096, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x51098, 0xddac541);
dwc_ddrphy_apb_wr_32b(0x5109a, 0xc540ff6f);
dwc_ddrphy_apb_wr_32b(0x5109c, 0xffaf0816);
dwc_ddrphy_apb_wr_32b(0x5109e, 0x208ad8ff);
dwc_ddrphy_apb_wr_32b(0x510a0, 0xc0400010);
dwc_ddrphy_apb_wr_32b(0x510a2, 0xd980d8ff);
dwc_ddrphy_apb_wr_32b(0x510a4, 0x746c764c);
dwc_ddrphy_apb_wr_32b(0x510a6, 0xc742c543);
dwc_ddrphy_apb_wr_32b(0x510a8, 0xff6f0dba);
dwc_ddrphy_apb_wr_32b(0x510aa, 0xc0a7c541);
dwc_ddrphy_apb_wr_32b(0x510ac, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x510ae, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x510b0, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x510b2, 0x1600b6c8);
dwc_ddrphy_apb_wr_32b(0x510b4, 0x90047101);
dwc_ddrphy_apb_wr_32b(0x510b6, 0x160001e0);
dwc_ddrphy_apb_wr_32b(0x510b8, 0x80007082);
dwc_ddrphy_apb_wr_32b(0x510ba, 0x6a120004);
dwc_ddrphy_apb_wr_32b(0x510bc, 0x2901);
dwc_ddrphy_apb_wr_32b(0x510be, 0x80db8c3);
dwc_ddrphy_apb_wr_32b(0x510c0, 0x8930190);
dwc_ddrphy_apb_wr_32b(0x510c2, 0x702c0071);
dwc_ddrphy_apb_wr_32b(0x510c4, 0x900446cb);
dwc_ddrphy_apb_wr_32b(0x510c6, 0x47cb0116);
dwc_ddrphy_apb_wr_32b(0x510c8, 0x25a00026);
dwc_ddrphy_apb_wr_32b(0x510ca, 0x10941e08);
dwc_ddrphy_apb_wr_32b(0x510cc, 0x702c40e1);
dwc_ddrphy_apb_wr_32b(0x510ce, 0xf9e71ad);
dwc_ddrphy_apb_wr_32b(0x510d0, 0x1e020020);
dwc_ddrphy_apb_wr_32b(0x510d2, 0xd8291055);
dwc_ddrphy_apb_wr_32b(0x510d4, 0x1e6cb6a0);
dwc_ddrphy_apb_wr_32b(0x510d6, 0x1e6c1205);
dwc_ddrphy_apb_wr_32b(0x510d8, 0x702c1004);
dwc_ddrphy_apb_wr_32b(0x510da, 0x43286f12);
dwc_ddrphy_apb_wr_32b(0x510dc, 0x90441ef2);
dwc_ddrphy_apb_wr_32b(0x510de, 0x200f7e);
dwc_ddrphy_apb_wr_32b(0x510e0, 0x10441e66);
dwc_ddrphy_apb_wr_32b(0x510e2, 0x1e6cd8a9);
dwc_ddrphy_apb_wr_32b(0x510e4, 0x208a1004);
dwc_ddrphy_apb_wr_32b(0x510e6, 0x1e6c0a46);
dwc_ddrphy_apb_wr_32b(0x510e8, 0x208a1004);
dwc_ddrphy_apb_wr_32b(0x510ea, 0x1e6c0a44);
dwc_ddrphy_apb_wr_32b(0x510ec, 0x1e6c1004);
dwc_ddrphy_apb_wr_32b(0x510ee, 0x700c1004);
dwc_ddrphy_apb_wr_32b(0x510f0, 0xa0f218a);
dwc_ddrphy_apb_wr_32b(0x510f2, 0x935c1e72);
dwc_ddrphy_apb_wr_32b(0x510f4, 0x93441ed0);
dwc_ddrphy_apb_wr_32b(0x510f6, 0x90dd1e72);
dwc_ddrphy_apb_wr_32b(0x510f8, 0x200f4a);
dwc_ddrphy_apb_wr_32b(0x510fa, 0x92c41ed0);
dwc_ddrphy_apb_wr_32b(0x510fc, 0xd920700c);
dwc_ddrphy_apb_wr_32b(0x510fe, 0x935c1e72);
dwc_ddrphy_apb_wr_32b(0x51100, 0x200f3a);
dwc_ddrphy_apb_wr_32b(0x51102, 0x92dc1e72);
dwc_ddrphy_apb_wr_32b(0x51104, 0x12c41ed0);
dwc_ddrphy_apb_wr_32b(0x51106, 0x909d1e72);
dwc_ddrphy_apb_wr_32b(0x51108, 0x45cbf054);
dwc_ddrphy_apb_wr_32b(0x5110a, 0x1169004);
dwc_ddrphy_apb_wr_32b(0x5110c, 0x10941d08);
dwc_ddrphy_apb_wr_32b(0x5110e, 0x2640c3);
dwc_ddrphy_apb_wr_32b(0x51110, 0x71ed25a0);
dwc_ddrphy_apb_wr_32b(0x51112, 0x200f16);
dwc_ddrphy_apb_wr_32b(0x51114, 0x10551d02);
dwc_ddrphy_apb_wr_32b(0x51116, 0x264ade18);
dwc_ddrphy_apb_wr_32b(0x51118, 0x702c3200);
dwc_ddrphy_apb_wr_32b(0x5111a, 0x40c3be8b);
dwc_ddrphy_apb_wr_32b(0x5111c, 0x4240000f);
dwc_ddrphy_apb_wr_32b(0x5111e, 0x1d6cb5e0);
dwc_ddrphy_apb_wr_32b(0x51120, 0x43381784);
dwc_ddrphy_apb_wr_32b(0x51122, 0x90441df2);
dwc_ddrphy_apb_wr_32b(0x51124, 0x10441d66);
dwc_ddrphy_apb_wr_32b(0x51126, 0x13841d6c);
dwc_ddrphy_apb_wr_32b(0x51128, 0x200eea);
dwc_ddrphy_apb_wr_32b(0x5112a, 0xbe704308);
dwc_ddrphy_apb_wr_32b(0x5112c, 0x2c2202f);
dwc_ddrphy_apb_wr_32b(0x5112e, 0xede702c);
dwc_ddrphy_apb_wr_32b(0x51130, 0x1d6c0020);
dwc_ddrphy_apb_wr_32b(0x51132, 0x40c31384);
dwc_ddrphy_apb_wr_32b(0x51134, 0x25a00026);
dwc_ddrphy_apb_wr_32b(0x51136, 0x702cb802);
dwc_ddrphy_apb_wr_32b(0x51138, 0x200eca);
dwc_ddrphy_apb_wr_32b(0x5113a, 0x17841d6c);
dwc_ddrphy_apb_wr_32b(0x5113c, 0x1d6cd888);
dwc_ddrphy_apb_wr_32b(0x5113e, 0x700c1004);
dwc_ddrphy_apb_wr_32b(0x51140, 0xa0f218a);
dwc_ddrphy_apb_wr_32b(0x51142, 0x17841d6c);
dwc_ddrphy_apb_wr_32b(0x51144, 0x16c41d6c);
dwc_ddrphy_apb_wr_32b(0x51146, 0x93dc1d72);
dwc_ddrphy_apb_wr_32b(0x51148, 0x93c41dd0);
dwc_ddrphy_apb_wr_32b(0x5114a, 0x90dd1d72);
dwc_ddrphy_apb_wr_32b(0x5114c, 0x200ea2);
dwc_ddrphy_apb_wr_32b(0x5114e, 0x96c41dd0);
dwc_ddrphy_apb_wr_32b(0x51150, 0xd920700c);
dwc_ddrphy_apb_wr_32b(0x51152, 0x93dc1d72);
dwc_ddrphy_apb_wr_32b(0x51154, 0x200e92);
dwc_ddrphy_apb_wr_32b(0x51156, 0x96dc1d72);
dwc_ddrphy_apb_wr_32b(0x51158, 0x16c41dd0);
dwc_ddrphy_apb_wr_32b(0x5115a, 0x909d1d72);
dwc_ddrphy_apb_wr_32b(0x5115c, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x5115e, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x51160, 0xaa6c0f1);
dwc_ddrphy_apb_wr_32b(0x51162, 0xc0d10040);
dwc_ddrphy_apb_wr_32b(0x51164, 0x700c7fe0);
dwc_ddrphy_apb_wr_32b(0x51166, 0x1600c0e6);
dwc_ddrphy_apb_wr_32b(0x51168, 0x80007083);
dwc_ddrphy_apb_wr_32b(0x5116a, 0x7b0b0013);
dwc_ddrphy_apb_wr_32b(0x5116c, 0xf246706c);
dwc_ddrphy_apb_wr_32b(0x5116e, 0x7efb92e0);
dwc_ddrphy_apb_wr_32b(0x51170, 0x1f832704);
dwc_ddrphy_apb_wr_32b(0x51172, 0xd6070000);
dwc_ddrphy_apb_wr_32b(0x51174, 0x140d2644);
dwc_ddrphy_apb_wr_32b(0x51176, 0x7bfd7d65);
dwc_ddrphy_apb_wr_32b(0x51178, 0x234443c9);
dwc_ddrphy_apb_wr_32b(0x5117a, 0x2384020c);
dwc_ddrphy_apb_wr_32b(0x5117c, 0x7ca51001);
dwc_ddrphy_apb_wr_32b(0x5117e, 0x130b2305);
dwc_ddrphy_apb_wr_32b(0x51180, 0x80c2344);
dwc_ddrphy_apb_wr_32b(0x51182, 0x12cc2405);
dwc_ddrphy_apb_wr_32b(0x51184, 0x10042684);
dwc_ddrphy_apb_wr_32b(0x51186, 0x23847e85);
dwc_ddrphy_apb_wr_32b(0x51188, 0x70ad0002);
dwc_ddrphy_apb_wr_32b(0x5118a, 0x6f727e65);
dwc_ddrphy_apb_wr_32b(0x5118c, 0x7ba4bd8d);
dwc_ddrphy_apb_wr_32b(0x5118e, 0x38c2305);
dwc_ddrphy_apb_wr_32b(0x51190, 0x2d41bf22);
dwc_ddrphy_apb_wr_32b(0x51192, 0x7be41083);
dwc_ddrphy_apb_wr_32b(0x51194, 0x89607c65);
dwc_ddrphy_apb_wr_32b(0x51196, 0x236c7e7b);
dwc_ddrphy_apb_wr_32b(0x51198, 0x2644004f);
dwc_ddrphy_apb_wr_32b(0x5119a, 0x7de5108d);
dwc_ddrphy_apb_wr_32b(0x5119c, 0x27447f7d);
dwc_ddrphy_apb_wr_32b(0x5119e, 0x7ba51043);
dwc_ddrphy_apb_wr_32b(0x511a0, 0x708d1600);
dwc_ddrphy_apb_wr_32b(0x511a2, 0x6c8000);
dwc_ddrphy_apb_wr_32b(0x511a4, 0x7d0b43e9);
dwc_ddrphy_apb_wr_32b(0x511a6, 0x2644f409);
dwc_ddrphy_apb_wr_32b(0x511a8, 0x2344120d);
dwc_ddrphy_apb_wr_32b(0x511aa, 0x23841100);
dwc_ddrphy_apb_wr_32b(0x511ac, 0x78a50cc3);
dwc_ddrphy_apb_wr_32b(0x511ae, 0xa9607b05);
dwc_ddrphy_apb_wr_32b(0x511b0, 0xb280716c);
dwc_ddrphy_apb_wr_32b(0x511b2, 0xc4c64060);
dwc_ddrphy_apb_wr_32b(0x511b4, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x511b6, 0x41c3b6c8);
dwc_ddrphy_apb_wr_32b(0x511b8, 0x1e89008);
dwc_ddrphy_apb_wr_32b(0x511ba, 0x21599100);
dwc_ddrphy_apb_wr_32b(0x511bc, 0x77040f4d);
dwc_ddrphy_apb_wr_32b(0x511be, 0x781b7810);
dwc_ddrphy_apb_wr_32b(0x511c0, 0x34e2005);
dwc_ddrphy_apb_wr_32b(0x511c2, 0x1600651d);
dwc_ddrphy_apb_wr_32b(0x511c4, 0x15c0111b);
dwc_ddrphy_apb_wr_32b(0x511c6, 0x8fa110f);
dwc_ddrphy_apb_wr_32b(0x511c8, 0xd8960020);
dwc_ddrphy_apb_wr_32b(0x511ca, 0x6822b824);
dwc_ddrphy_apb_wr_32b(0x511cc, 0xb8e07104);
dwc_ddrphy_apb_wr_32b(0x511ce, 0x121ca);
dwc_ddrphy_apb_wr_32b(0x511d0, 0xd9ff782f);
dwc_ddrphy_apb_wr_32b(0x511d2, 0x2304b908);
dwc_ddrphy_apb_wr_32b(0x511d4, 0x2005305b);
dwc_ddrphy_apb_wr_32b(0x511d6, 0x79e406c0);
dwc_ddrphy_apb_wr_32b(0x511d8, 0x2145b600);
dwc_ddrphy_apb_wr_32b(0x511da, 0x1dc003c0);
dwc_ddrphy_apb_wr_32b(0x511dc, 0x14041004);
dwc_ddrphy_apb_wr_32b(0x511de, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x511e0, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x511e2, 0xc1a5b6c8);
dwc_ddrphy_apb_wr_32b(0x511e4, 0xf8f2104);
dwc_ddrphy_apb_wr_32b(0x511e6, 0xe7f80000);
dwc_ddrphy_apb_wr_32b(0x511e8, 0x4608c244);
dwc_ddrphy_apb_wr_32b(0x511ea, 0xbf82c042);
dwc_ddrphy_apb_wr_32b(0x511ec, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x511ee, 0x4378734c);
dwc_ddrphy_apb_wr_32b(0x511f0, 0x1c0c70ad);
dwc_ddrphy_apb_wr_32b(0x511f2, 0x1c043001);
dwc_ddrphy_apb_wr_32b(0x511f4, 0xb2230c1);
dwc_ddrphy_apb_wr_32b(0x511f6, 0xc740ff6f);
dwc_ddrphy_apb_wr_32b(0x511f8, 0x11350d23);
dwc_ddrphy_apb_wr_32b(0x511fa, 0xc04178af);
dwc_ddrphy_apb_wr_32b(0x511fc, 0x702cc004);
dwc_ddrphy_apb_wr_32b(0x511fe, 0xc040da16);
dwc_ddrphy_apb_wr_32b(0x51200, 0x4363d8ff);
dwc_ddrphy_apb_wr_32b(0x51202, 0x30011c0c);
dwc_ddrphy_apb_wr_32b(0x51204, 0xff6f0b02);
dwc_ddrphy_apb_wr_32b(0x51206, 0x71a5c642);
dwc_ddrphy_apb_wr_32b(0x51208, 0x1600f1f0);
dwc_ddrphy_apb_wr_32b(0x5120a, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x5120c, 0x8110001);
dwc_ddrphy_apb_wr_32b(0x5120e, 0x78db01bf);
dwc_ddrphy_apb_wr_32b(0x51210, 0x1404c0a5);
dwc_ddrphy_apb_wr_32b(0x51212, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x51214, 0xd8ff7e0f);
dwc_ddrphy_apb_wr_32b(0x51216, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x51218, 0x70ad4363);
dwc_ddrphy_apb_wr_32b(0x5121a, 0x30011c0c);
dwc_ddrphy_apb_wr_32b(0x5121c, 0x30c11c04);
dwc_ddrphy_apb_wr_32b(0x5121e, 0xacec740);
dwc_ddrphy_apb_wr_32b(0x51220, 0xc642ff6f);
dwc_ddrphy_apb_wr_32b(0x51222, 0x91350ddd);
dwc_ddrphy_apb_wr_32b(0x51224, 0xc04178af);
dwc_ddrphy_apb_wr_32b(0x51226, 0x702cc004);
dwc_ddrphy_apb_wr_32b(0x51228, 0xc040da16);
dwc_ddrphy_apb_wr_32b(0x5122a, 0x4363d8ff);
dwc_ddrphy_apb_wr_32b(0x5122c, 0x30011c0c);
dwc_ddrphy_apb_wr_32b(0x5122e, 0xff6f0aae);
dwc_ddrphy_apb_wr_32b(0x51230, 0x71a5c642);
dwc_ddrphy_apb_wr_32b(0x51232, 0x78e0f1f0);
dwc_ddrphy_apb_wr_32b(0x51234, 0x282225f);
dwc_ddrphy_apb_wr_32b(0x51236, 0x60587034);
dwc_ddrphy_apb_wr_32b(0x51238, 0xf802032);
dwc_ddrphy_apb_wr_32b(0x5123a, 0x86c8000);
dwc_ddrphy_apb_wr_32b(0x5123c, 0x12228c1);
dwc_ddrphy_apb_wr_32b(0x5123e, 0x7fe0b8c3);
dwc_ddrphy_apb_wr_32b(0x51240, 0x3c02079);
dwc_ddrphy_apb_wr_32b(0x51242, 0x71011600);
dwc_ddrphy_apb_wr_32b(0x51244, 0x68000);
dwc_ddrphy_apb_wr_32b(0x51246, 0xf840813);
dwc_ddrphy_apb_wr_32b(0x51248, 0x4241000f);
dwc_ddrphy_apb_wr_32b(0x5124a, 0xa0f2885);
dwc_ddrphy_apb_wr_32b(0x5124c, 0x791d782c);
dwc_ddrphy_apb_wr_32b(0x5124e, 0x790cf004);
dwc_ddrphy_apb_wr_32b(0x51250, 0x41f2985);
dwc_ddrphy_apb_wr_32b(0x51252, 0x69017fe0);
dwc_ddrphy_apb_wr_32b(0x51254, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x51256, 0x2482b6c8);
dwc_ddrphy_apb_wr_32b(0x51258, 0x706f380c);
dwc_ddrphy_apb_wr_32b(0x5125a, 0x76c01e00);
dwc_ddrphy_apb_wr_32b(0x5125c, 0x9888000);
dwc_ddrphy_apb_wr_32b(0x5125e, 0xffef0a1e);
dwc_ddrphy_apb_wr_32b(0x51260, 0x43c3c086);
dwc_ddrphy_apb_wr_32b(0x51262, 0x15a8000);
dwc_ddrphy_apb_wr_32b(0x51264, 0x927702c);
dwc_ddrphy_apb_wr_32b(0x51266, 0x700c0135);
dwc_ddrphy_apb_wr_32b(0x51268, 0x295081b);
dwc_ddrphy_apb_wr_32b(0x5126a, 0x282215a);
dwc_ddrphy_apb_wr_32b(0x5126c, 0x2232621a);
dwc_ddrphy_apb_wr_32b(0x5126e, 0x80000f82);
dwc_ddrphy_apb_wr_32b(0x51270, 0x7104086c);
dwc_ddrphy_apb_wr_32b(0x51272, 0x921b01);
dwc_ddrphy_apb_wr_32b(0x51274, 0x7124f1f4);
dwc_ddrphy_apb_wr_32b(0x51276, 0x1600f1ef);
dwc_ddrphy_apb_wr_32b(0x51278, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x5127a, 0x70cd0010);
dwc_ddrphy_apb_wr_32b(0x5127c, 0xc04470ed);
dwc_ddrphy_apb_wr_32b(0x5127e, 0x11150e6b);
dwc_ddrphy_apb_wr_32b(0x51280, 0x863c004);
dwc_ddrphy_apb_wr_32b(0x51282, 0x71ad03ae);
dwc_ddrphy_apb_wr_32b(0x51284, 0xc08679cf);
dwc_ddrphy_apb_wr_32b(0x51286, 0x1600eee);
dwc_ddrphy_apb_wr_32b(0x51288, 0x7daf7dd8);
dwc_ddrphy_apb_wr_32b(0x5128a, 0xc18640a1);
dwc_ddrphy_apb_wr_32b(0x5128c, 0xe86714c);
dwc_ddrphy_apb_wr_32b(0x5128e, 0xdb4001e0);
dwc_ddrphy_apb_wr_32b(0x51290, 0xff4f0822);
dwc_ddrphy_apb_wr_32b(0x51292, 0xff0f0fce);
dwc_ddrphy_apb_wr_32b(0x51294, 0xc742c743);
dwc_ddrphy_apb_wr_32b(0x51296, 0x9dec741);
dwc_ddrphy_apb_wr_32b(0x51298, 0xc740ff6f);
dwc_ddrphy_apb_wr_32b(0x5129a, 0x31001422);
dwc_ddrphy_apb_wr_32b(0x5129c, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x5129e, 0xd8ffc040);
dwc_ddrphy_apb_wr_32b(0x512a0, 0xc743db18);
dwc_ddrphy_apb_wr_32b(0x512a2, 0xbb2c542);
dwc_ddrphy_apb_wr_32b(0x512a4, 0x1c04ff6f);
dwc_ddrphy_apb_wr_32b(0x512a6, 0xede3141);
dwc_ddrphy_apb_wr_32b(0x512a8, 0xc743ff0f);
dwc_ddrphy_apb_wr_32b(0x512aa, 0xc741c742);
dwc_ddrphy_apb_wr_32b(0x512ac, 0xff6f09b2);
dwc_ddrphy_apb_wr_32b(0x512ae, 0xeaec740);
dwc_ddrphy_apb_wr_32b(0x512b0, 0x71c5ff0f);
dwc_ddrphy_apb_wr_32b(0x512b2, 0xbe6f1cc);
dwc_ddrphy_apb_wr_32b(0x512b4, 0xcae0000);
dwc_ddrphy_apb_wr_32b(0x512b6, 0x1e000040);
dwc_ddrphy_apb_wr_32b(0x512b8, 0x900476c4);
dwc_ddrphy_apb_wr_32b(0x512ba, 0x160000dc);
dwc_ddrphy_apb_wr_32b(0x512bc, 0x8000708e);
dwc_ddrphy_apb_wr_32b(0x512be, 0x24000004);
dwc_ddrphy_apb_wr_32b(0x512c0, 0x3f80);
dwc_ddrphy_apb_wr_32b(0x512c2, 0x702c0280);
dwc_ddrphy_apb_wr_32b(0x512c4, 0x200fce);
dwc_ddrphy_apb_wr_32b(0x512c6, 0x2456daa0);
dwc_ddrphy_apb_wr_32b(0x512c8, 0xfc63f00);
dwc_ddrphy_apb_wr_32b(0x512ca, 0xdaa00020);
dwc_ddrphy_apb_wr_32b(0x512cc, 0x3a002456);
dwc_ddrphy_apb_wr_32b(0x512ce, 0x200fba);
dwc_ddrphy_apb_wr_32b(0x512d0, 0x2455daa0);
dwc_ddrphy_apb_wr_32b(0x512d2, 0xfb23a00);
dwc_ddrphy_apb_wr_32b(0x512d4, 0xdaa00020);
dwc_ddrphy_apb_wr_32b(0x512d6, 0xbc9be14);
dwc_ddrphy_apb_wr_32b(0x512d8, 0xc09e3135);
dwc_ddrphy_apb_wr_32b(0x512da, 0xfa2702c);
dwc_ddrphy_apb_wr_32b(0x512dc, 0xda280020);
dwc_ddrphy_apb_wr_32b(0x512de, 0xf9ac094);
dwc_ddrphy_apb_wr_32b(0x512e0, 0xda280020);
dwc_ddrphy_apb_wr_32b(0x512e2, 0xf92c08a);
dwc_ddrphy_apb_wr_32b(0x512e4, 0xda280020);
dwc_ddrphy_apb_wr_32b(0x512e6, 0x38002355);
dwc_ddrphy_apb_wr_32b(0x512e8, 0xc19e78c5);
dwc_ddrphy_apb_wr_32b(0x512ea, 0x1200802);
dwc_ddrphy_apb_wr_32b(0x512ec, 0x2355724c);
dwc_ddrphy_apb_wr_32b(0x512ee, 0x78c538c0);
dwc_ddrphy_apb_wr_32b(0x512f0, 0xe00ff6);
dwc_ddrphy_apb_wr_32b(0x512f2, 0x2355c194);
dwc_ddrphy_apb_wr_32b(0x512f4, 0x78c53d00);
dwc_ddrphy_apb_wr_32b(0x512f6, 0xe00fea);
dwc_ddrphy_apb_wr_32b(0x512f8, 0x1600c18a);
dwc_ddrphy_apb_wr_32b(0x512fa, 0x80007003);
dwc_ddrphy_apb_wr_32b(0x512fc, 0x4368098c);
dwc_ddrphy_apb_wr_32b(0x512fe, 0x70001600);
dwc_ddrphy_apb_wr_32b(0x51300, 0x9908000);
dwc_ddrphy_apb_wr_32b(0x51302, 0xc20865);
dwc_ddrphy_apb_wr_32b(0x51304, 0x20f4c09e);
dwc_ddrphy_apb_wr_32b(0x51306, 0x8fa00de);
dwc_ddrphy_apb_wr_32b(0x51308, 0x200affaf);
dwc_ddrphy_apb_wr_32b(0x5130a, 0x47080780);
dwc_ddrphy_apb_wr_32b(0x5130c, 0x20f4c094);
dwc_ddrphy_apb_wr_32b(0x5130e, 0xc08a00cd);
dwc_ddrphy_apb_wr_32b(0x51310, 0xc020f4);
dwc_ddrphy_apb_wr_32b(0x51312, 0x8e2bdc5);
dwc_ddrphy_apb_wr_32b(0x51314, 0x65fdffaf);
dwc_ddrphy_apb_wr_32b(0x51316, 0x3a02235a);
dwc_ddrphy_apb_wr_32b(0x51318, 0x3f812400);
dwc_ddrphy_apb_wr_32b(0x5131a, 0x2800000);
dwc_ddrphy_apb_wr_32b(0x5131c, 0x79746159);
dwc_ddrphy_apb_wr_32b(0x5131e, 0x2456b1a0);
dwc_ddrphy_apb_wr_32b(0x51320, 0x615c3f01);
dwc_ddrphy_apb_wr_32b(0x51322, 0x782212f);
dwc_ddrphy_apb_wr_32b(0x51324, 0x216c7c74);
dwc_ddrphy_apb_wr_32b(0x51326, 0xb4200101);
dwc_ddrphy_apb_wr_32b(0x51328, 0x3a012456);
dwc_ddrphy_apb_wr_32b(0x5132a, 0x79746159);
dwc_ddrphy_apb_wr_32b(0x5132c, 0x2455b1e0);
dwc_ddrphy_apb_wr_32b(0x5132e, 0x61593a01);
dwc_ddrphy_apb_wr_32b(0x51330, 0xb1007974);
dwc_ddrphy_apb_wr_32b(0x51332, 0xf1cc7164);
dwc_ddrphy_apb_wr_32b(0x51334, 0x9000230c);
dwc_ddrphy_apb_wr_32b(0x51336, 0xf6fe7165);
dwc_ddrphy_apb_wr_32b(0x51338, 0xf19f7167);
dwc_ddrphy_apb_wr_32b(0x5133a, 0xbf9fdf31);
dwc_ddrphy_apb_wr_32b(0x5133c, 0x13002742);
dwc_ddrphy_apb_wr_32b(0x5133e, 0x30c0264a);
dwc_ddrphy_apb_wr_32b(0x51340, 0x200ac045);
dwc_ddrphy_apb_wr_32b(0x51342, 0xc0440780);
dwc_ddrphy_apb_wr_32b(0x51344, 0x30320eb1);
dwc_ddrphy_apb_wr_32b(0x51346, 0x7074736c);
dwc_ddrphy_apb_wr_32b(0x51348, 0x306b26c2);
dwc_ddrphy_apb_wr_32b(0x5134a, 0xba1f6ba);
dwc_ddrphy_apb_wr_32b(0x5134c, 0x70ad07a0);
dwc_ddrphy_apb_wr_32b(0x5134e, 0x700b1600);
dwc_ddrphy_apb_wr_32b(0x51350, 0x98c8000);
dwc_ddrphy_apb_wr_32b(0x51352, 0x46a9bd8f);
dwc_ddrphy_apb_wr_32b(0x51354, 0x70001600);
dwc_ddrphy_apb_wr_32b(0x51356, 0x9908000);
dwc_ddrphy_apb_wr_32b(0x51358, 0x2e2086b);
dwc_ddrphy_apb_wr_32b(0x5135a, 0x202f78ae);
dwc_ddrphy_apb_wr_32b(0x5135c, 0x234402c2);
dwc_ddrphy_apb_wr_32b(0x5135e, 0x7a6f1041);
dwc_ddrphy_apb_wr_32b(0x51360, 0xdaa780f);
dwc_ddrphy_apb_wr_32b(0x51362, 0x4318ffef);
dwc_ddrphy_apb_wr_32b(0x51364, 0x222fe827);
dwc_ddrphy_apb_wr_32b(0x51366, 0xd9e0787);
dwc_ddrphy_apb_wr_32b(0x51368, 0x4063ffef);
dwc_ddrphy_apb_wr_32b(0x5136a, 0x235ae821);
dwc_ddrphy_apb_wr_32b(0x5136c, 0x24550a02);
dwc_ddrphy_apb_wr_32b(0x5136e, 0x60593a00);
dwc_ddrphy_apb_wr_32b(0x51370, 0x2cc21f4);
dwc_ddrphy_apb_wr_32b(0x51372, 0x3a01265a);
dwc_ddrphy_apb_wr_32b(0x51374, 0x20f46038);
dwc_ddrphy_apb_wr_32b(0x51376, 0x489402c0);
dwc_ddrphy_apb_wr_32b(0x51378, 0x200878ce);
dwc_ddrphy_apb_wr_32b(0x5137a, 0x2456030e);
dwc_ddrphy_apb_wr_32b(0x5137c, 0x60583f00);
dwc_ddrphy_apb_wr_32b(0x5137e, 0x2c220f4);
dwc_ddrphy_apb_wr_32b(0x51380, 0x3f802400);
dwc_ddrphy_apb_wr_32b(0x51382, 0x2800000);
dwc_ddrphy_apb_wr_32b(0x51384, 0x20f46038);
dwc_ddrphy_apb_wr_32b(0x51386, 0x485102c0);
dwc_ddrphy_apb_wr_32b(0x51388, 0x200878ae);
dwc_ddrphy_apb_wr_32b(0x5138a, 0x7165004d);
dwc_ddrphy_apb_wr_32b(0x5138c, 0xedaf1c8);
dwc_ddrphy_apb_wr_32b(0x5138e, 0x4200ff4f);
dwc_ddrphy_apb_wr_32b(0x51390, 0xff6f0c96);
dwc_ddrphy_apb_wr_32b(0x51392, 0xc10578ce);
dwc_ddrphy_apb_wr_32b(0x51394, 0x1f01a940);
dwc_ddrphy_apb_wr_32b(0x51396, 0xc0051012);
dwc_ddrphy_apb_wr_32b(0x51398, 0xc0457104);
dwc_ddrphy_apb_wr_32b(0x5139a, 0xf1ad7764);
dwc_ddrphy_apb_wr_32b(0x5139c, 0x800043cb);
dwc_ddrphy_apb_wr_32b(0x5139e, 0x2342004d);
dwc_ddrphy_apb_wr_32b(0x513a0, 0xc004141b);
dwc_ddrphy_apb_wr_32b(0x513a2, 0x3208af);
dwc_ddrphy_apb_wr_32b(0x513a4, 0xea373cd);
dwc_ddrphy_apb_wr_32b(0x513a6, 0x16001012);
dwc_ddrphy_apb_wr_32b(0x513a8, 0x80007003);
dwc_ddrphy_apb_wr_32b(0x513aa, 0x70ad098c);
dwc_ddrphy_apb_wr_32b(0x513ac, 0x47a9bd8f);
dwc_ddrphy_apb_wr_32b(0x513ae, 0x70001600);
dwc_ddrphy_apb_wr_32b(0x513b0, 0x9908000);
dwc_ddrphy_apb_wr_32b(0x513b2, 0xe2086f);
dwc_ddrphy_apb_wr_32b(0x513b4, 0x787d78ae);
dwc_ddrphy_apb_wr_32b(0x513b6, 0x3007262f);
dwc_ddrphy_apb_wr_32b(0x513b8, 0x412344);
dwc_ddrphy_apb_wr_32b(0x513ba, 0xcf67acf);
dwc_ddrphy_apb_wr_32b(0x513bc, 0x200affef);
dwc_ddrphy_apb_wr_32b(0x513be, 0xe8290780);
dwc_ddrphy_apb_wr_32b(0x513c0, 0x7a0fc004);
dwc_ddrphy_apb_wr_32b(0x513c2, 0xffef0ce6);
dwc_ddrphy_apb_wr_32b(0x513c4, 0x780200a);
dwc_ddrphy_apb_wr_32b(0x513c6, 0xc204e821);
dwc_ddrphy_apb_wr_32b(0x513c8, 0x1a0c265a);
dwc_ddrphy_apb_wr_32b(0x513ca, 0x3a1e2456);
dwc_ddrphy_apb_wr_32b(0x513cc, 0xa02225a);
dwc_ddrphy_apb_wr_32b(0x513ce, 0x3a012455);
dwc_ddrphy_apb_wr_32b(0x513d0, 0x33002600);
dwc_ddrphy_apb_wr_32b(0x513d2, 0xdf20f4);
dwc_ddrphy_apb_wr_32b(0x513d4, 0x20f46158);
dwc_ddrphy_apb_wr_32b(0x513d6, 0x619900c0);
dwc_ddrphy_apb_wr_32b(0x513d8, 0x7822200);
dwc_ddrphy_apb_wr_32b(0x513da, 0x301f270e);
dwc_ddrphy_apb_wr_32b(0x513dc, 0x270878ee);
dwc_ddrphy_apb_wr_32b(0x513de, 0x21f4300f);
dwc_ddrphy_apb_wr_32b(0x513e0, 0x22f400c0);
dwc_ddrphy_apb_wr_32b(0x513e2, 0x790200c1);
dwc_ddrphy_apb_wr_32b(0x513e4, 0x200878ae);
dwc_ddrphy_apb_wr_32b(0x513e6, 0x7164004d);
dwc_ddrphy_apb_wr_32b(0x513e8, 0xbe6f1c6);
dwc_ddrphy_apb_wr_32b(0x513ea, 0x4100ff4f);
dwc_ddrphy_apb_wr_32b(0x513ec, 0xff6f0bde);
dwc_ddrphy_apb_wr_32b(0x513ee, 0x1b0178ee);
dwc_ddrphy_apb_wr_32b(0x513f0, 0x1b013052);
dwc_ddrphy_apb_wr_32b(0x513f2, 0x77c51012);
dwc_ddrphy_apb_wr_32b(0x513f4, 0xc004f1b1);
dwc_ddrphy_apb_wr_32b(0x513f6, 0xc0447704);
dwc_ddrphy_apb_wr_32b(0x513f8, 0x40c3f1a9);
dwc_ddrphy_apb_wr_32b(0x513fa, 0xe1749003);
dwc_ddrphy_apb_wr_32b(0x513fc, 0x51800);
dwc_ddrphy_apb_wr_32b(0x513fe, 0xffaf089e);
dwc_ddrphy_apb_wr_32b(0x51400, 0x51802);
dwc_ddrphy_apb_wr_32b(0x51402, 0x380c2480);
dwc_ddrphy_apb_wr_32b(0x51404, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x51406, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x51408, 0xc1a4c2e4);
dwc_ddrphy_apb_wr_32b(0x5140a, 0x700c4608);
dwc_ddrphy_apb_wr_32b(0x5140c, 0xff2f0e1a);
dwc_ddrphy_apb_wr_32b(0x5140e, 0xcead9ff);
dwc_ddrphy_apb_wr_32b(0x51410, 0xc143ff0f);
dwc_ddrphy_apb_wr_32b(0x51412, 0xc141c142);
dwc_ddrphy_apb_wr_32b(0x51414, 0xff2f0ee2);
dwc_ddrphy_apb_wr_32b(0x51416, 0x208ac140);
dwc_ddrphy_apb_wr_32b(0x51418, 0xc0400010);
dwc_ddrphy_apb_wr_32b(0x5141a, 0xd980d8ff);
dwc_ddrphy_apb_wr_32b(0x5141c, 0xdb20764c);
dwc_ddrphy_apb_wr_32b(0x5141e, 0xc642c543);
dwc_ddrphy_apb_wr_32b(0x51420, 0xff2f0eca);
dwc_ddrphy_apb_wr_32b(0x51422, 0xbc6c541);
dwc_ddrphy_apb_wr_32b(0x51424, 0xc0a4ff0f);
dwc_ddrphy_apb_wr_32b(0x51426, 0x78e0c6c4);
dwc_ddrphy_apb_wr_32b(0x51428, 0xc1a4c2e6);
dwc_ddrphy_apb_wr_32b(0x5142a, 0x1843276f);
dwc_ddrphy_apb_wr_32b(0x5142c, 0x700c8fc0);
dwc_ddrphy_apb_wr_32b(0x5142e, 0xff2f0dd6);
dwc_ddrphy_apb_wr_32b(0x51430, 0x1600d9ff);
dwc_ddrphy_apb_wr_32b(0x51432, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x51434, 0x70ad03ff);
dwc_ddrphy_apb_wr_32b(0x51436, 0x80be818);
dwc_ddrphy_apb_wr_32b(0x51438, 0x70cd003f);
dwc_ddrphy_apb_wr_32b(0x5143a, 0x80b8fc1);
dwc_ddrphy_apb_wr_32b(0x5143c, 0x8f02009f);
dwc_ddrphy_apb_wr_32b(0x5143e, 0xd8ff7e05);
dwc_ddrphy_apb_wr_32b(0x51440, 0x754c702c);
dwc_ddrphy_apb_wr_32b(0x51442, 0xc543736c);
dwc_ddrphy_apb_wr_32b(0x51444, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x51446, 0xff2f0e7e);
dwc_ddrphy_apb_wr_32b(0x51448, 0xc543c540);
dwc_ddrphy_apb_wr_32b(0x5144a, 0xc541c642);
dwc_ddrphy_apb_wr_32b(0x5144c, 0xf011c540);
dwc_ddrphy_apb_wr_32b(0x5144e, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x51450, 0x736c754c);
dwc_ddrphy_apb_wr_32b(0x51452, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x51454, 0xe62c541);
dwc_ddrphy_apb_wr_32b(0x51456, 0xc540ff2f);
dwc_ddrphy_apb_wr_32b(0x51458, 0xc642c543);
dwc_ddrphy_apb_wr_32b(0x5145a, 0x1c00c541);
dwc_ddrphy_apb_wr_32b(0x5145c, 0xd8ff3041);
dwc_ddrphy_apb_wr_32b(0x5145e, 0xda09d980);
dwc_ddrphy_apb_wr_32b(0x51460, 0xff2f0e4a);
dwc_ddrphy_apb_wr_32b(0x51462, 0xb46db20);
dwc_ddrphy_apb_wr_32b(0x51464, 0xc0a4ff0f);
dwc_ddrphy_apb_wr_32b(0x51466, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x51468, 0xc421aa);
dwc_ddrphy_apb_wr_32b(0x5146a, 0x3f0911);
dwc_ddrphy_apb_wr_32b(0x5146c, 0x21ab722c);
dwc_ddrphy_apb_wr_32b(0x5146e, 0x712c00c4);
dwc_ddrphy_apb_wr_32b(0x51470, 0xc421ab);
dwc_ddrphy_apb_wr_32b(0x51472, 0x71011600);
dwc_ddrphy_apb_wr_32b(0x51474, 0x1009018);
dwc_ddrphy_apb_wr_32b(0x51476, 0xb9e27a1d);
dwc_ddrphy_apb_wr_32b(0x51478, 0x8120ca);
dwc_ddrphy_apb_wr_32b(0x5147a, 0x415080f);
dwc_ddrphy_apb_wr_32b(0x5147c, 0x71001600);
dwc_ddrphy_apb_wr_32b(0x5147e, 0x1d69008);
dwc_ddrphy_apb_wr_32b(0x51480, 0x21aaf01a);
dwc_ddrphy_apb_wr_32b(0x51482, 0x7b320104);
dwc_ddrphy_apb_wr_32b(0x51484, 0x250b19);
dwc_ddrphy_apb_wr_32b(0x51486, 0x114424aa);
dwc_ddrphy_apb_wr_32b(0x51488, 0x10422aa);
dwc_ddrphy_apb_wr_32b(0x5148a, 0x808409fd);
dwc_ddrphy_apb_wr_32b(0x5148c, 0x24aa7862);
dwc_ddrphy_apb_wr_32b(0x5148e, 0xf0031144);
dwc_ddrphy_apb_wr_32b(0x51490, 0x21aa6038);
dwc_ddrphy_apb_wr_32b(0x51492, 0x71100104);
dwc_ddrphy_apb_wr_32b(0x51494, 0x7c620e1);
dwc_ddrphy_apb_wr_32b(0x51496, 0x14422aa);
dwc_ddrphy_apb_wr_32b(0x51498, 0x90800cf3);
dwc_ddrphy_apb_wr_32b(0x5149a, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x5149c, 0x85ac0f1);
dwc_ddrphy_apb_wr_32b(0x5149e, 0xf960000);
dwc_ddrphy_apb_wr_32b(0x514a0, 0xc0d1ffcf);
dwc_ddrphy_apb_wr_32b(0x514a2, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x514a4, 0xf0ac0f1);
dwc_ddrphy_apb_wr_32b(0x514a6, 0xf86ffcf);
dwc_ddrphy_apb_wr_32b(0x514a8, 0xd814ffef);
dwc_ddrphy_apb_wr_32b(0x514aa, 0xff0f0cce);
dwc_ddrphy_apb_wr_32b(0x514ac, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x514ae, 0x648000);
dwc_ddrphy_apb_wr_32b(0x514b0, 0xfe080b);
dwc_ddrphy_apb_wr_32b(0x514b2, 0xa46700c);
dwc_ddrphy_apb_wr_32b(0x514b4, 0xc0d10100);
dwc_ddrphy_apb_wr_32b(0x514b6, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x514b8, 0xa16c0f1);
dwc_ddrphy_apb_wr_32b(0x514ba, 0xf5eff4f);
dwc_ddrphy_apb_wr_32b(0x514bc, 0x208affef);
dwc_ddrphy_apb_wr_32b(0x514be, 0x40c30010);
dwc_ddrphy_apb_wr_32b(0x514c0, 0x89a8000);
dwc_ddrphy_apb_wr_32b(0x514c2, 0xb8e38800);
dwc_ddrphy_apb_wr_32b(0x514c4, 0xff8208a4);
dwc_ddrphy_apb_wr_32b(0x514c6, 0x7ee0c0d1);
dwc_ddrphy_apb_wr_32b(0x514c8, 0x71021600);
dwc_ddrphy_apb_wr_32b(0x514ca, 0x68000);
dwc_ddrphy_apb_wr_32b(0x514cc, 0xf840819);
dwc_ddrphy_apb_wr_32b(0x514ce, 0xd410003);
dwc_ddrphy_apb_wr_32b(0x514d0, 0xa0f2885);
dwc_ddrphy_apb_wr_32b(0x514d2, 0x2805784c);
dwc_ddrphy_apb_wr_32b(0x514d4, 0xf82);
dwc_ddrphy_apb_wr_32b(0x514d6, 0xf0070fa0);
dwc_ddrphy_apb_wr_32b(0x514d8, 0x2805784c);
dwc_ddrphy_apb_wr_32b(0x514da, 0x3d0f82);
dwc_ddrphy_apb_wr_32b(0x514dc, 0x783d0900);
dwc_ddrphy_apb_wr_32b(0x514de, 0x22ca7050);
dwc_ddrphy_apb_wr_32b(0x514e0, 0x7fe0000d);
dwc_ddrphy_apb_wr_32b(0x514e2, 0x78e06a01);
dwc_ddrphy_apb_wr_32b(0x514e4, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x514e6, 0xc1aeb6c8);
dwc_ddrphy_apb_wr_32b(0x514e8, 0x36c3236f);
dwc_ddrphy_apb_wr_32b(0x514ea, 0x30821300);
dwc_ddrphy_apb_wr_32b(0x514ec, 0xc641c3);
dwc_ddrphy_apb_wr_32b(0x514ee, 0xf0a0001);
dwc_ddrphy_apb_wr_32b(0x514f0, 0x2278feaf);
dwc_ddrphy_apb_wr_32b(0x514f2, 0x45cb0080);
dwc_ddrphy_apb_wr_32b(0x514f4, 0x9848000);
dwc_ddrphy_apb_wr_32b(0x514f6, 0x10011d00);
dwc_ddrphy_apb_wr_32b(0x514f8, 0x31c31a0a);
dwc_ddrphy_apb_wr_32b(0x514fa, 0x71011600);
dwc_ddrphy_apb_wr_32b(0x514fc, 0x1dc9018);
dwc_ddrphy_apb_wr_32b(0x514fe, 0x402070cd);
dwc_ddrphy_apb_wr_32b(0x51500, 0xc032084);
dwc_ddrphy_apb_wr_32b(0x51502, 0x301c1a0d);
dwc_ddrphy_apb_wr_32b(0x51504, 0x800c218c);
dwc_ddrphy_apb_wr_32b(0x51506, 0x20cad81c);
dwc_ddrphy_apb_wr_32b(0x51508, 0x218c05a1);
dwc_ddrphy_apb_wr_32b(0x5150a, 0x1a0c8008);
dwc_ddrphy_apb_wr_32b(0x5150c, 0x20ca305c);
dwc_ddrphy_apb_wr_32b(0x5150e, 0x210405a5);
dwc_ddrphy_apb_wr_32b(0x51510, 0xf81);
dwc_ddrphy_apb_wr_32b(0x51512, 0x1a07ff00);
dwc_ddrphy_apb_wr_32b(0x51514, 0x218c3002);
dwc_ddrphy_apb_wr_32b(0x51516, 0xd81a8044);
dwc_ddrphy_apb_wr_32b(0x51518, 0x5a520ca);
dwc_ddrphy_apb_wr_32b(0x5151a, 0x30021a09);
dwc_ddrphy_apb_wr_32b(0x5151c, 0x20cad83f);
dwc_ddrphy_apb_wr_32b(0x5151e, 0x1a0809e5);
dwc_ddrphy_apb_wr_32b(0x51520, 0x40203002);
dwc_ddrphy_apb_wr_32b(0x51522, 0x305c1a0e);
dwc_ddrphy_apb_wr_32b(0x51524, 0x1020b8);
dwc_ddrphy_apb_wr_32b(0x51526, 0x821b8);
dwc_ddrphy_apb_wr_32b(0x51528, 0x9727825);
dwc_ddrphy_apb_wr_32b(0x5152a, 0x1a0cffaf);
dwc_ddrphy_apb_wr_32b(0x5152c, 0xb8c33002);
dwc_ddrphy_apb_wr_32b(0x5152e, 0x30021a03);
dwc_ddrphy_apb_wr_32b(0x51530, 0x30811302);
dwc_ddrphy_apb_wr_32b(0x51532, 0x832941);
dwc_ddrphy_apb_wr_32b(0x51534, 0x807e2153);
dwc_ddrphy_apb_wr_32b(0x51536, 0x6223c0);
dwc_ddrphy_apb_wr_32b(0x51538, 0xc22941);
dwc_ddrphy_apb_wr_32b(0x5153a, 0x808c2153);
dwc_ddrphy_apb_wr_32b(0x5153c, 0x6222c0);
dwc_ddrphy_apb_wr_32b(0x5153e, 0x30c21a05);
dwc_ddrphy_apb_wr_32b(0x51540, 0x30821a04);
dwc_ddrphy_apb_wr_32b(0x51542, 0x800047cb);
dwc_ddrphy_apb_wr_32b(0x51544, 0xe15086b);
dwc_ddrphy_apb_wr_32b(0x51546, 0x263c12b5);
dwc_ddrphy_apb_wr_32b(0x51548, 0x77241081);
dwc_ddrphy_apb_wr_32b(0x5154a, 0xaf2167df);
dwc_ddrphy_apb_wr_32b(0x5154c, 0xf1f671c5);
dwc_ddrphy_apb_wr_32b(0x5154e, 0xd9ffec06);
dwc_ddrphy_apb_wr_32b(0x51550, 0x30c2900);
dwc_ddrphy_apb_wr_32b(0x51552, 0xa98062f9);
dwc_ddrphy_apb_wr_32b(0x51554, 0x702c70ef);
dwc_ddrphy_apb_wr_32b(0x51556, 0x2950937);
dwc_ddrphy_apb_wr_32b(0x51558, 0x708c1600);
dwc_ddrphy_apb_wr_32b(0x5155a, 0xe8000);
dwc_ddrphy_apb_wr_32b(0x5155c, 0x106e0c0b);
dwc_ddrphy_apb_wr_32b(0x5155e, 0x1c01673c);
dwc_ddrphy_apb_wr_32b(0x51560, 0x718d1fc3);
dwc_ddrphy_apb_wr_32b(0x51562, 0x11150c1b);
dwc_ddrphy_apb_wr_32b(0x51564, 0x128e245a);
dwc_ddrphy_apb_wr_32b(0x51566, 0x663e7185);
dwc_ddrphy_apb_wr_32b(0x51568, 0x138b2700);
dwc_ddrphy_apb_wr_32b(0x5156a, 0x8ec1673e);
dwc_ddrphy_apb_wr_32b(0x5156c, 0x13821b01);
dwc_ddrphy_apb_wr_32b(0x5156e, 0x7124f1f4);
dwc_ddrphy_apb_wr_32b(0x51570, 0x260af1e6);
dwc_ddrphy_apb_wr_32b(0x51572, 0x80003f80);
dwc_ddrphy_apb_wr_32b(0x51574, 0xf2d015a);
dwc_ddrphy_apb_wr_32b(0x51576, 0x702c3135);
dwc_ddrphy_apb_wr_32b(0x51578, 0x2950921);
dwc_ddrphy_apb_wr_32b(0x5157a, 0x328c275a);
dwc_ddrphy_apb_wr_32b(0x5157c, 0x348e1601);
dwc_ddrphy_apb_wr_32b(0x5157e, 0x64fc643c);
dwc_ddrphy_apb_wr_32b(0x51580, 0x108b1401);
dwc_ddrphy_apb_wr_32b(0x51582, 0x23057124);
dwc_ddrphy_apb_wr_32b(0x51584, 0x1c01138b);
dwc_ddrphy_apb_wr_32b(0x51586, 0xf1f212c2);
dwc_ddrphy_apb_wr_32b(0x51588, 0xf1ed71e7);
dwc_ddrphy_apb_wr_32b(0x5158a, 0x41c3c040);
dwc_ddrphy_apb_wr_32b(0x5158c, 0x300ca);
dwc_ddrphy_apb_wr_32b(0x5158e, 0xff6f0bba);
dwc_ddrphy_apb_wr_32b(0x51590, 0xca05d80a);
dwc_ddrphy_apb_wr_32b(0x51592, 0x10011d08);
dwc_ddrphy_apb_wr_32b(0x51594, 0x10011d10);
dwc_ddrphy_apb_wr_32b(0x51596, 0xa5037704);
dwc_ddrphy_apb_wr_32b(0x51598, 0x7704ca04);
dwc_ddrphy_apb_wr_32b(0x5159a, 0x1600a505);
dwc_ddrphy_apb_wr_32b(0x5159c, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x5159e, 0xb8e20001);
dwc_ddrphy_apb_wr_32b(0x515a0, 0xf40ad807);
dwc_ddrphy_apb_wr_32b(0x515a2, 0x70c01600);
dwc_ddrphy_apb_wr_32b(0x515a4, 0x8000);
dwc_ddrphy_apb_wr_32b(0x515a6, 0x207b);
dwc_ddrphy_apb_wr_32b(0x515a8, 0xe03fb806);
dwc_ddrphy_apb_wr_32b(0x515aa, 0x1b43276f);
dwc_ddrphy_apb_wr_32b(0x515ac, 0x30021a0b);
dwc_ddrphy_apb_wr_32b(0x515ae, 0x951e17fa);
dwc_ddrphy_apb_wr_32b(0x515b0, 0x120e2740);
dwc_ddrphy_apb_wr_32b(0x515b2, 0x16008f45);
dwc_ddrphy_apb_wr_32b(0x515b4, 0x8000708d);
dwc_ddrphy_apb_wr_32b(0x515b6, 0x13000001);
dwc_ddrphy_apb_wr_32b(0x515b8, 0x17003080);
dwc_ddrphy_apb_wr_32b(0x515ba, 0x1646108b);
dwc_ddrphy_apb_wr_32b(0x515bc, 0x17f61483);
dwc_ddrphy_apb_wr_32b(0x515be, 0x8f839101);
dwc_ddrphy_apb_wr_32b(0x515c0, 0xc542c045);
dwc_ddrphy_apb_wr_32b(0x515c2, 0x402244);
dwc_ddrphy_apb_wr_32b(0x515c4, 0xcc45cb);
dwc_ddrphy_apb_wr_32b(0x515c6, 0xc1440008);
dwc_ddrphy_apb_wr_32b(0x515c8, 0xc340c041);
dwc_ddrphy_apb_wr_32b(0x515ca, 0x41a1d80a);
dwc_ddrphy_apb_wr_32b(0x515cc, 0x230a4261);
dwc_ddrphy_apb_wr_32b(0x515ce, 0xb3a0780);
dwc_ddrphy_apb_wr_32b(0x515d0, 0xc443ff6f);
dwc_ddrphy_apb_wr_32b(0x515d2, 0x151f1602);
dwc_ddrphy_apb_wr_32b(0x515d4, 0x150b1602);
dwc_ddrphy_apb_wr_32b(0x515d6, 0x15031602);
dwc_ddrphy_apb_wr_32b(0x515d8, 0x15021602);
dwc_ddrphy_apb_wr_32b(0x515da, 0x909e17f4);
dwc_ddrphy_apb_wr_32b(0x515dc, 0x96029621);
dwc_ddrphy_apb_wr_32b(0x515de, 0xc1449680);
dwc_ddrphy_apb_wr_32b(0x515e0, 0xc242c045);
dwc_ddrphy_apb_wr_32b(0x515e2, 0x254fc341);
dwc_ddrphy_apb_wr_32b(0x515e4, 0xd80a1401);
dwc_ddrphy_apb_wr_32b(0x515e6, 0x780220a);
dwc_ddrphy_apb_wr_32b(0x515e8, 0xc44343e3);
dwc_ddrphy_apb_wr_32b(0x515ea, 0xff6f0b02);
dwc_ddrphy_apb_wr_32b(0x515ec, 0x32c01c00);
dwc_ddrphy_apb_wr_32b(0x515ee, 0x800043db);
dwc_ddrphy_apb_wr_32b(0x515f0, 0x130003ff);
dwc_ddrphy_apb_wr_32b(0x515f2, 0xe83b3080);
dwc_ddrphy_apb_wr_32b(0x515f4, 0x72ad781b);
dwc_ddrphy_apb_wr_32b(0x515f6, 0x40a17d06);
dwc_ddrphy_apb_wr_32b(0x515f8, 0xffaf089a);
dwc_ddrphy_apb_wr_32b(0x515fa, 0xc048702c);
dwc_ddrphy_apb_wr_32b(0x515fc, 0x89240a1);
dwc_ddrphy_apb_wr_32b(0x515fe, 0x712cffaf);
dwc_ddrphy_apb_wr_32b(0x51600, 0x40a1c049);
dwc_ddrphy_apb_wr_32b(0x51602, 0xffaf0886);
dwc_ddrphy_apb_wr_32b(0x51604, 0xc04a722c);
dwc_ddrphy_apb_wr_32b(0x51606, 0x87e40a1);
dwc_ddrphy_apb_wr_32b(0x51608, 0x732cffaf);
dwc_ddrphy_apb_wr_32b(0x5160a, 0x40a1c04b);
dwc_ddrphy_apb_wr_32b(0x5160c, 0xffaf0872);
dwc_ddrphy_apb_wr_32b(0x5160e, 0xc04c742c);
dwc_ddrphy_apb_wr_32b(0x51610, 0x86a40a1);
dwc_ddrphy_apb_wr_32b(0x51612, 0x752cffaf);
dwc_ddrphy_apb_wr_32b(0x51614, 0x40a1c04d);
dwc_ddrphy_apb_wr_32b(0x51616, 0xffaf085e);
dwc_ddrphy_apb_wr_32b(0x51618, 0x1300762c);
dwc_ddrphy_apb_wr_32b(0x5161a, 0xc0453082);
dwc_ddrphy_apb_wr_32b(0x5161c, 0xc308c00d);
dwc_ddrphy_apb_wr_32b(0x5161e, 0xce41c3);
dwc_ddrphy_apb_wr_32b(0x51620, 0xc0440008);
dwc_ddrphy_apb_wr_32b(0x51622, 0xc043c00c);
dwc_ddrphy_apb_wr_32b(0x51624, 0xc042c00b);
dwc_ddrphy_apb_wr_32b(0x51626, 0xc041c00a);
dwc_ddrphy_apb_wr_32b(0x51628, 0xc040c009);
dwc_ddrphy_apb_wr_32b(0x5162a, 0xff6f0a82);
dwc_ddrphy_apb_wr_32b(0x5162c, 0x45cbd80a);
dwc_ddrphy_apb_wr_32b(0x5162e, 0xe14c9005);
dwc_ddrphy_apb_wr_32b(0x51630, 0x10851d00);
dwc_ddrphy_apb_wr_32b(0x51632, 0x908017f4);
dwc_ddrphy_apb_wr_32b(0x51634, 0x2005b815);
dwc_ddrphy_apb_wr_32b(0x51636, 0x90050f81);
dwc_ddrphy_apb_wr_32b(0x51638, 0x2005e048);
dwc_ddrphy_apb_wr_32b(0x5163a, 0x90040f80);
dwc_ddrphy_apb_wr_32b(0x5163c, 0x90000048);
dwc_ddrphy_apb_wr_32b(0x5163e, 0x43206c);
dwc_ddrphy_apb_wr_32b(0x51640, 0xb82b9600);
dwc_ddrphy_apb_wr_32b(0x51642, 0x422044);
dwc_ddrphy_apb_wr_32b(0x51644, 0x20447a65);
dwc_ddrphy_apb_wr_32b(0x51646, 0x78450080);
dwc_ddrphy_apb_wr_32b(0x51648, 0xc42b100);
dwc_ddrphy_apb_wr_32b(0x5164a, 0xd814ffef);
dwc_ddrphy_apb_wr_32b(0x5164c, 0x702c706c);
dwc_ddrphy_apb_wr_32b(0x5164e, 0x923b560);
dwc_ddrphy_apb_wr_32b(0x51650, 0x783b0135);
dwc_ddrphy_apb_wr_32b(0x51652, 0xe002056);
dwc_ddrphy_apb_wr_32b(0x51654, 0xf822005);
dwc_ddrphy_apb_wr_32b(0x51656, 0xe0009009);
dwc_ddrphy_apb_wr_32b(0x51658, 0xf802132);
dwc_ddrphy_apb_wr_32b(0x5165a, 0x7e8000);
dwc_ddrphy_apb_wr_32b(0x5165c, 0xb2007124);
dwc_ddrphy_apb_wr_32b(0x5165e, 0x42c3f1f1);
dwc_ddrphy_apb_wr_32b(0x51660, 0xe1c89009);
dwc_ddrphy_apb_wr_32b(0x51662, 0x151a02);
dwc_ddrphy_apb_wr_32b(0x51664, 0xb261b260);
dwc_ddrphy_apb_wr_32b(0x51666, 0x1600b262);
dwc_ddrphy_apb_wr_32b(0x51668, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x5166a, 0x8370001);
dwc_ddrphy_apb_wr_32b(0x5166c, 0x208a01bf);
dwc_ddrphy_apb_wr_32b(0x5166e, 0x1ad60044);
dwc_ddrphy_apb_wr_32b(0x51670, 0x40c38004);
dwc_ddrphy_apb_wr_32b(0x51672, 0x12020000);
dwc_ddrphy_apb_wr_32b(0x51674, 0x900941c3);
dwc_ddrphy_apb_wr_32b(0x51676, 0xb100e1a2);
dwc_ddrphy_apb_wr_32b(0x51678, 0x1ada781b);
dwc_ddrphy_apb_wr_32b(0x5167a, 0x40c38004);
dwc_ddrphy_apb_wr_32b(0x5167c, 0x38080000);
dwc_ddrphy_apb_wr_32b(0x5167e, 0x700cb102);
dwc_ddrphy_apb_wr_32b(0x51680, 0xb103b88e);
dwc_ddrphy_apb_wr_32b(0x51682, 0x3c4208a);
dwc_ddrphy_apb_wr_32b(0x51684, 0x208af00c);
dwc_ddrphy_apb_wr_32b(0x51686, 0x1ad600cc);
dwc_ddrphy_apb_wr_32b(0x51688, 0x40c38004);
dwc_ddrphy_apb_wr_32b(0x5168a, 0x2c0c0000);
dwc_ddrphy_apb_wr_32b(0x5168c, 0x80041ada);
dwc_ddrphy_apb_wr_32b(0x5168e, 0xbc4208a);
dwc_ddrphy_apb_wr_32b(0x51690, 0x80041ab6);
dwc_ddrphy_apb_wr_32b(0x51692, 0x71001600);
dwc_ddrphy_apb_wr_32b(0x51694, 0xea9004);
dwc_ddrphy_apb_wr_32b(0x51696, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x51698, 0xe0ee9005);
dwc_ddrphy_apb_wr_32b(0x5169a, 0xffcf0c16);
dwc_ddrphy_apb_wr_32b(0x5169c, 0x1404c0ae);
dwc_ddrphy_apb_wr_32b(0x5169e, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x516a0, 0x7350706c);
dwc_ddrphy_apb_wr_32b(0x516a2, 0x7c620e0);
dwc_ddrphy_apb_wr_32b(0x516a4, 0x48c1101);
dwc_ddrphy_apb_wr_32b(0x516a6, 0x18017164);
dwc_ddrphy_apb_wr_32b(0x516a8, 0xf1f90312);
dwc_ddrphy_apb_wr_32b(0x516aa, 0x7050621a);
dwc_ddrphy_apb_wr_32b(0x516ac, 0x7c620e0);
dwc_ddrphy_apb_wr_32b(0x516ae, 0x521801);
dwc_ddrphy_apb_wr_32b(0x516b0, 0x78e0f1fb);
dwc_ddrphy_apb_wr_32b(0x516b2, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x516b4, 0x1e00b6c8);
dwc_ddrphy_apb_wr_32b(0x516b6, 0x80007345);
dwc_ddrphy_apb_wr_32b(0x516b8, 0xaf20002);
dwc_ddrphy_apb_wr_32b(0x516ba, 0xc1aeff6f);
dwc_ddrphy_apb_wr_32b(0x516bc, 0xcfe);
dwc_ddrphy_apb_wr_32b(0x516be, 0x40c3);
dwc_ddrphy_apb_wr_32b(0x516c0, 0x45cbebfc);
dwc_ddrphy_apb_wr_32b(0x516c2, 0x3289012);
dwc_ddrphy_apb_wr_32b(0x516c4, 0xd888b500);
dwc_ddrphy_apb_wr_32b(0x516c6, 0xcc10b501);
dwc_ddrphy_apb_wr_32b(0x516c8, 0x14841c3);
dwc_ddrphy_apb_wr_32b(0x516ca, 0xda0d0002);
dwc_ddrphy_apb_wr_32b(0x516cc, 0x4032840);
dwc_ddrphy_apb_wr_32b(0x516ce, 0x631bcc0f);
dwc_ddrphy_apb_wr_32b(0x516d0, 0xff6f0936);
dwc_ddrphy_apb_wr_32b(0x516d2, 0xcc0fd80a);
dwc_ddrphy_apb_wr_32b(0x516d4, 0x80f9520);
dwc_ddrphy_apb_wr_32b(0x516d6, 0xcc100041);
dwc_ddrphy_apb_wr_32b(0x516d8, 0x8119521);
dwc_ddrphy_apb_wr_32b(0x516da, 0xd9a50040);
dwc_ddrphy_apb_wr_32b(0x516dc, 0xb2e700c);
dwc_ddrphy_apb_wr_32b(0x516de, 0xb911feaf);
dwc_ddrphy_apb_wr_32b(0x516e0, 0x1243266f);
dwc_ddrphy_apb_wr_32b(0x516e2, 0x16128e00);
dwc_ddrphy_apb_wr_32b(0x516e4, 0xc047111b);
dwc_ddrphy_apb_wr_32b(0x516e6, 0xc040b815);
dwc_ddrphy_apb_wr_32b(0x516e8, 0xf802005);
dwc_ddrphy_apb_wr_32b(0x516ea, 0x329004);
dwc_ddrphy_apb_wr_32b(0x516ec, 0xc0419000);
dwc_ddrphy_apb_wr_32b(0x516ee, 0x2005c000);
dwc_ddrphy_apb_wr_32b(0x516f0, 0x90020f81);
dwc_ddrphy_apb_wr_32b(0x516f2, 0x16000040);
dwc_ddrphy_apb_wr_32b(0x516f4, 0x90047100);
dwc_ddrphy_apb_wr_32b(0x516f6, 0xc0450074);
dwc_ddrphy_apb_wr_32b(0x516f8, 0xc0439100);
dwc_ddrphy_apb_wr_32b(0x516fa, 0x71001600);
dwc_ddrphy_apb_wr_32b(0x516fc, 0x809004);
dwc_ddrphy_apb_wr_32b(0x516fe, 0x1e00b8a0);
dwc_ddrphy_apb_wr_32b(0x51700, 0x90047004);
dwc_ddrphy_apb_wr_32b(0x51702, 0x165c0080);
dwc_ddrphy_apb_wr_32b(0x51704, 0xc0481100);
dwc_ddrphy_apb_wr_32b(0x51706, 0x6002046);
dwc_ddrphy_apb_wr_32b(0x51708, 0x10041e5c);
dwc_ddrphy_apb_wr_32b(0x5170a, 0x908016fd);
dwc_ddrphy_apb_wr_32b(0x5170c, 0x8e0cb8e6);
dwc_ddrphy_apb_wr_32b(0x5170e, 0xf206c042);
dwc_ddrphy_apb_wr_32b(0x51710, 0x2084c002);
dwc_ddrphy_apb_wr_32b(0x51712, 0xae0c0541);
dwc_ddrphy_apb_wr_32b(0x51714, 0xfeef0ffa);
dwc_ddrphy_apb_wr_32b(0x51716, 0x31031a00);
dwc_ddrphy_apb_wr_32b(0x51718, 0xb0002351);
dwc_ddrphy_apb_wr_32b(0x5171a, 0x1600f2f1);
dwc_ddrphy_apb_wr_32b(0x5171c, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x5171e, 0x80f03f9);
dwc_ddrphy_apb_wr_32b(0x51720, 0x1e00011f);
dwc_ddrphy_apb_wr_32b(0x51722, 0x90047085);
dwc_ddrphy_apb_wr_32b(0x51724, 0xc00000c0);
dwc_ddrphy_apb_wr_32b(0x51726, 0x200570ad);
dwc_ddrphy_apb_wr_32b(0x51728, 0x90050f81);
dwc_ddrphy_apb_wr_32b(0x5172a, 0xc001e032);
dwc_ddrphy_apb_wr_32b(0x5172c, 0xb100b880);
dwc_ddrphy_apb_wr_32b(0x5172e, 0x2005c000);
dwc_ddrphy_apb_wr_32b(0x51730, 0x90030f80);
dwc_ddrphy_apb_wr_32b(0x51732, 0xbb2e090);
dwc_ddrphy_apb_wr_32b(0x51734, 0x18000020);
dwc_ddrphy_apb_wr_32b(0x51736, 0xb5e0005);
dwc_ddrphy_apb_wr_32b(0x51738, 0x8a6ffcf);
dwc_ddrphy_apb_wr_32b(0x5173a, 0xd7dff8f);
dwc_ddrphy_apb_wr_32b(0x5173c, 0xcc0e1115);
dwc_ddrphy_apb_wr_32b(0x5173e, 0x8044208c);
dwc_ddrphy_apb_wr_32b(0x51740, 0xd1ff78e);
dwc_ddrphy_apb_wr_32b(0x51742, 0x238a1070);
dwc_ddrphy_apb_wr_32b(0x51744, 0xd170014);
dwc_ddrphy_apb_wr_32b(0x51746, 0x238a10f0);
dwc_ddrphy_apb_wr_32b(0x51748, 0xd0d0414);
dwc_ddrphy_apb_wr_32b(0x5174a, 0x238a10b1);
dwc_ddrphy_apb_wr_32b(0x5174c, 0xf0030214);
dwc_ddrphy_apb_wr_32b(0x5174e, 0x702cdba0);
dwc_ddrphy_apb_wr_32b(0x51750, 0x94dca04);
dwc_ddrphy_apb_wr_32b(0x51752, 0x704c0005);
dwc_ddrphy_apb_wr_32b(0x51754, 0x2150a41);
dwc_ddrphy_apb_wr_32b(0x51756, 0x209a40a1);
dwc_ddrphy_apb_wr_32b(0x51758, 0x78360401);
dwc_ddrphy_apb_wr_32b(0x5175a, 0x20006058);
dwc_ddrphy_apb_wr_32b(0x5175c, 0x80000f8c);
dwc_ddrphy_apb_wr_32b(0x5175e, 0x294009b0);
dwc_ddrphy_apb_wr_32b(0x51760, 0x78650300);
dwc_ddrphy_apb_wr_32b(0x51762, 0x6058b890);
dwc_ddrphy_apb_wr_32b(0x51764, 0x2005781b);
dwc_ddrphy_apb_wr_32b(0x51766, 0x90000f8f);
dwc_ddrphy_apb_wr_32b(0x51768, 0x97000000);
dwc_ddrphy_apb_wr_32b(0x5176a, 0x10f00d0f);
dwc_ddrphy_apb_wr_32b(0x5176c, 0xcc0eac00);
dwc_ddrphy_apb_wr_32b(0x5176e, 0x8044208c);
dwc_ddrphy_apb_wr_32b(0x51770, 0xb740f782);
dwc_ddrphy_apb_wr_32b(0x51772, 0xf1e27144);
dwc_ddrphy_apb_wr_32b(0x51774, 0xf1dc7124);
dwc_ddrphy_apb_wr_32b(0x51776, 0xf1c571a5);
dwc_ddrphy_apb_wr_32b(0x51778, 0x16008e60);
dwc_ddrphy_apb_wr_32b(0x5177a, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x5177c, 0x2b40000c);
dwc_ddrphy_apb_wr_32b(0x5177e, 0x201a055e);
dwc_ddrphy_apb_wr_32b(0x51780, 0x10f8b);
dwc_ddrphy_apb_wr_32b(0x51782, 0x260586a0);
dwc_ddrphy_apb_wr_32b(0x51784, 0x90023f80);
dwc_ddrphy_apb_wr_32b(0x51786, 0x90000086);
dwc_ddrphy_apb_wr_32b(0x51788, 0x11c22b41);
dwc_ddrphy_apb_wr_32b(0x5178a, 0x812044);
dwc_ddrphy_apb_wr_32b(0x5178c, 0x110a7143);
dwc_ddrphy_apb_wr_32b(0x5178e, 0x4a100700);
dwc_ddrphy_apb_wr_32b(0x51790, 0xc2048);
dwc_ddrphy_apb_wr_32b(0x51792, 0x7001108);
dwc_ddrphy_apb_wr_32b(0x51794, 0x10002c05);
dwc_ddrphy_apb_wr_32b(0x51796, 0x2189790f);
dwc_ddrphy_apb_wr_32b(0x51798, 0x26050fc1);
dwc_ddrphy_apb_wr_32b(0x5179a, 0x90033f80);
dwc_ddrphy_apb_wr_32b(0x5179c, 0xb020fe80);
dwc_ddrphy_apb_wr_32b(0x5179e, 0xe808ca0c);
dwc_ddrphy_apb_wr_32b(0x517a0, 0x3f802605);
dwc_ddrphy_apb_wr_32b(0x517a2, 0xfe609003);
dwc_ddrphy_apb_wr_32b(0x517a4, 0xf00bb020);
dwc_ddrphy_apb_wr_32b(0x517a6, 0x40c3eb89);
dwc_ddrphy_apb_wr_32b(0x517a8, 0xfe609003);
dwc_ddrphy_apb_wr_32b(0x517aa, 0x1840b020);
dwc_ddrphy_apb_wr_32b(0x517ac, 0x18600044);
dwc_ddrphy_apb_wr_32b(0x517ae, 0x2b050044);
dwc_ddrphy_apb_wr_32b(0x517b0, 0x1f80);
dwc_ddrphy_apb_wr_32b(0x517b2, 0x7104fa00);
dwc_ddrphy_apb_wr_32b(0x517b4, 0x1fe081b);
dwc_ddrphy_apb_wr_32b(0x517b6, 0x2208746c);
dwc_ddrphy_apb_wr_32b(0x517b8, 0xf80);
dwc_ddrphy_apb_wr_32b(0x517ba, 0x70c388b8);
dwc_ddrphy_apb_wr_32b(0x517bc, 0x793cffff);
dwc_ddrphy_apb_wr_32b(0x517be, 0xd072884);
dwc_ddrphy_apb_wr_32b(0x517c0, 0x780f706c);
dwc_ddrphy_apb_wr_32b(0x517c2, 0xfc12089);
dwc_ddrphy_apb_wr_32b(0x517c4, 0x2005b803);
dwc_ddrphy_apb_wr_32b(0x517c6, 0x160000c2);
dwc_ddrphy_apb_wr_32b(0x517c8, 0x90047100);
dwc_ddrphy_apb_wr_32b(0x517ca, 0x26050164);
dwc_ddrphy_apb_wr_32b(0x517cc, 0x90053f81);
dwc_ddrphy_apb_wr_32b(0x517ce, 0xb8c1e164);
dwc_ddrphy_apb_wr_32b(0x517d0, 0xa967845);
dwc_ddrphy_apb_wr_32b(0x517d2, 0xb1000020);
dwc_ddrphy_apb_wr_32b(0x517d4, 0x800040c3);
dwc_ddrphy_apb_wr_32b(0x517d6, 0x45cb0988);
dwc_ddrphy_apb_wr_32b(0x517d8, 0x8948000);
dwc_ddrphy_apb_wr_32b(0x517da, 0x11800);
dwc_ddrphy_apb_wr_32b(0x517dc, 0xff6f0f22);
dwc_ddrphy_apb_wr_32b(0x517de, 0x9a640a1);
dwc_ddrphy_apb_wr_32b(0x517e0, 0x40a100e0);
dwc_ddrphy_apb_wr_32b(0x517e2, 0xe8088e00);
dwc_ddrphy_apb_wr_32b(0x517e4, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x517e6, 0x3f98000);
dwc_ddrphy_apb_wr_32b(0x517e8, 0x11f080d);
dwc_ddrphy_apb_wr_32b(0x517ea, 0xffcf0976);
dwc_ddrphy_apb_wr_32b(0x517ec, 0xff0f0f42);
dwc_ddrphy_apb_wr_32b(0x517ee, 0xffcf0996);
dwc_ddrphy_apb_wr_32b(0x517f0, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x517f2, 0x648000);
dwc_ddrphy_apb_wr_32b(0x517f4, 0xde080f);
dwc_ddrphy_apb_wr_32b(0x517f6, 0xb8839503);
dwc_ddrphy_apb_wr_32b(0x517f8, 0xff6f0a3e);
dwc_ddrphy_apb_wr_32b(0x517fa, 0x40a1b503);
dwc_ddrphy_apb_wr_32b(0x517fc, 0x972712c);
dwc_ddrphy_apb_wr_32b(0x517fe, 0x704c01e0);
dwc_ddrphy_apb_wr_32b(0x51800, 0x8119e09);
dwc_ddrphy_apb_wr_32b(0x51802, 0x94a0013);
dwc_ddrphy_apb_wr_32b(0x51804, 0xa52fe8f);
dwc_ddrphy_apb_wr_32b(0x51806, 0xd80d0020);
dwc_ddrphy_apb_wr_32b(0x51808, 0x200a4a);
dwc_ddrphy_apb_wr_32b(0x5180a, 0xb13700c);
dwc_ddrphy_apb_wr_32b(0x5180c, 0x700c30be);
dwc_ddrphy_apb_wr_32b(0x5180e, 0xc00e7e);
dwc_ddrphy_apb_wr_32b(0x51810, 0x200a3a);
dwc_ddrphy_apb_wr_32b(0x51812, 0x2344720c);
dwc_ddrphy_apb_wr_32b(0x51814, 0xf208b08d);
dwc_ddrphy_apb_wr_32b(0x51816, 0xe00e6e);
dwc_ddrphy_apb_wr_32b(0x51818, 0xa2a710c);
dwc_ddrphy_apb_wr_32b(0x5181a, 0x710c0020);
dwc_ddrphy_apb_wr_32b(0x5181c, 0x4208a);
dwc_ddrphy_apb_wr_32b(0x5181e, 0xb00f2304);
dwc_ddrphy_apb_wr_32b(0x51820, 0x8e00f209);
dwc_ddrphy_apb_wr_32b(0x51822, 0xe56e887);
dwc_ddrphy_apb_wr_32b(0x51824, 0x730c00e0);
dwc_ddrphy_apb_wr_32b(0x51826, 0x200a0e);
dwc_ddrphy_apb_wr_32b(0x51828, 0x2344d80a);
dwc_ddrphy_apb_wr_32b(0x5182a, 0xc046b200);
dwc_ddrphy_apb_wr_32b(0x5182c, 0xe42f207);
dwc_ddrphy_apb_wr_32b(0x5182e, 0x750c00e0);
dwc_ddrphy_apb_wr_32b(0x51830, 0x2009fa);
dwc_ddrphy_apb_wr_32b(0x51832, 0xed08d8fd);
dwc_ddrphy_apb_wr_32b(0x51834, 0xe00e32);
dwc_ddrphy_apb_wr_32b(0x51836, 0x9ee720c);
dwc_ddrphy_apb_wr_32b(0x51838, 0xd8fe0020);
dwc_ddrphy_apb_wr_32b(0x5183a, 0xb4002344);
dwc_ddrphy_apb_wr_32b(0x5183c, 0xf208c044);
dwc_ddrphy_apb_wr_32b(0x5183e, 0xe00e1e);
dwc_ddrphy_apb_wr_32b(0x51840, 0x9da760c);
dwc_ddrphy_apb_wr_32b(0x51842, 0x740c0020);
dwc_ddrphy_apb_wr_32b(0x51844, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x51846, 0x3fe8000);
dwc_ddrphy_apb_wr_32b(0x51848, 0xde0825);
dwc_ddrphy_apb_wr_32b(0x5184a, 0x8e00ef10);
dwc_ddrphy_apb_wr_32b(0x5184c, 0x256fe88e);
dwc_ddrphy_apb_wr_32b(0x5184e, 0x8de01043);
dwc_ddrphy_apb_wr_32b(0x51850, 0x11402750);
dwc_ddrphy_apb_wr_32b(0x51852, 0xdf6ad00);
dwc_ddrphy_apb_wr_32b(0x51854, 0xd80e00e0);
dwc_ddrphy_apb_wr_32b(0x51856, 0x2009ae);
dwc_ddrphy_apb_wr_32b(0x51858, 0xade0d80a);
dwc_ddrphy_apb_wr_32b(0x5185a, 0xe808c006);
dwc_ddrphy_apb_wr_32b(0x5185c, 0xe00de2);
dwc_ddrphy_apb_wr_32b(0x5185e, 0x99e740c);
dwc_ddrphy_apb_wr_32b(0x51860, 0x730c0020);
dwc_ddrphy_apb_wr_32b(0x51862, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x51864, 0x3fe8000);
dwc_ddrphy_apb_wr_32b(0x51866, 0x9e0825);
dwc_ddrphy_apb_wr_32b(0x51868, 0xe810c004);
dwc_ddrphy_apb_wr_32b(0x5186a, 0x1043256f);
dwc_ddrphy_apb_wr_32b(0x5186c, 0x40e18de0);
dwc_ddrphy_apb_wr_32b(0x5186e, 0xfc22084);
dwc_ddrphy_apb_wr_32b(0x51870, 0xdbaad00);
dwc_ddrphy_apb_wr_32b(0x51872, 0x760c00e0);
dwc_ddrphy_apb_wr_32b(0x51874, 0x200972);
dwc_ddrphy_apb_wr_32b(0x51876, 0xade0740c);
dwc_ddrphy_apb_wr_32b(0x51878, 0xb2402351);
dwc_ddrphy_apb_wr_32b(0x5187a, 0x800043db);
dwc_ddrphy_apb_wr_32b(0x5187c, 0xf40b0988);
dwc_ddrphy_apb_wr_32b(0x5187e, 0xb8158e00);
dwc_ddrphy_apb_wr_32b(0x51880, 0xf812005);
dwc_ddrphy_apb_wr_32b(0x51882, 0xe0409003);
dwc_ddrphy_apb_wr_32b(0x51884, 0xb100c003);
dwc_ddrphy_apb_wr_32b(0x51886, 0x1b00f030);
dwc_ddrphy_apb_wr_32b(0x51888, 0xc6e3001);
dwc_ddrphy_apb_wr_32b(0x5188a, 0x16fdff2f);
dwc_ddrphy_apb_wr_32b(0x5188c, 0x4708908d);
dwc_ddrphy_apb_wr_32b(0x5188e, 0xff2f0d36);
dwc_ddrphy_apb_wr_32b(0x51890, 0xbde2710c);
dwc_ddrphy_apb_wr_32b(0x51892, 0x20ca710c);
dwc_ddrphy_apb_wr_32b(0x51894, 0xf6603e1);
dwc_ddrphy_apb_wr_32b(0x51896, 0x41e100e0);
dwc_ddrphy_apb_wr_32b(0x51898, 0xff0f0cfe);
dwc_ddrphy_apb_wr_32b(0x5189a, 0xff4f08c6);
dwc_ddrphy_apb_wr_32b(0x5189c, 0x702cc089);
dwc_ddrphy_apb_wr_32b(0x5189e, 0xffef0c1a);
dwc_ddrphy_apb_wr_32b(0x518a0, 0xc007da14);
dwc_ddrphy_apb_wr_32b(0x518a2, 0x714cc189);
dwc_ddrphy_apb_wr_32b(0x518a4, 0xc8eb814);
dwc_ddrphy_apb_wr_32b(0x518a6, 0xe02000a0);
dwc_ddrphy_apb_wr_32b(0x518a8, 0x19141c3);
dwc_ddrphy_apb_wr_32b(0x518aa, 0xd820000);
dwc_ddrphy_apb_wr_32b(0x518ac, 0x750cff2f);
dwc_ddrphy_apb_wr_32b(0x518ae, 0x712c700c);
dwc_ddrphy_apb_wr_32b(0x518b0, 0xfeef0c12);
dwc_ddrphy_apb_wr_32b(0x518b2, 0x8f6c289);
dwc_ddrphy_apb_wr_32b(0x518b4, 0xd8090020);
dwc_ddrphy_apb_wr_32b(0x518b6, 0xb3ec008);
dwc_ddrphy_apb_wr_32b(0x518b8, 0x1e5cffaf);
dwc_ddrphy_apb_wr_32b(0x518ba, 0xcc0e1004);
dwc_ddrphy_apb_wr_32b(0x518bc, 0x208c706c);
dwc_ddrphy_apb_wr_32b(0x518be, 0x742c8044);
dwc_ddrphy_apb_wr_32b(0x518c0, 0x6521ca);
dwc_ddrphy_apb_wr_32b(0x518c2, 0x650b63);
dwc_ddrphy_apb_wr_32b(0x518c4, 0x1014248a);
dwc_ddrphy_apb_wr_32b(0x518c6, 0x500b19);
dwc_ddrphy_apb_wr_32b(0x518c8, 0xf00b15);
dwc_ddrphy_apb_wr_32b(0x518ca, 0x1414248a);
dwc_ddrphy_apb_wr_32b(0x518cc, 0xb10b0b);
dwc_ddrphy_apb_wr_32b(0x518ce, 0x1214248a);
dwc_ddrphy_apb_wr_32b(0x518d0, 0xdca0f002);
dwc_ddrphy_apb_wr_32b(0x518d2, 0x1204704c);
dwc_ddrphy_apb_wr_32b(0x518d4, 0xa3b3081);
dwc_ddrphy_apb_wr_32b(0x518d6, 0x70ad0045);
dwc_ddrphy_apb_wr_32b(0x518d8, 0x12350d2f);
dwc_ddrphy_apb_wr_32b(0x518da, 0x3012a40);
dwc_ddrphy_apb_wr_32b(0x518dc, 0xb9907985);
dwc_ddrphy_apb_wr_32b(0x518de, 0x793b61b9);
dwc_ddrphy_apb_wr_32b(0x518e0, 0xf8f2105);
dwc_ddrphy_apb_wr_32b(0x518e2, 0x9000);
dwc_ddrphy_apb_wr_32b(0x518e4, 0x219a4160);
dwc_ddrphy_apb_wr_32b(0x518e6, 0x79560401);
dwc_ddrphy_apb_wr_32b(0x518e8, 0x716361b9);
dwc_ddrphy_apb_wr_32b(0x518ea, 0x811128);
dwc_ddrphy_apb_wr_32b(0x518ec, 0xb72071a5);
dwc_ddrphy_apb_wr_32b(0x518ee, 0x7144f1ea);
dwc_ddrphy_apb_wr_32b(0x518f0, 0x7164f1e3);
dwc_ddrphy_apb_wr_32b(0x518f2, 0xc000f1cb);
dwc_ddrphy_apb_wr_32b(0x518f4, 0xf812005);
dwc_ddrphy_apb_wr_32b(0x518f6, 0xe0329005);
dwc_ddrphy_apb_wr_32b(0x518f8, 0xb100c001);
dwc_ddrphy_apb_wr_32b(0x518fa, 0xae0cc002);
dwc_ddrphy_apb_wr_32b(0x518fc, 0x1e00c005);
dwc_ddrphy_apb_wr_32b(0x518fe, 0x90047004);
dwc_ddrphy_apb_wr_32b(0x51900, 0xa620074);
dwc_ddrphy_apb_wr_32b(0x51902, 0xd8070120);
dwc_ddrphy_apb_wr_32b(0x51904, 0x20ab700c);
dwc_ddrphy_apb_wr_32b(0x51906, 0x7fff00c4);
dwc_ddrphy_apb_wr_32b(0x51908, 0x78e0f1ff);
dwc_ddrphy_apb_wr_32b(0x5190a, 0x45cbc2e2);
dwc_ddrphy_apb_wr_32b(0x5190c, 0x49004);
dwc_ddrphy_apb_wr_32b(0x5190e, 0xb8a19500);
dwc_ddrphy_apb_wr_32b(0x51910, 0xeb2b500);
dwc_ddrphy_apb_wr_32b(0x51912, 0x740cffaf);
dwc_ddrphy_apb_wr_32b(0x51914, 0xeaad81f);
dwc_ddrphy_apb_wr_32b(0x51916, 0x1df6ffaf);
dwc_ddrphy_apb_wr_32b(0x51918, 0xc6c2105d);
dwc_ddrphy_apb_wr_32b(0x5191a, 0xe9ec2e2);
dwc_ddrphy_apb_wr_32b(0x5191c, 0xd81fffaf);
dwc_ddrphy_apb_wr_32b(0x5191e, 0x900445cb);
dwc_ddrphy_apb_wr_32b(0x51920, 0x740c01f0);
dwc_ddrphy_apb_wr_32b(0x51922, 0xffaf0e8e);
dwc_ddrphy_apb_wr_32b(0x51924, 0x10051d00);
dwc_ddrphy_apb_wr_32b(0x51926, 0x9700150a);
dwc_ddrphy_apb_wr_32b(0x51928, 0x1d0ab881);
dwc_ddrphy_apb_wr_32b(0x5192a, 0xc6c2901c);
dwc_ddrphy_apb_wr_32b(0x5192c, 0x1600c0f1);
dwc_ddrphy_apb_wr_32b(0x5192e, 0x80007081);
dwc_ddrphy_apb_wr_32b(0x51930, 0x218c0018);
dwc_ddrphy_apb_wr_32b(0x51932, 0x9fc8203);
dwc_ddrphy_apb_wr_32b(0x51934, 0x80e010e);
dwc_ddrphy_apb_wr_32b(0x51936, 0xc0d10000);
dwc_ddrphy_apb_wr_32b(0x51938, 0x78e07ee0);
dwc_ddrphy_apb_wr_32b(0x5193a, 0x1600c2e2);
dwc_ddrphy_apb_wr_32b(0x5193c, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x5193e, 0x81b0001);
dwc_ddrphy_apb_wr_32b(0x51940, 0xd80a003e);
dwc_ddrphy_apb_wr_32b(0x51942, 0x900545cb);
dwc_ddrphy_apb_wr_32b(0x51944, 0xe4ae036);
dwc_ddrphy_apb_wr_32b(0x51946, 0x1d00ffaf);
dwc_ddrphy_apb_wr_32b(0x51948, 0x1d001045);
dwc_ddrphy_apb_wr_32b(0x5194a, 0xc6c21005);
dwc_ddrphy_apb_wr_32b(0x5194c, 0x706dc2e2);
dwc_ddrphy_apb_wr_32b(0x5194e, 0x900445cb);
dwc_ddrphy_apb_wr_32b(0x51950, 0xb1f00f2);
dwc_ddrphy_apb_wr_32b(0x51952, 0xd82010f5);
dwc_ddrphy_apb_wr_32b(0x51954, 0xffaf0e2a);
dwc_ddrphy_apb_wr_32b(0x51956, 0x10451d00);
dwc_ddrphy_apb_wr_32b(0x51958, 0xe22d820);
dwc_ddrphy_apb_wr_32b(0x5195a, 0x1d00ffaf);
dwc_ddrphy_apb_wr_32b(0x5195c, 0x71651005);
dwc_ddrphy_apb_wr_32b(0x5195e, 0xc6c2f1f3);
dwc_ddrphy_apb_wr_32b(0x51960, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x51962, 0x2482b6c8);
dwc_ddrphy_apb_wr_32b(0x51964, 0xc0513002);
dwc_ddrphy_apb_wr_32b(0x51966, 0x70001600);
dwc_ddrphy_apb_wr_32b(0x51968, 0x9888000);
dwc_ddrphy_apb_wr_32b(0x5196a, 0x712c4628);
dwc_ddrphy_apb_wr_32b(0x5196c, 0xb2e4768);
dwc_ddrphy_apb_wr_32b(0x5196e, 0xc24eff2f);
dwc_ddrphy_apb_wr_32b(0x51970, 0x236dc053);
dwc_ddrphy_apb_wr_32b(0x51972, 0xcb20200);
dwc_ddrphy_apb_wr_32b(0x51974, 0x4318ff6f);
dwc_ddrphy_apb_wr_32b(0x51976, 0x71adc00e);
dwc_ddrphy_apb_wr_32b(0x51978, 0xc052b863);
dwc_ddrphy_apb_wr_32b(0x5197a, 0x3000149c);
dwc_ddrphy_apb_wr_32b(0x5197c, 0x1498c04f);
dwc_ddrphy_apb_wr_32b(0x5197e, 0xb213000);
dwc_ddrphy_apb_wr_32b(0x51980, 0xc0503030);
dwc_ddrphy_apb_wr_32b(0x51982, 0x819c012);
dwc_ddrphy_apb_wr_32b(0x51984, 0x16000114);
dwc_ddrphy_apb_wr_32b(0x51986, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x51988, 0x80d03f9);
dwc_ddrphy_apb_wr_32b(0x5198a, 0xda4001be);
dwc_ddrphy_apb_wr_32b(0x5198c, 0xfecf099e);
dwc_ddrphy_apb_wr_32b(0x5198e, 0x42c3c011);
dwc_ddrphy_apb_wr_32b(0x51990, 0xe0c49003);
dwc_ddrphy_apb_wr_32b(0x51992, 0x7d187077);
dwc_ddrphy_apb_wr_32b(0x51994, 0x10c02753);
dwc_ddrphy_apb_wr_32b(0x51996, 0xd9f0b200);
dwc_ddrphy_apb_wr_32b(0x51998, 0xc07208a);
dwc_ddrphy_apb_wr_32b(0x5199a, 0x4120ca);
dwc_ddrphy_apb_wr_32b(0x5199c, 0x3c12004);
dwc_ddrphy_apb_wr_32b(0x5199e, 0xb220ba8b);
dwc_ddrphy_apb_wr_32b(0x519a0, 0x702cc096);
dwc_ddrphy_apb_wr_32b(0x519a2, 0xa12da28);
dwc_ddrphy_apb_wr_32b(0x519a4, 0xc396ffef);
dwc_ddrphy_apb_wr_32b(0x519a6, 0x20b878ef);
dwc_ddrphy_apb_wr_32b(0x519a8, 0xc06d0fc3);
dwc_ddrphy_apb_wr_32b(0x519aa, 0xb808d80f);
dwc_ddrphy_apb_wr_32b(0x519ac, 0xd820c04b);
dwc_ddrphy_apb_wr_32b(0x519ae, 0xc00fc04a);
dwc_ddrphy_apb_wr_32b(0x519b0, 0x1c24c74c);
dwc_ddrphy_apb_wr_32b(0x519b2, 0xc0453003);
dwc_ddrphy_apb_wr_32b(0x519b4, 0xc648c010);
dwc_ddrphy_apb_wr_32b(0x519b6, 0x31031c1c);
dwc_ddrphy_apb_wr_32b(0x519b8, 0xc011c044);
dwc_ddrphy_apb_wr_32b(0x519ba, 0xc043c346);
dwc_ddrphy_apb_wr_32b(0x519bc, 0x1c25c00e);
dwc_ddrphy_apb_wr_32b(0x519be, 0xc0123002);
dwc_ddrphy_apb_wr_32b(0x519c0, 0x134080f);
dwc_ddrphy_apb_wr_32b(0x519c2, 0xc011712c);
dwc_ddrphy_apb_wr_32b(0x519c4, 0xe00fc2);
dwc_ddrphy_apb_wr_32b(0x519c6, 0x1494780f);
dwc_ddrphy_apb_wr_32b(0x519c8, 0xc10e3000);
dwc_ddrphy_apb_wr_32b(0x519ca, 0xc0557daf);
dwc_ddrphy_apb_wr_32b(0x519cc, 0x200a2a);
dwc_ddrphy_apb_wr_32b(0x519ce, 0xf0240a1);
dwc_ddrphy_apb_wr_32b(0x519d0, 0xc0830020);
dwc_ddrphy_apb_wr_32b(0x519d2, 0x70031600);
dwc_ddrphy_apb_wr_32b(0x519d4, 0x98c8000);
dwc_ddrphy_apb_wr_32b(0x519d6, 0x70001600);
dwc_ddrphy_apb_wr_32b(0x519d8, 0x9908000);
dwc_ddrphy_apb_wr_32b(0x519da, 0xe20841);
dwc_ddrphy_apb_wr_32b(0x519dc, 0x412344);
dwc_ddrphy_apb_wr_32b(0x519de, 0x7a0fc013);
dwc_ddrphy_apb_wr_32b(0x519e0, 0x8aa787d);
dwc_ddrphy_apb_wr_32b(0x519e2, 0x780fffaf);
dwc_ddrphy_apb_wr_32b(0x519e4, 0xc096e80e);
dwc_ddrphy_apb_wr_32b(0x519e6, 0xc220f5);
dwc_ddrphy_apb_wr_32b(0x519e8, 0x8130a21);
dwc_ddrphy_apb_wr_32b(0x519ea, 0x20f4c010);
dwc_ddrphy_apb_wr_32b(0x519ec, 0xe88c00c0);
dwc_ddrphy_apb_wr_32b(0x519ee, 0x2242c110);
dwc_ddrphy_apb_wr_32b(0x519f0, 0xf0060800);
dwc_ddrphy_apb_wr_32b(0x519f2, 0x40c3c110);
dwc_ddrphy_apb_wr_32b(0x519f4, 0x1fff0000);
dwc_ddrphy_apb_wr_32b(0x519f6, 0xb1007974);
dwc_ddrphy_apb_wr_32b(0x519f8, 0xf1de7164);
dwc_ddrphy_apb_wr_32b(0x519fa, 0x7704c00e);
dwc_ddrphy_apb_wr_32b(0x519fc, 0xb50835);
dwc_ddrphy_apb_wr_32b(0x519fe, 0x46cb7077);
dwc_ddrphy_apb_wr_32b(0x51a00, 0xf0f00000);
dwc_ddrphy_apb_wr_32b(0x51a02, 0x47cb);
dwc_ddrphy_apb_wr_32b(0x51a04, 0x43c1ffff);
dwc_ddrphy_apb_wr_32b(0x51a06, 0xd80f73fd);
dwc_ddrphy_apb_wr_32b(0x51a08, 0x42c141c1);
dwc_ddrphy_apb_wr_32b(0x51a0a, 0xff6f0972);
dwc_ddrphy_apb_wr_32b(0x51a0c, 0x7077c340);
dwc_ddrphy_apb_wr_32b(0x51a0e, 0xd80877dd);
dwc_ddrphy_apb_wr_32b(0x51a10, 0x42c141c1);
dwc_ddrphy_apb_wr_32b(0x51a12, 0x96243e1);
dwc_ddrphy_apb_wr_32b(0x51a14, 0xc740ff6f);
dwc_ddrphy_apb_wr_32b(0x51a16, 0x200ff6);
dwc_ddrphy_apb_wr_32b(0x51a18, 0x1600c083);
dwc_ddrphy_apb_wr_32b(0x51a1a, 0x80007003);
dwc_ddrphy_apb_wr_32b(0x51a1c, 0x1600098c);
dwc_ddrphy_apb_wr_32b(0x51a1e, 0x80007000);
dwc_ddrphy_apb_wr_32b(0x51a20, 0x8410990);
dwc_ddrphy_apb_wr_32b(0x51a22, 0x234400e2);
dwc_ddrphy_apb_wr_32b(0x51a24, 0xc0130041);
dwc_ddrphy_apb_wr_32b(0x51a26, 0x787d7a0f);
dwc_ddrphy_apb_wr_32b(0x51a28, 0xffaf081a);
dwc_ddrphy_apb_wr_32b(0x51a2a, 0xe80f780f);
dwc_ddrphy_apb_wr_32b(0x51a2c, 0x20f5c096);
dwc_ddrphy_apb_wr_32b(0x51a2e, 0xa2100c2);
dwc_ddrphy_apb_wr_32b(0x51a30, 0xc00f0813);
dwc_ddrphy_apb_wr_32b(0x51a32, 0xc020f4);
dwc_ddrphy_apb_wr_32b(0x51a34, 0x7f10815);
dwc_ddrphy_apb_wr_32b(0x51a36, 0xc10f4a48);
dwc_ddrphy_apb_wr_32b(0x51a38, 0xc10ff004);
dwc_ddrphy_apb_wr_32b(0x51a3a, 0xb80dd807);
dwc_ddrphy_apb_wr_32b(0x51a3c, 0xb1007974);
dwc_ddrphy_apb_wr_32b(0x51a3e, 0xf1df7164);
dwc_ddrphy_apb_wr_32b(0x51a40, 0x837c012);
dwc_ddrphy_apb_wr_32b(0x51a42, 0x40a10134);
dwc_ddrphy_apb_wr_32b(0x51a44, 0xff8f0b8a);
dwc_ddrphy_apb_wr_32b(0x51a46, 0x30100b2b);
dwc_ddrphy_apb_wr_32b(0x51a48, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x51a4a, 0x3f98000);
dwc_ddrphy_apb_wr_32b(0x51a4c, 0x1be081f);
dwc_ddrphy_apb_wr_32b(0x51a4e, 0x40c3da40);
dwc_ddrphy_apb_wr_32b(0x51a50, 0x8948000);
dwc_ddrphy_apb_wr_32b(0x51a52, 0x21049025);
dwc_ddrphy_apb_wr_32b(0x51a54, 0xf81);
dwc_ddrphy_apb_wr_32b(0x51a56, 0xb025fbff);
dwc_ddrphy_apb_wr_32b(0x51a58, 0x1a00cba);
dwc_ddrphy_apb_wr_32b(0x51a5a, 0x752c712c);
dwc_ddrphy_apb_wr_32b(0x51a5c, 0xa1e740c);
dwc_ddrphy_apb_wr_32b(0x51a5e, 0xb914ff2f);
dwc_ddrphy_apb_wr_32b(0x51a60, 0x700d1600);
dwc_ddrphy_apb_wr_32b(0x51a62, 0x98c8000);
dwc_ddrphy_apb_wr_32b(0x51a64, 0x70001600);
dwc_ddrphy_apb_wr_32b(0x51a66, 0x9908000);
dwc_ddrphy_apb_wr_32b(0x51a68, 0x36208cd);
dwc_ddrphy_apb_wr_32b(0x51a6a, 0x104e2544);
dwc_ddrphy_apb_wr_32b(0x51a6c, 0x7fbcc010);
dwc_ddrphy_apb_wr_32b(0x51a6e, 0x20f541c1);
dwc_ddrphy_apb_wr_32b(0x51a70, 0xc00f034b);
dwc_ddrphy_apb_wr_32b(0x51a72, 0x34320f5);
dwc_ddrphy_apb_wr_32b(0x51a74, 0x780fc013);
dwc_ddrphy_apb_wr_32b(0x51a76, 0xc214c054);
dwc_ddrphy_apb_wr_32b(0x51a78, 0xf7a78ef);
dwc_ddrphy_apb_wr_32b(0x51a7a, 0xc04eff6f);
dwc_ddrphy_apb_wr_32b(0x51a7c, 0x79b4c115);
dwc_ddrphy_apb_wr_32b(0x51a7e, 0x2302e830);
dwc_ddrphy_apb_wr_32b(0x51a80, 0x736102c0);
dwc_ddrphy_apb_wr_32b(0x51a82, 0x1b2048);
dwc_ddrphy_apb_wr_32b(0x51a84, 0x2048787c);
dwc_ddrphy_apb_wr_32b(0x51a86, 0x20490000);
dwc_ddrphy_apb_wr_32b(0x51a88, 0xc01007c2);
dwc_ddrphy_apb_wr_32b(0x51a8a, 0x43c1b140);
dwc_ddrphy_apb_wr_32b(0x51a8c, 0x34120f5);
dwc_ddrphy_apb_wr_32b(0x51a8e, 0x20f5c00f);
dwc_ddrphy_apb_wr_32b(0x51a90, 0xc2420340);
dwc_ddrphy_apb_wr_32b(0x51a92, 0xc041c140);
dwc_ddrphy_apb_wr_32b(0x51a94, 0x41c3740c);
dwc_ddrphy_apb_wr_32b(0x51a96, 0x50052);
dwc_ddrphy_apb_wr_32b(0x51a98, 0xff2f09a6);
dwc_ddrphy_apb_wr_32b(0x51a9a, 0x160042e1);
dwc_ddrphy_apb_wr_32b(0x51a9c, 0x800070c1);
dwc_ddrphy_apb_wr_32b(0x51a9e, 0x93b0001);
dwc_ddrphy_apb_wr_32b(0x51aa0, 0x202f0032);
dwc_ddrphy_apb_wr_32b(0x51aa2, 0xc04006c6);
dwc_ddrphy_apb_wr_32b(0x51aa4, 0x140207f);
dwc_ddrphy_apb_wr_32b(0x51aa6, 0x5441c3);
dwc_ddrphy_apb_wr_32b(0x51aa8, 0x42e10003);
dwc_ddrphy_apb_wr_32b(0x51aaa, 0xfe6f0b92);
dwc_ddrphy_apb_wr_32b(0x51aac, 0xf02043c1);
dwc_ddrphy_apb_wr_32b(0x51aae, 0x40c3);
dwc_ddrphy_apb_wr_32b(0x51ab0, 0xb1007fff);
dwc_ddrphy_apb_wr_32b(0x51ab2, 0x41c3740c);
dwc_ddrphy_apb_wr_32b(0x51ab4, 0x20051);
dwc_ddrphy_apb_wr_32b(0x51ab6, 0x96a42e1);
dwc_ddrphy_apb_wr_32b(0x51ab8, 0x43c1ff2f);
dwc_ddrphy_apb_wr_32b(0x51aba, 0x825f012);
dwc_ddrphy_apb_wr_32b(0x51abc, 0x43e101b3);
dwc_ddrphy_apb_wr_32b(0x51abe, 0xc041c213);
dwc_ddrphy_apb_wr_32b(0x51ac0, 0x41c3740c);
dwc_ddrphy_apb_wr_32b(0x51ac2, 0x40053);
dwc_ddrphy_apb_wr_32b(0x51ac4, 0xff2f094e);
dwc_ddrphy_apb_wr_32b(0x51ac6, 0xc00ec640);
dwc_ddrphy_apb_wr_32b(0x51ac8, 0xee2c214);
dwc_ddrphy_apb_wr_32b(0x51aca, 0x41c100a0);
dwc_ddrphy_apb_wr_32b(0x51acc, 0xf19871a5);
dwc_ddrphy_apb_wr_32b(0x51ace, 0x811c012);
dwc_ddrphy_apb_wr_32b(0x51ad0, 0x702c0134);
dwc_ddrphy_apb_wr_32b(0x51ad2, 0xda6c011);
dwc_ddrphy_apb_wr_32b(0x51ad4, 0x780f00e0);
dwc_ddrphy_apb_wr_32b(0x51ad6, 0x70051e00);
dwc_ddrphy_apb_wr_32b(0x51ad8, 0xe0049003);
dwc_ddrphy_apb_wr_32b(0x51ada, 0x30022480);
dwc_ddrphy_apb_wr_32b(0x51adc, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x51ade, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x51ae0, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x51ae2, 0xc1acb6c8);
dwc_ddrphy_apb_wr_32b(0x51ae4, 0xc045c144);
dwc_ddrphy_apb_wr_32b(0x51ae6, 0xb863c004);
dwc_ddrphy_apb_wr_32b(0x51ae8, 0xe0ac049);
dwc_ddrphy_apb_wr_32b(0x51aea, 0x7e0fff2f);
dwc_ddrphy_apb_wr_32b(0x51aec, 0xfeef0fa6);
dwc_ddrphy_apb_wr_32b(0x51aee, 0x4508c046);
dwc_ddrphy_apb_wr_32b(0x51af0, 0x859c009);
dwc_ddrphy_apb_wr_32b(0x51af2, 0x700c0134);
dwc_ddrphy_apb_wr_32b(0x51af4, 0xfeef084a);
dwc_ddrphy_apb_wr_32b(0x51af6, 0x1200d9ff);
dwc_ddrphy_apb_wr_32b(0x51af8, 0x712c3083);
dwc_ddrphy_apb_wr_32b(0x51afa, 0xd8ff70ed);
dwc_ddrphy_apb_wr_32b(0x51afc, 0x754cb98e);
dwc_ddrphy_apb_wr_32b(0x51afe, 0xc742c743);
dwc_ddrphy_apb_wr_32b(0x51b00, 0x90ac741);
dwc_ddrphy_apb_wr_32b(0x51b02, 0xc740feef);
dwc_ddrphy_apb_wr_32b(0x51b04, 0xd911c005);
dwc_ddrphy_apb_wr_32b(0x51b06, 0x780fb90a);
dwc_ddrphy_apb_wr_32b(0x51b08, 0xd8ffc042);
dwc_ddrphy_apb_wr_32b(0x51b0a, 0xdb7c704c);
dwc_ddrphy_apb_wr_32b(0x51b0c, 0x30411c0c);
dwc_ddrphy_apb_wr_32b(0x51b0e, 0x8eec741);
dwc_ddrphy_apb_wr_32b(0x51b10, 0xc740feef);
dwc_ddrphy_apb_wr_32b(0x51b12, 0xfe8f0e06);
dwc_ddrphy_apb_wr_32b(0x51b14, 0xc742c743);
dwc_ddrphy_apb_wr_32b(0x51b16, 0x8dec741);
dwc_ddrphy_apb_wr_32b(0x51b18, 0xc740feef);
dwc_ddrphy_apb_wr_32b(0x51b1a, 0xfe8f0dd6);
dwc_ddrphy_apb_wr_32b(0x51b1c, 0x110f267d);
dwc_ddrphy_apb_wr_32b(0x51b1e, 0xff2f0e0a);
dwc_ddrphy_apb_wr_32b(0x51b20, 0x100e2579);
dwc_ddrphy_apb_wr_32b(0x51b22, 0x2014c106);
dwc_ddrphy_apb_wr_32b(0x51b24, 0x4d58004d);
dwc_ddrphy_apb_wr_32b(0x51b26, 0xff2f0e0a);
dwc_ddrphy_apb_wr_32b(0x51b28, 0x5b2044);
dwc_ddrphy_apb_wr_32b(0x51b2a, 0x214448a8);
dwc_ddrphy_apb_wr_32b(0x51b2c, 0xc1040043);
dwc_ddrphy_apb_wr_32b(0x51b2e, 0xfc7228a);
dwc_ddrphy_apb_wr_32b(0x51b30, 0xc0f6989);
dwc_ddrphy_apb_wr_32b(0x51b32, 0x7eeb10b5);
dwc_ddrphy_apb_wr_32b(0x51b34, 0x752cf20b);
dwc_ddrphy_apb_wr_32b(0x51b36, 0xc109f00a);
dwc_ddrphy_apb_wr_32b(0x51b38, 0xd9087434);
dwc_ddrphy_apb_wr_32b(0x51b3a, 0x6521ca);
dwc_ddrphy_apb_wr_32b(0x51b3c, 0x2622ca);
dwc_ddrphy_apb_wr_32b(0x51b3e, 0x712cf002);
dwc_ddrphy_apb_wr_32b(0x51b40, 0x335b2300);
dwc_ddrphy_apb_wr_32b(0x51b42, 0x40c3631d);
dwc_ddrphy_apb_wr_32b(0x51b44, 0xe0c0900f);
dwc_ddrphy_apb_wr_32b(0x51b46, 0xb045b020);
dwc_ddrphy_apb_wr_32b(0x51b48, 0xffff40c3);
dwc_ddrphy_apb_wr_32b(0x51b4a, 0x7eebf0f0);
dwc_ddrphy_apb_wr_32b(0x51b4c, 0x770cc047);
dwc_ddrphy_apb_wr_32b(0x51b4e, 0xffff41c3);
dwc_ddrphy_apb_wr_32b(0x51b50, 0xc04af0f0);
dwc_ddrphy_apb_wr_32b(0x51b52, 0xc04a703c);
dwc_ddrphy_apb_wr_32b(0x51b54, 0x774cc007);
dwc_ddrphy_apb_wr_32b(0x51b56, 0xc2f705c);
dwc_ddrphy_apb_wr_32b(0x51b58, 0xc04710b5);
dwc_ddrphy_apb_wr_32b(0x51b5a, 0x46cbc007);
dwc_ddrphy_apb_wr_32b(0x51b5c, 0xf0f00000);
dwc_ddrphy_apb_wr_32b(0x51b5e, 0x7b1041c1);
dwc_ddrphy_apb_wr_32b(0x51b60, 0x42c1d80f);
dwc_ddrphy_apb_wr_32b(0x51b62, 0xff2f0ec2);
dwc_ddrphy_apb_wr_32b(0x51b64, 0xc00ac340);
dwc_ddrphy_apb_wr_32b(0x51b66, 0x42c141c1);
dwc_ddrphy_apb_wr_32b(0x51b68, 0xd8087b10);
dwc_ddrphy_apb_wr_32b(0x51b6a, 0xff2f0eb2);
dwc_ddrphy_apb_wr_32b(0x51b6c, 0xc004c340);
dwc_ddrphy_apb_wr_32b(0x51b6e, 0x3a1b2340);
dwc_ddrphy_apb_wr_32b(0x51b70, 0xb881e510);
dwc_ddrphy_apb_wr_32b(0x51b72, 0x36c01c20);
dwc_ddrphy_apb_wr_32b(0x51b74, 0xb108e9);
dwc_ddrphy_apb_wr_32b(0x51b76, 0xc006c54b);
dwc_ddrphy_apb_wr_32b(0x51b78, 0xf42790f);
dwc_ddrphy_apb_wr_32b(0x51b7a, 0x700cfeaf);
dwc_ddrphy_apb_wr_32b(0x51b7c, 0xfe8f0e0e);
dwc_ddrphy_apb_wr_32b(0x51b7e, 0xc142c143);
dwc_ddrphy_apb_wr_32b(0x51b80, 0x80ac141);
dwc_ddrphy_apb_wr_32b(0x51b82, 0xc140feef);
dwc_ddrphy_apb_wr_32b(0x51b84, 0xfeef0a72);
dwc_ddrphy_apb_wr_32b(0x51b86, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x51b88, 0xb98ed8ff);
dwc_ddrphy_apb_wr_32b(0x51b8a, 0x726c754c);
dwc_ddrphy_apb_wr_32b(0x51b8c, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x51b8e, 0xfeec541);
dwc_ddrphy_apb_wr_32b(0x51b90, 0xc540feaf);
dwc_ddrphy_apb_wr_32b(0x51b92, 0xdf75ca0b);
dwc_ddrphy_apb_wr_32b(0x51b94, 0xc043bf08);
dwc_ddrphy_apb_wr_32b(0x51b96, 0x43dbc005);
dwc_ddrphy_apb_wr_32b(0x51b98, 0x10000000);
dwc_ddrphy_apb_wr_32b(0x51b9a, 0x7e0f41e1);
dwc_ddrphy_apb_wr_32b(0x51b9c, 0x724cd8ff);
dwc_ddrphy_apb_wr_32b(0x51b9e, 0xc642746c);
dwc_ddrphy_apb_wr_32b(0x51ba0, 0xfcac541);
dwc_ddrphy_apb_wr_32b(0x51ba2, 0x1c00feaf);
dwc_ddrphy_apb_wr_32b(0x51ba4, 0xc00b36c0);
dwc_ddrphy_apb_wr_32b(0x51ba6, 0xb98e702c);
dwc_ddrphy_apb_wr_32b(0x51ba8, 0xd8ff7b0f);
dwc_ddrphy_apb_wr_32b(0x51baa, 0xc543754c);
dwc_ddrphy_apb_wr_32b(0x51bac, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x51bae, 0xfeaf0fae);
dwc_ddrphy_apb_wr_32b(0x51bb0, 0xa72c540);
dwc_ddrphy_apb_wr_32b(0x51bb2, 0x40c1ff2f);
dwc_ddrphy_apb_wr_32b(0x51bb4, 0x2750ca0b);
dwc_ddrphy_apb_wr_32b(0x51bb6, 0x714c1301);
dwc_ddrphy_apb_wr_32b(0x51bb8, 0xd8ffc043);
dwc_ddrphy_apb_wr_32b(0x51bba, 0xc642746c);
dwc_ddrphy_apb_wr_32b(0x51bbc, 0xf92c541);
dwc_ddrphy_apb_wr_32b(0x51bbe, 0x1c00feaf);
dwc_ddrphy_apb_wr_32b(0x51bc0, 0xa1636c0);
dwc_ddrphy_apb_wr_32b(0x51bc2, 0x40c1ff2f);
dwc_ddrphy_apb_wr_32b(0x51bc4, 0x702cc008);
dwc_ddrphy_apb_wr_32b(0x51bc6, 0x7b0f754c);
dwc_ddrphy_apb_wr_32b(0x51bc8, 0xc543d8ff);
dwc_ddrphy_apb_wr_32b(0x51bca, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x51bcc, 0xfeaf0f72);
dwc_ddrphy_apb_wr_32b(0x51bce, 0x700cc540);
dwc_ddrphy_apb_wr_32b(0x51bd0, 0x791bb88e);
dwc_ddrphy_apb_wr_32b(0x51bd2, 0xfe8f0d86);
dwc_ddrphy_apb_wr_32b(0x51bd4, 0x30c11c0c);
dwc_ddrphy_apb_wr_32b(0x51bd6, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x51bd8, 0xfeaf0f5a);
dwc_ddrphy_apb_wr_32b(0x51bda, 0xd6ac540);
dwc_ddrphy_apb_wr_32b(0x51bdc, 0xc543fe8f);
dwc_ddrphy_apb_wr_32b(0x51bde, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x51be0, 0xfeaf0f4a);
dwc_ddrphy_apb_wr_32b(0x51be2, 0x98ac540);
dwc_ddrphy_apb_wr_32b(0x51be4, 0xd8fffeef);
dwc_ddrphy_apb_wr_32b(0x51be6, 0x2b5);
dwc_ddrphy_apb_wr_32b(0x51be8, 0x82dc009);
dwc_ddrphy_apb_wr_32b(0x51bea, 0x70ad0135);
dwc_ddrphy_apb_wr_32b(0x51bec, 0x46cbc004);
dwc_ddrphy_apb_wr_32b(0x51bee, 0xaaaa0000);
dwc_ddrphy_apb_wr_32b(0x51bf0, 0x70ed7314);
dwc_ddrphy_apb_wr_32b(0x51bf2, 0xc004f2e8);
dwc_ddrphy_apb_wr_32b(0x51bf4, 0xf2df7514);
dwc_ddrphy_apb_wr_32b(0x51bf6, 0x7414c004);
dwc_ddrphy_apb_wr_32b(0x51bf8, 0x46cbf4e0);
dwc_ddrphy_apb_wr_32b(0x51bfa, 0xcccc0000);
dwc_ddrphy_apb_wr_32b(0x51bfc, 0xf0de71ed);
dwc_ddrphy_apb_wr_32b(0x51bfe, 0x7114c004);
dwc_ddrphy_apb_wr_32b(0x51c00, 0x220294);
dwc_ddrphy_apb_wr_32b(0x51c02, 0x700c70cd);
dwc_ddrphy_apb_wr_32b(0x51c04, 0xc006c044);
dwc_ddrphy_apb_wr_32b(0x51c06, 0xc0047d0f);
dwc_ddrphy_apb_wr_32b(0x51c08, 0x9508e7);
dwc_ddrphy_apb_wr_32b(0x51c0a, 0x47cbc007);
dwc_ddrphy_apb_wr_32b(0x51c0c, 0xffff0000);
dwc_ddrphy_apb_wr_32b(0x51c0e, 0xc0047b10);
dwc_ddrphy_apb_wr_32b(0x51c10, 0x7014c340);
dwc_ddrphy_apb_wr_32b(0x51c12, 0xd80f7fc0);
dwc_ddrphy_apb_wr_32b(0x51c14, 0xd5e41e1);
dwc_ddrphy_apb_wr_32b(0x51c16, 0x42e1ff2f);
dwc_ddrphy_apb_wr_32b(0x51c18, 0x41e1c00a);
dwc_ddrphy_apb_wr_32b(0x51c1a, 0x7b1042e1);
dwc_ddrphy_apb_wr_32b(0x51c1c, 0xd4ed808);
dwc_ddrphy_apb_wr_32b(0x51c1e, 0xc340ff2f);
dwc_ddrphy_apb_wr_32b(0x51c20, 0xdf2700c);
dwc_ddrphy_apb_wr_32b(0x51c22, 0x41a1feaf);
dwc_ddrphy_apb_wr_32b(0x51c24, 0xfe8f0cbe);
dwc_ddrphy_apb_wr_32b(0x51c26, 0xc142c143);
dwc_ddrphy_apb_wr_32b(0x51c28, 0xebac141);
dwc_ddrphy_apb_wr_32b(0x51c2a, 0xc140feaf);
dwc_ddrphy_apb_wr_32b(0x51c2c, 0xbf8e70ed);
dwc_ddrphy_apb_wr_32b(0x51c2e, 0x41e1d8ff);
dwc_ddrphy_apb_wr_32b(0x51c30, 0x726c754c);
dwc_ddrphy_apb_wr_32b(0x51c32, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x51c34, 0xea2c541);
dwc_ddrphy_apb_wr_32b(0x51c36, 0xc540feaf);
dwc_ddrphy_apb_wr_32b(0x51c38, 0xc043730c);
dwc_ddrphy_apb_wr_32b(0x51c3a, 0xbf8ac005);
dwc_ddrphy_apb_wr_32b(0x51c3c, 0x232f41e1);
dwc_ddrphy_apb_wr_32b(0x51c3e, 0xd8ff3007);
dwc_ddrphy_apb_wr_32b(0x51c40, 0x1c08724c);
dwc_ddrphy_apb_wr_32b(0x51c42, 0xc54136c0);
dwc_ddrphy_apb_wr_32b(0x51c44, 0x3f801c00);
dwc_ddrphy_apb_wr_32b(0x51c46, 0x100a0000);
dwc_ddrphy_apb_wr_32b(0x51c48, 0xfeaf0e7a);
dwc_ddrphy_apb_wr_32b(0x51c4a, 0x730c746c);
dwc_ddrphy_apb_wr_32b(0x51c4c, 0xc004c043);
dwc_ddrphy_apb_wr_32b(0x51c4e, 0x724c41e1);
dwc_ddrphy_apb_wr_32b(0x51c50, 0x2078);
dwc_ddrphy_apb_wr_32b(0x51c52, 0xc040b80c);
dwc_ddrphy_apb_wr_32b(0x51c54, 0x746cd8ff);
dwc_ddrphy_apb_wr_32b(0x51c56, 0x36c01c08);
dwc_ddrphy_apb_wr_32b(0x51c58, 0xfeaf0e5a);
dwc_ddrphy_apb_wr_32b(0x51c5a, 0x730cc541);
dwc_ddrphy_apb_wr_32b(0x51c5c, 0x274fc043);
dwc_ddrphy_apb_wr_32b(0x51c5e, 0xd8ff1401);
dwc_ddrphy_apb_wr_32b(0x51c60, 0x1c08724c);
dwc_ddrphy_apb_wr_32b(0x51c62, 0xc54136c0);
dwc_ddrphy_apb_wr_32b(0x51c64, 0x3f801c00);
dwc_ddrphy_apb_wr_32b(0x51c66, 0x100a0000);
dwc_ddrphy_apb_wr_32b(0x51c68, 0xfeaf0e3a);
dwc_ddrphy_apb_wr_32b(0x51c6a, 0xc00b746c);
dwc_ddrphy_apb_wr_32b(0x51c6c, 0x754cd980);
dwc_ddrphy_apb_wr_32b(0x51c6e, 0xd8ff7b0f);
dwc_ddrphy_apb_wr_32b(0x51c70, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x51c72, 0xe26c541);
dwc_ddrphy_apb_wr_32b(0x51c74, 0xc540feaf);
dwc_ddrphy_apb_wr_32b(0x51c76, 0xfe8f0b1e);
dwc_ddrphy_apb_wr_32b(0x51c78, 0x7104c004);
dwc_ddrphy_apb_wr_32b(0x51c7a, 0x700cf18a);
dwc_ddrphy_apb_wr_32b(0x51c7c, 0xfeaf0d3a);
dwc_ddrphy_apb_wr_32b(0x51c7e, 0x120041a1);
dwc_ddrphy_apb_wr_32b(0x51c80, 0xbf23083);
dwc_ddrphy_apb_wr_32b(0x51c82, 0xc643fe8f);
dwc_ddrphy_apb_wr_32b(0x51c84, 0xc641c642);
dwc_ddrphy_apb_wr_32b(0x51c86, 0xfeaf0dfe);
dwc_ddrphy_apb_wr_32b(0x51c88, 0x86ac640);
dwc_ddrphy_apb_wr_32b(0x51c8a, 0xd8fffeef);
dwc_ddrphy_apb_wr_32b(0x51c8c, 0xbd8e70ad);
dwc_ddrphy_apb_wr_32b(0x51c8e, 0x41a1d8ff);
dwc_ddrphy_apb_wr_32b(0x51c90, 0x726c754c);
dwc_ddrphy_apb_wr_32b(0x51c92, 0xc642c643);
dwc_ddrphy_apb_wr_32b(0x51c94, 0xde2c641);
dwc_ddrphy_apb_wr_32b(0x51c96, 0xc640feaf);
dwc_ddrphy_apb_wr_32b(0x51c98, 0x7f0fc005);
dwc_ddrphy_apb_wr_32b(0x51c9a, 0xff2f089e);
dwc_ddrphy_apb_wr_32b(0x51c9c, 0xca0b40e1);
dwc_ddrphy_apb_wr_32b(0x51c9e, 0x1281254f);
dwc_ddrphy_apb_wr_32b(0x51ca0, 0xc043714c);
dwc_ddrphy_apb_wr_32b(0x51ca2, 0x10802d41);
dwc_ddrphy_apb_wr_32b(0x51ca4, 0xd8ffc040);
dwc_ddrphy_apb_wr_32b(0x51ca6, 0xc742746c);
dwc_ddrphy_apb_wr_32b(0x51ca8, 0xfeaf0dba);
dwc_ddrphy_apb_wr_32b(0x51caa, 0x842c641);
dwc_ddrphy_apb_wr_32b(0x51cac, 0x40e1ff2f);
dwc_ddrphy_apb_wr_32b(0x51cae, 0x702cc008);
dwc_ddrphy_apb_wr_32b(0x51cb0, 0x7b0f754c);
dwc_ddrphy_apb_wr_32b(0x51cb2, 0xc643d8ff);
dwc_ddrphy_apb_wr_32b(0x51cb4, 0xc641c642);
dwc_ddrphy_apb_wr_32b(0x51cb6, 0xfeaf0d9e);
dwc_ddrphy_apb_wr_32b(0x51cb8, 0x79bbc640);
dwc_ddrphy_apb_wr_32b(0x51cba, 0xfe8f0bb6);
dwc_ddrphy_apb_wr_32b(0x51cbc, 0x30c11c0c);
dwc_ddrphy_apb_wr_32b(0x51cbe, 0xc641c642);
dwc_ddrphy_apb_wr_32b(0x51cc0, 0xfeaf0d8a);
dwc_ddrphy_apb_wr_32b(0x51cc2, 0xb9ac640);
dwc_ddrphy_apb_wr_32b(0x51cc4, 0xc643fe8f);
dwc_ddrphy_apb_wr_32b(0x51cc6, 0xc641c642);
dwc_ddrphy_apb_wr_32b(0x51cc8, 0xfeaf0d7a);
dwc_ddrphy_apb_wr_32b(0x51cca, 0xfbac640);
dwc_ddrphy_apb_wr_32b(0x51ccc, 0xd8fffeaf);
dwc_ddrphy_apb_wr_32b(0x51cce, 0xc642c643);
dwc_ddrphy_apb_wr_32b(0x51cd0, 0xc640c641);
dwc_ddrphy_apb_wr_32b(0x51cd2, 0x46cbf072);
dwc_ddrphy_apb_wr_32b(0x51cd4, 0xb2b20000);
dwc_ddrphy_apb_wr_32b(0x51cd6, 0xf00472ed);
dwc_ddrphy_apb_wr_32b(0x51cd8, 0x70cd70ed);
dwc_ddrphy_apb_wr_32b(0x51cda, 0x41c1d80f);
dwc_ddrphy_apb_wr_32b(0x51cdc, 0x43c142c1);
dwc_ddrphy_apb_wr_32b(0x51cde, 0xff2f0bca);
dwc_ddrphy_apb_wr_32b(0x51ce0, 0xc006c640);
dwc_ddrphy_apb_wr_32b(0x51ce2, 0xc6e790f);
dwc_ddrphy_apb_wr_32b(0x51ce4, 0x700cfeaf);
dwc_ddrphy_apb_wr_32b(0x51ce6, 0x30831200);
dwc_ddrphy_apb_wr_32b(0x51ce8, 0xfe8f0b22);
dwc_ddrphy_apb_wr_32b(0x51cea, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x51cec, 0xd32c541);
dwc_ddrphy_apb_wr_32b(0x51cee, 0xc540feaf);
dwc_ddrphy_apb_wr_32b(0x51cf0, 0x7a0f78d2);
dwc_ddrphy_apb_wr_32b(0x51cf2, 0x43dbc005);
dwc_ddrphy_apb_wr_32b(0x51cf4, 0x89a8000);
dwc_ddrphy_apb_wr_32b(0x51cf6, 0x31011300);
dwc_ddrphy_apb_wr_32b(0x51cf8, 0x40c17e0f);
dwc_ddrphy_apb_wr_32b(0x51cfa, 0xff6f09ce);
dwc_ddrphy_apb_wr_32b(0x51cfc, 0xf82db2c);
dwc_ddrphy_apb_wr_32b(0x51cfe, 0xd8fffeaf);
dwc_ddrphy_apb_wr_32b(0x51d00, 0xfeef0fd2);
dwc_ddrphy_apb_wr_32b(0x51d02, 0xca0b40c1);
dwc_ddrphy_apb_wr_32b(0x51d04, 0xc741702c);
dwc_ddrphy_apb_wr_32b(0x51d06, 0xc0434728);
dwc_ddrphy_apb_wr_32b(0x51d08, 0xd8ffbf8c);
dwc_ddrphy_apb_wr_32b(0x51d0a, 0x746cda15);
dwc_ddrphy_apb_wr_32b(0x51d0c, 0xcf2c642);
dwc_ddrphy_apb_wr_32b(0x51d0e, 0xc740feaf);
dwc_ddrphy_apb_wr_32b(0x51d10, 0xfeef0f76);
dwc_ddrphy_apb_wr_32b(0x51d12, 0xc00840c1);
dwc_ddrphy_apb_wr_32b(0x51d14, 0x754c702c);
dwc_ddrphy_apb_wr_32b(0x51d16, 0xd8ff7b0f);
dwc_ddrphy_apb_wr_32b(0x51d18, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x51d1a, 0xcd6c541);
dwc_ddrphy_apb_wr_32b(0x51d1c, 0xc540feaf);
dwc_ddrphy_apb_wr_32b(0x51d1e, 0xaee6f33);
dwc_ddrphy_apb_wr_32b(0x51d20, 0x1c0cfe8f);
dwc_ddrphy_apb_wr_32b(0x51d22, 0xc54230c1);
dwc_ddrphy_apb_wr_32b(0x51d24, 0xcc2c541);
dwc_ddrphy_apb_wr_32b(0x51d26, 0xc540feaf);
dwc_ddrphy_apb_wr_32b(0x51d28, 0xfe8f0ace);
dwc_ddrphy_apb_wr_32b(0x51d2a, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x51d2c, 0xcb2c541);
dwc_ddrphy_apb_wr_32b(0x51d2e, 0xc540feaf);
dwc_ddrphy_apb_wr_32b(0x51d30, 0xfeaf0eee);
dwc_ddrphy_apb_wr_32b(0x51d32, 0x1300d8ff);
dwc_ddrphy_apb_wr_32b(0x51d34, 0x702c3100);
dwc_ddrphy_apb_wr_32b(0x51d36, 0xc040734c);
dwc_ddrphy_apb_wr_32b(0x51d38, 0xdb2cd8ff);
dwc_ddrphy_apb_wr_32b(0x51d3a, 0xc642c543);
dwc_ddrphy_apb_wr_32b(0x51d3c, 0xfeaf0e7e);
dwc_ddrphy_apb_wr_32b(0x51d3e, 0x30c11c04);
dwc_ddrphy_apb_wr_32b(0x51d40, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x51d42, 0xc540c541);
dwc_ddrphy_apb_wr_32b(0x51d44, 0xd980d8ff);
dwc_ddrphy_apb_wr_32b(0x51d46, 0xc7e754c);
dwc_ddrphy_apb_wr_32b(0x51d48, 0x746cfeaf);
dwc_ddrphy_apb_wr_32b(0x51d4a, 0x1404c0ac);
dwc_ddrphy_apb_wr_32b(0x51d4c, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x51d4e, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x51d50, 0xc1a5b6c8);
dwc_ddrphy_apb_wr_32b(0x51d52, 0x16004708);
dwc_ddrphy_apb_wr_32b(0x51d54, 0x900e7100);
dwc_ddrphy_apb_wr_32b(0x51d56, 0xc040004c);
dwc_ddrphy_apb_wr_32b(0x51d58, 0xc0438f19);
dwc_ddrphy_apb_wr_32b(0x51d5a, 0x71001600);
dwc_ddrphy_apb_wr_32b(0x51d5c, 0x4e900e);
dwc_ddrphy_apb_wr_32b(0x51d5e, 0x8f10c041);
dwc_ddrphy_apb_wr_32b(0x51d60, 0xc003c042);
dwc_ddrphy_apb_wr_32b(0x51d62, 0x40c3e889);
dwc_ddrphy_apb_wr_32b(0x51d64, 0xffff0000);
dwc_ddrphy_apb_wr_32b(0x51d66, 0x42004100);
dwc_ddrphy_apb_wr_32b(0x51d68, 0xff2f0afa);
dwc_ddrphy_apb_wr_32b(0x51d6a, 0x9fa4300);
dwc_ddrphy_apb_wr_32b(0x51d6c, 0x8708fe8f);
dwc_ddrphy_apb_wr_32b(0x51d6e, 0x900346cb);
dwc_ddrphy_apb_wr_32b(0x51d70, 0x70ade064);
dwc_ddrphy_apb_wr_32b(0x51d72, 0x78c5781b);
dwc_ddrphy_apb_wr_32b(0x51d74, 0xffaf0fb2);
dwc_ddrphy_apb_wr_32b(0x51d76, 0x8729b0a0);
dwc_ddrphy_apb_wr_32b(0x51d78, 0xa00a36);
dwc_ddrphy_apb_wr_32b(0x51d7a, 0x43db710c);
dwc_ddrphy_apb_wr_32b(0x51d7c, 0xffff0000);
dwc_ddrphy_apb_wr_32b(0x51d7e, 0xfe8f0962);
dwc_ddrphy_apb_wr_32b(0x51d80, 0xfeaf0bda);
dwc_ddrphy_apb_wr_32b(0x51d82, 0xc100970e);
dwc_ddrphy_apb_wr_32b(0x51d84, 0xbeec201);
dwc_ddrphy_apb_wr_32b(0x51d86, 0x40e10060);
dwc_ddrphy_apb_wr_32b(0x51d88, 0xab6d80f);
dwc_ddrphy_apb_wr_32b(0x51d8a, 0xd90ffeef);
dwc_ddrphy_apb_wr_32b(0x51d8c, 0xa0e8729);
dwc_ddrphy_apb_wr_32b(0x51d8e, 0x710c00a0);
dwc_ddrphy_apb_wr_32b(0x51d90, 0x1ec0712c);
dwc_ddrphy_apb_wr_32b(0x51d92, 0x9f84);
dwc_ddrphy_apb_wr_32b(0x51d94, 0x1eccff00);
dwc_ddrphy_apb_wr_32b(0x51d96, 0x1ebe9044);
dwc_ddrphy_apb_wr_32b(0x51d98, 0xbaa9044);
dwc_ddrphy_apb_wr_32b(0x51d9a, 0x970afeaf);
dwc_ddrphy_apb_wr_32b(0x51d9c, 0x87018f58);
dwc_ddrphy_apb_wr_32b(0x51d9e, 0x600ad6);
dwc_ddrphy_apb_wr_32b(0x51da0, 0xc100712c);
dwc_ddrphy_apb_wr_32b(0x51da2, 0xbb2c201);
dwc_ddrphy_apb_wr_32b(0x51da4, 0x40e10060);
dwc_ddrphy_apb_wr_32b(0x51da6, 0xfe8f0982);
dwc_ddrphy_apb_wr_32b(0x51da8, 0xe808c003);
dwc_ddrphy_apb_wr_32b(0x51daa, 0xfc6c002);
dwc_ddrphy_apb_wr_32b(0x51dac, 0x2078feaf);
dwc_ddrphy_apb_wr_32b(0x51dae, 0xf0100100);
dwc_ddrphy_apb_wr_32b(0x51db0, 0x4263c002);
dwc_ddrphy_apb_wr_32b(0x51db2, 0x74144163);
dwc_ddrphy_apb_wr_32b(0x51db4, 0x40c3);
dwc_ddrphy_apb_wr_32b(0x51db6, 0x22cafffe);
dwc_ddrphy_apb_wr_32b(0x51db8, 0x20ca0001);
dwc_ddrphy_apb_wr_32b(0x51dba, 0xa5606c1);
dwc_ddrphy_apb_wr_32b(0x51dbc, 0x4363ff2f);
dwc_ddrphy_apb_wr_32b(0x51dbe, 0x2078c002);
dwc_ddrphy_apb_wr_32b(0x51dc0, 0xb8020100);
dwc_ddrphy_apb_wr_32b(0x51dc2, 0xc0447504);
dwc_ddrphy_apb_wr_32b(0x51dc4, 0x71001600);
dwc_ddrphy_apb_wr_32b(0x51dc6, 0x4c900e);
dwc_ddrphy_apb_wr_32b(0x51dc8, 0x1600c040);
dwc_ddrphy_apb_wr_32b(0x51dca, 0x900e7100);
dwc_ddrphy_apb_wr_32b(0x51dcc, 0x8729004e);
dwc_ddrphy_apb_wr_32b(0x51dce, 0x98ac041);
dwc_ddrphy_apb_wr_32b(0x51dd0, 0xc00400a0);
dwc_ddrphy_apb_wr_32b(0x51dd2, 0x70ad8708);
dwc_ddrphy_apb_wr_32b(0x51dd4, 0x78c5781b);
dwc_ddrphy_apb_wr_32b(0x51dd6, 0xffaf0eee);
dwc_ddrphy_apb_wr_32b(0x51dd8, 0x8aeb0a0);
dwc_ddrphy_apb_wr_32b(0x51dda, 0x970efe8f);
dwc_ddrphy_apb_wr_32b(0x51ddc, 0xfeaf0b22);
dwc_ddrphy_apb_wr_32b(0x51dde, 0xc1004528);
dwc_ddrphy_apb_wr_32b(0x51de0, 0xb36c201);
dwc_ddrphy_apb_wr_32b(0x51de2, 0x40e10060);
dwc_ddrphy_apb_wr_32b(0x51de4, 0x9fed80f);
dwc_ddrphy_apb_wr_32b(0x51de6, 0xd90ffeef);
dwc_ddrphy_apb_wr_32b(0x51de8, 0x9568729);
dwc_ddrphy_apb_wr_32b(0x51dea, 0xc00400a0);
dwc_ddrphy_apb_wr_32b(0x51dec, 0x9f841ec0);
dwc_ddrphy_apb_wr_32b(0x51dee, 0xff000000);
dwc_ddrphy_apb_wr_32b(0x51df0, 0x93441ecc);
dwc_ddrphy_apb_wr_32b(0x51df2, 0x93441ebe);
dwc_ddrphy_apb_wr_32b(0x51df4, 0x712c8705);
dwc_ddrphy_apb_wr_32b(0x51df6, 0xaee7104);
dwc_ddrphy_apb_wr_32b(0x51df8, 0x7810feaf);
dwc_ddrphy_apb_wr_32b(0x51dfa, 0xc201c100);
dwc_ddrphy_apb_wr_32b(0x51dfc, 0x600afe);
dwc_ddrphy_apb_wr_32b(0x51dfe, 0xc00340e1);
dwc_ddrphy_apb_wr_32b(0x51e00, 0xc002e806);
dwc_ddrphy_apb_wr_32b(0x51e02, 0xfeaf0f16);
dwc_ddrphy_apb_wr_32b(0x51e04, 0x1002079);
dwc_ddrphy_apb_wr_32b(0x51e06, 0x87038f58);
dwc_ddrphy_apb_wr_32b(0x51e08, 0x600a02);
dwc_ddrphy_apb_wr_32b(0x51e0a, 0xc0a5712c);
dwc_ddrphy_apb_wr_32b(0x51e0c, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x51e0e, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x51e10, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x51e12, 0xc1a5b6c8);
dwc_ddrphy_apb_wr_32b(0x51e14, 0x16004708);
dwc_ddrphy_apb_wr_32b(0x51e16, 0x900e7100);
dwc_ddrphy_apb_wr_32b(0x51e18, 0xc040004c);
dwc_ddrphy_apb_wr_32b(0x51e1a, 0xc0438f19);
dwc_ddrphy_apb_wr_32b(0x51e1c, 0x71001600);
dwc_ddrphy_apb_wr_32b(0x51e1e, 0x4e900e);
dwc_ddrphy_apb_wr_32b(0x51e20, 0x8f10c041);
dwc_ddrphy_apb_wr_32b(0x51e22, 0xc003c042);
dwc_ddrphy_apb_wr_32b(0x51e24, 0x40c3e889);
dwc_ddrphy_apb_wr_32b(0x51e26, 0xffff0000);
dwc_ddrphy_apb_wr_32b(0x51e28, 0x42004100);
dwc_ddrphy_apb_wr_32b(0x51e2a, 0xff2f0976);
dwc_ddrphy_apb_wr_32b(0x51e2c, 0x8764300);
dwc_ddrphy_apb_wr_32b(0x51e2e, 0xc102fe8f);
dwc_ddrphy_apb_wr_32b(0x51e30, 0x21798708);
dwc_ddrphy_apb_wr_32b(0x51e32, 0xa620101);
dwc_ddrphy_apb_wr_32b(0x51e34, 0x4338ff2f);
dwc_ddrphy_apb_wr_32b(0x51e36, 0x8ba8729);
dwc_ddrphy_apb_wr_32b(0x51e38, 0x730c00a0);
dwc_ddrphy_apb_wr_32b(0x51e3a, 0x900345cb);
dwc_ddrphy_apb_wr_32b(0x51e3c, 0x46cbe174);
dwc_ddrphy_apb_wr_32b(0x51e3e, 0xffff0000);
dwc_ddrphy_apb_wr_32b(0x51e40, 0x10051d00);
dwc_ddrphy_apb_wr_32b(0x51e42, 0x10051d02);
dwc_ddrphy_apb_wr_32b(0x51e44, 0x939c1d58);
dwc_ddrphy_apb_wr_32b(0x51e46, 0x905d1d5e);
dwc_ddrphy_apb_wr_32b(0x51e48, 0x905d1d57);
dwc_ddrphy_apb_wr_32b(0x51e4a, 0xa46970e);
dwc_ddrphy_apb_wr_32b(0x51e4c, 0x712cfeaf);
dwc_ddrphy_apb_wr_32b(0x51e4e, 0xc201c100);
dwc_ddrphy_apb_wr_32b(0x51e50, 0x600a56);
dwc_ddrphy_apb_wr_32b(0x51e52, 0x82a40e1);
dwc_ddrphy_apb_wr_32b(0x51e54, 0x970afe8f);
dwc_ddrphy_apb_wr_32b(0x51e56, 0xfeaf0a2e);
dwc_ddrphy_apb_wr_32b(0x51e58, 0x8f58712c);
dwc_ddrphy_apb_wr_32b(0x51e5a, 0x95e8702);
dwc_ddrphy_apb_wr_32b(0x51e5c, 0x712c0060);
dwc_ddrphy_apb_wr_32b(0x51e5e, 0xc201c100);
dwc_ddrphy_apb_wr_32b(0x51e60, 0x600a36);
dwc_ddrphy_apb_wr_32b(0x51e62, 0x80a40e1);
dwc_ddrphy_apb_wr_32b(0x51e64, 0xc003fe8f);
dwc_ddrphy_apb_wr_32b(0x51e66, 0xe4ee805);
dwc_ddrphy_apb_wr_32b(0x51e68, 0x4063feaf);
dwc_ddrphy_apb_wr_32b(0x51e6a, 0xc002f00f);
dwc_ddrphy_apb_wr_32b(0x51e6c, 0x42c3);
dwc_ddrphy_apb_wr_32b(0x51e6e, 0x41c1fffe);
dwc_ddrphy_apb_wr_32b(0x51e70, 0x40c17414);
dwc_ddrphy_apb_wr_32b(0x51e72, 0x8120ca);
dwc_ddrphy_apb_wr_32b(0x51e74, 0x38122ca);
dwc_ddrphy_apb_wr_32b(0x51e76, 0xff2f08de);
dwc_ddrphy_apb_wr_32b(0x51e78, 0x2b4043c1);
dwc_ddrphy_apb_wr_32b(0x51e7a, 0xe0073080);
dwc_ddrphy_apb_wr_32b(0x51e7c, 0x1600c040);
dwc_ddrphy_apb_wr_32b(0x51e7e, 0x900e7100);
dwc_ddrphy_apb_wr_32b(0x51e80, 0xc044004c);
dwc_ddrphy_apb_wr_32b(0x51e82, 0x71001600);
dwc_ddrphy_apb_wr_32b(0x51e84, 0x4e900e);
dwc_ddrphy_apb_wr_32b(0x51e86, 0xc0418729);
dwc_ddrphy_apb_wr_32b(0x51e88, 0xa00816);
dwc_ddrphy_apb_wr_32b(0x51e8a, 0x8708c000);
dwc_ddrphy_apb_wr_32b(0x51e8c, 0xff2f09ae);
dwc_ddrphy_apb_wr_32b(0x51e8e, 0x712c4163);
dwc_ddrphy_apb_wr_32b(0x51e90, 0x10051d00);
dwc_ddrphy_apb_wr_32b(0x51e92, 0x10051d02);
dwc_ddrphy_apb_wr_32b(0x51e94, 0x939c1d58);
dwc_ddrphy_apb_wr_32b(0x51e96, 0x905c1d5e);
dwc_ddrphy_apb_wr_32b(0x51e98, 0x905c1d57);
dwc_ddrphy_apb_wr_32b(0x51e9a, 0x9a6970e);
dwc_ddrphy_apb_wr_32b(0x51e9c, 0x4628feaf);
dwc_ddrphy_apb_wr_32b(0x51e9e, 0xc201c104);
dwc_ddrphy_apb_wr_32b(0x51ea0, 0x6009b6);
dwc_ddrphy_apb_wr_32b(0x51ea2, 0xd80f40e1);
dwc_ddrphy_apb_wr_32b(0x51ea4, 0xfeef087e);
dwc_ddrphy_apb_wr_32b(0x51ea6, 0x8729d90f);
dwc_ddrphy_apb_wr_32b(0x51ea8, 0x600fd6);
dwc_ddrphy_apb_wr_32b(0x51eaa, 0xd8ffc000);
dwc_ddrphy_apb_wr_32b(0x51eac, 0x1d58b808);
dwc_ddrphy_apb_wr_32b(0x51eae, 0x1d5e901c);
dwc_ddrphy_apb_wr_32b(0x51eb0, 0x1d57939c);
dwc_ddrphy_apb_wr_32b(0x51eb2, 0x8705939c);
dwc_ddrphy_apb_wr_32b(0x51eb4, 0x7104712c);
dwc_ddrphy_apb_wr_32b(0x51eb6, 0xfeaf096e);
dwc_ddrphy_apb_wr_32b(0x51eb8, 0xc1047810);
dwc_ddrphy_apb_wr_32b(0x51eba, 0x982c201);
dwc_ddrphy_apb_wr_32b(0x51ebc, 0x40e10060);
dwc_ddrphy_apb_wr_32b(0x51ebe, 0xe807c003);
dwc_ddrphy_apb_wr_32b(0x51ec0, 0xd9ac002);
dwc_ddrphy_apb_wr_32b(0x51ec2, 0x2078feaf);
dwc_ddrphy_apb_wr_32b(0x51ec4, 0x8f580100);
dwc_ddrphy_apb_wr_32b(0x51ec6, 0x8868703);
dwc_ddrphy_apb_wr_32b(0x51ec8, 0x712c0060);
dwc_ddrphy_apb_wr_32b(0x51eca, 0x1404c0a5);
dwc_ddrphy_apb_wr_32b(0x51ecc, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x51ece, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x51ed0, 0x2482b6c8);
dwc_ddrphy_apb_wr_32b(0x51ed2, 0xc1433903);
dwc_ddrphy_apb_wr_32b(0x51ed4, 0xfeef085e);
dwc_ddrphy_apb_wr_32b(0x51ed6, 0xc041712c);
dwc_ddrphy_apb_wr_32b(0x51ed8, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x51eda, 0x48000);
dwc_ddrphy_apb_wr_32b(0x51edc, 0xdab4d9ff);
dwc_ddrphy_apb_wr_32b(0x51ede, 0xf9ac049);
dwc_ddrphy_apb_wr_32b(0x51ee0, 0xc08cff6f);
dwc_ddrphy_apb_wr_32b(0x51ee2, 0xb808d821);
dwc_ddrphy_apb_wr_32b(0x51ee4, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x51ee6, 0xe0049003);
dwc_ddrphy_apb_wr_32b(0x51ee8, 0x1e00700c);
dwc_ddrphy_apb_wr_32b(0x51eea, 0x90037004);
dwc_ddrphy_apb_wr_32b(0x51eec, 0xc003fec4);
dwc_ddrphy_apb_wr_32b(0x51eee, 0x207971cd);
dwc_ddrphy_apb_wr_32b(0x51ef0, 0x49180001);
dwc_ddrphy_apb_wr_32b(0x51ef2, 0x6913c048);
dwc_ddrphy_apb_wr_32b(0x51ef4, 0xca0bc046);
dwc_ddrphy_apb_wr_32b(0x51ef6, 0xc108c206);
dwc_ddrphy_apb_wr_32b(0x51ef8, 0x650a1b);
dwc_ddrphy_apb_wr_32b(0x51efa, 0x2412a40);
dwc_ddrphy_apb_wr_32b(0x51efc, 0x10832e00);
dwc_ddrphy_apb_wr_32b(0x51efe, 0xf812105);
dwc_ddrphy_apb_wr_32b(0x51f00, 0xe0c49003);
dwc_ddrphy_apb_wr_32b(0x51f02, 0x7144b160);
dwc_ddrphy_apb_wr_32b(0x51f04, 0xd907f1f3);
dwc_ddrphy_apb_wr_32b(0x51f06, 0x43db7916);
dwc_ddrphy_apb_wr_32b(0x51f08, 0x9948000);
dwc_ddrphy_apb_wr_32b(0x51f0a, 0xe698c14a);
dwc_ddrphy_apb_wr_32b(0x51f0c, 0x2d01ae);
dwc_ddrphy_apb_wr_32b(0x51f0e, 0xc00170ed);
dwc_ddrphy_apb_wr_32b(0x51f10, 0x781bc109);
dwc_ddrphy_apb_wr_32b(0x51f12, 0x2056b915);
dwc_ddrphy_apb_wr_32b(0x51f14, 0x782508c0);
dwc_ddrphy_apb_wr_32b(0x51f16, 0x900341c3);
dwc_ddrphy_apb_wr_32b(0x51f18, 0x7825fe00);
dwc_ddrphy_apb_wr_32b(0x51f1a, 0xd821b0c0);
dwc_ddrphy_apb_wr_32b(0x51f1c, 0x1e00b808);
dwc_ddrphy_apb_wr_32b(0x51f1e, 0x90037004);
dwc_ddrphy_apb_wr_32b(0x51f20, 0xc003e004);
dwc_ddrphy_apb_wr_32b(0x51f22, 0xc812154);
dwc_ddrphy_apb_wr_32b(0x51f24, 0x40c37014);
dwc_ddrphy_apb_wr_32b(0x51f26, 0xf0649003);
dwc_ddrphy_apb_wr_32b(0x51f28, 0xc4a711c);
dwc_ddrphy_apb_wr_32b(0x51f2a, 0xb1e0ffaf);
dwc_ddrphy_apb_wr_32b(0x51f2c, 0xff8f0c42);
dwc_ddrphy_apb_wr_32b(0x51f2e, 0xf6ad80f);
dwc_ddrphy_apb_wr_32b(0x51f30, 0xd90ffeaf);
dwc_ddrphy_apb_wr_32b(0x51f32, 0xec2730c);
dwc_ddrphy_apb_wr_32b(0x51f34, 0x218a0060);
dwc_ddrphy_apb_wr_32b(0x51f36, 0xc00a0fc7);
dwc_ddrphy_apb_wr_32b(0x51f38, 0x900345cb);
dwc_ddrphy_apb_wr_32b(0x51f3a, 0x712ce024);
dwc_ddrphy_apb_wr_32b(0x51f3c, 0x710cb500);
dwc_ddrphy_apb_wr_32b(0x51f3e, 0x208ac047);
dwc_ddrphy_apb_wr_32b(0x51f40, 0x1d0c03c4);
dwc_ddrphy_apb_wr_32b(0x51f42, 0x1dfe1045);
dwc_ddrphy_apb_wr_32b(0x51f44, 0x8529004);
dwc_ddrphy_apb_wr_32b(0x51f46, 0xd840feaf);
dwc_ddrphy_apb_wr_32b(0x51f48, 0x4208a);
dwc_ddrphy_apb_wr_32b(0x51f4a, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x51f4c, 0xe0049003);
dwc_ddrphy_apb_wr_32b(0x51f4e, 0xfe4f0e32);
dwc_ddrphy_apb_wr_32b(0x51f50, 0x83ad807);
dwc_ddrphy_apb_wr_32b(0x51f52, 0x712cfeaf);
dwc_ddrphy_apb_wr_32b(0x51f54, 0xfc7208a);
dwc_ddrphy_apb_wr_32b(0x51f56, 0x101c1da8);
dwc_ddrphy_apb_wr_32b(0x51f58, 0xf16d80f);
dwc_ddrphy_apb_wr_32b(0x51f5a, 0xd90ffeaf);
dwc_ddrphy_apb_wr_32b(0x51f5c, 0x822730c);
dwc_ddrphy_apb_wr_32b(0x51f5e, 0x712cfeaf);
dwc_ddrphy_apb_wr_32b(0x51f60, 0xd90fd80f);
dwc_ddrphy_apb_wr_32b(0x51f62, 0xfeaf0f02);
dwc_ddrphy_apb_wr_32b(0x51f64, 0x13dc1da8);
dwc_ddrphy_apb_wr_32b(0x51f66, 0x712c700c);
dwc_ddrphy_apb_wr_32b(0x51f68, 0x1fc51d00);
dwc_ddrphy_apb_wr_32b(0x51f6a, 0x1fc51d0c);
dwc_ddrphy_apb_wr_32b(0x51f6c, 0xfeaf0802);
dwc_ddrphy_apb_wr_32b(0x51f6e, 0x93c41dfe);
dwc_ddrphy_apb_wr_32b(0x51f70, 0x300f1300);
dwc_ddrphy_apb_wr_32b(0x51f72, 0x8db406f);
dwc_ddrphy_apb_wr_32b(0x51f74, 0x264a03e2);
dwc_ddrphy_apb_wr_32b(0x51f76, 0x140c3040);
dwc_ddrphy_apb_wr_32b(0x51f78, 0xc506300b);
dwc_ddrphy_apb_wr_32b(0x51f7a, 0xdc7c008);
dwc_ddrphy_apb_wr_32b(0x51f7c, 0x275a1005);
dwc_ddrphy_apb_wr_32b(0x51f7e, 0xc18c1480);
dwc_ddrphy_apb_wr_32b(0x51f80, 0x23c074b5);
dwc_ddrphy_apb_wr_32b(0x51f82, 0xc0451061);
dwc_ddrphy_apb_wr_32b(0x51f84, 0x78b46038);
dwc_ddrphy_apb_wr_32b(0x51f86, 0x9000c044);
dwc_ddrphy_apb_wr_32b(0x51f88, 0x306126ca);
dwc_ddrphy_apb_wr_32b(0x51f8a, 0x8002208c);
dwc_ddrphy_apb_wr_32b(0x51f8c, 0x25009e);
dwc_ddrphy_apb_wr_32b(0x51f8e, 0x13402f40);
dwc_ddrphy_apb_wr_32b(0x51f90, 0xf802005);
dwc_ddrphy_apb_wr_32b(0x51f92, 0x649002);
dwc_ddrphy_apb_wr_32b(0x51f94, 0xc302c042);
dwc_ddrphy_apb_wr_32b(0x51f96, 0x12402d40);
dwc_ddrphy_apb_wr_32b(0x51f98, 0x7b0579af);
dwc_ddrphy_apb_wr_32b(0x51f9a, 0xc2019300);
dwc_ddrphy_apb_wr_32b(0x51f9c, 0x78efc04b);
dwc_ddrphy_apb_wr_32b(0x51f9e, 0x200f8a);
dwc_ddrphy_apb_wr_32b(0x51fa0, 0x20787a4f);
dwc_ddrphy_apb_wr_32b(0x51fa2, 0xc00b0001);
dwc_ddrphy_apb_wr_32b(0x51fa4, 0x1780240a);
dwc_ddrphy_apb_wr_32b(0x51fa6, 0x2079);
dwc_ddrphy_apb_wr_32b(0x51fa8, 0x807e2005);
dwc_ddrphy_apb_wr_32b(0x51faa, 0x24cac007);
dwc_ddrphy_apb_wr_32b(0x51fac, 0x20ca1021);
dwc_ddrphy_apb_wr_32b(0x51fae, 0x70950021);
dwc_ddrphy_apb_wr_32b(0x51fb0, 0x26cac047);
dwc_ddrphy_apb_wr_32b(0x51fb2, 0xf2293021);
dwc_ddrphy_apb_wr_32b(0x51fb4, 0x1080254f);
dwc_ddrphy_apb_wr_32b(0x51fb6, 0x1f1082b);
dwc_ddrphy_apb_wr_32b(0x51fb8, 0x2c7202f);
dwc_ddrphy_apb_wr_32b(0x51fba, 0x2079);
dwc_ddrphy_apb_wr_32b(0x51fbc, 0xd31b802);
dwc_ddrphy_apb_wr_32b(0x51fbe, 0xc18c1024);
dwc_ddrphy_apb_wr_32b(0x51fc0, 0x2840c305);
dwc_ddrphy_apb_wr_32b(0x51fc2, 0x633b0242);
dwc_ddrphy_apb_wr_32b(0x51fc4, 0x7b14c102);
dwc_ddrphy_apb_wr_32b(0x51fc6, 0x79457104);
dwc_ddrphy_apb_wr_32b(0x51fc8, 0xb3209120);
dwc_ddrphy_apb_wr_32b(0x51fca, 0xd23f1f3);
dwc_ddrphy_apb_wr_32b(0x51fcc, 0x93201211);
dwc_ddrphy_apb_wr_32b(0x51fce, 0xb020c004);
dwc_ddrphy_apb_wr_32b(0x51fd0, 0x33c02314);
dwc_ddrphy_apb_wr_32b(0x51fd2, 0xf009a8c9);
dwc_ddrphy_apb_wr_32b(0x51fd4, 0x11f10d0b);
dwc_ddrphy_apb_wr_32b(0x51fd6, 0x33c02314);
dwc_ddrphy_apb_wr_32b(0x51fd8, 0x260aa8c8);
dwc_ddrphy_apb_wr_32b(0x51fda, 0x71a53300);
dwc_ddrphy_apb_wr_32b(0x51fdc, 0x71e5f19e);
dwc_ddrphy_apb_wr_32b(0x51fde, 0xc007f194);
dwc_ddrphy_apb_wr_32b(0x51fe0, 0x701471c5);
dwc_ddrphy_apb_wr_32b(0x51fe2, 0x1300f329);
dwc_ddrphy_apb_wr_32b(0x51fe4, 0x406f300f);
dwc_ddrphy_apb_wr_32b(0x51fe6, 0x3c208a1);
dwc_ddrphy_apb_wr_32b(0x51fe8, 0xc008c606);
dwc_ddrphy_apb_wr_32b(0x51fea, 0x10050e95);
dwc_ddrphy_apb_wr_32b(0x51fec, 0xc04478ef);
dwc_ddrphy_apb_wr_32b(0x51fee, 0xc04278cf);
dwc_ddrphy_apb_wr_32b(0x51ff0, 0xc102c001);
dwc_ddrphy_apb_wr_32b(0x51ff2, 0xc045780f);
dwc_ddrphy_apb_wr_32b(0x51ff4, 0xedec004);
dwc_ddrphy_apb_wr_32b(0x51ff6, 0xc2050020);
dwc_ddrphy_apb_wr_32b(0x51ff8, 0x275ae83a);
dwc_ddrphy_apb_wr_32b(0x51ffa, 0xc58c1480);
dwc_ddrphy_apb_wr_32b(0x51ffc, 0x70c11600);
dwc_ddrphy_apb_wr_32b(0x51ffe, 0x18000);
dwc_ddrphy_apb_wr_32b(0x52000, 0x91f651d);
dwc_ddrphy_apb_wr_32b(0x52002, 0x25f40032);
dwc_ddrphy_apb_wr_32b(0x52004, 0x20bc1380);
dwc_ddrphy_apb_wr_32b(0x52006, 0x41c30002);
dwc_ddrphy_apb_wr_32b(0x52008, 0x200ba);
dwc_ddrphy_apb_wr_32b(0x5200a, 0x8d242e1);
dwc_ddrphy_apb_wr_32b(0x5200c, 0x43c1fe2f);
dwc_ddrphy_apb_wr_32b(0x5200e, 0x208cf012);
dwc_ddrphy_apb_wr_32b(0x52010, 0xf7908002);
dwc_ddrphy_apb_wr_32b(0x52012, 0x740cc201);
dwc_ddrphy_apb_wr_32b(0x52014, 0xb941c3);
dwc_ddrphy_apb_wr_32b(0x52016, 0x43e10003);
dwc_ddrphy_apb_wr_32b(0x52018, 0xfeaf0ea6);
dwc_ddrphy_apb_wr_32b(0x5201a, 0xc004c640);
dwc_ddrphy_apb_wr_32b(0x5201c, 0xc5ac102);
dwc_ddrphy_apb_wr_32b(0x5201e, 0xc2050060);
dwc_ddrphy_apb_wr_32b(0x52020, 0x2f40c001);
dwc_ddrphy_apb_wr_32b(0x52022, 0x25f41343);
dwc_ddrphy_apb_wr_32b(0x52024, 0x781b1381);
dwc_ddrphy_apb_wr_32b(0x52026, 0xd022055);
dwc_ddrphy_apb_wr_32b(0x52028, 0x2e407a65);
dwc_ddrphy_apb_wr_32b(0x5202a, 0x78451240);
dwc_ddrphy_apb_wr_32b(0x5202c, 0xb89cb891);
dwc_ddrphy_apb_wr_32b(0x5202e, 0xfc12189);
dwc_ddrphy_apb_wr_32b(0x52030, 0xb020b89f);
dwc_ddrphy_apb_wr_32b(0x52032, 0xf1b771c5);
dwc_ddrphy_apb_wr_32b(0x52034, 0xf1b171e5);
dwc_ddrphy_apb_wr_32b(0x52036, 0xe83ec003);
dwc_ddrphy_apb_wr_32b(0x52038, 0xfecf0b0e);
dwc_ddrphy_apb_wr_32b(0x5203a, 0x300e1300);
dwc_ddrphy_apb_wr_32b(0x5203c, 0x406f4308);
dwc_ddrphy_apb_wr_32b(0x5203e, 0x3a2086d);
dwc_ddrphy_apb_wr_32b(0x52040, 0x33802314);
dwc_ddrphy_apb_wr_32b(0x52042, 0x88298848);
dwc_ddrphy_apb_wr_32b(0x52044, 0x4953dd09);
dwc_ddrphy_apb_wr_32b(0x52046, 0x71504a30);
dwc_ddrphy_apb_wr_32b(0x52048, 0xcd20ca);
dwc_ddrphy_apb_wr_32b(0x5204a, 0x271a7f0f);
dwc_ddrphy_apb_wr_32b(0x5204c, 0xdb0812cf);
dwc_ddrphy_apb_wr_32b(0x5204e, 0x12d23ca);
dwc_ddrphy_apb_wr_32b(0x52050, 0x122d25ca);
dwc_ddrphy_apb_wr_32b(0x52052, 0x180f2f44);
dwc_ddrphy_apb_wr_32b(0x52054, 0x3450b3d);
dwc_ddrphy_apb_wr_32b(0x52056, 0x78cfc201);
dwc_ddrphy_apb_wr_32b(0x52058, 0xe16796f);
dwc_ddrphy_apb_wr_32b(0x5205a, 0x7a4f0020);
dwc_ddrphy_apb_wr_32b(0x5205c, 0xc001e814);
dwc_ddrphy_apb_wr_32b(0x5205e, 0x13412e40);
dwc_ddrphy_apb_wr_32b(0x52060, 0x2055781b);
dwc_ddrphy_apb_wr_32b(0x52062, 0x79050d00);
dwc_ddrphy_apb_wr_32b(0x52064, 0x2402b40);
dwc_ddrphy_apb_wr_32b(0x52066, 0xb8917825);
dwc_ddrphy_apb_wr_32b(0x52068, 0xb89fb89c);
dwc_ddrphy_apb_wr_32b(0x5206a, 0x79f09040);
dwc_ddrphy_apb_wr_32b(0x5206c, 0x21896159);
dwc_ddrphy_apb_wr_32b(0x5206e, 0xb0200fc1);
dwc_ddrphy_apb_wr_32b(0x52070, 0xf1e47164);
dwc_ddrphy_apb_wr_32b(0x52072, 0xf1cb71c5);
dwc_ddrphy_apb_wr_32b(0x52074, 0x39032480);
dwc_ddrphy_apb_wr_32b(0x52076, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x52078, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x5207a, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x5207c, 0x2482b6c8);
dwc_ddrphy_apb_wr_32b(0x5207e, 0xc045320b);
dwc_ddrphy_apb_wr_32b(0x52080, 0xc246700c);
dwc_ddrphy_apb_wr_32b(0x52082, 0xfeef0e92);
dwc_ddrphy_apb_wr_32b(0x52084, 0x700c4528);
dwc_ddrphy_apb_wr_32b(0x52086, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x52088, 0xe0049003);
dwc_ddrphy_apb_wr_32b(0x5208a, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x5208c, 0xff689003);
dwc_ddrphy_apb_wr_32b(0x5208e, 0x7014c006);
dwc_ddrphy_apb_wr_32b(0x52090, 0xc04a750c);
dwc_ddrphy_apb_wr_32b(0x52092, 0xc005f20d);
dwc_ddrphy_apb_wr_32b(0x52094, 0x7e0f712c);
dwc_ddrphy_apb_wr_32b(0x52096, 0xa00a1e);
dwc_ddrphy_apb_wr_32b(0x52098, 0x40c140c1);
dwc_ddrphy_apb_wr_32b(0x5209a, 0xfeaf0b96);
dwc_ddrphy_apb_wr_32b(0x5209c, 0x700c712c);
dwc_ddrphy_apb_wr_32b(0x5209e, 0xca0dc04a);
dwc_ddrphy_apb_wr_32b(0x520a0, 0x208c714c);
dwc_ddrphy_apb_wr_32b(0x520a2, 0xf40f8fc3);
dwc_ddrphy_apb_wr_32b(0x520a4, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x520a6, 0x8000);
dwc_ddrphy_apb_wr_32b(0x520a8, 0xd8ffb8e5);
dwc_ddrphy_apb_wr_32b(0x520aa, 0x1600f207);
dwc_ddrphy_apb_wr_32b(0x520ac, 0x80007000);
dwc_ddrphy_apb_wr_32b(0x520ae, 0x1a0d0988);
dwc_ddrphy_apb_wr_32b(0x520b0, 0xc1053002);
dwc_ddrphy_apb_wr_32b(0x520b2, 0x25797a38);
dwc_ddrphy_apb_wr_32b(0x520b4, 0x72241001);
dwc_ddrphy_apb_wr_32b(0x520b6, 0x790fc14d);
dwc_ddrphy_apb_wr_32b(0x520b8, 0x70001600);
dwc_ddrphy_apb_wr_32b(0x520ba, 0x9888000);
dwc_ddrphy_apb_wr_32b(0x520bc, 0x2039c24c);
dwc_ddrphy_apb_wr_32b(0x520be, 0xc1060040);
dwc_ddrphy_apb_wr_32b(0x520c0, 0x12179);
dwc_ddrphy_apb_wr_32b(0x520c2, 0xc0427825);
dwc_ddrphy_apb_wr_32b(0x520c4, 0xc00dc102);
dwc_ddrphy_apb_wr_32b(0x520c6, 0x4247110);
dwc_ddrphy_apb_wr_32b(0x520c8, 0xc0020006);
dwc_ddrphy_apb_wr_32b(0x520ca, 0x7214c50a);
dwc_ddrphy_apb_wr_32b(0x520cc, 0x106125ca);
dwc_ddrphy_apb_wr_32b(0x520ce, 0xc04b6d0b);
dwc_ddrphy_apb_wr_32b(0x520d0, 0x2079c002);
dwc_ddrphy_apb_wr_32b(0x520d2, 0xc0480080);
dwc_ddrphy_apb_wr_32b(0x520d4, 0x81dc00b);
dwc_ddrphy_apb_wr_32b(0x520d6, 0xc0080114);
dwc_ddrphy_apb_wr_32b(0x520d8, 0x1600e88a);
dwc_ddrphy_apb_wr_32b(0x520da, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x520dc, 0x80d03f9);
dwc_ddrphy_apb_wr_32b(0x520de, 0xda4001be);
dwc_ddrphy_apb_wr_32b(0x520e0, 0xfe4f0af6);
dwc_ddrphy_apb_wr_32b(0x520e2, 0x41a1c00c);
dwc_ddrphy_apb_wr_32b(0x520e4, 0xbfa780f);
dwc_ddrphy_apb_wr_32b(0x520e6, 0xc04effaf);
dwc_ddrphy_apb_wr_32b(0x520e8, 0xe80dc006);
dwc_ddrphy_apb_wr_32b(0x520ea, 0x817c002);
dwc_ddrphy_apb_wr_32b(0x520ec, 0x40c30051);
dwc_ddrphy_apb_wr_32b(0x520ee, 0xffff0000);
dwc_ddrphy_apb_wr_32b(0x520f0, 0x42004100);
dwc_ddrphy_apb_wr_32b(0x520f2, 0xfeef0be6);
dwc_ddrphy_apb_wr_32b(0x520f4, 0xc0054300);
dwc_ddrphy_apb_wr_32b(0x520f6, 0xc0027b0f);
dwc_ddrphy_apb_wr_32b(0x520f8, 0xc002e809);
dwc_ddrphy_apb_wr_32b(0x520fa, 0x812078);
dwc_ddrphy_apb_wr_32b(0x520fc, 0xffef0ba6);
dwc_ddrphy_apb_wr_32b(0x520fe, 0x36d4060);
dwc_ddrphy_apb_wr_32b(0x52100, 0x40600000);
dwc_ddrphy_apb_wr_32b(0x52102, 0xfeaf0c02);
dwc_ddrphy_apb_wr_32b(0x52104, 0xc043712c);
dwc_ddrphy_apb_wr_32b(0x52106, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x52108, 0x8000);
dwc_ddrphy_apb_wr_32b(0x5210a, 0x708e1600);
dwc_ddrphy_apb_wr_32b(0x5210c, 0x48000);
dwc_ddrphy_apb_wr_32b(0x5210e, 0xb8c1712c);
dwc_ddrphy_apb_wr_32b(0x52110, 0xc3034260);
dwc_ddrphy_apb_wr_32b(0x52112, 0xc0477918);
dwc_ddrphy_apb_wr_32b(0x52114, 0xd80ac141);
dwc_ddrphy_apb_wr_32b(0x52116, 0xa941c3);
dwc_ddrphy_apb_wr_32b(0x52118, 0xca60004);
dwc_ddrphy_apb_wr_32b(0x5211a, 0xc640feaf);
dwc_ddrphy_apb_wr_32b(0x5211c, 0x3dc02456);
dwc_ddrphy_apb_wr_32b(0x5211e, 0xb1a702c);
dwc_ddrphy_apb_wr_32b(0x52120, 0xda5aff6f);
dwc_ddrphy_apb_wr_32b(0x52122, 0x3f802400);
dwc_ddrphy_apb_wr_32b(0x52124, 0x1040000);
dwc_ddrphy_apb_wr_32b(0x52126, 0xff6f0b0a);
dwc_ddrphy_apb_wr_32b(0x52128, 0xa36dab4);
dwc_ddrphy_apb_wr_32b(0x5212a, 0x208aff2f);
dwc_ddrphy_apb_wr_32b(0x5212c, 0x9120b04);
dwc_ddrphy_apb_wr_32b(0x5212e, 0xc044ff2f);
dwc_ddrphy_apb_wr_32b(0x52130, 0x1e00702c);
dwc_ddrphy_apb_wr_32b(0x52132, 0x90037044);
dwc_ddrphy_apb_wr_32b(0x52134, 0x90ffec4);
dwc_ddrphy_apb_wr_32b(0x52136, 0x714c0235);
dwc_ddrphy_apb_wr_32b(0x52138, 0xfe4f0a1e);
dwc_ddrphy_apb_wr_32b(0x5213a, 0xc007f1fb);
dwc_ddrphy_apb_wr_32b(0x5213c, 0xb80ddd07);
dwc_ddrphy_apb_wr_32b(0x5213e, 0x1e00b887);
dwc_ddrphy_apb_wr_32b(0x52140, 0x90037004);
dwc_ddrphy_apb_wr_32b(0x52142, 0x2e40e004);
dwc_ddrphy_apb_wr_32b(0x52144, 0x20051540);
dwc_ddrphy_apb_wr_32b(0x52146, 0x90030f81);
dwc_ddrphy_apb_wr_32b(0x52148, 0x2005fe86);
dwc_ddrphy_apb_wr_32b(0x5214a, 0x90020f80);
dwc_ddrphy_apb_wr_32b(0x5214c, 0x90000086);
dwc_ddrphy_apb_wr_32b(0x5214e, 0xb100b8a0);
dwc_ddrphy_apb_wr_32b(0x52150, 0x8deca0b);
dwc_ddrphy_apb_wr_32b(0x52152, 0x7d16feef);
dwc_ddrphy_apb_wr_32b(0x52154, 0x8f07208c);
dwc_ddrphy_apb_wr_32b(0x52156, 0xf644d97f);
dwc_ddrphy_apb_wr_32b(0x52158, 0x1012844);
dwc_ddrphy_apb_wr_32b(0x5215a, 0xbe14c003);
dwc_ddrphy_apb_wr_32b(0x5215c, 0x781bc649);
dwc_ddrphy_apb_wr_32b(0x5215e, 0xd002055);
dwc_ddrphy_apb_wr_32b(0x52160, 0xf802005);
dwc_ddrphy_apb_wr_32b(0x52162, 0xfe009003);
dwc_ddrphy_apb_wr_32b(0x52164, 0x41c3b020);
dwc_ddrphy_apb_wr_32b(0x52166, 0xe0249003);
dwc_ddrphy_apb_wr_32b(0x52168, 0x3c4208a);
dwc_ddrphy_apb_wr_32b(0x5216a, 0xb1a0706f);
dwc_ddrphy_apb_wr_32b(0x5216c, 0x45190c);
dwc_ddrphy_apb_wr_32b(0x5216e, 0x800419fe);
dwc_ddrphy_apb_wr_32b(0x52170, 0xb7c0234c);
dwc_ddrphy_apb_wr_32b(0x52172, 0x260124);
dwc_ddrphy_apb_wr_32b(0x52174, 0xc003d957);
dwc_ddrphy_apb_wr_32b(0x52176, 0x8c12055);
dwc_ddrphy_apb_wr_32b(0x52178, 0x7825c009);
dwc_ddrphy_apb_wr_32b(0x5217a, 0x2005781b);
dwc_ddrphy_apb_wr_32b(0x5217c, 0x90030f80);
dwc_ddrphy_apb_wr_32b(0x5217e, 0x1800fe00);
dwc_ddrphy_apb_wr_32b(0x52180, 0x9ce06c4);
dwc_ddrphy_apb_wr_32b(0x52182, 0x46cbfe4f);
dwc_ddrphy_apb_wr_32b(0x52184, 0xfe649003);
dwc_ddrphy_apb_wr_32b(0x52186, 0xff6f0f8e);
dwc_ddrphy_apb_wr_32b(0x52188, 0x10051e00);
dwc_ddrphy_apb_wr_32b(0x5218a, 0xff4f0f86);
dwc_ddrphy_apb_wr_32b(0x5218c, 0xff2f0dba);
dwc_ddrphy_apb_wr_32b(0x5218e, 0x710cc004);
dwc_ddrphy_apb_wr_32b(0x52190, 0x600a06);
dwc_ddrphy_apb_wr_32b(0x52192, 0xfc7218a);
dwc_ddrphy_apb_wr_32b(0x52194, 0xdd80c007);
dwc_ddrphy_apb_wr_32b(0x52196, 0x7d19712c);
dwc_ddrphy_apb_wr_32b(0x52198, 0xfe6f0baa);
dwc_ddrphy_apb_wr_32b(0x5219a, 0xc09440a1);
dwc_ddrphy_apb_wr_32b(0x5219c, 0xada702c);
dwc_ddrphy_apb_wr_32b(0x5219e, 0x714c0020);
dwc_ddrphy_apb_wr_32b(0x521a0, 0xfe4f098e);
dwc_ddrphy_apb_wr_32b(0x521a2, 0xf56d87f);
dwc_ddrphy_apb_wr_32b(0x521a4, 0xb600ff6f);
dwc_ddrphy_apb_wr_32b(0x521a6, 0xff4f0f4e);
dwc_ddrphy_apb_wr_32b(0x521a8, 0xff2f0d82);
dwc_ddrphy_apb_wr_32b(0x521aa, 0x730cc004);
dwc_ddrphy_apb_wr_32b(0x521ac, 0x6009ce);
dwc_ddrphy_apb_wr_32b(0x521ae, 0xfc7218a);
dwc_ddrphy_apb_wr_32b(0x521b0, 0xb7a40a1);
dwc_ddrphy_apb_wr_32b(0x521b2, 0x712cfe6f);
dwc_ddrphy_apb_wr_32b(0x521b4, 0x3f802400);
dwc_ddrphy_apb_wr_32b(0x521b6, 0x2140000);
dwc_ddrphy_apb_wr_32b(0x521b8, 0xaa2702c);
dwc_ddrphy_apb_wr_32b(0x521ba, 0x714c0020);
dwc_ddrphy_apb_wr_32b(0x521bc, 0x70031600);
dwc_ddrphy_apb_wr_32b(0x521be, 0x9948000);
dwc_ddrphy_apb_wr_32b(0x521c0, 0xde2316);
dwc_ddrphy_apb_wr_32b(0x521c2, 0x70001600);
dwc_ddrphy_apb_wr_32b(0x521c4, 0x9988000);
dwc_ddrphy_apb_wr_32b(0x521c6, 0xc20879);
dwc_ddrphy_apb_wr_32b(0x521c8, 0x702cc091);
dwc_ddrphy_apb_wr_32b(0x521ca, 0xff6f09c2);
dwc_ddrphy_apb_wr_32b(0x521cc, 0x70adda09);
dwc_ddrphy_apb_wr_32b(0x521ce, 0x1780230a);
dwc_ddrphy_apb_wr_32b(0x521d0, 0x12150d5d);
dwc_ddrphy_apb_wr_32b(0x521d2, 0x2c0202f);
dwc_ddrphy_apb_wr_32b(0x521d4, 0xf872084);
dwc_ddrphy_apb_wr_32b(0x521d6, 0x2135c194);
dwc_ddrphy_apb_wr_32b(0x521d8, 0x2400000f);
dwc_ddrphy_apb_wr_32b(0x521da, 0x3f81);
dwc_ddrphy_apb_wr_32b(0x521dc, 0x21350214);
dwc_ddrphy_apb_wr_32b(0x521de, 0x2316000e);
dwc_ddrphy_apb_wr_32b(0x521e0, 0x4ef000c1);
dwc_ddrphy_apb_wr_32b(0x521e2, 0x22048);
dwc_ddrphy_apb_wr_32b(0x521e4, 0x60b8c091);
dwc_ddrphy_apb_wr_32b(0x521e6, 0x2456a840);
dwc_ddrphy_apb_wr_32b(0x521e8, 0x60383dc0);
dwc_ddrphy_apb_wr_32b(0x521ea, 0x882060b8);
dwc_ddrphy_apb_wr_32b(0x521ec, 0x91f7c4f);
dwc_ddrphy_apb_wr_32b(0x521ee, 0x66fe0325);
dwc_ddrphy_apb_wr_32b(0x521f0, 0x481235a);
dwc_ddrphy_apb_wr_32b(0x521f2, 0x2400a840);
dwc_ddrphy_apb_wr_32b(0x521f4, 0x3f80);
dwc_ddrphy_apb_wr_32b(0x521f6, 0x60380104);
dwc_ddrphy_apb_wr_32b(0x521f8, 0x79dd78b4);
dwc_ddrphy_apb_wr_32b(0x521fa, 0x71a5b020);
dwc_ddrphy_apb_wr_32b(0x521fc, 0xf1d47165);
dwc_ddrphy_apb_wr_32b(0x521fe, 0x26407164);
dwc_ddrphy_apb_wr_32b(0x52200, 0xf1c2325e);
dwc_ddrphy_apb_wr_32b(0x52202, 0xf16e7467);
dwc_ddrphy_apb_wr_32b(0x52204, 0xace740c);
dwc_ddrphy_apb_wr_32b(0x52206, 0xb911feaf);
dwc_ddrphy_apb_wr_32b(0x52208, 0x700f1600);
dwc_ddrphy_apb_wr_32b(0x5220a, 0x9948000);
dwc_ddrphy_apb_wr_32b(0x5220c, 0x70001600);
dwc_ddrphy_apb_wr_32b(0x5220e, 0x9988000);
dwc_ddrphy_apb_wr_32b(0x52210, 0x1047710);
dwc_ddrphy_apb_wr_32b(0x52212, 0x702c0029);
dwc_ddrphy_apb_wr_32b(0x52214, 0x13c02716);
dwc_ddrphy_apb_wr_32b(0x52216, 0x3dc12456);
dwc_ddrphy_apb_wr_32b(0x52218, 0x6038c04f);
dwc_ddrphy_apb_wr_32b(0x5221a, 0x70cd8820);
dwc_ddrphy_apb_wr_32b(0x5221c, 0x275aa828);
dwc_ddrphy_apb_wr_32b(0x5221e, 0x24001480);
dwc_ddrphy_apb_wr_32b(0x52220, 0x3f81);
dwc_ddrphy_apb_wr_32b(0x52222, 0xc0500104);
dwc_ddrphy_apb_wr_32b(0x52224, 0x90206038);
dwc_ddrphy_apb_wr_32b(0x52226, 0xed5b028);
dwc_ddrphy_apb_wr_32b(0x52228, 0x78ef1255);
dwc_ddrphy_apb_wr_32b(0x5222a, 0xc003c044);
dwc_ddrphy_apb_wr_32b(0x5222c, 0x41607bcf);
dwc_ddrphy_apb_wr_32b(0x5222e, 0xc0047d0f);
dwc_ddrphy_apb_wr_32b(0x52230, 0xa6642a1);
dwc_ddrphy_apb_wr_32b(0x52232, 0x43780020);
dwc_ddrphy_apb_wr_32b(0x52234, 0x3008b5);
dwc_ddrphy_apb_wr_32b(0x52236, 0x3dc12456);
dwc_ddrphy_apb_wr_32b(0x52238, 0x6038c00f);
dwc_ddrphy_apb_wr_32b(0x5223a, 0x70c11600);
dwc_ddrphy_apb_wr_32b(0x5223c, 0x18000);
dwc_ddrphy_apb_wr_32b(0x5223e, 0x919c047);
dwc_ddrphy_apb_wr_32b(0x52240, 0x60c80032);
dwc_ddrphy_apb_wr_32b(0x52242, 0xb041c3);
dwc_ddrphy_apb_wr_32b(0x52244, 0x42e10002);
dwc_ddrphy_apb_wr_32b(0x52246, 0xfdef0c5a);
dwc_ddrphy_apb_wr_32b(0x52248, 0xf01143c1);
dwc_ddrphy_apb_wr_32b(0x5224a, 0xc203e88f);
dwc_ddrphy_apb_wr_32b(0x5224c, 0x41c3740c);
dwc_ddrphy_apb_wr_32b(0x5224e, 0x300af);
dwc_ddrphy_apb_wr_32b(0x52250, 0xa3643e1);
dwc_ddrphy_apb_wr_32b(0x52252, 0xc640feaf);
dwc_ddrphy_apb_wr_32b(0x52254, 0x4163c004);
dwc_ddrphy_apb_wr_32b(0x52256, 0x200fe6);
dwc_ddrphy_apb_wr_32b(0x52258, 0xc01042a1);
dwc_ddrphy_apb_wr_32b(0x5225a, 0x3f812400);
dwc_ddrphy_apb_wr_32b(0x5225c, 0x1040000);
dwc_ddrphy_apb_wr_32b(0x5225e, 0x611d42e1);
dwc_ddrphy_apb_wr_32b(0x52260, 0x25f5c007);
dwc_ddrphy_apb_wr_32b(0x52262, 0x43c11381);
dwc_ddrphy_apb_wr_32b(0x52264, 0xc14160c8);
dwc_ddrphy_apb_wr_32b(0x52266, 0xb141c3);
dwc_ddrphy_apb_wr_32b(0x52268, 0xc0400004);
dwc_ddrphy_apb_wr_32b(0x5226a, 0xfeaf0a02);
dwc_ddrphy_apb_wr_32b(0x5226c, 0x2f40740c);
dwc_ddrphy_apb_wr_32b(0x5226e, 0x2e401301);
dwc_ddrphy_apb_wr_32b(0x52270, 0x79051200);
dwc_ddrphy_apb_wr_32b(0x52272, 0x2105c009);
dwc_ddrphy_apb_wr_32b(0x52274, 0x10f83);
dwc_ddrphy_apb_wr_32b(0x52276, 0x78250030);
dwc_ddrphy_apb_wr_32b(0x52278, 0x2005781b);
dwc_ddrphy_apb_wr_32b(0x5227a, 0x90020f82);
dwc_ddrphy_apb_wr_32b(0x5227c, 0x25f40080);
dwc_ddrphy_apb_wr_32b(0x5227e, 0xb2001380);
dwc_ddrphy_apb_wr_32b(0x52280, 0x25f4ca0c);
dwc_ddrphy_apb_wr_32b(0x52282, 0x42c31381);
dwc_ddrphy_apb_wr_32b(0x52284, 0x9000);
dwc_ddrphy_apb_wr_32b(0x52286, 0xc009e805);
dwc_ddrphy_apb_wr_32b(0x52288, 0x781b7865);
dwc_ddrphy_apb_wr_32b(0x5228a, 0x787bf002);
dwc_ddrphy_apb_wr_32b(0x5228c, 0xb0207845);
dwc_ddrphy_apb_wr_32b(0x5228e, 0xf19971c5);
dwc_ddrphy_apb_wr_32b(0x52290, 0xf17c71e5);
dwc_ddrphy_apb_wr_32b(0x52292, 0x708d1600);
dwc_ddrphy_apb_wr_32b(0x52294, 0x48000);
dwc_ddrphy_apb_wr_32b(0x52296, 0x3f802400);
dwc_ddrphy_apb_wr_32b(0x52298, 0x2140000);
dwc_ddrphy_apb_wr_32b(0x5229a, 0xff6f0822);
dwc_ddrphy_apb_wr_32b(0x5229c, 0xd9c9dab4);
dwc_ddrphy_apb_wr_32b(0x5229e, 0x99a750c);
dwc_ddrphy_apb_wr_32b(0x522a0, 0xb911feaf);
dwc_ddrphy_apb_wr_32b(0x522a2, 0x15002d40);
dwc_ddrphy_apb_wr_32b(0x522a4, 0x2400b886);
dwc_ddrphy_apb_wr_32b(0x522a6, 0x3f81);
dwc_ddrphy_apb_wr_32b(0x522a8, 0x8860214);
dwc_ddrphy_apb_wr_32b(0x522aa, 0xda090020);
dwc_ddrphy_apb_wr_32b(0x522ac, 0x2400700c);
dwc_ddrphy_apb_wr_32b(0x522ae, 0x3f82);
dwc_ddrphy_apb_wr_32b(0x522b0, 0x8120214);
dwc_ddrphy_apb_wr_32b(0x522b2, 0xd909fe6f);
dwc_ddrphy_apb_wr_32b(0x522b4, 0xfe8f0c92);
dwc_ddrphy_apb_wr_32b(0x522b6, 0x83dc00b);
dwc_ddrphy_apb_wr_32b(0x522b8, 0xaa20114);
dwc_ddrphy_apb_wr_32b(0x522ba, 0xc00eff2f);
dwc_ddrphy_apb_wr_32b(0x522bc, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x522be, 0x3f98000);
dwc_ddrphy_apb_wr_32b(0x522c0, 0xc008b8e6);
dwc_ddrphy_apb_wr_32b(0x522c2, 0x6120c5);
dwc_ddrphy_apb_wr_32b(0x522c4, 0x3f0821);
dwc_ddrphy_apb_wr_32b(0x522c6, 0x40c3c048);
dwc_ddrphy_apb_wr_32b(0x522c8, 0x8948000);
dwc_ddrphy_apb_wr_32b(0x522ca, 0xda409025);
dwc_ddrphy_apb_wr_32b(0x522cc, 0xf812104);
dwc_ddrphy_apb_wr_32b(0x522ce, 0xfbff0000);
dwc_ddrphy_apb_wr_32b(0x522d0, 0xbcab025);
dwc_ddrphy_apb_wr_32b(0x522d2, 0x712c0120);
dwc_ddrphy_apb_wr_32b(0x522d4, 0x3dfc002);
dwc_ddrphy_apb_wr_32b(0x522d6, 0x7104ffef);
dwc_ddrphy_apb_wr_32b(0x522d8, 0xe80cc006);
dwc_ddrphy_apb_wr_32b(0x522da, 0x702cc005);
dwc_ddrphy_apb_wr_32b(0x522dc, 0xf127d0f);
dwc_ddrphy_apb_wr_32b(0x522de, 0x40a1fe6f);
dwc_ddrphy_apb_wr_32b(0x522e0, 0xd8a40a1);
dwc_ddrphy_apb_wr_32b(0x522e2, 0x702c0060);
dwc_ddrphy_apb_wr_32b(0x522e4, 0x320b2480);
dwc_ddrphy_apb_wr_32b(0x522e6, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x522e8, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x522ea, 0x45cbc0e6);
dwc_ddrphy_apb_wr_32b(0x522ec, 0x9948000);
dwc_ddrphy_apb_wr_32b(0x522ee, 0x221a8580);
dwc_ddrphy_apb_wr_32b(0x522f0, 0x8561030e);
dwc_ddrphy_apb_wr_32b(0x522f2, 0x3220b29);
dwc_ddrphy_apb_wr_32b(0x522f4, 0xf2170ed);
dwc_ddrphy_apb_wr_32b(0x522f6, 0x7bd010a5);
dwc_ddrphy_apb_wr_32b(0x522f8, 0xcb2114);
dwc_ddrphy_apb_wr_32b(0x522fa, 0xf62c0f1);
dwc_ddrphy_apb_wr_32b(0x522fc, 0xc0d1fe0f);
dwc_ddrphy_apb_wr_32b(0x522fe, 0x71c59360);
dwc_ddrphy_apb_wr_32b(0x52300, 0x1b0071e5);
dwc_ddrphy_apb_wr_32b(0x52302, 0xf1f310c4);
dwc_ddrphy_apb_wr_32b(0x52304, 0xf1ed7185);
dwc_ddrphy_apb_wr_32b(0x52306, 0x78e0c4c6);
dwc_ddrphy_apb_wr_32b(0x52308, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x5230a, 0xc1a4b6c8);
dwc_ddrphy_apb_wr_32b(0x5230c, 0x800047cb);
dwc_ddrphy_apb_wr_32b(0x5230e, 0xc0400988);
dwc_ddrphy_apb_wr_32b(0x52310, 0x87638700);
dwc_ddrphy_apb_wr_32b(0x52312, 0x712cc142);
dwc_ddrphy_apb_wr_32b(0x52314, 0xfe6f0fde);
dwc_ddrphy_apb_wr_32b(0x52316, 0xc0434348);
dwc_ddrphy_apb_wr_32b(0x52318, 0x706f710c);
dwc_ddrphy_apb_wr_32b(0x5231a, 0x10300b1f);
dwc_ddrphy_apb_wr_32b(0x5231c, 0x7b76c041);
dwc_ddrphy_apb_wr_32b(0x5231e, 0x10b10b23);
dwc_ddrphy_apb_wr_32b(0x52320, 0x3200264a);
dwc_ddrphy_apb_wr_32b(0x52322, 0xe308d809);
dwc_ddrphy_apb_wr_32b(0x52324, 0x716dc041);
dwc_ddrphy_apb_wr_32b(0x52326, 0x3200234a);
dwc_ddrphy_apb_wr_32b(0x52328, 0x8703f008);
dwc_ddrphy_apb_wr_32b(0x5232a, 0x264a746d);
dwc_ddrphy_apb_wr_32b(0x5232c, 0x7b1b3100);
dwc_ddrphy_apb_wr_32b(0x5232e, 0x716df002);
dwc_ddrphy_apb_wr_32b(0x52330, 0x870487c3);
dwc_ddrphy_apb_wr_32b(0x52332, 0x3a20859);
dwc_ddrphy_apb_wr_32b(0x52334, 0xe51456b);
dwc_ddrphy_apb_wr_32b(0x52336, 0xc2033344);
dwc_ddrphy_apb_wr_32b(0x52338, 0x79af78cf);
dwc_ddrphy_apb_wr_32b(0x5233a, 0x200852);
dwc_ddrphy_apb_wr_32b(0x5233c, 0xe8187a4f);
dwc_ddrphy_apb_wr_32b(0x5233e, 0x12412d40);
dwc_ddrphy_apb_wr_32b(0x52340, 0x13402e40);
dwc_ddrphy_apb_wr_32b(0x52342, 0x20057825);
dwc_ddrphy_apb_wr_32b(0x52344, 0x90020f80);
dwc_ddrphy_apb_wr_32b(0x52346, 0x98200064);
dwc_ddrphy_apb_wr_32b(0x52348, 0xe808c002);
dwc_ddrphy_apb_wr_32b(0x5234a, 0x1402941);
dwc_ddrphy_apb_wr_32b(0x5234c, 0x2084b9c9);
dwc_ddrphy_apb_wr_32b(0x5234e, 0x6119081f);
dwc_ddrphy_apb_wr_32b(0x52350, 0x7874c000);
dwc_ddrphy_apb_wr_32b(0x52352, 0xf006b020);
dwc_ddrphy_apb_wr_32b(0x52354, 0x7874c000);
dwc_ddrphy_apb_wr_32b(0x52356, 0x3c51800);
dwc_ddrphy_apb_wr_32b(0x52358, 0x7561c001);
dwc_ddrphy_apb_wr_32b(0x5235a, 0xf1db631b);
dwc_ddrphy_apb_wr_32b(0x5235c, 0xf1d571c5);
dwc_ddrphy_apb_wr_32b(0x5235e, 0x1404c0a4);
dwc_ddrphy_apb_wr_32b(0x52360, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x52362, 0xe188c0f1);
dwc_ddrphy_apb_wr_32b(0x52364, 0xfe610ff8);
dwc_ddrphy_apb_wr_32b(0x52366, 0x8121ca);
dwc_ddrphy_apb_wr_32b(0x52368, 0x121ca);
dwc_ddrphy_apb_wr_32b(0x5236a, 0x225ff20c);
dwc_ddrphy_apb_wr_32b(0x5236c, 0x60580282);
dwc_ddrphy_apb_wr_32b(0x5236e, 0xf802032);
dwc_ddrphy_apb_wr_32b(0x52370, 0x86c8000);
dwc_ddrphy_apb_wr_32b(0x52372, 0xb8c07839);
dwc_ddrphy_apb_wr_32b(0x52374, 0x12078);
dwc_ddrphy_apb_wr_32b(0x52376, 0x7fe0c0d1);
dwc_ddrphy_apb_wr_32b(0x52378, 0x78e0782f);
dwc_ddrphy_apb_wr_32b(0x5237a, 0xb8638819);
dwc_ddrphy_apb_wr_32b(0x5237c, 0x20e07314);
dwc_ddrphy_apb_wr_32b(0x5237e, 0x40c307cd);
dwc_ddrphy_apb_wr_32b(0x52380, 0x1e4c900e);
dwc_ddrphy_apb_wr_32b(0x52382, 0x7fe0b020);
dwc_ddrphy_apb_wr_32b(0x52384, 0x78e0b041);
dwc_ddrphy_apb_wr_32b(0x52386, 0x45cbc2e2);
dwc_ddrphy_apb_wr_32b(0x52388, 0xe0009005);
dwc_ddrphy_apb_wr_32b(0x5238a, 0x9bed820);
dwc_ddrphy_apb_wr_32b(0x5238c, 0x1d00ff2f);
dwc_ddrphy_apb_wr_32b(0x5238e, 0x1d001045);
dwc_ddrphy_apb_wr_32b(0x52390, 0xc6c21005);
dwc_ddrphy_apb_wr_32b(0x52392, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x52394, 0x2482b6c8);
dwc_ddrphy_apb_wr_32b(0x52396, 0x16003d02);
dwc_ddrphy_apb_wr_32b(0x52398, 0x8000708d);
dwc_ddrphy_apb_wr_32b(0x5239a, 0xc1420004);
dwc_ddrphy_apb_wr_32b(0x5239c, 0xc043702c);
dwc_ddrphy_apb_wr_32b(0x5239e, 0x2b50929);
dwc_ddrphy_apb_wr_32b(0x523a0, 0x3402940);
dwc_ddrphy_apb_wr_32b(0x523a2, 0xf822005);
dwc_ddrphy_apb_wr_32b(0x523a4, 0x949002);
dwc_ddrphy_apb_wr_32b(0x523a6, 0x24559200);
dwc_ddrphy_apb_wr_32b(0x523a8, 0x7b343a03);
dwc_ddrphy_apb_wr_32b(0x523aa, 0x2004b300);
dwc_ddrphy_apb_wr_32b(0x523ac, 0xf80);
dwc_ddrphy_apb_wr_32b(0x523ae, 0xb200fbff);
dwc_ddrphy_apb_wr_32b(0x523b0, 0xf1ee7124);
dwc_ddrphy_apb_wr_32b(0x523b2, 0x41c3c088);
dwc_ddrphy_apb_wr_32b(0x523b4, 0x7348000);
dwc_ddrphy_apb_wr_32b(0x523b6, 0xfdef0916);
dwc_ddrphy_apb_wr_32b(0x523b8, 0xc088da7e);
dwc_ddrphy_apb_wr_32b(0x523ba, 0x1200a4a);
dwc_ddrphy_apb_wr_32b(0x523bc, 0xd56d97e);
dwc_ddrphy_apb_wr_32b(0x523be, 0xb1efe0f);
dwc_ddrphy_apb_wr_32b(0x523c0, 0x40c3ff4f);
dwc_ddrphy_apb_wr_32b(0x523c2, 0x42080000);
dwc_ddrphy_apb_wr_32b(0x523c4, 0x900343db);
dwc_ddrphy_apb_wr_32b(0x523c6, 0x1b00e004);
dwc_ddrphy_apb_wr_32b(0x523c8, 0xc0033004);
dwc_ddrphy_apb_wr_32b(0x523ca, 0x7918712c);
dwc_ddrphy_apb_wr_32b(0x523cc, 0x702c782f);
dwc_ddrphy_apb_wr_32b(0x523ce, 0xfeaf0d02);
dwc_ddrphy_apb_wr_32b(0x523d0, 0x9dac041);
dwc_ddrphy_apb_wr_32b(0x523d2, 0xc00100e0);
dwc_ddrphy_apb_wr_32b(0x523d4, 0xfc7208a);
dwc_ddrphy_apb_wr_32b(0x523d6, 0x32051b20);
dwc_ddrphy_apb_wr_32b(0x523d8, 0x30451b2c);
dwc_ddrphy_apb_wr_32b(0x523da, 0x30041b1e);
dwc_ddrphy_apb_wr_32b(0x523dc, 0xfe0f0d16);
dwc_ddrphy_apb_wr_32b(0x523de, 0xf1ed8f0);
dwc_ddrphy_apb_wr_32b(0x523e0, 0x712cfe2f);
dwc_ddrphy_apb_wr_32b(0x523e2, 0xf16d890);
dwc_ddrphy_apb_wr_32b(0x523e4, 0x712cfe2f);
dwc_ddrphy_apb_wr_32b(0x523e6, 0xf0ed890);
dwc_ddrphy_apb_wr_32b(0x523e8, 0x712cfe2f);
dwc_ddrphy_apb_wr_32b(0x523ea, 0xffcf0f3a);
dwc_ddrphy_apb_wr_32b(0x523ec, 0xe2ec003);
dwc_ddrphy_apb_wr_32b(0x523ee, 0x712cfe6f);
dwc_ddrphy_apb_wr_32b(0x523f0, 0x700f1600);
dwc_ddrphy_apb_wr_32b(0x523f2, 0x9948000);
dwc_ddrphy_apb_wr_32b(0x523f4, 0xc046bd14);
dwc_ddrphy_apb_wr_32b(0x523f6, 0x1600c547);
dwc_ddrphy_apb_wr_32b(0x523f8, 0x80007000);
dwc_ddrphy_apb_wr_32b(0x523fa, 0x8950998);
dwc_ddrphy_apb_wr_32b(0x523fc, 0xd80f03e2);
dwc_ddrphy_apb_wr_32b(0x523fe, 0x13402f40);
dwc_ddrphy_apb_wr_32b(0x52400, 0xf802005);
dwc_ddrphy_apb_wr_32b(0x52402, 0x16e9002);
dwc_ddrphy_apb_wr_32b(0x52404, 0x78ef90c0);
dwc_ddrphy_apb_wr_32b(0x52406, 0xc006c044);
dwc_ddrphy_apb_wr_32b(0x52408, 0x780f702c);
dwc_ddrphy_apb_wr_32b(0x5240a, 0xc004c045);
dwc_ddrphy_apb_wr_32b(0x5240c, 0xfeef0c52);
dwc_ddrphy_apb_wr_32b(0x5240e, 0x7014c205);
dwc_ddrphy_apb_wr_32b(0x52410, 0xc205c004);
dwc_ddrphy_apb_wr_32b(0x52412, 0xc46712c);
dwc_ddrphy_apb_wr_32b(0x52414, 0x26cffeef);
dwc_ddrphy_apb_wr_32b(0x52416, 0x70141021);
dwc_ddrphy_apb_wr_32b(0x52418, 0x70c01600);
dwc_ddrphy_apb_wr_32b(0x5241a, 0x18000);
dwc_ddrphy_apb_wr_32b(0x5241c, 0x32081d);
dwc_ddrphy_apb_wr_32b(0x5241e, 0x112126cf);
dwc_ddrphy_apb_wr_32b(0x52420, 0x14402678);
dwc_ddrphy_apb_wr_32b(0x52422, 0xd841c3);
dwc_ddrphy_apb_wr_32b(0x52424, 0x89e0001);
dwc_ddrphy_apb_wr_32b(0x52426, 0x42e1fdef);
dwc_ddrphy_apb_wr_32b(0x52428, 0xf1cf71e5);
dwc_ddrphy_apb_wr_32b(0x5242a, 0xdfd70ad);
dwc_ddrphy_apb_wr_32b(0x5242c, 0x70b590b5);
dwc_ddrphy_apb_wr_32b(0x5242e, 0x20cad810);
dwc_ddrphy_apb_wr_32b(0x52430, 0x7e0b0061);
dwc_ddrphy_apb_wr_32b(0x52432, 0xc203f410);
dwc_ddrphy_apb_wr_32b(0x52434, 0x41c3740c);
dwc_ddrphy_apb_wr_32b(0x52436, 0x300d7);
dwc_ddrphy_apb_wr_32b(0x52438, 0xe6643e1);
dwc_ddrphy_apb_wr_32b(0x5243a, 0xc540fe6f);
dwc_ddrphy_apb_wr_32b(0x5243c, 0xc205c004);
dwc_ddrphy_apb_wr_32b(0x5243e, 0x200bf6);
dwc_ddrphy_apb_wr_32b(0x52440, 0x10412578);
dwc_ddrphy_apb_wr_32b(0x52442, 0xf1e971a5);
dwc_ddrphy_apb_wr_32b(0x52444, 0xfe6f0d3e);
dwc_ddrphy_apb_wr_32b(0x52446, 0x208ad90f);
dwc_ddrphy_apb_wr_32b(0x52448, 0x1b000208);
dwc_ddrphy_apb_wr_32b(0x5244a, 0xc0013004);
dwc_ddrphy_apb_wr_32b(0x5244c, 0xfeaf0c06);
dwc_ddrphy_apb_wr_32b(0x5244e, 0x8de712c);
dwc_ddrphy_apb_wr_32b(0x52450, 0xc00100e0);
dwc_ddrphy_apb_wr_32b(0x52452, 0xe36d820);
dwc_ddrphy_apb_wr_32b(0x52454, 0x712cfe2f);
dwc_ddrphy_apb_wr_32b(0x52456, 0xfeaf0bd2);
dwc_ddrphy_apb_wr_32b(0x52458, 0x4608740c);
dwc_ddrphy_apb_wr_32b(0x5245a, 0x1600c001);
dwc_ddrphy_apb_wr_32b(0x5245c, 0x8000708d);
dwc_ddrphy_apb_wr_32b(0x5245e, 0xbe2005d);
dwc_ddrphy_apb_wr_32b(0x52460, 0x722cfeaf);
dwc_ddrphy_apb_wr_32b(0x52462, 0x712cc002);
dwc_ddrphy_apb_wr_32b(0x52464, 0xffef0d4a);
dwc_ddrphy_apb_wr_32b(0x52466, 0xbeeb704c);
dwc_ddrphy_apb_wr_32b(0x52468, 0x1600d830);
dwc_ddrphy_apb_wr_32b(0x5246a, 0x80007001);
dwc_ddrphy_apb_wr_32b(0x5246c, 0x20ca098c);
dwc_ddrphy_apb_wr_32b(0x5246e, 0x70b50621);
dwc_ddrphy_apb_wr_32b(0x52470, 0x100125ca);
dwc_ddrphy_apb_wr_32b(0x52472, 0x70001600);
dwc_ddrphy_apb_wr_32b(0x52474, 0x9908000);
dwc_ddrphy_apb_wr_32b(0x52476, 0x420817);
dwc_ddrphy_apb_wr_32b(0x52478, 0x20f4c002);
dwc_ddrphy_apb_wr_32b(0x5247a, 0x48b20040);
dwc_ddrphy_apb_wr_32b(0x5247c, 0x7834c002);
dwc_ddrphy_apb_wr_32b(0x5247e, 0xb0407124);
dwc_ddrphy_apb_wr_32b(0x52480, 0xc006f1f2);
dwc_ddrphy_apb_wr_32b(0x52482, 0x714cc107);
dwc_ddrphy_apb_wr_32b(0x52484, 0x8002055);
dwc_ddrphy_apb_wr_32b(0x52486, 0xc1027825);
dwc_ddrphy_apb_wr_32b(0x52488, 0x12008fe);
dwc_ddrphy_apb_wr_32b(0x5248a, 0x740c716c);
dwc_ddrphy_apb_wr_32b(0x5248c, 0xda41c3);
dwc_ddrphy_apb_wr_32b(0x5248e, 0xdba0001);
dwc_ddrphy_apb_wr_32b(0x52490, 0x42a1fe6f);
dwc_ddrphy_apb_wr_32b(0x52492, 0x1b00702c);
dwc_ddrphy_apb_wr_32b(0x52494, 0x1e003044);
dwc_ddrphy_apb_wr_32b(0x52496, 0x90057044);
dwc_ddrphy_apb_wr_32b(0x52498, 0x921e076);
dwc_ddrphy_apb_wr_32b(0x5249a, 0x245502b5);
dwc_ddrphy_apb_wr_32b(0x5249c, 0x20f43a00);
dwc_ddrphy_apb_wr_32b(0x5249e, 0x29400042);
dwc_ddrphy_apb_wr_32b(0x524a0, 0x20050340);
dwc_ddrphy_apb_wr_32b(0x524a2, 0x90020f80);
dwc_ddrphy_apb_wr_32b(0x524a4, 0xb0400094);
dwc_ddrphy_apb_wr_32b(0x524a6, 0xf1f37124);
dwc_ddrphy_apb_wr_32b(0x524a8, 0xffcf0dbe);
dwc_ddrphy_apb_wr_32b(0x524aa, 0x3d022480);
dwc_ddrphy_apb_wr_32b(0x524ac, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x524ae, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x524b0, 0x21469021);
dwc_ddrphy_apb_wr_32b(0x524b2, 0xb0210601);
dwc_ddrphy_apb_wr_32b(0x524b4, 0x21049022);
dwc_ddrphy_apb_wr_32b(0x524b6, 0xf81);
dwc_ddrphy_apb_wr_32b(0x524b8, 0xb022cfff);
dwc_ddrphy_apb_wr_32b(0x524ba, 0x21469023);
dwc_ddrphy_apb_wr_32b(0x524bc, 0x41c30603);
dwc_ddrphy_apb_wr_32b(0x524be, 0x9888000);
dwc_ddrphy_apb_wr_32b(0x524c0, 0x712c8140);
dwc_ddrphy_apb_wr_32b(0x524c2, 0x2900b063);
dwc_ddrphy_apb_wr_32b(0x524c4, 0x16000082);
dwc_ddrphy_apb_wr_32b(0x524c6, 0x80007081);
dwc_ddrphy_apb_wr_32b(0x524c8, 0x210403ff);
dwc_ddrphy_apb_wr_32b(0x524ca, 0x218a808c);
dwc_ddrphy_apb_wr_32b(0x524cc, 0x228a0044);
dwc_ddrphy_apb_wr_32b(0x524ce, 0x22ca0004);
dwc_ddrphy_apb_wr_32b(0x524d0, 0x90200041);
dwc_ddrphy_apb_wr_32b(0x524d2, 0x44cb7095);
dwc_ddrphy_apb_wr_32b(0x524d4, 0xde3d0000);
dwc_ddrphy_apb_wr_32b(0x524d6, 0x2c12146);
dwc_ddrphy_apb_wr_32b(0x524d8, 0x42c37945);
dwc_ddrphy_apb_wr_32b(0x524da, 0xf3f80000);
dwc_ddrphy_apb_wr_32b(0x524dc, 0xf20eb020);
dwc_ddrphy_apb_wr_32b(0x524de, 0xbb8d9024);
dwc_ddrphy_apb_wr_32b(0x524e0, 0x7984b063);
dwc_ddrphy_apb_wr_32b(0x524e2, 0x9025b024);
dwc_ddrphy_apb_wr_32b(0x524e4, 0xb0257944);
dwc_ddrphy_apb_wr_32b(0x524e6, 0xb98d9026);
dwc_ddrphy_apb_wr_32b(0x524e8, 0xb0267fe0);
dwc_ddrphy_apb_wr_32b(0x524ea, 0x79849024);
dwc_ddrphy_apb_wr_32b(0x524ec, 0x9025b024);
dwc_ddrphy_apb_wr_32b(0x524ee, 0x7fe07944);
dwc_ddrphy_apb_wr_32b(0x524f0, 0x78e0b025);
dwc_ddrphy_apb_wr_32b(0x524f2, 0x1343246f);
dwc_ddrphy_apb_wr_32b(0x524f4, 0xd9209440);
dwc_ddrphy_apb_wr_32b(0x524f6, 0x228cdb40);
dwc_ddrphy_apb_wr_32b(0x524f8, 0x21ca85ca);
dwc_ddrphy_apb_wr_32b(0x524fa, 0x228c0c2d);
dwc_ddrphy_apb_wr_32b(0x524fc, 0x21ca89d0);
dwc_ddrphy_apb_wr_32b(0x524fe, 0x228c00cd);
dwc_ddrphy_apb_wr_32b(0x52500, 0xd8508fd8);
dwc_ddrphy_apb_wr_32b(0x52502, 0xd21ca);
dwc_ddrphy_apb_wr_32b(0x52504, 0x72d3);
dwc_ddrphy_apb_wr_32b(0x52506, 0xd8600e0f);
dwc_ddrphy_apb_wr_32b(0x52508, 0xd21ca);
dwc_ddrphy_apb_wr_32b(0x5250a, 0x72d3);
dwc_ddrphy_apb_wr_32b(0x5250c, 0xd870112f);
dwc_ddrphy_apb_wr_32b(0x5250e, 0xd21ca);
dwc_ddrphy_apb_wr_32b(0x52510, 0x5ca208a);
dwc_ddrphy_apb_wr_32b(0x52512, 0x908c14fe);
dwc_ddrphy_apb_wr_32b(0x52514, 0x80203c);
dwc_ddrphy_apb_wr_32b(0x52516, 0x89d0228c);
dwc_ddrphy_apb_wr_32b(0x52518, 0xad20ca);
dwc_ddrphy_apb_wr_32b(0x5251a, 0x8fd8228c);
dwc_ddrphy_apb_wr_32b(0x5251c, 0xed20ca);
dwc_ddrphy_apb_wr_32b(0x5251e, 0x7905bc15);
dwc_ddrphy_apb_wr_32b(0x52520, 0x1f802405);
dwc_ddrphy_apb_wr_32b(0x52522, 0xf89004);
dwc_ddrphy_apb_wr_32b(0x52524, 0x2250b020);
dwc_ddrphy_apb_wr_32b(0x52526, 0x201a0000);
dwc_ddrphy_apb_wr_32b(0x52528, 0xf80);
dwc_ddrphy_apb_wr_32b(0x5252a, 0x2405096f);
dwc_ddrphy_apb_wr_32b(0x5252c, 0x90041f81);
dwc_ddrphy_apb_wr_32b(0x5252e, 0x2e0500fa);
dwc_ddrphy_apb_wr_32b(0x52530, 0x3b9a7000);
dwc_ddrphy_apb_wr_32b(0x52532, 0x2089ca00);
dwc_ddrphy_apb_wr_32b(0x52534, 0xe0c00fce);
dwc_ddrphy_apb_wr_32b(0x52536, 0xd23ca);
dwc_ddrphy_apb_wr_32b(0x52538, 0xfd8208a);
dwc_ddrphy_apb_wr_32b(0x5253a, 0x80203c);
dwc_ddrphy_apb_wr_32b(0x5253c, 0x72d3);
dwc_ddrphy_apb_wr_32b(0x5253e, 0xb160095f);
dwc_ddrphy_apb_wr_32b(0x52540, 0xad20ca);
dwc_ddrphy_apb_wr_32b(0x52542, 0x1f812405);
dwc_ddrphy_apb_wr_32b(0x52544, 0xe29004);
dwc_ddrphy_apb_wr_32b(0x52546, 0xb1007fe0);
dwc_ddrphy_apb_wr_32b(0x52548, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x5254a, 0xc1a4b6c8);
dwc_ddrphy_apb_wr_32b(0x5254c, 0x43184728);
dwc_ddrphy_apb_wr_32b(0x5254e, 0xb96d840);
dwc_ddrphy_apb_wr_32b(0x52550, 0xd9fffe2f);
dwc_ddrphy_apb_wr_32b(0x52552, 0xfe0f0a62);
dwc_ddrphy_apb_wr_32b(0x52554, 0xc142c143);
dwc_ddrphy_apb_wr_32b(0x52556, 0xc5ec141);
dwc_ddrphy_apb_wr_32b(0x52558, 0xc140fe2f);
dwc_ddrphy_apb_wr_32b(0x5255a, 0x75cd702c);
dwc_ddrphy_apb_wr_32b(0x5255c, 0xb990d8ff);
dwc_ddrphy_apb_wr_32b(0x5255e, 0x726c734c);
dwc_ddrphy_apb_wr_32b(0x52560, 0xc742c543);
dwc_ddrphy_apb_wr_32b(0x52562, 0xc46c641);
dwc_ddrphy_apb_wr_32b(0x52564, 0x1c00fe2f);
dwc_ddrphy_apb_wr_32b(0x52566, 0xd8ff36c0);
dwc_ddrphy_apb_wr_32b(0x52568, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x5256a, 0xc543726c);
dwc_ddrphy_apb_wr_32b(0x5256c, 0xc641c742);
dwc_ddrphy_apb_wr_32b(0x5256e, 0xfe2f0c2e);
dwc_ddrphy_apb_wr_32b(0x52570, 0x36c01c00);
dwc_ddrphy_apb_wr_32b(0x52572, 0xd8ff702c);
dwc_ddrphy_apb_wr_32b(0x52574, 0x734cb990);
dwc_ddrphy_apb_wr_32b(0x52576, 0xc543db18);
dwc_ddrphy_apb_wr_32b(0x52578, 0xc641c742);
dwc_ddrphy_apb_wr_32b(0x5257a, 0xfe2f0c16);
dwc_ddrphy_apb_wr_32b(0x5257c, 0x36c01c00);
dwc_ddrphy_apb_wr_32b(0x5257e, 0xfe0f092e);
dwc_ddrphy_apb_wr_32b(0x52580, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x52582, 0xc06c541);
dwc_ddrphy_apb_wr_32b(0x52584, 0xc540fe2f);
dwc_ddrphy_apb_wr_32b(0x52586, 0xfe0f08fe);
dwc_ddrphy_apb_wr_32b(0x52588, 0x1404c0a4);
dwc_ddrphy_apb_wr_32b(0x5258a, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x5258c, 0x4508c2e6);
dwc_ddrphy_apb_wr_32b(0x5258e, 0x217d4628);
dwc_ddrphy_apb_wr_32b(0x52590, 0x257d0140);
dwc_ddrphy_apb_wr_32b(0x52592, 0x78241141);
dwc_ddrphy_apb_wr_32b(0x52594, 0x41541c3);
dwc_ddrphy_apb_wr_32b(0x52596, 0x42a10002);
dwc_ddrphy_apb_wr_32b(0x52598, 0xfdaf0db6);
dwc_ddrphy_apb_wr_32b(0x5259a, 0x246f43c1);
dwc_ddrphy_apb_wr_32b(0x5259c, 0x8c001243);
dwc_ddrphy_apb_wr_32b(0x5259e, 0x2005b815);
dwc_ddrphy_apb_wr_32b(0x525a0, 0x90080f81);
dwc_ddrphy_apb_wr_32b(0x525a2, 0x200501ea);
dwc_ddrphy_apb_wr_32b(0x525a4, 0x90080f82);
dwc_ddrphy_apb_wr_32b(0x525a6, 0x91e001ec);
dwc_ddrphy_apb_wr_32b(0x525a8, 0x14609260);
dwc_ddrphy_apb_wr_32b(0x525aa, 0x2704110c);
dwc_ddrphy_apb_wr_32b(0x525ac, 0x1f80);
dwc_ddrphy_apb_wr_32b(0x525ae, 0x246dc0ff);
dwc_ddrphy_apb_wr_32b(0x525b0, 0x659d10cc);
dwc_ddrphy_apb_wr_32b(0x525b2, 0x75c3bd08);
dwc_ddrphy_apb_wr_32b(0x525b4, 0xfb000000);
dwc_ddrphy_apb_wr_32b(0x525b6, 0xb10078a5);
dwc_ddrphy_apb_wr_32b(0x525b8, 0x236c6698);
dwc_ddrphy_apb_wr_32b(0x525ba, 0xb8650141);
dwc_ddrphy_apb_wr_32b(0x525bc, 0xb2007825);
dwc_ddrphy_apb_wr_32b(0x525be, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x525c0, 0x4648c2e4);
dwc_ddrphy_apb_wr_32b(0x525c2, 0xf9a4328);
dwc_ddrphy_apb_wr_32b(0x525c4, 0x260afe6f);
dwc_ddrphy_apb_wr_32b(0x525c6, 0x45083000);
dwc_ddrphy_apb_wr_32b(0x525c8, 0x780200a);
dwc_ddrphy_apb_wr_32b(0x525ca, 0xfa64161);
dwc_ddrphy_apb_wr_32b(0x525cc, 0x42c1fe6f);
dwc_ddrphy_apb_wr_32b(0x525ce, 0xf7e4100);
dwc_ddrphy_apb_wr_32b(0x525d0, 0x40a1ffef);
dwc_ddrphy_apb_wr_32b(0x525d2, 0x78e0c6c4);
dwc_ddrphy_apb_wr_32b(0x525d4, 0x4718c3e2);
dwc_ddrphy_apb_wr_32b(0x525d6, 0x2078);
dwc_ddrphy_apb_wr_32b(0x525d8, 0x206f6823);
dwc_ddrphy_apb_wr_32b(0x525da, 0x88600243);
dwc_ddrphy_apb_wr_32b(0x525dc, 0x30421a00);
dwc_ddrphy_apb_wr_32b(0x525de, 0x811069);
dwc_ddrphy_apb_wr_32b(0x525e0, 0x3009af);
dwc_ddrphy_apb_wr_32b(0x525e2, 0xca01c1a2);
dwc_ddrphy_apb_wr_32b(0x525e4, 0x2b00831);
dwc_ddrphy_apb_wr_32b(0x525e6, 0x841704c);
dwc_ddrphy_apb_wr_32b(0x525e8, 0x264a0330);
dwc_ddrphy_apb_wr_32b(0x525ea, 0x8593080);
dwc_ddrphy_apb_wr_32b(0x525ec, 0x264a03b1);
dwc_ddrphy_apb_wr_32b(0x525ee, 0x1c003000);
dwc_ddrphy_apb_wr_32b(0x525f0, 0x16003601);
dwc_ddrphy_apb_wr_32b(0x525f2, 0x90047100);
dwc_ddrphy_apb_wr_32b(0x525f4, 0x841004e);
dwc_ddrphy_apb_wr_32b(0x525f6, 0x264a0071);
dwc_ddrphy_apb_wr_32b(0x525f8, 0x1c043080);
dwc_ddrphy_apb_wr_32b(0x525fa, 0xf01c3581);
dwc_ddrphy_apb_wr_32b(0x525fc, 0xd913cc0c);
dwc_ddrphy_apb_wr_32b(0x525fe, 0x3040264a);
dwc_ddrphy_apb_wr_32b(0x52600, 0x844d208c);
dwc_ddrphy_apb_wr_32b(0x52602, 0x4a121ca);
dwc_ddrphy_apb_wr_32b(0x52604, 0xf012c140);
dwc_ddrphy_apb_wr_32b(0x52606, 0x35011c00);
dwc_ddrphy_apb_wr_32b(0x52608, 0x71001600);
dwc_ddrphy_apb_wr_32b(0x5260a, 0x4e9004);
dwc_ddrphy_apb_wr_32b(0x5260c, 0x51080b);
dwc_ddrphy_apb_wr_32b(0x5260e, 0x34811c04);
dwc_ddrphy_apb_wr_32b(0x52610, 0x1c04f006);
dwc_ddrphy_apb_wr_32b(0x52612, 0xf0043541);
dwc_ddrphy_apb_wr_32b(0x52614, 0x36411c04);
dwc_ddrphy_apb_wr_32b(0x52616, 0x5412b40);
dwc_ddrphy_apb_wr_32b(0x52618, 0x238ac380);
dwc_ddrphy_apb_wr_32b(0x5261a, 0xa3b1004);
dwc_ddrphy_apb_wr_32b(0x5261c, 0xdcfe07a5);
dwc_ddrphy_apb_wr_32b(0x5261e, 0x71444b40);
dwc_ddrphy_apb_wr_32b(0x52620, 0x2844b8e0);
dwc_ddrphy_apb_wr_32b(0x52622, 0x24ca0080);
dwc_ddrphy_apb_wr_32b(0x52624, 0x70f712c1);
dwc_ddrphy_apb_wr_32b(0x52626, 0x7825b80d);
dwc_ddrphy_apb_wr_32b(0x52628, 0x20057885);
dwc_ddrphy_apb_wr_32b(0x5262a, 0x90000f8c);
dwc_ddrphy_apb_wr_32b(0x5262c, 0x94000000);
dwc_ddrphy_apb_wr_32b(0x5262e, 0xf8d2004);
dwc_ddrphy_apb_wr_32b(0x52630, 0xffbf0000);
dwc_ddrphy_apb_wr_32b(0x52632, 0x20cab886);
dwc_ddrphy_apb_wr_32b(0x52634, 0xb4000341);
dwc_ddrphy_apb_wr_32b(0x52636, 0xc7c2f1e5);
dwc_ddrphy_apb_wr_32b(0x52638, 0x225f7034);
dwc_ddrphy_apb_wr_32b(0x5263a, 0x238a0281);
dwc_ddrphy_apb_wr_32b(0x5263c, 0x23ca0c3f);
dwc_ddrphy_apb_wr_32b(0x5263e, 0x603803e1);
dwc_ddrphy_apb_wr_32b(0x52640, 0xf812000);
dwc_ddrphy_apb_wr_32b(0x52642, 0x86c8000);
dwc_ddrphy_apb_wr_32b(0x52644, 0x78658900);
dwc_ddrphy_apb_wr_32b(0x52646, 0xa9007fe0);
dwc_ddrphy_apb_wr_32b(0x52648, 0x282225f);
dwc_ddrphy_apb_wr_32b(0x5264a, 0x20006058);
dwc_ddrphy_apb_wr_32b(0x5264c, 0x80000f82);
dwc_ddrphy_apb_wr_32b(0x5264e, 0x8a00086c);
dwc_ddrphy_apb_wr_32b(0x52650, 0x40200f);
dwc_ddrphy_apb_wr_32b(0x52652, 0xaa007fe0);
dwc_ddrphy_apb_wr_32b(0x52654, 0x4508c2e4);
dwc_ddrphy_apb_wr_32b(0x52656, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x52658, 0x3ff8000);
dwc_ddrphy_apb_wr_32b(0x5265a, 0x36e0817);
dwc_ddrphy_apb_wr_32b(0x5265c, 0x740c740c);
dwc_ddrphy_apb_wr_32b(0x5265e, 0x1fe41c3);
dwc_ddrphy_apb_wr_32b(0x52660, 0xa160001);
dwc_ddrphy_apb_wr_32b(0x52662, 0x42a1fe6f);
dwc_ddrphy_apb_wr_32b(0x52664, 0x46cbc6c4);
dwc_ddrphy_apb_wr_32b(0x52666, 0x8948000);
dwc_ddrphy_apb_wr_32b(0x52668, 0x41c39666);
dwc_ddrphy_apb_wr_32b(0x5266a, 0x201ff);
dwc_ddrphy_apb_wr_32b(0x5266c, 0xfe6f09fe);
dwc_ddrphy_apb_wr_32b(0x5266e, 0x960642a1);
dwc_ddrphy_apb_wr_32b(0x52670, 0xd4e41a1);
dwc_ddrphy_apb_wr_32b(0x52672, 0x714c00a0);
dwc_ddrphy_apb_wr_32b(0x52674, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x52676, 0x18000);
dwc_ddrphy_apb_wr_32b(0x52678, 0x80fe08d9);
dwc_ddrphy_apb_wr_32b(0x5267a, 0x89640a1);
dwc_ddrphy_apb_wr_32b(0x5267c, 0x41c100e0);
dwc_ddrphy_apb_wr_32b(0x5267e, 0x78e0c6c4);
dwc_ddrphy_apb_wr_32b(0x52680, 0x70811600);
dwc_ddrphy_apb_wr_32b(0x52682, 0x48000);
dwc_ddrphy_apb_wr_32b(0x52684, 0x2105b915);
dwc_ddrphy_apb_wr_32b(0x52686, 0x90040f82);
dwc_ddrphy_apb_wr_32b(0x52688, 0x21050040);
dwc_ddrphy_apb_wr_32b(0x5268a, 0x90030f81);
dwc_ddrphy_apb_wr_32b(0x5268c, 0xb200e040);
dwc_ddrphy_apb_wr_32b(0x5268e, 0xffef01f1);
dwc_ddrphy_apb_wr_32b(0x52690, 0x78e0b100);
dwc_ddrphy_apb_wr_32b(0x52692, 0x4300c2e6);
dwc_ddrphy_apb_wr_32b(0x52694, 0x900340c3);
dwc_ddrphy_apb_wr_32b(0x52696, 0x1800ff64);
dwc_ddrphy_apb_wr_32b(0x52698, 0x18040005);
dwc_ddrphy_apb_wr_32b(0x5269a, 0x45cb0045);
dwc_ddrphy_apb_wr_32b(0x5269c, 0x9888000);
dwc_ddrphy_apb_wr_32b(0x5269e, 0x43288500);
dwc_ddrphy_apb_wr_32b(0x526a0, 0xfe6f08c6);
dwc_ddrphy_apb_wr_32b(0x526a2, 0x8543712c);
dwc_ddrphy_apb_wr_32b(0x526a4, 0x852470cd);
dwc_ddrphy_apb_wr_32b(0x526a6, 0x82097f);
dwc_ddrphy_apb_wr_32b(0x526a8, 0x281205a);
dwc_ddrphy_apb_wr_32b(0x526aa, 0x21326159);
dwc_ddrphy_apb_wr_32b(0x526ac, 0x80000f81);
dwc_ddrphy_apb_wr_32b(0x526ae, 0x2306086c);
dwc_ddrphy_apb_wr_32b(0x526b0, 0x79ef104f);
dwc_ddrphy_apb_wr_32b(0x526b2, 0x8fc3218c);
dwc_ddrphy_apb_wr_32b(0x526b4, 0x2a40f417);
dwc_ddrphy_apb_wr_32b(0x526b6, 0x21050341);
dwc_ddrphy_apb_wr_32b(0x526b8, 0x90020f8c);
dwc_ddrphy_apb_wr_32b(0x526ba, 0x21051f64);
dwc_ddrphy_apb_wr_32b(0x526bc, 0x90020f81);
dwc_ddrphy_apb_wr_32b(0x526be, 0xb4601f68);
dwc_ddrphy_apb_wr_32b(0x526c0, 0x123f0b13);
dwc_ddrphy_apb_wr_32b(0x526c2, 0x41c3b1c0);
dwc_ddrphy_apb_wr_32b(0x526c4, 0xf1649003);
dwc_ddrphy_apb_wr_32b(0x526c6, 0x1904b1c0);
dwc_ddrphy_apb_wr_32b(0x526c8, 0x71440045);
dwc_ddrphy_apb_wr_32b(0x526ca, 0x708df1db);
dwc_ddrphy_apb_wr_32b(0x526cc, 0xcfbef7d);
dwc_ddrphy_apb_wr_32b(0x526ce, 0x272f9275);
dwc_ddrphy_apb_wr_32b(0x526d0, 0xf75393c2);
dwc_ddrphy_apb_wr_32b(0x526d2, 0x35e2a40);
dwc_ddrphy_apb_wr_32b(0x526d4, 0x12412c40);
dwc_ddrphy_apb_wr_32b(0x526d6, 0x7812105);
dwc_ddrphy_apb_wr_32b(0x526d8, 0xf9e2105);
dwc_ddrphy_apb_wr_32b(0x526da, 0x1649002);
dwc_ddrphy_apb_wr_32b(0x526dc, 0xf812105);
dwc_ddrphy_apb_wr_32b(0x526de, 0x1689002);
dwc_ddrphy_apb_wr_32b(0x526e0, 0x30c41e00);
dwc_ddrphy_apb_wr_32b(0x526e2, 0x7185b1c0);
dwc_ddrphy_apb_wr_32b(0x526e4, 0xc6c6f1e8);
dwc_ddrphy_apb_wr_32b(0x526e6, 0x4220c0f1);
dwc_ddrphy_apb_wr_32b(0x526e8, 0xfe6f0e9a);
dwc_ddrphy_apb_wr_32b(0x526ea, 0x718d4300);
dwc_ddrphy_apb_wr_32b(0x526ec, 0xb47eb23);
dwc_ddrphy_apb_wr_32b(0x526ee, 0xb090150);
dwc_ddrphy_apb_wr_32b(0x526f0, 0xe89f0191);
dwc_ddrphy_apb_wr_32b(0x526f2, 0xb09ea84);
dwc_ddrphy_apb_wr_32b(0x526f4, 0xe81b0251);
dwc_ddrphy_apb_wr_32b(0x526f6, 0x2910b09);
dwc_ddrphy_apb_wr_32b(0x526f8, 0x50082f);
dwc_ddrphy_apb_wr_32b(0x526fa, 0x422078);
dwc_ddrphy_apb_wr_32b(0x526fc, 0x2c1237f);
dwc_ddrphy_apb_wr_32b(0x526fe, 0xf411794b);
dwc_ddrphy_apb_wr_32b(0x52700, 0x822078);
dwc_ddrphy_apb_wr_32b(0x52702, 0x3012378);
dwc_ddrphy_apb_wr_32b(0x52704, 0xf40b794b);
dwc_ddrphy_apb_wr_32b(0x52706, 0x12078);
dwc_ddrphy_apb_wr_32b(0x52708, 0x240237f);
dwc_ddrphy_apb_wr_32b(0x5270a, 0xf405782b);
dwc_ddrphy_apb_wr_32b(0x5270c, 0x34c237f);
dwc_ddrphy_apb_wr_32b(0x5270e, 0xc0d17c44);
dwc_ddrphy_apb_wr_32b(0x52710, 0x40817fe0);
dwc_ddrphy_apb_wr_32b(0x52712, 0x70811600);
dwc_ddrphy_apb_wr_32b(0x52714, 0x108000);
dwc_ddrphy_apb_wr_32b(0x52716, 0x7fe07824);
dwc_ddrphy_apb_wr_32b(0x52718, 0x2078);
dwc_ddrphy_apb_wr_32b(0x5271a, 0x45cbc2e4);
dwc_ddrphy_apb_wr_32b(0x5271c, 0x569004);
dwc_ddrphy_apb_wr_32b(0x5271e, 0x43a995c0);
dwc_ddrphy_apb_wr_32b(0x52720, 0x12832380);
dwc_ddrphy_apb_wr_32b(0x52722, 0x10551bd0);
dwc_ddrphy_apb_wr_32b(0x52724, 0x2605702c);
dwc_ddrphy_apb_wr_32b(0x52726, 0x1f80);
dwc_ddrphy_apb_wr_32b(0x52728, 0x1b001800);
dwc_ddrphy_apb_wr_32b(0x5272a, 0xb5001005);
dwc_ddrphy_apb_wr_32b(0x5272c, 0x70441e00);
dwc_ddrphy_apb_wr_32b(0x5272e, 0xe1129005);
dwc_ddrphy_apb_wr_32b(0x52730, 0x91001320);
dwc_ddrphy_apb_wr_32b(0x52732, 0x101204f);
dwc_ddrphy_apb_wr_32b(0x52734, 0x90441b20);
dwc_ddrphy_apb_wr_32b(0x52736, 0x90041b20);
dwc_ddrphy_apb_wr_32b(0x52738, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x5273a, 0x18000);
dwc_ddrphy_apb_wr_32b(0x5273c, 0x5f080d);
dwc_ddrphy_apb_wr_32b(0x5273e, 0x5f540c3);
dwc_ddrphy_apb_wr_32b(0x52740, 0xf005e100);
dwc_ddrphy_apb_wr_32b(0x52742, 0x9840c3);
dwc_ddrphy_apb_wr_32b(0x52744, 0xab29680);
dwc_ddrphy_apb_wr_32b(0x52746, 0x702cfeef);
dwc_ddrphy_apb_wr_32b(0x52748, 0x1b00b5c0);
dwc_ddrphy_apb_wr_32b(0x5274a, 0xc6c41045);
dwc_ddrphy_apb_wr_32b(0x5274c, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x5274e, 0x2482b6c8);
dwc_ddrphy_apb_wr_32b(0x52750, 0x46083509);
dwc_ddrphy_apb_wr_32b(0x52752, 0x843206f);
dwc_ddrphy_apb_wr_32b(0x52754, 0x10f48820);
dwc_ddrphy_apb_wr_32b(0x52756, 0x700c808d);
dwc_ddrphy_apb_wr_32b(0x52758, 0xe0fc14d);
dwc_ddrphy_apb_wr_32b(0x5275a, 0xc04311b5);
dwc_ddrphy_apb_wr_32b(0x5275c, 0x78d9d839);
dwc_ddrphy_apb_wr_32b(0x5275e, 0x2678b8c0);
dwc_ddrphy_apb_wr_32b(0x52760, 0x78251381);
dwc_ddrphy_apb_wr_32b(0x52762, 0x700cc046);
dwc_ddrphy_apb_wr_32b(0x52764, 0x11f50e23);
dwc_ddrphy_apb_wr_32b(0x52766, 0xd858c044);
dwc_ddrphy_apb_wr_32b(0x52768, 0x83802011);
dwc_ddrphy_apb_wr_32b(0x5276a, 0xc044700c);
dwc_ddrphy_apb_wr_32b(0x5276c, 0xc006f209);
dwc_ddrphy_apb_wr_32b(0x5276e, 0xea2e804);
dwc_ddrphy_apb_wr_32b(0x52770, 0xf004fe0f);
dwc_ddrphy_apb_wr_32b(0x52772, 0xfe0f0eba);
dwc_ddrphy_apb_wr_32b(0x52774, 0xc004c044);
dwc_ddrphy_apb_wr_32b(0x52776, 0x12078);
dwc_ddrphy_apb_wr_32b(0x52778, 0x11002679);
dwc_ddrphy_apb_wr_32b(0x5277a, 0x80402005);
dwc_ddrphy_apb_wr_32b(0x5277c, 0xf405c049);
dwc_ddrphy_apb_wr_32b(0x5277e, 0xfe2f0f56);
dwc_ddrphy_apb_wr_32b(0x52780, 0x2d40c006);
dwc_ddrphy_apb_wr_32b(0x52782, 0x16001500);
dwc_ddrphy_apb_wr_32b(0x52784, 0x80007083);
dwc_ddrphy_apb_wr_32b(0x52786, 0xc04a0001);
dwc_ddrphy_apb_wr_32b(0x52788, 0x3ec02455);
dwc_ddrphy_apb_wr_32b(0x5278a, 0xfdcf0e1e);
dwc_ddrphy_apb_wr_32b(0x5278c, 0xe3ec08e);
dwc_ddrphy_apb_wr_32b(0x5278e, 0xdab4feef);
dwc_ddrphy_apb_wr_32b(0x52790, 0x710cbbe2);
dwc_ddrphy_apb_wr_32b(0x52792, 0x20cac048);
dwc_ddrphy_apb_wr_32b(0x52794, 0xc04803e1);
dwc_ddrphy_apb_wr_32b(0x52796, 0x11802679);
dwc_ddrphy_apb_wr_32b(0x52798, 0x2642c04b);
dwc_ddrphy_apb_wr_32b(0x5279a, 0x706f1240);
dwc_ddrphy_apb_wr_32b(0x5279c, 0xc003c04c);
dwc_ddrphy_apb_wr_32b(0x5279e, 0x1347414);
dwc_ddrphy_apb_wr_32b(0x527a0, 0xc0030006);
dwc_ddrphy_apb_wr_32b(0x527a2, 0xfe2f0ec2);
dwc_ddrphy_apb_wr_32b(0x527a4, 0xc047c106);
dwc_ddrphy_apb_wr_32b(0x527a6, 0xc00dc103);
dwc_ddrphy_apb_wr_32b(0x527a8, 0x80402011);
dwc_ddrphy_apb_wr_32b(0x527aa, 0xc003f28a);
dwc_ddrphy_apb_wr_32b(0x527ac, 0x800041c3);
dwc_ddrphy_apb_wr_32b(0x527ae, 0xa1000988);
dwc_ddrphy_apb_wr_32b(0x527b0, 0xc045780f);
dwc_ddrphy_apb_wr_32b(0x527b2, 0x800040c3);
dwc_ddrphy_apb_wr_32b(0x527b4, 0xc920894);
dwc_ddrphy_apb_wr_32b(0x527b6, 0xc1050020);
dwc_ddrphy_apb_wr_32b(0x527b8, 0x3d002456);
dwc_ddrphy_apb_wr_32b(0x527ba, 0xfdcf0dbe);
dwc_ddrphy_apb_wr_32b(0x527bc, 0xee0f70ed);
dwc_ddrphy_apb_wr_32b(0x527be, 0x10f00e27);
dwc_ddrphy_apb_wr_32b(0x527c0, 0xe29704c);
dwc_ddrphy_apb_wr_32b(0x527c2, 0xe2d1090);
dwc_ddrphy_apb_wr_32b(0x527c4, 0x24561071);
dwc_ddrphy_apb_wr_32b(0x527c6, 0xa1e3d01);
dwc_ddrphy_apb_wr_32b(0x527c8, 0xc0050120);
dwc_ddrphy_apb_wr_32b(0x527ca, 0xc005f04f);
dwc_ddrphy_apb_wr_32b(0x527cc, 0xffaf0f8e);
dwc_ddrphy_apb_wr_32b(0x527ce, 0x3d012456);
dwc_ddrphy_apb_wr_32b(0x527d0, 0xc003f049);
dwc_ddrphy_apb_wr_32b(0x527d2, 0xf00bc104);
dwc_ddrphy_apb_wr_32b(0x527d4, 0xe00b1a);
dwc_ddrphy_apb_wr_32b(0x527d6, 0xf043c005);
dwc_ddrphy_apb_wr_32b(0x527d8, 0x13b10e11);
dwc_ddrphy_apb_wr_32b(0x527da, 0xc003714c);
dwc_ddrphy_apb_wr_32b(0x527dc, 0x93ec104);
dwc_ddrphy_apb_wr_32b(0x527de, 0xf03bff8f);
dwc_ddrphy_apb_wr_32b(0x527e0, 0x8376e0c);
dwc_ddrphy_apb_wr_32b(0x527e2, 0xc08e00b5);
dwc_ddrphy_apb_wr_32b(0x527e4, 0x2455c042);
dwc_ddrphy_apb_wr_32b(0x527e6, 0xc0413ec0);
dwc_ddrphy_apb_wr_32b(0x527e8, 0x3d002456);
dwc_ddrphy_apb_wr_32b(0x527ea, 0xc004c040);
dwc_ddrphy_apb_wr_32b(0x527ec, 0xc108dbff);
dwc_ddrphy_apb_wr_32b(0x527ee, 0x208a7014);
dwc_ddrphy_apb_wr_32b(0x527f0, 0x731c0fc7);
dwc_ddrphy_apb_wr_32b(0x527f2, 0x11402678);
dwc_ddrphy_apb_wr_32b(0x527f4, 0xada6852);
dwc_ddrphy_apb_wr_32b(0x527f6, 0xc003ff2f);
dwc_ddrphy_apb_wr_32b(0x527f8, 0xdf8c716f);
dwc_ddrphy_apb_wr_32b(0x527fa, 0xe25f014);
dwc_ddrphy_apb_wr_32b(0x527fc, 0xc08e11b1);
dwc_ddrphy_apb_wr_32b(0x527fe, 0x2455c041);
dwc_ddrphy_apb_wr_32b(0x52800, 0xc0403ec0);
dwc_ddrphy_apb_wr_32b(0x52802, 0xc108c003);
dwc_ddrphy_apb_wr_32b(0x52804, 0x8eac204);
dwc_ddrphy_apb_wr_32b(0x52806, 0x24560060);
dwc_ddrphy_apb_wr_32b(0x52808, 0x716f3d03);
dwc_ddrphy_apb_wr_32b(0x5280a, 0xf004dfc0);
dwc_ddrphy_apb_wr_32b(0x5280c, 0x30100b1b);
dwc_ddrphy_apb_wr_32b(0x5280e, 0xc20bc007);
dwc_ddrphy_apb_wr_32b(0x52810, 0x3d012456);
dwc_ddrphy_apb_wr_32b(0x52812, 0xc00a671f);
dwc_ddrphy_apb_wr_32b(0x52814, 0x9e6716c);
dwc_ddrphy_apb_wr_32b(0x52816, 0x78e500e0);
dwc_ddrphy_apb_wr_32b(0x52818, 0x9ca476b);
dwc_ddrphy_apb_wr_32b(0x5281a, 0xe0ffe4f);
dwc_ddrphy_apb_wr_32b(0x5281c, 0xc00710d1);
dwc_ddrphy_apb_wr_32b(0x5281e, 0xfe2f0fee);
dwc_ddrphy_apb_wr_32b(0x52820, 0xe11c105);
dwc_ddrphy_apb_wr_32b(0x52822, 0xc0071391);
dwc_ddrphy_apb_wr_32b(0x52824, 0xfe2f0fe2);
dwc_ddrphy_apb_wr_32b(0x52826, 0xf00dc105);
dwc_ddrphy_apb_wr_32b(0x52828, 0x817c00c);
dwc_ddrphy_apb_wr_32b(0x5282a, 0x710c0134);
dwc_ddrphy_apb_wr_32b(0x5282c, 0xc207c106);
dwc_ddrphy_apb_wr_32b(0x5282e, 0x7826c305);
dwc_ddrphy_apb_wr_32b(0x52830, 0xfe2f0f22);
dwc_ddrphy_apb_wr_32b(0x52832, 0x43f941a1);
dwc_ddrphy_apb_wr_32b(0x52834, 0x7104c003);
dwc_ddrphy_apb_wr_32b(0x52836, 0xf167c043);
dwc_ddrphy_apb_wr_32b(0x52838, 0x7014c009);
dwc_ddrphy_apb_wr_32b(0x5283a, 0xfe010db8);
dwc_ddrphy_apb_wr_32b(0x5283c, 0x70031e00);
dwc_ddrphy_apb_wr_32b(0x5283e, 0x148000);
dwc_ddrphy_apb_wr_32b(0x52840, 0x35092480);
dwc_ddrphy_apb_wr_32b(0x52842, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x52844, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x52846, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x52848, 0xc1b0b6c8);
dwc_ddrphy_apb_wr_32b(0x5284a, 0x1600c04e);
dwc_ddrphy_apb_wr_32b(0x5284c, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x5284e, 0xc0470004);
dwc_ddrphy_apb_wr_32b(0x52850, 0xfe6f0ef6);
dwc_ddrphy_apb_wr_32b(0x52852, 0x40c34020);
dwc_ddrphy_apb_wr_32b(0x52854, 0xffff0000);
dwc_ddrphy_apb_wr_32b(0x52856, 0x42004100);
dwc_ddrphy_apb_wr_32b(0x52858, 0xfe6f0d1a);
dwc_ddrphy_apb_wr_32b(0x5285a, 0xc1a4300);
dwc_ddrphy_apb_wr_32b(0x5285c, 0x47cbfdcf);
dwc_ddrphy_apb_wr_32b(0x5285e, 0xe0049003);
dwc_ddrphy_apb_wr_32b(0x52860, 0x10151f22);
dwc_ddrphy_apb_wr_32b(0x52862, 0xfc7208a);
dwc_ddrphy_apb_wr_32b(0x52864, 0x101c1fa7);
dwc_ddrphy_apb_wr_32b(0x52866, 0x101c1fa8);
dwc_ddrphy_apb_wr_32b(0x52868, 0xd9ff710c);
dwc_ddrphy_apb_wr_32b(0x5286a, 0x1ffeb700);
dwc_ddrphy_apb_wr_32b(0x5286c, 0xb7059004);
dwc_ddrphy_apb_wr_32b(0x5286e, 0xffef0c4a);
dwc_ddrphy_apb_wr_32b(0x52870, 0x90041ffc);
dwc_ddrphy_apb_wr_32b(0x52872, 0x800046cb);
dwc_ddrphy_apb_wr_32b(0x52874, 0x86030988);
dwc_ddrphy_apb_wr_32b(0x52876, 0x1600c046);
dwc_ddrphy_apb_wr_32b(0x52878, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x5287a, 0xb81a0001);
dwc_ddrphy_apb_wr_32b(0x5287c, 0x7c12842);
dwc_ddrphy_apb_wr_32b(0x5287e, 0x7824c006);
dwc_ddrphy_apb_wr_32b(0x52880, 0x8604c042);
dwc_ddrphy_apb_wr_32b(0x52882, 0x7824c04b);
dwc_ddrphy_apb_wr_32b(0x52884, 0x8602c04c);
dwc_ddrphy_apb_wr_32b(0x52886, 0x8601c04a);
dwc_ddrphy_apb_wr_32b(0x52888, 0xc102c049);
dwc_ddrphy_apb_wr_32b(0x5288a, 0x1600c00c);
dwc_ddrphy_apb_wr_32b(0x5288c, 0x80007082);
dwc_ddrphy_apb_wr_32b(0x5288e, 0x71100001);
dwc_ddrphy_apb_wr_32b(0x52890, 0x90200);
dwc_ddrphy_apb_wr_32b(0x52892, 0xa17ca07);
dwc_ddrphy_apb_wr_32b(0x52894, 0xc048017e);
dwc_ddrphy_apb_wr_32b(0x52896, 0xa604c002);
dwc_ddrphy_apb_wr_32b(0x52898, 0x781ba603);
dwc_ddrphy_apb_wr_32b(0x5289a, 0x7104a601);
dwc_ddrphy_apb_wr_32b(0x5289c, 0x770ca602);
dwc_ddrphy_apb_wr_32b(0x5289e, 0x73adc043);
dwc_ddrphy_apb_wr_32b(0x528a0, 0xc041700c);
dwc_ddrphy_apb_wr_32b(0x528a2, 0x17a70b5);
dwc_ddrphy_apb_wr_32b(0x528a4, 0x752c002b);
dwc_ddrphy_apb_wr_32b(0x528a6, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x528a8, 0x108000);
dwc_ddrphy_apb_wr_32b(0x528aa, 0x2011a6a0);
dwc_ddrphy_apb_wr_32b(0x528ac, 0xf2b18340);
dwc_ddrphy_apb_wr_32b(0x528ae, 0x40a1712c);
dwc_ddrphy_apb_wr_32b(0x528b0, 0xfe2f0ca6);
dwc_ddrphy_apb_wr_32b(0x528b2, 0x35b2900);
dwc_ddrphy_apb_wr_32b(0x528b4, 0x78afc04f);
dwc_ddrphy_apb_wr_32b(0x528b6, 0x40c3c045);
dwc_ddrphy_apb_wr_32b(0x528b8, 0x8948000);
dwc_ddrphy_apb_wr_32b(0x528ba, 0x200a86);
dwc_ddrphy_apb_wr_32b(0x528bc, 0xc005c105);
dwc_ddrphy_apb_wr_32b(0x528be, 0x2009ce);
dwc_ddrphy_apb_wr_32b(0x528c0, 0x740c712c);
dwc_ddrphy_apb_wr_32b(0x528c2, 0x1b41c3);
dwc_ddrphy_apb_wr_32b(0x528c4, 0xd4e0001);
dwc_ddrphy_apb_wr_32b(0x528c6, 0x42a1fe2f);
dwc_ddrphy_apb_wr_32b(0x528c8, 0x6c7202f);
dwc_ddrphy_apb_wr_32b(0x528ca, 0xc2e702c);
dwc_ddrphy_apb_wr_32b(0x528cc, 0xc04dff2f);
dwc_ddrphy_apb_wr_32b(0x528ce, 0xfdcf0a6e);
dwc_ddrphy_apb_wr_32b(0x528d0, 0x301b1404);
dwc_ddrphy_apb_wr_32b(0x528d2, 0x230cc008);
dwc_ddrphy_apb_wr_32b(0x528d4, 0xeeb000);
dwc_ddrphy_apb_wr_32b(0x528d6, 0xc1070009);
dwc_ddrphy_apb_wr_32b(0x528d8, 0x2105b915);
dwc_ddrphy_apb_wr_32b(0x528da, 0x90050f80);
dwc_ddrphy_apb_wr_32b(0x528dc, 0x1800e040);
dwc_ddrphy_apb_wr_32b(0x528de, 0x160006c4);
dwc_ddrphy_apb_wr_32b(0x528e0, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x528e2, 0x8110001);
dwc_ddrphy_apb_wr_32b(0x528e4, 0x2105015f);
dwc_ddrphy_apb_wr_32b(0x528e6, 0x90030f80);
dwc_ddrphy_apb_wr_32b(0x528e8, 0xf009e040);
dwc_ddrphy_apb_wr_32b(0x528ea, 0xb80dc002);
dwc_ddrphy_apb_wr_32b(0x528ec, 0x20057825);
dwc_ddrphy_apb_wr_32b(0x528ee, 0x90020f80);
dwc_ddrphy_apb_wr_32b(0x528f0, 0x18000040);
dwc_ddrphy_apb_wr_32b(0x528f2, 0xeee06c4);
dwc_ddrphy_apb_wr_32b(0x528f4, 0xd814feaf);
dwc_ddrphy_apb_wr_32b(0x528f6, 0xff8f0d22);
dwc_ddrphy_apb_wr_32b(0x528f8, 0x712cc00e);
dwc_ddrphy_apb_wr_32b(0x528fa, 0xfdef0ce6);
dwc_ddrphy_apb_wr_32b(0x528fc, 0x86037810);
dwc_ddrphy_apb_wr_32b(0x528fe, 0x700cc041);
dwc_ddrphy_apb_wr_32b(0x52900, 0x8624c044);
dwc_ddrphy_apb_wr_32b(0x52902, 0x979c001);
dwc_ddrphy_apb_wr_32b(0x52904, 0xd80f0022);
dwc_ddrphy_apb_wr_32b(0x52906, 0x702cc201);
dwc_ddrphy_apb_wr_32b(0x52908, 0xba0d706c);
dwc_ddrphy_apb_wr_32b(0x5290a, 0xf802205);
dwc_ddrphy_apb_wr_32b(0x5290c, 0x1709002);
dwc_ddrphy_apb_wr_32b(0x5290e, 0xb1d9000);
dwc_ddrphy_apb_wr_32b(0x52910, 0x2b400235);
dwc_ddrphy_apb_wr_32b(0x52912, 0x78450240);
dwc_ddrphy_apb_wr_32b(0x52914, 0xfdcf0a4e);
dwc_ddrphy_apb_wr_32b(0x52916, 0x7830e804);
dwc_ddrphy_apb_wr_32b(0x52918, 0xc1200f);
dwc_ddrphy_apb_wr_32b(0x5291a, 0xf1f57164);
dwc_ddrphy_apb_wr_32b(0x5291c, 0x205ac00f);
dwc_ddrphy_apb_wr_32b(0x5291e, 0xc0010282);
dwc_ddrphy_apb_wr_32b(0x52920, 0x40c3621a);
dwc_ddrphy_apb_wr_32b(0x52922, 0x86c8000);
dwc_ddrphy_apb_wr_32b(0x52924, 0x21066208);
dwc_ddrphy_apb_wr_32b(0x52926, 0xc1040000);
dwc_ddrphy_apb_wr_32b(0x52928, 0xf008262f);
dwc_ddrphy_apb_wr_32b(0x5292a, 0xc1447905);
dwc_ddrphy_apb_wr_32b(0x5292c, 0xc301f40b);
dwc_ddrphy_apb_wr_32b(0x5292e, 0x41c3740c);
dwc_ddrphy_apb_wr_32b(0x52930, 0x3001d);
dwc_ddrphy_apb_wr_32b(0x52932, 0xc7242a1);
dwc_ddrphy_apb_wr_32b(0x52934, 0x1c00fe2f);
dwc_ddrphy_apb_wr_32b(0x52936, 0xc00436c0);
dwc_ddrphy_apb_wr_32b(0x52938, 0xc0447810);
dwc_ddrphy_apb_wr_32b(0x5293a, 0x7104c001);
dwc_ddrphy_apb_wr_32b(0x5293c, 0xf1c5c041);
dwc_ddrphy_apb_wr_32b(0x5293e, 0xfe2f0b4a);
dwc_ddrphy_apb_wr_32b(0x52940, 0xc003d90f);
dwc_ddrphy_apb_wr_32b(0x52942, 0x6c02008);
dwc_ddrphy_apb_wr_32b(0x52944, 0xc004c041);
dwc_ddrphy_apb_wr_32b(0x52946, 0x710c7014);
dwc_ddrphy_apb_wr_32b(0x52948, 0x7167f206);
dwc_ddrphy_apb_wr_32b(0x5294a, 0xc003f188);
dwc_ddrphy_apb_wr_32b(0x5294c, 0x700cc041);
dwc_ddrphy_apb_wr_32b(0x5294e, 0x2241c3);
dwc_ddrphy_apb_wr_32b(0x52950, 0xe460001);
dwc_ddrphy_apb_wr_32b(0x52952, 0x42a1fd6f);
dwc_ddrphy_apb_wr_32b(0x52954, 0xfeaf0d6a);
dwc_ddrphy_apb_wr_32b(0x52956, 0xc005c00d);
dwc_ddrphy_apb_wr_32b(0x52958, 0x20089a);
dwc_ddrphy_apb_wr_32b(0x5295a, 0xc001702c);
dwc_ddrphy_apb_wr_32b(0x5295c, 0x77a5c043);
dwc_ddrphy_apb_wr_32b(0x5295e, 0xc003f144);
dwc_ddrphy_apb_wr_32b(0x52960, 0x7812b913);
dwc_ddrphy_apb_wr_32b(0x52962, 0xfd6f0e22);
dwc_ddrphy_apb_wr_32b(0x52964, 0x1600b83f);
dwc_ddrphy_apb_wr_32b(0x52966, 0x80007081);
dwc_ddrphy_apb_wr_32b(0x52968, 0xc0030024);
dwc_ddrphy_apb_wr_32b(0x5296a, 0x6119c207);
dwc_ddrphy_apb_wr_32b(0x5296c, 0xba15c008);
dwc_ddrphy_apb_wr_32b(0x5296e, 0xf832205);
dwc_ddrphy_apb_wr_32b(0x52970, 0xe0409005);
dwc_ddrphy_apb_wr_32b(0x52972, 0x12109);
dwc_ddrphy_apb_wr_32b(0x52974, 0x1600b320);
dwc_ddrphy_apb_wr_32b(0x52976, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x52978, 0x8170001);
dwc_ddrphy_apb_wr_32b(0x5297a, 0x2205015f);
dwc_ddrphy_apb_wr_32b(0x5297c, 0x90030f80);
dwc_ddrphy_apb_wr_32b(0x5297e, 0xc12e040);
dwc_ddrphy_apb_wr_32b(0x52980, 0xb020ffaf);
dwc_ddrphy_apb_wr_32b(0x52982, 0xc002f009);
dwc_ddrphy_apb_wr_32b(0x52984, 0x7845b80d);
dwc_ddrphy_apb_wr_32b(0x52986, 0xf802005);
dwc_ddrphy_apb_wr_32b(0x52988, 0x409002);
dwc_ddrphy_apb_wr_32b(0x5298a, 0xc002b020);
dwc_ddrphy_apb_wr_32b(0x5298c, 0x5fb7104);
dwc_ddrphy_apb_wr_32b(0x5298e, 0xc042ffef);
dwc_ddrphy_apb_wr_32b(0x52990, 0x15e0a15);
dwc_ddrphy_apb_wr_32b(0x52992, 0xa604c00b);
dwc_ddrphy_apb_wr_32b(0x52994, 0xa603c006);
dwc_ddrphy_apb_wr_32b(0x52996, 0xa602c00a);
dwc_ddrphy_apb_wr_32b(0x52998, 0xa601c009);
dwc_ddrphy_apb_wr_32b(0x5299a, 0x1fa7700c);
dwc_ddrphy_apb_wr_32b(0x5299c, 0x1fa8101c);
dwc_ddrphy_apb_wr_32b(0x5299e, 0xb700101c);
dwc_ddrphy_apb_wr_32b(0x529a0, 0x1404c0b0);
dwc_ddrphy_apb_wr_32b(0x529a2, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x529a4, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x529a6, 0x4528b6c8);
dwc_ddrphy_apb_wr_32b(0x529a8, 0x70811600);
dwc_ddrphy_apb_wr_32b(0x529aa, 0x3ff8000);
dwc_ddrphy_apb_wr_32b(0x529ac, 0x2e0973);
dwc_ddrphy_apb_wr_32b(0x529ae, 0x712cc1a4);
dwc_ddrphy_apb_wr_32b(0x529b0, 0x1b2900);
dwc_ddrphy_apb_wr_32b(0x529b2, 0x205f781d);
dwc_ddrphy_apb_wr_32b(0x529b4, 0xd9ff0380);
dwc_ddrphy_apb_wr_32b(0x529b6, 0xf8f2034);
dwc_ddrphy_apb_wr_32b(0x529b8, 0x8a08000);
dwc_ddrphy_apb_wr_32b(0x529ba, 0xfdef0abe);
dwc_ddrphy_apb_wr_32b(0x529bc, 0x1200700c);
dwc_ddrphy_apb_wr_32b(0x529be, 0x702c3083);
dwc_ddrphy_apb_wr_32b(0x529c0, 0x754cd8ff);
dwc_ddrphy_apb_wr_32b(0x529c2, 0xc1434628);
dwc_ddrphy_apb_wr_32b(0x529c4, 0xc141c142);
dwc_ddrphy_apb_wr_32b(0x529c6, 0xfdef0b7e);
dwc_ddrphy_apb_wr_32b(0x529c8, 0x202fc140);
dwc_ddrphy_apb_wr_32b(0x529ca, 0x70b506c7);
dwc_ddrphy_apb_wr_32b(0x529cc, 0x27c5c042);
dwc_ddrphy_apb_wr_32b(0x529ce, 0x1f82);
dwc_ddrphy_apb_wr_32b(0x529d0, 0xd8ff2100);
dwc_ddrphy_apb_wr_32b(0x529d2, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x529d4, 0xc643db18);
dwc_ddrphy_apb_wr_32b(0x529d6, 0x31811c04);
dwc_ddrphy_apb_wr_32b(0x529d8, 0xfdef0d46);
dwc_ddrphy_apb_wr_32b(0x529da, 0x876c740);
dwc_ddrphy_apb_wr_32b(0x529dc, 0xc643fdcf);
dwc_ddrphy_apb_wr_32b(0x529de, 0xc641c642);
dwc_ddrphy_apb_wr_32b(0x529e0, 0xfdef0b4a);
dwc_ddrphy_apb_wr_32b(0x529e2, 0x846c640);
dwc_ddrphy_apb_wr_32b(0x529e4, 0xc0a4fdcf);
dwc_ddrphy_apb_wr_32b(0x529e6, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x529e8, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x529ea, 0xba9fda6e);
dwc_ddrphy_apb_wr_32b(0x529ec, 0x4122f4);
dwc_ddrphy_apb_wr_32b(0x529ee, 0x3f090b);
dwc_ddrphy_apb_wr_32b(0x529f0, 0x12f2b905);
dwc_ddrphy_apb_wr_32b(0x529f2, 0x21848101);
dwc_ddrphy_apb_wr_32b(0x529f4, 0x2004001c);
dwc_ddrphy_apb_wr_32b(0x529f6, 0xf80);
dwc_ddrphy_apb_wr_32b(0x529f8, 0x7fe0f8ff);
dwc_ddrphy_apb_wr_32b(0x529fa, 0x78e07825);
dwc_ddrphy_apb_wr_32b(0x529fc, 0x4508c2e2);
dwc_ddrphy_apb_wr_32b(0x529fe, 0xfda9001);
dwc_ddrphy_apb_wr_32b(0x52a00, 0x4328ffef);
dwc_ddrphy_apb_wr_32b(0x52a02, 0x9502b501);
dwc_ddrphy_apb_wr_32b(0x52a04, 0x200836);
dwc_ddrphy_apb_wr_32b(0x52a06, 0xb5024161);
dwc_ddrphy_apb_wr_32b(0x52a08, 0x80e9505);
dwc_ddrphy_apb_wr_32b(0x52a0a, 0x41610020);
dwc_ddrphy_apb_wr_32b(0x52a0c, 0xc6c2b505);
dwc_ddrphy_apb_wr_32b(0x52a0e, 0xba9fda6e);
dwc_ddrphy_apb_wr_32b(0x52a10, 0x4122f4);
dwc_ddrphy_apb_wr_32b(0x52a12, 0x1f0909);
dwc_ddrphy_apb_wr_32b(0x52a14, 0x810112fa);
dwc_ddrphy_apb_wr_32b(0x52a16, 0x72184);
dwc_ddrphy_apb_wr_32b(0x52a18, 0xf802004);
dwc_ddrphy_apb_wr_32b(0x52a1a, 0xfe3f0000);
dwc_ddrphy_apb_wr_32b(0x52a1c, 0x78257fe0);
dwc_ddrphy_apb_wr_32b(0x52a1e, 0xbb9fdb6e);
dwc_ddrphy_apb_wr_32b(0x52a20, 0x4123f4);
dwc_ddrphy_apb_wr_32b(0x52a22, 0x90dda07);
dwc_ddrphy_apb_wr_32b(0x52a24, 0xba09003f);
dwc_ddrphy_apb_wr_32b(0x52a26, 0x810113f4);
dwc_ddrphy_apb_wr_32b(0x52a28, 0x20047944);
dwc_ddrphy_apb_wr_32b(0x52a2a, 0xf80);
dwc_ddrphy_apb_wr_32b(0x52a2c, 0x7fe0f1ff);
dwc_ddrphy_apb_wr_32b(0x52a2e, 0x78e07825);
dwc_ddrphy_apb_wr_32b(0x52a30, 0x8fc3208c);
dwc_ddrphy_apb_wr_32b(0x52a32, 0x821f209);
dwc_ddrphy_apb_wr_32b(0x52a34, 0x41c301d1);
dwc_ddrphy_apb_wr_32b(0x52a36, 0x2029004);
dwc_ddrphy_apb_wr_32b(0x52a38, 0x451900);
dwc_ddrphy_apb_wr_32b(0x52a3a, 0x41c3f006);
dwc_ddrphy_apb_wr_32b(0x52a3c, 0x2029004);
dwc_ddrphy_apb_wr_32b(0x52a3e, 0x1051900);
dwc_ddrphy_apb_wr_32b(0x52a40, 0x51900);
dwc_ddrphy_apb_wr_32b(0x52a42, 0x901841c3);
dwc_ddrphy_apb_wr_32b(0x52a44, 0xb1000064);
dwc_ddrphy_apb_wr_32b(0x52a46, 0x20001d);
dwc_ddrphy_apb_wr_32b(0x52a48, 0x51902);
dwc_ddrphy_apb_wr_32b(0x52a4a, 0x901841c3);
dwc_ddrphy_apb_wr_32b(0x52a4c, 0xb1000064);
dwc_ddrphy_apb_wr_32b(0x52a4e, 0xb102b830);
dwc_ddrphy_apb_wr_32b(0x52a50, 0x200009);
dwc_ddrphy_apb_wr_32b(0x52a52, 0x51902);
dwc_ddrphy_apb_wr_32b(0x52a54, 0x901841c3);
dwc_ddrphy_apb_wr_32b(0x52a56, 0x91000008);
dwc_ddrphy_apb_wr_32b(0x52a58, 0x801f08ff);
dwc_ddrphy_apb_wr_32b(0x52a5a, 0x45195e);
dwc_ddrphy_apb_wr_32b(0x52a5c, 0x8019100);
dwc_ddrphy_apb_wr_32b(0x52a5e, 0x7ee0001e);
dwc_ddrphy_apb_wr_32b(0x52a60, 0x4200c2e2);
dwc_ddrphy_apb_wr_32b(0x52a62, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x52a64, 0x18000);
dwc_ddrphy_apb_wr_32b(0x52a66, 0x13f0827);
dwc_ddrphy_apb_wr_32b(0x52a68, 0xd8084320);
dwc_ddrphy_apb_wr_32b(0x52a6a, 0xffef0f8e);
dwc_ddrphy_apb_wr_32b(0x52a6c, 0xfbe7d50);
dwc_ddrphy_apb_wr_32b(0x52a6e, 0x4040ffef);
dwc_ddrphy_apb_wr_32b(0x52a70, 0xa13704c);
dwc_ddrphy_apb_wr_32b(0x52a72, 0xfb20345);
dwc_ddrphy_apb_wr_32b(0x52a74, 0x1304ffef);
dwc_ddrphy_apb_wr_32b(0x52a76, 0x71440400);
dwc_ddrphy_apb_wr_32b(0x52a78, 0xc6c2f1f9);
dwc_ddrphy_apb_wr_32b(0x52a7a, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x52a7c, 0x2482b6c8);
dwc_ddrphy_apb_wr_32b(0x52a7e, 0x46083706);
dwc_ddrphy_apb_wr_32b(0x52a80, 0x243206f);
dwc_ddrphy_apb_wr_32b(0x52a82, 0x88204728);
dwc_ddrphy_apb_wr_32b(0x52a84, 0x808d10fc);
dwc_ddrphy_apb_wr_32b(0x52a86, 0xc15e40c1);
dwc_ddrphy_apb_wr_32b(0x52a88, 0xc357702c);
dwc_ddrphy_apb_wr_32b(0x52a8a, 0xfe2f08f2);
dwc_ddrphy_apb_wr_32b(0x52a8c, 0x866c24e);
dwc_ddrphy_apb_wr_32b(0x52a8e, 0xc050fe2f);
dwc_ddrphy_apb_wr_32b(0x52a90, 0x24554318);
dwc_ddrphy_apb_wr_32b(0x52a92, 0x80e3e80);
dwc_ddrphy_apb_wr_32b(0x52a94, 0x2455fdcf);
dwc_ddrphy_apb_wr_32b(0x52a96, 0x41c338c0);
dwc_ddrphy_apb_wr_32b(0x52a98, 0x6148000);
dwc_ddrphy_apb_wr_32b(0x52a9a, 0xfd6f0b4e);
dwc_ddrphy_apb_wr_32b(0x52a9c, 0x2455da5a);
dwc_ddrphy_apb_wr_32b(0x52a9e, 0xc8238c0);
dwc_ddrphy_apb_wr_32b(0x52aa0, 0xd95a00a0);
dwc_ddrphy_apb_wr_32b(0x52aa2, 0x2b00716d);
dwc_ddrphy_apb_wr_32b(0x52aa4, 0xc0521380);
dwc_ddrphy_apb_wr_32b(0x52aa6, 0xbde6c00e);
dwc_ddrphy_apb_wr_32b(0x52aa8, 0x20cac051);
dwc_ddrphy_apb_wr_32b(0x52aaa, 0xc0510061);
dwc_ddrphy_apb_wr_32b(0x52aac, 0x3600146d);
dwc_ddrphy_apb_wr_32b(0x52aae, 0x146cc04f);
dwc_ddrphy_apb_wr_32b(0x52ab0, 0xc0553600);
dwc_ddrphy_apb_wr_32b(0x52ab2, 0xe80bc00e);
dwc_ddrphy_apb_wr_32b(0x52ab4, 0x900341c3);
dwc_ddrphy_apb_wr_32b(0x52ab6, 0xb2bf0c4);
dwc_ddrphy_apb_wr_32b(0x52ab8, 0xd8ff3030);
dwc_ddrphy_apb_wr_32b(0x52aba, 0xfc7208a);
dwc_ddrphy_apb_wr_32b(0x52abc, 0x700cf00f);
dwc_ddrphy_apb_wr_32b(0x52abe, 0x235081d);
dwc_ddrphy_apb_wr_32b(0x52ac0, 0x2412840);
dwc_ddrphy_apb_wr_32b(0x52ac2, 0x10022b00);
dwc_ddrphy_apb_wr_32b(0x52ac4, 0xf812105);
dwc_ddrphy_apb_wr_32b(0x52ac6, 0xe0c49003);
dwc_ddrphy_apb_wr_32b(0x52ac8, 0x7104b140);
dwc_ddrphy_apb_wr_32b(0x52aca, 0xb100f1f4);
dwc_ddrphy_apb_wr_32b(0x52acc, 0x712c78cf);
dwc_ddrphy_apb_wr_32b(0x52ace, 0xffef0dae);
dwc_ddrphy_apb_wr_32b(0x52ad0, 0xc012c05b);
dwc_ddrphy_apb_wr_32b(0x52ad2, 0x780f702c);
dwc_ddrphy_apb_wr_32b(0x52ad4, 0xff2f081a);
dwc_ddrphy_apb_wr_32b(0x52ad6, 0x7077c05c);
dwc_ddrphy_apb_wr_32b(0x52ad8, 0xfc7238a);
dwc_ddrphy_apb_wr_32b(0x52ada, 0x727cdaff);
dwc_ddrphy_apb_wr_32b(0x52adc, 0xd8ffc30e);
dwc_ddrphy_apb_wr_32b(0x52ade, 0x7074c643);
dwc_ddrphy_apb_wr_32b(0x52ae0, 0xc04c705c);
dwc_ddrphy_apb_wr_32b(0x52ae2, 0xd80f704c);
dwc_ddrphy_apb_wr_32b(0x52ae4, 0xb808ba8b);
dwc_ddrphy_apb_wr_32b(0x52ae6, 0xc04b705c);
dwc_ddrphy_apb_wr_32b(0x52ae8, 0xc04ad840);
dwc_ddrphy_apb_wr_32b(0x52aea, 0x1600c00e);
dwc_ddrphy_apb_wr_32b(0x52aec, 0x8000701b);
dwc_ddrphy_apb_wr_32b(0x52aee, 0x16000994);
dwc_ddrphy_apb_wr_32b(0x52af0, 0x8000708e);
dwc_ddrphy_apb_wr_32b(0x52af2, 0x207903fe);
dwc_ddrphy_apb_wr_32b(0x52af4, 0x6a010002);
dwc_ddrphy_apb_wr_32b(0x52af6, 0x2455c069);
dwc_ddrphy_apb_wr_32b(0x52af8, 0xc0463e80);
dwc_ddrphy_apb_wr_32b(0x52afa, 0x1600c00f);
dwc_ddrphy_apb_wr_32b(0x52afc, 0x8000700d);
dwc_ddrphy_apb_wr_32b(0x52afe, 0x23160998);
dwc_ddrphy_apb_wr_32b(0x52b00, 0xc04536db);
dwc_ddrphy_apb_wr_32b(0x52b02, 0xbec1c015);
dwc_ddrphy_apb_wr_32b(0x52b04, 0xc044702c);
dwc_ddrphy_apb_wr_32b(0x52b06, 0xba03c00e);
dwc_ddrphy_apb_wr_32b(0x52b08, 0x70147db6);
dwc_ddrphy_apb_wr_32b(0x52b0a, 0x322223ca);
dwc_ddrphy_apb_wr_32b(0x52b0c, 0x728ddb10);
dwc_ddrphy_apb_wr_32b(0x52b0e, 0xc748c16d);
dwc_ddrphy_apb_wr_32b(0x52b10, 0x31831c1c);
dwc_ddrphy_apb_wr_32b(0x52b12, 0x10f00e1b);
dwc_ddrphy_apb_wr_32b(0x52b14, 0x30421c25);
dwc_ddrphy_apb_wr_32b(0x52b16, 0x2e016e13);
dwc_ddrphy_apb_wr_32b(0x52b18, 0x87003);
dwc_ddrphy_apb_wr_32b(0x52b1a, 0x2e010804);
dwc_ddrphy_apb_wr_32b(0x52b1c, 0x2700c);
dwc_ddrphy_apb_wr_32b(0x52b1e, 0x6a010408);
dwc_ddrphy_apb_wr_32b(0x52b20, 0x4d18c054);
dwc_ddrphy_apb_wr_32b(0x52b22, 0x786fc059);
dwc_ddrphy_apb_wr_32b(0x52b24, 0x250925);
dwc_ddrphy_apb_wr_32b(0x52b26, 0x7a8fc05d);
dwc_ddrphy_apb_wr_32b(0x52b28, 0x7aac69a1);
dwc_ddrphy_apb_wr_32b(0x52b2a, 0x4040b9e0);
dwc_ddrphy_apb_wr_32b(0x52b2c, 0xf832084);
dwc_ddrphy_apb_wr_32b(0x52b2e, 0x22ca7813);
dwc_ddrphy_apb_wr_32b(0x52b30, 0xc09f0001);
dwc_ddrphy_apb_wr_32b(0x52b32, 0xa9406119);
dwc_ddrphy_apb_wr_32b(0x52b34, 0xf1ef41a1);
dwc_ddrphy_apb_wr_32b(0x52b36, 0xc053710c);
dwc_ddrphy_apb_wr_32b(0x52b38, 0xc056700c);
dwc_ddrphy_apb_wr_32b(0x52b3a, 0x7014c013);
dwc_ddrphy_apb_wr_32b(0x52b3c, 0xc26f2e5);
dwc_ddrphy_apb_wr_32b(0x52b3e, 0xc083ff2f);
dwc_ddrphy_apb_wr_32b(0x52b40, 0xc019456b);
dwc_ddrphy_apb_wr_32b(0x52b42, 0x362083f);
dwc_ddrphy_apb_wr_32b(0x52b44, 0xc110c083);
dwc_ddrphy_apb_wr_32b(0x52b46, 0xf7e78af);
dwc_ddrphy_apb_wr_32b(0x52b48, 0x792ffdaf);
dwc_ddrphy_apb_wr_32b(0x52b4a, 0x79b4c115);
dwc_ddrphy_apb_wr_32b(0x52b4c, 0x9100e80e);
dwc_ddrphy_apb_wr_32b(0x52b4e, 0x2455e890);
dwc_ddrphy_apb_wr_32b(0x52b50, 0x20f43e80);
dwc_ddrphy_apb_wr_32b(0x52b52, 0x20420340);
dwc_ddrphy_apb_wr_32b(0x52b54, 0x262f0800);
dwc_ddrphy_apb_wr_32b(0x52b56, 0xef006);
dwc_ddrphy_apb_wr_32b(0x52b58, 0xf0060004);
dwc_ddrphy_apb_wr_32b(0x52b5a, 0x40c3);
dwc_ddrphy_apb_wr_32b(0x52b5c, 0xb1001fff);
dwc_ddrphy_apb_wr_32b(0x52b5e, 0x651dc014);
dwc_ddrphy_apb_wr_32b(0x52b60, 0xd62f1e1);
dwc_ddrphy_apb_wr_32b(0x52b62, 0x456bff0f);
dwc_ddrphy_apb_wr_32b(0x52b64, 0x841c019);
dwc_ddrphy_apb_wr_32b(0x52b66, 0x70cd0362);
dwc_ddrphy_apb_wr_32b(0x52b68, 0x78afc110);
dwc_ddrphy_apb_wr_32b(0x52b6a, 0xfdaf0f36);
dwc_ddrphy_apb_wr_32b(0x52b6c, 0xe810792f);
dwc_ddrphy_apb_wr_32b(0x52b6e, 0x3e802455);
dwc_ddrphy_apb_wr_32b(0x52b70, 0x34220f5);
dwc_ddrphy_apb_wr_32b(0x52b72, 0x8120a1f);
dwc_ddrphy_apb_wr_32b(0x52b74, 0x20f4c00f);
dwc_ddrphy_apb_wr_32b(0x52b76, 0x8170340);
dwc_ddrphy_apb_wr_32b(0x52b78, 0x4a480ff1);
dwc_ddrphy_apb_wr_32b(0x52b7a, 0xf005c10f);
dwc_ddrphy_apb_wr_32b(0x52b7c, 0xd807c10f);
dwc_ddrphy_apb_wr_32b(0x52b7e, 0x79b4b80d);
dwc_ddrphy_apb_wr_32b(0x52b80, 0xc014b100);
dwc_ddrphy_apb_wr_32b(0x52b82, 0xf1e2651d);
dwc_ddrphy_apb_wr_32b(0x52b84, 0x1600c016);
dwc_ddrphy_apb_wr_32b(0x52b86, 0x8000700f);
dwc_ddrphy_apb_wr_32b(0x52b88, 0x780f0994);
dwc_ddrphy_apb_wr_32b(0x52b8a, 0xc118c058);
dwc_ddrphy_apb_wr_32b(0x52b8c, 0x7110c01d);
dwc_ddrphy_apb_wr_32b(0x52b8e, 0x20cac011);
dwc_ddrphy_apb_wr_32b(0x52b90, 0xc0510061);
dwc_ddrphy_apb_wr_32b(0x52b92, 0xc053700c);
dwc_ddrphy_apb_wr_32b(0x52b94, 0x70001600);
dwc_ddrphy_apb_wr_32b(0x52b96, 0x9988000);
dwc_ddrphy_apb_wr_32b(0x52b98, 0x1047710);
dwc_ddrphy_apb_wr_32b(0x52b9a, 0xc0140009);
dwc_ddrphy_apb_wr_32b(0x52b9c, 0x661e456b);
dwc_ddrphy_apb_wr_32b(0x52b9e, 0x720c77c5);
dwc_ddrphy_apb_wr_32b(0x52ba0, 0xdf1c05a);
dwc_ddrphy_apb_wr_32b(0x52ba2, 0xc00e1253);
dwc_ddrphy_apb_wr_32b(0x52ba4, 0xd15e88a);
dwc_ddrphy_apb_wr_32b(0x52ba6, 0x79d01231);
dwc_ddrphy_apb_wr_32b(0x52ba8, 0x7834c017);
dwc_ddrphy_apb_wr_32b(0x52baa, 0x810110f0);
dwc_ddrphy_apb_wr_32b(0x52bac, 0xf05ab020);
dwc_ddrphy_apb_wr_32b(0x52bae, 0x78cfc110);
dwc_ddrphy_apb_wr_32b(0x52bb0, 0xeaa792f);
dwc_ddrphy_apb_wr_32b(0x52bb2, 0xc152fdaf);
dwc_ddrphy_apb_wr_32b(0x52bb4, 0x3008a5);
dwc_ddrphy_apb_wr_32b(0x52bb6, 0xc0157ad0);
dwc_ddrphy_apb_wr_32b(0x52bb8, 0x8320f5);
dwc_ddrphy_apb_wr_32b(0x52bba, 0x20f5c00f);
dwc_ddrphy_apb_wr_32b(0x52bbc, 0x48710080);
dwc_ddrphy_apb_wr_32b(0x52bbe, 0x12148);
dwc_ddrphy_apb_wr_32b(0x52bc0, 0x981792e);
dwc_ddrphy_apb_wr_32b(0x52bc2, 0x607801b3);
dwc_ddrphy_apb_wr_32b(0x52bc4, 0xe809c011);
dwc_ddrphy_apb_wr_32b(0x52bc6, 0x70c01600);
dwc_ddrphy_apb_wr_32b(0x52bc8, 0x18000);
dwc_ddrphy_apb_wr_32b(0x52bca, 0x32087f);
dwc_ddrphy_apb_wr_32b(0x52bcc, 0xc21a740c);
dwc_ddrphy_apb_wr_32b(0x52bce, 0x10c0257f);
dwc_ddrphy_apb_wr_32b(0x52bd0, 0x200a6d);
dwc_ddrphy_apb_wr_32b(0x52bd2, 0xc011c052);
dwc_ddrphy_apb_wr_32b(0x52bd4, 0x41c3c140);
dwc_ddrphy_apb_wr_32b(0x52bd6, 0x30032);
dwc_ddrphy_apb_wr_32b(0x52bd8, 0x2078);
dwc_ddrphy_apb_wr_32b(0x52bda, 0x93242e1);
dwc_ddrphy_apb_wr_32b(0x52bdc, 0x43a1fd6f);
dwc_ddrphy_apb_wr_32b(0x52bde, 0x73b5c010);
dwc_ddrphy_apb_wr_32b(0x52be0, 0x2055c29f);
dwc_ddrphy_apb_wr_32b(0x52be2, 0x2f4008c1);
dwc_ddrphy_apb_wr_32b(0x52be4, 0x78251300);
dwc_ddrphy_apb_wr_32b(0x52be6, 0x22920cf);
dwc_ddrphy_apb_wr_32b(0x52be8, 0xc01e791b);
dwc_ddrphy_apb_wr_32b(0x52bea, 0x7825b815);
dwc_ddrphy_apb_wr_32b(0x52bec, 0xf812005);
dwc_ddrphy_apb_wr_32b(0x52bee, 0x9002);
dwc_ddrphy_apb_wr_32b(0x52bf0, 0xc0189160);
dwc_ddrphy_apb_wr_32b(0x52bf2, 0x2233);
dwc_ddrphy_apb_wr_32b(0x52bf4, 0x780e6078);
dwc_ddrphy_apb_wr_32b(0x52bf6, 0x2048);
dwc_ddrphy_apb_wr_32b(0x52bf8, 0x8002049);
dwc_ddrphy_apb_wr_32b(0x52bfa, 0x710cb100);
dwc_ddrphy_apb_wr_32b(0x52bfc, 0xc012c053);
dwc_ddrphy_apb_wr_32b(0x52bfe, 0xf008c05a);
dwc_ddrphy_apb_wr_32b(0x52c00, 0x781cc117);
dwc_ddrphy_apb_wr_32b(0x52c02, 0x20487954);
dwc_ddrphy_apb_wr_32b(0x52c04, 0xb1000000);
dwc_ddrphy_apb_wr_32b(0x52c06, 0x71a571c5);
dwc_ddrphy_apb_wr_32b(0x52c08, 0xc210f199);
dwc_ddrphy_apb_wr_32b(0x52c0a, 0x41c3c141);
dwc_ddrphy_apb_wr_32b(0x52c0c, 0x40031);
dwc_ddrphy_apb_wr_32b(0x52c0e, 0xeba43e1);
dwc_ddrphy_apb_wr_32b(0x52c10, 0xc540fdef);
dwc_ddrphy_apb_wr_32b(0x52c12, 0x78efc212);
dwc_ddrphy_apb_wr_32b(0x52c14, 0xffaf0c6a);
dwc_ddrphy_apb_wr_32b(0x52c16, 0xf1f079af);
dwc_ddrphy_apb_wr_32b(0x52c18, 0xf17c71e5);
dwc_ddrphy_apb_wr_32b(0x52c1a, 0x7014c013);
dwc_ddrphy_apb_wr_32b(0x52c1c, 0xfec20a60);
dwc_ddrphy_apb_wr_32b(0x52c1e, 0x7104c016);
dwc_ddrphy_apb_wr_32b(0x52c20, 0xd933f119);
dwc_ddrphy_apb_wr_32b(0x52c22, 0xe92740c);
dwc_ddrphy_apb_wr_32b(0x52c24, 0xb910fdef);
dwc_ddrphy_apb_wr_32b(0x52c26, 0x700f1600);
dwc_ddrphy_apb_wr_32b(0x52c28, 0x9948000);
dwc_ddrphy_apb_wr_32b(0x52c2a, 0x160070cd);
dwc_ddrphy_apb_wr_32b(0x52c2c, 0x80007000);
dwc_ddrphy_apb_wr_32b(0x52c2e, 0x8750998);
dwc_ddrphy_apb_wr_32b(0x52c30, 0x79d003e2);
dwc_ddrphy_apb_wr_32b(0x52c32, 0x456bc014);
dwc_ddrphy_apb_wr_32b(0x52c34, 0x20006038);
dwc_ddrphy_apb_wr_32b(0x52c36, 0xf8e);
dwc_ddrphy_apb_wr_32b(0x52c38, 0xd5dffff);
dwc_ddrphy_apb_wr_32b(0x52c3a, 0xd0b1253);
dwc_ddrphy_apb_wr_32b(0x52c3c, 0xc00e1211);
dwc_ddrphy_apb_wr_32b(0x52c3e, 0xc110e825);
dwc_ddrphy_apb_wr_32b(0x52c40, 0xd8a78cf);
dwc_ddrphy_apb_wr_32b(0x52c42, 0x792ffdaf);
dwc_ddrphy_apb_wr_32b(0x52c44, 0x78dbe817);
dwc_ddrphy_apb_wr_32b(0x52c46, 0xf812004);
dwc_ddrphy_apb_wr_32b(0x52c48, 0xfffe0001);
dwc_ddrphy_apb_wr_32b(0x52c4a, 0x2035c015);
dwc_ddrphy_apb_wr_32b(0x52c4c, 0xc00f0042);
dwc_ddrphy_apb_wr_32b(0x52c4e, 0x432035);
dwc_ddrphy_apb_wr_32b(0x52c50, 0x2035c017);
dwc_ddrphy_apb_wr_32b(0x52c52, 0x41c30040);
dwc_ddrphy_apb_wr_32b(0x52c54, 0x50035);
dwc_ddrphy_apb_wr_32b(0x52c56, 0xc042c341);
dwc_ddrphy_apb_wr_32b(0x52c58, 0xc240740c);
dwc_ddrphy_apb_wr_32b(0x52c5a, 0x740cf005);
dwc_ddrphy_apb_wr_32b(0x52c5c, 0x3441c3);
dwc_ddrphy_apb_wr_32b(0x52c5e, 0x42e10002);
dwc_ddrphy_apb_wr_32b(0x52c60, 0xfdef0e16);
dwc_ddrphy_apb_wr_32b(0x52c62, 0x71c543a1);
dwc_ddrphy_apb_wr_32b(0x52c64, 0xf1d571a5);
dwc_ddrphy_apb_wr_32b(0x52c66, 0xf1c571e5);
dwc_ddrphy_apb_wr_32b(0x52c68, 0xfe6f0f42);
dwc_ddrphy_apb_wr_32b(0x52c6a, 0x702cc01c);
dwc_ddrphy_apb_wr_32b(0x52c6c, 0x70441e00);
dwc_ddrphy_apb_wr_32b(0x52c6e, 0xe0049003);
dwc_ddrphy_apb_wr_32b(0x52c70, 0xffef0a6a);
dwc_ddrphy_apb_wr_32b(0x52c72, 0x2480c01b);
dwc_ddrphy_apb_wr_32b(0x52c74, 0x14043706);
dwc_ddrphy_apb_wr_32b(0x52c76, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x52c78, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x52c7a, 0x2482b6c8);
dwc_ddrphy_apb_wr_32b(0x52c7c, 0xc1503a03);
dwc_ddrphy_apb_wr_32b(0x52c7e, 0x780f4708);
dwc_ddrphy_apb_wr_32b(0x52c80, 0xc352712c);
dwc_ddrphy_apb_wr_32b(0x52c82, 0xbc64548);
dwc_ddrphy_apb_wr_32b(0x52c84, 0xc054fdef);
dwc_ddrphy_apb_wr_32b(0x52c86, 0x36001440);
dwc_ddrphy_apb_wr_32b(0x52c88, 0x72051e00);
dwc_ddrphy_apb_wr_32b(0x52c8a, 0xe022900f);
dwc_ddrphy_apb_wr_32b(0x52c8c, 0xc056c110);
dwc_ddrphy_apb_wr_32b(0x52c8e, 0x14fcc041);
dwc_ddrphy_apb_wr_32b(0x52c90, 0xc3123000);
dwc_ddrphy_apb_wr_32b(0x52c92, 0xc055704c);
dwc_ddrphy_apb_wr_32b(0x52c94, 0xbcec040);
dwc_ddrphy_apb_wr_32b(0x52c96, 0x40e1ffef);
dwc_ddrphy_apb_wr_32b(0x52c98, 0xb9ac014);
dwc_ddrphy_apb_wr_32b(0x52c9a, 0x702cfdef);
dwc_ddrphy_apb_wr_32b(0x52c9c, 0x43db70b5);
dwc_ddrphy_apb_wr_32b(0x52c9e, 0x9948000);
dwc_ddrphy_apb_wr_32b(0x52ca0, 0x4167f28f);
dwc_ddrphy_apb_wr_32b(0x52ca2, 0x422116);
dwc_ddrphy_apb_wr_32b(0x52ca4, 0x849406f);
dwc_ddrphy_apb_wr_32b(0x52ca6, 0x750c0062);
dwc_ddrphy_apb_wr_32b(0x52ca8, 0x4348706c);
dwc_ddrphy_apb_wr_32b(0x52caa, 0x2150b37);
dwc_ddrphy_apb_wr_32b(0x52cac, 0x20f5c012);
dwc_ddrphy_apb_wr_32b(0x52cae, 0x716502cd);
dwc_ddrphy_apb_wr_32b(0x52cb0, 0xb83b6d1c);
dwc_ddrphy_apb_wr_32b(0x52cb2, 0xbcc4651c);
dwc_ddrphy_apb_wr_32b(0x52cb4, 0x2d447c02);
dwc_ddrphy_apb_wr_32b(0x52cb6, 0x2b401800);
dwc_ddrphy_apb_wr_32b(0x52cb8, 0x7164024d);
dwc_ddrphy_apb_wr_32b(0x52cba, 0x7c05b80a);
dwc_ddrphy_apb_wr_32b(0x52cbc, 0x3402940);
dwc_ddrphy_apb_wr_32b(0x52cbe, 0x200578a5);
dwc_ddrphy_apb_wr_32b(0x52cc0, 0x90020f80);
dwc_ddrphy_apb_wr_32b(0x52cc2, 0xb0800064);
dwc_ddrphy_apb_wr_32b(0x52cc4, 0x7124f1e6);
dwc_ddrphy_apb_wr_32b(0x52cc6, 0xf1dee209);
dwc_ddrphy_apb_wr_32b(0x52cc8, 0xfe0f0aee);
dwc_ddrphy_apb_wr_32b(0x52cca, 0xf49ab8eb);
dwc_ddrphy_apb_wr_32b(0x52ccc, 0xb32c014);
dwc_ddrphy_apb_wr_32b(0x52cce, 0x712cfdef);
dwc_ddrphy_apb_wr_32b(0x52cd0, 0xfdef0cb2);
dwc_ddrphy_apb_wr_32b(0x52cd2, 0x40e1700c);
dwc_ddrphy_apb_wr_32b(0x52cd4, 0xfdef0c5e);
dwc_ddrphy_apb_wr_32b(0x52cd6, 0xc058702c);
dwc_ddrphy_apb_wr_32b(0x52cd8, 0x800041c3);
dwc_ddrphy_apb_wr_32b(0x52cda, 0x2455066e);
dwc_ddrphy_apb_wr_32b(0x52cdc, 0xeca38c0);
dwc_ddrphy_apb_wr_32b(0x52cde, 0xda5afd2f);
dwc_ddrphy_apb_wr_32b(0x52ce0, 0x38c02455);
dwc_ddrphy_apb_wr_32b(0x52ce2, 0x600ffa);
dwc_ddrphy_apb_wr_32b(0x52ce4, 0xd8ffd95a);
dwc_ddrphy_apb_wr_32b(0x52ce6, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x52ce8, 0xf0c49003);
dwc_ddrphy_apb_wr_32b(0x52cea, 0x22164267);
dwc_ddrphy_apb_wr_32b(0x52cec, 0x406f0083);
dwc_ddrphy_apb_wr_32b(0x52cee, 0x721070cd);
dwc_ddrphy_apb_wr_32b(0x52cf0, 0x290106);
dwc_ddrphy_apb_wr_32b(0x52cf2, 0xc118710c);
dwc_ddrphy_apb_wr_32b(0x52cf4, 0xcda784f);
dwc_ddrphy_apb_wr_32b(0x52cf6, 0x792ffdef);
dwc_ddrphy_apb_wr_32b(0x52cf8, 0x41c3e82e);
dwc_ddrphy_apb_wr_32b(0x52cfa, 0x7fff0000);
dwc_ddrphy_apb_wr_32b(0x52cfc, 0x44686901);
dwc_ddrphy_apb_wr_32b(0x52cfe, 0x12350e1b);
dwc_ddrphy_apb_wr_32b(0x52d00, 0xc0127d0e);
dwc_ddrphy_apb_wr_32b(0x52d02, 0x20f571c5);
dwc_ddrphy_apb_wr_32b(0x52d04, 0x71850300);
dwc_ddrphy_apb_wr_32b(0x52d06, 0x12109);
dwc_ddrphy_apb_wr_32b(0x52d08, 0x3402008);
dwc_ddrphy_apb_wr_32b(0x52d0a, 0x61b8f1f4);
dwc_ddrphy_apb_wr_32b(0x52d0c, 0x8c2844);
dwc_ddrphy_apb_wr_32b(0x52d0e, 0x691c798e);
dwc_ddrphy_apb_wr_32b(0x52d10, 0x8012944);
dwc_ddrphy_apb_wr_32b(0x52d12, 0x641db83b);
dwc_ddrphy_apb_wr_32b(0x52d14, 0x4d10bdc4);
dwc_ddrphy_apb_wr_32b(0x52d16, 0x7905b90a);
dwc_ddrphy_apb_wr_32b(0x52d18, 0x3402a40);
dwc_ddrphy_apb_wr_32b(0x52d1a, 0xf802005);
dwc_ddrphy_apb_wr_32b(0x52d1c, 0x10649002);
dwc_ddrphy_apb_wr_32b(0x52d1e, 0xc099b020);
dwc_ddrphy_apb_wr_32b(0x52d20, 0xb0807854);
dwc_ddrphy_apb_wr_32b(0x52d22, 0x7854c09e);
dwc_ddrphy_apb_wr_32b(0x52d24, 0xf008b020);
dwc_ddrphy_apb_wr_32b(0x52d26, 0x7854c099);
dwc_ddrphy_apb_wr_32b(0x52d28, 0xc09eb0c0);
dwc_ddrphy_apb_wr_32b(0x52d2a, 0xb0c07854);
dwc_ddrphy_apb_wr_32b(0x52d2c, 0xe3097144);
dwc_ddrphy_apb_wr_32b(0x52d2e, 0x40e1f1bf);
dwc_ddrphy_apb_wr_32b(0x52d30, 0xfdef0ba6);
dwc_ddrphy_apb_wr_32b(0x52d32, 0x1300702c);
dwc_ddrphy_apb_wr_32b(0x52d34, 0xc044300e);
dwc_ddrphy_apb_wr_32b(0x52d36, 0x138f2616);
dwc_ddrphy_apb_wr_32b(0x52d38, 0x7610406f);
dwc_ddrphy_apb_wr_32b(0x52d3a, 0x290308);
dwc_ddrphy_apb_wr_32b(0x52d3c, 0x4568706c);
dwc_ddrphy_apb_wr_32b(0x52d3e, 0x2542bd8f);
dwc_ddrphy_apb_wr_32b(0x52d40, 0x43e9105e);
dwc_ddrphy_apb_wr_32b(0x52d42, 0x2350b2f);
dwc_ddrphy_apb_wr_32b(0x52d44, 0xc20478ae);
dwc_ddrphy_apb_wr_32b(0x52d46, 0x796f78cf);
dwc_ddrphy_apb_wr_32b(0x52d48, 0xff6f0c36);
dwc_ddrphy_apb_wr_32b(0x52d4a, 0xe80c7a4f);
dwc_ddrphy_apb_wr_32b(0x52d4c, 0x79aec012);
dwc_ddrphy_apb_wr_32b(0x52d4e, 0x2c020f5);
dwc_ddrphy_apb_wr_32b(0x52d50, 0x4d2008);
dwc_ddrphy_apb_wr_32b(0x52d52, 0x8780200c);
dwc_ddrphy_apb_wr_32b(0x52d54, 0x300b26ca);
dwc_ddrphy_apb_wr_32b(0x52d56, 0x71647165);
dwc_ddrphy_apb_wr_32b(0x52d58, 0x2000f1ea);
dwc_ddrphy_apb_wr_32b(0x52d5a, 0x28440780);
dwc_ddrphy_apb_wr_32b(0x52d5c, 0xc1120080);
dwc_ddrphy_apb_wr_32b(0x52d5e, 0xe70971c5);
dwc_ddrphy_apb_wr_32b(0x52d60, 0x2c12114);
dwc_ddrphy_apb_wr_32b(0x52d62, 0xf1d6b100);
dwc_ddrphy_apb_wr_32b(0x52d64, 0xfdef0b8a);
dwc_ddrphy_apb_wr_32b(0x52d66, 0xc016700c);
dwc_ddrphy_apb_wr_32b(0x52d68, 0xc312c110);
dwc_ddrphy_apb_wr_32b(0x52d6a, 0xc015c041);
dwc_ddrphy_apb_wr_32b(0x52d6c, 0xc040714c);
dwc_ddrphy_apb_wr_32b(0x52d6e, 0xffef0a1a);
dwc_ddrphy_apb_wr_32b(0x52d70, 0x29940e1);
dwc_ddrphy_apb_wr_32b(0x52d72, 0xa420000);
dwc_ddrphy_apb_wr_32b(0x52d74, 0xd9ffffaf);
dwc_ddrphy_apb_wr_32b(0x52d76, 0xfc7218a);
dwc_ddrphy_apb_wr_32b(0x52d78, 0x900340c3);
dwc_ddrphy_apb_wr_32b(0x52d7a, 0xb020e174);
dwc_ddrphy_apb_wr_32b(0x52d7c, 0xa4ab021);
dwc_ddrphy_apb_wr_32b(0x52d7e, 0x712cfd8f);
dwc_ddrphy_apb_wr_32b(0x52d80, 0xb98ed8ff);
dwc_ddrphy_apb_wr_32b(0x52d82, 0xc643754c);
dwc_ddrphy_apb_wr_32b(0x52d84, 0xc641c642);
dwc_ddrphy_apb_wr_32b(0x52d86, 0xfdaf0bfe);
dwc_ddrphy_apb_wr_32b(0x52d88, 0x710cc640);
dwc_ddrphy_apb_wr_32b(0x52d8a, 0x780f78f8);
dwc_ddrphy_apb_wr_32b(0x52d8c, 0xc057d911);
dwc_ddrphy_apb_wr_32b(0x52d8e, 0xd8ffc042);
dwc_ddrphy_apb_wr_32b(0x52d90, 0x704cb90a);
dwc_ddrphy_apb_wr_32b(0x52d92, 0x1c0cdb7c);
dwc_ddrphy_apb_wr_32b(0x52d94, 0xc6413041);
dwc_ddrphy_apb_wr_32b(0x52d96, 0xfdaf0bde);
dwc_ddrphy_apb_wr_32b(0x52d98, 0x8fac640);
dwc_ddrphy_apb_wr_32b(0x52d9a, 0xc643fd8f);
dwc_ddrphy_apb_wr_32b(0x52d9c, 0xc641c642);
dwc_ddrphy_apb_wr_32b(0x52d9e, 0xfdaf0bce);
dwc_ddrphy_apb_wr_32b(0x52da0, 0x8cac640);
dwc_ddrphy_apb_wr_32b(0x52da2, 0x120bfd8f);
dwc_ddrphy_apb_wr_32b(0x52da4, 0xa423081);
dwc_ddrphy_apb_wr_32b(0x52da6, 0x40e10020);
dwc_ddrphy_apb_wr_32b(0x52da8, 0x14550edd);
dwc_ddrphy_apb_wr_32b(0x52daa, 0xbe6);
dwc_ddrphy_apb_wr_32b(0x52dac, 0x300d1300);
dwc_ddrphy_apb_wr_32b(0x52dae, 0xc053700c);
dwc_ddrphy_apb_wr_32b(0x52db0, 0x8c5406f);
dwc_ddrphy_apb_wr_32b(0x52db2, 0x78af0362);
dwc_ddrphy_apb_wr_32b(0x52db4, 0xc018c051);
dwc_ddrphy_apb_wr_32b(0x52db6, 0xc044780f);
dwc_ddrphy_apb_wr_32b(0x52db8, 0xb52c011);
dwc_ddrphy_apb_wr_32b(0x52dba, 0xc104fdef);
dwc_ddrphy_apb_wr_32b(0x52dbc, 0x3008a9);
dwc_ddrphy_apb_wr_32b(0x52dbe, 0x702c704c);
dwc_ddrphy_apb_wr_32b(0x52dc0, 0x2350a19);
dwc_ddrphy_apb_wr_32b(0x52dc2, 0x2432a40);
dwc_ddrphy_apb_wr_32b(0x52dc4, 0x13402d40);
dwc_ddrphy_apb_wr_32b(0x52dc6, 0x8ea7865);
dwc_ddrphy_apb_wr_32b(0x52dc8, 0x7144fd8f);
dwc_ddrphy_apb_wr_32b(0x52dca, 0xf1f66119);
dwc_ddrphy_apb_wr_32b(0x52dcc, 0x6038c013);
dwc_ddrphy_apb_wr_32b(0x52dce, 0x300985);
dwc_ddrphy_apb_wr_32b(0x52dd0, 0xe25c053);
dwc_ddrphy_apb_wr_32b(0x52dd2, 0x16001411);
dwc_ddrphy_apb_wr_32b(0x52dd4, 0x800070c0);
dwc_ddrphy_apb_wr_32b(0x52dd6, 0x8550001);
dwc_ddrphy_apb_wr_32b(0x52dd8, 0x740c0032);
dwc_ddrphy_apb_wr_32b(0x52dda, 0x41c3700c);
dwc_ddrphy_apb_wr_32b(0x52ddc, 0x1003a);
dwc_ddrphy_apb_wr_32b(0x52dde, 0xfd2f0d2a);
dwc_ddrphy_apb_wr_32b(0x52de0, 0xf03042a1);
dwc_ddrphy_apb_wr_32b(0x52de2, 0x800040c3);
dwc_ddrphy_apb_wr_32b(0x52de4, 0x20f505f4);
dwc_ddrphy_apb_wr_32b(0x52de6, 0xc0990381);
dwc_ddrphy_apb_wr_32b(0x52de8, 0x34020f4);
dwc_ddrphy_apb_wr_32b(0x52dea, 0x20486038);
dwc_ddrphy_apb_wr_32b(0x52dec, 0x20890000);
dwc_ddrphy_apb_wr_32b(0x52dee, 0x68350fc3);
dwc_ddrphy_apb_wr_32b(0x52df0, 0x20047825);
dwc_ddrphy_apb_wr_32b(0x52df2, 0xf81);
dwc_ddrphy_apb_wr_32b(0x52df4, 0x2d401c1f);
dwc_ddrphy_apb_wr_32b(0x52df6, 0x20051340);
dwc_ddrphy_apb_wr_32b(0x52df8, 0x90020f80);
dwc_ddrphy_apb_wr_32b(0x52dfa, 0xb0201064);
dwc_ddrphy_apb_wr_32b(0x52dfc, 0x78b4c09e);
dwc_ddrphy_apb_wr_32b(0x52dfe, 0xf012b020);
dwc_ddrphy_apb_wr_32b(0x52e00, 0x3941c3);
dwc_ddrphy_apb_wr_32b(0x52e02, 0x42e10002);
dwc_ddrphy_apb_wr_32b(0x52e04, 0xfdef0ace);
dwc_ddrphy_apb_wr_32b(0x52e06, 0xc01143a1);
dwc_ddrphy_apb_wr_32b(0x52e08, 0x862c204);
dwc_ddrphy_apb_wr_32b(0x52e0a, 0x702cffaf);
dwc_ddrphy_apb_wr_32b(0x52e0c, 0x85ac011);
dwc_ddrphy_apb_wr_32b(0x52e0e, 0x712cffaf);
dwc_ddrphy_apb_wr_32b(0x52e10, 0xf1a071a5);
dwc_ddrphy_apb_wr_32b(0x52e12, 0x82dc013);
dwc_ddrphy_apb_wr_32b(0x52e14, 0x71c58031);
dwc_ddrphy_apb_wr_32b(0x52e16, 0xc04ed8ff);
dwc_ddrphy_apb_wr_32b(0x52e18, 0xb88b700c);
dwc_ddrphy_apb_wr_32b(0x52e1a, 0xd840c04d);
dwc_ddrphy_apb_wr_32b(0x52e1c, 0xc010c04c);
dwc_ddrphy_apb_wr_32b(0x52e1e, 0xc16f702c);
dwc_ddrphy_apb_wr_32b(0x52e20, 0xc016c04a);
dwc_ddrphy_apb_wr_32b(0x52e22, 0xc148c169);
dwc_ddrphy_apb_wr_32b(0x52e24, 0xc015c047);
dwc_ddrphy_apb_wr_32b(0x52e26, 0x714cc19e);
dwc_ddrphy_apb_wr_32b(0x52e28, 0xc085c046);
dwc_ddrphy_apb_wr_32b(0x52e2a, 0x98ac745);
dwc_ddrphy_apb_wr_32b(0x52e2c, 0x1c2cfe2f);
dwc_ddrphy_apb_wr_32b(0x52e2e, 0xc0853085);
dwc_ddrphy_apb_wr_32b(0x52e30, 0x97ec19e);
dwc_ddrphy_apb_wr_32b(0x52e32, 0x704cfe2f);
dwc_ddrphy_apb_wr_32b(0x52e34, 0x1300c017);
dwc_ddrphy_apb_wr_32b(0x52e36, 0xba6300e);
dwc_ddrphy_apb_wr_32b(0x52e38, 0x1304fe6f);
dwc_ddrphy_apb_wr_32b(0x52e3a, 0xd93b300d);
dwc_ddrphy_apb_wr_32b(0x52e3c, 0xa5e740c);
dwc_ddrphy_apb_wr_32b(0x52e3e, 0xb910fdef);
dwc_ddrphy_apb_wr_32b(0x52e40, 0x13402516);
dwc_ddrphy_apb_wr_32b(0x52e42, 0x1300e008);
dwc_ddrphy_apb_wr_32b(0x52e44, 0xc057300d);
dwc_ddrphy_apb_wr_32b(0x52e46, 0x13802616);
dwc_ddrphy_apb_wr_32b(0x52e48, 0xc044e008);
dwc_ddrphy_apb_wr_32b(0x52e4a, 0xc004c117);
dwc_ddrphy_apb_wr_32b(0x52e4c, 0x2209cb);
dwc_ddrphy_apb_wr_32b(0x52e4e, 0x78af702c);
dwc_ddrphy_apb_wr_32b(0x52e50, 0xc018c050);
dwc_ddrphy_apb_wr_32b(0x52e52, 0xc053780f);
dwc_ddrphy_apb_wr_32b(0x52e54, 0xa1ac010);
dwc_ddrphy_apb_wr_32b(0x52e56, 0xc113fdef);
dwc_ddrphy_apb_wr_32b(0x52e58, 0xc115e835);
dwc_ddrphy_apb_wr_32b(0x52e5a, 0xc212c004);
dwc_ddrphy_apb_wr_32b(0x52e5c, 0x21f5);
dwc_ddrphy_apb_wr_32b(0x52e5e, 0xc051c116);
dwc_ddrphy_apb_wr_32b(0x52e60, 0x21f5c004);
dwc_ddrphy_apb_wr_32b(0x52e62, 0xc011000e);
dwc_ddrphy_apb_wr_32b(0x52e64, 0x791c60d8);
dwc_ddrphy_apb_wr_32b(0x52e66, 0x2148c004);
dwc_ddrphy_apb_wr_32b(0x52e68, 0x7a140003);
dwc_ddrphy_apb_wr_32b(0x52e6a, 0xb260c011);
dwc_ddrphy_apb_wr_32b(0x52e6c, 0xc040c142);
dwc_ddrphy_apb_wr_32b(0x52e6e, 0x41c3740c);
dwc_ddrphy_apb_wr_32b(0x52e70, 0x5003d);
dwc_ddrphy_apb_wr_32b(0x52e72, 0xdb0842a1);
dwc_ddrphy_apb_wr_32b(0x52e74, 0xfdef09ee);
dwc_ddrphy_apb_wr_32b(0x52e76, 0xc011c641);
dwc_ddrphy_apb_wr_32b(0x52e78, 0x70c11600);
dwc_ddrphy_apb_wr_32b(0x52e7a, 0x18000);
dwc_ddrphy_apb_wr_32b(0x52e7c, 0x20484e10);
dwc_ddrphy_apb_wr_32b(0x52e7e, 0x9310000);
dwc_ddrphy_apb_wr_32b(0x52e80, 0x780e0032);
dwc_ddrphy_apb_wr_32b(0x52e82, 0x207fc040);
dwc_ddrphy_apb_wr_32b(0x52e84, 0x41c30140);
dwc_ddrphy_apb_wr_32b(0x52e86, 0x3003f);
dwc_ddrphy_apb_wr_32b(0x52e88, 0xbd642a1);
dwc_ddrphy_apb_wr_32b(0x52e8a, 0xdb08fd2f);
dwc_ddrphy_apb_wr_32b(0x52e8c, 0x740cf020);
dwc_ddrphy_apb_wr_32b(0x52e8e, 0x3c41c3);
dwc_ddrphy_apb_wr_32b(0x52e90, 0x42a10002);
dwc_ddrphy_apb_wr_32b(0x52e92, 0xfdef09b2);
dwc_ddrphy_apb_wr_32b(0x52e94, 0xf018db08);
dwc_ddrphy_apb_wr_32b(0x52e96, 0x1b3082d);
dwc_ddrphy_apb_wr_32b(0x52e98, 0xc04142e1);
dwc_ddrphy_apb_wr_32b(0x52e9a, 0x41c3740c);
dwc_ddrphy_apb_wr_32b(0x52e9c, 0x4003e);
dwc_ddrphy_apb_wr_32b(0x52e9e, 0x99a43a1);
dwc_ddrphy_apb_wr_32b(0x52ea0, 0x1c00fdef);
dwc_ddrphy_apb_wr_32b(0x52ea2, 0xc0103201);
dwc_ddrphy_apb_wr_32b(0x52ea4, 0xf2ac213);
dwc_ddrphy_apb_wr_32b(0x52ea6, 0x702cff6f);
dwc_ddrphy_apb_wr_32b(0x52ea8, 0xf22c010);
dwc_ddrphy_apb_wr_32b(0x52eaa, 0x712cff6f);
dwc_ddrphy_apb_wr_32b(0x52eac, 0x71a5c004);
dwc_ddrphy_apb_wr_32b(0x52eae, 0xc044e009);
dwc_ddrphy_apb_wr_32b(0x52eb0, 0x1e00f19a);
dwc_ddrphy_apb_wr_32b(0x52eb2, 0x900f7205);
dwc_ddrphy_apb_wr_32b(0x52eb4, 0x1e00e022);
dwc_ddrphy_apb_wr_32b(0x52eb6, 0x90037005);
dwc_ddrphy_apb_wr_32b(0x52eb8, 0xf5ae004);
dwc_ddrphy_apb_wr_32b(0x52eba, 0xc014fdaf);
dwc_ddrphy_apb_wr_32b(0x52ebc, 0xfdcf08b6);
dwc_ddrphy_apb_wr_32b(0x52ebe, 0x3a032480);
dwc_ddrphy_apb_wr_32b(0x52ec0, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x52ec2, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x52ec4, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x52ec6, 0xc1a8b6c8);
dwc_ddrphy_apb_wr_32b(0x52ec8, 0xe4a4338);
dwc_ddrphy_apb_wr_32b(0x52eca, 0x4608fdef);
dwc_ddrphy_apb_wr_32b(0x52ecc, 0xfdef0eae);
dwc_ddrphy_apb_wr_32b(0x52ece, 0xebac045);
dwc_ddrphy_apb_wr_32b(0x52ed0, 0xc047fdef);
dwc_ddrphy_apb_wr_32b(0x52ed2, 0xc005c044);
dwc_ddrphy_apb_wr_32b(0x52ed4, 0x88a790f);
dwc_ddrphy_apb_wr_32b(0x52ed6, 0x700cfdaf);
dwc_ddrphy_apb_wr_32b(0x52ed8, 0x70001600);
dwc_ddrphy_apb_wr_32b(0x52eda, 0x9848000);
dwc_ddrphy_apb_wr_32b(0x52edc, 0x30831200);
dwc_ddrphy_apb_wr_32b(0x52ede, 0x70c3702c);
dwc_ddrphy_apb_wr_32b(0x52ee0, 0x5608000);
dwc_ddrphy_apb_wr_32b(0x52ee2, 0xd8ffa820);
dwc_ddrphy_apb_wr_32b(0x52ee4, 0x4528754c);
dwc_ddrphy_apb_wr_32b(0x52ee6, 0xc142c143);
dwc_ddrphy_apb_wr_32b(0x52ee8, 0x93ac141);
dwc_ddrphy_apb_wr_32b(0x52eea, 0xc140fdaf);
dwc_ddrphy_apb_wr_32b(0x52eec, 0xbf8e70ed);
dwc_ddrphy_apb_wr_32b(0x52eee, 0x41e1d8ff);
dwc_ddrphy_apb_wr_32b(0x52ef0, 0x726c754c);
dwc_ddrphy_apb_wr_32b(0x52ef2, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x52ef4, 0x922c541);
dwc_ddrphy_apb_wr_32b(0x52ef6, 0xc540fdaf);
dwc_ddrphy_apb_wr_32b(0x52ef8, 0x6c7202f);
dwc_ddrphy_apb_wr_32b(0x52efa, 0xc043c046);
dwc_ddrphy_apb_wr_32b(0x52efc, 0x78d8710c);
dwc_ddrphy_apb_wr_32b(0x52efe, 0xd8ff7e0f);
dwc_ddrphy_apb_wr_32b(0x52f00, 0x41c3);
dwc_ddrphy_apb_wr_32b(0x52f02, 0x724c7500);
dwc_ddrphy_apb_wr_32b(0x52f04, 0xc642746c);
dwc_ddrphy_apb_wr_32b(0x52f06, 0x1c00c541);
dwc_ddrphy_apb_wr_32b(0x52f08, 0x3f80);
dwc_ddrphy_apb_wr_32b(0x52f0a, 0x8f61000);
dwc_ddrphy_apb_wr_32b(0x52f0c, 0x4338fdaf);
dwc_ddrphy_apb_wr_32b(0x52f0e, 0x754cc004);
dwc_ddrphy_apb_wr_32b(0x52f10, 0xe010c543);
dwc_ddrphy_apb_wr_32b(0x52f12, 0x412044);
dwc_ddrphy_apb_wr_32b(0x52f14, 0xc542c004);
dwc_ddrphy_apb_wr_32b(0x52f16, 0x6038c541);
dwc_ddrphy_apb_wr_32b(0x52f18, 0x780fe010);
dwc_ddrphy_apb_wr_32b(0x52f1a, 0xc304c044);
dwc_ddrphy_apb_wr_32b(0x52f1c, 0xd980d8ff);
dwc_ddrphy_apb_wr_32b(0x52f1e, 0xfdaf08ce);
dwc_ddrphy_apb_wr_32b(0x52f20, 0x1600c540);
dwc_ddrphy_apb_wr_32b(0x52f22, 0x80007001);
dwc_ddrphy_apb_wr_32b(0x52f24, 0x12000984);
dwc_ddrphy_apb_wr_32b(0x52f26, 0x754c3083);
dwc_ddrphy_apb_wr_32b(0x52f28, 0x800071c3);
dwc_ddrphy_apb_wr_32b(0x52f2a, 0xa9010560);
dwc_ddrphy_apb_wr_32b(0x52f2c, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x52f2e, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x52f30, 0x8aac541);
dwc_ddrphy_apb_wr_32b(0x52f32, 0xc540fdaf);
dwc_ddrphy_apb_wr_32b(0x52f34, 0x41e1d8ff);
dwc_ddrphy_apb_wr_32b(0x52f36, 0x726c754c);
dwc_ddrphy_apb_wr_32b(0x52f38, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x52f3a, 0x896c541);
dwc_ddrphy_apb_wr_32b(0x52f3c, 0xc540fdaf);
dwc_ddrphy_apb_wr_32b(0x52f3e, 0x4163c006);
dwc_ddrphy_apb_wr_32b(0x52f40, 0xc043724c);
dwc_ddrphy_apb_wr_32b(0x52f42, 0xc642d8ff);
dwc_ddrphy_apb_wr_32b(0x52f44, 0x1c00c541);
dwc_ddrphy_apb_wr_32b(0x52f46, 0x3f80);
dwc_ddrphy_apb_wr_32b(0x52f48, 0x87a1000);
dwc_ddrphy_apb_wr_32b(0x52f4a, 0x746cfdaf);
dwc_ddrphy_apb_wr_32b(0x52f4c, 0xd8ffc304);
dwc_ddrphy_apb_wr_32b(0x52f4e, 0x754c41e1);
dwc_ddrphy_apb_wr_32b(0x52f50, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x52f52, 0x866c541);
dwc_ddrphy_apb_wr_32b(0x52f54, 0xc540fdaf);
dwc_ddrphy_apb_wr_32b(0x52f56, 0xfdef0b26);
dwc_ddrphy_apb_wr_32b(0x52f58, 0xc00640c1);
dwc_ddrphy_apb_wr_32b(0x52f5a, 0x33012350);
dwc_ddrphy_apb_wr_32b(0x52f5c, 0xc043714c);
dwc_ddrphy_apb_wr_32b(0x52f5e, 0xc642d8ff);
dwc_ddrphy_apb_wr_32b(0x52f60, 0x1c00c541);
dwc_ddrphy_apb_wr_32b(0x52f62, 0x3f80);
dwc_ddrphy_apb_wr_32b(0x52f64, 0x8421000);
dwc_ddrphy_apb_wr_32b(0x52f66, 0x746cfdaf);
dwc_ddrphy_apb_wr_32b(0x52f68, 0xfdef0ac6);
dwc_ddrphy_apb_wr_32b(0x52f6a, 0xc10540c1);
dwc_ddrphy_apb_wr_32b(0x52f6c, 0x754cc007);
dwc_ddrphy_apb_wr_32b(0x52f6e, 0x2014c543);
dwc_ddrphy_apb_wr_32b(0x52f70, 0x49580041);
dwc_ddrphy_apb_wr_32b(0x52f72, 0x6038b8c0);
dwc_ddrphy_apb_wr_32b(0x52f74, 0x7b0fe028);
dwc_ddrphy_apb_wr_32b(0x52f76, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x52f78, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x52f7a, 0xfdaf0816);
dwc_ddrphy_apb_wr_32b(0x52f7c, 0x79fbc540);
dwc_ddrphy_apb_wr_32b(0x52f7e, 0xfd4f0e2e);
dwc_ddrphy_apb_wr_32b(0x52f80, 0x30c11c0c);
dwc_ddrphy_apb_wr_32b(0x52f82, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x52f84, 0xfdaf0802);
dwc_ddrphy_apb_wr_32b(0x52f86, 0xe12c540);
dwc_ddrphy_apb_wr_32b(0x52f88, 0xc543fd4f);
dwc_ddrphy_apb_wr_32b(0x52f8a, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x52f8c, 0xfd6f0ff2);
dwc_ddrphy_apb_wr_32b(0x52f8e, 0xd0ec540);
dwc_ddrphy_apb_wr_32b(0x52f90, 0xc543fd4f);
dwc_ddrphy_apb_wr_32b(0x52f92, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x52f94, 0xfd6f0fe2);
dwc_ddrphy_apb_wr_32b(0x52f96, 0xc0a8c540);
dwc_ddrphy_apb_wr_32b(0x52f98, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x52f9a, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x52f9c, 0x1cfcc2e4);
dwc_ddrphy_apb_wr_32b(0x52f9e, 0x45cbb6c8);
dwc_ddrphy_apb_wr_32b(0x52fa0, 0xcccc0000);
dwc_ddrphy_apb_wr_32b(0x52fa2, 0x41a1d80f);
dwc_ddrphy_apb_wr_32b(0x52fa4, 0x706c42a1);
dwc_ddrphy_apb_wr_32b(0x52fa6, 0xfdef0e3a);
dwc_ddrphy_apb_wr_32b(0x52fa8, 0xb0091cfc);
dwc_ddrphy_apb_wr_32b(0x52faa, 0x46cb);
dwc_ddrphy_apb_wr_32b(0x52fac, 0xd808ffff);
dwc_ddrphy_apb_wr_32b(0x52fae, 0x42c141c1);
dwc_ddrphy_apb_wr_32b(0x52fb0, 0xe26706c);
dwc_ddrphy_apb_wr_32b(0x52fb2, 0x1c00fdef);
dwc_ddrphy_apb_wr_32b(0x52fb4, 0x16003001);
dwc_ddrphy_apb_wr_32b(0x52fb6, 0x80007000);
dwc_ddrphy_apb_wr_32b(0x52fb8, 0x43db0984);
dwc_ddrphy_apb_wr_32b(0x52fba, 0x5608000);
dwc_ddrphy_apb_wr_32b(0x52fbc, 0xfdaf0a8a);
dwc_ddrphy_apb_wr_32b(0x52fbe, 0x6c02032);
dwc_ddrphy_apb_wr_32b(0x52fc0, 0xfd4f0c8a);
dwc_ddrphy_apb_wr_32b(0x52fc2, 0x10812d41);
dwc_ddrphy_apb_wr_32b(0x52fc4, 0x43c3);
dwc_ddrphy_apb_wr_32b(0x52fc6, 0xd80f9999);
dwc_ddrphy_apb_wr_32b(0x52fc8, 0xdf64220);
dwc_ddrphy_apb_wr_32b(0x52fca, 0xc340fdef);
dwc_ddrphy_apb_wr_32b(0x52fcc, 0x41c3);
dwc_ddrphy_apb_wr_32b(0x52fce, 0xd8085555);
dwc_ddrphy_apb_wr_32b(0x52fd0, 0x43c14220);
dwc_ddrphy_apb_wr_32b(0x52fd2, 0xfdef0de2);
dwc_ddrphy_apb_wr_32b(0x52fd4, 0x1600c640);
dwc_ddrphy_apb_wr_32b(0x52fd6, 0x80007000);
dwc_ddrphy_apb_wr_32b(0x52fd8, 0x23000984);
dwc_ddrphy_apb_wr_32b(0x52fda, 0xa4e3001);
dwc_ddrphy_apb_wr_32b(0x52fdc, 0x8901fdaf);
dwc_ddrphy_apb_wr_32b(0x52fde, 0xe0ad80f);
dwc_ddrphy_apb_wr_32b(0x52fe0, 0xd90ffdaf);
dwc_ddrphy_apb_wr_32b(0x52fe2, 0xfd4f0c46);
dwc_ddrphy_apb_wr_32b(0x52fe4, 0x14047487);
dwc_ddrphy_apb_wr_32b(0x52fe6, 0xc6c4341b);
dwc_ddrphy_apb_wr_32b(0x52fe8, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x52fea, 0xc1adb6c8);
dwc_ddrphy_apb_wr_32b(0x52fec, 0x710c4508);
dwc_ddrphy_apb_wr_32b(0x52fee, 0xc04778b8);
dwc_ddrphy_apb_wr_32b(0x52ff0, 0xc2449101);
dwc_ddrphy_apb_wr_32b(0x52ff2, 0x800043db);
dwc_ddrphy_apb_wr_32b(0x52ff4, 0xb887086c);
dwc_ddrphy_apb_wr_32b(0x52ff6, 0xc004c046);
dwc_ddrphy_apb_wr_32b(0x52ff8, 0x132ae887);
dwc_ddrphy_apb_wr_32b(0x52ffa, 0xbe23100);
dwc_ddrphy_apb_wr_32b(0x52ffc, 0x41a1ffaf);
dwc_ddrphy_apb_wr_32b(0x52ffe, 0xd97ec046);
dwc_ddrphy_apb_wr_32b(0x53000, 0x6528b99f);
dwc_ddrphy_apb_wr_32b(0x53002, 0x310d132c);
dwc_ddrphy_apb_wr_32b(0x53004, 0x1192c04b);
dwc_ddrphy_apb_wr_32b(0x53006, 0xd9ff8080);
dwc_ddrphy_apb_wr_32b(0x53008, 0xe22c049);
dwc_ddrphy_apb_wr_32b(0x5300a, 0x700cfd6f);
dwc_ddrphy_apb_wr_32b(0x5300c, 0x30831200);
dwc_ddrphy_apb_wr_32b(0x5300e, 0xcd670ed);
dwc_ddrphy_apb_wr_32b(0x53010, 0xc743fd4f);
dwc_ddrphy_apb_wr_32b(0x53012, 0xc741c742);
dwc_ddrphy_apb_wr_32b(0x53014, 0xfd6f0ee2);
dwc_ddrphy_apb_wr_32b(0x53016, 0xc107c740);
dwc_ddrphy_apb_wr_32b(0x53018, 0x7826c009);
dwc_ddrphy_apb_wr_32b(0x5301a, 0x2504c048);
dwc_ddrphy_apb_wr_32b(0x5301c, 0xffff1f80);
dwc_ddrphy_apb_wr_32b(0x5301e, 0xc04af1ff);
dwc_ddrphy_apb_wr_32b(0x53020, 0x11350fe7);
dwc_ddrphy_apb_wr_32b(0x53022, 0xc104710c);
dwc_ddrphy_apb_wr_32b(0x53024, 0x3ce2800);
dwc_ddrphy_apb_wr_32b(0x53026, 0x3100132a);
dwc_ddrphy_apb_wr_32b(0x53028, 0x79ef7034);
dwc_ddrphy_apb_wr_32b(0x5302a, 0xf8220c5);
dwc_ddrphy_apb_wr_32b(0x5302c, 0x10800000);
dwc_ddrphy_apb_wr_32b(0x5302e, 0xffaf0b7a);
dwc_ddrphy_apb_wr_32b(0x53030, 0xc045c14c);
dwc_ddrphy_apb_wr_32b(0x53032, 0x839c009);
dwc_ddrphy_apb_wr_32b(0x53034, 0xc00403ce);
dwc_ddrphy_apb_wr_32b(0x53036, 0xc008e818);
dwc_ddrphy_apb_wr_32b(0x53038, 0x7e0b79cf);
dwc_ddrphy_apb_wr_32b(0x5303a, 0x132cf226);
dwc_ddrphy_apb_wr_32b(0x5303c, 0xc1423100);
dwc_ddrphy_apb_wr_32b(0x5303e, 0x2004702c);
dwc_ddrphy_apb_wr_32b(0x53040, 0xf80);
dwc_ddrphy_apb_wr_32b(0x53042, 0xc040f1ff);
dwc_ddrphy_apb_wr_32b(0x53044, 0x734cd8ff);
dwc_ddrphy_apb_wr_32b(0x53046, 0x1c0cdb18);
dwc_ddrphy_apb_wr_32b(0x53048, 0x8663001);
dwc_ddrphy_apb_wr_32b(0x5304a, 0x1c04fdaf);
dwc_ddrphy_apb_wr_32b(0x5304c, 0xf0053081);
dwc_ddrphy_apb_wr_32b(0x5304e, 0x7e0bc008);
dwc_ddrphy_apb_wr_32b(0x53050, 0xc004f241);
dwc_ddrphy_apb_wr_32b(0x53052, 0xe8057dcf);
dwc_ddrphy_apb_wr_32b(0x53054, 0x7e0bc00b);
dwc_ddrphy_apb_wr_32b(0x53056, 0x710cf211);
dwc_ddrphy_apb_wr_32b(0x53058, 0xc005c041);
dwc_ddrphy_apb_wr_32b(0x5305a, 0xc143702c);
dwc_ddrphy_apb_wr_32b(0x5305c, 0xd8ffc040);
dwc_ddrphy_apb_wr_32b(0x5305e, 0xf02fc542);
dwc_ddrphy_apb_wr_32b(0x53060, 0x1c0cc00a);
dwc_ddrphy_apb_wr_32b(0x53062, 0xc1423001);
dwc_ddrphy_apb_wr_32b(0x53064, 0x30811c04);
dwc_ddrphy_apb_wr_32b(0x53066, 0x1332f024);
dwc_ddrphy_apb_wr_32b(0x53068, 0xb4e3100);
dwc_ddrphy_apb_wr_32b(0x5306a, 0xc10cffaf);
dwc_ddrphy_apb_wr_32b(0x5306c, 0x20044608);
dwc_ddrphy_apb_wr_32b(0x5306e, 0xf80);
dwc_ddrphy_apb_wr_32b(0x53070, 0x702cfe3f);
dwc_ddrphy_apb_wr_32b(0x53072, 0xd8ffc040);
dwc_ddrphy_apb_wr_32b(0x53074, 0xdb18734c);
dwc_ddrphy_apb_wr_32b(0x53076, 0xc542c143);
dwc_ddrphy_apb_wr_32b(0x53078, 0xfdaf0806);
dwc_ddrphy_apb_wr_32b(0x5307a, 0x31411c04);
dwc_ddrphy_apb_wr_32b(0x5307c, 0xc043700c);
dwc_ddrphy_apb_wr_32b(0x5307e, 0xc041710c);
dwc_ddrphy_apb_wr_32b(0x53080, 0xc542c005);
dwc_ddrphy_apb_wr_32b(0x53082, 0xf812004);
dwc_ddrphy_apb_wr_32b(0x53084, 0xf8ff0000);
dwc_ddrphy_apb_wr_32b(0x53086, 0x20846e12);
dwc_ddrphy_apb_wr_32b(0x53088, 0x7825001c);
dwc_ddrphy_apb_wr_32b(0x5308a, 0xd8ffc040);
dwc_ddrphy_apb_wr_32b(0x5308c, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x5308e, 0xfd6f0fda);
dwc_ddrphy_apb_wr_32b(0x53090, 0x71e5db18);
dwc_ddrphy_apb_wr_32b(0x53092, 0xc007f18e);
dwc_ddrphy_apb_wr_32b(0x53094, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x53096, 0xc042780f);
dwc_ddrphy_apb_wr_32b(0x53098, 0xdb18c006);
dwc_ddrphy_apb_wr_32b(0x5309a, 0x78104528);
dwc_ddrphy_apb_wr_32b(0x5309c, 0xd8ffc040);
dwc_ddrphy_apb_wr_32b(0x5309e, 0xfbac143);
dwc_ddrphy_apb_wr_32b(0x530a0, 0x1c04fd6f);
dwc_ddrphy_apb_wr_32b(0x530a2, 0xbae3041);
dwc_ddrphy_apb_wr_32b(0x530a4, 0xdb32fd4f);
dwc_ddrphy_apb_wr_32b(0x530a6, 0x34011c0c);
dwc_ddrphy_apb_wr_32b(0x530a8, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x530aa, 0xfd6f0db6);
dwc_ddrphy_apb_wr_32b(0x530ac, 0xad2c540);
dwc_ddrphy_apb_wr_32b(0x530ae, 0xc543fd4f);
dwc_ddrphy_apb_wr_32b(0x530b0, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x530b2, 0xfd6f0da6);
dwc_ddrphy_apb_wr_32b(0x530b4, 0xaa2c540);
dwc_ddrphy_apb_wr_32b(0x530b6, 0xc0adfd4f);
dwc_ddrphy_apb_wr_32b(0x530b8, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x530ba, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x530bc, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x530be, 0xc1a4b6c8);
dwc_ddrphy_apb_wr_32b(0x530c0, 0xfdef0ac6);
dwc_ddrphy_apb_wr_32b(0x530c2, 0x47084608);
dwc_ddrphy_apb_wr_32b(0x530c4, 0xcaa700c);
dwc_ddrphy_apb_wr_32b(0x530c6, 0xd910fd6f);
dwc_ddrphy_apb_wr_32b(0x530c8, 0xfd4f0b76);
dwc_ddrphy_apb_wr_32b(0x530ca, 0xc142c143);
dwc_ddrphy_apb_wr_32b(0x530cc, 0xd72c141);
dwc_ddrphy_apb_wr_32b(0x530ce, 0xc140fd6f);
dwc_ddrphy_apb_wr_32b(0x530d0, 0xfd6f0fda);
dwc_ddrphy_apb_wr_32b(0x530d2, 0x82ed8ff);
dwc_ddrphy_apb_wr_32b(0x530d4, 0x40c1fdef);
dwc_ddrphy_apb_wr_32b(0x530d6, 0x43db);
dwc_ddrphy_apb_wr_32b(0x530d8, 0xd8ff1000);
dwc_ddrphy_apb_wr_32b(0x530da, 0x714c702c);
dwc_ddrphy_apb_wr_32b(0x530dc, 0xc543746c);
dwc_ddrphy_apb_wr_32b(0x530de, 0xc541c642);
dwc_ddrphy_apb_wr_32b(0x530e0, 0xfd6f0d4a);
dwc_ddrphy_apb_wr_32b(0x530e2, 0x36c01c00);
dwc_ddrphy_apb_wr_32b(0x530e4, 0xfdaf0fce);
dwc_ddrphy_apb_wr_32b(0x530e6, 0x4f7e40c1);
dwc_ddrphy_apb_wr_32b(0x530e8, 0x60f8b8c0);
dwc_ddrphy_apb_wr_32b(0x530ea, 0x7b0fe03e);
dwc_ddrphy_apb_wr_32b(0x530ec, 0xfd4f0b1a);
dwc_ddrphy_apb_wr_32b(0x530ee, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x530f0, 0xd2ac541);
dwc_ddrphy_apb_wr_32b(0x530f2, 0xc540fd6f);
dwc_ddrphy_apb_wr_32b(0x530f4, 0x30c12b40);
dwc_ddrphy_apb_wr_32b(0x530f6, 0xfd4f0b3e);
dwc_ddrphy_apb_wr_32b(0x530f8, 0x30c11c0c);
dwc_ddrphy_apb_wr_32b(0x530fa, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x530fc, 0xfd6f0d12);
dwc_ddrphy_apb_wr_32b(0x530fe, 0xb22c540);
dwc_ddrphy_apb_wr_32b(0x53100, 0xc543fd4f);
dwc_ddrphy_apb_wr_32b(0x53102, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x53104, 0xfd6f0d02);
dwc_ddrphy_apb_wr_32b(0x53106, 0xf42c540);
dwc_ddrphy_apb_wr_32b(0x53108, 0xd8fffd6f);
dwc_ddrphy_apb_wr_32b(0x5310a, 0xfd4f0a16);
dwc_ddrphy_apb_wr_32b(0x5310c, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x5310e, 0xceec541);
dwc_ddrphy_apb_wr_32b(0x53110, 0xc540fd6f);
dwc_ddrphy_apb_wr_32b(0x53112, 0x1404c0a4);
dwc_ddrphy_apb_wr_32b(0x53114, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x53116, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x53118, 0xc1acb6c8);
dwc_ddrphy_apb_wr_32b(0x5311a, 0xd896c048);
dwc_ddrphy_apb_wr_32b(0x5311c, 0xa4ec249);
dwc_ddrphy_apb_wr_32b(0x5311e, 0x4528fe2f);
dwc_ddrphy_apb_wr_32b(0x53120, 0xfdef0a16);
dwc_ddrphy_apb_wr_32b(0x53122, 0x46084318);
dwc_ddrphy_apb_wr_32b(0x53124, 0xfdaf0a0e);
dwc_ddrphy_apb_wr_32b(0x53126, 0xaf6710c);
dwc_ddrphy_apb_wr_32b(0x53128, 0x70edfd4f);
dwc_ddrphy_apb_wr_32b(0x5312a, 0xfd4f0a9e);
dwc_ddrphy_apb_wr_32b(0x5312c, 0xc742c743);
dwc_ddrphy_apb_wr_32b(0x5312e, 0xcaec741);
dwc_ddrphy_apb_wr_32b(0x53130, 0xc740fd6f);
dwc_ddrphy_apb_wr_32b(0x53132, 0x78b8710c);
dwc_ddrphy_apb_wr_32b(0x53134, 0x2344c04a);
dwc_ddrphy_apb_wr_32b(0x53136, 0x70633040);
dwc_ddrphy_apb_wr_32b(0x53138, 0x2644c04b);
dwc_ddrphy_apb_wr_32b(0x5313a, 0x60d81040);
dwc_ddrphy_apb_wr_32b(0x5313c, 0x43db70ad);
dwc_ddrphy_apb_wr_32b(0x5313e, 0x10000000);
dwc_ddrphy_apb_wr_32b(0x53140, 0xc544c046);
dwc_ddrphy_apb_wr_32b(0x53142, 0x8f5c004);
dwc_ddrphy_apb_wr_32b(0x53144, 0x702c00f5);
dwc_ddrphy_apb_wr_32b(0x53146, 0x734cc00a);
dwc_ddrphy_apb_wr_32b(0x53148, 0xc0047e0f);
dwc_ddrphy_apb_wr_32b(0x5314a, 0xc743db12);
dwc_ddrphy_apb_wr_32b(0x5314c, 0xc0087214);
dwc_ddrphy_apb_wr_32b(0x5314e, 0x1c04c642);
dwc_ddrphy_apb_wr_32b(0x53150, 0x20cf3181);
dwc_ddrphy_apb_wr_32b(0x53152, 0xc04001e2);
dwc_ddrphy_apb_wr_32b(0x53154, 0xfd6f0e4e);
dwc_ddrphy_apb_wr_32b(0x53156, 0xc00bd8ff);
dwc_ddrphy_apb_wr_32b(0x53158, 0xb98e702c);
dwc_ddrphy_apb_wr_32b(0x5315a, 0xc045780f);
dwc_ddrphy_apb_wr_32b(0x5315c, 0xd8ffc305);
dwc_ddrphy_apb_wr_32b(0x5315e, 0xc743754c);
dwc_ddrphy_apb_wr_32b(0x53160, 0xc741c742);
dwc_ddrphy_apb_wr_32b(0x53162, 0xfd6f0c46);
dwc_ddrphy_apb_wr_32b(0x53164, 0xc009c740);
dwc_ddrphy_apb_wr_32b(0x53166, 0x1008a5);
dwc_ddrphy_apb_wr_32b(0x53168, 0x8a1c004);
dwc_ddrphy_apb_wr_32b(0x5316a, 0xd9110031);
dwc_ddrphy_apb_wr_32b(0x5316c, 0xb90ad8ff);
dwc_ddrphy_apb_wr_32b(0x5316e, 0xdb7c704c);
dwc_ddrphy_apb_wr_32b(0x53170, 0x30411c0c);
dwc_ddrphy_apb_wr_32b(0x53172, 0xc541c642);
dwc_ddrphy_apb_wr_32b(0x53174, 0xfd6f0c22);
dwc_ddrphy_apb_wr_32b(0x53176, 0x2b40c540);
dwc_ddrphy_apb_wr_32b(0x53178, 0xc0473100);
dwc_ddrphy_apb_wr_32b(0x5317a, 0x2b40d8ff);
dwc_ddrphy_apb_wr_32b(0x5317c, 0x724c3101);
dwc_ddrphy_apb_wr_32b(0x5317e, 0x1c0c746c);
dwc_ddrphy_apb_wr_32b(0x53180, 0xc6423101);
dwc_ddrphy_apb_wr_32b(0x53182, 0xc06c541);
dwc_ddrphy_apb_wr_32b(0x53184, 0x1c00fd6f);
dwc_ddrphy_apb_wr_32b(0x53186, 0xd83236c0);
dwc_ddrphy_apb_wr_32b(0x53188, 0xc043d911);
dwc_ddrphy_apb_wr_32b(0x5318a, 0xb90ad8ff);
dwc_ddrphy_apb_wr_32b(0x5318c, 0x746c724c);
dwc_ddrphy_apb_wr_32b(0x5318e, 0xc541c642);
dwc_ddrphy_apb_wr_32b(0x53190, 0xfd6f0bea);
dwc_ddrphy_apb_wr_32b(0x53192, 0x36c01c00);
dwc_ddrphy_apb_wr_32b(0x53194, 0xd8ffc107);
dwc_ddrphy_apb_wr_32b(0x53196, 0x746c724c);
dwc_ddrphy_apb_wr_32b(0x53198, 0x31011c0c);
dwc_ddrphy_apb_wr_32b(0x5319a, 0xc541c642);
dwc_ddrphy_apb_wr_32b(0x5319c, 0xfd6f0bd2);
dwc_ddrphy_apb_wr_32b(0x5319e, 0x36c01c00);
dwc_ddrphy_apb_wr_32b(0x531a0, 0x702cc006);
dwc_ddrphy_apb_wr_32b(0x531a2, 0xe024754c);
dwc_ddrphy_apb_wr_32b(0x531a4, 0xd8ff7b0f);
dwc_ddrphy_apb_wr_32b(0x531a6, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x531a8, 0xbbac541);
dwc_ddrphy_apb_wr_32b(0x531aa, 0xc540fd6f);
dwc_ddrphy_apb_wr_32b(0x531ac, 0x208ac305);
dwc_ddrphy_apb_wr_32b(0x531ae, 0xc0400010);
dwc_ddrphy_apb_wr_32b(0x531b0, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x531b2, 0xc543764c);
dwc_ddrphy_apb_wr_32b(0x531b4, 0xba2c642);
dwc_ddrphy_apb_wr_32b(0x531b6, 0xc541fd6f);
dwc_ddrphy_apb_wr_32b(0x531b8, 0x7104c004);
dwc_ddrphy_apb_wr_32b(0x531ba, 0xf188c044);
dwc_ddrphy_apb_wr_32b(0x531bc, 0xfd4f08b2);
dwc_ddrphy_apb_wr_32b(0x531be, 0xc742c743);
dwc_ddrphy_apb_wr_32b(0x531c0, 0xb8ac741);
dwc_ddrphy_apb_wr_32b(0x531c2, 0xc740fd6f);
dwc_ddrphy_apb_wr_32b(0x531c4, 0xfd4f0882);
dwc_ddrphy_apb_wr_32b(0x531c6, 0xfdaf08ca);
dwc_ddrphy_apb_wr_32b(0x531c8, 0xc0ac700c);
dwc_ddrphy_apb_wr_32b(0x531ca, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x531cc, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x531ce, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x531d0, 0xc1aab6c8);
dwc_ddrphy_apb_wr_32b(0x531d2, 0x1600c044);
dwc_ddrphy_apb_wr_32b(0x531d4, 0x80007140);
dwc_ddrphy_apb_wr_32b(0x531d6, 0xc3490016);
dwc_ddrphy_apb_wr_32b(0x531d8, 0xc148c247);
dwc_ddrphy_apb_wr_32b(0x531da, 0x32080b);
dwc_ddrphy_apb_wr_32b(0x531dc, 0x700cc046);
dwc_ddrphy_apb_wr_32b(0x531de, 0xd840f002);
dwc_ddrphy_apb_wr_32b(0x531e0, 0xfd6f0a72);
dwc_ddrphy_apb_wr_32b(0x531e2, 0x1200d9ff);
dwc_ddrphy_apb_wr_32b(0x531e4, 0x706f3083);
dwc_ddrphy_apb_wr_32b(0x531e6, 0xfd4f094a);
dwc_ddrphy_apb_wr_32b(0x531e8, 0x36c01c0c);
dwc_ddrphy_apb_wr_32b(0x531ea, 0x36c01c08);
dwc_ddrphy_apb_wr_32b(0x531ec, 0x36c01c04);
dwc_ddrphy_apb_wr_32b(0x531ee, 0xfd6f0b2e);
dwc_ddrphy_apb_wr_32b(0x531f0, 0x36c01c00);
dwc_ddrphy_apb_wr_32b(0x531f2, 0xb1c0234c);
dwc_ddrphy_apb_wr_32b(0x531f4, 0x260116);
dwc_ddrphy_apb_wr_32b(0x531f6, 0x23327277);
dwc_ddrphy_apb_wr_32b(0x531f8, 0x80003f8e);
dwc_ddrphy_apb_wr_32b(0x531fa, 0xc0080838);
dwc_ddrphy_apb_wr_32b(0x531fc, 0x20f4c109);
dwc_ddrphy_apb_wr_32b(0x531fe, 0x20ec0380);
dwc_ddrphy_apb_wr_32b(0x53200, 0x211100a1);
dwc_ddrphy_apb_wr_32b(0x53202, 0xf47b8380);
dwc_ddrphy_apb_wr_32b(0x53204, 0xc0067f10);
dwc_ddrphy_apb_wr_32b(0x53206, 0x32081f);
dwc_ddrphy_apb_wr_32b(0x53208, 0xc00470ad);
dwc_ddrphy_apb_wr_32b(0x5320a, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x5320c, 0xd8ffc042);
dwc_ddrphy_apb_wr_32b(0x5320e, 0xc543db18);
dwc_ddrphy_apb_wr_32b(0x53210, 0xcd6c641);
dwc_ddrphy_apb_wr_32b(0x53212, 0xc740fd6f);
dwc_ddrphy_apb_wr_32b(0x53214, 0xc004f069);
dwc_ddrphy_apb_wr_32b(0x53216, 0xb990702c);
dwc_ddrphy_apb_wr_32b(0x53218, 0xd8ffc042);
dwc_ddrphy_apb_wr_32b(0x5321a, 0x726c734c);
dwc_ddrphy_apb_wr_32b(0x5321c, 0xc641c543);
dwc_ddrphy_apb_wr_32b(0x5321e, 0xfd6f0ace);
dwc_ddrphy_apb_wr_32b(0x53220, 0xc004c740);
dwc_ddrphy_apb_wr_32b(0x53222, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x53224, 0xd8ffc042);
dwc_ddrphy_apb_wr_32b(0x53226, 0xc543726c);
dwc_ddrphy_apb_wr_32b(0x53228, 0xabac641);
dwc_ddrphy_apb_wr_32b(0x5322a, 0xc740fd6f);
dwc_ddrphy_apb_wr_32b(0x5322c, 0x702cc004);
dwc_ddrphy_apb_wr_32b(0x5322e, 0xc042b990);
dwc_ddrphy_apb_wr_32b(0x53230, 0x734cd8ff);
dwc_ddrphy_apb_wr_32b(0x53232, 0xc543db18);
dwc_ddrphy_apb_wr_32b(0x53234, 0xaa2c641);
dwc_ddrphy_apb_wr_32b(0x53236, 0xc740fd6f);
dwc_ddrphy_apb_wr_32b(0x53238, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x5323a, 0x18000);
dwc_ddrphy_apb_wr_32b(0x5323c, 0x1be0883);
dwc_ddrphy_apb_wr_32b(0x5323e, 0xc004702c);
dwc_ddrphy_apb_wr_32b(0x53240, 0x781bb990);
dwc_ddrphy_apb_wr_32b(0x53242, 0xc045780f);
dwc_ddrphy_apb_wr_32b(0x53244, 0xd8ffc042);
dwc_ddrphy_apb_wr_32b(0x53246, 0x726c734c);
dwc_ddrphy_apb_wr_32b(0x53248, 0xc641c543);
dwc_ddrphy_apb_wr_32b(0x5324a, 0xfd6f0a76);
dwc_ddrphy_apb_wr_32b(0x5324c, 0xc005c740);
dwc_ddrphy_apb_wr_32b(0x5324e, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x53250, 0xd8ffc042);
dwc_ddrphy_apb_wr_32b(0x53252, 0xc543726c);
dwc_ddrphy_apb_wr_32b(0x53254, 0xa62c641);
dwc_ddrphy_apb_wr_32b(0x53256, 0xc740fd6f);
dwc_ddrphy_apb_wr_32b(0x53258, 0x702cc005);
dwc_ddrphy_apb_wr_32b(0x5325a, 0xc042b990);
dwc_ddrphy_apb_wr_32b(0x5325c, 0x734cd8ff);
dwc_ddrphy_apb_wr_32b(0x5325e, 0xc543db18);
dwc_ddrphy_apb_wr_32b(0x53260, 0xa4ac641);
dwc_ddrphy_apb_wr_32b(0x53262, 0xc740fd6f);
dwc_ddrphy_apb_wr_32b(0x53264, 0x30f10b33);
dwc_ddrphy_apb_wr_32b(0x53266, 0xf6a70ad);
dwc_ddrphy_apb_wr_32b(0x53268, 0xc543fd0f);
dwc_ddrphy_apb_wr_32b(0x5326a, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x5326c, 0xfd6f0a32);
dwc_ddrphy_apb_wr_32b(0x5326e, 0xf3ec540);
dwc_ddrphy_apb_wr_32b(0x53270, 0xd840fd0f);
dwc_ddrphy_apb_wr_32b(0x53272, 0xfd6f094e);
dwc_ddrphy_apb_wr_32b(0x53274, 0x812d9ff);
dwc_ddrphy_apb_wr_32b(0x53276, 0xc543fd4f);
dwc_ddrphy_apb_wr_32b(0x53278, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x5327a, 0xfd6f0a16);
dwc_ddrphy_apb_wr_32b(0x5327c, 0x7167c540);
dwc_ddrphy_apb_wr_32b(0x5327e, 0xc007f174);
dwc_ddrphy_apb_wr_32b(0x53280, 0xc006e82a);
dwc_ddrphy_apb_wr_32b(0x53282, 0x81370ad);
dwc_ddrphy_apb_wr_32b(0x53284, 0x268a0032);
dwc_ddrphy_apb_wr_32b(0x53286, 0xc0041010);
dwc_ddrphy_apb_wr_32b(0x53288, 0xc042c543);
dwc_ddrphy_apb_wr_32b(0x5328a, 0xd8fff018);
dwc_ddrphy_apb_wr_32b(0x5328c, 0xda07702c);
dwc_ddrphy_apb_wr_32b(0x5328e, 0xc543726c);
dwc_ddrphy_apb_wr_32b(0x53290, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x53292, 0xfd6f09e6);
dwc_ddrphy_apb_wr_32b(0x53294, 0xc004c640);
dwc_ddrphy_apb_wr_32b(0x53296, 0xda07702c);
dwc_ddrphy_apb_wr_32b(0x53298, 0xd8ffc042);
dwc_ddrphy_apb_wr_32b(0x5329a, 0xc543726c);
dwc_ddrphy_apb_wr_32b(0x5329c, 0x9d2c541);
dwc_ddrphy_apb_wr_32b(0x5329e, 0xc640fd6f);
dwc_ddrphy_apb_wr_32b(0x532a0, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x532a2, 0x702cd8ff);
dwc_ddrphy_apb_wr_32b(0x532a4, 0x746cda07);
dwc_ddrphy_apb_wr_32b(0x532a6, 0x9bec541);
dwc_ddrphy_apb_wr_32b(0x532a8, 0xc640fd6f);
dwc_ddrphy_apb_wr_32b(0x532aa, 0xd8ff702c);
dwc_ddrphy_apb_wr_32b(0x532ac, 0xdb42754c);
dwc_ddrphy_apb_wr_32b(0x532ae, 0x34011c0c);
dwc_ddrphy_apb_wr_32b(0x532b0, 0xc1424528);
dwc_ddrphy_apb_wr_32b(0x532b2, 0x9a6c141);
dwc_ddrphy_apb_wr_32b(0x532b4, 0xc140fd6f);
dwc_ddrphy_apb_wr_32b(0x532b6, 0xfd0f0eca);
dwc_ddrphy_apb_wr_32b(0x532b8, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x532ba, 0x996c541);
dwc_ddrphy_apb_wr_32b(0x532bc, 0xc540fd6f);
dwc_ddrphy_apb_wr_32b(0x532be, 0xfd0f0e9e);
dwc_ddrphy_apb_wr_32b(0x532c0, 0x1404c0aa);
dwc_ddrphy_apb_wr_32b(0x532c2, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x532c4, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x532c6, 0xc1b0b6c8);
dwc_ddrphy_apb_wr_32b(0x532c8, 0x3000260a);
dwc_ddrphy_apb_wr_32b(0x532ca, 0x2800710c);
dwc_ddrphy_apb_wr_32b(0x532cc, 0xc0470780);
dwc_ddrphy_apb_wr_32b(0x532ce, 0x708d1600);
dwc_ddrphy_apb_wr_32b(0x532d0, 0xf8000);
dwc_ddrphy_apb_wr_32b(0x532d2, 0x71001600);
dwc_ddrphy_apb_wr_32b(0x532d4, 0x4a9004);
dwc_ddrphy_apb_wr_32b(0x532d6, 0x25534628);
dwc_ddrphy_apb_wr_32b(0x532d8, 0xc048104b);
dwc_ddrphy_apb_wr_32b(0x532da, 0xe8a9102);
dwc_ddrphy_apb_wr_32b(0x532dc, 0x210aff6f);
dwc_ddrphy_apb_wr_32b(0x532de, 0x43000780);
dwc_ddrphy_apb_wr_32b(0x532e0, 0xe5e9605);
dwc_ddrphy_apb_wr_32b(0x532e2, 0x210aff6f);
dwc_ddrphy_apb_wr_32b(0x532e4, 0x23ad0780);
dwc_ddrphy_apb_wr_32b(0x532e6, 0xc04c0241);
dwc_ddrphy_apb_wr_32b(0x532e8, 0xeb15c044);
dwc_ddrphy_apb_wr_32b(0x532ea, 0x700b17);
dwc_ddrphy_apb_wr_32b(0x532ec, 0xb13720c);
dwc_ddrphy_apb_wr_32b(0x532ee, 0x700c00f0);
dwc_ddrphy_apb_wr_32b(0x532f0, 0xb10b09);
dwc_ddrphy_apb_wr_32b(0x532f2, 0xf003740c);
dwc_ddrphy_apb_wr_32b(0x532f4, 0xc10c760c);
dwc_ddrphy_apb_wr_32b(0x532f6, 0x2104b806);
dwc_ddrphy_apb_wr_32b(0x532f8, 0xf81);
dwc_ddrphy_apb_wr_32b(0x532fa, 0x7825fe3f);
dwc_ddrphy_apb_wr_32b(0x532fc, 0x265fc044);
dwc_ddrphy_apb_wr_32b(0x532fe, 0x43db3500);
dwc_ddrphy_apb_wr_32b(0x53300, 0x868000);
dwc_ddrphy_apb_wr_32b(0x53302, 0xd9ffbd22);
dwc_ddrphy_apb_wr_32b(0x53304, 0x2379c049);
dwc_ddrphy_apb_wr_32b(0x53306, 0xc04a1000);
dwc_ddrphy_apb_wr_32b(0x53308, 0xb08013e6);
dwc_ddrphy_apb_wr_32b(0x5330a, 0xc04fc545);
dwc_ddrphy_apb_wr_32b(0x5330c, 0xc0469603);
dwc_ddrphy_apb_wr_32b(0x5330e, 0xc04b9604);
dwc_ddrphy_apb_wr_32b(0x53310, 0xfd6f0812);
dwc_ddrphy_apb_wr_32b(0x53312, 0x1200700c);
dwc_ddrphy_apb_wr_32b(0x53314, 0x702c3083);
dwc_ddrphy_apb_wr_32b(0x53316, 0x754cd8ff);
dwc_ddrphy_apb_wr_32b(0x53318, 0xc1434528);
dwc_ddrphy_apb_wr_32b(0x5331a, 0xc141c142);
dwc_ddrphy_apb_wr_32b(0x5331c, 0xfd6f08d2);
dwc_ddrphy_apb_wr_32b(0x5331e, 0xc007c140);
dwc_ddrphy_apb_wr_32b(0x53320, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x53322, 0xc0047f0f);
dwc_ddrphy_apb_wr_32b(0x53324, 0xc543db18);
dwc_ddrphy_apb_wr_32b(0x53326, 0xd8ffc040);
dwc_ddrphy_apb_wr_32b(0x53328, 0xaa6c742);
dwc_ddrphy_apb_wr_32b(0x5332a, 0x1c04fd6f);
dwc_ddrphy_apb_wr_32b(0x5332c, 0xc00b3141);
dwc_ddrphy_apb_wr_32b(0x5332e, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x53330, 0xf802004);
dwc_ddrphy_apb_wr_32b(0x53332, 0xefff0000);
dwc_ddrphy_apb_wr_32b(0x53334, 0xd8ffc040);
dwc_ddrphy_apb_wr_32b(0x53336, 0xc543db18);
dwc_ddrphy_apb_wr_32b(0x53338, 0xa86c742);
dwc_ddrphy_apb_wr_32b(0x5333a, 0x1c04fd6f);
dwc_ddrphy_apb_wr_32b(0x5333c, 0x96223101);
dwc_ddrphy_apb_wr_32b(0x5333e, 0xda240e1);
dwc_ddrphy_apb_wr_32b(0x53340, 0xda18fd6f);
dwc_ddrphy_apb_wr_32b(0x53342, 0x702cc006);
dwc_ddrphy_apb_wr_32b(0x53344, 0xb884734c);
dwc_ddrphy_apb_wr_32b(0x53346, 0xd8ffc040);
dwc_ddrphy_apb_wr_32b(0x53348, 0xc543db18);
dwc_ddrphy_apb_wr_32b(0x5334a, 0xa62c742);
dwc_ddrphy_apb_wr_32b(0x5334c, 0x1c04fd6f);
dwc_ddrphy_apb_wr_32b(0x5334e, 0xd9a30c1);
dwc_ddrphy_apb_wr_32b(0x53350, 0xc543fd0f);
dwc_ddrphy_apb_wr_32b(0x53352, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x53354, 0xfd6f0862);
dwc_ddrphy_apb_wr_32b(0x53356, 0x700cc540);
dwc_ddrphy_apb_wr_32b(0x53358, 0xfd6f082a);
dwc_ddrphy_apb_wr_32b(0x5335a, 0x9642712c);
dwc_ddrphy_apb_wr_32b(0x5335c, 0xd4a9621);
dwc_ddrphy_apb_wr_32b(0x5335e, 0x9600fd6f);
dwc_ddrphy_apb_wr_32b(0x53360, 0xb080137e);
dwc_ddrphy_apb_wr_32b(0x53362, 0x2005b815);
dwc_ddrphy_apb_wr_32b(0x53364, 0x90080f80);
dwc_ddrphy_apb_wr_32b(0x53366, 0xc04d01ec);
dwc_ddrphy_apb_wr_32b(0x53368, 0xc04e9000);
dwc_ddrphy_apb_wr_32b(0x5336a, 0x80db8c5);
dwc_ddrphy_apb_wr_32b(0x5336c, 0x420006b5);
dwc_ddrphy_apb_wr_32b(0x5336e, 0xf005e218);
dwc_ddrphy_apb_wr_32b(0x53370, 0xc950a07);
dwc_ddrphy_apb_wr_32b(0x53372, 0xc009da32);
dwc_ddrphy_apb_wr_32b(0x53374, 0x70adc10a);
dwc_ddrphy_apb_wr_32b(0x53376, 0xc0497063);
dwc_ddrphy_apb_wr_32b(0x53378, 0x6038c005);
dwc_ddrphy_apb_wr_32b(0x5337a, 0xc00ec04a);
dwc_ddrphy_apb_wr_32b(0x5337c, 0x141206c);
dwc_ddrphy_apb_wr_32b(0x5337e, 0x7945c00d);
dwc_ddrphy_apb_wr_32b(0x53380, 0xc107b020);
dwc_ddrphy_apb_wr_32b(0x53382, 0x2004c008);
dwc_ddrphy_apb_wr_32b(0x53384, 0xc0488040);
dwc_ddrphy_apb_wr_32b(0x53386, 0xc045720c);
dwc_ddrphy_apb_wr_32b(0x53388, 0x6220ca);
dwc_ddrphy_apb_wr_32b(0x5338a, 0xc00fc045);
dwc_ddrphy_apb_wr_32b(0x5338c, 0xc005790b);
dwc_ddrphy_apb_wr_32b(0x5338e, 0x12220ca);
dwc_ddrphy_apb_wr_32b(0x53390, 0x700cc045);
dwc_ddrphy_apb_wr_32b(0x53392, 0xc006c046);
dwc_ddrphy_apb_wr_32b(0x53394, 0x13a7214);
dwc_ddrphy_apb_wr_32b(0x53396, 0x706f002d);
dwc_ddrphy_apb_wr_32b(0x53398, 0x230cc00a);
dwc_ddrphy_apb_wr_32b(0x5339a, 0x128b000);
dwc_ddrphy_apb_wr_32b(0x5339c, 0xc1080006);
dwc_ddrphy_apb_wr_32b(0x5339e, 0x16c2242f);
dwc_ddrphy_apb_wr_32b(0x533a0, 0x900e40c3);
dwc_ddrphy_apb_wr_32b(0x533a2, 0x70341e48);
dwc_ddrphy_apb_wr_32b(0x533a4, 0x41c3);
dwc_ddrphy_apb_wr_32b(0x533a6, 0x238affff);
dwc_ddrphy_apb_wr_32b(0x533a8, 0x42c30fc7);
dwc_ddrphy_apb_wr_32b(0x533aa, 0xca900e);
dwc_ddrphy_apb_wr_32b(0x533ac, 0xb020f209);
dwc_ddrphy_apb_wr_32b(0x533ae, 0x303f0b1b);
dwc_ddrphy_apb_wr_32b(0x533b0, 0xb022b021);
dwc_ddrphy_apb_wr_32b(0x533b2, 0x702cb023);
dwc_ddrphy_apb_wr_32b(0x533b4, 0xb020f009);
dwc_ddrphy_apb_wr_32b(0x533b6, 0xb0a2b021);
dwc_ddrphy_apb_wr_32b(0x533b8, 0xb260b0a3);
dwc_ddrphy_apb_wr_32b(0x533ba, 0xb0a2f016);
dwc_ddrphy_apb_wr_32b(0x533bc, 0xb260b0a3);
dwc_ddrphy_apb_wr_32b(0x533be, 0xf00f700c);
dwc_ddrphy_apb_wr_32b(0x533c0, 0x23057b1b);
dwc_ddrphy_apb_wr_32b(0x533c2, 0x900e0f82);
dwc_ddrphy_apb_wr_32b(0x533c4, 0xb220004c);
dwc_ddrphy_apb_wr_32b(0x533c6, 0xf822305);
dwc_ddrphy_apb_wr_32b(0x533c8, 0x4e900e);
dwc_ddrphy_apb_wr_32b(0x533ca, 0x2056b220);
dwc_ddrphy_apb_wr_32b(0x533cc, 0x208c0800);
dwc_ddrphy_apb_wr_32b(0x533ce, 0xf7f28fcf);
dwc_ddrphy_apb_wr_32b(0x533d0, 0x42c3bc0d);
dwc_ddrphy_apb_wr_32b(0x533d2, 0x16c9002);
dwc_ddrphy_apb_wr_32b(0x533d4, 0x2205706d);
dwc_ddrphy_apb_wr_32b(0x533d6, 0x1e000300);
dwc_ddrphy_apb_wr_32b(0x533d8, 0x900372c4);
dwc_ddrphy_apb_wr_32b(0x533da, 0x1800e16c);
dwc_ddrphy_apb_wr_32b(0x533dc, 0xc1070045);
dwc_ddrphy_apb_wr_32b(0x533de, 0x4381c00f);
dwc_ddrphy_apb_wr_32b(0x533e0, 0xf207790b);
dwc_ddrphy_apb_wr_32b(0x533e2, 0x102396);
dwc_ddrphy_apb_wr_32b(0x533e4, 0x1a007a65);
dwc_ddrphy_apb_wr_32b(0x533e6, 0xc0090045);
dwc_ddrphy_apb_wr_32b(0x533e8, 0x2032d9ff);
dwc_ddrphy_apb_wr_32b(0x533ea, 0xc04406c0);
dwc_ddrphy_apb_wr_32b(0x533ec, 0xc04b8e0d);
dwc_ddrphy_apb_wr_32b(0x533ee, 0xfd2f0e56);
dwc_ddrphy_apb_wr_32b(0x533f0, 0xd1a700c);
dwc_ddrphy_apb_wr_32b(0x533f2, 0x1c0cfd0f);
dwc_ddrphy_apb_wr_32b(0x533f4, 0x1c0832c0);
dwc_ddrphy_apb_wr_32b(0x533f6, 0x1c0432c0);
dwc_ddrphy_apb_wr_32b(0x533f8, 0xf1a32c0);
dwc_ddrphy_apb_wr_32b(0x533fa, 0x1c00fd2f);
dwc_ddrphy_apb_wr_32b(0x533fc, 0xc00432c0);
dwc_ddrphy_apb_wr_32b(0x533fe, 0xb8c6c10b);
dwc_ddrphy_apb_wr_32b(0x53400, 0xc004c044);
dwc_ddrphy_apb_wr_32b(0x53402, 0x7825b908);
dwc_ddrphy_apb_wr_32b(0x53404, 0xc006c044);
dwc_ddrphy_apb_wr_32b(0x53406, 0x7214762c);
dwc_ddrphy_apb_wr_32b(0x53408, 0x20cfc004);
dwc_ddrphy_apb_wr_32b(0x5340a, 0xc04401e5);
dwc_ddrphy_apb_wr_32b(0x5340c, 0x976c204);
dwc_ddrphy_apb_wr_32b(0x5340e, 0x40e1fd6f);
dwc_ddrphy_apb_wr_32b(0x53410, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x53412, 0x18000);
dwc_ddrphy_apb_wr_32b(0x53414, 0x1be0813);
dwc_ddrphy_apb_wr_32b(0x53416, 0xc007762c);
dwc_ddrphy_apb_wr_32b(0x53418, 0x781bc204);
dwc_ddrphy_apb_wr_32b(0x5341a, 0xfd6f095a);
dwc_ddrphy_apb_wr_32b(0x5341c, 0x700c780f);
dwc_ddrphy_apb_wr_32b(0x5341e, 0xc042c043);
dwc_ddrphy_apb_wr_32b(0x53420, 0xc040c041);
dwc_ddrphy_apb_wr_32b(0x53422, 0xd980d8ff);
dwc_ddrphy_apb_wr_32b(0x53424, 0xec2754c);
dwc_ddrphy_apb_wr_32b(0x53426, 0x746cfd2f);
dwc_ddrphy_apb_wr_32b(0x53428, 0xfd0f0bca);
dwc_ddrphy_apb_wr_32b(0x5342a, 0x2300c005);
dwc_ddrphy_apb_wr_32b(0x5342c, 0xf16c301b);
dwc_ddrphy_apb_wr_32b(0x5342e, 0x7104c006);
dwc_ddrphy_apb_wr_32b(0x53430, 0x40c3f162);
dwc_ddrphy_apb_wr_32b(0x53432, 0x1e48900e);
dwc_ddrphy_apb_wr_32b(0x53434, 0x151802);
dwc_ddrphy_apb_wr_32b(0x53436, 0xb0a1b0a0);
dwc_ddrphy_apb_wr_32b(0x53438, 0x208ab0a2);
dwc_ddrphy_apb_wr_32b(0x5343a, 0x1e000fc7);
dwc_ddrphy_apb_wr_32b(0x5343c, 0x900e7004);
dwc_ddrphy_apb_wr_32b(0x5343e, 0x1e0000ca);
dwc_ddrphy_apb_wr_32b(0x53440, 0x90037344);
dwc_ddrphy_apb_wr_32b(0x53442, 0x9604e16c);
dwc_ddrphy_apb_wr_32b(0x53444, 0x111b1606);
dwc_ddrphy_apb_wr_32b(0x53446, 0xc044d9ff);
dwc_ddrphy_apb_wr_32b(0x53448, 0xfd2f0da2);
dwc_ddrphy_apb_wr_32b(0x5344a, 0xc66700c);
dwc_ddrphy_apb_wr_32b(0x5344c, 0xc543fd0f);
dwc_ddrphy_apb_wr_32b(0x5344e, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x53450, 0xfd2f0e6a);
dwc_ddrphy_apb_wr_32b(0x53452, 0x2350c540);
dwc_ddrphy_apb_wr_32b(0x53454, 0x40e13102);
dwc_ddrphy_apb_wr_32b(0x53456, 0x8e2732c);
dwc_ddrphy_apb_wr_32b(0x53458, 0x4358fd6f);
dwc_ddrphy_apb_wr_32b(0x5345a, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x5345c, 0x18000);
dwc_ddrphy_apb_wr_32b(0x5345e, 0x1be0813);
dwc_ddrphy_apb_wr_32b(0x53460, 0xc007732c);
dwc_ddrphy_apb_wr_32b(0x53462, 0x781b4263);
dwc_ddrphy_apb_wr_32b(0x53464, 0xfd6f08c6);
dwc_ddrphy_apb_wr_32b(0x53466, 0x70ad780f);
dwc_ddrphy_apb_wr_32b(0x53468, 0xfd0f0b66);
dwc_ddrphy_apb_wr_32b(0x5346a, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x5346c, 0xe32c541);
dwc_ddrphy_apb_wr_32b(0x5346e, 0xc540fd2f);
dwc_ddrphy_apb_wr_32b(0x53470, 0xfd0f0b3a);
dwc_ddrphy_apb_wr_32b(0x53472, 0xc00dc10e);
dwc_ddrphy_apb_wr_32b(0x53474, 0x700cb020);
dwc_ddrphy_apb_wr_32b(0x53476, 0xfd2f0d46);
dwc_ddrphy_apb_wr_32b(0x53478, 0xc0ad9ff);
dwc_ddrphy_apb_wr_32b(0x5347a, 0xc543fd0f);
dwc_ddrphy_apb_wr_32b(0x5347c, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x5347e, 0xfd2f0e0e);
dwc_ddrphy_apb_wr_32b(0x53480, 0xc00cc540);
dwc_ddrphy_apb_wr_32b(0x53482, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x53484, 0xd8ffc040);
dwc_ddrphy_apb_wr_32b(0x53486, 0xc543db18);
dwc_ddrphy_apb_wr_32b(0x53488, 0xfe6c742);
dwc_ddrphy_apb_wr_32b(0x5348a, 0x1c04fd2f);
dwc_ddrphy_apb_wr_32b(0x5348c, 0xc0043141);
dwc_ddrphy_apb_wr_32b(0x5348e, 0x734c702c);
dwc_ddrphy_apb_wr_32b(0x53490, 0xd8ffc040);
dwc_ddrphy_apb_wr_32b(0x53492, 0xc543db18);
dwc_ddrphy_apb_wr_32b(0x53494, 0xfcec742);
dwc_ddrphy_apb_wr_32b(0x53496, 0x1c04fd2f);
dwc_ddrphy_apb_wr_32b(0x53498, 0x96223101);
dwc_ddrphy_apb_wr_32b(0x5349a, 0xa9e40e1);
dwc_ddrphy_apb_wr_32b(0x5349c, 0xda18fd6f);
dwc_ddrphy_apb_wr_32b(0x5349e, 0xfd0f0afa);
dwc_ddrphy_apb_wr_32b(0x534a0, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x534a2, 0xdc6c541);
dwc_ddrphy_apb_wr_32b(0x534a4, 0xc540fd2f);
dwc_ddrphy_apb_wr_32b(0x534a6, 0xd8e700c);
dwc_ddrphy_apb_wr_32b(0x534a8, 0x712cfd2f);
dwc_ddrphy_apb_wr_32b(0x534aa, 0x96219642);
dwc_ddrphy_apb_wr_32b(0x534ac, 0xfd6f0a6a);
dwc_ddrphy_apb_wr_32b(0x534ae, 0xc0b09600);
dwc_ddrphy_apb_wr_32b(0x534b0, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x534b2, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x534b4, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x534b6, 0xc1a1b6c8);
dwc_ddrphy_apb_wr_32b(0x534b8, 0x709b1600);
dwc_ddrphy_apb_wr_32b(0x534ba, 0x108000);
dwc_ddrphy_apb_wr_32b(0x534bc, 0x47284648);
dwc_ddrphy_apb_wr_32b(0x534be, 0x700c4508);
dwc_ddrphy_apb_wr_32b(0x534c0, 0xc000c040);
dwc_ddrphy_apb_wr_32b(0x534c2, 0x115082f);
dwc_ddrphy_apb_wr_32b(0x534c4, 0xb25c000);
dwc_ddrphy_apb_wr_32b(0x534c6, 0x712c302e);
dwc_ddrphy_apb_wr_32b(0x534c8, 0x2900c000);
dwc_ddrphy_apb_wr_32b(0x534ca, 0x790f001e);
dwc_ddrphy_apb_wr_32b(0x534cc, 0xff6f0a62);
dwc_ddrphy_apb_wr_32b(0x534ce, 0x202f40a1);
dwc_ddrphy_apb_wr_32b(0x534d0, 0x41a10787);
dwc_ddrphy_apb_wr_32b(0x534d2, 0x9fa42e1);
dwc_ddrphy_apb_wr_32b(0x534d4, 0x43c1ffef);
dwc_ddrphy_apb_wr_32b(0x534d6, 0x7104c000);
dwc_ddrphy_apb_wr_32b(0x534d8, 0x7487f1e8);
dwc_ddrphy_apb_wr_32b(0x534da, 0x341b1404);
dwc_ddrphy_apb_wr_32b(0x534dc, 0x78e0c6c6);
dwc_ddrphy_apb_wr_32b(0x534de, 0x260ac2e2);
dwc_ddrphy_apb_wr_32b(0x534e0, 0x43083040);
dwc_ddrphy_apb_wr_32b(0x534e2, 0x2e4570ad);
dwc_ddrphy_apb_wr_32b(0x534e4, 0xd413180);
dwc_ddrphy_apb_wr_32b(0x534e6, 0x255a1005);
dwc_ddrphy_apb_wr_32b(0x534e8, 0x71611181);
dwc_ddrphy_apb_wr_32b(0x534ea, 0x89608901);
dwc_ddrphy_apb_wr_32b(0x534ec, 0xb8088942);
dwc_ddrphy_apb_wr_32b(0x534ee, 0x89037b05);
dwc_ddrphy_apb_wr_32b(0x534f0, 0x7845b808);
dwc_ddrphy_apb_wr_32b(0x534f2, 0x2005b810);
dwc_ddrphy_apb_wr_32b(0x534f4, 0x890500c2);
dwc_ddrphy_apb_wr_32b(0x534f6, 0x77548964);
dwc_ddrphy_apb_wr_32b(0x534f8, 0x7865b808);
dwc_ddrphy_apb_wr_32b(0x534fa, 0x795bf206);
dwc_ddrphy_apb_wr_32b(0x534fc, 0xb99fb99c);
dwc_ddrphy_apb_wr_32b(0x534fe, 0xf004b100);
dwc_ddrphy_apb_wr_32b(0x53500, 0xfdcf0ed2);
dwc_ddrphy_apb_wr_32b(0x53502, 0xf1e171a5);
dwc_ddrphy_apb_wr_32b(0x53504, 0x78e0c6c2);
dwc_ddrphy_apb_wr_32b(0x53506, 0x1600c2e4);
dwc_ddrphy_apb_wr_32b(0x53508, 0x8000700e);
dwc_ddrphy_apb_wr_32b(0x5350a, 0x70540994);
dwc_ddrphy_apb_wr_32b(0x5350c, 0x3200264a);
dwc_ddrphy_apb_wr_32b(0x5350e, 0x26167cdb);
dwc_ddrphy_apb_wr_32b(0x53510, 0x23ca138b);
dwc_ddrphy_apb_wr_32b(0x53512, 0x26ca1302);
dwc_ddrphy_apb_wr_32b(0x53514, 0x16003062);
dwc_ddrphy_apb_wr_32b(0x53516, 0x80007002);
dwc_ddrphy_apb_wr_32b(0x53518, 0xa550998);
dwc_ddrphy_apb_wr_32b(0x5351a, 0x70ef03a2);
dwc_ddrphy_apb_wr_32b(0x5351c, 0x37c40e49);
dwc_ddrphy_apb_wr_32b(0x5351e, 0x2c221f5);
dwc_ddrphy_apb_wr_32b(0x53520, 0x6a9ceb09);
dwc_ddrphy_apb_wr_32b(0x53522, 0x629dbc3b);
dwc_ddrphy_apb_wr_32b(0x53524, 0x7d82bdc4);
dwc_ddrphy_apb_wr_32b(0x53526, 0x80c2a44);
dwc_ddrphy_apb_wr_32b(0x53528, 0x2204f008);
dwc_ddrphy_apb_wr_32b(0x5352a, 0xf8c);
dwc_ddrphy_apb_wr_32b(0x5352c, 0xbac9fc00);
dwc_ddrphy_apb_wr_32b(0x5352e, 0x4548bc2a);
dwc_ddrphy_apb_wr_32b(0x53530, 0x7d456c56);
dwc_ddrphy_apb_wr_32b(0x53532, 0x13422e40);
dwc_ddrphy_apb_wr_32b(0x53534, 0x7c457c1b);
dwc_ddrphy_apb_wr_32b(0x53536, 0x32422f40);
dwc_ddrphy_apb_wr_32b(0x53538, 0xba917a85);
dwc_ddrphy_apb_wr_32b(0x5353a, 0xba9fba9c);
dwc_ddrphy_apb_wr_32b(0x5353c, 0x71e7b2a0);
dwc_ddrphy_apb_wr_32b(0x5353e, 0xf1de7165);
dwc_ddrphy_apb_wr_32b(0x53540, 0xf1d571c5);
dwc_ddrphy_apb_wr_32b(0x53542, 0x78e0c6c4);
dwc_ddrphy_apb_wr_32b(0x53544, 0x45cbc0e6);
dwc_ddrphy_apb_wr_32b(0x53546, 0x9948000);
dwc_ddrphy_apb_wr_32b(0x53548, 0x221a8580);
dwc_ddrphy_apb_wr_32b(0x5354a, 0x8561030e);
dwc_ddrphy_apb_wr_32b(0x5354c, 0x3220b27);
dwc_ddrphy_apb_wr_32b(0x5354e, 0xf1f70ed);
dwc_ddrphy_apb_wr_32b(0x53550, 0x7bd010a5);
dwc_ddrphy_apb_wr_32b(0x53552, 0xcb21f4);
dwc_ddrphy_apb_wr_32b(0x53554, 0xaaec0f1);
dwc_ddrphy_apb_wr_32b(0x53556, 0xc0d1fd0f);
dwc_ddrphy_apb_wr_32b(0x53558, 0x2c41b00);
dwc_ddrphy_apb_wr_32b(0x5355a, 0x71e571c5);
dwc_ddrphy_apb_wr_32b(0x5355c, 0x7185f1f3);
dwc_ddrphy_apb_wr_32b(0x5355e, 0xc4c6f1ed);
dwc_ddrphy_apb_wr_32b(0x53560, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x53562, 0x2494b6c8);
dwc_ddrphy_apb_wr_32b(0x53564, 0x702c3e25);
dwc_ddrphy_apb_wr_32b(0x53566, 0xfd6f0b3a);
dwc_ddrphy_apb_wr_32b(0x53568, 0xc04ac04b);
dwc_ddrphy_apb_wr_32b(0x5356a, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x5356c, 0x48000);
dwc_ddrphy_apb_wr_32b(0x5356e, 0x1600c056);
dwc_ddrphy_apb_wr_32b(0x53570, 0x90047100);
dwc_ddrphy_apb_wr_32b(0x53572, 0xc058004a);
dwc_ddrphy_apb_wr_32b(0x53574, 0xfd6f096e);
dwc_ddrphy_apb_wr_32b(0x53576, 0xc00b710c);
dwc_ddrphy_apb_wr_32b(0x53578, 0xfd6f09da);
dwc_ddrphy_apb_wr_32b(0x5357a, 0x1e00712c);
dwc_ddrphy_apb_wr_32b(0x5357c, 0x900f7205);
dwc_ddrphy_apb_wr_32b(0x5357e, 0xc00be022);
dwc_ddrphy_apb_wr_32b(0x53580, 0xff6f084a);
dwc_ddrphy_apb_wr_32b(0x53582, 0xc00b712c);
dwc_ddrphy_apb_wr_32b(0x53584, 0xe7e71ad);
dwc_ddrphy_apb_wr_32b(0x53586, 0x7d180020);
dwc_ddrphy_apb_wr_32b(0x53588, 0xfdaf0cb2);
dwc_ddrphy_apb_wr_32b(0x5358a, 0x702c78af);
dwc_ddrphy_apb_wr_32b(0x5358c, 0x808208a);
dwc_ddrphy_apb_wr_32b(0x5358e, 0x70441e00);
dwc_ddrphy_apb_wr_32b(0x53590, 0xff689003);
dwc_ddrphy_apb_wr_32b(0x53592, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x53594, 0xe0049003);
dwc_ddrphy_apb_wr_32b(0x53596, 0x1e00710c);
dwc_ddrphy_apb_wr_32b(0x53598, 0x900f7004);
dwc_ddrphy_apb_wr_32b(0x5359a, 0x1e00e0c0);
dwc_ddrphy_apb_wr_32b(0x5359c, 0x90037044);
dwc_ddrphy_apb_wr_32b(0x5359e, 0x90ffe64);
dwc_ddrphy_apb_wr_32b(0x535a0, 0x714c0235);
dwc_ddrphy_apb_wr_32b(0x535a2, 0xfd0f094a);
dwc_ddrphy_apb_wr_32b(0x535a4, 0x45cbf1fb);
dwc_ddrphy_apb_wr_32b(0x535a6, 0xaaaa0000);
dwc_ddrphy_apb_wr_32b(0x535a8, 0x41a1d80f);
dwc_ddrphy_apb_wr_32b(0x535aa, 0x43a142a1);
dwc_ddrphy_apb_wr_32b(0x535ac, 0xfdaf0a2e);
dwc_ddrphy_apb_wr_32b(0x535ae, 0x972c540);
dwc_ddrphy_apb_wr_32b(0x535b0, 0x710cfd0f);
dwc_ddrphy_apb_wr_32b(0x535b2, 0xff2f09c2);
dwc_ddrphy_apb_wr_32b(0x535b4, 0x70cdd9ff);
dwc_ddrphy_apb_wr_32b(0x535b6, 0x900347cb);
dwc_ddrphy_apb_wr_32b(0x535b8, 0x208ae174);
dwc_ddrphy_apb_wr_32b(0x535ba, 0xb7c00fc7);
dwc_ddrphy_apb_wr_32b(0x535bc, 0x43dbb701);
dwc_ddrphy_apb_wr_32b(0x535be, 0xffff0000);
dwc_ddrphy_apb_wr_32b(0x535c0, 0x1f58710c);
dwc_ddrphy_apb_wr_32b(0x535c2, 0x1f5e96dc);
dwc_ddrphy_apb_wr_32b(0x535c4, 0x1f57901c);
dwc_ddrphy_apb_wr_32b(0x535c6, 0xd830901c);
dwc_ddrphy_apb_wr_32b(0x535c8, 0xfd2f0b4a);
dwc_ddrphy_apb_wr_32b(0x535ca, 0xd80f712c);
dwc_ddrphy_apb_wr_32b(0x535cc, 0x704c702c);
dwc_ddrphy_apb_wr_32b(0x535ce, 0x9ea4363);
dwc_ddrphy_apb_wr_32b(0x535d0, 0x1c00fdaf);
dwc_ddrphy_apb_wr_32b(0x535d2, 0x740c36c0);
dwc_ddrphy_apb_wr_32b(0x535d4, 0xfd2f0b32);
dwc_ddrphy_apb_wr_32b(0x535d6, 0xd80f712c);
dwc_ddrphy_apb_wr_32b(0x535d8, 0x42a141a1);
dwc_ddrphy_apb_wr_32b(0x535da, 0x9d243a1);
dwc_ddrphy_apb_wr_32b(0x535dc, 0xc540fdaf);
dwc_ddrphy_apb_wr_32b(0x535de, 0xb7c0710c);
dwc_ddrphy_apb_wr_32b(0x535e0, 0x8e2b7c1);
dwc_ddrphy_apb_wr_32b(0x535e2, 0x730cfd0f);
dwc_ddrphy_apb_wr_32b(0x535e4, 0xff2f095e);
dwc_ddrphy_apb_wr_32b(0x535e6, 0xd830d9ff);
dwc_ddrphy_apb_wr_32b(0x535e8, 0xfd2f0b0a);
dwc_ddrphy_apb_wr_32b(0x535ea, 0xc016712c);
dwc_ddrphy_apb_wr_32b(0x535ec, 0x70011600);
dwc_ddrphy_apb_wr_32b(0x535ee, 0x9948000);
dwc_ddrphy_apb_wr_32b(0x535f0, 0xc056b814);
dwc_ddrphy_apb_wr_32b(0x535f2, 0x70001600);
dwc_ddrphy_apb_wr_32b(0x535f4, 0x9988000);
dwc_ddrphy_apb_wr_32b(0x535f6, 0x620845);
dwc_ddrphy_apb_wr_32b(0x535f8, 0xfc7208a);
dwc_ddrphy_apb_wr_32b(0x535fa, 0x104c2616);
dwc_ddrphy_apb_wr_32b(0x535fc, 0xa35704c);
dwc_ddrphy_apb_wr_32b(0x535fe, 0x2a400235);
dwc_ddrphy_apb_wr_32b(0x53600, 0x29400243);
dwc_ddrphy_apb_wr_32b(0x53602, 0x78650340);
dwc_ddrphy_apb_wr_32b(0x53604, 0xf802005);
dwc_ddrphy_apb_wr_32b(0x53606, 0x649002);
dwc_ddrphy_apb_wr_32b(0x53608, 0x71449000);
dwc_ddrphy_apb_wr_32b(0x5360a, 0x1432841);
dwc_ddrphy_apb_wr_32b(0x5360c, 0x7b05b8c4);
dwc_ddrphy_apb_wr_32b(0x5360e, 0x3f802400);
dwc_ddrphy_apb_wr_32b(0x53610, 0xc700000);
dwc_ddrphy_apb_wr_32b(0x53612, 0xb0607894);
dwc_ddrphy_apb_wr_32b(0x53614, 0xf1e97185);
dwc_ddrphy_apb_wr_32b(0x53616, 0xf1dc7124);
dwc_ddrphy_apb_wr_32b(0x53618, 0x710cb700);
dwc_ddrphy_apb_wr_32b(0x5361a, 0x1f58b7c1);
dwc_ddrphy_apb_wr_32b(0x5361c, 0x1f5e96dc);
dwc_ddrphy_apb_wr_32b(0x5361e, 0x1f57901c);
dwc_ddrphy_apb_wr_32b(0x53620, 0x208a901c);
dwc_ddrphy_apb_wr_32b(0x53622, 0x1e0007d0);
dwc_ddrphy_apb_wr_32b(0x53624, 0x90037004);
dwc_ddrphy_apb_wr_32b(0x53626, 0xd830fe64);
dwc_ddrphy_apb_wr_32b(0x53628, 0xfd2f0a8a);
dwc_ddrphy_apb_wr_32b(0x5362a, 0xd80f712c);
dwc_ddrphy_apb_wr_32b(0x5362c, 0x704c702c);
dwc_ddrphy_apb_wr_32b(0x5362e, 0x92a4363);
dwc_ddrphy_apb_wr_32b(0x53630, 0x1c00fdaf);
dwc_ddrphy_apb_wr_32b(0x53632, 0x740c36c0);
dwc_ddrphy_apb_wr_32b(0x53634, 0xfd2f0a72);
dwc_ddrphy_apb_wr_32b(0x53636, 0xd80f712c);
dwc_ddrphy_apb_wr_32b(0x53638, 0x42a141a1);
dwc_ddrphy_apb_wr_32b(0x5363a, 0x91243a1);
dwc_ddrphy_apb_wr_32b(0x5363c, 0xc540fdaf);
dwc_ddrphy_apb_wr_32b(0x5363e, 0xd9ff710c);
dwc_ddrphy_apb_wr_32b(0x53640, 0x8a6b7c0);
dwc_ddrphy_apb_wr_32b(0x53642, 0xb7c1ff2f);
dwc_ddrphy_apb_wr_32b(0x53644, 0x81a710c);
dwc_ddrphy_apb_wr_32b(0x53646, 0xd830fd0f);
dwc_ddrphy_apb_wr_32b(0x53648, 0xfd2f0a4a);
dwc_ddrphy_apb_wr_32b(0x5364a, 0x1600712c);
dwc_ddrphy_apb_wr_32b(0x5364c, 0x8000700b);
dwc_ddrphy_apb_wr_32b(0x5364e, 0x16000994);
dwc_ddrphy_apb_wr_32b(0x53650, 0x80007000);
dwc_ddrphy_apb_wr_32b(0x53652, 0x8e30998);
dwc_ddrphy_apb_wr_32b(0x53654, 0x70cd02e2);
dwc_ddrphy_apb_wr_32b(0x53656, 0x12de2616);
dwc_ddrphy_apb_wr_32b(0x53658, 0x12150ed3);
dwc_ddrphy_apb_wr_32b(0x5365a, 0x301b1458);
dwc_ddrphy_apb_wr_32b(0x5365c, 0x2b40c10a);
dwc_ddrphy_apb_wr_32b(0x5365e, 0x23051300);
dwc_ddrphy_apb_wr_32b(0x53660, 0x2155301b);
dwc_ddrphy_apb_wr_32b(0x53662, 0x21050d01);
dwc_ddrphy_apb_wr_32b(0x53664, 0x264d06c1);
dwc_ddrphy_apb_wr_32b(0x53666, 0x2e4090c0);
dwc_ddrphy_apb_wr_32b(0x53668, 0x21cf1203);
dwc_ddrphy_apb_wr_32b(0x5366a, 0x78650225);
dwc_ddrphy_apb_wr_32b(0x5366c, 0x45cb793b);
dwc_ddrphy_apb_wr_32b(0x5366e, 0x9002);
dwc_ddrphy_apb_wr_32b(0x53670, 0x79a5781b);
dwc_ddrphy_apb_wr_32b(0x53672, 0xf802005);
dwc_ddrphy_apb_wr_32b(0x53674, 0x649002);
dwc_ddrphy_apb_wr_32b(0x53676, 0x90009140);
dwc_ddrphy_apb_wr_32b(0x53678, 0x2841bac4);
dwc_ddrphy_apb_wr_32b(0x5367a, 0xb8c40141);
dwc_ddrphy_apb_wr_32b(0x5367c, 0x24007905);
dwc_ddrphy_apb_wr_32b(0x5367e, 0x3f80);
dwc_ddrphy_apb_wr_32b(0x53680, 0x20f50c70);
dwc_ddrphy_apb_wr_32b(0x53682, 0x22400780);
dwc_ddrphy_apb_wr_32b(0x53684, 0x7110040c);
dwc_ddrphy_apb_wr_32b(0x53686, 0x82920d4);
dwc_ddrphy_apb_wr_32b(0x53688, 0x780e6038);
dwc_ddrphy_apb_wr_32b(0x5368a, 0x4220791c);
dwc_ddrphy_apb_wr_32b(0x5368c, 0x4990792e);
dwc_ddrphy_apb_wr_32b(0x5368e, 0x8012154);
dwc_ddrphy_apb_wr_32b(0x53690, 0x3009272f);
dwc_ddrphy_apb_wr_32b(0x53692, 0x78114990);
dwc_ddrphy_apb_wr_32b(0x53694, 0x87c208ef);
dwc_ddrphy_apb_wr_32b(0x53696, 0x4990794e);
dwc_ddrphy_apb_wr_32b(0x53698, 0x3009272f);
dwc_ddrphy_apb_wr_32b(0x5369a, 0x3f2080);
dwc_ddrphy_apb_wr_32b(0x5369c, 0x21007811);
dwc_ddrphy_apb_wr_32b(0x5369e, 0xf82);
dwc_ddrphy_apb_wr_32b(0x536a0, 0x8edffc0);
dwc_ddrphy_apb_wr_32b(0x536a2, 0x214887c2);
dwc_ddrphy_apb_wr_32b(0x536a4, 0x791b0000);
dwc_ddrphy_apb_wr_32b(0x536a6, 0x72184);
dwc_ddrphy_apb_wr_32b(0x536a8, 0x7905b8c4);
dwc_ddrphy_apb_wr_32b(0x536aa, 0x2055c00a);
dwc_ddrphy_apb_wr_32b(0x536ac, 0x23050c00);
dwc_ddrphy_apb_wr_32b(0x536ae, 0x2305301b);
dwc_ddrphy_apb_wr_32b(0x536b0, 0x787b06c3);
dwc_ddrphy_apb_wr_32b(0x536b2, 0xe177d05);
dwc_ddrphy_apb_wr_32b(0x536b4, 0xb52011f1);
dwc_ddrphy_apb_wr_32b(0x536b6, 0x6c0202f);
dwc_ddrphy_apb_wr_32b(0x536b8, 0xf802005);
dwc_ddrphy_apb_wr_32b(0x536ba, 0x10009002);
dwc_ddrphy_apb_wr_32b(0x536bc, 0x71c5b020);
dwc_ddrphy_apb_wr_32b(0x536be, 0x305e2640);
dwc_ddrphy_apb_wr_32b(0x536c0, 0x7165f198);
dwc_ddrphy_apb_wr_32b(0x536c2, 0xd8fff18d);
dwc_ddrphy_apb_wr_32b(0x536c4, 0x901c1f58);
dwc_ddrphy_apb_wr_32b(0x536c6, 0xd9ff710c);
dwc_ddrphy_apb_wr_32b(0x536c8, 0x1f5e4508);
dwc_ddrphy_apb_wr_32b(0x536ca, 0xf92901c);
dwc_ddrphy_apb_wr_32b(0x536cc, 0x1f57feef);
dwc_ddrphy_apb_wr_32b(0x536ce, 0xcfe901c);
dwc_ddrphy_apb_wr_32b(0x536d0, 0xd80ffe0f);
dwc_ddrphy_apb_wr_32b(0x536d2, 0x73841e00);
dwc_ddrphy_apb_wr_32b(0x536d4, 0xe0049003);
dwc_ddrphy_apb_wr_32b(0x536d6, 0x73441e00);
dwc_ddrphy_apb_wr_32b(0x536d8, 0xe0c0900f);
dwc_ddrphy_apb_wr_32b(0x536da, 0x73841e00);
dwc_ddrphy_apb_wr_32b(0x536dc, 0xfec49003);
dwc_ddrphy_apb_wr_32b(0x536de, 0x73841e00);
dwc_ddrphy_apb_wr_32b(0x536e0, 0xff689003);
dwc_ddrphy_apb_wr_32b(0x536e2, 0xfd6f0802);
dwc_ddrphy_apb_wr_32b(0x536e4, 0x208ad90f);
dwc_ddrphy_apb_wr_32b(0x536e6, 0x41000090);
dwc_ddrphy_apb_wr_32b(0x536e8, 0xd80fc040);
dwc_ddrphy_apb_wr_32b(0x536ea, 0xfb2704c);
dwc_ddrphy_apb_wr_32b(0x536ec, 0x4320fd6f);
dwc_ddrphy_apb_wr_32b(0x536ee, 0x3f802400);
dwc_ddrphy_apb_wr_32b(0x536f0, 0xc5c0000);
dwc_ddrphy_apb_wr_32b(0x536f2, 0xf72702c);
dwc_ddrphy_apb_wr_32b(0x536f4, 0xda14fdef);
dwc_ddrphy_apb_wr_32b(0x536f6, 0xf4e68b);
dwc_ddrphy_apb_wr_32b(0x536f8, 0x700c002d);
dwc_ddrphy_apb_wr_32b(0x536fa, 0xfd2f08e6);
dwc_ddrphy_apb_wr_32b(0x536fc, 0x1600712c);
dwc_ddrphy_apb_wr_32b(0x536fe, 0x8000700d);
dwc_ddrphy_apb_wr_32b(0x53700, 0x706f098c);
dwc_ddrphy_apb_wr_32b(0x53702, 0xc0554063);
dwc_ddrphy_apb_wr_32b(0x53704, 0x70001600);
dwc_ddrphy_apb_wr_32b(0x53706, 0x9908000);
dwc_ddrphy_apb_wr_32b(0x53708, 0x36208bf);
dwc_ddrphy_apb_wr_32b(0x5370a, 0xc00ad90f);
dwc_ddrphy_apb_wr_32b(0x5370c, 0x104f2544);
dwc_ddrphy_apb_wr_32b(0x5370e, 0x780f7bbc);
dwc_ddrphy_apb_wr_32b(0x53710, 0xc217c057);
dwc_ddrphy_apb_wr_32b(0x53712, 0x41e1786f);
dwc_ddrphy_apb_wr_32b(0x53714, 0xfdaf0e42);
dwc_ddrphy_apb_wr_32b(0x53716, 0x889c059);
dwc_ddrphy_apb_wr_32b(0x53718, 0xbb0c0030);
dwc_ddrphy_apb_wr_32b(0x5371a, 0xc018c10a);
dwc_ddrphy_apb_wr_32b(0x5371c, 0x78e47839);
dwc_ddrphy_apb_wr_32b(0x5371e, 0x7865b80a);
dwc_ddrphy_apb_wr_32b(0x53720, 0xe36781b);
dwc_ddrphy_apb_wr_32b(0x53722, 0x2300fccf);
dwc_ddrphy_apb_wr_32b(0x53724, 0xe82f301b);
dwc_ddrphy_apb_wr_32b(0x53726, 0x2055c00a);
dwc_ddrphy_apb_wr_32b(0x53728, 0xc0160d01);
dwc_ddrphy_apb_wr_32b(0x5372a, 0x78657825);
dwc_ddrphy_apb_wr_32b(0x5372c, 0x2f40791b);
dwc_ddrphy_apb_wr_32b(0x5372e, 0x78251240);
dwc_ddrphy_apb_wr_32b(0x53730, 0xf822005);
dwc_ddrphy_apb_wr_32b(0x53732, 0x9002);
dwc_ddrphy_apb_wr_32b(0x53734, 0x40209220);
dwc_ddrphy_apb_wr_32b(0x53736, 0x1f2084);
dwc_ddrphy_apb_wr_32b(0x53738, 0x8054208c);
dwc_ddrphy_apb_wr_32b(0x5373a, 0x250044);
dwc_ddrphy_apb_wr_32b(0x5373c, 0x8002155);
dwc_ddrphy_apb_wr_32b(0x5373e, 0x70c01600);
dwc_ddrphy_apb_wr_32b(0x53740, 0x18000);
dwc_ddrphy_apb_wr_32b(0x53742, 0x710c7014);
dwc_ddrphy_apb_wr_32b(0x53744, 0xc20bf65a);
dwc_ddrphy_apb_wr_32b(0x53746, 0x41c3740c);
dwc_ddrphy_apb_wr_32b(0x53748, 0x2024a);
dwc_ddrphy_apb_wr_32b(0x5374a, 0xfd6f0842);
dwc_ddrphy_apb_wr_32b(0x5374c, 0xc01943a1);
dwc_ddrphy_apb_wr_32b(0x5374e, 0xdd6c217);
dwc_ddrphy_apb_wr_32b(0x53750, 0x41e1feef);
dwc_ddrphy_apb_wr_32b(0x53752, 0x2400f00b);
dwc_ddrphy_apb_wr_32b(0x53754, 0x3f80);
dwc_ddrphy_apb_wr_32b(0x53756, 0x60b80c5c);
dwc_ddrphy_apb_wr_32b(0x53758, 0x431800);
dwc_ddrphy_apb_wr_32b(0x5375a, 0xf00bc015);
dwc_ddrphy_apb_wr_32b(0x5375c, 0xc015b200);
dwc_ddrphy_apb_wr_32b(0x5375e, 0x3f812400);
dwc_ddrphy_apb_wr_32b(0x53760, 0xc5c0000);
dwc_ddrphy_apb_wr_32b(0x53762, 0x190061b9);
dwc_ddrphy_apb_wr_32b(0x53764, 0x71a50003);
dwc_ddrphy_apb_wr_32b(0x53766, 0xefaf19d);
dwc_ddrphy_apb_wr_32b(0x53768, 0xd80ffd2f);
dwc_ddrphy_apb_wr_32b(0x5376a, 0xfe0f0bc6);
dwc_ddrphy_apb_wr_32b(0x5376c, 0x815c015);
dwc_ddrphy_apb_wr_32b(0x5376e, 0x71c58030);
dwc_ddrphy_apb_wr_32b(0x53770, 0x70c01600);
dwc_ddrphy_apb_wr_32b(0x53772, 0x18000);
dwc_ddrphy_apb_wr_32b(0x53774, 0x1627014);
dwc_ddrphy_apb_wr_32b(0x53776, 0x2378002b);
dwc_ddrphy_apb_wr_32b(0x53778, 0x41c33000);
dwc_ddrphy_apb_wr_32b(0x5377a, 0x24d);
dwc_ddrphy_apb_wr_32b(0x5377c, 0xfc8f09ee);
dwc_ddrphy_apb_wr_32b(0x5377e, 0x70c01600);
dwc_ddrphy_apb_wr_32b(0x53780, 0x3fe8000);
dwc_ddrphy_apb_wr_32b(0x53782, 0x2587014);
dwc_ddrphy_apb_wr_32b(0x53784, 0x2456002a);
dwc_ddrphy_apb_wr_32b(0x53786, 0x702c3fc0);
dwc_ddrphy_apb_wr_32b(0x53788, 0xfdef0e46);
dwc_ddrphy_apb_wr_32b(0x5378a, 0x2400da28);
dwc_ddrphy_apb_wr_32b(0x5378c, 0x3f80);
dwc_ddrphy_apb_wr_32b(0x5378e, 0xe3a0144);
dwc_ddrphy_apb_wr_32b(0x53790, 0xdab4fdef);
dwc_ddrphy_apb_wr_32b(0x53792, 0x724cc00a);
dwc_ddrphy_apb_wr_32b(0x53794, 0xd012055);
dwc_ddrphy_apb_wr_32b(0x53796, 0x7825c016);
dwc_ddrphy_apb_wr_32b(0x53798, 0x3fc12456);
dwc_ddrphy_apb_wr_32b(0x5379a, 0xfeaf0ea2);
dwc_ddrphy_apb_wr_32b(0x5379c, 0xc00ac057);
dwc_ddrphy_apb_wr_32b(0x5379e, 0x301b1458);
dwc_ddrphy_apb_wr_32b(0x537a0, 0x3f812400);
dwc_ddrphy_apb_wr_32b(0x537a2, 0x1440000);
dwc_ddrphy_apb_wr_32b(0x537a4, 0xc002055);
dwc_ddrphy_apb_wr_32b(0x537a6, 0x6c02005);
dwc_ddrphy_apb_wr_32b(0x537a8, 0xe86da09);
dwc_ddrphy_apb_wr_32b(0x537aa, 0x4318feaf);
dwc_ddrphy_apb_wr_32b(0x537ac, 0x3f802400);
dwc_ddrphy_apb_wr_32b(0x537ae, 0x2340000);
dwc_ddrphy_apb_wr_32b(0x537b0, 0x42c3);
dwc_ddrphy_apb_wr_32b(0x537b2, 0xdf20a28);
dwc_ddrphy_apb_wr_32b(0x537b4, 0x702cfdef);
dwc_ddrphy_apb_wr_32b(0x537b6, 0x3f802400);
dwc_ddrphy_apb_wr_32b(0x537b8, 0x2200000);
dwc_ddrphy_apb_wr_32b(0x537ba, 0xde2d9ff);
dwc_ddrphy_apb_wr_32b(0x537bc, 0xda14fdef);
dwc_ddrphy_apb_wr_32b(0x537be, 0x3f802400);
dwc_ddrphy_apb_wr_32b(0x537c0, 0x11c0000);
dwc_ddrphy_apb_wr_32b(0x537c2, 0x3fc12456);
dwc_ddrphy_apb_wr_32b(0x537c4, 0xfdef0dba);
dwc_ddrphy_apb_wr_32b(0x537c6, 0xc09ada28);
dwc_ddrphy_apb_wr_32b(0x537c8, 0x3f812400);
dwc_ddrphy_apb_wr_32b(0x537ca, 0x1440000);
dwc_ddrphy_apb_wr_32b(0x537cc, 0xfdef0daa);
dwc_ddrphy_apb_wr_32b(0x537ce, 0x2400dab4);
dwc_ddrphy_apb_wr_32b(0x537d0, 0x3f80);
dwc_ddrphy_apb_wr_32b(0x537d2, 0xc19a011c);
dwc_ddrphy_apb_wr_32b(0x537d4, 0xfd2f0aaa);
dwc_ddrphy_apb_wr_32b(0x537d6, 0x83f228a);
dwc_ddrphy_apb_wr_32b(0x537d8, 0xe5c170ad);
dwc_ddrphy_apb_wr_32b(0x537da, 0x2600dc);
dwc_ddrphy_apb_wr_32b(0x537dc, 0x2400724c);
dwc_ddrphy_apb_wr_32b(0x537de, 0x3f81);
dwc_ddrphy_apb_wr_32b(0x537e0, 0xaca011c);
dwc_ddrphy_apb_wr_32b(0x537e2, 0xc017ffef);
dwc_ddrphy_apb_wr_32b(0x537e4, 0xc19a4063);
dwc_ddrphy_apb_wr_32b(0x537e6, 0xffef0abe);
dwc_ddrphy_apb_wr_32b(0x537e8, 0xacada09);
dwc_ddrphy_apb_wr_32b(0x537ea, 0xd80ffe0f);
dwc_ddrphy_apb_wr_32b(0x537ec, 0xfd2f0dee);
dwc_ddrphy_apb_wr_32b(0x537ee, 0xc2ed90f);
dwc_ddrphy_apb_wr_32b(0x537f0, 0x1600fccf);
dwc_ddrphy_apb_wr_32b(0x537f2, 0x80007001);
dwc_ddrphy_apb_wr_32b(0x537f4, 0x1600098c);
dwc_ddrphy_apb_wr_32b(0x537f6, 0x80007000);
dwc_ddrphy_apb_wr_32b(0x537f8, 0x8490990);
dwc_ddrphy_apb_wr_32b(0x537fa, 0x714c0062);
dwc_ddrphy_apb_wr_32b(0x537fc, 0xfccf0c4a);
dwc_ddrphy_apb_wr_32b(0x537fe, 0xfccf0c86);
dwc_ddrphy_apb_wr_32b(0x53800, 0x40209060);
dwc_ddrphy_apb_wr_32b(0x53802, 0x82209a);
dwc_ddrphy_apb_wr_32b(0x53804, 0x3f822400);
dwc_ddrphy_apb_wr_32b(0x53806, 0x2340000);
dwc_ddrphy_apb_wr_32b(0x53808, 0x78b46058);
dwc_ddrphy_apb_wr_32b(0x5380a, 0x18740d21);
dwc_ddrphy_apb_wr_32b(0x5380c, 0xeb0eb060);
dwc_ddrphy_apb_wr_32b(0x5380e, 0x3f802400);
dwc_ddrphy_apb_wr_32b(0x53810, 0x2200000);
dwc_ddrphy_apb_wr_32b(0x53812, 0x1200603a);
dwc_ddrphy_apb_wr_32b(0x53814, 0x80d00c0);
dwc_ddrphy_apb_wr_32b(0x53816, 0x25420033);
dwc_ddrphy_apb_wr_32b(0x53818, 0xaa001840);
dwc_ddrphy_apb_wr_32b(0x5381a, 0xf1db7124);
dwc_ddrphy_apb_wr_32b(0x5381c, 0x3f802400);
dwc_ddrphy_apb_wr_32b(0x5381e, 0x11c0000);
dwc_ddrphy_apb_wr_32b(0x53820, 0xfd2f0a12);
dwc_ddrphy_apb_wr_32b(0x53822, 0x71a5c19a);
dwc_ddrphy_apb_wr_32b(0x53824, 0x1600f1b5);
dwc_ddrphy_apb_wr_32b(0x53826, 0x8000700d);
dwc_ddrphy_apb_wr_32b(0x53828, 0x1600098c);
dwc_ddrphy_apb_wr_32b(0x5382a, 0x80007000);
dwc_ddrphy_apb_wr_32b(0x5382c, 0x75100990);
dwc_ddrphy_apb_wr_32b(0x5382e, 0xffc906a0);
dwc_ddrphy_apb_wr_32b(0x53830, 0x3f802400);
dwc_ddrphy_apb_wr_32b(0x53832, 0xc5c0000);
dwc_ddrphy_apb_wr_32b(0x53834, 0xe89260a8);
dwc_ddrphy_apb_wr_32b(0x53836, 0x740cc20b);
dwc_ddrphy_apb_wr_32b(0x53838, 0x24c41c3);
dwc_ddrphy_apb_wr_32b(0x5383a, 0xe620002);
dwc_ddrphy_apb_wr_32b(0x5383c, 0x43a1fd2f);
dwc_ddrphy_apb_wr_32b(0x5383e, 0x2544c00a);
dwc_ddrphy_apb_wr_32b(0x53840, 0x7a0f1041);
dwc_ddrphy_apb_wr_32b(0x53842, 0xbee78bd);
dwc_ddrphy_apb_wr_32b(0x53844, 0x780ffeef);
dwc_ddrphy_apb_wr_32b(0x53846, 0xf1e371a5);
dwc_ddrphy_apb_wr_32b(0x53848, 0x24e41c3);
dwc_ddrphy_apb_wr_32b(0x5384a, 0xe420000);
dwc_ddrphy_apb_wr_32b(0x5384c, 0x740cfd2f);
dwc_ddrphy_apb_wr_32b(0x5384e, 0x700d1600);
dwc_ddrphy_apb_wr_32b(0x53850, 0x98c8000);
dwc_ddrphy_apb_wr_32b(0x53852, 0x70001600);
dwc_ddrphy_apb_wr_32b(0x53854, 0x9908000);
dwc_ddrphy_apb_wr_32b(0x53856, 0x3620889);
dwc_ddrphy_apb_wr_32b(0x53858, 0xc08cd925);
dwc_ddrphy_apb_wr_32b(0x5385a, 0xca2702c);
dwc_ddrphy_apb_wr_32b(0x5385c, 0xda24fdef);
dwc_ddrphy_apb_wr_32b(0x5385e, 0xe2c0704c);
dwc_ddrphy_apb_wr_32b(0x53860, 0xd0040);
dwc_ddrphy_apb_wr_32b(0x53862, 0xb39706c);
dwc_ddrphy_apb_wr_32b(0x53864, 0x40a10815);
dwc_ddrphy_apb_wr_32b(0x53866, 0x82209a);
dwc_ddrphy_apb_wr_32b(0x53868, 0x3f812400);
dwc_ddrphy_apb_wr_32b(0x5386a, 0x2340000);
dwc_ddrphy_apb_wr_32b(0x5386c, 0x2b416119);
dwc_ddrphy_apb_wr_32b(0x5386e, 0x60580080);
dwc_ddrphy_apb_wr_32b(0x53870, 0x21f4);
dwc_ddrphy_apb_wr_32b(0x53872, 0x795de80a);
dwc_ddrphy_apb_wr_32b(0x53874, 0x6119c08c);
dwc_ddrphy_apb_wr_32b(0x53876, 0x234e8180);
dwc_ddrphy_apb_wr_32b(0x53878, 0x240f0700);
dwc_ddrphy_apb_wr_32b(0x5387a, 0xa1001000);
dwc_ddrphy_apb_wr_32b(0x5387c, 0xf1e77464);
dwc_ddrphy_apb_wr_32b(0x5387e, 0xf1e1e208);
dwc_ddrphy_apb_wr_32b(0x53880, 0x300b1430);
dwc_ddrphy_apb_wr_32b(0x53882, 0xc211c30d);
dwc_ddrphy_apb_wr_32b(0x53884, 0xc013c112);
dwc_ddrphy_apb_wr_32b(0x53886, 0xc60fc70e);
dwc_ddrphy_apb_wr_32b(0x53888, 0xc046c410);
dwc_ddrphy_apb_wr_32b(0x5388a, 0xc244c145);
dwc_ddrphy_apb_wr_32b(0x5388c, 0x740cc340);
dwc_ddrphy_apb_wr_32b(0x5388e, 0x24f41c3);
dwc_ddrphy_apb_wr_32b(0x53890, 0x42a10009);
dwc_ddrphy_apb_wr_32b(0x53892, 0xc4434361);
dwc_ddrphy_apb_wr_32b(0x53894, 0xdaec642);
dwc_ddrphy_apb_wr_32b(0x53896, 0xc741fd2f);
dwc_ddrphy_apb_wr_32b(0x53898, 0xf1ba71a5);
dwc_ddrphy_apb_wr_32b(0x5389a, 0xda2740c);
dwc_ddrphy_apb_wr_32b(0x5389c, 0xb914fd2f);
dwc_ddrphy_apb_wr_32b(0x5389e, 0x2456c017);
dwc_ddrphy_apb_wr_32b(0x538a0, 0x94a3fc1);
dwc_ddrphy_apb_wr_32b(0x538a2, 0x724cffef);
dwc_ddrphy_apb_wr_32b(0x538a4, 0x24004063);
dwc_ddrphy_apb_wr_32b(0x538a6, 0x3f81);
dwc_ddrphy_apb_wr_32b(0x538a8, 0x93a0144);
dwc_ddrphy_apb_wr_32b(0x538aa, 0xda09ffef);
dwc_ddrphy_apb_wr_32b(0x538ac, 0xfe0f0942);
dwc_ddrphy_apb_wr_32b(0x538ae, 0x70051e00);
dwc_ddrphy_apb_wr_32b(0x538b0, 0xe0049003);
dwc_ddrphy_apb_wr_32b(0x538b2, 0x9e6c00b);
dwc_ddrphy_apb_wr_32b(0x538b4, 0x702cff2f);
dwc_ddrphy_apb_wr_32b(0x538b6, 0xb5ec00b);
dwc_ddrphy_apb_wr_32b(0x538b8, 0x702cfd2f);
dwc_ddrphy_apb_wr_32b(0x538ba, 0xfd2f0ae2);
dwc_ddrphy_apb_wr_32b(0x538bc, 0x2494700c);
dwc_ddrphy_apb_wr_32b(0x538be, 0x1404321a);
dwc_ddrphy_apb_wr_32b(0x538c0, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x538c2, 0xb7c81c78);
dwc_ddrphy_apb_wr_32b(0x538c4, 0x41c3c081);
dwc_ddrphy_apb_wr_32b(0x538c6, 0x7b28000);
dwc_ddrphy_apb_wr_32b(0x538c8, 0xfc6f0ef2);
dwc_ddrphy_apb_wr_32b(0x538ca, 0xc081da84);
dwc_ddrphy_apb_wr_32b(0x538cc, 0xffef0826);
dwc_ddrphy_apb_wr_32b(0x538ce, 0xb32d984);
dwc_ddrphy_apb_wr_32b(0x538d0, 0x1488fccf);
dwc_ddrphy_apb_wr_32b(0x538d2, 0x7ee0341f);
dwc_ddrphy_apb_wr_32b(0x538d4, 0x1cfcc2e6);
dwc_ddrphy_apb_wr_32b(0x538d6, 0x2494b6c8);
dwc_ddrphy_apb_wr_32b(0x538d8, 0xc0463fac);
dwc_ddrphy_apb_wr_32b(0x538da, 0x70801600);
dwc_ddrphy_apb_wr_32b(0x538dc, 0x48000);
dwc_ddrphy_apb_wr_32b(0x538de, 0xa9ac157);
dwc_ddrphy_apb_wr_32b(0x538e0, 0xc051fd6f);
dwc_ddrphy_apb_wr_32b(0x538e2, 0x8e82208c);
dwc_ddrphy_apb_wr_32b(0x538e4, 0xf706ddfe);
dwc_ddrphy_apb_wr_32b(0x538e6, 0xfd4f0a8a);
dwc_ddrphy_apb_wr_32b(0x538e8, 0x88d2054);
dwc_ddrphy_apb_wr_32b(0x538ea, 0x71001600);
dwc_ddrphy_apb_wr_32b(0x538ec, 0xaa9004);
dwc_ddrphy_apb_wr_32b(0x538ee, 0xb880c05a);
dwc_ddrphy_apb_wr_32b(0x538f0, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x538f2, 0xe0aa9005);
dwc_ddrphy_apb_wr_32b(0x538f4, 0xffef0f9e);
dwc_ddrphy_apb_wr_32b(0x538f6, 0x105b2544);
dwc_ddrphy_apb_wr_32b(0x538f8, 0x800047cb);
dwc_ddrphy_apb_wr_32b(0x538fa, 0x8f0003f9);
dwc_ddrphy_apb_wr_32b(0x538fc, 0x2044712c);
dwc_ddrphy_apb_wr_32b(0x538fe, 0xf208808b);
dwc_ddrphy_apb_wr_32b(0x53900, 0xb88f700c);
dwc_ddrphy_apb_wr_32b(0x53902, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x53904, 0xe0029003);
dwc_ddrphy_apb_wr_32b(0x53906, 0x2300c006);
dwc_ddrphy_apb_wr_32b(0x53908, 0x1c20335b);
dwc_ddrphy_apb_wr_32b(0x5390a, 0x290036c0);
dwc_ddrphy_apb_wr_32b(0x5390c, 0xd840000e);
dwc_ddrphy_apb_wr_32b(0x5390e, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x53910, 0xe0269003);
dwc_ddrphy_apb_wr_32b(0x53912, 0x1e00d898);
dwc_ddrphy_apb_wr_32b(0x53914, 0x90057004);
dwc_ddrphy_apb_wr_32b(0x53916, 0xc006e04c);
dwc_ddrphy_apb_wr_32b(0x53918, 0x900841c3);
dwc_ddrphy_apb_wr_32b(0x5391a, 0x21f401c0);
dwc_ddrphy_apb_wr_32b(0x5391c, 0x9109001b);
dwc_ddrphy_apb_wr_32b(0x5391e, 0xc006c052);
dwc_ddrphy_apb_wr_32b(0x53920, 0x2056781b);
dwc_ddrphy_apb_wr_32b(0x53922, 0xb450e00);
dwc_ddrphy_apb_wr_32b(0x53924, 0xc0471030);
dwc_ddrphy_apb_wr_32b(0x53926, 0x4208a);
dwc_ddrphy_apb_wr_32b(0x53928, 0xfcef0be2);
dwc_ddrphy_apb_wr_32b(0x5392a, 0xab2d9ff);
dwc_ddrphy_apb_wr_32b(0x5392c, 0xc143fccf);
dwc_ddrphy_apb_wr_32b(0x5392e, 0xc141c142);
dwc_ddrphy_apb_wr_32b(0x53930, 0xfcef0caa);
dwc_ddrphy_apb_wr_32b(0x53932, 0x78cfc140);
dwc_ddrphy_apb_wr_32b(0x53934, 0x700cc042);
dwc_ddrphy_apb_wr_32b(0x53936, 0xc040b88c);
dwc_ddrphy_apb_wr_32b(0x53938, 0xd980c008);
dwc_ddrphy_apb_wr_32b(0x5393a, 0x7b0fb990);
dwc_ddrphy_apb_wr_32b(0x5393c, 0x724cd8ff);
dwc_ddrphy_apb_wr_32b(0x5393e, 0xc8ec543);
dwc_ddrphy_apb_wr_32b(0x53940, 0xc541fcef);
dwc_ddrphy_apb_wr_32b(0x53942, 0xfccf0986);
dwc_ddrphy_apb_wr_32b(0x53944, 0x41c3c093);
dwc_ddrphy_apb_wr_32b(0x53946, 0x8948000);
dwc_ddrphy_apb_wr_32b(0x53948, 0xfdef0ab2);
dwc_ddrphy_apb_wr_32b(0x5394a, 0xc007da0e);
dwc_ddrphy_apb_wr_32b(0x5394c, 0x2005d9ff);
dwc_ddrphy_apb_wr_32b(0x5394e, 0x90090f80);
dwc_ddrphy_apb_wr_32b(0x53950, 0xc05be000);
dwc_ddrphy_apb_wr_32b(0x53952, 0xc106b020);
dwc_ddrphy_apb_wr_32b(0x53954, 0xff2f0952);
dwc_ddrphy_apb_wr_32b(0x53956, 0x1600c093);
dwc_ddrphy_apb_wr_32b(0x53958, 0x80007100);
dwc_ddrphy_apb_wr_32b(0x5395a, 0x20ad0898);
dwc_ddrphy_apb_wr_32b(0x5395c, 0xe80c0241);
dwc_ddrphy_apb_wr_32b(0x5395e, 0x700851);
dwc_ddrphy_apb_wr_32b(0x53960, 0x84d724c);
dwc_ddrphy_apb_wr_32b(0x53962, 0x704c00f0);
dwc_ddrphy_apb_wr_32b(0x53964, 0xb10843);
dwc_ddrphy_apb_wr_32b(0x53966, 0xf020744c);
dwc_ddrphy_apb_wr_32b(0x53968, 0x71011600);
dwc_ddrphy_apb_wr_32b(0x5396a, 0x89e8000);
dwc_ddrphy_apb_wr_32b(0x5396c, 0xf802104);
dwc_ddrphy_apb_wr_32b(0x5396e, 0xfe3f0000);
dwc_ddrphy_apb_wr_32b(0x53970, 0x30041c56);
dwc_ddrphy_apb_wr_32b(0x53972, 0x2032c006);
dwc_ddrphy_apb_wr_32b(0x53974, 0x80000f80);
dwc_ddrphy_apb_wr_32b(0x53976, 0x7e0b007e);
dwc_ddrphy_apb_wr_32b(0x53978, 0x6912f425);
dwc_ddrphy_apb_wr_32b(0x5397a, 0x71011600);
dwc_ddrphy_apb_wr_32b(0x5397c, 0x8968000);
dwc_ddrphy_apb_wr_32b(0x5397e, 0x1c2084);
dwc_ddrphy_apb_wr_32b(0x53980, 0xf812104);
dwc_ddrphy_apb_wr_32b(0x53982, 0xf8ff0000);
dwc_ddrphy_apb_wr_32b(0x53984, 0x764cf016);
dwc_ddrphy_apb_wr_32b(0x53986, 0x71001600);
dwc_ddrphy_apb_wr_32b(0x53988, 0x89e8000);
dwc_ddrphy_apb_wr_32b(0x5398a, 0xf802004);
dwc_ddrphy_apb_wr_32b(0x5398c, 0xfe3f0000);
dwc_ddrphy_apb_wr_32b(0x5398e, 0x30041c56);
dwc_ddrphy_apb_wr_32b(0x53990, 0x71001600);
dwc_ddrphy_apb_wr_32b(0x53992, 0x8968000);
dwc_ddrphy_apb_wr_32b(0x53994, 0xf812004);
dwc_ddrphy_apb_wr_32b(0x53996, 0xf8ff0000);
dwc_ddrphy_apb_wr_32b(0x53998, 0x2002a40);
dwc_ddrphy_apb_wr_32b(0x5399a, 0x1c4e7825);
dwc_ddrphy_apb_wr_32b(0x5399c, 0xdd0f3004);
dwc_ddrphy_apb_wr_32b(0x5399e, 0x78b2bd08);
dwc_ddrphy_apb_wr_32b(0x539a0, 0x78cfc049);
dwc_ddrphy_apb_wr_32b(0x539a2, 0x714cc193);
dwc_ddrphy_apb_wr_32b(0x539a4, 0x2b40db40);
dwc_ddrphy_apb_wr_32b(0x539a6, 0x852321b);
dwc_ddrphy_apb_wr_32b(0x539a8, 0xc047ffaf);
dwc_ddrphy_apb_wr_32b(0x539aa, 0xc193c006);
dwc_ddrphy_apb_wr_32b(0x539ac, 0xff6f0c7a);
dwc_ddrphy_apb_wr_32b(0x539ae, 0xc011714c);
dwc_ddrphy_apb_wr_32b(0x539b0, 0x2005b815);
dwc_ddrphy_apb_wr_32b(0x539b2, 0x90090f81);
dwc_ddrphy_apb_wr_32b(0x539b4, 0xc158e1e0);
dwc_ddrphy_apb_wr_32b(0x539b6, 0xf802005);
dwc_ddrphy_apb_wr_32b(0x539b8, 0x1e09008);
dwc_ddrphy_apb_wr_32b(0x539ba, 0xc0189020);
dwc_ddrphy_apb_wr_32b(0x539bc, 0xb988c15c);
dwc_ddrphy_apb_wr_32b(0x539be, 0x8f00b020);
dwc_ddrphy_apb_wr_32b(0x539c0, 0x7f0889);
dwc_ddrphy_apb_wr_32b(0x539c2, 0x4208a);
dwc_ddrphy_apb_wr_32b(0x539c4, 0xfcef0aaa);
dwc_ddrphy_apb_wr_32b(0x539c6, 0xca00d9ff);
dwc_ddrphy_apb_wr_32b(0x539c8, 0x754c702c);
dwc_ddrphy_apb_wr_32b(0x539ca, 0xa002054);
dwc_ddrphy_apb_wr_32b(0x539cc, 0xd8ff7b0f);
dwc_ddrphy_apb_wr_32b(0x539ce, 0xc1434628);
dwc_ddrphy_apb_wr_32b(0x539d0, 0xc141c142);
dwc_ddrphy_apb_wr_32b(0x539d2, 0xfcef0b66);
dwc_ddrphy_apb_wr_32b(0x539d4, 0x882c140);
dwc_ddrphy_apb_wr_32b(0x539d6, 0xc643fccf);
dwc_ddrphy_apb_wr_32b(0x539d8, 0xc641c642);
dwc_ddrphy_apb_wr_32b(0x539da, 0xfcef0b56);
dwc_ddrphy_apb_wr_32b(0x539dc, 0x852c640);
dwc_ddrphy_apb_wr_32b(0x539de, 0x70edfccf);
dwc_ddrphy_apb_wr_32b(0x539e0, 0x208abf8f);
dwc_ddrphy_apb_wr_32b(0x539e2, 0x1e000004);
dwc_ddrphy_apb_wr_32b(0x539e4, 0x900373c4);
dwc_ddrphy_apb_wr_32b(0x539e6, 0xa66e002);
dwc_ddrphy_apb_wr_32b(0x539e8, 0xd9fffcef);
dwc_ddrphy_apb_wr_32b(0x539ea, 0x30831200);
dwc_ddrphy_apb_wr_32b(0x539ec, 0xfccf091a);
dwc_ddrphy_apb_wr_32b(0x539ee, 0xc642c643);
dwc_ddrphy_apb_wr_32b(0x539f0, 0xb2ac641);
dwc_ddrphy_apb_wr_32b(0x539f2, 0xc640fcef);
dwc_ddrphy_apb_wr_32b(0x539f4, 0xd980c007);
dwc_ddrphy_apb_wr_32b(0x539f6, 0xc042bf23);
dwc_ddrphy_apb_wr_32b(0x539f8, 0xb990c008);
dwc_ddrphy_apb_wr_32b(0x539fa, 0x7b0f724c);
dwc_ddrphy_apb_wr_32b(0x539fc, 0xc643d8ff);
dwc_ddrphy_apb_wr_32b(0x539fe, 0xb0ec641);
dwc_ddrphy_apb_wr_32b(0x53a00, 0xc740fcef);
dwc_ddrphy_apb_wr_32b(0x53a02, 0xfccf0806);
dwc_ddrphy_apb_wr_32b(0x53a04, 0xc012c109);
dwc_ddrphy_apb_wr_32b(0x53a06, 0x335b2304);
dwc_ddrphy_apb_wr_32b(0x53a08, 0x36c01c64);
dwc_ddrphy_apb_wr_32b(0x53a0a, 0x8327824);
dwc_ddrphy_apb_wr_32b(0x53a0c, 0xc052fd6f);
dwc_ddrphy_apb_wr_32b(0x53a0e, 0x208ac049);
dwc_ddrphy_apb_wr_32b(0x53a10, 0xa120004);
dwc_ddrphy_apb_wr_32b(0x53a12, 0x712cfcef);
dwc_ddrphy_apb_wr_32b(0x53a14, 0xfccf08de);
dwc_ddrphy_apb_wr_32b(0x53a16, 0xc142c143);
dwc_ddrphy_apb_wr_32b(0x53a18, 0xadac141);
dwc_ddrphy_apb_wr_32b(0x53a1a, 0xc140fcef);
dwc_ddrphy_apb_wr_32b(0x53a1c, 0xfcef0d42);
dwc_ddrphy_apb_wr_32b(0x53a1e, 0xc007d8ff);
dwc_ddrphy_apb_wr_32b(0x53a20, 0x73cd70ed);
dwc_ddrphy_apb_wr_32b(0x53a22, 0xbf8cc042);
dwc_ddrphy_apb_wr_32b(0x53a24, 0x41c3d8ff);
dwc_ddrphy_apb_wr_32b(0x53a26, 0xc0001);
dwc_ddrphy_apb_wr_32b(0x53a28, 0x746c714c);
dwc_ddrphy_apb_wr_32b(0x53a2a, 0xc541c643);
dwc_ddrphy_apb_wr_32b(0x53a2c, 0xab2c740);
dwc_ddrphy_apb_wr_32b(0x53a2e, 0x4338fcef);
dwc_ddrphy_apb_wr_32b(0x53a30, 0x6f34c007);
dwc_ddrphy_apb_wr_32b(0x53a32, 0xc042724c);
dwc_ddrphy_apb_wr_32b(0x53a34, 0x746cd8ff);
dwc_ddrphy_apb_wr_32b(0x53a36, 0xc541c543);
dwc_ddrphy_apb_wr_32b(0x53a38, 0xfcef0a9a);
dwc_ddrphy_apb_wr_32b(0x53a3a, 0xc007c740);
dwc_ddrphy_apb_wr_32b(0x53a3c, 0x714c4163);
dwc_ddrphy_apb_wr_32b(0x53a3e, 0xd8ffc042);
dwc_ddrphy_apb_wr_32b(0x53a40, 0xc643746c);
dwc_ddrphy_apb_wr_32b(0x53a42, 0xa86c541);
dwc_ddrphy_apb_wr_32b(0x53a44, 0xc740fcef);
dwc_ddrphy_apb_wr_32b(0x53a46, 0x702cc008);
dwc_ddrphy_apb_wr_32b(0x53a48, 0x780f754c);
dwc_ddrphy_apb_wr_32b(0x53a4a, 0xc308c048);
dwc_ddrphy_apb_wr_32b(0x53a4c, 0xc543d8ff);
dwc_ddrphy_apb_wr_32b(0x53a4e, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x53a50, 0xfcef0a6a);
dwc_ddrphy_apb_wr_32b(0x53a52, 0xc009c540);
dwc_ddrphy_apb_wr_32b(0x53a54, 0xc543714c);
dwc_ddrphy_apb_wr_32b(0x53a56, 0x2044e01e);
dwc_ddrphy_apb_wr_32b(0x53a58, 0xc0090041);
dwc_ddrphy_apb_wr_32b(0x53a5a, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x53a5c, 0xe01e6038);
dwc_ddrphy_apb_wr_32b(0x53a5e, 0xd8ff7b0f);
dwc_ddrphy_apb_wr_32b(0x53a60, 0xa4a742c);
dwc_ddrphy_apb_wr_32b(0x53a62, 0xc740fcef);
dwc_ddrphy_apb_wr_32b(0x53a64, 0x8626f33);
dwc_ddrphy_apb_wr_32b(0x53a66, 0xc643fccf);
dwc_ddrphy_apb_wr_32b(0x53a68, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x53a6a, 0xfcef0a36);
dwc_ddrphy_apb_wr_32b(0x53a6c, 0x846c540);
dwc_ddrphy_apb_wr_32b(0x53a6e, 0xc543fccf);
dwc_ddrphy_apb_wr_32b(0x53a70, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x53a72, 0xfcef0a26);
dwc_ddrphy_apb_wr_32b(0x53a74, 0xc66c540);
dwc_ddrphy_apb_wr_32b(0x53a76, 0xd8fffcef);
dwc_ddrphy_apb_wr_32b(0x53a78, 0xfc8f0f3a);
dwc_ddrphy_apb_wr_32b(0x53a7a, 0xc542c543);
dwc_ddrphy_apb_wr_32b(0x53a7c, 0xa12c541);
dwc_ddrphy_apb_wr_32b(0x53a7e, 0xc540fcef);
dwc_ddrphy_apb_wr_32b(0x53a80, 0x40c3);
dwc_ddrphy_apb_wr_32b(0x53a82, 0x1e006210);
dwc_ddrphy_apb_wr_32b(0x53a84, 0x90037004);
dwc_ddrphy_apb_wr_32b(0x53a86, 0x730ce004);
dwc_ddrphy_apb_wr_32b(0x53a88, 0xfcef09ca);
dwc_ddrphy_apb_wr_32b(0x53a8a, 0x208a712c);
dwc_ddrphy_apb_wr_32b(0x53a8c, 0x1e000408);
dwc_ddrphy_apb_wr_32b(0x53a8e, 0x90037004);
dwc_ddrphy_apb_wr_32b(0x53a90, 0x1600e004);
dwc_ddrphy_apb_wr_32b(0x53a92, 0x80007080);
dwc_ddrphy_apb_wr_32b(0x53a94, 0x80d0001);
dwc_ddrphy_apb_wr_32b(0x53a96, 0x208a00bf);
dwc_ddrphy_apb_wr_32b(0x53a98, 0xf0030606);
dwc_ddrphy_apb_wr_32b(0x53a9a, 0x9a6d833);
dwc_ddrphy_apb_wr_32b(0x53a9c, 0x712cfcef);
dwc_ddrphy_apb_wr_32b(0x53a9e, 0xc112c011);
dwc_ddrphy_apb_wr_32b(0x53aa0, 0xc051b814);
dwc_ddrphy_apb_wr_32b(0x53aa2, 0x7825c019);
dwc_ddrphy_apb_wr_32b(0x53aa4, 0x1600c049);
dwc_ddrphy_apb_wr_32b(0x53aa6, 0x800070c0);
dwc_ddrphy_apb_wr_32b(0x53aa8, 0x701403fe);
dwc_ddrphy_apb_wr_32b(0x53aaa, 0x2a0154);
dwc_ddrphy_apb_wr_32b(0x53aac, 0x2400702c);
dwc_ddrphy_apb_wr_32b(0x53aae, 0x3f80);
dwc_ddrphy_apb_wr_32b(0x53ab0, 0xff601dc);
dwc_ddrphy_apb_wr_32b(0x53ab2, 0x228afdaf);
dwc_ddrphy_apb_wr_32b(0x53ab4, 0x24560a1e);
dwc_ddrphy_apb_wr_32b(0x53ab6, 0xfea3940);
dwc_ddrphy_apb_wr_32b(0x53ab8, 0xdab4fdaf);
dwc_ddrphy_apb_wr_32b(0x53aba, 0x39402456);
dwc_ddrphy_apb_wr_32b(0x53abc, 0x89a712c);
dwc_ddrphy_apb_wr_32b(0x53abe, 0x704cfeaf);
dwc_ddrphy_apb_wr_32b(0x53ac0, 0x2456c09d);
dwc_ddrphy_apb_wr_32b(0x53ac2, 0xfbe3941);
dwc_ddrphy_apb_wr_32b(0x53ac4, 0xdab4fdaf);
dwc_ddrphy_apb_wr_32b(0x53ac6, 0x218aca09);
dwc_ddrphy_apb_wr_32b(0x53ac8, 0xb8050a3f);
dwc_ddrphy_apb_wr_32b(0x53aca, 0x7c22040);
dwc_ddrphy_apb_wr_32b(0x53acc, 0xc7ec09d);
dwc_ddrphy_apb_wr_32b(0x53ace, 0x4358fcef);
dwc_ddrphy_apb_wr_32b(0x53ad0, 0xfc7218a);
dwc_ddrphy_apb_wr_32b(0x53ad2, 0x900340c3);
dwc_ddrphy_apb_wr_32b(0x53ad4, 0x70ade174);
dwc_ddrphy_apb_wr_32b(0x53ad6, 0x800046cb);
dwc_ddrphy_apb_wr_32b(0x53ad8, 0xb020098c);
dwc_ddrphy_apb_wr_32b(0x53ada, 0xd55b021);
dwc_ddrphy_apb_wr_32b(0x53adc, 0xc09d1c75);
dwc_ddrphy_apb_wr_32b(0x53ade, 0x9ce);
dwc_ddrphy_apb_wr_32b(0x53ae0, 0xfdcf0cda);
dwc_ddrphy_apb_wr_32b(0x53ae2, 0x802d80f);
dwc_ddrphy_apb_wr_32b(0x53ae4, 0xd90ffd2f);
dwc_ddrphy_apb_wr_32b(0x53ae6, 0xfc8f0e3e);
dwc_ddrphy_apb_wr_32b(0x53ae8, 0x86018620);
dwc_ddrphy_apb_wr_32b(0x53aea, 0x620829);
dwc_ddrphy_apb_wr_32b(0x53aec, 0xe6ac09d);
dwc_ddrphy_apb_wr_32b(0x53aee, 0x6961fc8f);
dwc_ddrphy_apb_wr_32b(0x53af0, 0x881219a);
dwc_ddrphy_apb_wr_32b(0x53af2, 0xfc8f0e9e);
dwc_ddrphy_apb_wr_32b(0x53af4, 0x24009040);
dwc_ddrphy_apb_wr_32b(0x53af6, 0x3f80);
dwc_ddrphy_apb_wr_32b(0x53af8, 0x603801dc);
dwc_ddrphy_apb_wr_32b(0x53afa, 0xb04078b4);
dwc_ddrphy_apb_wr_32b(0x53afc, 0xf1ed4160);
dwc_ddrphy_apb_wr_32b(0x53afe, 0xc1a712c);
dwc_ddrphy_apb_wr_32b(0x53b00, 0x4263fcef);
dwc_ddrphy_apb_wr_32b(0x53b02, 0xf1d971a5);
dwc_ddrphy_apb_wr_32b(0x53b04, 0x23e41c3);
dwc_ddrphy_apb_wr_32b(0x53b06, 0x8ca0000);
dwc_ddrphy_apb_wr_32b(0x53b08, 0x740cfd2f);
dwc_ddrphy_apb_wr_32b(0x53b0a, 0x860186a0);
dwc_ddrphy_apb_wr_32b(0x53b0c, 0x362087d);
dwc_ddrphy_apb_wr_32b(0x53b0e, 0xc08ad909);
dwc_ddrphy_apb_wr_32b(0x53b10, 0xf36702c);
dwc_ddrphy_apb_wr_32b(0x53b12, 0xda1cfdaf);
dwc_ddrphy_apb_wr_32b(0x53b14, 0xc550941);
dwc_ddrphy_apb_wr_32b(0x53b16, 0xa39704c);
dwc_ddrphy_apb_wr_32b(0x53b18, 0x40a10815);
dwc_ddrphy_apb_wr_32b(0x53b1a, 0x881209a);
dwc_ddrphy_apb_wr_32b(0x53b1c, 0x3f832400);
dwc_ddrphy_apb_wr_32b(0x53b1e, 0x1dc0000);
dwc_ddrphy_apb_wr_32b(0x53b20, 0x2a41631b);
dwc_ddrphy_apb_wr_32b(0x53b22, 0x60380080);
dwc_ddrphy_apb_wr_32b(0x53b24, 0x23f4);
dwc_ddrphy_apb_wr_32b(0x53b26, 0x7b3de88a);
dwc_ddrphy_apb_wr_32b(0x53b28, 0x631bc08a);
dwc_ddrphy_apb_wr_32b(0x53b2a, 0x224e8380);
dwc_ddrphy_apb_wr_32b(0x53b2c, 0x240f0700);
dwc_ddrphy_apb_wr_32b(0x53b2e, 0xa3001000);
dwc_ddrphy_apb_wr_32b(0x53b30, 0xf1e77444);
dwc_ddrphy_apb_wr_32b(0x53b32, 0xf1e2e108);
dwc_ddrphy_apb_wr_32b(0x53b34, 0x300b1428);
dwc_ddrphy_apb_wr_32b(0x53b36, 0xc20dc30b);
dwc_ddrphy_apb_wr_32b(0x53b38, 0xc00fc10e);
dwc_ddrphy_apb_wr_32b(0x53b3a, 0xc143c40c);
dwc_ddrphy_apb_wr_32b(0x53b3c, 0xc242c044);
dwc_ddrphy_apb_wr_32b(0x53b3e, 0x740cc340);
dwc_ddrphy_apb_wr_32b(0x53b40, 0x23f41c3);
dwc_ddrphy_apb_wr_32b(0x53b42, 0x42a10007);
dwc_ddrphy_apb_wr_32b(0x53b44, 0x84e4361);
dwc_ddrphy_apb_wr_32b(0x53b46, 0xc441fd2f);
dwc_ddrphy_apb_wr_32b(0x53b48, 0xf1c371a5);
dwc_ddrphy_apb_wr_32b(0x53b4a, 0x842740c);
dwc_ddrphy_apb_wr_32b(0x53b4c, 0xb916fd2f);
dwc_ddrphy_apb_wr_32b(0x53b4e, 0x2008ee);
dwc_ddrphy_apb_wr_32b(0x53b50, 0x39402456);
dwc_ddrphy_apb_wr_32b(0x53b52, 0xfdcf0bf6);
dwc_ddrphy_apb_wr_32b(0x53b54, 0x704cc009);
dwc_ddrphy_apb_wr_32b(0x53b56, 0x70041e00);
dwc_ddrphy_apb_wr_32b(0x53b58, 0xe1d29009);
dwc_ddrphy_apb_wr_32b(0x53b5a, 0x2032c006);
dwc_ddrphy_apb_wr_32b(0x53b5c, 0x80000f81);
dwc_ddrphy_apb_wr_32b(0x53b5e, 0xc01b007e);
dwc_ddrphy_apb_wr_32b(0x53b60, 0xc193b020);
dwc_ddrphy_apb_wr_32b(0x53b62, 0xff6f090e);
dwc_ddrphy_apb_wr_32b(0x53b64, 0x40c3c006);
dwc_ddrphy_apb_wr_32b(0x53b66, 0x8948000);
dwc_ddrphy_apb_wr_32b(0x53b68, 0xa9a712c);
dwc_ddrphy_apb_wr_32b(0x53b6a, 0xda40ffaf);
dwc_ddrphy_apb_wr_32b(0x53b6c, 0x70adc01a);
dwc_ddrphy_apb_wr_32b(0x53b6e, 0x1e00712c);
dwc_ddrphy_apb_wr_32b(0x53b70, 0x90057004);
dwc_ddrphy_apb_wr_32b(0x53b72, 0x1e00e0aa);
dwc_ddrphy_apb_wr_32b(0x53b74, 0x90037344);
dwc_ddrphy_apb_wr_32b(0x53b76, 0x1e00e002);
dwc_ddrphy_apb_wr_32b(0x53b78, 0x90037344);
dwc_ddrphy_apb_wr_32b(0x53b7a, 0xf3ee026);
dwc_ddrphy_apb_wr_32b(0x53b7c, 0x208afcaf);
dwc_ddrphy_apb_wr_32b(0x53b7e, 0x12000004);
dwc_ddrphy_apb_wr_32b(0x53b80, 0xdf23083);
dwc_ddrphy_apb_wr_32b(0x53b82, 0xc543fc8f);
dwc_ddrphy_apb_wr_32b(0x53b84, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x53b86, 0xfcaf0ffe);
dwc_ddrphy_apb_wr_32b(0x53b88, 0xc007c540);
dwc_ddrphy_apb_wr_32b(0x53b8a, 0x702cc308);
dwc_ddrphy_apb_wr_32b(0x53b8c, 0xd8ffc042);
dwc_ddrphy_apb_wr_32b(0x53b8e, 0x724cb990);
dwc_ddrphy_apb_wr_32b(0x53b90, 0xc541c543);
dwc_ddrphy_apb_wr_32b(0x53b92, 0xfcaf0fe6);
dwc_ddrphy_apb_wr_32b(0x53b94, 0xd02c740);
dwc_ddrphy_apb_wr_32b(0x53b96, 0xc543fc8f);
dwc_ddrphy_apb_wr_32b(0x53b98, 0xc541c542);
dwc_ddrphy_apb_wr_32b(0x53b9a, 0xfcaf0fd6);
dwc_ddrphy_apb_wr_32b(0x53b9c, 0xcd2c540);
dwc_ddrphy_apb_wr_32b(0x53b9e, 0xc11cfc8f);
dwc_ddrphy_apb_wr_32b(0x53ba0, 0x704cc018);
dwc_ddrphy_apb_wr_32b(0x53ba2, 0x1e00b020);
dwc_ddrphy_apb_wr_32b(0x53ba4, 0x90037344);
dwc_ddrphy_apb_wr_32b(0x53ba6, 0xc017e004);
dwc_ddrphy_apb_wr_32b(0x53ba8, 0xfe6f0ec2);
dwc_ddrphy_apb_wr_32b(0x53baa, 0xc006702c);
dwc_ddrphy_apb_wr_32b(0x53bac, 0xfcef0eae);
dwc_ddrphy_apb_wr_32b(0x53bae, 0xc111702c);
dwc_ddrphy_apb_wr_32b(0x53bb0, 0xd002055);
dwc_ddrphy_apb_wr_32b(0x53bb2, 0x7825714c);
dwc_ddrphy_apb_wr_32b(0x53bb4, 0xaa6c117);
dwc_ddrphy_apb_wr_32b(0x53bb6, 0x706cffaf);
dwc_ddrphy_apb_wr_32b(0x53bb8, 0xfeaf0d3a);
dwc_ddrphy_apb_wr_32b(0x53bba, 0xb26c006);
dwc_ddrphy_apb_wr_32b(0x53bbc, 0xf96fdcf);
dwc_ddrphy_apb_wr_32b(0x53bbe, 0x2494fe4f);
dwc_ddrphy_apb_wr_32b(0x53bc0, 0x14043093);
dwc_ddrphy_apb_wr_32b(0x53bc2, 0xc6c6341b);
dwc_ddrphy_apb_wr_32b(0x53bc4, 0x43c3c0e4);
dwc_ddrphy_apb_wr_32b(0x53bc6, 0x9948000);
dwc_ddrphy_apb_wr_32b(0x53bc8, 0x7c5b8340);
dwc_ddrphy_apb_wr_32b(0x53bca, 0x9438321);
dwc_ddrphy_apb_wr_32b(0x53bcc, 0x706d00a2);
dwc_ddrphy_apb_wr_32b(0x53bce, 0x11550b37);
dwc_ddrphy_apb_wr_32b(0x53bd0, 0x30e20f5);
dwc_ddrphy_apb_wr_32b(0x53bd2, 0x6e3c7185);
dwc_ddrphy_apb_wr_32b(0x53bd4, 0x663db93b);
dwc_ddrphy_apb_wr_32b(0x53bd6, 0x7d22bdc4);
dwc_ddrphy_apb_wr_32b(0x53bd8, 0x18012e44);
dwc_ddrphy_apb_wr_32b(0x53bda, 0x2105b90a);
dwc_ddrphy_apb_wr_32b(0x53bdc, 0x2b40034e);
dwc_ddrphy_apb_wr_32b(0x53bde, 0x2a40124d);
dwc_ddrphy_apb_wr_32b(0x53be0, 0x79a50341);
dwc_ddrphy_apb_wr_32b(0x53be2, 0xf812105);
dwc_ddrphy_apb_wr_32b(0x53be4, 0x649002);
dwc_ddrphy_apb_wr_32b(0x53be6, 0x7465b1c0);
dwc_ddrphy_apb_wr_32b(0x53be8, 0x7144f1e6);
dwc_ddrphy_apb_wr_32b(0x53bea, 0xc4c4f1e0);
dwc_ddrphy_apb_wr_32b(0x53bec, 0x0);
dwc_ddrphy_apb_wr_32b(0x53bee, 0x0);
dwc_ddrphy_apb_wr_32b(0x53bf0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53bf2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53bf4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53bf6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53bf8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53bfa, 0x0);
dwc_ddrphy_apb_wr_32b(0x53bfc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53bfe, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c00, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c02, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c04, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c06, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c08, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c10, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c12, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c14, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c16, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c18, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c20, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c22, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c24, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c26, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c28, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c30, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c32, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c34, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c36, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c38, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c40, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c42, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c44, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c46, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c48, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c50, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c52, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c54, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c56, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c58, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c60, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c62, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c64, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c66, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c68, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c70, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c72, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c74, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c76, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c78, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c80, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c82, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c84, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c86, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c88, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c90, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c92, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c94, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c96, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c98, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53c9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ca0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ca2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ca4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ca6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ca8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53caa, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cac, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cae, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cba, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cca, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ccc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cce, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cda, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cdc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cde, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ce0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ce2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ce4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ce6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ce8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cea, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cec, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cee, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cf0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cf2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cf4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cf6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cf8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cfa, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cfc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53cfe, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d00, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d02, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d04, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d06, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d08, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d10, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d12, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d14, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d16, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d18, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d20, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d22, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d24, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d26, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d28, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d30, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d32, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d34, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d36, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d38, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d40, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d42, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d44, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d46, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d48, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d50, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d52, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d54, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d56, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d58, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d60, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d62, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d64, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d66, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d68, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d70, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d72, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d74, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d76, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d78, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d80, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d82, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d84, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d86, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d88, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d90, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d92, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d94, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d96, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d98, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53d9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53da0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53da2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53da4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53da6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53da8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53daa, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dac, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dae, 0x0);
dwc_ddrphy_apb_wr_32b(0x53db0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53db2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53db4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53db6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53db8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dba, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dca, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dcc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dce, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dda, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ddc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dde, 0x0);
dwc_ddrphy_apb_wr_32b(0x53de0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53de2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53de4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53de6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53de8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dea, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dec, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dee, 0x0);
dwc_ddrphy_apb_wr_32b(0x53df0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53df2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53df4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53df6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53df8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dfa, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dfc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53dfe, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e00, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e02, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e04, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e06, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e08, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e10, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e12, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e14, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e16, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e18, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e20, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e22, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e24, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e26, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e28, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e30, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e32, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e34, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e36, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e38, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e40, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e42, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e44, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e46, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e48, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e50, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e52, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e54, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e56, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e58, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e60, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e62, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e64, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e66, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e68, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e70, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e72, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e74, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e76, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e78, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e80, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e82, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e84, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e86, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e88, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e90, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e92, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e94, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e96, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e98, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53e9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ea0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ea2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ea4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ea6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ea8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53eaa, 0x0);
dwc_ddrphy_apb_wr_32b(0x53eac, 0x0);
dwc_ddrphy_apb_wr_32b(0x53eae, 0x0);
dwc_ddrphy_apb_wr_32b(0x53eb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53eb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53eb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53eb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53eb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53eba, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ebc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ebe, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ec0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ec2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ec4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ec6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ec8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53eca, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ecc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ece, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ed0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ed2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ed4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ed6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ed8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53eda, 0x0);
dwc_ddrphy_apb_wr_32b(0x53edc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ede, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ee0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ee2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ee4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ee6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ee8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53eea, 0x0);
dwc_ddrphy_apb_wr_32b(0x53eec, 0x0);
dwc_ddrphy_apb_wr_32b(0x53eee, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ef0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ef2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ef4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ef6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ef8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53efa, 0x0);
dwc_ddrphy_apb_wr_32b(0x53efc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53efe, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f00, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f02, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f04, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f06, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f08, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f10, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f12, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f14, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f16, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f18, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f20, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f22, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f24, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f26, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f28, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f30, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f32, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f34, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f36, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f38, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f40, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f42, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f44, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f46, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f48, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f50, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f52, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f54, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f56, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f58, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f60, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f62, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f64, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f66, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f68, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f70, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f72, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f74, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f76, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f78, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f80, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f82, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f84, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f86, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f88, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f90, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f92, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f94, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f96, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f98, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x53f9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fa0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fa2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fa4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fa6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fa8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53faa, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fac, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fae, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fba, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fca, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fcc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fce, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fda, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fdc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fde, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fe0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fe2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fe4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fe6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fe8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fea, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fec, 0x0);
dwc_ddrphy_apb_wr_32b(0x53fee, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ff0, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ff2, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ff4, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ff6, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ff8, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ffa, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ffc, 0x0);
dwc_ddrphy_apb_wr_32b(0x53ffe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54000, 0x0);
dwc_ddrphy_apb_wr_32b(0x54002, 0x0);
dwc_ddrphy_apb_wr_32b(0x54004, 0x0);
dwc_ddrphy_apb_wr_32b(0x54006, 0x0);
dwc_ddrphy_apb_wr_32b(0x54008, 0x0);
dwc_ddrphy_apb_wr_32b(0x5400a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5400c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5400e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54010, 0x0);
dwc_ddrphy_apb_wr_32b(0x54012, 0x0);
dwc_ddrphy_apb_wr_32b(0x54014, 0x0);
dwc_ddrphy_apb_wr_32b(0x54016, 0x0);
dwc_ddrphy_apb_wr_32b(0x54018, 0x0);
dwc_ddrphy_apb_wr_32b(0x5401a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5401c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5401e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54020, 0x0);
dwc_ddrphy_apb_wr_32b(0x54022, 0x0);
dwc_ddrphy_apb_wr_32b(0x54024, 0x0);
dwc_ddrphy_apb_wr_32b(0x54026, 0x0);
dwc_ddrphy_apb_wr_32b(0x54028, 0x0);
dwc_ddrphy_apb_wr_32b(0x5402a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5402c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5402e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54030, 0x0);
dwc_ddrphy_apb_wr_32b(0x54032, 0x0);
dwc_ddrphy_apb_wr_32b(0x54034, 0x0);
dwc_ddrphy_apb_wr_32b(0x54036, 0x0);
dwc_ddrphy_apb_wr_32b(0x54038, 0x0);
dwc_ddrphy_apb_wr_32b(0x5403a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5403c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5403e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54040, 0x0);
dwc_ddrphy_apb_wr_32b(0x54042, 0x0);
dwc_ddrphy_apb_wr_32b(0x54044, 0x0);
dwc_ddrphy_apb_wr_32b(0x54046, 0x0);
dwc_ddrphy_apb_wr_32b(0x54048, 0x0);
dwc_ddrphy_apb_wr_32b(0x5404a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5404c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5404e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54050, 0x0);
dwc_ddrphy_apb_wr_32b(0x54052, 0x0);
dwc_ddrphy_apb_wr_32b(0x54054, 0x0);
dwc_ddrphy_apb_wr_32b(0x54056, 0x0);
dwc_ddrphy_apb_wr_32b(0x54058, 0x0);
dwc_ddrphy_apb_wr_32b(0x5405a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5405c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5405e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54060, 0x0);
dwc_ddrphy_apb_wr_32b(0x54062, 0x0);
dwc_ddrphy_apb_wr_32b(0x54064, 0x0);
dwc_ddrphy_apb_wr_32b(0x54066, 0x0);
dwc_ddrphy_apb_wr_32b(0x54068, 0x0);
dwc_ddrphy_apb_wr_32b(0x5406a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5406c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5406e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54070, 0x0);
dwc_ddrphy_apb_wr_32b(0x54072, 0x0);
dwc_ddrphy_apb_wr_32b(0x54074, 0x0);
dwc_ddrphy_apb_wr_32b(0x54076, 0x0);
dwc_ddrphy_apb_wr_32b(0x54078, 0x0);
dwc_ddrphy_apb_wr_32b(0x5407a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5407c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5407e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54080, 0x0);
dwc_ddrphy_apb_wr_32b(0x54082, 0x0);
dwc_ddrphy_apb_wr_32b(0x54084, 0x0);
dwc_ddrphy_apb_wr_32b(0x54086, 0x0);
dwc_ddrphy_apb_wr_32b(0x54088, 0x0);
dwc_ddrphy_apb_wr_32b(0x5408a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5408c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5408e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54090, 0x0);
dwc_ddrphy_apb_wr_32b(0x54092, 0x0);
dwc_ddrphy_apb_wr_32b(0x54094, 0x0);
dwc_ddrphy_apb_wr_32b(0x54096, 0x0);
dwc_ddrphy_apb_wr_32b(0x54098, 0x0);
dwc_ddrphy_apb_wr_32b(0x5409a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5409c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5409e, 0x0);
dwc_ddrphy_apb_wr_32b(0x540a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x540a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x540a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x540a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x540a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x540aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x540ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x540ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x540b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x540b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x540b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x540b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x540b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x540ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x540bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x540be, 0x0);
dwc_ddrphy_apb_wr_32b(0x540c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x540c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x540c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x540c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x540c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x540ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x540cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x540ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x540d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x540d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x540d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x540d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x540d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x540da, 0x0);
dwc_ddrphy_apb_wr_32b(0x540dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x540de, 0x0);
dwc_ddrphy_apb_wr_32b(0x540e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x540e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x540e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x540e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x540e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x540ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x540ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x540ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x540f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x540f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x540f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x540f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x540f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x540fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x540fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x540fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54100, 0x0);
dwc_ddrphy_apb_wr_32b(0x54102, 0x0);
dwc_ddrphy_apb_wr_32b(0x54104, 0x0);
dwc_ddrphy_apb_wr_32b(0x54106, 0x0);
dwc_ddrphy_apb_wr_32b(0x54108, 0x0);
dwc_ddrphy_apb_wr_32b(0x5410a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5410c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5410e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54110, 0x0);
dwc_ddrphy_apb_wr_32b(0x54112, 0x0);
dwc_ddrphy_apb_wr_32b(0x54114, 0x0);
dwc_ddrphy_apb_wr_32b(0x54116, 0x0);
dwc_ddrphy_apb_wr_32b(0x54118, 0x0);
dwc_ddrphy_apb_wr_32b(0x5411a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5411c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5411e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54120, 0x0);
dwc_ddrphy_apb_wr_32b(0x54122, 0x0);
dwc_ddrphy_apb_wr_32b(0x54124, 0x0);
dwc_ddrphy_apb_wr_32b(0x54126, 0x0);
dwc_ddrphy_apb_wr_32b(0x54128, 0x0);
dwc_ddrphy_apb_wr_32b(0x5412a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5412c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5412e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54130, 0x0);
dwc_ddrphy_apb_wr_32b(0x54132, 0x0);
dwc_ddrphy_apb_wr_32b(0x54134, 0x0);
dwc_ddrphy_apb_wr_32b(0x54136, 0x0);
dwc_ddrphy_apb_wr_32b(0x54138, 0x0);
dwc_ddrphy_apb_wr_32b(0x5413a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5413c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5413e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54140, 0x0);
dwc_ddrphy_apb_wr_32b(0x54142, 0x0);
dwc_ddrphy_apb_wr_32b(0x54144, 0x0);
dwc_ddrphy_apb_wr_32b(0x54146, 0x0);
dwc_ddrphy_apb_wr_32b(0x54148, 0x0);
dwc_ddrphy_apb_wr_32b(0x5414a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5414c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5414e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54150, 0x0);
dwc_ddrphy_apb_wr_32b(0x54152, 0x0);
dwc_ddrphy_apb_wr_32b(0x54154, 0x0);
dwc_ddrphy_apb_wr_32b(0x54156, 0x0);
dwc_ddrphy_apb_wr_32b(0x54158, 0x0);
dwc_ddrphy_apb_wr_32b(0x5415a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5415c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5415e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54160, 0x0);
dwc_ddrphy_apb_wr_32b(0x54162, 0x0);
dwc_ddrphy_apb_wr_32b(0x54164, 0x0);
dwc_ddrphy_apb_wr_32b(0x54166, 0x0);
dwc_ddrphy_apb_wr_32b(0x54168, 0x0);
dwc_ddrphy_apb_wr_32b(0x5416a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5416c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5416e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54170, 0x0);
dwc_ddrphy_apb_wr_32b(0x54172, 0x0);
dwc_ddrphy_apb_wr_32b(0x54174, 0x0);
dwc_ddrphy_apb_wr_32b(0x54176, 0x0);
dwc_ddrphy_apb_wr_32b(0x54178, 0x0);
dwc_ddrphy_apb_wr_32b(0x5417a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5417c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5417e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54180, 0x0);
dwc_ddrphy_apb_wr_32b(0x54182, 0x0);
dwc_ddrphy_apb_wr_32b(0x54184, 0x0);
dwc_ddrphy_apb_wr_32b(0x54186, 0x0);
dwc_ddrphy_apb_wr_32b(0x54188, 0x0);
dwc_ddrphy_apb_wr_32b(0x5418a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5418c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5418e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54190, 0x0);
dwc_ddrphy_apb_wr_32b(0x54192, 0x0);
dwc_ddrphy_apb_wr_32b(0x54194, 0x0);
dwc_ddrphy_apb_wr_32b(0x54196, 0x0);
dwc_ddrphy_apb_wr_32b(0x54198, 0x0);
dwc_ddrphy_apb_wr_32b(0x5419a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5419c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5419e, 0x0);
dwc_ddrphy_apb_wr_32b(0x541a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x541a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x541a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x541a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x541a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x541aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x541ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x541ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x541b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x541b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x541b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x541b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x541b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x541ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x541bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x541be, 0x0);
dwc_ddrphy_apb_wr_32b(0x541c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x541c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x541c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x541c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x541c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x541ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x541cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x541ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x541d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x541d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x541d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x541d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x541d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x541da, 0x0);
dwc_ddrphy_apb_wr_32b(0x541dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x541de, 0x0);
dwc_ddrphy_apb_wr_32b(0x541e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x541e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x541e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x541e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x541e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x541ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x541ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x541ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x541f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x541f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x541f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x541f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x541f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x541fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x541fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x541fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54200, 0x0);
dwc_ddrphy_apb_wr_32b(0x54202, 0x0);
dwc_ddrphy_apb_wr_32b(0x54204, 0x0);
dwc_ddrphy_apb_wr_32b(0x54206, 0x0);
dwc_ddrphy_apb_wr_32b(0x54208, 0x0);
dwc_ddrphy_apb_wr_32b(0x5420a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5420c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5420e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54210, 0x0);
dwc_ddrphy_apb_wr_32b(0x54212, 0x0);
dwc_ddrphy_apb_wr_32b(0x54214, 0x0);
dwc_ddrphy_apb_wr_32b(0x54216, 0x0);
dwc_ddrphy_apb_wr_32b(0x54218, 0x0);
dwc_ddrphy_apb_wr_32b(0x5421a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5421c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5421e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54220, 0x0);
dwc_ddrphy_apb_wr_32b(0x54222, 0x0);
dwc_ddrphy_apb_wr_32b(0x54224, 0x0);
dwc_ddrphy_apb_wr_32b(0x54226, 0x0);
dwc_ddrphy_apb_wr_32b(0x54228, 0x0);
dwc_ddrphy_apb_wr_32b(0x5422a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5422c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5422e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54230, 0x0);
dwc_ddrphy_apb_wr_32b(0x54232, 0x0);
dwc_ddrphy_apb_wr_32b(0x54234, 0x0);
dwc_ddrphy_apb_wr_32b(0x54236, 0x0);
dwc_ddrphy_apb_wr_32b(0x54238, 0x0);
dwc_ddrphy_apb_wr_32b(0x5423a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5423c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5423e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54240, 0x0);
dwc_ddrphy_apb_wr_32b(0x54242, 0x0);
dwc_ddrphy_apb_wr_32b(0x54244, 0x0);
dwc_ddrphy_apb_wr_32b(0x54246, 0x0);
dwc_ddrphy_apb_wr_32b(0x54248, 0x0);
dwc_ddrphy_apb_wr_32b(0x5424a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5424c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5424e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54250, 0x0);
dwc_ddrphy_apb_wr_32b(0x54252, 0x0);
dwc_ddrphy_apb_wr_32b(0x54254, 0x0);
dwc_ddrphy_apb_wr_32b(0x54256, 0x0);
dwc_ddrphy_apb_wr_32b(0x54258, 0x0);
dwc_ddrphy_apb_wr_32b(0x5425a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5425c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5425e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54260, 0x0);
dwc_ddrphy_apb_wr_32b(0x54262, 0x0);
dwc_ddrphy_apb_wr_32b(0x54264, 0x0);
dwc_ddrphy_apb_wr_32b(0x54266, 0x0);
dwc_ddrphy_apb_wr_32b(0x54268, 0x0);
dwc_ddrphy_apb_wr_32b(0x5426a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5426c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5426e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54270, 0x0);
dwc_ddrphy_apb_wr_32b(0x54272, 0x0);
dwc_ddrphy_apb_wr_32b(0x54274, 0x0);
dwc_ddrphy_apb_wr_32b(0x54276, 0x0);
dwc_ddrphy_apb_wr_32b(0x54278, 0x0);
dwc_ddrphy_apb_wr_32b(0x5427a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5427c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5427e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54280, 0x0);
dwc_ddrphy_apb_wr_32b(0x54282, 0x0);
dwc_ddrphy_apb_wr_32b(0x54284, 0x0);
dwc_ddrphy_apb_wr_32b(0x54286, 0x0);
dwc_ddrphy_apb_wr_32b(0x54288, 0x0);
dwc_ddrphy_apb_wr_32b(0x5428a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5428c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5428e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54290, 0x0);
dwc_ddrphy_apb_wr_32b(0x54292, 0x0);
dwc_ddrphy_apb_wr_32b(0x54294, 0x0);
dwc_ddrphy_apb_wr_32b(0x54296, 0x0);
dwc_ddrphy_apb_wr_32b(0x54298, 0x0);
dwc_ddrphy_apb_wr_32b(0x5429a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5429c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5429e, 0x0);
dwc_ddrphy_apb_wr_32b(0x542a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x542a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x542a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x542a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x542a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x542aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x542ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x542ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x542b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x542b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x542b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x542b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x542b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x542ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x542bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x542be, 0x0);
dwc_ddrphy_apb_wr_32b(0x542c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x542c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x542c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x542c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x542c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x542ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x542cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x542ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x542d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x542d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x542d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x542d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x542d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x542da, 0x0);
dwc_ddrphy_apb_wr_32b(0x542dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x542de, 0x0);
dwc_ddrphy_apb_wr_32b(0x542e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x542e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x542e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x542e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x542e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x542ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x542ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x542ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x542f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x542f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x542f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x542f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x542f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x542fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x542fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x542fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54300, 0x0);
dwc_ddrphy_apb_wr_32b(0x54302, 0x0);
dwc_ddrphy_apb_wr_32b(0x54304, 0x0);
dwc_ddrphy_apb_wr_32b(0x54306, 0x0);
dwc_ddrphy_apb_wr_32b(0x54308, 0x0);
dwc_ddrphy_apb_wr_32b(0x5430a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5430c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5430e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54310, 0x0);
dwc_ddrphy_apb_wr_32b(0x54312, 0x0);
dwc_ddrphy_apb_wr_32b(0x54314, 0x0);
dwc_ddrphy_apb_wr_32b(0x54316, 0x0);
dwc_ddrphy_apb_wr_32b(0x54318, 0x0);
dwc_ddrphy_apb_wr_32b(0x5431a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5431c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5431e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54320, 0x0);
dwc_ddrphy_apb_wr_32b(0x54322, 0x0);
dwc_ddrphy_apb_wr_32b(0x54324, 0x0);
dwc_ddrphy_apb_wr_32b(0x54326, 0x0);
dwc_ddrphy_apb_wr_32b(0x54328, 0x0);
dwc_ddrphy_apb_wr_32b(0x5432a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5432c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5432e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54330, 0x0);
dwc_ddrphy_apb_wr_32b(0x54332, 0x0);
dwc_ddrphy_apb_wr_32b(0x54334, 0x0);
dwc_ddrphy_apb_wr_32b(0x54336, 0x0);
dwc_ddrphy_apb_wr_32b(0x54338, 0x0);
dwc_ddrphy_apb_wr_32b(0x5433a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5433c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5433e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54340, 0x0);
dwc_ddrphy_apb_wr_32b(0x54342, 0x0);
dwc_ddrphy_apb_wr_32b(0x54344, 0x0);
dwc_ddrphy_apb_wr_32b(0x54346, 0x0);
dwc_ddrphy_apb_wr_32b(0x54348, 0x0);
dwc_ddrphy_apb_wr_32b(0x5434a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5434c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5434e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54350, 0x0);
dwc_ddrphy_apb_wr_32b(0x54352, 0x0);
dwc_ddrphy_apb_wr_32b(0x54354, 0x0);
dwc_ddrphy_apb_wr_32b(0x54356, 0x0);
dwc_ddrphy_apb_wr_32b(0x54358, 0x0);
dwc_ddrphy_apb_wr_32b(0x5435a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5435c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5435e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54360, 0x0);
dwc_ddrphy_apb_wr_32b(0x54362, 0x0);
dwc_ddrphy_apb_wr_32b(0x54364, 0x0);
dwc_ddrphy_apb_wr_32b(0x54366, 0x0);
dwc_ddrphy_apb_wr_32b(0x54368, 0x0);
dwc_ddrphy_apb_wr_32b(0x5436a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5436c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5436e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54370, 0x0);
dwc_ddrphy_apb_wr_32b(0x54372, 0x0);
dwc_ddrphy_apb_wr_32b(0x54374, 0x0);
dwc_ddrphy_apb_wr_32b(0x54376, 0x0);
dwc_ddrphy_apb_wr_32b(0x54378, 0x0);
dwc_ddrphy_apb_wr_32b(0x5437a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5437c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5437e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54380, 0x0);
dwc_ddrphy_apb_wr_32b(0x54382, 0x0);
dwc_ddrphy_apb_wr_32b(0x54384, 0x0);
dwc_ddrphy_apb_wr_32b(0x54386, 0x0);
dwc_ddrphy_apb_wr_32b(0x54388, 0x0);
dwc_ddrphy_apb_wr_32b(0x5438a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5438c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5438e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54390, 0x0);
dwc_ddrphy_apb_wr_32b(0x54392, 0x0);
dwc_ddrphy_apb_wr_32b(0x54394, 0x0);
dwc_ddrphy_apb_wr_32b(0x54396, 0x0);
dwc_ddrphy_apb_wr_32b(0x54398, 0x0);
dwc_ddrphy_apb_wr_32b(0x5439a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5439c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5439e, 0x0);
dwc_ddrphy_apb_wr_32b(0x543a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x543a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x543a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x543a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x543a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x543aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x543ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x543ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x543b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x543b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x543b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x543b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x543b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x543ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x543bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x543be, 0x0);
dwc_ddrphy_apb_wr_32b(0x543c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x543c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x543c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x543c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x543c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x543ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x543cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x543ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x543d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x543d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x543d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x543d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x543d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x543da, 0x0);
dwc_ddrphy_apb_wr_32b(0x543dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x543de, 0x0);
dwc_ddrphy_apb_wr_32b(0x543e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x543e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x543e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x543e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x543e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x543ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x543ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x543ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x543f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x543f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x543f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x543f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x543f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x543fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x543fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x543fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54400, 0x0);
dwc_ddrphy_apb_wr_32b(0x54402, 0x0);
dwc_ddrphy_apb_wr_32b(0x54404, 0x0);
dwc_ddrphy_apb_wr_32b(0x54406, 0x0);
dwc_ddrphy_apb_wr_32b(0x54408, 0x0);
dwc_ddrphy_apb_wr_32b(0x5440a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5440c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5440e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54410, 0x0);
dwc_ddrphy_apb_wr_32b(0x54412, 0x0);
dwc_ddrphy_apb_wr_32b(0x54414, 0x0);
dwc_ddrphy_apb_wr_32b(0x54416, 0x0);
dwc_ddrphy_apb_wr_32b(0x54418, 0x0);
dwc_ddrphy_apb_wr_32b(0x5441a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5441c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5441e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54420, 0x0);
dwc_ddrphy_apb_wr_32b(0x54422, 0x0);
dwc_ddrphy_apb_wr_32b(0x54424, 0x0);
dwc_ddrphy_apb_wr_32b(0x54426, 0x0);
dwc_ddrphy_apb_wr_32b(0x54428, 0x0);
dwc_ddrphy_apb_wr_32b(0x5442a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5442c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5442e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54430, 0x0);
dwc_ddrphy_apb_wr_32b(0x54432, 0x0);
dwc_ddrphy_apb_wr_32b(0x54434, 0x0);
dwc_ddrphy_apb_wr_32b(0x54436, 0x0);
dwc_ddrphy_apb_wr_32b(0x54438, 0x0);
dwc_ddrphy_apb_wr_32b(0x5443a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5443c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5443e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54440, 0x0);
dwc_ddrphy_apb_wr_32b(0x54442, 0x0);
dwc_ddrphy_apb_wr_32b(0x54444, 0x0);
dwc_ddrphy_apb_wr_32b(0x54446, 0x0);
dwc_ddrphy_apb_wr_32b(0x54448, 0x0);
dwc_ddrphy_apb_wr_32b(0x5444a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5444c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5444e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54450, 0x0);
dwc_ddrphy_apb_wr_32b(0x54452, 0x0);
dwc_ddrphy_apb_wr_32b(0x54454, 0x0);
dwc_ddrphy_apb_wr_32b(0x54456, 0x0);
dwc_ddrphy_apb_wr_32b(0x54458, 0x0);
dwc_ddrphy_apb_wr_32b(0x5445a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5445c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5445e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54460, 0x0);
dwc_ddrphy_apb_wr_32b(0x54462, 0x0);
dwc_ddrphy_apb_wr_32b(0x54464, 0x0);
dwc_ddrphy_apb_wr_32b(0x54466, 0x0);
dwc_ddrphy_apb_wr_32b(0x54468, 0x0);
dwc_ddrphy_apb_wr_32b(0x5446a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5446c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5446e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54470, 0x0);
dwc_ddrphy_apb_wr_32b(0x54472, 0x0);
dwc_ddrphy_apb_wr_32b(0x54474, 0x0);
dwc_ddrphy_apb_wr_32b(0x54476, 0x0);
dwc_ddrphy_apb_wr_32b(0x54478, 0x0);
dwc_ddrphy_apb_wr_32b(0x5447a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5447c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5447e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54480, 0x0);
dwc_ddrphy_apb_wr_32b(0x54482, 0x0);
dwc_ddrphy_apb_wr_32b(0x54484, 0x0);
dwc_ddrphy_apb_wr_32b(0x54486, 0x0);
dwc_ddrphy_apb_wr_32b(0x54488, 0x0);
dwc_ddrphy_apb_wr_32b(0x5448a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5448c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5448e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54490, 0x0);
dwc_ddrphy_apb_wr_32b(0x54492, 0x0);
dwc_ddrphy_apb_wr_32b(0x54494, 0x0);
dwc_ddrphy_apb_wr_32b(0x54496, 0x0);
dwc_ddrphy_apb_wr_32b(0x54498, 0x0);
dwc_ddrphy_apb_wr_32b(0x5449a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5449c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5449e, 0x0);
dwc_ddrphy_apb_wr_32b(0x544a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x544a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x544a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x544a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x544a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x544aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x544ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x544ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x544b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x544b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x544b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x544b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x544b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x544ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x544bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x544be, 0x0);
dwc_ddrphy_apb_wr_32b(0x544c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x544c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x544c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x544c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x544c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x544ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x544cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x544ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x544d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x544d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x544d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x544d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x544d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x544da, 0x0);
dwc_ddrphy_apb_wr_32b(0x544dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x544de, 0x0);
dwc_ddrphy_apb_wr_32b(0x544e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x544e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x544e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x544e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x544e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x544ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x544ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x544ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x544f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x544f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x544f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x544f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x544f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x544fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x544fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x544fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54500, 0x0);
dwc_ddrphy_apb_wr_32b(0x54502, 0x0);
dwc_ddrphy_apb_wr_32b(0x54504, 0x0);
dwc_ddrphy_apb_wr_32b(0x54506, 0x0);
dwc_ddrphy_apb_wr_32b(0x54508, 0x0);
dwc_ddrphy_apb_wr_32b(0x5450a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5450c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5450e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54510, 0x0);
dwc_ddrphy_apb_wr_32b(0x54512, 0x0);
dwc_ddrphy_apb_wr_32b(0x54514, 0x0);
dwc_ddrphy_apb_wr_32b(0x54516, 0x0);
dwc_ddrphy_apb_wr_32b(0x54518, 0x0);
dwc_ddrphy_apb_wr_32b(0x5451a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5451c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5451e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54520, 0x0);
dwc_ddrphy_apb_wr_32b(0x54522, 0x0);
dwc_ddrphy_apb_wr_32b(0x54524, 0x0);
dwc_ddrphy_apb_wr_32b(0x54526, 0x0);
dwc_ddrphy_apb_wr_32b(0x54528, 0x0);
dwc_ddrphy_apb_wr_32b(0x5452a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5452c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5452e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54530, 0x0);
dwc_ddrphy_apb_wr_32b(0x54532, 0x0);
dwc_ddrphy_apb_wr_32b(0x54534, 0x0);
dwc_ddrphy_apb_wr_32b(0x54536, 0x0);
dwc_ddrphy_apb_wr_32b(0x54538, 0x0);
dwc_ddrphy_apb_wr_32b(0x5453a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5453c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5453e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54540, 0x0);
dwc_ddrphy_apb_wr_32b(0x54542, 0x0);
dwc_ddrphy_apb_wr_32b(0x54544, 0x0);
dwc_ddrphy_apb_wr_32b(0x54546, 0x0);
dwc_ddrphy_apb_wr_32b(0x54548, 0x0);
dwc_ddrphy_apb_wr_32b(0x5454a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5454c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5454e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54550, 0x0);
dwc_ddrphy_apb_wr_32b(0x54552, 0x0);
dwc_ddrphy_apb_wr_32b(0x54554, 0x0);
dwc_ddrphy_apb_wr_32b(0x54556, 0x0);
dwc_ddrphy_apb_wr_32b(0x54558, 0x0);
dwc_ddrphy_apb_wr_32b(0x5455a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5455c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5455e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54560, 0x0);
dwc_ddrphy_apb_wr_32b(0x54562, 0x0);
dwc_ddrphy_apb_wr_32b(0x54564, 0x0);
dwc_ddrphy_apb_wr_32b(0x54566, 0x0);
dwc_ddrphy_apb_wr_32b(0x54568, 0x0);
dwc_ddrphy_apb_wr_32b(0x5456a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5456c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5456e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54570, 0x0);
dwc_ddrphy_apb_wr_32b(0x54572, 0x0);
dwc_ddrphy_apb_wr_32b(0x54574, 0x0);
dwc_ddrphy_apb_wr_32b(0x54576, 0x0);
dwc_ddrphy_apb_wr_32b(0x54578, 0x0);
dwc_ddrphy_apb_wr_32b(0x5457a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5457c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5457e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54580, 0x0);
dwc_ddrphy_apb_wr_32b(0x54582, 0x0);
dwc_ddrphy_apb_wr_32b(0x54584, 0x0);
dwc_ddrphy_apb_wr_32b(0x54586, 0x0);
dwc_ddrphy_apb_wr_32b(0x54588, 0x0);
dwc_ddrphy_apb_wr_32b(0x5458a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5458c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5458e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54590, 0x0);
dwc_ddrphy_apb_wr_32b(0x54592, 0x0);
dwc_ddrphy_apb_wr_32b(0x54594, 0x0);
dwc_ddrphy_apb_wr_32b(0x54596, 0x0);
dwc_ddrphy_apb_wr_32b(0x54598, 0x0);
dwc_ddrphy_apb_wr_32b(0x5459a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5459c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5459e, 0x0);
dwc_ddrphy_apb_wr_32b(0x545a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x545a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x545a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x545a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x545a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x545aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x545ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x545ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x545b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x545b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x545b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x545b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x545b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x545ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x545bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x545be, 0x0);
dwc_ddrphy_apb_wr_32b(0x545c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x545c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x545c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x545c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x545c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x545ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x545cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x545ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x545d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x545d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x545d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x545d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x545d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x545da, 0x0);
dwc_ddrphy_apb_wr_32b(0x545dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x545de, 0x0);
dwc_ddrphy_apb_wr_32b(0x545e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x545e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x545e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x545e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x545e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x545ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x545ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x545ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x545f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x545f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x545f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x545f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x545f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x545fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x545fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x545fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54600, 0x0);
dwc_ddrphy_apb_wr_32b(0x54602, 0x0);
dwc_ddrphy_apb_wr_32b(0x54604, 0x0);
dwc_ddrphy_apb_wr_32b(0x54606, 0x0);
dwc_ddrphy_apb_wr_32b(0x54608, 0x0);
dwc_ddrphy_apb_wr_32b(0x5460a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5460c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5460e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54610, 0x0);
dwc_ddrphy_apb_wr_32b(0x54612, 0x0);
dwc_ddrphy_apb_wr_32b(0x54614, 0x0);
dwc_ddrphy_apb_wr_32b(0x54616, 0x0);
dwc_ddrphy_apb_wr_32b(0x54618, 0x0);
dwc_ddrphy_apb_wr_32b(0x5461a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5461c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5461e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54620, 0x0);
dwc_ddrphy_apb_wr_32b(0x54622, 0x0);
dwc_ddrphy_apb_wr_32b(0x54624, 0x0);
dwc_ddrphy_apb_wr_32b(0x54626, 0x0);
dwc_ddrphy_apb_wr_32b(0x54628, 0x0);
dwc_ddrphy_apb_wr_32b(0x5462a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5462c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5462e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54630, 0x0);
dwc_ddrphy_apb_wr_32b(0x54632, 0x0);
dwc_ddrphy_apb_wr_32b(0x54634, 0x0);
dwc_ddrphy_apb_wr_32b(0x54636, 0x0);
dwc_ddrphy_apb_wr_32b(0x54638, 0x0);
dwc_ddrphy_apb_wr_32b(0x5463a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5463c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5463e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54640, 0x0);
dwc_ddrphy_apb_wr_32b(0x54642, 0x0);
dwc_ddrphy_apb_wr_32b(0x54644, 0x0);
dwc_ddrphy_apb_wr_32b(0x54646, 0x0);
dwc_ddrphy_apb_wr_32b(0x54648, 0x0);
dwc_ddrphy_apb_wr_32b(0x5464a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5464c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5464e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54650, 0x0);
dwc_ddrphy_apb_wr_32b(0x54652, 0x0);
dwc_ddrphy_apb_wr_32b(0x54654, 0x0);
dwc_ddrphy_apb_wr_32b(0x54656, 0x0);
dwc_ddrphy_apb_wr_32b(0x54658, 0x0);
dwc_ddrphy_apb_wr_32b(0x5465a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5465c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5465e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54660, 0x0);
dwc_ddrphy_apb_wr_32b(0x54662, 0x0);
dwc_ddrphy_apb_wr_32b(0x54664, 0x0);
dwc_ddrphy_apb_wr_32b(0x54666, 0x0);
dwc_ddrphy_apb_wr_32b(0x54668, 0x0);
dwc_ddrphy_apb_wr_32b(0x5466a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5466c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5466e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54670, 0x0);
dwc_ddrphy_apb_wr_32b(0x54672, 0x0);
dwc_ddrphy_apb_wr_32b(0x54674, 0x0);
dwc_ddrphy_apb_wr_32b(0x54676, 0x0);
dwc_ddrphy_apb_wr_32b(0x54678, 0x0);
dwc_ddrphy_apb_wr_32b(0x5467a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5467c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5467e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54680, 0x0);
dwc_ddrphy_apb_wr_32b(0x54682, 0x0);
dwc_ddrphy_apb_wr_32b(0x54684, 0x0);
dwc_ddrphy_apb_wr_32b(0x54686, 0x0);
dwc_ddrphy_apb_wr_32b(0x54688, 0x0);
dwc_ddrphy_apb_wr_32b(0x5468a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5468c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5468e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54690, 0x0);
dwc_ddrphy_apb_wr_32b(0x54692, 0x0);
dwc_ddrphy_apb_wr_32b(0x54694, 0x0);
dwc_ddrphy_apb_wr_32b(0x54696, 0x0);
dwc_ddrphy_apb_wr_32b(0x54698, 0x0);
dwc_ddrphy_apb_wr_32b(0x5469a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5469c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5469e, 0x0);
dwc_ddrphy_apb_wr_32b(0x546a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x546a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x546a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x546a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x546a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x546aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x546ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x546ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x546b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x546b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x546b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x546b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x546b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x546ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x546bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x546be, 0x0);
dwc_ddrphy_apb_wr_32b(0x546c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x546c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x546c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x546c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x546c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x546ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x546cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x546ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x546d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x546d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x546d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x546d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x546d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x546da, 0x0);
dwc_ddrphy_apb_wr_32b(0x546dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x546de, 0x0);
dwc_ddrphy_apb_wr_32b(0x546e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x546e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x546e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x546e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x546e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x546ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x546ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x546ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x546f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x546f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x546f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x546f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x546f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x546fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x546fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x546fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54700, 0x0);
dwc_ddrphy_apb_wr_32b(0x54702, 0x0);
dwc_ddrphy_apb_wr_32b(0x54704, 0x0);
dwc_ddrphy_apb_wr_32b(0x54706, 0x0);
dwc_ddrphy_apb_wr_32b(0x54708, 0x0);
dwc_ddrphy_apb_wr_32b(0x5470a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5470c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5470e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54710, 0x0);
dwc_ddrphy_apb_wr_32b(0x54712, 0x0);
dwc_ddrphy_apb_wr_32b(0x54714, 0x0);
dwc_ddrphy_apb_wr_32b(0x54716, 0x0);
dwc_ddrphy_apb_wr_32b(0x54718, 0x0);
dwc_ddrphy_apb_wr_32b(0x5471a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5471c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5471e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54720, 0x0);
dwc_ddrphy_apb_wr_32b(0x54722, 0x0);
dwc_ddrphy_apb_wr_32b(0x54724, 0x0);
dwc_ddrphy_apb_wr_32b(0x54726, 0x0);
dwc_ddrphy_apb_wr_32b(0x54728, 0x0);
dwc_ddrphy_apb_wr_32b(0x5472a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5472c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5472e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54730, 0x0);
dwc_ddrphy_apb_wr_32b(0x54732, 0x0);
dwc_ddrphy_apb_wr_32b(0x54734, 0x0);
dwc_ddrphy_apb_wr_32b(0x54736, 0x0);
dwc_ddrphy_apb_wr_32b(0x54738, 0x0);
dwc_ddrphy_apb_wr_32b(0x5473a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5473c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5473e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54740, 0x0);
dwc_ddrphy_apb_wr_32b(0x54742, 0x0);
dwc_ddrphy_apb_wr_32b(0x54744, 0x0);
dwc_ddrphy_apb_wr_32b(0x54746, 0x0);
dwc_ddrphy_apb_wr_32b(0x54748, 0x0);
dwc_ddrphy_apb_wr_32b(0x5474a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5474c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5474e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54750, 0x0);
dwc_ddrphy_apb_wr_32b(0x54752, 0x0);
dwc_ddrphy_apb_wr_32b(0x54754, 0x0);
dwc_ddrphy_apb_wr_32b(0x54756, 0x0);
dwc_ddrphy_apb_wr_32b(0x54758, 0x0);
dwc_ddrphy_apb_wr_32b(0x5475a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5475c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5475e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54760, 0x0);
dwc_ddrphy_apb_wr_32b(0x54762, 0x0);
dwc_ddrphy_apb_wr_32b(0x54764, 0x0);
dwc_ddrphy_apb_wr_32b(0x54766, 0x0);
dwc_ddrphy_apb_wr_32b(0x54768, 0x0);
dwc_ddrphy_apb_wr_32b(0x5476a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5476c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5476e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54770, 0x0);
dwc_ddrphy_apb_wr_32b(0x54772, 0x0);
dwc_ddrphy_apb_wr_32b(0x54774, 0x0);
dwc_ddrphy_apb_wr_32b(0x54776, 0x0);
dwc_ddrphy_apb_wr_32b(0x54778, 0x0);
dwc_ddrphy_apb_wr_32b(0x5477a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5477c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5477e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54780, 0x0);
dwc_ddrphy_apb_wr_32b(0x54782, 0x0);
dwc_ddrphy_apb_wr_32b(0x54784, 0x0);
dwc_ddrphy_apb_wr_32b(0x54786, 0x0);
dwc_ddrphy_apb_wr_32b(0x54788, 0x0);
dwc_ddrphy_apb_wr_32b(0x5478a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5478c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5478e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54790, 0x0);
dwc_ddrphy_apb_wr_32b(0x54792, 0x0);
dwc_ddrphy_apb_wr_32b(0x54794, 0x0);
dwc_ddrphy_apb_wr_32b(0x54796, 0x0);
dwc_ddrphy_apb_wr_32b(0x54798, 0x0);
dwc_ddrphy_apb_wr_32b(0x5479a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5479c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5479e, 0x0);
dwc_ddrphy_apb_wr_32b(0x547a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x547a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x547a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x547a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x547a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x547aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x547ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x547ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x547b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x547b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x547b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x547b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x547b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x547ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x547bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x547be, 0x0);
dwc_ddrphy_apb_wr_32b(0x547c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x547c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x547c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x547c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x547c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x547ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x547cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x547ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x547d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x547d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x547d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x547d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x547d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x547da, 0x0);
dwc_ddrphy_apb_wr_32b(0x547dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x547de, 0x0);
dwc_ddrphy_apb_wr_32b(0x547e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x547e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x547e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x547e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x547e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x547ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x547ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x547ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x547f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x547f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x547f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x547f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x547f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x547fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x547fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x547fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54800, 0x0);
dwc_ddrphy_apb_wr_32b(0x54802, 0x0);
dwc_ddrphy_apb_wr_32b(0x54804, 0x0);
dwc_ddrphy_apb_wr_32b(0x54806, 0x0);
dwc_ddrphy_apb_wr_32b(0x54808, 0x0);
dwc_ddrphy_apb_wr_32b(0x5480a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5480c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5480e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54810, 0x0);
dwc_ddrphy_apb_wr_32b(0x54812, 0x0);
dwc_ddrphy_apb_wr_32b(0x54814, 0x0);
dwc_ddrphy_apb_wr_32b(0x54816, 0x0);
dwc_ddrphy_apb_wr_32b(0x54818, 0x0);
dwc_ddrphy_apb_wr_32b(0x5481a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5481c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5481e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54820, 0x0);
dwc_ddrphy_apb_wr_32b(0x54822, 0x0);
dwc_ddrphy_apb_wr_32b(0x54824, 0x0);
dwc_ddrphy_apb_wr_32b(0x54826, 0x0);
dwc_ddrphy_apb_wr_32b(0x54828, 0x0);
dwc_ddrphy_apb_wr_32b(0x5482a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5482c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5482e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54830, 0x0);
dwc_ddrphy_apb_wr_32b(0x54832, 0x0);
dwc_ddrphy_apb_wr_32b(0x54834, 0x0);
dwc_ddrphy_apb_wr_32b(0x54836, 0x0);
dwc_ddrphy_apb_wr_32b(0x54838, 0x0);
dwc_ddrphy_apb_wr_32b(0x5483a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5483c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5483e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54840, 0x0);
dwc_ddrphy_apb_wr_32b(0x54842, 0x0);
dwc_ddrphy_apb_wr_32b(0x54844, 0x0);
dwc_ddrphy_apb_wr_32b(0x54846, 0x0);
dwc_ddrphy_apb_wr_32b(0x54848, 0x0);
dwc_ddrphy_apb_wr_32b(0x5484a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5484c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5484e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54850, 0x0);
dwc_ddrphy_apb_wr_32b(0x54852, 0x0);
dwc_ddrphy_apb_wr_32b(0x54854, 0x0);
dwc_ddrphy_apb_wr_32b(0x54856, 0x0);
dwc_ddrphy_apb_wr_32b(0x54858, 0x0);
dwc_ddrphy_apb_wr_32b(0x5485a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5485c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5485e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54860, 0x0);
dwc_ddrphy_apb_wr_32b(0x54862, 0x0);
dwc_ddrphy_apb_wr_32b(0x54864, 0x0);
dwc_ddrphy_apb_wr_32b(0x54866, 0x0);
dwc_ddrphy_apb_wr_32b(0x54868, 0x0);
dwc_ddrphy_apb_wr_32b(0x5486a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5486c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5486e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54870, 0x0);
dwc_ddrphy_apb_wr_32b(0x54872, 0x0);
dwc_ddrphy_apb_wr_32b(0x54874, 0x0);
dwc_ddrphy_apb_wr_32b(0x54876, 0x0);
dwc_ddrphy_apb_wr_32b(0x54878, 0x0);
dwc_ddrphy_apb_wr_32b(0x5487a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5487c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5487e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54880, 0x0);
dwc_ddrphy_apb_wr_32b(0x54882, 0x0);
dwc_ddrphy_apb_wr_32b(0x54884, 0x0);
dwc_ddrphy_apb_wr_32b(0x54886, 0x0);
dwc_ddrphy_apb_wr_32b(0x54888, 0x0);
dwc_ddrphy_apb_wr_32b(0x5488a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5488c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5488e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54890, 0x0);
dwc_ddrphy_apb_wr_32b(0x54892, 0x0);
dwc_ddrphy_apb_wr_32b(0x54894, 0x0);
dwc_ddrphy_apb_wr_32b(0x54896, 0x0);
dwc_ddrphy_apb_wr_32b(0x54898, 0x0);
dwc_ddrphy_apb_wr_32b(0x5489a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5489c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5489e, 0x0);
dwc_ddrphy_apb_wr_32b(0x548a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x548a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x548a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x548a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x548a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x548aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x548ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x548ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x548b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x548b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x548b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x548b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x548b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x548ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x548bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x548be, 0x0);
dwc_ddrphy_apb_wr_32b(0x548c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x548c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x548c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x548c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x548c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x548ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x548cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x548ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x548d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x548d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x548d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x548d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x548d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x548da, 0x0);
dwc_ddrphy_apb_wr_32b(0x548dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x548de, 0x0);
dwc_ddrphy_apb_wr_32b(0x548e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x548e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x548e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x548e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x548e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x548ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x548ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x548ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x548f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x548f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x548f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x548f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x548f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x548fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x548fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x548fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54900, 0x0);
dwc_ddrphy_apb_wr_32b(0x54902, 0x0);
dwc_ddrphy_apb_wr_32b(0x54904, 0x0);
dwc_ddrphy_apb_wr_32b(0x54906, 0x0);
dwc_ddrphy_apb_wr_32b(0x54908, 0x0);
dwc_ddrphy_apb_wr_32b(0x5490a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5490c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5490e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54910, 0x0);
dwc_ddrphy_apb_wr_32b(0x54912, 0x0);
dwc_ddrphy_apb_wr_32b(0x54914, 0x0);
dwc_ddrphy_apb_wr_32b(0x54916, 0x0);
dwc_ddrphy_apb_wr_32b(0x54918, 0x0);
dwc_ddrphy_apb_wr_32b(0x5491a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5491c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5491e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54920, 0x0);
dwc_ddrphy_apb_wr_32b(0x54922, 0x0);
dwc_ddrphy_apb_wr_32b(0x54924, 0x0);
dwc_ddrphy_apb_wr_32b(0x54926, 0x0);
dwc_ddrphy_apb_wr_32b(0x54928, 0x0);
dwc_ddrphy_apb_wr_32b(0x5492a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5492c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5492e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54930, 0x0);
dwc_ddrphy_apb_wr_32b(0x54932, 0x0);
dwc_ddrphy_apb_wr_32b(0x54934, 0x0);
dwc_ddrphy_apb_wr_32b(0x54936, 0x0);
dwc_ddrphy_apb_wr_32b(0x54938, 0x0);
dwc_ddrphy_apb_wr_32b(0x5493a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5493c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5493e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54940, 0x0);
dwc_ddrphy_apb_wr_32b(0x54942, 0x0);
dwc_ddrphy_apb_wr_32b(0x54944, 0x0);
dwc_ddrphy_apb_wr_32b(0x54946, 0x0);
dwc_ddrphy_apb_wr_32b(0x54948, 0x0);
dwc_ddrphy_apb_wr_32b(0x5494a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5494c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5494e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54950, 0x0);
dwc_ddrphy_apb_wr_32b(0x54952, 0x0);
dwc_ddrphy_apb_wr_32b(0x54954, 0x0);
dwc_ddrphy_apb_wr_32b(0x54956, 0x0);
dwc_ddrphy_apb_wr_32b(0x54958, 0x0);
dwc_ddrphy_apb_wr_32b(0x5495a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5495c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5495e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54960, 0x0);
dwc_ddrphy_apb_wr_32b(0x54962, 0x0);
dwc_ddrphy_apb_wr_32b(0x54964, 0x0);
dwc_ddrphy_apb_wr_32b(0x54966, 0x0);
dwc_ddrphy_apb_wr_32b(0x54968, 0x0);
dwc_ddrphy_apb_wr_32b(0x5496a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5496c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5496e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54970, 0x0);
dwc_ddrphy_apb_wr_32b(0x54972, 0x0);
dwc_ddrphy_apb_wr_32b(0x54974, 0x0);
dwc_ddrphy_apb_wr_32b(0x54976, 0x0);
dwc_ddrphy_apb_wr_32b(0x54978, 0x0);
dwc_ddrphy_apb_wr_32b(0x5497a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5497c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5497e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54980, 0x0);
dwc_ddrphy_apb_wr_32b(0x54982, 0x0);
dwc_ddrphy_apb_wr_32b(0x54984, 0x0);
dwc_ddrphy_apb_wr_32b(0x54986, 0x0);
dwc_ddrphy_apb_wr_32b(0x54988, 0x0);
dwc_ddrphy_apb_wr_32b(0x5498a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5498c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5498e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54990, 0x0);
dwc_ddrphy_apb_wr_32b(0x54992, 0x0);
dwc_ddrphy_apb_wr_32b(0x54994, 0x0);
dwc_ddrphy_apb_wr_32b(0x54996, 0x0);
dwc_ddrphy_apb_wr_32b(0x54998, 0x0);
dwc_ddrphy_apb_wr_32b(0x5499a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5499c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5499e, 0x0);
dwc_ddrphy_apb_wr_32b(0x549a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x549a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x549a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x549a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x549a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x549aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x549ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x549ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x549b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x549b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x549b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x549b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x549b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x549ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x549bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x549be, 0x0);
dwc_ddrphy_apb_wr_32b(0x549c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x549c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x549c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x549c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x549c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x549ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x549cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x549ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x549d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x549d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x549d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x549d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x549d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x549da, 0x0);
dwc_ddrphy_apb_wr_32b(0x549dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x549de, 0x0);
dwc_ddrphy_apb_wr_32b(0x549e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x549e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x549e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x549e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x549e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x549ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x549ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x549ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x549f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x549f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x549f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x549f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x549f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x549fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x549fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x549fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a00, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a02, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a04, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a06, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a08, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a10, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a12, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a14, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a16, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a18, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a20, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a22, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a24, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a26, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a28, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a30, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a32, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a34, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a36, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a38, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a40, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a42, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a44, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a46, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a48, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a50, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a52, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a54, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a56, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a58, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a60, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a62, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a64, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a66, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a68, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a70, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a72, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a74, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a76, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a78, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a80, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a82, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a84, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a86, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a88, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a90, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a92, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a94, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a96, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a98, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54a9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54aa0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54aa2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54aa4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54aa6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54aa8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54aaa, 0x0);
dwc_ddrphy_apb_wr_32b(0x54aac, 0x0);
dwc_ddrphy_apb_wr_32b(0x54aae, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ab0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ab2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ab4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ab6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ab8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54aba, 0x0);
dwc_ddrphy_apb_wr_32b(0x54abc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54abe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ac0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ac2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ac4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ac6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ac8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54aca, 0x0);
dwc_ddrphy_apb_wr_32b(0x54acc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ace, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ad0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ad2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ad4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ad6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ad8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ada, 0x0);
dwc_ddrphy_apb_wr_32b(0x54adc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ade, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ae0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ae2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ae4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ae6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ae8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54aea, 0x0);
dwc_ddrphy_apb_wr_32b(0x54aec, 0x0);
dwc_ddrphy_apb_wr_32b(0x54aee, 0x0);
dwc_ddrphy_apb_wr_32b(0x54af0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54af2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54af4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54af6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54af8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54afa, 0x0);
dwc_ddrphy_apb_wr_32b(0x54afc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54afe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b00, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b02, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b04, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b06, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b08, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b10, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b12, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b14, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b16, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b18, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b20, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b22, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b24, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b26, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b28, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b30, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b32, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b34, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b36, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b38, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b40, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b42, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b44, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b46, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b48, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b50, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b52, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b54, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b56, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b58, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b60, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b62, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b64, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b66, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b68, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b70, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b72, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b74, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b76, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b78, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b80, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b82, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b84, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b86, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b88, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b90, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b92, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b94, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b96, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b98, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54b9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ba0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ba2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ba4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ba6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ba8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54baa, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bac, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bae, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bba, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bca, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bcc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bce, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bda, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bdc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bde, 0x0);
dwc_ddrphy_apb_wr_32b(0x54be0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54be2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54be4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54be6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54be8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bea, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bec, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bee, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bf0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bf2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bf4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bf6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bf8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bfa, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bfc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54bfe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c00, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c02, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c04, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c06, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c08, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c10, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c12, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c14, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c16, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c18, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c20, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c22, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c24, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c26, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c28, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c30, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c32, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c34, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c36, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c38, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c40, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c42, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c44, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c46, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c48, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c50, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c52, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c54, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c56, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c58, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c60, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c62, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c64, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c66, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c68, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c70, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c72, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c74, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c76, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c78, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c80, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c82, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c84, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c86, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c88, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c90, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c92, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c94, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c96, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c98, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54c9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ca0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ca2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ca4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ca6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ca8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54caa, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cac, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cae, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cba, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cca, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ccc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cce, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cda, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cdc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cde, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ce0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ce2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ce4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ce6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ce8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cea, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cec, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cee, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cf0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cf2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cf4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cf6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cf8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cfa, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cfc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54cfe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d00, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d02, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d04, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d06, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d08, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d10, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d12, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d14, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d16, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d18, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d20, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d22, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d24, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d26, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d28, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d30, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d32, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d34, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d36, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d38, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d40, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d42, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d44, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d46, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d48, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d50, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d52, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d54, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d56, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d58, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d60, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d62, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d64, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d66, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d68, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d70, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d72, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d74, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d76, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d78, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d80, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d82, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d84, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d86, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d88, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d90, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d92, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d94, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d96, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d98, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54d9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54da0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54da2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54da4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54da6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54da8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54daa, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dac, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dae, 0x0);
dwc_ddrphy_apb_wr_32b(0x54db0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54db2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54db4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54db6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54db8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dba, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dca, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dcc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dce, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dda, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ddc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dde, 0x0);
dwc_ddrphy_apb_wr_32b(0x54de0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54de2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54de4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54de6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54de8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dea, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dec, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dee, 0x0);
dwc_ddrphy_apb_wr_32b(0x54df0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54df2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54df4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54df6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54df8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dfa, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dfc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54dfe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e00, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e02, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e04, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e06, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e08, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e10, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e12, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e14, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e16, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e18, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e20, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e22, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e24, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e26, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e28, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e30, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e32, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e34, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e36, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e38, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e40, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e42, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e44, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e46, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e48, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e50, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e52, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e54, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e56, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e58, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e60, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e62, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e64, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e66, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e68, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e70, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e72, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e74, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e76, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e78, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e80, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e82, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e84, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e86, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e88, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e90, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e92, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e94, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e96, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e98, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54e9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ea0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ea2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ea4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ea6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ea8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54eaa, 0x0);
dwc_ddrphy_apb_wr_32b(0x54eac, 0x0);
dwc_ddrphy_apb_wr_32b(0x54eae, 0x0);
dwc_ddrphy_apb_wr_32b(0x54eb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54eb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54eb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54eb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54eb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54eba, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ebc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ebe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ec0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ec2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ec4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ec6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ec8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54eca, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ecc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ece, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ed0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ed2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ed4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ed6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ed8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54eda, 0x0);
dwc_ddrphy_apb_wr_32b(0x54edc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ede, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ee0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ee2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ee4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ee6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ee8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54eea, 0x0);
dwc_ddrphy_apb_wr_32b(0x54eec, 0x0);
dwc_ddrphy_apb_wr_32b(0x54eee, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ef0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ef2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ef4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ef6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ef8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54efa, 0x0);
dwc_ddrphy_apb_wr_32b(0x54efc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54efe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f00, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f02, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f04, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f06, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f08, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f10, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f12, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f14, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f16, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f18, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f20, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f22, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f24, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f26, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f28, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f30, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f32, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f34, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f36, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f38, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f40, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f42, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f44, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f46, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f48, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f50, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f52, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f54, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f56, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f58, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f60, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f62, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f64, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f66, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f68, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f70, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f72, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f74, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f76, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f78, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f80, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f82, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f84, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f86, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f88, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f90, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f92, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f94, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f96, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f98, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x54f9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fa0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fa2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fa4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fa6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fa8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54faa, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fac, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fae, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fba, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fca, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fcc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fce, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fda, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fdc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fde, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fe0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fe2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fe4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fe6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fe8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fea, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fec, 0x0);
dwc_ddrphy_apb_wr_32b(0x54fee, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ff0, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ff2, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ff4, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ff6, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ff8, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ffa, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ffc, 0x0);
dwc_ddrphy_apb_wr_32b(0x54ffe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55000, 0x0);
dwc_ddrphy_apb_wr_32b(0x55002, 0x0);
dwc_ddrphy_apb_wr_32b(0x55004, 0x0);
dwc_ddrphy_apb_wr_32b(0x55006, 0x0);
dwc_ddrphy_apb_wr_32b(0x55008, 0x0);
dwc_ddrphy_apb_wr_32b(0x5500a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5500c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5500e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55010, 0x0);
dwc_ddrphy_apb_wr_32b(0x55012, 0x0);
dwc_ddrphy_apb_wr_32b(0x55014, 0x0);
dwc_ddrphy_apb_wr_32b(0x55016, 0x0);
dwc_ddrphy_apb_wr_32b(0x55018, 0x0);
dwc_ddrphy_apb_wr_32b(0x5501a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5501c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5501e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55020, 0x0);
dwc_ddrphy_apb_wr_32b(0x55022, 0x0);
dwc_ddrphy_apb_wr_32b(0x55024, 0x0);
dwc_ddrphy_apb_wr_32b(0x55026, 0x0);
dwc_ddrphy_apb_wr_32b(0x55028, 0x0);
dwc_ddrphy_apb_wr_32b(0x5502a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5502c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5502e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55030, 0x0);
dwc_ddrphy_apb_wr_32b(0x55032, 0x0);
dwc_ddrphy_apb_wr_32b(0x55034, 0x0);
dwc_ddrphy_apb_wr_32b(0x55036, 0x0);
dwc_ddrphy_apb_wr_32b(0x55038, 0x0);
dwc_ddrphy_apb_wr_32b(0x5503a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5503c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5503e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55040, 0x0);
dwc_ddrphy_apb_wr_32b(0x55042, 0x0);
dwc_ddrphy_apb_wr_32b(0x55044, 0x0);
dwc_ddrphy_apb_wr_32b(0x55046, 0x0);
dwc_ddrphy_apb_wr_32b(0x55048, 0x0);
dwc_ddrphy_apb_wr_32b(0x5504a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5504c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5504e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55050, 0x0);
dwc_ddrphy_apb_wr_32b(0x55052, 0x0);
dwc_ddrphy_apb_wr_32b(0x55054, 0x0);
dwc_ddrphy_apb_wr_32b(0x55056, 0x0);
dwc_ddrphy_apb_wr_32b(0x55058, 0x0);
dwc_ddrphy_apb_wr_32b(0x5505a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5505c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5505e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55060, 0x0);
dwc_ddrphy_apb_wr_32b(0x55062, 0x0);
dwc_ddrphy_apb_wr_32b(0x55064, 0x0);
dwc_ddrphy_apb_wr_32b(0x55066, 0x0);
dwc_ddrphy_apb_wr_32b(0x55068, 0x0);
dwc_ddrphy_apb_wr_32b(0x5506a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5506c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5506e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55070, 0x0);
dwc_ddrphy_apb_wr_32b(0x55072, 0x0);
dwc_ddrphy_apb_wr_32b(0x55074, 0x0);
dwc_ddrphy_apb_wr_32b(0x55076, 0x0);
dwc_ddrphy_apb_wr_32b(0x55078, 0x0);
dwc_ddrphy_apb_wr_32b(0x5507a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5507c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5507e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55080, 0x0);
dwc_ddrphy_apb_wr_32b(0x55082, 0x0);
dwc_ddrphy_apb_wr_32b(0x55084, 0x0);
dwc_ddrphy_apb_wr_32b(0x55086, 0x0);
dwc_ddrphy_apb_wr_32b(0x55088, 0x0);
dwc_ddrphy_apb_wr_32b(0x5508a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5508c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5508e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55090, 0x0);
dwc_ddrphy_apb_wr_32b(0x55092, 0x0);
dwc_ddrphy_apb_wr_32b(0x55094, 0x0);
dwc_ddrphy_apb_wr_32b(0x55096, 0x0);
dwc_ddrphy_apb_wr_32b(0x55098, 0x0);
dwc_ddrphy_apb_wr_32b(0x5509a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5509c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5509e, 0x0);
dwc_ddrphy_apb_wr_32b(0x550a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x550a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x550a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x550a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x550a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x550aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x550ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x550ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x550b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x550b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x550b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x550b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x550b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x550ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x550bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x550be, 0x0);
dwc_ddrphy_apb_wr_32b(0x550c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x550c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x550c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x550c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x550c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x550ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x550cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x550ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x550d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x550d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x550d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x550d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x550d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x550da, 0x0);
dwc_ddrphy_apb_wr_32b(0x550dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x550de, 0x0);
dwc_ddrphy_apb_wr_32b(0x550e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x550e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x550e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x550e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x550e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x550ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x550ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x550ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x550f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x550f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x550f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x550f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x550f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x550fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x550fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x550fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55100, 0x0);
dwc_ddrphy_apb_wr_32b(0x55102, 0x0);
dwc_ddrphy_apb_wr_32b(0x55104, 0x0);
dwc_ddrphy_apb_wr_32b(0x55106, 0x0);
dwc_ddrphy_apb_wr_32b(0x55108, 0x0);
dwc_ddrphy_apb_wr_32b(0x5510a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5510c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5510e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55110, 0x0);
dwc_ddrphy_apb_wr_32b(0x55112, 0x0);
dwc_ddrphy_apb_wr_32b(0x55114, 0x0);
dwc_ddrphy_apb_wr_32b(0x55116, 0x0);
dwc_ddrphy_apb_wr_32b(0x55118, 0x0);
dwc_ddrphy_apb_wr_32b(0x5511a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5511c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5511e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55120, 0x0);
dwc_ddrphy_apb_wr_32b(0x55122, 0x0);
dwc_ddrphy_apb_wr_32b(0x55124, 0x0);
dwc_ddrphy_apb_wr_32b(0x55126, 0x0);
dwc_ddrphy_apb_wr_32b(0x55128, 0x0);
dwc_ddrphy_apb_wr_32b(0x5512a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5512c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5512e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55130, 0x0);
dwc_ddrphy_apb_wr_32b(0x55132, 0x0);
dwc_ddrphy_apb_wr_32b(0x55134, 0x0);
dwc_ddrphy_apb_wr_32b(0x55136, 0x0);
dwc_ddrphy_apb_wr_32b(0x55138, 0x0);
dwc_ddrphy_apb_wr_32b(0x5513a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5513c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5513e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55140, 0x0);
dwc_ddrphy_apb_wr_32b(0x55142, 0x0);
dwc_ddrphy_apb_wr_32b(0x55144, 0x0);
dwc_ddrphy_apb_wr_32b(0x55146, 0x0);
dwc_ddrphy_apb_wr_32b(0x55148, 0x0);
dwc_ddrphy_apb_wr_32b(0x5514a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5514c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5514e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55150, 0x0);
dwc_ddrphy_apb_wr_32b(0x55152, 0x0);
dwc_ddrphy_apb_wr_32b(0x55154, 0x0);
dwc_ddrphy_apb_wr_32b(0x55156, 0x0);
dwc_ddrphy_apb_wr_32b(0x55158, 0x0);
dwc_ddrphy_apb_wr_32b(0x5515a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5515c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5515e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55160, 0x0);
dwc_ddrphy_apb_wr_32b(0x55162, 0x0);
dwc_ddrphy_apb_wr_32b(0x55164, 0x0);
dwc_ddrphy_apb_wr_32b(0x55166, 0x0);
dwc_ddrphy_apb_wr_32b(0x55168, 0x0);
dwc_ddrphy_apb_wr_32b(0x5516a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5516c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5516e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55170, 0x0);
dwc_ddrphy_apb_wr_32b(0x55172, 0x0);
dwc_ddrphy_apb_wr_32b(0x55174, 0x0);
dwc_ddrphy_apb_wr_32b(0x55176, 0x0);
dwc_ddrphy_apb_wr_32b(0x55178, 0x0);
dwc_ddrphy_apb_wr_32b(0x5517a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5517c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5517e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55180, 0x0);
dwc_ddrphy_apb_wr_32b(0x55182, 0x0);
dwc_ddrphy_apb_wr_32b(0x55184, 0x0);
dwc_ddrphy_apb_wr_32b(0x55186, 0x0);
dwc_ddrphy_apb_wr_32b(0x55188, 0x0);
dwc_ddrphy_apb_wr_32b(0x5518a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5518c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5518e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55190, 0x0);
dwc_ddrphy_apb_wr_32b(0x55192, 0x0);
dwc_ddrphy_apb_wr_32b(0x55194, 0x0);
dwc_ddrphy_apb_wr_32b(0x55196, 0x0);
dwc_ddrphy_apb_wr_32b(0x55198, 0x0);
dwc_ddrphy_apb_wr_32b(0x5519a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5519c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5519e, 0x0);
dwc_ddrphy_apb_wr_32b(0x551a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x551a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x551a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x551a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x551a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x551aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x551ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x551ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x551b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x551b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x551b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x551b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x551b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x551ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x551bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x551be, 0x0);
dwc_ddrphy_apb_wr_32b(0x551c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x551c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x551c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x551c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x551c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x551ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x551cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x551ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x551d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x551d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x551d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x551d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x551d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x551da, 0x0);
dwc_ddrphy_apb_wr_32b(0x551dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x551de, 0x0);
dwc_ddrphy_apb_wr_32b(0x551e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x551e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x551e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x551e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x551e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x551ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x551ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x551ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x551f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x551f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x551f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x551f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x551f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x551fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x551fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x551fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55200, 0x0);
dwc_ddrphy_apb_wr_32b(0x55202, 0x0);
dwc_ddrphy_apb_wr_32b(0x55204, 0x0);
dwc_ddrphy_apb_wr_32b(0x55206, 0x0);
dwc_ddrphy_apb_wr_32b(0x55208, 0x0);
dwc_ddrphy_apb_wr_32b(0x5520a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5520c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5520e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55210, 0x0);
dwc_ddrphy_apb_wr_32b(0x55212, 0x0);
dwc_ddrphy_apb_wr_32b(0x55214, 0x0);
dwc_ddrphy_apb_wr_32b(0x55216, 0x0);
dwc_ddrphy_apb_wr_32b(0x55218, 0x0);
dwc_ddrphy_apb_wr_32b(0x5521a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5521c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5521e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55220, 0x0);
dwc_ddrphy_apb_wr_32b(0x55222, 0x0);
dwc_ddrphy_apb_wr_32b(0x55224, 0x0);
dwc_ddrphy_apb_wr_32b(0x55226, 0x0);
dwc_ddrphy_apb_wr_32b(0x55228, 0x0);
dwc_ddrphy_apb_wr_32b(0x5522a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5522c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5522e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55230, 0x0);
dwc_ddrphy_apb_wr_32b(0x55232, 0x0);
dwc_ddrphy_apb_wr_32b(0x55234, 0x0);
dwc_ddrphy_apb_wr_32b(0x55236, 0x0);
dwc_ddrphy_apb_wr_32b(0x55238, 0x0);
dwc_ddrphy_apb_wr_32b(0x5523a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5523c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5523e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55240, 0x0);
dwc_ddrphy_apb_wr_32b(0x55242, 0x0);
dwc_ddrphy_apb_wr_32b(0x55244, 0x0);
dwc_ddrphy_apb_wr_32b(0x55246, 0x0);
dwc_ddrphy_apb_wr_32b(0x55248, 0x0);
dwc_ddrphy_apb_wr_32b(0x5524a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5524c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5524e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55250, 0x0);
dwc_ddrphy_apb_wr_32b(0x55252, 0x0);
dwc_ddrphy_apb_wr_32b(0x55254, 0x0);
dwc_ddrphy_apb_wr_32b(0x55256, 0x0);
dwc_ddrphy_apb_wr_32b(0x55258, 0x0);
dwc_ddrphy_apb_wr_32b(0x5525a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5525c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5525e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55260, 0x0);
dwc_ddrphy_apb_wr_32b(0x55262, 0x0);
dwc_ddrphy_apb_wr_32b(0x55264, 0x0);
dwc_ddrphy_apb_wr_32b(0x55266, 0x0);
dwc_ddrphy_apb_wr_32b(0x55268, 0x0);
dwc_ddrphy_apb_wr_32b(0x5526a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5526c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5526e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55270, 0x0);
dwc_ddrphy_apb_wr_32b(0x55272, 0x0);
dwc_ddrphy_apb_wr_32b(0x55274, 0x0);
dwc_ddrphy_apb_wr_32b(0x55276, 0x0);
dwc_ddrphy_apb_wr_32b(0x55278, 0x0);
dwc_ddrphy_apb_wr_32b(0x5527a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5527c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5527e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55280, 0x0);
dwc_ddrphy_apb_wr_32b(0x55282, 0x0);
dwc_ddrphy_apb_wr_32b(0x55284, 0x0);
dwc_ddrphy_apb_wr_32b(0x55286, 0x0);
dwc_ddrphy_apb_wr_32b(0x55288, 0x0);
dwc_ddrphy_apb_wr_32b(0x5528a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5528c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5528e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55290, 0x0);
dwc_ddrphy_apb_wr_32b(0x55292, 0x0);
dwc_ddrphy_apb_wr_32b(0x55294, 0x0);
dwc_ddrphy_apb_wr_32b(0x55296, 0x0);
dwc_ddrphy_apb_wr_32b(0x55298, 0x0);
dwc_ddrphy_apb_wr_32b(0x5529a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5529c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5529e, 0x0);
dwc_ddrphy_apb_wr_32b(0x552a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x552a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x552a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x552a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x552a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x552aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x552ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x552ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x552b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x552b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x552b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x552b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x552b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x552ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x552bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x552be, 0x0);
dwc_ddrphy_apb_wr_32b(0x552c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x552c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x552c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x552c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x552c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x552ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x552cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x552ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x552d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x552d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x552d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x552d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x552d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x552da, 0x0);
dwc_ddrphy_apb_wr_32b(0x552dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x552de, 0x0);
dwc_ddrphy_apb_wr_32b(0x552e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x552e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x552e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x552e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x552e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x552ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x552ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x552ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x552f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x552f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x552f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x552f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x552f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x552fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x552fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x552fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55300, 0x0);
dwc_ddrphy_apb_wr_32b(0x55302, 0x0);
dwc_ddrphy_apb_wr_32b(0x55304, 0x0);
dwc_ddrphy_apb_wr_32b(0x55306, 0x0);
dwc_ddrphy_apb_wr_32b(0x55308, 0x0);
dwc_ddrphy_apb_wr_32b(0x5530a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5530c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5530e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55310, 0x0);
dwc_ddrphy_apb_wr_32b(0x55312, 0x0);
dwc_ddrphy_apb_wr_32b(0x55314, 0x0);
dwc_ddrphy_apb_wr_32b(0x55316, 0x0);
dwc_ddrphy_apb_wr_32b(0x55318, 0x0);
dwc_ddrphy_apb_wr_32b(0x5531a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5531c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5531e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55320, 0x0);
dwc_ddrphy_apb_wr_32b(0x55322, 0x0);
dwc_ddrphy_apb_wr_32b(0x55324, 0x0);
dwc_ddrphy_apb_wr_32b(0x55326, 0x0);
dwc_ddrphy_apb_wr_32b(0x55328, 0x0);
dwc_ddrphy_apb_wr_32b(0x5532a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5532c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5532e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55330, 0x0);
dwc_ddrphy_apb_wr_32b(0x55332, 0x0);
dwc_ddrphy_apb_wr_32b(0x55334, 0x0);
dwc_ddrphy_apb_wr_32b(0x55336, 0x0);
dwc_ddrphy_apb_wr_32b(0x55338, 0x0);
dwc_ddrphy_apb_wr_32b(0x5533a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5533c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5533e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55340, 0x0);
dwc_ddrphy_apb_wr_32b(0x55342, 0x0);
dwc_ddrphy_apb_wr_32b(0x55344, 0x0);
dwc_ddrphy_apb_wr_32b(0x55346, 0x0);
dwc_ddrphy_apb_wr_32b(0x55348, 0x0);
dwc_ddrphy_apb_wr_32b(0x5534a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5534c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5534e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55350, 0x0);
dwc_ddrphy_apb_wr_32b(0x55352, 0x0);
dwc_ddrphy_apb_wr_32b(0x55354, 0x0);
dwc_ddrphy_apb_wr_32b(0x55356, 0x0);
dwc_ddrphy_apb_wr_32b(0x55358, 0x0);
dwc_ddrphy_apb_wr_32b(0x5535a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5535c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5535e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55360, 0x0);
dwc_ddrphy_apb_wr_32b(0x55362, 0x0);
dwc_ddrphy_apb_wr_32b(0x55364, 0x0);
dwc_ddrphy_apb_wr_32b(0x55366, 0x0);
dwc_ddrphy_apb_wr_32b(0x55368, 0x0);
dwc_ddrphy_apb_wr_32b(0x5536a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5536c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5536e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55370, 0x0);
dwc_ddrphy_apb_wr_32b(0x55372, 0x0);
dwc_ddrphy_apb_wr_32b(0x55374, 0x0);
dwc_ddrphy_apb_wr_32b(0x55376, 0x0);
dwc_ddrphy_apb_wr_32b(0x55378, 0x0);
dwc_ddrphy_apb_wr_32b(0x5537a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5537c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5537e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55380, 0x0);
dwc_ddrphy_apb_wr_32b(0x55382, 0x0);
dwc_ddrphy_apb_wr_32b(0x55384, 0x0);
dwc_ddrphy_apb_wr_32b(0x55386, 0x0);
dwc_ddrphy_apb_wr_32b(0x55388, 0x0);
dwc_ddrphy_apb_wr_32b(0x5538a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5538c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5538e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55390, 0x0);
dwc_ddrphy_apb_wr_32b(0x55392, 0x0);
dwc_ddrphy_apb_wr_32b(0x55394, 0x0);
dwc_ddrphy_apb_wr_32b(0x55396, 0x0);
dwc_ddrphy_apb_wr_32b(0x55398, 0x0);
dwc_ddrphy_apb_wr_32b(0x5539a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5539c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5539e, 0x0);
dwc_ddrphy_apb_wr_32b(0x553a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x553a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x553a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x553a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x553a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x553aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x553ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x553ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x553b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x553b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x553b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x553b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x553b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x553ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x553bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x553be, 0x0);
dwc_ddrphy_apb_wr_32b(0x553c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x553c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x553c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x553c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x553c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x553ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x553cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x553ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x553d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x553d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x553d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x553d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x553d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x553da, 0x0);
dwc_ddrphy_apb_wr_32b(0x553dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x553de, 0x0);
dwc_ddrphy_apb_wr_32b(0x553e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x553e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x553e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x553e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x553e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x553ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x553ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x553ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x553f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x553f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x553f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x553f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x553f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x553fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x553fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x553fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55400, 0x0);
dwc_ddrphy_apb_wr_32b(0x55402, 0x0);
dwc_ddrphy_apb_wr_32b(0x55404, 0x0);
dwc_ddrphy_apb_wr_32b(0x55406, 0x0);
dwc_ddrphy_apb_wr_32b(0x55408, 0x0);
dwc_ddrphy_apb_wr_32b(0x5540a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5540c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5540e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55410, 0x0);
dwc_ddrphy_apb_wr_32b(0x55412, 0x0);
dwc_ddrphy_apb_wr_32b(0x55414, 0x0);
dwc_ddrphy_apb_wr_32b(0x55416, 0x0);
dwc_ddrphy_apb_wr_32b(0x55418, 0x0);
dwc_ddrphy_apb_wr_32b(0x5541a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5541c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5541e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55420, 0x0);
dwc_ddrphy_apb_wr_32b(0x55422, 0x0);
dwc_ddrphy_apb_wr_32b(0x55424, 0x0);
dwc_ddrphy_apb_wr_32b(0x55426, 0x0);
dwc_ddrphy_apb_wr_32b(0x55428, 0x0);
dwc_ddrphy_apb_wr_32b(0x5542a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5542c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5542e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55430, 0x0);
dwc_ddrphy_apb_wr_32b(0x55432, 0x0);
dwc_ddrphy_apb_wr_32b(0x55434, 0x0);
dwc_ddrphy_apb_wr_32b(0x55436, 0x0);
dwc_ddrphy_apb_wr_32b(0x55438, 0x0);
dwc_ddrphy_apb_wr_32b(0x5543a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5543c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5543e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55440, 0x0);
dwc_ddrphy_apb_wr_32b(0x55442, 0x0);
dwc_ddrphy_apb_wr_32b(0x55444, 0x0);
dwc_ddrphy_apb_wr_32b(0x55446, 0x0);
dwc_ddrphy_apb_wr_32b(0x55448, 0x0);
dwc_ddrphy_apb_wr_32b(0x5544a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5544c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5544e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55450, 0x0);
dwc_ddrphy_apb_wr_32b(0x55452, 0x0);
dwc_ddrphy_apb_wr_32b(0x55454, 0x0);
dwc_ddrphy_apb_wr_32b(0x55456, 0x0);
dwc_ddrphy_apb_wr_32b(0x55458, 0x0);
dwc_ddrphy_apb_wr_32b(0x5545a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5545c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5545e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55460, 0x0);
dwc_ddrphy_apb_wr_32b(0x55462, 0x0);
dwc_ddrphy_apb_wr_32b(0x55464, 0x0);
dwc_ddrphy_apb_wr_32b(0x55466, 0x0);
dwc_ddrphy_apb_wr_32b(0x55468, 0x0);
dwc_ddrphy_apb_wr_32b(0x5546a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5546c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5546e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55470, 0x0);
dwc_ddrphy_apb_wr_32b(0x55472, 0x0);
dwc_ddrphy_apb_wr_32b(0x55474, 0x0);
dwc_ddrphy_apb_wr_32b(0x55476, 0x0);
dwc_ddrphy_apb_wr_32b(0x55478, 0x0);
dwc_ddrphy_apb_wr_32b(0x5547a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5547c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5547e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55480, 0x0);
dwc_ddrphy_apb_wr_32b(0x55482, 0x0);
dwc_ddrphy_apb_wr_32b(0x55484, 0x0);
dwc_ddrphy_apb_wr_32b(0x55486, 0x0);
dwc_ddrphy_apb_wr_32b(0x55488, 0x0);
dwc_ddrphy_apb_wr_32b(0x5548a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5548c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5548e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55490, 0x0);
dwc_ddrphy_apb_wr_32b(0x55492, 0x0);
dwc_ddrphy_apb_wr_32b(0x55494, 0x0);
dwc_ddrphy_apb_wr_32b(0x55496, 0x0);
dwc_ddrphy_apb_wr_32b(0x55498, 0x0);
dwc_ddrphy_apb_wr_32b(0x5549a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5549c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5549e, 0x0);
dwc_ddrphy_apb_wr_32b(0x554a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x554a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x554a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x554a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x554a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x554aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x554ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x554ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x554b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x554b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x554b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x554b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x554b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x554ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x554bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x554be, 0x0);
dwc_ddrphy_apb_wr_32b(0x554c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x554c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x554c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x554c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x554c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x554ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x554cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x554ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x554d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x554d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x554d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x554d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x554d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x554da, 0x0);
dwc_ddrphy_apb_wr_32b(0x554dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x554de, 0x0);
dwc_ddrphy_apb_wr_32b(0x554e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x554e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x554e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x554e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x554e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x554ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x554ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x554ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x554f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x554f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x554f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x554f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x554f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x554fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x554fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x554fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55500, 0x0);
dwc_ddrphy_apb_wr_32b(0x55502, 0x0);
dwc_ddrphy_apb_wr_32b(0x55504, 0x0);
dwc_ddrphy_apb_wr_32b(0x55506, 0x0);
dwc_ddrphy_apb_wr_32b(0x55508, 0x0);
dwc_ddrphy_apb_wr_32b(0x5550a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5550c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5550e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55510, 0x0);
dwc_ddrphy_apb_wr_32b(0x55512, 0x0);
dwc_ddrphy_apb_wr_32b(0x55514, 0x0);
dwc_ddrphy_apb_wr_32b(0x55516, 0x0);
dwc_ddrphy_apb_wr_32b(0x55518, 0x0);
dwc_ddrphy_apb_wr_32b(0x5551a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5551c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5551e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55520, 0x0);
dwc_ddrphy_apb_wr_32b(0x55522, 0x0);
dwc_ddrphy_apb_wr_32b(0x55524, 0x0);
dwc_ddrphy_apb_wr_32b(0x55526, 0x0);
dwc_ddrphy_apb_wr_32b(0x55528, 0x0);
dwc_ddrphy_apb_wr_32b(0x5552a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5552c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5552e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55530, 0x0);
dwc_ddrphy_apb_wr_32b(0x55532, 0x0);
dwc_ddrphy_apb_wr_32b(0x55534, 0x0);
dwc_ddrphy_apb_wr_32b(0x55536, 0x0);
dwc_ddrphy_apb_wr_32b(0x55538, 0x0);
dwc_ddrphy_apb_wr_32b(0x5553a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5553c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5553e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55540, 0x0);
dwc_ddrphy_apb_wr_32b(0x55542, 0x0);
dwc_ddrphy_apb_wr_32b(0x55544, 0x0);
dwc_ddrphy_apb_wr_32b(0x55546, 0x0);
dwc_ddrphy_apb_wr_32b(0x55548, 0x0);
dwc_ddrphy_apb_wr_32b(0x5554a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5554c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5554e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55550, 0x0);
dwc_ddrphy_apb_wr_32b(0x55552, 0x0);
dwc_ddrphy_apb_wr_32b(0x55554, 0x0);
dwc_ddrphy_apb_wr_32b(0x55556, 0x0);
dwc_ddrphy_apb_wr_32b(0x55558, 0x0);
dwc_ddrphy_apb_wr_32b(0x5555a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5555c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5555e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55560, 0x0);
dwc_ddrphy_apb_wr_32b(0x55562, 0x0);
dwc_ddrphy_apb_wr_32b(0x55564, 0x0);
dwc_ddrphy_apb_wr_32b(0x55566, 0x0);
dwc_ddrphy_apb_wr_32b(0x55568, 0x0);
dwc_ddrphy_apb_wr_32b(0x5556a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5556c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5556e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55570, 0x0);
dwc_ddrphy_apb_wr_32b(0x55572, 0x0);
dwc_ddrphy_apb_wr_32b(0x55574, 0x0);
dwc_ddrphy_apb_wr_32b(0x55576, 0x0);
dwc_ddrphy_apb_wr_32b(0x55578, 0x0);
dwc_ddrphy_apb_wr_32b(0x5557a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5557c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5557e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55580, 0x0);
dwc_ddrphy_apb_wr_32b(0x55582, 0x0);
dwc_ddrphy_apb_wr_32b(0x55584, 0x0);
dwc_ddrphy_apb_wr_32b(0x55586, 0x0);
dwc_ddrphy_apb_wr_32b(0x55588, 0x0);
dwc_ddrphy_apb_wr_32b(0x5558a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5558c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5558e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55590, 0x0);
dwc_ddrphy_apb_wr_32b(0x55592, 0x0);
dwc_ddrphy_apb_wr_32b(0x55594, 0x0);
dwc_ddrphy_apb_wr_32b(0x55596, 0x0);
dwc_ddrphy_apb_wr_32b(0x55598, 0x0);
dwc_ddrphy_apb_wr_32b(0x5559a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5559c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5559e, 0x0);
dwc_ddrphy_apb_wr_32b(0x555a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x555a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x555a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x555a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x555a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x555aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x555ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x555ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x555b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x555b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x555b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x555b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x555b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x555ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x555bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x555be, 0x0);
dwc_ddrphy_apb_wr_32b(0x555c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x555c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x555c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x555c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x555c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x555ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x555cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x555ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x555d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x555d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x555d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x555d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x555d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x555da, 0x0);
dwc_ddrphy_apb_wr_32b(0x555dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x555de, 0x0);
dwc_ddrphy_apb_wr_32b(0x555e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x555e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x555e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x555e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x555e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x555ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x555ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x555ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x555f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x555f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x555f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x555f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x555f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x555fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x555fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x555fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55600, 0x0);
dwc_ddrphy_apb_wr_32b(0x55602, 0x0);
dwc_ddrphy_apb_wr_32b(0x55604, 0x0);
dwc_ddrphy_apb_wr_32b(0x55606, 0x0);
dwc_ddrphy_apb_wr_32b(0x55608, 0x0);
dwc_ddrphy_apb_wr_32b(0x5560a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5560c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5560e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55610, 0x0);
dwc_ddrphy_apb_wr_32b(0x55612, 0x0);
dwc_ddrphy_apb_wr_32b(0x55614, 0x0);
dwc_ddrphy_apb_wr_32b(0x55616, 0x0);
dwc_ddrphy_apb_wr_32b(0x55618, 0x0);
dwc_ddrphy_apb_wr_32b(0x5561a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5561c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5561e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55620, 0x0);
dwc_ddrphy_apb_wr_32b(0x55622, 0x0);
dwc_ddrphy_apb_wr_32b(0x55624, 0x0);
dwc_ddrphy_apb_wr_32b(0x55626, 0x0);
dwc_ddrphy_apb_wr_32b(0x55628, 0x0);
dwc_ddrphy_apb_wr_32b(0x5562a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5562c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5562e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55630, 0x0);
dwc_ddrphy_apb_wr_32b(0x55632, 0x0);
dwc_ddrphy_apb_wr_32b(0x55634, 0x0);
dwc_ddrphy_apb_wr_32b(0x55636, 0x0);
dwc_ddrphy_apb_wr_32b(0x55638, 0x0);
dwc_ddrphy_apb_wr_32b(0x5563a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5563c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5563e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55640, 0x0);
dwc_ddrphy_apb_wr_32b(0x55642, 0x0);
dwc_ddrphy_apb_wr_32b(0x55644, 0x0);
dwc_ddrphy_apb_wr_32b(0x55646, 0x0);
dwc_ddrphy_apb_wr_32b(0x55648, 0x0);
dwc_ddrphy_apb_wr_32b(0x5564a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5564c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5564e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55650, 0x0);
dwc_ddrphy_apb_wr_32b(0x55652, 0x0);
dwc_ddrphy_apb_wr_32b(0x55654, 0x0);
dwc_ddrphy_apb_wr_32b(0x55656, 0x0);
dwc_ddrphy_apb_wr_32b(0x55658, 0x0);
dwc_ddrphy_apb_wr_32b(0x5565a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5565c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5565e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55660, 0x0);
dwc_ddrphy_apb_wr_32b(0x55662, 0x0);
dwc_ddrphy_apb_wr_32b(0x55664, 0x0);
dwc_ddrphy_apb_wr_32b(0x55666, 0x0);
dwc_ddrphy_apb_wr_32b(0x55668, 0x0);
dwc_ddrphy_apb_wr_32b(0x5566a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5566c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5566e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55670, 0x0);
dwc_ddrphy_apb_wr_32b(0x55672, 0x0);
dwc_ddrphy_apb_wr_32b(0x55674, 0x0);
dwc_ddrphy_apb_wr_32b(0x55676, 0x0);
dwc_ddrphy_apb_wr_32b(0x55678, 0x0);
dwc_ddrphy_apb_wr_32b(0x5567a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5567c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5567e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55680, 0x0);
dwc_ddrphy_apb_wr_32b(0x55682, 0x0);
dwc_ddrphy_apb_wr_32b(0x55684, 0x0);
dwc_ddrphy_apb_wr_32b(0x55686, 0x0);
dwc_ddrphy_apb_wr_32b(0x55688, 0x0);
dwc_ddrphy_apb_wr_32b(0x5568a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5568c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5568e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55690, 0x0);
dwc_ddrphy_apb_wr_32b(0x55692, 0x0);
dwc_ddrphy_apb_wr_32b(0x55694, 0x0);
dwc_ddrphy_apb_wr_32b(0x55696, 0x0);
dwc_ddrphy_apb_wr_32b(0x55698, 0x0);
dwc_ddrphy_apb_wr_32b(0x5569a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5569c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5569e, 0x0);
dwc_ddrphy_apb_wr_32b(0x556a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x556a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x556a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x556a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x556a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x556aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x556ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x556ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x556b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x556b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x556b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x556b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x556b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x556ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x556bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x556be, 0x0);
dwc_ddrphy_apb_wr_32b(0x556c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x556c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x556c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x556c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x556c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x556ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x556cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x556ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x556d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x556d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x556d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x556d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x556d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x556da, 0x0);
dwc_ddrphy_apb_wr_32b(0x556dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x556de, 0x0);
dwc_ddrphy_apb_wr_32b(0x556e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x556e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x556e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x556e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x556e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x556ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x556ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x556ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x556f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x556f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x556f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x556f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x556f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x556fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x556fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x556fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55700, 0x0);
dwc_ddrphy_apb_wr_32b(0x55702, 0x0);
dwc_ddrphy_apb_wr_32b(0x55704, 0x0);
dwc_ddrphy_apb_wr_32b(0x55706, 0x0);
dwc_ddrphy_apb_wr_32b(0x55708, 0x0);
dwc_ddrphy_apb_wr_32b(0x5570a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5570c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5570e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55710, 0x0);
dwc_ddrphy_apb_wr_32b(0x55712, 0x0);
dwc_ddrphy_apb_wr_32b(0x55714, 0x0);
dwc_ddrphy_apb_wr_32b(0x55716, 0x0);
dwc_ddrphy_apb_wr_32b(0x55718, 0x0);
dwc_ddrphy_apb_wr_32b(0x5571a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5571c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5571e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55720, 0x0);
dwc_ddrphy_apb_wr_32b(0x55722, 0x0);
dwc_ddrphy_apb_wr_32b(0x55724, 0x0);
dwc_ddrphy_apb_wr_32b(0x55726, 0x0);
dwc_ddrphy_apb_wr_32b(0x55728, 0x0);
dwc_ddrphy_apb_wr_32b(0x5572a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5572c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5572e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55730, 0x0);
dwc_ddrphy_apb_wr_32b(0x55732, 0x0);
dwc_ddrphy_apb_wr_32b(0x55734, 0x0);
dwc_ddrphy_apb_wr_32b(0x55736, 0x0);
dwc_ddrphy_apb_wr_32b(0x55738, 0x0);
dwc_ddrphy_apb_wr_32b(0x5573a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5573c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5573e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55740, 0x0);
dwc_ddrphy_apb_wr_32b(0x55742, 0x0);
dwc_ddrphy_apb_wr_32b(0x55744, 0x0);
dwc_ddrphy_apb_wr_32b(0x55746, 0x0);
dwc_ddrphy_apb_wr_32b(0x55748, 0x0);
dwc_ddrphy_apb_wr_32b(0x5574a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5574c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5574e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55750, 0x0);
dwc_ddrphy_apb_wr_32b(0x55752, 0x0);
dwc_ddrphy_apb_wr_32b(0x55754, 0x0);
dwc_ddrphy_apb_wr_32b(0x55756, 0x0);
dwc_ddrphy_apb_wr_32b(0x55758, 0x0);
dwc_ddrphy_apb_wr_32b(0x5575a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5575c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5575e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55760, 0x0);
dwc_ddrphy_apb_wr_32b(0x55762, 0x0);
dwc_ddrphy_apb_wr_32b(0x55764, 0x0);
dwc_ddrphy_apb_wr_32b(0x55766, 0x0);
dwc_ddrphy_apb_wr_32b(0x55768, 0x0);
dwc_ddrphy_apb_wr_32b(0x5576a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5576c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5576e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55770, 0x0);
dwc_ddrphy_apb_wr_32b(0x55772, 0x0);
dwc_ddrphy_apb_wr_32b(0x55774, 0x0);
dwc_ddrphy_apb_wr_32b(0x55776, 0x0);
dwc_ddrphy_apb_wr_32b(0x55778, 0x0);
dwc_ddrphy_apb_wr_32b(0x5577a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5577c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5577e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55780, 0x0);
dwc_ddrphy_apb_wr_32b(0x55782, 0x0);
dwc_ddrphy_apb_wr_32b(0x55784, 0x0);
dwc_ddrphy_apb_wr_32b(0x55786, 0x0);
dwc_ddrphy_apb_wr_32b(0x55788, 0x0);
dwc_ddrphy_apb_wr_32b(0x5578a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5578c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5578e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55790, 0x0);
dwc_ddrphy_apb_wr_32b(0x55792, 0x0);
dwc_ddrphy_apb_wr_32b(0x55794, 0x0);
dwc_ddrphy_apb_wr_32b(0x55796, 0x0);
dwc_ddrphy_apb_wr_32b(0x55798, 0x0);
dwc_ddrphy_apb_wr_32b(0x5579a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5579c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5579e, 0x0);
dwc_ddrphy_apb_wr_32b(0x557a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x557a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x557a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x557a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x557a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x557aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x557ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x557ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x557b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x557b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x557b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x557b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x557b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x557ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x557bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x557be, 0x0);
dwc_ddrphy_apb_wr_32b(0x557c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x557c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x557c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x557c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x557c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x557ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x557cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x557ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x557d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x557d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x557d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x557d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x557d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x557da, 0x0);
dwc_ddrphy_apb_wr_32b(0x557dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x557de, 0x0);
dwc_ddrphy_apb_wr_32b(0x557e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x557e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x557e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x557e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x557e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x557ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x557ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x557ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x557f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x557f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x557f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x557f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x557f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x557fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x557fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x557fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55800, 0x0);
dwc_ddrphy_apb_wr_32b(0x55802, 0x0);
dwc_ddrphy_apb_wr_32b(0x55804, 0x0);
dwc_ddrphy_apb_wr_32b(0x55806, 0x0);
dwc_ddrphy_apb_wr_32b(0x55808, 0x0);
dwc_ddrphy_apb_wr_32b(0x5580a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5580c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5580e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55810, 0x0);
dwc_ddrphy_apb_wr_32b(0x55812, 0x0);
dwc_ddrphy_apb_wr_32b(0x55814, 0x0);
dwc_ddrphy_apb_wr_32b(0x55816, 0x0);
dwc_ddrphy_apb_wr_32b(0x55818, 0x0);
dwc_ddrphy_apb_wr_32b(0x5581a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5581c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5581e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55820, 0x0);
dwc_ddrphy_apb_wr_32b(0x55822, 0x0);
dwc_ddrphy_apb_wr_32b(0x55824, 0x0);
dwc_ddrphy_apb_wr_32b(0x55826, 0x0);
dwc_ddrphy_apb_wr_32b(0x55828, 0x0);
dwc_ddrphy_apb_wr_32b(0x5582a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5582c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5582e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55830, 0x0);
dwc_ddrphy_apb_wr_32b(0x55832, 0x0);
dwc_ddrphy_apb_wr_32b(0x55834, 0x0);
dwc_ddrphy_apb_wr_32b(0x55836, 0x0);
dwc_ddrphy_apb_wr_32b(0x55838, 0x0);
dwc_ddrphy_apb_wr_32b(0x5583a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5583c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5583e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55840, 0x0);
dwc_ddrphy_apb_wr_32b(0x55842, 0x0);
dwc_ddrphy_apb_wr_32b(0x55844, 0x0);
dwc_ddrphy_apb_wr_32b(0x55846, 0x0);
dwc_ddrphy_apb_wr_32b(0x55848, 0x0);
dwc_ddrphy_apb_wr_32b(0x5584a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5584c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5584e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55850, 0x0);
dwc_ddrphy_apb_wr_32b(0x55852, 0x0);
dwc_ddrphy_apb_wr_32b(0x55854, 0x0);
dwc_ddrphy_apb_wr_32b(0x55856, 0x0);
dwc_ddrphy_apb_wr_32b(0x55858, 0x0);
dwc_ddrphy_apb_wr_32b(0x5585a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5585c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5585e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55860, 0x0);
dwc_ddrphy_apb_wr_32b(0x55862, 0x0);
dwc_ddrphy_apb_wr_32b(0x55864, 0x0);
dwc_ddrphy_apb_wr_32b(0x55866, 0x0);
dwc_ddrphy_apb_wr_32b(0x55868, 0x0);
dwc_ddrphy_apb_wr_32b(0x5586a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5586c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5586e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55870, 0x0);
dwc_ddrphy_apb_wr_32b(0x55872, 0x0);
dwc_ddrphy_apb_wr_32b(0x55874, 0x0);
dwc_ddrphy_apb_wr_32b(0x55876, 0x0);
dwc_ddrphy_apb_wr_32b(0x55878, 0x0);
dwc_ddrphy_apb_wr_32b(0x5587a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5587c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5587e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55880, 0x0);
dwc_ddrphy_apb_wr_32b(0x55882, 0x0);
dwc_ddrphy_apb_wr_32b(0x55884, 0x0);
dwc_ddrphy_apb_wr_32b(0x55886, 0x0);
dwc_ddrphy_apb_wr_32b(0x55888, 0x0);
dwc_ddrphy_apb_wr_32b(0x5588a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5588c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5588e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55890, 0x0);
dwc_ddrphy_apb_wr_32b(0x55892, 0x0);
dwc_ddrphy_apb_wr_32b(0x55894, 0x0);
dwc_ddrphy_apb_wr_32b(0x55896, 0x0);
dwc_ddrphy_apb_wr_32b(0x55898, 0x0);
dwc_ddrphy_apb_wr_32b(0x5589a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5589c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5589e, 0x0);
dwc_ddrphy_apb_wr_32b(0x558a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x558a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x558a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x558a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x558a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x558aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x558ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x558ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x558b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x558b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x558b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x558b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x558b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x558ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x558bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x558be, 0x0);
dwc_ddrphy_apb_wr_32b(0x558c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x558c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x558c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x558c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x558c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x558ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x558cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x558ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x558d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x558d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x558d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x558d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x558d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x558da, 0x0);
dwc_ddrphy_apb_wr_32b(0x558dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x558de, 0x0);
dwc_ddrphy_apb_wr_32b(0x558e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x558e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x558e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x558e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x558e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x558ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x558ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x558ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x558f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x558f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x558f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x558f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x558f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x558fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x558fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x558fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55900, 0x0);
dwc_ddrphy_apb_wr_32b(0x55902, 0x0);
dwc_ddrphy_apb_wr_32b(0x55904, 0x0);
dwc_ddrphy_apb_wr_32b(0x55906, 0x0);
dwc_ddrphy_apb_wr_32b(0x55908, 0x0);
dwc_ddrphy_apb_wr_32b(0x5590a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5590c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5590e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55910, 0x0);
dwc_ddrphy_apb_wr_32b(0x55912, 0x0);
dwc_ddrphy_apb_wr_32b(0x55914, 0x0);
dwc_ddrphy_apb_wr_32b(0x55916, 0x0);
dwc_ddrphy_apb_wr_32b(0x55918, 0x0);
dwc_ddrphy_apb_wr_32b(0x5591a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5591c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5591e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55920, 0x0);
dwc_ddrphy_apb_wr_32b(0x55922, 0x0);
dwc_ddrphy_apb_wr_32b(0x55924, 0x0);
dwc_ddrphy_apb_wr_32b(0x55926, 0x0);
dwc_ddrphy_apb_wr_32b(0x55928, 0x0);
dwc_ddrphy_apb_wr_32b(0x5592a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5592c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5592e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55930, 0x0);
dwc_ddrphy_apb_wr_32b(0x55932, 0x0);
dwc_ddrphy_apb_wr_32b(0x55934, 0x0);
dwc_ddrphy_apb_wr_32b(0x55936, 0x0);
dwc_ddrphy_apb_wr_32b(0x55938, 0x0);
dwc_ddrphy_apb_wr_32b(0x5593a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5593c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5593e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55940, 0x0);
dwc_ddrphy_apb_wr_32b(0x55942, 0x0);
dwc_ddrphy_apb_wr_32b(0x55944, 0x0);
dwc_ddrphy_apb_wr_32b(0x55946, 0x0);
dwc_ddrphy_apb_wr_32b(0x55948, 0x0);
dwc_ddrphy_apb_wr_32b(0x5594a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5594c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5594e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55950, 0x0);
dwc_ddrphy_apb_wr_32b(0x55952, 0x0);
dwc_ddrphy_apb_wr_32b(0x55954, 0x0);
dwc_ddrphy_apb_wr_32b(0x55956, 0x0);
dwc_ddrphy_apb_wr_32b(0x55958, 0x0);
dwc_ddrphy_apb_wr_32b(0x5595a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5595c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5595e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55960, 0x0);
dwc_ddrphy_apb_wr_32b(0x55962, 0x0);
dwc_ddrphy_apb_wr_32b(0x55964, 0x0);
dwc_ddrphy_apb_wr_32b(0x55966, 0x0);
dwc_ddrphy_apb_wr_32b(0x55968, 0x0);
dwc_ddrphy_apb_wr_32b(0x5596a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5596c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5596e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55970, 0x0);
dwc_ddrphy_apb_wr_32b(0x55972, 0x0);
dwc_ddrphy_apb_wr_32b(0x55974, 0x0);
dwc_ddrphy_apb_wr_32b(0x55976, 0x0);
dwc_ddrphy_apb_wr_32b(0x55978, 0x0);
dwc_ddrphy_apb_wr_32b(0x5597a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5597c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5597e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55980, 0x0);
dwc_ddrphy_apb_wr_32b(0x55982, 0x0);
dwc_ddrphy_apb_wr_32b(0x55984, 0x0);
dwc_ddrphy_apb_wr_32b(0x55986, 0x0);
dwc_ddrphy_apb_wr_32b(0x55988, 0x0);
dwc_ddrphy_apb_wr_32b(0x5598a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5598c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5598e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55990, 0x0);
dwc_ddrphy_apb_wr_32b(0x55992, 0x0);
dwc_ddrphy_apb_wr_32b(0x55994, 0x0);
dwc_ddrphy_apb_wr_32b(0x55996, 0x0);
dwc_ddrphy_apb_wr_32b(0x55998, 0x0);
dwc_ddrphy_apb_wr_32b(0x5599a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5599c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5599e, 0x0);
dwc_ddrphy_apb_wr_32b(0x559a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x559a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x559a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x559a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x559a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x559aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x559ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x559ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x559b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x559b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x559b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x559b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x559b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x559ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x559bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x559be, 0x0);
dwc_ddrphy_apb_wr_32b(0x559c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x559c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x559c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x559c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x559c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x559ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x559cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x559ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x559d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x559d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x559d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x559d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x559d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x559da, 0x0);
dwc_ddrphy_apb_wr_32b(0x559dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x559de, 0x0);
dwc_ddrphy_apb_wr_32b(0x559e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x559e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x559e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x559e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x559e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x559ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x559ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x559ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x559f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x559f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x559f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x559f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x559f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x559fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x559fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x559fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a00, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a02, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a04, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a06, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a08, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a10, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a12, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a14, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a16, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a18, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a20, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a22, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a24, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a26, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a28, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a30, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a32, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a34, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a36, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a38, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a40, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a42, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a44, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a46, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a48, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a50, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a52, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a54, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a56, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a58, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a60, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a62, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a64, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a66, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a68, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a70, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a72, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a74, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a76, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a78, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a80, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a82, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a84, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a86, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a88, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a90, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a92, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a94, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a96, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a98, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55a9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55aa0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55aa2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55aa4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55aa6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55aa8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55aaa, 0x0);
dwc_ddrphy_apb_wr_32b(0x55aac, 0x0);
dwc_ddrphy_apb_wr_32b(0x55aae, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ab0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ab2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ab4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ab6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ab8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55aba, 0x0);
dwc_ddrphy_apb_wr_32b(0x55abc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55abe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ac0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ac2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ac4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ac6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ac8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55aca, 0x0);
dwc_ddrphy_apb_wr_32b(0x55acc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ace, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ad0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ad2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ad4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ad6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ad8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ada, 0x0);
dwc_ddrphy_apb_wr_32b(0x55adc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ade, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ae0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ae2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ae4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ae6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ae8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55aea, 0x0);
dwc_ddrphy_apb_wr_32b(0x55aec, 0x0);
dwc_ddrphy_apb_wr_32b(0x55aee, 0x0);
dwc_ddrphy_apb_wr_32b(0x55af0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55af2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55af4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55af6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55af8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55afa, 0x0);
dwc_ddrphy_apb_wr_32b(0x55afc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55afe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b00, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b02, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b04, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b06, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b08, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b10, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b12, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b14, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b16, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b18, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b20, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b22, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b24, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b26, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b28, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b30, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b32, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b34, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b36, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b38, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b40, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b42, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b44, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b46, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b48, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b50, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b52, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b54, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b56, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b58, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b60, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b62, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b64, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b66, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b68, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b70, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b72, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b74, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b76, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b78, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b80, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b82, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b84, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b86, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b88, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b90, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b92, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b94, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b96, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b98, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55b9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ba0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ba2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ba4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ba6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ba8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55baa, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bac, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bae, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bba, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bca, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bcc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bce, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bda, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bdc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bde, 0x0);
dwc_ddrphy_apb_wr_32b(0x55be0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55be2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55be4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55be6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55be8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bea, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bec, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bee, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bf0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bf2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bf4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bf6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bf8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bfa, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bfc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55bfe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c00, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c02, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c04, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c06, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c08, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c10, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c12, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c14, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c16, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c18, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c20, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c22, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c24, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c26, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c28, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c30, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c32, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c34, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c36, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c38, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c40, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c42, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c44, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c46, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c48, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c50, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c52, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c54, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c56, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c58, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c60, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c62, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c64, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c66, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c68, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c70, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c72, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c74, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c76, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c78, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c80, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c82, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c84, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c86, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c88, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c90, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c92, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c94, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c96, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c98, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55c9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ca0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ca2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ca4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ca6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ca8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55caa, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cac, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cae, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cba, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cca, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ccc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cce, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cda, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cdc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cde, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ce0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ce2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ce4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ce6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ce8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cea, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cec, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cee, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cf0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cf2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cf4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cf6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cf8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cfa, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cfc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55cfe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d00, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d02, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d04, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d06, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d08, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d10, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d12, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d14, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d16, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d18, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d20, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d22, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d24, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d26, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d28, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d30, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d32, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d34, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d36, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d38, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d40, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d42, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d44, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d46, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d48, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d50, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d52, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d54, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d56, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d58, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d60, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d62, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d64, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d66, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d68, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d70, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d72, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d74, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d76, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d78, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d80, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d82, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d84, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d86, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d88, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d90, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d92, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d94, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d96, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d98, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55d9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55da0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55da2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55da4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55da6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55da8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55daa, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dac, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dae, 0x0);
dwc_ddrphy_apb_wr_32b(0x55db0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55db2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55db4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55db6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55db8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dba, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dca, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dcc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dce, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dda, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ddc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dde, 0x0);
dwc_ddrphy_apb_wr_32b(0x55de0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55de2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55de4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55de6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55de8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dea, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dec, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dee, 0x0);
dwc_ddrphy_apb_wr_32b(0x55df0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55df2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55df4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55df6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55df8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dfa, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dfc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55dfe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e00, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e02, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e04, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e06, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e08, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e10, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e12, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e14, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e16, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e18, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e20, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e22, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e24, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e26, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e28, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e30, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e32, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e34, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e36, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e38, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e40, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e42, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e44, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e46, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e48, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e50, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e52, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e54, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e56, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e58, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e60, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e62, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e64, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e66, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e68, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e70, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e72, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e74, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e76, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e78, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e80, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e82, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e84, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e86, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e88, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e90, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e92, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e94, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e96, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e98, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55e9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ea0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ea2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ea4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ea6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ea8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55eaa, 0x0);
dwc_ddrphy_apb_wr_32b(0x55eac, 0x0);
dwc_ddrphy_apb_wr_32b(0x55eae, 0x0);
dwc_ddrphy_apb_wr_32b(0x55eb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55eb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55eb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55eb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55eb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55eba, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ebc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ebe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ec0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ec2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ec4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ec6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ec8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55eca, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ecc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ece, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ed0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ed2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ed4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ed6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ed8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55eda, 0x0);
dwc_ddrphy_apb_wr_32b(0x55edc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ede, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ee0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ee2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ee4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ee6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ee8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55eea, 0x0);
dwc_ddrphy_apb_wr_32b(0x55eec, 0x0);
dwc_ddrphy_apb_wr_32b(0x55eee, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ef0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ef2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ef4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ef6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ef8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55efa, 0x0);
dwc_ddrphy_apb_wr_32b(0x55efc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55efe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f00, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f02, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f04, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f06, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f08, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f10, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f12, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f14, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f16, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f18, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f20, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f22, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f24, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f26, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f28, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f30, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f32, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f34, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f36, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f38, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f40, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f42, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f44, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f46, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f48, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f50, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f52, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f54, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f56, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f58, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f60, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f62, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f64, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f66, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f68, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f70, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f72, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f74, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f76, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f78, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f80, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f82, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f84, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f86, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f88, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f90, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f92, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f94, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f96, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f98, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x55f9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fa0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fa2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fa4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fa6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fa8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55faa, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fac, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fae, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fba, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fca, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fcc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fce, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fda, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fdc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fde, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fe0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fe2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fe4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fe6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fe8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fea, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fec, 0x0);
dwc_ddrphy_apb_wr_32b(0x55fee, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ff0, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ff2, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ff4, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ff6, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ff8, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ffa, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ffc, 0x0);
dwc_ddrphy_apb_wr_32b(0x55ffe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56000, 0x0);
dwc_ddrphy_apb_wr_32b(0x56002, 0x0);
dwc_ddrphy_apb_wr_32b(0x56004, 0x0);
dwc_ddrphy_apb_wr_32b(0x56006, 0x0);
dwc_ddrphy_apb_wr_32b(0x56008, 0x0);
dwc_ddrphy_apb_wr_32b(0x5600a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5600c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5600e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56010, 0x0);
dwc_ddrphy_apb_wr_32b(0x56012, 0x0);
dwc_ddrphy_apb_wr_32b(0x56014, 0x0);
dwc_ddrphy_apb_wr_32b(0x56016, 0x0);
dwc_ddrphy_apb_wr_32b(0x56018, 0x0);
dwc_ddrphy_apb_wr_32b(0x5601a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5601c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5601e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56020, 0x0);
dwc_ddrphy_apb_wr_32b(0x56022, 0x0);
dwc_ddrphy_apb_wr_32b(0x56024, 0x0);
dwc_ddrphy_apb_wr_32b(0x56026, 0x0);
dwc_ddrphy_apb_wr_32b(0x56028, 0x0);
dwc_ddrphy_apb_wr_32b(0x5602a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5602c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5602e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56030, 0x0);
dwc_ddrphy_apb_wr_32b(0x56032, 0x0);
dwc_ddrphy_apb_wr_32b(0x56034, 0x0);
dwc_ddrphy_apb_wr_32b(0x56036, 0x0);
dwc_ddrphy_apb_wr_32b(0x56038, 0x0);
dwc_ddrphy_apb_wr_32b(0x5603a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5603c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5603e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56040, 0x0);
dwc_ddrphy_apb_wr_32b(0x56042, 0x0);
dwc_ddrphy_apb_wr_32b(0x56044, 0x0);
dwc_ddrphy_apb_wr_32b(0x56046, 0x0);
dwc_ddrphy_apb_wr_32b(0x56048, 0x0);
dwc_ddrphy_apb_wr_32b(0x5604a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5604c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5604e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56050, 0x0);
dwc_ddrphy_apb_wr_32b(0x56052, 0x0);
dwc_ddrphy_apb_wr_32b(0x56054, 0x0);
dwc_ddrphy_apb_wr_32b(0x56056, 0x0);
dwc_ddrphy_apb_wr_32b(0x56058, 0x0);
dwc_ddrphy_apb_wr_32b(0x5605a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5605c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5605e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56060, 0x0);
dwc_ddrphy_apb_wr_32b(0x56062, 0x0);
dwc_ddrphy_apb_wr_32b(0x56064, 0x0);
dwc_ddrphy_apb_wr_32b(0x56066, 0x0);
dwc_ddrphy_apb_wr_32b(0x56068, 0x0);
dwc_ddrphy_apb_wr_32b(0x5606a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5606c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5606e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56070, 0x0);
dwc_ddrphy_apb_wr_32b(0x56072, 0x0);
dwc_ddrphy_apb_wr_32b(0x56074, 0x0);
dwc_ddrphy_apb_wr_32b(0x56076, 0x0);
dwc_ddrphy_apb_wr_32b(0x56078, 0x0);
dwc_ddrphy_apb_wr_32b(0x5607a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5607c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5607e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56080, 0x0);
dwc_ddrphy_apb_wr_32b(0x56082, 0x0);
dwc_ddrphy_apb_wr_32b(0x56084, 0x0);
dwc_ddrphy_apb_wr_32b(0x56086, 0x0);
dwc_ddrphy_apb_wr_32b(0x56088, 0x0);
dwc_ddrphy_apb_wr_32b(0x5608a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5608c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5608e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56090, 0x0);
dwc_ddrphy_apb_wr_32b(0x56092, 0x0);
dwc_ddrphy_apb_wr_32b(0x56094, 0x0);
dwc_ddrphy_apb_wr_32b(0x56096, 0x0);
dwc_ddrphy_apb_wr_32b(0x56098, 0x0);
dwc_ddrphy_apb_wr_32b(0x5609a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5609c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5609e, 0x0);
dwc_ddrphy_apb_wr_32b(0x560a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x560a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x560a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x560a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x560a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x560aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x560ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x560ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x560b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x560b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x560b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x560b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x560b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x560ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x560bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x560be, 0x0);
dwc_ddrphy_apb_wr_32b(0x560c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x560c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x560c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x560c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x560c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x560ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x560cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x560ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x560d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x560d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x560d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x560d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x560d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x560da, 0x0);
dwc_ddrphy_apb_wr_32b(0x560dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x560de, 0x0);
dwc_ddrphy_apb_wr_32b(0x560e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x560e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x560e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x560e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x560e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x560ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x560ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x560ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x560f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x560f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x560f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x560f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x560f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x560fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x560fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x560fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56100, 0x0);
dwc_ddrphy_apb_wr_32b(0x56102, 0x0);
dwc_ddrphy_apb_wr_32b(0x56104, 0x0);
dwc_ddrphy_apb_wr_32b(0x56106, 0x0);
dwc_ddrphy_apb_wr_32b(0x56108, 0x0);
dwc_ddrphy_apb_wr_32b(0x5610a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5610c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5610e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56110, 0x0);
dwc_ddrphy_apb_wr_32b(0x56112, 0x0);
dwc_ddrphy_apb_wr_32b(0x56114, 0x0);
dwc_ddrphy_apb_wr_32b(0x56116, 0x0);
dwc_ddrphy_apb_wr_32b(0x56118, 0x0);
dwc_ddrphy_apb_wr_32b(0x5611a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5611c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5611e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56120, 0x0);
dwc_ddrphy_apb_wr_32b(0x56122, 0x0);
dwc_ddrphy_apb_wr_32b(0x56124, 0x0);
dwc_ddrphy_apb_wr_32b(0x56126, 0x0);
dwc_ddrphy_apb_wr_32b(0x56128, 0x0);
dwc_ddrphy_apb_wr_32b(0x5612a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5612c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5612e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56130, 0x0);
dwc_ddrphy_apb_wr_32b(0x56132, 0x0);
dwc_ddrphy_apb_wr_32b(0x56134, 0x0);
dwc_ddrphy_apb_wr_32b(0x56136, 0x0);
dwc_ddrphy_apb_wr_32b(0x56138, 0x0);
dwc_ddrphy_apb_wr_32b(0x5613a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5613c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5613e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56140, 0x0);
dwc_ddrphy_apb_wr_32b(0x56142, 0x0);
dwc_ddrphy_apb_wr_32b(0x56144, 0x0);
dwc_ddrphy_apb_wr_32b(0x56146, 0x0);
dwc_ddrphy_apb_wr_32b(0x56148, 0x0);
dwc_ddrphy_apb_wr_32b(0x5614a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5614c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5614e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56150, 0x0);
dwc_ddrphy_apb_wr_32b(0x56152, 0x0);
dwc_ddrphy_apb_wr_32b(0x56154, 0x0);
dwc_ddrphy_apb_wr_32b(0x56156, 0x0);
dwc_ddrphy_apb_wr_32b(0x56158, 0x0);
dwc_ddrphy_apb_wr_32b(0x5615a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5615c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5615e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56160, 0x0);
dwc_ddrphy_apb_wr_32b(0x56162, 0x0);
dwc_ddrphy_apb_wr_32b(0x56164, 0x0);
dwc_ddrphy_apb_wr_32b(0x56166, 0x0);
dwc_ddrphy_apb_wr_32b(0x56168, 0x0);
dwc_ddrphy_apb_wr_32b(0x5616a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5616c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5616e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56170, 0x0);
dwc_ddrphy_apb_wr_32b(0x56172, 0x0);
dwc_ddrphy_apb_wr_32b(0x56174, 0x0);
dwc_ddrphy_apb_wr_32b(0x56176, 0x0);
dwc_ddrphy_apb_wr_32b(0x56178, 0x0);
dwc_ddrphy_apb_wr_32b(0x5617a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5617c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5617e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56180, 0x0);
dwc_ddrphy_apb_wr_32b(0x56182, 0x0);
dwc_ddrphy_apb_wr_32b(0x56184, 0x0);
dwc_ddrphy_apb_wr_32b(0x56186, 0x0);
dwc_ddrphy_apb_wr_32b(0x56188, 0x0);
dwc_ddrphy_apb_wr_32b(0x5618a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5618c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5618e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56190, 0x0);
dwc_ddrphy_apb_wr_32b(0x56192, 0x0);
dwc_ddrphy_apb_wr_32b(0x56194, 0x0);
dwc_ddrphy_apb_wr_32b(0x56196, 0x0);
dwc_ddrphy_apb_wr_32b(0x56198, 0x0);
dwc_ddrphy_apb_wr_32b(0x5619a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5619c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5619e, 0x0);
dwc_ddrphy_apb_wr_32b(0x561a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x561a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x561a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x561a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x561a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x561aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x561ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x561ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x561b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x561b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x561b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x561b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x561b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x561ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x561bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x561be, 0x0);
dwc_ddrphy_apb_wr_32b(0x561c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x561c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x561c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x561c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x561c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x561ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x561cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x561ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x561d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x561d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x561d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x561d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x561d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x561da, 0x0);
dwc_ddrphy_apb_wr_32b(0x561dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x561de, 0x0);
dwc_ddrphy_apb_wr_32b(0x561e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x561e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x561e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x561e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x561e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x561ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x561ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x561ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x561f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x561f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x561f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x561f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x561f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x561fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x561fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x561fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56200, 0x0);
dwc_ddrphy_apb_wr_32b(0x56202, 0x0);
dwc_ddrphy_apb_wr_32b(0x56204, 0x0);
dwc_ddrphy_apb_wr_32b(0x56206, 0x0);
dwc_ddrphy_apb_wr_32b(0x56208, 0x0);
dwc_ddrphy_apb_wr_32b(0x5620a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5620c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5620e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56210, 0x0);
dwc_ddrphy_apb_wr_32b(0x56212, 0x0);
dwc_ddrphy_apb_wr_32b(0x56214, 0x0);
dwc_ddrphy_apb_wr_32b(0x56216, 0x0);
dwc_ddrphy_apb_wr_32b(0x56218, 0x0);
dwc_ddrphy_apb_wr_32b(0x5621a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5621c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5621e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56220, 0x0);
dwc_ddrphy_apb_wr_32b(0x56222, 0x0);
dwc_ddrphy_apb_wr_32b(0x56224, 0x0);
dwc_ddrphy_apb_wr_32b(0x56226, 0x0);
dwc_ddrphy_apb_wr_32b(0x56228, 0x0);
dwc_ddrphy_apb_wr_32b(0x5622a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5622c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5622e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56230, 0x0);
dwc_ddrphy_apb_wr_32b(0x56232, 0x0);
dwc_ddrphy_apb_wr_32b(0x56234, 0x0);
dwc_ddrphy_apb_wr_32b(0x56236, 0x0);
dwc_ddrphy_apb_wr_32b(0x56238, 0x0);
dwc_ddrphy_apb_wr_32b(0x5623a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5623c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5623e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56240, 0x0);
dwc_ddrphy_apb_wr_32b(0x56242, 0x0);
dwc_ddrphy_apb_wr_32b(0x56244, 0x0);
dwc_ddrphy_apb_wr_32b(0x56246, 0x0);
dwc_ddrphy_apb_wr_32b(0x56248, 0x0);
dwc_ddrphy_apb_wr_32b(0x5624a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5624c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5624e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56250, 0x0);
dwc_ddrphy_apb_wr_32b(0x56252, 0x0);
dwc_ddrphy_apb_wr_32b(0x56254, 0x0);
dwc_ddrphy_apb_wr_32b(0x56256, 0x0);
dwc_ddrphy_apb_wr_32b(0x56258, 0x0);
dwc_ddrphy_apb_wr_32b(0x5625a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5625c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5625e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56260, 0x0);
dwc_ddrphy_apb_wr_32b(0x56262, 0x0);
dwc_ddrphy_apb_wr_32b(0x56264, 0x0);
dwc_ddrphy_apb_wr_32b(0x56266, 0x0);
dwc_ddrphy_apb_wr_32b(0x56268, 0x0);
dwc_ddrphy_apb_wr_32b(0x5626a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5626c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5626e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56270, 0x0);
dwc_ddrphy_apb_wr_32b(0x56272, 0x0);
dwc_ddrphy_apb_wr_32b(0x56274, 0x0);
dwc_ddrphy_apb_wr_32b(0x56276, 0x0);
dwc_ddrphy_apb_wr_32b(0x56278, 0x0);
dwc_ddrphy_apb_wr_32b(0x5627a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5627c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5627e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56280, 0x0);
dwc_ddrphy_apb_wr_32b(0x56282, 0x0);
dwc_ddrphy_apb_wr_32b(0x56284, 0x0);
dwc_ddrphy_apb_wr_32b(0x56286, 0x0);
dwc_ddrphy_apb_wr_32b(0x56288, 0x0);
dwc_ddrphy_apb_wr_32b(0x5628a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5628c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5628e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56290, 0x0);
dwc_ddrphy_apb_wr_32b(0x56292, 0x0);
dwc_ddrphy_apb_wr_32b(0x56294, 0x0);
dwc_ddrphy_apb_wr_32b(0x56296, 0x0);
dwc_ddrphy_apb_wr_32b(0x56298, 0x0);
dwc_ddrphy_apb_wr_32b(0x5629a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5629c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5629e, 0x0);
dwc_ddrphy_apb_wr_32b(0x562a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x562a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x562a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x562a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x562a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x562aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x562ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x562ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x562b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x562b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x562b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x562b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x562b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x562ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x562bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x562be, 0x0);
dwc_ddrphy_apb_wr_32b(0x562c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x562c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x562c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x562c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x562c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x562ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x562cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x562ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x562d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x562d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x562d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x562d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x562d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x562da, 0x0);
dwc_ddrphy_apb_wr_32b(0x562dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x562de, 0x0);
dwc_ddrphy_apb_wr_32b(0x562e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x562e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x562e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x562e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x562e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x562ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x562ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x562ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x562f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x562f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x562f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x562f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x562f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x562fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x562fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x562fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56300, 0x0);
dwc_ddrphy_apb_wr_32b(0x56302, 0x0);
dwc_ddrphy_apb_wr_32b(0x56304, 0x0);
dwc_ddrphy_apb_wr_32b(0x56306, 0x0);
dwc_ddrphy_apb_wr_32b(0x56308, 0x0);
dwc_ddrphy_apb_wr_32b(0x5630a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5630c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5630e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56310, 0x0);
dwc_ddrphy_apb_wr_32b(0x56312, 0x0);
dwc_ddrphy_apb_wr_32b(0x56314, 0x0);
dwc_ddrphy_apb_wr_32b(0x56316, 0x0);
dwc_ddrphy_apb_wr_32b(0x56318, 0x0);
dwc_ddrphy_apb_wr_32b(0x5631a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5631c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5631e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56320, 0x0);
dwc_ddrphy_apb_wr_32b(0x56322, 0x0);
dwc_ddrphy_apb_wr_32b(0x56324, 0x0);
dwc_ddrphy_apb_wr_32b(0x56326, 0x0);
dwc_ddrphy_apb_wr_32b(0x56328, 0x0);
dwc_ddrphy_apb_wr_32b(0x5632a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5632c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5632e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56330, 0x0);
dwc_ddrphy_apb_wr_32b(0x56332, 0x0);
dwc_ddrphy_apb_wr_32b(0x56334, 0x0);
dwc_ddrphy_apb_wr_32b(0x56336, 0x0);
dwc_ddrphy_apb_wr_32b(0x56338, 0x0);
dwc_ddrphy_apb_wr_32b(0x5633a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5633c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5633e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56340, 0x0);
dwc_ddrphy_apb_wr_32b(0x56342, 0x0);
dwc_ddrphy_apb_wr_32b(0x56344, 0x0);
dwc_ddrphy_apb_wr_32b(0x56346, 0x0);
dwc_ddrphy_apb_wr_32b(0x56348, 0x0);
dwc_ddrphy_apb_wr_32b(0x5634a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5634c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5634e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56350, 0x0);
dwc_ddrphy_apb_wr_32b(0x56352, 0x0);
dwc_ddrphy_apb_wr_32b(0x56354, 0x0);
dwc_ddrphy_apb_wr_32b(0x56356, 0x0);
dwc_ddrphy_apb_wr_32b(0x56358, 0x0);
dwc_ddrphy_apb_wr_32b(0x5635a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5635c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5635e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56360, 0x0);
dwc_ddrphy_apb_wr_32b(0x56362, 0x0);
dwc_ddrphy_apb_wr_32b(0x56364, 0x0);
dwc_ddrphy_apb_wr_32b(0x56366, 0x0);
dwc_ddrphy_apb_wr_32b(0x56368, 0x0);
dwc_ddrphy_apb_wr_32b(0x5636a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5636c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5636e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56370, 0x0);
dwc_ddrphy_apb_wr_32b(0x56372, 0x0);
dwc_ddrphy_apb_wr_32b(0x56374, 0x0);
dwc_ddrphy_apb_wr_32b(0x56376, 0x0);
dwc_ddrphy_apb_wr_32b(0x56378, 0x0);
dwc_ddrphy_apb_wr_32b(0x5637a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5637c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5637e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56380, 0x0);
dwc_ddrphy_apb_wr_32b(0x56382, 0x0);
dwc_ddrphy_apb_wr_32b(0x56384, 0x0);
dwc_ddrphy_apb_wr_32b(0x56386, 0x0);
dwc_ddrphy_apb_wr_32b(0x56388, 0x0);
dwc_ddrphy_apb_wr_32b(0x5638a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5638c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5638e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56390, 0x0);
dwc_ddrphy_apb_wr_32b(0x56392, 0x0);
dwc_ddrphy_apb_wr_32b(0x56394, 0x0);
dwc_ddrphy_apb_wr_32b(0x56396, 0x0);
dwc_ddrphy_apb_wr_32b(0x56398, 0x0);
dwc_ddrphy_apb_wr_32b(0x5639a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5639c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5639e, 0x0);
dwc_ddrphy_apb_wr_32b(0x563a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x563a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x563a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x563a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x563a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x563aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x563ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x563ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x563b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x563b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x563b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x563b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x563b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x563ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x563bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x563be, 0x0);
dwc_ddrphy_apb_wr_32b(0x563c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x563c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x563c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x563c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x563c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x563ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x563cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x563ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x563d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x563d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x563d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x563d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x563d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x563da, 0x0);
dwc_ddrphy_apb_wr_32b(0x563dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x563de, 0x0);
dwc_ddrphy_apb_wr_32b(0x563e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x563e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x563e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x563e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x563e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x563ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x563ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x563ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x563f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x563f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x563f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x563f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x563f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x563fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x563fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x563fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56400, 0x0);
dwc_ddrphy_apb_wr_32b(0x56402, 0x0);
dwc_ddrphy_apb_wr_32b(0x56404, 0x0);
dwc_ddrphy_apb_wr_32b(0x56406, 0x0);
dwc_ddrphy_apb_wr_32b(0x56408, 0x0);
dwc_ddrphy_apb_wr_32b(0x5640a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5640c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5640e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56410, 0x0);
dwc_ddrphy_apb_wr_32b(0x56412, 0x0);
dwc_ddrphy_apb_wr_32b(0x56414, 0x0);
dwc_ddrphy_apb_wr_32b(0x56416, 0x0);
dwc_ddrphy_apb_wr_32b(0x56418, 0x0);
dwc_ddrphy_apb_wr_32b(0x5641a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5641c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5641e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56420, 0x0);
dwc_ddrphy_apb_wr_32b(0x56422, 0x0);
dwc_ddrphy_apb_wr_32b(0x56424, 0x0);
dwc_ddrphy_apb_wr_32b(0x56426, 0x0);
dwc_ddrphy_apb_wr_32b(0x56428, 0x0);
dwc_ddrphy_apb_wr_32b(0x5642a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5642c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5642e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56430, 0x0);
dwc_ddrphy_apb_wr_32b(0x56432, 0x0);
dwc_ddrphy_apb_wr_32b(0x56434, 0x0);
dwc_ddrphy_apb_wr_32b(0x56436, 0x0);
dwc_ddrphy_apb_wr_32b(0x56438, 0x0);
dwc_ddrphy_apb_wr_32b(0x5643a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5643c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5643e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56440, 0x0);
dwc_ddrphy_apb_wr_32b(0x56442, 0x0);
dwc_ddrphy_apb_wr_32b(0x56444, 0x0);
dwc_ddrphy_apb_wr_32b(0x56446, 0x0);
dwc_ddrphy_apb_wr_32b(0x56448, 0x0);
dwc_ddrphy_apb_wr_32b(0x5644a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5644c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5644e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56450, 0x0);
dwc_ddrphy_apb_wr_32b(0x56452, 0x0);
dwc_ddrphy_apb_wr_32b(0x56454, 0x0);
dwc_ddrphy_apb_wr_32b(0x56456, 0x0);
dwc_ddrphy_apb_wr_32b(0x56458, 0x0);
dwc_ddrphy_apb_wr_32b(0x5645a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5645c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5645e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56460, 0x0);
dwc_ddrphy_apb_wr_32b(0x56462, 0x0);
dwc_ddrphy_apb_wr_32b(0x56464, 0x0);
dwc_ddrphy_apb_wr_32b(0x56466, 0x0);
dwc_ddrphy_apb_wr_32b(0x56468, 0x0);
dwc_ddrphy_apb_wr_32b(0x5646a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5646c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5646e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56470, 0x0);
dwc_ddrphy_apb_wr_32b(0x56472, 0x0);
dwc_ddrphy_apb_wr_32b(0x56474, 0x0);
dwc_ddrphy_apb_wr_32b(0x56476, 0x0);
dwc_ddrphy_apb_wr_32b(0x56478, 0x0);
dwc_ddrphy_apb_wr_32b(0x5647a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5647c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5647e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56480, 0x0);
dwc_ddrphy_apb_wr_32b(0x56482, 0x0);
dwc_ddrphy_apb_wr_32b(0x56484, 0x0);
dwc_ddrphy_apb_wr_32b(0x56486, 0x0);
dwc_ddrphy_apb_wr_32b(0x56488, 0x0);
dwc_ddrphy_apb_wr_32b(0x5648a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5648c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5648e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56490, 0x0);
dwc_ddrphy_apb_wr_32b(0x56492, 0x0);
dwc_ddrphy_apb_wr_32b(0x56494, 0x0);
dwc_ddrphy_apb_wr_32b(0x56496, 0x0);
dwc_ddrphy_apb_wr_32b(0x56498, 0x0);
dwc_ddrphy_apb_wr_32b(0x5649a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5649c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5649e, 0x0);
dwc_ddrphy_apb_wr_32b(0x564a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x564a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x564a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x564a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x564a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x564aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x564ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x564ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x564b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x564b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x564b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x564b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x564b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x564ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x564bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x564be, 0x0);
dwc_ddrphy_apb_wr_32b(0x564c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x564c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x564c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x564c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x564c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x564ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x564cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x564ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x564d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x564d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x564d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x564d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x564d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x564da, 0x0);
dwc_ddrphy_apb_wr_32b(0x564dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x564de, 0x0);
dwc_ddrphy_apb_wr_32b(0x564e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x564e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x564e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x564e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x564e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x564ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x564ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x564ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x564f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x564f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x564f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x564f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x564f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x564fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x564fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x564fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56500, 0x0);
dwc_ddrphy_apb_wr_32b(0x56502, 0x0);
dwc_ddrphy_apb_wr_32b(0x56504, 0x0);
dwc_ddrphy_apb_wr_32b(0x56506, 0x0);
dwc_ddrphy_apb_wr_32b(0x56508, 0x0);
dwc_ddrphy_apb_wr_32b(0x5650a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5650c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5650e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56510, 0x0);
dwc_ddrphy_apb_wr_32b(0x56512, 0x0);
dwc_ddrphy_apb_wr_32b(0x56514, 0x0);
dwc_ddrphy_apb_wr_32b(0x56516, 0x0);
dwc_ddrphy_apb_wr_32b(0x56518, 0x0);
dwc_ddrphy_apb_wr_32b(0x5651a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5651c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5651e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56520, 0x0);
dwc_ddrphy_apb_wr_32b(0x56522, 0x0);
dwc_ddrphy_apb_wr_32b(0x56524, 0x0);
dwc_ddrphy_apb_wr_32b(0x56526, 0x0);
dwc_ddrphy_apb_wr_32b(0x56528, 0x0);
dwc_ddrphy_apb_wr_32b(0x5652a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5652c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5652e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56530, 0x0);
dwc_ddrphy_apb_wr_32b(0x56532, 0x0);
dwc_ddrphy_apb_wr_32b(0x56534, 0x0);
dwc_ddrphy_apb_wr_32b(0x56536, 0x0);
dwc_ddrphy_apb_wr_32b(0x56538, 0x0);
dwc_ddrphy_apb_wr_32b(0x5653a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5653c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5653e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56540, 0x0);
dwc_ddrphy_apb_wr_32b(0x56542, 0x0);
dwc_ddrphy_apb_wr_32b(0x56544, 0x0);
dwc_ddrphy_apb_wr_32b(0x56546, 0x0);
dwc_ddrphy_apb_wr_32b(0x56548, 0x0);
dwc_ddrphy_apb_wr_32b(0x5654a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5654c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5654e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56550, 0x0);
dwc_ddrphy_apb_wr_32b(0x56552, 0x0);
dwc_ddrphy_apb_wr_32b(0x56554, 0x0);
dwc_ddrphy_apb_wr_32b(0x56556, 0x0);
dwc_ddrphy_apb_wr_32b(0x56558, 0x0);
dwc_ddrphy_apb_wr_32b(0x5655a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5655c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5655e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56560, 0x0);
dwc_ddrphy_apb_wr_32b(0x56562, 0x0);
dwc_ddrphy_apb_wr_32b(0x56564, 0x0);
dwc_ddrphy_apb_wr_32b(0x56566, 0x0);
dwc_ddrphy_apb_wr_32b(0x56568, 0x0);
dwc_ddrphy_apb_wr_32b(0x5656a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5656c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5656e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56570, 0x0);
dwc_ddrphy_apb_wr_32b(0x56572, 0x0);
dwc_ddrphy_apb_wr_32b(0x56574, 0x0);
dwc_ddrphy_apb_wr_32b(0x56576, 0x0);
dwc_ddrphy_apb_wr_32b(0x56578, 0x0);
dwc_ddrphy_apb_wr_32b(0x5657a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5657c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5657e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56580, 0x0);
dwc_ddrphy_apb_wr_32b(0x56582, 0x0);
dwc_ddrphy_apb_wr_32b(0x56584, 0x0);
dwc_ddrphy_apb_wr_32b(0x56586, 0x0);
dwc_ddrphy_apb_wr_32b(0x56588, 0x0);
dwc_ddrphy_apb_wr_32b(0x5658a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5658c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5658e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56590, 0x0);
dwc_ddrphy_apb_wr_32b(0x56592, 0x0);
dwc_ddrphy_apb_wr_32b(0x56594, 0x0);
dwc_ddrphy_apb_wr_32b(0x56596, 0x0);
dwc_ddrphy_apb_wr_32b(0x56598, 0x0);
dwc_ddrphy_apb_wr_32b(0x5659a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5659c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5659e, 0x0);
dwc_ddrphy_apb_wr_32b(0x565a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x565a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x565a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x565a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x565a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x565aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x565ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x565ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x565b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x565b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x565b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x565b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x565b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x565ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x565bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x565be, 0x0);
dwc_ddrphy_apb_wr_32b(0x565c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x565c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x565c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x565c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x565c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x565ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x565cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x565ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x565d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x565d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x565d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x565d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x565d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x565da, 0x0);
dwc_ddrphy_apb_wr_32b(0x565dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x565de, 0x0);
dwc_ddrphy_apb_wr_32b(0x565e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x565e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x565e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x565e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x565e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x565ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x565ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x565ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x565f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x565f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x565f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x565f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x565f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x565fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x565fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x565fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56600, 0x0);
dwc_ddrphy_apb_wr_32b(0x56602, 0x0);
dwc_ddrphy_apb_wr_32b(0x56604, 0x0);
dwc_ddrphy_apb_wr_32b(0x56606, 0x0);
dwc_ddrphy_apb_wr_32b(0x56608, 0x0);
dwc_ddrphy_apb_wr_32b(0x5660a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5660c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5660e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56610, 0x0);
dwc_ddrphy_apb_wr_32b(0x56612, 0x0);
dwc_ddrphy_apb_wr_32b(0x56614, 0x0);
dwc_ddrphy_apb_wr_32b(0x56616, 0x0);
dwc_ddrphy_apb_wr_32b(0x56618, 0x0);
dwc_ddrphy_apb_wr_32b(0x5661a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5661c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5661e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56620, 0x0);
dwc_ddrphy_apb_wr_32b(0x56622, 0x0);
dwc_ddrphy_apb_wr_32b(0x56624, 0x0);
dwc_ddrphy_apb_wr_32b(0x56626, 0x0);
dwc_ddrphy_apb_wr_32b(0x56628, 0x0);
dwc_ddrphy_apb_wr_32b(0x5662a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5662c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5662e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56630, 0x0);
dwc_ddrphy_apb_wr_32b(0x56632, 0x0);
dwc_ddrphy_apb_wr_32b(0x56634, 0x0);
dwc_ddrphy_apb_wr_32b(0x56636, 0x0);
dwc_ddrphy_apb_wr_32b(0x56638, 0x0);
dwc_ddrphy_apb_wr_32b(0x5663a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5663c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5663e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56640, 0x0);
dwc_ddrphy_apb_wr_32b(0x56642, 0x0);
dwc_ddrphy_apb_wr_32b(0x56644, 0x0);
dwc_ddrphy_apb_wr_32b(0x56646, 0x0);
dwc_ddrphy_apb_wr_32b(0x56648, 0x0);
dwc_ddrphy_apb_wr_32b(0x5664a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5664c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5664e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56650, 0x0);
dwc_ddrphy_apb_wr_32b(0x56652, 0x0);
dwc_ddrphy_apb_wr_32b(0x56654, 0x0);
dwc_ddrphy_apb_wr_32b(0x56656, 0x0);
dwc_ddrphy_apb_wr_32b(0x56658, 0x0);
dwc_ddrphy_apb_wr_32b(0x5665a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5665c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5665e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56660, 0x0);
dwc_ddrphy_apb_wr_32b(0x56662, 0x0);
dwc_ddrphy_apb_wr_32b(0x56664, 0x0);
dwc_ddrphy_apb_wr_32b(0x56666, 0x0);
dwc_ddrphy_apb_wr_32b(0x56668, 0x0);
dwc_ddrphy_apb_wr_32b(0x5666a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5666c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5666e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56670, 0x0);
dwc_ddrphy_apb_wr_32b(0x56672, 0x0);
dwc_ddrphy_apb_wr_32b(0x56674, 0x0);
dwc_ddrphy_apb_wr_32b(0x56676, 0x0);
dwc_ddrphy_apb_wr_32b(0x56678, 0x0);
dwc_ddrphy_apb_wr_32b(0x5667a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5667c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5667e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56680, 0x0);
dwc_ddrphy_apb_wr_32b(0x56682, 0x0);
dwc_ddrphy_apb_wr_32b(0x56684, 0x0);
dwc_ddrphy_apb_wr_32b(0x56686, 0x0);
dwc_ddrphy_apb_wr_32b(0x56688, 0x0);
dwc_ddrphy_apb_wr_32b(0x5668a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5668c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5668e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56690, 0x0);
dwc_ddrphy_apb_wr_32b(0x56692, 0x0);
dwc_ddrphy_apb_wr_32b(0x56694, 0x0);
dwc_ddrphy_apb_wr_32b(0x56696, 0x0);
dwc_ddrphy_apb_wr_32b(0x56698, 0x0);
dwc_ddrphy_apb_wr_32b(0x5669a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5669c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5669e, 0x0);
dwc_ddrphy_apb_wr_32b(0x566a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x566a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x566a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x566a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x566a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x566aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x566ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x566ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x566b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x566b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x566b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x566b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x566b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x566ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x566bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x566be, 0x0);
dwc_ddrphy_apb_wr_32b(0x566c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x566c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x566c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x566c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x566c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x566ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x566cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x566ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x566d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x566d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x566d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x566d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x566d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x566da, 0x0);
dwc_ddrphy_apb_wr_32b(0x566dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x566de, 0x0);
dwc_ddrphy_apb_wr_32b(0x566e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x566e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x566e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x566e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x566e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x566ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x566ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x566ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x566f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x566f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x566f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x566f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x566f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x566fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x566fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x566fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56700, 0x0);
dwc_ddrphy_apb_wr_32b(0x56702, 0x0);
dwc_ddrphy_apb_wr_32b(0x56704, 0x0);
dwc_ddrphy_apb_wr_32b(0x56706, 0x0);
dwc_ddrphy_apb_wr_32b(0x56708, 0x0);
dwc_ddrphy_apb_wr_32b(0x5670a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5670c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5670e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56710, 0x0);
dwc_ddrphy_apb_wr_32b(0x56712, 0x0);
dwc_ddrphy_apb_wr_32b(0x56714, 0x0);
dwc_ddrphy_apb_wr_32b(0x56716, 0x0);
dwc_ddrphy_apb_wr_32b(0x56718, 0x0);
dwc_ddrphy_apb_wr_32b(0x5671a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5671c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5671e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56720, 0x0);
dwc_ddrphy_apb_wr_32b(0x56722, 0x0);
dwc_ddrphy_apb_wr_32b(0x56724, 0x0);
dwc_ddrphy_apb_wr_32b(0x56726, 0x0);
dwc_ddrphy_apb_wr_32b(0x56728, 0x0);
dwc_ddrphy_apb_wr_32b(0x5672a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5672c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5672e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56730, 0x0);
dwc_ddrphy_apb_wr_32b(0x56732, 0x0);
dwc_ddrphy_apb_wr_32b(0x56734, 0x0);
dwc_ddrphy_apb_wr_32b(0x56736, 0x0);
dwc_ddrphy_apb_wr_32b(0x56738, 0x0);
dwc_ddrphy_apb_wr_32b(0x5673a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5673c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5673e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56740, 0x0);
dwc_ddrphy_apb_wr_32b(0x56742, 0x0);
dwc_ddrphy_apb_wr_32b(0x56744, 0x0);
dwc_ddrphy_apb_wr_32b(0x56746, 0x0);
dwc_ddrphy_apb_wr_32b(0x56748, 0x0);
dwc_ddrphy_apb_wr_32b(0x5674a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5674c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5674e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56750, 0x0);
dwc_ddrphy_apb_wr_32b(0x56752, 0x0);
dwc_ddrphy_apb_wr_32b(0x56754, 0x0);
dwc_ddrphy_apb_wr_32b(0x56756, 0x0);
dwc_ddrphy_apb_wr_32b(0x56758, 0x0);
dwc_ddrphy_apb_wr_32b(0x5675a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5675c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5675e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56760, 0x0);
dwc_ddrphy_apb_wr_32b(0x56762, 0x0);
dwc_ddrphy_apb_wr_32b(0x56764, 0x0);
dwc_ddrphy_apb_wr_32b(0x56766, 0x0);
dwc_ddrphy_apb_wr_32b(0x56768, 0x0);
dwc_ddrphy_apb_wr_32b(0x5676a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5676c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5676e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56770, 0x0);
dwc_ddrphy_apb_wr_32b(0x56772, 0x0);
dwc_ddrphy_apb_wr_32b(0x56774, 0x0);
dwc_ddrphy_apb_wr_32b(0x56776, 0x0);
dwc_ddrphy_apb_wr_32b(0x56778, 0x0);
dwc_ddrphy_apb_wr_32b(0x5677a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5677c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5677e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56780, 0x0);
dwc_ddrphy_apb_wr_32b(0x56782, 0x0);
dwc_ddrphy_apb_wr_32b(0x56784, 0x0);
dwc_ddrphy_apb_wr_32b(0x56786, 0x0);
dwc_ddrphy_apb_wr_32b(0x56788, 0x0);
dwc_ddrphy_apb_wr_32b(0x5678a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5678c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5678e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56790, 0x0);
dwc_ddrphy_apb_wr_32b(0x56792, 0x0);
dwc_ddrphy_apb_wr_32b(0x56794, 0x0);
dwc_ddrphy_apb_wr_32b(0x56796, 0x0);
dwc_ddrphy_apb_wr_32b(0x56798, 0x0);
dwc_ddrphy_apb_wr_32b(0x5679a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5679c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5679e, 0x0);
dwc_ddrphy_apb_wr_32b(0x567a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x567a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x567a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x567a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x567a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x567aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x567ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x567ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x567b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x567b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x567b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x567b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x567b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x567ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x567bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x567be, 0x0);
dwc_ddrphy_apb_wr_32b(0x567c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x567c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x567c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x567c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x567c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x567ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x567cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x567ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x567d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x567d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x567d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x567d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x567d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x567da, 0x0);
dwc_ddrphy_apb_wr_32b(0x567dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x567de, 0x0);
dwc_ddrphy_apb_wr_32b(0x567e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x567e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x567e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x567e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x567e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x567ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x567ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x567ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x567f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x567f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x567f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x567f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x567f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x567fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x567fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x567fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56800, 0x0);
dwc_ddrphy_apb_wr_32b(0x56802, 0x0);
dwc_ddrphy_apb_wr_32b(0x56804, 0x0);
dwc_ddrphy_apb_wr_32b(0x56806, 0x0);
dwc_ddrphy_apb_wr_32b(0x56808, 0x0);
dwc_ddrphy_apb_wr_32b(0x5680a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5680c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5680e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56810, 0x0);
dwc_ddrphy_apb_wr_32b(0x56812, 0x0);
dwc_ddrphy_apb_wr_32b(0x56814, 0x0);
dwc_ddrphy_apb_wr_32b(0x56816, 0x0);
dwc_ddrphy_apb_wr_32b(0x56818, 0x0);
dwc_ddrphy_apb_wr_32b(0x5681a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5681c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5681e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56820, 0x0);
dwc_ddrphy_apb_wr_32b(0x56822, 0x0);
dwc_ddrphy_apb_wr_32b(0x56824, 0x0);
dwc_ddrphy_apb_wr_32b(0x56826, 0x0);
dwc_ddrphy_apb_wr_32b(0x56828, 0x0);
dwc_ddrphy_apb_wr_32b(0x5682a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5682c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5682e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56830, 0x0);
dwc_ddrphy_apb_wr_32b(0x56832, 0x0);
dwc_ddrphy_apb_wr_32b(0x56834, 0x0);
dwc_ddrphy_apb_wr_32b(0x56836, 0x0);
dwc_ddrphy_apb_wr_32b(0x56838, 0x0);
dwc_ddrphy_apb_wr_32b(0x5683a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5683c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5683e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56840, 0x0);
dwc_ddrphy_apb_wr_32b(0x56842, 0x0);
dwc_ddrphy_apb_wr_32b(0x56844, 0x0);
dwc_ddrphy_apb_wr_32b(0x56846, 0x0);
dwc_ddrphy_apb_wr_32b(0x56848, 0x0);
dwc_ddrphy_apb_wr_32b(0x5684a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5684c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5684e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56850, 0x0);
dwc_ddrphy_apb_wr_32b(0x56852, 0x0);
dwc_ddrphy_apb_wr_32b(0x56854, 0x0);
dwc_ddrphy_apb_wr_32b(0x56856, 0x0);
dwc_ddrphy_apb_wr_32b(0x56858, 0x0);
dwc_ddrphy_apb_wr_32b(0x5685a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5685c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5685e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56860, 0x0);
dwc_ddrphy_apb_wr_32b(0x56862, 0x0);
dwc_ddrphy_apb_wr_32b(0x56864, 0x0);
dwc_ddrphy_apb_wr_32b(0x56866, 0x0);
dwc_ddrphy_apb_wr_32b(0x56868, 0x0);
dwc_ddrphy_apb_wr_32b(0x5686a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5686c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5686e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56870, 0x0);
dwc_ddrphy_apb_wr_32b(0x56872, 0x0);
dwc_ddrphy_apb_wr_32b(0x56874, 0x0);
dwc_ddrphy_apb_wr_32b(0x56876, 0x0);
dwc_ddrphy_apb_wr_32b(0x56878, 0x0);
dwc_ddrphy_apb_wr_32b(0x5687a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5687c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5687e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56880, 0x0);
dwc_ddrphy_apb_wr_32b(0x56882, 0x0);
dwc_ddrphy_apb_wr_32b(0x56884, 0x0);
dwc_ddrphy_apb_wr_32b(0x56886, 0x0);
dwc_ddrphy_apb_wr_32b(0x56888, 0x0);
dwc_ddrphy_apb_wr_32b(0x5688a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5688c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5688e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56890, 0x0);
dwc_ddrphy_apb_wr_32b(0x56892, 0x0);
dwc_ddrphy_apb_wr_32b(0x56894, 0x0);
dwc_ddrphy_apb_wr_32b(0x56896, 0x0);
dwc_ddrphy_apb_wr_32b(0x56898, 0x0);
dwc_ddrphy_apb_wr_32b(0x5689a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5689c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5689e, 0x0);
dwc_ddrphy_apb_wr_32b(0x568a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x568a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x568a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x568a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x568a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x568aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x568ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x568ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x568b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x568b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x568b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x568b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x568b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x568ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x568bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x568be, 0x0);
dwc_ddrphy_apb_wr_32b(0x568c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x568c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x568c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x568c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x568c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x568ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x568cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x568ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x568d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x568d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x568d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x568d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x568d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x568da, 0x0);
dwc_ddrphy_apb_wr_32b(0x568dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x568de, 0x0);
dwc_ddrphy_apb_wr_32b(0x568e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x568e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x568e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x568e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x568e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x568ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x568ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x568ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x568f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x568f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x568f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x568f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x568f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x568fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x568fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x568fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56900, 0x0);
dwc_ddrphy_apb_wr_32b(0x56902, 0x0);
dwc_ddrphy_apb_wr_32b(0x56904, 0x0);
dwc_ddrphy_apb_wr_32b(0x56906, 0x0);
dwc_ddrphy_apb_wr_32b(0x56908, 0x0);
dwc_ddrphy_apb_wr_32b(0x5690a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5690c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5690e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56910, 0x0);
dwc_ddrphy_apb_wr_32b(0x56912, 0x0);
dwc_ddrphy_apb_wr_32b(0x56914, 0x0);
dwc_ddrphy_apb_wr_32b(0x56916, 0x0);
dwc_ddrphy_apb_wr_32b(0x56918, 0x0);
dwc_ddrphy_apb_wr_32b(0x5691a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5691c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5691e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56920, 0x0);
dwc_ddrphy_apb_wr_32b(0x56922, 0x0);
dwc_ddrphy_apb_wr_32b(0x56924, 0x0);
dwc_ddrphy_apb_wr_32b(0x56926, 0x0);
dwc_ddrphy_apb_wr_32b(0x56928, 0x0);
dwc_ddrphy_apb_wr_32b(0x5692a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5692c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5692e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56930, 0x0);
dwc_ddrphy_apb_wr_32b(0x56932, 0x0);
dwc_ddrphy_apb_wr_32b(0x56934, 0x0);
dwc_ddrphy_apb_wr_32b(0x56936, 0x0);
dwc_ddrphy_apb_wr_32b(0x56938, 0x0);
dwc_ddrphy_apb_wr_32b(0x5693a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5693c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5693e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56940, 0x0);
dwc_ddrphy_apb_wr_32b(0x56942, 0x0);
dwc_ddrphy_apb_wr_32b(0x56944, 0x0);
dwc_ddrphy_apb_wr_32b(0x56946, 0x0);
dwc_ddrphy_apb_wr_32b(0x56948, 0x0);
dwc_ddrphy_apb_wr_32b(0x5694a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5694c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5694e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56950, 0x0);
dwc_ddrphy_apb_wr_32b(0x56952, 0x0);
dwc_ddrphy_apb_wr_32b(0x56954, 0x0);
dwc_ddrphy_apb_wr_32b(0x56956, 0x0);
dwc_ddrphy_apb_wr_32b(0x56958, 0x0);
dwc_ddrphy_apb_wr_32b(0x5695a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5695c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5695e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56960, 0x0);
dwc_ddrphy_apb_wr_32b(0x56962, 0x0);
dwc_ddrphy_apb_wr_32b(0x56964, 0x0);
dwc_ddrphy_apb_wr_32b(0x56966, 0x0);
dwc_ddrphy_apb_wr_32b(0x56968, 0x0);
dwc_ddrphy_apb_wr_32b(0x5696a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5696c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5696e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56970, 0x0);
dwc_ddrphy_apb_wr_32b(0x56972, 0x0);
dwc_ddrphy_apb_wr_32b(0x56974, 0x0);
dwc_ddrphy_apb_wr_32b(0x56976, 0x0);
dwc_ddrphy_apb_wr_32b(0x56978, 0x0);
dwc_ddrphy_apb_wr_32b(0x5697a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5697c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5697e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56980, 0x0);
dwc_ddrphy_apb_wr_32b(0x56982, 0x0);
dwc_ddrphy_apb_wr_32b(0x56984, 0x0);
dwc_ddrphy_apb_wr_32b(0x56986, 0x0);
dwc_ddrphy_apb_wr_32b(0x56988, 0x0);
dwc_ddrphy_apb_wr_32b(0x5698a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5698c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5698e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56990, 0x0);
dwc_ddrphy_apb_wr_32b(0x56992, 0x0);
dwc_ddrphy_apb_wr_32b(0x56994, 0x0);
dwc_ddrphy_apb_wr_32b(0x56996, 0x0);
dwc_ddrphy_apb_wr_32b(0x56998, 0x0);
dwc_ddrphy_apb_wr_32b(0x5699a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5699c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5699e, 0x0);
dwc_ddrphy_apb_wr_32b(0x569a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x569a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x569a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x569a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x569a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x569aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x569ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x569ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x569b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x569b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x569b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x569b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x569b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x569ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x569bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x569be, 0x0);
dwc_ddrphy_apb_wr_32b(0x569c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x569c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x569c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x569c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x569c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x569ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x569cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x569ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x569d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x569d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x569d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x569d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x569d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x569da, 0x0);
dwc_ddrphy_apb_wr_32b(0x569dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x569de, 0x0);
dwc_ddrphy_apb_wr_32b(0x569e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x569e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x569e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x569e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x569e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x569ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x569ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x569ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x569f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x569f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x569f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x569f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x569f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x569fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x569fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x569fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a00, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a02, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a04, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a06, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a08, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a10, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a12, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a14, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a16, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a18, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a20, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a22, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a24, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a26, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a28, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a30, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a32, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a34, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a36, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a38, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a40, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a42, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a44, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a46, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a48, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a50, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a52, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a54, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a56, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a58, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a60, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a62, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a64, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a66, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a68, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a70, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a72, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a74, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a76, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a78, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a80, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a82, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a84, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a86, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a88, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a90, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a92, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a94, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a96, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a98, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56a9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56aa0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56aa2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56aa4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56aa6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56aa8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56aaa, 0x0);
dwc_ddrphy_apb_wr_32b(0x56aac, 0x0);
dwc_ddrphy_apb_wr_32b(0x56aae, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ab0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ab2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ab4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ab6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ab8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56aba, 0x0);
dwc_ddrphy_apb_wr_32b(0x56abc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56abe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ac0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ac2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ac4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ac6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ac8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56aca, 0x0);
dwc_ddrphy_apb_wr_32b(0x56acc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ace, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ad0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ad2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ad4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ad6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ad8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ada, 0x0);
dwc_ddrphy_apb_wr_32b(0x56adc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ade, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ae0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ae2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ae4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ae6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ae8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56aea, 0x0);
dwc_ddrphy_apb_wr_32b(0x56aec, 0x0);
dwc_ddrphy_apb_wr_32b(0x56aee, 0x0);
dwc_ddrphy_apb_wr_32b(0x56af0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56af2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56af4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56af6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56af8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56afa, 0x0);
dwc_ddrphy_apb_wr_32b(0x56afc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56afe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b00, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b02, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b04, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b06, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b08, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b10, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b12, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b14, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b16, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b18, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b20, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b22, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b24, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b26, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b28, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b30, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b32, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b34, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b36, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b38, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b40, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b42, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b44, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b46, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b48, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b50, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b52, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b54, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b56, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b58, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b60, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b62, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b64, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b66, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b68, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b70, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b72, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b74, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b76, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b78, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b80, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b82, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b84, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b86, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b88, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b90, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b92, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b94, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b96, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b98, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56b9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ba0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ba2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ba4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ba6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ba8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56baa, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bac, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bae, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bba, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bca, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bcc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bce, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bda, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bdc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bde, 0x0);
dwc_ddrphy_apb_wr_32b(0x56be0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56be2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56be4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56be6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56be8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bea, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bec, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bee, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bf0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bf2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bf4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bf6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bf8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bfa, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bfc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56bfe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c00, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c02, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c04, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c06, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c08, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c10, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c12, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c14, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c16, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c18, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c20, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c22, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c24, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c26, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c28, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c30, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c32, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c34, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c36, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c38, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c40, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c42, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c44, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c46, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c48, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c50, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c52, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c54, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c56, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c58, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c60, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c62, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c64, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c66, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c68, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c70, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c72, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c74, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c76, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c78, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c80, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c82, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c84, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c86, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c88, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c90, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c92, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c94, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c96, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c98, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56c9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ca0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ca2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ca4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ca6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ca8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56caa, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cac, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cae, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cba, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cca, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ccc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cce, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cda, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cdc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cde, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ce0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ce2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ce4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ce6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ce8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cea, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cec, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cee, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cf0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cf2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cf4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cf6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cf8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cfa, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cfc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56cfe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d00, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d02, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d04, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d06, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d08, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d10, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d12, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d14, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d16, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d18, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d20, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d22, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d24, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d26, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d28, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d30, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d32, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d34, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d36, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d38, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d40, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d42, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d44, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d46, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d48, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d50, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d52, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d54, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d56, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d58, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d60, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d62, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d64, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d66, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d68, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d70, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d72, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d74, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d76, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d78, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d80, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d82, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d84, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d86, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d88, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d90, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d92, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d94, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d96, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d98, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56d9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56da0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56da2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56da4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56da6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56da8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56daa, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dac, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dae, 0x0);
dwc_ddrphy_apb_wr_32b(0x56db0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56db2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56db4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56db6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56db8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dba, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dca, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dcc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dce, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dda, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ddc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dde, 0x0);
dwc_ddrphy_apb_wr_32b(0x56de0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56de2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56de4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56de6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56de8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dea, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dec, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dee, 0x0);
dwc_ddrphy_apb_wr_32b(0x56df0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56df2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56df4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56df6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56df8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dfa, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dfc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56dfe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e00, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e02, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e04, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e06, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e08, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e10, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e12, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e14, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e16, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e18, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e20, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e22, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e24, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e26, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e28, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e30, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e32, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e34, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e36, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e38, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e40, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e42, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e44, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e46, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e48, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e50, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e52, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e54, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e56, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e58, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e60, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e62, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e64, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e66, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e68, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e70, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e72, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e74, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e76, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e78, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e80, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e82, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e84, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e86, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e88, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e90, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e92, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e94, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e96, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e98, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56e9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ea0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ea2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ea4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ea6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ea8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56eaa, 0x0);
dwc_ddrphy_apb_wr_32b(0x56eac, 0x0);
dwc_ddrphy_apb_wr_32b(0x56eae, 0x0);
dwc_ddrphy_apb_wr_32b(0x56eb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56eb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56eb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56eb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56eb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56eba, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ebc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ebe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ec0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ec2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ec4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ec6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ec8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56eca, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ecc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ece, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ed0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ed2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ed4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ed6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ed8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56eda, 0x0);
dwc_ddrphy_apb_wr_32b(0x56edc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ede, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ee0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ee2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ee4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ee6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ee8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56eea, 0x0);
dwc_ddrphy_apb_wr_32b(0x56eec, 0x0);
dwc_ddrphy_apb_wr_32b(0x56eee, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ef0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ef2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ef4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ef6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ef8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56efa, 0x0);
dwc_ddrphy_apb_wr_32b(0x56efc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56efe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f00, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f02, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f04, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f06, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f08, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f10, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f12, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f14, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f16, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f18, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f20, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f22, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f24, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f26, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f28, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f30, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f32, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f34, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f36, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f38, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f40, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f42, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f44, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f46, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f48, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f50, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f52, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f54, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f56, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f58, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f60, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f62, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f64, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f66, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f68, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f70, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f72, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f74, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f76, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f78, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f80, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f82, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f84, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f86, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f88, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f90, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f92, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f94, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f96, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f98, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x56f9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fa0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fa2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fa4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fa6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fa8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56faa, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fac, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fae, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fba, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fca, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fcc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fce, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fda, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fdc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fde, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fe0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fe2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fe4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fe6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fe8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fea, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fec, 0x0);
dwc_ddrphy_apb_wr_32b(0x56fee, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ff0, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ff2, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ff4, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ff6, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ff8, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ffa, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ffc, 0x0);
dwc_ddrphy_apb_wr_32b(0x56ffe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57000, 0x0);
dwc_ddrphy_apb_wr_32b(0x57002, 0x0);
dwc_ddrphy_apb_wr_32b(0x57004, 0x0);
dwc_ddrphy_apb_wr_32b(0x57006, 0x0);
dwc_ddrphy_apb_wr_32b(0x57008, 0x0);
dwc_ddrphy_apb_wr_32b(0x5700a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5700c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5700e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57010, 0x0);
dwc_ddrphy_apb_wr_32b(0x57012, 0x0);
dwc_ddrphy_apb_wr_32b(0x57014, 0x0);
dwc_ddrphy_apb_wr_32b(0x57016, 0x0);
dwc_ddrphy_apb_wr_32b(0x57018, 0x0);
dwc_ddrphy_apb_wr_32b(0x5701a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5701c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5701e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57020, 0x0);
dwc_ddrphy_apb_wr_32b(0x57022, 0x0);
dwc_ddrphy_apb_wr_32b(0x57024, 0x0);
dwc_ddrphy_apb_wr_32b(0x57026, 0x0);
dwc_ddrphy_apb_wr_32b(0x57028, 0x0);
dwc_ddrphy_apb_wr_32b(0x5702a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5702c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5702e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57030, 0x0);
dwc_ddrphy_apb_wr_32b(0x57032, 0x0);
dwc_ddrphy_apb_wr_32b(0x57034, 0x0);
dwc_ddrphy_apb_wr_32b(0x57036, 0x0);
dwc_ddrphy_apb_wr_32b(0x57038, 0x0);
dwc_ddrphy_apb_wr_32b(0x5703a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5703c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5703e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57040, 0x0);
dwc_ddrphy_apb_wr_32b(0x57042, 0x0);
dwc_ddrphy_apb_wr_32b(0x57044, 0x0);
dwc_ddrphy_apb_wr_32b(0x57046, 0x0);
dwc_ddrphy_apb_wr_32b(0x57048, 0x0);
dwc_ddrphy_apb_wr_32b(0x5704a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5704c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5704e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57050, 0x0);
dwc_ddrphy_apb_wr_32b(0x57052, 0x0);
dwc_ddrphy_apb_wr_32b(0x57054, 0x0);
dwc_ddrphy_apb_wr_32b(0x57056, 0x0);
dwc_ddrphy_apb_wr_32b(0x57058, 0x0);
dwc_ddrphy_apb_wr_32b(0x5705a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5705c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5705e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57060, 0x0);
dwc_ddrphy_apb_wr_32b(0x57062, 0x0);
dwc_ddrphy_apb_wr_32b(0x57064, 0x0);
dwc_ddrphy_apb_wr_32b(0x57066, 0x0);
dwc_ddrphy_apb_wr_32b(0x57068, 0x0);
dwc_ddrphy_apb_wr_32b(0x5706a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5706c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5706e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57070, 0x0);
dwc_ddrphy_apb_wr_32b(0x57072, 0x0);
dwc_ddrphy_apb_wr_32b(0x57074, 0x0);
dwc_ddrphy_apb_wr_32b(0x57076, 0x0);
dwc_ddrphy_apb_wr_32b(0x57078, 0x0);
dwc_ddrphy_apb_wr_32b(0x5707a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5707c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5707e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57080, 0x0);
dwc_ddrphy_apb_wr_32b(0x57082, 0x0);
dwc_ddrphy_apb_wr_32b(0x57084, 0x0);
dwc_ddrphy_apb_wr_32b(0x57086, 0x0);
dwc_ddrphy_apb_wr_32b(0x57088, 0x0);
dwc_ddrphy_apb_wr_32b(0x5708a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5708c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5708e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57090, 0x0);
dwc_ddrphy_apb_wr_32b(0x57092, 0x0);
dwc_ddrphy_apb_wr_32b(0x57094, 0x0);
dwc_ddrphy_apb_wr_32b(0x57096, 0x0);
dwc_ddrphy_apb_wr_32b(0x57098, 0x0);
dwc_ddrphy_apb_wr_32b(0x5709a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5709c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5709e, 0x0);
dwc_ddrphy_apb_wr_32b(0x570a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x570a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x570a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x570a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x570a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x570aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x570ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x570ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x570b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x570b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x570b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x570b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x570b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x570ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x570bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x570be, 0x0);
dwc_ddrphy_apb_wr_32b(0x570c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x570c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x570c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x570c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x570c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x570ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x570cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x570ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x570d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x570d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x570d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x570d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x570d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x570da, 0x0);
dwc_ddrphy_apb_wr_32b(0x570dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x570de, 0x0);
dwc_ddrphy_apb_wr_32b(0x570e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x570e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x570e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x570e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x570e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x570ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x570ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x570ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x570f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x570f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x570f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x570f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x570f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x570fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x570fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x570fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57100, 0x0);
dwc_ddrphy_apb_wr_32b(0x57102, 0x0);
dwc_ddrphy_apb_wr_32b(0x57104, 0x0);
dwc_ddrphy_apb_wr_32b(0x57106, 0x0);
dwc_ddrphy_apb_wr_32b(0x57108, 0x0);
dwc_ddrphy_apb_wr_32b(0x5710a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5710c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5710e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57110, 0x0);
dwc_ddrphy_apb_wr_32b(0x57112, 0x0);
dwc_ddrphy_apb_wr_32b(0x57114, 0x0);
dwc_ddrphy_apb_wr_32b(0x57116, 0x0);
dwc_ddrphy_apb_wr_32b(0x57118, 0x0);
dwc_ddrphy_apb_wr_32b(0x5711a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5711c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5711e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57120, 0x0);
dwc_ddrphy_apb_wr_32b(0x57122, 0x0);
dwc_ddrphy_apb_wr_32b(0x57124, 0x0);
dwc_ddrphy_apb_wr_32b(0x57126, 0x0);
dwc_ddrphy_apb_wr_32b(0x57128, 0x0);
dwc_ddrphy_apb_wr_32b(0x5712a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5712c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5712e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57130, 0x0);
dwc_ddrphy_apb_wr_32b(0x57132, 0x0);
dwc_ddrphy_apb_wr_32b(0x57134, 0x0);
dwc_ddrphy_apb_wr_32b(0x57136, 0x0);
dwc_ddrphy_apb_wr_32b(0x57138, 0x0);
dwc_ddrphy_apb_wr_32b(0x5713a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5713c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5713e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57140, 0x0);
dwc_ddrphy_apb_wr_32b(0x57142, 0x0);
dwc_ddrphy_apb_wr_32b(0x57144, 0x0);
dwc_ddrphy_apb_wr_32b(0x57146, 0x0);
dwc_ddrphy_apb_wr_32b(0x57148, 0x0);
dwc_ddrphy_apb_wr_32b(0x5714a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5714c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5714e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57150, 0x0);
dwc_ddrphy_apb_wr_32b(0x57152, 0x0);
dwc_ddrphy_apb_wr_32b(0x57154, 0x0);
dwc_ddrphy_apb_wr_32b(0x57156, 0x0);
dwc_ddrphy_apb_wr_32b(0x57158, 0x0);
dwc_ddrphy_apb_wr_32b(0x5715a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5715c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5715e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57160, 0x0);
dwc_ddrphy_apb_wr_32b(0x57162, 0x0);
dwc_ddrphy_apb_wr_32b(0x57164, 0x0);
dwc_ddrphy_apb_wr_32b(0x57166, 0x0);
dwc_ddrphy_apb_wr_32b(0x57168, 0x0);
dwc_ddrphy_apb_wr_32b(0x5716a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5716c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5716e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57170, 0x0);
dwc_ddrphy_apb_wr_32b(0x57172, 0x0);
dwc_ddrphy_apb_wr_32b(0x57174, 0x0);
dwc_ddrphy_apb_wr_32b(0x57176, 0x0);
dwc_ddrphy_apb_wr_32b(0x57178, 0x0);
dwc_ddrphy_apb_wr_32b(0x5717a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5717c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5717e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57180, 0x0);
dwc_ddrphy_apb_wr_32b(0x57182, 0x0);
dwc_ddrphy_apb_wr_32b(0x57184, 0x0);
dwc_ddrphy_apb_wr_32b(0x57186, 0x0);
dwc_ddrphy_apb_wr_32b(0x57188, 0x0);
dwc_ddrphy_apb_wr_32b(0x5718a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5718c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5718e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57190, 0x0);
dwc_ddrphy_apb_wr_32b(0x57192, 0x0);
dwc_ddrphy_apb_wr_32b(0x57194, 0x0);
dwc_ddrphy_apb_wr_32b(0x57196, 0x0);
dwc_ddrphy_apb_wr_32b(0x57198, 0x0);
dwc_ddrphy_apb_wr_32b(0x5719a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5719c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5719e, 0x0);
dwc_ddrphy_apb_wr_32b(0x571a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x571a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x571a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x571a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x571a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x571aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x571ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x571ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x571b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x571b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x571b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x571b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x571b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x571ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x571bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x571be, 0x0);
dwc_ddrphy_apb_wr_32b(0x571c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x571c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x571c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x571c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x571c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x571ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x571cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x571ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x571d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x571d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x571d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x571d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x571d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x571da, 0x0);
dwc_ddrphy_apb_wr_32b(0x571dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x571de, 0x0);
dwc_ddrphy_apb_wr_32b(0x571e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x571e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x571e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x571e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x571e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x571ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x571ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x571ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x571f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x571f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x571f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x571f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x571f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x571fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x571fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x571fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57200, 0x0);
dwc_ddrphy_apb_wr_32b(0x57202, 0x0);
dwc_ddrphy_apb_wr_32b(0x57204, 0x0);
dwc_ddrphy_apb_wr_32b(0x57206, 0x0);
dwc_ddrphy_apb_wr_32b(0x57208, 0x0);
dwc_ddrphy_apb_wr_32b(0x5720a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5720c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5720e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57210, 0x0);
dwc_ddrphy_apb_wr_32b(0x57212, 0x0);
dwc_ddrphy_apb_wr_32b(0x57214, 0x0);
dwc_ddrphy_apb_wr_32b(0x57216, 0x0);
dwc_ddrphy_apb_wr_32b(0x57218, 0x0);
dwc_ddrphy_apb_wr_32b(0x5721a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5721c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5721e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57220, 0x0);
dwc_ddrphy_apb_wr_32b(0x57222, 0x0);
dwc_ddrphy_apb_wr_32b(0x57224, 0x0);
dwc_ddrphy_apb_wr_32b(0x57226, 0x0);
dwc_ddrphy_apb_wr_32b(0x57228, 0x0);
dwc_ddrphy_apb_wr_32b(0x5722a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5722c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5722e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57230, 0x0);
dwc_ddrphy_apb_wr_32b(0x57232, 0x0);
dwc_ddrphy_apb_wr_32b(0x57234, 0x0);
dwc_ddrphy_apb_wr_32b(0x57236, 0x0);
dwc_ddrphy_apb_wr_32b(0x57238, 0x0);
dwc_ddrphy_apb_wr_32b(0x5723a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5723c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5723e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57240, 0x0);
dwc_ddrphy_apb_wr_32b(0x57242, 0x0);
dwc_ddrphy_apb_wr_32b(0x57244, 0x0);
dwc_ddrphy_apb_wr_32b(0x57246, 0x0);
dwc_ddrphy_apb_wr_32b(0x57248, 0x0);
dwc_ddrphy_apb_wr_32b(0x5724a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5724c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5724e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57250, 0x0);
dwc_ddrphy_apb_wr_32b(0x57252, 0x0);
dwc_ddrphy_apb_wr_32b(0x57254, 0x0);
dwc_ddrphy_apb_wr_32b(0x57256, 0x0);
dwc_ddrphy_apb_wr_32b(0x57258, 0x0);
dwc_ddrphy_apb_wr_32b(0x5725a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5725c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5725e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57260, 0x0);
dwc_ddrphy_apb_wr_32b(0x57262, 0x0);
dwc_ddrphy_apb_wr_32b(0x57264, 0x0);
dwc_ddrphy_apb_wr_32b(0x57266, 0x0);
dwc_ddrphy_apb_wr_32b(0x57268, 0x0);
dwc_ddrphy_apb_wr_32b(0x5726a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5726c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5726e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57270, 0x0);
dwc_ddrphy_apb_wr_32b(0x57272, 0x0);
dwc_ddrphy_apb_wr_32b(0x57274, 0x0);
dwc_ddrphy_apb_wr_32b(0x57276, 0x0);
dwc_ddrphy_apb_wr_32b(0x57278, 0x0);
dwc_ddrphy_apb_wr_32b(0x5727a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5727c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5727e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57280, 0x0);
dwc_ddrphy_apb_wr_32b(0x57282, 0x0);
dwc_ddrphy_apb_wr_32b(0x57284, 0x0);
dwc_ddrphy_apb_wr_32b(0x57286, 0x0);
dwc_ddrphy_apb_wr_32b(0x57288, 0x0);
dwc_ddrphy_apb_wr_32b(0x5728a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5728c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5728e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57290, 0x0);
dwc_ddrphy_apb_wr_32b(0x57292, 0x0);
dwc_ddrphy_apb_wr_32b(0x57294, 0x0);
dwc_ddrphy_apb_wr_32b(0x57296, 0x0);
dwc_ddrphy_apb_wr_32b(0x57298, 0x0);
dwc_ddrphy_apb_wr_32b(0x5729a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5729c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5729e, 0x0);
dwc_ddrphy_apb_wr_32b(0x572a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x572a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x572a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x572a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x572a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x572aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x572ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x572ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x572b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x572b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x572b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x572b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x572b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x572ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x572bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x572be, 0x0);
dwc_ddrphy_apb_wr_32b(0x572c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x572c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x572c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x572c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x572c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x572ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x572cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x572ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x572d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x572d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x572d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x572d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x572d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x572da, 0x0);
dwc_ddrphy_apb_wr_32b(0x572dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x572de, 0x0);
dwc_ddrphy_apb_wr_32b(0x572e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x572e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x572e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x572e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x572e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x572ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x572ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x572ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x572f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x572f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x572f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x572f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x572f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x572fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x572fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x572fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57300, 0x0);
dwc_ddrphy_apb_wr_32b(0x57302, 0x0);
dwc_ddrphy_apb_wr_32b(0x57304, 0x0);
dwc_ddrphy_apb_wr_32b(0x57306, 0x0);
dwc_ddrphy_apb_wr_32b(0x57308, 0x0);
dwc_ddrphy_apb_wr_32b(0x5730a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5730c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5730e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57310, 0x0);
dwc_ddrphy_apb_wr_32b(0x57312, 0x0);
dwc_ddrphy_apb_wr_32b(0x57314, 0x0);
dwc_ddrphy_apb_wr_32b(0x57316, 0x0);
dwc_ddrphy_apb_wr_32b(0x57318, 0x0);
dwc_ddrphy_apb_wr_32b(0x5731a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5731c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5731e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57320, 0x0);
dwc_ddrphy_apb_wr_32b(0x57322, 0x0);
dwc_ddrphy_apb_wr_32b(0x57324, 0x0);
dwc_ddrphy_apb_wr_32b(0x57326, 0x0);
dwc_ddrphy_apb_wr_32b(0x57328, 0x0);
dwc_ddrphy_apb_wr_32b(0x5732a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5732c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5732e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57330, 0x0);
dwc_ddrphy_apb_wr_32b(0x57332, 0x0);
dwc_ddrphy_apb_wr_32b(0x57334, 0x0);
dwc_ddrphy_apb_wr_32b(0x57336, 0x0);
dwc_ddrphy_apb_wr_32b(0x57338, 0x0);
dwc_ddrphy_apb_wr_32b(0x5733a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5733c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5733e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57340, 0x0);
dwc_ddrphy_apb_wr_32b(0x57342, 0x0);
dwc_ddrphy_apb_wr_32b(0x57344, 0x0);
dwc_ddrphy_apb_wr_32b(0x57346, 0x0);
dwc_ddrphy_apb_wr_32b(0x57348, 0x0);
dwc_ddrphy_apb_wr_32b(0x5734a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5734c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5734e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57350, 0x0);
dwc_ddrphy_apb_wr_32b(0x57352, 0x0);
dwc_ddrphy_apb_wr_32b(0x57354, 0x0);
dwc_ddrphy_apb_wr_32b(0x57356, 0x0);
dwc_ddrphy_apb_wr_32b(0x57358, 0x0);
dwc_ddrphy_apb_wr_32b(0x5735a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5735c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5735e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57360, 0x0);
dwc_ddrphy_apb_wr_32b(0x57362, 0x0);
dwc_ddrphy_apb_wr_32b(0x57364, 0x0);
dwc_ddrphy_apb_wr_32b(0x57366, 0x0);
dwc_ddrphy_apb_wr_32b(0x57368, 0x0);
dwc_ddrphy_apb_wr_32b(0x5736a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5736c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5736e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57370, 0x0);
dwc_ddrphy_apb_wr_32b(0x57372, 0x0);
dwc_ddrphy_apb_wr_32b(0x57374, 0x0);
dwc_ddrphy_apb_wr_32b(0x57376, 0x0);
dwc_ddrphy_apb_wr_32b(0x57378, 0x0);
dwc_ddrphy_apb_wr_32b(0x5737a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5737c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5737e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57380, 0x0);
dwc_ddrphy_apb_wr_32b(0x57382, 0x0);
dwc_ddrphy_apb_wr_32b(0x57384, 0x0);
dwc_ddrphy_apb_wr_32b(0x57386, 0x0);
dwc_ddrphy_apb_wr_32b(0x57388, 0x0);
dwc_ddrphy_apb_wr_32b(0x5738a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5738c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5738e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57390, 0x0);
dwc_ddrphy_apb_wr_32b(0x57392, 0x0);
dwc_ddrphy_apb_wr_32b(0x57394, 0x0);
dwc_ddrphy_apb_wr_32b(0x57396, 0x0);
dwc_ddrphy_apb_wr_32b(0x57398, 0x0);
dwc_ddrphy_apb_wr_32b(0x5739a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5739c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5739e, 0x0);
dwc_ddrphy_apb_wr_32b(0x573a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x573a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x573a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x573a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x573a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x573aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x573ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x573ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x573b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x573b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x573b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x573b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x573b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x573ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x573bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x573be, 0x0);
dwc_ddrphy_apb_wr_32b(0x573c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x573c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x573c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x573c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x573c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x573ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x573cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x573ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x573d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x573d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x573d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x573d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x573d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x573da, 0x0);
dwc_ddrphy_apb_wr_32b(0x573dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x573de, 0x0);
dwc_ddrphy_apb_wr_32b(0x573e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x573e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x573e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x573e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x573e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x573ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x573ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x573ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x573f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x573f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x573f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x573f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x573f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x573fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x573fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x573fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57400, 0x0);
dwc_ddrphy_apb_wr_32b(0x57402, 0x0);
dwc_ddrphy_apb_wr_32b(0x57404, 0x0);
dwc_ddrphy_apb_wr_32b(0x57406, 0x0);
dwc_ddrphy_apb_wr_32b(0x57408, 0x0);
dwc_ddrphy_apb_wr_32b(0x5740a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5740c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5740e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57410, 0x0);
dwc_ddrphy_apb_wr_32b(0x57412, 0x0);
dwc_ddrphy_apb_wr_32b(0x57414, 0x0);
dwc_ddrphy_apb_wr_32b(0x57416, 0x0);
dwc_ddrphy_apb_wr_32b(0x57418, 0x0);
dwc_ddrphy_apb_wr_32b(0x5741a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5741c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5741e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57420, 0x0);
dwc_ddrphy_apb_wr_32b(0x57422, 0x0);
dwc_ddrphy_apb_wr_32b(0x57424, 0x0);
dwc_ddrphy_apb_wr_32b(0x57426, 0x0);
dwc_ddrphy_apb_wr_32b(0x57428, 0x0);
dwc_ddrphy_apb_wr_32b(0x5742a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5742c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5742e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57430, 0x0);
dwc_ddrphy_apb_wr_32b(0x57432, 0x0);
dwc_ddrphy_apb_wr_32b(0x57434, 0x0);
dwc_ddrphy_apb_wr_32b(0x57436, 0x0);
dwc_ddrphy_apb_wr_32b(0x57438, 0x0);
dwc_ddrphy_apb_wr_32b(0x5743a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5743c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5743e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57440, 0x0);
dwc_ddrphy_apb_wr_32b(0x57442, 0x0);
dwc_ddrphy_apb_wr_32b(0x57444, 0x0);
dwc_ddrphy_apb_wr_32b(0x57446, 0x0);
dwc_ddrphy_apb_wr_32b(0x57448, 0x0);
dwc_ddrphy_apb_wr_32b(0x5744a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5744c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5744e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57450, 0x0);
dwc_ddrphy_apb_wr_32b(0x57452, 0x0);
dwc_ddrphy_apb_wr_32b(0x57454, 0x0);
dwc_ddrphy_apb_wr_32b(0x57456, 0x0);
dwc_ddrphy_apb_wr_32b(0x57458, 0x0);
dwc_ddrphy_apb_wr_32b(0x5745a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5745c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5745e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57460, 0x0);
dwc_ddrphy_apb_wr_32b(0x57462, 0x0);
dwc_ddrphy_apb_wr_32b(0x57464, 0x0);
dwc_ddrphy_apb_wr_32b(0x57466, 0x0);
dwc_ddrphy_apb_wr_32b(0x57468, 0x0);
dwc_ddrphy_apb_wr_32b(0x5746a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5746c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5746e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57470, 0x0);
dwc_ddrphy_apb_wr_32b(0x57472, 0x0);
dwc_ddrphy_apb_wr_32b(0x57474, 0x0);
dwc_ddrphy_apb_wr_32b(0x57476, 0x0);
dwc_ddrphy_apb_wr_32b(0x57478, 0x0);
dwc_ddrphy_apb_wr_32b(0x5747a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5747c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5747e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57480, 0x0);
dwc_ddrphy_apb_wr_32b(0x57482, 0x0);
dwc_ddrphy_apb_wr_32b(0x57484, 0x0);
dwc_ddrphy_apb_wr_32b(0x57486, 0x0);
dwc_ddrphy_apb_wr_32b(0x57488, 0x0);
dwc_ddrphy_apb_wr_32b(0x5748a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5748c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5748e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57490, 0x0);
dwc_ddrphy_apb_wr_32b(0x57492, 0x0);
dwc_ddrphy_apb_wr_32b(0x57494, 0x0);
dwc_ddrphy_apb_wr_32b(0x57496, 0x0);
dwc_ddrphy_apb_wr_32b(0x57498, 0x0);
dwc_ddrphy_apb_wr_32b(0x5749a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5749c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5749e, 0x0);
dwc_ddrphy_apb_wr_32b(0x574a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x574a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x574a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x574a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x574a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x574aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x574ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x574ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x574b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x574b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x574b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x574b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x574b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x574ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x574bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x574be, 0x0);
dwc_ddrphy_apb_wr_32b(0x574c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x574c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x574c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x574c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x574c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x574ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x574cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x574ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x574d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x574d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x574d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x574d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x574d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x574da, 0x0);
dwc_ddrphy_apb_wr_32b(0x574dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x574de, 0x0);
dwc_ddrphy_apb_wr_32b(0x574e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x574e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x574e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x574e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x574e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x574ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x574ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x574ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x574f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x574f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x574f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x574f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x574f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x574fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x574fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x574fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57500, 0x0);
dwc_ddrphy_apb_wr_32b(0x57502, 0x0);
dwc_ddrphy_apb_wr_32b(0x57504, 0x0);
dwc_ddrphy_apb_wr_32b(0x57506, 0x0);
dwc_ddrphy_apb_wr_32b(0x57508, 0x0);
dwc_ddrphy_apb_wr_32b(0x5750a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5750c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5750e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57510, 0x0);
dwc_ddrphy_apb_wr_32b(0x57512, 0x0);
dwc_ddrphy_apb_wr_32b(0x57514, 0x0);
dwc_ddrphy_apb_wr_32b(0x57516, 0x0);
dwc_ddrphy_apb_wr_32b(0x57518, 0x0);
dwc_ddrphy_apb_wr_32b(0x5751a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5751c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5751e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57520, 0x0);
dwc_ddrphy_apb_wr_32b(0x57522, 0x0);
dwc_ddrphy_apb_wr_32b(0x57524, 0x0);
dwc_ddrphy_apb_wr_32b(0x57526, 0x0);
dwc_ddrphy_apb_wr_32b(0x57528, 0x0);
dwc_ddrphy_apb_wr_32b(0x5752a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5752c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5752e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57530, 0x0);
dwc_ddrphy_apb_wr_32b(0x57532, 0x0);
dwc_ddrphy_apb_wr_32b(0x57534, 0x0);
dwc_ddrphy_apb_wr_32b(0x57536, 0x0);
dwc_ddrphy_apb_wr_32b(0x57538, 0x0);
dwc_ddrphy_apb_wr_32b(0x5753a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5753c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5753e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57540, 0x0);
dwc_ddrphy_apb_wr_32b(0x57542, 0x0);
dwc_ddrphy_apb_wr_32b(0x57544, 0x0);
dwc_ddrphy_apb_wr_32b(0x57546, 0x0);
dwc_ddrphy_apb_wr_32b(0x57548, 0x0);
dwc_ddrphy_apb_wr_32b(0x5754a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5754c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5754e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57550, 0x0);
dwc_ddrphy_apb_wr_32b(0x57552, 0x0);
dwc_ddrphy_apb_wr_32b(0x57554, 0x0);
dwc_ddrphy_apb_wr_32b(0x57556, 0x0);
dwc_ddrphy_apb_wr_32b(0x57558, 0x0);
dwc_ddrphy_apb_wr_32b(0x5755a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5755c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5755e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57560, 0x0);
dwc_ddrphy_apb_wr_32b(0x57562, 0x0);
dwc_ddrphy_apb_wr_32b(0x57564, 0x0);
dwc_ddrphy_apb_wr_32b(0x57566, 0x0);
dwc_ddrphy_apb_wr_32b(0x57568, 0x0);
dwc_ddrphy_apb_wr_32b(0x5756a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5756c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5756e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57570, 0x0);
dwc_ddrphy_apb_wr_32b(0x57572, 0x0);
dwc_ddrphy_apb_wr_32b(0x57574, 0x0);
dwc_ddrphy_apb_wr_32b(0x57576, 0x0);
dwc_ddrphy_apb_wr_32b(0x57578, 0x0);
dwc_ddrphy_apb_wr_32b(0x5757a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5757c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5757e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57580, 0x0);
dwc_ddrphy_apb_wr_32b(0x57582, 0x0);
dwc_ddrphy_apb_wr_32b(0x57584, 0x0);
dwc_ddrphy_apb_wr_32b(0x57586, 0x0);
dwc_ddrphy_apb_wr_32b(0x57588, 0x0);
dwc_ddrphy_apb_wr_32b(0x5758a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5758c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5758e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57590, 0x0);
dwc_ddrphy_apb_wr_32b(0x57592, 0x0);
dwc_ddrphy_apb_wr_32b(0x57594, 0x0);
dwc_ddrphy_apb_wr_32b(0x57596, 0x0);
dwc_ddrphy_apb_wr_32b(0x57598, 0x0);
dwc_ddrphy_apb_wr_32b(0x5759a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5759c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5759e, 0x0);
dwc_ddrphy_apb_wr_32b(0x575a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x575a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x575a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x575a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x575a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x575aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x575ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x575ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x575b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x575b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x575b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x575b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x575b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x575ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x575bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x575be, 0x0);
dwc_ddrphy_apb_wr_32b(0x575c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x575c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x575c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x575c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x575c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x575ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x575cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x575ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x575d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x575d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x575d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x575d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x575d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x575da, 0x0);
dwc_ddrphy_apb_wr_32b(0x575dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x575de, 0x0);
dwc_ddrphy_apb_wr_32b(0x575e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x575e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x575e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x575e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x575e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x575ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x575ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x575ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x575f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x575f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x575f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x575f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x575f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x575fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x575fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x575fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57600, 0x0);
dwc_ddrphy_apb_wr_32b(0x57602, 0x0);
dwc_ddrphy_apb_wr_32b(0x57604, 0x0);
dwc_ddrphy_apb_wr_32b(0x57606, 0x0);
dwc_ddrphy_apb_wr_32b(0x57608, 0x0);
dwc_ddrphy_apb_wr_32b(0x5760a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5760c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5760e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57610, 0x0);
dwc_ddrphy_apb_wr_32b(0x57612, 0x0);
dwc_ddrphy_apb_wr_32b(0x57614, 0x0);
dwc_ddrphy_apb_wr_32b(0x57616, 0x0);
dwc_ddrphy_apb_wr_32b(0x57618, 0x0);
dwc_ddrphy_apb_wr_32b(0x5761a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5761c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5761e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57620, 0x0);
dwc_ddrphy_apb_wr_32b(0x57622, 0x0);
dwc_ddrphy_apb_wr_32b(0x57624, 0x0);
dwc_ddrphy_apb_wr_32b(0x57626, 0x0);
dwc_ddrphy_apb_wr_32b(0x57628, 0x0);
dwc_ddrphy_apb_wr_32b(0x5762a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5762c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5762e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57630, 0x0);
dwc_ddrphy_apb_wr_32b(0x57632, 0x0);
dwc_ddrphy_apb_wr_32b(0x57634, 0x0);
dwc_ddrphy_apb_wr_32b(0x57636, 0x0);
dwc_ddrphy_apb_wr_32b(0x57638, 0x0);
dwc_ddrphy_apb_wr_32b(0x5763a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5763c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5763e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57640, 0x0);
dwc_ddrphy_apb_wr_32b(0x57642, 0x0);
dwc_ddrphy_apb_wr_32b(0x57644, 0x0);
dwc_ddrphy_apb_wr_32b(0x57646, 0x0);
dwc_ddrphy_apb_wr_32b(0x57648, 0x0);
dwc_ddrphy_apb_wr_32b(0x5764a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5764c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5764e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57650, 0x0);
dwc_ddrphy_apb_wr_32b(0x57652, 0x0);
dwc_ddrphy_apb_wr_32b(0x57654, 0x0);
dwc_ddrphy_apb_wr_32b(0x57656, 0x0);
dwc_ddrphy_apb_wr_32b(0x57658, 0x0);
dwc_ddrphy_apb_wr_32b(0x5765a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5765c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5765e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57660, 0x0);
dwc_ddrphy_apb_wr_32b(0x57662, 0x0);
dwc_ddrphy_apb_wr_32b(0x57664, 0x0);
dwc_ddrphy_apb_wr_32b(0x57666, 0x0);
dwc_ddrphy_apb_wr_32b(0x57668, 0x0);
dwc_ddrphy_apb_wr_32b(0x5766a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5766c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5766e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57670, 0x0);
dwc_ddrphy_apb_wr_32b(0x57672, 0x0);
dwc_ddrphy_apb_wr_32b(0x57674, 0x0);
dwc_ddrphy_apb_wr_32b(0x57676, 0x0);
dwc_ddrphy_apb_wr_32b(0x57678, 0x0);
dwc_ddrphy_apb_wr_32b(0x5767a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5767c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5767e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57680, 0x0);
dwc_ddrphy_apb_wr_32b(0x57682, 0x0);
dwc_ddrphy_apb_wr_32b(0x57684, 0x0);
dwc_ddrphy_apb_wr_32b(0x57686, 0x0);
dwc_ddrphy_apb_wr_32b(0x57688, 0x0);
dwc_ddrphy_apb_wr_32b(0x5768a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5768c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5768e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57690, 0x0);
dwc_ddrphy_apb_wr_32b(0x57692, 0x0);
dwc_ddrphy_apb_wr_32b(0x57694, 0x0);
dwc_ddrphy_apb_wr_32b(0x57696, 0x0);
dwc_ddrphy_apb_wr_32b(0x57698, 0x0);
dwc_ddrphy_apb_wr_32b(0x5769a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5769c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5769e, 0x0);
dwc_ddrphy_apb_wr_32b(0x576a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x576a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x576a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x576a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x576a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x576aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x576ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x576ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x576b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x576b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x576b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x576b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x576b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x576ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x576bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x576be, 0x0);
dwc_ddrphy_apb_wr_32b(0x576c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x576c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x576c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x576c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x576c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x576ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x576cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x576ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x576d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x576d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x576d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x576d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x576d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x576da, 0x0);
dwc_ddrphy_apb_wr_32b(0x576dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x576de, 0x0);
dwc_ddrphy_apb_wr_32b(0x576e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x576e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x576e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x576e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x576e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x576ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x576ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x576ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x576f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x576f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x576f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x576f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x576f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x576fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x576fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x576fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57700, 0x0);
dwc_ddrphy_apb_wr_32b(0x57702, 0x0);
dwc_ddrphy_apb_wr_32b(0x57704, 0x0);
dwc_ddrphy_apb_wr_32b(0x57706, 0x0);
dwc_ddrphy_apb_wr_32b(0x57708, 0x0);
dwc_ddrphy_apb_wr_32b(0x5770a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5770c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5770e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57710, 0x0);
dwc_ddrphy_apb_wr_32b(0x57712, 0x0);
dwc_ddrphy_apb_wr_32b(0x57714, 0x0);
dwc_ddrphy_apb_wr_32b(0x57716, 0x0);
dwc_ddrphy_apb_wr_32b(0x57718, 0x0);
dwc_ddrphy_apb_wr_32b(0x5771a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5771c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5771e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57720, 0x0);
dwc_ddrphy_apb_wr_32b(0x57722, 0x0);
dwc_ddrphy_apb_wr_32b(0x57724, 0x0);
dwc_ddrphy_apb_wr_32b(0x57726, 0x0);
dwc_ddrphy_apb_wr_32b(0x57728, 0x0);
dwc_ddrphy_apb_wr_32b(0x5772a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5772c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5772e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57730, 0x0);
dwc_ddrphy_apb_wr_32b(0x57732, 0x0);
dwc_ddrphy_apb_wr_32b(0x57734, 0x0);
dwc_ddrphy_apb_wr_32b(0x57736, 0x0);
dwc_ddrphy_apb_wr_32b(0x57738, 0x0);
dwc_ddrphy_apb_wr_32b(0x5773a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5773c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5773e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57740, 0x0);
dwc_ddrphy_apb_wr_32b(0x57742, 0x0);
dwc_ddrphy_apb_wr_32b(0x57744, 0x0);
dwc_ddrphy_apb_wr_32b(0x57746, 0x0);
dwc_ddrphy_apb_wr_32b(0x57748, 0x0);
dwc_ddrphy_apb_wr_32b(0x5774a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5774c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5774e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57750, 0x0);
dwc_ddrphy_apb_wr_32b(0x57752, 0x0);
dwc_ddrphy_apb_wr_32b(0x57754, 0x0);
dwc_ddrphy_apb_wr_32b(0x57756, 0x0);
dwc_ddrphy_apb_wr_32b(0x57758, 0x0);
dwc_ddrphy_apb_wr_32b(0x5775a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5775c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5775e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57760, 0x0);
dwc_ddrphy_apb_wr_32b(0x57762, 0x0);
dwc_ddrphy_apb_wr_32b(0x57764, 0x0);
dwc_ddrphy_apb_wr_32b(0x57766, 0x0);
dwc_ddrphy_apb_wr_32b(0x57768, 0x0);
dwc_ddrphy_apb_wr_32b(0x5776a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5776c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5776e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57770, 0x0);
dwc_ddrphy_apb_wr_32b(0x57772, 0x0);
dwc_ddrphy_apb_wr_32b(0x57774, 0x0);
dwc_ddrphy_apb_wr_32b(0x57776, 0x0);
dwc_ddrphy_apb_wr_32b(0x57778, 0x0);
dwc_ddrphy_apb_wr_32b(0x5777a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5777c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5777e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57780, 0x0);
dwc_ddrphy_apb_wr_32b(0x57782, 0x0);
dwc_ddrphy_apb_wr_32b(0x57784, 0x0);
dwc_ddrphy_apb_wr_32b(0x57786, 0x0);
dwc_ddrphy_apb_wr_32b(0x57788, 0x0);
dwc_ddrphy_apb_wr_32b(0x5778a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5778c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5778e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57790, 0x0);
dwc_ddrphy_apb_wr_32b(0x57792, 0x0);
dwc_ddrphy_apb_wr_32b(0x57794, 0x0);
dwc_ddrphy_apb_wr_32b(0x57796, 0x0);
dwc_ddrphy_apb_wr_32b(0x57798, 0x0);
dwc_ddrphy_apb_wr_32b(0x5779a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5779c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5779e, 0x0);
dwc_ddrphy_apb_wr_32b(0x577a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x577a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x577a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x577a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x577a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x577aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x577ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x577ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x577b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x577b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x577b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x577b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x577b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x577ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x577bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x577be, 0x0);
dwc_ddrphy_apb_wr_32b(0x577c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x577c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x577c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x577c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x577c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x577ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x577cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x577ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x577d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x577d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x577d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x577d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x577d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x577da, 0x0);
dwc_ddrphy_apb_wr_32b(0x577dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x577de, 0x0);
dwc_ddrphy_apb_wr_32b(0x577e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x577e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x577e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x577e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x577e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x577ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x577ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x577ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x577f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x577f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x577f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x577f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x577f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x577fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x577fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x577fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57800, 0x0);
dwc_ddrphy_apb_wr_32b(0x57802, 0x0);
dwc_ddrphy_apb_wr_32b(0x57804, 0x0);
dwc_ddrphy_apb_wr_32b(0x57806, 0x0);
dwc_ddrphy_apb_wr_32b(0x57808, 0x0);
dwc_ddrphy_apb_wr_32b(0x5780a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5780c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5780e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57810, 0x0);
dwc_ddrphy_apb_wr_32b(0x57812, 0x0);
dwc_ddrphy_apb_wr_32b(0x57814, 0x0);
dwc_ddrphy_apb_wr_32b(0x57816, 0x0);
dwc_ddrphy_apb_wr_32b(0x57818, 0x0);
dwc_ddrphy_apb_wr_32b(0x5781a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5781c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5781e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57820, 0x0);
dwc_ddrphy_apb_wr_32b(0x57822, 0x0);
dwc_ddrphy_apb_wr_32b(0x57824, 0x0);
dwc_ddrphy_apb_wr_32b(0x57826, 0x0);
dwc_ddrphy_apb_wr_32b(0x57828, 0x0);
dwc_ddrphy_apb_wr_32b(0x5782a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5782c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5782e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57830, 0x0);
dwc_ddrphy_apb_wr_32b(0x57832, 0x0);
dwc_ddrphy_apb_wr_32b(0x57834, 0x0);
dwc_ddrphy_apb_wr_32b(0x57836, 0x0);
dwc_ddrphy_apb_wr_32b(0x57838, 0x0);
dwc_ddrphy_apb_wr_32b(0x5783a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5783c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5783e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57840, 0x0);
dwc_ddrphy_apb_wr_32b(0x57842, 0x0);
dwc_ddrphy_apb_wr_32b(0x57844, 0x0);
dwc_ddrphy_apb_wr_32b(0x57846, 0x0);
dwc_ddrphy_apb_wr_32b(0x57848, 0x0);
dwc_ddrphy_apb_wr_32b(0x5784a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5784c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5784e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57850, 0x0);
dwc_ddrphy_apb_wr_32b(0x57852, 0x0);
dwc_ddrphy_apb_wr_32b(0x57854, 0x0);
dwc_ddrphy_apb_wr_32b(0x57856, 0x0);
dwc_ddrphy_apb_wr_32b(0x57858, 0x0);
dwc_ddrphy_apb_wr_32b(0x5785a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5785c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5785e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57860, 0x0);
dwc_ddrphy_apb_wr_32b(0x57862, 0x0);
dwc_ddrphy_apb_wr_32b(0x57864, 0x0);
dwc_ddrphy_apb_wr_32b(0x57866, 0x0);
dwc_ddrphy_apb_wr_32b(0x57868, 0x0);
dwc_ddrphy_apb_wr_32b(0x5786a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5786c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5786e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57870, 0x0);
dwc_ddrphy_apb_wr_32b(0x57872, 0x0);
dwc_ddrphy_apb_wr_32b(0x57874, 0x0);
dwc_ddrphy_apb_wr_32b(0x57876, 0x0);
dwc_ddrphy_apb_wr_32b(0x57878, 0x0);
dwc_ddrphy_apb_wr_32b(0x5787a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5787c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5787e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57880, 0x0);
dwc_ddrphy_apb_wr_32b(0x57882, 0x0);
dwc_ddrphy_apb_wr_32b(0x57884, 0x0);
dwc_ddrphy_apb_wr_32b(0x57886, 0x0);
dwc_ddrphy_apb_wr_32b(0x57888, 0x0);
dwc_ddrphy_apb_wr_32b(0x5788a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5788c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5788e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57890, 0x0);
dwc_ddrphy_apb_wr_32b(0x57892, 0x0);
dwc_ddrphy_apb_wr_32b(0x57894, 0x0);
dwc_ddrphy_apb_wr_32b(0x57896, 0x0);
dwc_ddrphy_apb_wr_32b(0x57898, 0x0);
dwc_ddrphy_apb_wr_32b(0x5789a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5789c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5789e, 0x0);
dwc_ddrphy_apb_wr_32b(0x578a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x578a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x578a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x578a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x578a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x578aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x578ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x578ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x578b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x578b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x578b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x578b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x578b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x578ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x578bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x578be, 0x0);
dwc_ddrphy_apb_wr_32b(0x578c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x578c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x578c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x578c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x578c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x578ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x578cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x578ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x578d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x578d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x578d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x578d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x578d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x578da, 0x0);
dwc_ddrphy_apb_wr_32b(0x578dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x578de, 0x0);
dwc_ddrphy_apb_wr_32b(0x578e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x578e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x578e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x578e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x578e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x578ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x578ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x578ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x578f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x578f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x578f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x578f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x578f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x578fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x578fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x578fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57900, 0x0);
dwc_ddrphy_apb_wr_32b(0x57902, 0x0);
dwc_ddrphy_apb_wr_32b(0x57904, 0x0);
dwc_ddrphy_apb_wr_32b(0x57906, 0x0);
dwc_ddrphy_apb_wr_32b(0x57908, 0x0);
dwc_ddrphy_apb_wr_32b(0x5790a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5790c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5790e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57910, 0x0);
dwc_ddrphy_apb_wr_32b(0x57912, 0x0);
dwc_ddrphy_apb_wr_32b(0x57914, 0x0);
dwc_ddrphy_apb_wr_32b(0x57916, 0x0);
dwc_ddrphy_apb_wr_32b(0x57918, 0x0);
dwc_ddrphy_apb_wr_32b(0x5791a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5791c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5791e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57920, 0x0);
dwc_ddrphy_apb_wr_32b(0x57922, 0x0);
dwc_ddrphy_apb_wr_32b(0x57924, 0x0);
dwc_ddrphy_apb_wr_32b(0x57926, 0x0);
dwc_ddrphy_apb_wr_32b(0x57928, 0x0);
dwc_ddrphy_apb_wr_32b(0x5792a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5792c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5792e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57930, 0x0);
dwc_ddrphy_apb_wr_32b(0x57932, 0x0);
dwc_ddrphy_apb_wr_32b(0x57934, 0x0);
dwc_ddrphy_apb_wr_32b(0x57936, 0x0);
dwc_ddrphy_apb_wr_32b(0x57938, 0x0);
dwc_ddrphy_apb_wr_32b(0x5793a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5793c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5793e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57940, 0x0);
dwc_ddrphy_apb_wr_32b(0x57942, 0x0);
dwc_ddrphy_apb_wr_32b(0x57944, 0x0);
dwc_ddrphy_apb_wr_32b(0x57946, 0x0);
dwc_ddrphy_apb_wr_32b(0x57948, 0x0);
dwc_ddrphy_apb_wr_32b(0x5794a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5794c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5794e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57950, 0x0);
dwc_ddrphy_apb_wr_32b(0x57952, 0x0);
dwc_ddrphy_apb_wr_32b(0x57954, 0x0);
dwc_ddrphy_apb_wr_32b(0x57956, 0x0);
dwc_ddrphy_apb_wr_32b(0x57958, 0x0);
dwc_ddrphy_apb_wr_32b(0x5795a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5795c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5795e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57960, 0x0);
dwc_ddrphy_apb_wr_32b(0x57962, 0x0);
dwc_ddrphy_apb_wr_32b(0x57964, 0x0);
dwc_ddrphy_apb_wr_32b(0x57966, 0x0);
dwc_ddrphy_apb_wr_32b(0x57968, 0x0);
dwc_ddrphy_apb_wr_32b(0x5796a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5796c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5796e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57970, 0x0);
dwc_ddrphy_apb_wr_32b(0x57972, 0x0);
dwc_ddrphy_apb_wr_32b(0x57974, 0x0);
dwc_ddrphy_apb_wr_32b(0x57976, 0x0);
dwc_ddrphy_apb_wr_32b(0x57978, 0x0);
dwc_ddrphy_apb_wr_32b(0x5797a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5797c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5797e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57980, 0x0);
dwc_ddrphy_apb_wr_32b(0x57982, 0x0);
dwc_ddrphy_apb_wr_32b(0x57984, 0x0);
dwc_ddrphy_apb_wr_32b(0x57986, 0x0);
dwc_ddrphy_apb_wr_32b(0x57988, 0x0);
dwc_ddrphy_apb_wr_32b(0x5798a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5798c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5798e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57990, 0x0);
dwc_ddrphy_apb_wr_32b(0x57992, 0x0);
dwc_ddrphy_apb_wr_32b(0x57994, 0x0);
dwc_ddrphy_apb_wr_32b(0x57996, 0x0);
dwc_ddrphy_apb_wr_32b(0x57998, 0x0);
dwc_ddrphy_apb_wr_32b(0x5799a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5799c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5799e, 0x0);
dwc_ddrphy_apb_wr_32b(0x579a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x579a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x579a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x579a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x579a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x579aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x579ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x579ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x579b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x579b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x579b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x579b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x579b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x579ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x579bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x579be, 0x0);
dwc_ddrphy_apb_wr_32b(0x579c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x579c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x579c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x579c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x579c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x579ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x579cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x579ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x579d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x579d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x579d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x579d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x579d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x579da, 0x0);
dwc_ddrphy_apb_wr_32b(0x579dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x579de, 0x0);
dwc_ddrphy_apb_wr_32b(0x579e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x579e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x579e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x579e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x579e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x579ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x579ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x579ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x579f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x579f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x579f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x579f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x579f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x579fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x579fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x579fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a00, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a02, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a04, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a06, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a08, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a10, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a12, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a14, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a16, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a18, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a20, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a22, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a24, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a26, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a28, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a30, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a32, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a34, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a36, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a38, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a40, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a42, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a44, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a46, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a48, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a50, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a52, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a54, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a56, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a58, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a60, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a62, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a64, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a66, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a68, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a70, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a72, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a74, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a76, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a78, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a80, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a82, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a84, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a86, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a88, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a90, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a92, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a94, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a96, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a98, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57a9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57aa0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57aa2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57aa4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57aa6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57aa8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57aaa, 0x0);
dwc_ddrphy_apb_wr_32b(0x57aac, 0x0);
dwc_ddrphy_apb_wr_32b(0x57aae, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ab0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ab2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ab4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ab6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ab8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57aba, 0x0);
dwc_ddrphy_apb_wr_32b(0x57abc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57abe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ac0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ac2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ac4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ac6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ac8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57aca, 0x0);
dwc_ddrphy_apb_wr_32b(0x57acc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ace, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ad0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ad2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ad4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ad6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ad8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ada, 0x0);
dwc_ddrphy_apb_wr_32b(0x57adc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ade, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ae0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ae2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ae4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ae6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ae8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57aea, 0x0);
dwc_ddrphy_apb_wr_32b(0x57aec, 0x0);
dwc_ddrphy_apb_wr_32b(0x57aee, 0x0);
dwc_ddrphy_apb_wr_32b(0x57af0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57af2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57af4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57af6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57af8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57afa, 0x0);
dwc_ddrphy_apb_wr_32b(0x57afc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57afe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b00, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b02, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b04, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b06, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b08, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b10, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b12, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b14, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b16, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b18, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b20, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b22, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b24, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b26, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b28, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b30, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b32, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b34, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b36, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b38, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b40, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b42, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b44, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b46, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b48, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b50, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b52, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b54, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b56, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b58, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b60, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b62, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b64, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b66, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b68, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b70, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b72, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b74, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b76, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b78, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b80, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b82, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b84, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b86, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b88, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b90, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b92, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b94, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b96, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b98, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57b9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ba0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ba2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ba4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ba6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ba8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57baa, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bac, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bae, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bba, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bca, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bcc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bce, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bda, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bdc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bde, 0x0);
dwc_ddrphy_apb_wr_32b(0x57be0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57be2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57be4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57be6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57be8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bea, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bec, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bee, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bf0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bf2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bf4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bf6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bf8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bfa, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bfc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57bfe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c00, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c02, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c04, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c06, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c08, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c10, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c12, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c14, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c16, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c18, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c20, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c22, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c24, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c26, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c28, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c30, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c32, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c34, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c36, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c38, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c40, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c42, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c44, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c46, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c48, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c50, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c52, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c54, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c56, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c58, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c60, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c62, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c64, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c66, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c68, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c70, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c72, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c74, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c76, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c78, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c80, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c82, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c84, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c86, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c88, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c90, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c92, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c94, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c96, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c98, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57c9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ca0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ca2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ca4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ca6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ca8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57caa, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cac, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cae, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cba, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cca, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ccc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cce, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cda, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cdc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cde, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ce0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ce2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ce4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ce6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ce8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cea, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cec, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cee, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cf0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cf2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cf4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cf6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cf8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cfa, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cfc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57cfe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d00, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d02, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d04, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d06, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d08, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d10, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d12, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d14, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d16, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d18, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d20, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d22, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d24, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d26, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d28, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d30, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d32, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d34, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d36, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d38, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d40, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d42, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d44, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d46, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d48, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d50, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d52, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d54, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d56, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d58, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d60, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d62, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d64, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d66, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d68, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d70, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d72, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d74, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d76, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d78, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d80, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d82, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d84, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d86, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d88, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d90, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d92, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d94, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d96, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d98, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57d9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57da0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57da2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57da4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57da6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57da8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57daa, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dac, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dae, 0x0);
dwc_ddrphy_apb_wr_32b(0x57db0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57db2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57db4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57db6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57db8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dba, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dca, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dcc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dce, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dda, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ddc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dde, 0x0);
dwc_ddrphy_apb_wr_32b(0x57de0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57de2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57de4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57de6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57de8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dea, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dec, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dee, 0x0);
dwc_ddrphy_apb_wr_32b(0x57df0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57df2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57df4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57df6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57df8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dfa, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dfc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57dfe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e00, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e02, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e04, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e06, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e08, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e10, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e12, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e14, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e16, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e18, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e20, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e22, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e24, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e26, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e28, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e30, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e32, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e34, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e36, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e38, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e40, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e42, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e44, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e46, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e48, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e50, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e52, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e54, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e56, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e58, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e60, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e62, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e64, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e66, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e68, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e70, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e72, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e74, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e76, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e78, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e80, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e82, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e84, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e86, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e88, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e90, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e92, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e94, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e96, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e98, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57e9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ea0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ea2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ea4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ea6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ea8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57eaa, 0x0);
dwc_ddrphy_apb_wr_32b(0x57eac, 0x0);
dwc_ddrphy_apb_wr_32b(0x57eae, 0x0);
dwc_ddrphy_apb_wr_32b(0x57eb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57eb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57eb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57eb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57eb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57eba, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ebc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ebe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ec0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ec2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ec4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ec6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ec8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57eca, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ecc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ece, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ed0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ed2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ed4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ed6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ed8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57eda, 0x0);
dwc_ddrphy_apb_wr_32b(0x57edc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ede, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ee0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ee2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ee4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ee6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ee8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57eea, 0x0);
dwc_ddrphy_apb_wr_32b(0x57eec, 0x0);
dwc_ddrphy_apb_wr_32b(0x57eee, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ef0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ef2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ef4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ef6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ef8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57efa, 0x0);
dwc_ddrphy_apb_wr_32b(0x57efc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57efe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f00, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f02, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f04, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f06, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f08, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f0a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f0c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f0e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f10, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f12, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f14, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f16, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f18, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f1a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f1c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f1e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f20, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f22, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f24, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f26, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f28, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f2a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f2c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f2e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f30, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f32, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f34, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f36, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f38, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f3a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f3c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f3e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f40, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f42, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f44, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f46, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f48, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f4a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f4c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f4e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f50, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f52, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f54, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f56, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f58, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f5a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f5c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f5e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f60, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f62, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f64, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f66, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f68, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f6a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f6c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f6e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f70, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f72, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f74, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f76, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f78, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f7a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f7c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f7e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f80, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f82, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f84, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f86, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f88, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f8a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f8c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f8e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f90, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f92, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f94, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f96, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f98, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f9a, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f9c, 0x0);
dwc_ddrphy_apb_wr_32b(0x57f9e, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fa0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fa2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fa4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fa6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fa8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57faa, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fac, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fae, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fb0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fb2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fb4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fb6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fb8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fba, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fbc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fbe, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fc0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fc2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fc4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fc6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fc8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fca, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fcc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fce, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fd0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fd2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fd4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fd6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fd8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fda, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fdc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fde, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fe0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fe2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fe4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fe6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fe8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fea, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fec, 0x0);
dwc_ddrphy_apb_wr_32b(0x57fee, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ff0, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ff2, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ff4, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ff6, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ff8, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ffa, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ffc, 0x0);
dwc_ddrphy_apb_wr_32b(0x57ffe, 0x0);
#endif
//// [dwc_ddrphy_phyinit_WriteOutMem] DONE.  Index 0x8000
//// 2.	Isolate the APB access from the internal CSRs by setting the MicroContMuxSel CSR to 1.
////	  This allows the firmware unrestricted access to the configuration CSRs.
dwc_ddrphy_apb_wr(0xd0000, 0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
//// [dwc_ddrphy_phyinit_D_loadIMEM, 1D] End of dwc_ddrphy_phyinit_D_loadIMEM()
//
//
////##############################################################
////
//// 4.3.5(E) Set the PHY input clocks to the desired frequency for pstate 0
////
//// Set the PHY input Dfi Clk to the desired operating frequency associated with the given Pstate. Before proceeding to the next step,
//// the clock should be stable at the new frequency. For more information on clocking requirements, see "Clocks" on page <XXX>.
////
////##############################################################
//
dwc_ddrphy_phyinit_userCustom_E_setDfiClk(0);

//
//// [dwc_ddrphy_phyinit_userCustom_E_setDfiClk] End of dwc_ddrphy_phyinit_userCustom_E_setDfiClk()
//// [phyinit_F_loadDMEM, 1D] Start of dwc_ddrphy_phyinit_F_loadDMEM (pstate=0, Train2D=0)
//
//
////##############################################################
////
//// 4.3.5(F) Load the 1D DMEM image and write the 1D Message Block parameters for the training firmware
////
//// The procedure is as follows:
////
////##############################################################
//
//
//
//// 1.    Load the firmware DMEM segment to initialize the data structures.
//
//// 2.    Write the Firmware Message Block with the required contents detailing the training parameters.
//
// [dwc_ddrphy_phyinit_storeIncvFile] Reading input file: /home/jerry_ku/Project/Development/ast2700dev/ddr45phy_tsmc12/coreConsultant/config3_3.50a/2022-12-12-16-52-55/firmware/Latest/training/ddr4/ddr4_pmu_train_dmem.incv

//// 1.	Enable access to the internal CSRs by setting the MicroContMuxSel CSR to 0.
////	   This allows the memory controller unrestricted access to the configuration CSRs.
dwc_ddrphy_apb_wr(0xd0000, 0x0); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
//// [dwc_ddrphy_phyinit_WriteOutMem] STARTING 32bit write. offset 0x58000 size 0x8000
//#ifdef TRAIN_LOADBIN
#if defined(CONFIG_DDR_PHY_TRAINING)
dwc_ddrphy_phyinit_userCustom_F_loadDMEM(0, 0);
#endif
dwc_ddrphy_apb_wr_32b(0x58000, 0x700);
dwc_ddrphy_apb_wr_32b(0x58002, 0xc800000);
dwc_ddrphy_apb_wr_32b(0x58004, 0x0);
dwc_ddrphy_apb_wr_32b(0x58006, 0x10000240);
dwc_ddrphy_apb_wr_32b(0x58008, 0x1);
dwc_ddrphy_apb_wr_32b(0x5800a, 0x31f0000);
dwc_ddrphy_apb_wr_32b(0x5800c, 0xc8);
dwc_ddrphy_apb_wr_32b(0x5800e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58010, 0x0);
dwc_ddrphy_apb_wr_32b(0x58012, 0x2);
dwc_ddrphy_apb_wr_32b(0x58014, 0x0);
dwc_ddrphy_apb_wr_32b(0x58016, 0x0);
dwc_ddrphy_apb_wr_32b(0x58018, 0x0);
dwc_ddrphy_apb_wr_32b(0x5801a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5801c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5801e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58020, 0x0);
dwc_ddrphy_apb_wr_32b(0x58022, 0x0);
dwc_ddrphy_apb_wr_32b(0x58024, 0x0);
dwc_ddrphy_apb_wr_32b(0x58026, 0x0);
dwc_ddrphy_apb_wr_32b(0x58028, 0x0);
dwc_ddrphy_apb_wr_32b(0x5802a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5802c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5802e, 0x21500000);
dwc_ddrphy_apb_wr_32b(0x58030, 0x2280101);
dwc_ddrphy_apb_wr_32b(0x58032, 0x400);
dwc_ddrphy_apb_wr_32b(0x58034, 0x104f0500);
dwc_ddrphy_apb_wr_32b(0x58036, 0x0);
dwc_ddrphy_apb_wr_32b(0x58038, 0x0);
dwc_ddrphy_apb_wr_32b(0x5803a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5803c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5803e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58040, 0x0);
dwc_ddrphy_apb_wr_32b(0x58042, 0xf0f0000);
dwc_ddrphy_apb_wr_32b(0x58044, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58046, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58048, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x5804a, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x5804c, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x5804e, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58050, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58052, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58054, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58056, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58058, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x5805a, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x5805c, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x5805e, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58060, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58062, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58064, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58066, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58068, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x5806a, 0xf0f);
dwc_ddrphy_apb_wr_32b(0x5806c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5806e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58070, 0x0);
dwc_ddrphy_apb_wr_32b(0x58072, 0x0);
dwc_ddrphy_apb_wr_32b(0x58074, 0x0);
dwc_ddrphy_apb_wr_32b(0x58076, 0x0);
dwc_ddrphy_apb_wr_32b(0x58078, 0x0);
dwc_ddrphy_apb_wr_32b(0x5807a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5807c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5807e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58080, 0x0);
dwc_ddrphy_apb_wr_32b(0x58082, 0x0);
dwc_ddrphy_apb_wr_32b(0x58084, 0x0);
dwc_ddrphy_apb_wr_32b(0x58086, 0x0);
dwc_ddrphy_apb_wr_32b(0x58088, 0x0);
dwc_ddrphy_apb_wr_32b(0x5808a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5808c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5808e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58090, 0x0);
dwc_ddrphy_apb_wr_32b(0x58092, 0x0);
dwc_ddrphy_apb_wr_32b(0x58094, 0x0);
dwc_ddrphy_apb_wr_32b(0x58096, 0x0);
dwc_ddrphy_apb_wr_32b(0x58098, 0x0);
dwc_ddrphy_apb_wr_32b(0x5809a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5809c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5809e, 0x0);
dwc_ddrphy_apb_wr_32b(0x580a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x580a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x580a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x580a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x580a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x580aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x580b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x580b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x580b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x580b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x580b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x580bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x580be, 0x0);
dwc_ddrphy_apb_wr_32b(0x580c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x580c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x580c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x580c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x580c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x580cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x580d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x580d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x580d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x580d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x580d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x580da, 0x0);
dwc_ddrphy_apb_wr_32b(0x580dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x580de, 0x0);
dwc_ddrphy_apb_wr_32b(0x580e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x580e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x580e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x580e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x580e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x580f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x580f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x580f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x580f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x580f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x580fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x580fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x580fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x58100, 0x0);
dwc_ddrphy_apb_wr_32b(0x58102, 0x0);
dwc_ddrphy_apb_wr_32b(0x58104, 0x0);
dwc_ddrphy_apb_wr_32b(0x58106, 0x0);
dwc_ddrphy_apb_wr_32b(0x58108, 0x0);
dwc_ddrphy_apb_wr_32b(0x5810a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5810c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5810e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58110, 0x0);
dwc_ddrphy_apb_wr_32b(0x58112, 0x0);
dwc_ddrphy_apb_wr_32b(0x58114, 0x0);
dwc_ddrphy_apb_wr_32b(0x58116, 0x0);
dwc_ddrphy_apb_wr_32b(0x58118, 0x0);
dwc_ddrphy_apb_wr_32b(0x5811a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5811c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5811e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58120, 0x0);
dwc_ddrphy_apb_wr_32b(0x58122, 0x0);
dwc_ddrphy_apb_wr_32b(0x58124, 0x0);
dwc_ddrphy_apb_wr_32b(0x58126, 0x0);
dwc_ddrphy_apb_wr_32b(0x58128, 0x0);
dwc_ddrphy_apb_wr_32b(0x5812a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5812c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5812e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58130, 0x0);
dwc_ddrphy_apb_wr_32b(0x58132, 0x0);
dwc_ddrphy_apb_wr_32b(0x58134, 0x0);
dwc_ddrphy_apb_wr_32b(0x58136, 0x0);
dwc_ddrphy_apb_wr_32b(0x58138, 0x0);
dwc_ddrphy_apb_wr_32b(0x5813a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5813c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5813e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58140, 0x0);
dwc_ddrphy_apb_wr_32b(0x58142, 0x0);
dwc_ddrphy_apb_wr_32b(0x58144, 0x0);
dwc_ddrphy_apb_wr_32b(0x58146, 0x0);
dwc_ddrphy_apb_wr_32b(0x58148, 0x0);
dwc_ddrphy_apb_wr_32b(0x5814a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5814c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5814e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58150, 0x0);
dwc_ddrphy_apb_wr_32b(0x58152, 0x0);
dwc_ddrphy_apb_wr_32b(0x58154, 0x0);
dwc_ddrphy_apb_wr_32b(0x58156, 0x0);
dwc_ddrphy_apb_wr_32b(0x58158, 0x0);
dwc_ddrphy_apb_wr_32b(0x5815a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5815c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5815e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58160, 0x0);
dwc_ddrphy_apb_wr_32b(0x58162, 0x0);
dwc_ddrphy_apb_wr_32b(0x58164, 0x0);
dwc_ddrphy_apb_wr_32b(0x58166, 0x0);
dwc_ddrphy_apb_wr_32b(0x58168, 0x0);
dwc_ddrphy_apb_wr_32b(0x5816a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5816c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5816e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58170, 0x0);
dwc_ddrphy_apb_wr_32b(0x58172, 0x0);
dwc_ddrphy_apb_wr_32b(0x58174, 0x0);
dwc_ddrphy_apb_wr_32b(0x58176, 0x0);
dwc_ddrphy_apb_wr_32b(0x58178, 0x0);
dwc_ddrphy_apb_wr_32b(0x5817a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5817c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5817e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58180, 0x0);
dwc_ddrphy_apb_wr_32b(0x58182, 0x0);
dwc_ddrphy_apb_wr_32b(0x58184, 0x0);
dwc_ddrphy_apb_wr_32b(0x58186, 0x0);
dwc_ddrphy_apb_wr_32b(0x58188, 0x0);
dwc_ddrphy_apb_wr_32b(0x5818a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5818c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5818e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58190, 0x0);
dwc_ddrphy_apb_wr_32b(0x58192, 0x0);
dwc_ddrphy_apb_wr_32b(0x58194, 0x0);
dwc_ddrphy_apb_wr_32b(0x58196, 0x0);
dwc_ddrphy_apb_wr_32b(0x58198, 0x0);
dwc_ddrphy_apb_wr_32b(0x5819a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5819c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5819e, 0x0);
dwc_ddrphy_apb_wr_32b(0x581a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x581a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x581a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x581a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x581a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x581aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x581b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x581b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x581b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x581b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x581b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x581bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x581be, 0x0);
dwc_ddrphy_apb_wr_32b(0x581c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x581c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x581c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x581c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x581c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x581cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x581d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x581d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x581d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x581d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x581d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x581da, 0x0);
dwc_ddrphy_apb_wr_32b(0x581dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x581de, 0x0);
dwc_ddrphy_apb_wr_32b(0x581e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x581e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x581e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x581e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x581e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x581f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x581f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x581f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x581f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x581f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x581fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x581fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x581fe, 0x0);
//// [dwc_ddrphy_phyinit_WriteOutMem] DONE.  Index 0x8000
//// 2.	Isolate the APB access from the internal CSRs by setting the MicroContMuxSel CSR to 1.
////	  This allows the firmware unrestricted access to the configuration CSRs.
dwc_ddrphy_apb_wr(0xd0000, 0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
//// [phyinit_F_loadDMEM, 1D] End of dwc_ddrphy_phyinit_F_loadDMEM()
//
//
////##############################################################
////
//// 4.3.7(G) Execute the Training Firmware
////
//// The training firmware is executed with the following procedure:
////
////##############################################################
//
//
//// 1.  Reset the firmware microcontroller by writing the MicroReset CSR to set the StallToMicro and
////	 ResetToMicro fields to 1 (all other fields should be zero).
////	 Then rewrite the CSR so that only the StallToMicro remains set (all other fields should be zero).
dwc_ddrphy_apb_wr(0xd0000, 0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
dwc_ddrphy_apb_wr(0xd0099, 0x9); // DWC_DDRPHYA_APBONLY0_MicroReset
dwc_ddrphy_apb_wr(0xd0099, 0x1); // DWC_DDRPHYA_APBONLY0_MicroReset
//
//// 2. Begin execution of the training firmware by setting the MicroReset CSR to 4'b0000.
dwc_ddrphy_apb_wr(0xd0099, 0x0); // DWC_DDRPHYA_APBONLY0_MicroReset
//
//// 3.   Wait for the training firmware to complete by following the procedure in "uCtrl Initialization and Mailbox Messaging"
//// 4.3.7	3.	 Wait for the training firmware to complete.  Implement timeout function or follow the procedure in "3.4 Running the firmware" of the Training Firmware Application Note to poll the Mailbox message.
dwc_ddrphy_phyinit_userCustom_G_waitFwDone();

//// [dwc_ddrphy_phyinit_userCustom_G_waitFwDone] End of dwc_ddrphy_phyinit_userCustom_G_waitFwDone()
//// 4.   Halt the microcontroller."
dwc_ddrphy_apb_wr(0xd0099, 0x1); // DWC_DDRPHYA_APBONLY0_MicroReset
dwc_ddrphy_apb_wr(0x20089, 0x0); // DWC_DDRPHYA_MASTER0_base0_CalZap
//// [dwc_ddrphy_phyinit_G_execFW] End of dwc_ddrphy_phyinit_G_execFW()
//
//
////##############################################################
////
//// 4.3.8(H) Read the Message Block results
////
//// The procedure is as follows:
////
////##############################################################
//
//
//// 1.	Enable access to the internal CSRs by setting the MicroContMuxSel CSR to 0.
dwc_ddrphy_apb_wr(0xd0000, 0x0); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
//
//2. Read the Firmware Message Block to obtain the results from the training.
//This can be accomplished by issuing APB read commands to the DMEM addresses.
//Example:
//if (Train2D)
//{
//	_read_2d_message_block_outputs_
//}
//else
//{
//	_read_1d_message_block_outputs_
//}
//This can be accomplished by issuing APB read commands to the DMEM addresses.
dwc_ddrphy_phyinit_userCustom_H_readMsgBlock(0);

//[dwc_ddrphy_phyinit_userCustom_H_readMsgBlock] End of dwc_ddrphy_phyinit_userCustom_H_readMsgBlock()
//// 3.	Isolate the APB access from the internal CSRs by setting the MicroContMuxSel CSR to 1.
dwc_ddrphy_apb_wr(0xd0000, 0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
//// 4.	If training is required at another frequency, repeat the operations starting at step (E).
//// [dwc_ddrphy_phyinit_H_readMsgBlock] End of dwc_ddrphy_phyinit_H_readMsgBlock()
//
//
////##############################################################
////
//// 4.3.5(E) Set the PHY input clocks to the desired frequency for pstate 0
////
//// Set the PHY input Dfi Clk to the desired operating frequency associated with the given Pstate. Before proceeding to the next step,
//// the clock should be stable at the new frequency. For more information on clocking requirements, see "Clocks" on page <XXX>.
////
////##############################################################
//
dwc_ddrphy_phyinit_userCustom_E_setDfiClk(0);

//
//// [dwc_ddrphy_phyinit_userCustom_E_setDfiClk] End of dwc_ddrphy_phyinit_userCustom_E_setDfiClk()
//// [dwc_ddrphy_phyinit_D_loadIMEM, 2D] Start of dwc_ddrphy_phyinit_D_loadIMEM (Train2D=1)
//
//
////##############################################################
////
//// (D) Load the 2D IMEM image
////
//// This function loads the training firmware IMEM image into the SRAM.
//// See PhyInit App Note for detailed description and function usage
////
////##############################################################
//
//
// [dwc_ddrphy_phyinit_storeIncvFile] Reading input file: /home/jerry_ku/Project/Development/ast2700dev/ddr45phy_tsmc12/coreConsultant/config3_3.50a/2022-12-12-16-52-55/firmware/Latest/training/ddr4_2d/ddr4_2d_pmu_train_imem.incv

//// 1.	Enable access to the internal CSRs by setting the MicroContMuxSel CSR to 0.
////	   This allows the memory controller unrestricted access to the configuration CSRs.
dwc_ddrphy_apb_wr(0xd0000, 0x0); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
//// [dwc_ddrphy_phyinit_WriteOutMem] STARTING 32bit write. offset 0x50000 size 0x8000
dwc_ddrphy_phyinit_userCustom_D_loadIMEM(1);
//// [dwc_ddrphy_phyinit_WriteOutMem] DONE.  Index 0x8000
//// 2.	Isolate the APB access from the internal CSRs by setting the MicroContMuxSel CSR to 1.
////	  This allows the firmware unrestricted access to the configuration CSRs.
dwc_ddrphy_apb_wr(0xd0000, 0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
//// [dwc_ddrphy_phyinit_D_loadIMEM, 2D] End of dwc_ddrphy_phyinit_D_loadIMEM()
//// [phyinit_F_loadDMEM, 2D] Start of dwc_ddrphy_phyinit_F_loadDMEM (pstate=0, Train2D=1)
//
//
////##############################################################
////
//// 4.3.5(F) Load the 2D DMEM image and write the 2D Message Block parameters for the training firmware
////
//// The procedure is as follows:
////
////##############################################################
//
//
//
//// 1.    Load the firmware DMEM segment to initialize the data structures.
//
//// 2.    Write the Firmware Message Block with the required contents detailing the training parameters.
//
// [dwc_ddrphy_phyinit_storeIncvFile] Reading input file: /home/jerry_ku/Project/Development/ast2700dev/ddr45phy_tsmc12/coreConsultant/config3_3.50a/2022-12-12-16-52-55/firmware/Latest/training/ddr4_2d/ddr4_2d_pmu_train_dmem.incv

//// 1.	Enable access to the internal CSRs by setting the MicroContMuxSel CSR to 0.
////	   This allows the memory controller unrestricted access to the configuration CSRs.
dwc_ddrphy_apb_wr(0xd0000, 0x0); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
//// [dwc_ddrphy_phyinit_WriteOutMem] STARTING 32bit write. offset 0x58000 size 0x8000
dwc_ddrphy_phyinit_userCustom_F_loadDMEM(0, 1);
dwc_ddrphy_apb_wr_32b(0x58000, 0x700);
dwc_ddrphy_apb_wr_32b(0x58002, 0xc800000);
dwc_ddrphy_apb_wr_32b(0x58004, 0x0);
dwc_ddrphy_apb_wr_32b(0x58006, 0x10000240);
dwc_ddrphy_apb_wr_32b(0x58008, 0x1);
#if defined(CONFIG_DDR_PHY_TRAINING)
printf("- <DWC_DDRPHY/TRAIN>: Override 2D DMEM image for SequenceCtrl, RX2D_TrainOpt, TX2D_TrainOpt, Delay_Weight2D, and Voltage_Weight2D\n");
//	  uint16_t SequenceCtrl;	 // Byte offset 0x16, CSR Addr 0x5800b, Direction=In
							  // SequenceCtrl[0] = Run DevInit - Device/PHY initialization. Should always be set
							  // SequenceCtrl[5] = Run rd2D - 2d read dqs training
							  // SequenceCtrl[6] = Run wr2D - 2d write dq training
dwc_ddrphy_apb_wr_32b(0x5800a, 0x0610000);

// Redmine 1392: To speed up data collection, set the voltage and delay step size in Rx2D_TrainOpt and Tx2D_TrainOpt to its maximum value.
//	 uint8_t  HdtCtrl;			// Byte offset 0x18, CSR Addr 0x5800c, Direction=In
							  //	0x04 = Maximal debug messages (e.g., Eye contours)
							  //	0x05 = Detailed debug messages (e.g. Eye delays)
							  //	0x0A = Coarse debug messages (e.g. rank information)
							  //	0xC8 = Stage completion
							  //	0xC9 = Assertion messages
							  //	0xFF = Firmware completion messages only
//	 uint8_t  RX2D_TrainOpt;	// Byte offset 0x19, CSR Addr 0x5800c, Direction=In
//	 uint8_t  TX2D_TrainOpt;	// Byte offset 0x1a, CSR Addr 0x5800d, Direction=In
  #ifdef DWC_DEBUG
dwc_ddrphy_apb_wr_32b(0x5800c, 0x001e1e0a);
  #else
dwc_ddrphy_apb_wr_32b(0x5800c, 0x001e1ec8);
  #endif
//	 uint8_t  Delay_Weight2D;	// Byte offset 0x1c, CSR Addr 0x5800e, Direction=In
//	 uint8_t  Voltage_Weight2D; // Byte offset 0x1d, CSR Addr 0x5800e, Direction=In
dwc_ddrphy_apb_wr_32b(0x5800e, 0x8020);
#else
dwc_ddrphy_apb_wr_32b(0x5800a, 0x31f0000);
dwc_ddrphy_apb_wr_32b(0x5800c, 0xc8);
dwc_ddrphy_apb_wr_32b(0x5800e, 0x8020);
#endif
dwc_ddrphy_apb_wr_32b(0x58010, 0x0);
dwc_ddrphy_apb_wr_32b(0x58012, 0x2);
dwc_ddrphy_apb_wr_32b(0x58014, 0x0);
dwc_ddrphy_apb_wr_32b(0x58016, 0x0);
dwc_ddrphy_apb_wr_32b(0x58018, 0x0);
dwc_ddrphy_apb_wr_32b(0x5801a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5801c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5801e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58020, 0x0);
dwc_ddrphy_apb_wr_32b(0x58022, 0x0);
dwc_ddrphy_apb_wr_32b(0x58024, 0x0);
dwc_ddrphy_apb_wr_32b(0x58026, 0x0);
dwc_ddrphy_apb_wr_32b(0x58028, 0x0);
dwc_ddrphy_apb_wr_32b(0x5802a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5802c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5802e, 0x21500000);
dwc_ddrphy_apb_wr_32b(0x58030, 0x2280101);
dwc_ddrphy_apb_wr_32b(0x58032, 0x400);
dwc_ddrphy_apb_wr_32b(0x58034, 0x104f0500);
dwc_ddrphy_apb_wr_32b(0x58036, 0x0);
dwc_ddrphy_apb_wr_32b(0x58038, 0x0);
dwc_ddrphy_apb_wr_32b(0x5803a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5803c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5803e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58040, 0x0);
dwc_ddrphy_apb_wr_32b(0x58042, 0xf0f0000);
dwc_ddrphy_apb_wr_32b(0x58044, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58046, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58048, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x5804a, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x5804c, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x5804e, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58050, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58052, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58054, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58056, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58058, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x5805a, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x5805c, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x5805e, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58060, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58062, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58064, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58066, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x58068, 0xf0f0f0f);
dwc_ddrphy_apb_wr_32b(0x5806a, 0xf0f);
dwc_ddrphy_apb_wr_32b(0x5806c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5806e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58070, 0x0);
dwc_ddrphy_apb_wr_32b(0x58072, 0x0);
dwc_ddrphy_apb_wr_32b(0x58074, 0x0);
dwc_ddrphy_apb_wr_32b(0x58076, 0x0);
dwc_ddrphy_apb_wr_32b(0x58078, 0x0);
dwc_ddrphy_apb_wr_32b(0x5807a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5807c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5807e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58080, 0x0);
dwc_ddrphy_apb_wr_32b(0x58082, 0x0);
dwc_ddrphy_apb_wr_32b(0x58084, 0x0);
dwc_ddrphy_apb_wr_32b(0x58086, 0x0);
dwc_ddrphy_apb_wr_32b(0x58088, 0x0);
dwc_ddrphy_apb_wr_32b(0x5808a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5808c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5808e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58090, 0x0);
dwc_ddrphy_apb_wr_32b(0x58092, 0x0);
dwc_ddrphy_apb_wr_32b(0x58094, 0x0);
dwc_ddrphy_apb_wr_32b(0x58096, 0x0);
dwc_ddrphy_apb_wr_32b(0x58098, 0x0);
dwc_ddrphy_apb_wr_32b(0x5809a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5809c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5809e, 0x0);
dwc_ddrphy_apb_wr_32b(0x580a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x580a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x580a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x580a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x580a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x580aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x580b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x580b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x580b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x580b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x580b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x580bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x580be, 0x0);
dwc_ddrphy_apb_wr_32b(0x580c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x580c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x580c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x580c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x580c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x580cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x580d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x580d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x580d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x580d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x580d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x580da, 0x0);
dwc_ddrphy_apb_wr_32b(0x580dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x580de, 0x0);
dwc_ddrphy_apb_wr_32b(0x580e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x580e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x580e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x580e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x580e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x580ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x580f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x580f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x580f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x580f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x580f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x580fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x580fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x580fe, 0x0);
dwc_ddrphy_apb_wr_32b(0x58100, 0x0);
dwc_ddrphy_apb_wr_32b(0x58102, 0x0);
dwc_ddrphy_apb_wr_32b(0x58104, 0x0);
dwc_ddrphy_apb_wr_32b(0x58106, 0x0);
dwc_ddrphy_apb_wr_32b(0x58108, 0x0);
dwc_ddrphy_apb_wr_32b(0x5810a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5810c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5810e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58110, 0x0);
dwc_ddrphy_apb_wr_32b(0x58112, 0x0);
dwc_ddrphy_apb_wr_32b(0x58114, 0x0);
dwc_ddrphy_apb_wr_32b(0x58116, 0x0);
dwc_ddrphy_apb_wr_32b(0x58118, 0x0);
dwc_ddrphy_apb_wr_32b(0x5811a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5811c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5811e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58120, 0x0);
dwc_ddrphy_apb_wr_32b(0x58122, 0x0);
dwc_ddrphy_apb_wr_32b(0x58124, 0x0);
dwc_ddrphy_apb_wr_32b(0x58126, 0x0);
dwc_ddrphy_apb_wr_32b(0x58128, 0x0);
dwc_ddrphy_apb_wr_32b(0x5812a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5812c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5812e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58130, 0x0);
dwc_ddrphy_apb_wr_32b(0x58132, 0x0);
dwc_ddrphy_apb_wr_32b(0x58134, 0x0);
dwc_ddrphy_apb_wr_32b(0x58136, 0x0);
dwc_ddrphy_apb_wr_32b(0x58138, 0x0);
dwc_ddrphy_apb_wr_32b(0x5813a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5813c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5813e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58140, 0x0);
dwc_ddrphy_apb_wr_32b(0x58142, 0x0);
dwc_ddrphy_apb_wr_32b(0x58144, 0x0);
dwc_ddrphy_apb_wr_32b(0x58146, 0x0);
dwc_ddrphy_apb_wr_32b(0x58148, 0x0);
dwc_ddrphy_apb_wr_32b(0x5814a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5814c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5814e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58150, 0x0);
dwc_ddrphy_apb_wr_32b(0x58152, 0x0);
dwc_ddrphy_apb_wr_32b(0x58154, 0x0);
dwc_ddrphy_apb_wr_32b(0x58156, 0x0);
dwc_ddrphy_apb_wr_32b(0x58158, 0x0);
dwc_ddrphy_apb_wr_32b(0x5815a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5815c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5815e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58160, 0x0);
dwc_ddrphy_apb_wr_32b(0x58162, 0x0);
dwc_ddrphy_apb_wr_32b(0x58164, 0x0);
dwc_ddrphy_apb_wr_32b(0x58166, 0x0);
dwc_ddrphy_apb_wr_32b(0x58168, 0x0);
dwc_ddrphy_apb_wr_32b(0x5816a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5816c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5816e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58170, 0x0);
dwc_ddrphy_apb_wr_32b(0x58172, 0x0);
dwc_ddrphy_apb_wr_32b(0x58174, 0x0);
dwc_ddrphy_apb_wr_32b(0x58176, 0x0);
dwc_ddrphy_apb_wr_32b(0x58178, 0x0);
dwc_ddrphy_apb_wr_32b(0x5817a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5817c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5817e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58180, 0x0);
dwc_ddrphy_apb_wr_32b(0x58182, 0x0);
dwc_ddrphy_apb_wr_32b(0x58184, 0x0);
dwc_ddrphy_apb_wr_32b(0x58186, 0x0);
dwc_ddrphy_apb_wr_32b(0x58188, 0x0);
dwc_ddrphy_apb_wr_32b(0x5818a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5818c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5818e, 0x0);
dwc_ddrphy_apb_wr_32b(0x58190, 0x0);
dwc_ddrphy_apb_wr_32b(0x58192, 0x0);
dwc_ddrphy_apb_wr_32b(0x58194, 0x0);
dwc_ddrphy_apb_wr_32b(0x58196, 0x0);
dwc_ddrphy_apb_wr_32b(0x58198, 0x0);
dwc_ddrphy_apb_wr_32b(0x5819a, 0x0);
dwc_ddrphy_apb_wr_32b(0x5819c, 0x0);
dwc_ddrphy_apb_wr_32b(0x5819e, 0x0);
dwc_ddrphy_apb_wr_32b(0x581a0, 0x0);
dwc_ddrphy_apb_wr_32b(0x581a2, 0x0);
dwc_ddrphy_apb_wr_32b(0x581a4, 0x0);
dwc_ddrphy_apb_wr_32b(0x581a6, 0x0);
dwc_ddrphy_apb_wr_32b(0x581a8, 0x0);
dwc_ddrphy_apb_wr_32b(0x581aa, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ac, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ae, 0x0);
dwc_ddrphy_apb_wr_32b(0x581b0, 0x0);
dwc_ddrphy_apb_wr_32b(0x581b2, 0x0);
dwc_ddrphy_apb_wr_32b(0x581b4, 0x0);
dwc_ddrphy_apb_wr_32b(0x581b6, 0x0);
dwc_ddrphy_apb_wr_32b(0x581b8, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ba, 0x0);
dwc_ddrphy_apb_wr_32b(0x581bc, 0x0);
dwc_ddrphy_apb_wr_32b(0x581be, 0x0);
dwc_ddrphy_apb_wr_32b(0x581c0, 0x0);
dwc_ddrphy_apb_wr_32b(0x581c2, 0x0);
dwc_ddrphy_apb_wr_32b(0x581c4, 0x0);
dwc_ddrphy_apb_wr_32b(0x581c6, 0x0);
dwc_ddrphy_apb_wr_32b(0x581c8, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ca, 0x0);
dwc_ddrphy_apb_wr_32b(0x581cc, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ce, 0x0);
dwc_ddrphy_apb_wr_32b(0x581d0, 0x0);
dwc_ddrphy_apb_wr_32b(0x581d2, 0x0);
dwc_ddrphy_apb_wr_32b(0x581d4, 0x0);
dwc_ddrphy_apb_wr_32b(0x581d6, 0x0);
dwc_ddrphy_apb_wr_32b(0x581d8, 0x0);
dwc_ddrphy_apb_wr_32b(0x581da, 0x0);
dwc_ddrphy_apb_wr_32b(0x581dc, 0x0);
dwc_ddrphy_apb_wr_32b(0x581de, 0x0);
dwc_ddrphy_apb_wr_32b(0x581e0, 0x0);
dwc_ddrphy_apb_wr_32b(0x581e2, 0x0);
dwc_ddrphy_apb_wr_32b(0x581e4, 0x0);
dwc_ddrphy_apb_wr_32b(0x581e6, 0x0);
dwc_ddrphy_apb_wr_32b(0x581e8, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ea, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ec, 0x0);
dwc_ddrphy_apb_wr_32b(0x581ee, 0x0);
dwc_ddrphy_apb_wr_32b(0x581f0, 0x0);
dwc_ddrphy_apb_wr_32b(0x581f2, 0x0);
dwc_ddrphy_apb_wr_32b(0x581f4, 0x0);
dwc_ddrphy_apb_wr_32b(0x581f6, 0x0);
dwc_ddrphy_apb_wr_32b(0x581f8, 0x0);
dwc_ddrphy_apb_wr_32b(0x581fa, 0x0);
dwc_ddrphy_apb_wr_32b(0x581fc, 0x0);
dwc_ddrphy_apb_wr_32b(0x581fe, 0x0);
//// [dwc_ddrphy_phyinit_WriteOutMem] DONE.  Index 0x8000
//// 2.	Isolate the APB access from the internal CSRs by setting the MicroContMuxSel CSR to 1.
////	  This allows the firmware unrestricted access to the configuration CSRs.
dwc_ddrphy_apb_wr(0xd0000, 0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
//// [phyinit_F_loadDMEM, 2D] End of dwc_ddrphy_phyinit_F_loadDMEM()
//
//
////##############################################################
////
//// 4.3.7(G) Execute the Training Firmware
////
//// The training firmware is executed with the following procedure:
////
////##############################################################
//
//
//// 1.  Reset the firmware microcontroller by writing the MicroReset CSR to set the StallToMicro and
////	 ResetToMicro fields to 1 (all other fields should be zero).
////	 Then rewrite the CSR so that only the StallToMicro remains set (all other fields should be zero).
dwc_ddrphy_apb_wr(0xd0000, 0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
dwc_ddrphy_apb_wr(0xd0099, 0x9); // DWC_DDRPHYA_APBONLY0_MicroReset
dwc_ddrphy_apb_wr(0xd0099, 0x1); // DWC_DDRPHYA_APBONLY0_MicroReset
//
//// 2. Begin execution of the training firmware by setting the MicroReset CSR to 4'b0000.
dwc_ddrphy_apb_wr(0xd0099, 0x0); // DWC_DDRPHYA_APBONLY0_MicroReset
//
//// 3.   Wait for the training firmware to complete by following the procedure in "uCtrl Initialization and Mailbox Messaging"
//// 4.3.7	3.	 Wait for the training firmware to complete.  Implement timeout function or follow the procedure in "3.4 Running the firmware" of the Training Firmware Application Note to poll the Mailbox message.
dwc_ddrphy_phyinit_userCustom_G_waitFwDone();

//// [dwc_ddrphy_phyinit_userCustom_G_waitFwDone] End of dwc_ddrphy_phyinit_userCustom_G_waitFwDone()
//// 4.   Halt the microcontroller."
dwc_ddrphy_apb_wr(0xd0099, 0x1); // DWC_DDRPHYA_APBONLY0_MicroReset
dwc_ddrphy_apb_wr(0x20089, 0x0); // DWC_DDRPHYA_MASTER0_base0_CalZap
//// [dwc_ddrphy_phyinit_G_execFW] End of dwc_ddrphy_phyinit_G_execFW()
//
//
////##############################################################
////
//// 4.3.8(H) Read the Message Block results
////
//// The procedure is as follows:
////
////##############################################################
//
//
//// 1.	Enable access to the internal CSRs by setting the MicroContMuxSel CSR to 0.
dwc_ddrphy_apb_wr(0xd0000, 0x0); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
//
//2. Read the Firmware Message Block to obtain the results from the training.
//This can be accomplished by issuing APB read commands to the DMEM addresses.
//Example:
//if (Train2D)
//{
//	_read_2d_message_block_outputs_
//}
//else
//{
//	_read_1d_message_block_outputs_
//}
//This can be accomplished by issuing APB read commands to the DMEM addresses.
dwc_ddrphy_phyinit_userCustom_H_readMsgBlock(1);

//[dwc_ddrphy_phyinit_userCustom_H_readMsgBlock] End of dwc_ddrphy_phyinit_userCustom_H_readMsgBlock()
//// 3.	Isolate the APB access from the internal CSRs by setting the MicroContMuxSel CSR to 1.
dwc_ddrphy_apb_wr(0xd0000, 0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
//// 4.	If training is required at another frequency, repeat the operations starting at step (E).
//// [dwc_ddrphy_phyinit_H_readMsgBlock] End of dwc_ddrphy_phyinit_H_readMsgBlock()
//// [initRuntimeConfigEnableBits] Start of initRuntimeConfigEnableBits()
//// [initRuntimeConfigEnableBits] enableBits[0] = 0x00000009
//// [initRuntimeConfigEnableBits] WR_RD_RTT_PARK_A0 = 0x000000ff, rtt_required = 0x0000000f
//// [initRuntimeConfigEnableBits] WR_RD_RTT_PARK_A1 = 0x000000ff, rtt_required = 0x0000000f
//// [initRuntimeConfigEnableBits] WR_RD_RTT_PARK_A2 = 0x000000ff, rtt_required = 0x0000000f
//// [initRuntimeConfigEnableBits] WR_RD_RTT_PARK_A3 = 0x000000ff, rtt_required = 0x0000000f
//// [initRuntimeConfigEnableBits] enableBits[1] = 0x00000000
//// [initRuntimeConfigEnableBits] WR_RD_RTT_PARK_B0 = 0x000000ff, rtt_required = 0x0000000f
//// [initRuntimeConfigEnableBits] WR_RD_RTT_PARK_B1 = 0x000000ff, rtt_required = 0x0000000f
//// [initRuntimeConfigEnableBits] WR_RD_RTT_PARK_B2 = 0x000000ff, rtt_required = 0x0000000f
//// [initRuntimeConfigEnableBits] WR_RD_RTT_PARK_B3 = 0x000000ff, rtt_required = 0x0000000f
//// [initRuntimeConfigEnableBits] enableBits[2] = 0x00000000
//// [initRuntimeConfigEnableBits] End of initRuntimeConfigEnableBits()
//// [phyinit_I_loadPIEImage] Start of dwc_ddrphy_phyinit_I_loadPIEImage()
//
//
////##############################################################
////
//// 4.3.9(I) Load PHY Init Engine Image
////
//// Load the PHY Initialization Engine memory with the provided initialization sequence.
////
////##############################################################
//
//
//// Enable access to the internal CSRs by setting the MicroContMuxSel CSR to 0.
//// This allows the memory controller unrestricted access to the configuration CSRs.
dwc_ddrphy_apb_wr(0xd0000, 0x0); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
//// [phyinit_I_loadPIEImage] Programming ForceClkGaterEnables::ForcePubDxClkEnLow to 0x1
dwc_ddrphy_apb_wr(0x200a6, 0x2); // DWC_DDRPHYA_MASTER0_base0_ForceClkGaterEnables
//// [phyinit_I_loadPIEImage] Programming PIE Production Code
//// [phyinit_LoadPIECodeSections] Start of dwc_ddrphy_phyinit_LoadPIECodeSections()
//// [phyinit_LoadPIECodeSections] Moving start address from 0 to 90000
dwc_ddrphy_apb_wr(0x90000, 0x10); // DWC_DDRPHYA_INITENG0_base0_PreSequenceReg0b0s0
dwc_ddrphy_apb_wr(0x90001, 0x400); // DWC_DDRPHYA_INITENG0_base0_PreSequenceReg0b0s1
dwc_ddrphy_apb_wr(0x90002, 0x10e); // DWC_DDRPHYA_INITENG0_base0_PreSequenceReg0b0s2
dwc_ddrphy_apb_wr(0x90003, 0x0); // DWC_DDRPHYA_INITENG0_base0_PreSequenceReg0b1s0
dwc_ddrphy_apb_wr(0x90004, 0x0); // DWC_DDRPHYA_INITENG0_base0_PreSequenceReg0b1s1
dwc_ddrphy_apb_wr(0x90005, 0x8); // DWC_DDRPHYA_INITENG0_base0_PreSequenceReg0b1s2
//// [phyinit_LoadPIECodeSections] Moving start address from 90006 to 90029
dwc_ddrphy_apb_wr(0x90029, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b0s0
dwc_ddrphy_apb_wr(0x9002a, 0x4); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b0s1
dwc_ddrphy_apb_wr(0x9002b, 0x18); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b0s2
dwc_ddrphy_apb_wr(0x9002c, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b1s0
dwc_ddrphy_apb_wr(0x9002d, 0x4); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b1s1
dwc_ddrphy_apb_wr(0x9002e, 0x18); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b1s2
dwc_ddrphy_apb_wr(0x9002f, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b2s0
dwc_ddrphy_apb_wr(0x90030, 0x4); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b2s1
dwc_ddrphy_apb_wr(0x90031, 0x18); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b2s2
dwc_ddrphy_apb_wr(0x90032, 0xb); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b3s0
dwc_ddrphy_apb_wr(0x90033, 0x480); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b3s1
dwc_ddrphy_apb_wr(0x90034, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b3s2
dwc_ddrphy_apb_wr(0x90035, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b4s0
dwc_ddrphy_apb_wr(0x90036, 0x448); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b4s1
dwc_ddrphy_apb_wr(0x90037, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b4s2
dwc_ddrphy_apb_wr(0x90038, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b5s0
dwc_ddrphy_apb_wr(0x90039, 0x478); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b5s1
dwc_ddrphy_apb_wr(0x9003a, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b5s2
dwc_ddrphy_apb_wr(0x9003b, 0x2); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b6s0
dwc_ddrphy_apb_wr(0x9003c, 0x10); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b6s1
dwc_ddrphy_apb_wr(0x9003d, 0x139); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b6s2
dwc_ddrphy_apb_wr(0x9003e, 0xf); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b7s0
dwc_ddrphy_apb_wr(0x9003f, 0x7c0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b7s1
dwc_ddrphy_apb_wr(0x90040, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b7s2
dwc_ddrphy_apb_wr(0x90041, 0x107); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b8s0
dwc_ddrphy_apb_wr(0x90042, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b8s1
dwc_ddrphy_apb_wr(0x90043, 0x159); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b8s2
dwc_ddrphy_apb_wr(0x90044, 0x18); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b9s0
dwc_ddrphy_apb_wr(0x90045, 0xe0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b9s1
dwc_ddrphy_apb_wr(0x90046, 0x139); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b9s2
dwc_ddrphy_apb_wr(0x90047, 0x147); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b10s0
dwc_ddrphy_apb_wr(0x90048, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b10s1
dwc_ddrphy_apb_wr(0x90049, 0x159); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b10s2
dwc_ddrphy_apb_wr(0x9004a, 0x14f); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b11s0
dwc_ddrphy_apb_wr(0x9004b, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b11s1
dwc_ddrphy_apb_wr(0x9004c, 0x159); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b11s2
dwc_ddrphy_apb_wr(0x9004d, 0x7); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b12s0
dwc_ddrphy_apb_wr(0x9004e, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b12s1
dwc_ddrphy_apb_wr(0x9004f, 0x149); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b12s2
dwc_ddrphy_apb_wr(0x90050, 0x47); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b13s0
dwc_ddrphy_apb_wr(0x90051, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b13s1
dwc_ddrphy_apb_wr(0x90052, 0x149); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b13s2
dwc_ddrphy_apb_wr(0x90053, 0x4f); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b14s0
dwc_ddrphy_apb_wr(0x90054, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b14s1
dwc_ddrphy_apb_wr(0x90055, 0x179); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b14s2
dwc_ddrphy_apb_wr(0x90056, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b15s0
dwc_ddrphy_apb_wr(0x90057, 0x7c8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b15s1
dwc_ddrphy_apb_wr(0x90058, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b15s2
dwc_ddrphy_apb_wr(0x90059, 0x11); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b16s0
dwc_ddrphy_apb_wr(0x9005a, 0x530); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b16s1
dwc_ddrphy_apb_wr(0x9005b, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b16s2
dwc_ddrphy_apb_wr(0x9005c, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b17s0
dwc_ddrphy_apb_wr(0x9005d, 0x1); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b17s1
dwc_ddrphy_apb_wr(0x9005e, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b17s2
dwc_ddrphy_apb_wr(0x9005f, 0x14f); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b18s0
dwc_ddrphy_apb_wr(0x90060, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b18s1
dwc_ddrphy_apb_wr(0x90061, 0x159); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b18s2
dwc_ddrphy_apb_wr(0x90062, 0x2); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b19s0
dwc_ddrphy_apb_wr(0x90063, 0x45a); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b19s1
dwc_ddrphy_apb_wr(0x90064, 0x9); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b19s2
dwc_ddrphy_apb_wr(0x90065, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b20s0
dwc_ddrphy_apb_wr(0x90066, 0x530); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b20s1
dwc_ddrphy_apb_wr(0x90067, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b20s2
dwc_ddrphy_apb_wr(0x90068, 0x18); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b21s0
dwc_ddrphy_apb_wr(0x90069, 0x65a); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b21s1
dwc_ddrphy_apb_wr(0x9006a, 0x9); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b21s2
dwc_ddrphy_apb_wr(0x9006b, 0x41); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b22s0
dwc_ddrphy_apb_wr(0x9006c, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b22s1
dwc_ddrphy_apb_wr(0x9006d, 0x179); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b22s2
dwc_ddrphy_apb_wr(0x9006e, 0x1); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b23s0
dwc_ddrphy_apb_wr(0x9006f, 0x618); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b23s1
dwc_ddrphy_apb_wr(0x90070, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b23s2
dwc_ddrphy_apb_wr(0x90071, 0x40c0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b24s0
dwc_ddrphy_apb_wr(0x90072, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b24s1
dwc_ddrphy_apb_wr(0x90073, 0x149); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b24s2
dwc_ddrphy_apb_wr(0x90074, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b25s0
dwc_ddrphy_apb_wr(0x90075, 0x4); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b25s1
dwc_ddrphy_apb_wr(0x90076, 0x48); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b25s2
dwc_ddrphy_apb_wr(0x90077, 0x4040); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b26s0
dwc_ddrphy_apb_wr(0x90078, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b26s1
dwc_ddrphy_apb_wr(0x90079, 0x149); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b26s2
dwc_ddrphy_apb_wr(0x9007a, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b27s0
dwc_ddrphy_apb_wr(0x9007b, 0x4); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b27s1
dwc_ddrphy_apb_wr(0x9007c, 0x48); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b27s2
dwc_ddrphy_apb_wr(0x9007d, 0x40); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b28s0
dwc_ddrphy_apb_wr(0x9007e, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b28s1
dwc_ddrphy_apb_wr(0x9007f, 0x149); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b28s2
dwc_ddrphy_apb_wr(0x90080, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b29s0
dwc_ddrphy_apb_wr(0x90081, 0x658); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b29s1
dwc_ddrphy_apb_wr(0x90082, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b29s2
dwc_ddrphy_apb_wr(0x90083, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b30s0
dwc_ddrphy_apb_wr(0x90084, 0x4); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b30s1
dwc_ddrphy_apb_wr(0x90085, 0x18); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b30s2
dwc_ddrphy_apb_wr(0x90086, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b31s0
dwc_ddrphy_apb_wr(0x90087, 0x4); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b31s1
dwc_ddrphy_apb_wr(0x90088, 0x78); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b31s2
dwc_ddrphy_apb_wr(0x90089, 0x549); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b32s0
dwc_ddrphy_apb_wr(0x9008a, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b32s1
dwc_ddrphy_apb_wr(0x9008b, 0x159); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b32s2
dwc_ddrphy_apb_wr(0x9008c, 0xd49); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b33s0
dwc_ddrphy_apb_wr(0x9008d, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b33s1
dwc_ddrphy_apb_wr(0x9008e, 0x159); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b33s2
dwc_ddrphy_apb_wr(0x9008f, 0x94c); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b34s0
dwc_ddrphy_apb_wr(0x90090, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b34s1
dwc_ddrphy_apb_wr(0x90091, 0x159); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b34s2
dwc_ddrphy_apb_wr(0x90092, 0x94c); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b35s0
dwc_ddrphy_apb_wr(0x90093, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b35s1
dwc_ddrphy_apb_wr(0x90094, 0x159); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b35s2
dwc_ddrphy_apb_wr(0x90095, 0x442); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b36s0
dwc_ddrphy_apb_wr(0x90096, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b36s1
dwc_ddrphy_apb_wr(0x90097, 0x149); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b36s2
dwc_ddrphy_apb_wr(0x90098, 0x42); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b37s0
dwc_ddrphy_apb_wr(0x90099, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b37s1
dwc_ddrphy_apb_wr(0x9009a, 0x149); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b37s2
dwc_ddrphy_apb_wr(0x9009b, 0x1); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b38s0
dwc_ddrphy_apb_wr(0x9009c, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b38s1
dwc_ddrphy_apb_wr(0x9009d, 0x149); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b38s2
dwc_ddrphy_apb_wr(0x9009e, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b39s0
dwc_ddrphy_apb_wr(0x9009f, 0xe0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b39s1
dwc_ddrphy_apb_wr(0x900a0, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b39s2
dwc_ddrphy_apb_wr(0x900a1, 0xa); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b40s0
dwc_ddrphy_apb_wr(0x900a2, 0x10); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b40s1
dwc_ddrphy_apb_wr(0x900a3, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b40s2
dwc_ddrphy_apb_wr(0x900a4, 0x9); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b41s0
dwc_ddrphy_apb_wr(0x900a5, 0x3c0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b41s1
dwc_ddrphy_apb_wr(0x900a6, 0x149); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b41s2
dwc_ddrphy_apb_wr(0x900a7, 0x9); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b42s0
dwc_ddrphy_apb_wr(0x900a8, 0x3c0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b42s1
dwc_ddrphy_apb_wr(0x900a9, 0x159); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b42s2
dwc_ddrphy_apb_wr(0x900aa, 0x18); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b43s0
dwc_ddrphy_apb_wr(0x900ab, 0x10); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b43s1
dwc_ddrphy_apb_wr(0x900ac, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b43s2
dwc_ddrphy_apb_wr(0x900ad, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b44s0
dwc_ddrphy_apb_wr(0x900ae, 0x3c0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b44s1
dwc_ddrphy_apb_wr(0x900af, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b44s2
dwc_ddrphy_apb_wr(0x900b0, 0x18); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b45s0
dwc_ddrphy_apb_wr(0x900b1, 0x4); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b45s1
dwc_ddrphy_apb_wr(0x900b2, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b45s2
dwc_ddrphy_apb_wr(0x900b3, 0xc); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b46s0
dwc_ddrphy_apb_wr(0x900b4, 0x10); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b46s1
dwc_ddrphy_apb_wr(0x900b5, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b46s2
dwc_ddrphy_apb_wr(0x900b6, 0x3); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b47s0
dwc_ddrphy_apb_wr(0x900b7, 0x10); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b47s1
dwc_ddrphy_apb_wr(0x900b8, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b47s2
dwc_ddrphy_apb_wr(0x900b9, 0x7); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b48s0
dwc_ddrphy_apb_wr(0x900ba, 0x7c0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b48s1
dwc_ddrphy_apb_wr(0x900bb, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b48s2
//// [phyinit_LoadPIECodeSections] Matched ANY enable_bits = 8, type = 0
dwc_ddrphy_apb_wr(0x900bc, 0x3a); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b49s0
dwc_ddrphy_apb_wr(0x900bd, 0x1e2); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b49s1
dwc_ddrphy_apb_wr(0x900be, 0x9); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b49s2
dwc_ddrphy_apb_wr(0x900bf, 0x10); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b50s0
dwc_ddrphy_apb_wr(0x900c0, 0x10); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b50s1
dwc_ddrphy_apb_wr(0x900c1, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b50s2
dwc_ddrphy_apb_wr(0x900c2, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b51s0
dwc_ddrphy_apb_wr(0x900c3, 0x8140); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b51s1
dwc_ddrphy_apb_wr(0x900c4, 0x10c); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b51s2
dwc_ddrphy_apb_wr(0x900c5, 0x10); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b52s0
dwc_ddrphy_apb_wr(0x900c6, 0x8138); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b52s1
dwc_ddrphy_apb_wr(0x900c7, 0x10c); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b52s2
//// [phyinit_LoadPIECodeSections] Matched ANY enable_bits = 1, type = 0
dwc_ddrphy_apb_wr(0x900c8, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b53s0
dwc_ddrphy_apb_wr(0x900c9, 0x400); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b53s1
dwc_ddrphy_apb_wr(0x900ca, 0x10e); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b53s2
dwc_ddrphy_apb_wr(0x900cb, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b54s0
dwc_ddrphy_apb_wr(0x900cc, 0x448); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b54s1
dwc_ddrphy_apb_wr(0x900cd, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b54s2
dwc_ddrphy_apb_wr(0x900ce, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b55s0
dwc_ddrphy_apb_wr(0x900cf, 0x7c8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b55s1
dwc_ddrphy_apb_wr(0x900d0, 0x101); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b55s2
dwc_ddrphy_apb_wr(0x900d1, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b56s0
dwc_ddrphy_apb_wr(0x900d2, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b56s1
dwc_ddrphy_apb_wr(0x900d3, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b56s2
dwc_ddrphy_apb_wr(0x900d4, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b57s0
dwc_ddrphy_apb_wr(0x900d5, 0x448); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b57s1
dwc_ddrphy_apb_wr(0x900d6, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b57s2
dwc_ddrphy_apb_wr(0x900d7, 0xf); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b58s0
dwc_ddrphy_apb_wr(0x900d8, 0x7c0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b58s1
dwc_ddrphy_apb_wr(0x900d9, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b58s2
dwc_ddrphy_apb_wr(0x900da, 0x7); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b59s0
dwc_ddrphy_apb_wr(0x900db, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b59s1
dwc_ddrphy_apb_wr(0x900dc, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b59s2
dwc_ddrphy_apb_wr(0x900dd, 0x47); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b60s0
dwc_ddrphy_apb_wr(0x900de, 0x630); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b60s1
dwc_ddrphy_apb_wr(0x900df, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b60s2
dwc_ddrphy_apb_wr(0x900e0, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b61s0
dwc_ddrphy_apb_wr(0x900e1, 0x618); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b61s1
dwc_ddrphy_apb_wr(0x900e2, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b61s2
dwc_ddrphy_apb_wr(0x900e3, 0x18); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b62s0
dwc_ddrphy_apb_wr(0x900e4, 0xe0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b62s1
dwc_ddrphy_apb_wr(0x900e5, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b62s2
dwc_ddrphy_apb_wr(0x900e6, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b63s0
dwc_ddrphy_apb_wr(0x900e7, 0x7c8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b63s1
dwc_ddrphy_apb_wr(0x900e8, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b63s2
dwc_ddrphy_apb_wr(0x900e9, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b64s0
dwc_ddrphy_apb_wr(0x900ea, 0x8140); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b64s1
dwc_ddrphy_apb_wr(0x900eb, 0x10c); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b64s2
dwc_ddrphy_apb_wr(0x900ec, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b65s0
dwc_ddrphy_apb_wr(0x900ed, 0x478); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b65s1
dwc_ddrphy_apb_wr(0x900ee, 0x109); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b65s2
dwc_ddrphy_apb_wr(0x900ef, 0x0); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b66s0
dwc_ddrphy_apb_wr(0x900f0, 0x1); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b66s1
dwc_ddrphy_apb_wr(0x900f1, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b66s2
dwc_ddrphy_apb_wr(0x900f2, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b67s0
dwc_ddrphy_apb_wr(0x900f3, 0x4); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b67s1
dwc_ddrphy_apb_wr(0x900f4, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b67s2
dwc_ddrphy_apb_wr(0x900f5, 0x8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b68s0
dwc_ddrphy_apb_wr(0x900f6, 0x7c8); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b68s1
dwc_ddrphy_apb_wr(0x900f7, 0x101); // DWC_DDRPHYA_INITENG0_base0_SequenceReg0b68s2
//// [phyinit_LoadPIECodeSections] Moving start address from 900f8 to 90006
dwc_ddrphy_apb_wr(0x90006, 0x0); // DWC_DDRPHYA_INITENG0_base0_PostSequenceReg0b0s0
dwc_ddrphy_apb_wr(0x90007, 0x0); // DWC_DDRPHYA_INITENG0_base0_PostSequenceReg0b0s1
dwc_ddrphy_apb_wr(0x90008, 0x8); // DWC_DDRPHYA_INITENG0_base0_PostSequenceReg0b0s2
dwc_ddrphy_apb_wr(0x90009, 0x0); // DWC_DDRPHYA_INITENG0_base0_PostSequenceReg0b1s0
dwc_ddrphy_apb_wr(0x9000a, 0x0); // DWC_DDRPHYA_INITENG0_base0_PostSequenceReg0b1s1
dwc_ddrphy_apb_wr(0x9000b, 0x0); // DWC_DDRPHYA_INITENG0_base0_PostSequenceReg0b1s2
//// [phyinit_LoadPIECodeSections] Moving start address from 9000c to d00e7
dwc_ddrphy_apb_wr(0xd00e7, 0x400); // DWC_DDRPHYA_APBONLY0_SequencerOverride
//// [phyinit_LoadPIECodeSections] End of dwc_ddrphy_phyinit_LoadPIECodeSections()
//seq0b_LoadPstateSeqProductionCode(): ---------------------------------------------------------------------------------------------------
//seq0b_LoadPstateSeqProductionCode(): Programming the 0B sequencer 0b0000 start vector registers with 0.
//seq0b_LoadPstateSeqProductionCode(): Programming the 0B sequencer 0b1111 start vector register with 56.
//seq0b_LoadPstateSeqProductionCode(): ---------------------------------------------------------------------------------------------------
dwc_ddrphy_apb_wr(0x90017, 0x0); // DWC_DDRPHYA_INITENG0_base0_StartVector0b0
dwc_ddrphy_apb_wr(0x90026, 0x38); // DWC_DDRPHYA_INITENG0_base0_StartVector0b15
dwc_ddrphy_apb_wr(0x9000c, 0x0); // DWC_DDRPHYA_INITENG0_base0_Seq0BDisableFlag0
dwc_ddrphy_apb_wr(0x9000d, 0x173); // DWC_DDRPHYA_INITENG0_base0_Seq0BDisableFlag1
dwc_ddrphy_apb_wr(0x9000e, 0x60); // DWC_DDRPHYA_INITENG0_base0_Seq0BDisableFlag2
dwc_ddrphy_apb_wr(0x9000f, 0x6110); // DWC_DDRPHYA_INITENG0_base0_Seq0BDisableFlag3
dwc_ddrphy_apb_wr(0x90010, 0x2152); // DWC_DDRPHYA_INITENG0_base0_Seq0BDisableFlag4
dwc_ddrphy_apb_wr(0x90011, 0xdfbd); // DWC_DDRPHYA_INITENG0_base0_Seq0BDisableFlag5
dwc_ddrphy_apb_wr(0x90012, 0xffff); // DWC_DDRPHYA_INITENG0_base0_Seq0BDisableFlag6
dwc_ddrphy_apb_wr(0x90013, 0x6152); // DWC_DDRPHYA_INITENG0_base0_Seq0BDisableFlag7
//// [phyinit_I_loadPIEImage] Programming D4PowerControl::D4CATxDllLP to 0x1
//// [phyinit_I_loadPIEImage] Programming AcLcdlMasDis to 0xfff
dwc_ddrphy_apb_wr(0x2006d, 0x1); // DWC_DDRPHYA_MASTER0_base0_D4PowerControl
dwc_ddrphy_apb_wr(0x200e8, 0xfff); // DWC_DDRPHYA_MASTER0_base0_AcLcdlMasDis
//// [phyinit_I_loadPIEImage] Turn on calibration and hold idle until dfi_init_start is asserted sequence is triggered.
//// [phyinit_I_loadPIEImage] Programming CalZap to 0x1
//// [phyinit_I_loadPIEImage] Programming CalRate::CalRun to 0x1
//// [phyinit_I_loadPIEImage] Programming CalRate to 0x19
dwc_ddrphy_apb_wr(0x20089, 0x1); // DWC_DDRPHYA_MASTER0_base0_CalZap
dwc_ddrphy_apb_wr(0x20088, 0x19); // DWC_DDRPHYA_MASTER0_base0_CalRate
//// [phyinit_I_loadPIEImage] Programming ForceClkGaterEnables::ForcePubDxClkEnLow to 0x0
dwc_ddrphy_apb_wr(0x200a6, 0x0); // DWC_DDRPHYA_MASTER0_base0_ForceClkGaterEnables
//// Disabling Ucclk (PMU) and Hclk (training hardware)
dwc_ddrphy_apb_wr(0xc0080, 0x0); // DWC_DDRPHYA_DRTUB0_UcclkHclkEnables
//// Isolate the APB access from the internal CSRs by setting the MicroContMuxSel CSR to 1.
dwc_ddrphy_apb_wr(0xd0000, 0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
//// [phyinit_userCustom_wait] Wait 40 DfiClks
//// [phyinit_I_loadPIEImage] End of dwc_ddrphy_phyinit_I_loadPIEImage()
//
//
////##############################################################
////
//// dwc_ddrphy_phyinit_userCustom_customPostTrain is a user-editable function.
////
//// The purpose of dwc_ddrphy_phyinit_userCustom_customPostTrain() is to override any
//// CSR values programmed by the training firmware or dwc_ddrphy_phyinit_progCsrSkipTrain()
//// This function is executed after training
////
//// IMPORTANT: in this function, user shall not override any values in userInputBasic and
//// userInputAdvanced data structures. Only CSR programming should be done in this function.
////
//// Sequence of Events in this function are:
//// 1. Enable APB access.
//// 2. Issue register writes
//// 3. Isolate APB access.
//
////##############################################################
//
dwc_ddrphy_phyinit_userCustom_customPostTrain();

//// [dwc_ddrphy_phyinit_userCustom_customPostTrain] End of dwc_ddrphy_phyinit_userCustom_customPostTrain()
//// [dwc_ddrphy_phyinit_userCustom_J_enterMissionMode] Start of dwc_ddrphy_phyinit_userCustom_J_enterMissionMode()
//
//
////##############################################################
////
//// 4.3.10(J) Initialize the PHY to Mission Mode through DFI Initialization
////
//// Initialize the PHY to mission mode as follows:
////
//// 1. Set the PHY input clocks to the desired frequency.
//// 2. Initialize the PHY to mission mode by performing DFI Initialization.
////	Please see the DFI specification for more information. See the DFI frequency bus encoding in section <XXX>.
//// Note: The PHY training firmware initializes the DRAM state. if skip
//// training is used, the DRAM state is not initialized.
////
////##############################################################
//
dwc_ddrphy_phyinit_userCustom_J_enterMissionMode();

//
//// [dwc_ddrphy_phyinit_userCustom_J_enterMissionMode] End of dwc_ddrphy_phyinit_userCustom_J_enterMissionMode()
// [dwc_ddrphy_phyinit_sequence] End of dwc_ddrphy_phyinit_sequence()
// [dwc_ddrphy_phyinit_main] End of dwc_ddrphy_phyinit_main()
