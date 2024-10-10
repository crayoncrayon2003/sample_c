# install
```
sudo apt install gcc
sudo apt install gcc
sudo apt install libpcap-dev
```

# authority
```
$ sudo groupadd pcap
$ sudo usermod -a -G pcap $USER
$ sudo chgrp pcap /usr/sbin/tcpdump
$ sudo chmod 750 /usr/sbin/tcpdump
$ sudo setcap cap_net_raw,cap_net_admin=eip /usr/sbin/tcpdump
```

# Setting
## setting.h
SETTING_NIC　is NIC ID