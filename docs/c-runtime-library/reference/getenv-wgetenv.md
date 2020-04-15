---
title: getenv, _wgetenv
description: Descreve a biblioteca getenv e _wgetenv as funções de tempo de execução do Microsoft C.
ms.date: 4/2/2020
api_name:
- getenv
- _wgetenv
- _o__wgetenv
- _o_getenv
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
- _wgetenv
- getenv
- _tgetenv
helpviewer_keywords:
- getenv function
- tgetenv function
- wgetenv function
- environment values
- environment variables
- _tgetenv function
- _wgetenv function
ms.assetid: 3b9cb9ab-a126-4e0e-a44f-6c5a7134daf4
no-loc:
- getenv
- _wgetenv
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
ms.openlocfilehash: c9d7f7e1a2c5d6b15aee2f7f972a30cc0c90115c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81344247"
---
# <a name="getenv-_wgetenv"></a>getenv, _wgetenv

Obtém um valor do ambiente atual. Versões mais seguras dessas funções estão disponíveis; consulte [getenv_s, _wgetenv_s](getenv-s-wgetenv-s.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*Varname*<br/>
Nome da variável de ambiente.

## <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a entrada da tabela de ambiente contendo *varname*. Não é seguro modificar o valor da variável de ambiente usando o ponteiro retornado. Use a função [_putenv](putenv-wputenv.md) para modificar o valor de uma variável de ambiente. O valor de devolução é **NULO** se *o varname* não for encontrado na tabela de ambiente.

## <a name="remarks"></a>Comentários

A função **getenv** pesquisa a lista de variáveis de ambiente para *varname*. **getenv** não é sensível a casos no sistema operacional Windows. **getenv** e **_putenv** usam a cópia do ambiente apontada pela variável global **_environ** para acessar o ambiente. **A getenv** opera apenas nas estruturas de dados acessíveis à biblioteca de tempo de execução e não no ambiente "segmento" criado para o processo pelo sistema operacional. Portanto, programas que usam o argumento *envp* para [principal](../../cpp/main-function-command-line-args.md) ou [wmain](../../cpp/main-function-command-line-args.md) podem recuperar informações inválidas.

Se *o nome varname* for **NULL**, esta função invoca um manipulador de parâmetros inválido, conforme descrito na Validação [de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, esta função define **errno** para **EINVAL** e retorna **NULL**.

**_wgetenv** é uma versão de grande caráter de **getenv;** o argumento e o valor de retorno de **_wgetenv** são cadeias de caracteres de grande porte. A **_wenviron** variável global é uma versão ampla de **_environ**.

Em um programa MBCS (por exemplo, em um programa SBCS ASCII), **_wenviron** é inicialmente **NULA** porque o ambiente é composto de strings de caracteres multibytes. Em seguida, na primeira chamada para [_wputenv](putenv-wputenv.md), ou na primeira chamada para **_wgetenv** se um ambiente (MBCS) já existe, um ambiente de string de caracteres amplos correspondente é criado e, em seguida, é apontado por **_wenviron**.

Da mesma forma em um programa Unicode **(_wmain),** **_environ** é inicialmente **NULA** porque o ambiente é composto de strings de caracteres amplos. Em seguida, na primeira chamada para **_putenv**, ou na primeira chamada para **getenv** se um ambiente (Unicode) já existe, um ambiente MBCS correspondente é criado e, em seguida, é apontado por **_environ**.

Quando duas cópias do ambiente (MBCS e Unicode) existirem simultaneamente em um programa, o sistema de tempo de execução deverá manter as duas cópias, fazendo com que o tempo de execução fique mais lento. Por exemplo, sempre que você chamar **_putenv**, uma chamada para **_wputenv** também é executada automaticamente, de modo que as duas strings de ambiente correspondam.

> [!CAUTION]
> Em casos raros, quando o sistema de tempo de execução mantém uma versão Unicode e uma versão multibyte do ambiente, as duas versões de ambiente podem não corresponder exatamente. Isso acontece porque, embora qualquer cadeia de caracteres multibyte exclusiva seja mapeada para uma cadeia de caracteres Unicode exclusiva, o mapeamento de uma cadeia de caracteres Unicode exclusiva para uma cadeia de caracteres multibyte não é necessariamente exclusivo. Para obter mais informações, consulte [_environ, _wenviron](../../c-runtime-library/environ-wenviron.md).

> [!NOTE]
> As **_putenv** e **_getenv** famílias de funções não são seguras para fios. **_getenv** pode retornar um ponteiro de seqüência enquanto **_putenv** está modificando a seqüência, causando falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tgetenv**|**getenv**|**getenv**|**_wgetenv**|

Para verificar ou alterar o valor da variável ambiente **TZ,** use **getenv**, **_putenv** e **_tzset** conforme necessário. Para obter mais informações sobre **a TZ,** consulte [_tzset](tzset.md) e [_daylight, fuso horário e _tzname](../../c-runtime-library/daylight-dstbias-timezone-and-tzname.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**getenv**|\<stdlib.h>|
|**_wgetenv**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Confira também

[Controle de processos e ambientes](../../c-runtime-library/process-and-environment-control.md)<br/>
[_putenv, _wputenv](putenv-wputenv.md)<br/>
[Constantes ambientais](../../c-runtime-library/environmental-constants.md)<br/>
