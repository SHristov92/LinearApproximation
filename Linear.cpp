/*
 * Linear.cpp
 *
 *  Created on: Jan 15, 2021
 *      Author: SHristov
 *
 *
 * MIT License
 *
 * Copyright (c) 2021 Spas Hristov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "Linear.h"

#include <stdlib.h>

Linear::Linear() :
		currentTableSize(0), isTableSorted(false)
{

}

Linear::~Linear() {
}

bool Linear::addPoint(const float dataIn, const float keyIn)
{
	if (currentTableSize < MAX_TABLE_SIZE)
	{
		data[currentTableSize].data = dataIn;
		data[currentTableSize].key = keyIn;

		currentTableSize++;
		isTableSorted = false;

		return true;
	}
	else
	{
		return false;
	}
}

float Linear::getPoint(const float key)
{
	if (!isTableSorted)
	{
		sortTable();
	}

	if (key <= data[0].key) return data[0].data;
	if (key >= data[currentTableSize - 1].key) return data[currentTableSize - 1].data;

	uint8_t index;

	for (index = 0; index < currentTableSize - 2; index++)
	{
		if ((data[index].key <= key) && (data[index + 1].key > key))
		{
			break;
		}
	}

	float key0 = data[index].key;
	float key1 = data[index + 1].key;

	float ratio0 = 1.0f - (key - key0);
	float ratio1 = 1.0f - (key1 - key);

	return (data[index].data * ratio0) + (data[index + 1].data * ratio1);
}

int compareDataEntry(const void *a, const void *b)
{
	if (((Linear::DataEntry*) a)->key < ((Linear::DataEntry*) b)->key)	return -1;
	if (((Linear::DataEntry*) a)->key > ((Linear::DataEntry*) b)->key)	return 1;
	return 0;
}

void Linear::sortTable()
{
	qsort(data, currentTableSize, sizeof(DataEntry), compareDataEntry);
	isTableSorted = true;
}

