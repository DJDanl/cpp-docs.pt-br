---
title: strerror, _strerror, _wcserror, __wcserror
description: Descreve as funções crt (Microsoft C Runtime Library, biblioteca de tempo de execução) do Microsoft C, _strerror, _wcserror e __wcserror.
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 9eecb7376cf476f0128dc20c8884746a3b4d47d9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81337325"
---
# <a name="strerror-_strerror-_wcserror-__wcserror"></a>strerror, _strerror, _wcserror, __wcserror

Obtém uma seqüência de mensagem de erro do sistema **(strerror**, **_wcserror)** ou formata uma seqüência de mensagens de erro fornecidapelo usuário **(_strerror**, **__wcserror**). Versões mais seguras dessas funções estão disponíveis; consulte [strerror_s, _strerror_s, _wcserror_s, \__wcserror_s](strerror-s-strerror-s-wcserror-s-wcserror-s.md).

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

Todas essas funções retornam um ponteiro para uma seqüência de mensagens de erro, em um buffer de armazenamento local de thread de propriedade do tempo de execução. Chamadas posteriores no mesmo segmento podem substituir essa seqüência.

## <a name="remarks"></a>Comentários

A função **strerror** *mapeia errnum* para uma seqüência de mensagens de erro e retorna um ponteiro para a seqüência. As funções **strerror** e **_strerror** não imprimem a mensagem. Para imprimir, chame uma função de saída como [fprintf](fprintf-fprintf-l-fwprintf-fwprintf-l.md):

```C
if (( _access( "datafile", 2 )) == -1 )
   fprintf( stderr, _strerror(NULL) );
```

Se *strErrMsg* for aprovado como **NULL,** **_strerror** retorna um ponteiro a uma seqüência. Ele contém a mensagem de erro do sistema para a última chamada da biblioteca que produziu um erro. A cadeia de caracteres de mensagens de erro é encerrada pelo caractere newline ('\n'). Quando *strErrMsg* não é **NULL**, a seqüência contém, em ordem: sua seqüência *strErrMsg,* um cólon, um espaço, a mensagem de erro do sistema e um caractere newline. Sua mensagem de seqüência pode ter, no máximo, 94 caracteres de comprimento, em caracteres estreitos **(_strerror)** ou largos **(__wcserror).**

O número de erro real para **_strerror** é armazenado na variável [errno](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Para produzir resultados precisos, ligue **_strerror** imediatamente após uma rotina de biblioteca retornar um erro. Caso contrário, chamadas posteriores para rotinas de biblioteca podem substituir o **valor errno.**

**_wcserror** e **__wcserror** são versões de amplo caráter de **strerror** e **_strerror,** respectivamente.

**_strerror**, **_wcserror**e **__wcserror** são específicos da Microsoft, não fazem parte da biblioteca Padrão C. Não recomendamos usá-los onde quiser código portátil. Para compatibilidade padrão C, use **strerror** em vez disso.

Para obter seqüências de erro, recomendamos **strerror** ou **_wcserror** em vez das macros depreciadas [_sys_errlist](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) e [_sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) e as funções internas depreciadas **__sys_errlist** e **__sys_nerr**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos de rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcserror**|**Strerror**|**Strerror**|**_wcserror**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**Strerror**|\<string.h>|
|**_strerror**|\<string.h>|
|**_wcserror**, **__wcserror**|\<string.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [perror](perror-wperror.md).

## <a name="see-also"></a>Confira também

[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md)\
[Clearerr](clearerr.md)\
[Ferror](ferror.md)\
[perror, _wperror](perror-wperror.md)
