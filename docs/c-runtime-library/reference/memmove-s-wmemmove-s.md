---
title: memmove_s, wmemmove_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
apitype: DLLExport
f1_keywords:
- wmemmove_s
- memmove_s
dev_langs:
- C++
helpviewer_keywords:
- wmemmove_s function
- memmove_s function
ms.assetid: a17619e4-1307-4bb0-98c6-77f8c68dab2d
caps.latest.revision: 26
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: ca9796f61ad5a3d65d0f421c27133cc2b458f588
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="memmoves-wmemmoves"></a>memmove_s, wmemmove_s
Move um buffer para outro. Estas são versões de [memmove, wmemmove](../../c-runtime-library/reference/memmove-wmemmove.md) com aprimoramentos de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `dest`  
 Objeto de destino.  
  
 `numberOfElements`  
 Tamanho do buffer de destino.  
  
 `src`  
 Objeto de origem.  
  
 `count`  
 O número de bytes (`memmove_s`) ou caracteres (`wmemmove_s`) a serem copiados.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido ou um código de erro em caso de falha  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`dest`|`numberOfElements`|`src`|Valor retornado|Conteúdo de `dest`|  
|------------|------------------------|-----------|------------------|------------------------|  
|`NULL`|qualquer|qualquer|`EINVAL`|não modificado|  
|qualquer|qualquer|`NULL`|`EINVAL`|não modificado|  
|qualquer|< `count`|qualquer|`ERANGE`|não modificado|  
  
## <a name="remarks"></a>Comentários  
 Cópias `count` bytes de caracteres de `src` para `dest`. Se algumas regiões da área de origem e do destino se sobrepõem, `memmove_s` garante que os bytes de origem originais na região sobreposta são copiados antes de serem substituídos.  
  
 Se `dest` ou `src` for um ponteiro nulo ou se a cadeia de caracteres de destino for pequena demais, essas funções invocarão um manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão `EINVAL` e definirão `errno` para `EINVAL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`memmove_s`|\<string.h>|  
|`wmemmove_s`|\<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
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
  
## <a name="output"></a>Saída  
  
```  
Before: 0123456789  
 After: 0012345789  
```  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de buffer](../../c-runtime-library/buffer-manipulation.md)   
 [_memccpy](../../c-runtime-library/reference/memccpy.md)   
 [memcpy, wmemcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md)   
 [strcpy_s, wcscpy_s, _mbscpy_s](../../c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s.md)   
 [strcpy, wcscpy, _mbscpy](../../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)   
 [strncpy_s, _strncpy_s_l, wcsncpy_s, _wcsncpy_s_l, _mbsncpy_s, _mbsncpy_s_l](../../c-runtime-library/reference/strncpy-s-strncpy-s-l-wcsncpy-s-wcsncpy-s-l-mbsncpy-s-mbsncpy-s-l.md)   
 [strncpy, _strncpy_l, wcsncpy, _wcsncpy_l, _mbsncpy, _mbsncpy_l](../../c-runtime-library/reference/strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l.md)
