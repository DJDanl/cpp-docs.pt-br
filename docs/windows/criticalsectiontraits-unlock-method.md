---
title: 'Método criticalsectiontraits:: Unlock | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits::Unlock
dev_langs:
- C++
helpviewer_keywords:
- Unlock method
ms.assetid: 8fb382f5-6eda-407e-9673-71d77bda4962
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5babc5c14baae474409cd364af31b70549fcefe5
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46413010"
---
# <a name="criticalsectiontraitsunlock-method"></a>Método CriticalSectionTraits::Unlock

É especialista um `CriticalSection` modelo para que ele dá suporte a liberar propriedade do objeto especificado de seção crítica.

## <a name="syntax"></a>Sintaxe

```cpp
inline static void Unlock(
   _In_ Type cs
);
```

### <a name="parameters"></a>Parâmetros

*cs*<br/>
Um ponteiro para um objeto de seção crítica.

## <a name="remarks"></a>Comentários

O `Type` modificador é definido como `typedef CRITICAL_SECTION* Type;`.

Para obter mais informações, consulte **função LeaveCriticalSection** na **funções de sincronização** seção da documentação da API do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="see-also"></a>Consulte também

[Estrutura CriticalSectionTraits](../windows/criticalsectiontraits-structure.md)