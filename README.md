# knu-os-lab-4

## Getting started
```
./build
```

### Getting the keyboard event

```
cat /proc/bus/input/devices
```

That file contains the `/dev/input` event name for each device in the `Handlers` section.
```
I: Bus=0005 Vendor=3434 Product=0213 Version=0132
N: Name=""Keychron K1 Pro" Keyboard"
P: Phys=60:e9:aa:a0:4f:2c
S: Sysfs=/devices/virtual/misc/uhid/0005:3434:0213.000A/input/input46
U: Uniq=6c:93:08:62:72:16
H: Handlers=sysrq kbd leds event18 
B: PROP=0
B: EV=12001f
B: KEY=3f000307ff 0 0 483ffff17aff32d bfd4444600000000 1 130ff38b17d007 ffff7bfad9415fff ffbeffdfffefffff fffffffffffffffe
B: REL=1040
B: ABS=100000000
B: MSC=10
B: LED=1f
```

## Reading memory of another process

```
./build/read_target
```

Reading memory of another process requires the administrator rights, so don't forget to add `sudo`.
```
sudo ./build/read_process_memory
```