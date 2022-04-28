
all: qmake

qmake:
	cd src/
	qmake

clean:
	cd src/
	rm *.o
	cd ..
	
