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
ms.openlocfilehash: 17109508cf99888ccde79be39a41c5361da24c6e
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58783830"
---
# <a name="argtraits-structure"></a>Estrutura ArgTraits

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

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
O parâmetro TypeName para uma estrutura ArgTraits que não pode corresponder a qualquer `Invoke` assinatura do método.

*TDelegateInterface*<br/>
Uma interface de delegado.

*TArg1*<br/>
O tipo do primeiro argumento do `Invoke` método.

*TArg2*<br/>
O tipo do segundo argumento do `Invoke` método.

*TArg3*<br/>
O tipo do terceiro argumento do `Invoke` método.

*TArg4*<br/>
O tipo do quarto argumento do `Invoke` método.

*TArg5*<br/>
O tipo do quinto argumento do `Invoke` método.

*TArg6*<br/>
O tipo do sexto argumento do `Invoke` método.

*TArg7*<br/>
O tipo do sétimo argumento do `Invoke` método.

*TArg8*<br/>
O tipo do oitavo argumento do `Invoke` método.

*TArg9*<br/>
O tipo do nono argumento do `Invoke` método.

## <a name="remarks"></a>Comentários

O `ArgTraits` estrutura declara um delegado especificado de interface e uma função de membro anônimo que tem um número especificado de parâmetros.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome       | Descrição
---------- | ----------------------
`Arg1Type` | O typedef de DynamicSite<Targ1.
`Arg2Type` | O typedef de TArg2.
`Arg3Type` | O typedef de TArg3.
`Arg4Type` | O typedef de TArg4.
`Arg5Type` | O typedef de TArg5.
`Arg6Type` | O typedef de TArg6.
`Arg7Type` | O typedef de TArg7.
`Arg8Type` | O typedef de TArg8.
`Arg9Type` | O typedef de TArg9.

### <a name="public-constants"></a>Constantes públicas

Nome                     | Descrição
------------------------ | ---------------------------------------------------------------------------------------
[ArgTraits::args](#args) | Mantém uma contagem do número de parâmetros `Invoke` método da interface de um delegado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ArgTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL::Details

## <a name="args"></a>ArgTraits::args

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
static const int args = -1;
```

### <a name="remarks"></a>Comentários

Mantém uma contagem do número de parâmetros `Invoke` método da interface de um delegado. Quando `args` for igual a -1, não pode haver nenhuma correspondência para o `Invoke` assinatura do método.
