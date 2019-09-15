---
title: _query_new_mode
ms.date: 11/04/2016
api_name:
- _query_new_mode
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
- api-ms-win-crt-heap-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- query_new_mode
- _query_new_mode
helpviewer_keywords:
- query_new_mode function
- handler modes
- _query_new_mode function
ms.assetid: e185c5f9-b73b-4257-8eff-b47648374768
ms.openlocfilehash: 59724dafdc6488596478d0b44b254c4f498fce99
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70950108"
---
# <a name="_query_new_mode"></a>_query_new_mode

Retorna um inteiro que indica o novo modo de manipulador definido por **_set_new_mode** para **malloc**.

## <a name="syntax"></a>Sintaxe

```C
int _query_new_mode(
   void
);
```

## <a name="return-value"></a>Valor de retorno

Retorna o novo modo de manipulador atual, ou seja, 0 ou 1, para **malloc**. Um valor de retorno 1 indica que, em falha ao alocar memória, **malloc** chama a nova rotina do manipulador; um valor de retorno 0 indica que ele não faz isso.

## <a name="remarks"></a>Comentários

A C++ função **_query_new_mode** retorna um inteiro que indica o novo modo de manipulador definido C++ pela função [_set_new_mode](set-new-mode.md) para [malloc](malloc.md). O novo modo de manipulador indica se, em caso de falha ao alocar memória, **malloc** é chamar a nova rotina do manipulador, conforme definido por [_set_new_handler](set-new-handler.md). Por padrão, o **malloc** não chama a nova rotina do manipulador em caso de falha. Você pode usar **_set_new_mode** para substituir esse comportamento para que, em falha, **malloc** chame a nova rotina do manipulador da mesma maneira que o **novo** operador faz quando ele falha ao alocar memória. Para obter mais informações, consulte a discussão sobre os [operadores new e delete](../../cpp/new-and-delete-operators.md) na Referência da Linguagem C++.

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
