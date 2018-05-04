---
title: _query_new_mode | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- query_new_mode function
- handler modes
- _query_new_mode function
ms.assetid: e185c5f9-b73b-4257-8eff-b47648374768
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8907b043e8b4441d6e5213a1d386dbc1a5a6910a
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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

Retorna o novo manipulador modo atual, ou seja, 0 ou 1, para **malloc**. A retornar o valor de 1 indica que, em caso de falha ao alocar memória, **malloc** chama a rotina do manipulador de novo; um valor de retorno 0 indica que não.

## <a name="remarks"></a>Comentários

O C++ **query_new_mode** função retorna um inteiro que indica o novo modo de manipulador é definido por C++ [set_new_mode](set-new-mode.md) funcionar para [malloc](malloc.md). O novo modo de manipulador indica se, em caso de falha ao alocar memória, **malloc** é chamar a rotina do manipulador de novo conforme definido pela [set_new_handler](set-new-handler.md). Por padrão, **malloc** não chamar a rotina do manipulador de novo em caso de falha. Você pode usar **set_new_mode** para substituir esse comportamento para que em caso de falha **malloc** chama a rotina do manipulador de novo na mesma forma que o **novo** operador não quando ele falhar ao aloca memória. Para obter mais informações, consulte a discussão sobre os [operadores new e delete](../../cpp/new-and-delete-operators.md) na Referência da Linguagem C++.

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
