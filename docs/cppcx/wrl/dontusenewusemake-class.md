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
ms.openlocfilehash: ae67373b4f2f2d4a199b939b06e6f526f1365446
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371549"
---
# <a name="dontusenewusemake-class"></a>Classe DontUseNewUseMake

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
class DontUseNewUseMake;
```

## <a name="remarks"></a>Comentários

Impede o `new` uso `RuntimeClass`do operador em . Consequentemente, você deve usar a [função Fazer](make-function.md) em vez disso.

## <a name="members"></a>Membros

### <a name="public-operators"></a>Operadores públicos

Nome                                             | Descrição
------------------------------------------------ | ---------------------------------------------------------------------------
[DontUseNewUseMake:novo operador](#operator-new) | Sobrecarrega `new` o operador e impede `RuntimeClass`que ele seja usado em .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`DontUseNewUseMake`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="dontusenewusemakeoperator-new"></a><a name="operator-new"></a>DontUseNewUseMake:novo operador

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
void* operator new(
   size_t,
   _In_ void* placement
);
```

### <a name="parameters"></a>Parâmetros

*__unnamed0*<br/>
Um parâmetro não nomeado que especifica o número de bytes de memória para alocar.

*Colocação*<br/>
O tipo a ser alocado.

### <a name="return-value"></a>Valor retornado

Fornece uma maneira de passar argumentos `new`adicionais se você sobrecarregar o operador .

### <a name="remarks"></a>Comentários

Sobrecarrega `new` o operador e impede `RuntimeClass`que ele seja usado em .
