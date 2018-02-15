---
title: _snscanf, _snscanf_l, _snwscanf, _snwscanf_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _snwscanf
- _snscanf_l
- _snscanf
- _snwscanf_l
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
apitype: DLLExport
f1_keywords:
- _snscanf
- _snscanf_l
- _snwscanf
- snscanf_l
- snscanf
- _sntscanf_l
- _sntscanf
- _snwscanf_l
- sntscanf_l
- sntscanf
- snwscanf
- snwscanf_l
dev_langs:
- C++
helpviewer_keywords:
- snscanf_l function
- snwscanf function
- _sntscanf_l function
- sntscanf function
- _snwscanf_l function
- _sntscanf function
- _snscanf_l function
- sntscanf_l function
- strings [C++], reading data from
- snscanf function
- snwscanf_l function
- _snwscanf function
- reading data, strings
- strings [C++], reading
- _snscanf function
ms.assetid: da1ac890-f905-4cd7-954b-3c90957b5551
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 37ebbde63bec1ef670e4e0bf9596c2e59aa5fcc5
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="snscanf-snscanfl-snwscanf-snwscanfl"></a>_snscanf, _snscanf_l, _snwscanf, _snwscanf_l
Lê dados formatados de um comprimento especificado de uma cadeia de caracteres. Versões mais seguras dessas funções estão disponíveis; consulte [_snscanf_s, _snscanf_s_l, _snwscanf_s, _snwscanf_s_l](../../c-runtime-library/reference/snscanf-s-snscanf-s-l-snwscanf-s-snwscanf-s-l.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int __cdecl _snscanf(  
   const char * input,  
   size_t length,  
   const char * format,  
   ...  
);  
int __cdecl _snscanf_l(  
   const char * input,  
   size_t length,  
   const char * format,  
   locale_t locale,  
   ...  
);  
int __cdecl _snwscanf(  
   const wchar_t * input,  
   size_t length,  
   const wchar_t * format,  
   ...  
);  
int __cdecl _snwscanf_l(  
   const wchar_t * input,  
   size_t length,  
   const wchar_t * format,  
   locale_t locale,  
   ...  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `input`  
 A cadeia de caracteres de entrada para examinar.  
  
 `length`  
 O número de caracteres a examinar em `input`.  
  
 `format`  
 Um ou mais especificadores de formato.  
  
 `... (optional)`  
 Variáveis que serão usadas para armazenar os valores extraídos da cadeia de caracteres de entrada por especificadores de formato em `format`.  
  
 `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 Ambas essas funções retornam o número de campos convertidos e atribuídos com êxito; o valor retornado não inclui campos que foram lidos mas não foram atribuídos. Um valor retornado igual a 0 indica que nenhum campo foi atribuído. O valor retornado será `EOF` para um erro ou se o fim da cadeia de caracteres for alcançado antes da primeira conversão. Para obter mais informações, consulte [sscanf](../../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md).  
  
 Se `input` ou `format` for um ponteiro `NULL` ou se `length` for menor que ou igual a zero, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão `EOF` e definirão `errno` para `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 Esta função é como `sscanf`, exceto pelo fato de que ela fornece a capacidade de especificar um número fixo de caracteres da cadeia de entrada para examinar. Para obter mais informações, consulte [sscanf](../../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md).  
  
 As versões dessas funções com o sufixo `_l` são idênticas, com a exceção de usarem o parâmetro de localidade passado, em vez da localidade do thread atual.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_sntscanf`|`_snscanf`|`_snscanf`|`_snwscanf`|  
|`_sntscanf_l`|`_snscanf_l`|`_snscanf_l`|`_snwscanf_l`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_snscanf`, `_snscanf_l`|\<stdio.h>|  
|`_snwscanf`, `_snwscanf_l`|\<stdio.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_snscanf.c  
// compile with: /W3  
  
#include <stdio.h>  
int main( )  
{  
   char  str1[] = "15 12 14...";  
   wchar_t  str2[] = L"15 12 14...";  
   char  s1[3];  
   wchar_t  s2[3];  
   int   i;  
   float fp;  
  
   i = _snscanf( str1, 6,  "%s %f", s1, &fp); // C4996  
   // Note: _snscanf is deprecated; consider using _snscanf_s instead  
   printf("_snscanf converted %d fields: ", i);  
   printf("%s and %f\n", s1, fp);  
  
   i = _snwscanf( str2, 6,  L"%s %f", s2, &fp); // C4996  
   // Note: _snwscanf is deprecated; consider using _snwscanf_s instead  
   wprintf(L"_snwscanf converted %d fields: ", i);  
   wprintf(L"%s and %f\n", s2, fp);  
}  
```  
  
```Output  
_snscanf converted 2 fields: 15 and 12.000000  
_snwscanf converted 2 fields: 15 and 12.000000  
```  
  
## <a name="see-also"></a>Consulte também  
 [Especificação de largura scanf](../../c-runtime-library/scanf-width-specification.md)