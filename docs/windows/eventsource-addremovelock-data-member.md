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
ms.openlocfilehash: 084a292ed5228f337deced74a87ee20acf0ee5ab
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42611729"
---
# <a name="eventsourceaddremovelock-data-member"></a>Membro de dados EventSource::addRemoveLock_

Sincroniza o acesso para o [targets _](../windows/eventsource-targets-data-member.md) matriz ao adicionar, remover ou invocar manipuladores de eventos.

## <a name="syntax"></a>Sintaxe

```cpp
Wrappers::SRWLock addRemoveLock_;
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também
[Classe EventSource](../windows/eventsource-class.md)