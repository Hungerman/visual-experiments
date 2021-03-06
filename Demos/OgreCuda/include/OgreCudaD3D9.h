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

#pragma once

#include "OgreCuda.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32

#include <OgreD3D9RenderSystem.h>
#include <OgreD3D9Texture.h>
#include <OgreD3D9HardwareVertexBuffer.h>

namespace Ogre
{
	namespace Cuda
	{
		class D3D9Root : public Root
		{
			public:
				D3D9Root(Ogre::RenderWindow* renderWindow);
				virtual void init();

			protected:
				LPDIRECT3DDEVICE9 mDevice;
		};

		class D3D9Texture : public Texture
		{
			public:
				D3D9Texture(Ogre::TexturePtr& texture);
				virtual void registerForCudaUse();
				
			protected:
				IDirect3DBaseTexture9* mD3D9Texture;
		};

		class D3D9VertexBuffer : public VertexBuffer
		{
			public:
				D3D9VertexBuffer(Ogre::HardwareVertexBufferSharedPtr vertexBuffer);
				virtual void registerForCudaUse();

			protected:
				IDirect3DVertexBuffer9* mD3D9VertexBuffer;
		};

		class D3D9TextureManager : public TextureManager
		{
			public:
				virtual Texture* createTexture(Ogre::TexturePtr texture);
				virtual void destroyTexture(Texture* texture);
		};

		class D3D9VertexBufferManager : public VertexBufferManager
		{
			public:
				virtual VertexBuffer* createVertexBuffer(Ogre::HardwareVertexBufferSharedPtr vertexBuffer);
				virtual void destroyVertexBuffer(VertexBuffer* vertexBuffer);
		};
	}
}

#endif //if OGRE_PLATFORM == OGRE_PLATFORM_WIN32