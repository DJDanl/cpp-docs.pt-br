---
title: Estrutura InterfaceTraits
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::InterfaceTraits
- implements/Microsoft::WRL::Details::InterfaceTraits::CanCastTo
- implements/Microsoft::WRL::Details::InterfaceTraits::CastToBase
- implements/Microsoft::WRL::Details::InterfaceTraits::CastToUnknown
- implements/Microsoft::WRL::Details::InterfaceTraits::FillArrayWithIid
- implements/Microsoft::WRL::Details::InterfaceTraits::IidCount
- implements/Microsoft::WRL::Details::InterfaceTraits::Verify
helpviewer_keywords:
- Microsoft::WRL::Details::InterfaceTraits structure
- Microsoft::WRL::Details::InterfaceTraits::CanCastTo method
- Microsoft::WRL::Details::InterfaceTraits::CastToBase method
- Microsoft::WRL::Details::InterfaceTraits::CastToUnknown method
- Microsoft::WRL::Details::InterfaceTraits::FillArrayWithIid method
- Microsoft::WRL::Details::InterfaceTraits::IidCount constant
- Microsoft::WRL::Details::InterfaceTraits::Verify method
ms.assetid: ede0c284-19a7-4892-9738-ff3da4923d0a
ms.openlocfilehash: c08c6e8bbcc16120dd44da69a2933fc3ec42f387
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216564"
---
# <a name="interfacetraits-structure"></a>Estrutura InterfaceTraits

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename I0>
struct __declspec(novtable) InterfaceTraits;

template<typename CloakedType>
struct __declspec(novtable) InterfaceTraits<
    CloakedIid<CloakedType>
>;

template<>
struct __declspec(novtable) InterfaceTraits<Nil>;
```

### <a name="parameters"></a>parâmetros

*I0*<br/>
O nome de uma interface.

*CloakedType*<br/>
Para `RuntimeClass` , `Implements` e `ChainInterfaces` , uma interface que não estará na lista de IDs de interface com suporte.

## <a name="remarks"></a>Comentários

Implementa características comuns de uma interface.

O segundo modelo é uma especialização para interfaces encobertas. O terceiro modelo é uma especialização para parâmetros nil.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a><a name="public-typedefs"></a>TYPEDEFs públicos

Nome   | Descrição
------ | ------------------------------------------
`Base` | Um sinônimo para o parâmetro de modelo *i0* .

### <a name="public-methods"></a>Métodos públicos

Nome                                                   | Descrição
------------------------------------------------------ | ----------------------------------------------------------------------------------------
[InterfaceTraits:: cancastto](#cancastto)               | Indica se o ponteiro especificado pode ser convertido em um ponteiro para `Base` .
[InterfaceTraits::CastToBase](#casttobase)             | Converte o ponteiro especificado para um ponteiro para `Base` .
[InterfaceTraits::CastToUnknown](#casttounknown)       | Converte o ponteiro especificado para um ponteiro para `IUnknown` .
[InterfaceTraits::FillArrayWithIid](#fillarraywithiid) | Atribui a ID de interface do `Base` ao elemento de matriz especificado pelo argumento de índice.
[InterfaceTraits:: verificar](#verify)                     | Verifica se `Base` é derivado adequadamente.

### <a name="public-constants"></a>Constantes públicas

Nome                                   | Descrição
-------------------------------------- | ---------------------------------------------------------------------------------------
[InterfaceTraits::IidCount](#iidcount) | Mantém o número de IDs de interface associadas ao `InterfaceTraits` objeto atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`InterfaceTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="interfacetraitscancastto"></a><a name="cancastto"></a>InterfaceTraits:: cancastto

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
template<typename T>
static __forceinline bool CanCastTo(
   _In_ T* ptr,
   REFIID riid,
   _Deref_out_ void **ppv
);
```

### <a name="parameters"></a>parâmetros

*ptr*<br/>
O nome de um ponteiro para um tipo.

*riid*<br/>
A ID da interface de `Base` .

*ppv*<br/>
Se essa operação for bem-sucedida, *PPV* apontará para a interface especificada por `Base` . Caso contrário, *PPV* será definido como **`nullptr`** .

### <a name="return-value"></a>Valor retornado

**`true`** Se essa operação for bem-sucedida e a *PTR* for convertida para um ponteiro para `Base` ; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Indica se o ponteiro especificado pode ser convertido em um ponteiro para `Base` .

Para obter mais informações sobre `Base` o, consulte a seção [TYPEDEFs públicos](#public-typedefs) .

## <a name="interfacetraitscasttobase"></a><a name="casttobase"></a>InterfaceTraits::CastToBase

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
template<typename T>
static __forceinline Base* CastToBase(
   _In_ T* ptr
);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de parâmetro *PTR*.

*ptr*<br/>
Ponteiro para um tipo *T*.

### <a name="return-value"></a>Valor retornado

Um ponteiro para `Base`.

### <a name="remarks"></a>Comentários

Converte o ponteiro especificado para um ponteiro para `Base` .

Para obter mais informações sobre `Base` o, consulte a seção [TYPEDEFs públicos](#public-typedefs) .

## <a name="interfacetraitscasttounknown"></a><a name="casttounknown"></a>InterfaceTraits::CastToUnknown

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
template<typename T>
static __forceinline IUnknown* CastToUnknown(
   _In_ T* ptr
);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de parâmetro *PTR*.

*ptr*<br/>
Ponteiro para tipo *T*.

### <a name="return-value"></a>Valor retornado

Ponteiro para o IUnknown do qual `Base` é derivado.

### <a name="remarks"></a>Comentários

Converte o ponteiro especificado para um ponteiro para `IUnknown` .

Para obter mais informações sobre `Base` o, consulte a seção [TYPEDEFs públicos](#public-typedefs) .

## <a name="interfacetraitsfillarraywithiid"></a><a name="fillarraywithiid"></a>InterfaceTraits::FillArrayWithIid

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
__forceinline static void FillArrayWithIid(
   _Inout_ unsigned long &index,
   _In_ IID* iids
);
```

### <a name="parameters"></a>parâmetros

*index*<br/>
Ponteiro para um campo que contém um valor de índice baseado em zero.

*IIDs*<br/>
Uma matriz de IDs de interface.

### <a name="remarks"></a>Comentários

Atribui a ID de interface do `Base` ao elemento de matriz especificado pelo argumento de índice.

Ao contrário do nome dessa API, apenas um elemento da matriz é modificado; Não é a matriz inteira.

Para obter mais informações sobre `Base` o, consulte a seção [TYPEDEFs públicos](#public-typedefs) .

## <a name="interfacetraitsiidcount"></a><a name="iidcount"></a>InterfaceTraits::IidCount

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
static const unsigned long IidCount = 1;
```

### <a name="remarks"></a>Comentários

Mantém o número de IDs de interface associadas ao `InterfaceTraits` objeto atual.

## <a name="interfacetraitsverify"></a><a name="verify"></a>InterfaceTraits:: verificar

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
__forceinline static void Verify();
```

### <a name="remarks"></a>Comentários

Verifica se `Base` é derivado adequadamente.

Para obter mais informações sobre `Base` o, consulte a seção [TYPEDEFs públicos](#public-typedefs) .
