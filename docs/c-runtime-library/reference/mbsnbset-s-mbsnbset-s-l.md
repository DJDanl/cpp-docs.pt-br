---
title: "_mbsnbset_s, _mbsnbset_s_l | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_mbsnbset_s_l"
  - "_mbsnbset_s"
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
  - "api-ms-win-crt-multibyte-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "mbsnbset_s"
  - "_mbsnbset_s_l"
  - "_mbsnbset_s"
  - "mbsnbset_s_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbsnbset_s"
  - "Função _mbsnbset_s_l"
  - "Função _tcsnset_s"
  - "Função _tcsnset_s_l"
  - "Função mbsnbset_s"
  - "Função mbsnbset_s_l"
  - "Função tcsnset_s"
  - "Função tcsnset_s_l"
ms.assetid: 811f92c9-cc31-4bbd-8017-2d1bfc6fb96f
caps.latest.revision: 21
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mbsnbset_s, _mbsnbset_s_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define a primeira `n` bytes de uma seqüência de caracteres multibyte para um caractere especificado.  Essas versões do [\_mbsnbset, \_mbsnbset\_l](../../c-runtime-library/reference/mbsnbset-mbsnbset-l.md) tem aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
errno_t _mbsnbset_s(  
   unsigned char *str,  
   size_t size,  
   unsigned int c,  
   size_t count   
);  
errno_t _mbsnbset_s_l(  
   unsigned char *str,  
   size_t size,  
   unsigned int c,  
   size_t count,  
   _locale_t locale  
);  
template <size_t size>  
errno_t _mbsnbset_s(  
   unsigned char (&str)[size],  
   unsigned int c,  
   size_t count   
); // C++ only  
template <size_t size>  
errno_t _mbsnbset_s_l(  
   unsigned char (&str)[size],  
   unsigned int c,  
   size_t count,  
   _locale_t locale  
); // C++ only  
```  
  
#### Parâmetros  
 `str`  
 Cadeia de caracteres a ser alterada.  
  
 `size`  
 O tamanho do buffer da cadeia de caracteres.  
  
 `c`  
 Configuração de byte único ou caracteres multibyte.  
  
 `count`  
 Número de bytes a ser definido.  
  
 `locale`  
 Localidade a usar.  
  
## Valor de retorno  
 Zero se tiver êxito; Caso contrário, um código de erro.  
  
## Comentários  
 O `_mbsnbset_s` e `_mbsnbset_s_l` funções definir, no máximo, o primeiro `count` bytes de `str` para `c`.  Se `count` for maior que o comprimento de `str`, o comprimento de `str` é usado em vez de `count`.  Se `c` é um caractere multibyte e não pode ser definido inteiramente para o último byte especificado por `count`, o último byte é preenchido com um caractere em branco.  `_mbsnbset_s` e `_mbsnbset_s_l` não coloque uma terminação nula no final da `str`.  
  
 `_mbsnbset_s` e `_mbsnbset_s_l` lembram `_mbsnset`, exceto que eles definir `count` bytes em vez de `count` caracteres de `c`.  
  
 Se `str` é `NULL` ou `count` for zero, essa função gera uma exceção de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, `errno` é definido como `EINVAL` e a função retornará `NULL`.  Além disso, se `c` não é um caractere multibyte válido `errno` é definido como `EINVAL` e um espaço é usado em vez disso.  
  
 O valor de saída é afetado pela definição da configuração de categoria `LC_CTYPE` da localidade. Consulte [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md) para obter mais informações.  O `_mbsnbset_s` versão dessa função usa a localidade atual para esse comportamento depende da localidade; o `_mbsnbset_s_l` versão é idêntico, exceto que em vez disso, ele usa o parâmetro de localidade que é passado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Em C\+\+, uso dessas funções é simplificado pela sobrecargas de modelo; as sobrecargas podem inferir automaticamente o tamanho do buffer e eliminando a necessidade de especificar um argumento de tamanho.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
 As versões de depuração dessas funções primeiro preencher o buffer com 0xFD.  Para desabilitar esse comportamento, use [\_CrtSetDebugFillThreshold](../../c-runtime-library/reference/crtsetdebugfillthreshold.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tcsnset_s`|`_strnset_s`|`_mbsnbset_s`|`_wcsnset_s`|  
|`_tcsnset_s_l`|`_strnset_s _l`|`_mbsnbset_s_l`|`_wcsnset_s_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_mbsnbset_s`|\<mbstring.h\>|  
|`_mbsnbset_s_l`|\<mbstring.h\>|  
  
 Para obter mais informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_mbsnbset_s.c  
#include <mbstring.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char string[15] = "This is a test";  
   /* Set not more than 4 bytes of string to be *'s */  
   printf( "Before: %s\n", string );  
   _mbsnbset_s( string, sizeof(string), '*', 4 );  
   printf( "After:  %s\n", string );  
}  
```  
  
## Saída  
  **Antes: Este é um teste**  
**Depois: \* \* \* é um teste**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [\_mbsnbcat, \_mbsnbcat\_l](../../c-runtime-library/reference/mbsnbcat-mbsnbcat-l.md)   
 [\_strnset, \_strnset\_l, \_wcsnset, \_wcsnset\_l, \_mbsnset, \_mbsnset\_l](../../c-runtime-library/reference/strnset-strnset-l-wcsnset-wcsnset-l-mbsnset-mbsnset-l.md)   
 [\_strset, \_strset\_l, \_wcsset, \_wcsset\_l, \_mbsset, \_mbsset\_l](../../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)