---
title: "Enumerações de namespace de simultaneidade (AMP) | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 4c87457e-184f-4992-81ab-ca75e7d524ab
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: b9555023e01cb765ca943fcaaf785cdc2b4e2d0d
ms.lasthandoff: 02/25/2017

---
# <a name="concurrency-namespace-enums-amp"></a>Enumerações de namespace de simultaneidade (AMP)
|||  
|-|-|  
|[Enumeração access_type](#access_type)|[Enumeração queuing_mode](#queuing_mode)|  
  
##  <a name="a-nameaccesstypea--accesstype-enumeration"></a><a name="access_type"></a>Enumeração access_type  
 Tipo de enumeração usado para indicar vários tipos de acesso a dados.  
  
```  
enum access_type;  
```  
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`access_type_auto`|Escolher automaticamente o melhor `access_type` Accelerator.|  
|`access_type_none`|Dedicada. A alocação só é acessível do Accelerator e não na CPU.|  
|`access_type_read`|Compartilhado. A alocação é acessível do Accelerator e legível na CPU.|  
|`access_type_read_write`|Compartilhado. A alocação é acessível do Accelerator e pode ser gravada na CPU.|  
|`access_type_write`|Compartilhado. A alocação é acessível do Accelerator e legível e gravável na CPU.|  

  
##  <a name="a-namequeuingmodea--queuingmode-enumeration"></a><a name="queuing_mode"></a>Enumeração queuing_mode  
 Especifica os modos de enfileiramento de mensagens que são compatíveis com o acelerador.  
  
```  
enum queuing_mode;  
``` 
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`queuing_mode_immediate`|Um modo de enfileiramento de mensagens que especifica que qualquer comandos como, por exemplo, [função parallel_for_each (C++ AMP)](concurrency-namespace-functions-amp.md#parallel_for_each), são enviados ao dispositivo acelerador correspondentes assim que elas retornam ao chamador.|  
|`queuing_mode_automatic`|Um modo de enfileiramento de mensagens que especifica que comandos serão enfileirados em uma fila de comando que corresponde do [accelerator_view](accelerator-view-class.md) objeto. Os comandos são enviados ao dispositivo quando [accelerator_view:: Flush](accelerator-view-class.md#flush) é chamado.|   
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

