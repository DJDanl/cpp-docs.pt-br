---
title: getenv_s, _wgetenv_s
description: Descreve a biblioteca getenv_s e _wgetenv_s as funções do Microsoft C Runtime.
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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 0713ed5735916c31edaab1a178a5e9b1b7cf5377
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82913676"
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

*preativar*<br/>
O tamanho do buffer necessário ou 0 se a variável não for encontrada.

*completo*<br/>
Buffer para armazenar o valor da variável de ambiente.

*numberOfElements*<br/>
Tamanho do *buffer*.

*varname*<br/>
Nome da variável de ambiente.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido; caso contrário, um código de erro em caso de falha.

### <a name="error-conditions"></a>Condições de erro

|*preativar*|*completo*|*numberOfElements*|*varname*|Valor retornado|
|--------------------|--------------|------------------------|---------------|------------------|
|**NULO**|any|any|any|**EINVAL**|
|any|**NULO**|>0|any|**EINVAL**|
|any|any|any|**NULO**|**EINVAL**|

Qualquer uma dessas condições de erro invoca um manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, as funções definirão **errno** como **EINVAL** e retornarão **EINVAL**.

Além disso, se o buffer for muito pequeno, essas funções retornarão **ERANGE**. Elas não invocam um manipulador de parâmetro inválido. Eles gravam o tamanho de buffer necessário em *preligávalue*e, portanto, permitem que os programas chamem a função novamente com um buffer maior.

## <a name="remarks"></a>Comentários

A função **getenv_s** pesquisa a lista de variáveis de ambiente para *VarName*. **getenv_s** não diferencia maiúsculas de minúsculas no sistema operacional Windows. **getenv_s** e [_putenv_s](putenv-s-wputenv-s.md) usar a cópia do ambiente apontado pela variável global **_environ** para acessar o ambiente. **getenv_s** funciona apenas nas estruturas de dados que são acessíveis para a biblioteca de tempo de execução e não no ambiente "Segment" criado para o processo pelo sistema operacional. Portanto, os programas que usam o argumento *envp* para [Main](../../cpp/main-function-command-line-args.md) ou [wmain](../../cpp/main-function-command-line-args.md) podem recuperar informações inválidas.

**_wgetenv_s** é uma versão de caractere largo do **getenv_s**; o argumento e o valor de retorno de **_wgetenv_s** são cadeias de caracteres largos. A variável global **_wenviron** é uma versão de caractere largo do **_environ**.

Em um programa MBCS (por exemplo, em um programa SBCS ASCII), **_wenviron** é inicialmente **nulo** porque o ambiente é composto por cadeias de caracteres multibyte. Em seguida, na primeira chamada para [_wputenv](putenv-wputenv.md), ou na primeira chamada para **_wgetenv_s**, se um ambiente (MBCS) já existir, um ambiente de cadeia de caracteres largo correspondente será criado e, em seguida, apontado por **_wenviron**.

Da mesma forma em um programa Unicode (**_wmain**), o **_Environ** é inicialmente **nulo** porque o ambiente é composto por cadeias de caracteres largos. Em seguida, na primeira chamada para [_putenv](putenv-wputenv.md), ou na primeira chamada para **getenv_s** se um ambiente (Unicode) já existir, um ambiente MBCS correspondente será criado e, em seguida, apontado por **_environ**.

Quando duas cópias do ambiente (MBCS e Unicode) existirem simultaneamente em um programa, o sistema de tempo de execução deverá manter as duas cópias e isso faz com que o tempo de execução fique mais lento. Por exemplo, quando você chama **_putenv**, uma chamada para **_wputenv** também é executada automaticamente para que as duas cadeias de caracteres de ambiente correspondam.

> [!CAUTION]
> Em casos raros, quando o sistema de tempo de execução mantém uma versão Unicode e uma versão multibyte do ambiente, as duas versões de ambiente podem não corresponder exatamente. Isso acontece porque, embora qualquer cadeia de caracteres multibyte exclusiva seja mapeada para uma cadeia de caracteres Unicode exclusiva, o mapeamento de uma cadeia de caracteres Unicode exclusiva para uma cadeia de caracteres multibyte não é necessariamente exclusivo. Para obter mais informações, consulte [_environ, _wenviron](../../c-runtime-library/environ-wenviron.md).

> [!NOTE]
> As famílias de **_putenv_s** e **_getenv_s** de funções não são thread-safe. **_getenv_s** poderia retornar um ponteiro de cadeia de caracteres enquanto **_putenv_s** estiver modificando a cadeia de caracteres e, portanto, causar falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.

No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tgetenv_s**|**getenv_s**|**getenv_s**|**_wgetenv_s**|

Para verificar ou alterar o valor da variável de ambiente do **TZ** , use **getenv_s**, **_putenv**e **_tzset**, conforme necessário. Para obter mais informações sobre o **TZ**, consulte [_tzset](tzset.md) e [_daylight, _dstbias, _timezone e _tzname](../../c-runtime-library/daylight-dstbias-timezone-and-tzname.md).

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
