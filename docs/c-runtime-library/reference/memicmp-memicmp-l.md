---
title: _memicmp, _memicmp_l
ms.date: 11/04/2016
api_name:
- _memicmp_l
- _memicmp
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
- api-ms-win-crt-string-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _memicmp
- memicmp_l
- _memicmp_l
helpviewer_keywords:
- memicmp function
- _memicmp function
- memicmp_l function
- _memicmp_l function
ms.assetid: 0a6eb945-4077-4f84-935d-1aaebe8db8cb
ms.openlocfilehash: a463b9c79a76879311bb811b38e4aabcfd6e7226
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70951838"
---
# <a name="_memicmp-_memicmp_l"></a>_memicmp, _memicmp_l

Compara caracteres em dois buffers (não diferencia maiúsculas e minúsculas).

## <a name="syntax"></a>Sintaxe

```C
int _memicmp(
   const void *buffer1,
   const void *buffer2,
   size_t count
);
int _memicmp_l(
   const void *buffer1,
   const void *buffer2,
   size_t count,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*buffer1*<br/>
Primeiro buffer.

*buffer2*<br/>
Segundo buffer.

*count*<br/>
Número de caracteres.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

O valor retornado indica a relação entre os buffers.

|Valor retornado|Relação dos primeiros count caracteres de buf1 e buf2|
|------------------|--------------------------------------------------------|
|< 0|*buffer1* menor que *BUFFER2*.|
|0|*buffer1* idêntico a *BUFFER2*.|
|> 0|*buffer1* maior que *BUFFER2*.|
|**_NLSCMPERROR**|Ocorreu um erro.|

## <a name="remarks"></a>Comentários

A função **_memicmp** compara os primeiros caracteres de *contagem* dos dois buffers *buffer1* e *BUFFER2* byte por byte. A comparação não diferencia maiúsculas de minúsculas.

Se *buffer1* ou *BUFFER2* for um ponteiro nulo, essa função invocará um manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará **_NLSCMPERROR** e definirá **errno** como **EINVAL**.

**_memicmp** usa a localidade atual para comportamento dependente de localidade; **_memicmp_l** é idêntico, exceto pelo fato de que ele usa a localidade transmitida em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_memicmp**|\<memory.h> ou \<string.h>|
|**_memicmp_l**|\<memory.h> ou \<string.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_memicmp.c
// This program uses _memicmp to compare
// the first 29 letters of the strings named first and
// second without regard to the case of the letters.

#include <memory.h>
#include <stdio.h>
#include <string.h>

int main( void )
{
   int result;
   char first[] = "Those Who Will Not Learn from History";
   char second[] = "THOSE WHO WILL NOT LEARN FROM their mistakes";
   // Note that the 29th character is right here ^

   printf( "Compare '%.29s' to '%.29s'\n", first, second );
   result = _memicmp( first, second, 29 );
   if( result < 0 )
      printf( "First is less than second.\n" );
   else if( result == 0 )
      printf( "First is equal to second.\n" );
   else if( result > 0 )
      printf( "First is greater than second.\n" );
}
```

```Output
Compare 'Those Who Will Not Learn from' to 'THOSE WHO WILL NOT LEARN FROM'
First is equal to second.
```

## <a name="see-also"></a>Consulte também

[Manipulação de buffer](../../c-runtime-library/buffer-manipulation.md)<br/>
[_memccpy](memccpy.md)<br/>
[memchr, wmemchr](memchr-wmemchr.md)<br/>
[memcmp, wmemcmp](memcmp-wmemcmp.md)<br/>
[memcpy, wmemcpy](memcpy-wmemcpy.md)<br/>
[memset, wmemset](memset-wmemset.md)<br/>
[_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l](stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)<br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)<br/>
