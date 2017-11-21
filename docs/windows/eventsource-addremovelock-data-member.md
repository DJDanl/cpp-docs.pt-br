---
title: Membro de dados EventSource::addRemoveLock_ | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: event/Microsoft::WRL::EventSource::addRemoveLock_
dev_langs: C++
helpviewer_keywords: addRemoveLock_ data member
ms.assetid: e2d69256-4891-4aad-ad0b-76479c0bb076
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 1eb3a62429883ce8b2ff39828cdcdff47624f894
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="eventsourceaddremovelock-data-member"></a>Membro de dados EventSource::addRemoveLock_
Sincroniza o acesso para o [targets _](../windows/eventsource-targets-data-member.md) matriz durante a adição, remoção ou chamar manipuladores de eventos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
Wrappers::SRWLock addRemoveLock_;  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft:: wrl
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)