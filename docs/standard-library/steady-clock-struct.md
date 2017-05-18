---
title: Struct steady_clock | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- chrono/std::chrono::steady_clock
dev_langs:
- C++
ms.assetid: 970d12ec-fc80-4391-a2f7-b57b2aec668d
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 4ecf60434799708acab4726a95380a2d3b9dbb3a
ms.openlocfilehash: 332008ed313eeae7f04f39165424a9280c2aed8c
ms.contentlocale: pt-br
ms.lasthandoff: 04/19/2017

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

