/*
 * Wrapper.h
 *
 *  Created on: Sep 15, 2017
 *      Author: root
 */

#ifndef WRAPPER_H_
#define WRAPPER_H_
#include "CommonData.pb.h"
#include <string>
#include <sstream>
#include <iostream>
class Wrapper {

public:
	static void wrap(const std::string& data, const uint cond, std::string* value);
};

#endif /* WRAPPER_H_ */
