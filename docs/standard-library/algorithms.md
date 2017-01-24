---
title: "Algoritmos | Microsoft Docs"
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
  - "convenções da biblioteca C++ para funções de modelo de algoritmo"
  - "algoritmos [C++], C++"
  - "convenções [C++], algoritmo C++"
  - "bibliotecas [C++], convenções para algoritmos C++"
  - "Biblioteca Padrão C++, algoritmos"
ms.assetid: dec9b373-7d5c-46cc-b7d2-21a938ecd0a6
caps.latest.revision: 10
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Algoritmos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Algoritmos são uma parte fundamental da biblioteca de modelos padrão.  Algoritmos não funcionam com contêineres próprios, mas em vez disso, com os iteradores.  Portanto, o mesmo algoritmo pode ser usado pela maioria, se não todos os contêineres STL.  Esta seção discute as convenções e da terminologia dos algoritmos da STL.  
  
## Comentários  
 As descrições das funções do modelo de algoritmo utilizam várias expressões de forma abreviada:  
  
-   A frase "no intervalo \[*um*, *B*\)" significa a sequência de zero ou mais valores discretos, começando com *um* até, mas não incluindo *B*.  Um intervalo é válido somente se *B* é acessível a partir do *A;* pode armazenar *um* em um objeto *N* \(*N* \= *um*\), incrementar o objeto zero ou mais vezes \(\+ \+*N*\), e o objeto comparados como iguais a *B* após um número finito de incrementos \(N \= \= B*\).*  
  
-   A frase "cada *N* no intervalo \[*um*, *B*\)" significa que *N* começa com o valor *um* e é incrementado zero ou mais vezes até que ele é igual ao valor *B*.  O caso *N* \= \= *B* não está no intervalo.  
  
-   A frase "o valor mais baixo de *N* no intervalo \[*um*, *B*\), de modo que *X*" significa que a condição *X* é determinado para cada *N* no intervalo \[*um*, *B*\) até que a condição *X* for atendida.  
  
-   A frase "o maior valor de *N* no intervalo \[*um*, *B*\), de modo que *X* significa que *X* é determinado para cada *N* no intervalo \[*um*, *B*\).  A função armazena na `K` uma cópia do *N* sempre que a condição *X* for atendida.  Se ocorrer qualquer armazenamento de tal, a função substituirá o valor final de *N*, que é igual a *B*, com o valor de `K`.  Para um iterador de acesso aleatório ou bidirecional, no entanto, isso também pode significar que *N* começa com o valor mais alto no intervalo e é decrementado sobre o intervalo até que a condição *X* for atendida.  
  
-   Expressões como *X* \- *Y*, onde *X* e *Y* podem ser iteradores que não sejam os iteradores de acesso aleatório, destinam\-se no sentido matemático.  A função não é necessariamente avaliada operador**\-** se ele deve determinar esse valor.  O mesmo vale também para expressões como *X* \+ *N* e *X* \- *N*, onde *N* é um tipo inteiro.  
  
 Vários algoritmos de fazer uso de um predicado que executa uma comparação emparelhada, como com `operator==`, para produzir um `bool` resultados.  A função predicate `operator==`, ou qualquer substituição, não deve alterar qualquer um dos operandos.  Ele deve produzir o mesmo `bool` resultados sempre que é avaliado e ele deve produzir o mesmo resultado se o operando substituirá uma cópia de qualquer um dos operandos.  
  
 Vários algoritmos de fazer uso de um predicado que deve impor uma ordenação fraca restrita em pares de elementos de uma sequência.  Para o predicado `pr`\(*X*, *Y*\):  
  
-   Strict significa que `pr`\(*X*, *X*\) é false.  
  
-   Fraca significa que *X* e *Y* tem um equivalente se ordenação\!`pr`\(*X*, *Y*\) && \!`pr`\(*Y*, *X*\) \(*X* \=\= *Y* does not need to be defined\).  
  
-   Ordenação significa que `pr`\(*X*, *Y*\) & & `pr`\(*Y*, Z\) implica `pr`\(*X*, Z\).  
  
 Alguns desses algoritmos implicitamente usam o predicado *X* \< *Y*.  Outros predicados que normalmente satisfazem a requisito de ordenação de fraca restrita são *X* \> *Y*, **menos**\(*X*, *Y*\), e `greater`\(*X*, *Y*\).  Observe, entretanto, que predicados como *X* \< \= *Y* e *X* \> \= *Y* não atender a esse requisito.  
  
 Uma sequência de elementos designados pelo iteradores no intervalo \[`First`, `Last`\) é uma seqüência ordenada pelo operador**\<** se, para cada *N* no intervalo \[0, `Last` \- `First`\) e para cada *M* no intervalo \(N, `Last` \- `First`\) o predicado\! \(\*\(`First` \+ *M*\) \< \*\(*First* \+ *N*\)\) is true.  \(Observe que os elementos são classificados em ordem crescente\). A função predicate **operador \<**, ou qualquer substituição, não deve alterar qualquer um dos operandos.  Ele deve produzir o mesmo `bool` resultados sempre que é avaliado e ele deve produzir o mesmo resultado se o operando substituirá uma cópia de qualquer um dos operandos.  Além disso, ele deve impor uma ordenação fraca restrita nos operandos compara.  
  
 Uma sequência de elementos designados pelo iteradores no intervalo \[`First`, `Last`\) é um heap ordenado por **operador \<** se, para cada *N* no intervalo \[1, `Last` \- `First`\) o predicado\! \(\*`First` \< \*\(`First` \+ *N*\)\) is true.  \(O primeiro elemento é o maior\). Sua estrutura interna é conhecida apenas para as funções de modelo [make\_heap](../Topic/make_heap.md), [pop\_heap](../Topic/pop_heap.md), e [push\_heap](../Topic/push_heap.md).  Assim como acontece com uma seqüência ordenada, a função predicate **operador \<**, ou qualquer substituição, não deve alterar qualquer um dos operandos, e ele deve impor uma ordenação fraca restrita nos operandos compara.  Ele deve produzir o mesmo `bool` resultados sempre que é avaliado e ele deve produzir o mesmo resultado se o operando substituirá uma cópia de qualquer um dos operandos.  
  
 Os algoritmos da STL estão localizados na [\<algorithm\>](../standard-library/algorithm.md) e [\<numeric\>](../standard-library/numeric.md) arquivos de cabeçalho.  
  
## Consulte também  
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)