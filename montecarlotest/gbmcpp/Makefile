CC=g++
#CPPFLAGS= -g `pkg-config --cflags python3`
LDFLAGS= -I/usr/include/python3.12 -lpython3.12 -g 

gbmsim: geo_brownian_motion_sim.cpp
	$(CC) $(CPPFLAGS) geo_brownian_motion_sim.cpp -o gbmsim $(LDFLAGS)

.PHONY: clean

clean: 
	rm -f gbmsim
