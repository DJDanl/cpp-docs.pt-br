---
title: memmove_s, wmemmove_s
ms.date: 4/2/2020
api_name:
- wmemmove_s
- memmove_s
- _o_wmemmove_s
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
- ntoskrnl.exe
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- wmemmove_s
- memmove_s
helpviewer_keywords:
- wmemmove_s function
- memmove_s function
ms.assetid: a17619e4-1307-4bb0-98c6-77f8c68dab2d
ms.openlocfilehash: baec33046f891f64c04adeccf21f41d3eec7b814
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81333149"
---
# <a name="memmove_s-wmemmove_s"></a>memmove_s, wmemmove_s

Move um buffer para outro. Estas são versões de [memmove, wmemmove](memmove-wmemmove.md) com aprimoramentos de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t memmove_s(
   void *dest,
   size_t numberOfElements,
   const void *src,
   size_t count
);
errno_t wmemmove_s(
   wchar_t *dest,
   size_t numberOfElements,
   const wchar_t *src,
   size_t count
);
```

### <a name="parameters"></a>Parâmetros

*dest*<br/>
Objeto de destino.

*Numberofelements*<br/>
Tamanho do buffer de destino.

*src*<br/>
Objeto de origem.

*contagem*<br/>
Número de bytes **(memmove_s)** ou caracteres **(wmemmove_s)** para copiar.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido ou um código de erro em caso de falha

### <a name="error-conditions"></a>Condições de erro

|*dest*|*Numberofelements*|*src*|Valor retornado|Conteúdo *de dest*|
|------------|------------------------|-----------|------------------|------------------------|
|**NULO**|any|any|**Einval**|não modificado|
|any|any|**NULO**|**Einval**|não modificado|
|any|< *Contar*|any|**ERANGE**|não modificado|

## <a name="remarks"></a>Comentários

Cópias *contam* bytes de caracteres *de src* a *dest*. Se algumas regiões da área de origem e do destino se sobreporem, **memmove_s** garante que os bytes originais de origem na região sobreposta sejam copiados antes de serem substituídos.

Se *dest* ou se *src* for um ponteiro nulo, ou se a seqüência de destino for muito pequena, essas funções invocam um manipulador de parâmetros inválido, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md) . Se a execução for permitida, essas funções retornam **eINVAL** e definem **errno** para **EINVAL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**memmove_s**|\<string.h>|
|**wmemmove_s**|\<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_memmove_s.c
//
// The program demonstrates the
// memmove_s function which works as expected
// for moving overlapping regions.

#include <stdio.h>
#include <string.h>

int main()
{
   char str[] = "0123456789";

   printf("Before: %s\n", str);

   // Move six bytes from the start of the string
   // to a new position shifted by one byte. To protect against
   // buffer overrun, the secure version of memmove requires the
   // the length of the destination string to be specified.

   memmove_s((str + 1), strnlen(str + 1, 10), str, 6);

   printf_s(" After: %s\n", str);
}
```

### <a name="output"></a>Saída

```Output
Before: 0123456789
After: 0012345789
```

## <a name="see-also"></a>Confira também

[Manipulação de buffer](../../c-runtime-library/buffer-manipulation.md)<br/>
[_memccpy](memccpy.md)<br/>
[memcpy, wmemcpy](memcpy-wmemcpy.md)<br/>
[strcpy_s, wcscpy_s, _mbscpy_s](strcpy-s-wcscpy-s-mbscpy-s.md)<br/>
[strcpy, wcscpy, _mbscpy](strcpy-wcscpy-mbscpy.md)<br/>
[strncpy_s, _strncpy_s_l, wcsncpy_s, _wcsncpy_s_l, _mbsncpy_s, _mbsncpy_s_l](strncpy-s-strncpy-s-l-wcsncpy-s-wcsncpy-s-l-mbsncpy-s-mbsncpy-s-l.md)<br/>
[strncpy, _strncpy_l, wcsncpy, _wcsncpy_l, _mbsncpy, _mbsncpy_l](strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l.md)<br/>
