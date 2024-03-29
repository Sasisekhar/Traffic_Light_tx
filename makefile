# -DNO_LOG_STATE
all:
	g++ -std=gnu++20 -DDEBUG_DELAY -I main/ main/main_rt_model.cpp -o run && ./run

run:
	./run

clean:
	rm -f *.o
	rm -f *.csv
	rm -f run

setup:
	. ${IDF_PATH}/export.sh
	idf.py set-target esp32s3


embedded:
	idf.py build
	idf.py flash -p /dev/ttyACM1
	idf.py monitor -p /dev/ttyACM1

e_clean:
	idf.py clean