#!/bin/bash

basedir=/home/gilsun91/bitcoin-master
/home/gilsun91/bitcoin-master/src/bitcoind -daemon -conf=$basedir/conf/bitcoin.conf -txindex -rpcbind=0.0.0.0 -datadir=$basedir/data
