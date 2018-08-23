---
title: Namespace Microsoft::WRL::wrappers::Details | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details
- internal/Microsoft::WRL::Details
- async/Microsoft::WRL::Details
- corewrappers/Microsoft::WRL::Wrappers::Details
- client/Microsoft::WRL::Details
- module/Microsoft::WRL::Details
- event/Microsoft::WRL::Details
dev_langs:
- C++
helpviewer_keywords:
- Details namespace
ms.assetid: 6d3f04ac-9b53-4a82-a188-a85309ec34a4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3af5add0a934b59cf3027b7beb0ea000a7ae1415
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42595701"
---
# <a name="microsoftwrlwrappersdetails-namespace"></a>Namespace Microsoft::WRL::Wrappers::Details

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
namespace Microsoft::WRL::Wrappers::Details;
```

## <a name="members"></a>Membros

### <a name="classes"></a>Classes

|Nome|Descrição|
|----------|-----------------|
|[Classe SyncLockT](../windows/synclockt-class.md)|Representa um tipo que pode levar exclusivo ou a propriedade compartilhada de um recurso.|
|[Classe SyncLockWithStatusT](../windows/synclockwithstatust-class.md)|Representa um tipo que pode levar exclusivo ou a propriedade compartilhada de um recurso.|

### <a name="methods"></a>Métodos

|Nome|Descrição|
|----------|-----------------|
|[Método CompareStringOrdinal](../windows/comparestringordinal-method.md)|Compara dois especificado `HSTRING` objetos e retorna um inteiro que indica sua posição relativa em uma ordem de classificação.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)