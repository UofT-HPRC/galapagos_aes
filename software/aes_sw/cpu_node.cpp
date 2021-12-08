
#define INTERFACE_100G
#include <string>
#include <math.h>
#include <thread>
#include <chrono>
#include <boost/program_options.hpp>

#include "../util/CommandLine.hpp"
#include "../galapagos_node.hpp"
#include "../galapagos_net_udp.hpp"
#include "kern.hpp"

#define GALAPAGOS_PORT 640 

using namespace boost::program_options;

int main(int argc, char** argv){
    std::string init_kern_ipadd = "10.1.2.101";
    std::string key_core_one_ipadd = "10.1.2.101";
    std::string key_core_two_ipadd = "10.1.2.101";
    std::string kern_enc_ipadd = "10.1.5.8";
    std::string kern_dec_ipadd = "10.1.5.8";
    std::string node_ip_address = "10.1.2.101";

    std::vector <std::string> kern_info;

    kern_info.push_back(init_kern_ipadd);
    kern_info.push_back(key_core_one_ipadd);
    kern_info.push_back(key_core_two_ipadd);
    kern_info.push_back(kern_enc_ipadd);
    kern_info.push_back(kern_dec_ipadd);

    std::vector < galapagos::external_driver<T> * > ext_drivers;
    std::unique_ptr<galapagos::node <T> > node_ptr;
    
    galapagos::net::udp <T> my_udp(
                GALAPAGOS_PORT, 
                kern_info, 
                node_ip_address
            );
    ext_drivers.push_back(&my_udp);
    node_ptr = std::make_unique<galapagos::node <T> >(kern_info, node_ip_address, ext_drivers);


//Adding Kernels    
    if(init_kern_ipadd == node_ip_address){
        node_ptr->add_kernel(0, init_kern);
        std::cout << "adding the 0 kernel" << std::endl;
    }
    if(key_core_one_ipadd == node_ip_address){
        node_ptr->add_kernel(1, key_core_one);
        std::cout << "adding the 1 kernel" << std::endl;
    }
    if(key_core_two_ipadd == node_ip_address){
        node_ptr->add_kernel(2, key_core_two);
        std::cout << "adding the 2 kernel" << std::endl;
    }
    if(kern_enc_ipadd == node_ip_address){
        node_ptr->add_kernel(3, kern_enc);
        std::cout << "adding the 3 kernel" << std::endl;
    }
    if(kern_dec_ipadd == node_ip_address){
        node_ptr->add_kernel(4, kern_dec);
        std::cout << "adding the 4 kernel" << std::endl;
    }

    node_ptr->start();
    node_ptr->end();

}
