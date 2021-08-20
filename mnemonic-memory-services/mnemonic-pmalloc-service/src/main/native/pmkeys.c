/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "pminternal.h"

int pmalloc_setkey(void *md, int keyidx, void *key) {
	struct mdesc *mdp = (struct mdesc *) md;
	int result = 0;

	if ((mdp != NULL) && (keyidx >= 0) && (keyidx < PMALLOC_KEYS)) {
		mdp->persistkeys[keyidx] = key;
		result++;
	}
	return (result);
}

void * pmalloc_getkey(void *md, int keyidx) {
	struct mdesc *mdp = (struct mdesc *) md;
	void * keyval = NULL;

	if ((mdp != NULL) && (keyidx >= 0) && (keyidx < PMALLOC_KEYS)) {
		keyval = mdp->persistkeys[keyidx];
	}
	return (keyval);
}
