---
title: Enumerações de namespace de simultaneidade (AMP) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- amp/Concurrency::access_type
- amp/Concurrency::queuing_mode
dev_langs:
- C++
ms.assetid: 4c87457e-184f-4992-81ab-ca75e7d524ab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a67b5e77b8ab8c52e55dea96e64a3f16a4d70e39
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33695662"
---
# <a name="concurrency-namespace-enums-amp"></a>Enumerações de namespace de simultaneidade (AMP)
|||  
|-|-|  
|[Enumeração access_type](#access_type)|[Enumeração queuing_mode](#queuing_mode)|  
  
##  <a name="access_type"></a>  Enumeração access_type  
 Tipo de enumeração usado para indicar vários tipos de acesso a dados.  
  
```  
enum access_type;  
```  
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`access_type_auto`|Escolher automaticamente a melhor `access_type` para o acelerador.|  
|`access_type_none`|Dedicada. A alocação só é acessível do Accelerator e não na CPU.|  
|`access_type_read`|Compartilhado. A alocação é acessível do Accelerator e pode ser lida na CPU.|  
|`access_type_read_write`|Compartilhado. A alocação está acessível do Accelerator e é gravável na CPU.|  
|`access_type_write`|Compartilhado. A alocação está acessível do Accelerator e é legível e gravável na CPU.|  

  
##  <a name="queuing_mode"></a>  Enumeração queuing_mode  
 Especifica os modos de enfileiramento de mensagens que têm suporte para o acelerador.  
  
```  
enum queuing_mode;  
``` 
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`queuing_mode_immediate`|Um modo de enfileiramento de mensagens que especifica que quaisquer comandos como, por exemplo, [função (C++ AMP) parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each), são enviados para o dispositivo correspondente do acelerador assim que elas retornam ao chamador.|  
|`queuing_mode_automatic`|Um modo de enfileiramento de mensagens que especifica os comandos serão enfileirados em uma fila de comando que corresponde do [accelerator_view](accelerator-view-class.md) objeto. Comandos são enviados para o dispositivo quando [accelerator_view:: Flush](accelerator-view-class.md#flush) é chamado.|   
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
