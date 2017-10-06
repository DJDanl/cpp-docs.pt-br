---
title: "Várias Classes Base | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- base classes [C++], multiple
- derived classes [C++], multiple bases
- multiple inheritance, class declaration
- multiple base classes [C++]
ms.assetid: a30c69fe-401c-4a87-96a0-e0da70c7c740
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 947084ca5bf59494a3574950f5148f5b4d3f0770
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="multiple-base-classes"></a>Várias classes base
Conforme descrito em [várias heranças](http://msdn.microsoft.com/en-us/3b74185e-2beb-4e29-8684-441e51d2a2ca), uma classe pode ser derivada de mais de uma classe base. Em um modelo de herança múltipla (onde classes são derivadas de mais de uma classe base), as classes base são especificadas usando o *lista base* elemento gramática. Por exemplo, a declaração de classe de `CollectionOfBook`, derivada de `Collection` e de `Book`, pode ser especificada:  
  
```  
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
  
-   A ordem na qual ocorre a inicialização pelo construtor. Se seu código depende da parte `Book` de `CollectionOfBook` para ser inicializado antes da parte `Collection`, a ordem de especificação é significante. A inicialização ocorre na ordem em que as classes são especificadas no *lista base*.  
  
-   A ordem na qual os destruidores são chamados para limpeza. Novamente, se for necessário que uma "parte" específica da classe esteja presente quando outra parte for destruída, a ordem é importante. Destrutores sejam chamados na ordem inversa das classes especificadas no *lista base*.  
  
    > [!NOTE]
    >  A ordem de especificação das classes base pode afetar o layout de memória da classe. Não tome decisões de programação com base na ordem dos membros base na memória.  
  
 Ao especificar o *lista base*, você não pode especificar o mesmo nome de classe mais de uma vez. No entanto, uma classe pode ser uma base indireta para uma classe derivada mais de uma vez.  
  
## <a name="virtual-base-classes"></a>Classes base virtuais  
 Porque uma classe pode ser uma classe base indireta a uma classe derivada mais de uma vez, C++ fornece uma maneira de otimizar a forma como funcionam as classes base. As classes base virtuais oferecem uma maneira de economizar espaço e evitar ambiguidades nas hierarquias de classes que usam a herança múltipla.  
  
 Cada objeto não virtual contém uma cópia dos membros de dados definidos na classe base. Essa duplicação perde espaço e exige que você especifique que cópia dos membros da classe base você quer sempre que os acessa.  
  
 Quando uma classe base é especificada como base virtual, ela pode atuar como uma base indireta mais de uma vez sem duplicação de seus membros de dados. Uma única cópia dos membros de dados é compartilhada por todas as classes base que ela usa como base virtual.  
  
 Ao declarar uma classe base virtual, o **virtual** palavra-chave aparece nas listas de base das classes derivadas.  
  
 Considere a hierarquia de classes na figura a seguir, que ilustra uma linha simulada de almoço.  
  
 ![Gráfico de linha almoçar simulada](../cpp/media/vc38xp1.gif "vc38XP1")  
Gráfico de linha de almoço simulado  
  
 Na figura, `Queue` é a classe base para `CashierQueue` e `LunchQueue`. No entanto, quando as duas classes são combinadas para formar `LunchCashierQueue`, o seguinte problema ocorre: a nova classe contém dois subobjetos do tipo `Queue`, um de `CashierQueue` e o outro de `LunchQueue`. A figura a seguir mostra o layout conceitual de memória (o layout real de memória pode ser otimizado).  
  
 ![Almoçar simulada &#45; objeto linha](../cpp/media/vc38xp2.gif "vc38XP2")  
Objeto de linha de almoço simulado  
  
 Observe que há dois subobjetos `Queue` no objeto `LunchCashierQueue`. O código a seguir declara `Queue` como uma classe base virtual:  
  
```  
// deriv_VirtualBaseClasses.cpp  
// compile with: /LD  
class Queue {};  
class CashierQueue : virtual public Queue {};  
class LunchQueue : virtual public Queue {};  
class LunchCashierQueue : public LunchQueue, public CashierQueue {};  
```  
  
 A palavra-chave `virtual` garante que apenas uma cópia do subobjeto `Queue` seja incluída (veja a figura a seguir).  
  
 ![Almoçar simulada &#45; o objeto de linha, classes de base virtuais](../cpp/media/vc38xp3.gif "vc38XP3")  
Objeto de linha de almoço simulado com classes base virtuais  
  
 Uma classe pode ter um componente virtual e um componente não virtual de determinado tipo. Isso acontece nas condições ilustradas na figura a seguir.  
  
 ![Componentes virtuais e não virtuais de uma classe](../cpp/media/vc38xp4.gif "vc38XP4")  
Componentes virtuais e não virtuais da mesma classe  
  
 Na figura, `CashierQueue` e `LunchQueue` usam `Queue` como uma classe base virtual. No entanto, `TakeoutQueue` especifica `Queue` como uma classe base, não uma classe base virtual. Portanto, `LunchTakeoutCashierQueue` tem dois subobjetos do tipo `Queue`: um do caminho de herança que inclui `LunchCashierQueue` e outro do caminho que inclui `TakeoutQueue`. Isso é ilustrado na figura a seguir.  
  
 ![Herança virtual e não virtual no layout de objeto](../cpp/media/vc38xp5.gif "vc38XP5")  
Layout de objeto com herança virtual e não virtual  
  
> [!NOTE]
>  A herança virtual oferece benefícios significativos de tamanho quando comparada com a herança não virtual. No entanto, pode apresentar a sobrecarga adicional de processamento.  
  
 Se uma classe derivada substitui uma função virtual que herda de uma classe base virtual e, se um construtor ou um destruidor para a classe base derivada chamar essa função usando um ponteiro para a classe base virtual, o compilador virtual poderá inserir campos “vtordisp” adicionais ocultos nas classes com bases virtuais. A opção do compilador /vd0 suprime a adição do membro oculto de deslocamento do construtor/destruidor vtordisp. A opção do compilador /vd1, padrão, habilita esses campos quando são necessários. Desative vtordisps apenas se você tiver certeza de que todos os destruidores e construtores da classe chamam funções virtuais virtualmente.  
  
 A opção do compilador /vd afeta um módulo de compilação inteiro. Use o **vtordisp** pragma para suprimir e, em seguida, reabilitar campos vtordisp em uma classe por classe base:  
  
```  
#pragma vtordisp( off )  
class GetReal : virtual public { ... };  
#pragma vtordisp( on )  
```  
  
## <a name="name-ambiguities"></a>Ambiguidades de nome  
 A herança múltipla apresenta a possibilidade de que os nomes sejam herdados ao longo de mais de um caminho. Os nomes de membros de classe ao longo desses caminhos não são necessariamente exclusivos. Esses conflitos de nome são chamados de “ambiguidades”.  
  
 Qualquer expressão que se referir a um membro de classe deve fazer uma referência não ambígua. O exemplo a seguir mostra como as ambiguidades se desenvolvem:  
  
```  
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
  
```  
C *pc = new C;  
  
pc->b();  
```  
  
 Considere o exemplo anterior. Como o nome `a` é um membro das classes `A` e `B`, o compilador não consegue distinguir qual `a` designa a função a ser chamada. O acesso a um membro é ambíguo se pode referenciar mais de uma função, objeto, tipo ou enumerador.  
  
 O compilador detecta ambiguidades executando testes nesta ordem:  
  
1.  Se o acesso ao nome é ambíguo (como somente descrito), será gerada uma mensagem de erro.  
  
2.  Se as funções sobrecarregadas são inequívocas, elas são resolvidas.
  
3.  Se o acesso ao nome viola a permissão de acesso a membros, será gerada uma mensagem de erro. (Para obter mais informações, consulte [controle de acesso de membro](../cpp/member-access-control-cpp.md).)  
  
 Quando uma expressão gera uma ambiguidade por meio de uma herança, você pode solucioná-la manualmente qualificando o nome em questão com seu nome de classe. Para fazer com que o exemplo acima seja compilado corretamente sem ambiguidades, use códigos como:  
  
```  
C *pc = new C;  
  
pc->B::a();  
```  
  
> [!NOTE]
>  Quando `C` é declarado, ele tem o potencial para causar erros quando `B` é referenciado no escopo de `C`. Nenhum erro é emitido, no entanto, até que uma referência não qualificada a `B` seja feita no escopo de `C`.  
  
### <a name="dominance"></a>Dominância  
 É possível que mais de um nome (função, objeto ou enumerador) seja acessado por meio de um gráfico de herança. Esses casos são considerados ambíguos com classes base não virtuais. Eles também são ambíguos com classes base virtuais, a menos que um dos nomes “domine” os outros.  
  
 Um nome domina outro nome quando é definido em ambas as classes e uma classe é derivada da outra. O nome dominante é o nome na classe derivada; esse nome é usado quando uma ambiguidade poderia surgir de outra forma, conforme mostrado no seguinte exemplo:  
  
```  
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
  
-   A declaração de um objeto de tipo `D`.  
  
-   O efeito de aplicar o operador address-of (**&**) para o objeto. Observe que o operador address-of sempre fornece o endereço base do objeto.  
  
-   O efeito de converter explicitamente o ponteiro obtido usando o operador address-of para o tipo de classe base `A`. Observe que a coerção do endereço do objeto para o tipo `A*` não fornece sempre ao compilador informações suficientes sobre o subobjeto do tipo `A` a ser selecionado; nesse caso, existem dois subobjetos.  
  
 ![Conversão ambíguo de ponteiros para classes base](../cpp/media/vc38xt1.gif "vc38XT1")  
Conversão ambígua dos ponteiros para as classes base  
  
 A conversão para o tipo `A*` (ponteiro para `A`) é ambígua porque não há como distinguir qual subobjeto do tipo `A` está correto. Observe que você pode evitar a ambiguidade explicitamente especificando qual subobjeto você pretende usar, como segue:  
  
```  
(A *)(B *)&d       // Use B subobject.  
(A *)(C *)&d       // Use C subobject.  
```  
  
### <a name="ambiguities-and-virtual-base-classes"></a>Ambiguidades e classes base virtuais  
 Se forem usadas classes base virtuais, as funções, os objetos, os tipos e os enumeradores poderão ser alcançados por meio de caminhos de herança múltipla. Como há somente uma instância da classe base, não há nenhuma ambiguidade ao acessar esses nomes.  
  
 A figura a seguir mostra como os objetos são compostos usando a herança virtual e não virtual.  
  
 ![Derivação virtual e não virtual derivação](../cpp/media/vc38xr1.gif "vc38XR1")  
Virtuais vs. Derivação não virtual  
  
 Na figura, o acesso a qualquer membro da classe `A` por meio de classes base não virtuais causa uma ambiguidade; o compilador não tem nenhuma informação que explique se ele deve usar o subobjeto associado a `B` ou o subobjeto associado a `C`. No entanto, quando `A` é especificada como uma classe base virtual, não há dúvida sobre qual subobjeto está sendo acessado.  
  
## <a name="see-also"></a>Consulte também  
 [Herança](../cpp/inheritance-cpp.md)
