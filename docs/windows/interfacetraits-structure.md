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
ms.openlocfilehash: e8222ccaca9572331412b90e696829568eedcf8e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50543943"
---
# <a name="interfacetraits-structure"></a>Estrutura InterfaceTraits

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

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

### <a name="parameters"></a>Parâmetros

*I0*<br/>
O nome de uma interface.

*CloakedType*<br/>
Para `RuntimeClass`, `Implements` e `ChainInterfaces`, suporte de uma interface que não esteja na lista de IDs de interface.

## <a name="remarks"></a>Comentários

Características comuns de implementa uma interface.

O segundo modelo é uma especialização para interfaces encobertas. O terceiro modelo é uma especialização para parâmetros Nil.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome   | Descrição
------ | ------------------------------------------
`Base` | Um sinônimo para o *I0* parâmetro de modelo.

### <a name="public-methods"></a>Métodos públicos

Nome                                                   | Descrição
------------------------------------------------------ | ----------------------------------------------------------------------------------------
[Interfacetraits:: Cancastto](#cancastto)               | Indica se o ponteiro especificado pode ser convertido em um ponteiro para `Base`.
[Interfacetraits:: Casttobase](#casttobase)             | Converte o ponteiro especificado para um ponteiro para `Base`.
[Interfacetraits:: Casttounknown](#casttounknown)       | Converte o ponteiro especificado para um ponteiro para `IUnknown`.
[Interfacetraits:: Fillarraywithiid](#fillarraywithiid) | Atribui a ID de interface do `Base` ao elemento de matriz especificado pelo argumento de índice.
[Interfacetraits:: Verify](#verify)                     | Verifica se `Base` é derivado corretamente.

### <a name="public-constants"></a>Constantes públicas

Nome                                   | Descrição
-------------------------------------- | ---------------------------------------------------------------------------------------
[Interfacetraits:: Iidcount](#iidcount) | Contém o número de IDs associadas ao atual de interface `InterfaceTraits` objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`InterfaceTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="cancastto"></a>Interfacetraits:: Cancastto

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
template<typename T>
static __forceinline bool CanCastTo(
   _In_ T* ptr,
   REFIID riid,
   _Deref_out_ void **ppv
);
```

### <a name="parameters"></a>Parâmetros

*ptr*<br/>
O nome de um ponteiro para um tipo.

*riid*<br/>
A ID de interface do `Base`.

*ppv*<br/>
Se essa operação for bem-sucedida, *ppv* aponta para a interface especificada pelo `Base`. Caso contrário, *ppv* é definido como `nullptr`.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se essa operação for bem-sucedida e *ptr* é convertido em um ponteiro para `Base`; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Indica se o ponteiro especificado pode ser convertido em um ponteiro para `Base`.

Para obter mais informações sobre `Base`, consulte o [Typedefs públicos](#public-typedefs) seção.

## <a name="casttobase"></a>Interfacetraits:: Casttobase

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
template<typename T>
static __forceinline Base* CastToBase(
   _In_ T* ptr
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo do parâmetro *ptr*.

*ptr*<br/>
Ponteiro para um tipo *T*.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para `Base`.

### <a name="remarks"></a>Comentários

Converte o ponteiro especificado para um ponteiro para `Base`.

Para obter mais informações sobre `Base`, consulte o [Typedefs públicos](#public-typedefs) seção.

## <a name="casttounknown"></a>Interfacetraits:: Casttounknown

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
template<typename T>
static __forceinline IUnknown* CastToUnknown(
   _In_ T* ptr
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo do parâmetro *ptr*.

*ptr*<br/>
Ponteiro para o tipo *T*.

### <a name="return-value"></a>Valor de retorno

Ponteiro para o IUnknown do qual `Base` é derivado.

### <a name="remarks"></a>Comentários

Converte o ponteiro especificado para um ponteiro para `IUnknown`.

Para obter mais informações sobre `Base`, consulte o [Typedefs públicos](#public-typedefs) seção.

## <a name="fillarraywithiid"></a>Interfacetraits:: Fillarraywithiid

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
__forceinline static void FillArrayWithIid(
   _Inout_ unsigned long &index,
   _In_ IID* iids
);
```

### <a name="parameters"></a>Parâmetros

*index*<br/>
Ponteiro para um campo que contém um valor de índice baseado em zero.

*IIDs*<br/>
Uma matriz de IDs de interface.

### <a name="remarks"></a>Comentários

Atribui a ID de interface do `Base` ao elemento de matriz especificado pelo argumento de índice.

O nome dessa API, ao contrário do elemento de apenas uma matriz é modificado; não é a matriz inteira.

Para obter mais informações sobre `Base`, consulte o [Typedefs públicos](#public-typedefs) seção.

## <a name="iidcount"></a>Interfacetraits:: Iidcount

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
static const unsigned long IidCount = 1;
```

### <a name="remarks"></a>Comentários

Contém o número de IDs associadas ao atual de interface `InterfaceTraits` objeto.

## <a name="verify"></a>Interfacetraits:: Verify

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
__forceinline static void Verify();
```

### <a name="remarks"></a>Comentários

Verifica se `Base` é derivado corretamente.

Para obter mais informações sobre `Base`, consulte o [Typedefs públicos](#public-typedefs) seção.
