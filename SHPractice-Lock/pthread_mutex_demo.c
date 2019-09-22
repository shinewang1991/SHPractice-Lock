//
//  pthread_mutex_demo.c
//  SHPractice-Lock
//
//  Created by Shine on 2019/9/22.
//  Copyright © 2019 shine. All rights reserved.
//

#include "pthread_mutex_demo.h"
#include "pthread.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;   //互斥锁
int num = 0;   //临界资源
void * producer(){
    int times = 10000000;
    while (times--) {
        pthread_mutex_lock(&mutex);
        num++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void * consumer(){
    int times = 10000000;
    while (times--) {
        pthread_mutex_lock(&mutex);
        num--;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void mutexDemo(){
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, &producer, NULL);
    pthread_create(&thread2, NULL, &consumer, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("num is -----------%d\n",num);
}
