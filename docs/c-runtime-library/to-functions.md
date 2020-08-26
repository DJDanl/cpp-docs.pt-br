---
title: Funções to
ms.date: 11/04/2016
api_location:
- msvcr120.dll
- msvcr90.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr80.dll
- msvcr100.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- To
helpviewer_keywords:
- to functions
- string conversion, to different characters
- string conversion, case
- lowercase, converting strings
- uppercase, converting strings
- case, converting
- characters, converting
ms.assetid: f636a4c6-8c9f-4be2-baac-064f9dbae300
ms.openlocfilehash: a54f20d6ae4dead5ba7c606fd28d456e96ff31d6
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88836072"
---
# <a name="to-functions"></a>Funções to

Cada uma das funções **to** e sua macro associada, se houver, converte um único caractere em outro caractere.

[__toascii](../c-runtime-library/reference/toascii-toascii.md)\
[ToLower, _tolower, towlower](../c-runtime-library/reference/tolower-tolower-towlower-tolower-l-towlower-l.md)\
[toupper, _toupper, towupper](../c-runtime-library/reference/toupper-toupper-towupper-toupper-l-towupper-l.md)

## <a name="remarks"></a>Comentários

As funções **to** e as conversões de macro são as seguintes.

|Rotina|Macro|Descrição|
|-------------|-----------|-----------------|
|`__toascii`|`__toascii`|Converte `c` em caractere ASCII|
|`tolower`|`tolower`|Converte `c` em minúscula, se apropriado|
|`_tolower`|`_tolower`|Converte `c` em minúscula|
|`towlower`|Nenhum|Converte `c` em letra minúscula de caractere largo correspondente|
|`toupper`|`toupper`|Converte `c` em maiúscula, se apropriado|
|`_toupper`|`_toupper`|Converte `c` em maiúscula|
|`towupper`|Nenhum|Converte c em letra maiúscula de caractere largo correspondente|

Para usar as versões de função das rotinas **to** que também são definidas como macros, remova as definições de macro com diretivas `#undef` ou não inclua CTYPE. H. Se você usar a opção do compilador /Za, o compilador usará a versão da função `toupper` ou `tolower`. As declarações das funções `toupper` e `tolower` estão em STDLIB. H.

A rotina `__toascii` define todos, exceto os 7 bits de ordem inferior de `c` a 0, de forma que o valor convertido represente um caractere no conjunto de caracteres ASCII. Se `c` já representar um caractere ASCII, `c` permanecerá inalterado.

As rotinas `tolower` e `toupper`:

- Dependem da categoria `LC_CTYPE` da localidade atual (`tolower` chama `isupper` e `toupper` chama `islower`).

- Convertem `c` se `c` representar uma letra conversível do caso apropriado na localidade atual e se o caso oposto existir para essa localidade. Caso contrário, `c` permanecerá inalterado.

As rotinas `_tolower` e `_toupper`:

- São versões muito mais rápidas, independentes de localidade, de `tolower` e **toupper.**

- Pode ser usado somente quando **isascii (** `c` **)** e **IsUpper (** `c` **)** ou **islow (** `c` **)**, respectivamente, são diferentes de zero.

- Terão resultados indefinidos se `c` não for uma letra ASCII do caso apropriado para conversão.

As funções `towlower` e `towupper` retornarão uma cópia convertida de `c` se ambas as seguintes condições forem diferentes de zero. Caso contrário, `c` permanecerá inalterado.

- `c` é um caractere largo do caso apropriado (ou seja, para o qual `iswupper` ou **iswlower,** respectivamente, é diferente de zero).

- Há um caractere largo correspondente do caso de destino (ou seja, para o qual `iswlower` ou **iswupper,** respectivamente, é diferente de zero).

## <a name="example"></a>Exemplo

```c
// crt_toupper.c
/* This program uses toupper and tolower to
 * analyze all characters between 0x0 and 0x7F. It also
 * applies _toupper and _tolower to any code in this
 * range for which these functions make sense.
 */

#include <ctype.h>
#include <string.h>

char msg[] = "Some of THESE letters are Capitals.";
char *p;

int main( void )
{
   printf( "%s\n", msg );

   /* Reverse case of message. */
   for( p = msg; p < msg + strlen( msg ); p++ )
   {
      if( islower( *p ) )
         putchar( _toupper( *p ) );
      else if( isupper( *p ) )
         putchar( _tolower( *p ) );
      else
         putchar( *p );
   }
}
```

```Output
Some of THESE letters are Capitals.
sOME OF these LETTERS ARE cAPITALS.
```

## <a name="see-also"></a>Confira também

[Conversão de Dados](../c-runtime-library/data-conversion.md)<br/>
[Localidade](../c-runtime-library/locale.md)<br/>
[é, rotinas de isw](../c-runtime-library/is-isw-routines.md)
