---
title: "strstr, wcsstr, _mbsstr, _mbsstr_l | Microsoft Docs"
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
  - "_mbsstr"
  - "wcsstr"
  - "_mbsstr_l"
  - "strstr"
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
  - "_fstrstr"
  - "_ftcsstr"
  - "strstr"
  - "wcsstr"
  - "_mbsstr"
  - "_tcsstr"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _fstrstr"
  - "Função _ftcsstr"
  - "Função _mbsstr"
  - "Função _mbsstr_l"
  - "Função _tcsstr"
  - "Função fstrstr"
  - "Função ftcsstr"
  - "Função mbsstr"
  - "Função mbsstr_l"
  - "cadeias de caracteres [C++], procurando"
  - "Função strstr"
  - "subcadeias, localizando"
  - "Função tcsstr"
  - "Função wcsstr"
ms.assetid: 03d70c3f-2473-45cb-a5f8-b35beeb2748a
caps.latest.revision: 32
caps.handback.revision: 30
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strstr, wcsstr, _mbsstr, _mbsstr_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna um ponteiro para a primeira ocorrência de uma cadeia de caracteres de pesquisa em uma cadeia de caracteres.  
  
> [!IMPORTANT]
>  `_mbsstr` e `_mbsstr_l` não podem ser usados em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
char *strstr(  
   const char *str,  
   const char *strSearch   
); // C only  
char *strstr(  
   char *str,  
   const char *strSearch   
); // C++ only  
const char *strstr(  
   const char *str,  
   const char *strSearch   
); // C++ only  
wchar_t *wcsstr(  
   const wchar_t *str,  
   const wchar_t *strSearch   
); // C only  
wchar_t *wcsstr(  
   wchar_t *str,  
   const wchar_t *strSearch   
); // C++ only  
const wchar_t *wcsstr(  
   const wchar_t *str,  
   const wchar_t *strSearch   
); // C++ only  
unsigned char *_mbsstr(  
   const unsigned char *str,  
   const unsigned char *strSearch   
); // C only  
unsigned char *_mbsstr(  
   unsigned char *str,  
   const unsigned char *strSearch   
); // C++ only  
const unsigned char *_mbsstr(  
   const unsigned char *str,  
   const unsigned char *strSearch   
); // C++ only  
unsigned char *_mbsstr_l(  
   const unsigned char *str,  
   const unsigned char *strSearch,  
   _locale_t locale  
); // C only  
unsigned char *_mbsstr_l(  
   unsigned char *str,  
   const unsigned char *strSearch,  
   _locale_t locale  
); // C++ only  
const unsigned char *_mbsstr_l(  
   const unsigned char *str,  
   const unsigned char *strSearch,  
   _locale_t locale  
); // C++ only  
```  
  
#### Parâmetros  
 `str`  
 Cadeia de caracteres terminada com Null para pesquisa.  
  
 `strSearch`  
 Cadeia de caracteres com terminação nula para a procura por.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 Retorna um ponteiro para a primeira ocorrência de `strSearch` em `str`, ou `NULL` se `strSearch` não aparece em `str`.  Se os pontos de `strSearch` a uma cadeia de caracteres de comprimento zero, a função retorna `str`.  
  
## Comentários  
 A função de `strstr` retorna um ponteiro para a primeira ocorrência de `strSearch` em `str`.  A pesquisa não inclui o encerramento em caracteres nulos.  `wcsstr` é a versão de ampla caractere de `strstr` e `_mbsstr` é a versão de multibyte\- caractere.  Os argumentos e o valor de retorno de `wcsstr` são cadeias de caracteres largos; `_mbsstr` são cadeias de caracteres de vários bytes.  `_mbsstr` valida seus parâmetros.  Se `str` ou `strSearch` são `NULL`, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md) .  Se a execução puder continuar, `_mbsstr` definirá `errno` como `EINVAL` e retornará 0.  `strstr` e `wcsstr` não validam seus parâmetros.  Essas três funções se comportam de forma idêntica.  
  
> [!IMPORTANT]
>  Essas funções podem causar uma ameaça de um problema de excesso de buffer.  Os problemas de excesso de buffer podem ser usados para atacar um sistema porque podem permitir a execução do código arbitrário, o que pode causar uma despropositado elevação de privilégios.  Para obter mais informações, consulte [Evitando saturações de buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  
  
 No C, essas funções têm um ponteiro de `const` para o primeiro argumento.  No C\+\+, duas sobrecargas estão disponíveis.  A sobrecarga que usa um ponteiro para `const` retorna um ponteiro para `const`; a versão que usa um ponteiro para`const` não retorna um ponteiro para`const`não.  A macro \_CONST\_CORRECT\_OVERLOADS será definida se as versões `const` e não `const` dessas funções estiverem disponíveis.  Se você não exigir o comportamento não `const` para as duas sobrecargas de C\+\+, defina o símbolo \_CONST\_RETURN.  
  
 O valor de saída é afetado pela configuração de localidade categoria de `LC_CTYPE`; para obter mais informações, consulte [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md).  As versões dessas funções que não têm o uso do sufixo de `_l` a localidade atual para este comportamento dependente de localidade; as versões que têm o sufixo de `_l` são idênticas a não ser que usam em vez do parâmetro de localidade que é passado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcsstr`|`strstr`|`_mbsstr`|`wcsstr`|  
|**n\/d**|**n\/d**|`_mbsstr_l`|**n\/d**|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strstr`|\<string.h\>|  
|`wcsstr`|\<string.h\> ou \<wchar.h\>|  
|`_mbsstr`, `_mbsstr_l`|\<mbstring.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_strstr.c  
  
#include <string.h>  
#include <stdio.h>  
  
char str[] =    "lazy";  
char string[] = "The quick brown dog jumps over the lazy fox";  
char fmt1[] =   "         1         2         3         4         5";  
char fmt2[] =   "12345678901234567890123456789012345678901234567890";  
  
int main( void )  
{  
   char *pdest;  
   int  result;  
   printf( "String to be searched:\n   %s\n", string );  
   printf( "   %s\n   %s\n\n", fmt1, fmt2 );  
   pdest = strstr( string, str );  
   result = (int)(pdest - string + 1);  
   if ( pdest != NULL )  
      printf( "%s found at position %d\n", str, result );  
   else  
      printf( "%s not found\n", str );  
}  
```  
  
  **Cadeia de caracteres a ser pesquisada:**  
 **O ignora dog marrom rápido sobre a raposa lenta**  
 **1         2         3         4         5**  
 **12345678901234567890123456789012345678901234567890**  
**lazy localizado na posição 36**   
## Equivalência do .NET Framework  
 [System::String::IndexOf](https://msdn.microsoft.com/en-us/library/system.string.indexof.aspx)  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [strcspn, wcscspn, \_mbscspn, \_mbscspn\_l](../Topic/strcspn,%20wcscspn,%20_mbscspn,%20_mbscspn_l.md)   
 [strcmp, wcscmp, \_mbscmp](../Topic/strcmp,%20wcscmp,%20_mbscmp.md)   
 [strpbrk, wcspbrk, \_mbspbrk, \_mbspbrk\_l](../../c-runtime-library/reference/strpbrk-wcspbrk-mbspbrk-mbspbrk-l.md)   
 [strrchr, wcsrchr, \_mbsrchr, \_mbsrchr\_l](../../c-runtime-library/reference/strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)   
 [strspn, wcsspn, \_mbsspn, \_mbsspn\_l](../../c-runtime-library/reference/strspn-wcsspn-mbsspn-mbsspn-l.md)   
 [basic\_string::find](../Topic/basic_string::find.md)