---
title: _getch_nolock, _getwch_nolock
ms.date: 4/2/2020
api_name:
- _getwch_nolock
- _getch_nolock
- _o__getch_nolock
- _o__getwch_nolock
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
- api-ms-win-crt-conio-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _getch_nolock
- getwch_nolock
- getch_nolock
- _getwch_nolock
- _gettch_nolock
- gettch_nolock
helpviewer_keywords:
- characters, getting from console
- _getwch_nolock function
- _getch_nolock function
- getwch_nolock function
- _gettch_nolock function
- console, reading from
- getch_nolock function
- gettch_nolock function
ms.assetid: 9d248546-26ca-482c-b0c6-55812a987e83
ms.openlocfilehash: 4ba88ad86b6db892a581b9d94cb36f5ab8240c10
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81344702"
---
# <a name="_getch_nolock-_getwch_nolock"></a>_getch_nolock, _getwch_nolock

Obtém um caractere do console, sem eco e sem bloquear o thread.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _getch_nolock( void );
wint_t _getwch_nolock( void );
```

## <a name="return-value"></a>Valor retornado

Retorna o caractere lido. Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

**_getch_nolock** e **_getwch_nolock** são idênticos aos **_getch** e **_getchw** exceto que não estão protegidos contra interferências por outros segmentos. Elas podem ser mais rápidas, porque não incorrem na sobrecarga de bloquear outros threads. Use estas funções apenas em contextos thread-safe, como aplicativos de thread único ou em que o escopo de chamada já trata do isolamento de threads.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_gettch_nolock**|**_getch_nolock**|**_getch_nolock**|**_getwch_nolock**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_getch_nolock**|\<conio.h>|
|**_getwch_nolock**|\<conio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_getch_nolock.c
// compile with: /c
// This program reads characters from
// the keyboard until it receives a 'Y' or 'y'.

#include <conio.h>
#include <ctype.h>

int main( void )
{
   int ch;

   _cputs( "Type 'Y' when finished typing keys: " );
   do
   {
      ch = _getch_nolock();
      ch = toupper( ch );
   } while( ch != 'Y' );

   _putch_nolock( ch );
   _putch_nolock( '\r' );    // Carriage return
   _putch_nolock( '\n' );    // Line feed
}
```

```Input
abcdefy
```

```Output
Type 'Y' when finished typing keys: Y
```

## <a name="see-also"></a>Confira também

[Console e Porta I/O](../../c-runtime-library/console-and-port-i-o.md)<br/>
[_getche, _getwche](getche-getwche.md)<br/>
[_cgets, _cgetws](../../c-runtime-library/cgets-cgetws.md)<br/>
[getc, getwc](getc-getwc.md)<br/>
[_ungetch, _ungetwch, _ungetch_nolock, _ungetwch_nolock](ungetch-ungetwch-ungetch-nolock-ungetwch-nolock.md)<br/>
