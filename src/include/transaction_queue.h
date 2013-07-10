/*
 * transaction_queue.h
 *
 * This file is released under the terms of the Artistic License.  Please see
 * the file LICENSE, included in this package, for details.
 *
 * Copyright (C) 2002 Mark Wong & Open Source Development Lab, Inc.
 *
 * 5 august 2002
 */

#ifndef _TRANSACTION_QUEUE_H_
#define _TRANSACTION_QUEUE_H_

#include <_semaphore.h>
#include "transaction_data.h"
#define REQ_QUEUED 0
#define REQ_EXECUTING 1

struct transaction_queue_node_t
{
	sem_t s;
	int id;
	struct client_transaction_t client_data;
	struct transaction_queue_node_t *next;
};

struct transaction_queue_node_t *dequeue_transaction();
int enqueue_transaction(struct transaction_queue_node_t *node);
int init_transaction_queue();

extern sem_t queue_length;

#endif /* _TRANSACTION_QUEUE_H_ */
