---
title: "memmove_s, wmemmove_s | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "wmemmove_s"
  - "memmove_s"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-string-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "wmemmove_s"
  - "memmove_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função memmove_s"
  - "Função wmemmove_s"
ms.assetid: a17619e4-1307-4bb0-98c6-77f8c68dab2d
caps.latest.revision: 26
caps.handback.revision: 26
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# memmove_s, wmemmove_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Move um buffer para outro.  Essas são as versões de [memmove, wmemmove](../../c-runtime-library/reference/memmove-wmemmove.md) com aprimoramentos de segurança, como descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `dest`  
 Objeto de destino.  
  
 `numberOfElements`  
 Tamanho do buffer de destino.  
  
 `src`  
 Objeto de origem.  
  
 `count`  
 Número de bytes \(`memmove_s`\) ou de caracteres \(`wmemmove_s`\) a serem copiados.  
  
## Valor de retorno  
 Zero se bem\-sucedido; um código de erro da falha  
  
### Condições de erro  
  
|`dest`|`numberOfElements`|`src`|Valor de retorno|Conteúdo de `dest`|  
|------------|------------------------|-----------|----------------------|------------------------|  
|`NULL`|any|any|`EINVAL`|não modificado|  
|any|any|`NULL`|`EINVAL`|não modificado|  
|any|\< `count`|any|`ERANGE`|não modificado|  
  
## Comentários  
 Copia bytes de `count` de caracteres de `src` a `dest`*.* Se algumas regiões da área de origem e de destino se sobrepõem, `memmove_s` assegura que os bytes de origem original na região sobreposta sejam copiados antes de ser substituído.  
  
 Se `dest` ou se `src` for um ponteiro nulo, ou se a cadeia de caracteres de destino for muito pequena, essas funções invoca um manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md) .  Se a execução puder continuar, essas funções retornarão `EINVAL` e definirão `errno` para `EINVAL`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`memmove_s`|\<string.h\>|  
|`wmemmove_s`|\<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
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
  
## Saída  
  
```  
Before: 0123456789  
 After: 0012345789  
```  
  
## Equivalência do .NET Framework  
 [System::Buffer::BlockCopy](https://msdn.microsoft.com/en-us/library/system.buffer.blockcopy.aspx)  
  
## Consulte também  
 [Manipulação de buffer](../Topic/Buffer%20Manipulation.md)   
 [\_memccpy](../../c-runtime-library/reference/memccpy.md)   
 [memcpy, wmemcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md)   
 [strcpy\_s, wcscpy\_s, \_mbscpy\_s](../../c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s.md)   
 [strcpy, wcscpy, \_mbscpy](../../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)   
 [strncpy\_s, \_strncpy\_s\_l, wcsncpy\_s, \_wcsncpy\_s\_l, \_mbsncpy\_s, \_mbsncpy\_s\_l](../Topic/strncpy_s,%20_strncpy_s_l,%20wcsncpy_s,%20_wcsncpy_s_l,%20_mbsncpy_s,%20_mbsncpy_s_l.md)   
 [strncpy, \_strncpy\_l, wcsncpy, \_wcsncpy\_l, \_mbsncpy, \_mbsncpy\_l](../../c-runtime-library/reference/strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l.md)