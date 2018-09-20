---
title: 'MakeAllocator:: ~ MakeAllocator destruidor | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::MakeAllocator::~MakeAllocator
dev_langs:
- C++
helpviewer_keywords:
- ~MakeAllocator, destructor
ms.assetid: f1299c5f-cc6b-4d4e-85d4-aee1be0e2b0a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5ba40aa98321956f19de30f5f4002cb788ff446e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46371986"
---
# <a name="makeallocatormakeallocator-destructor"></a>Destruidor MakeAllocator::~MakeAllocator

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
~MakeAllocator();
```

## <a name="remarks"></a>Comentários

Realiza o desligamento da instância atual do **MakeAllocator** classe.

Este destruidor também exclui a memória alocada subjacente, se necessário.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Classe MakeAllocator](../windows/makeallocator-class.md)<br/>
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)