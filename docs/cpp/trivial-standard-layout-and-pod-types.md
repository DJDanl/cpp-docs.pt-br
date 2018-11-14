---
title: Trivial, layout padrão, o POD e tipos de literal
ms.date: 04/05/2018
ms.assetid: 2b23a7be-9bad-49fc-8298-31a9a7c556b0
ms.openlocfilehash: c742f4c84a1b2ba558b790d7eea7760902da7818
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51521694"
---
# <a name="trivial-standard-layout-pod-and-literal-types"></a>Trivial, layout padrão, o POD e tipos de literal

O termo *layout* se refere a como os membros de um objeto de classe, struct ou tipo de união são organizados na memória. Em alguns casos, o layout é bem definido pela especificação de linguagem. Mas, quando uma classe ou struct contém determinados recursos da linguagem C++, como classes base virtuais, funções virtuais, os membros com controle de acesso diferentes, em seguida, o compilador é livre para escolher um layout. Esse layout pode variar, dependendo de quais otimizações estão sendo executadas e em muitos casos objeto pode não mesmo ocupar uma área contígua da memória. Por exemplo, se uma classe tem funções virtuais, todas as instâncias dessa classe podem compartilhar uma tabela de função virtual único. Esses tipos são obviamente muito útil, mas eles também têm limitações. Como o layout é indefinido não podem ser passados para os programas escritos em outras linguagens, como C, e porque eles podem ser não contíguos que eles não podem ser confiável copiados com funções de nível inferior rápido como `memcopy` ou serializado em uma rede.

Para habilitar metaprograms raciocinar sobre a adequação de qualquer tipo para operações que dependem de um layout de memória específica, bem como programas do C++ e compiladores, C + + 14 introduziu três categorias de classes simples e estruturas: *trivial*, *layout padrão*, e *POD* ou dados antigos simples. A biblioteca padrão tem os modelos de função `is_trivial<T>`, `is_standard_layout<T>` e `is_pod<T>` que determinam se um determinado tipo pertence a uma determinada categoria.

## <a name="trivial-types"></a>Tipos triviais

Quando uma classe ou struct em C++ tem fornecido pelo compilador ou usada como padrão explicitamente funções de membro especial, em seguida, ele é um tipo trivial. Ele ocupa uma área de memória contígua. Ele pode ter membros com especificadores de acesso diferentes. No C++, o compilador é livre para escolher como ordenar os membros nessa situação. Portanto, você pode memcopy esses objetos, mas confiável não é possível consumi-los de um programa em C. Um tipo trivial T pode ser copiado para uma matriz de char ou unsigned char e com segurança copiado novamente para uma variável T. Observe que, devido aos requisitos de alinhamento, pode haver bytes de preenchimento entre os membros de tipo.

Tipos triviais tem um construtor padrão trivial, o construtor de cópia trivial, o operador de atribuição triviais de cópia e o destruidor trivial. Em cada caso, *trivial* significa que o construtor/operador/destruidor não é fornecido pelo usuário e pertence a uma classe que tem

- Não há funções virtuais ou classes base virtuais,

- Nenhuma classe base com um correspondente não triviais construtor/operador/destruidor

- Nenhum membro de dados do tipo de classe com um correspondente não triviais construtor/operador/destruidor

Os exemplos a seguir mostram os tipos triviais. No Trivial2, a presença do `Trivial2(int a, int b)` construtor requer que você forneça um construtor padrão. Para o tipo ser qualificado como trivial, você deve explicitamente que um construtor padrão.

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

Quando uma classe ou struct não contém determinados recursos da linguagem C++, como funções virtuais que não são encontrados na linguagem C, e todos os membros têm o mesmo controle de acesso, ele é um tipo de layout padrão. Ele é capaz de memcopy e o layout é suficientemente definido que pode ser consumido por programas C. Tipos de layout padrão podem ter funções de membro especiais definidas pelo usuário. Além disso, os tipos de layout padrão tem as seguintes características:

- Não há funções virtuais ou classes base virtuais

- todos os membros de dados não estáticos têm o mesmo controle de acesso

- todos os membros não estáticos do tipo de classe são o layout padrão

- as classes base são o layout padrão

- tem sem classes base do mesmo tipo como o primeiro membro de dados não estáticos.

- atende a uma das seguintes condições:

  - Nenhum membro de dados não estáticos na classe mais derivada e não mais de uma classe base com membros de dados não estáticos, ou

  - não tem nenhuma classe base com membros de dados não estáticos

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

Os dois últimos requisitos talvez podem ser melhor ilustrados pelo código. No exemplo a seguir, embora Base é layout padrão, `Derived` não é o layout padrão porque ambos os it (a classe mais derivada) e `Base` ter membros de dados não estáticos:

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

Neste exemplo `Derived` é o layout padrão porque `Base` não tem nenhum membro de dados não estáticos:

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

Derivado também seria layout padrão se `Base` tinha os membros de dados e `Derived` tinha apenas as funções de membro.

## <a name="pod-types"></a>Tipos POD

Quando uma classe ou struct é trivial e layout padrão, ele é um tipo POD (dados antigos simples). O layout da memória dos tipos POD, portanto, é contíguo e cada membro tem um endereço mais alto do que o membro que foi declarado antes dele, para que copia de byte por byte e o binário e/s podem ser executadas nesses tipos.  Tipos escalares, como int também são tipos POD. Tipos POD que são classes podem ter apenas tipos POD como membros de dados não estáticos.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra as distinções entre o layout de padrão trivial, e tipos POD:

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

Um tipo de literal é aquele cujo layout pode ser determinado em tempo de compilação. A seguir está os tipos de literais:

- void
- tipos escalares
- referências
- Matrizes de void, tipos escalares ou faz referência
- Uma classe que tem um destruidor trivial e um ou mais construtores de constexpr que não são movidos ou construtores de cópia. Além disso, todos os seus membros de dados não estáticos e classes base devem ser tipos de literais e não volátil.

## <a name="see-also"></a>Consulte também

[Conceitos básicos](../cpp/basic-concepts-cpp.md)