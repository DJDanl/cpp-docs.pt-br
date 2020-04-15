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
ms.openlocfilehash: e33842f574df5617fb40c5b3f6bb8324d5ba7c1e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371391"
---
# <a name="implementshelper-structure"></a>Estrutura ImplementsHelper

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename RuntimeClassFlagsT, typename ILst, bool IsDelegateToClass>
friend struct Details::ImplementsHelper;
```

### <a name="parameters"></a>Parâmetros

*RuntimeClassFlagsT*<br/>
Um campo de bandeiras que especifica um ou mais enumeradores [RuntimeClassType.](runtimeclasstype-enumeration.md)

*ILst*<br/>
Uma lista de IDs de interface.

*isdelegatetoclass*<br/>
Especifique **verdadeiro** `Implements` se a instância atual de é uma classe base do primeiro ID de interface no *ILst*; caso contrário, **falso**.

## <a name="remarks"></a>Comentários

Ajuda a implementar a estrutura [de Implementos.](implements-structure.md)

Este modelo atravessa uma lista de interfaces e as adiciona como `QueryInterface`classes base e como informações necessárias para habilitar .

## <a name="members"></a>Membros

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                                    | Descrição
------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------
[ImplementaHelper::CanCastTo](#cancastto)               | Obtém um ponteiro para o ID de interface especificado.
[ImplementaHelper::CastToUnknown](#casttounknown)       | Obtém um ponteiro `IUnknown` para a `Implements` interface subjacente para a estrutura atual.
[ImplementaHelper::FillArrayWithIid](#fillarraywithiid) | Insere o ID de interface especificado pelo parâmetro atual do modelo zeroth no elemento de matriz especificado.
[ImplementaHelper::IidCount](#iidcount)                 | Contém o número de IDs `Implements` de interface implementados no objeto atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ImplementsHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="implementshelpercancastto"></a><a name="cancastto"></a>ImplementaHelper::CanCastTo

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

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
Referência a um ID de interface.

*Ppv*<br/>
Se esta operação for bem sucedida, um ponteiro para a interface especificada por *riid* ou *iid*.

*Iid*<br/>
Referência a um ID de interface.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Obtém um ponteiro para o ID de interface especificado.

## <a name="implementshelpercasttounknown"></a><a name="casttounknown"></a>ImplementaHelper::CastToUnknown

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
IUnknown* CastToUnknown();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para a `IUnknown` interface subjacente.

### <a name="remarks"></a>Comentários

Obtém um ponteiro `IUnknown` para a `Implements` interface subjacente para a estrutura atual.

## <a name="implementshelperfillarraywithiid"></a><a name="fillarraywithiid"></a>ImplementaHelper::FillArrayWithIid

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
void FillArrayWithIid(
   _Inout_ unsigned long *index,
   _Inout_ IID* iids) throw();
```

### <a name="parameters"></a>Parâmetros

*Índice*<br/>
Um índice baseado em zero que indica o elemento de matriz inicial para esta operação. Quando esta operação é concluída, *o índice* é incrementado em 1.

*Iids*<br/>
Uma matriz de IIDs tipo.

### <a name="remarks"></a>Comentários

Insere o ID de interface especificado pelo parâmetro atual do modelo zeroth no elemento de matriz especificado.

## <a name="implementshelperiidcount"></a><a name="iidcount"></a>ImplementaHelper::IidCount

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
static const unsigned long IidCount;
```

### <a name="remarks"></a>Comentários

Contém o número de IDs `Implements` de interface implementados no objeto atual.
