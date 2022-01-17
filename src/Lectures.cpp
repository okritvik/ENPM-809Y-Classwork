/**
 * @file Lectures.cpp
 * @author Kumara Ritvik Oruganti (okritvik@umd.edu)
 * @brief Contains the important points told in the lectures
 * @version 0.1
 * @date 2021-09-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
//Function like macro
#define LOG(x) std::cout<<x<<std::endl;

//CREATING NAMESPACES:

namespace first_namespace{
	int a{3};
}

namespace second_namespace{
	int b{4};
	//int a{5}; //using a is ambiguous because a is declared in first_namespace and second_namespace.
	//Hence it is recommended to use the scope resolution operator.
}

using namespace first_namespace;
using namespace second_namespace;
int main(){
	// int var = 6;
	// std::cout<<"Hello World!"<<std::endl;
	// std::cout<<var<<std::endl;
	
	/*
	There are three types of initializations.
	C Type => int var=1;
	Constructor type = int var(1);
	List initialization or bracket initialization = int var{1} // It doesn't take multiple values
	int var {} => zero initialization == var is initialized with zero
	*/
	//int list_var = {1,2,3};
	/*
	So basically, if we say 3.0, it will be taken as a double same like java. If we say 3.0f, it is taken as float but there is implicit conversion available in c++ to convert from double to float
	Converting from narrow data type to wide data type is safe but not vice versa because it may result in loss of data.
	The list initialization will prevent from narrow conversions. It is safe way while converting the data as it will throw an error.
	
	Compiler uses the global variable if declared unless it is shadowed(same name) in local scope.
	Hence try to differentiate the global variables and local variables

	Constants must be initialized. They cannot be declared first and initialized later.

	"auto" keyword is used for type deduction automatically by c++
	ex: auto var1 = 2;
	type deduction will not work for objects that do not have initializers or zero initializers. Hence auto var{} is not valid. 

	Macros are defined with #define directive.
	Syntax: #define <identifier> <value> //Identifier must be all caps.
	Macros are initialized initially outside main. They can be redifined in the code but the value changes globally.
	If we redefine a macro, it will be changed globally.
	Another use of macros:(Function like macros)
	#define LOG(x) std::cout<<x<<std::endl;
	#undef keyword is used to undefine the macro. 
	Use the LOG(var) to print the variable in console.
	Macros doesn't have extra memory allocated.

	*/
	// char *s = "Hello world from char pointer";
	// LOG(s);

	/*
	std::cin interacts with the user (using console.)
	cout object in C++ is an object of class ostream.
	<< is called insertion operator.
	>> is called extraction operator.
	:: is called scope resolution operation


	Dont use using namespace std in this course. Instead
	use 
	using std::endl;
	using std::cout;
	using std::cin;


	creating namespaces:
	namespace first_namespace{
		int a{3};
	}

	namespace second_namespace{
		int b{4};
	}
	*/
	// std::cout<<"HEllo"<<"Worldd "<<"\n";


	// //Taking Input:
	// std::cout << "Please enter your age: ";
	// unsigned short age;
	// std::cin >> age;
	// std::cout << "Your age is : " << age << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	/*
	Lecture 3
	std::endl should be avoided to improve performance
	buffer is flushed everytime when we call endl at the back end
	After the program is finished, the buffer gets flushed automatically and it is done only once. 
	For Loop:
	for (int i{};i<10;i++){
		std::cout<<"."<<std::flush; //gives an output of . every second 
		where as std::cout<<"."; // gives output after the end of program

	}
	Sleep function:
	sleep(1) gives 1 sec delay
	Using std flush is always inefficient. It is invoking the buffer to flush and very inefficient.
	using endl takes 6 times more time than "\n"
	We can use manipulators or create manipulators (custom) to replace \n with a function call.or we can use Macros (should be avoided though). It is just to make work easier.
	Example of manipulator is boolalpha.
	String data type is defined in std
	"HELLO WORLD" is a string but it is a C String. It is array of characters.
	=> it is a char* string. These are very light compared to std::string;
	To create a string and manipulate, we have to #include <string> 
	then, std::string var_name
	if we include string library, we have string manipulating functions available for us
	std::cin breaks on blank space if we use extraction operator. >> only returns characters up to the first white space it encounters
	The data after the first blank space is there in the buffer and waits for the next extraction
	Hence use std::getline() to take the whole string till the next line character is encountered
	example to use std::getline:
		std::getline(std::cin >> std::ws, stringvar)
	if we dont use std::ws, blank space is treated as another string if we are taking any input after the present line
	we can leave to compiler to manage the memory management of std::string. We need not worry about that
	use std::string::size_type s_size = stringvar.size() to store the size of the string. size_type lets the compiler decides the memory allocation(type) to store the size of the string
	If we have string value greater than the size of string, 
	Arrays:::
		Similar type of data in a contiguous memory location under one name
		create a string: std::string example[<size>]{}
		Once we created a fixed size array, the size is fixed. We cannot grow.
		Index starts from 0 to (size -1)
		or we can use std::array and include #include<array>
		There is no noticiable performance difference between c style and c++ style.
		There are two types of initializations of arrays.
		1) type identifier[size]{list_of_elements} (comma seperated)
		2) type identifier[size] = {list of elements} (comma seperated)
		int array[]{1,2,3} //automatically computes the array size
		std::fill(<identifier>+index_val, <identifier>+index_val2 or index value, <value>) // it fills the value from index_val1  to index_val2(doesnt include)
		If we access out of bounds, we may get garbage or segmentation fault.
		To get size of C style array, we can use sizeof(array_identifier)/sizeof(int)

		C++ style arrays: 
			std::array<type,size> identifier = {list of elements}
			to fill all the elements, use identifier.fill(<value>)

	Typedef specifier:
		it is an alias for a datatype.
		ex: typedef int my_int;
		my_int a = 5;
		the datatype of my_int is int. SO basically we are aliasing int with my_int. we can use int/my_int to declare integer variables
		typedef is not compatible with templates
	Using specifier:
		using T = int //type alias
		using is compatible with templates.
		
	Lecture - 4:
	FUNCTIONS:
	In C++ we have 5 types of scopes. 
		Global scope
		Function scope
		Block scope
		Function prototype scope
		Class scope
	Life time is the time duration where an object/variable is in a valid state.
	Function is a group of statements intended for a particular job.
	It improves the readability, Organization, reusability, testing, extensibility, abstraction
	There are two types of function categories. Builtin and User-defined ( Third Party and yours )
	Function prototype:
		return_type identifier(Parameters){
			body
		}
	The header of the funtion is return indentifier and parameters
	The signature is identifier and parameters
	Caller function and called function concept exists in C++
	Call Stack in the VSC helps to understands the hierarchy of called functions. 
	The functions should be declared before the main function ( COMPILER READS THE CODE LIKE A BOOK. IF THE FUNCTION IS AFTER THE MAIN, IT THROWS THE ERROR - FUNTION IS NOT DECLARED IN THE SCOPE)
	Even if we have a function calling another function, that called function should be written above the caller function. We can fix this by using the forward declartion concept.
	So basically we put the prototype and then we write the body later. For assignments and projects, use the function prototypes.
	We can either document the prototype or the function definition. And we need to be consistent. 
	The order doesnt matter if we have prototypes declared. 
	For prototypes, it is not necessary to write the references. i.e int x => here x is not necessary in the prototype. Even if we want to use it, make sure the references match with the references in the function defenition
	Return should be there in both the if and else if we are returning something in the if else statements.
	The parameters in the function are called the formal parameters. 
	The actual parameters/arguments are the ones we are using at the caller function
	we can also use main with int argc and char** argv
	argc gives the number of arguments that we are giving at the console, and argv contains the data.

	Pass By Value or Pass by COPY:
		By default, data passed into a function is passed by value. i.e we are working with a copy of the original value.
	Pass by reference:
		We are working with the original data. We should have the pointer as a reference. 
		Syntax: type& <identifier>
		ex: 
		int num{5};
		int& ref{num};

	
	To preserve the value of function local variables, you can declare variables to be static.
	All static variables persist until program terminates. And they are initialized only once. 
	When we are passing by reference and we dont want to change the data, use a const before the reference. 
	We can also return a reference. Never return a reference to a local variable because the memory will be deallocated and we get undefined behaviour.

	The functions will be called based on
		Perfect match: if the perfect match of the parameters are found for that function call.
		Promotion: promotes short to int etc
		Conversion: converts double to float etc
		Error: if none of the above work 
	We can have some default paramenters(optional parameters) in the functions paramenters.
	Once defined, a default argument cannot be re-defined.
	The default argument can be defined either in the prototype or the function definition.
	If one of the parameter is default, the parameters to the right of it should also be default parameters.

	Function Overloading:
		Function with same name but different formal parameters.
		The return type is not considered for the uniqueness in function overloading.
		The optional parameters are also not considered for the uniqueness.
	In C++ 17, we can initialize the variable in the if statement:
		ex: if(auto result = dummy(2); result>0){
			//code block
		}
	The function calls working:
		Lowest Address -> Higher address order:
			program code -> global/static variables -> dynamic memory(heap) -> unused space -> stack -> local variables (all have fixed space except heap)
		The stack will have the variables etc;
		The dynamic allocation grows upwards when new or smart pointers are invoked.
	Stack Frame(Activation Record):
		Memory mngmt technique.
		Every time a function is called in your program, an individual stack frame is pushed on the stack. It contains actual paramenters, temporary locations, and local variables.
		We may have stack overflow if we use the functional call multiple times. 
	
	Lecture 5:
	Raw Pointers: (Ported from C)
		Smart pointers contain raw pointers i.e they are wrappers. 
		Static memory is used for static and global variables. Memory for these types of variables is allocated once when your program is run and persists throughout the life of your program.
		Automatic memory is allocated for function parameters(pass by value) and local variables. Memory for these types of variables is allocated on stack.
		Dynamic memory allocations is used to request memory from the OS when needed. This is not allocated on the stack but from a much larger pool arranged by OS.
		For big application with large data structures, allocating memory on the stack may lead to a stack overflow. Hence the programmer can explicitly allocate memory on the heap through pointers
		The heap is a region of your computer managed by OS. if we dont release/free memory, it is called memory leak.
		When to use the heap? When we need a lot of memory for data or when we are not sure how much memory you will need.
		Allocating memory on the heap needs to be explicitly performed by the programmer. Hence to allocate data dynamically, we use the scalar(non-array) form of the "new" operator.


		Dereference operator:
		Allows to access a value at a particular address. ex: *(&a) gives the value of a.
		Pointers store address of a memory location and they are variables.
		Pointer is a variable whose value is address of a location.
		The address can be of another variable or function or data with no identifier.
		Pointers are declared using:
			int var{1};
			int *p{&var}; //This is raw pointer
		Pointers are used to operate on C-style arrays efficiently. We can use them to allocate memory on the heap
		They are used in polymorphism
		syntax: type *identifier;
		Good way is to initialize them to "nullptr"
		IMPPPPP: int* ptr1,ptr2 => ptr1 is pointer ptr2 is int. Hence be careful in quizzes
		All pointers must be either null or piont to a valid object. 
		typeid(&a).name() returns the name. ex: Pi (pointer to integer)
		We can change the value using the pointer. 
		The size of a pointer is dependent upon the architecture the executable is compiled for. All pointers in a program have the same size

	NEW operator:
		allocates memory in heap.
		we are supposed to free the memory. Hence when declared, make sure you are freeing the memory.
		Watch slide 38 in lec5 for more info on memory leak.
		Valgrind is an instrumentation framework for building dynamic analysis tools. It comes with tools that can automatically detect memory leak, threading bugs and profile your programs in detail.
		We have to use the executable with valgrind to check the memory leaks. Hence dont run the programs directly.
		To check with valgrind, command is valgrind --leak-check=full ./Lectures      WE SHOULD GET 0 ERRORS FROM 0 CONTECTS AT THE END! THATS THE GOAL
		Hence, we use something like:
			int *ptr{new int};
			*ptr = 5;
			(or)
			int *ptr{new int{5}};
		Deallocating the memory:
			we use delete operator.
			ex:
			delete ptr;
		Delete doesnt delete the pointer variable either. Just like any other variable, a pointer variable is destroyed when it goes out of scope. Delete just frees memory and that memory is available to be used by OS.
	ONLY DELETE WHAT YOU NEW!!!!!!

	Using delete on a pointer that is not pointing to dynamically allocated memory is undefined behaviour.
	Dangling pointer:
		The non-null pointer which points to unallocated (already freed) memory area. 
		They are dangerous only when you dereference or delete it (double delete) -> gives undefined behaviour.
		
		C style arrays dynamic allocation:
		int *array_ptr;
		size_t size;
		array_ptr = new int(size);
		delete [] array_ptr;

	Pointers to constants:
		Syntax: const int* ptr
		The data pointed to by the pointers is constant and cannot be changed.
		=> *ptr = something //doesnt work
	Constant pointers:
		Syntax: int* const ptr
		We cannot re-assign the pointer to other address
	Constant Pointers to Constants:
		Syntax: const int* const ptr
		No data assignment, no change of address
	Pass by pointer:
		Pass a pointer to a function.
		A copy of the pointer is passed to the function.
		The actual parameter can be address or a pointer.
	REMEBER THAT THERE IS NOTHING LIKE STRING POOL IN C++ IF WE USE STD::STRING

	Return a pointer from a function: SAFE WAY:
		int* largest_num(int* num1, int* num2){
			if(*num1>*num2){
				return num1;
			}
			else{
				return num2;
			}
		}
		int *func1(){
			int a{5};
			int *func1_ptr = new int;
			*func1_ptr = a;
			return func1_ptr;
		}
		int main(){
			int* main_ptr{nullptr};
			main_ptr = func1();
			std::cout << *main_ptr << '\n'; //5
			delete main_ptr;
		}
		Never return address/pointer to local variables.

	Iterator:
		std::vector<int> vect = {1,2,3,4,5};
		std::vector<int>::iterator ptr;
		for(ptr = vect.begin(); ptr<vect.end(); ptr++){
			std::cout << *ptr << " ";
		}
	We should avoid raw pointers for allocating dynamic memory at all costs. Hence we will use smart pointers. 
	raw pointers are used for iterators only.
	basically c++ overused the rawpointers.
	
	std::cout << std::string(20,'-'); //Prints ---- for 20 times

	Lecture - 6:
	Smart Pointers:
		Have the memory management on the heap.
		Can be passed to functions
		Can be returned from functions
		They eliminate raw pointers' issues
		Ownership relationship
		Automatic memory deallocation
		std::auto_ptr is removed from c++17
		current smart pinters are std::unique_ptr, std::shared_ptr, std::weak_ptr;
		Smart pointers is an object from STL. And they require #include<memory>
		Can only be used to allocate memory on the heap.
		They are implemented as class templates.
		It is a wrapper around raw pointer.
		Can be deferenced.
		Smart pointers adhere to RAII principle. (deallocated automatically when lifetime ends)
		Syntax:
		unique_ptr<int> ptr {new int(5)};

		NOTE: We should not use the raw pointers to allocate memory in the heap.

		unique_pointer: Only one pointer can be pointed to that memory(no multiple pointers to the same object). It is a scope pointer. Use it for a pointer to memory that gets deleted after the scope
		syntax: std::unique_ptr<T> ptr {new T{value}};
				std::unique_ptr<T> ptr = std::make_unique<T>(value);
				auto ptr = std::make_unique<T>(value);
			Any one of the above three can be used. But better to use the 2nd and 3rd.
		The unique_ptr comes with a set of methods. Notable ones are get, release, reset, swap
		assert: to test the program (debugging)
		assert(smart_ptr.get()==nullptr);
		assert(a==b); //If a != b, then the program stops here with some error messages.
		If we release a smart pointer, we have to catch the raw pointer and delete it, otherwise we will have memory leak.
		smt_ptr.reset() will make it point to null pointer (internally it calls delete for the present pointing object)
		smt_ptr.reset(new int(5)) will make smt_ptr point to the new int object and it internally calls the delete to previously pointing object.
		if there are two smart pointers and we want to switch their pointing objects, we can use .swap() method. 
		ex: smart_ptr1.swap(smart_ptr2);
		std::move moves the ownership/data to the new one. It is used for specific semantics. check slide 23 in lecture 6 main file.

		Passing of smart pointers to functions:
		Check from slides 27 in lecture 6
		We cannot copy a unique pointer. Hence pass the pointer by copy doesn't work. Hence we have to use move.
		We have to use pass by reference for the smart pointers. 
		Go with as simpler raw pointer or a reference when your function just needs to inspect the underlying object or do something with it. Donot delete the pointer. 

		std::shared_ptr is a smart pointer that retains shared ownership of an object through a pointer. i.e, multiple pointers can point to one object. 
		Its memory is deallocated when there are no pointers pointing to the object. 
		We have use_count() method to know that how many pointers are pointing to that particular object.
		
		std::weak_ptr
		This is the non-owning smart pointer that holds a "weak" reference (doesnt increase ref count) to an object that is managed by std::shared_ptr
		It must be converted to shared_ptr to access the shared object.
		Weak pointers can be useful in caching. They can be used to track ( observe ) an object that is managed by std::shared_ptr
		So we need to have a shared ptr to create a weak_ptr.
		notable methods are: lock, expired, use_count (returns the number of shared_ptr objects that manage the memory)
		
	Lecture - 7:
	Time Complexity:
		Algorithm is a set of instructions which tells a computer what to do and how to do it
		Characteristics of choosing an algorithm:
			Readability, no.of local variables, processing time
		Multiplication requires more number of cycles than addition.
		The better approach is to determine the time complexity of each algorithm and choose the best. 
		Time complexity is simplified mathematical way for determining how the processing time increases as the size of the problem (input size) increases.
		Input size is the number of elements in the input.
			no.of elements in a DS
			no. of llines in a file
		To determine the time complexity:
			Use asymptotic analysis to determine the processing time of the algorithm as a function t(n)
		The comparision can be made at large n. for small n values, algorithms may perform almost same
		Usually, the time required by an algorithm to execute falls under:
			Best case(omega): min time rquired for program executuion
			Worst case( Big-O ): worst case time required 
			Avg cost (theeta): Avg time
		Notation O is the formal way to express the upper bound of an algorithms running time. It measures the longest time an algorithm takes.
		The notation theeta is the formal way to express the lower bound and the upper bound of an algorithm running time.
		In programming we will determine the worst case scenario.
		Commonly used rate of growth:
			n! > 2^n > n^p > nlog(n) > n > Sqrt(n) > log(n) > c
		Constant time complexity => it is independent of input => it is ignoring the input.
		log(n) time complexity algorithms are very fast. This one is done using the DIVIDE AND CONQUER.
		For large datasets, quadratic time complexity algorithms should be avoided.
		Nested for loop will have n^2 time complexity. 
		Bruteforce algorithms use exponential time complexity.
		Time complexity of if else:
			take the worst case between if and else.
		Loops have the time complexity of O(n) irrelevant of the addition/substraction incrementor 
			They will have O(log(n) to the base k) time complexity when there is multiplication or division of incrementor by k [because we are using asymptomatically calculating the time complexity]
		Nested Loops: O(mxn) {outer loop n times and inner loop m times} for additive/subtractive incrementor. Basically look at the loops before deciding the Order

	Lecture - 8:
	OOP-1:
		Procedural programming has no security of data available because the variables are available throughout the code.
		Since the focus is on the instructions, it is difficult to relate to real world problems
		There is no hierarchy
		It is difficult to maintain when the code grows larger.
		OOP retains the best features of procedural method adding Abstraction, Encapsulation, Inheritance, Polymorphism.

		Advantages:
			Modularity: With encapsulation, Objects are self-contained and each bit does its own thing
			Reuse of code through inheritance
			Flexibility through polymorphism
			Effective problem solving
			Learning curve
			Design
			Program size: Usually larger and more complex
		OOP IS NOT A SOLUTION FOR EVERYTHING
		Class:
			blueprint that describes behavior/state
			can be user-defined type
			has data mambers
			has function members
			can hide members
			must provide a public interface
		Syntax:
			class identifier{
				//access specifiers
				public:
				protected:
				private:
				
				
				//attributes
				type attribute;

				//Method prototypes
				returntype method(params);

			};
		Object is an instance of class
		Each object has its own identity.

		UML (Unified Modeling Language) is a graphical language for modeling the structure and behavior of oop systems
		It is widely used in industry
		Divided intor threee parts. (class name at top, attributes in middle, methods at last)
		+ for public fields
		# for frotected fields
		- for private fields
		(LUCID CHART - UMD Free providing for student to draw diagrams)
		
		Classes are split into two files.
		Header file(.h) and code file(.cpp)
		Class definitions goes in header files and class implementation goes in code files
		The derived class includes the base class header file
		Code files are compiled and never included. Header files are never compiled but they have to be included in code file
		DOCUMENTATION SHOULD GO IN HEADER FILES but in exceptional cases, we create in cpp file
		.h file is called interface. 
		We usually place .h files in include folder. 
		If we include the header files twice, we will have compiletime error.

		We will have a include guard to avoid multiple include error
		Syntax:
		IN HEADER FILE:
			#ifndef MONSTER_H
			#define MONSTER_H
			class Monster{

			};
			#endif
		IN main.cpp
		#include "monster.h"
		#include "zombie.h" //zombie extends monster which gives compile time error because zombie has monster already included. but we have ifndef which takes care of multiple includes

		It is highly recommended to enclose your class in a namespace to avoid any naming clash. (in header file)
		namespace rpg{
			include guard
			class Monster{

			};
			#endif
		}
		
		to implement:
		1)
		using namespace rpg;
		returntype Monster:: etc

		2)
		namespace rpg{
			returntype Monster::
		}

		3)
		returntype rpg::Monster::

		We are going to test the class in main.cpp
		
		IF no access modifier is specified before, they are private by default
		IN OOP Attributes must be made private(because of encapsulation)
		Accessors (getters) should provide read-only access to data. Therefore, they should return by value or const refernce(never by non-const reference)
		Mutator is a setter
		Abstraction is also called implementation hiding.
		It is a mechanism which represents the eential features without including the implementation details
		Encapsulation is a subset of abstraction
		Abstraction seperates code into interface(.h files) and implementation(.cpp )files. 

		Constructor:
			It is a public method that is called when an object is created
			COnstructor without any parameters passed is called default constructor
			If we dont write any constructor, compiler provides a default consructor and initializes them if they are from stl library
			However if you provide one, compiler no longer provides a default constructor
			Syntax:
			public:
			Classname(){

			}

	VVV IMPORTANT:	Variables in the initializer list are not initialized in the order that they are specified in the initializer list. Instead, they are initialized in the order in which they are declared in the class.
		Hence use proper member initialization list which is just before the paranthesis of constructor
		ex:
		Monster(params):
		Member initializations,
		{

		}
		Best practice is to have member initialization list
	
	Lecture-9:
		Destructor is a special method which is executed when an object goes out of scope. It is not required generally. But some situations require it (like raw pointer allocating memory on heap)
		Must have same name as class and must preceded by a tilde, no return type, no parameters
		Ex:
		~Monster(){
			std::cout<<"Destructor called"
		}
		Explicit keyword prevents the compiler from using that constructor for implicit converstions.
		Best practice: use explicit whenever there is a constructor with only one parameter. 
		const objects: Ensure that no attributes of the object are changed during the objects' lifetime
		const methods: methods called for const objects must also be declared as const.

		Rules:
			object const => method called should be const
			const method can be called on sonct and non const objects
			the const specifier must appear in both method definition and implementation
			IMP Best Practice: Accessors(Getters) must be const

		Each time a copy needs to be made, the compiler uses a copy constructor.
		Compiler provides one if we dont provide one. 
		The copy constructor uses shallow copy
		We have problems when we use shallow copy with pointers( double delete ). Hence we need to have a deep copy in copy constructor.
		When we have raw pointers allocating memory in heap, we need to delete that in destructor. 

		When we have raw pointer allocating memory on the heap (Rule of Three):
			Destructor to deallocate memory
			A copy constructor
			A copy assignment operator
		
	Lecture-10:
		Friend functions and classes: Another way to do encapsulation
		Accessors and mutators make complex codes. friend function or friend class makes the function or class to access the data members
		ex:
			class A{
				friend void f(const A&);
			};
			class A{
				friend void B::g(const A&);
			};
			class A{
				friend class B; //all methods of B can access all members of A
			}
		It doesn't matter if the members are private/public/protected

		this friend function is implemented outside of the class but declared inside the class //incase of friend function
		IMPORTANT: We have to prototype the classes as well.

		Operator overloading:
		overloaded operators are functions with special names: the keyword operators followed by symbol
		They are methods. There are some cases where operator methods are not methods but friends of class

		There are some rules for operator overloading. Slide 11 in lec10
		Overloading biniary operator:
		int main(){
			A a1;
			Aa2;
			a1 <X> a2; //<X> is the binary operator
			basically it is same as a1.<X>(a2)
		}
		Type operator<X>(A&rhs){

		}

		The compiler provides = operator method for the same class objects


		Inheritance:
			is_a relationship
			base class/ parent class/ super class

			Derived/child/sub class derive/inherit/extend the parent class
			Inherited members are represented with ^ symbol
			Derived class attributes (denoted with / symbol)
			Protected members are specified with # symbol in the documentation

			5 types:
				single
				multiple
				hierarchial
				hybrid
				multi level

			We can derive a class with multiple access modifiers
			default inheritance will be private inheritance
			Commonly we use public inheritance

			child calls the parent class constructor before executing its own constructor.

			To initialize the super class, we can call the super class constructor in the member initialization list of the derived class constructor
			
			IMP:: NOTE THAT THE default parameters should be declared either in the prototype of implementation. Having them at header file is prefered.
			Static polymorphism is used by default.
			
			Runtime polymorphism is possible with Inherited classes, pointer or reference to a base class, virtual methods

			For dynamic polymorphism, we need to declare the function as virtual. (V IMP)

			Virtual specifier specifies that a non static method is virtual and supports dynamic polymorphism by overriding base class methods
			A virtual method is declared within baseclass.

			If we are refering to derived class using a base class reference, we may need to use the virtual keyword.
			Best practice is to make the derived class methods as well to virtual. 

			If a class has virtual destructor, then we have to define a virtual destructor as well in all the derived classes.
			
			Override:
			override specifier (used for virtual methods and in derived class)
			Important: We cannot override a non virtual method

			Final:
			final keyword makes the class non derivable and final methods are not overridable but they can be overloadable.

			Abstract:
			We cannot create an object from the abstract class. We have to have a pure virtual method in the class to make the class abstract.
			Ex:
				Have a method:
				virtual void take_damage()=0;
				Generally we provide the prototypes in the h file for abstract class. Nothing in the implementation. But we can implement some if required.
				If the derived class doesnt implement the pure virtual method, the derived class also be virtual.

			Concrete class;
				A concrete class is a class that has the implementation of all the methods of the base class.
				We can create the objects.

	Lecture 11:
		Bash:
			Aliases: alias <alias_name> = "command to run"
			ex: alias .. = "cd .."

		ROS:
			NODE:
				c++ or python program within a catkin package that executes simple task
				ex: Node /lidar which reads sensor data and another node /control which controls a robot actuators based on the data received from /lidar
				Nodes communicate with each other by publishing messages to topics and reading messages from topics.
			Message:
				It is a packet of data. They are strongly typed
			Topic:
				It is a named bus over which nodes exchange messages.
				Topics have anonymous publish/subscribe semantics
			There can be multiple subs and pubs to a topic.

			Publisher can initiate a topic if it is not available. The subscriber cannot initiate a topic

			Catkin_Package:
				A catkin package MUST be created in the src folder of your catkin workspace
	
	Lecture 12:
		rqt_graph:
			gives the graph of topics and nodes with pub sub arrows
		
		rostopic type <topic_name>: gives the type and messages used
		rospack find <package_name>: gives whether that package is installed or not
		rostopic info <topic_name>: gives more infor specfic to that topic. which topics are publishing, which topics are subscribed
		To know more about the messages: use the rosmsg show <message name> 
		rostopic pub -r <rate> <topic> <message_type> 'data'
		ROS Logging:
			ROS_DEBUG_STREAM: to see if the system is working properly and not required for application user
			INFO: info useful to user <use this while doing assignments>
			WARN: info that the user may find alarmiong and may affect the output
			ERROR: something serious and recoverable happened
			FATAL: something serious and not recoverable happened

		rqt_console:
			Same as the terminal, it shows the info printed on console but it is more feasible to filter the type of printed info and who prints it
		
		rosdep install <package_name>: installs the dependencies that are missed in that package

		The list of dependencies needed for a given package is located in package.xml

		<IMPORTANT: EDIT THE package.xml of catkin package for final project>
			description
			maintainer
			uncomment author and edit 
	Lecture 13:
		Subscriber does not know when message will arrive on a topic
		Hence we use callback function.
		Call back is any executable code that is passed as an argument to other code; that other code is expected to call back the argument at given time
		During call back, you donot call yourself, you define it yourself.
		Usually, you pass the function pointer to another component that will call your function when it seems appropriate
		For call backs to be executed in ROS, we need to have ros::spin() function
		It basically creates a thread. Hence it should be written at the last. 
		ros::spinOnce() only executes callback time to time and returns the control back to us. It is not blocking in nature.
		ros::spin() will exececute the callback whenever there is data. It needs to be shut down by rosmaster or using ctrl+c
		=>	while(ros::ok()){
			ros::spinOnce();
		} is equivalent to ros::spin()

		We should not omit the ros::spin() or ros::spinOnce() otherwise the callback doesn't work

		IMPORTANT:
		For everypackage, the executable name is found in the CmakeLists or we can change the add executable field to change the node name
		To write the launch file,
		We need name: name of the node (found in the .cpp file at ros::init( 3rd argument ))
				type: name of the executable (found in the cmakeLists)
				pkg : name of the package
				output: "screen" to display on the console
		
		We can include other launch files in a launch file using
		<include file = "<path of the file>"

		A key requirement in robotics is to keep track of the positions and velocities of objects
		In general, the location of an object in 3D space can be specified by its positon and orientation values.
		We can use quaternions 
		We use Right Handed Rule.

		TF package:
			ROS TF gives the transformation between two frames
			TF is very very important for robotics
			There are two types
			Publisher(broadcaster):
				Publish transforms between coordinate frames on the /tf Topic
				This allow us to setup our own relationship between two coordinate frames
			Subscriber (or listener):
				Listen to the /tf Topic to get transforms between frames
			
			IMP: Messages are delimeted with ---
			rosrun tf tf_echo /odom /camera_rgb_frame - gives the transformation between the two frames
			
		Lecture-14:
			We use the principle of time of flight for the calculation of distance
			LIDAR - Light Inspection, Detection and Ranging
			LIDAR data is published on the /scan Topic by Gazebo
			We need not have Gazebo/Rviz running to run rosmsg show <message_type>

			Robotic mapping addresses the problem of acquiring spatial models of physical environemts through mobile robots
			The purpose is to navigation
			SLAM - Simulatneously Localization and Mapping is the most wellknown tech for indoor mapping
			The robot builds a map representing its spatial environment while keeping track of its position within the built map

			Most well-known mapping packages that became available in ROS is gmapping.
			It has slam_gmapping which provides laser-based SLAM

			Initially the robot is not localized when the simulation starts.
			We can help /amcl node localize the robot using one of the three:
				start moving the robot programmatically (publish data to /cmd_vel) so /amcl can retrieve data from env
				Use 2D pose estimate feature in rviz to get pose estimation
				Since we are spawning the robot, we can pass this info to /amcl node as an initial pose.
				Take a look at [start_navigation.launch] how it calls [start_amcl.launch]

			IMP: move_base package does the autonomous nav
			planners: the move_base node links together a global and local planners to accomplish its global navigation task
			Costmaps: The move_base node also maintains two costmaps, one for the global planner, and one for a local planner that are used to accomplish nav tasks
				



			


		


	*/

}