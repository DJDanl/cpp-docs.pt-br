---
title: 'Declarador de referência rvalue: &amp;&amp;'
ms.date: 11/04/2016
f1_keywords:
- '&&'
helpviewer_keywords:
- '&& rvalue reference declarator'
ms.assetid: eab0ce3a-c5a3-4992-aa70-6a8ab1f7491d
ms.openlocfilehash: 953aafe79115ad32a172c878eb910dd06b81e3f4
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88842033"
---
# <a name="rvalue-reference-declarator-ampamp"></a>Declarador de referência rvalue: &amp;&amp;

Contém uma referência a uma expressão rvalue.

## <a name="syntax"></a>Sintaxe

```
type-id && cast-expression
```

## <a name="remarks"></a>Comentários

Referências de rvalue permitem que você diferencie um lvalue de um rvalue. As referências a lvalue e as referências a rvalue são sintaticamente e semanticamente semelhantes, mas seguem regras um pouco diferentes. Para obter mais informações sobre lvalues e rvalues, consulte [lvalues e rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md). Para obter mais informações sobre referências de lvalue, consulte [Declarador de referência lvalue: &](../cpp/lvalue-reference-declarator-amp.md).

As seções a seguir descrevem como as referências a rvalue dão suporte à implementação de *semântica de movimentação* e *encaminhamento perfeito*.

## <a name="move-semantics"></a>Semântica de movimentação

As referências a rvalue dão suporte à implementação da *semântica de movimentação*, o que pode aumentar significativamente o desempenho de seus aplicativos. A semântica de movimentação permite que você escreva códigos que transfiram recursos (como a memória dinamicamente alocada) de um objeto para outro. A semântica de movimentação funciona porque permite que recursos sejam transferidos de objetos temporários que não podem ser referenciados em outro lugar no programa.

Para implementar a semântica de movimentação, você normalmente fornece um *Construtor de movimentação e,* opcionalmente, um operador de atribuição de movimento (**operador =**), para sua classe. As operações de cópia e atribuição cujas origens são rvalues aproveitam automaticamente as vantagens da semântica de movimentação. Diferente do construtor de cópia padrão, o compilador não fornece um construtor de movimentação padrão. Para obter mais informações sobre como escrever um construtor de movimentação e como usá-lo em seu aplicativo, consulte [mover construtores e mover operadores de atribuição (C++)](../cpp/move-constructors-and-move-assignment-operators-cpp.md).

Você também pode sobrecarregar as funções e operadores comuns para aproveitar a semântica de movimentação. O Visual Studio 2010 introduz a semântica de movimentação na biblioteca padrão C++. Por exemplo, a classe `string` implementa as operações que executam a semântica de movimentação. Considere o exemplo a seguir, que concatena várias cadeias de caracteres e imprime o resultado:

```cpp
// string_concatenation.cpp
// compile with: /EHsc
#include <iostream>
#include <string>
using namespace std;

int main()
{
   string s = string("h") + "e" + "ll" + "o";
   cout << s << endl;
}
```

Antes do Visual Studio 2010, cada chamada para **Operator +** aloca e retorna um novo objeto temporário `string` (um rvalue). o **operador +** não pode acrescentar uma cadeia de caracteres à outra porque não sabe se as cadeias de caracteres de origem são lvalue ou rvalues. Se as cadeias de caracteres de origem forem lvalues, poderão ser referenciadas em outro local do programa e, portanto, não devem ser modificadas. Usando referências rvalue, o **operador +** pode ser modificado para pegar rvalues, que não podem ser referenciados em outro lugar no programa. Portanto, o **operador +** pode agora acrescentar uma cadeia de caracteres a outra. Isso pode reduzir significativamente o número de alocações de memória dinâmica que a classe `string` deve executar. Para obter mais informações sobre a `string` classe, consulte [basic_string classe](../standard-library/basic-string-class.md).

A semântica de movimentação também ajuda quando o compilador não pode usar a Otimização de Valor de Retorno (RVO) ou a Otimização de Valor de Retorno (NRVO). Nesses casos, o compilador chama o construtor de movimentação caso o tipo o defina.

Para compreender melhor a semântica de movimentação, considere o exemplo de inserção de um elemento em um objeto `vector`. Se a capacidade do objeto `vector` for excedida, o objeto `vector` deverá realocar memória para os seus elementos e então copiar cada elemento para outro local da memória para dar espaço ao elemento inserido. Quando uma operação de inserção copia um elemento, ele cria um novo elemento, chama o construtor de cópia para copiar os dados do elemento anterior para o novo elemento e destrói o elemento anterior. A semântica de movimentação permite que você mova objetos diretamente sem ter que executar operações caras de alocação de memória e de cópia.

Para aproveitar a semântica de movimentação no exemplo `vector`, você pode escrever um construtor de movimentação para mover dados de um objeto para outro.

Para obter mais informações sobre a introdução da semântica de movimentação na biblioteca padrão do C++ no Visual Studio 2010, consulte [biblioteca padrão do c++](../standard-library/cpp-standard-library-reference.md).

## <a name="perfect-forwarding"></a>Encaminhamento perfeito

O encaminhamento perfeito reduz a necessidade de funções sobrecarregadas e ajuda a evitar problemas de encaminhamento. O *problema de encaminhamento* pode ocorrer quando você escreve uma função genérica que usa referências como seus parâmetros e passa (ou *encaminha*) esses parâmetros para outra função. Por exemplo, se a função genérica receber um parâmetro de tipo `const T&`, então a função chamada não poderá modificar o valor desse parâmetro. Se a função genérica pegar um parâmetro do tipo `T&`, então a função não poderá ser chamada usando um rvalue (como um objeto temporário ou um literal de inteiro).

Normalmente, para resolver esse problema, você deve fornecer as versões sobrecarregadas da função genérica que recebe `T&` e `const T&` para cada um dos seus parâmetros. Como resultado, o número de funções sobrecarregadas aumenta exponencialmente com o número de parâmetros. As referências rvalue permitem que você grave uma versão de uma função que aceita argumentos arbitrários e os encaminha para outra função, como se a outra função tivesse sido chamada diretamente.

Considere o seguinte exemplo que declara quatro tipos, `W`, `X`, `Y` e `Z`. O construtor para cada tipo usa uma combinação diferente de **`const`** referências e não **`const`** lvalue como seus parâmetros.

```cpp
struct W
{
   W(int&, int&) {}
};

struct X
{
   X(const int&, int&) {}
};

struct Y
{
   Y(int&, const int&) {}
};

struct Z
{
   Z(const int&, const int&) {}
};
```

Suponha que você quer gravar uma função genérica que gera objetos. O exemplo a seguir mostra uma maneira de gravar esta função:

```cpp
template <typename T, typename A1, typename A2>
T* factory(A1& a1, A2& a2)
{
   return new T(a1, a2);
}
```

O exemplo a seguir mostra uma chamada válida para a função `factory`:

```cpp
int a = 4, b = 5;
W* pw = factory<W>(a, b);
```

No entanto, o exemplo a seguir não contém uma chamada válida para a função `factory` porque `factory` pega referências lvalue que são modificáveis como seus parâmetros, mas é chamada usando rvalues:

```cpp
Z* pz = factory<Z>(2, 2);
```

Normalmente, para resolver esse problema, você deve criar uma versão sobrecarregada da função `factory` para cada combinação de parâmetros `A&` e `const A&`. As referências de rvalue permitem que você grave uma versão da função `factory`, conforme mostrado no exemplo o seguir:

```cpp
template <typename T, typename A1, typename A2>
T* factory(A1&& a1, A2&& a2)
{
   return new T(std::forward<A1>(a1), std::forward<A2>(a2));
}
```

Este exemplo usa referências de rvalue como os parâmetros para a função `factory`. A finalidade da função [std:: forward](../standard-library/utility-functions.md#forward) é encaminhar os parâmetros da função de fábrica para o construtor da classe de modelo.

O exemplo a seguir mostra a função `main` que usa a função `factory` revisada para criar instâncias das classes `W`, `X`, `Y` e `Z`. A função `factory` revisada encaminha seus parâmetros (lvalues ou rvalues) para o construtor de classe apropriado.

```cpp
int main()
{
   int a = 4, b = 5;
   W* pw = factory<W>(a, b);
   X* px = factory<X>(2, b);
   Y* py = factory<Y>(a, 2);
   Z* pz = factory<Z>(2, 2);

   delete pw;
   delete px;
   delete py;
   delete pz;
}
```

## <a name="additional-properties-of-rvalue-references"></a>Propriedades adicionais das referências de rvalue

**Você pode sobrecarregar uma função para obter uma referência de lvalue e uma referência de rvalue.**

Ao sobrecarregar uma função para obter uma **`const`** referência lvalue ou uma referência rvalue, você pode escrever código que diferencie entre objetos não modificáveis (lvalues) e valores temporários modificáveis (rvalues). Você pode passar um objeto para uma função que usa uma referência rvalue, a menos que o objeto seja marcado como **`const`** . O exemplo a seguir mostra a função `f`, que é sobrecarregada para pegar uma referência de lvalue e uma referência de rvalue. A função `main` chama `f` com lvalues e um rvalue.

```cpp
// reference-overload.cpp
// Compile with: /EHsc
#include <iostream>
using namespace std;

// A class that contains a memory resource.
class MemoryBlock
{
   // TODO: Add resources for the class here.
};

void f(const MemoryBlock&)
{
   cout << "In f(const MemoryBlock&). This version cannot modify the parameter." << endl;
}

void f(MemoryBlock&&)
{
   cout << "In f(MemoryBlock&&). This version can modify the parameter." << endl;
}

int main()
{
   MemoryBlock block;
   f(block);
   f(MemoryBlock());
}
```

Esse exemplo gera a saída a seguir:

```Output
In f(const MemoryBlock&). This version cannot modify the parameter.
In f(MemoryBlock&&). This version can modify the parameter.
```

Nesse exemplo, a primeira chamada para `f` passa uma variável local (um lvalue) como seu argumento. A segunda chamada para `f` passa um objeto temporário como seu argumento. Como o objeto temporário não pode ser referenciado em outro lugar no programa, a chamada é associada à versão sobrecarregada de `f` que utiliza uma referência de rvalue, que está livre para alterar o objeto.

**O compilador trata uma referência de rvalue nomeada como um lvalue e uma referência de rvalue não nomeada como um rvalue.**

Quando você escrever uma função que recebe uma referência de rvalue como seu parâmetro, esse parâmetro é tratado como um lvalue no corpo da função. O compilador trata uma referência de rvalue nomeada como um lvalue porque um objeto nomeado pode ser referenciado por várias partes de um programa. Seria perigoso permitir que várias partes de um programa modifiquem ou removam recursos desse objeto. Por exemplo, se várias partes de um programa tentarem transferir recursos do mesmo objeto, somente a primeira parte transferirá o recurso com êxito.

O exemplo a seguir mostra a função `g`, que é sobrecarregada para pegar uma referência de lvalue e uma referência de rvalue. A função `f` pega uma referência de rvalue como seu parâmetro (uma referência de rvalue nomeada) e retorna uma referência de rvalue (uma referência de rvalue sem nome). Na chamada a `g` de `f`, a resolução de sobrecarga seleciona a versão de `g` que utiliza uma referência de lvalue porque o corpo de `f` trata seu parâmetro como um lvalue. Na chamada a `g` de `main`, a resolução de sobrecarga seleciona a versão de `g` que utiliza uma referência de rvalue porque `f` retorna uma referência de rvalue.

```cpp
// named-reference.cpp
// Compile with: /EHsc
#include <iostream>
using namespace std;

// A class that contains a memory resource.
class MemoryBlock
{
   // TODO: Add resources for the class here.
};

void g(const MemoryBlock&)
{
   cout << "In g(const MemoryBlock&)." << endl;
}

void g(MemoryBlock&&)
{
   cout << "In g(MemoryBlock&&)." << endl;
}

MemoryBlock&& f(MemoryBlock&& block)
{
   g(block);
   return move(block);
}

int main()
{
   g(f(MemoryBlock()));
}
```

Esse exemplo gera a saída a seguir:

```cpp
In g(const MemoryBlock&).
In g(MemoryBlock&&).
```

Neste exemplo, a função `main` passa um rvalue para `f`. O corpo de `f` trata seu parâmetro nomeado como um lvalue. A chamada de `f` para `g` associa o parâmetro a uma referência de lvalue (a primeira versão sobrecarregada de `g`).

- **Você pode converter um lvalue em uma referência rvalue.**

A função padrão de biblioteca do C++ [std:: move](../standard-library/utility-functions.md#move) permite converter um objeto em uma referência rvalue para esse objeto. Como alternativa, você pode usar a **`static_cast`** palavra-chave para converter um lvalue em uma referência rvalue, conforme mostrado no exemplo a seguir:

```cpp
// cast-reference.cpp
// Compile with: /EHsc
#include <iostream>
using namespace std;

// A class that contains a memory resource.
class MemoryBlock
{
   // TODO: Add resources for the class here.
};

void g(const MemoryBlock&)
{
   cout << "In g(const MemoryBlock&)." << endl;
}

void g(MemoryBlock&&)
{
   cout << "In g(MemoryBlock&&)." << endl;
}

int main()
{
   MemoryBlock block;
   g(block);
   g(static_cast<MemoryBlock&&>(block));
}
```

Esse exemplo gera a saída a seguir:

```cpp
In g(const MemoryBlock&).
In g(MemoryBlock&&).
```

**Os modelos de função deduzem seus tipos de argumento de modelo e então usam regras de recolhimento de referência.**

É comum escrever um modelo de função que passe (ou *encaminhe*) seus parâmetros para outra função. É importante compreender como funciona a dedução de tipo de modelo para os modelos de função com referências de rvalue.

Se o argumento de função for um rvalue, o compilador deduzirá o argumento como uma referência de rvalue. Por exemplo, se você passar uma referência de rvalue para um objeto do tipo `X` a uma função de modelo que obtenha o tipo `T&&` como seu parâmetro, a dedução do argumento do modelo deduzirá `T` como `X`. Portanto, o parâmetro tem o tipo `X&&`. Se o argumento da função for um lvalue ou **`const`** lvalue, o compilador deduzirá seu tipo para ser uma referência lvalue ou uma **`const`** referência lvalue desse tipo.

O exemplo a seguir declara um modelo de estrutura e o especializa para vários tipos de referência. A função `print_type_and_value` usa uma referência de rvalue como seu parâmetro e a encaminha para a versão especializada apropriada do método `S::print`. A função `main` demonstra as várias maneiras de chamar o método `S::print`.

```cpp
// template-type-deduction.cpp
// Compile with: /EHsc
#include <iostream>
#include <string>
using namespace std;

template<typename T> struct S;

// The following structures specialize S by
// lvalue reference (T&), const lvalue reference (const T&),
// rvalue reference (T&&), and const rvalue reference (const T&&).
// Each structure provides a print method that prints the type of
// the structure and its parameter.

template<typename T> struct S<T&> {
   static void print(T& t)
   {
      cout << "print<T&>: " << t << endl;
   }
};

template<typename T> struct S<const T&> {
   static void print(const T& t)
   {
      cout << "print<const T&>: " << t << endl;
   }
};

template<typename T> struct S<T&&> {
   static void print(T&& t)
   {
      cout << "print<T&&>: " << t << endl;
   }
};

template<typename T> struct S<const T&&> {
   static void print(const T&& t)
   {
      cout << "print<const T&&>: " << t << endl;
   }
};

// This function forwards its parameter to a specialized
// version of the S type.
template <typename T> void print_type_and_value(T&& t)
{
   S<T&&>::print(std::forward<T>(t));
}

// This function returns the constant string "fourth".
const string fourth() { return string("fourth"); }

int main()
{
   // The following call resolves to:
   // print_type_and_value<string&>(string& && t)
   // Which collapses to:
   // print_type_and_value<string&>(string& t)
   string s1("first");
   print_type_and_value(s1);

   // The following call resolves to:
   // print_type_and_value<const string&>(const string& && t)
   // Which collapses to:
   // print_type_and_value<const string&>(const string& t)
   const string s2("second");
   print_type_and_value(s2);

   // The following call resolves to:
   // print_type_and_value<string&&>(string&& t)
   print_type_and_value(string("third"));

   // The following call resolves to:
   // print_type_and_value<const string&&>(const string&& t)
   print_type_and_value(fourth());
}
```

Esse exemplo gera a saída a seguir:

```cpp
print<T&>: first
print<const T&>: second
print<T&&>: third
print<const T&&>: fourth
```

Para resolver cada chamada para a função `print_type_and_value`, o compilador executa primeiro a dedução do argumento do modelo. O compilador, então, aplica regras de recolhimento de referência quando substitui os argumentos de modelo deduzidos para os tipos de parâmetro. Por exemplo, passar a variável local `s1` para a função `print_type_and_value` faz com que o compilador produza a seguinte assinatura de função:

```cpp
print_type_and_value<string&>(string& && t)
```

O compilador usa regras de recolhimento de referência para reduzir a assinatura para:

```cpp
print_type_and_value<string&>(string& t)
```

Esta versão da função `print_type_and_value` encaminha seu parâmetro para a versão especializada correta do método `S::print`.

A tabela a seguir resume as regras de recolhimento de referência para dedução do tipo de argumento de modelo:

| Tipo expandido | Tipo recolhido |
|--|--|
| `T& &` | `T&` |
| `T& &&` | `T&` |
| `T&& &` | `T&` |
| `T&& &&` | `T&&` |

A dedução do argumento do modelo é um elemento importante para a implementação do encaminhamento perfeito. A seção Encaminhamento perfeito apresentada anteriormente neste tópico descreve o encaminhamento perfeito com mais detalhes.

## <a name="summary"></a>Resumo

Referências de rvalue diferenciam lvalues de rvalues. Elas podem ajudar a melhorar o desempenho de seus aplicativos eliminando a necessidade de alocações de memória e operações de cópia desnecessárias. Elas também permitem que você grave uma versão de uma função que aceita argumentos arbitrários e os encaminha para outra função, como se a outra função tivesse sido chamada diretamente.

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Declarador de referência Lvalue: &](../cpp/lvalue-reference-declarator-amp.md)<br/>
[Lvalues e rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md)<br/>
[Move Constructors and Move Assignment Operators (C++)](../cpp/move-constructors-and-move-assignment-operators-cpp.md) (Operadores de construtores de movimento e de atribuição de movimento (C++))<br/>
[Biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
