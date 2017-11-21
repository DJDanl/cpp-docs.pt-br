---
title: "3.1.4 função omp_get_thread_num | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 5220402b-c109-4b1f-ba79-002e93d08617
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 9beb9e81d767a11b4ca701725ac44cc19cd3c3e1
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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
  
-   `omp_get_num_threads`função, consulte [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37.