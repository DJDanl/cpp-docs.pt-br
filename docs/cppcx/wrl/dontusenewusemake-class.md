---
title: Classe DontUseNewUseMake
ms.date: 09/21/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::DontUseNewUseMake
- implements/Microsoft::WRL::Details::DontUseNewUseMake::operator new
helpviewer_keywords:
- Microsoft::WRL::Details::DontUseNewUseMake class
- Microsoft::WRL::Details::DontUseNewUseMake::operator new operator
ms.assetid: 8b38d07b-fc14-4cea-afb9-4c1a7dde0093
ms.openlocfilehash: 02420f2657c7d7d6a7a0294f0321717a3bb2b5d7
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783741"
---
# <a name="dontusenewusemake-class"></a>Classe DontUseNewUseMake

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
class DontUseNewUseMake;
```

## <a name="remarks"></a>Comentários

Impeça o uso de operador `new` em `RuntimeClass`. Consequentemente, você deve usar o [tornar função](make-function.md) em vez disso.

## <a name="members"></a>Membros

### <a name="public-operators"></a>Operadores públicos

Nome                                             | Descrição
------------------------------------------------ | ---------------------------------------------------------------------------
[Dontusenewusemake:: Operator new](#operator-new) | Sobrecarrega o operador `new` e impede que ele seja usado no `RuntimeClass`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`DontUseNewUseMake`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="operator-new"></a>DontUseNewUseMake::operator new

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
void* operator new(
   size_t,
   _In_ void* placement
);
```

### <a name="parameters"></a>Parâmetros

*__unnamed0*<br/>
Um parâmetro não nomeado que especifica o número de bytes de memória para alocar.

*placement*<br/>
O tipo a ser alocado.

### <a name="return-value"></a>Valor de retorno

Fornece uma maneira de passar argumentos adicionais se você sobrecarregar o operador `new`.

### <a name="remarks"></a>Comentários

Sobrecarrega o operador `new` e impede que ele seja usado no `RuntimeClass`.
