---
title: Estrutura ImplementsHelper
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::ImplementsHelper
- implements/Microsoft::WRL::Details::ImplementsHelper::CanCastTo
- implements/Microsoft::WRL::Details::ImplementsHelper::CastToUnknown
- implements/Microsoft::WRL::Details::ImplementsHelper::FillArrayWithIid
- implements/Microsoft::WRL::Details::ImplementsHelper::IidCount
helpviewer_keywords:
- Microsoft::WRL::Details::ImplementsHelper structure
- Microsoft::WRL::Details::ImplementsHelper::CanCastTo method
- Microsoft::WRL::Details::ImplementsHelper::CastToUnknown method
- Microsoft::WRL::Details::ImplementsHelper::FillArrayWithIid method
- Microsoft::WRL::Details::ImplementsHelper::IidCount constant
ms.assetid: b857ba80-81bd-4e53-92b6-210991954243
ms.openlocfilehash: d7908670b67df7dbf7b2b74e98f8b59cf30f8e96
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87184937"
---
# <a name="implementshelper-structure"></a>Estrutura ImplementsHelper

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename RuntimeClassFlagsT, typename ILst, bool IsDelegateToClass>
friend struct Details::ImplementsHelper;
```

### <a name="parameters"></a>parâmetros

*RuntimeClassFlagsT*<br/>
Um campo de sinalizadores que especifica um ou mais enumeradores [RuntimeClassType](runtimeclasstype-enumeration.md) .

*ILst*<br/>
Uma lista de IDs de interface.

*IsDelegateToClass*<br/>
Especifique **`true`** se a instância atual do `Implements` é uma classe base da primeira ID de interface em *ILst*; caso contrário, **`false`** .

## <a name="remarks"></a>Comentários

Ajuda a implementar a estrutura de [implementações](implements-structure.md) .

Esse modelo percorre uma lista de interfaces e as adiciona como classes base e como as informações necessárias para habilitar o `QueryInterface` .

## <a name="members"></a>Membros

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                                    | Descrição
------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------
[ImplementsHelper:: cancastto](#cancastto)               | Obtém um ponteiro para a ID de interface especificada.
[ImplementsHelper::CastToUnknown](#casttounknown)       | Obtém um ponteiro para a interface subjacente da `IUnknown` estrutura atual `Implements` .
[ImplementsHelper::FillArrayWithIid](#fillarraywithiid) | Insere a ID de interface especificada pelo parâmetro de modelo inicial atual no elemento de matriz especificado.
[ImplementsHelper::IidCount](#iidcount)                 | Mantém o número de IDs de interface implementadas no `Implements` objeto atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ImplementsHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="implementshelpercancastto"></a><a name="cancastto"></a>ImplementsHelper:: cancastto

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

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

### <a name="parameters"></a>parâmetros

*riid*<br/>
Referência a uma ID de interface.

*ppv*<br/>
Se essa operação for bem-sucedida, um ponteiro para a interface especificada por *riid* ou *IID*.

*IID*<br/>
Referência a uma ID de interface.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Obtém um ponteiro para a ID de interface especificada.

## <a name="implementshelpercasttounknown"></a><a name="casttounknown"></a>ImplementsHelper::CastToUnknown

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
IUnknown* CastToUnknown();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para a `IUnknown` interface subjacente.

### <a name="remarks"></a>Comentários

Obtém um ponteiro para a interface subjacente da `IUnknown` estrutura atual `Implements` .

## <a name="implementshelperfillarraywithiid"></a><a name="fillarraywithiid"></a>ImplementsHelper::FillArrayWithIid

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
void FillArrayWithIid(
   _Inout_ unsigned long *index,
   _Inout_ IID* iids) throw();
```

### <a name="parameters"></a>parâmetros

*index*<br/>
Um índice de base zero que indica o elemento de matriz inicial para esta operação. Quando essa operação for concluída, o *índice* será incrementado em 1.

*IIDs*<br/>
Uma matriz do tipo IIDs.

### <a name="remarks"></a>Comentários

Insere a ID de interface especificada pelo parâmetro de modelo inicial atual no elemento de matriz especificado.

## <a name="implementshelperiidcount"></a><a name="iidcount"></a>ImplementsHelper::IidCount

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
static const unsigned long IidCount;
```

### <a name="remarks"></a>Comentários

Mantém o número de IDs de interface implementadas no `Implements` objeto atual.
