---
title: Estrutura ImplementsHelper | Microsoft Docs
ms.custom: ''
ms.date: 09/21/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::ImplementsHelper
- implements/Microsoft::WRL::Details::ImplementsHelper::CanCastTo
- implements/Microsoft::WRL::Details::ImplementsHelper::CastToUnknown
- implements/Microsoft::WRL::Details::ImplementsHelper::FillArrayWithIid
- implements/Microsoft::WRL::Details::ImplementsHelper::IidCount
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Details::ImplementsHelper structure
- Microsoft::WRL::Details::ImplementsHelper::CanCastTo method
- Microsoft::WRL::Details::ImplementsHelper::CastToUnknown method
- Microsoft::WRL::Details::ImplementsHelper::FillArrayWithIid method
- Microsoft::WRL::Details::ImplementsHelper::IidCount constant
ms.assetid: b857ba80-81bd-4e53-92b6-210991954243
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9436185ca6abc19f89e007ed20091e9c7be168a3
ms.sourcegitcommit: 1d9bd38cacbc783fccd3884b7b92062161c91c84
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48235042"
---
# <a name="implementshelper-structure"></a>Estrutura ImplementsHelper

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   typename RuntimeClassFlagsT,
   typename ILst,
   bool IsDelegateToClass
>
friend struct Details::ImplementsHelper;
```

### <a name="parameters"></a>Parâmetros

*RuntimeClassFlagsT*<br/>
Um campo de sinalizadores que especifica um ou mais [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) enumeradores.

*ILst*<br/>
Uma lista de IDs de interface.

*IsDelegateToClass*<br/>
Especificar `true` se a instância atual do `Implements` é uma classe base da primeira identificação de interface em *ILst*; caso contrário, `false`.

## <a name="remarks"></a>Comentários

Ajuda a implementar o [implementa](../windows/implements-structure.md) estrutura.

Esse modelo percorre uma lista de interfaces e os adiciona como classes base e como as informações necessárias para habilitar `QueryInterface`.

## <a name="members"></a>Membros

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                                    | Descrição
------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------
[Implementshelper:: Cancastto](#cancastto)               | Obtém um ponteiro para a ID de interface especificado.
[Implementshelper:: Casttounknown](#casttounknown)       | Obtém um ponteiro para subjacente `IUnknown` interface atual `Implements` estrutura.
[Implementshelper:: Fillarraywithiid](#fillarraywithiid) | Insere a ID de interface especificada pelo parâmetro de modelo inicial atual para o elemento da matriz especificada.
[Implementshelper:: Iidcount](#iidcount)                 | Contém o número de IDs de interface implementada no atual `Implements` objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ImplementsHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="cancastto"></a>Implementshelper:: Cancastto

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
HRESULT CanCastTo(
   REFIID riid,
   _Deref_out_ void **ppv
);

HRESULT CanCastTo(
   _In_ const IID &iid,
   _Deref_out_ void **ppv
);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Referência a uma ID de interface.

*ppv*<br/>
Se essa operação for bem-sucedida, um ponteiro para a interface especificada por *riid* ou *iid*.

*IID*<br/>
Referência a uma ID de interface.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Obtém um ponteiro para a ID de interface especificado.

## <a name="casttounknown"></a>Implementshelper:: Casttounknown

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
IUnknown* CastToUnknown();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro subjacente `IUnknown` interface.

### <a name="remarks"></a>Comentários

Obtém um ponteiro para subjacente `IUnknown` interface atual `Implements` estrutura.

## <a name="fillarraywithiid"></a>Implementshelper:: Fillarraywithiid

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
void FillArrayWithIid(
   _Inout_ unsigned long *index,
   _Inout_ IID* iids) throw();
```

### <a name="parameters"></a>Parâmetros

*index*<br/>
Um índice baseado em zero que indica o elemento de matriz inicial para esta operação. Quando essa operação for concluída, *índice* é incrementado em 1.

*IIDs*<br/>
Uma matriz do tipo IIDs.

### <a name="remarks"></a>Comentários

Insere a ID de interface especificada pelo parâmetro de modelo inicial atual para o elemento da matriz especificada.

## <a name="iidcount"></a>Implementshelper:: Iidcount

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
static const unsigned long IidCount;
```

### <a name="remarks"></a>Comentários

Contém o número de IDs de interface implementada no atual `Implements` objeto.
