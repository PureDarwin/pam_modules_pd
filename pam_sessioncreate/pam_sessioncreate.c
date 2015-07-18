
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include <Security/AuthSession.h>

#define _PAM_EXTERN_FUNCTIONS
#define PAM_SM_SESSION

#include <pam/pam_modules.h>
#include <pam/pam_mod_misc.h>



PAM_EXTERN int
pam_sm_open_session(pam_handle_t *pamh, int flags, 
					int argc, const char **argv)
{
	
	SessionCreationFlags flgs;
	SessionAttributeBits attbs;

	flgs = 0;	
	attbs = sessionHasTTY;
	
    SessionCreate(flgs, attbs);
 
	return PAM_SUCCESS;
  
}

PAM_EXTERN int 
pam_sm_close_session(pam_handle_t *pamh, int flags, 
					int argc, const char **argv)
{
	return PAM_SUCCESS;
}
