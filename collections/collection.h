#ifndef COLLECTION_H
#define COLLECTION_H
#pragma once
typedef void* T;
typedef void   (*foreach)    (T);
typedef void*  (*mapper)     (T);
typedef int    (*comparator) (T, T);
typedef void*  (*folder)     (T, T);
typedef int    (*predicate)  (T);
#endif