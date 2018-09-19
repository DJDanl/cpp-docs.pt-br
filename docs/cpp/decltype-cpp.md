---
title: decltype (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- decltype_cpp
dev_langs:
- C++
helpviewer_keywords:
- operators [C++], decltype
- decltype operator
- operators [C++], type of an expression
- operators [C++], deduce expression type
ms.assetid: 6dcf8888-8196-4f13-af50-51e3797255d4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1c6cab68cd351c64d65eeed1eeffda7bf49385aa
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46073991"
---
# <a name="decltype--c"></a>decltype (C++)

O **decltype** especificador de tipo produz o tipo de uma expressão especificada. O **decltype** especificador de tipo junto com o [palavra-chave auto](../cpp/auto-cpp.md), é útil principalmente para desenvolvedores que escrevem bibliotecas de modelos. Use **automática** e **decltype** para declarar uma função de modelo cujo retorno tipo depende dos tipos de seus argumentos de modelo. Ou, use **automática** e **decltype** para declarar uma função de modelo que encapsula uma chamada para outra função e, em seguida, retorna o tipo de retorno da função encapsulada.

## <a name="syntax"></a>Sintaxe

```
decltype( expression )
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Expressão*|Uma expressão. Para obter mais informações, consulte [expressões](../cpp/expressions-cpp.md).|

## <a name="return-value"></a>Valor de retorno

O tipo dos *expressão* parâmetro.

## <a name="remarks"></a>Comentários

O **decltype** especificador de tipo é suportado no Visual C++ 2010 ou versões posteriores e pode ser usado com código nativo ou gerenciado. `decltype(auto)` (C + + 14) tem suporte no Visual Studio 2015 e posterior.

O compilador usa as regras a seguir para determinar o tipo dos *expressão* parâmetro.

- Se o *expressão* parâmetro é um identificador ou um [acesso de membro de classe](../cpp/member-access-operators-dot-and.md), `decltype(expression)` é o tipo de entidade nomeada por *expressão*. Se não houver nenhum tal entidade ou o *expressão* nomes de parâmetro de um conjunto de funções sobrecarregadas, o compilador produz uma mensagem de erro.

- Se o *expressão* parâmetro é uma chamada para uma função ou uma função de operador sobrecarregado, `decltype(expression)` é o tipo de retorno da função. Os parênteses em torno de um operador sobrecarregado são ignorados.

- Se o *expressão* parâmetro é um [rvalue](../cpp/lvalues-and-rvalues-visual-cpp.md), `decltype(expression)` é o tipo de *expressão*. Se o *expressão* parâmetro é um [lvalue](../cpp/lvalues-and-rvalues-visual-cpp.md), `decltype(expression)` é um [referência de lvalue](../cpp/lvalue-reference-declarator-amp.md) para o tipo do *expressão*.

O exemplo de código a seguir demonstra alguns usos do **decltype** especificador de tipo. Primeiro, suponha que você tenha codificado as instruções a seguir.

```cpp
int var;
const int&& fx();
struct A { double x; }
const A* a = new A();
```

Em seguida, examine os tipos que são retornados pelas quatro **decltype** instruções na tabela a seguir.

|Instrução|Tipo|Observações|
|---------------|----------|-----------|
|`decltype(fx());`|`const int&&`|Uma [referência de rvalue](../cpp/rvalue-reference-declarator-amp-amp.md) para um **const int**.|
|`decltype(var);`|**int**|O tipo da variável `var`.|
|`decltype(a->x);`|**double**|O tipo do acesso de membro.|
|`decltype((a->x));`|`const double&`|Os parênteses internos fazem com que a instrução seja avaliada como uma expressão em vez de um acesso de membro. E, como `a` é declarado como um `const` ponteiro, o tipo é uma referência a **duplo const**.|

## <a name="decltype-and-auto"></a>Decltype e auto

No C++ 14, você pode usar `decltype(auto)` com nenhum tipo de retorno à direita para declarar uma função de modelo cujo tipo de retorno depende dos tipos de seus argumentos de modelo.

No C++ 11, você pode usar o **decltype** especificador em um tipo de retorno à direita, de tipo junto com o **automático** palavra-chave, para declarar uma função de modelo cujo tipo de retorno depende dos tipos de seu modelo argumentos. Por exemplo, considere o exemplo de código a seguir, no qual o tipo de retorno da função de modelo depende dos tipos dos argumentos de modelo. No exemplo de código, o *desconhecido* espaço reservado que indica que o tipo de retorno não pode ser especificado.

```cpp
template<typename T, typename U>
UNKNOWN func(T&& t, U&& u){ return t + u; };
```

A introdução do **decltype** especificador de tipo permite que um desenvolvedor obter o tipo da expressão que retorna a função de modelo. Use o *sintaxe de declaração de função alternativa* que é mostrado posteriormente, o **automática** palavra-chave e o **decltype** digite especificador para declarar um  *com especificação tardia* tipo de retorno. O tipo de retorno com especificação tardia é determinado quando a declaração é compilada, não quando ela é codificada.

O protótipo a seguir ilustra a sintaxe de uma declaração de função alternativa. Observe que o **const** e **volátil** qualificadores e o **lançar** [especificação de exceção](../cpp/exception-specifications-throw-cpp.md) são opcionais. O *function_body* espaço reservado representa uma instrução composta que especifica que a função faz. Como uma melhor prática de codificação, o *expressão* espaço reservado na **decltype** instrução deve corresponder à expressão especificada pelo **retornar** instrução, se houver, em que o *function_body*.

**auto** *function_name* **(** *parâmetros*<sub>aceitar</sub> **)**  **Const**<sub>opt</sub> **volátil**<sub>aceitação</sub> **->** **decltype (** *expressão* **)** **lançar**<sub>aceitar</sub> **{** *function_body* **};**

No exemplo de código a seguir, o tipo de retorno com especificação tardia da função de modelo `myFunc` é determinado pelos tipos dos argumentos de modelo `t` e `u`. Como uma melhor prática de codificação, o exemplo de código também usa referências de rvalue e o `forward` modelo de função, que oferece suporte a *encaminhamento perfeito*. Para obter mais informações, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).

```cpp
//C++11
template<typename T, typename U>
auto myFunc(T&& t, U&& u) -> decltype (forward<T>(t) + forward<U>(u))
        { return forward<T>(t) + forward<U>(u); };

//C++14
template<typename T, typename U>
decltype(auto) myFunc(T&& t, U&& u)
        { return forward<T>(t) + forward<U>(u); };
```

## <a name="decltype-and-forwarding-functions-c11"></a>Decltype e funções de encaminhamento (c++11)

As funções de encaminhamento encapsulam chamadas para outras funções. Considere um modelo de função que encaminha seus argumentos, ou os resultados de uma expressão que envolve esses argumentos, para outra função. Além disso, a função de encaminhamento retorna o resultado da chamada para a outra função. Nesse cenário, o tipo de retorno da função de encaminhamento deve ser igual ao tipo de retorno da função encapsulada.

Nesse cenário, você não pode gravar uma expressão de tipo apropriada sem o **decltype** especificador de tipo. O **decltype** especificador de tipo habilita funções genéricas de encaminhamento porque não perde informações necessárias sobre se uma função retorna um tipo de referência. Para obter um exemplo de código de uma função de encaminhamento, consulte o exemplo anterior da função de modelo `myFunc`.

## <a name="example"></a>Exemplo

O exemplo de código a seguir declara o tipo de retorno com especificação tardia da função de modelo `Plus()`. O `Plus` função processa seus dois operandos com o **operator +** de sobrecarga. Consequentemente, a interpretação do operador de adição (+) e do tipo de retorno da função `Plus` depende dos tipos dos argumentos de função.

```cpp
// decltype_1.cpp
// compile with: cl /EHsc decltype_1.cpp

#include <iostream>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;

template<typename T1, typename T2>
auto Plus(T1&& t1, T2&& t2) ->
   decltype(forward<T1>(t1) + forward<T2>(t2))
{
   return forward<T1>(t1) + forward<T2>(t2);
}

class X
{
   friend X operator+(const X& x1, const X& x2)
   {
      return X(x1.m_data + x2.m_data);
   }

public:
   X(int data) : m_data(data) {}
   int Dump() const { return m_data;}
private:
   int m_data;
};

int main()
{
   // Integer
   int i = 4;
   cout <<
      "Plus(i, 9) = " <<
      Plus(i, 9) << endl;

   // Floating point
   float dx = 4.0;
   float dy = 9.5;
   cout <<
      setprecision(3) <<
      "Plus(dx, dy) = " <<
      Plus(dx, dy) << endl;

   // String
   string hello = "Hello, ";
   string world = "world!";
   cout << Plus(hello, world) << endl;

   // Custom type
   X x1(20);
   X x2(22);
   X x3 = Plus(x1, x2);
   cout <<
      "x3.Dump() = " <<
      x3.Dump() << endl;
}
```

```Output
Plus(i, 9) = 13
Plus(dx, dy) = 13.5
Hello, world!
x3.Dump() = 42
```

## <a name="example"></a>Exemplo

**Visual Studio 2017 e posterior:** o compilador analisa argumentos decltype quando os modelos são declarados em vez de instanciados. Consequentemente, se uma especialização não dependente for encontrada no argumento decltype, ela não será adiada para o momento de instanciação e será processada imediatamente e quaisquer erros resultantes serão ser diagnosticados nesse momento.

O exemplo a seguir mostra esse erro do compilador gerado no momento da declaração:

```cpp
#include <utility>
template <class T, class ReturnT, class... ArgsT> class IsCallable
{
public:
   struct BadType {};
   template <class U>
   static decltype(std::declval<T>()(std::declval<ArgsT>()...)) Test(int); //C2064. Should be declval<U>
   template <class U>
   static BadType Test(...);
   static constexpr bool value = std::is_convertible<decltype(Test<T>(0)), ReturnT>::value;
};

constexpr bool test1 = IsCallable<int(), int>::value;
static_assert(test1, "PASS1");
constexpr bool test2 = !IsCallable<int*, int>::value;
static_assert(test2, "PASS2");
```

## <a name="requirements"></a>Requisitos

Visual C++ 2010 ou versões posteriores.

`decltype(auto)` requer o Visual Studio 2015 ou posterior.