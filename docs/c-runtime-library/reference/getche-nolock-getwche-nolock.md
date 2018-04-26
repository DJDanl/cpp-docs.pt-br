---
title: _getche_nolock, _getwche_nolock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _getche_nolock
- _getwche_nolock
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
apitype: DLLExport
f1_keywords:
- _getche_nolock
- _gettche_nolock
- _getwche_nolock
- getche_nolock
- getwche_nolock
- gettche_nolock
dev_langs:
- C++
helpviewer_keywords:
- characters, getting from console
- _gettche_nolock function
- getwche_nolock function
- _getche_nolock function
- getche_nolock function
- console, reading from
- _getwche_nolock function
- gettche_nolock function
ms.assetid: 9e853ad4-4d8a-4442-9ae5-da4b434f0b8c
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 38558969749533118277918fda6a5b03a11287dc
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="getchenolock-getwchenolock"></a>_getche_nolock, _getwche_nolock

Obtém um caractere do console, com o eco e sem bloquear o thread.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _getche_nolock( void );
wint_t _getwche_nolock( void );
```

## <a name="return-value"></a>Valor de retorno

Retorna o caractere lido. Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

**getche_nolock** e **getwche_nolock** são idênticos aos **getche** e **getwche** exceto que eles não protegidos contra interferência por outros threads. Elas podem ser mais rápidas, porque não incorrem na sobrecarga de bloquear outros threads. Use estas funções apenas em contextos thread-safe, como aplicativos de thread único ou em que o escopo de chamada já trata do isolamento de threads.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**gettche_nolock**|**_getche_nolock**|**_getch_nolock**|**_getwche_nolock**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_getche_nolock**|\<conio.h>|
|**_getwche_nolock**|\<conio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_getche_nolock.c
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
      ch = _getche_nolock();
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
Type 'Y' when finished typing keys: abcdefyY
```

## <a name="see-also"></a>Consulte também

[E/S de porta e console](../../c-runtime-library/console-and-port-i-o.md)<br/>
[_cgets, _cgetws](../../c-runtime-library/cgets-cgetws.md)<br/>
[getc, getwc](getc-getwc.md)<br/>
[_ungetch, _ungetwch, _ungetch_nolock, _ungetwch_nolock](ungetch-ungetwch-ungetch-nolock-ungetwch-nolock.md)<br/>
