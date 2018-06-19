---
title: getenv_s, _wgetenv_s | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- getenv_s
- _wgetenv_s
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
- api-ms-win-crt-environment-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- getenv_s
- _tgetenv_s
- _wgetenv_s
dev_langs:
- C++
helpviewer_keywords:
- _tgetenv_s function
- wgetenv_s function
- _wgetenv_s function
- getenv_s function
- environment variables
- tgetenv_s function
ms.assetid: c3ae1ffe-d4cd-4bae-bcb1-3afa754c613a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 144c8d1d05d40f17e37f337902bbd2ee2cf15458
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32405160"
---
# <a name="getenvs-wgetenvs"></a>getenv_s, _wgetenv_s

Obtém um valor do ambiente atual. Estas versões de [getenv, _wgetenv](getenv-wgetenv.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*pReturnValue*<br/>
O tamanho do buffer necessário ou 0 se a variável não for encontrada.

*buffer*<br/>
Buffer para armazenar o valor da variável de ambiente.

*numberOfElements*<br/>
Tamanho de *buffer*.

*varname*<br/>
Nome da variável de ambiente.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido; caso contrário, um código de erro em caso de falha.

### <a name="error-conditions"></a>Condições de Erro

|*pReturnValue*|*buffer*|*numberOfElements*|*varname*|Valor de retorno|
|--------------------|--------------|------------------------|---------------|------------------|
|**NULL**|qualquer|qualquer|qualquer|**EINVAL**|
|qualquer|**NULL**|>0|qualquer|**EINVAL**|
|qualquer|qualquer|qualquer|**NULL**|**EINVAL**|

Qualquer uma dessas condições de erro invoca um manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, as funções de conjunto **errno** para **EINVAL** e retornar **EINVAL**.

Além disso, se o buffer é muito pequeno, essas funções retornam **ERANGE**. Elas não invocam um manipulador de parâmetro inválido. Gravar o tamanho do buffer necessário em *pReturnValue*e assim habilitar programas chamar a função novamente com um buffer maior.

## <a name="remarks"></a>Comentários

O **getenv_s** função pesquisa a lista de variáveis de ambiente para *varname*. **getenv_s** não diferencia maiusculas de minúsculas no sistema operacional Windows. **getenv_s** e [putenv_s](putenv-s-wputenv-s.md) usar a cópia do ambiente que é apontada pela variável global **Environ** acessem o ambiente. **getenv_s** opera somente em estruturas de dados que são acessíveis para a biblioteca de tempo de execução e não no ambiente "segmento" que é criado para o processo pelo sistema operacional. Portanto, programas que usam o *envp* argumento [principal](../../cpp/main-program-startup.md) ou [wmain](../../cpp/main-program-startup.md) pode recuperar informações inválidas.

**wgetenv_s** é uma versão de caractere largo de **getenv_s**; o valor de retorno e de argumento de **wgetenv_s** são cadeias de caracteres do caractere largo. O **wenviron** variável global é uma versão de caractere largo de **Environ**.

Em um programa MBCS (por exemplo, em um programa de ASCII SBCS) **wenviron** é inicialmente **nulo** porque o ambiente é composto de cadeias de caracteres multibyte. Em seguida, na primeira chamada para [wputenv](putenv-wputenv.md), ou na primeira chamada para **wgetenv_s**, se já existir um ambiente (MBCS), um ambiente de cadeia de caracteres largos correspondente é criado e, em seguida, é apontado pelo **wenviron**.

Da mesma forma em Unicode (**_wmain**) programa, **Environ** é inicialmente **nulo** porque o ambiente é composto de cadeias de caracteres largos. Em seguida, na primeira chamada para [putenv](putenv-wputenv.md), ou na primeira chamada para **getenv_s** se já existir um ambiente (Unicode), um ambiente de MBCS correspondente é criado e, em seguida, é apontado pelo **_ ambiente**.

Quando duas cópias do ambiente (MBCS e Unicode) existirem simultaneamente em um programa, o sistema de tempo de execução deverá manter as duas cópias e isso faz com que o tempo de execução fique mais lento. Por exemplo, quando você chama **putenv**, uma chamada para **wputenv** também é executado automaticamente para que as cadeias de caracteres de dois ambiente correspondem.

> [!CAUTION]
> Em casos raros, quando o sistema de tempo de execução mantém uma versão Unicode e uma versão multibyte do ambiente, as duas versões de ambiente podem não corresponder exatamente. Isso acontece porque, embora qualquer cadeia de caracteres multibyte exclusiva seja mapeada para uma cadeia de caracteres Unicode exclusiva, o mapeamento de uma cadeia de caracteres Unicode exclusiva para uma cadeia de caracteres multibyte não é necessariamente exclusivo. Para obter mais informações, consulte [_environ, _wenviron](../../c-runtime-library/environ-wenviron.md).

> [!NOTE]
> O **putenv_s** e **_getenv_s** famílias de funções não são thread-safe. **_getenv_s** poderia retornar um ponteiro de cadeia de caracteres ao **putenv_s** está modificando a cadeia de caracteres e, assim, causar falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.

No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tgetenv_s**|**getenv_s**|**getenv_s**|**_wgetenv_s**|

Para verificar ou alterar o valor de **TZ** uso de variável de ambiente **getenv_s**, **putenv**, e **tzset**, conforme necessário. Para obter mais informações sobre **TZ**, consulte [tzset](tzset.md) e [Daylight, dstbias, TimeZone e tzname](../../c-runtime-library/daylight-dstbias-timezone-and-tzname.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**getenv_s**|\<stdlib.h>|
|**_wgetenv_s**|\<stdlib.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Constantes ambientais](../../c-runtime-library/environmental-constants.md)<br/>
[_putenv, _wputenv](putenv-wputenv.md)<br/>
[_dupenv_s, _wdupenv_s](dupenv-s-wdupenv-s.md)<br/>
