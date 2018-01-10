---
title: Membro de dados EventSource::targets_ | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: event/Microsoft::WRL::EventSource::targets_
dev_langs: C++
helpviewer_keywords: targets_ data member
ms.assetid: 5d5cee05-3315-4514-bce2-19173c923c7d
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1fb14e7cfa25cd34d6bbaf6d0b48870f1d93f991
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="eventsourcetargets-data-member"></a>Membro de dados EventSource::targets_
Uma matriz de um ou mais manipuladores de eventos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
ComPtr<Details::EventTargetArray> targets_;  
```  
  
## <a name="remarks"></a>Comentários  
 Quando ocorre o evento que é representado pelo objeto EventSource atual, os manipuladores de eventos são chamados.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft:: wrl
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)