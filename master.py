import spidev
import time

# Cria um objeto spi
spi = spidev.SpiDev()
# Habilita a porta spi 0
# CS = 1
spi.open(0, 1)

try:
	while True:
		# Transfere 3 bits 
		# seguidos para 
		# iniciar aquisição
		x = spi.xfer2(['i'])
		y = spi.xfer2(['x'])
		z = spi.xfer2(['y'])
		# Espera 20 segundos
		time.sleep(20)
		# Recebe e imprime 
		# bits que representam 
		# valor da tensão obtida
		print(y+z*0.1+x*0.01)
	except KeyboardInterrupt:
		# Fecha porta spi
		spi.close()
