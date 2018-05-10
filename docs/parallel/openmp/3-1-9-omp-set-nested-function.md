---
title: 3.1.9 função omp_set_nested | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: e4afc3aa-bb96-4314-9849-fd5df5f437d9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: df08d6eb1a93ff5852c239757d5f917e9777919b
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="319-ompsetnested-function"></a>3.1.9 função omp_set_nested
O **omp_set_nested** função habilita ou desabilita o paralelismo aninhado. O formato é o seguinte:  
  
```  
#include <omp.h>  
void omp_set_nested(int nested);  
```  
  
 Se *aninhada* é avaliada como 0, aninhados paralelismo estiver desabilitado, o que é o padrão e regiões paralelas aninhados são serializadas e executadas pelo thread atual. Se *aninhada* é avaliada como um valor diferente de zero, paralelismo aninhado está habilitado e regiões paralelas aninhados podem implantar threads adicionais para formar equipes aninhadas.  
  
 Essa função tem os efeitos descritos acima, quando chamado a partir de uma parte do programa de onde o **omp_in_parallel** função retornará zero. Se ele é chamado de uma parte do programa de onde o **omp_in_parallel** função retorna um valor diferente de zero, o comportamento dessa função é indefinido.  
  
 Essa chamada tem precedência sobre o **OMP_NESTED** variável de ambiente.  
  
 Quando o paralelismo aninhado estiver habilitado, o número de threads usados para executar regiões paralelas aninhadas é definido pela implementação. Como resultado, implementações OpenMP compatíveis são permitidas para serializar aninhadas regiões paralelas mesmo quando o paralelismo aninhado está habilitado.  
  
## <a name="cross-references"></a>Entre referências:  
  
-   **OMP_NESTED** consulte de variável de ambiente [seção 4.4](../../parallel/openmp/4-4-omp-nested.md) na página 49.  
  
-   **omp_in_parallel** funcionam, consulte [seção 3.1.6](../../parallel/openmp/3-1-6-omp-in-parallel-function.md) na página 38.