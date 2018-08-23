---
title: 'Membro de dados creatormap:: Activationid | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::CreatorMap::activationId
dev_langs:
- C++
helpviewer_keywords:
- activationId data member
ms.assetid: 77518b76-6e6a-4b48-8e2e-a4c7c67769e0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: eeaaedeb4c3806af888f36e62c8fa8e54c47eb46
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42595688"
---
# <a name="creatormapactivationid-data-member"></a>Membro de dados CreatorMap::activationId

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
union {
   const IID* clsid;
   const wchar_t* (*getRuntimeName)();
} activationId;
```

### <a name="parameters"></a>Parâmetros

*clsid*  
Uma ID de interface.

*getRuntimeName*  
Uma função que recupera o nome do tempo de execução do Windows de um objeto.

## <a name="remarks"></a>Comentários

Representa uma ID de objeto é identificada por uma ID de classe do COM clássico ou um nome de tempo de execução do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Estrutura CreatorMap](../windows/creatormap-structure.md)  
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)