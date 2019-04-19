import spidev
import time

spi=spidev.Spidev()
spi.open(0,0)
spi.max_speed_hz(500000)
while 1:
    resp=spi.xfer2(0xAA)
    print resp
    time.sleep(0.5)
