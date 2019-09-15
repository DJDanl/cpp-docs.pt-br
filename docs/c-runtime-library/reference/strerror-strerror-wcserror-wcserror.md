---
title: strerror, _strerror, _wcserror, __wcserror
ms.date: 11/04/2016
api_name:
- strerror
- _strerror
- _wcserror
- __wcserror
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
- __sys_errlist
- wcserror
- _strerror
- __wcserror
- strerror
- __sys_nerr
- _tcserror
- _wcserror
- tcserror
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
ms.openlocfilehash: 0b4d70687bc2f428162d035c80d6bc8525a8fb9e
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70958140"
---
# <a name="strerror-_strerror-_wcserror-__wcserror"></a>strerror, _strerror, _wcserror, __wcserror

Obtém uma cadeia de caracteres de mensagem de erro do sistema (**strerror**, **_wcserror**) ou formata uma cadeia de caracteres de mensagem de erro fornecida pelo usuário ( **_strerror**, **__wcserror**). Versões mais seguras dessas funções estão disponíveis; consulte [strerror_s, _strerror_s, _wcserror_s, \__wcserror_s](strerror-s-strerror-s-wcserror-s-wcserror-s.md).

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

A função **strerror** mapeia *errnum* para uma cadeia de caracteres de mensagem de erro e retorna um ponteiro para a cadeia de caracteres. Nem **strerror** nem **_strerror** realmente imprime a mensagem: Para isso, você precisa chamar uma função de saída, como [fprintf](fprintf-fprintf-l-fwprintf-fwprintf-l.md):

```C
if (( _access( "datafile",2 )) == -1 )
   fprintf( stderr, _strerror(NULL) );
```

Se *strErrMsg* for passado como **NULL**, **_strerror** retornará um ponteiro para uma cadeia de caracteres que contém a mensagem de erro do sistema para a última chamada de biblioteca que produziu um erro. A cadeia de caracteres de mensagens de erro é encerrada pelo caractere newline ('\n'). Se *strErrMsg* não for igual a **NULL**, **_strerror** retornará um ponteiro para uma cadeia de caracteres que contenha (em ordem) sua mensagem de cadeia de caracteres, dois-pontos, um espaço, a mensagem de erro do sistema para a última chamada da biblioteca que produz um erro e uma nova linha espaço. Sua mensagem da cadeia de caracteres pode ter, no máximo, 94 caracteres de comprimento.

O número de erro real para **_strerror** é armazenado na variável [errno](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Para produzir resultados precisos, chame **_strerror** imediatamente após uma rotina de biblioteca retornar com um erro. Caso contrário, as chamadas subsequentes para **strerror** ou **_strerror** podem substituir o valor **errno** .

**_wcserror** e **__wcserror** são versões de caracteres largos de **strerror** e **_strerror**, respectivamente.

**_strerror**, **_wcserror**e **__wcserror** não fazem parte da definição de ANSI; Elas são extensões da Microsoft e recomendamos que você não as use onde desejar código portátil. Para compatibilidade com ANSI, use **strerror** em vez disso.

Para obter cadeias de caracteres de erro, recomendamos **strerror** ou **_wcserror** em vez das macros preteridas [_sys_errlist](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) e [_sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) e as funções internas preteridas **__sys_errlist** e **__sys_nerr**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcserror**|**strerror**|**strerror**|**_wcserror**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strerror**|\<string.h>|
|**_strerror**|\<string.h>|
|**_wcserror**, **__wcserror**|\<string.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [perror](perror-wperror.md).

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[clearerr](clearerr.md)<br/>
[ferror](ferror.md)<br/>
[perror, _wperror](perror-wperror.md)<br/>
