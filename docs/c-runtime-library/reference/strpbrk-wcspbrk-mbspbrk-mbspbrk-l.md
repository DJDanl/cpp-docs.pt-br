---
title: strpbrk, wcspbrk, _mbspbrk, _mbspbrk_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _mbspbrk
- wcspbrk
- _mbspbrk_l
- strpbrk
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
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _fstrpbrk
- _mbspbrk
- strpbrk
- _tcspbrk
- _ftcspbrk
- wcspbrk
dev_langs: C++
helpviewer_keywords:
- fstrpbrk function
- _ftcspbrk function
- _mbspbrk_l function
- strpbrk function
- _fstrpbrk function
- mbspbrk function
- characters [C++], scanning strings
- _tcspbrk function
- wcspbrk function
- ftcspbrk function
- character sets [C++], scanning strings for characters
- strings [C++], scanning
- tcspbrk function
- _mbspbrk function
- mbspbrk_l function
ms.assetid: 80b504f7-a167-4dde-97ad-4ae3000dc810
caps.latest.revision: "30"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 323ee2842799cdfe948bdf0a8af7ec2bfad92439
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="strpbrk-wcspbrk-mbspbrk-mbspbrkl"></a>strpbrk, wcspbrk, _mbspbrk, _mbspbrk_l
Procura cadeias de caracteres em conjuntos de caracteres especificados.  
  
> [!IMPORTANT]
>  `_mbspbrk` e `_mbspbrk_l` não podem ser usados em aplicativos executados no Windows Runtime. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `str`  
 Cadeia de caracteres pesquisadas e terminadas em nulo.  
  
 `strCharSet`  
 Conjunto de caracteres terminado em nulo.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para a primeira ocorrência de qualquer caractere de `strCharSet` na `str` ou um ponteiro `NULL` se os dois argumentos de cadeia de caracteres não têm caracteres em comum.  
  
## <a name="remarks"></a>Comentários  
 A função `strpbrk` retorna um ponteiro para a primeira ocorrência de um caractere em `str` que pertence ao conjunto de caracteres em `strCharSet`. A pesquisa não inclui o caractere nulo de terminação.  
  
 `wcspbrk` e `_mbspbrk` são versões de caracteres largos e de caracteres multibyte de `strpbrk`. Os argumentos e o valor retornado de `wcspbrk` são cadeias de caracteres largos; aqueles de `_mbspbrk` são cadeias de caracteres multibyte.  
  
 `_mbspbrk` valida seus parâmetros. Se `str` ou `strCharSet` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, `_mbspbrk` retornará `NULL` e definirá `errno` como `EINVAL`. `strpbrk` e `wcspbrk` não validam seus parâmetros. Caso contrário, essas três funções se comportam de forma idêntica.  
  
 `_mbspbrk` é semelhante ao `_mbscspn`, exceto que `_mbspbrk` retorna um ponteiro em vez de um valor do tipo [size_t](../../c-runtime-library/standard-types.md).  
  
 Em C, essas funções usam um ponteiro `const` para o primeiro argumento. No C++, duas sobrecargas estão disponíveis. A sobrecarga de colocar um ponteiro para `const` retorna um ponteiro para `const`; a versão que usa um ponteiro para não `const` retorna um ponteiro para não `const`. A macro `_CRT_CONST_CORRECT_OVERLOADS` é definido se o `const` e não-`const` versões dessas funções estão disponíveis. Se você precisar não`const` comportamento para as sobrecargas de C++, defina o símbolo `_CONST_RETURN`.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade; consulte [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo `_l` usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo `_l` são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcspbrk`|`strpbrk`|`_mbspbrk`|`wcspbrk`|  
|**n/d**|**n/d**|`_mbspbrk_l`|**n/d**|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`strpbrk`|\<string.h>|  
|`wcspbrk`|\<string.h> ou \<wchar.h>|  
|`_mbspbrk`, `_mbspbrk_l`|\<mbstring.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
1: The 3 men and 2 boys ate 5 pigs  
  
2: 3 men and 2 boys ate 5 pigs  
  
3: 2 boys ate 5 pigs  
  
4: 5 pigs  
```  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [strcspn, wcscspn, _mbscspn, _mbscspn_l](../../c-runtime-library/reference/strcspn-wcscspn-mbscspn-mbscspn-l.md)   
 [strchr, wcschr, _mbschr, _mbschr_l](../../c-runtime-library/reference/strchr-wcschr-mbschr-mbschr-l.md)   
 [strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](../../c-runtime-library/reference/strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)