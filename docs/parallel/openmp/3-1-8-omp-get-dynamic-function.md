---
title: "3.1.8 função omp_get_dynamic | Microsoft Docs"
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
ms.assetid: c03e2daf-29c9-49e3-9b67-b980ad1ab195
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bd4ec73b82848efcdface781738639b05a256958
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="318-ompgetdynamic-function"></a>3.1.8 função omp_get_dynamic
O **omp_get_dynamic** função retorna um valor diferente de zero se ajuste dinâmico de threads está habilitado e, caso contrário, retornará 0. O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_get_dynamic(void);  
```  
  
 Se a implementação não implementar ajuste dinâmico do número de threads, essa função sempre retorna 0.  
  
## <a name="cross-references"></a>Entre referências:  
  
-   Para obter uma descrição de ajuste de thread dinâmica, consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.