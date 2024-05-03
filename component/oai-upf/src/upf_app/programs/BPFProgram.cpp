#include "BPFProgram.h"
#include "logger.hpp"

/*****************************************************************************************************************/
u_int32_t BPFProgram::sIdCounter = 1;
BPFProgram::BPFProgram(/* args */) : mId(sIdCounter) {
  sIdCounter++;
  Logger::upf_app().info("BPFProgram %d is created!!!", mId);
}

/*****************************************************************************************************************/
BPFProgram::~BPFProgram() {}

/*****************************************************************************************************************/
uint32_t BPFProgram::getId() const {
  return mId;
}
/*****************************************************************************************************************/