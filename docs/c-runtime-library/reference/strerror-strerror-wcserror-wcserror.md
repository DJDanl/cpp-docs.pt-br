---
title: strerror, _strerror, _wcserror, __wcserror | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- strerror
- _strerror
- _wcserror
- __wcserror
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
- __sys_errlist
- wcserror
- _strerror
- __wcserror
- strerror
- __sys_nerr
- _tcserror
- _wcserror
- tcserror
dev_langs:
- C++
helpviewer_keywords:
- strerror function
- _strerror function
- __sys_errlist
- wcserror function
- error messages, printing
- __sys_nerr
- tcserror function
- printing error messages
- _wcserror function
- _tcserror function
- __wcserror function
- error messages, getting
ms.assetid: 27b72255-f627-43c0-8836-bcda8b003e14
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e89a5de45baeb9b3beea2aa538cb0a2168f3c5ed
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="strerror-strerror-wcserror-wcserror"></a>strerror, _strerror, _wcserror, __wcserror

Obtém uma cadeia de caracteres de mensagem de erro do sistema (**strerror**, **wcserror**) ou formata uma cadeia de caracteres de mensagem de erro fornecida pelo usuário (**strError**, **wcserror**). Versões mais seguras dessas funções estão disponíveis; consulte [strerror_s, _strerror_s, _wcserror_s, \__wcserror_s](strerror-s-strerror-s-wcserror-s-wcserror-s.md).

## <a name="syntax"></a>Sintaxe

```C
char *strerror(
   int errnum
);
char *_strerror(
   const char *strErrMsg
);
wchar_t * _wcserror(
   int errnum
);
wchar_t * __wcserror(
   const wchar_t *strErrMsg
);
```

### <a name="parameters"></a>Parâmetros

*errnum*<br/>
Número do erro.

*strErrMsg*<br/>
Mensagem fornecida pelo usuário.

## <a name="return-value"></a>Valor de retorno

Todas essas funções retornam um ponteiro para a cadeia de caracteres de mensagens de erro. Chamadas subsequentes podem substituir a cadeia de caracteres.

## <a name="remarks"></a>Comentários

O **strerror** função mapas *errnum* para uma cadeia de caracteres de mensagem de erro e retorna um ponteiro para a cadeia de caracteres. Nem **strerror** nem **strError** realmente imprime a mensagem: para fazer isso, você precisa chamar uma função de saída como [fprintf](fprintf-fprintf-l-fwprintf-fwprintf-l.md):

```C
if (( _access( "datafile",2 )) == -1 )
   fprintf( stderr, _strerror(NULL) );
```

Se *strErrMsg* é passado como **nulo**, **strError** retorna um ponteiro para uma cadeia de caracteres que contém a mensagem de erro do sistema para a última chamada de biblioteca que produziu um erro. A cadeia de caracteres de mensagens de erro é encerrada pelo caractere newline ('\n'). Se *strErrMsg* não é igual a **nulo**, em seguida, **strError** retorna um ponteiro para uma cadeia de caracteres que contém (na ordem), a mensagem de cadeia de caracteres, um vírgula, um espaço, o erro do sistema mensagem para a última chamada de biblioteca que produz um erro e um caractere de nova linha. Sua mensagem da cadeia de caracteres pode ter, no máximo, 94 caracteres de comprimento.

O número de erro real **strError** é armazenado na variável [errno](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Para produzir resultados precisos, chame **strError** imediatamente depois que retorna uma rotina de biblioteca com um erro. Caso contrário, chamadas subsequentes para **strerror** ou **strError** pode substituir o **errno** valor.

**wcserror** e **wcserror** são versões de caractere largo de **strerror** e **strError**, respectivamente.

**strError**, **wcserror**, e **wcserror** não fazem parte da definição de ANSI; eles são extensões da Microsoft e é recomendável que você não usá-los onde você deseja que o código portátil. Para compatibilidade ANSI, use **strerror** em vez disso.

Para obter as cadeias de caracteres de erro, é recomendável **strerror** ou **wcserror** em vez de macros preteridas [sys_errlist](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) e [sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) e as funções internas preteridas **__sys_errlist** e **__sys_nerr**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tcserror**|**strerror**|**strerror**|**_wcserror**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strerror**|\<string.h>|
|**_strerror**|\<string.h>|
|**wcserror**, **wcserror**|\<string.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [perror](perror-wperror.md).

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[clearerr](clearerr.md)<br/>
[ferror](ferror.md)<br/>
[perror, _wperror](perror-wperror.md)<br/>
