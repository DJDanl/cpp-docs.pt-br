---
title: "strpbrk, wcspbrk, _mbspbrk, _mbspbrk_l | Microsoft Docs"
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
  - "_mbspbrk"
  - "wcspbrk"
  - "_mbspbrk_l"
  - "strpbrk"
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
  - "_fstrpbrk"
  - "_mbspbrk"
  - "strpbrk"
  - "_tcspbrk"
  - "_ftcspbrk"
  - "wcspbrk"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _fstrpbrk"
  - "Função _ftcspbrk"
  - "Função _mbspbrk"
  - "Função _mbspbrk_l"
  - "Função _tcspbrk"
  - "conjunto de caracteres [C++], verificando os caracteres nas cadeias de caracteres"
  - "caracteres [C++], verificando cadeias de caracteres"
  - "Função fstrpbrk"
  - "Função ftcspbrk"
  - "Função mbspbrk"
  - "Função mbspbrk_l"
  - "cadeias de caracteres [C++], verificando"
  - "Função strpbrk"
  - "Função tcspbrk"
  - "Função wcspbrk"
ms.assetid: 80b504f7-a167-4dde-97ad-4ae3000dc810
caps.latest.revision: 30
caps.handback.revision: 28
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strpbrk, wcspbrk, _mbspbrk, _mbspbrk_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Procura caracteres em conjuntos de caracteres especificados da cadeia de caracteres.  
  
> [!IMPORTANT]
>  `_mbspbrk` e `_mbspbrk_l` não podem ser usados em aplicativos executados no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
char *strpbrk(  
   const char *str,  
   const char *strCharSet   
); // C only  
char *strpbrk(  
   char *str,  
   const char *strCharSet   
); // C++ only  
const char *strpbrk(  
   const char *str,  
   const char *strCharSet   
); // C++ only  
wchar_t *wcspbrk(  
   const wchar_t *str,  
   const wchar_t *strCharSet   
); // C only  
wchar_t *wcspbrk(  
   wchar_t *str,  
   const wchar_t *strCharSet   
); // C++ only  
const wchar_t *wcspbrk(  
   const wchar_t *str,  
   const wchar_t *strCharSet   
); // C++ only  
unsigned char *_mbspbrk(  
   const unsigned char *str,  
   const unsigned char *strCharSet   
); // C only  
unsigned char *_mbspbrk(  
   unsigned char *str,  
   const unsigned char *strCharSet   
); // C++ only  
const unsigned char *_mbspbrk(  
   const unsigned char *str,  
   const unsigned char *strCharSet   
); // C++ only  
unsigned char *_mbspbrk_l(  
   const unsigned char *str,  
   const unsigned char *strCharSet,  
   _locale_t locale  
); // C only  
unsigned char *_mbspbrk_l(  
   unsigned char *str,  
   const unsigned char *strCharSet,  
   _locale_t locale  
); // C++ only  
const unsigned char *_mbspbrk_l(  
   const unsigned char *str,  
   const unsigned char* strCharSet,  
   _locale_t locale  
); // C++ only  
```  
  
#### Parâmetros  
 `str`  
 Cadeia de caracteres pesquisada terminada com Null.  
  
 `strCharSet`  
 Conjunto de caracteres terminados em nulo.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 Retorna um ponteiro para a primeira ocorrência de qualquer caractere de `strCharSet` em `str` ou um ponteiro `NULL` se os dois argumentos da cadeia de caracteres não tiverem caracteres em comum.  
  
## Comentários  
 A função `strpbrk` retorna um ponteiro para a primeira ocorrência de um caractere em `str` que pertence ao conjunto de caracteres em `strCharSet`.  A pesquisa não inclui o encerramento em caractere nulo.  
  
 `wcspbrk` e `_mbspbrk` são versões de caracteres largos e de multibyte de `strpbrk`.  Os argumentos e o valor de retorno de `wcspbrk` são cadeias de caracteres largos; `_mbspbrk` são cadeias de caracteres de vários bytes.  
  
 `_mbspbrk` valida seus parâmetros.  Se `str` ou `strCharSet` for `NULL`, o manipulador de parâmetro inválido será chamado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar,`_mbspbrk` retornará `NULL` e definirá `errno` como `EINVAL`.  `strpbrk` e `wcspbrk` não validam seus parâmetros.  Essas três funções se comportam de forma idêntica.  
  
 `_mbspbrk` é semelhante a `_mbscspn` exceto que `_mbspbrk` retorna um um ponteiro em vez de um valor do tipo [size\_t](../../c-runtime-library/standard-types.md).  
  
 No C, essas funções têm um ponteiro de `const` para o primeiro argumento.  No C\+\+, duas sobrecargas estão disponíveis.  A sobrecarga que usa um ponteiro para `const` retorna um ponteiro para `const`; a versão que usa um ponteiro para não `const` retorna um ponteiro para não `const`.  A macro \_CONST\_CORRECT\_OVERLOADS será definida se as versões `const` e não `const` dessas funções estiverem disponíveis.  Se você não exigir o comportamento não `const` para as duas sobrecargas de C\+\+, defina o símbolo \_CONST\_RETURN.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` de localidade. Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  As versões dessas funções sem o sufixo `_l` usam a localidade atual para esse comportamento dependente da localidade; a versão com o sufixo `_l` é idêntica, exceto aquela que usa o parâmetro de localidade informado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcspbrk`|`strpbrk`|`_mbspbrk`|`wcspbrk`|  
|**n\/d**|**n\/d**|`_mbspbrk_l`|**n\/d**|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strpbrk`|\<string.h\>|  
|`wcspbrk`|\<string.h\> ou \<wchar.h\>|  
|`_mbspbrk`, `_mbspbrk_l`|\<mbstring.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_strpbrk.c  
  
#include <string.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char string[100] = "The 3 men and 2 boys ate 5 pigs\n";  
   char *result = NULL;  
  
   // Return pointer to first digit in "string".  
   printf( "1: %s\n", string );  
   result = strpbrk( string, "0123456789" );  
   printf( "2: %s\n", result++ );  
   result = strpbrk( result, "0123456789" );  
   printf( "3: %s\n", result++ );  
   result = strpbrk( result, "0123456789" );  
   printf( "4: %s\n", result );  
}  
```  
  
  **1: Os 3 homens e os 2 meninos comeram 5 porcos**  
**2: 3 homens e 2 meninos comeram 5 porcos**  
**3: 2 meninos comeram 5 porcos**  
**4: 5 porcos**   
## Equivalência do .NET Framework  
 [System::String::IndexOfAny](https://msdn.microsoft.com/en-us/library/system.string.indexofany.aspx)  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [strcspn, wcscspn, \_mbscspn, \_mbscspn\_l](../Topic/strcspn,%20wcscspn,%20_mbscspn,%20_mbscspn_l.md)   
 [strchr, wcschr, \_mbschr, \_mbschr\_l](../../c-runtime-library/reference/strchr-wcschr-mbschr-mbschr-l.md)   
 [strrchr, wcsrchr, \_mbsrchr, \_mbsrchr\_l](../../c-runtime-library/reference/strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)