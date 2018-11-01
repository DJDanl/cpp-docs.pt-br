---
title: _query_new_mode
ms.date: 11/04/2016
apiname:
- _query_new_mode
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
- api-ms-win-crt-heap-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- query_new_mode
- _query_new_mode
helpviewer_keywords:
- query_new_mode function
- handler modes
- _query_new_mode function
ms.assetid: e185c5f9-b73b-4257-8eff-b47648374768
ms.openlocfilehash: 327f22c847793316bd126721b4a66846d7da84dd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50620019"
---
# <a name="querynewmode"></a>_query_new_mode

Retorna um inteiro que indica o novo modo de manipulador definido por **set_new_mode** para **malloc**.

## <a name="syntax"></a>Sintaxe

```C
int _query_new_mode(
   void
);
```

## <a name="return-value"></a>Valor de retorno

Retorna o novo manipulador modo atual, ou seja, 0 ou 1, para **malloc**. Um valor retornado de 1 indica que, em caso de falha ao alocar memória, **malloc** chama a nova rotina do manipulador; um valor de retorno 0 indica que não.

## <a name="remarks"></a>Comentários

O C++ **query_new_mode** função retorna um inteiro que indica o novo modo do manipulador que é definido por C++ [set_new_mode](set-new-mode.md) funcionar por [malloc](malloc.md). O novo modo do manipulador indica se deve, em caso de falha ao alocar memória, **malloc** é chamar a nova rotina do manipulador conforme definido pela [set_new_handler](set-new-handler.md). Por padrão, **malloc** não chama a nova rotina do manipulador em caso de falha. Você pode usar **set_new_mode** para substituir esse comportamento para que, em caso de falha **malloc** chame a nova rotina do manipulador da mesma forma que o **novo** operador faz quando ele não consegue aloca memória. Para obter mais informações, consulte a discussão sobre os [operadores new e delete](../../cpp/new-and-delete-operators.md) na Referência da Linguagem C++.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_query_new_mode**|\<new.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
[calloc](calloc.md)<br/>
[free](free.md)<br/>
[realloc](realloc.md)<br/>
[_query_new_handler](query-new-handler.md)<br/>
