---
title: _initterm, _initterm_e
ms.date: 11/04/2016
apiname:
- _initterm_e
- _initterm
apilocation:
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
apitype: DLLExport
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
ms.openlocfilehash: 65963e95507d4d6444ebcc9038b5b8cf797f9feb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62331656"
---
# <a name="initterm-initterme"></a>_initterm, _initterm_e

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

Quando esses métodos percorrem uma tabela de entradas de função, eles pulam **nulo** entradas e continuar.

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
