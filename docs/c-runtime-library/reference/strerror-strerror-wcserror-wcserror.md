---
title: strerror, _strerror, _wcserror, __wcserror
description: Descreve as funções do Microsoft C Runtime Library (CRT) strerror, _strerror, _wcserror e __wcserror.
ms.date: 4/2/2020
api_name:
- strerror
- _strerror
- _wcserror
- __wcserror
- _o___wcserror
- _o__strerror
- _o__wcserror
- _o_strerror
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
ms.openlocfilehash: 30885974b9c9fbf0fdca0e52808fb8bd1dfbaffe
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82920027"
---
# <a name="strerror-_strerror-_wcserror-__wcserror"></a>strerror, _strerror, _wcserror, __wcserror

Obtém uma cadeia de caracteres de mensagem de erro do sistema (**strerror**, **_wcserror**) ou formata uma cadeia de caracteres de mensagem de erro fornecida pelo usuário (**_strerror**, **__wcserror**). Versões mais seguras dessas funções estão disponíveis; consulte [strerror_s, _strerror_s, _wcserror_s, \__wcserror_s](strerror-s-strerror-s-wcserror-s-wcserror-s.md).

## <a name="syntax"></a>Sintaxe

```C
char * strerror(
   int errnum );

char * _strerror(
   const char *strErrMsg );

wchar_t * _wcserror(
   int errnum );

wchar_t * __wcserror(
   const wchar_t *strErrMsg );
```

### <a name="parameters"></a>Parâmetros

*errnum*\
Número de erro.

*strErrMsg*\
Mensagem fornecida pelo usuário.

## <a name="return-value"></a>Valor retornado

Todas essas funções retornam um ponteiro para uma cadeia de caracteres de mensagem de erro, em um buffer de armazenamento local de thread de Propriedade do tempo de execução. Chamadas posteriores no mesmo thread podem substituir essa cadeia de caracteres.

## <a name="remarks"></a>Comentários

A função **strerror** mapeia *errnum* para uma cadeia de caracteres de mensagem de erro e retorna um ponteiro para a cadeia de caracteres. As funções **strerror** e **_strerror** não imprimem realmente a mensagem. Para imprimir, chame uma função de saída como [fprintf](fprintf-fprintf-l-fwprintf-fwprintf-l.md):

```C
if (( _access( "datafile", 2 )) == -1 )
   fprintf( stderr, _strerror(NULL) );
```

Se *strErrMsg* for passado como **NULL**, **_strerror** retornará um ponteiro para uma cadeia de caracteres. Ele contém a mensagem de erro do sistema para a última chamada de biblioteca que produziu um erro. A cadeia de caracteres de mensagens de erro é encerrada pelo caractere newline ('\n'). Quando *strErrMsg* não é **nulo**, a cadeia de caracteres contém, em ordem: sua cadeia de caracteres *strErrMsg* , dois-pontos, um espaço, a mensagem de erro do sistema e um caractere de nova linha. Sua mensagem de cadeia de caracteres pode ter, no máximo, 94 caracteres de comprimento, em caracteres estreitos (**_strerror**) ou largos (**__wcserror**).

O número de erro real para **_strerror** é armazenado na variável [errno](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Para produzir resultados precisos, chame **_strerror** imediatamente depois que uma rotina de biblioteca retornar um erro. Caso contrário, chamadas posteriores para rotinas de biblioteca podem substituir o valor **errno** .

**_wcserror** e **__wcserror** são versões de caracteres largos de **strerror** e **_strerror**, respectivamente.

**_strerror**, **_wcserror**e **__wcserror** são específicos da Microsoft, não fazem parte da biblioteca C padrão. Não recomendamos que você os use onde desejar código portátil. Para compatibilidade com C padrão, use **strerror** em vez disso.

Para obter cadeias de caracteres de erro, recomendamos **strerror** ou **_wcserror** em vez das macros preteridas [_sys_errlist](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) e [_sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) e as funções internas preteridas **__sys_errlist** e **__sys_nerr**.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos de rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcserror**|**strerror**|**strerror**|**_wcserror**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strerror**|\<string.h>|
|**_strerror**|\<string.h>|
|**_wcserror**, **__wcserror**|\<string.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [perror](perror-wperror.md).

## <a name="see-also"></a>Consulte também

[Manipulação de cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)\
[clearerr](clearerr.md)\
[referenciador](ferror.md)\
[perror, _wperror](perror-wperror.md)
