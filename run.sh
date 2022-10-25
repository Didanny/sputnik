g++ -L/build/sputnik -L/usr/local/cuda-11.7/lib64 -L/pkg/glog/0.3.3/lib -I/usr/local/cuda-11.7/targets/x86_64-linux/include -I/home/dannya1/sputnik -I/pkg/glog/0.3.3/include -lglog -lcuda -lcudart test.cpp -o test
./test
