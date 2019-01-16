---
title: Estrutura IsSame
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::IsSame
- internal/Microsoft::WRL::Details::IsSame::value
helpviewer_keywords:
- Microsoft::WRL::Details::IsSame structure
- Microsoft::WRL::Details::IsSame::value constant
ms.assetid: 1eddbc3f-3cc5-434f-8495-e4477e1f868e
ms.openlocfilehash: b659f832756b79289181db34fa8d6fc0d974609d
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335661"
---
# <a name="issame-structure"></a>Estrutura IsSame

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T1, typename T2>
struct IsSame;

template <typename T1>
struct IsSame<T1, T1>;
```

### <a name="parameters"></a>Parâmetros

*T1*<br/>
Um tipo.

*T2*<br/>
Outro tipo.

## <a name="remarks"></a>Comentários

Testes se um tipo especificado é igual a outro tipo especificado.

## <a name="members"></a>Membros

### <a name="public-constants"></a>Constantes públicas

Nome                    | Descrição
----------------------- | --------------------------------------------------
[IsSame::value](#value) | Indica se um tipo é igual a outro.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IsSame`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** internal.h

**Namespace:** Microsoft::WRL::Details

## <a name="value"></a>IsSame::value

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
template <typename T1, typename T2>
struct IsSame
{
    static const bool value = false;
};

template <typename T1>
struct IsSame<T1, T1>
{
    static const bool value = true;
};
```

### <a name="remarks"></a>Comentários

Indica se um tipo é igual a outro.

`value` está **verdadeira** se os parâmetros de modelo são os mesmos, e **falso** se os parâmetros de modelo são diferentes.
