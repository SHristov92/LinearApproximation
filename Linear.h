/*
 * Linear.h
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

#ifndef LINEAR_H_
#define LINEAR_H_

#include <stdint.h>

#define MAX_TABLE_SIZE (10u)

class Linear {
public:
	Linear();
	virtual ~Linear();

	bool addPoint(const float dataIn, const float keyIn);
	float getPoint(const float key);
	struct DataEntry
	{
		float data;
		float key;
	};

private:
	void sortTable();

	DataEntry data[MAX_TABLE_SIZE];

	uint8_t currentTableSize;
	bool isTableSorted;
};

#endif /* LINEAR_H_ */
