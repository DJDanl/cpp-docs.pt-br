---
title: _atodbl, _atodbl_l, _atoldbl, _atoldbl_l, _atoflt, _atoflt_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _atoldbl
- _atoldbl_l
- _atodbl
- _atoflt
- _atoflt_l
- _atodbl_l
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
- _atoflt
- _atoflt_l
- atodbl_l
- atoflt_l
- _atoldbl
- _atoldbl_l
- atodbl
- _atodbl_l
- atoldbl
- atoflt
- atoldbl_l
- _atodbl
dev_langs:
- C++
helpviewer_keywords:
- _atodbl function
- _atoldbl_l function
- atoflt function
- atoflt_l function
- atoldbl function
- _atoldbl function
- atodbl_l function
- _atoflt_l function
- atoldbl_l function
- atodbl function
- string conversion, to floating point values
- _atoflt function
- _atodbl_l function
ms.assetid: 2d2530f4-4bd4-42e3-8083-f2d2fbc8432a
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 5dc40e701e50343c26e03a1d2a4fccfeb710504d
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="atodbl-atodbll-atoldbl-atoldbll-atoflt-atofltl"></a>_atodbl, _atodbl_l, _atoldbl, _atoldbl_l, _atoflt, _atoflt_l
Converte uma cadeia de caracteres para um duplo (`_atodbl`), duplo longo (`_atoldbl`) ou float (`_atoflt`).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _atodbl(  
   _CRT_DOUBLE * value,  
   char * str  
);  
int _atodbl_l (  
   _CRT_DOUBLE * value,  
   char * str,  
   locale_t locale  
);  
int _atoldbl(  
   _LDOUBLE * value,  
   char * str  
);  
int _atoldbl_l (  
   _LDOUBLE * value,  
   char * str,  
   locale_t locale  
);  
int _atoflt(  
   _CRT_FLOAT * value,  
   const char * str  
);  
int _atoflt_l(  
   _CRT_FLOAT * value,  
   const char * str,  
   locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `value`  
 O valor de duplo, duplo longo ou float gerado ao converter a cadeia de caracteres em um valor de ponto flutuante. Esses valores são encapsulados em uma estrutura.  
  
 `str`  
 A cadeia de caracteres a ser analisada para converter em um valor de ponto flutuante.  
  
 `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna 0 se for bem-sucedido. Códigos de erro possíveis são `_UNDERFLOW` ou `_OVERFLOW`, que são definidos no arquivo de cabeçalho Math.h.  
  
## <a name="remarks"></a>Comentários  
 Essas funções convertem uma cadeia de caracteres em um valor de ponto flutuante. A diferença entre essas funções e a família de funções `atof` é que essas funções não geram código de ponto flutuante e não causam exceções de hardware. Em vez disso, condições de erro são relatadas como códigos de erro.  
  
 Se uma cadeia de caracteres não tiver uma interpretação válida como um valor de ponto flutuante, `value` será definido como zero e o valor retornado será zero.  
  
 As versões dessas funções que têm o sufixo `_l` são idênticas às versões que não têm o sufixo, exceto por usarem o parâmetro de localidade que é passado no lugar da localidade do thread atual.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotinas|Cabeçalho necessário|  
|--------------|---------------------|  
|`_atodbl`, `_atoldbl`, `_atoflt`<br /><br /> `_atodbl_l`, `_atoldbl_l`, `_atoflt_l`|\<stdlib.h>|  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_atodbl.c  
// Uses _atodbl to convert a string to a double precision  
// floating point value.  
  
#include <stdlib.h>  
#include <stdio.h>  
  
int main()  
{  
   char str1[256] = "3.141592654";  
   char abc[256] = "abc";  
   char oflow[256] = "1.0E+5000";  
   _CRT_DOUBLE dblval;  
   _CRT_FLOAT fltval;  
   int retval;  
  
   retval = _atodbl(&dblval, str1);  
  
   printf("Double value: %lf\n", dblval.x);  
   printf("Return value: %d\n\n", retval);  
  
   retval = _atoflt(&fltval, str1);  
   printf("Float value: %f\n", fltval.f);  
   printf("Return value: %d\n\n", retval);  
  
   // A non-floating point value: returns 0.  
   retval = _atoflt(&fltval, abc);  
   printf("Float value: %f\n", fltval.f);  
   printf("Return value: %d\n\n", retval);  
  
   // Overflow.  
   retval = _atoflt(&fltval, oflow);  
   printf("Float value: %f\n", fltval.f);  
   printf("Return value: %d\n\n", retval);  
  
   return 0;  
}  
```  
  
```Output  
Double value: 3.141593  
Return value: 0  
  
Float value: 3.141593  
Return value: 0  
  
Float value: 0.000000  
Return value: 0  
  
Float value: 1.#INF00  
Return value: 3  
```  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [atof, _atof_l, _wtof, _wtof_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)
