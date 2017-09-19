-module(ecc).
-author('atao').
-export([init/0, get/1, put/2, put/3, erase/1, open/1, close/0]).

%% @doc load ecc.so
init() ->
   erlang:load_nif("../ecc", 0).

%% @spec open(Path::string()) -> ok | false.
%% @doc 打开一个缓存库
open(_Path) ->
   "NIF library not loaded".


%% @spec close() -> ok.
%% @doc 关闭本地硬盘缓存库
close() ->
   "NIF library not loaded".

%% @spec put(Key::string(), Proto::string(), Bin::binary(), Cond::integer()) -> ok
%% @doc 插入
%% @doc Cond:select查询条件使用
put(_Key, _Bin) ->
   put(_Key, _Bin, 0).
put(_Key, _Bin, _Cond) ->
   "NIF library not loaded".

%% @spec get(Key::string()) -> Value::binary() | not_find
%% @doc 查找
get(_Key) ->
   "NIF library not loaded".

%% @spec erase(Key::string()) -> ok
%% @doc 删除key关联的值
erase(_Key) ->
   "NIF library not loaded".


