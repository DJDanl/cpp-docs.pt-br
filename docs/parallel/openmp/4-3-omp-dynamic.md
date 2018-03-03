---
title: 4.3 OMP_DYNAMIC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: a15edefb-1f85-4f06-a427-beb3cfc4434f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 103067b28990854fb6522c19f4349a9607d65bab
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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