https://aur.archlinux.org/packages/qmk/

https://www.archlinux.org/packages/community/x86_64/teensy-loader-cli/

    qmk compile -km macovsky -kb kinesis/stapelberg

    teensy-loader-cli --mcu=at90usb1286 -v -w .build/kinesis_stapelberg_macovsky.hex

    xset r rate 250 40
