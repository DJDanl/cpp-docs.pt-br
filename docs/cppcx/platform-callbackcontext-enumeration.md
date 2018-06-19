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
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 757de5f686bb809a5d2fb159a3ee547a20edc982
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33086936"
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
 **Suporte mínimo de cliente:** Windows 8  
  
 **Suporte mínimo de servidor:** Windows Server 2012  
  
 **Namespace:** Platform  
  
 **Metadados:** platform.winmd