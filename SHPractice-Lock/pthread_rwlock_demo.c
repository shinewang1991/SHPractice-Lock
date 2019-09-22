//
//  pthread_rwlock_demo.c
//  SHPractice-Lock
//
//  Created by Shine on 2019/9/22.
//  Copyright © 2019 shine. All rights reserved.
//

#include "pthread_rwlock_demo.h"
#include <pthread.h>

int nums = 0;
pthread_rwlock_t lock;
void *reader(){
    int times = 100000;
    while (times--) {
        pthread_rwlock_rdlock(&lock);
        if(times % 1000 == 0){
        printf("nums is -------%d\n",nums);
        }
        pthread_rwlock_unlock(&lock);
    }
    return NULL;
}

void *writer(){
    int times = 100000;
    while (times--) {
        pthread_rwlock_wrlock(&lock);
        nums++;
        pthread_rwlock_unlock(&lock);
    }
    return NULL;
}

void rwlockDemo(void){
    pthread_rwlock_init(&lock, NULL);
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_create(&thread1, NULL, &reader, NULL);
    pthread_create(&thread2, NULL, &reader, NULL);
    pthread_create(&thread3, NULL, &writer, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
}
