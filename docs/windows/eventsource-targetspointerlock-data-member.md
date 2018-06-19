---
title: Membro de dados EventSource::targetsPointerLock_ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::EventSource::targetsPointerLock_
dev_langs:
- C++
helpviewer_keywords:
- targetsPointerLock_ data member
ms.assetid: 8f08409f-5262-4be7-9cf1-2ed15f19684a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: fb3c2131331521dab1b8264b696206d953762851
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33873102"
---
# <a name="eventsourcetargetspointerlock-data-member"></a>Membro de dados EventSource::targetsPointerLock_
Sincroniza o acesso a membros de dados internos, mesmo quando os manipuladores de eventos para essa EventSource estão sendo adicionados, removidos ou invocado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
Wrappers::SRWLock targetsPointerLock_;  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)