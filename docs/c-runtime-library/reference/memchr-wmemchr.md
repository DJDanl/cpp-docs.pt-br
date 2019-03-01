---
title: memchr, wmemchr
ms.date: 11/04/2016
apiname:
- wmemchr
- memchr
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
- ntoskrnl.exe
apitype: DLLExport
f1_keywords:
- memchr
- wmemchr
helpviewer_keywords:
- memchr function
- wmemchr function
ms.assetid: 5a348581-28f1-4256-8434-687245f7fc9f
ms.openlocfilehash: cbd8b80ed42a6532fb7161fab7217a772a2cb777
ms.sourcegitcommit: e06648107065f3dea35f40c1ae5999391087b80b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/01/2019
ms.locfileid: "57209893"
---
# <a name="memchr-wmemchr"></a>memchr, wmemchr

Localize caracteres em um buffer.

## <a name="syntax"></a>Sintaxe

```C
void *memchr(
   const void *buffer,
   int c,
   size_t count
); // C only
void *memchr(
   void *buffer,
   int c,
   size_t count
); // C++ only
const void *memchr(
   const void *buffer,
   int c,
   size_t count
); // C++ only
wchar_t *wmemchr(
   const wchar_t * buffer,
   wchar_t c,
   size_t count
); // C only
wchar_t *wmemchr(
   wchar_t * buffer,
   wchar_t c,
   size_t count
); // C++ only
const wchar_t *wmemchr(
   const wchar_t * buffer,
   wchar_t c,
   size_t count
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*buffer*<br/>
Ponteiro para o buffer.

*c*<br/>
Caractere a ser procurado.

*count*<br/>
O número de caracteres a serem verificados.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retorna um ponteiro para o primeiro local da *c* na *buffer*. Caso contrário, ele retornará NULL.

## <a name="remarks"></a>Comentários

`memchr` e `wmemchr` procurar a primeira ocorrência do *c* no primeiro *contagem* bytes de *buffer*. Ele para quando encontra *c* ou quando tiver verificado os primeiros *contagem* bytes.

Em C, essas funções usam um **const** ponteiro para o primeiro argumento. No C++, duas sobrecargas estão disponíveis. A sobrecarga de colocar um ponteiro para **const** retorna um ponteiro para **const**; a versão que usa um ponteiro para não**const** retorna um ponteiro para não -**const** . _CRT_CONST_CORRECT_OVERLOADS a macro é definida se ambos os **const** e não-**const** versões dessas funções estão disponíveis. Se você precisar de não**const** comportamento para ambas as sobrecargas de C++ no C++, defina o símbolo const_return.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`memchr`|\<memory.h> ou \<string.h>|
|`wmemchr`|\<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_memchr.c

#include <memory.h>
#include <stdio.h>

int  ch = 'r';
char str[] =    "lazy";
char string[] = "The quick brown dog jumps over the lazy fox";
char fmt1[] =   "         1         2         3         4         5";
char fmt2[] =   "12345678901234567890123456789012345678901234567890";

int main( void )
{
   char *pdest;
   int result;
   printf( "String to be searched:\n             %s\n", string );
   printf( "             %s\n             %s\n\n", fmt1, fmt2 );

   printf( "Search char: %c\n", ch );
   pdest = memchr( string, ch, sizeof( string ) );
   result = (int)(pdest - string + 1);
   if ( pdest != NULL )
      printf( "Result:      %c found at position %d\n", ch, result );
   else
      printf( "Result:      %c not found\n" );
}
```

### <a name="output"></a>Saída

```Output
String to be searched:
             The quick brown dog jumps over the lazy fox
                      1         2         3         4         5
             12345678901234567890123456789012345678901234567890

Search char: r
Result:      r found at position 12
```

## <a name="see-also"></a>Consulte também

[Manipulação de buffer](../../c-runtime-library/buffer-manipulation.md)<br/>
[_memccpy](memccpy.md)<br/>
[memcmp, wmemcmp](memcmp-wmemcmp.md)<br/>
[memcpy, wmemcpy](memcpy-wmemcpy.md)<br/>
[memset, wmemset](memset-wmemset.md)<br/>
[strchr, wcschr, _mbschr, _mbschr_l](strchr-wcschr-mbschr-mbschr-l.md)<br/>
