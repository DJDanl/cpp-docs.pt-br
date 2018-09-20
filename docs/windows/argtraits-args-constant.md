---
title: 'Constante argtraits:: args | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::ArgTraits::args
dev_langs:
- C++
helpviewer_keywords:
- args constant
ms.assetid: a68100ab-254b-4571-a0bc-946f1633a46b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 504909cba41588c0ccefccabfbd541a39d4327b2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46387335"
---
# <a name="argtraitsargs-constant"></a>Constante ArgTraits::args

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
static const int args = -1; ;
```

## <a name="remarks"></a>Comentários

Mantém uma contagem do número de parâmetros `Invoke` método da interface de um delegado.

## <a name="remarks"></a>Comentários

Quando **args** igual a -1 indica que não pode haver nenhuma correspondência para o `Invoke` assinatura do método.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Estrutura ArgTraits](../windows/argtraits-structure.md)<br/>
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)