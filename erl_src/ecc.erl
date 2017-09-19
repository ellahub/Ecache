-module(ecc).

-export([init/0, get/1, put/4, erase/1, open/1, close/0]).


init() ->
   erlang:load_nif("../ecc", 0).

put(_Key, _Proto, _Bin, _Cond) ->
   "NIF library not loaded".

erase(_Key) ->
   "NIF library not loaded".

get(_Key) ->
   "NIF library not loaded".

open(_Path) ->
   "NIF library not loaded".

close() ->
   "NIF library not loaded".


