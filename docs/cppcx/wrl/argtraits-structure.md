---
title: Estrutura ArgTraits
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::ArgTraits
- event/Microsoft::WRL::Details::ArgTraits::args
helpviewer_keywords:
- Microsoft::WRL::Details::ArgTraits structure
- Microsoft::WRL::Details::ArgTraits::args constant
ms.assetid: 58ae4115-c1bc-48c8-b01b-e60554841c30
ms.openlocfilehash: 16c44d861ebbbc98fa1bffb62a00d1989c0c803c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377167"
---
# <a name="argtraits-structure"></a>Estrutura ArgTraits

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename TMemberFunction>
struct ArgTraits;

template<typename TDelegateInterface>
struct ArgTraits<HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)(void)>;

template<typename TDelegateInterface, typename TArg1>
struct ArgTraits<HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)(TArg1)>;

template<typename TDelegateInterface, typename TArg1, typename TArg2>
struct ArgTraits<
    HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)(TArg1, TArg2)>;

template<
    typename TDelegateInterface,
    typename TArg1,
    typename TArg2,
    typename TArg3
>
struct ArgTraits<
    HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)(TArg1, TArg2, TArg3)>;

template<
    typename TDelegateInterface,
    typename TArg1,
    typename TArg2,
    typename TArg3,
    typename TArg4
>
struct ArgTraits<
    HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)
             (TArg1, TArg2, TArg3, TArg4)>;

template<
    typename TDelegateInterface,
    typename TArg1,
    typename TArg2,
    typename TArg3,
    typename TArg4,
    typename TArg5
>
struct ArgTraits<
    HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)
             (TArg1, TArg2, TArg3, TArg4, TArg5)>;

template<
    typename TDelegateInterface,
    typename TArg1,
    typename TArg2,
    typename TArg3,
    typename TArg4,
    typename TArg5,
    typename TArg6
>
struct ArgTraits<
    HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)
             (TArg1, TArg2, TArg3, TArg4, TArg5, TArg6)>;

template<
    typename TDelegateInterface,
    typename TArg1,
    typename TArg2,
    typename TArg3,
    typename TArg4,
    typename TArg5,
    typename TArg6,
    typename TArg7
>
struct ArgTraits<
    HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)
             (TArg1, TArg2, TArg3, TArg4, TArg5, TArg6, TArg7)>;

template<
    typename TDelegateInterface,
    typename TArg1,
    typename TArg2,
    typename TArg3,
    typename TArg4,
    typename TArg5,
    typename TArg6,
    typename TArg7,
    typename TArg8
>
struct ArgTraits<
    HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)
             (TArg1, TArg2, TArg3, TArg4, TArg5, TArg6, TArg7, TArg8)>;

template<
    typename TDelegateInterface,
    typename TArg1,
    typename TArg2,
    typename TArg3,
    typename TArg4,
    typename TArg5,
    typename TArg6,
    typename TArg7,
    typename TArg8,
    typename TArg9
>
struct ArgTraits<
    HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)
             (TArg1, TArg2, TArg3, TArg4, TArg5, TArg6, TArg7, TArg8, TArg9)>;
```

### <a name="parameters"></a>Parâmetros

*TMemberFunction*<br/>
Parâmetro typename para uma estrutura ArgTraits `Invoke` que não pode corresponder a qualquer assinatura do método.

*Interface de TDelegate*<br/>
Uma interface de delegado.

*TArg1*<br/>
O tipo do primeiro `Invoke` argumento do método.

*TArg2*<br/>
O tipo do segundo `Invoke` argumento do método.

*TArg3*<br/>
O tipo do terceiro `Invoke` argumento do método.

*TArg4*<br/>
O tipo do quarto `Invoke` argumento do método.

*Rio TArg5*<br/>
O tipo do quinto `Invoke` argumento do método.

*TArg6*<br/>
O tipo do sexto `Invoke` argumento do método.

*TArg7*<br/>
O tipo do sétimo `Invoke` argumento do método.

*TArg8*<br/>
O tipo do oitavo `Invoke` argumento do método.

*TArg9*<br/>
O tipo do nono `Invoke` argumento do método.

## <a name="remarks"></a>Comentários

A `ArgTraits` estrutura declara uma interface de delegado especificada e uma função de membro anônimo que tem um número especificado de parâmetros.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome       | Descrição
---------- | ----------------------
`Arg1Type` | O typedef para TArg1.
`Arg2Type` | O typedef para TArg2.
`Arg3Type` | O typedef para TArg3.
`Arg4Type` | O typedef para TArg4.
`Arg5Type` | O typedef para TArg5.
`Arg6Type` | O typedef para TArg6.
`Arg7Type` | O typedef para TArg7.
`Arg8Type` | O typedef para TArg8.
`Arg9Type` | O typedef para TArg9.

### <a name="public-constants"></a>Constantes públicas

Nome                     | Descrição
------------------------ | ---------------------------------------------------------------------------------------
[ArgTraits::args](#args) | Mantém a contagem do `Invoke` número de parâmetros no método de uma interface de delegado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ArgTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** event.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="argtraitsargs"></a><a name="args"></a>ArgTraits::args

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
static const int args = -1;
```

### <a name="remarks"></a>Comentários

Mantém a contagem do `Invoke` número de parâmetros no método de uma interface de delegado. Quando `args` igual a -1, não pode `Invoke` haver correspondência para a assinatura do método.
