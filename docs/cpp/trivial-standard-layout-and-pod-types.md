---
title: Trivial, layout padrão, POD e tipos de literal | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.topic: language-reference
ms.assetid: 2b23a7be-9bad-49fc-8298-31a9a7c556b0
ms.openlocfilehash: 7a80db109df1d9aa25f471312a9ff7103b90df7b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32424845"
---
# <a name="trivial-standard-layout-pod-and-literal-types"></a>Trivial, layout padrão, POD e tipos literais

O termo *layout* refere-se ao modo como os membros de um objeto de class, struct ou tipo de união são organizados na memória. Em alguns casos, o layout é bem definido pela especificação de linguagem. Mas, quando uma classe ou estrutura contém alguns recursos de linguagem C++, como classes base virtuais, funções virtuais, membros com controle de acesso diferentes, em seguida, o compilador está livre para escolher um layout. Esse layout pode variar dependendo de quais otimizações estão sendo executadas e em muitos casos objeto talvez não ainda ocupam uma área contígua de memória. Por exemplo, se uma classe possui funções virtual, todas as instâncias dessa classe podem compartilhar uma tabela de função virtual único. Esses tipos de claro são muito úteis, mas também possuem limitações. Como o layout é indefinido não pode ser passados para programas escritos em outras linguagens, como C, e porque eles podem ser não-contíguo que eles não podem ser confiável copiados com funções de nível baixo rápida, como `memcopy` ou serializado em uma rede.

 Para habilitar compiladores, bem como programas C++ e metaprograms de raciocinar sobre a adequação de qualquer tipo determinado para operações que dependem de um layout específico de memória, C++ 14 introduziu três categorias de simples classes e estruturas: *trivial*, *layout padrão*, e *POD* ou Plain Old Data. A biblioteca padrão tem os modelos de função `is_trivial<T>`, `is_standard_layout<T>` e `is_pod<T>` que determinam se um determinado tipo pertence a uma determinada categoria.

## <a name="trivial-types"></a>Tipos simples

 Quando uma classe ou estrutura em C++ foi fornecida pelo compilador ou padronizados explicitamente funções de membro especiais, em seguida, ele é um tipo simples. Ele ocupa uma área de memória contígua. Ele pode ter membros com especificadores de acesso diferentes. Em C++, o compilador está livre para escolher como ordenar os membros nessa situação. Portanto, você pode memcopy esses objetos, mas confiável não pode usá-los de um programa em C. Um tipo simples T pode ser copiado para uma matriz de caractere ou caracteres não assinados e com segurança copiado de volta para uma variável de T. Observe que, devido aos requisitos de alinhamento, pode haver bytes de preenchimento entre os membros de tipo.

 Tipos simples tem um construtor padrão trivial, o construtor de cópia trivial, o operador de atribuição de cópia trivial e o destruidor trivial. Em cada caso, *trivial* significa que o construtor/operador/destruidor não é fornecido pelo usuário e pertence a uma classe que tem

- Não há funções virtuais ou classes de base virtuais

- Nenhuma classe base com um correspondente não trivial construtor/operador/destruidor

- Não há membros de dados do tipo de classe com um correspondente não trivial construtor/operador/destruidor

Os exemplos a seguir mostram os tipos simples. Em Trivial2, a presença de `Trivial2(int a, int b)` construtor requer que você forneça um construtor padrão. O tipo para a qualificação trivial, você deve explicitamente padrão esse construtor.

```cpp
struct Trivial
{
      int i;
private:
   int j;  
   };

struct Trivial2
{
   int i;
   Trivial2(int a, int b) : i(a), j(b) {}
   Trivial2() = default;
   private:
   int j;   // Different access control
};

```

## <a name="standard-layout-types"></a>Tipos de layout padrão

 Quando uma classe ou estrutura não tem alguns recursos de linguagem C++, como funções virtuais que não são encontrados na linguagem C, e todos os membros têm o mesmo controle de acesso, ele é um tipo de layout padrão. É capaz de memcopy e o layout é suficientemente definido que podem ser consumido por programas C. Tipos de layout padrão podem ter funções membro especiais definidas pelo usuário. Além disso, os tipos de layout padrão têm as seguintes características:

- Não há funções virtuais ou classes de base virtuais

- todos os membros de dados estáticos não têm o mesmo controle de acesso

- todos os membros não estáticos de tipo de classe são layout padrão

- todas as classes base são layout padrão

- não tem nenhuma classe base do mesmo tipo como o primeiro membro de dados não estáticos.

- atende a uma das seguintes condições:

  - Nenhum membro de dados não estático na classe mais derivada e não mais de uma classe base com membros de dados não estático, ou

  - não tem nenhuma classe base com membros de dados não estático

O código a seguir mostra um exemplo de um tipo de layout padrão:

```cpp
struct SL
{
   // All members have same access:
   int i;
   int j;
   SL(int a, int b) : i(a), j(b) {} // User-defined constructor OK
};

```

 Os últimos dois requisitos talvez podem ser ilustrados melhor com o código. No exemplo a seguir, embora Base é layout padrão, `Derived` não é o layout padrão porque equipe de TI (a classe mais derivada) e `Base` ter membros de dados não estático:

```cpp
struct Base
{
   int i;
   int j;
};

// std::is_standard_layout<<Derived> == false!
struct Derived : public Base
{
   int x;
   int y;
};

```

 Neste exemplo `Derived` é o layout padrão porque `Base` não tem nenhum membro de dados não estático:

```cpp
struct Base
{
   void Foo() {}
};

// std::is_standard_layout<<Derived> == true
struct Derived : public Base
{
   int x;
   int y;
};
```

 Derivado também seriam layout padrão se `Base` tinha os membros de dados e `Derived` tinha apenas as funções de membro.

## <a name="pod-types"></a>Tipos POD

 Quando uma classe ou estrutura é trivial e layout padrão, é um tipo POD (Plain Old Data). O layout de memória dos tipos POD, portanto, é contíguo e cada membro tem um endereço mais alto que o membro que foi declarado antes, para que o byte por byte copia e binário e/s podem ser executadas nesses tipos.  Tipos escalares como int também são tipos POD. Tipos de POD classes podem ter apenas tipos POD como membros de dados não estáticos.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra as distinções entre trivial, standard-layout e POD tipos:

```cpp
#include <type_traits>
#include <iostream>

using namespace std;

struct B
{
protected:
   virtual void Foo() {}
};

// Neither trivial nor standard-layout
struct A : B
{
      int a;
   int b;
   void Foo() override {} // Virtual function
};

// Trivial but not standard-layout
struct C
   {
      int a;
private:
   int b;   // Different access control
};

// Standard-layout but not trivial
struct D
{
   int a;
   int b;
   D() {} //User-defined constructor
};

struct POD
{
   int a;
   int b;
};

int main()
{
   cout << boolalpha;
   cout << "A is trivial is " << is_trivial<A>() << endl; // false
   cout << "A is standard-layout is " << is_standard_layout<A>() << endl;  // false

   cout << "C is trivial is " << is_trivial<C>() << endl; // true
   cout << "C is standard-layout is " << is_standard_layout<C>() << endl;  // false

   cout << "D is trivial is " << is_trivial<D>() << endl;  // false
   cout << "D is standard-layout is " << is_standard_layout<D>() << endl; // true

   cout << "POD is trivial is " << is_trivial<POD>() << endl; // true
   cout << "POD is standard-layout is " << is_standard_layout<POD>() << endl; // true

   return 0;
}

```

## <a name="literal_types"></a> Tipos literais

Um tipo literal é uma cujo layout pode ser determinado em tempo de compilação. Esses são os tipos de literal:

- void
- tipos escalares
- referências
- Matrizes de void, escalar tipos ou faz referência
- Uma classe que tenha um destruidor trivial e um ou mais construtores de constexpr que não são mover ou copiar construtores. Além disso, todas as suas classes base e membros de dados não estáticos devem ser tipos de literal e não volátil.

## <a name="see-also"></a>Consulte também

 [Conceitos básicos](../cpp/basic-concepts-cpp.md)