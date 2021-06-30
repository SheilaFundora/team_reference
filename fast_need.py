import sys
import math
import random


if __name__ == "__main__":

	file = open( 'Input/closest_pair.in', 'w')

	file.write( str( 10000 ) + '\n' )
	for i in range( 10000 ):
		file.write( str( random.randint( 0 , 100000 )) + ' ' + str( random.randint( 0, 100000 ) ) + '\n' )
	pass
