---
title: Conversão
ms.date: 11/19/2018
helpviewer_keywords:
- casting [C++]
- coercion [C++]
- virtual functions [C++], in derived classes [C++]
- static cast operator
- dynamic cast operator
- polymorphic classes [C++]
- classes [C++], polymorphism
ms.assetid: 3dbeb06e-2f4b-4693-832d-624bc8ec95de
ms.openlocfilehash: bb06db3af6aee031b6cb2d69b38a9404304420fc
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190114"
---
# <a name="casting"></a>Conversão

A linguagem C++ estabelece que se uma classe é derivada de uma classe base que contém funções virtuais, um ponteiro para esse tipo de classe base pode ser usado para chamar as implementações das funções virtuais que residem no objeto de classe derivada. Uma classe que contém funções virtuais é às vezes chamada de "classe polimórfica".

Como uma classe derivada contém completamente as definições de todas as classes base de que é derivada, é seguro converter um ponteiro superior da hierarquia de classes em qualquer uma dessas classes base. Dado um ponteiro para uma classe base, talvez seja seguro converter o ponteiro abaixo na hierarquia. É seguro se o objeto que está sendo apontado seja realmente de um tipo derivado da classe base. Nesse caso, o objeto real é considerado o "objeto completo". O ponteiro para classe base é considerado um "subobjeto" do objeto completo. Por exemplo, considere a hierarquia da classe mostrada na figura a seguir.

![Hierarquia de classes](../cpp/media/vc38zz1.gif "Hierarquia de classe") <br/>
Hierarquia de classe

Um objeto do tipo `C` pode ser visualizado conforme mostrado na figura a seguir.

![Classe C com os&#45;subobjetos B e A](../cpp/media/vc38zz2.gif "Classe C com os&#45;subobjetos B e A") <br/>
Classe C com subobjetos B e um

Dada uma instância da classe `C`, há um subobjeto `B` e um subobjeto `A`. A instância de `C`, inclusive os subobjetos `A` e `B`, é o “objeto completo”.

Usando as informações de tipo de tempo de execução, é possível verificar se um ponteiro aponta realmente para um objeto completo e pode ser convertido seguramente para apontar para outro objeto em sua hierarquia. O operador [dynamic_cast](../cpp/dynamic-cast-operator.md) pode ser usado para fazer esses tipos de conversões. Também executa a verificação de tempo de execução necessária para tornar a operação segura.

Para a conversão de tipos nonpolymorphic, você pode usar o operador de [static_cast](../cpp/static-cast-operator.md) (este tópico explica a diferença entre conversões de conversão estática e dinâmica e quando é apropriado usar cada uma).

Esta seção contém os seguintes tópicos:

- [Operadores de conversão](../cpp/casting-operators.md)

- [Informações de tipo de tempo de execução](../cpp/run-time-type-information.md)

## <a name="see-also"></a>Confira também

[Expressões](../cpp/expressions-cpp.md)
