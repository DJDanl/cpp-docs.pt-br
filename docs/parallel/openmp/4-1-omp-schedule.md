---
title: 4.1 OMP_SCHEDULE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: d0dce411-2351-4ee9-a1cc-c0322a58b65c
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 330e5ea576e3cd779a7c17c21d00b6459f5e7043
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="41-ompschedule"></a>4.1 OMP_SCHEDULE
**OMP_SCHEDULE** só se aplica ao **para** e **paralelo para** diretivas com o tipo de agenda **tempo de execução**. O tamanho de bloco e de tipo de agendamento para todos os loops pode ser definido em tempo de execução definindo-se esta variável de ambiente para qualquer um dos tipos de agenda reconhecida e opcional *chunk_size*.  
  
 Para **para** e **paralelo para** diretivas que têm um tipo de agenda diferentes de **tempo de execução**, **OMP_SCHEDULE** será ignorado. O valor padrão para essa variável de ambiente é definido pela implementação. Se o valor opcional *chunk_size* for definida, o valor deve ser positivo. Se *chunk_size* não está definida, será considerado um valor de 1, exceto no caso de um **estático** agendamento. Para uma **estático** agendamento, o tamanho da parte padrão é definido como o espaço de iteração do loop dividido pelo número de threads aplicada para o loop.  
  
 Exemplo:  
  
```  
setenv OMP_SCHEDULE "guided,4"  
setenv OMP_SCHEDULE "dynamic"  
```  
  
## <a name="cross-references"></a>Entre referências:  
  
-   **para** diretiva, consulte [seção 2.4.1](../../parallel/openmp/2-4-1-for-construct.md) na página 11.  
  
-   **paralelo para** diretiva, consulte [seção 2.5.1](../../parallel/openmp/2-5-1-parallel-for-construct.md) na página 16.