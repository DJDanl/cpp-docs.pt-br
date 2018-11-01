---
title: _query_new_handler
ms.date: 11/04/2016
apiname:
- _query_new_handler
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
- _query_new_handler
- query_new_handler
helpviewer_keywords:
- query_new_handler function
- handler routines
- error handling
- _query_new_handler function
ms.assetid: 9a84b5c3-fe33-4c01-83a0-be87dc3ec518
ms.openlocfilehash: febefbe46d95b7e5c8de026806a20d7eff74e7cc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50515983"
---
# <a name="querynewhandler"></a>_query_new_handler

Retorna o endereço da rotina atual do novo manipulador.

## <a name="syntax"></a>Sintaxe

```C
_PNH _query_new_handler(
   void
);
```

## <a name="return-value"></a>Valor de retorno

Retorna o endereço da rotina atual novo manipulador conforme definido pela **set_new_handler**.

## <a name="remarks"></a>Comentários

O C++ **query_new_handler** função retorna o endereço da função de manipulação de exceção atual definida pelo C++ [set_new_handler](set-new-handler.md) função. **set_new_handler** é usado para especificar uma função de manipulação de exceção que assumirá o controle se o **nova** operador falha ao alocar memória. Para obter mais informações, consulte a discussão sobre os [operadores new e delete](../../cpp/new-and-delete-operators.md) na Referência da Linguagem C++.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_query_new_handler**|\<new.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
[free](free.md)<br/>
