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
	
	void* SmartAllocator::_malloc(unsigned int size){
		
		return nullptr;
	}
	
	void SmartAllocator::_free(void* ptr){
		
	}
	
	SmartAllocator::SmartAllocator(unsigned int heapSize, unsigned int alignement){
		m_heapSize = heapSize * (sizeof(MBlock) * heapSize/alignement);
		m_blockSize = alignement;
		m_heap = static_cast<char*>(_malloc(m_heapSize));
		ASSERT_(m_heap,"Can't allocate 0x" + Upp::Format64Hex (m_heapSize) +" bytes");
		m_begin = m_heap;
		m_end = m_begin + m_heapSize;

		memset(m_begin, 0, m_heapSize);
		
		char* previous = nullptr;
		for(char* ptr = m_begin; ptr <= m_end; ptr = ptr + sizeof(MBlock) + alignement){
			MBlock* block = (MBlock*) ptr;
			block->pNext = ptr + sizeof(MBlock) + alignement;
			block->pPrevious = previous;
			block->pMem = ptr + sizeof(MBlock);
			block->size = 0x00;
			block->allocId = 0x00;
			
			if(block->pNext >=  m_end) block->pNext = nullptr;
			previous = ptr;
		}
	}
	
	SmartAllocator::~SmartAllocator(){
		if(m_heap){
			free(m_heap);
		}
	}
	
	SmartAllocator::MBlock* SmartAllocator::FindFreeBlock(int size){ //Size in bytes
		return nullptr;
	}
};