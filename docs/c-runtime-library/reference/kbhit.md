---
title: _kbhit
ms.date: 11/04/2016
api_name:
- _kbhit
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
- api-ms-win-crt-stdio-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _kbhit
- conio/_kbhit
helpviewer_keywords:
- keyboard input
- user input, checking for keyboard
- kbhit function
- console
- console, checking
- keyboards, keyboard input
- _kbhit function
- keyboards, checking input
ms.assetid: e82a1cc9-bbec-4150-b678-a7e433220fe4
ms.openlocfilehash: 972b060dd98b5d267fa1f529c898573d4b82bb61
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79438097"
---
# <a name="_kbhit"></a>_kbhit

Verifica no console se há entradas de teclado.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C

int _kbhit( void );
```

## <a name="return-value"></a>Valor retornado

**_kbhit** retornará um valor diferente de zero se uma chave tiver sido pressionada. Caso contrário, retorna 0.

## <a name="remarks"></a>Comentários

A função **_kbhit** verifica o console para obter um pressionamento de tecla recente. Se a função retornar um valor diferente de zero, um pressionamento de tecla está aguardando no buffer. O programa pode então chamar **_getch** ou **_getche** para obter o pressionamento de teclas.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_kbhit**|\<conio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

```C
// crt_kbhit.c
// compile with: /c
/* This program loops until the user
* presses a key. If _kbhit returns nonzero, a
* keystroke is waiting in the buffer. The program
* can call _getch or _getche to get the keystroke.
*/

#include <conio.h>
#include <stdio.h>

int main( void )
{
   /* Display message until key is pressed. */
   while( !_kbhit() )
      _cputs( "Hit me!! " );

   /* Use _getch to throw key away. */
   printf( "\nKey struck was '%c'\n", _getch() );
}
```

### <a name="sample-output"></a>Saída de exemplo

```Output
Hit me!! Hit me!! Hit me!! Hit me!! Hit me!! Hit me!! Hit me!!
Key struck was 'q'
```

## <a name="see-also"></a>Consulte também

[E/S de porta e console](../../c-runtime-library/console-and-port-i-o.md)<br/>
