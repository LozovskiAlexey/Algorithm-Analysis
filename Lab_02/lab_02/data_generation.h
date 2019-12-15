#ifndef DATA_GENERATION_H
#define DATA_GENERATION_H

int* create_sorted(int size);
int* create_random(int size);
int* create_reversed(int size);

int my_rand(int min, int max);

//int* generate_data(int size, int mode);
void release_data(int* arr);

#endif // DATA_GENERATION_H
