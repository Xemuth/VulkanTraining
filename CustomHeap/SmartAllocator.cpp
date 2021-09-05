#include "SmartAllocator.h"
#include <Core/Core.h>

namespace Upp{
	
	SmartAllocator* SmartAllocator::m_allocator = nullptr;
	
	SmartAllocator& SmartAllocator::GetAllocator(unsigned int heapSize, unsigned int blockSize){
		if(!m_allocator){
			m_allocator = new SmartAllocator(heapSize, blockSize);
		}
		return *m_allocator;
	}
	
	void SmartAllocator::DestroyAllocator(){
		if(m_allocator){
			delete m_allocator;
		}
	}
	
	unsigned int SmartAllocator::GetCurrentHeapSize()const{
		return m_heapSize;
	}
	
	void* SmartAllocator::SAMalloc(unsigned int size, unsigned short* allocID){
		BlockFound block = FindFreeBlock(size);
		if(block.current){
			char* ptr = (char*)block.current;
			int numberBlockNeeded = 1;
			numberBlockNeeded += (size - m_blockSize) / (sizeof(MBlock) + m_blockSize);
			block.current->size = numberBlockNeeded;
			block.current->allocId = GenerateUniqueID();
			block.current->used = 0x01;
			if(allocID) *allocID = block.current->allocId;
			LOG("[SmartAllocator][SAMalloc] New allocation of " + AsString(numberBlockNeeded) + " blocks (" + AsString(numberBlockNeeded * (sizeof(MBlock) + m_blockSize)) + " bytes) on the heap with ID " + AsString(block.current->allocId) );
			return ptr + sizeof(MBlock);
		}else{
			LOG("[SmartAllocator][SAMalloc] Can't allocate " + AsString(size) + " bytes on current heap");
		}
		return nullptr;
	}
	
	void SmartAllocator::SAFree(void* ptr){
		if(ptr && ptr >= m_begin && ptr < m_end){
			MBlock* block = (MBlock*)((char*)ptr -sizeof(MBlock));
			char* pBlock = (char*)ptr -sizeof(MBlock);
			int numberToClean = block->size;
			short allocationId = block->allocId;
			for(int e = 0; e < numberToClean; e++, pBlock = pBlock + sizeof(MBlock) + m_blockSize){
				block = (MBlock*)((char*)pBlock);
				block->size = 0x00;
				block->allocId = 0x00;
				block->used = 0x00;
				memset(pBlock + sizeof(MBlock), 0, m_blockSize);
			}
			LOG("[SmartAllocator][SAFree] Freed allocation ID " +  AsString(allocationId) +"("+ AsString(numberToClean * (sizeof(MBlock) + m_blockSize)) + " bytes)");
		}
	}
	
	short SmartAllocator::GenerateUniqueID(){
		static short uID = 0;
		return ++uID; //TODO Something more sophisticated
	}
	
	SmartAllocator::SmartAllocator(unsigned int heapSize, unsigned int alignement){
		ASSERT_( heapSize > alignement, "HeapSize of " + AsString(heapSize) + " is too low for an alignement of " + AsString(alignement) + " bytes");
		m_blockSize = alignement;
		m_heapSize = heapSize + (sizeof(MBlock) * (heapSize/m_blockSize));
		m_heap = static_cast<char*>(malloc(m_heapSize));
		ASSERT_(m_heap, "Can't allocate " + AsString(m_heapSize) +" bytes");
		m_begin = m_heap;
		m_end = m_begin + m_heapSize;

		memset(m_begin, 0, m_heapSize);
		
		MBlock* block1 = (MBlock*) m_begin;
		block1->size = 0x00;
		block1->used = 0x00;
		block1->allocId = 0x00;

		char* previous = m_begin;
		char* ptr = m_begin + sizeof(MBlock) + m_blockSize;
		int numberOfBlock = 1;
		for(; ptr < m_end; ptr = ptr + sizeof(MBlock) + m_blockSize){
			MBlock* block2 = (MBlock*) ptr;
			block2->size = 0x00;
			block2->used = 0x00;
			block2->allocId = 0x00;
			
			previous = ptr;
			numberOfBlock++;
		}
		LOG("[SmartAllocator][Constructor] Heap created with " + AsString(numberOfBlock) + " blocks of " + AsString(m_blockSize) + " bytes for a total heap size of " + AsString(m_heapSize) + " bytes");
		LOG("[SmartAllocator][Constructor] Current size of MBlock is " + AsString(sizeof(MBlock)) + " bytes");
	}
	
	SmartAllocator::~SmartAllocator(){
		if(m_heap){
			free(m_heap);
		}
	}
	
	SmartAllocator::BlockFound SmartAllocator::FindFreeBlock(int size){ //Size in bytes
		BlockFound bf;
		bf.previous = nullptr;
		bf.current = nullptr;
		char* ptr = m_begin;
		MBlock* previous = nullptr;
		for(; ptr < m_end; ptr = ptr + sizeof(MBlock) + m_blockSize){
			if(ptr >= m_end){
				bf.current = nullptr;
				bf.previous = previous;
				return bf;
			}
			MBlock* block = (MBlock*) ptr;
			if(!(block->used & 0x01)){
				int remainingSize = size - m_blockSize;
				int lookupBlock = 1;
				if(remainingSize <= 0){
					bf.current = block;
					return bf;
				}else{
					char* ptrMb = ptr + sizeof(MBlock) + m_blockSize;
					MBlock* mb = (MBlock*) ptrMb;
					while(!(mb->used & 0x01) && remainingSize > 0){
						remainingSize -= m_blockSize + sizeof(MBlock);
						lookupBlock++;
						ptrMb = ptrMb  + sizeof(MBlock) + m_blockSize;
						mb = (MBlock*) ptrMb;
						if(ptrMb >= m_end){
							bf.current = nullptr;
							return bf;
						}
					}
					if(remainingSize <= 0){
						bf.current = block;
						bf.previous = previous;
						return bf;
					}else{
						ptr += lookupBlock * (sizeof(MBlock) + m_blockSize);
					}
				}
			}else{
				previous = block;
				ptr += (block->size -1) * (sizeof(MBlock) + m_blockSize);
			}
		}
		return bf;
	}
};