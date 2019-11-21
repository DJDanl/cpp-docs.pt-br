---
title: C++ type system
ms.date: 11/19/2019
ms.topic: conceptual
ms.assetid: 553c0ed6-77c4-43e9-87b1-c903eec53e80
ms.openlocfilehash: 1f12f7505438dc995aaf8a045fd903488e9ff092
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246597"
---
# <a name="c-type-system"></a>C++ type system

The concept of *type* is very important in C++. Cada variável, argumento de função e valor de retorno de função deve ter um tipo para ser compilado. Além disso, cada expressão (incluindo valores literais) recebe implicitamente um tipo do compilador antes de ser avaliada. Some examples of types include **int** to store integral values, **double** to store floating-point values (also known as *scalar* data types), or the Standard Library class [std::basic_string](../standard-library/basic-string-class.md) to store text. You can create your own type by defining a **class** or **struct**. O tipo especifica a quantidade de memória que será atribuída à variável (ou o resultado da expressão), os tipos de valores que podem ser armazenados nessa variável, como os valores (como padrão de bits) são interpretados e as operações que podem ser executadas nele. Este artigo contém uma visão geral informal dos principais recursos do sistema de tipos C++.

## <a name="terminology"></a>Terminologia

**Variable**: The symbolic name of a quantity of data so that the name can be used to access the data it refers to throughout the scope of the code where it is defined. In C++, *variable* is generally used to refer to instances of scalar data types, whereas instances of other types are usually called *objects*.

**Object**: For simplicity and consistency, this article uses the term *object* to refer to any instance of a class or structure, and when it is used in the general sense includes all types, even scalar variables.

**POD type** (plain old data): This informal category of data types in C++ refers to types that are scalar (see the Fundamental types section) or are *POD classes*. Uma classe POD não tem membros de dados estáticos que também não sejam PODs e não tem construtores definidos pelo usuário, destruidores definidos pelo usuário ou operadores de atribuição definidos pelo usuário. Além disso, uma classe POD não tem função virtual, nenhuma classe base e nenhum membro de dados não estático particular ou protegido. Os tipos POD são quase sempre usados para a troca de dados externos, por exemplo, com um módulo escrito na linguagem C (que tem apenas tipos POD).

## <a name="specifying-variable-and-function-types"></a>Especificando tipos de variável e de função

C++ is a *strongly typed* language and it is also *statically-typed*; every object has a type and that type never changes (not to be confused with static data objects).
**When you declare a variable** in your code, you must either specify its type explicitly, or use the **auto** keyword to instruct the compiler to deduce the type from the initializer.
**When you declare a function** in your code, you must specify the type of each argument and its return value, or **void** if no value is returned by the function. A exceção se dá quando você está usando modelos de função, que permitem argumentos de tipos arbitrários.

Após a primeira declaração de uma variável, você não pode alterar seu tipo em um momento posterior. No entanto, você pode copiar o valor da variável ou o valor de retorno de uma função para outra variável de tipo diferente. Such operations are called *type conversions*, which are sometimes necessary but are also potential sources of data loss or incorrectness.

Ao declarar uma variável do tipo POD, é altamente recomendável inicializá-la, ou seja, dar a ela um valor inicial. Até que você inicialize uma variável, ela terá o valor “garbage”, que consiste nos bits que estavam nesse local de memória anteriormente. Esse é um aspecto importante da linguagem C++ a ser lembrado, especialmente se você estiver vindo de outra linguagem que manipule a inicialização para você. Ao declarar uma variável do tipo de classe não POD, o construtor manipula a inicialização.

O exemplo a seguir mostra algumas declarações de variável simples com algumas descrições para cada uma. O exemplo também mostra como o compilador usa informações de tipo para permitir ou não permitir determinadas operações subsequentes na variável.

```cpp
int result = 0;              // Declare and initialize an integer.
double coefficient = 10.8;   // Declare and initialize a floating
                             // point value.
auto name = "Lady G.";       // Declare a variable and let compiler
                             // deduce the type.
auto address;                // error. Compiler cannot deduce a type
                             // without an intializing value.
age = 12;                    // error. Variable declaration must
                             // specify a type or use auto!
result = "Kenny G.";         // error. Can’t assign text to an int.
string result = "zero";      // error. Can’t redefine a variable with
                             // new type.
int maxValue;                // Not recommended! maxValue contains
                             // garbage bits until it is initialized.
```

## <a name="fundamental-built-in-types"></a>Tipos (internos) fundamentais

Ao contrário de algumas linguagens, C++ não tem tipo base universal do qual todos os outros tipos são derivados. The language includes many *fundamental types*, also known as *built-in types*. This includes numeric types such as **int**, **double**, **long**, **bool**, plus the **char** and **wchar_t** types for ASCII and UNICODE characters, respectively. Most fundamental types (except **bool**, **double**, **wchar_t** and related types) all have unsigned versions, which modify the range of values that the variable can store. For example, an **int**, which stores a 32-bit signed integer, can represent a value from -2,147,483,648 to 2,147,483,647. An **unsigned int**, which is also stored as 32-bits, can store a value from 0 to 4,294,967,295. O número total de valores possíveis em cada caso é o mesmo; somente o intervalo é diferente.

Os tipos fundamentais são reconhecidos pelo compilador, que tem regras internas que controlam que operações você poderá executar neles e como eles serão convertidos em outros tipos fundamentais. For a complete list of built-in types and their size and numeric limits, see [Fundamental Types](../cpp/fundamental-types-cpp.md).

A ilustração a seguir mostra os tamanhos relativos dos tipos internos:

![Size in bytes of built&#45;in types](../cpp/media/built-intypesizes.png "Size in bytes of built&#45;in types")

A tabela a seguir lista os tipos fundamentais usados com mais frequência:

|Digite|Tamanho|Comentário|
|----------|----------|-------------|
|int|4 bytes|A opção padrão para valores integrais.|
|double|8 bytes|A opção padrão para valores de ponto flutuante.|
|bool|1 byte|Representa valores que podem ser true ou false.|
|char|1 byte|Use os caracteres ASCII em cadeias de caracteres do estilo C mais antigo ou objetos std::string que nunca precisarão ser convertidos em UNICODE.|
|wchar_t|2 bytes|Representa os valores de caractere "largos" que podem ser codificados no formato UNICODE (UTF-16 no Windows, outros sistemas operacionais podem ser diferentes). Esse é o tipo de caractere usado em cadeias de caracteres do tipo `std::wstring`.|
|unsigned&nbsp;char|1 byte|O C++ não tem o tipo `byte` interno.  Use unsigned char para representar um valor de bytes.|
|unsigned int|4 bytes|Escolha padrão para sinalizadores de bit.|
|long long|8 bytes|Representa valores inteiros muito grandes.|

## <a name="the-void-type"></a>O tipo void

The **void** type is a special type; you cannot declare a variable of type **void**, but you can declare a variable of type __void \*__ (pointer to **void**), which is sometimes necessary when allocating raw (un-typed) memory. However, pointers to **void** are not type-safe and generally their use is strongly discouraged in modern C++. In a function declaration, a **void** return value means that the function does not return a value; this is a common and acceptable use of **void**. While the C language required functions that have zero parameters to declare **void** in the parameter list, for example, `fou(void)`, this practice is discouraged in modern C++ and should be declared `fou()`. For more information, see [Type Conversions and Type Safety](../cpp/type-conversions-and-type-safety-modern-cpp.md).

## <a name="const-type-qualifier"></a>Qualificador do tipo const

Qualquer tipo interno ou definido pelo usuário pode ser qualificado pela palavra-chave const. Additionally, member functions may be **const**-qualified and even **const**-overloaded. The value of a **const** type cannot be modified after it is initialized.

```cpp

const double PI = 3.1415;
PI = .75 //Error. Cannot modify const variable.
```

The **const** qualifier is used extensively in function and variable declarations and "const correctness" is an important concept in C++; essentially it means to use **const** to guarantee, at compile time, that values are not modified unintentionally. For more information, see [const](../cpp/const-cpp.md).

A **const** type is distinct from its non-const version; for example, **const int** is a distinct type from **int**. You can use the C++ **const_cast** operator on those rare occasions when you must remove *const-ness* from a variable. For more information, see [Type Conversions and Type Safety](../cpp/type-conversions-and-type-safety-modern-cpp.md).

## <a name="string-types"></a>Tipos de cadeia de caracteres

Strictly speaking, the C++ language has no built-in string type; **char** and **wchar_t** store single characters - you must declare an array of these types to approximate a string, adding a terminating null value (for example, ASCII `'\0'`) to the array element one past the last valid character (also called a *C-style string*). As cadeias de caracteres de estilo C exigiam que muito mais códigos fossem escritos ou o uso de funções da biblioteca de utilitários de cadeia de caracteres externos. But in modern C++, we have the Standard Library types `std::string` (for 8-bit **char**-type character strings) or `std::wstring` (for 16-bit **wchar_t**-type character strings). These C++ Standard Library containers can be thought of as native string types because they are part of the standard libraries that are included in any compliant C++ build environment. Basta usar a diretiva `#include <string>` para tornar esses tipos disponíveis em seu programa. (If you are using MFC or ATL, the CString class is also available, but is not part of the C++ standard.) The use of null-terminated character arrays (the C-style strings previously mentioned) is strongly discouraged in modern C++.

## <a name="user-defined-types"></a>Tipos definidos pelo usuário

When you define a **class**, **struct**, **union**, or **enum**, that construct is used in the rest of your code as if it were a fundamental type. Ele tem um tamanho conhecido na memória e certas regras sobre como pode ser usado aplicado para verificar o tempo de compilação e, no runtime, para a vida útil de seu programa. As principais diferenças entre os tipos internos fundamentais e os tipos definidos pelo usuário são:

- O compilador não tem conhecimento interno de um tipo definido pelo usuário. It learns of the type when it first encounters the definition during the compilation process.

- Você especifica que operações podem ser executadas em seu tipo, e como ele pode ser convertido em outros tipos, definindo (por meio de sobrecarga) os operadores apropriados, como membros de classe ou funções de não membro. For more information, see [Function Overloading](function-overloading.md)

## <a name="pointer-types"></a>Tipos de ponteiro

Desde as primeiras versões da linguagem C, o C++ continua permitindo que você declare uma variável de um tipo de ponteiro usando o declarador especial `*` (asterisco). Um tipo de ponteiro armazena o endereço do local na memória em que o valor real de dados é armazenado. In modern C++, these are referred to as *raw pointers*, and are accessed in your code through special operators `*` (asterisk) or `->` (dash with greater-than). This is called *dereferencing*, and which one that you use depends on whether you are dereferencing a pointer to a scalar or a pointer to a member in an object. O trabalho com tipos de ponteiro foi durante muito tempo um dos aspectos mais desafiadores e confusos do desenvolvimento de programas em C e C++. This section outlines some facts and practices to help use raw pointers if you want to, but in modern C++ it’s no longer required (or recommended) to use raw pointers for object ownership at all, due to the evolution of the [smart pointer](../cpp/smart-pointers-modern-cpp.md) (discussed more at the end of this section). Ainda é útil e seguro usar ponteiros brutos para observar objetos, mas se você tiver de usá-los para a propriedade de objeto, faça isso com muito cuidado e considerando como os objetos possuídos por eles são criados e destruídos.

A primeira coisa que você deve saber é que a declaração de uma variável de ponteiro bruto alocará somente a memória necessária para armazenar um endereço do local da memória a que o ponteiro fará referência quando sua referência for removida. Allocation of the memory for the data value itself (also called *backing store*) is not yet allocated. Ou seja, declarando uma variável de ponteiro bruto, você está criando uma variável do endereço de memória, não uma variável de dados real. Remover a referência de uma variável de ponteiro antes de verificar se ela contém um endereço válido para um repositório de backup causará um comportamento indefinido (geralmente um erro fatal) em seu programa. O exemplo a seguir demonstra esse tipo de erro:

```cpp
int* pNumber;       // Declare a pointer-to-int variable.
*pNumber = 10;      // error. Although this may compile, it is
                    // a serious error. We are dereferencing an
                    // uninitialized pointer variable with no
                    // allocated memory to point to.
```

O exemplo remove a referência de um tipo de ponteiro sem ter memória alocada para armazenar os dados inteiros reais ou um endereço de memória válido atribuído a ele. O código a seguir corrige esses erros:

```cpp
    int number = 10;          // Declare and initialize a local integer
                              // variable for data backing store.
    int* pNumber = &number;   // Declare and initialize a local integer
                              // pointer variable to a valid memory
                              // address to that backing store.
...
    *pNumber = 41;            // Dereference and store a new value in
                              // the memory pointed to by
                              // pNumber, the integer variable called
                              // "number". Note "number" was changed, not
                              // "pNumber".
```

O exemplo de código corrigido usa a memória de pilha local para criar o repositório de backup para o qual `pNumber` aponta. Usamos um tipo fundamental para simplificar. In practice, the backing store for pointers are most often user-defined types that are dynamically-allocated in an area of memory called the *heap* (or *free store*) by using a **new** keyword expression (in C-style programming, the older `malloc()` C runtime library function was used). Once allocated, these variables are usually referred to as objects, especially if they are based on a class definition. Memory that is allocated with **new** must be deleted by a corresponding **delete** statement (or, if you used the `malloc()` function to allocate it, the C runtime function `free()`).

However, it is easy to forget to delete a dynamically-allocated object- especially in complex code, which causes a resource bug called a *memory leak*. Por esse motivo, o uso de ponteiros brutos é altamente desaconselhável em C++ moderno. It is almost always better to wrap a raw pointer in a [smart pointer](../cpp/smart-pointers-modern-cpp.md), which will automatically release the memory when its destructor is invoked (when the code goes out of scope for the smart pointer); by using smart pointers you virtually eliminate a whole class of bugs in your C++ programs. No exemplo a seguir, suponha que `MyClass` seja um tipo definido pelo usuário que tem um método público `DoSomeWork();`

```cpp
void someFunction() {
    unique_ptr<MyClass> pMc(new MyClass);
    pMc->DoSomeWork();
}
  // No memory leak. Out-of-scope automatically calls the destructor
  // for the unique_ptr, freeing the resource.
```

For more information about smart pointers, see [Smart Pointers](../cpp/smart-pointers-modern-cpp.md).

For more information about pointer conversions, see [Type Conversions and Type Safety](../cpp/type-conversions-and-type-safety-modern-cpp.md).

For more information about pointers in general, see [Pointers](../cpp/pointers-cpp.md).

## <a name="windows-data-types"></a>Tipos de dados do Windows

Na programação Win32 clássica para C e C++, a maioria das funções usa typedefs e macros #define específicas do Windows (definidas em `windef.h`) para especificar os tipos de parâmetros e valores de retorno. These Windows data types are mostly just special names (aliases) given to C/C++ built-in types. For a complete list of these typedefs and preprocessor definitions, see [Windows Data Types](/windows/win32/WinProg/windows-data-types). Alguns desses typedefs, como HRESULT e LCID, são úteis e descritivos. Outros, como INT, não têm significado especial e são apenas aliases para tipos C++ fundamentais. Outros tipos de dados do Windows têm nomes que foram mantidos desde a época da programação em C e de processadores de 16 bits, e não têm finalidade ou significado em hardware ou sistemas operacionais modernos. There are also special data types associated with the Windows Runtime Library, listed as [Windows Runtime base data types](/windows/win32/WinRT/base-data-types). Em C++ moderno, a orientação geral é dar preferência aos tipos C++ fundamentais, a menos que o tipo do Windows comunique qualquer significado adicional sobre como o valor deve ser interpretado.

## <a name="more-information"></a>Mais informações

Para obter mais informações sobre o sistema de tipos C++, consulte os tópicos a seguir.

|||
|-|-|
|[Tipos de valor](../cpp/value-types-modern-cpp.md)|Describes *value types* along with issues relating to their use.|
|[Type Conversions and Type Safety](../cpp/type-conversions-and-type-safety-modern-cpp.md)|Descreve problemas de conversão de tipos comuns e mostra como evitá-los.|

## <a name="see-also"></a>Consulte também

[Welcome back to C++](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)
