---
title: decltype (C++)
ms.date: 11/04/2016
f1_keywords:
- decltype_cpp
helpviewer_keywords:
- operators [C++], decltype
- decltype operator
- operators [C++], type of an expression
- operators [C++], deduce expression type
ms.assetid: 6dcf8888-8196-4f13-af50-51e3797255d4
ms.openlocfilehash: 1ed07b8987df7b621ea2809409069cc1121fa24f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180206"
---
# <a name="decltype--c"></a>decltype (C++)

O especificador de tipo **decltype** produz o tipo de uma expressão especificada. O especificador de tipo **decltype** , junto com a [palavra-chave auto](../cpp/auto-cpp.md), é útil principalmente para os desenvolvedores que gravam bibliotecas de modelos. Use **auto** e **decltype** para declarar uma função de modelo cujo tipo de retorno depende dos tipos de seus argumentos de modelo. Ou use **auto** e **decltype** para declarar uma função de modelo que encapsula uma chamada para outra função e, em seguida, retorna o tipo de retorno da função encapsulada.

## <a name="syntax"></a>Sintaxe

```
decltype( expression )
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*expressão*|Uma expressão. Para obter mais informações, consulte [expressões](../cpp/expressions-cpp.md).|

## <a name="return-value"></a>Valor retornado

O tipo do parâmetro da *expressão* .

## <a name="remarks"></a>Comentários

O especificador de tipo **decltype** tem suporte no Visual Studio 2010 ou em versões posteriores e pode ser usado com código nativo ou gerenciado. o `decltype(auto)` (C++ 14) tem suporte no Visual Studio 2015 e posterior.

O compilador usa as regras a seguir para determinar o tipo do parâmetro de *expressão* .

- Se o parâmetro *expression* for um identificador ou um [acesso de membro de classe](../cpp/member-access-operators-dot-and.md), `decltype(expression)` será o tipo da entidade chamada por *expressão*. Se não houver nenhuma entidade ou o parâmetro de *expressão* nomeia um conjunto de funções sobrecarregadas, o compilador produzirá uma mensagem de erro.

- Se o parâmetro *expression* for uma chamada para uma função ou uma função de operador sobrecarregada, `decltype(expression)` será o tipo de retorno da função. Os parênteses em torno de um operador sobrecarregado são ignorados.

- Se o parâmetro *expression* for um [rvalue](../cpp/lvalues-and-rvalues-visual-cpp.md), `decltype(expression)` será o tipo de *expressão*. Se o parâmetro *expression* for um [lvalue](../cpp/lvalues-and-rvalues-visual-cpp.md), `decltype(expression)` será uma [referência lvalue](../cpp/lvalue-reference-declarator-amp.md) ao tipo de *expressão*.

O exemplo de código a seguir demonstra alguns usos do especificador de tipo **decltype** . Primeiro, suponha que você tenha codificado as instruções a seguir.

```cpp
int var;
const int&& fx();
struct A { double x; }
const A* a = new A();
```

Em seguida, examine os tipos que são retornados pelas quatro instruções **decltype** na tabela a seguir.

|de|Type|Observações|
|---------------|----------|-----------|
|`decltype(fx());`|`const int&&`|Uma [referência rvalue](../cpp/rvalue-reference-declarator-amp-amp.md) a uma **const int**.|
|`decltype(var);`|**int**|O tipo da variável `var`.|
|`decltype(a->x);`|**double**|O tipo do acesso de membro.|
|`decltype((a->x));`|`const double&`|Os parênteses internos fazem com que a instrução seja avaliada como uma expressão em vez de um acesso de membro. E como `a` é declarado como um ponteiro de `const`, o tipo é uma referência a **const Double**.|

## <a name="decltype-and-auto"></a>Decltype e auto

No C++ 14, você pode usar `decltype(auto)` sem nenhum tipo de retorno à direita para declarar uma função de modelo cujo tipo de retorno depende dos tipos de seus argumentos de modelo.

No C++ 11, você pode usar o especificador de tipo **decltype** em um tipo de retorno à direita, junto com a palavra-chave **auto** , para declarar uma função de modelo cujo tipo de retorno depende dos tipos de seus argumentos de modelo. Por exemplo, considere o exemplo de código a seguir, no qual o tipo de retorno da função de modelo depende dos tipos dos argumentos de modelo. No exemplo de código, o espaço reservado *desconhecido* indica que o tipo de retorno não pode ser especificado.

```cpp
template<typename T, typename U>
UNKNOWN func(T&& t, U&& u){ return t + u; };
```

A introdução do especificador de tipo **decltype** permite que um desenvolvedor obtenha o tipo da expressão que a função de modelo retorna. Use a *sintaxe de declaração de função alternativa* que é mostrada posteriormente, a palavra-chave **auto** e o especificador de tipo **decltype** para declarar um tipo de retorno especificado de forma *tardia* . O tipo de retorno com especificação tardia é determinado quando a declaração é compilada, não quando ela é codificada.

O protótipo a seguir ilustra a sintaxe de uma declaração de função alternativa. Observe que os qualificadores **const** e **volatile** e a [especificação de exceção](../cpp/exception-specifications-throw-cpp.md) **throw** são opcionais. O espaço reservado *function_body* representa uma instrução composta que especifica o que a função faz. Como uma melhor prática de codificação, o espaço reservado de *expressão* na instrução **decltype** deve corresponder à expressão especificada pela instrução **Return** , se houver, no *function_body*.

**auto** *function_name* **(** *Parameters*<sub>opt</sub> **)** **const**<sub>opt</sub> **volátil**<sub>opt</sub> **->** **decltype (** *expressão* **)** **throw**<sub>opt</sub> **{** *function_body* **};**

No exemplo de código a seguir, o tipo de retorno com especificação tardia da função de modelo `myFunc` é determinado pelos tipos dos argumentos de modelo `t` e `u`. Como uma melhor prática de codificação, o exemplo de código também usa referências a rvalue e o modelo de função `forward`, que dá suporte ao *encaminhamento perfeito*. Para obter mais informações, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).

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

## <a name="decltype-and-forwarding-functions-c11"></a>Funções decltype e Forwarding (C++ 11)

As funções de encaminhamento encapsulam chamadas para outras funções. Considere um modelo de função que encaminha seus argumentos, ou os resultados de uma expressão que envolve esses argumentos, para outra função. Além disso, a função de encaminhamento retorna o resultado da chamada para a outra função. Nesse cenário, o tipo de retorno da função de encaminhamento deve ser igual ao tipo de retorno da função encapsulada.

Nesse cenário, você não pode gravar uma expressão de tipo apropriada sem o especificador de tipo **decltype** . O especificador de tipo **decltype** habilita funções de encaminhamento genéricas porque não perde as informações necessárias sobre se uma função retorna um tipo de referência. Para obter um exemplo de código de uma função de encaminhamento, consulte o exemplo anterior da função de modelo `myFunc`.

## <a name="example"></a>Exemplo

O exemplo de código a seguir declara o tipo de retorno com especificação tardia da função de modelo `Plus()`. A função `Plus` processa seus dois operandos com o **operador +** sobrecarga. Consequentemente, a interpretação do operador de adição (+) e do tipo de retorno da função `Plus` depende dos tipos dos argumentos de função.

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

**Visual Studio 2017 e posterior:** O compilador analisa argumentos decltype quando os modelos são declarados em vez de instanciados. Consequentemente, se uma especialização não dependente for encontrada no argumento decltype, ela não será adiada para o momento de instanciação e será processada imediatamente e quaisquer erros resultantes serão ser diagnosticados nesse momento.

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

Visual Studio 2010 ou versões posteriores.

`decltype(auto)` requer o Visual Studio 2015 ou posterior.
