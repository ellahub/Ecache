#include <cassert>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <erl_nif.h>
#include "Ecache.h"
#include "Wrapper.h"
#include "citydata.pb.h"

void open(const std::string& path) {
   EccStatus status = ECACHE->open(path);
   if (status == ECC_OK) {
      std::cout << "open cache ok." << std::endl;
   } else {
      std::cout << "open cache fail." << std::endl;
   }
}

void put(const std::string& key, const std::string& value) {
   leveldb::Status status =  ECACHE->put(key, value);
   //  if (status.ok()) {
   //     std::cout << "put ok." << std::endl;
   //  } else {
   //     std::cout << "put fail:" << status.ToString() << std::endl;
   //  }
}

void get(const std::string& key, std::string& value) {
   leveldb::Status status = ECACHE->get(key, value);
   if (status.ok()) {
      std::cout << "get ok." << std::endl;
   } else {
      std::cout << "get fail:" << status.ToString() << std::endl;
   }
}

void close() {
   ECACHE->close();
}

void show_all() {
   ECACHE->show();
}

void save_pb_data(const std::string& key) {

   std::time_t* t = nullptr;
	std::string value;
	std::string tag("citydata");
	std::string data;
	uint cond = rand() % 100000;

	//encode city
	citydata city;
	std::string city_str;
	city.set_id(1);
	city.set_account("abc");
	city.set_name("abcded");
	city.set_lv(100);
	city.set_create_time((uint32_t)Ecache::unixtime(t));

	city.SerializeToString(&city_str);

	if(city_str.size() > 0) {
		Wrapper::wrap(tag, city_str, cond, &value);
	}

	put(key, value);
}

void load_pb_data(const std::string& key) {
	std::string value;
	get(key, value);

	CommonData wrap_data;
	if (value.size() > 0) {
		wrap_data.ParseFromString(value);
	} else {
      return;
   }

	if(wrap_data.has_tag()) {
		std::cout << "\nproto:" << wrap_data.tag() << std::endl;
	} else {
      return;
   }

   std::string city_str = wrap_data.data();
   citydata city;
   city.ParseFromString(city_str);

   std::cout << "id:" << city.id() << "\n"
      << "name:" << city.name() << "\n"
      << "account:" << city.account() << "\n"
      << "lv:" << city.lv() << "\n"
      << "create_time:" << city.create_time() << std::endl;

   wrap_data.Clear();
   city.Clear();
}

int main() {

   std::stringstream ss;
   open("t_m");

   for (auto i = 1; i < 100000; i++) {
      ss << i;
      save_pb_data("role_" + ss.str());
      ss.clear();
      ss.str("");
   }
//
//   std::string value;
//   get("a1001", value);
//
//   std::cout << "key a's value:" << value << std::endl;
//

   //show_all();


   std::string key = "12345678";
   save_pb_data(key);

   //load_pb_data(key);
   //

   for (auto i = 10; i < 12; i++) {
      ss << i;
      load_pb_data("role_" + ss.str());
      ss.clear();
      ss.str("");
   }

   std::cout << ECACHE->stats() << std::endl;

   //test select
   std::vector<std::string> result;

   ECACHE->select("citydata", 50000, result);

   std::cout << "result size:" << result.size() << std::endl;
   close();
   return 0;
}


