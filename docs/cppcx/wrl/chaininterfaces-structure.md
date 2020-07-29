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
ms.openlocfilehash: 48b663f2042ff0095466d83fe872ef6196112f76
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211535"
---
# <a name="chaininterfaces-structure"></a>Estrutura ChainInterfaces

Especifica as funções de verificação e inicialização que podem ser aplicadas a um conjunto de IDs de interface.

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

### <a name="parameters"></a>parâmetros

*I0*<br/>
Necessária ID da interface 0.

*I1*<br/>
Necessária ID da interface 1.

*I2*<br/>
Adicional ID da interface 2.

*I3*<br/>
Adicional ID da interface 3.

*I4*<br/>
Adicional ID da interface 4.

*I5*<br/>
Adicional ID da interface 5.

*I6*<br/>
Adicional ID da interface 6.

*I7*<br/>
Adicional ID da interface 7.

*I8*<br/>
Adicional ID da interface 8.

*I9*<br/>
Adicional ID da interface 9.

*Derivadotype*<br/>
Um tipo derivado.

*BaseType*<br/>
O tipo base de um tipo derivado.

*hasImplements*<br/>
Um valor booliano que se **`true`** , se, significa que você não pode usar uma estrutura [mescla](mixin-structure.md) com uma classe que não derive de Stucture [implementa](implements-structure.md) .

## <a name="members"></a>Membros

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                                   | Descrição
------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[ChainInterfaces:: cancastto](#cancastto)               | Indica se a ID de interface especificada pode ser convertida em cada uma das especializações definidas pelos `ChainInterface` parâmetros do modelo.
[ChainInterfaces::CastToUnknown](#casttounknown)       | Converte o ponteiro de interface do tipo definido pelo parâmetro de modelo *i0* para um ponteiro para `IUnknown` .
[ChainInterfaces::FillArrayWithIid](#fillarraywithiid) | Armazena a ID de interface definida pelo parâmetro de modelo *i0* em um local especificado em uma matriz especificada de IDs de interface.
[ChainInterfaces:: verificar](#verify)                     | Verifica se cada interface definida pelos parâmetros de modelo *i0* por meio de *i9* herda de `IUnknown` e/ou e `IInspectable` se *i0* herda de *i1* até *i9*.

### <a name="protected-constants"></a>Constantes protegidas

Nome                                   | Descrição
-------------------------------------- | -----------------------------------------------------------------------------------------------------------------
[ChainInterfaces::IidCount](#iidcount) | O número total de IDs de interface contidas em interfaces especificadas por parâmetros de modelo *i0* por meio de *i9*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`I0`

`ChainInterfaces`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL

## <a name="chaininterfacescancastto"></a><a name="cancastto"></a>ChainInterfaces:: cancastto

Indica se a ID de interface especificada pode ser convertida em cada uma das especializações definidas pelos parâmetros de modelo não padrão.

```cpp
__forceinline bool CanCastTo(
   REFIID riid,
   _Deref_out_ void **ppv
);
```

### <a name="parameters"></a>parâmetros

*riid*<br/>
Uma ID de interface.

*ppv*<br/>
Um ponteiro para a última ID de interface que foi convertida com êxito.

### <a name="return-value"></a>Valor retornado

**`true`** se todas as operações de conversão tiverem êxito; caso contrário, **`false`** .

## <a name="chaininterfacescasttounknown"></a><a name="casttounknown"></a>ChainInterfaces::CastToUnknown

Converte o ponteiro de interface do tipo definido pelo parâmetro de modelo *i0* para um ponteiro para `IUnknown` .

```cpp
__forceinline IUnknown* CastToUnknown();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para `IUnknown`.

## <a name="chaininterfacesfillarraywithiid"></a><a name="fillarraywithiid"></a>ChainInterfaces::FillArrayWithIid

Armazena a ID de interface definida pelo parâmetro de modelo *i0* em um local especificado em uma matriz especificada de IDs de interface.

```cpp
__forceinline static void FillArrayWithIid(
   _Inout_ unsigned long &index,
   _In_ IID* iids
);
```

### <a name="parameters"></a>parâmetros

*index*<br/>
Ponteiro para um valor de índice na matriz *IIDs* .

*IIDs*<br/>
Uma matriz de IDs de interface.

## <a name="chaininterfacesiidcount"></a><a name="iidcount"></a>ChainInterfaces::IidCount

O número total de IDs de interface contidas em interfaces especificadas por parâmetros de modelo *i0* por meio de *i9*.

```cpp
static const unsigned long IidCount = Details::InterfaceTraits<I0>::IidCount + Details::InterfaceTraits<I1>::IidCount + Details::InterfaceTraits<I2>::IidCount + Details::InterfaceTraits<I3>::IidCount + Details::InterfaceTraits<I4>::IidCount + Details::InterfaceTraits<I5>::IidCount + Details::InterfaceTraits<I6>::IidCount + Details::InterfaceTraits<I7>::IidCount + Details::InterfaceTraits<I8>::IidCount + Details::InterfaceTraits<I9>::IidCount;
```

### <a name="return-value"></a>Valor retornado

O número total de IDs de interface.

### <a name="remarks"></a>Comentários

Os parâmetros de modelo *i0* e *i1* são obrigatórios e os parâmetros *i2* por meio de *i9* são opcionais. A contagem de IID de cada interface normalmente é 1.

## <a name="chaininterfacesverify"></a><a name="verify"></a>ChainInterfaces:: verificar

Verifica se cada interface definida pelos parâmetros de modelo *i0* por meio de *i9* herda de `IUnknown` e/ou e `IInspectable` se *i0* herda de *i1* até *i9*.

```cpp
WRL_NOTHROW __forceinline static void Verify();
```

### <a name="remarks"></a>Comentários

Se a operação de verificação falhar, um **`static_assert`** emitirá uma mensagem de erro que descreve a falha.

Os parâmetros de modelo *i0* e *i1* são obrigatórios e os parâmetros *i2* por meio de *i9* são opcionais.
