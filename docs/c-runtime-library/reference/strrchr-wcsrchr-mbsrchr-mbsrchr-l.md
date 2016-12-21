---
title: "strrchr, wcsrchr, _mbsrchr, _mbsrchr_l | Microsoft Docs"
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
  - "strrchr"
  - "wcsrchr"
  - "_mbsrchr"
  - "_mbsrchr_l"
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
  - "_tcsrchr"
  - "_ftcsrchr"
  - "strrchr"
  - "wcsrchr"
  - "_mbsrchr"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ftcsrchr"
  - "Função _mbsrchr"
  - "Função _mbsrchr_l"
  - "Função _tcsrchr"
  - "caracteres [C++], verificando"
  - "Função ftcsrchr"
  - "Função mbsrchr"
  - "Função mbsrchr_l"
  - "verificando cadeias de caracteres"
  - "cadeias de caracteres [C++], verificando"
  - "Função strrchr"
  - "Função tcsrchr"
  - "Função wcsrchr"
ms.assetid: 75cf2664-758e-49bb-bf6b-8a139cd474d2
caps.latest.revision: 28
caps.handback.revision: 28
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strrchr, wcsrchr, _mbsrchr, _mbsrchr_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Examina uma cadeia de caracteres da última ocorrência de um caractere.  
  
> [!IMPORTANT]
>  `_mbsrchr` e `_mbsrchr_l` não podem ser usados em aplicativos executados no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
char *strrchr(  
   const char *str,  
   int c   
); // C only  
char *strrchr(  
   char *str,  
   int c   
); // C++ only  
const char *strrchr(  
   const char *str,  
   int c   
); // C++ only  
wchar_t *wcsrchr(  
   const wchar_t *str,  
   wchar_t c   
); // C only  
wchar_t *wcsrchr(  
   wchar_t *str,  
   wchar_t c   
); // C++ only  
const wchar_t *wcsrchr(  
   const wchar_t *str,  
   wchar_t c   
); // C++ only  
unsigned char *_mbsrchr(  
   const unsigned char *str,  
   unsigned int c   
); // C only  
unsigned char *_mbsrchr(  
   unsigned char *str,  
   unsigned int c   
); // C++ only  
const unsigned char *_mbsrchr(  
   const unsigned char *str,  
   unsigned int c   
); // C++ only  
unsigned char *_mbsrchr_l(  
   const unsigned char *str,  
   unsigned int c,  
   _locale_t locale  
); // C only  
unsigned char *_mbsrchr_l(  
   unsigned char *str,  
   unsigned int c,  
   _locale_t locale  
); // C++ only  
const unsigned char *_mbsrchr_l(  
   const unsigned char *str,  
   unsigned int c,  
   _locale_t locale  
); // C++ only  
```  
  
#### Parâmetros  
 `str`  
 Cadeia de caracteres terminada com Null para pesquisa.  
  
 `c`  
 Caractere a ser localizado.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 Retorna um ponteiro para a última ocorrência em de `c` em `str`, ou `NULL` se `c` não for localizado.  
  
## Comentários  
 A função de `strrchr` localiza a última ocorrência de `c` \(convertido em `char`\) em `str`.  A pesquisa inclui o caractere nulo sendo encerrado.  
  
 `wcsrchr` e `_mbsrchr` são versões de caracteres largos e de multibyte de `strrchr`.  Os argumentos e o valor de retorno de `wcsrchr` são cadeias de caracteres de ampla caractere; essas de `_mbsrchr` são cadeias de caracteres de multibyte\- caractere.  
  
 No C, essas funções têm um ponteiro de `const` para o primeiro argumento.  No C\+\+, duas sobrecargas estão disponíveis.  A sobrecarga que usa um ponteiro para `const` retorna um ponteiro para `const`; a versão que usa um ponteiro para não `const` retorna um ponteiro para não `const`.  A macro \_CONST\_CORRECT\_OVERLOADS será definida se as versões `const` e não `const` dessas funções estiverem disponíveis.  Se você não exigir o comportamento não `const` para as duas sobrecargas de C\+\+, defina o símbolo \_CONST\_RETURN.  
  
 `_mbsrchr` valida seus parâmetros.  Se `str` é `NULL`, o parâmetro de manipulador inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, `errno` está definido como `EINVAL` e retorna 0 de `_mbsrchr` .  `strrchr` e `wcsrchr` não validam seus parâmetros.  Essas três funções se comportam de forma idêntica.  
  
 O valor de saída é afetado pela configuração da configuração da categoria de `LC_CTYPE` de localidade; para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  As versões dessas funções sem o sufixo `_l` usam a localidade atual para esse comportamento dependente da localidade; as versões com o sufixo `_l` são idênticas, exceto que elas usam o parâmetro de localidade informado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcsrchr`|`strrchr`|`_mbsrchr`|`wcsrchr`|  
|**n\/d**|**n\/d**|`_mbsrchr_l`|**n\/d**|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strrchr`|\<string.h\>|  
|`wcsrchr`|\<string.h\> ou \<wchar.h\>|  
|`_mbsrchr`, `_mbsrchr_l`|\<mbstring.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 Para obter um exemplo de como usar `strrchr`, consulte [strchr](../../c-runtime-library/reference/strchr-wcschr-mbschr-mbschr-l.md).  
  
## Equivalência do .NET Framework  
 [System::String::LastIndexOf](https://msdn.microsoft.com/en-us/library/system.string.lastindexof.aspx)  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [strchr, wcschr, \_mbschr, \_mbschr\_l](../../c-runtime-library/reference/strchr-wcschr-mbschr-mbschr-l.md)   
 [strcspn, wcscspn, \_mbscspn, \_mbscspn\_l](../Topic/strcspn,%20wcscspn,%20_mbscspn,%20_mbscspn_l.md)   
 [\_strnicmp, \_wcsnicmp, \_mbsnicmp, \_strnicmp\_l, \_wcsnicmp\_l, \_mbsnicmp\_l](../../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)   
 [strpbrk, wcspbrk, \_mbspbrk, \_mbspbrk\_l](../../c-runtime-library/reference/strpbrk-wcspbrk-mbspbrk-mbspbrk-l.md)   
 [strspn, wcsspn, \_mbsspn, \_mbsspn\_l](../../c-runtime-library/reference/strspn-wcsspn-mbsspn-mbsspn-l.md)