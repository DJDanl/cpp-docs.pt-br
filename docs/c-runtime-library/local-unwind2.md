---
title: _local_unwind2
ms.date: 11/04/2016
api_name:
- _local_unwind2
api_location:
- msvcr110_clr0400.dll
- msvcrt.dll
- msvcr100.dll
- msvcr110.dll
- msvcr80.dll
- msvcr90.dll
- msvcr120.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _local_unwind2
- local_unwind2
helpviewer_keywords:
- _local_unwind2 function
- local_unwind2 function
ms.assetid: 44f1fa82-e01e-490f-a6e6-18fc6811c28c
ms.openlocfilehash: 64ed92af32caaf579e7c6951250e3bf692d1cf43
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70944203"
---
# <a name="_local_unwind2"></a>_local_unwind2

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
