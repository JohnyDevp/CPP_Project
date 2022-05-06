
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
	rm -rf ui_*;\
	rm -rf moc_*;\
	rm -rf *.o;\
	rm -rf .qmake.stash ;\
	cd ..; \
	cd docs/;\
	rm -rf html;\
	cd ..;

doxygen:
	cd docs/;\
	doxygen Doxyfile;\
	cd ..;

run:
	cd src/;\
	./CPP_Project;\
	cd ..;

# TODO: Change reame to txt
pack:
	make clean;\
	zip -r  n-xzimol04-xholan11.zip docs examples src Makefile README.md;