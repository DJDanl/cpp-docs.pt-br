---
title: atol, _atol_l, _wtol, _wtol_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- atol
- _wtol_l
- _wtol
- _atol_l
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
- _atol_l
- _ttol_l
- _tstol_l
- _tstol
- _wtol
- _ttol
- _wtol_l
dev_langs:
- C++
helpviewer_keywords:
- tstol function
- atol function
- ttol function
- _atol_l function
- _tstol_l function
- string conversion, to integers
- _tstol function
- _ttol function
- _ttol_l function
- atol_l function
- wtol_l function
- _wtol_l function
- wtol function
- _wtol function
ms.assetid: cedfc21c-2d64-4e9c-bd04-bdf60b12db46
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c727f51d67e3ef64362f36c3a6f3cbd04d9f00c4
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="atol-atoll-wtol-wtoll"></a>atol, _atol_l, _wtol, _wtol_l
Converte uma cadeia de caracteres em um inteiro longo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
long atol(  
   const char *str   
);  
long _atol_l(  
   const char *str,  
   _locale_t locale  
);  
long _wtol(  
   const wchar_t *str   
);  
long _wtol_l(  
   const wchar_t *str,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `str`  
 Cadeia de caracteres a ser convertida.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada função retorna o valor `long` produzido interpretando os caracteres de entrada como um número. O valor retornado será 0L para `atol` se a entrada não puder ser convertida para um valor desse tipo.  
  
 No caso de estouro com grandes valores inteiros positivos, `atol` retorna `LONG_MAX`; no caso de estouro com grandes valores inteiros negativos. `LONG_MIN` é retornado. Em todos os casos de fora do intervalo, `errno` é definido como `ERANGE`. Se o parâmetro passado for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação do Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definirão `errno` como `EINVAL` e retornarão 0.  
  
## <a name="remarks"></a>Comentários  
 Essas funções convertem uma cadeia de caracteres em um valor inteiro longo (`atol`).  
  
 A cadeia de caracteres de entrada é uma sequência de caracteres que pode ser interpretada como um valor numérico do tipo especificado. A função para de ler a cadeia de caracteres de entrada no primeiro caractere que não consegue reconhecer como parte de um número. Esse caractere pode ser o caractere `NULL` ('\0' ou L'\0') que encerra a cadeia de caracteres.  
  
 O argumento `str` para `atol` tem a seguinte forma:  
  
 [`whitespace`] [`sign`] [`digits`]]  
  
 Um `whitespace` consiste em caracteres de espaço ou tabulação, que são ignorados; `sign` é um sinal de adição (+) ou menos (-); e `digits` são um ou mais dígitos.  
  
 `_wtol` é idêntico a `atol`, exceto que assume uma cadeia de caracteres largos.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, com a exceção de que usam o parâmetro de localidade passado em vez da localidade atual. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tstol`|`atol`|`atol`|`_wtol`|  
|`_ttol`|`atol`|`atol`|`_wtol`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotinas|Cabeçalho necessário|  
|--------------|---------------------|  
|`atol`|\<stdlib.h>|  
|`_atol_l`, `_wtol`, `_wtol_l`|\<stdlib.h> e \<wchar.h>|  
  
## <a name="example"></a>Exemplo  
 Esse programa mostra como os números armazenados como cadeias de caracteres podem ser convertidos em valores numéricos usando a função `atol`.  
  
```  
// crt_atol.c  
// This program shows how numbers stored as  
// strings can be converted to numeric values  
// using the atol functions.  
#include <stdlib.h>  
#include <stdio.h>  
#include <errno.h>  
  
int main( void )  
{  
    char    *str = NULL;  
    long    value = 0;  
  
    // An example of the atol function  
    // with leading and trailing white spaces.  
    str = "  -2309 ";  
    value = atol( str );  
    printf( "Function: atol( \"%s\" ) = %d\n", str, value );  
  
    // Another example of the atol function   
    // with an arbitrary decimal point.  
    str = "314127.64";  
    value = atol( str );  
    printf( "Function: atol( \"%s\" ) = %d\n", str, value );  
  
    // Another example of the atol function  
    // with an overflow condition occurring.  
    str = "3336402735171707160320";  
    value = atol( str );  
    printf( "Function: atol( \"%s\" ) = %d\n", str, value );  
    if (errno == ERANGE)  
    {  
       printf("Overflow condition occurred.\n");  
    }  
}  
```  
  
```Output  
Function: atol( "  -2309 " ) = -2309  
Function: atol( "314127.64" ) = 314127  
Function: atol( "3336402735171707160320" ) = 2147483647  
Overflow condition occurred.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [_ecvt](../../c-runtime-library/reference/ecvt.md)   
 [_fcvt](../../c-runtime-library/reference/fcvt.md)   
 [_gcvt](../../c-runtime-library/reference/gcvt.md)   
 [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md)   
 [_atodbl, _atodbl_l, _atoldbl, _atoldbl_l, _atoflt, _atoflt_l](../../c-runtime-library/reference/atodbl-atodbl-l-atoldbl-atoldbl-l-atoflt-atoflt-l.md)