#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


size_t* arr_new(size_t n) {
  size_t* a = malloc(sizeof(size_t)*(n+1));
  if (a == NULL){
    return NULL;
  }
  a[0] = n;
  return a;
}

void arr_free(size_t *a){
  free(a);
}

size_t arr_length(const size_t *a){
  if (a == NULL){
    return 0;
  }
  return a[0];
}

void arr_print(const size_t *a){
  for(size_t i=1; i<=arr_length(a); i++){
  printf("%zu", a[i]);
  if (i != arr_length(a))
            printf(", ");
  }
  printf("\n");
}

void arr_clear(size_t *a){
  for(size_t i=1; i<=arr_length(a); i++){
    a[i] = 0;
  }
}

void arr_set(size_t *a, size_t index, size_t value){
  if (index < arr_length(a)) {
        a[index+1] = value;
      }
}

size_t arr_get(const size_t *a, size_t index){
  if (index < arr_length(a)){
    return a[index+1];  
  }
else
    return 0;
}
void arr_rand(size_t *a){
  for (size_t i = 0; i < arr_length(a); i++) {
        arr_set(a, i, rand());
    }

}

size_t arr_dot(const size_t *a, const size_t *b){
  size_t c = 0;

  if (arr_length(a)!=arr_length(b)){
  return 0;
}

  for (size_t i= 1; i <= arr_length(a); i++){
    c += a[i] * b[i];
  }
  return c;
}

bool arr_add(size_t *dest, const size_t *arr){
  if (arr_length(dest)!=arr_length(arr)){
    return false;
  }
    for(size_t i = 0; i<arr_length(dest); i++){
      arr_set(dest, i , arr_get(dest, i) +  arr_get(arr, i));
    }
    return true;
  }
  





int main() {
  srand(time(NULL));
    size_t* a = arr_new(7);
    arr_set(a, 2, 6);
    arr_set(a, 5, 8);
    arr_set(a, 8, 2);
    arr_set(a, 4, 12);
    arr_set(a, 1, 10);
    arr_print(a);
    printf("arr_dot = %zu\n", arr_dot(a, a));
    printf("arr_get: %zu\n", arr_get(a, 3));
    arr_add(a,a);
    arr_print(a);
    arr_clear(a);
    arr_print(a);
    arr_rand(a);
    arr_print(a);
    arr_free(a);
    return 0;
}

