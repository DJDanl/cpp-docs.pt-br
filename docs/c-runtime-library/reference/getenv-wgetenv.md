---
title: getenv, _wgetenv | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- getenv
- _wgetenv
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
- _wgetenv
- getenv
- _tgetenv
dev_langs:
- C++
helpviewer_keywords:
- getenv function
- tgetenv function
- wgetenv function
- environment values
- environment variables
- _tgetenv function
- _wgetenv function
ms.assetid: 3b9cb9ab-a126-4e0e-a44f-6c5a7134daf4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a2e68ca55d9e33995df583719e4797a6880d34ca
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="getenv-wgetenv"></a>getenv, _wgetenv

Obtém um valor do ambiente atual. Versões mais seguras dessas funções estão disponíveis; consulte [getenv_s, _wgetenv_s](getenv-s-wgetenv-s.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
char *getenv(
   const char *varname
);
wchar_t *_wgetenv(
   const wchar_t *varname
);
```

### <a name="parameters"></a>Parâmetros

*varname*<br/>
Nome da variável de ambiente.

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para a entrada de tabela de ambiente contendo *varname*. Não é seguro modificar o valor da variável de ambiente usando o ponteiro retornado. Use o [putenv](putenv-wputenv.md) função para modificar o valor de uma variável de ambiente. O valor de retorno é **nulo** se *varname* não foi encontrado na tabela de ambiente.

## <a name="remarks"></a>Comentários

O **getenv** função pesquisa a lista de variáveis de ambiente para *varname*. **GETENV** não diferencia maiusculas de minúsculas no sistema operacional Windows. **GETENV** e **putenv** usar a cópia do ambiente apontada pela variável global **Environ** acessem o ambiente. **GETENV** opera somente em estruturas de dados acessíveis para a biblioteca de tempo de execução e não no ambiente "segmento" criado para o processo pelo sistema operacional. Portanto, programas que usam o *envp* argumento [principal](../../cpp/main-program-startup.md) ou [wmain](../../cpp/main-program-startup.md) pode recuperar informações inválidas.

Se *varname* é **nulo**, esta função chama um manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, esta função define **errno** para **EINVAL** e retorna **nulo**.

**wgetenv** é uma versão de caractere largo de **getenv**; o valor de retorno e de argumento de **wgetenv** são cadeias de caracteres do caractere largo. O **wenviron** variável global é uma versão de caractere largo de **Environ**.

Em um programa MBCS (por exemplo, em um programa de ASCII SBCS) **wenviron** é inicialmente **nulo** porque o ambiente é composto de cadeias de caracteres multibyte. Em seguida, na primeira chamada para [wputenv](putenv-wputenv.md), ou na primeira chamada para **wgetenv** se já existir um ambiente (MBCS), um ambiente de cadeia de caracteres largos correspondente é criado e, em seguida, é apontado pelo **wenviron**.

Da mesma forma em Unicode (**_wmain**) programa, **Environ** é inicialmente **nulo** porque o ambiente é composto de cadeias de caracteres largos. Em seguida, na primeira chamada para **putenv**, ou na primeira chamada para **getenv** se já existir um ambiente (Unicode), um ambiente de MBCS correspondente é criado e, em seguida, é apontado pelo **_ ambiente**.

Quando duas cópias do ambiente (MBCS e Unicode) existirem simultaneamente em um programa, o sistema de tempo de execução deverá manter as duas cópias, fazendo com que o tempo de execução fique mais lento. Por exemplo, sempre que você chamar **putenv**, uma chamada para **wputenv** também é executado automaticamente, para que as cadeias de caracteres de dois ambiente correspondem.

> [!CAUTION]
> Em casos raros, quando o sistema de tempo de execução mantém uma versão Unicode e uma versão multibyte do ambiente, as duas versões de ambiente podem não corresponder exatamente. Isso acontece porque, embora qualquer cadeia de caracteres multibyte exclusiva seja mapeada para uma cadeia de caracteres Unicode exclusiva, o mapeamento de uma cadeia de caracteres Unicode exclusiva para uma cadeia de caracteres multibyte não é necessariamente exclusivo. Para obter mais informações, consulte [_environ, _wenviron](../../c-runtime-library/environ-wenviron.md).

> [!NOTE]
> O **putenv** e **_getenv** famílias de funções não são thread-safe. **_getenv** poderia retornar um ponteiro de cadeia de caracteres ao **putenv** está modificando a cadeia de caracteres, causando falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tgetenv**|**getenv**|**getenv**|**_wgetenv**|

Para verificar ou alterar o valor de **TZ** uso de variável de ambiente **getenv**, **putenv** e **tzset** conforme necessário. Para obter mais informações sobre **TZ**, consulte [tzset](tzset.md) e [Daylight, fuso horário e tzname](../../c-runtime-library/daylight-dstbias-timezone-and-tzname.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**getenv**|\<stdlib.h>|
|**_wgetenv**|\<stdlib.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_getenv.c
// compile with: /W3
// This program uses getenv to retrieve
// the LIB environment variable and then uses
// _putenv to change it to a new value.

#include <stdlib.h>
#include <stdio.h>

int main( void )
{
   char *libvar;

   // Get the value of the LIB environment variable.
   libvar = getenv( "LIB" ); // C4996
   // Note: getenv is deprecated; consider using getenv_s instead

   if( libvar != NULL )
      printf( "Original LIB variable is: %s\n", libvar );

   // Attempt to change path. Note that this only affects the environment
   // variable of the current process. The command processor's
   // environment is not changed.
   _putenv( "LIB=c:\\mylib;c:\\yourlib" ); // C4996
   // Note: _putenv is deprecated; consider using putenv_s instead

   // Get new value.
   libvar = getenv( "LIB" ); // C4996

   if( libvar != NULL )
      printf( "New LIB variable is: %s\n", libvar );
}
```

```Output
Original LIB variable is: C:\progra~1\devstu~1\vc\lib
New LIB variable is: c:\mylib;c:\yourlib
```

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[_putenv, _wputenv](putenv-wputenv.md)<br/>
[Constantes ambientais](../../c-runtime-library/environmental-constants.md)<br/>
