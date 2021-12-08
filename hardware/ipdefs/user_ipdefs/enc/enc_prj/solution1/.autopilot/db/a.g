#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/mahdi/finalIPs/finalIPs/enc/enc_prj/solution1/.autopilot/db/a.g.bc ${1+"$@"}
