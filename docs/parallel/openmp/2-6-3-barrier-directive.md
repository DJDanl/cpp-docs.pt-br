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
ms.openlocfilehash: 68df92207feb45a77055098cdb1227a68b04bcab
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="263-barrier-directive"></a>2.6.3 Diretiva barrier
O **barreira** diretiva sincroniza todos os threads em uma equipe. Quando encontrada, cada thread na equipe aguarda até que todos os outros tem atingido esse ponto. A sintaxe do **barreira** diretiva é da seguinte maneira:  
  
```  
#pragma omp barrier new-line  
```  
  
 Depois que todos os threads na equipe encontrou a barreira, cada thread na equipe começa a executar as instruções após a diretiva de barreira em paralelo. Observe que, como o **barreira** diretiva não tem uma instrução de linguagem C como parte de sua sintaxe, há algumas restrições em seu posicionamento dentro de um programa. Consulte [Apêndice C](../../parallel/openmp/c-openmp-c-and-cpp-grammar.md) da gramática formal. O exemplo a seguir ilustra essas restrições.  
  
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