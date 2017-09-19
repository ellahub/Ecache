#ifndef ECACHE_H_
#define ECACHE_H_

#include <string>
#include <iostream>
#include <chrono>
#include <vector>

#include <leveldb/db.h>
#include "CommonData.pb.h"

enum EccStatus {
   ECC_OK = 0,
   ECC_FAIL,
   ECC_EXIST,
   ECC_NODB
};

class Ecache {

public:
   static Ecache* instance();
   static void close(void);

   static uint64_t unixtime(std::time_t* t);

   ~Ecache();

   EccStatus open(const std::string& path);
   //API
   EccStatus put(const std::string& key, const std::string& value);
   EccStatus get(const std::string& key, std::string& value);
   EccStatus erase(const std::string& key);
   void select(const uint cond, std::vector<std::string>& result);

   //最后一次操作的状态
   leveldb::Status last() {
      return status_;
   }

   void show();

   std::string stats() {
      std::string file_stats;
      db_->GetProperty("leveldb.stats", &file_stats);

      std::string mem_stats;
      db_->GetProperty("leveldb.approximate-memory-usage", &mem_stats);

      return file_stats + "\n" + mem_stats + "\n";
   }

private:
   static Ecache* instance_;
   static leveldb::DB* db_;

   leveldb::Status status_;
   std::string db_path_;
   leveldb::Options options_;
   leveldb::ReadOptions read_options_;
   leveldb::WriteOptions write_options_;

private:
   //instance
   Ecache();

   //no copying allowed
   Ecache(const Ecache& e) = delete;
   Ecache& operator=(const Ecache& e) = delete;
};
#define ECACHE Ecache::instance()
#endif // ECACHE_H_



