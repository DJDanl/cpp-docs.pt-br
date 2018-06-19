---
title: 4.3 OMP_DYNAMIC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: a15edefb-1f85-4f06-a427-beb3cfc4434f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f376fe639d9bca58b6e2bd55fd081b88921a7342
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33686666"
---
# <a name="43-ompdynamic"></a>4.3 OMP_DYNAMIC
O **OMP_DYNAMIC** variável de ambiente ativa ou desativa o ajuste dinâmico do número de threads disponíveis para execução de regiões paralelas, a menos que o ajuste dinâmico é habilitado ou desabilitado chamando o explicitamente**omp_set_dynamic** rotina de biblioteca. O valor deve ser **TRUE** ou **FALSE**.  
  
 Se definido como **TRUE**, o número de threads que são usados para a execução paralelas regiões pode ser ajustado pelo ambiente de tempo de execução para utilizar melhor os recursos do sistema.  Se definido como **FALSE**, ajuste dinâmico está desabilitado. A condição padrão é definido pela implementação.  
  
 Exemplo:  
  
```  
setenv OMP_DYNAMIC TRUE  
```  
  
## <a name="cross-references"></a>Entre referências:  
  
-   Para obter mais informações sobre regiões paralelas, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8.  
  
-   **omp_set_dynamic** funcionam, consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.