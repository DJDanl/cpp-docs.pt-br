---
title: 'Método makeallocator:: allocate | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::MakeAllocator::Allocate
dev_langs:
- C++
helpviewer_keywords:
- Allocate method
ms.assetid: a01997bc-4ff1-4ed0-9def-e4aaa15b0598
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4422dea0b0bfb07904d0c4defad8f33281a51bec
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42609856"
---
# <a name="makeallocatorallocate-method"></a>Método MakeAllocator::Allocate

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
__forceinline void* Allocate();
```

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, um ponteiro para a memória alocada; Caso contrário, **nullptr**.

## <a name="remarks"></a>Comentários

Aloca memória e o associa ao atual **MakeAllocator** objeto.

O tamanho da memória alocada é o tamanho do tipo especificado pelo atual **MakeAllocator** parâmetro de modelo.

Um desenvolvedor precisar substituir apenas a **Allocate()** método para implementar um modelo de alocação de memória diferentes.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Classe MakeAllocator](../windows/makeallocator-class.md)  
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)