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
ms.openlocfilehash: c13e7fec3289b66b40e44f91404a50cba7a473b1
ms.sourcegitcommit: b8c22e6d555cf833510753cba7a368d57e5886db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2020
ms.locfileid: "76821708"
---
# <a name="argtraits-structure"></a>Estrutura ArgTraits

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

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
Parâmetro TypeName para uma estrutura ArgTraits que não pode corresponder a nenhuma assinatura de método de `Invoke`.

*TDelegateInterface*<br/>
Uma interface de representante.

*TArg1*<br/>
O tipo do primeiro argumento do método `Invoke`.

*TArg2*<br/>
O tipo do segundo argumento do método `Invoke`.

*TArg3*<br/>
O tipo do terceiro argumento do método `Invoke`.

*TArg4*<br/>
O tipo do quarto argumento do método de `Invoke`.

*TArg5*<br/>
O tipo do quinto argumento do método `Invoke`.

*TArg6*<br/>
O tipo do sexto argumento do método de `Invoke`.

*TArg7*<br/>
O tipo do sétimo argumento do método `Invoke`.

*TArg8*<br/>
O tipo do oitavo argumento do método `Invoke`.

*TArg9*<br/>
O tipo do nono argumento do método de `Invoke`.

## <a name="remarks"></a>Comentários

A estrutura de `ArgTraits` declara uma interface de delegado especificada e uma função de membro anônimo que tem um número especificado de parâmetros.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

Name       | Descrição
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

### <a name="public-constants"></a>Constantes Públicas

Name                     | Descrição
------------------------ | ---------------------------------------------------------------------------------------
[ArgTraits::args](#args) | Mantém a contagem do número de parâmetros no método `Invoke` de uma interface de representante.

## <a name="inheritance-hierarchy"></a>Hierarquia de Herança

`ArgTraits`

## <a name="requirements"></a>Requisitos do

**Cabeçalho:** Event. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="args"></a>ArgTraits::args

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
static const int args = -1;
```

### <a name="remarks"></a>Comentários

Mantém a contagem do número de parâmetros no método `Invoke` de uma interface de representante. Quando `args` é igual a-1, não pode haver nenhuma correspondência para a assinatura do método `Invoke`.
