---
title: memcmp, wmemcmp
ms.date: 11/04/2016
apiname:
- memcmp
- wmemcmp
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
- ntdll.dll
- ucrtbase.dll
- ntoskrnl.exe
apitype: DLLExport
f1_keywords:
- memcmp
- wmemcmp
helpviewer_keywords:
- wmemcmp function
- memcmp function
ms.assetid: 0c21c3e3-8ee4-40e5-add1-eb26d225fd8d
ms.openlocfilehash: 4feaa692ced7777d757b579c1b131b541dccea66
ms.sourcegitcommit: e06648107065f3dea35f40c1ae5999391087b80b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/01/2019
ms.locfileid: "57210231"
---
# <a name="memcmp-wmemcmp"></a>memcmp, wmemcmp

Compara caracteres em dois buffers.

## <a name="syntax"></a>Sintaxe

```C
int memcmp(
   const void *buffer1,
   const void *buffer2,
   size_t count
);
int wmemcmp(
   const wchar_t * buffer1,
   const wchar_t * buffer2,
   size_t count
);
```

### <a name="parameters"></a>Parâmetros

*buffer1*<br/>
Primeiro buffer.

*buffer2*<br/>
Segundo buffer.

*count*<br/>
O número de caracteres a serem comparados. (Compara bytes para **memcmp**, caracteres largos para **wmemcmp**).

## <a name="return-value"></a>Valor de retorno

O valor retornado indica a relação entre os buffers.

|Valor retornado|Relação dos primeiros *contagem* caracteres de buf1 e buf2|
|------------------|---------------------------------------------------------------|
|< 0|*buffer1* menor que *buffer2*|
|0|*buffer1* idêntico ao *buffer2*|
|> 0|*buffer1* maior que *buffer2*|

## <a name="remarks"></a>Comentários

Compara os primeiros *contagem* caracteres de *buffer1* e *buffer2* e retorna um valor que indica a relação. O sinal de um valor retornado diferente de zero é o sinal da diferença entre o primeiro par de valores diferentes nos buffers. Os valores são interpretados como **sem sinal** **char** para **memcmp**e como **wchar_t** para **wmemcmp**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**memcmp**|\<memory.h> ou \<string.h>|
|**wmemcmp**|\<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões da [biblioteca de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_memcmp.c
/* This program uses memcmp to compare
* the strings named first and second. If the first
* 19 bytes of the strings are equal, the program
* considers the strings to be equal.
*/

#include <string.h>
#include <stdio.h>

int main( void )
{
   char first[]  = "12345678901234567890";
   char second[] = "12345678901234567891";
   int int_arr1[] = {1,2,3,4};
   int int_arr2[] = {1,2,3,4};
   int result;

   printf( "Compare '%.19s' to '%.19s':\n", first, second );
   result = memcmp( first, second, 19 );
   if( result < 0 )
      printf( "First is less than second.\n" );
   else if( result == 0 )
      printf( "First is equal to second.\n" );
   else
      printf( "First is greater than second.\n" );

   printf( "Compare '%d,%d' to '%d,%d':\n", int_arr1[0], int_arr1[1], int_arr2[0], int_arr2[1]);
   result = memcmp( int_arr1, int_arr2, sizeof(int) * 2 );
   if( result < 0 )
      printf( "int_arr1 is less than int_arr2.\n" );
   else if( result == 0 )
      printf( "int_arr1 is equal to int_arr2.\n" );
   else
      printf( "int_arr1 is greater than int_arr2.\n" );
}
```

```Output
Compare '1234567890123456789' to '1234567890123456789':
First is equal to second.
Compare '1,2' to '1,2':
int_arr1 is equal to int_arr2.
```

## <a name="see-also"></a>Consulte também

[Manipulação de buffer](../../c-runtime-library/buffer-manipulation.md)<br/>
[_memccpy](memccpy.md)<br/>
[memchr, wmemchr](memchr-wmemchr.md)<br/>
[memcpy, wmemcpy](memcpy-wmemcpy.md)<br/>
[memset, wmemset](memset-wmemset.md)<br/>
[strcmp, wcscmp, _mbscmp](strcmp-wcscmp-mbscmp.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
