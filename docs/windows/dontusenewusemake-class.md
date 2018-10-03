---
title: Classe DontUseNewUseMake | Microsoft Docs
ms.custom: ''
ms.date: 09/21/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::DontUseNewUseMake
- implements/Microsoft::WRL::Details::DontUseNewUseMake::operator new
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Details::DontUseNewUseMake class
- Microsoft::WRL::Details::DontUseNewUseMake::operator new operator
ms.assetid: 8b38d07b-fc14-4cea-afb9-4c1a7dde0093
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9c1f3a57401a3ab2efd45cab2dace127010c24e6
ms.sourcegitcommit: 1d9bd38cacbc783fccd3884b7b92062161c91c84
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48235276"
---
# <a name="dontusenewusemake-class"></a>Classe DontUseNewUseMake

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
class DontUseNewUseMake;
```

## <a name="remarks"></a>Comentários

Impeça o uso de operador `new` em `RuntimeClass`. Consequentemente, você deve usar o [tornar função](../windows/make-function.md) em vez disso.

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

## <a name="operator-new"></a>Dontusenewusemake:: Operator new

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
