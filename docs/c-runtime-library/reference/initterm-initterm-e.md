---
title: _initterm, _initterm_e
ms.date: 11/04/2016
api_name:
- _initterm_e
- _initterm
api_location:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-runtime-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _initterm_e
- initterm
- _initterm
- initterm_e
helpviewer_keywords:
- initterm function
- initterm_e function
- _initterm function
- _initterm_e function
ms.assetid: 85131efe-c747-429a-8897-bcdedb000172
ms.openlocfilehash: 7e85494bf6c8215d03602ee112e1ff2c0f1cf6f2
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70954624"
---
# <a name="_initterm-_initterm_e"></a>_initterm, _initterm_e

Métodos internos que percorrem uma tabela de ponteiros de função e os inicializam.

O primeiro ponteiro é o local de início da tabela e o segundo ponteiro é o local de término.

## <a name="syntax"></a>Sintaxe

```C
void __cdecl _initterm(
   PVFV *,
   PVFV *
);

int __cdecl _initterm_e(
   PVFV *,
   PVFV *
);
```

## <a name="return-value"></a>Valor de retorno

Um código de erro diferente de zero se uma inicialização falhar e gerar um erro; 0 se nenhum erro ocorrer.

## <a name="remarks"></a>Comentários

Esses métodos são chamados internamente apenas durante a inicialização de um programa C++. Não chame esses métodos em um programa.

Quando esses métodos orientam uma tabela de entradas de função, eles ignoram entradas **nulas** e continuam.

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
