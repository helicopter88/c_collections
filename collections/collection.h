#ifndef COLLECTION_H
#define COLLECTION_H
#pragma once

typedef void   (*foreach)    (void*);
typedef void*  (*mapper)     (void*);
typedef int    (*comparator) (void*, void*);
typedef void*  (*folder)     (void*, void*);
typedef int    (*predicate)  (void*);
#endif