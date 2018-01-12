---
title: "Enumeração Platform:: callbackcontext | Microsoft Docs"
ms.custom: 
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: VCCORLIB/Platform::CallbackContext
dev_langs: C++
helpviewer_keywords: Platform::CallbackContext Enumeration
ms.assetid: 60e0c7cb-5d8f-482a-bdca-ca9335ae4899
caps.latest.revision: "3"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ede3cfecadbe87caf5182e0d3df9c25a481f3079
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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