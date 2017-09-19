/*
 * author:atao 1628025718@qq.com
 * */
#include "Ecache.h"

//Init static member vars
Ecache* Ecache::instance_ = 0;
leveldb::DB* Ecache::db_ = 0;


Ecache::Ecache() {
   options_.create_if_missing = true;
}

Ecache::~Ecache() {
   std::cout << "deconstruct Ecache" << std::endl;
   close();
}

Ecache* Ecache::instance() {
   if (!instance_) {
      instance_ = new Ecache;
   }
   return instance_;
}

void Ecache::close() {
   if (db_) {
      delete db_;
   }
   db_ = 0;
}

uint64_t Ecache::unixtime(std::time_t* t) {
   std::time_t st = std::time(t);
   auto milles = static_cast<std::chrono::milliseconds>(st).count();
   auto seconds = static_cast<uint64_t>(milles);
   return seconds;
}

EccStatus Ecache::open(const std::string& path) {
   /*
    * 不允许一个进程启动多个db
    * */
   if (db_)
      return ECC_EXIST;

   db_path_ = path;
   status_ = leveldb::DB::Open(options_, db_path_, &db_);

   if (status_.ok()) 
      return ECC_OK;

   std::cerr << "Open DB:" << path << " exception:" << status_.ToString() << std::endl;
   return ECC_FAIL;
}


EccStatus Ecache::put(const std::string& key, const std::string& value) {
   if (!db_)
      return ECC_NODB;

   status_ = db_->Put(write_options_, key, value);
   return ECC_OK;
}

EccStatus Ecache::get(const std::string& key, std::string& value) {
   if (!db_)
      return ECC_NODB;

   status_ = db_->Get(read_options_, key, &value);

   if (status_.ok())
      return ECC_OK;

   return ECC_FAIL;
}

EccStatus Ecache::erase(const std::string& key) {
   if (!db_)
      return ECC_NODB;

   status_ = db_->Delete(write_options_, key);
   return ECC_OK;
}

void Ecache::show() {
   leveldb::Iterator* it = db_->NewIterator(read_options_);
   for(it->SeekToFirst(); it->Valid(); it->Next()) {
      std::cout << it->key().ToString() << " " << it->value().ToString() << std::endl;
   }
   if (it->status().ok())
      std::cout << "show all ok." << std::endl;

   delete it;
}

//select op
void Ecache::select(const uint cond, std::vector<std::string>& result) {

   CommonData value;
   leveldb::Iterator* it = db_->NewIterator(read_options_);
   for(it->SeekToFirst(); it->Valid(); it->Next()) {
      value.ParseFromString(it->value().ToString());
      if (value.has_cond()) {
         if (value.cond() >= cond) {
           result.push_back(value.data());
         }
      }
      value.Clear();
   }

   delete it;
}
