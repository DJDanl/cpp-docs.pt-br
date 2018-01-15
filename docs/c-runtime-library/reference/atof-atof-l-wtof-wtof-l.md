---
title: atof, _atof_l, _wtof, _wtof_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wtof_l
- atof
- _atof_l
- _wtof
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
- _tstof
- _ttof
- atof
- stdlib/atof
- math/atof
- _atof_l
- stdlib/_atof_l
- math/_atof_l
- _wtof
- corecrt_wstdlib/_wtof
- _wtof_l
- corecrt_wstdlib/_wtof_l
dev_langs: C++
helpviewer_keywords:
- tstof function
- atof_l function
- _atof_l function
- atof function
- _tstof function
- _ttof function
- wtof function
- _wtof_l function
- ttof function
- wtof_l function
- _wtof function
- string conversion, to floating point values
ms.assetid: eb513241-c9a9-4f5c-b7e7-a49b14abfb75
caps.latest.revision: "26"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d3232acdfdda7cf5a9e19eeb34d4578b9443cc3d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="atof-atofl-wtof-wtofl"></a>atof, _atof_l, _wtof, _wtof_l
Converta uma cadeia de caracteres em duplo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
double atof(  
   const char *str   
);  
double _atof_l(  
   const char *str,  
   _locale_t locale  
);  
double _wtof(  
   const wchar_t *str   
);  
double _wtof_l(  
   const wchar_t *str,  
   _locale_t locale  
);  
```  
  
## <a name="parameters"></a>Parâmetros  
 `str`  
 Cadeia de caracteres a ser convertida.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada função retorna o valor `double` produzido interpretando os caracteres de entrada como um número. O valor retornado será 0,0 se a entrada não puder ser convertida para um valor desse tipo.  
  
 Em todos os casos fora do intervalo, errno é definido como `ERANGE`. Se o parâmetro passado for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação do Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definirão `errno` como `EINVAL` e retornarão 0.  
  
## <a name="remarks"></a>Comentários  
 Essas funções convertem uma cadeia de caracteres em um valor de ponto flutuante de precisão dupla.  
  
 A cadeia de caracteres de entrada é uma sequência de caracteres que pode ser interpretada como um valor numérico do tipo especificado. A função para de ler a cadeia de caracteres de entrada no primeiro caractere que não consegue reconhecer como parte de um número. Esse caractere pode ser o caractere nulo ('\0' ou L'\0') que encerra a cadeia de caracteres.  
  
 O argumento `str` para `atof` e `_wtof` tem a seguinte forma:  
  
 [`whitespace`] [`sign`] [`digits`] [`.digits`] [ {`e` &#124; `E` }[`sign`]`digits`]  
  
 Um `whitespace` consiste em caracteres de espaço ou tabulação, que são ignorados; `sign` é um sinal de adição (+) ou menos (-); e `digits` são um ou mais dígitos decimais. Se nenhum dígito aparecer antes do ponto decimal, pelo menos um deverá aparecer após o ponto decimal. Os dígitos decimais podem ser seguidos por um expoente, que consiste em uma carta de apresentação (`e` ou `E`) e um inteiro decimal opcionalmente com sinal.  
 
 As versões UCRT dessas funções não dão suporte para a conversão do estilo Fortran (`d` ou `D`) letras de expoente. Essa extensão não padrão tinha suporte em versões anteriores do CRT e pode ser uma alteração significativa para seu código.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, com a exceção de que usam o parâmetro de localidade passado em vez da localidade atual.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tstof`|`atof`|`atof`|`_wtof`|  
|`_ttof`|`atof`|`atof`|`_wtof`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina(s)|Cabeçalho necessário|  
|------------------|---------------------|  
|`atof`, `_atof_l`|C: \<math.h> ou \<stdlib.h> C++: \<cstdlib>, \<stdlib.h>, \<cmath> ou \<math.h>|  
|`_wtof`, `_wtof_l`|C: \<stdlib.h> ou \<wchar.h> C++: \<cstdlib>, \<stdlib.h> ou \<wchar.h>|  
  
## <a name="example"></a>Exemplo  
 Esse programa mostra como os números armazenados como cadeias de caracteres podem ser convertidos em valores numéricos usando as funções `atof` e `_atof_l`.  
  
```C  
// crt_atof.c  
//  
// This program shows how numbers stored as   
// strings can be converted to numeric  
// values using the atof and _atof_l functions.  

#include <stdlib.h>  
#include <stdio.h>  
#include <locale.h>  

int main(void)
{
    char    *str = NULL;
    double value = 0;
    _locale_t fr = _create_locale(LC_NUMERIC, "fr-FR");

    // An example of the atof function  
    // using leading and training spaces.  
    str = "  3336402735171707160320 ";
    value = atof(str);
    printf("Function: atof(\"%s\") = %e\n", str, value);

    // Another example of the atof function  
    // using the 'E' exponential formatting keyword.  
    str = "3.1412764583E210";
    value = atof(str);
    printf("Function: atof(\"%s\") = %e\n", str, value);

    // An example of the atof and _atof_l functions  
    // using the 'e' exponential formatting keyword  
    // and showing different decimal point interpretations.  
    str = "  -2,309e-25";
    value = atof(str);
    printf("Function: atof(\"%s\") = %e\n", str, value);
    value = _atof_l(str, fr);
    printf("Function: _atof_l(\"%s\", fr)) = %e\n", str, value);
}  
```  
  
```Output  
Function: atof("  3336402735171707160320 ") = 3.336403e+21
Function: atof("3.1412764583E210") = 3.141276e+210
Function: atof("  -2,309e-25") = -2.000000e+00
Function: _atof_l("  -2,309e-25", fr)) = -2.309000e-25  
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