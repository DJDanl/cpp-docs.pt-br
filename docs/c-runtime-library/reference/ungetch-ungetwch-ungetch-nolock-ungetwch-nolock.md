---
title: _ungetch, _ungetwch, _ungetch_nolock, _ungetwch_nolock
ms.date: 4/2/2020
api_name:
- _ungetch_nolock
- _ungetwch_nolock
- _ungetwch
- _ungetch
- _o__ungetch
- _o__ungetch_nolock
- _o__ungetwch
- _o__ungetwch_nolock
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _ungetch_nolock
- ungetwch
- ungetch_nolock
- _ungetwch
- ungetwch_nolock
- _ungetch
- _ungettch_nolock
- _ungettch
- _ungetwch_nolock
helpviewer_keywords:
- _ungetch function
- ungetwch function
- characters, pushing back to console
- _ungettch_nolock function
- ungettch function
- _ungettch function
- ungetch_nolock function
- ungettch_nolock function
- _ungetwch_nolock function
- _ungetch_nolock function
- ungetwch_nolock function
- _ungetwch function
ms.assetid: 70ae71c6-228c-4883-a57d-de6d5f873825
ms.openlocfilehash: 2a7b3b2a71b633eac64ad5ebc5203d70f31626ed
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82909297"
---
# <a name="_ungetch-_ungetwch-_ungetch_nolock-_ungetwch_nolock"></a>_ungetch, _ungetwch, _ungetch_nolock, _ungetwch_nolock

Envia de volta o último caractere que é lido do console.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _ungetch(
   int c
);
wint_t _ungetwch(
   wint_t c
);
int _ungetch_nolock(
   int c
);
wint_t _ungetwch_nolock(
   wint_t c
);
```

### <a name="parameters"></a>Parâmetros

*&*<br/>
O caractere a ser enviado.

## <a name="return-value"></a>Valor retornado

Ambas as funções retornam o caractere *c* se bem-sucedidas. Se houver um erro, **_ungetch** retornará um valor de **EOF** e **_ungetwch** retornará **WEOF**.

## <a name="remarks"></a>Comentários

Essas funções enviam o caractere *c* de volta para o console, fazendo com que *c* seja o próximo caractere lido por **_getch** ou **_getche** (ou **_getwch** ou **_getwche**). **_ungetch** e **_ungetwch** falham se forem chamados mais de uma vez antes da próxima leitura. O argumento *c* não pode ser **EOF** (ou **WEOF**).

As versões com o sufixo **_nolock** são idênticas, exceto pelo fato de não serem protegidas contra interferência de outros threads. Elas pode ser mais rápidas, pois não incorrem na sobrecarga de bloquear outros threads. Use estas funções apenas em contextos thread-safe, como aplicativos de thread único ou em que o escopo de chamada já trata do isolamento de threads.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_ungettch**|**_ungetch**|**_ungetch**|**_ungetwch**|
|**_ungettch_nolock**|**_ungetch_nolock**|**_ungetch_nolock**|**_ungetwch_nolock**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_ungetch**, **_ungetch_nolock**|\<conio.h>|
|**_ungetwch**, **_ungetwch_nolock**|\<conio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_ungetch.c
// compile with: /c
// In this program, a white-space delimited
// token is read from the keyboard. When the program
// encounters a delimiter, it uses _ungetch to replace
// the character in the keyboard buffer.
//

#include <conio.h>
#include <ctype.h>
#include <stdio.h>

int main( void )
{
   char buffer[100];
   int count = 0;
   int ch;

   ch = _getche();
   while( isspace( ch ) )      // Skip preceding white space.
      ch = _getche();
   while( count < 99 )         // Gather token.
   {
      if( isspace( ch ) )      // End of token.
         break;
      buffer[count++] = (char)ch;
      ch = _getche();
   }
   _ungetch( ch );            // Put back delimiter.
   buffer[count] = '\0';      // Null terminate the token.
   printf( "\ntoken = %s\n", buffer );
}
```

```Output

Whitetoken = White
```

## <a name="see-also"></a>Confira também

[E/s de porta e de console](../../c-runtime-library/console-and-port-i-o.md)<br/>
[_cscanf, _cscanf_l, _cwscanf, _cwscanf_l](cscanf-cscanf-l-cwscanf-cwscanf-l.md)<br/>
[_getch, _getwch](getch-getwch.md)<br/>
