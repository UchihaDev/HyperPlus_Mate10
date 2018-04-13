# MD5: 53e23a12099fff70976f07cba435e248
CFG_BBP_MASTER_NONE                             := 0
CFG_BBP_MASTER_V8R1                             := 1
CFG_BBP_MASTER_V7R5                             := 2
CFG_BBP_MASTER_V8R5                             := 3
CFG_BBP_MASTER_K3V6                             := 4
CFG_BBP_MASTER_KIRIN970                         := 5
CFG_FEATURE_BBP_MASTER_VER                      := (BBP_MASTER_KIRIN970)
CFG_BBP_MASTER_ES                               := 0
CFG_BBP_MASTER_CS                               := 1
ifeq ($(CFG_CHIP_TYPE_CS),FEATURE_ON)
CFG_BBP_MASTER_CHIP_TYPE                        := BBP_MASTER_CS
else
CFG_BBP_MASTER_CHIP_TYPE                        := BBP_MASTER_ES
endif
CFG_FEATURE_POWER_TIMER                         := FEATURE_ON
CFG_FEATURE_UE_UICC_MULTI_APP_SUPPORT           := FEATURE_ON
CFG_FEATURE_VSIM                                := FEATURE_ON
CFG_FEATURE_GUC_BBP_TRIG                        := FEATURE_ON
CFG_FEATURE_GUC_BBP_TRIG_NEWVERSION             := FEATURE_ON
CFG_FEATURE_GUBBP_HANDSHAKE                     := FEATURE_ON
CFG_FEATURE_GUDRX_NEWVERSION                    := FEATURE_ON
CFG_FEATURE_VOS_REDUCE_MEM_CFG                  := FEATURE_OFF
CFG_FEATURE_RTC_TIMER_DBG                       := FEATURE_ON
CFG_FEATURE_PHONE_SC                            := FEATURE_ON
CFG_FEATURE_SC_SEC_UPDATE                       := FEATURE_ON
CFG_FEATURE_SC_OS_SEC_FILE                      := FEATURE_OFF
CFG_FEATURE_SC_DATA_STRUCT_EXTERN               := FEATURE_OFF
CFG_FEATURE_SC_NETWORK_UPDATE                   := FEATURE_OFF
CFG_FEATURE_VSIM_ICC_SEC_CHANNEL                := FEATURE_ON
CFG_FEATURE_BOSTON_AFTER_FEATURE                := FEATURE_ON
CFG_FEATURE_BOSTON_ONLY_FEATURE                 := FEATURE_ON
