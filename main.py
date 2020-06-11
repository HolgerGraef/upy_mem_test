import gc
import test
import time
from machine import SPI, Pin

time.sleep(1)

spi = SPI(2, sck=Pin(18), mosi=Pin(23), miso=Pin(19), polarity=0, phase=0)

i = 0
last_free = 0
while True:
    test.test(spi.write)
    free = gc.mem_free()
    if free > last_free:
        print('gc cleaned up')
        time.sleep(1)
    print('free: {} allocated: {}'.format(free, gc.mem_alloc()))
    i += 1
    last_free = free