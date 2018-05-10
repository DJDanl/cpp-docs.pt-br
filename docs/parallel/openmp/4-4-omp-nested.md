---
title: 4.4 OMP_NESTED | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: fd17b6f4-84e8-44c0-a96a-3a9e5ba33688
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1779b75774a2177a0d6a4f0661406e28b479a7ee
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="44-ompnested"></a>4.4 OMP_NESTED
O `OMP_NESTED` variável de ambiente habilita ou desabilita o paralelismo aninhado a menos que o paralelismo aninhado está habilitado ou desabilitado, chamando o `o` **mp_set_nested** rotina de biblioteca. Se definido como **TRUE**, paralelismo aninhado está habilitado; se ela for definida como **FALSE**aninhados paralelismo está desabilitado. O valor padrão é **FALSE**.  
  
 Exemplo:  
  
```  
setenv OMP_NESTED TRUE  
```  
  
## <a name="cross-reference"></a>Referência cruzada:  
  
-   `omp_set_nested` função, consulte [seção 3.1.9](../../parallel/openmp/3-1-9-omp-set-nested-function.md) na página 40.