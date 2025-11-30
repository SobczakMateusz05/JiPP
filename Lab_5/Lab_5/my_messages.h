#pragma once

enum MY_MESSAGES
{
	MY_MESS_MEM_ALOC_ERROR,    //0
	MY_MESS_COS_TAM_WARN,	   //1
	MY_MESS_KOMUNIK_AAAA,      //2
	MY_MESS_TOTAL              //ZAWSZE OSTATNI !!!
};

void my_mess_fun(enum MY_MESSAGES mess);
