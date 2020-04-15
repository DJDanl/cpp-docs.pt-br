---
title: Estrutura IsBaseOfStrict
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::IsBaseOfStrict
- internal/Microsoft::WRL::Details::IsBaseOfStrict::value
helpviewer_keywords:
- Microsoft::WRL::Details::IsBaseOfStrict structure
- Microsoft::WRL::Details::IsBaseOfStrict::value constant
ms.assetid: 6fed7366-c8d4-4991-b4fb-43ed93f8e1bf
ms.openlocfilehash: 71db5a1b52a7d7d5471c15591fb34d954b465d07
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371360"
---
# <a name="isbaseofstrict-structure"></a>Estrutura IsBaseOfStrict

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename Base, typename Derived>
struct IsBaseOfStrict;

template <typename Base>
struct IsBaseOfStrict<Base, Base>;
```

### <a name="parameters"></a>Parâmetros

*Base*<br/>
O tipo base.

*Derivada*<br/>
O tipo derivado.

## <a name="remarks"></a>Comentários

Testa se um tipo é a base de outro.

O primeiro modelo testa se um tipo é derivado de um tipo de base, o que pode render **verdadeiro** ou **falso**. O segundo modelo testa se um tipo é derivado de si mesmo, o que sempre rende **falso**.

## <a name="members"></a>Membros

### <a name="public-constants"></a>Constantes públicas

Nome                            | Descrição
------------------------------- | --------------------------------------------------
[IsBaseOfStrict::valor](#value) | Indica se um tipo é a base de outro.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IsBaseOfStrict`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** internal.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="isbaseofstrictvalue"></a><a name="value"></a>IsBaseOfStrict::valor

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
static const bool value = __is_base_of(Base, Derived);
```

### <a name="remarks"></a>Comentários

Indica se um tipo é a base de outro.

`value`é **verdade** `Base` se o tipo é `Derived`uma classe base do tipo, caso contrário, é **falso**.
