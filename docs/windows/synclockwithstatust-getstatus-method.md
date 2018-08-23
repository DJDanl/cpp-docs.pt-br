---
title: 'Método synclockwithstatust:: getStatus | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::GetStatus
dev_langs:
- C++
helpviewer_keywords:
- GetStatus method
ms.assetid: d448b51d-a63d-40d9-a9ee-4aad3204118d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c2cef491aac3350c1692c2f87236f3cbf01dd9b0
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42612072"
---
# <a name="synclockwithstatustgetstatus-method"></a>Método SyncLockWithStatusT::GetStatus

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
DWORD GetStatus() const;
```

## <a name="return-value"></a>Valor de retorno

O resultado de uma operação de espera no objeto que se baseia o **SyncLockWithStatusT** classe, como um [Mutex](../windows/mutex-class1.md) ou [semáforo](../windows/semaphore-class.md). Zero (0) indica que a operação de espera retornado o estado sinalizado; Caso contrário, outro estado ocorreu, como o valor de tempo limite decorrido.

## <a name="remarks"></a>Comentários

Recupera o status de espera do atual **SyncLockWithStatusT** objeto.

A função getStatus () recupera o valor do subjacente [status _](../windows/synclockwithstatust-status-data-member.md) membro de dados. Quando um objeto com base nas **SyncLockWithStatusT** classe executa uma operação de bloqueio, o objeto primeiro aguardará para o objeto se torne disponível. O resultado dessa operação de espera é armazenado no `status_` membro de dados. Os valores possíveis do `status_` membro de dados são os valores de retorno da operação de espera. Para obter mais informações, consulte os valores de retorno de `WaitForSingleObjectEx()` função na biblioteca MSDN.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::Details

## <a name="see-also"></a>Consulte também

[Classe SyncLockWithStatusT](../windows/synclockwithstatust-class.md)