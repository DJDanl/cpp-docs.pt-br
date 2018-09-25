---
title: Estrutura RuntimeClassBaseT | Microsoft Docs
ms.custom: ''
ms.date: 09/24/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::RuntimeClassBaseT
- implements/Microsoft::WRL::Details::RuntimeClassBaseT::AsIID
- implements/Microsoft::WRL::Details::RuntimeClassBaseT::GetImplementedIIDS
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Details::RuntimeClassBaseT structure
- Microsoft::WRL::Details::RuntimeClassBaseT::AsIID method
- Microsoft::WRL::Details::RuntimeClassBaseT::GetImplementedIIDS method
ms.assetid: a62775fb-3359-4f45-9ff1-c07fa8da464b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c9e7f5b38d3434e8753646db4733218978e7e766
ms.sourcegitcommit: edb46b0239a0e616af4ec58906e12338c3e8d2c6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2018
ms.locfileid: "47169704"
---
# <a name="runtimeclassbaset-structure"></a>Estrutura RuntimeClassBaseT

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   unsigned int RuntimeClassTypeT
>
friend struct Details::RuntimeClassBaseT;
```

### <a name="parameters"></a>Parâmetros

*RuntimeClassTypeT*<br/>
Um campo de sinalizadores que especifica um ou mais [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) enumeradores.

## <a name="remarks"></a>Comentários

Fornece métodos auxiliares para `QueryInterface` operações e ao obter IDs de interface.

## <a name="members"></a>Membros

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                                         | Descrição
------------------------------------------------------------ | -----------------------------------------------------------------------------
[Runtimeclassbaset:: Asiid](#asiid)                           | Recupera um ponteiro para a ID de interface especificado.
[Runtimeclassbaset:: Getimplementediids](#getimplementediids) | Recupera uma matriz de IDs que são implementadas por um tipo especificado de interface.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`RuntimeClassBaseT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="asiid"></a>Runtimeclassbaset:: Asiid

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
template<typename T>
__forceinline static HRESULT AsIID(
   _In_ T* implements,
   REFIID riid,
   _Deref_out_ void **ppvObject
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Um tipo que implementa a interface ID especificado pelo parâmetro *riid*.

*Implementa*<br/>
Uma variável do tipo especificado pelo parâmetro de modelo *T*.

*riid*<br/>
A ID de interface para recuperar.

*ppvObject*<br/>
Se essa operação for bem-sucedida, um ponteiro-para-um-ponteiro para a interface especificada pelo parâmetro *riid*.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve o erro.

### <a name="remarks"></a>Comentários

Recupera um ponteiro para a ID de interface especificado.

## <a name="getimplementediids"></a>Runtimeclassbaset:: Getimplementediids

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
template<typename T>
__forceinline static HRESULT GetImplementedIIDS(
   _In_ T* implements,
   _Out_ ULONG *iidCount,
   _Deref_out_ _Deref_post_cap_(*iidCount) IID **iids
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo dos *implementa* parâmetro.

*Implementa*<br/>
Ponteiro para o tipo especificado pelo parâmetro *T*.

*iidCount*<br/>
O número máximo de IDs de interface para recuperar.

*IIDs*<br/>
Se essa operação for concluída com êxito, uma matriz de IDs implementadas pelo tipo de interface *T*.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve o erro.

### <a name="remarks"></a>Comentários

Recupera uma matriz de IDs que são implementadas por um tipo especificado de interface.
