---
title: Funções &lt;exception&gt;
ms.date: 11/04/2016
f1_keywords:
- exception/std::current_exception
- exception/std::get_terminate
- exception/std::get_unexpected
- exception/std::make_exception_ptr
- exception/std::rethrow_exception
- exception/std::set_terminate
- exception/std::set_unexpected
- exception/std::terminate
- exception/std::uncaught_exception
- exception/std::unexpected
ms.assetid: c09ac569-5e35-4fe8-872d-ca5810274dd7
helpviewer_keywords:
- std::current_exception [C++]
- std::get_terminate [C++]
- std::get_unexpected [C++]
- std::make_exception_ptr [C++]
- std::rethrow_exception [C++]
- std::set_terminate [C++]
- std::set_unexpected [C++]
- std::terminate [C++]
- std::uncaught_exception [C++]
- std::unexpected [C++]
ms.openlocfilehash: 849f3c8406c43b0efc2d34837e00fee6ff64e52a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87193777"
---
# <a name="ltexceptiongt-functions"></a>Funções &lt;exception&gt;

## <a name="current_exception"></a><a name="current_exception"></a>current_exception

Obtém um ponteiro inteligente para a exceção atual.

```cpp
exception_ptr current_exception();
```

### <a name="return-value"></a>Valor retornado

Um objeto [exception_ptr](../standard-library/exception-typedefs.md#exception_ptr) que aponta para a exceção atual.

### <a name="remarks"></a>Comentários

Chame a função `current_exception` em um bloco catch. Se uma exceção estiver em voo e o bloco catch puder capturar a exceção, a função `current_exception` retornará um objeto `exception_ptr` que faz referência à exceção. Caso contrário, a função retornará um objeto `exception_ptr` nulo.

A `current_exception` função captura a exceção que está em trânsito, independentemente de a **`catch`** instrução especificar uma instrução [de declaração de exceção](../cpp/try-throw-and-catch-statements-cpp.md) .

O destruidor para a exceção atual será chamado no final do **`catch`** bloco se você não relançar a exceção. No entanto, mesmo que você chame a função `current_exception` no destruidor, a função retornará um objeto `exception_ptr` que faz referência à exceção atual.

As chamadas sucessivas à função `current_exception` retornam objetos `exception_ptr` que se referem a diferentes cópias da exceção atual. Consequentemente, os objetos são comparados como diferentes, pois se referem a diferentes cópias, mesmo quando as cópias têm o mesmo valor binário.

## <a name="make_exception_ptr"></a><a name="make_exception_ptr"></a>make_exception_ptr

Cria um objeto [exception_ptr](../standard-library/exception-typedefs.md#exception_ptr) que mantém a cópia de uma exceção.

```cpp
template <class E>
    exception_ptr make_exception_ptr(E Except);
```

### <a name="parameters"></a>parâmetros

*Excepção*\
A classe com a exceção a ser copiada. Normalmente, você especifica um objeto de [classe de exceção](../standard-library/exception-class.md) como o argumento para a função `make_exception_ptr`, embora qualquer objeto de classe possa ser o argumento.

### <a name="return-value"></a>Valor retornado

Um objeto [exception_ptr](../standard-library/exception-typedefs.md#exception_ptr) que aponta para uma cópia da exceção atual para *, exceto*.

### <a name="remarks"></a>Comentários

Chamar a função `make_exception_ptr` é equivalente a lançar uma exceção C++, capturá-la em um bloco catch e chamar a função [current_exception](../standard-library/exception-functions.md#current_exception) para retornar um objeto `exception_ptr` que faça referência à exceção. A implementação da função `make_exception_ptr` da Microsoft é mais eficiente do que lançar e depois capturar uma exceção.

Geralmente, um aplicativo não exige a função `make_exception_ptr` e não recomendamos seu uso.

## <a name="rethrow_exception"></a><a name="rethrow_exception"></a>rethrow_exception

Lança uma exceção passada como um parâmetro.

```cpp
void rethrow_exception(exception_ptr P);
```

### <a name="parameters"></a>parâmetros

*DTI*\
A exceção capturada para relançamento. Se *P* for um [exception_ptr](../standard-library/exception-typedefs.md#exception_ptr)nulo, a função lançará [std:: bad_exception](../standard-library/bad-exception-class.md).

### <a name="remarks"></a>Comentários

Depois de armazenar uma exceção capturada em um objeto `exception_ptr`, o thread primário poderá processar o objeto. Em seu thread primário, chame a função `rethrow_exception` juntamente com o objeto `exception_ptr` como seu argumento. A função `rethrow_exception` extrai a exceção do objeto `exception_ptr` e a lança no contexto do thread primário.

## <a name="get_terminate"></a><a name="get_terminate"></a>get_terminate

Obtém a função `terminate_handler` atual.

```cpp
terminate_handler get_terminate();
```

## <a name="set_terminate"></a><a name="set_terminate"></a>set_terminate

Estabelece um novo `terminate_handler` a ser chamado na finalização do programa.

```cpp
terminate_handler set_terminate(terminate_handler fnew) throw();
```

### <a name="parameters"></a>parâmetros

*fnew*\
A função a ser chamada no encerramento.

### <a name="return-value"></a>Valor retornado

O endereço da função anterior que costumava ser chamada no encerramento.

### <a name="remarks"></a>Comentários

A função estabelece um novo [terminate_handler](../standard-library/exception-typedefs.md#terminate_handler) como a função * *fnew*. Portanto, *fnew* não deve ser um ponteiro nulo. A função retorna o endereço do manipulador de encerramento anterior.

### <a name="example"></a>Exemplo

```cpp
// exception_set_terminate.cpp
// compile with: /EHsc
#include <exception>
#include <iostream>

using namespace std;

void termfunction()
{
    cout << "My terminate function called." << endl;
    abort();
}

int main()
{
    terminate_handler oldHandler = set_terminate(termfunction);

    // Throwing an unhandled exception would also terminate the program
    // or we could explicitly call terminate();

    //throw bad_alloc();
    terminate();
}
```

## <a name="get_unexpected"></a><a name="get_unexpected"></a>get_unexpected

Obtém a função `unexpected_handler` atual.

```cpp
unexpected_handler get_unexpected();
```

## <a name="rethrow_if_nested"></a><a name="rethrow_if_nested"></a>rethrow_if_nested

```cpp
template <class E>
    void rethrow_if_nested(const E& e);
```

### <a name="remarks"></a>Comentários

Se não for um tipo de classe polimórfico ou se `nested_exception` estiver inacessível ou ambíguo, não haverá nenhum efeito. Caso contrário, o executará uma conversão dinâmica.

## <a name="set_unexpected"></a><a name="set_unexpected"></a>set_unexpected

Estabelece um novo `unexpected_handler` a ser chamado quando uma exceção inesperada é encontrada.

```cpp
unexpected_handler set_unexpected(unexpected_handler fnew) throw();
```

### <a name="parameters"></a>parâmetros

*fnew*\
A função a ser chamada quando uma exceção inesperada é encontrada.

### <a name="return-value"></a>Valor retornado

O endereço do `unexpected_handler` anterior.

### <a name="remarks"></a>Comentários

*fnew* não deve ser um ponteiro nulo.

O padrão C++ requer que `unexpected` seja chamado quando uma função lançar uma exceção que não está em sua lista de lançamento. A implementação atual não dá suporte a isso. O exemplo a seguir chama `unexpected` diretamente, que, em seguida, chama `unexpected_handler`.

### <a name="example"></a>Exemplo

```cpp
// exception_set_unexpected.cpp
// compile with: /EHsc
#include <exception>
#include <iostream>

using namespace std;

void uefunction()
{
    cout << "My unhandled exception function called." << endl;
    terminate(); // this is what unexpected() calls by default
}

int main()
{
    unexpected_handler oldHandler = set_unexpected(uefunction);

    unexpected(); // library function to force calling the
                  // current unexpected handler
}
```

## <a name="terminate"></a><a name="terminate"></a>encerrar

Chama um manipulador de finalização.

```cpp
void terminate();
```

### <a name="remarks"></a>Comentários

A função chama um manipulador de término, uma função do tipo **`void`** . Se `terminate` é chamado diretamente pelo programa, o manipulador de término é aquele definido mais recentemente por uma chamada para [set_terminate](../standard-library/exception-functions.md#set_terminate). Se `terminate` for chamado para qualquer um dos vários outros motivos durante a avaliação de uma expressão throw, o manipulador Terminate será aquele em vigor imediatamente após avaliar a expressão throw.

Um manipulador de encerramento não pode retornar a seu chamador. Na inicialização do programa, o manipulador de encerramento é uma função que chama `abort` .

### <a name="example"></a>Exemplo

Consulte [set_unexpected](../standard-library/exception-functions.md#set_unexpected) para obter um exemplo do uso de `terminate`.

## <a name="throw_with_nested"></a><a name="throw_with_nested"></a>throw_with_nested

```cpp
template <class T> [[noreturn]]
    void throw_with_nested(T&& t);
```

### <a name="remarks"></a>Comentários

Gera uma exceção com exceções aninhadas.

## <a name="uncaught_exception"></a><a name="uncaught_exception"></a>uncaught_exception

Retorna **`true`** somente se uma exceção gerada estiver sendo processada no momento.

```cpp
bool uncaught_exception();
```

### <a name="return-value"></a>Valor retornado

Retorna **`true`** após concluir a avaliação de uma expressão throw e antes de concluir a inicialização da declaração de exceção no manipulador correspondente ou chamar [inesperado](../standard-library/exception-functions.md#unexpected) como resultado da expressão throw. Em particular, `uncaught_exception` retornará **`true`** quando chamado de um destruidor que está sendo invocado durante um desenrolamento de exceção. Em dispositivos, `uncaught_exception` só tem suporte no Windows CE 5.00 e versões posteriores, incluindo as plataformas Windows Mobile 2005.

### <a name="example"></a>Exemplo

```cpp
// exception_uncaught_exception.cpp
// compile with: /EHsc
#include <exception>
#include <iostream>
#include <string>

class Test
{
public:
   Test( std::string msg ) : m_msg( msg )
   {
      std::cout << "In Test::Test(\"" << m_msg << "\")" << std::endl;
   }
   ~Test( )
   {
      std::cout << "In Test::~Test(\"" << m_msg << "\")" << std::endl
         << "        std::uncaught_exception( ) = "
         << std::uncaught_exception( )
         << std::endl;
   }
private:
    std::string m_msg;
};

// uncaught_exception will be true in the destructor
// for the object created inside the try block because
// the destructor is being called as part of the unwind.

int main( void )
   {
      Test t1( "outside try block" );
      try
      {
         Test t2( "inside try block" );
         throw 1;
      }
      catch (...) {
   }
}
```

```Output
In Test::Test("outside try block")
In Test::Test("inside try block")
In Test::~Test("inside try block")
        std::uncaught_exception( ) = 1
In Test::~Test("outside try block")
        std::uncaught_exception( ) = 0
```

## <a name="unexpected"></a><a name="unexpected"></a>previsto

Chama o manipulador inesperado.

```cpp
void unexpected();
```

### <a name="remarks"></a>Comentários

O padrão C++ requer que `unexpected` seja chamado quando uma função lançar uma exceção que não está em sua lista de lançamento. A implementação atual não dá suporte a isso. O exemplo chama `unexpected` diretamente, que chama o manipulador inesperado.

A função chama um manipulador inesperado, uma função do tipo **`void`** . Se `unexpected` é chamado diretamente pelo programa, o manipulador inesperado é o mais recentemente definido por uma chamada a [set_unexpected](../standard-library/exception-functions.md#set_unexpected).

Um manipulador inesperado não pode retornar a seu chamador. Ele pode encerrar a execução:

- Lançando um objeto de um tipo listado na especificação de exceção ou um objeto de qualquer tipo, se o manipulador inesperado for chamado diretamente pelo programa.

- Lançando um objeto do tipo [bad_exception](../standard-library/bad-exception-class.md).

- Chamar [Terminate](../standard-library/exception-functions.md#terminate) `abort` ou `exit` .

Na inicialização do programa, o manipulador inesperado é uma função que chama [terminate](../standard-library/exception-functions.md#terminate).

### <a name="example"></a>Exemplo

Consulte [set_unexpected](../standard-library/exception-functions.md#set_unexpected) para obter um exemplo do uso de `unexpected`.
