---
title: Membro de dados EventSource::targets_ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::EventSource::targets_
dev_langs:
- C++
helpviewer_keywords:
- targets_ data member
ms.assetid: 5d5cee05-3315-4514-bce2-19173c923c7d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e8782d66683d0a242e5321e8e3a0c8ab24b6f358
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39568843"
---
# <a name="eventsourcetargets-data-member"></a>Membro de dados EventSource::targets_
Uma matriz de um ou mais manipuladores de eventos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
ComPtr<Details::EventTargetArray> targets_;  
```  
  
## <a name="remarks"></a>Comentários  
 Quando o evento que é representado por atual **EventSource** objeto ocorre, os manipuladores de eventos são chamados.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Event. h  
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)