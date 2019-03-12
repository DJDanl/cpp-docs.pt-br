---
title: _local_unwind2
ms.date: 11/04/2016
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
helpviewer_keywords:
- _local_unwind2 function
- local_unwind2 function
ms.assetid: 44f1fa82-e01e-490f-a6e6-18fc6811c28c
ms.openlocfilehash: c62763ecbdd2c05e8cd7b6733ec1df4254362527
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57744004"
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
