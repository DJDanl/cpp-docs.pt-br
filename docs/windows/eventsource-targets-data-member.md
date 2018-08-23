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
ms.openlocfilehash: fcdcb759c90009410f76a4b10039a0d976ca0cc4
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42605109"
---
# <a name="eventsourcetargets-data-member"></a>Membro de dados EventSource::targets_

Uma matriz de um ou mais manipuladores de eventos.

## <a name="syntax"></a>Sintaxe

```cpp
ComPtr<Details::EventTargetArray> targets_;
```

## <a name="remarks"></a>Comentários

Quando o evento que é representado por atual **EventSource** objeto ocorre, os manipuladores de eventos são chamados.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também
[Classe EventSource](../windows/eventsource-class.md)