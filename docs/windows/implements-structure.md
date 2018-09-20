---
title: Implementa estrutura | Microsoft Docs
ms.custom: ''
ms.date: 09/11/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Implements
- implements/Microsoft::WRL::Implements::CanCastTo
- implements/Microsoft::WRL::Implements::CastToUnknown
- implements/Microsoft::WRL::Implements::FillArrayWithIid
- implements/Microsoft::WRL::Implements::IidCount
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Implements structure
- Microsoft::WRL::Implements::CanCastTo method
- Microsoft::WRL::Implements::CastToUnknown method
- Microsoft::WRL::Implements::FillArrayWithIid method
- Microsoft::WRL::Implements::IidCount method
ms.assetid: 29b13e90-34d4-4a0b-babd-5187c9eb0c36
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 27a2cfaaf4ddb5ae58cdcd212b5fdcb7ded73bb0
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46434720"
---
# <a name="implements-structure"></a>Implementa estrutura

Implementa `QueryInterface` e `GetIid` para interfaces especificadas.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   typename I0,
   typename I1 = Details::Nil,
   typename I2 = Details::Nil,
   typename I3 = Details::Nil,
   typename I4 = Details::Nil,
   typename I5 = Details::Nil,
   typename I6 = Details::Nil,
   typename I7 = Details::Nil,
   typename I8 = Details::Nil,
   typename I9 = Details::Nil
>
struct __declspec(novtable) Implements : Details::ImplementsHelper<RuntimeClassFlags<WinRt>, typename Details::InterfaceListHelper<I0, I1, I2, I3, I4, I5, I6, I7, I8, I9>::TypeT>, Details::ImplementsBase;
template <
   int flags,
   typename I0,
   typename I1,
   typename I2,
   typename I3,
   typename I4,
   typename I5,
   typename I6,
   typename I7,
   typename I8
>
struct __declspec(novtable) Implements<RuntimeClassFlags<flags>, I0, I1, I2, I3, I4, I5, I6, I7, I8> : Details::ImplementsHelper<RuntimeClassFlags<flags>, typename Details::InterfaceListHelper<I0, I1, I2, I3, I4, I5, I6, I7, I8>::TypeT>, Details::ImplementsBase;
```

### <a name="parameters"></a>Parâmetros

*I0*<br/>
A ID de interface inicial. (Obrigatório)

*I1*<br/>
A primeira ID de interface. (Opcional)

*I2*<br/>
A segunda ID de interface. (Opcional)

*I3*<br/>
A terceira ID de interface. (Opcional)

*I4*<br/>
A quarta ID de interface. (Opcional)

*I5*<br/>
A quinta ID de interface. (Opcional)

*I6*<br/>
A sexta ID de interface. (Opcional)

*I7*<br/>
A sétima ID de interface. (Opcional)

*I8*<br/>
A ID de interface do oitavo. (Opcional)

*I9*<br/>
A nona ID de interface. (Opcional)

*flags*<br/>
Sinalizadores de configuração para a classe. Um ou mais [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) enumerações que são especificadas em uma [RuntimeClassFlags](../windows/runtimeclassflags-structure.md) estrutura.

## <a name="remarks"></a>Comentários

Deriva da lista de interfaces especificadas e implementa os modelos de auxiliar para `QueryInterface` e `GetIid`.

Cada *I0* por meio *I9* parâmetro interface deve derivar do `IUnknown`, `IInspectable`, ou o [ChainInterfaces](../windows/chaininterfaces-structure.md) modelo. O *sinalizadores* parâmetro determina se o suporte é gerado para `IUnknown` ou `IInspectable`.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

| Nome        | Descrição                               |
| ----------- | ----------------------------------------- |
| `ClassFlags`| Um sinônimo de `RuntimeClassFlags<WinRt>`. |

### <a name="protected-methods"></a>Métodos Protegidos

| Nome                                              | Descrição                                                                                                   |
| ------------------------------------------------- | ------------------------------------------------------------------------------------------------------------- |
| [Implements:: cancastto](#cancastto)               | Obtém um ponteiro para a interface especificada.                                                                    |
| [Implements:: casttounknown](#casttounknown)       | Obtém um ponteiro para subjacente `IUnknown` interface.                                                        |
| [Implements:: fillarraywithiid](#fillarraywithiid) | Insere a ID de interface especificada pelo parâmetro de modelo inicial atual para o elemento da matriz especificada. |

### <a name="protected-constants"></a>Constantes protegidos

| Nome                              | Descrição                                    |
| --------------------------------- | ---------------------------------------------- |
| [Implements:: iidcount](#iidcount) | Contém o número de IDs de interface implementada. |

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`I0`

`ChainInterfaces`

`I0`

`ImplementsBase`

`ImplementsHelper`

`Implements`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="cancastto"></a>Implements:: cancastto

Obtém um ponteiro para a interface especificada.

```cpp
__forceinline HRESULT CanCastTo(
   REFIID riid,
   _Deref_out_ void **ppv
);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Uma referência a uma ID de interface.

*ppv*<br/>
Se for bem-sucedido, um ponteiro para a interface especificada por *riid*.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro, como E_NOINTERFACE.

### <a name="remarks"></a>Comentários

Essa é uma função de auxiliar interno que executa uma operação de QueryInterface.

## <a name="casttounknown"></a>Implements:: casttounknown

Obtém um ponteiro para subjacente `IUnknown` interface.

```cpp
__forceinline IUnknown* CastToUnknown();
```

### <a name="return-value"></a>Valor de retorno

Essa operação for bem-sucedida e retornar sempre o `IUnknown` ponteiro.

### <a name="remarks"></a>Comentários

Função auxiliar interno.

## <a name="fillarraywithiid"></a>Implements:: fillarraywithiid

Insere a ID de interface especificada pelo parâmetro de modelo inicial atual para o elemento da matriz especificada.

```cpp
__forceinline static void FillArrayWithIid(
   unsigned long &index,
   _In_ IID* iids
);
```

### <a name="parameters"></a>Parâmetros

*index*<br/>
Um índice baseado em zero que indica o elemento de matriz inicial para esta operação. Quando essa operação for concluída, *índice* é incrementado em 1.

*IIDs*<br/>
Uma matriz do tipo IID.

### <a name="remarks"></a>Comentários

Função auxiliar interno.

## <a name="iidcount"></a>Implements:: iidcount

Contém o número de IDs de interface implementada.

```cpp
static const unsigned long IidCount;
```
