#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
   if(pq->size == 0)return NULL;
   return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
   int i = (pq->capac * 2) + 1;

   if(pq->size == pq->capac){
      pq->heapArray = (heapElem *) realloc (pq->heapArray,i*sizeof(heapElem));
   }

  /* for(i = 0; i<pq->capac; i++){
      if(pq->heapArray[i].data == NULL){
         pq->heapArray[i].priority = priority;
         pq->heapArray[i].data = data;
         break;
      }
   }*/

   pq->heapArray[pq->size+1].data = data;
   pq->heapArray[pq->size+1].priority = priority;

   i= pq->size + 1;
   heapElem  aux;

   while(pq->heapArray[i].priority > pq->heapArray[(i-1)/2].priority){
      aux = pq->heapArray[i];
      pq->heapArray[i] = pq->heapArray[(i-1)/2];
      pq->heapArray[(i-1)/2] = aux;
      i = (i-1)/2;
   }
   pq->size += 1;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
   Heap * monticulo = (Heap *) calloc (3 ,sizeof(Heap));
   monticulo->heapArray = (heapElem *) malloc (sizeof(heapElem));
   monticulo->size = 0;
   monticulo->capac = 3;
   return monticulo;
}
