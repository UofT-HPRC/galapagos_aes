#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/mahdi/finalIPs/finalIPs/dec/dec_prj/solution1/.autopilot/db/a.g.bc ${1+"$@"}
