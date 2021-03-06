/*
	Copyright (c) 2010 ASTRE Henri (http://www.visual-experiments.com)

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.
*/

#include "GPUSurfScriptGenerator.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int width    = 640;
	int height   = 480;
	int nbOctave = 5;

	cout << "GPUSurf ScriptGenerator :"<<endl;
	cout << "Image width (default 640) :"<<endl;
	cin >> width;
	cout << "Image height (default 480) :"<<endl;
	cin >> height;
	cout << "Nb octaves (default 5) :"<<endl;
	cin >> nbOctave;

	GPUSurfScriptGenerator generator(width, height, nbOctave);
	generator.createMaterials();
	generator.createMaterialsHLSL();
	generator.createMaterialsGLSL();

    return 0;
}