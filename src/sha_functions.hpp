/* Copyright 2018 Columbia University SLD Group */

#ifndef __MAC_FUNCTIONS_HPP__
#define __MAC_FUNCTIONS_HPP__

void sha::do_sha(bool ping_pong)
{
    printf("INSIDE DO SHA FUNCTION \n") ;
    for(int i = 0 ; i < 100 ; i ++ ){
        if(ping_pong){
            printf(" %d", in_data_buf_1[i]) ;    
        }
        else{
            printf(" %d", in_data_buf_2[i]) ; 
        }
    }   
    printf("DO SHA FUNCTION DONE \n") ;
}

#endif /* __MAC_FUNCTIONS_HPP__ */