---
title: "_strrev, _wcsrev, _mbsrev, _mbsrev_l | Microsoft Docs"
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
  - "_wcsrev"
  - "_mbsrev"
  - "_strrev"
  - "_mbsrev_l"
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
  - "_strrev"
  - "_ftcsrev"
  - "_tcsrev"
  - "mbsrev"
  - "mbsrev_l"
  - "_wcsrev_fstrrev"
  - "_mbsrev"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ftcsrev"
  - "Função _mbsrev"
  - "Função _mbsrev_l"
  - "Função _strrev"
  - "Função _tcsrev"
  - "Função _wcsrev"
  - "caracteres [C++], invertendo a ordem"
  - "caracteres [C++], alternando"
  - "Função ftcsrev"
  - "Função mbsrev"
  - "Função mbsrev_l"
  - "invertendo caracteres em cadeias de caracteres"
  - "cadeias de caracteres [C++], invertendo"
  - "Função strrev"
  - "Função tcsrev"
  - "Função wcsrev"
ms.assetid: 87863e89-4fa0-421c-af48-25d8516fe72f
caps.latest.revision: 25
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _strrev, _wcsrev, _mbsrev, _mbsrev_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Inverte os caracteres de uma cadeia de caracteres.  
  
> [!IMPORTANT]
>  `_mbsrev` e `_mbsrev_l` não podem ser usados em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
char *_strrev(  
   char *str   
);  
wchar_t *_wcsrev(  
   wchar_t *str   
);  
unsigned char *_mbsrev(  
   unsigned char *str   
);  
unsigned char *_mbsrev_l(  
   unsigned char *str,  
   _locale_t locale   
);  
```  
  
#### Parâmetros  
 `str`  
 Cadeia de caracteres terminada com Null a ser invertida.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 Retorna um ponteiro para a cadeia de caracteres alterada.  Nenhum valor de retorno é reservado para indicar um erro.  
  
## Comentários  
 A função `_strrev` inverte a ordem dos caracteres em `string`.  O caractere de terminação nula permanece no lugar.  `_wcsrev` e `_mbsrev` são versões de caracteres largos e de multibyte de `_strrev`.  Os argumentos e o valor de retorno de `_wcsrev` são cadeias de caracteres largos; `_mbsrev` são cadeias de caracteres de vários bytes.  Para `_mbsrev`, a ordem dos bytes em cada caractere de multibyte em `string` não é alterada.  Essas três funções se comportam de forma idêntica.  
  
 `_mbsrev` valida seus parâmetros.  Se `string1` ou `string2` for um ponteiro nulo, o parâmetro de manipulador inválido será chamado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar,`_mbsrev` retornará `NULL` e definirá `errno` como `EINVAL`.  `_strrev` e `_wcsrev` não validam seus parâmetros.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` de localidade. Para obter mais informações, consulte [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md).  As versões dessas funções são idênticas, exceto aquelas que não têm o sufixo `_l` usam a localidade atual e aquelas que têm o sufixo`_l`, ao contrário, usam o parâmetro de localidade que foi informado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
> [!IMPORTANT]
>  Essas funções podem ser vulneráveis às ameaças de saturação de buffer.  As saturações de buffer podem ser usadas para ataques ao sistema, pois podem causar uma elevação de privilégios injustificável.  Para obter mais informações, consulte [Evitando saturações de buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcsrev`|`_strrev`|`_mbsrev`|`_wcsrev`|  
|**n\/d**|**n\/d**|`_mbsrev_l`|**n\/d**|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_strrev`|\<string.h\>|  
|`_wcsrev`|\<string.h\> ou \<wchar.h\>|  
|`_mbsrev`, `_mbsrev_l`|\<mbstring.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_strrev.c  
// This program checks a string to see  
// whether it is a palindrome: that is, whether  
// it reads the same forward and backward.  
//  
  
#include <string.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char* string = "Able was I ere I saw Elba";  
   int result;  
  
   // Reverse string and compare (ignore case):  
   result = _stricmp( string, _strrev( _strdup( string ) ) );  
   if( result == 0 )  
      printf( "The string \"%s\" is a palindrome\n", string );  
   else  
      printf( "The string \"%s\" is not a palindrome\n", string );  
}  
```  
  
  **A cadeia de caracteres "Able was I ere I saw Elba" é um palíndromo**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [strcpy, wcscpy, \_mbscpy](../../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)   
 [\_strset, \_strset\_l, \_wcsset, \_wcsset\_l, \_mbsset, \_mbsset\_l](../../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)