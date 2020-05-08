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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 2ee68506437cb1c5b76cac05d674527095055055
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82920408"
---
# <a name="_get_terminate"></a>_get_terminate

Retorna a rotina de término a ser chamada por **Terminate**.

## <a name="syntax"></a>Sintaxe

```C
terminate_function _get_terminate( void );
```

## <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a função registrada por [set_terminate](set-terminate-crt.md). Se nenhuma função tiver sido definida, o valor de retorno poderá ser usado para restaurar o comportamento padrão; Esse valor pode ser **nulo**.

## <a name="remarks"></a>Comentários

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_terminate**|\<eh.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Rotinas de tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)<br/>
[anular](abort.md)<br/>
[set_unexpected](set-unexpected-crt.md)<br/>
[encerrar](terminate-crt.md)<br/>
[previsto](unexpected-crt.md)<br/>
