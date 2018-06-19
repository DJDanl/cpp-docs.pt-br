---
title: 4.1 OMP_SCHEDULE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: d0dce411-2351-4ee9-a1cc-c0322a58b65c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7e13332077a40e741f56b5602ac5197bbdfef071
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33691044"
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