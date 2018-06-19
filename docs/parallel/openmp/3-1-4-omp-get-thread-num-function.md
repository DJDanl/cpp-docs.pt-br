---
title: 3.1.4 função omp_get_thread_num | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 5220402b-c109-4b1f-ba79-002e93d08617
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fad749b91470f7834169fe8ed734f1d627aa228e
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33686065"
---
# <a name="314-ompgetthreadnum-function"></a>3.1.4 função omp_get_thread_num
O `omp_get_thread_num` função retorna o número de threads, dentro de sua equipe do thread executando a função. O consiste de thread número entre 0 e **omp_get_num_threads()**-1, inclusivo. O thread principal da equipe é 0.  
  
 O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_get_thread_num(void);  
```  
  
 Se for chamado de uma região de série, `omp_get_thread_num` retornará 0. Se chamado de dentro de uma região parallel aninhada é serializado, essa função retornará 0.  
  
## <a name="cross-references"></a>Entre referências:  
  
-   `omp_get_num_threads` função, consulte [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37.