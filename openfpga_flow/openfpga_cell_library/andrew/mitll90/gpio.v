/**
 * Wrapper module for GPIO pads
 *
 */

`include "/l/research/pdks/MITLL/MITLL90_STDLIB_8T/2019.12.20/MITLL90_STDLIB_8T.v"

/** 
 * Make GPIO pads bidirectional
 */
module GPIO ( 
    inout PAD,  //the physical PAD connection
    input DIR,  // communication direction 1=to_pad, 0=from_pad
    input TO_PAD, //data going from core to pad
    output FROM_PAD //data coming from pad to core
    );
   
    wire DIR_N;
    wire FROM_PAD_N; 
    wire TO_PAD_N;
    wire CORE;

    inv(.A(DIR), .X(DIR_N));
    inv_1x (.A(FROM_PAD_N), .X(FROM_PAD) );
    inv_1x (.A(TO_PAD), .X(TO_PAD_N) );

    tinv_1x tri_from_pad(
        .EN(DIR),
        .A(CORE),
        .X(FROM_PAD_N) 
        );

    tinv_1x tri_to_pad(
        .EN(DIR_N),
        .A(TO_PAD_N),
        .X(CORE)
        );

    pad80_inDig_buf_out_cdm gpio_cell (
        .SEL_OUT(DIR), 
        .SEL_SUBh(1'h1), 
        .CORE(CORE), 
        .PAD(PAD)
        );

endmodule
