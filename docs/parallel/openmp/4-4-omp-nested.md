---
title: 4.4 OMP_NESTED | Microsoft Docs
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
ms.assetid: fd17b6f4-84e8-44c0-a96a-3a9e5ba33688
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 50b2b110f191252702da9a2b6eed99baa40b7814
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="44-ompnested"></a>4.4 OMP_NESTED
O `OMP_NESTED` variável de ambiente habilita ou desabilita o paralelismo aninhado a menos que o paralelismo aninhado está habilitado ou desabilitado, chamando o `o` **mp_set_nested** rotina de biblioteca. Se definido como **TRUE**, paralelismo aninhado está habilitado; se ela for definida como **FALSE**aninhados paralelismo está desabilitado. O valor padrão é **FALSE**.  
  
 Exemplo:  
  
```  
setenv OMP_NESTED TRUE  
```  
  
## <a name="cross-reference"></a>Referência cruzada:  
  
-   `omp_set_nested`função, consulte [seção 3.1.9](../../parallel/openmp/3-1-9-omp-set-nested-function.md) na página 40.