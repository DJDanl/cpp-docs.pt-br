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
ms.openlocfilehash: d67453b636d50fcb78092318ebb76f5192817548
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46442728"
---
# <a name="265-flush-directive"></a>2.6.5 Diretiva flush

O **liberar** diretiva, explícita ou implícita, especifica um ponto de sequência de "thread cruzado" em que a implementação é necessário para garantir que todos os threads em uma equipe tenham uma exibição consistente de determinados objetos (especificado abaixo) no memória. Isso significa que avaliações anteriores das expressões que referenciam esses objetos forem concluídas e as avaliações subsequentes ainda não começaram. Por exemplo, os compiladores devem restaurar os valores dos objetos de registros para a memória e hardware talvez seja necessário liberar os buffers de gravação para a memória e recarregar os valores dos objetos da memória.

A sintaxe do **liberar** diretiva é da seguinte maneira:

```
#pragma omp flush [(variable-list)]  new-line
```

Se os objetos que requerem sincronização podem ser designados por variáveis, essas variáveis podem ser especificadas na opcional *lista variável*. Se um ponteiro estiver presente na *lista variável*, o ponteiro em si é liberado, não o objeto que o ponteiro se refere a.

Um **liberar** diretiva sem uma *lista variável* sincroniza objetos todos compartilhados, exceto objetos inacessíveis com duração automática de armazenamento. (Isso é provavelmente terá mais sobrecarga do que um **liberar** com um *lista variável*.) Um **liberar** diretiva sem uma *lista variável* é implícita para as seguintes diretivas:

- `barrier`

- Na entrada e saída de **crítico**

- Na entrada e saída de `ordered`

- Na entrada e saída de **paralela**

- AT sair do **para**

- AT sair do **seções**

- AT sair do **único**

- Na entrada e saída de **paralelo para**

- Na entrada e saída de **seções em paralelo**

A diretiva não é implícita se um `nowait` cláusula estiver presente. É importante observar que o **liberar** diretiva não é implícita para qualquer um dos seguintes:

- Na entrada para **para**

- Na entrada ou saída de **mestre**

- Na entrada para **seções**

- Na entrada para **único**

Uma referência que acessa o valor de um objeto com um tipo qualificado como volátil se comporta como se houvesse uma **liberar** diretiva especificando o objeto no ponto de sequência anterior. Uma referência que modifica o valor de um objeto com um tipo qualificado como volátil se comporta como se houvesse uma **liberar** diretiva especificando o objeto no ponto de sequência subsequente.

Observe que, como o **liberar** diretiva não tem uma instrução de linguagem C como parte de sua sintaxe, há algumas restrições sobre seu posicionamento dentro de um programa. Ver [Apêndice C](../../parallel/openmp/c-openmp-c-and-cpp-grammar.md) para conhecer a gramática formal. O exemplo a seguir ilustra essas restrições.

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

- Uma variável especificada em uma **liberar** diretiva não deve ter um tipo de referência.