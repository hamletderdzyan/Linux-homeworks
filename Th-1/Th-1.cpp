#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <sys/times.h>
#include <string>
#include <string.h>
using namespace std;

#define DATA_PER_THREAD 1024


struct local_args {
    int* array;
    int start;
    int end;
};

void* local_sum(void* arg){
    int local_sum = 0;
    local_args* block = (local_args*)arg;
    for(int i = block->start; i < block->end; i++){
        local_sum += block->array[i];
    }
    return new int(local_sum);
}

void threadless_sum(int* arr, int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
}

int main(int argc, char** argv){

    if(argc < 3){
        cout << "Not enough arguments!" << endl;
        exit(1);
    }
    int array_size = stoi(argv[1]);
    int thread_num = stoi(argv[2]);
    int* array = new int[array_size];
    srand(12);
    int i = 0, sum = 0;

    for(i = 0; i < array_size; i++){
        array[i] = rand() % 1000;
    }

    struct tms start_st, end_st;
    clock_t start, end;
    start = times(&start_st);

    threadless_sum(array, array_size);
    end = times(&end_st);

    clock_t ticks_per_second = sysconf(_SC_CLK_TCK);
    double delta = end - start;
    double time_loop = delta / ticks_per_second;

    pthread_t* threads = new pthread_t[thread_num];
    thread_args** array_of_args = new thread_args*[thread_num];
    for(i = 0; i < thread_num; i++){
        array_of_args[i] = new thread_args;
        array_of_args[i]->array = array;
        array_of_args[i]->start = i * (array_size / thread_num);
        array_of_args[i]->end = min(array_of_args[i]->start + (array_size / thread_num), array_size);
        int thread_output = pthread_create(&threads[i], NULL, thread_sum, array_of_args[i]);
        if(thread_output != 0){
            cerr << strerror(thread_output) << endl;
            exit(thread_output);
        } 
    }
    int global_sum = 0;
    start = times(&start_st);

    for(int i = 0; i < thread_num; ++i){
        void* return_value;
        int result = pthread_join(threads[i], &return_value);
        int* thread_sum_result = (int*)return_value;
        global_sum += *thread_sum_result;
    }
    
    end = times(&end_st);
    delta = end - start;
    double time_threads = delta / ticks_per_second;

    cout  << time_loop << endl;
    cout  << time_threads << endl;
     delete[] array_of_args;
    delete[] array;

    return 0;
}