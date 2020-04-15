---
title: _get_terminate
ms.date: 4/2/2020
api_name:
- _get_terminate
- _o__get_terminate
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- get_terminate
- _get_terminate
- __get_terminate
helpviewer_keywords:
- __get_terminate function
- get_terminate function
- _get_terminate function
ms.assetid: c8f168c4-0ad5-4832-a522-dd1ef383c208
ms.openlocfilehash: fff90037851b23f3525f514aba0f6f913f9dd776
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81344927"
---
# <a name="_get_terminate"></a>_get_terminate

Retorna a rotina de rescisão para ser chamado por **terminar**.

## <a name="syntax"></a>Sintaxe

```C
terminate_function _get_terminate( void );
```

## <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a função registrada por [set_terminate](set-terminate-crt.md). Se nenhuma função tiver sido definida, o valor de retorno poderá ser usado para restaurar o comportamento padrão; este valor pode ser **NULO**.

## <a name="remarks"></a>Comentários

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_terminate**|\<eh.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Rotinas de tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)<br/>
[Abortar](abort.md)<br/>
[Set_unexpected](set-unexpected-crt.md)<br/>
[Terminar](terminate-crt.md)<br/>
[Inesperado](unexpected-crt.md)<br/>
