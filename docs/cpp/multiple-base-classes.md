---
title: Várias classes base
ms.date: 11/19/2018
helpviewer_keywords:
- base classes [C++], multiple
- derived classes [C++], multiple bases
- multiple inheritance, class declaration
- multiple base classes [C++]
ms.assetid: a30c69fe-401c-4a87-96a0-e0da70c7c740
ms.openlocfilehash: b8bc411b1b8d0b459fe58a39cf351d59d09b2d0e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80179446"
---
# <a name="multiple-base-classes"></a>Várias classes base

Uma classe pode ser derivada de mais de uma classe base. Em um modelo de várias heranças (em que classes são derivadas de mais de uma classe base), as classes base são especificadas usando o elemento de gramática de *lista de base* . Por exemplo, a declaração de classe de `CollectionOfBook`, derivada de `Collection` e de `Book`, pode ser especificada:

```cpp
// deriv_MultipleBaseClasses.cpp
// compile with: /LD
class Collection {
};
class Book {};
class CollectionOfBook : public Book, public Collection {
    // New members
};
```

A ordem na qual as classes base são especificadas não é significativa, exceto em determinados casos nos quais os construtores e os destruidores são invocados. Nesses casos, a ordem na qual as classes base são especificadas afeta o seguinte:

- A ordem na qual ocorre a inicialização pelo construtor. Se seu código depende da parte `Book` de `CollectionOfBook` para ser inicializado antes da parte `Collection`, a ordem de especificação é significante. A inicialização ocorre na ordem em que as classes são especificadas na *lista de base*.

- A ordem na qual os destruidores são chamados para limpeza. Novamente, se for necessário que uma "parte" específica da classe esteja presente quando outra parte for destruída, a ordem é importante. Os destruidores são chamados na ordem inversa das classes especificadas na lista de *base*.

    > [!NOTE]
    >  A ordem de especificação das classes base pode afetar o layout de memória da classe. Não tome decisões de programação com base na ordem dos membros base na memória.

Ao especificar a *lista de base*, você não pode especificar o mesmo nome de classe mais de uma vez. No entanto, uma classe pode ser uma base indireta para uma classe derivada mais de uma vez.

## <a name="virtual-base-classes"></a>Classes base virtuais

Porque uma classe pode ser uma classe base indireta a uma classe derivada mais de uma vez, C++ fornece uma maneira de otimizar a forma como funcionam as classes base. As classes base virtuais oferecem uma maneira de economizar espaço e evitar ambiguidades nas hierarquias de classes que usam a herança múltipla.

Cada objeto não virtual contém uma cópia dos membros de dados definidos na classe base. Essa duplicação perde espaço e exige que você especifique que cópia dos membros da classe base você quer sempre que os acessa.

Quando uma classe base é especificada como base virtual, ela pode atuar como uma base indireta mais de uma vez sem duplicação de seus membros de dados. Uma única cópia dos membros de dados é compartilhada por todas as classes base que ela usa como base virtual.

Ao declarar uma classe base virtual, a palavra-chave **virtual** é exibida nas listas base das classes derivadas.

Considere a hierarquia de classes na figura a seguir, que ilustra uma linha simulada de almoço.

![Grafo de linha de almoço simulada](../cpp/media/vc38xp1.gif "Grafo de linha de almoço simulada") <br/>
Grafo de linha de almoço simulado

Na figura, `Queue` é a classe base para `CashierQueue` e `LunchQueue`. No entanto, quando as duas classes são combinadas para formar `LunchCashierQueue`, o seguinte problema ocorre: a nova classe contém dois subobjetos do tipo `Queue`, um de `CashierQueue` e o outro de `LunchQueue`. A figura a seguir mostra o layout conceitual de memória (o layout real de memória pode ser otimizado).

![Objeto de linha&#45;de almoço simulado](../cpp/media/vc38xp2.gif "Objeto de linha&#45;de almoço simulado") <br/>
Objeto de linha de almoço simulado

Observe que há dois subobjetos `Queue` no objeto `LunchCashierQueue`. O código a seguir declara `Queue` como uma classe base virtual:

```cpp
// deriv_VirtualBaseClasses.cpp
// compile with: /LD
class Queue {};
class CashierQueue : virtual public Queue {};
class LunchQueue : virtual public Queue {};
class LunchCashierQueue : public LunchQueue, public CashierQueue {};
```

A palavra-chave **virtual** garante que apenas uma cópia do subobjeto `Queue` esteja incluída (consulte a figura a seguir).

![Objeto de linha&#45;de almoço simulado, classes base virtuais](../cpp/media/vc38xp3.gif "Objeto de linha&#45;de almoço simulado, classes base virtuais") <br/>
Objeto de linha de almoço simulado com classes base virtuais

Uma classe pode ter um componente virtual e um componente não virtual de determinado tipo. Isso acontece nas condições ilustradas na figura a seguir.

![Componentes virtuais e&#45;não virtuais de uma classe](../cpp/media/vc38xp4.gif "Componentes virtuais e&#45;não virtuais de uma classe") <br/>
Componentes virtuais e não virtuais da mesma classe

Na figura, `CashierQueue` e `LunchQueue` usam `Queue` como uma classe base virtual. No entanto, `TakeoutQueue` especifica `Queue` como uma classe base, não uma classe base virtual. Portanto, `LunchTakeoutCashierQueue` tem dois subobjetos do tipo `Queue`: um do caminho de herança que inclui `LunchCashierQueue` e outro do caminho que inclui `TakeoutQueue`. Isso é ilustrado na figura a seguir.

![Virtual & herança&#45;não virtual no layout do objeto](../cpp/media/vc38xp5.gif "Virtual & herança&#45;não virtual no layout do objeto") <br/>
Layout de objeto com herança virtual e não virtual

> [!NOTE]
>  A herança virtual oferece benefícios significativos de tamanho quando comparada com a herança não virtual. No entanto, pode apresentar a sobrecarga adicional de processamento.

Se uma classe derivada substitui uma função virtual que herda de uma classe base virtual e, se um construtor ou um destruidor para a classe base derivada chamar essa função usando um ponteiro para a classe base virtual, o compilador virtual poderá inserir campos “vtordisp” adicionais ocultos nas classes com bases virtuais. A opção de compilador `/vd0` suprime a adição do membro de substituição do Construtor vtordisp/destruidor oculto. A opção de compilador `/vd1`, o padrão, habilita-os onde eles são necessários. Desative vtordisps apenas se você tiver certeza de que todos os destruidores e construtores da classe chamam funções virtuais virtualmente.

A opção de compilador `/vd` afeta um módulo de compilação inteiro. Use o `vtordisp` pragma para suprimir e, em seguida, reativar `vtordisp` campos de acordo com a classe:

```cpp
#pragma vtordisp( off )
class GetReal : virtual public { ... };
\#pragma vtordisp( on )
```

## <a name="name-ambiguities"></a>Ambiguidades de nome

A herança múltipla apresenta a possibilidade de que os nomes sejam herdados ao longo de mais de um caminho. Os nomes de membros de classe ao longo desses caminhos não são necessariamente exclusivos. Esses conflitos de nome são chamados de “ambiguidades”.

Qualquer expressão que se referir a um membro de classe deve fazer uma referência não ambígua. O exemplo a seguir mostra como as ambiguidades se desenvolvem:

```cpp
// deriv_NameAmbiguities.cpp
// compile with: /LD
// Declare two base classes, A and B.
class A {
public:
    unsigned a;
    unsigned b();
};

class B {
public:
    unsigned a();  // Note that class A also has a member "a"
    int b();       //  and a member "b".
    char c;
};

// Define class C as derived from A and B.
class C : public A, public B {};
```

Dadas as declarações de classe anteriores, códigos como o seguinte são ambíguos porque não está claro se `b` se refere a `b` em `A` ou em `B`:

```cpp
C *pc = new C;

pc->b();
```

Considere o exemplo anterior. Como o nome `a` é um membro das classes `A` e `B`, o compilador não consegue distinguir qual `a` designa a função a ser chamada. O acesso a um membro é ambíguo se pode referenciar mais de uma função, objeto, tipo ou enumerador.

O compilador detecta ambiguidades executando testes nesta ordem:

1. Se o acesso ao nome é ambíguo (como somente descrito), será gerada uma mensagem de erro.

1. Se as funções sobrecarregadas são inequívocas, elas são resolvidas.

1. Se o acesso ao nome viola a permissão de acesso a membros, será gerada uma mensagem de erro. (Para obter mais informações, consulte [controle de acesso de membro](../cpp/member-access-control-cpp.md).)

Quando uma expressão gera uma ambiguidade por meio de uma herança, você pode solucioná-la manualmente qualificando o nome em questão com seu nome de classe. Para fazer com que o exemplo acima seja compilado corretamente sem ambiguidades, use códigos como:

```cpp
C *pc = new C;

pc->B::a();
```

> [!NOTE]
>  Quando `C` é declarado, ele tem o potencial para causar erros quando `B` é referenciado no escopo de `C`. Nenhum erro é emitido, no entanto, até que uma referência não qualificada a `B` seja feita no escopo de `C`.

### <a name="dominance"></a>Dominância

É possível que mais de um nome (função, objeto ou enumerador) seja acessado por meio de um gráfico de herança. Esses casos são considerados ambíguos com classes base não virtuais. Eles também são ambíguos com classes base virtuais, a menos que um dos nomes “domine” os outros.

Um nome domina outro nome quando é definido em ambas as classes e uma classe é derivada da outra. O nome dominante é o nome na classe derivada; esse nome é usado quando uma ambiguidade poderia surgir de outra forma, conforme mostrado no seguinte exemplo:

```cpp
// deriv_Dominance.cpp
// compile with: /LD
class A {
public:
    int a;
};

class B : public virtual A {
public:
    int a();
};

class C : public virtual A {};

class D : public B, public C {
public:
    D() { a(); } // Not ambiguous. B::a() dominates A::a.
};
```

### <a name="ambiguous-conversions"></a>Conversões ambíguas

As conversões explícitas e implícitas de ponteiros ou as referências aos tipos da classe podem causar ambiguidades. A figura a seguir, a conversão ambígua dos ponteiros para as classes base, mostra o seguinte:

- A declaração de um objeto de tipo `D`.

- O efeito de aplicar o operador de endereço ( **&** ) a esse objeto. Observe que o operador address-of sempre fornece o endereço base do objeto.

- O efeito de converter explicitamente o ponteiro obtido usando o operador address-of para o tipo de classe base `A`. Observe que a coerção do endereço do objeto para o tipo `A*` não fornece sempre ao compilador informações suficientes sobre o subobjeto do tipo `A` a ser selecionado; nesse caso, existem dois subobjetos.

![Conversão ambígua de ponteiros para classes base](../cpp/media/vc38xt1.gif "Conversão ambígua de ponteiros para classes base") <br/>
Conversão ambígua de ponteiros para classes base

A conversão para o tipo `A*` (ponteiro para `A`) é ambígua porque não há como distinguir qual subobjeto do tipo `A` está correto. Observe que você pode evitar a ambiguidade explicitamente especificando qual subobjeto você pretende usar, como segue:

```cpp
(A *)(B *)&d       // Use B subobject.
(A *)(C *)&d       // Use C subobject.
```

### <a name="ambiguities-and-virtual-base-classes"></a>Ambiguidades e classes base virtuais

Se forem usadas classes base virtuais, as funções, os objetos, os tipos e os enumeradores poderão ser alcançados por meio de caminhos de herança múltipla. Como há somente uma instância da classe base, não há nenhuma ambiguidade ao acessar esses nomes.

A figura a seguir mostra como os objetos são compostos usando a herança virtual e não virtual.

![Derivação virtual e&#45;derivação não virtual](../cpp/media/vc38xr1.gif "Derivação virtual e&#45;derivação não virtual") <br/>
Derivação virtual versus não virtual

Na figura, o acesso a qualquer membro da classe `A` por meio de classes base não virtuais causa uma ambiguidade; o compilador não tem nenhuma informação que explique se ele deve usar o subobjeto associado a `B` ou o subobjeto associado a `C`. No entanto, quando `A` é especificada como uma classe base virtual, não há dúvida sobre qual subobjeto está sendo acessado.

## <a name="see-also"></a>Confira também

[Herança](../cpp/inheritance-cpp.md)
