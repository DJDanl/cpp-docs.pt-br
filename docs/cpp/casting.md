---
title: "Conversão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- casting [C++]
- coercion [C++]
- virtual functions [C++], in derived classes [C++]
- static cast operator
- dynamic cast operator
- polymorphic classes [C++]
- classes [C++], polymorphism
ms.assetid: 3dbeb06e-2f4b-4693-832d-624bc8ec95de
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 85f26c61e1e4fa996f73b4f61f4f961ba59dec98
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="casting"></a>Conversão
A linguagem C++ estabelece que se uma classe é derivada de uma classe base que contém funções virtuais, um ponteiro para esse tipo de classe base pode ser usado para chamar as implementações das funções virtuais que residem no objeto de classe derivada. Uma classe que contém funções virtuais é às vezes chamada de "classe polimórfica".  
  
 Como uma classe derivada contém completamente as definições de todas as classes base de que é derivada, é seguro converter um ponteiro superior da hierarquia de classes em qualquer uma dessas classes base. Dado um ponteiro para uma classe base, talvez seja seguro converter o ponteiro abaixo na hierarquia. É seguro se o objeto que está sendo apontado seja realmente de um tipo derivado da classe base. Nesse caso, o objeto real é considerado o "objeto completo". O ponteiro para classe base é considerado um "subobjeto" do objeto completo. Por exemplo, considere a hierarquia da classe mostrada na figura a seguir.  
  
 ![Hierarquia de classes](../cpp/media/vc38zz1.gif "vc38ZZ1")  
Hierarquia de classes  
  
 Um objeto do tipo `C` pode ser visualizado conforme mostrado na figura a seguir.  
  
 ![Classe C com sub &#45; objetos B e A](../cpp/media/vc38zz2.gif "vc38ZZ2")  
Classe C com subobjeto B e subobjeto A  
  
 Dada uma instância da classe `C`, há um subobjeto `B` e um subobjeto `A`. A instância de `C`, inclusive os subobjetos `A` e `B`, é o “objeto completo”.  
  
 Usando as informações de tipo de tempo de execução, é possível verificar se um ponteiro aponta realmente para um objeto completo e pode ser convertido seguramente para apontar para outro objeto em sua hierarquia. O [dynamic_cast](../cpp/dynamic-cast-operator.md) operador pode ser usado para fazer esses tipos de conversões. Também executa a verificação de tempo de execução necessária para tornar a operação segura.  
  
 Para conversão de tipos nonpolymorphic, você pode usar o [static_cast](../cpp/static-cast-operator.md) operador (Este tópico explica a diferença entre as conversões de conversão estáticos e dinâmicos, e quando é apropriado usar cada).  
  
 Esta seção abrange os seguintes tópicos:  
  
-   [Operadores de conversão](../cpp/casting-operators.md)  
  
-   [Informações de tipo de tempo de execução](../cpp/run-time-type-information.md)  
  
## <a name="see-also"></a>Consulte também  
 [Expressões](../cpp/expressions-cpp.md)