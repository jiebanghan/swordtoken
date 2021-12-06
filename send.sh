#!/bin/bash
for((i=1;i<=$1;i++));  
do   
/home/gilsun91/bitcoin-master/src/bitcoin-cli -regtest -rpcport=8332 -rpcuser=user -rpcpassword=password  sendtoaddress "bcrt1qw4sqg8vlh6ae6ppuu7at3hfckz0se35uwc02kc" 0.01
done  
