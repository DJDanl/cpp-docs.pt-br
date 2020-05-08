---
title: _strtime_s, _wstrtime_s
ms.date: 4/2/2020
api_name:
- _wstrtime_s
- _strtime_s
- _o__strtime_s
- _o__wstrtime_s
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
- api-ms-win-crt-time-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _wstrtime_s
- strtime_s
- wstrtime_s
- _strtime_s
helpviewer_keywords:
- wstrtime_s function
- copying time to buffers
- strtime_s function
- _wstrtime_s function
- time, copying
- _strtime_s function
ms.assetid: 42acf013-c334-485d-b610-84c0af8a46ec
ms.openlocfilehash: 54828bf894ffc9062125c9680ec087cdf929b1a2
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82910933"
---
# <a name="_strtime_s-_wstrtime_s"></a>_strtime_s, _wstrtime_s

Copia a hora atual para um buffer. Estas são versões de [_strtime, _wstrtime](strtime-wstrtime.md) com melhorias de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _strtime_s(
   char *buffer,
   size_t numberOfElements
);
errno_t _wstrtime_s(
   wchar_t *buffer,
   size_t numberOfElements
);
template <size_t size>
errno_t _strtime_s(
   char (&buffer)[size]
); // C++ only
template <size_t size>
errno_t _wstrtime_s(
   wchar_t (&buffer)[size]
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*completo*<br/>
Um buffer de, pelo menos, 10 bytes de comprimento, no qual a hora será gravada.

*numberOfElements*<br/>
O tamanho do buffer.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido.

Se ocorrer uma condição de erro, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se houver uma falha, o valor retornado será um código de erro. Códigos de erro são definidos em ERRNO. H; consulte a tabela a seguir para os erros exatos gerados por esta função. Para obter mais informações sobre códigos de erro, consulte [Constantes errno](../../c-runtime-library/errno-constants.md).

### <a name="error-conditions"></a>Condições de erro

|*completo*|*numberOfElements*|Retorno|Conteúdo do *buffer*|
|--------------|------------------------|------------|--------------------------|
|**NULO**|(qualquer)|**EINVAL**|Não modificado|
|Não **nulo** (apontando para um buffer válido)|0|**EINVAL**|Não modificado|
|Não **nulo** (apontando para um buffer válido)|0 < tamanho < 9|**EINVAL**|cadeia de caracteres vazia|
|Não **nulo** (apontando para um buffer válido)|Tamanho > 9|0|Hora atual formatada conforme especificado nos comentários|

## <a name="security-issues"></a>Problemas de segurança

A passagem de um valor não**nulo** inválido para o buffer resultará em uma violação de acesso se o parâmetro *numberOfElements* for maior que 9.

Passar um valor para *numberOfElements* que seja maior que o tamanho real do buffer resultará em saturação do buffer.

## <a name="remarks"></a>Comentários

Essas funções fornecem versões mais seguras do [_strtime](strtime-wstrtime.md) e [_wstrtime](strtime-wstrtime.md). A função **_strtime_s** copia a hora local atual para o buffer apontado por *timestr*. O tempo é formatado como **hh: mm: SS** , em que **hh** é dois dígitos que representam a hora na notação de 24 horas, **mm** é dois dígitos que representam os minutos passados da hora e **SS** é dois dígitos que representam segundos. Por exemplo, a cadeia de caracteres **18:23:44** representa 23 minutos e 44 segundos das últimas 18:00 O buffer deve ter, pelo menos, 9 bytes; o tamanho real é especificado pelo segundo parâmetro.

**_wstrtime** é uma versão de caractere largo do **_strtime**; o argumento e o valor de retorno de **_wstrtime** são cadeias de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

As versões de biblioteca de depuração dessas funções primeiro preenchem o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mapping"></a>Mapeamento da Rotina de Texto Genérico:

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tstrtime_s**|**_strtime_s**|**_strtime_s**|**_wstrtime_s**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_strtime_s**|\<time.h>|
|**_wstrtime_s**|\<time.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// strtime_s.c

#include <time.h>
#include <stdio.h>

int main()
{
    char tmpbuf[9];
    errno_t err;

    // Set time zone from TZ environment variable. If TZ is not set,
    // the operating system is queried to obtain the default value
    // for the variable.
    //
    _tzset();

    // Display operating system-style date and time.
    err = _strtime_s( tmpbuf, 9 );
    if (err)
    {
       printf("_strdate_s failed due to an invalid argument.");
      exit(1);
    }
    printf( "OS time:\t\t\t\t%s\n", tmpbuf );
    err = _strdate_s( tmpbuf, 9 );
    if (err)
    {
       printf("_strdate_s failed due to an invalid argument.");
       exit(1);
    }
    printf( "OS date:\t\t\t\t%s\n", tmpbuf );

}
```

```Output
OS time:            14:37:49
OS date:            04/25/03
```

## <a name="see-also"></a>Confira também

[Gerenciamento de tempo](../../c-runtime-library/time-management.md)<br/>
[asctime_s, _wasctime_s](asctime-s-wasctime-s.md)<br/>
[ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s](ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)<br/>
[gmtime_s, _gmtime32_s, _gmtime64_s](gmtime-s-gmtime32-s-gmtime64-s.md)<br/>
[localtime_s, _localtime32_s, _localtime64_s](localtime-s-localtime32-s-localtime64-s.md)<br/>
[mktime, _mktime32, _mktime64](mktime-mktime32-mktime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
[_tzset](tzset.md)<br/>
