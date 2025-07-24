#pragma once


#define DEBUG

#ifdef DEBUG
#define ERROR std::cout<<"[ERROR]: "<<__FUNCTION__<<": "
#define INFO std::cout<<"[INFO]: "<<__FUNCTION__<<": "
#endif
