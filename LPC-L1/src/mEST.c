/*
===============================================================================
 Name        : INFO2_LIB.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

#include <stdio.h>

#include <xyz_timer.h>

#include <xyz_io.h>

#include <xyz_base.h>

enum {MCIERRE = 1, MAPERT = 2, SENOUT = 1, SENIN = 2, FC_CERR = 3, FC_AB = 4}; //enum basicos
enum {CERRADO = 0, ABRIENDO = 1, ABIERTO = 2, CERRANDO = 3}; //estados
enum {T_APERT, T_ESP}; // timers

#include "inicializar.h"

int main(void)
{
	int estado;

    Inicializar_io();

    InitTimer();

    estado = inicializar();


    while(1)
    {
    	switch(estado){
    	case CERRADO:
    		if(Dig_Inputs(SENOUT) || Dig_Inputs(SENIN)){
    			estado = ABRIENDO;
    			set_timer(T_APERT,3);
    			Relays(MAPERT,ON);
    		}
    		break;

    	case ABRIENDO:
    	    if( !(Dig_Inputs(SENOUT) || Dig_Inputs(SENIN)) && is_timer_end(T_APERT) ){
    	    	estado = CERRANDO;
    	    	Relays(MAPERT,OFF);
    	    	Relays(MCIERRE, ON);
    	    }
    	    if(Teclado(FC_AB)){
    	    	estado = ABIERTO;
    	    	Relays(MAPERT,OFF);
    	    }
    	    break;

    	case CERRANDO:
    		if(Dig_Inputs(SENOUT) || Dig_Inputs(SENIN)){
    			estado = ABRIENDO;
    			set_timer(T_APERT,3);
    			Relays(MAPERT,ON);
    		}
    		if(FC_CERR){
    			estado = CERRADO;
    			Relays(MCIERRE, OFF);
    		}
    		break;

    	case ABIERTO:
    		set_timer(T_ESP,5);
    		if(!(Dig_Inputs(SENOUT) || Dig_Inputs(SENIN)) && is_timer_end(T_ESP)){
    			estado = CERRANDO;
       	    	Relays(MCIERRE, ON);
    		}
    		break;

    	default:
    		estado = inicializar();
    		break;
    	}
    }
    return 0 ;
}

