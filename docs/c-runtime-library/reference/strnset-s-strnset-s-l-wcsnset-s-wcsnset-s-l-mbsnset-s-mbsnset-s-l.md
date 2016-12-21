---
title: "_strnset_s, _strnset_s_l, _wcsnset_s, _wcsnset_s_l, _mbsnset_s, _mbsnset_s_l | Microsoft Docs"
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
  - "_mbsnset_s_l"
  - "_strnset_s"
  - "_mbsnset_s"
  - "_strnset_s_l"
  - "_wcsnset_s_l"
  - "_wcsnset_s"
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
  - "api-ms-win-crt-string-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_mbsnset_s_l"
  - "wcsnset_s"
  - "_tcsnset_s_l"
  - "_wcsnset_s"
  - "_mbsnset_s"
  - "_wcsnset_s_l"
  - "_strnset_s_l"
  - "strnset_s_l"
  - "_tcsnset_s"
  - "_strnset_s"
  - "strnset_s"
  - "mbsnset_s_l"
  - "mbsnset_s"
  - "wcsnset_s_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbsnset_s"
  - "Função _mbsnset_s_l"
  - "Função _strnset_s"
  - "Função _strnset_s_l"
  - "Função _tcsnset_s"
  - "Função _tcsnset_s_l"
  - "Função _wcsnset_s"
  - "inicializando caracteres"
  - "Função mbsnset_s"
  - "Função mbsnset_s_l"
  - "Função strnset_s"
  - "Função strnset_s_l"
  - "Função tcsnset_s"
  - "Função tcsnset_s_l"
  - "Função wcsnset_s"
ms.assetid: 9cf1b321-b5cb-4469-b285-4c07cfbd8813
caps.latest.revision: 27
caps.handback.revision: 25
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _strnset_s, _strnset_s_l, _wcsnset_s, _wcsnset_s_l, _mbsnset_s, _mbsnset_s_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Inicializa os caracteres de uma cadeia de caracteres para um determinado caractere.  Essas versões de [\_strnset, \_strnset\_l, \_wcsnset, \_wcsnset\_l, \_mbsnset, \_mbsnset\_l](../../c-runtime-library/reference/strnset-strnset-l-wcsnset-wcsnset-l-mbsnset-mbsnset-l.md) têm aprimoramentos de segurança, como descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
> [!IMPORTANT]
>  `_mbsnset_s` e `_mbsnset_s_l` não podem ser usados em aplicativos executados no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
errno_t _strnset_s(  
   char *str,  
   size_t numberOfElements,  
   int c,  
   size_t count   
);  
errno_t _strnset_s_l(  
   char *str,  
   size_t numberOfElements,  
   int c,  
   size_t count,  
   locale_t locale  
);  
errno_t _wcsnset_s(  
   wchar_t *str,  
   size_t numberOfElements,  
   wchar_t c,  
   size_t count   
);  
errno_t _wcsnset_s_l(  
   wchar_t *str,  
   size_t numberOfElements,  
   wchar_t c,  
   size_t count,  
   _locale_t locale  
);  
errno_t _mbsnset_s(  
   unsigned char *str,  
   size_t numberOfElements,  
   unsigned int c,  
   size_t count   
);  
errno_t _mbsnset_s_l(  
   unsigned char *str,  
   size_t numberOfElements,  
   unsigned int c,  
   size_t count,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `str`  
 Cadeia de caracteres a ser alterada.  
  
 `numberOfElements`  
 O tamanho do buffer `str`.  
  
 `c`  
 Configuração de caracteres.  
  
 `count`  
 Número de caracteres a serem definidos.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 Zero se tiver êxito, caso contrário, um código de erro.  
  
 Essas funções validam seus argumentos.  Se `str` não for uma cadeia de caracteres válida terminada em nulo ou o argumento de tamanho for menor ou igual a 0, o manipulador de parâmetro inválido á chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a exceção puder continuar, essas funções retornarão um código de erro e definirão `errno` como código de erro.  O código de erro padrão é `EINVAL` se um valor mais específico não se aplicar.  
  
## Comentários  
 Essas funções definem, no máximo, os primeiros caracteres `count` de `str` a `c`.  Se `count` for maior que o tamanho de `str`, o tamanho de `str` será usado no lugar de `count`.  Um erro ocorrerá se `count` for maior que `numberOfElements` e ambos os parâmetros forem maiores que o tamanho de `str`.  
  
 `_wcsnset_s` e `_mbsnset_s` são versões de caracteres largos e de multibyte de `_strnset_s`.  O argumento de cadeia de caracteres de `_wcsnset_s` é uma cadeia de caracteres largos; enquanto `_mbsnset_s` é uma `` cadeia de caracteres multibyte.  Essas três funções se comportam de forma idêntica.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` de localidade. Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  As versões dessas funções sem o sufixo `_l` usam a localidade atual para esse comportamento dependente da localidade; as versões com o sufixo`_l` são idênticas, exceto que elas usam o parâmetro de localidade informado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 As versões de depuração dessas funções preenchem primeiro o buffer com 0xFD.  Para desabilitar esse comportamento, use [\_CrtSetDebugFillThreshold](../../c-runtime-library/reference/crtsetdebugfillthreshold.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcsnset_s`|`_strnset_s`|`_mbsnbset_s`|`_wcsnset_s`|  
|`_tcsnset_s_l`|`_strnset_s_l`|`_mbsnbset_s_l`|`_wcsnset_s_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_strnset_s`|\<string.h\>|  
|`_strnset_s_l`|\<tchar.h\>|  
|`_wcsnset_s`|\<string.h\> ou \<wchar.h\>|  
|`_wcsnset_s_l`|\<tchar.h\>|  
|`_mbsnset_s`, `_mbsnset_s_l`|\<mbstring.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_strnset_s.c  
#include <string.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char string[15] = "This is a test";  
   /* Set not more than 4 characters of string to be *'s */  
   printf( "Before: %s\n", string );  
   _strnset_s( string, sizeof(string), '*', 4 );  
   printf( "After:  %s\n", string );  
}  
```  
  
  **Antes: este é um teste simples**  
**Em seguida:  \*\*\*\* é um teste**   
## Equivalência do .NET Framework  
 [System::String::Replace](https://msdn.microsoft.com/en-us/library/system.string.replace.aspx)  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [strcat, wcscat, \_mbscat](../../c-runtime-library/reference/strcat-wcscat-mbscat.md)   
 [strcmp, wcscmp, \_mbscmp](../Topic/strcmp,%20wcscmp,%20_mbscmp.md)   
 [strcpy, wcscpy, \_mbscpy](../../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)   
 [\_strset, \_strset\_l, \_wcsset, \_wcsset\_l, \_mbsset, \_mbsset\_l](../../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)