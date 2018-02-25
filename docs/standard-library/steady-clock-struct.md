---
title: Struct steady_clock | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- chrono/std::chrono::steady_clock
dev_langs:
- C++
ms.assetid: 970d12ec-fc80-4391-a2f7-b57b2aec668d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2651b8d7bdb50997c7757f85687dcf425f6d7e2f
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="steadyclock-struct"></a>Struct steady_clock
Representa um relógio `steady`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct steady_clock;  
```  
  
## <a name="remarks"></a>Comentários  
 No Windows, steady_clock encapsula a função QueryPerformanceCounter.  
  
 Um relógio será *monotônico* se o valor retornado por uma primeira chamada a `now()` for sempre menor ou igual ao valor retornado por uma chamada posterior a `now()`.  
  
 Um relógio será *estável* se ele for *monotônico* e se o tempo entre os tiques do relógio for constante.  
  
 High_resolution_clock é um typdef para steady_clock.  
  
## <a name="public-functions"></a>Funções públicas  
  
|Função|Descrição|  
|--------------|-----------------|  
|now|Retorna a hora atual como um valor de time_point.|  
  
## <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|`system_clock::is_steady`|Contém `true`. Um `steady_clock` é *steady*.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<chrono >  
  
 **Namespace:** std::chrono  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<chrono>](../standard-library/chrono.md)   
 [Estrutura system_clock](../standard-library/system-clock-structure.md)
