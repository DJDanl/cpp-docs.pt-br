---
title: 'Enumeração Platform:: callbackcontext | Microsoft Docs'
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::CallbackContext
dev_langs:
- C++
helpviewer_keywords:
- Platform::CallbackContext Enumeration
ms.assetid: 60e0c7cb-5d8f-482a-bdca-ca9335ae4899
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4b80fe7749fdb2f91e300cff007c01001edfa557
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42603032"
---
# <a name="platformcallbackcontext-enumeration"></a>Enumeração Platform::CallbackContext
Especifica o contexto do thread no qual uma função de retorno de chamada (manipulador de eventos) é executada.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
enum class CallbackContext {};  
```  
  
### <a name="members"></a>Membros  
  
|Type Code|Descrição|  
|---------------|-----------------|  
|Qualquer|A função de retorno de chamada pode ser executada em qualquer contexto de thread.|  
|Same|A função de retorno de chamada pode ser executada apenas no contexto de thread que iniciou a operação assíncrona.|  
  
### <a name="requirements"></a>Requisitos  
 **Mínimo de cliente com suporte:** Windows 8  
  
 **Mínimo de servidor com suporte:** Windows Server 2012  
  
 **Namespace:** Platform  
  
 **Metadados:** platform.winmd