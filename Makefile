
all: qmake

qmake: 
	cd src;\
	qmake;\
	make;\
	cd ..;
clean:
	# TODO: Remove gitignores
	rm -rf build-CPP_Project-Desktop-Debug;\
	rm -rf build-CPP_Project-Desktop-Debug;\
	rm -rf .qt_for_python;\
	cd src/;\
	rm CPP_Project;\
	rm CPP_Project.pro.*;\
	rm Makefile;\
	rm -rf ui_*;\
	rm -rf moc_*;\
	rm -rf *.o;\
	rm -rf .qmake.stash ;\
	cd ..; \
	cd doc/;\
	rm -rf html;\
	cd ..;

doxygen:
	cd doc/;\
	doxygen Doxyfile;\
	cd ..;

run:
	cd src/;\
	./CPP_Project;\
	cd ..;

pack:
	make clean;\
	zip -r  1-xzimol04-xholan11.zip doc examples src Makefile README.txt;