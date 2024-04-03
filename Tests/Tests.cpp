#include "pch.h"
#include "CppUnitTest.h"
#include"..\SmartAllocator\smartAllocator.h"
#include <vector>
//#include "..\SmartAllocator\smartAllocator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace allocator;
namespace Main_Tests
{	
	TEST_CLASS(Allocation)
	{
	public:

		TEST_METHOD(IsSimpleValueAllocationCorrrect)
		{
			int v = 23;

			smart_allocator<int> t1;

			t1.allocate(v);

			Assert::AreEqual(*t1.getData(), v);
		}

		TEST_METHOD(IsEmptyValueAllocationCorrect)
		{
			smart_allocator<int> t1;

			t1.allocate();

			Assert::IsNotNull(t1.getData());
		}

		TEST_METHOD(IsBlockAllocationCorrect)
		{
			std::vector<int> data = { 1,2,3,4,5 };

			smart_allocator<int> t1;
			
			t1.allocate_memory_block(data.size());
			int i = 0;
			for (int e : data)
			{
				t1[i] = e;
				++i;
			}

			t1.iterate([data](const int& elem, int index)->bool 
				{
					int g = data[index];

					Assert::AreEqual(data[index], elem);

					return true;
				});

			Assert::AreEqual(t1.isAllocated(), true);
			Assert::AreEqual(t1.hasBlockAllocated(), true);
			Assert::AreEqual(t1.getSize(), (size_t)data.size());
		}

	};

	TEST_CLASS(CtorsTesting)
	{
	public:

		TEST_METHOD(IsCtorCorrect)
		{
			smart_allocator<char> t1;

			Assert::AreEqual(t1.getData(), nullptr);
			Assert::AreEqual(t1.hasBlockAllocated(), false);
			Assert::AreEqual(t1.isAllocated(), false);
			Assert::AreEqual(t1.getSize(), (size_t)0);
		}

		TEST_METHOD(IsCtorWithAlloctionCorrect)
		{
			char d = 'a';
			smart_allocator<char> test(d);

			Assert::AreEqual(*test.getData(), d);
			Assert::AreEqual(test.isAllocated(), true);
			Assert::AreEqual(test.hasBlockAllocated(), false);
			Assert::AreEqual(test.getSize(), (size_t)1);						
		}

		TEST_METHOD(IsVectorCastCorrect)
		{
			std::vector<int> v = { 1,2,3,4,5 };

			smart_allocator<int> test(v);

			int i = 0;

			for (int el : v)
			{
				Assert::AreEqual(el, *(test.getData() + i));
					++i;
			}
			
			Assert::AreEqual(test.isAllocated(), true);
			Assert::AreEqual(test.hasBlockAllocated(), true);
			Assert::AreEqual(test.getSize(), (size_t)v.size());
		}

		TEST_METHOD(IsCopyCtorCorrect_EmptyValue)
		{
			smart_allocator<int> t;
			t.allocate();

			smart_allocator<int> t2(t);

			Assert::AreEqual(*t.getData(), *t2.getData());
			Assert::AreEqual(t.hasBlockAllocated(), false);
			Assert::AreEqual(t2.hasBlockAllocated(), false);
			Assert::AreEqual(t.isAllocated(), true);
			Assert::AreEqual(t2.isAllocated(), true);
			Assert::AreEqual(t.getSize(), t2.getSize());
		}

		TEST_METHOD(IsCopyCtorCorrect_SingleValue)
		{
			smart_allocator<char> t1('s');
			smart_allocator<char> t2(t1);

			Assert::AreEqual(*t1.getData(), *t2.getData());

			Assert::AreEqual(t1.hasBlockAllocated(), false);
			Assert::AreEqual(t2.hasBlockAllocated(), false);

			Assert::AreEqual(t1.isAllocated(), true);
			Assert::AreEqual(t2.isAllocated(), true);

			Assert::AreEqual(t1.getSize(), t2.getSize());
		}

		TEST_METHOD(IsCopyCtorCorrect_Mem_Block)
		{
			std::vector<char> d {'d', 'f', 'c', 'k'};

			smart_allocator<char> t1;

			t1.allocate_memory_block(d);
			
			smart_allocator<char> t2(t1);

			Assert::AreEqual(t1.isAllocated(), true);
			Assert::AreEqual(t2.isAllocated(), true);

			Assert::AreEqual(t1.hasBlockAllocated(), true);
			Assert::AreEqual(t2.hasBlockAllocated(), true);

			Assert::AreEqual(t2.getSize(), t1.getSize());

			int i = 0;

			size_t size = t1.getSize();

			for (size_t i = 0; i < size; i++)
			{
				Assert::AreEqual(t1[i], t2[i]);
			}
		}

		

		
	};

	TEST_CLASS(Operators)
	{
	public:
		TEST_METHOD(IsAssignmentOperatorCorrect_EmptyValue)
		{			
			smart_allocator<int> t;
			t.allocate();
			smart_allocator<int> t1 = t;

			Assert::AreNotSame(t.getData(), t1.getData());
			Assert::AreEqual(*t.getData(), *t1.getData());

			Assert::AreEqual(t.isAllocated(), true);
			Assert::AreEqual(t1.isAllocated(), true);

			Assert::AreEqual(t.hasBlockAllocated(), false);
			Assert::AreEqual(t1.hasBlockAllocated(), false);

			Assert::AreEqual(t.getSize(), (size_t)1);
			Assert::AreEqual(t1.getSize(), (size_t)1);

		}
	};

	TEST_CLASS(InterfaceMethods)
	{		
	public:

		TEST_METHOD(IsGetDataCorrect)
		{
			int d = 5;

			smart_allocator<int> t(d);

			Assert::AreEqual(d, *t.getData());
		}
	};
}
