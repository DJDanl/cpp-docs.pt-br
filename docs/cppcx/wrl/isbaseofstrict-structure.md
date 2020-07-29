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
ms.openlocfilehash: 11acb4c7162a17ff763a574c27c186061ae476a7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211522"
---
# <a name="isbaseofstrict-structure"></a>Estrutura IsBaseOfStrict

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename Base, typename Derived>
struct IsBaseOfStrict;

template <typename Base>
struct IsBaseOfStrict<Base, Base>;
```

### <a name="parameters"></a>parâmetros

*Polybase*<br/>
O tipo base.

*Derivado*<br/>
O tipo derivado.

## <a name="remarks"></a>Comentários

Testa se um tipo é a base de outro.

O primeiro modelo testa se um tipo é derivado de um tipo base, o que pode gerar **`true`** ou **`false`** . O segundo modelo testa se um tipo é derivado de si mesmo, o que sempre produz **`false`** .

## <a name="members"></a>Membros

### <a name="public-constants"></a>Constantes públicas

Nome                            | Descrição
------------------------------- | --------------------------------------------------
[IsBaseOfStrict:: valor](#value) | Indica se um tipo é a base de outro.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IsBaseOfStrict`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Internal. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="isbaseofstrictvalue"></a><a name="value"></a>IsBaseOfStrict:: valor

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
static const bool value = __is_base_of(Base, Derived);
```

### <a name="remarks"></a>Comentários

Indica se um tipo é a base de outro.

`value`é **`true`** se Type `Base` for uma classe base do tipo `Derived` , caso contrário, é **`false`** .
