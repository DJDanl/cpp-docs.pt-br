---
title: 'Weakref:: Operator&amp; operador | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::WeakRef::operator&
dev_langs:
- C++
helpviewer_keywords:
- operator& operator
ms.assetid: 900afb73-3801-4d08-9b41-2e6a62011ccd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f8bb81ca1591fc398b1d0814fca918309169e82c
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42600978"
---
# <a name="weakrefoperatoramp-operator"></a>Weakref:: Operator&amp; operador

Retorna um `ComPtrRef` objeto que representa o atual **WeakRef** objeto.

## <a name="syntax"></a>Sintaxe

```cpp
Details::ComPtrRef<WeakRef> operator&() throw()  
```

## <a name="return-value"></a>Valor de retorno

Um `ComPtrRef` objeto que representa o atual **WeakRef** objeto.

## <a name="remarks"></a>Comentários

Este é um operador auxiliar interno que não se destina a ser usado em seu código.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe WeakRef](../windows/weakref-class.md)