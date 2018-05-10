---
title: 3.1.8 função omp_get_dynamic | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: c03e2daf-29c9-49e3-9b67-b980ad1ab195
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: af7755173ab884a40a5f8a41f432f265cc1e6c32
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
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