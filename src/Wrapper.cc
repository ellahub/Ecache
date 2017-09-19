/*
 * Wrapper.cc
 *
 *  Created on: Sep 15, 2017
 *      Author: root
 */

#include "Wrapper.h"

void Wrapper::wrap(const std::string& tag, const std::string& data, const uint cond, std::string* value) {
	CommonData wrap_data;
	wrap_data.set_tag(tag);
	wrap_data.set_data(data);
	wrap_data.set_cond(cond);

	wrap_data.SerializeToString(value);
}

