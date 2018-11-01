---
title: 2.6.3 Diretiva barrier
ms.date: 11/04/2016
ms.assetid: 4485a3d7-533f-4fec-8128-a131bec7fa16
ms.openlocfilehash: 9079dce4b2a27e91e349fd0df8414d38cd245d2e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50637015"
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