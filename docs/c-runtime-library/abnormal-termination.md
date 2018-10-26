---
title: _abnormal_termination | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
apiname:
- _abnormal_termination
apilocation:
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr90.dll
- msvcr120.dll
- msvcrt.dll
- msvcr80.dll
- msvcr100.dll
apitype: DLLExport
f1_keywords:
- _abnormal_termination
dev_langs:
- C++
helpviewer_keywords:
- _abnormal_termination
ms.assetid: 952970a4-9586-4c3d-807a-db729448c91c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 053fa3559672e4b314d209184c076e8ced2018db
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49162146"
---
# <a name="abnormaltermination"></a>_abnormal_termination

Indica se o bloco `__finally` de uma [instrução try-finally](../cpp/try-finally-statement.md) é inserido enquanto o sistema está executado uma lista interna de manipuladores de término.

## <a name="syntax"></a>Sintaxe

```cpp
int   _abnormal_termination(
   );
```

## <a name="return-value"></a>Valor retornado

**true** se o sistema estiver *desenrolando* a pilha; caso contrário, **false**.

## <a name="remarks"></a>Comentários

É uma função interna usada para gerenciar o desenrolamento de exceções e não tem o objetivo de ser chamado no código do usuário.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|_abnormal_termination|excpt. h|

## <a name="see-also"></a>Consulte também

[Instrução try-finally](../cpp/try-finally-statement.md)