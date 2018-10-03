---
title: Estrutura ChainInterfaces | Microsoft Docs
ms.custom: ''
ms.date: 09/28/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::ChainInterfaces
- implements/Microsoft::WRL::ChainInterfaces::CanCastTo
- implements/Microsoft::WRL::ChainInterfaces::CastToUnknown
- implements/Microsoft::WRL::ChainInterfaces::FillArrayWithIid
- implements/Microsoft::WRL::ChainInterfaces::IidCount
- implements/Microsoft::WRL::ChainInterfaces::Verify
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::ChainInterfaces structure
- Microsoft::WRL::ChainInterfaces::CanCastTo method
- Microsoft::WRL::ChainInterfaces::CastToUnknown method
- Microsoft::WRL::ChainInterfaces::FillArrayWithIid method
- Microsoft::WRL::ChainInterfaces::IidCount constant
- Microsoft::WRL::ChainInterfaces::Verify method
ms.assetid: d7415b59-5468-4bef-a3fd-8d82b12f0e9c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a80b9afd8f2db895440d12776173c559e41c2cfe
ms.sourcegitcommit: 1d9bd38cacbc783fccd3884b7b92062161c91c84
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48234860"
---
# <a name="chaininterfaces-structure"></a>Estrutura ChainInterfaces

Especifica as funções de verificação e de inicialização que podem ser aplicadas a um conjunto de IDs de interface.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   typename I0,
   typename I1,
   typename I2 = Details::Nil,
   typename I3 = Details::Nil,
   typename I4 = Details::Nil,
   typename I5 = Details::Nil,
   typename I6 = Details::Nil,
   typename I7 = Details::Nil,
   typename I8 = Details::Nil,
   typename I9 = Details::Nil
>
struct ChainInterfaces : I0;
template <
   typename DerivedType,
   typename BaseType,
   bool hasImplements,
   typename I1,
   typename I2,
   typename I3,
   typename I4,
   typename I5,
   typename I6,
   typename I7,
   typename I8,
   typename I9
>
struct ChainInterfaces<MixIn<DerivedType, BaseType, hasImplements>, I1, I2, I3, I4, I5, I6, I7, I8, I9>;
```

### <a name="parameters"></a>Parâmetros

*I0*<br/>
(Obrigatório) Interface ID 0.

*I1*<br/>
(Obrigatório) Interface ID 1.

*I2*<br/>
(Opcional) ID da interface 2.

*I3*<br/>
(Opcional) ID da interface 3.

*I4*<br/>
(Opcional) ID da interface 4.

*I5*<br/>
(Opcional) ID da interface 5.

*I6*<br/>
(Opcional) ID de interface 6.

*I7*<br/>
(Opcional) ID de interface 7.

*I8*<br/>
(Opcional) ID de interface 8.

*I9*<br/>
(Opcional) ID de interface 9.

*DerivedType*<br/>
Um tipo derivado.

*BaseType*<br/>
O tipo base de um tipo derivado.

*hasImplements*<br/>
Um valor booliano que, se `true`, significa que você não pode usar um [mescla](../windows/mixin-structure.md) estrutura com uma classe que deriva de [implementa](../windows/implements-structure.md) estrutura.

## <a name="members"></a>Membros

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                                   | Descrição
------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[Chaininterfaces:: Cancastto](#cancastto)               | Indica se a ID de interface especificado pode ser convertida em cada um dos especializações definidas pelo `ChainInterface` parâmetros de modelo.
[Chaininterfaces:: Casttounknown](#casttounknown)       | Converte o ponteiro de interface do tipo definido pelos *I0* parâmetro de modelo para um ponteiro para `IUnknown`.
[Chaininterfaces:: Fillarraywithiid](#fillarraywithiid) | Armazena a ID de interface definida pelo *I0* parâmetro de modelo em um local especificado em uma matriz especificada de IDs de interface.
[Chaininterfaces:: Verify](#verify)                     | Verifica se cada interface definido pelos parâmetros de modelo *I0* por meio *I9* herda `IUnknown` e/ou `IInspectable`e que *I0* herda de *I1* por meio *I9*.

### <a name="protected-constants"></a>Constantes protegidos

Nome                                   | Descrição
-------------------------------------- | -----------------------------------------------------------------------------------------------------------------
[Chaininterfaces:: Iidcount](#iidcount) | O número total de IDs contidas nas interfaces especificadas pelos parâmetros de modelo de interface *I0* por meio *I9*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`I0`

`ChainInterfaces`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="cancastto"></a>Chaininterfaces:: Cancastto

Indica se a ID de interface especificado pode ser convertida em cada um dos especializações definidas pelos parâmetros de modelo não padrão.

```cpp
__forceinline bool CanCastTo(
   REFIID riid,
   _Deref_out_ void **ppv
);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Uma ID de interface.

*ppv*<br/>
Um ponteiro para a última ID de interface que foi convertido com êxito.

### <a name="return-value"></a>Valor de retorno

`true` Se todas as operações de conversão for bem-sucedida; Caso contrário, `false`.

## <a name="casttounknown"></a>Chaininterfaces:: Casttounknown

Converte o ponteiro de interface do tipo definido pelos *I0* parâmetro de modelo para um ponteiro para `IUnknown`.

```cpp
__forceinline IUnknown* CastToUnknown();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para `IUnknown`.

## <a name="fillarraywithiid"></a>Chaininterfaces:: Fillarraywithiid

Armazena a ID de interface definida pelo *I0* parâmetro de modelo em um local especificado em uma matriz especificada de IDs de interface.

```cpp
__forceinline static void FillArrayWithIid(
   _Inout_ unsigned long &index,
   _In_ IID* iids
);
```

### <a name="parameters"></a>Parâmetros

*index*<br/>
Ponteiro para um valor de índice para o *iids* matriz.

*IIDs*<br/>
Uma matriz de IDs de interface.

## <a name="iidcount"></a>Chaininterfaces:: Iidcount

O número total de IDs contidas nas interfaces especificadas pelos parâmetros de modelo de interface *I0* por meio *I9*.

```cpp
static const unsigned long IidCount = Details::InterfaceTraits<I0>::IidCount + Details::InterfaceTraits<I1>::IidCount + Details::InterfaceTraits<I2>::IidCount + Details::InterfaceTraits<I3>::IidCount + Details::InterfaceTraits<I4>::IidCount + Details::InterfaceTraits<I5>::IidCount + Details::InterfaceTraits<I6>::IidCount + Details::InterfaceTraits<I7>::IidCount + Details::InterfaceTraits<I8>::IidCount + Details::InterfaceTraits<I9>::IidCount;
```

### <a name="return-value"></a>Valor de retorno

O número total de identificadores de interface.

### <a name="remarks"></a>Comentários

Parâmetros de modelo *I0* e *I1* são necessários e os parâmetros *I2* por meio de *I9* são opcionais. A contagem IID de cada interface normalmente é 1.

## <a name="verify"></a>Chaininterfaces:: Verify

Verifica se cada interface definido pelos parâmetros de modelo *I0* por meio *I9* herda `IUnknown` e/ou `IInspectable`e que *I0* herda de *I1* por meio *I9*.

```cpp
WRL_NOTHROW __forceinline static void Verify();
```

### <a name="remarks"></a>Comentários

Se a operação de verificação falhar, um `static_assert` emite uma mensagem de erro que descreve a falha.

Parâmetros de modelo *I0* e *I1* são necessários e os parâmetros *I2* por meio de *I9* são opcionais.
