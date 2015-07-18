# pam_modules_pd

Without this, following error messages are printed to the system error log on a PureDarwin system:

```
Mar 17 16:50:57 VMDarwin com.apple.launchd[1]  
(com.apple.launchd.peruser.1000[95]): Root Mach bootstrap cannot be  
transferred.
Mar 17 16:50:57 VMDarwin login[94]: USER_PROCESS: 94 ttys000
Mar 17 16:50:57 VMDarwin com.apple.launchd[95] (0x1010b0.login[94]):  
Bug: launchd_core_logic.c:6292 (23646):1100: kr == 0
```

Following a [thread](https://lists.macosforge.org/pipermail/launchd-dev/2009-March/000497.html) on the `launchd-dev` mailing list, Stuart Crook wrote this module for PureDarwin following information from Damien Sorresso that "`login` is calling into pam_launchd, which calls into `_vprocmgr_move_subset_to_user()`, and it resides in the root Mach bootstrap, i.e. the bootstrap provided by the PID 1 `launchd`. The SPI is calling `_vprocmgr_move_subset_to_user()` because it moves a bootstrap subset, not a root bootstrap. So have `login` call the Security framework's `SessionCreate()` SPI before calling into `pam_launchd`. That should do the trick."
