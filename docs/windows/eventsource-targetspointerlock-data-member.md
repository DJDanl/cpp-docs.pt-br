---
title: Membro de dados EventSource::targetsPointerLock_ | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: event/Microsoft::WRL::EventSource::targetsPointerLock_
dev_langs: C++
helpviewer_keywords: targetsPointerLock_ data member
ms.assetid: 8f08409f-5262-4be7-9cf1-2ed15f19684a
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: be274d7bcf970795df69744324332d29f252363a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="eventsourcetargetspointerlock-data-member"></a>Membro de dados EventSource::targetsPointerLock_
Sincroniza o acesso a membros de dados internos, mesmo quando os manipuladores de eventos para essa EventSource estão sendo adicionados, removidos ou invocado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
Wrappers::SRWLock targetsPointerLock_;  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft:: wrl
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)