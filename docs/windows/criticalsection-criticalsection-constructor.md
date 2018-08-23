---
title: 'Construtor CriticalSection:: CriticalSection | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::CriticalSection::CriticalSection
dev_langs:
- C++
helpviewer_keywords:
- CriticalSection, constructor
ms.assetid: 930b89be-4d74-46bd-8879-5dd4d15bcbd0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 892a32c6ff6f8e9a3a30452d05dd6e15c38a4fa8
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42605046"
---
# <a name="criticalsectioncriticalsection-constructor"></a>Construtor CriticalSection::CriticalSection

Inicializa um objeto de sincronização que é semelhante a um objeto de mutex, mas pode ser usado por apenas os threads de um único processo.

## <a name="syntax"></a>Sintaxe

```cpp
explicit CriticalSection(
   ULONG spincount = 0
);
```

### <a name="parameters"></a>Parâmetros

*spincount*  
A contagem de rotação para o objeto de seção crítica. O valor padrão é 0.

## <a name="remarks"></a>Comentários

Para obter mais informações sobre as seções críticas e spincounts, consulte o `InitializeCriticalSectionAndSpinCount` funcionar a **sincronização** seção da documentação de API do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe CriticalSection](../windows/criticalsection-class.md)