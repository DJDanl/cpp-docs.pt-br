---
title: Tipos literal, POD, layout padrão e trivial
ms.date: 04/05/2018
ms.assetid: 2b23a7be-9bad-49fc-8298-31a9a7c556b0
ms.openlocfilehash: 2745302b3ebd7927e9d839e4661e884a2bd91042
ms.sourcegitcommit: 61121faf879cc581a4d39e4baccabf7cf1f673a5
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/20/2019
ms.locfileid: "65934205"
---
# <a name="trivial-standard-layout-pod-and-literal-types"></a>Tipos literal, POD, layout padrão e trivial

O termo *layout* se refere a como os membros de um objeto de classe, struct ou tipo de união são organizados na memória. Em alguns casos, o layout é bem definido pela especificação da linguagem de programação. Mas, quando uma classe ou struct contém determinados recursos da linguagem de programação C++, como classes base virtuais, funções virtuais, membros com controle de acesso diferente, o compilador escolhe um layout. Esse layout pode variar dependendo de quais otimizações estão sendo executadas e, em muitos casos, o objeto pode não ocupar uma área contígua da memória. Por exemplo, se uma classe tem funções virtuais, todas as instâncias dessa classe podem compartilhar uma única tabela de função virtual. Esses tipos são muito úteis, mas também têm limitações. Como o layout é indefinido, eles não podem ser passados para os programas escritos em outras linguagens de programação, como C, e como podem ser não contíguos, não é possível copiá-los de modo confiável com funções de nível inferior rápidas, como `memcopy`, ou serializados em uma rede.

Para habilitar os compiladores, bem como programas e metaprogramas C++ para ponderar sobre a adequação de um determinado tipo para operações que dependem de um layout de memória específico, o C++14 introduziu três categorias de classes e structs simples: *trivial*, *layout padrão* e *POD* (dados antigos simples). A Biblioteca Padrão tem os modelos de função `is_trivial<T>`, `is_standard_layout<T>` e `is_pod<T>` que determinam se um tipo específico pertence a uma determinada categoria.

## <a name="trivial-types"></a>Tipos triviais

Quando uma classe ou struct no C++ tem funções de membro especial explicitamente padronizadas ou fornecidas pelo compilador, trata-se de um tipo trivial. Esse tipo ocupa uma área de memória contígua. Ele pode ter membros com especificadores de acesso diferentes. No C++, o compilador escolhe como ordenar os membros nessa situação. Portanto, você pode copiar esses objetos na memória, mas não pode consumi-los confiavelmente de um programa em C. Um tipo trivial T pode ser copiado em uma matriz char ou unsigned char e copiado novamente, com segurança, em uma variável T. Observe que, devido aos requisitos de alinhamento, pode haver bytes de preenchimento entre os membros de tipo.

Tipos triviais têm um construtor padrão trivial, um construtor de cópia trivial, um operador de atribuição de cópia trivial e um destruidor trivial. Em cada caso, *trivial* significa que o construtor/operador/destruidor não é fornecido pelo usuário e pertence a uma classe que

- não tem funções virtuais nem classes base virtuais,

- bem como nenhuma classe base com um construtor/operador/destruidor não trivial correspondente

- nenhum membro de dados de tipo de classe com um construtor/operador/destruidor não trivial correspondente

Os exemplos a seguir mostram os tipos triviais. No Trivial2, a presença do construtor `Trivial2(int a, int b)` requer que você forneça um construtor padrão. Para o tipo ser qualificado como trivial, você deve padronizar explicitamente o construtor.

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

Quando uma classe ou struct não contém determinados recursos da linguagem de programação C++, como funções virtuais que não são encontradas na linguagem C, e todos os membros têm o mesmo controle de acesso, essa classe ou struct é um tipo de layout padrão. Ele pode ser copiado na memória e o layout é suficientemente definido de modo que pode ser consumido por programas C. Tipos de layout padrão podem ter funções de membro especiais definidas pelo usuário. Além disso, os tipos de layout padrão têm as seguintes características:

- não têm funções virtuais nem classes base virtuais

- todos os membros de dados não estáticos têm o mesmo controle de acesso

- todos os membros não estáticos de tipo de classe são layout padrão

- as classes base são layout padrão

- não têm classes base do mesmo tipo como o primeiro membro de dados não estáticos.

- atendem a uma das seguintes condições:

  - nenhum membro de dados não estáticos na classe mais derivada e não mais de uma classe base com membros de dados não estáticos, ou

  - nenhuma classe base com membros de dados não estáticos

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

Os dois últimos requisitos talvez possam ser mais bem ilustrados com o código. No exemplo a seguir, embora Base seja layout padrão, `Derived` não é layout padrão porque ambos, a classe mais derivada e `Base`, têm membros de dados não estáticos:

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

Neste exemplo, `Derived` é layout padrão porque `Base` não tem membros de dados não estáticos:

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

Derivado também seria layout padrão se `Base` tivesse membros de dados e `Derived` tivesse apenas as funções de membro.

## <a name="pod-types"></a>Tipos POD

Quando uma classe ou struct é trivial e layout padrão, essa classe ou struct é um tipo POD (dados antigos simples). Portanto, o layout da memória dos tipos POD é contíguo e cada membro tem um endereço mais alto do que o membro que foi declarado antes dele para que as cópias de byte por byte e a E/S binária possam ser executadas nesses tipos.  Tipos escalares, como int, também são tipos POD. Os tipos POD que são classes podem ter apenas tipos POD como membros de dados não estáticos.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra as distinções entre os tipos layout padrão, trivial e POD:

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

Um tipo literal é aquele cujo layout pode ser determinado no tempo de compilação. Os tipos a seguir são literais:

- void
- tipos escalares
- referências
- Matrizes de void, tipos escalares ou referências
- Uma classe que tem um destruidor trivial e um ou mais construtores constexpr que não são construtores de cópia ou movimento. Além disso, todos os seus membros de dados não estáticos e classes base devem ser tipos literais e não voláteis.

## <a name="see-also"></a>Consulte também

[Conceitos básicos](../cpp/basic-concepts-cpp.md)