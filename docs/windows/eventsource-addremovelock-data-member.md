---
title: Membro de dados EventSource::addRemoveLock_ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::EventSource::addRemoveLock_
dev_langs:
- C++
helpviewer_keywords:
- addRemoveLock_ data member
ms.assetid: e2d69256-4891-4aad-ad0b-76479c0bb076
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 46763a6376a18ae469833c3eee6a0d5d9f15ee45
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33872647"
---
# <a name="eventsourceaddremovelock-data-member"></a>Membro de dados EventSource::addRemoveLock_
Sincroniza o acesso para o [targets _](../windows/eventsource-targets-data-member.md) matriz durante a adição, remoção ou chamar manipuladores de eventos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
Wrappers::SRWLock addRemoveLock_;  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)