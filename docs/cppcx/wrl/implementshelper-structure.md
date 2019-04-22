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
ms.openlocfilehash: 250a59152e9b41eb48c453caaa696fdc8ca3d3b4
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58783945"
---
# <a name="implementshelper-structure"></a>Estrutura ImplementsHelper

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename RuntimeClassFlagsT, typename ILst, bool IsDelegateToClass>
friend struct Details::ImplementsHelper;
```

### <a name="parameters"></a>Parâmetros

*RuntimeClassFlagsT*<br/>
Um campo de sinalizadores que especifica um ou mais [RuntimeClassType](runtimeclasstype-enumeration.md) enumeradores.

*ILst*<br/>
Uma lista de IDs de interface.

*IsDelegateToClass*<br/>
Especificar **verdadeira** se a instância atual do `Implements` é uma classe base da primeira ID de interface no *ILst*; caso contrário, **false**.

## <a name="remarks"></a>Comentários

Ajuda a implementar o [implementa](implements-structure.md) estrutura.

Esse modelo percorre uma lista de interfaces e os adiciona como classes base e como as informações necessárias para habilitar `QueryInterface`.

## <a name="members"></a>Membros

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                                    | Descrição
------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------
[ImplementsHelper::CanCastTo](#cancastto)               | Obtém um ponteiro para a ID de interface especificado.
[ImplementsHelper::CastToUnknown](#casttounknown)       | Obtém um ponteiro para subjacente `IUnknown` interface atual `Implements` estrutura.
[ImplementsHelper::FillArrayWithIid](#fillarraywithiid) | Insere a ID de interface especificada pelo parâmetro de modelo inicial atual para o elemento da matriz especificada.
[ImplementsHelper::IidCount](#iidcount)                 | Contém o número de IDs de interface implementada no atual `Implements` objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ImplementsHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="cancastto"></a>ImplementsHelper::CanCastTo

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

*iid*<br/>
Referência a uma ID de interface.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Obtém um ponteiro para a ID de interface especificado.

## <a name="casttounknown"></a>ImplementsHelper::CastToUnknown

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
IUnknown* CastToUnknown();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro subjacente `IUnknown` interface.

### <a name="remarks"></a>Comentários

Obtém um ponteiro para subjacente `IUnknown` interface atual `Implements` estrutura.

## <a name="fillarraywithiid"></a>ImplementsHelper::FillArrayWithIid

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
void FillArrayWithIid(
   _Inout_ unsigned long *index,
   _Inout_ IID* iids) throw();
```

### <a name="parameters"></a>Parâmetros

*index*<br/>
Um índice baseado em zero que indica o elemento de matriz inicial para esta operação. Quando essa operação for concluída, *índice* é incrementado em 1.

*iids*<br/>
Uma matriz do tipo IIDs.

### <a name="remarks"></a>Comentários

Insere a ID de interface especificada pelo parâmetro de modelo inicial atual para o elemento da matriz especificada.

## <a name="iidcount"></a>ImplementsHelper::IidCount

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
static const unsigned long IidCount;
```

### <a name="remarks"></a>Comentários

Contém o número de IDs de interface implementada no atual `Implements` objeto.
