---
title: _abnormal_termination
ms.date: 11/04/2016
api_name:
- _abnormal_termination
api_location:
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr90.dll
- msvcr120.dll
- msvcrt.dll
- msvcr80.dll
- msvcr100.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _abnormal_termination
helpviewer_keywords:
- _abnormal_termination
ms.assetid: 952970a4-9586-4c3d-807a-db729448c91c
ms.openlocfilehash: a963f1059eccaddce9ec01cd53a07df668ee46c6
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213652"
---
# <a name="_abnormal_termination"></a>_abnormal_termination

Indica se o **`__finally`** bloco de uma [instrução try-finally](../cpp/try-finally-statement.md) é inserido enquanto o sistema está executando uma lista interna de manipuladores de encerramento.

## <a name="syntax"></a>Sintaxe

```cpp
int   _abnormal_termination(
   );
```

## <a name="return-value"></a>Valor retornado

**`true`** Se o sistema estiver *desenrolando* a pilha; caso contrário, **`false`** .

## <a name="remarks"></a>Comentários

É uma função interna usada para gerenciar o desenrolamento de exceções e não tem o objetivo de ser chamado no código do usuário.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|_abnormal_termination|excpt. h|

## <a name="see-also"></a>Confira também

[Instrução try – finally](../cpp/try-finally-statement.md)
