---
title: 'Construtor roinitializewrapper:: Roinitializewrapper | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper::RoInitializeWrapper
dev_langs:
- C++
ms.assetid: c6f7fb07-14af-4574-9135-cea164607f30
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8b5cf858ae3fb3974898428b8437784ac3ce324e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46416273"
---
# <a name="roinitializewrapperroinitializewrapper-constructor"></a>Construtor RoInitializeWrapper::RoInitializeWrapper

Inicializa uma nova instância dos **RoInitializeWrapper** classe.

## <a name="syntax"></a>Sintaxe

```cpp
RoInitializeWrapper(   RO_INIT_TYPE flags)  
```

### <a name="parameters"></a>Parâmetros

*flags*<br/>
Uma das enumerações RO_INIT_TYPE, que especifica o suporte fornecido pelo tempo de execução do Windows.

## <a name="remarks"></a>Comentários

O **RoInitializeWrapper** classe invoca `Windows::Foundation::Initialize(flags)`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe HandleT](../windows/handlet-class.md)