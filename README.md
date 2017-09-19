# Ecache
Ecache是一个基于erlang nif、leveldb、protobuf构建的轻量级、高效、没有容量限制的本地磁盘缓存系统。

## 设计目的
在进行服务器开发的时候，我们使用Erlang来进行整体架构，本地磁盘缓存系统使用dets(disk erlang term storage)完成。dets在使用上非常方便，提供完善的数据操作接口，比如lookup，insert，delete，select等常用的操作，但是dets提供的存储容量上限不超过2G的限制，不能满足我们的业务需求，如果需要更大容量的数据存储支持，需要引入mnesia，这样的引入无疑加大了系统的开发和维护的成本，其复杂度也远远超出了我对本地磁盘缓存系统的预期。

先看下我需要的磁盘缓存系统应该是怎样的：

> 1. 没有容量限制：不应该因为数据增长导致该系统失效，影响整个系统的运作。
> 2. 高性能：性能在海量数据下不会明显下降，要比dets高效。
> 3. 要成熟可靠：底层核心系统需要足够完善和健壮。
> 4. 简单：不论在提供的接口的使用上，还是后期的维护上都要足够简单。

dets无法满足第1条，mnesia无法满足第4条。所以开发Ecache系统，Ecache的特点：

> 1. 没有容量限制：数据使用leveldb进行存储.
> 2. 读写性能是dets的两倍以上。
> 3. 采用leveldb+protobuf进行数据的读写，在使用这两者的产品非常多，非常稳定。
> 4. 接口简单：通过nif，提供put,get,erase,select四个数据操作接口，使用起来更加简单和直观。

## 核心

> 1. Ecache.cc：封装了leveldb常用接口，同时在open之后直到close或者关闭进程之前，长期持有缓存系统的入口。提供统计，便于内部信息的查看。
> 2. Wrapper.cc：该类很简单，只对用户输入数据进行一次编码，统一为CommonData格式。
> 3. ecc.cc：nif实现文件，存储的时候接受binary类型，查询返回也是binary类型，这样做的目的就是，让用户自己决定用什么实现来打包数据，可以根据具体的数据采用具体的打包方式，当然也可以简单的统一使用term_to_binary进行打包，查询后使用binary_to_term解包。

## Ecache提供的功能

支持常规的插入(put),查找(get),按条件查找(select),删除(erase),查看系统信息(info)。

## 安装

> 不支持windows

### 安装protobuf， g++需要支持c++11及以上

```bash
#确保系统安装了:autoconf automake libtool curl make g++ unzip
git clone https://github.com/google/protobuf.git
./autogen.sh
./configure
make
make check
make install
ldconfig
# 如果安装成功的话，就可以使用protoc命令，用于根据proto文件生成c++对应的源文件。
```

### 安装leveldb

```bash
git clone https://github.com/google/leveldb.git
make

#因为需要leveldb的动态链接库，拷贝到指定位置
cd out-shared
cp libleveldb.so.1.20 /usr/local/lib/
cd  /usr/local/lib
ln -s libleveldb.so.1.20 libleveldb.so
ln -s libleveldb.so libleveldb.so.1 
ldconfig

## 拷贝leveldb的头文件到usr/local/include
cp -a include/leveldb /usr/local/include
```

### 安装erlang

```bash
## 确保系统安装了erlang，假设安装目录为/usr/local
```

### 将相关的库和头文件加入对应的环境变量

```bash
cat ~/.bash_profile <<EOF
export C_INCLUDE_PATH=$C_INCLUDE_PATH:/usr/local/erlang/lib/erlang/usr/include:/usr/local/include/leveldb
export CPLUS_INCLUDE_PATH=$C_INCLUDE_PATH:/usr/local/erlang/lib/erlang/usr/include:/usr/local/include/leveldb
export LD_LIARARY_PATH=$LD_LIARARY_PATH:/usr/local/lib
EOF
```

### 编译Ecache

```bash
git clone https://github.com/ellahub/Ecache.git
cd Ecache
# 生成CommonData.cc
cd proto
bash gen_proto.sh
cd ..
make
```

编译成功后会看到ecc.so动态库，将ecc.so和erl_src/ecc.erl加入项目中（根据so的位置，ecc.erl中的load_nif的地址需要调整一下）。

### 使用

```erlang
ecc:init().
ok = ecc:open("db").
Key = "key",
Data = {1,2,3,4,5}.
Cond = 0.
Proto = "term_to_binary",
ok = ecc:put(Key, term_to_binary(Data)).
Data = binary_to_term(ecc:get("test")).
ok = ecc:close().
```

> 可以使用put/3这个接口，额外多了一个select时候的过滤条件参数，默认为0

### 测评
...

### 交流
QQ: 1628025718(注明Ecache)
