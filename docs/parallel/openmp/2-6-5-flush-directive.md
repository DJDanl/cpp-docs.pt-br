---
title: 2.6.5 diretiva flush | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: a2ec5f74-9c37-424a-8376-47ab4a5829a2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ad3b34195015f57955c5be685807ec43f0a8f8c6
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="265-flush-directive"></a>2.6.5 Diretiva flush
O **liberar** diretiva, explícita ou implícita, especifica um ponto de sequência "entre threads" em que a implementação é necessário para garantir que todos os threads em uma equipe tem uma exibição consistente de determinados objetos (especificadas abaixo) no memória. Isso significa que o anteriores avaliações de expressões que fazem referência a esses objetos sejam concluídas e avaliações subsequentes ainda não foram iniciadas. Por exemplo, compiladores devem restaurar os valores dos objetos de registros para a memória e hardware pode ser necessário liberar buffers de gravação para a memória e recarregar os valores dos objetos de memória.  
  
 A sintaxe do **liberar** diretiva é da seguinte maneira:  
  
```  
#pragma omp flush [(variable-list)]  new-line  
```  
  
 Se os objetos que requerem sincronização podem ser designados por variáveis, essas variáveis podem ser especificados em opcional *lista variável*. Se houver um ponteiro no *lista variável*, o ponteiro em si é liberado, não o objeto que o ponteiro se refere a.  
  
 Um **liberar** diretiva sem um *lista variável* sincroniza compartilhadas com todos os objetos, exceto objetos inacessíveis com duração de armazenamento automática. (Isso é adequado para ter mais sobrecarga do que um **liberar** com um *variável lista*.) Um **liberar** diretiva sem um *lista variável* está implícita para as seguintes diretivas:  
  
-   `barrier`  
  
-   Na entrada e saída de **crítico**  
  
-   Na entrada e saída do `ordered`  
  
-   Na entrada e saída de **paralela**  
  
-   Ao sair do **para**  
  
-   Ao sair do **seções**  
  
-   Ao sair do **único**  
  
-   Na entrada e saída de **paralelo para**  
  
-   Na entrada e saída de **paralelo seções**  
  
 A diretiva não está implícita se um `nowait` cláusula estiver presente. Observe que o **liberar** diretiva não está implícita para qualquer um dos seguintes:  
  
-   Na entrada para **para**  
  
-   A entrada ou saída de **mestre**  
  
-   Na entrada para **seções**  
  
-   Na entrada para **único**  
  
 Uma referência que acessa o valor de um objeto com um tipo qualificado volátil se comporta como se houvesse um **liberar** diretiva especificando o objeto no ponto de sequência anterior. Uma referência que modifica o valor de um objeto com um tipo qualificado volátil se comporta como se houvesse um **liberar** diretiva especificando o objeto no ponto de sequência subsequente.  
  
 Observe que, como o **liberar** diretiva não tem uma instrução de linguagem C como parte de sua sintaxe, há algumas restrições em seu posicionamento dentro de um programa. Consulte [Apêndice C](../../parallel/openmp/c-openmp-c-and-cpp-grammar.md) da gramática formal. O exemplo a seguir ilustra essas restrições.  
  
```  
/* ERROR - The flush directive cannot be the immediate  
*          substatement of an if statement.  
*/  
if (x!=0)  
   #pragma omp flush (x)  
...  
  
/* OK - The flush directive is enclosed in a  
*      compound statement  
*/  
if (x!=0) {  
   #pragma omp flush (x)  
}  
```  
  
 Restrições para o **liberar** diretiva são da seguinte maneira:  
  
-   Uma variável especificada em uma **liberar** diretiva não deve ter um tipo de referência.