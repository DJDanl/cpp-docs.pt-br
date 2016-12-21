---
title: "Convers&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "conversão"
  - "classes [C++], polimorfismo"
  - "coerção"
  - "Operador de conversão dinâmica"
  - "classes polimórficas"
  - "Operador de conversão estática"
  - "funções virtuais, em classes derivadas"
ms.assetid: 3dbeb06e-2f4b-4693-832d-624bc8ec95de
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convers&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A linguagem C\+\+ estabelece que se uma classe é derivada de uma classe base que contém funções virtuais, um ponteiro para esse tipo de classe base pode ser usado para chamar as implementações das funções virtuais que residem no objeto de classe derivada.  Uma classe que contém funções virtuais é às vezes chamada de "classe polimórfica".  
  
 Como uma classe derivada contém completamente as definições de todas as classes base de que é derivada, é seguro converter um ponteiro superior da hierarquia de classes em qualquer uma dessas classes base.  Dado um ponteiro para uma classe base, talvez seja seguro converter o ponteiro abaixo na hierarquia.  É seguro se o objeto que está sendo apontado seja realmente de um tipo derivado da classe base.  Nesse caso, o objeto real é considerado o "objeto completo". O ponteiro para classe base é considerado um "subobjeto" do objeto completo.  Por exemplo, considere a hierarquia da classe mostrada na figura a seguir.  
  
 ![Gráfico de hierarquia de classes](../cpp/media/vc38zz1.png "vc38ZZ1")  
Hierarquia de classes  
  
 Um objeto do tipo `C` pode ser visualizado conforme mostrado na figura a seguir.  
  
 ![Classe C com B subobjeto e um Subobjeto](../cpp/media/vc38zz2.png "vc38ZZ2")  
Classe C com subobjeto B e subobjeto A  
  
 Dada uma instância da classe `C`, há um subobjeto `B` e um subobjeto `A`.  A instância de `C`, inclusive os subobjetos `A` e `B`, é o “objeto completo”.  
  
 Usando as informações de tipo de tempo de execução, é possível verificar se um ponteiro aponta realmente para um objeto completo e pode ser convertido seguramente para apontar para outro objeto em sua hierarquia.  O operador [dynamic\_cast](../cpp/dynamic-cast-operator.md) pode ser usado para fazer esses tipos de conversões.  Também executa a verificação de tempo de execução necessária para tornar a operação segura.  
  
 Para conversão de tipos não polimórficos, você pode usar o operador [static\_cast](../cpp/static-cast-operator.md) \(este tópico explica a diferença entre conversões estáticas e dinâmicas, e quando é apropriado usar cada uma\).  
  
 Esta seção abrange os seguintes tópicos:  
  
-   [Operadores de conversão](../cpp/casting-operators.md)  
  
-   [Informações de tipo de tempo de execução](../Topic/Run-Time%20Type%20Information.md)  
  
## Consulte também  
 [Expressões](../cpp/expressions-cpp.md)