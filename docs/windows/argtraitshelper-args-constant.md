---
title: 'Constante argtraitshelper:: args | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::ArgTraitsHelper::args
dev_langs:
- C++
helpviewer_keywords:
- args constant
ms.assetid: 1c0efa32-c072-43e3-bbd9-a3f6aec069a2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e4817d0f0082ef4ec0a9a588982405772d733fe0
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42598026"
---
# <a name="argtraitshelperargs-constant"></a>Constante ArgTraitsHelper::args

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
static const int args = Traits::args;
```

## <a name="remarks"></a>Comentários

Ajuda [argtraitshelper:: args](../windows/argtraitshelper-args-constant.md) manter a contagem do número de parâmetros `Invoke` método da interface de um delegado.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Estrutura ArgTraitsHelper](../windows/argtraitshelper-structure.md)  
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)