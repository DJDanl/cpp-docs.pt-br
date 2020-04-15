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
ms.openlocfilehash: 17f743a38af3ddc600a55e38905d19868d076a22
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371366"
---
# <a name="interfacetraits-structure"></a>Estrutura InterfaceTraits

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

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
Para `RuntimeClass` `Implements` , `ChainInterfaces`e , uma interface que não estará na lista de IDs de interface suportados.

## <a name="remarks"></a>Comentários

Implementa características comuns de uma interface.

O segundo modelo é uma especialização para interfaces camufladas. O terceiro modelo é uma especialização para parâmetros Nil.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a><a name="public-typedefs"></a>Typedefs públicos

Nome   | Descrição
------ | ------------------------------------------
`Base` | Um sinônimo para o parâmetro de modelo *I0.*

### <a name="public-methods"></a>Métodos públicos

Nome                                                   | Descrição
------------------------------------------------------ | ----------------------------------------------------------------------------------------
[Situado em interface::Cancastto](#cancastto)               | Indica se o ponteiro especificado pode `Base`ser lançado a um ponteiro para .
[Eos de interface::CasttoBase](#casttobase)             | Lança o ponteiro especificado para `Base`um ponteiro para .
[InterfaceTraits::CasttoUnknown](#casttounknown)       | Lança o ponteiro especificado para `IUnknown`um ponteiro para .
[InterfaceTraits::FillArrayWithIid](#fillarraywithiid) | Atribui o ID `Base` de interface ao elemento matriz especificado pelo argumento do índice.
[Eos de interface::Verificar](#verify)                     | Verifica se `Base` é derivado corretamente.

### <a name="public-constants"></a>Constantes públicas

Nome                                   | Descrição
-------------------------------------- | ---------------------------------------------------------------------------------------
[InterfaceTraits::IidCount](#iidcount) | Contém o número de IDs `InterfaceTraits` de interface associados ao objeto atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`InterfaceTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="interfacetraitscancastto"></a><a name="cancastto"></a>Situado em interface::Cancastto

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
template<typename T>
static __forceinline bool CanCastTo(
   _In_ T* ptr,
   REFIID riid,
   _Deref_out_ void **ppv
);
```

### <a name="parameters"></a>Parâmetros

*Ptr*<br/>
O nome de um ponteiro para um tipo.

*riid*<br/>
O ID `Base`de interface de .

*Ppv*<br/>
Se esta operação for bem sucedida, o `Base` *ppv* aponte para a interface especificada por . Caso contrário, *ppv* `nullptr`é definido para .

### <a name="return-value"></a>Valor retornado

**verdade** se esta operação é bem sucedida e `Base` *ptr* é lançado a um ponteiro para ; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

Indica se o ponteiro especificado pode `Base`ser lançado a um ponteiro para .

Para obter `Base`mais informações sobre , consulte a seção [Typedefs públicos.](#public-typedefs)

## <a name="interfacetraitscasttobase"></a><a name="casttobase"></a>Eos de interface::CasttoBase

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
template<typename T>
static __forceinline Base* CastToBase(
   _In_ T* ptr
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de parâmetro *ptr*.

*Ptr*<br/>
Ponteiro para um tipo *T*.

### <a name="return-value"></a>Valor retornado

Um ponteiro para `Base`.

### <a name="remarks"></a>Comentários

Lança o ponteiro especificado para `Base`um ponteiro para .

Para obter `Base`mais informações sobre , consulte a seção [Typedefs públicos.](#public-typedefs)

## <a name="interfacetraitscasttounknown"></a><a name="casttounknown"></a>InterfaceTraits::CasttoUnknown

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
template<typename T>
static __forceinline IUnknown* CastToUnknown(
   _In_ T* ptr
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de parâmetro *ptr*.

*Ptr*<br/>
Ponteiro para digitar *T*.

### <a name="return-value"></a>Valor retornado

Ponteiro para o IUnknown do qual `Base` é derivado.

### <a name="remarks"></a>Comentários

Lança o ponteiro especificado para `IUnknown`um ponteiro para .

Para obter `Base`mais informações sobre , consulte a seção [Typedefs públicos.](#public-typedefs)

## <a name="interfacetraitsfillarraywithiid"></a><a name="fillarraywithiid"></a>InterfaceTraits::FillArrayWithIid

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
__forceinline static void FillArrayWithIid(
   _Inout_ unsigned long &index,
   _In_ IID* iids
);
```

### <a name="parameters"></a>Parâmetros

*Índice*<br/>
Ponteiro para um campo que contém um valor de índice baseado em zero.

*Iids*<br/>
Uma matriz de IDs de interface.

### <a name="remarks"></a>Comentários

Atribui o ID `Base` de interface ao elemento matriz especificado pelo argumento do índice.

Ao contrário do nome desta API, apenas um elemento de matriz é modificado; não toda a matriz.

Para obter `Base`mais informações sobre , consulte a seção [Typedefs públicos.](#public-typedefs)

## <a name="interfacetraitsiidcount"></a><a name="iidcount"></a>InterfaceTraits::IidCount

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
static const unsigned long IidCount = 1;
```

### <a name="remarks"></a>Comentários

Contém o número de IDs `InterfaceTraits` de interface associados ao objeto atual.

## <a name="interfacetraitsverify"></a><a name="verify"></a>Eos de interface::Verificar

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
__forceinline static void Verify();
```

### <a name="remarks"></a>Comentários

Verifica se `Base` é derivado corretamente.

Para obter `Base`mais informações sobre , consulte a seção [Typedefs públicos.](#public-typedefs)
