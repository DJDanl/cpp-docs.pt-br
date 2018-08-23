---
title: 'Método weakref:: as | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::WeakRef::As
dev_langs:
- C++
helpviewer_keywords:
- As method
ms.assetid: 7173da62-b3fe-44d6-aea4-1aa97e69b221
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c2a56904fb3709137c167513d0eba426bda7ad14
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42589363"
---
# <a name="weakrefas-method"></a>Método WeakRef::As

Define especificado `ComPtr` parâmetro de ponteiro para representar a interface especificada.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename U>
HRESULT As(
   _Out_ ComPtr<U>* ptr
);

template<typename U>
HRESULT As(
   _Out_ Details::ComPtrRef<ComPtr<U>> ptr
);
```

### <a name="parameters"></a>Parâmetros

*U*  
Uma ID de interface.

*ptr*  
Quando essa operação for concluída, um objeto que representa o parâmetro *U*.

## <a name="return-value"></a>Valor de retorno

- S_OK se essa operação for bem-sucedida; Caso contrário, um HRESULT que indica o motivo pelo qual a operação falhou, e *ptr* é definido como **nullptr**.

- S_OK se essa operação for bem-sucedida, mas atual **WeakRef** o objeto já foi liberado. Parâmetro *ptr* é definido como **nullptr**.

- S_OK se essa operação for bem-sucedida, mas atual **WeakRef** objeto não é derivado do parâmetro *U*. Parâmetro *ptr* é definido como **nullptr**.

## <a name="remarks"></a>Comentários

Um erro será emitido se parâmetro *U* é `IWeakReference`, ou não é derivado de `IInspectable`.

O primeiro modelo é a forma que você deve usar em seu código. O segundo modelo é uma especialização de auxiliar interno, que dá suporte a recursos da linguagem C++, como o [automática](../cpp/auto-cpp.md) palavra-chave de dedução de tipo.

A partir do SDK do Windows 10, esse método não define o **WeakRef** instância **nullptr** se não foi possível obter a referência fraca, portanto, você deve evitar a verificação de erros de código que verifica o WeakRef para **nullptr**. Em vez disso, verifique *ptr* para **nullptr**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe WeakRef](../windows/weakref-class.md)