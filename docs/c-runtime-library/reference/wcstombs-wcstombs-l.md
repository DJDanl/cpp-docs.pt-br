---
title: wcstombs, _wcstombs_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- wcstombs
- _wcstombs_l
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
- api-ms-win-crt-convert-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- wcstombs
- _wcstombs_l
dev_langs:
- C++
helpviewer_keywords:
- _wcstombs_l function
- wcstombs function
- string conversion, wide characters
- wide characters, converting
- wcstombs_l function
- characters, converting
- string conversion, multibyte character strings
ms.assetid: 91234252-9ea1-423a-af99-e9d0ce4a40e3
caps.latest.revision: 30
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: 200337a53155b27b76a944d025c8fb013c29c4e6
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="wcstombs-wcstombsl"></a>wcstombs, _wcstombs_l
Converte uma sequência de caracteres largos em uma sequência de caracteres multibyte correspondente. Estão disponíveis versões mais seguras dessas funções; consulte [wcstombs_s, _wcstombs_s_l](../../c-runtime-library/reference/wcstombs-s-wcstombs-s-l.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
size_t wcstombs(  
   char *mbstr,  
   const wchar_t *wcstr,  
   size_t count   
);  
size_t _wcstombs_l(  
   char *mbstr,  
   const wchar_t *wcstr,  
   size_t count,  
   _locale_t locale  
);  
template <size_t size>  
size_t wcstombs(  
   char (&mbstr)[size],  
   const wchar_t *wcstr,  
   size_t count   
); // C++ only  
template <size_t size>  
size_t _wcstombs_l(  
   char (&mbstr)[size],  
   const wchar_t *wcstr,  
   size_t count,  
   _locale_t locale  
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `mbstr`  
 O endereço de uma sequência de caracteres multibyte.  
  
 `wcstr`  
 O endereço de uma sequência de caracteres largos.  
  
 `count`  
 O número máximo de bytes que pode ser armazenado na cadeia de caracteres multibyte de saída.  
  
 `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 Se `wcstombs` converter com êxito a cadeia de caracteres multibyte, será retornado o número de bytes gravados na cadeia de caracteres multibyte de saída, excluindo a terminação `NULL` (se houver). Se o argumento `mbstr` for `NULL`, `wcstombs` retornará o tamanho necessário em bytes da cadeia de caracteres de destino. Se `wcstombs` encontra um caractere largo não é possível converter um caractere multibyte, retornará -1 convertido no tipo `size_t` e define `errno` para `EILSEQ`.  
  
## <a name="remarks"></a>Comentários  
 A função `wcstombs` converte a cadeia de caracteres largos apontada por `wcstr` nos caracteres multibyte correspondentes e armazena os resultados na matriz `mbstr`. O parâmetro `count` indica o número máximo de bytes que pode ser armazenado na cadeia de caracteres multibyte de saída (ou seja, o tamanho de `mbstr`). Em geral, a quantidade de bytes necessária ao converter uma cadeia de caracteres largos não é conhecida. Alguns caracteres largos exigem apenas um byte na cadeia de caracteres saída; outros exigem dois. Se houver dois bytes na cadeia de caracteres multibyte de saída para cada caractere largo na cadeia de caracteres de entrada (incluindo o caractere largo `NULL`), o resultado terá um ajuste garantido.  
  
 Se `wcstombs` encontrar o caractere nulo de caractere largo (L'\0') antes ou quando `count` ocorrer, ele o converterá em um 0 de 8 bits e será interrompido. Dessa forma, a cadeia de caracteres multibyte em `mbstr` será terminada em nulo somente se `wcstombs` encontrar um caractere nulo de caractere largo durante a conversão. Se as sequências apontadas por `wcstr` e por `mbstr` se sobrepuserem, o comportamento de `wcstombs` será indefinido.  
  
 Se o argumento `mbstr` for `NULL`, `wcstombs` retornará o tamanho necessário em bytes da cadeia de caracteres de destino.  
  
 `wcstombs` valida seus parâmetros. Se `wcstr` é `NULL`, ou se `count` é maior do que `INT_MAX`, essa função invoca o manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md) . Se a execução puder continuar, a função definirá `errno` como `EINVAL` e retornará –1.  
  
 `wcstombs` usa a localidade atual de qualquer comportamento dependente da localidade; `_wcstombs_l` é idêntico, exceto pelo fato de que ele usa a localidade passada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`wcstombs`|\<stdlib.h>|  
|`_wcstombs_l`|\<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Este programa ilustra o comportamento da função `wcstombs`.  
  
```  
// crt_wcstombs.c  
// compile with: /W3  
// This example demonstrates the use  
// of wcstombs, which converts a string  
// of wide characters to a string of   
// multibyte characters.  
  
#include <stdlib.h>  
#include <stdio.h>  
  
#define BUFFER_SIZE 100  
  
int main( void )  
{  
    size_t  count;  
    char    *pMBBuffer = (char *)malloc( BUFFER_SIZE );  
    wchar_t *pWCBuffer = L"Hello, world.";  
  
    printf("Convert wide-character string:\n" );  
  
    count = wcstombs(pMBBuffer, pWCBuffer, BUFFER_SIZE ); // C4996  
    // Note: wcstombs is deprecated; consider using wcstombs_s instead  
    printf("   Characters converted: %u\n",  
            count );  
    printf("    Multibyte character: %s\n\n",  
           pMBBuffer );  
  
    free(pMBBuffer);  
}  
```  
  
```Output  
Convert wide-character string:  
   Characters converted: 13  
    Multibyte character: Hello, world.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [_mbclen, mblen, _mblen_l](../../c-runtime-library/reference/mbclen-mblen-mblen-l.md)   
 [mbstowcs, _mbstowcs_l](../../c-runtime-library/reference/mbstowcs-mbstowcs-l.md)   
 [mbtowc, _mbtowc_l](../../c-runtime-library/reference/mbtowc-mbtowc-l.md)   
 [wctomb, _wctomb_l](../../c-runtime-library/reference/wctomb-wctomb-l.md)   
 [WideCharToMultiByte](http://msdn.microsoft.com/library/windows/desktop/dd374130)
