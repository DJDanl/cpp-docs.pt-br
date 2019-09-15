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
ms.openlocfilehash: b66cf0df998b4e33a9f3425fdf0f260d163f423b
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70944720"
---
# <a name="_abnormal_termination"></a>_abnormal_termination

Indica se o bloco `__finally` de uma [instrução try-finally](../cpp/try-finally-statement.md) é inserido enquanto o sistema está executado uma lista interna de manipuladores de término.

## <a name="syntax"></a>Sintaxe

```cpp
int   _abnormal_termination(
   );
```

## <a name="return-value"></a>Valor de retorno

**true** se o sistema estiver *desenrolando* a pilha; caso contrário, **false**.

## <a name="remarks"></a>Comentários

É uma função interna usada para gerenciar o desenrolamento de exceções e não tem o objetivo de ser chamado no código do usuário.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|_abnormal_termination|excpt. h|

## <a name="see-also"></a>Consulte também

[Instrução try-finally](../cpp/try-finally-statement.md)
