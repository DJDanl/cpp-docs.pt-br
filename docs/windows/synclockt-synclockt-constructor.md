---
title: 'Construtor synclockt:: Synclockt | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT::SyncLockT
dev_langs:
- C++
helpviewer_keywords:
- SyncLockT, constructor
ms.assetid: 713dfd9f-7369-4d86-b4a0-8b32c184d89b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3dfee1d923536f519917a50ed44fd5c115007c27
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42601961"
---
# <a name="synclocktsynclockt-constructor"></a>Construtor SyncLockT::SyncLockT

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
SyncLockT(
   _Inout_ SyncLockT&& other
);

explicit SyncLockT(
   typename SyncTraits::Type sync = SyncTraits::GetInvalidValue()  
);
```

### <a name="parameters"></a>Parâmetros

*other*  
Uma referência rvalue para outro **SyncLockT** objeto.

*sync*  
Uma referência a outro `SyncLockWithStatusT` objeto.

## <a name="remarks"></a>Comentários

Inicializa uma nova instância dos **SyncLockT** classe.

O primeiro construtor inicializa o atual **SyncLockT** objeto de outro **SyncLockT** objeto especificado pelo parâmetro *outros*e, em seguida, invalida as outras  **SyncLockT** objeto. É o segundo construtor **protegidos**e a inicializa atual **SyncLockT** objeto para um estado inválido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::Details

## <a name="see-also"></a>Consulte também

[Classe SyncLockT](../windows/synclockt-class.md)