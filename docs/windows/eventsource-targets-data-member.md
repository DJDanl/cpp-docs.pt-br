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
ms.openlocfilehash: a35992a5579bf852323f4c01396fab56542f40cd
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33871738"
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
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)