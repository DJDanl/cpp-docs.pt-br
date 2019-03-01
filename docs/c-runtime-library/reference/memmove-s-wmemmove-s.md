---
title: memmove_s, wmemmove_s
ms.date: 11/04/2016
apiname:
- wmemmove_s
- memmove_s
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
- api-ms-win-crt-string-l1-1-0.dll
- ntoskrnl.exe
apitype: DLLExport
f1_keywords:
- wmemmove_s
- memmove_s
helpviewer_keywords:
- wmemmove_s function
- memmove_s function
ms.assetid: a17619e4-1307-4bb0-98c6-77f8c68dab2d
ms.openlocfilehash: 28d879a205790d1f132caca1022d0740e317c342
ms.sourcegitcommit: e06648107065f3dea35f40c1ae5999391087b80b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/01/2019
ms.locfileid: "57210595"
---
# <a name="memmoves-wmemmoves"></a>memmove_s, wmemmove_s

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

*numberOfElements*<br/>
Tamanho do buffer de destino.

*src*<br/>
Objeto de origem.

*count*<br/>
Número de bytes (**memmove_s**) ou caracteres (**wmemmove_s**) para copiar.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido ou um código de erro em caso de falha

### <a name="error-conditions"></a>Condições de Erro

|*dest*|*numberOfElements*|*src*|Valor retornado|Conteúdo de *dest*|
|------------|------------------------|-----------|------------------|------------------------|
|**NULL**|qualquer|qualquer|**EINVAL**|não modificado|
|qualquer|qualquer|**NULL**|**EINVAL**|não modificado|
|qualquer|< *count*|qualquer|**ERANGE**|não modificado|

## <a name="remarks"></a>Comentários

Cópias *contagem* bytes de caracteres de *src* para *dest*. Se algumas regiões da área de origem e o destino se sobrepõem, **memmove_s** garante que os bytes de origem originais na região sobreposta são copiados antes de serem substituídos.

Se *dest* ou se *src* for um ponteiro nulo ou se a cadeia de caracteres de destino for muito pequena, essas funções invocarão um manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md) . Se a execução puder continuar, essas funções retornarão **EINVAL** e defina **errno** para **EINVAL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**memmove_s**|\<string.h>|
|**wmemmove_s**|\<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[Manipulação de buffer](../../c-runtime-library/buffer-manipulation.md)<br/>
[_memccpy](memccpy.md)<br/>
[memcpy, wmemcpy](memcpy-wmemcpy.md)<br/>
[strcpy_s, wcscpy_s, _mbscpy_s](strcpy-s-wcscpy-s-mbscpy-s.md)<br/>
[strcpy, wcscpy, _mbscpy](strcpy-wcscpy-mbscpy.md)<br/>
[strncpy_s, _strncpy_s_l, wcsncpy_s, _wcsncpy_s_l, _mbsncpy_s, _mbsncpy_s_l](strncpy-s-strncpy-s-l-wcsncpy-s-wcsncpy-s-l-mbsncpy-s-mbsncpy-s-l.md)<br/>
[strncpy, _strncpy_l, wcsncpy, _wcsncpy_l, _mbsncpy, _mbsncpy_l](strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l.md)<br/>
