---
title: 'Comptrref:: Operator! = operador | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::Details::ComPtrRef::operator!=
dev_langs:
- C++
ms.assetid: ab3093cc-6fbd-4039-890a-6df1cde992b6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0f4aeb3bc5b2ee0598cf9e7d3f572f1f0e5fb5f2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46393172"
---
# <a name="comptrrefoperator-operator"></a>Operador ComPtrRef::operator!=

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
bool operator!=(
   const Details::ComPtrRef<ComPtr<T>>& a,
   const Details::ComPtrRef<ComPtr<U>>& b
);

bool operator!=(
   const Details::ComPtrRef<ComPtr<T>>& a,
   decltype(__nullptr)  
);

bool operator!=(
   decltype(__nullptr),
   const Details::ComPtrRef<ComPtr<T>>& a
);

bool operator!=(
   const Details::ComPtrRef<ComPtr<T>>& a,
   void* b
);

bool operator!=(
   void* b,
   const Details::ComPtrRef<ComPtr<T>>& a
);
```

### <a name="parameters"></a>Parâmetros

*a*<br/>
Uma referência a um **ComPtrRef** objeto.

*b*<br/>
Uma referência a outro **ComPtrRef** objeto ou um ponteiro para um objeto anônimo (`void*`).

## <a name="return-value"></a>Valor de retorno

A primeira produz do operador **verdadeira** se objeto *um* não é igual ao objeto *b*; caso contrário, **false**.

Os operadores de segundo e terceiro yield **verdadeira** se objeto *um* não é igual a **nullptr**; caso contrário, **false**.

Os operadores de quarto e quintas yield **verdadeira** se objeto *um* não é igual ao objeto *b*; caso contrário, **false**.

## <a name="remarks"></a>Comentários

Indica se dois **ComPtrRef** objetos não forem iguais.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)<br/>
[Classe ComPtrRef](../windows/comptrref-class.md)