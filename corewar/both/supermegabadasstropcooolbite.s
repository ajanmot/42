.name "definitely lost: 0 bytes in 0 blocks"
.comment "=56839==    by 0x1005D39B5: map_images_nolock (in /usr/lib/libobjc.A.dylib)"

begin:
    ld   %7, r3
    sti  r1, %0, r3

lab_live:
    live %40
    ld %100, r2
    fork %:begin
    st r2, 20
