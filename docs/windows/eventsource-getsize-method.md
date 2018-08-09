---
title: 'Método EventSource:: GetSize | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::EventSource::GetSize
dev_langs:
- C++
helpviewer_keywords:
- GetSize method
ms.assetid: 7825aab5-1a6b-465f-9159-3a6684142d1f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 49497c8b33641521a66c3e84dc2dae3dbd993699
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39645042"
---
# <a name="eventsourcegetsize-method"></a>Método EventSource::GetSize
Recupera o número de manipuladores de eventos associados ao atual **EventSource** objeto  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
size_t GetSize() const;  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O número de manipuladores de eventos em [targets _](../windows/eventsource-targets-data-member.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Event. h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe EventSource](../windows/eventsource-class.md)