inp=$1
if ("$inp" "-eq" 'bus_t1')
then
	g++ -std=c++14 src/TEST/BusinessTest01.cpp -o build/BusinessTest.o -lpthread -ldl
fi
