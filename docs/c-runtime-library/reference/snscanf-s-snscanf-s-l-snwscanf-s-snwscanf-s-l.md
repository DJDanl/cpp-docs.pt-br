---
title: _snscanf_s, _snscanf_s_l, _snwscanf_s, _snwscanf_s_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _snwscanf_s_l
- _snwscanf_s
- _snscanf_s
- _snscanf_s_l
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
- _sntscanf_s
- snscanf_s
- _snwscanf_s_l
- sntscanf_s_l
- snwscanf_s_l
- snwscanf_s
- _snscanf_s
- _snwscanf_s
- snscanf_s_l
- _sntscanf_s_l
- _snscanf_s_l
- sntscanf_s
dev_langs: C++
helpviewer_keywords:
- _snscanf_s_l function
- snwscanf_s function
- _snwscanf_s function
- sntscanf_s_l function
- sntscanf_s function
- _snwscanf_s_l function
- _snscanf_s function
- snscanf_s_l function
- strings [C++], reading data from
- _sntscanf_s_l function
- reading data, strings
- snscanf_s function
- strings [C++], reading
- _sntscanf_s function
- snwscanf_s_l function
ms.assetid: 72356653-7362-461a-af73-597b9c0a8094
caps.latest.revision: "24"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 71c771c20256053b9bb6da0751bbde761e66d678
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="snscanfs-snscanfsl-snwscanfs-snwscanfsl"></a>_snscanf_s, _snscanf_s_l, _snwscanf_s, _snwscanf_s_l
Lê dados formatados de um comprimento especificado de uma cadeia de caracteres. Essas são versões de [_snscanf, _snscanf_l, _snwscanf, _snwscanf_l](../../c-runtime-library/reference/snscanf-snscanf-l-snwscanf-snwscanf-l.md) com aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int __cdecl _snscanf_s(  
   const char * input,  
   size_t length,  
   const char * format [, argument_list]  
);  
int __cdecl _snscanf_s_l(  
   const char * input,  
   size_t length,  
   const char * format,  
   locale_t locale [, argument_list]
);  
int __cdecl _snwscanf_s(  
   const wchar_t * input,  
   size_t length,  
   const wchar_t * format [, argument_list]
);  
int __cdecl _snwscanf_s_l(  
   const wchar_t * input,  
   size_t length,  
   const wchar_t * format,  
   locale_t locale [, argument_list]
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
  
 `argument_list`  
 Argumentos opcionais para serem atribuídos de acordo com a cadeia de caracteres de formato.  
  
## <a name="return-value"></a>Valor de retorno  
 Ambas essas funções retornam o número de campos convertidos e atribuídos com êxito; o valor retornado não inclui campos que foram lidos mas não foram atribuídos. Um valor retornado igual a 0 indica que nenhum campo foi atribuído. O valor retornado será `EOF` para um erro ou se o fim da cadeia de caracteres for alcançado antes da primeira conversão. Para obter mais informações, consulte [sscanf_s, _sscanf_s_l, swscanf_s e _swscanf_s_l](../../c-runtime-library/reference/sscanf-s-sscanf-s-l-swscanf-s-swscanf-s-l.md).  
  
 Se `input` ou `format` for um ponteiro `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão `EOF` e definirão `errno` para `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 Esta função é como `sscanf_s`, exceto pelo fato de que ela fornece a capacidade de especificar um número fixo de caracteres da cadeia de entrada para examinar. Para obter mais informações, consulte [sscanf_s, _sscanf_s_l, swscanf_s e _swscanf_s_l](../../c-runtime-library/reference/sscanf-s-sscanf-s-l-swscanf-s-swscanf-s-l.md).  
  
 O parâmetro de tamanho do buffer é necessário com os caracteres de campo de tipo `c`, `C`, `s`, `S` e `[`. Para obter mais informações, consulte [Caracteres de campo de tipo scanf](../../c-runtime-library/scanf-type-field-characters.md).  
  
> [!NOTE]
>  O parâmetro de tamanho é do tipo `unsigned`, não `size_t`.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, com a exceção de usarem o parâmetro de localidade passado, em vez da localidade do thread atual.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_sntscanf_s`|`_snscanf_s`|`_snscanf_s`|`_snwscanf_s`|  
|`_sntscanf_s_l`|`_snscanf_s_l`|`_snscanf_s_l`|`_snwscanf_s_l`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_snscanf_s`, `_snscanf_s_l`|\<stdio.h>|  
|`_snwscanf_s`, `_snwscanf_s_l`|\<stdio.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_snscanf_s.c  
// This example scans a string of   
// numbers, using both the character  
// and wide character secure versions  
// of the snscanf function.  
  
#include <stdio.h>  
  
int main( )  
{  
    char        str1[] = "15 12 14...";  
    wchar_t     str2[] = L"15 12 14...";  
    char        s1[3];  
    wchar_t     s2[3];  
    int         i;  
    float       fp;  
  
    i = _snscanf_s( str1, 6,  "%s %f", s1, 3, &fp);  
    printf_s("_snscanf_s converted %d fields: ", i);  
    printf_s("%s and %f\n", s1, fp);  
  
    i = _snwscanf_s( str2, 6,  L"%s %f", s2, 3, &fp);  
    wprintf_s(L"_snwscanf_s converted %d fields: ", i);  
    wprintf_s(L"%s and %f\n", s2, fp);  
}  
```  
  
```Output  
_snscanf_s converted 2 fields: 15 and 12.000000  
_snwscanf_s converted 2 fields: 15 and 12.000000  
```  
  
## <a name="see-also"></a>Consulte também  
 [Especificação de largura scanf](../../c-runtime-library/scanf-width-specification.md)