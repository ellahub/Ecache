/*
 * author:atao 1628025718@qq.com
 * */
#include <cassert>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <erl_nif.h>
#include "Ecache.h"
#include "Wrapper.h"

// util function
static ERL_NIF_TERM make_atom(ErlNifEnv* env, const char* atom)
{

   ERL_NIF_TERM existing_atom;

   if(enif_make_existing_atom(env, atom, &existing_atom, ERL_NIF_LATIN1))
      return existing_atom;
   return enif_make_atom(env, atom);
}

// nif function
static ERL_NIF_TERM put(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) 
{
   uint size = 0;
   //get key
   const uint key_max_size = 1024;
   char key_buf[key_max_size];
   if ((size = enif_get_string(env, argv[0], key_buf, key_max_size, ERL_NIF_LATIN1)) <= 0) {
      return enif_make_badarg(env);
   }

   std::string key(key_buf, size);

   //get data
   ErlNifBinary bin;
   if (!enif_inspect_binary(env, argv[2], &bin))
      return enif_make_badarg(env);

   //根据bin构造一个string类型
   char* buff = (char*)enif_alloc(bin.size);

   if(!buff)
      return enif_make_badarg(env);
   memcpy(buff, bin.data, bin.size);
   std::string data_str(buff, bin.size);
   enif_free(buff);

   //get cond
   uint64_t cond = 0;
   if (!enif_get_uint64(env, argv[3], &cond)) {
      return enif_make_badarg(env);
   }

   //storage the data
   std::string storage_data;
   Wrapper::wrap(data_str, cond, &storage_data);

   if(ECACHE->put(key, storage_data) == ECC_OK)
      return make_atom(env, "ok");

   return make_atom(env, "false");
}

static ERL_NIF_TERM get(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) 
{

   uint size = 0;
   //get key
   const uint key_max_size = 1024;
   char key_buf[key_max_size];
   if ((size = enif_get_string(env, argv[0], key_buf, key_max_size, ERL_NIF_LATIN1)) <= 0) {
      return enif_make_badarg(env);
   }
   std::string key(key_buf, size);

   //lookup value
   std::string value;
   if (!(ECACHE->get(key, value) == ECC_OK))
      return make_atom(env, "not_find");

   CommonData storage_data;
   storage_data.ParseFromString(value);
   std::string data_str = storage_data.data();

   //using data_str make a binary for return
   ErlNifBinary bin;
   int byteSize = data_str.size();

   if (!enif_alloc_binary(byteSize, &bin)) {
      return enif_make_badarg(env);
   }

   memcpy(bin.data, data_str.data(), byteSize);
   bin.size = byteSize;

   return enif_make_binary(env, &bin);

   //return enif_make_string_len(env, data_str.data(), data_str.size(), ERL_NIF_LATIN1);
}

/*
 * @doc 开启一个leveldb
 * @TODO db的路径不超过1024
 * */
static ERL_NIF_TERM open(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) 
{
   const uint max_size = 1024;
   char buf[max_size];
   uint size = 0;

   if ((size = enif_get_string(env, argv[0], buf, max_size, ERL_NIF_LATIN1)) > 0 && size <= max_size) {
      std::string path(buf);
      if( ECACHE->open(path) == ECC_OK) {
         return make_atom(env, "ok");
      }

      return make_atom(env, "false");
   } else {
      return enif_make_badarg(env);
   }
}

static ERL_NIF_TERM close(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) 
{
   Ecache::close();
   return make_atom(env, "ok");
}

static ERL_NIF_TERM erase(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
   uint size = 0;
   //get key
   const uint key_max_size = 1024;
   char key_buf[key_max_size];
   if ((size = enif_get_string(env, argv[0], key_buf, key_max_size, ERL_NIF_LATIN1)) <= 0) {
      return enif_make_badarg(env);
   }
   std::string key(key_buf, size);

   if (ECACHE->erase(key) == ECC_OK)
      return make_atom(env, "ok");

   return make_atom(env, "false");
}

static ErlNifFunc nif_funcs[] = 
{
   {"open", 1, open}
   ,{"close", 0, close}
   ,{"put", 4, put}
   ,{"get", 1, get}
   ,{"erase", 1, erase}
};

ERL_NIF_INIT(ecc, nif_funcs, NULL, NULL, NULL, NULL)
