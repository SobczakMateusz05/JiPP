#pragma once

enum MY_MESSAGES
{
	MY_MESS_MEM_ALOC_ERROR,        //0
	MY_MESS_INCORR_INDEX_WARN,	   //1
	MY_MESS_MEM_ALLOC_NOT_FATAL,   //2
	MY_MESS_TOTAL                  //ZAWSZE OSTATNI !!!
};

void my_mess_fun(enum MY_MESSAGES mess);