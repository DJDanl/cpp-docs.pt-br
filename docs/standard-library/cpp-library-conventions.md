---
title: "Conven&#231;&#245;es da Biblioteca C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes [C++]"
  - "convenções de codificação, Biblioteca Padrão C++"
  - "convenções [C++], Biblioteca Padrão C++"
  - "nomes de função [C++]"
  - "funções [C++], convenções de nomenclatura da biblioteca"
  - "convenções de nomenclatura [C++], biblioteca C++"
  - "convenções de nomenclatura [C++], Biblioteca Padrão C++"
  - "Biblioteca Padrão C++, convenções"
ms.assetid: bf41b79a-2d53-4f46-8d05-779358335146
caps.latest.revision: 9
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Conven&#231;&#245;es da Biblioteca C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca C\+\+ muito obedece as mesmas convenções que a biblioteca padrão C, mais quaisquer mais descritos aqui.  
  
 Uma implementação tiver determinada latitude como declara tipos e funções da biblioteca C\+\+:  
  
-   Os nomes de funções na biblioteca padrão C podem ter extern \# " C\+\+” ou vinculação extern de C “2.0”.  Inclui o cabeçalho de C do padrão apropriado em vez do que declara uma entidade da biblioteca de tabela embutida.  
  
-   Um nome de função de membro em uma classe de biblioteca pode ter assinaturas adicionais da função nas listadas neste documento.  Você pode ter certeza de que uma chamada de função descrita aqui se comporta como esperado, mas não pode levar do endereço de uma função de membro de biblioteca. \(O tipo não pode ser o que você espera.\)  
  
-   Uma classe de biblioteca pode ter classes base \(nonvirtual\) não documentadas.  Uma classe do como uma classe derivada de outras, de fato, pode ser derivada de aquela classe por outras classes não documentadas.  
  
-   Um tipo definido como um sinônimo para qualquer tipo de inteiro pode ser igual a um de vários tipos diferentes de inteiro.  
  
-   Um tipo de máscara de bits o pode ser implementado como um tipo de número inteiro ou uma enumeração.  Em ambos os casos, você pode executar operação bit a bit \(como `AND` e `OR`\) em valores do mesmo tipo de máscara de bits.  Os elementos `A` e `B` de um tipo de máscara de bits são valores diferentes de zero de modo que `A` &`B` é zero.  
  
-   Uma função de biblioteca que não tem nenhuma especificação de exceção é possível lançar uma exceção arbitrária, a menos que a definição restringir claramente essa possibilidade.  
  
 Por outro lado, há algumas restrições:  
  
-   A biblioteca padrão C do não usa nenhuma macro mascarando.  Somente assinaturas da função específica são reservadas, não os nomes das funções são exibidos.  
  
-   Um nome de função de biblioteca fora de uma classe não terá adicional, não documentado, assinaturas da função.  Você pode usar o seu endereço.  
  
-   As classes base e tão virtuais descritos funções de membro são realmente virtuais, quando aquelas descritas quanto nonvirtual são realmente nonvirtual.  
  
-   Dois tipos definidos pela biblioteca de C\+\+ sempre são diferentes a menos que esse documento sugerir outros explicitamente.  
  
-   As funções fornecidas pela biblioteca, incluindo as versões padrão de funções substituíveis, podem lançar no *máximo* essas exceções listadas em qualquer especificação de exceção.  Nenhum destruidor fornecido pela biblioteca lança exceções.  As funções da biblioteca padrão C consegue propagar uma exceção, como quando `qsort` chama uma função de comparação que gerou uma exceção, mas não lançam exceções de outra forma.  
  
## Consulte também  
 [Visão geral da STL](../standard-library/cpp-standard-library-overview.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)