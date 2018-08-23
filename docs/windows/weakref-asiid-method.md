---
title: 'Método weakref:: Asiid | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::WeakRef::AsIID
dev_langs:
- C++
helpviewer_keywords:
- AsIID method
ms.assetid: 94e87309-32da-4dbb-8233-e77313a1f448
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8844828028e174bd216bddb7e7c82cc9e5971a90
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42594877"
---
# <a name="weakrefasiid-method"></a>Método WeakRef::AsIID

Define especificado `ComPtr` parâmetro de ponteiro para representar a ID de interface especificado.

## <a name="syntax"></a>Sintaxe

```cpp
HRESULT AsIID(
   REFIID riid,
   _Out_ ComPtr<IInspectable>* ptr
);
```

### <a name="parameters"></a>Parâmetros

*riid*  
Uma ID de interface.

*ptr*  
Quando essa operação for concluída, um objeto que representa o parâmetro *riid*.

## <a name="return-value"></a>Valor de retorno

- S_OK se essa operação for bem-sucedida; Caso contrário, um HRESULT que indica o motivo pelo qual a operação falhou, e *ptr* é definido como **nullptr**.

- S_OK se essa operação for bem-sucedida, mas atual **WeakRef** o objeto já foi liberado. Parâmetro *ptr* é definido como **nullptr**.

- S_OK se essa operação for bem-sucedida, mas atual **WeakRef** objeto não é derivado do parâmetro *riid*. Parâmetro *ptr* é definido como **nullptr**. (Para obter mais informações, consulte comentários).

## <a name="remarks"></a>Comentários

Um erro será emitido se parâmetro *riid* não é derivado de `IInspectable`. Esse erro substitui o valor de retorno.

O primeiro modelo é a forma que você deve usar em seu código. O segundo modelo (não mostrados aqui, mas declarados no arquivo de cabeçalho) é uma especialização de auxiliar interno, que dá suporte a recursos da linguagem C++, como o [automática](../cpp/auto-cpp.md) palavra-chave de dedução de tipo.

A partir do SDK do Windows 10, esse método não define o **WeakRef** instância **nullptr** se não foi possível obter a referência fraca, portanto, você deve evitar a verificação de erros de código que verifica a **WeakRef** para **nullptr**. Em vez disso, verifique *ptr* para **nullptr**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe WeakRef](../windows/weakref-class.md)