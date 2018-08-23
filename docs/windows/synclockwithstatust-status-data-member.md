---
title: Membro de dados SyncLockWithStatusT::status_ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::status_
dev_langs:
- C++
helpviewer_keywords:
- status_ data member
ms.assetid: 466fa336-b5ff-4d43-8efd-1e87e5fddf88
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d4a9a65e7ba45d38084d1695932c3897de583f49
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42610021"
---
# <a name="synclockwithstatuststatus-data-member"></a>Membro de dados SyncLockWithStatusT::status_

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
DWORD status_;
```

## <a name="remarks"></a>Comentários

Contém o resultado da operação de espera adjacente após uma operação de bloqueio em um objeto com base no atual **SyncLockWithStatusT** objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::Details

## <a name="see-also"></a>Consulte também

[Classe SyncLockWithStatusT](../windows/synclockwithstatust-class.md)