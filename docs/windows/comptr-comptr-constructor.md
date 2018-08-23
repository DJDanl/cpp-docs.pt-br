---
title: 'Construtor comptr:: Comptr | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr::ComPtr
dev_langs:
- C++
helpviewer_keywords:
- ComPtr, constructor
ms.assetid: eaf70907-beac-458f-a503-2e5e27b0c196
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ae03de851d7cf24d7322ff6f9e1f8610a584b376
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42606210"
---
# <a name="comptrcomptr-constructor"></a>Construtor ComPtr::ComPtr

Inicializa uma nova instância dos **ComPtr** classe. Sobrecargas fornecem construtores padrão, copiar, mover e conversão.

## <a name="syntax"></a>Sintaxe

```cpp
WRL_NOTHROW ComPtr();
WRL_NOTHROW ComPtr(
   decltype(__nullptr)  
);
template<class U>
WRL_NOTHROW ComPtr(
   _In_opt_ U *other
);
WRL_NOTHROW ComPtr(
   const ComPtr& other
);
template<class U>
WRL_NOTHROW ComPtr(
   const ComPtr<U> &other,
   typename ENABLE_IF<__is_convertible_to(U*,
   T*),
   void *>;
WRL_NOTHROW ComPtr(
   _Inout_ ComPtr &&other
);
template<class U>
WRL_NOTHROW ComPtr(
   _Inout_ ComPtr<U>&& other,
   typename ENABLE_IF<__is_convertible_to(U*,
   T*),
   void *>;
```

### <a name="parameters"></a>Parâmetros

*U*  
O tipo dos *outros* parâmetro.

*other*  
Um objeto do tipo *U*.

## <a name="return-value"></a>Valor de retorno

## <a name="remarks"></a>Comentários

O primeiro construtor é o construtor padrão, quais implícita cria um objeto vazio. Especifica o segundo construtor [nullptr](../windows/nullptr-cpp-component-extensions.md), que cria explicitamente um objeto vazio.

O terceiro construtor cria um objeto do objeto especificado por um ponteiro.

Os construtores quarto e quintas são construtores de cópia. O quinto construtor copia um objeto se ele for conversível para o tipo atual.

Os sexto e sétimo construtores são construtores de movimentação. O sétimo construtor move um objeto se ele for conversível para o tipo atual.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe ComPtr](../windows/comptr-class.md)