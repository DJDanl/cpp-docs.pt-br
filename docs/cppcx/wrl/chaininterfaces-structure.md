---
title: Estrutura ChainInterfaces
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::ChainInterfaces
- implements/Microsoft::WRL::ChainInterfaces::CanCastTo
- implements/Microsoft::WRL::ChainInterfaces::CastToUnknown
- implements/Microsoft::WRL::ChainInterfaces::FillArrayWithIid
- implements/Microsoft::WRL::ChainInterfaces::IidCount
- implements/Microsoft::WRL::ChainInterfaces::Verify
helpviewer_keywords:
- Microsoft::WRL::ChainInterfaces structure
- Microsoft::WRL::ChainInterfaces::CanCastTo method
- Microsoft::WRL::ChainInterfaces::CastToUnknown method
- Microsoft::WRL::ChainInterfaces::FillArrayWithIid method
- Microsoft::WRL::ChainInterfaces::IidCount constant
- Microsoft::WRL::ChainInterfaces::Verify method
ms.assetid: d7415b59-5468-4bef-a3fd-8d82b12f0e9c
ms.openlocfilehash: dd1af3fb5c1079a40d8248dc71ae4972537aa856
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372660"
---
# <a name="chaininterfaces-structure"></a>Estrutura ChainInterfaces

Especifica funções de verificação e inicialização que podem ser aplicadas a um conjunto de IDs de interface.

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
struct ChainInterfaces<
    MixIn<
        DerivedType,
        BaseType,
        hasImplements
    >, I1, I2, I3, I4, I5, I6, I7, I8, I9
>;
```

### <a name="parameters"></a>Parâmetros

*I0*<br/>
(Obrigatório) Interface ID 0.

*I1*<br/>
(Obrigatório) ID de interface 1.

*I2*<br/>
(Opcional) Interface ID 2.

*I3*<br/>
(Opcional) Interface ID 3.

*I4*<br/>
(Opcional) Interface ID 4.

*I5*<br/>
(Opcional) Interface ID 5.

*I6*<br/>
(Opcional) Interface ID 6.

*I7*<br/>
(Opcional) Interface ID 7.

*I8*<br/>
(Opcional) Interface ID 8.

*I9*<br/>
(Opcional) Interface ID 9.

*Derivedtype*<br/>
Um tipo derivado.

*BaseType*<br/>
O tipo base de um tipo derivado.

*hasImplements*<br/>
Um valor booleano que, se **verdadeiro,** significa que você não pode usar uma estrutura [MixIn](mixin-structure.md) com uma classe que não deriva da estutura [Implements.](implements-structure.md)

## <a name="members"></a>Membros

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                                   | Descrição
------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[Interfaces de cadeia::CanCastTo](#cancastto)               | Indica se o ID de interface especificado pode ser lançado `ChainInterface` para cada uma das especializações definidas pelos parâmetros do modelo.
[Interfaces de cadeia::CastToUnknown](#casttounknown)       | Lança o ponteiro de interface do tipo definido pelo parâmetro `IUnknown`de modelo *I0* para um ponteiro para .
[Interfaces de cadeia::FillArrayWithIid](#fillarraywithiid) | Armazena o ID de interface definido pelo parâmetro de modelo *I0* em um local especificado em um conjunto especificado de IDs de interface.
[Interfaces de cadeia::Verificar](#verify)                     | Verifica se cada interface definida pelos parâmetros de modelo *I0* a *I9* herda `IUnknown` de e/ou `IInspectable`, e que *I0* herda de *I1* a *I9*.

### <a name="protected-constants"></a>Constantes protegidas

Nome                                   | Descrição
-------------------------------------- | -----------------------------------------------------------------------------------------------------------------
[Interfaces de cadeia::IidCount](#iidcount) | O número total de IDs de interface contidos nas interfaces especificadas pelos parâmetros de modelo *I0* a *I9*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`I0`

`ChainInterfaces`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Espaço de nome:** Microsoft::WRL

## <a name="chaininterfacescancastto"></a><a name="cancastto"></a>Interfaces de cadeia::CanCastTo

Indica se o ID de interface especificado pode ser lançado para cada uma das especializações definidas pelos parâmetros de modelo não padrão.

```cpp
__forceinline bool CanCastTo(
   REFIID riid,
   _Deref_out_ void **ppv
);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Um ID de interface.

*Ppv*<br/>
Um ponteiro para o último ID de interface que foi lançado com sucesso.

### <a name="return-value"></a>Valor retornado

**verdade** se todas as operações de elenco conseguiram; caso contrário, **falso**.

## <a name="chaininterfacescasttounknown"></a><a name="casttounknown"></a>Interfaces de cadeia::CastToUnknown

Lança o ponteiro de interface do tipo definido pelo parâmetro `IUnknown`de modelo *I0* para um ponteiro para .

```cpp
__forceinline IUnknown* CastToUnknown();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para `IUnknown`.

## <a name="chaininterfacesfillarraywithiid"></a><a name="fillarraywithiid"></a>Interfaces de cadeia::FillArrayWithIid

Armazena o ID de interface definido pelo parâmetro de modelo *I0* em um local especificado em um conjunto especificado de IDs de interface.

```cpp
__forceinline static void FillArrayWithIid(
   _Inout_ unsigned long &index,
   _In_ IID* iids
);
```

### <a name="parameters"></a>Parâmetros

*Índice*<br/>
Ponteiro para um valor de índice na matriz *iids.*

*Iids*<br/>
Uma matriz de IDs de interface.

## <a name="chaininterfacesiidcount"></a><a name="iidcount"></a>Interfaces de cadeia::IidCount

O número total de IDs de interface contidos nas interfaces especificadas pelos parâmetros de modelo *I0* a *I9*.

```cpp
static const unsigned long IidCount = Details::InterfaceTraits<I0>::IidCount + Details::InterfaceTraits<I1>::IidCount + Details::InterfaceTraits<I2>::IidCount + Details::InterfaceTraits<I3>::IidCount + Details::InterfaceTraits<I4>::IidCount + Details::InterfaceTraits<I5>::IidCount + Details::InterfaceTraits<I6>::IidCount + Details::InterfaceTraits<I7>::IidCount + Details::InterfaceTraits<I8>::IidCount + Details::InterfaceTraits<I9>::IidCount;
```

### <a name="return-value"></a>Valor retornado

O número total de IDs de interface.

### <a name="remarks"></a>Comentários

Os parâmetros de modelo *I0* e *I1* são necessários, e os parâmetros *I2* a *I9* são opcionais. A contagem de IDdes de cada interface é tipicamente 1.

## <a name="chaininterfacesverify"></a><a name="verify"></a>Interfaces de cadeia::Verificar

Verifica se cada interface definida pelos parâmetros de modelo *I0* a *I9* herda `IUnknown` de e/ou `IInspectable`, e que *I0* herda de *I1* a *I9*.

```cpp
WRL_NOTHROW __forceinline static void Verify();
```

### <a name="remarks"></a>Comentários

Se a operação de `static_assert` verificação falhar, uma mensagem de erro descreve a falha.

Os parâmetros de modelo *I0* e *I1* são necessários, e os parâmetros *I2* a *I9* são opcionais.
