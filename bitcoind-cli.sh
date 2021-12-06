#!/bin/bash
#

if [ $# -eq 0 ];then
	echo "Error, Usage: $(basename $0) method"
	exit 2
fi
/home/gilsun91/bitcoin-master/src/bitcoin-cli -rpcport=18443 -rpcuser=superman -rpcpassword=superman $@
