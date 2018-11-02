---
title: _get_unexpected
ms.date: 11/04/2016
apiname:
- _get_unexpected
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
apitype: DLLExport
f1_keywords:
- __get_unexpected
- _get_unexpected
- get_unexpected
helpviewer_keywords:
- __get_unexpected function
- get_unexpected function
- _get_unexpected function
ms.assetid: a5f7a7a0-18e0-485e-953d-db291068a1e8
ms.openlocfilehash: 225158ecab60a5997ebedbad107eb43d82189234
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50519399"
---
# <a name="getunexpected"></a>_get_unexpected

Retorna a rotina de terminação a ser chamado pelo **inesperado**.

## <a name="syntax"></a>Sintaxe

```C
unexpected_function _get_unexpected( void );
```

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para a função registrada por [set_unexpected](set-unexpected-crt.md). Se nenhuma função tiver sido definida, o valor retornado pode ser usado para restaurar o comportamento padrão; Esse valor pode ser **nulo**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_unexpected**|\<eh.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Rotinas de tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)<br/>
[abort](abort.md)<br/>
[set_terminate](set-terminate-crt.md)<br/>
[terminate](terminate-crt.md)<br/>
[unexpected](unexpected-crt.md)<br/>
