# AES example using Galapagos Framework

This is an example project used to demonstrate the usage of the Galapagos framework.
This project has a heterogeneous system including CPU and FPGA, which uses libGalapagos library and Galapagos Shell, respectively. 
You can find the software project under the `software` folder. 
Re-create the hardware project by going to the `hardware` folder.
In order to create both software and hardware projects, you have to go carefully through the README files provided in those folders. 

# Brief Explanation of AES Project

This project has five kernels. 
The `init_kern` is responsible for initializing the key exchange cores and sending the plain text to the encryption core.
It also gets the deciphered text from the decryption core.
Two cores, `key_core_one` and `key_core_two`, are responsible for generating the AES cores' shared secret.
Two cores, `kern_enc` and `kern_dec`, are AES-128-based HLS cores used to cipher/decipher data.
The first three kernels have been implemented on software, and the enc/dec cores have been developed on FPGA.

For more detailed information about the AES project and its flow, please take a look at https://github.com/EdwinKLee/Encrypted-Inter-FPGA-Data-Stream/blob/main/Report.pdf .

P.S.: This project initially was a course project for ECE 1373 course at UofT. 
However, we found it educational for future developers working with the Galapagos framework.

# Contributors

Primary Contributor: 
- [Mohammadmahdi Mazraeli](https://github.com/mazraeli)

Course-teammate Contributors:
- [Edwin Lee](https://github.com/EdwinKLee)
- [Mahdi Abbaszadeh](https://github.com/mahdi-abbaszadeh)

With the help of:
- [Naif Tarafdar](https://github.com/tarafdar) who developed the Galapagos framework.
- [Qianfeng (Clark) Shen](https://github.com/QianfengClarkShen) who developed the Gulf-Stream UDP bridge.
- [Juan Camilo Vega](https://github.com/juancamilovega)
- Yu Gao
