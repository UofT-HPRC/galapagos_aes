#include "kern_dec.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void kern_dec::thread_hdltv_gen() {
    const char* dump_tv = std::getenv("AP_WRITE_TV");
    if (!(dump_tv && string(dump_tv) == "on")) return;

    wait();

    mHdltvinHandle << "[ " << endl;
    mHdltvoutHandle << "[ " << endl;
    int ap_cycleNo = 0;
    while (1) {
        wait();
        const char* mComma = ap_cycleNo == 0 ? " " : ", " ;
        mHdltvinHandle << mComma << "{"  <<  " \"ap_rst_n\" :  \"" << ap_rst_n.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"id\" :  \"" << id.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"in_r_TDATA\" :  \"" << in_r_TDATA.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"in_r_TVALID\" :  \"" << in_r_TVALID.read() << "\" ";
        mHdltvoutHandle << mComma << "{"  <<  " \"in_r_TREADY\" :  \"" << in_r_TREADY.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"in_r_TDEST\" :  \"" << in_r_TDEST.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"in_r_TLAST\" :  \"" << in_r_TLAST.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"in_r_TID\" :  \"" << in_r_TID.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"in_r_TUSER\" :  \"" << in_r_TUSER.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"in_r_TKEEP\" :  \"" << in_r_TKEEP.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"out_r_TDATA\" :  \"" << out_r_TDATA.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"out_r_TVALID\" :  \"" << out_r_TVALID.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"out_r_TREADY\" :  \"" << out_r_TREADY.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"out_r_TDEST\" :  \"" << out_r_TDEST.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"out_r_TLAST\" :  \"" << out_r_TLAST.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"out_r_TID\" :  \"" << out_r_TID.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"out_r_TUSER\" :  \"" << out_r_TUSER.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"out_r_TKEEP\" :  \"" << out_r_TKEEP.read() << "\" ";
        mHdltvinHandle << "}" << std::endl;
        mHdltvoutHandle << "}" << std::endl;
        ap_cycleNo++;
    }
}

}

