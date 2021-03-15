#pragma once
// 元编程的主要组件是元函数， 元函数实际表现类似于c++中的class，模板类或者模板函数：
// 因为元函数的执行是在编译期间完成的，在应用程序实际启动后，没有进行元函数的调用而是直接使用编译器的计算结果
// 所以元函数只处理元数据，即编译器常量和类型，元函数中存在运行时变量和类型是编译不过的

// 元函数要求： 无副作用

// 编译期 和 运行期
// 运行期语法： if else for

// 元函数中可以使用的语法比较有限：
/* enum, static const, 用来定义编译期间的整数常量
	typedef/using, 用于定义元数据
	T，Args..., 主要用于定义元函数
	template, 主要用于定义元函数
	::, 域运算符，用于解析类型作用域获取计算结果（元数据）
*/

/*
	如果在元编程中需要用到if else，可以用type_traits来替代，他不仅可以在编译期间做判断，还可以做计算，查询，转换和选择
	元编程中的for逻辑可以通过递归，重载和模板特化（偏特化）等方法实现
*/


namespace meta_function {

	template<typename T, typename S>
	struct meta_func
	{
		static const int value = T + S;
	};

	// << c++模板元编程 >>------------
	// 将一个包含了type声明的类模板称为元函数
	// 元函数的输入输出均是类型
	// << c++模板元编程 >>------------

	template<typename T>
	// todo(yshi): 这里struct后面不接参数列表表示什么？
	struct Func_
	{
		// 使用using定义元数据
		using type = T;
	};

	// 对int和long类型的typename 做特化
	template<>
	struct Func_<int>
	{
		using type = unsigned int;
	};

	template<>
	struct Func_<long>
	{
		using type = unsigned long;
	};


	template<typename T>
	// typename 表明Func_<T>::type是一个类型，而不是静态数据，避免了二义性所做的规定，是c++规范中书写要求
	using Func = typename Func_<T>::type;


	// todo(yshi): the different between class and typename while in tempalte programing
	template<class T, T v>
	struct integral_constant
	{

	};

	using one_type = std::integral_constant<int, 1>;

	template<class T>
	struct one_type : std::integral_constant<int, 1> {};


	template<>
	struct Func_<int>
	{
		using reference_type = int&;
		using const_reference_type = const int&;
		using value_type = int;
	};



	// type_traits
	/*
		c++11引入的元函数库，由boost引入，实现了类型变换，类型比较和判断等功能
		依赖头文件: #include <type_traits>
	*/

#include <type_traits>
	std::remove_reference<int&>::type h1 = 3;
	// todo(yshi): std::remove_reference_t 编译不通过
	// std::remove_reference_t<int&>::type h2 = 3;

	/* macro： 宏也可以被理解为一类特殊的元函数。一般在讨论c++时，元函数指的是constexpr修饰的函数和模板构造的函数，并不包括宏
			   因为macro实际上是由预处理器来解析，而不是由编译器编译的。所以很多编译期间可以用到的特性，宏是无法利用的
	*/

	// 宏的不好的主要一方面是，导致名字空间完全失效，c++中专门用来解决冲突问题的namespace也无济于事。所以代码中最好少用宏
	// 但是在某些情况下，宏拥有自己的特殊优势，注意把握

	// name foramt in meta program
	// 如果元函数的返回值可以直接使用某种非依赖型的名称表示，那么元函数中将不包含下划线形式的后缀
	template<int a, int b>
	struct Add_
	{
		constexpr static const value = a + b;
	};

	template<int a, int b>
	constexpr int Add = a + b;

	constexpr int x1 = Add_<2, 3>::value;
	constexpr int x2 = Add<2, 3>;


	// 元函数可以操作类型和数值，对于元函数来说，类型和数值并没有本质的区别。事实上，c++元函数可以操作的数据包括3类
	// 数值，类型和模板，他们统称为 '元数据'，以区别于运行时所操作的 '数据'。

	// 模板作为元函数的输入
	// 如果元函数类比为数学中的函数，那么当前这种类型： 模板作为元函数的操作类型，可以理解为复合函数
	template <template <typename> class T, typename T2>
	struct Fun_
	{
		using type = typename T1<T2>::type;
	};

	template <template <typename> class T1, typename T2>
	using Fun = typename Fun_<T1, T2>::type;

	Fun<std::remove_reference, int&> h = 3;

	// 模板作为元函数的输出

	template<typename T>
	// todo(yshi): 这里struct后面不接参数列表表示什么？
	struct Func3_
	{
		// 使用using定义元数据
		using type = T;
	};
	template <bool AddOrRemoveRef> struct Func3_;

	template <>
	struct Func3_<true>
	{
		template <typename T>
		using type = std::add_lvalue_reference<T>;
	};

	template <>
	struct Func3_<false>
	{
		template <typename T>
		using type = std::remove_reference<T>;
	};

	template <typename T>
	template <bool AddOrRemove>
	using Func3 = typename Func3_<AddOrRemove>::tempalte::type;

	template <typename T>
	using Res_ = Func3<false>;

	Res_<int&>::type h = 3;
	// 元编程中习惯，仅在必要时才引入定义，其他的时候直接使用声明即可

	// 容器模板
	template <int... vals> struct IntContainer;
	template <bool... vals> struct BoolContainer;

	template <typename... vals> struct TypeContainer;

	template <template <typename>  class...T> struct TemplateCotainer;


	// 编译期间元函数，顺序分支和循环代码的编写

	template <typename T>
	struct RemoveReferenceConst_
	{
	private:
		using inter_type = typename std::remove_reference<T>::type;

	public:
		using type = typename std::remove_const<inter_type>::type;
	};

	template <typename T>
	using RemoveReferenceConst = typename RemoveReference_<T>::type;

	RemoveReferenceConst<const int&> h = 3;
};  // end namespace meta_function
