---
title: 'Método weakref:: CopyTo | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::WeakRef::CopyTo
dev_langs:
- C++
helpviewer_keywords:
- CopyTo method
ms.assetid: f83de6da-b3d4-41a6-9845-cd725ecf3b75
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 791e9040d9e35c7dfb657cca38e26c01e86c86c4
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42594415"
---
# <a name="weakrefcopyto-method"></a>Método WeakRef::CopyTo

Atribui um ponteiro para uma interface, se disponível, para a variável de ponteiro especificado.

## <a name="syntax"></a>Sintaxe

```cpp
HRESULT CopyTo(
   REFIID riid,
   _Deref_out_ IInspectable** ptr
);

template<typename U>
HRESULT CopyTo(
   _Deref_out_ U** ptr
);

HRESULT CopyTo(
   _Deref_out_ IWeakReference** ptr
);
```

### <a name="parameters"></a>Parâmetros

*U*  
Ponteiro um `IInspectable` interface. Um erro será emitido se *U* não é derivado de `IInspectable`.

*riid*  
Uma ID de interface. Um erro será emitido se *riid* não é derivado de `IWeakReference`.

*ptr*  
Um ponteiro indireto duplamente para `IInspectable` ou `IWeakReference`.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve a falha. Para obter mais informações, consulte **Comentários**.

## <a name="remarks"></a>Comentários

Um valor de retorno de S_OK significa que essa operação foi bem-sucedida, mas não indica se a referência fraca foi resolvida para uma referência forte. Se for retornado S_OK, esse parâmetro de teste *p* é uma ótima referência; ou seja, o parâmetro *p* não for igual a **nullptr**.

A partir do SDK do Windows 10, esse método não define o **WeakRef** instância **nullptr** se não foi possível obter a referência fraca, portanto, você deve evitar erro ao verificar o código que verifica o WeakRef para **nullptr**. Em vez disso, verifique *ptr* para **nullptr**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe WeakRef](../windows/weakref-class.md)