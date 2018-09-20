---
title: 2.6.3 diretiva barrier | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 4485a3d7-533f-4fec-8128-a131bec7fa16
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8654534143e6feed06e93406c8fe03983ee9c2fc
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46429143"
---
# <a name="263-barrier-directive"></a>2.6.3 Diretiva barrier

O **barreira** diretiva sincroniza todos os threads em uma equipe. Quando encontrados, cada thread em que a equipe espera até que todos os outros tenham atingido neste ponto. A sintaxe do **barreira** diretiva é da seguinte maneira:

```
#pragma omp barrier new-line
```

Depois que todos os threads da equipe tiveram encontrado a barreira, cada thread em que a equipe começa a executar as instruções após a diretiva de barreira em paralelo. Observe que, como o **barreira** diretiva não tem uma instrução de linguagem C como parte de sua sintaxe, há algumas restrições sobre seu posicionamento dentro de um programa. Ver [Apêndice C](../../parallel/openmp/c-openmp-c-and-cpp-grammar.md) para conhecer a gramática formal. O exemplo a seguir ilustra essas restrições.

```
/* ERROR - The barrier directive cannot be the immediate
*          substatement of an if statement
*/
if (x!=0)
   #pragma omp barrier
...

/* OK - The barrier directive is enclosed in a
*      compound statement.
*/
if (x!=0) {
   #pragma omp barrier
}
```