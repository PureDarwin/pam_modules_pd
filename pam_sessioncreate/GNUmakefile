##
# pam_sessioncreate Makefile
##
# Luke Howard <lukeh@padl.com>
##

PAMModuleName            = pam_sessioncreate

Extra_CC_Flags           = -I/System/Library/Frameworks/Security.framework/PrivateHeaders 
Extra_LD_Flags           = -framework Security -lpam
PAMModuleSources         = pam_sessioncreate.c 

include ../PAMModule.defs
