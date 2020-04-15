---
title: getenv_s, _wgetenv_s
description: Descreve a biblioteca getenv_s e _wgetenv_s as funções de tempo de execução do Microsoft C.
ms.date: 4/2/2020
api_name:
- getenv_s
- _wgetenv_s
- _o__wgetenv_s
- _o_getenv_s
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
- api-ms-win-crt-environment-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- getenv_s
- _tgetenv_s
- _wgetenv_s
helpviewer_keywords:
- _tgetenv_s function
- wgetenv_s function
- _wgetenv_s function
- getenv_s function
- environment variables
- tgetenv_s function
ms.assetid: c3ae1ffe-d4cd-4bae-bcb1-3afa754c613a
no-loc:
- getenv_s
- _wgetenv_s
- _putenv_s
- main
- wmain
- errno
- EINVAL
- ERANGE
- _environ
- _wenviron
- _putenv
- _wputenv
- _tgetenv_s
- _tzset
- _dupenv_s
- _wdupenv_s
ms.openlocfilehash: 17c4e001f7f4637f6f66f218c94378368976901f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81344275"
---
# <a name="getenv_s-_wgetenv_s"></a>getenv_s, _wgetenv_s

Obtém um valor do ambiente atual. Estas versões de [getenv, _wgetenv](getenv-wgetenv.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t getenv_s(
   size_t *pReturnValue,
   char* buffer,
   size_t numberOfElements,
   const char *varname
);
errno_t _wgetenv_s(
   size_t *pReturnValue,
   wchar_t *buffer,
   size_t numberOfElements,
   const wchar_t *varname
);
template <size_t size>
errno_t getenv_s(
   size_t *pReturnValue,
   char (&buffer)[size],
   const char *varname
); // C++ only
template <size_t size>
errno_t _wgetenv_s(
   size_t *pReturnValue,
   wchar_t (&buffer)[size],
   const wchar_t *varname
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*Preturnvalue*<br/>
O tamanho do buffer necessário ou 0 se a variável não for encontrada.

*Buffer*<br/>
Buffer para armazenar o valor da variável de ambiente.

*Numberofelements*<br/>
Tamanho do *buffer*.

*Varname*<br/>
Nome da variável de ambiente.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido; caso contrário, um código de erro em caso de falha.

### <a name="error-conditions"></a>Condições de erro

|*Preturnvalue*|*Buffer*|*Numberofelements*|*Varname*|Valor retornado|
|--------------------|--------------|------------------------|---------------|------------------|
|**NULO**|any|any|any|**Einval**|
|any|**NULO**|>0|any|**Einval**|
|any|any|any|**NULO**|**Einval**|

Qualquer uma dessas condições de erro invoca um manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, as funções se configuram **para** **EINVAL** e retornam **EINVAL**.

Além disso, se o buffer for muito pequeno, essas funções retornam **ERANGE**. Elas não invocam um manipulador de parâmetro inválido. Eles escrevem o tamanho de buffer necessário no *pReturnValue*e, assim, permitem que os programas chamem a função novamente com um buffer maior.

## <a name="remarks"></a>Comentários

A **função getenv_s** pesquisa a lista de variáveis de ambiente para *varname*. **getenv_s** não é sensível a casos no sistema operacional Windows. **getenv_s** e [_putenv_s](putenv-s-wputenv-s.md) usam a cópia do ambiente apontada pela variável global **_environ** para acessar o ambiente. **getenv_s** opera apenas nas estruturas de dados acessíveis à biblioteca de tempo de execução e não no ambiente "segmento" criado para o processo pelo sistema operacional. Portanto, programas que usam o argumento *envp* para [principal](../../cpp/main-function-command-line-args.md) ou [wmain](../../cpp/main-function-command-line-args.md) podem recuperar informações inválidas.

**_wgetenv_s** é uma versão ampla de **getenv_s;** o argumento e o valor de retorno de **_wgetenv_s** são cadeias de caracteres amplos. A **_wenviron** variável global é uma versão ampla de **_environ**.

Em um programa MBCS (por exemplo, em um programa SBCS ASCII), **_wenviron** é inicialmente **NULA** porque o ambiente é composto de strings de caracteres multibytes. Em seguida, na primeira chamada para [_wputenv](putenv-wputenv.md), ou na primeira chamada para **_wgetenv_s**, se um ambiente (MBCS) já existe, um ambiente de string de caracteres amplocorrespondente é criado e, em seguida, é apontado por **_wenviron**.

Da mesma forma em um programa Unicode **(_wmain),** **_environ** é inicialmente **NULA** porque o ambiente é composto de strings de caracteres amplos. Em seguida, na primeira chamada para [_putenv](putenv-wputenv.md), ou na primeira chamada para **getenv_s** se um ambiente (Unicode) já existe, um ambiente MBCS correspondente é criado e, em seguida, é apontado por **_environ**.

Quando duas cópias do ambiente (MBCS e Unicode) existirem simultaneamente em um programa, o sistema de tempo de execução deverá manter as duas cópias e isso faz com que o tempo de execução fique mais lento. Por exemplo, quando você chama **_putenv**, uma chamada para **_wputenv** também é executada automaticamente para que as duas strings de ambiente correspondam.

> [!CAUTION]
> Em casos raros, quando o sistema de tempo de execução mantém uma versão Unicode e uma versão multibyte do ambiente, as duas versões de ambiente podem não corresponder exatamente. Isso acontece porque, embora qualquer cadeia de caracteres multibyte exclusiva seja mapeada para uma cadeia de caracteres Unicode exclusiva, o mapeamento de uma cadeia de caracteres Unicode exclusiva para uma cadeia de caracteres multibyte não é necessariamente exclusivo. Para obter mais informações, consulte [_environ, _wenviron](../../c-runtime-library/environ-wenviron.md).

> [!NOTE]
> As **_putenv_s** e **_getenv_s** famílias de funções não são seguras para fios. **_getenv_s** pode retornar um ponteiro de seqüência enquanto **_putenv_s** está modificando a seqüência e, assim, causar falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.

No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tgetenv_s**|**getenv_s**|**getenv_s**|**_wgetenv_s**|

Para verificar ou alterar o valor da variável ambiente **TZ,** use **getenv_s,** **_putenv**e **_tzset,** conforme necessário. Para obter mais informações sobre **a TZ,** consulte [_tzset](tzset.md) e [_daylight, _dstbias, _timezone e _tzname](../../c-runtime-library/daylight-dstbias-timezone-and-tzname.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**getenv_s**|\<stdlib.h>|
|**_wgetenv_s**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_getenv_s.c
// This program uses getenv_s to retrieve
// the LIB environment variable and then uses
// _putenv to change it to a new value.

#include <stdlib.h>
#include <stdio.h>

int main( void )
{
   char* libvar;
   size_t requiredSize;

   getenv_s( &requiredSize, NULL, 0, "LIB");
   if (requiredSize == 0)
   {
      printf("LIB doesn't exist!\n");
      exit(1);
   }

   libvar = (char*) malloc(requiredSize * sizeof(char));
   if (!libvar)
   {
      printf("Failed to allocate memory!\n");
      exit(1);
   }

   // Get the value of the LIB environment variable.
   getenv_s( &requiredSize, libvar, requiredSize, "LIB" );

   printf( "Original LIB variable is: %s\n", libvar );

   // Attempt to change path. Note that this only affects
   // the environment variable of the current process. The command
   // processor's environment is not changed.
   _putenv_s( "LIB", "c:\\mylib;c:\\yourlib" );

   getenv_s( &requiredSize, NULL, 0, "LIB");

   libvar = (char*) realloc(libvar, requiredSize * sizeof(char));
   if (!libvar)
   {
      printf("Failed to allocate memory!\n");
      exit(1);
   }

   // Get the new value of the LIB environment variable.
   getenv_s( &requiredSize, libvar, requiredSize, "LIB" );

   printf( "New LIB variable is: %s\n", libvar );

   free(libvar);
}
```

```Output
Original LIB variable is: c:\vctools\lib;c:\vctools\atlmfc\lib;c:\vctools\PlatformSDK\lib;c:\vctools\Visual Studio SDKs\DIA Sdk\lib;c:\vctools\Visual Studio SDKs\BSC Sdk\lib
New LIB variable is: c:\mylib;c:\yourlib
```

## <a name="see-also"></a>Confira também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Constantes ambientais](../../c-runtime-library/environmental-constants.md)<br/>
[_putenv, _wputenv](putenv-wputenv.md)<br/>
[_dupenv_s, _wdupenv_s](dupenv-s-wdupenv-s.md)<br/>
