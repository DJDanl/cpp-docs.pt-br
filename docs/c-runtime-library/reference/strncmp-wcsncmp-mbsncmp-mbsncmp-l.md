---
title: "strncmp, wcsncmp, _mbsncmp, _mbsncmp_l | Microsoft Docs"
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
  - "strncmp"
  - "_mbsncmp"
  - "wcsncmp"
  - "_mbsncmp_l"
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
  - "_ftcsnccmp"
  - "_ftcsncmp"
  - "_tcsncmp"
  - "_tcsnccmp"
  - "strncmp"
  - "_mbsncmp"
  - "wcsncmp"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ftcsnccmp"
  - "Função _ftcsncmp"
  - "Função _mbsncmp"
  - "Função _mbsncmp_l"
  - "Função _tcsnccmp"
  - "Função _tcsncmp"
  - "caracteres [C++], comparando"
  - "Função ftcsnccmp"
  - "Função ftcsncmp"
  - "Função mbsncmp"
  - "Função mbsncmp_l"
  - "comparação de cadeias de caracteres [C++], Função strncmp"
  - "cadeias de caracteres [C++], comparando caracteres de"
  - "Função strncmp"
  - "Função tcsnccmp"
  - "Função tcsncmp"
  - "Função wcsncmp"
ms.assetid: 2fdbf4e6-77da-4b59-9086-488f6066b8af
caps.latest.revision: 28
caps.handback.revision: 26
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strncmp, wcsncmp, _mbsncmp, _mbsncmp_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Compara até a contagem de caracteres de duas cadeias de caracteres especificada.  
  
> [!IMPORTANT]
>  `_mbsncmp` e `_mbsncmp_l` não pode ser usado em aplicativos executados no tempo de execução do Windows.  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int strncmp(  
   const char *string1,  
   const char *string2,  
   size_t count   
);  
int wcsncmp(  
   const wchar_t *string1,  
   const wchar_t *string2,  
   size_t count   
);  
int _mbsncmp(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count   
);  
int _mbsncmp_l(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count,   
   _locale_t locale  
);int _mbsnbcmp(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count   
);  
```  
  
#### Parâmetros  
 `string1, string2`  
 Cadeias de caracteres a ser comparado.  
  
 `count`  
 Número de caracteres a ser comparado.  
  
 `locale`  
 Localidade a usar.  
  
## Valor de retorno  
 O valor de retorno indica a relação de subcadeias de caracteres de `string1` e `string2` da seguinte maneira.  
  
|Valor de retorno|Descrição|  
|----------------------|---------------|  
|\< 0|`string1` subcadeia de caracteres menor que `string2` subcadeia de caracteres|  
|0|`string1` subcadeia de caracteres idêntica à `string2` subcadeia de caracteres|  
|\> 0|`string1` subcadeia de caracteres maior que `string2` subcadeia de caracteres|  
  
 Em um erro de validação de parâmetro, `_mbsncmp` e `_mbsncmp_l` retornar `_NLSCMPERROR`, que é definido em \< String. h \> e \< mbstring.h \>.  
  
## Comentários  
 O `strncmp` função executa uma comparação ordinal do primeiro no máximo `count` caracteres `string1` e `string2` e retorna um valor que indica a relação entre as subcadeias de caracteres.  `strncmp` é uma versão de maiúsculas e minúsculas do `_strnicmp`.  `wcsncmp` e `_mbsncmp` são versões de maiúsculas e minúsculas de `_wcsnicmp` e `_mbsnicmp`.  
  
 `wcsncmp` e `_mbsncmp` são versões de caractere largo e caracteres multibyte `strncmp`.  Os argumentos de `wcsncmp` são caracteres largos cadeias de caracteres; desses `_mbsncmp` são cadeias de caracteres multibyte.  `_mbsncmp` reconhece sequências de caracteres multibyte de acordo com uma página de código multibyte e retorna `_NLSCMPERROR` em caso de erro.  
  
 Além disso, `_mbsncmp` e `_mbsncmp_l` validar parâmetros.  Se `string1` ou `string2` é um ponteiro nulo, o manipulador de parâmetro inválido é chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, `_mbsncmp` e `_mbsncmp_l` retornar `_NLSCMPERROR` e defina `errno` para `EINVAL`.  `strncmp` e `wcsncmp` não validam seus parâmetros.  Essas funções se comportam de forma idêntica caso contrário.  
  
 O comportamento de comparação de `_mbsncmp` e `_mbsncmp_l` é afetado pela configuração do `LC_CTYPE` configuração de categoria da localidade.  Isso controla a detecção de bytes à esquerda e à direita de caracteres multibyte.  Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  O `_mbsncmp` função usa a localidade atual desse comportamento dependente de localidade.  O `_mbsncmp_l` função é idêntica, exceto que ele usa o `locale` parâmetro em vez disso.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  Se a localidade é um byte único, o comportamento dessas funções é idêntico ao `strncmp`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tcsnccmp`|`strncmp`|`_mbsncmp`|`wcsncmp`|  
|`_tcsncmp`|`strncmp`|`_mbsnbcmp`|`wcsncmp`|  
|`_tccmp`|Mapas de macro ou uma função in\-line|`_mbsncmp`|Mapas de macro ou uma função in\-line|  
|**não aplicável**|**não aplicável**|`_mbsncmp_l`|**não aplicável**|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strncmp`|\<string.h\>|  
|`wcsncmp`|\<string.h\> ou \<wchar.h\>|  
|`_mbsncmp`, `_mbsncmp_l`|\<mbstring.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_strncmp.c  
#include <string.h>  
#include <stdio.h>  
  
char string1[] = "The quick brown dog jumps over the lazy fox";  
char string2[] = "The QUICK brown fox jumps over the lazy dog";  
  
int main( void )  
{  
   char tmp[20];  
   int result;  
   printf( "Compare strings:\n      %s\n      %s\n\n",  
           string1, string2 );  
   printf( "Function:   strncmp (first 10 characters only)\n" );  
   result = strncmp( string1, string2 , 10 );  
   if( result > 0 )  
      strcpy_s( tmp, sizeof(tmp), "greater than" );  
   else if( result < 0 )  
      strcpy_s( tmp, sizeof(tmp), "less than" );  
   else  
      strcpy_s( tmp, sizeof(tmp), "equal to" );  
   printf( "Result:      String 1 is %s string 2\n\n", tmp );  
   printf( "Function:   strnicmp _strnicmp (first 10 characters only)\n" );  
   result = _strnicmp( string1, string2, 10 );  
   if( result > 0 )  
      strcpy_s( tmp, sizeof(tmp), "greater than" );  
   else if( result < 0 )  
      strcpy_s( tmp, sizeof(tmp), "less than" );  
   else  
      strcpy_s( tmp, sizeof(tmp), "equal to" );  
   printf( "Result:      String 1 is %s string 2\n", tmp );  
}  
```  
  
  **Compare cadeias de caracteres:**  
 **O rápido cachorro marrom pula sobre o fox lento**  
 **A LIGEIRA raposa marrom pula sobre o cachorro preguiçoso**  
**Função: strncmp \(apenas 10 primeiros caracteres\)**  
**Resultado: A cadeia de caracteres 1 é maior que 2 da cadeia de caracteres**  
**Função: strnicmp strnicmp \(apenas 10 primeiros caracteres\)**  
**Resultado: A cadeia de caracteres de 1 é igual a cadeia de caracteres de 2**   
## Equivalência do .NET Framework  
 [System::String::Compare](https://msdn.microsoft.com/en-us/library/system.string.compare.aspx)  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [\_mbsnbcmp, \_mbsnbcmp\_l](../../c-runtime-library/reference/mbsnbcmp-mbsnbcmp-l.md)   
 [\_mbsnbicmp, \_mbsnbicmp\_l](../../c-runtime-library/reference/mbsnbicmp-mbsnbicmp-l.md)   
 [strcmp, wcscmp, \_mbscmp](../Topic/strcmp,%20wcscmp,%20_mbscmp.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [\_strnicmp, \_wcsnicmp, \_mbsnicmp, \_strnicmp\_l, \_wcsnicmp\_l, \_mbsnicmp\_l](../../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)   
 [strrchr, wcsrchr, \_mbsrchr, \_mbsrchr\_l](../../c-runtime-library/reference/strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)   
 [\_strset, \_strset\_l, \_wcsset, \_wcsset\_l, \_mbsset, \_mbsset\_l](../../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)   
 [strspn, wcsspn, \_mbsspn, \_mbsspn\_l](../../c-runtime-library/reference/strspn-wcsspn-mbsspn-mbsspn-l.md)