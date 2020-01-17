---
title: getenv, _wgetenv
description: Descreve a biblioteca de tempo de execução do Microsoft C getenv e as funções de _wgetenv.
ms.date: 01/15/2020
api_name:
- getenv
- _wgetenv
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
ms.openlocfilehash: 5e06e0c66d1ee60a067c2e27fedb5ca1dca7109a
ms.sourcegitcommit: e93f3e6a110fe38bc642055bdf4785e620d4220f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2020
ms.locfileid: "76123988"
---
# <a name="opno-locgetenv-opno-loc_wgetenv"></a>getenv, _wgetenv

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

*varname*<br/>
Nome da variável de ambiente.

## <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a entrada da tabela de ambiente que contém *VarName*. Não é seguro modificar o valor da variável de ambiente usando o ponteiro retornado. Use a função [_putenv](putenv-wputenv.md) para modificar o valor de uma variável de ambiente. O valor de retorno será **nulo** se *VarName* não for encontrado na tabela de ambiente.

## <a name="remarks"></a>Comentários

A função **getenv** pesquisa a lista de variáveis de ambiente para *VarName*. **getenv** não diferencia maiúsculas de minúsculas no sistema operacional Windows. **getenv** e **_putenv** usar a cópia do ambiente apontado pela variável global **_environ** para acessar o ambiente. **getenv** funciona apenas nas estruturas de dados acessíveis para a biblioteca de tempo de execução e não no ambiente "segmento" criado para o processo pelo sistema operacional. Portanto, os programas que usam o argumento *envp* para [main](../../cpp/main-function-command-line-args.md) ou [wmain](../../cpp/main-function-command-line-args.md) podem recuperar informações inválidas.

Se *VarName* for **NULL**, essa função invocará um manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função definirá **errno** como **EINVAL** e retornará **NULL**.

**_wgetenv** é uma versão de caractere largo do **getenv** ; o argumento e o valor de retorno de **_wgetenv** são cadeias de caracteres largos. A variável global **_wenviron** é uma versão de caractere largo do **_environ** .

Em um programa MBCS (por exemplo, em um programa SBCS ASCII), **_wenviron** é inicialmente **nulo** porque o ambiente é composto por cadeias de caracteres multibyte. Em seguida, na primeira chamada para [_wputenv](putenv-wputenv.md), ou na primeira chamada para **_wgetenv** se um ambiente (MBCS) já existir, um ambiente de cadeia de caracteres largo correspondente será criado e, em seguida, apontado por **_wenviron** .

Da mesma forma em um programa Unicode ( **_wmain**), o **_environ** é inicialmente **nulo** porque o ambiente é composto por cadeias de caracteres largos. Em seguida, na primeira chamada para **_putenv** , ou na primeira chamada para **getenv** se um ambiente (Unicode) já existir, um ambiente MBCS correspondente será criado e, em seguida, apontado por **_environ** .

Quando duas cópias do ambiente (MBCS e Unicode) existirem simultaneamente em um programa, o sistema de tempo de execução deverá manter as duas cópias, fazendo com que o tempo de execução fique mais lento. Por exemplo, sempre que você chama **_putenv** , uma chamada para **_wputenv** também é executada automaticamente, para que as duas cadeias de caracteres de ambiente correspondam.

> [!CAUTION]
> Em casos raros, quando o sistema de tempo de execução mantém uma versão Unicode e uma versão multibyte do ambiente, as duas versões de ambiente podem não corresponder exatamente. Isso acontece porque, embora qualquer cadeia de caracteres multibyte exclusiva seja mapeada para uma cadeia de caracteres Unicode exclusiva, o mapeamento de uma cadeia de caracteres Unicode exclusiva para uma cadeia de caracteres multibyte não é necessariamente exclusivo. Para obter mais informações, consulte [_environ, _wenviron](../../c-runtime-library/environ-wenviron.md).

> [!NOTE]
> As famílias de **_putenv** e **_getenv** de funções não são thread-safe. **_getenv** poderia retornar um ponteiro de cadeia de caracteres enquanto **_putenv** está modificando a cadeia de caracteres, causando falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tgetenv**|**getenv**|**getenv**|**_wgetenv**|

Para verificar ou alterar o valor da variável de ambiente do **TZ** , use **getenv** , **_putenv** e **_tzset** conforme necessário. Para obter mais informações sobre o **TZ**, consulte [_tzset](tzset.md) e [_daylight, fuso horário e _tzname](../../c-runtime-library/daylight-dstbias-timezone-and-tzname.md).

## <a name="requirements"></a>Requisitos do

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

## <a name="see-also"></a>Veja também

[Controle de processo e ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[_putenv, _wputenv](putenv-wputenv.md)<br/>
[Constantes ambientais](../../c-runtime-library/environmental-constants.md)<br/>
