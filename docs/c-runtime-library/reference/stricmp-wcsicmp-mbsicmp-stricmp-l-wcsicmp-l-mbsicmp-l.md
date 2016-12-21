---
title: "_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l | Microsoft Docs"
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
  - "_stricmp_l"
  - "_mbsicmp"
  - "_wcsicmp"
  - "_mbsicmp_l"
  - "_stricmp"
  - "_wcsicmp_l"
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
  - "_ftcsicmp"
  - "_stricmp"
  - "wcsicmp_l"
  - "_wcsicmp"
  - "_tcsicmp"
  - "_strcmpi"
  - "stricmp_l"
  - "_mbsicmp"
  - "_fstricmp"
  - "mbsicmp_l"
  - "mbsicmp"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _fstricmp"
  - "Função _ftcsicmp"
  - "Função _mbsicmp"
  - "Função _mbsicmp_l"
  - "Função _strcmpi"
  - "Função _stricmp"
  - "Função _stricmp_l"
  - "Função _tcsicmp"
  - "Função _wcsicmp"
  - "Função _wcsicmp_l"
  - "Função fstricmp"
  - "Função ftcsicmp"
  - "Função mbsicmp"
  - "Função mbsicmp_l"
  - "Função stricmp_l"
  - "comparação de cadeias de caracteres [C++], minúsculas"
  - "cadeias de caracteres [C++], comparando"
  - "Função tcsicmp"
  - "Função wcsicmp_l"
ms.assetid: 0e1ee515-0d75-435a-a445-8875d4669b50
caps.latest.revision: 28
caps.handback.revision: 26
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Executa uma comparação de maiúsculas e minúsculas de cadeias de caracteres.  
  
> [!IMPORTANT]
>  `_mbsicmp` e `_mbsicmp_l` não pode ser usado em aplicativos executados no tempo de execução do Windows.  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _stricmp(  
   const char *string1,  
   const char *string2   
);  
int _wcsicmp(  
   const wchar_t *string1,  
   const wchar_t *string2   
);  
int _mbsicmp(  
   const unsigned char *string1,  
   const unsigned char *string2   
);  
int _stricmp_l(  
   const char *string1,  
   const char *string2,  
   _locale_t locale  
);  
int _wcsicmp_l(  
   const wchar_t *string1,  
   const wchar_t *string2,  
   _locale_t locale  
);  
int _mbsicmp_l(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `string1, string2`  
 Caracteres de terminação nula para comparar.  
  
 `locale`  
 Localidade a usar.  
  
## Valor de retorno  
 O valor de retorno indica a relação de `string1` para `string2` da seguinte maneira.  
  
|Valor de retorno|Descrição|  
|----------------------|---------------|  
|\< 0|`string1` menor que `string2`|  
|0|`string1` idêntico ao `string2`|  
|\> 0|`string1` maior que `string2`|  
  
 Em caso de erro, `_mbsicmp` retorna `_NLSCMPERROR`, que é definido em \< String. h \> e \< mbstring.h \>.  
  
## Comentários  
 O `_stricmp` ordinalmente função compara `string1` e `string2` após converter cada caractere em minúsculas e retorna um valor que indica sua relação.  `_stricmp` difere `_stricoll` que o `_stricmp` comparação será afetada somente por `LC_CTYPE`, que determina quais caracteres são maiúsculas e minúsculas.  O `_stricoll` função compara cadeias de caracteres de acordo com ambos os `LC_CTYPE` e `LC_COLLATE` categorias de localidade, que inclui o caso e a ordem de agrupamento.  Para obter mais informações sobre o `LC_COLLATE` categoria, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md) e [categorias de localidade](../../c-runtime-library/locale-categories.md).  As versões dessas funções sem o `_l` sufixo usam a localidade atual para o comportamento depende da localidade.  As versões com o sufixo são idênticas, exceto que eles usam a localidade passada em seu lugar.  Se a localidade não tiver sido definida, a localidade C é usada.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
> [!NOTE]
>  `_stricmp` equivale a `_strcmpi`.  Eles podem ser usados alternadamente, mas `_stricmp` é o padrão preferencial.  
  
 O `_strcmpi` função é equivalente a `_stricmp` e é fornecido para fins de compatibilidade com versões anteriores.  
  
 Porque `_stricmp` minúsculas comparações, isso pode resultar em comportamento inesperado.  
  
 Para ilustrar quando caso a conversão por `_stricmp` afeta o resultado de uma comparação, suponha que você tenha duas cadeias de caracteres JOHNSTON e JOHN\_HENRY.  A cadeia de caracteres JOHN\_HENRY será considerado inferior a JOHNSTON como "\_" tem um valor de ASCII menor que um s minúsculo  Na verdade, qualquer caractere que tem um valor ASCII entre 91 e 96 será considerado menor do que qualquer letra.  
  
 Se o [strcmp](../Topic/strcmp,%20wcscmp,%20_mbscmp.md) função é usada em vez de `_stricmp`, JOHN\_HENRY será maior que JOHNSTON.  
  
 `_wcsicmp` e `_mbsicmp` são versões de caractere largo e caracteres multibyte `_stricmp`.  Os argumentos e o valor de retorno de `_wcsicmp` são caracteres largos cadeias de caracteres; desses `_mbsicmp` são cadeias de caracteres multibyte.  `_mbsicmp` reconhece sequências de caracteres multibyte de acordo com a página de código multibyte atual e retorna `_NLSCMPERROR` em caso de erro.  Para obter mais informações, consulte [páginas de código](../../c-runtime-library/code-pages.md).  Essas três funções comportam idêntico caso contrário.  
  
 `_wcsicmp` e `wcscmp` comportamento idêntico, exceto que `wcscmp` não converter seus argumentos para minúsculas antes de compará\-los.  `_mbsicmp` e `_mbscmp` comportamento idêntico, exceto que `_mbscmp` não converter seus argumentos para minúsculas antes de compará\-los.  
  
 Você precisará chamar [setlocale](../Topic/setlocale,%20_wsetlocale.md) para `_wcsicmp` para trabalhar com caracteres Latino 1.  A localidade C está em vigor por padrão, então, por exemplo, ä não serão comparados como iguais a Ä.  Chamar `setlocale` com qualquer localidade que não seja a localidade C antes da chamada para `_wcsicmp`.  O exemplo a seguir demonstra como `_wcsicmp` é sensível à localidade:  
  
```  
// crt_stricmp_locale.c  
#include <string.h>  
#include <stdio.h>  
#include <locale.h>  
  
int main() {  
   setlocale(LC_ALL,"C");   // in effect by default  
   printf("\n%d",_wcsicmp(L"ä", L"Ä"));   // compare fails  
   setlocale(LC_ALL,"");  
   printf("\n%d",_wcsicmp(L"ä", L"Ä"));   // compare succeeds  
}  
```  
  
 Uma alternativa é chamar [\_create\_locale, \_wcreate\_locale](../../c-runtime-library/reference/create-locale-wcreate-locale.md) e passe o objeto de localidade retornado como um parâmetro para `_wcsicmp_l`.  
  
 Todas essas funções validam seus parâmetros.  Se `string1` ou `string2` são ponteiros nulos, o manipulador de parâmetro inválido é chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md) .  Se a execução puder continuar, essas funções retornarão `_NLSCMPERROR` e definirão `errno` para `EINVAL`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tcsicmp`|`_stricmp`|`_mbsicmp`|`_wcsicmp`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_stricmp`, `_stricmp_l`|\<string.h\>|  
|`_wcsicmp`, `_wcsicmp_l`|\<string.h\> ou \<wchar.h\>|  
|`_mbsicmp`, `_mbsicmp_l`|\<mbstring.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_stricmp.c  
  
#include <string.h>  
#include <stdio.h>  
#include <stdlib.h>  
  
char string1[] = "The quick brown dog jumps over the lazy fox";  
char string2[] = "The QUICK brown dog jumps over the lazy fox";  
  
int main( void )  
{  
   char tmp[20];  
   int result;  
  
   // Case sensitive  
   printf( "Compare strings:\n   %s\n   %s\n\n", string1, string2 );  
   result = strcmp( string1, string2 );  
   if( result > 0 )  
      strcpy_s( tmp, _countof(tmp), "greater than" );  
   else if( result < 0 )  
      strcpy_s( tmp, _countof(tmp), "less than" );  
   else  
      strcpy_s( tmp, _countof(tmp), "equal to" );  
   printf( "   strcmp:   String 1 is %s string 2\n", tmp );  
  
   // Case insensitive (could use equivalent _stricmp)  
   result = _stricmp( string1, string2 );  
   if( result > 0 )  
      strcpy_s( tmp, _countof(tmp), "greater than" );  
   else if( result < 0 )  
      strcpy_s( tmp, _countof(tmp), "less than" );  
   else  
      strcpy_s( tmp, _countof(tmp), "equal to" );  
   printf( "   _stricmp:  String 1 is %s string 2\n", tmp );  
}  
```  
  
  **Compare cadeias de caracteres:**  
 **O rápido cachorro marrom pula sobre o fox lento**  
 **O rápido cachorro marrom pula sobre o fox lento**  
 **strcmp: 1 da cadeia de caracteres é maior que 2 da cadeia de caracteres**  
 **stricmp: 1 da cadeia de caracteres é igual a cadeia de caracteres de 2**   
## Equivalência do .NET Framework  
 [System::String::Compare](https://msdn.microsoft.com/en-us/library/system.string.compare.aspx)  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [memcmp, wmemcmp](../../c-runtime-library/reference/memcmp-wmemcmp.md)   
 [\_memicmp, \_memicmp\_l](../../c-runtime-library/reference/memicmp-memicmp-l.md)   
 [strcmp, wcscmp, \_mbscmp](../Topic/strcmp,%20wcscmp,%20_mbscmp.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [strncmp, wcsncmp, \_mbsncmp, \_mbsncmp\_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [\_strnicmp, \_wcsnicmp, \_mbsnicmp, \_strnicmp\_l, \_wcsnicmp\_l, \_mbsnicmp\_l](../../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)   
 [strrchr, wcsrchr, \_mbsrchr, \_mbsrchr\_l](../../c-runtime-library/reference/strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)   
 [\_strset, \_strset\_l, \_wcsset, \_wcsset\_l, \_mbsset, \_mbsset\_l](../../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)   
 [strspn, wcsspn, \_mbsspn, \_mbsspn\_l](../../c-runtime-library/reference/strspn-wcsspn-mbsspn-mbsspn-l.md)