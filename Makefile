
all: qmake

qmake: 
	cd src;\
	qmake;\
	make;\
	cd ..;

clean:
	cd src/;\
	rm -rf ui_*;\
	rm -rf moc_*;\
	rm -rf *.o;\
	rm -rf .qmake.stash ;\
	cd ..;

doxygen:
	
