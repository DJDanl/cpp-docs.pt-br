---
title: _CrtSetDebugFillThreshold
description: Use a função _CrtSetDebugFillThreshold para definir a quantidade máxima de buffer para preencher as funções CRT seguras.
ms.date: 10/31/2019
api_name:
- _CrtSetDebugFillThreshold
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _CrtSetDebugFillThreshold
- CrtSetDebugFillThreshold
helpviewer_keywords:
- debug, buffer-filling behavior
- CrtSetDebugFillThreshold function
- _CrtSetDebugFillThreshold function
- buffer-filling behavior
- 0xFE
ms.assetid: 6cb360e8-56ae-4248-b17f-e28aee3e0ed7
ms.openlocfilehash: 3fdf6646603a59e8a7a2387600060ab3a3556b37
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73624390"
---
# <a name="_crtsetdebugfillthreshold"></a>_CrtSetDebugFillThreshold

Recupera ou modifica o limite controlando o comportamento de preenchimento de buffer nas funções de depuração.

## <a name="syntax"></a>Sintaxe

```C
size_t _CrtSetDebugFillThreshold( size_t newThreshold );
```

### <a name="parameters"></a>Parâmetros

*newThreshold*<br/>
Novo tamanho do limite em bytes.

## <a name="return-value"></a>Valor retornado

O valor do limite anterior.

## <a name="remarks"></a>Comentários

As versões de depuração de algumas funções CRT com segurança avançada preenchem o buffer passado para eles com um caractere especial (0xFE). Esse caractere de preenchimento ajuda a localizar casos em que o tamanho incorreto foi passado para a função. Infelizmente, isso também reduz o desempenho. Para melhorar o desempenho, use **_CrtSetDebugFillThreshold** para desabilitar o preenchimento de buffer para buffers maiores do que o limite de *newThreshold* . Um valor de *newThreshold* de 0 desabilita-o para todos os buffers.

O limite padrão é **SIZE_T_MAX**.

Veja a seguir uma lista das funções afetadas.

- [asctime_s, _wasctime_s](asctime-s-wasctime-s.md)

- [_cgets_s, _cgetws_s](cgets-s-cgetws-s.md)

- [ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s](ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)

- [_ecvt_s](ecvt-s.md)

- [_fcvt_s](fcvt-s.md)

- [_gcvt_s](gcvt-s.md)

- [_itoa_s, _ltoa_s, _ultoa_s, _i64toa_s, _ui64toa_s, _itow_s, _ltow_s, _ultow_s, _i64tow_s, _ui64tow_s](itoa-s-itow-s.md)

- [_makepath_s, _wmakepath_s](makepath-s-wmakepath-s.md)

- [_mbsnbcat_s, _mbsnbcat_s_l](mbsnbcat-s-mbsnbcat-s-l.md)

- [_mbsnbcpy_s, _mbsnbcpy_s_l](mbsnbcpy-s-mbsnbcpy-s-l.md)

- [_mbsnbset_s, _mbsnbset_s_l](mbsnbset-s-mbsnbset-s-l.md)

- [_mktemp_s, _wmktemp_s](makepath-s-wmakepath-s.md)

- [_splitpath_s, _wsplitpath_s](splitpath-s-wsplitpath-s.md)

- [strcat_s, wcscat_s, _mbscat_s](strcat-s-wcscat-s-mbscat-s.md)

- [strcpy_s, wcscpy_s, _mbscpy_s](strcpy-s-wcscpy-s-mbscpy-s.md)

- [_strdate_s, _wstrdate_s](strdate-s-wstrdate-s.md)

- [strerror_s, _strerror_s, _wcserror_s, \__wcserror_s](strerror-s-strerror-s-wcserror-s-wcserror-s.md)

- [_strlwr_s, _strlwr_s_l, _mbslwr_s, _mbslwr_s_l, _wcslwr_s, _wcslwr_s_l](strlwr-s-strlwr-s-l-mbslwr-s-mbslwr-s-l-wcslwr-s-wcslwr-s-l.md)

- [strncat_s, _strncat_s_l, wcsncat_s, _wcsncat_s_l, _mbsncat_s, _mbsncat_s_l](strncat-s-strncat-s-l-wcsncat-s-wcsncat-s-l-mbsncat-s-mbsncat-s-l.md)

- [strncpy_s, _strncpy_s_l, wcsncpy_s, _wcsncpy_s_l, _mbsncpy_s, _mbsncpy_s_l](strncpy-s-strncpy-s-l-wcsncpy-s-wcsncpy-s-l-mbsncpy-s-mbsncpy-s-l.md)

- [_strnset_s, _strnset_s_l, _wcsnset_s, _wcsnset_s_l, _mbsnset_s, _mbsnset_s_l](strnset-s-strnset-s-l-wcsnset-s-wcsnset-s-l-mbsnset-s-mbsnset-s-l.md)

- [_strset_s, _strset_s_l, _wcsset_s, _wcsset_s_l, _mbsset_s, _mbsset_s_l](strset-s-strset-s-l-wcsset-s-wcsset-s-l-mbsset-s-mbsset-s-l.md)

- [_strtime_s, _wstrtime_s](strtime-s-wstrtime-s.md)

- [_strupr_s, _strupr_s_l, _mbsupr_s, _mbsupr_s_l, _wcsupr_s, _wcsupr_s_l](strupr-s-strupr-s-l-mbsupr-s-mbsupr-s-l-wcsupr-s-wcsupr-s-l.md)

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtSetDebugFillThreshold**|\<crtdbg.h>|

Essa função é específica da Microsoft. Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Depurar versões somente das [bibliotecas de tempo de execução do C](../../c-runtime-library/crt-library-features.md) .

## <a name="example"></a>Exemplo

```C
// crt_crtsetdebugfillthreshold.c
// compile with: cl /MTd crt_crtsetdebugfillthreshold.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>

void Clear( char buff[], size_t size )
{
   for( int i=0; i<size; ++i )
      buff[i] = 0;
}

void Print( char buff[], size_t size )
{
   for( int i=0; i<size; ++i )
      printf( "%02x  %c\n", (unsigned char)buff[i], buff[i] );
}

int main( void )
{
   char buff[10];

   printf( "With buffer-filling on:\n" );
   strcpy_s( buff, _countof(buff), "howdy" );
   Print( buff, _countof(buff) );

   _CrtSetDebugFillThreshold( 0 );

   printf( "With buffer-filling off:\n" );
   Clear( buff, _countof(buff) );
   strcpy_s( buff, _countof(buff), "howdy" );
   Print( buff, _countof(buff) );
}
```

```Output
With buffer-filling on:
68  h
6f  o
77  w
64  d
79  y
00
fe  ■
fe  ■
fe  ■
fe  ■
With buffer-filling off:
68  h
6f  o
77  w
64  d
79  y
00
00
00
00
00
```

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
