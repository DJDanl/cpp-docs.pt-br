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
ms.openlocfilehash: fcaf33309521b44163022e0ffa9b1e03e53e2551
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371341"
---
# <a name="issame-structure"></a>Estrutura IsSame

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

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

Testa se um tipo especificado é o mesmo que outro tipo especificado.

## <a name="members"></a>Membros

### <a name="public-constants"></a>Constantes públicas

Nome                    | Descrição
----------------------- | --------------------------------------------------
[IsSame::valor](#value) | Indica se um tipo é o mesmo que o outro.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IsSame`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** internal.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="issamevalue"></a><a name="value"></a>IsSame::valor

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

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

Indica se um tipo é o mesmo que o outro.

`value`é **verdade** se os parâmetros do modelo forem os mesmos e **forem falsos** se os parâmetros do modelo forem diferentes.
