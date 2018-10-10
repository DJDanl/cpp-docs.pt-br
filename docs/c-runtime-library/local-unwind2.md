---
title: _local_unwind2 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
apiname:
- _local_unwind2
apilocation:
- msvcr110_clr0400.dll
- msvcrt.dll
- msvcr100.dll
- msvcr110.dll
- msvcr80.dll
- msvcr90.dll
- msvcr120.dll
apitype: DLLExport
f1_keywords:
- _local_unwind2
- local_unwind2
dev_langs:
- C++
helpviewer_keywords:
- _local_unwind2 function
- local_unwind2 function
ms.assetid: 44f1fa82-e01e-490f-a6e6-18fc6811c28c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 47227d4be0ad1c5145a9064d11b4ea633c7d7fc1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46035780"
---
# <a name="localunwind2"></a>_local_unwind2

Função CRT interna. Executa todos os manipuladores de terminação listados na tabela de escopo indicada.

## <a name="syntax"></a>Sintaxe

```
void _local_unwind2(
   PEXCEPTION_REGISTRATION xr,
   int stop
);
```

#### <a name="parameters"></a>Parâmetros

*xr*<br/>
[in] Um registro associado a uma tabela de escopo.

*stop*<br/>
[in] O nível lexical que indica o local em que o `_local_unwind2` deve parar.

## <a name="remarks"></a>Comentários

Esse método só é usado pelo ambiente de tempo de execução. Não chame o método no seu código.

Quando esse método executa manipuladores de terminação, ele começa no nível lexical atual e avança nos níveis lexicais até atingir o número indicado por `stop`. Não executa manipuladores de terminação no nível indicado por `stop`.

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)